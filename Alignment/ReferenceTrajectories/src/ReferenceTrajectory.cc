//  Author     : Gero Flucke (based on code by Edmund Widl replacing ORCA's TkReferenceTrack)
//  date       : 2006/09/17
//  last update: $Date: 2011/11/24 14:33:37 $
//  by         : $Author: mussgill $

#include <memory>

#include "Alignment/ReferenceTrajectories/interface/ReferenceTrajectory.h"

#include "DataFormats/GeometrySurface/interface/Surface.h" 
#include "DataFormats/GeometrySurface/interface/Plane.h"
#include "DataFormats/GeometrySurface/interface/OpenBounds.h"

#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "DataFormats/CLHEP/interface/AlgebraicObjects.h" 
#include "DataFormats/GeometrySurface/interface/LocalError.h"
#include "DataFormats/GeometryVector/interface/LocalPoint.h"
#include "Geometry/CommonDetUnit/interface/GeomDet.h"

#include "DataFormats/TrajectoryState/interface/LocalTrajectoryParameters.h"
#include "DataFormats/TrackingRecHit/interface/KfComponentsHolder.h"

#include "TrackingTools/AnalyticalJacobians/interface/AnalyticalCurvilinearJacobian.h"
#include "TrackingTools/AnalyticalJacobians/interface/JacobianLocalToCurvilinear.h"
#include "TrackingTools/AnalyticalJacobians/interface/JacobianCurvilinearToLocal.h"

#include "TrackingTools/GeomPropagators/interface/AnalyticalPropagator.h"
#include "TrackPropagation/RungeKutta/interface/RKTestPropagator.h"

#include "TrackingTools/TrajectoryState/interface/TrajectoryStateOnSurface.h"
#include "TrackingTools/TrajectoryParametrization/interface/GlobalTrajectoryParameters.h"

#include "TrackingTools/MaterialEffects/interface/MultipleScatteringUpdator.h"
#include "TrackingTools/MaterialEffects/interface/EnergyLossUpdator.h"
#include "TrackingTools/MaterialEffects/interface/CombinedMaterialEffectsUpdator.h"
#include <TrackingTools/PatternTools/interface/TSCPBuilderNoMaterial.h>
#include <TrackingTools/PatternTools/interface/TSCBLBuilderNoMaterial.h>
#include "TrackingTools/TrajectoryState/interface/TrajectoryStateClosestToPoint.h"
#include "TrackingTools/TrajectoryState/interface/TrajectoryStateClosestToBeamLine.h"

#include "MagneticField/Engine/interface/MagneticField.h"

#include "Alignment/ReferenceTrajectories/interface/BeamSpotTransientTrackingRecHit.h"
#include "Alignment/ReferenceTrajectories/interface/BeamSpotGeomDet.h"

//__________________________________________________________________________________

ReferenceTrajectory::ReferenceTrajectory(const TrajectoryStateOnSurface &refTsos,
					 const TransientTrackingRecHit::ConstRecHitContainer
					 &recHits, bool hitsAreReverse,
					 const MagneticField *magField, 
					 MaterialEffects materialEffects,
					 PropagationDirection propDir,
					 double mass,
					 bool useBeamSpot, const reco::BeamSpot &beamSpot) 
 : ReferenceTrajectoryBase( 
   (materialEffects >= brokenLinesCoarse) ? 1 : refTsos.localParameters().mixedFormatVector().kSize, 
   (useBeamSpot == true) ? recHits.size()+1 : recHits.size(),
   (materialEffects >= brokenLinesCoarse) ? 
       2*((useBeamSpot == true) ? recHits.size()+1 : recHits.size())   :
   ( (materialEffects == breakPoints) ? 2*((useBeamSpot == true) ? recHits.size()+1 : recHits.size())-2 : 0) , 
   (materialEffects >= brokenLinesCoarse) ? 
       2*((useBeamSpot == true) ? recHits.size()+1 : recHits.size())-4 : 
   ( (materialEffects == breakPoints) ? 2*((useBeamSpot == true) ? recHits.size()+1 : recHits.size())-2 : 0) )
{
  // no check against magField == 0  
  theParameters = asHepVector<5>( refTsos.localParameters().mixedFormatVector() );
  
  if (hitsAreReverse) {
    TransientTrackingRecHit::ConstRecHitContainer fwdRecHits;
    fwdRecHits.reserve(recHits.size());
    for (TransientTrackingRecHit::ConstRecHitContainer::const_reverse_iterator it=recHits.rbegin();
	 it != recHits.rend(); ++it) {
      fwdRecHits.push_back(*it);
    }
    theValidityFlag = this->construct(refTsos, fwdRecHits, mass, materialEffects,
				      propDir, magField,
				      useBeamSpot, beamSpot);
  } else {
    theValidityFlag = this->construct(refTsos, recHits, mass, materialEffects,
				      propDir, magField,
				      useBeamSpot, beamSpot);
  }
}


//__________________________________________________________________________________

ReferenceTrajectory::ReferenceTrajectory( unsigned int nPar, unsigned int nHits,
					  MaterialEffects materialEffects)
 : ReferenceTrajectoryBase( 
   (materialEffects >= brokenLinesCoarse) ? 1 : nPar, 
   nHits, 
   (materialEffects >= brokenLinesCoarse) ? 2*nHits   : ( (materialEffects == breakPoints) ? 2*nHits-2 : 0 ), 
   (materialEffects >= brokenLinesCoarse) ? 2*nHits-4 : ( (materialEffects == breakPoints) ? 2*nHits-2 : 0 ) )
{}


//__________________________________________________________________________________

bool ReferenceTrajectory::construct(const TrajectoryStateOnSurface &refTsos, 
				    const TransientTrackingRecHit::ConstRecHitContainer &recHits,
				    double mass, MaterialEffects materialEffects,
				    const PropagationDirection propDir,
				    const MagneticField *magField,
				    bool useBeamSpot,
				    const reco::BeamSpot &beamSpot)
{   
  TrajectoryStateOnSurface theRefTsos = refTsos;

  const SurfaceSide surfaceSide = this->surfaceSide(propDir);
  // auto_ptr to avoid memory leaks in case of not reaching delete at end of method:
  std::auto_ptr<MaterialEffectsUpdator> aMaterialEffectsUpdator
    (this->createUpdator(materialEffects, mass));
  if (!aMaterialEffectsUpdator.get()) return false; // empty auto_ptr

  AlgebraicMatrix                 fullJacobian(theParameters.num_row(), theParameters.num_row());
  std::vector<AlgebraicMatrix>    allJacobians; 
  allJacobians.reserve(theNumberOfHits);

  TransientTrackingRecHit::ConstRecHitPointer  previousHitPtr;
  TrajectoryStateOnSurface                     previousTsos;
  AlgebraicSymMatrix              previousChangeInCurvature(theParameters.num_row(), 1);
  std::vector<AlgebraicSymMatrix> allCurvatureChanges; 
  allCurvatureChanges.reserve(theNumberOfHits);
  
  const LocalTrajectoryError zeroErrors(0., 0., 0., 0., 0.);

  std::vector<AlgebraicMatrix> allProjections;
  allProjections.reserve(theNumberOfHits);
  std::vector<AlgebraicSymMatrix> allDeltaParameterCovs;
  allDeltaParameterCovs.reserve(theNumberOfHits);

  // CHK
  std::vector<AlgebraicMatrix> allLocalToCurv;
  allLocalToCurv.reserve(theNumberOfHits); 
  std::vector<double> allSteps;
  allSteps.reserve(theNumberOfHits); 
  std::vector<AlgebraicMatrix>    allCurvlinJacobians; 
  allCurvlinJacobians.reserve(theNumberOfHits);
  
  AlgebraicMatrix firstCurvlinJacobian(5, 5, 1);
  
  unsigned int iRow = 0;

  // local storage vector of all rechits (including rechit for beam spot in case it is used)
  TransientTrackingRecHit::ConstRecHitContainer allRecHits;

  if (useBeamSpot && propDir==alongMomentum) {
    
    GlobalPoint bs(beamSpot.x0(), beamSpot.y0(), beamSpot.z0());
    
    TrajectoryStateClosestToBeamLine tsctbl(TSCBLBuilderNoMaterial()(*(refTsos.freeState()), beamSpot));
    if (!tsctbl.isValid()) {
      edm::LogError("Alignment") << "@SUB=ReferenceTrajectory::construct" 
				 << "TrajectoryStateClostestToBeamLine invalid. Skip track.";
      return false;
    }

    FreeTrajectoryState pcaFts = tsctbl.trackStateAtPCA();
    GlobalVector bd(beamSpot.dxdz(), beamSpot.dydz(), 1.0);
    
    //propagation FIXME: Should use same propagator everywhere...
    AnalyticalPropagator propagator(magField);
    std::pair< TrajectoryStateOnSurface, double > tsosWithPath =
      propagator.propagateWithPath(pcaFts, refTsos.surface());
    
    if (!tsosWithPath.first.isValid()) return false;
    
    GlobalVector momDir(pcaFts.momentum());
    GlobalVector perpDir(bd.cross(momDir));
    BoundPlane::RotationType rotation(perpDir, bd);
    
    BeamSpotGeomDet * bsGeom = new BeamSpotGeomDet(BoundPlane::build(bs, rotation, OpenBounds()));

    // There is also a constructor taking the magentic field. Use this one instead?
    theRefTsos = TrajectoryStateOnSurface(pcaFts, bsGeom->surface());
    
    TransientTrackingRecHit::ConstRecHitPointer bsRecHit = 
      new BeamSpotTransientTrackingRecHit(beamSpot,
					  bsGeom,
					  theRefTsos.freeState()->momentum().phi());
    allRecHits.push_back(bsRecHit);

  }
  
  // copy all rechits to the local storage vector
  TransientTrackingRecHit::ConstRecHitContainer::const_iterator itRecHit;
  for ( itRecHit = recHits.begin(); itRecHit != recHits.end(); ++itRecHit ) { 
    const TransientTrackingRecHit::ConstRecHitPointer &hitPtr = *itRecHit;
    allRecHits.push_back(hitPtr);
  }

  for ( itRecHit = allRecHits.begin(); itRecHit != allRecHits.end(); ++itRecHit ) { 
    
    const TransientTrackingRecHit::ConstRecHitPointer &hitPtr = *itRecHit;
    theRecHits.push_back(hitPtr);

    if (0 == iRow) {

      // compute the derivatives of the reference-track's parameters w.r.t. the initial ones
      // derivative of the initial reference-track parameters w.r.t. themselves is of course the identity 
      fullJacobian = AlgebraicMatrix(theParameters.num_row(), theParameters.num_row(), 1);
      allJacobians.push_back(fullJacobian);
      theTsosVec.push_back(theRefTsos);
      const JacobianLocalToCurvilinear startTrafo(hitPtr->det()->surface(), theRefTsos.localParameters(), *magField);
      const AlgebraicMatrix localToCurvilinear =  asHepMatrix<5>(startTrafo.jacobian());
      if (materialEffects <= breakPoints) {
         theInnerTrajectoryToCurvilinear = asHepMatrix<5>(startTrafo.jacobian());
	 theInnerLocalToTrajectory = AlgebraicMatrix(5, 5, 1);
      }	 
      allLocalToCurv.push_back(localToCurvilinear);
      allSteps.push_back(0.);
      allCurvlinJacobians.push_back(firstCurvlinJacobian);

    } else {

      AlgebraicMatrix nextJacobian;
      AlgebraicMatrix nextCurvlinJacobian;
      double nextStep = 0.;
      TrajectoryStateOnSurface nextTsos;

      if (!this->propagate(previousHitPtr->det()->surface(), previousTsos,
			   hitPtr->det()->surface(), nextTsos,
			   nextJacobian, nextCurvlinJacobian, nextStep, propDir, magField)) {
	return false; // stop if problem...// no delete aMaterialEffectsUpdator needed
      }
      
      allJacobians.push_back(nextJacobian);
      fullJacobian = nextJacobian * previousChangeInCurvature * fullJacobian;
      theTsosVec.push_back(nextTsos);
      
      const JacobianLocalToCurvilinear startTrafo(hitPtr->det()->surface(), nextTsos.localParameters(), *magField);
      const AlgebraicMatrix localToCurvilinear =  asHepMatrix<5>(startTrafo.jacobian());
      allLocalToCurv.push_back(localToCurvilinear);
      if (nextStep == 0.) { 
	edm::LogError("Alignment") << "@SUB=ReferenceTrajectory::construct"
				   << "step 0. from id " << previousHitPtr->geographicalId()
				   << " to " << hitPtr->det()->geographicalId() << ".";
	// brokenLinesFine will not work, brokenLinesCoarse combines close by layers
	if (materialEffects == brokenLinesFine) {
	  edm::LogError("Alignment") << "@SUB=ReferenceTrajectory::construct" << "Skip track.";
	  return false;
	}
      }
      allSteps.push_back(nextStep);
      allCurvlinJacobians.push_back(nextCurvlinJacobian);

    }

    // take material effects into account. since trajectory-state is constructed with errors equal zero,
    // the updated state contains only the uncertainties due to interactions in the current layer.
    const TrajectoryStateOnSurface tmpTsos(theTsosVec.back().localParameters(), zeroErrors,
					   theTsosVec.back().surface(), magField, surfaceSide);
    const TrajectoryStateOnSurface updatedTsos = aMaterialEffectsUpdator->updateState(tmpTsos, propDir);

    if ( !updatedTsos.isValid() ) return false;// no delete aMaterialEffectsUpdator needed
    
    if ( theTsosVec.back().localParameters().charge() )
    {
      previousChangeInCurvature[0][0] = updatedTsos.localParameters().signedInverseMomentum() 
	/ theTsosVec.back().localParameters().signedInverseMomentum();
    }
    
    // get multiple-scattering covariance-matrix
    allDeltaParameterCovs.push_back( asHepMatrix<5>(updatedTsos.localError().matrix()) );
    allCurvatureChanges.push_back(previousChangeInCurvature);
    
    // projection-matrix tsos-parameters -> measurement-coordinates
    allProjections.push_back(this->getHitProjectionMatrix(hitPtr));
    // set start-parameters for next propagation. trajectory-state without error
    //  - no error propagation needed here.
    previousHitPtr = hitPtr;
    previousTsos   = TrajectoryStateOnSurface(updatedTsos.globalParameters(),
                                              updatedTsos.surface(), surfaceSide);
    
    if (materialEffects < brokenLinesCoarse) {
      this->fillDerivatives(allProjections.back(), fullJacobian, iRow);
    }

    AlgebraicVector mixedLocalParams = asHepVector<5>(theTsosVec.back().localParameters().mixedFormatVector());
    this->fillTrajectoryPositions(allProjections.back(), mixedLocalParams, iRow);
    if ( useRecHit( hitPtr ) ) this->fillMeasurementAndError(hitPtr, iRow, updatedTsos);

    iRow += nMeasPerHit;
  } // end of loop on hits

  bool msOK = true;
  switch (materialEffects) {
  case none:
    break;
  case multipleScattering:
  case energyLoss:
  case combined:
    msOK = this->addMaterialEffectsCov(allJacobians, allProjections, allCurvatureChanges,
                                       allDeltaParameterCovs);
    break;
  case breakPoints:
    msOK = this->addMaterialEffectsBp(allJacobians, allProjections, allCurvatureChanges,
                                      allDeltaParameterCovs, allLocalToCurv);
    break;
  case brokenLinesCoarse:
    msOK = this->addMaterialEffectsBrl(allProjections, allDeltaParameterCovs, allLocalToCurv,
                                       allSteps, refTsos.globalParameters());
    break;
  case brokenLinesFine:
    msOK = this->addMaterialEffectsBrl(allCurvlinJacobians, allProjections, allCurvatureChanges,
                                       allDeltaParameterCovs, allLocalToCurv, refTsos.globalParameters());
  }
  if (!msOK) return false;
 
  if (refTsos.hasError()) {
    AlgebraicSymMatrix parameterCov = asHepMatrix<5>(refTsos.localError().matrix());
    AlgebraicMatrix  parDeriv;
    if (theNumberOfVirtualPars>0) { 
      parDeriv = theDerivatives.sub( 1, nMeasPerHit*allJacobians.size(), 1, theParameters.num_row() ); 
    } else {
      parDeriv = theDerivatives; 
    }
    theTrajectoryPositionCov = parameterCov.similarity(parDeriv);
  } else {
    theTrajectoryPositionCov = AlgebraicSymMatrix(theDerivatives.num_row(), 1);
  }

  return true;
}

//__________________________________________________________________________________

MaterialEffectsUpdator*
ReferenceTrajectory::createUpdator(MaterialEffects materialEffects, double mass) const
{
  switch (materialEffects) {
    // MultipleScatteringUpdator doesn't change the trajectory-state
    // during update and can therefore be used if material effects should be ignored:
  case none:
  case multipleScattering: 
    return new MultipleScatteringUpdator(mass);
  case energyLoss:
    return new EnergyLossUpdator(mass);
  case combined:
    return new CombinedMaterialEffectsUpdator(mass);
  case breakPoints:
    return new CombinedMaterialEffectsUpdator(mass);
  case brokenLinesCoarse:
  case brokenLinesFine:
    return new CombinedMaterialEffectsUpdator(mass);
}

  return 0;
}

//__________________________________________________________________________________

bool ReferenceTrajectory::propagate(const BoundPlane &previousSurface, const TrajectoryStateOnSurface &previousTsos,
				    const BoundPlane &newSurface, TrajectoryStateOnSurface &newTsos, AlgebraicMatrix &newJacobian, 
				    AlgebraicMatrix &newCurvlinJacobian, double &nextStep,
				    const PropagationDirection propDir, const MagneticField *magField) const
{
  // propagate to next layer
  /** From TrackingTools/ GeomPropagators/ interface/ AnalyticalPropagator.h
   * NB: this propagator assumes constant, non-zero magnetic field parallel to the z-axis!
   */
  //AnalyticalPropagator aPropagator(magField, propDir);
  // Hard coded RungeKutta instead Analytical (avoid bias in TEC), but
  // work around TrackPropagation/RungeKutta/interface/RKTestPropagator.h and
  // http://www.parashift.com/c++-faq-lite/strange-inheritance.html#faq-23.9
  RKTestPropagator bPropagator(magField, propDir); //double tolerance = 5.e-5)
  Propagator &aPropagator = bPropagator;
  const std::pair<TrajectoryStateOnSurface, double> tsosWithPath =
    aPropagator.propagateWithPath(previousTsos, newSurface);

  // stop if propagation wasn't successful
  if (!tsosWithPath.first.isValid()) return false;
  
  nextStep = tsosWithPath.second;
  // calculate derivative of reference-track parameters on the actual layer w.r.t. the ones
  // on the previous layer (both in global coordinates)
  const AnalyticalCurvilinearJacobian aJacobian(previousTsos.globalParameters(), 
						tsosWithPath.first.globalPosition(),
						tsosWithPath.first.globalMomentum(),
						tsosWithPath.second);
  const AlgebraicMatrix curvilinearJacobian = asHepMatrix<5,5>(aJacobian.jacobian());

  // jacobian of the track parameters on the previous layer for local->global transformation
  const JacobianLocalToCurvilinear startTrafo(previousSurface, previousTsos.localParameters(), *magField);
  const AlgebraicMatrix localToCurvilinear = asHepMatrix<5>(startTrafo.jacobian());
    
  // jacobian of the track parameters on the actual layer for global->local transformation
  const JacobianCurvilinearToLocal endTrafo(newSurface, tsosWithPath.first.localParameters(), *magField);
  const AlgebraicMatrix curvilinearToLocal = asHepMatrix<5>(endTrafo.jacobian());
  
  // compute derivative of reference-track parameters on the actual layer w.r.t. the ones on
  // the previous layer (both in their local representation)
  newCurvlinJacobian = curvilinearJacobian;
  newJacobian = curvilinearToLocal * curvilinearJacobian * localToCurvilinear;
  newTsos     = tsosWithPath.first;

  return true;
}

//__________________________________________________________________________________

void ReferenceTrajectory::fillMeasurementAndError(const TransientTrackingRecHit::ConstRecHitPointer &hitPtr,
						  unsigned int iRow,
						  const TrajectoryStateOnSurface &updatedTsos)
{
  // get the measurements and their errors, use information updated with tsos if improving
  // (GF: Also for measurements or only for errors or do the former not change?)
  // GF 10/2008: I doubt that it makes sense to update the hit with the tsos here:
  //             That is an analytical extrapolation and not the best guess of the real 
  //             track state on the module, but the latter should be better to get the best
  //             hit uncertainty estimate!
  TransientTrackingRecHit::ConstRecHitPointer newHitPtr(hitPtr->canImproveWithTrack() ?
							hitPtr->clone(updatedTsos) : hitPtr);

  const LocalPoint localMeasurement    = newHitPtr->localPosition();
  const LocalError localMeasurementCov = newHitPtr->localPositionError();
  
  theMeasurements[iRow]   = localMeasurement.x();
  theMeasurements[iRow+1] = localMeasurement.y();
  theMeasurementsCov[iRow][iRow]     = localMeasurementCov.xx();
  theMeasurementsCov[iRow][iRow+1]   = localMeasurementCov.xy();
  theMeasurementsCov[iRow+1][iRow+1] = localMeasurementCov.yy();
  // GF: Should be a loop once the hit dimension is not hardcoded as nMeasPerHit (to be checked):
  // for (int i = 0; i < hitPtr->dimension(); ++i) {
  //   theMeasurements[iRow+i]   = hitPtr->parameters()[i]; // fixme: parameters() is by value!
  //   for (int j = i; j < hitPtr->dimension(); ++j) {
  //     theMeasurementsCov[iRow+i][iRow+j] = hitPtr->parametersError()[i][j];
  //   }
  // }
}

//__________________________________________________________________________________

void ReferenceTrajectory::fillDerivatives(const AlgebraicMatrix &projection,
					  const AlgebraicMatrix &fullJacobian,
					  unsigned int iRow)
{
  // derivatives of the local coordinates of the reference track w.r.t. to the inital track-parameters
  const AlgebraicMatrix projectedJacobian(projection * fullJacobian);
  for (int i = 0; i < parameters().num_row(); ++i) {
    theDerivatives[iRow  ][i] = projectedJacobian[0][i];
    theDerivatives[iRow+1][i] = projectedJacobian[1][i];
    // GF: Should be a loop once the hit dimension is not hardcoded as nMeasPerHit (to be checked):
    // for (int j = 0; j < projection.num_col(); ++j) {
    //   theDerivatives[iRow+j][i] = projectedJacobian[j][i];
    // }
  }
}

//__________________________________________________________________________________

void ReferenceTrajectory::fillTrajectoryPositions(const AlgebraicMatrix &projection, 
						  const AlgebraicVector &mixedLocalParams, 
						  unsigned int iRow)
{
  // get the local coordinates of the reference trajectory
  const AlgebraicVector localPosition(projection * mixedLocalParams);
  theTrajectoryPositions[iRow] = localPosition[0];
  theTrajectoryPositions[iRow+1] = localPosition[1];
  // GF: Should be a loop once the hit dimension is not hardcoded as nMeasPerHit (to be checked):
  // for (int j = 0; j < projection.num_col(); ++j) {
  //   theTrajectoryPositions[iRow+j] = localPosition[j];
  // }
}

//__________________________________________________________________________________

bool ReferenceTrajectory::addMaterialEffectsCov(const std::vector<AlgebraicMatrix> &allJacobians, 
						const std::vector<AlgebraicMatrix> &allProjections,
						const std::vector<AlgebraicSymMatrix> &allCurvatureChanges,
						const std::vector<AlgebraicSymMatrix> &allDeltaParameterCovs)
{
  // the uncertainty due to multiple scattering is 'transferred' to the error matrix of the hits

  // GF: Needs update once hit dimension is not hardcoded as nMeasPerHit!

  AlgebraicSymMatrix materialEffectsCov(nMeasPerHit * allJacobians.size(), 0);

  // additional covariance-matrix of the measurements due to material-effects (single measurement)
  AlgebraicSymMatrix deltaMaterialEffectsCov;

  // additional covariance-matrix of the parameters due to material-effects
  AlgebraicSymMatrix paramMaterialEffectsCov(allDeltaParameterCovs[0]); //initialization
  // error-propagation to state after energy loss
  //GFback  paramMaterialEffectsCov = paramMaterialEffectsCov.similarity(allCurvatureChanges[0]);

  AlgebraicMatrix tempParameterCov;
  AlgebraicMatrix tempMeasurementCov;

  for (unsigned int k = 1; k < allJacobians.size(); ++k) {
    // error-propagation to next layer
    paramMaterialEffectsCov = paramMaterialEffectsCov.similarity(allJacobians[k]);

    // get dependences for the measurements
    deltaMaterialEffectsCov = paramMaterialEffectsCov.similarity(allProjections[k]);
    materialEffectsCov[nMeasPerHit*k  ][nMeasPerHit*k  ] = deltaMaterialEffectsCov[0][0];
    materialEffectsCov[nMeasPerHit*k  ][nMeasPerHit*k+1] = deltaMaterialEffectsCov[0][1];
    materialEffectsCov[nMeasPerHit*k+1][nMeasPerHit*k  ] = deltaMaterialEffectsCov[1][0];
    materialEffectsCov[nMeasPerHit*k+1][nMeasPerHit*k+1] = deltaMaterialEffectsCov[1][1];

    // GFback add uncertainties for the following layers due to scattering at this layer
    paramMaterialEffectsCov += allDeltaParameterCovs[k];
    // end GFback
    tempParameterCov = paramMaterialEffectsCov;

    // compute "inter-layer-dependencies"
    for (unsigned int l = k+1; l < allJacobians.size(); ++l) {
      tempParameterCov   = allJacobians[l]   * allCurvatureChanges[l] * tempParameterCov;
      tempMeasurementCov = allProjections[l] * tempParameterCov       * allProjections[k].T();

      materialEffectsCov[nMeasPerHit*l][nMeasPerHit*k] = tempMeasurementCov[0][0];
      materialEffectsCov[nMeasPerHit*k][nMeasPerHit*l] = tempMeasurementCov[0][0];

      materialEffectsCov[nMeasPerHit*l][nMeasPerHit*k+1] = tempMeasurementCov[0][1];
      materialEffectsCov[nMeasPerHit*k+1][nMeasPerHit*l] = tempMeasurementCov[0][1];

      materialEffectsCov[nMeasPerHit*l+1][nMeasPerHit*k] = tempMeasurementCov[1][0];
      materialEffectsCov[nMeasPerHit*k][nMeasPerHit*l+1] = tempMeasurementCov[1][0];

      materialEffectsCov[nMeasPerHit*l+1][nMeasPerHit*k+1] = tempMeasurementCov[1][1];
      materialEffectsCov[nMeasPerHit*k+1][nMeasPerHit*l+1] = tempMeasurementCov[1][1];
    } 
    // add uncertainties for the following layers due to scattering at this layer
    // GFback paramMaterialEffectsCov += allDeltaParameterCovs[k];    
    // error-propagation to state after energy loss
    paramMaterialEffectsCov = paramMaterialEffectsCov.similarity(allCurvatureChanges[k]);
     
  }
  theMeasurementsCov += materialEffectsCov;

  return true; // cannot fail
}

//__________________________________________________________________________________

bool ReferenceTrajectory::addMaterialEffectsBp(const std::vector<AlgebraicMatrix> &allJacobians, 
                                               const std::vector<AlgebraicMatrix> &allProjections,
                                               const std::vector<AlgebraicSymMatrix> &allCurvatureChanges,
                                               const std::vector<AlgebraicSymMatrix> &allDeltaParameterCovs,
                                               const std::vector<AlgebraicMatrix> &allLocalToCurv)
{
//CHK: add material effects using break points
  int offsetPar = theNumberOfPars; 
  int offsetMeas = nMeasPerHit * allJacobians.size();
  int ierr = 0; 

  AlgebraicMatrix tempJacobian;
  AlgebraicMatrix MSprojection(2,5);
  MSprojection[0][1] = 1;
  MSprojection[1][2] = 1;
  AlgebraicSymMatrix tempMSCov; 
  AlgebraicSymMatrix tempMSCovProj;
  AlgebraicMatrix tempMSJacProj;   

  for (unsigned int k = 1; k < allJacobians.size(); ++k) {
// CHK 
    int kbp = k-1;
    tempJacobian = allJacobians[k] * allCurvatureChanges[k];
    tempMSCov = allDeltaParameterCovs[k-1].similarity(allLocalToCurv[k-1]);
    tempMSCovProj = tempMSCov.similarity(MSprojection);
    theMeasurementsCov[offsetMeas+nMeasPerHit*kbp  ][offsetMeas+nMeasPerHit*kbp  ] = tempMSCovProj[0][0];
    theMeasurementsCov[offsetMeas+nMeasPerHit*kbp+1][offsetMeas+nMeasPerHit*kbp+1]=  tempMSCovProj[1][1];
    theDerivatives[offsetMeas+nMeasPerHit*kbp  ][offsetPar+2*kbp  ] = 1.0;
    theDerivatives[offsetMeas+nMeasPerHit*kbp+1][offsetPar+2*kbp+1] = 1.0 ; 

    tempMSJacProj = (allProjections[k] * ( tempJacobian * allLocalToCurv[k-1].inverse(ierr) )) * MSprojection.T();
    if (ierr) {
      edm::LogError("Alignment") << "@SUB=ReferenceTrajectory::addMaterialEffectsBp"
	                         << "Inversion 1 for break points failed: " << ierr;
      return false;
    }
    theDerivatives[nMeasPerHit*k  ][offsetPar+2*kbp  ] =  tempMSJacProj[0][0];  
    theDerivatives[nMeasPerHit*k  ][offsetPar+2*kbp+1] =  tempMSJacProj[0][1]; 
    theDerivatives[nMeasPerHit*k+1][offsetPar+2*kbp  ] =  tempMSJacProj[1][0];  
    theDerivatives[nMeasPerHit*k+1][offsetPar+2*kbp+1] =  tempMSJacProj[1][1];
              
    for (unsigned int l = k+1; l < allJacobians.size(); ++l) {
// CHK    
      int kbp = k-1;
      tempJacobian = allJacobians[l] * allCurvatureChanges[l] * tempJacobian; 
      tempMSJacProj = (allProjections[l] * ( tempJacobian * allLocalToCurv[k-1].inverse(ierr) )) * MSprojection.T();
      if (ierr) {
	edm::LogError("Alignment") << "@SUB=ReferenceTrajectory::addMaterialEffectsBp"
				   << "Inversion 2 for break points failed: " << ierr;
        return false;
      }
      theDerivatives[nMeasPerHit*l  ][offsetPar+2*kbp  ] =  tempMSJacProj[0][0];  
      theDerivatives[nMeasPerHit*l  ][offsetPar+2*kbp+1] =  tempMSJacProj[0][1]; 
      theDerivatives[nMeasPerHit*l+1][offsetPar+2*kbp  ] =  tempMSJacProj[1][0];  
      theDerivatives[nMeasPerHit*l+1][offsetPar+2*kbp+1] =  tempMSJacProj[1][1]; 

    }

  }

  return true;
}

//__________________________________________________________________________________

bool ReferenceTrajectory::addMaterialEffectsBrl(const std::vector<AlgebraicMatrix> &allCurvlinJacobians, 
						const std::vector<AlgebraicMatrix> &allProjections,
						const std::vector<AlgebraicSymMatrix> &allCurvatureChanges,
						const std::vector<AlgebraicSymMatrix> &allDeltaParameterCovs,
						const std::vector<AlgebraicMatrix> &allLocalToCurv,
						const GlobalTrajectoryParameters &gtp)
{
//CHK: add material effects using broken lines
//fine: use exact Jacobians, all detectors  
//broken lines: pair of offsets (u1,u2) = (xt,yt) (in curvilinear frame (q/p,lambda,phi,xt,yt)) at each layer
//              scattering angles (alpha1,alpha2) = (cosLambda*dPhi, dLambda) (cosLambda cancels in Chi2)
//              DU' = (dU'/dU)*DU + (dU'/dAlpha)*DAlpha + (dU'/dQbyp)*DQbyp (propagation of U)
//                  = J*DU + S*DAlpha + d*DQbyp
//           => DAlpha = S^-1 (DU' - J*DU - d*DQbyp)

  int offsetPar = theNumberOfPars;
  int offsetMeas = nMeasPerHit*allCurvlinJacobians.size();
  int ierr = 0;

  GlobalVector p = gtp.momentum();
  double cosLambda = sqrt((p.x()*p.x()+p.y()*p.y())/(p.x()*p.x()+p.y()*p.y()+p.z()*p.z()));

// transformations Curvilinear <-> BrokenLines
  AlgebraicMatrix QbypToCurv(5,1);   // dCurv/dQbyp
  QbypToCurv[0][0] = 1.;             // dQbyp/dQbyp
  AlgebraicMatrix AngleToCurv(5,2);  // dCurv/dAlpha
  AngleToCurv[1][1] = 1.;            // dlambda/dalpha2
  AngleToCurv[2][0] = 1./cosLambda;  // dphi/dalpha1
  AlgebraicMatrix CurvToAngle(2,5);  // dAlpha/dCurv
  CurvToAngle[1][1] = 1.;            // dalpha2/dlambda
  CurvToAngle[0][2] = cosLambda;     // dalpha1/dphi
  AlgebraicMatrix OffsetToCurv(5,2); // dCurv/dU
  OffsetToCurv[3][0] = 1.;           // dxt/du1
  OffsetToCurv[4][1] = 1.;           // dyt/du2
  AlgebraicMatrix CurvToOffset(2,5); // dU/dCurv
  CurvToOffset[0][3] = 1.;           // du1/dxt
  CurvToOffset[1][4] = 1.;           // du2/dyt

// transformations  trajectory to components (Qbyp, U1, U2)
  AlgebraicMatrix TrajToQbyp(1,5);
  TrajToQbyp[0][0] = 1.;
  AlgebraicMatrix TrajToOff1(2,5);
  TrajToOff1[0][1] = 1.;
  TrajToOff1[1][2] = 1.;
  AlgebraicMatrix TrajToOff2(2,5);
  TrajToOff2[0][3] = 1.;
  TrajToOff2[1][4] = 1.;

  AlgebraicMatrix JacOffsetToAngleC, JacQbypToAngleC;
  AlgebraicMatrix JacCurvToOffsetL, JacOffsetToOffsetL, JacAngleToOffsetL, JacQbypToOffsetL, JacOffsetToAngleL;
  AlgebraicMatrix JacCurvToOffsetN, JacOffsetToOffsetN, JacAngleToOffsetN, JacQbypToOffsetN, JacOffsetToAngleN;

// transformation from trajectory to curvilinear parameters

  JacCurvToOffsetN = CurvToOffset * allCurvlinJacobians[1]; // (dU'/dCurv') * (dCurv'/dCurv) @ 2nd point
  JacOffsetToOffsetN = JacCurvToOffsetN * OffsetToCurv; // J: (dU'/dU)     = (dU'/dCurv') * (dCurv'/dCurv) * (dCurv/dU)
  JacAngleToOffsetN  = JacCurvToOffsetN * AngleToCurv;  // S: (dU'/dAlpha) = (dU'/dCurv') * (dCurv'/dCurv) * (dCurv/dAlpha)
  JacQbypToOffsetN   = JacCurvToOffsetN * QbypToCurv;   // d: (dU'/dQbyp)  = (dU'/dCurv') * (dCurv'/dCurv) * (dCurv/dQbyp)
  JacOffsetToAngleN  = JacAngleToOffsetN.inverse(ierr); // W
  if (ierr) {
     edm::LogError("Alignment") << "@SUB=ReferenceTrajectory::addMaterialEffectsBrl"
                                << "Inversion 1 for fine broken lines failed: " << ierr;
     return false;
  }
  JacOffsetToAngleC = -(JacOffsetToAngleN * JacOffsetToOffsetN); // (dAlpha/dU)
  JacQbypToAngleC   = -(JacOffsetToAngleN * JacQbypToOffsetN);   // (dAlpha/dQbyp)
  // (dAlpha/dTraj) = (dAlpha/dQbyp) * (dQbyp/dTraj) + (dAlpha/dU1) * (dU1/dTraj) + (dAlpha/dU2) * (dU2/dTraj)
  AlgebraicMatrix JacTrajToAngle = JacQbypToAngleC * TrajToQbyp + JacOffsetToAngleC * TrajToOff1 + JacOffsetToAngleN * TrajToOff2;
  // (dCurv/dTraj) = (dCurv/dQbyp) * (dQbyp/dTraj) + (dCurv/dAlpha) * (dAlpha/dTraj) + (dCurv/dU) * (dU/dTraj)
  theInnerTrajectoryToCurvilinear = QbypToCurv * TrajToQbyp + AngleToCurv * JacTrajToAngle + OffsetToCurv * TrajToOff1;
  theInnerLocalToTrajectory = theInnerTrajectoryToCurvilinear.inverse(ierr) * allLocalToCurv[0];
  if (ierr) {
    edm::LogError("Alignment") << "@SUB=ReferenceTrajectory::addMaterialEffectsBrl"
                               << "Inversion 2 for fine broken lines failed: " << ierr;
    return false;
  }

  AlgebraicMatrix tempJacobian(allCurvatureChanges[0]);
  AlgebraicSymMatrix tempMSCov;
  AlgebraicSymMatrix tempMSCovProj;
  AlgebraicMatrix tempJacL, tempJacN;
  AlgebraicMatrix JacOffsetToMeas;

// measurements from hits  
  for (unsigned int k = 0; k < allCurvlinJacobians.size(); ++k) {
//  (dMeas/dU) = (dMeas/dLoc) * (dLoc/dCurv) * (dCurv/dU)
    JacOffsetToMeas = (allProjections[k] * allLocalToCurv[k].inverse(ierr) ) * OffsetToCurv;
    if (ierr) {
       edm::LogError("Alignment") << "@SUB=ReferenceTrajectory::addMaterialEffectsBrl"
				   << "Inversion 3 for fine broken lines failed: " << ierr;
       return false;
    }
    theDerivatives[nMeasPerHit*k  ][offsetPar+2*k  ] =  JacOffsetToMeas[0][0];
    theDerivatives[nMeasPerHit*k  ][offsetPar+2*k+1] =  JacOffsetToMeas[0][1];
    theDerivatives[nMeasPerHit*k+1][offsetPar+2*k  ] =  JacOffsetToMeas[1][0];
    theDerivatives[nMeasPerHit*k+1][offsetPar+2*k+1] =  JacOffsetToMeas[1][1];
  }

// measurement of MS kink  
  for (unsigned int k = 1; k < allCurvlinJacobians.size()-1; ++k) {
// CHK 
    int iMsMeas = k-1; 
    int l    = k-1; // last hit
    int n    = k+1; // next hit

// amount of multiple scattering in layer k  (angular error perp to direction)  
    tempMSCov = allDeltaParameterCovs[k].similarity(allLocalToCurv[k]);
    tempMSCovProj = tempMSCov.similarity(CurvToAngle);
    theMeasurementsCov[offsetMeas+nMeasPerHit*iMsMeas  ][offsetMeas+nMeasPerHit*iMsMeas  ] = tempMSCovProj[1][1];
    theMeasurementsCov[offsetMeas+nMeasPerHit*iMsMeas+1][offsetMeas+nMeasPerHit*iMsMeas+1] = tempMSCovProj[0][0];

// transformation matices for offsets ( l <- k -> n )
    tempJacL = allCurvlinJacobians[k] * tempJacobian;
    JacCurvToOffsetL = CurvToOffset * tempJacL.inverse(ierr); // (dU'/dCurv') * (dCurv'/dCurv) @ last point

    if (ierr) {
       edm::LogError("Alignment") << "@SUB=ReferenceTrajectory::addMaterialEffectsBrl"
				   << "Inversion 4 for fine broken lines failed: " << ierr;
       return false;
    }
    JacOffsetToOffsetL = JacCurvToOffsetL * OffsetToCurv; // J-: (dU'/dU)     = (dU'/dCurv') * (dCurv'/dCurv) * (dCurv/dU)
    JacAngleToOffsetL  = JacCurvToOffsetL * AngleToCurv;  // S-: (dU'/dAlpha) = (dU'/dCurv') * (dCurv'/dCurv) * (dCurv/dAlpha)
    JacQbypToOffsetL   = JacCurvToOffsetL * QbypToCurv;   // d-: (dU'/dQbyp)  = (dU'/dCurv') * (dCurv'/dCurv) * (dCurv/dQbyp)
    JacOffsetToAngleL  =-JacAngleToOffsetL.inverse(ierr); // W-
    if (ierr) {
       edm::LogError("Alignment") << "@SUB=ReferenceTrajectory::addMaterialEffectsBrl"
				   << "Inversion 5 for fine broken lines failed: " << ierr;
       return false;
    }
    tempJacobian = tempJacobian * allCurvatureChanges[k];
    tempJacN = allCurvlinJacobians[n] * tempJacobian;
    JacCurvToOffsetN = CurvToOffset * tempJacN; // (dU'/dCurv') * (dCurv'/dCurv) @ next point
    JacOffsetToOffsetN = JacCurvToOffsetN * OffsetToCurv; // J+: (dU'/dU)     = (dU'/dCurv') * (dCurv'/dCurv) * (dCurv/dU)
    JacAngleToOffsetN  = JacCurvToOffsetN * AngleToCurv;  // S+: (dU'/dAlpha) = (dU'/dCurv') * (dCurv'/dCurv) * (dCurv/dAlpha)
    JacQbypToOffsetN   = JacCurvToOffsetN * QbypToCurv;   // d+: (dU'/dQbyp)  = (dU'/dCurv') * (dCurv'/dCurv) * (dCurv/dQbyp)
    JacOffsetToAngleN  = JacAngleToOffsetN.inverse(ierr); // W+
    if (ierr) {
       edm::LogError("Alignment") << "@SUB=ReferenceTrajectory::addMaterialEffectsBrl"
				   << "Inversion 6 for fine broken lines failed: " << ierr;
       return false;
    }
    JacOffsetToAngleC = -(JacOffsetToAngleL * JacOffsetToOffsetL + JacOffsetToAngleN * JacOffsetToOffsetN);
    JacQbypToAngleC   = -(JacOffsetToAngleL * JacQbypToOffsetL   + JacOffsetToAngleN * JacQbypToOffsetN);

    // bending    
    theDerivatives[offsetMeas+nMeasPerHit*iMsMeas  ][              0] = JacQbypToAngleC[0][0];
    theDerivatives[offsetMeas+nMeasPerHit*iMsMeas+1][              0] = JacQbypToAngleC[1][0];
    // last layer
    theDerivatives[offsetMeas+nMeasPerHit*iMsMeas  ][offsetPar+2*l  ] = JacOffsetToAngleL[0][0];
    theDerivatives[offsetMeas+nMeasPerHit*iMsMeas  ][offsetPar+2*l+1] = JacOffsetToAngleL[0][1];
    theDerivatives[offsetMeas+nMeasPerHit*iMsMeas+1][offsetPar+2*l  ] = JacOffsetToAngleL[1][0];
    theDerivatives[offsetMeas+nMeasPerHit*iMsMeas+1][offsetPar+2*l+1] = JacOffsetToAngleL[1][1];
    // current layer
    theDerivatives[offsetMeas+nMeasPerHit*iMsMeas  ][offsetPar+2*k  ] = JacOffsetToAngleC[0][0];
    theDerivatives[offsetMeas+nMeasPerHit*iMsMeas  ][offsetPar+2*k+1] = JacOffsetToAngleC[0][1];
    theDerivatives[offsetMeas+nMeasPerHit*iMsMeas+1][offsetPar+2*k  ] = JacOffsetToAngleC[1][0];
    theDerivatives[offsetMeas+nMeasPerHit*iMsMeas+1][offsetPar+2*k+1] = JacOffsetToAngleC[1][1];

    // next layer
    theDerivatives[offsetMeas+nMeasPerHit*iMsMeas  ][offsetPar+2*n  ] = JacOffsetToAngleN[0][0];
    theDerivatives[offsetMeas+nMeasPerHit*iMsMeas  ][offsetPar+2*n+1] = JacOffsetToAngleN[0][1];
    theDerivatives[offsetMeas+nMeasPerHit*iMsMeas+1][offsetPar+2*n  ] = JacOffsetToAngleN[1][0];
    theDerivatives[offsetMeas+nMeasPerHit*iMsMeas+1][offsetPar+2*n+1] = JacOffsetToAngleN[1][1];

  }

  return true;
}

//__________________________________________________________________________________

bool ReferenceTrajectory::addMaterialEffectsBrl(const std::vector<AlgebraicMatrix> &allProjections,
						const std::vector<AlgebraicSymMatrix> &allDeltaParameterCovs,
						const std::vector<AlgebraicMatrix> &allLocalToCurv,
						const std::vector<double> &allSteps,
						const GlobalTrajectoryParameters &gtp,
						const double minStep)
{
//CHK: add material effects using broken lines
//BrokenLinesCoarse: combine close by detectors, 
//                   use approximate Jacobians from Steps (limit Qbyp -> 0),
//                   bending only in RPhi (B=(0,0,Bz)), no energy loss correction

  int offsetPar = theNumberOfPars; 
  int offsetMeas = nMeasPerHit*allSteps.size();
  int ierr = 0;

  GlobalVector p = gtp.momentum();
  double cosLambda = sqrt((p.x()*p.x()+p.y()*p.y())/(p.x()*p.x()+p.y()*p.y()+p.z()*p.z()));
  double bFac = -gtp.magneticFieldInInverseGeV(gtp.position()).mag();

  // transformation from trajectory to curvilinear parameters at refTsos
  double delta (1.0/allSteps[1]);    
  theInnerTrajectoryToCurvilinear[0][0] = 1;
  theInnerTrajectoryToCurvilinear[1][2] = -delta;  
  theInnerTrajectoryToCurvilinear[1][4] =  delta;    
  theInnerTrajectoryToCurvilinear[2][0] = -0.5*bFac/delta;
  theInnerTrajectoryToCurvilinear[2][1] = -delta/cosLambda;
  theInnerTrajectoryToCurvilinear[2][3] =  delta/cosLambda;
  theInnerTrajectoryToCurvilinear[3][1] = 1;
  theInnerTrajectoryToCurvilinear[4][2] = 1;
  theInnerLocalToTrajectory = theInnerTrajectoryToCurvilinear.inverse(ierr) * allLocalToCurv[0];
  if (ierr) {
    edm::LogError("Alignment") << "@SUB=ReferenceTrajectory::addMaterialEffectsBrl"
                               << "Inversion 1 for coarse broken lines failed: " << ierr;
    return false;
  }

  AlgebraicMatrix CurvToAngle(2,5);  // dAlpha/dCurv
  CurvToAngle[1][1] = 1.;            // dalpha2/dlambda
  CurvToAngle[0][2] = cosLambda;     // dalpha1/dphi
  AlgebraicMatrix OffsetToCurv(5,2); // dCurv/dU
  OffsetToCurv[3][0] = 1.;           // dxt/du1
  OffsetToCurv[4][1] = 1.;           // dyt/du2

  AlgebraicSymMatrix tempMSCov;
  AlgebraicSymMatrix tempMSCovProj;
  AlgebraicMatrix JacOffsetToMeas;

  // combine closeby detectors into single plane
  std::vector<unsigned int> first(allSteps.size());
  std::vector<unsigned int> last (allSteps.size());
  std::vector<unsigned int> plane(allSteps.size());
  std::vector<double> sPlane(allSteps.size());
  unsigned int nPlane = 0;
  double sTot = 0;

  for (unsigned int k = 1; k < allSteps.size(); ++k) {
    sTot += allSteps[k];
    if (fabs(allSteps[k])>minStep) { nPlane += 1; first[nPlane] = k; }
    last[nPlane] = k;
    plane[k] = nPlane;
    sPlane[nPlane] += sTot;
  }
  if (nPlane < 2) return false; // pathological cases: need at least 2 planes

  theNumberOfVirtualPars = 2*(nPlane+1);
  theNumberOfVirtualMeas = 2*(nPlane-1);// unsigned underflow for nPlane == 0...
  for (unsigned int k = 0; k <= nPlane; ++k) { sPlane[k] /= (double) (last[k]-first[k]+1); }

  // measurements from hits
  sTot = 0; 
  for (unsigned int k = 0; k < allSteps.size(); ++k) {
    sTot += allSteps[k];
//  (dMeas/dU) = (dMeas/dLoc) * (dLoc/dCurv) * (dCurv/dU)
    JacOffsetToMeas = (allProjections[k] * allLocalToCurv[k].inverse(ierr) ) * OffsetToCurv;
    if (ierr) {
      edm::LogError("Alignment") << "@SUB=ReferenceTrajectory::addMaterialEffectsBrl"
                                 << "Inversion 2 for coarse broken lines failed: " << ierr;
      return false;
    }

    unsigned int iPlane = plane[k];
    if (last[iPlane] == first[iPlane])
    { // single plane
      theDerivatives[nMeasPerHit*k  ][offsetPar+2*iPlane  ] =  JacOffsetToMeas[0][0];
      theDerivatives[nMeasPerHit*k  ][offsetPar+2*iPlane+1] =  JacOffsetToMeas[0][1];
      theDerivatives[nMeasPerHit*k+1][offsetPar+2*iPlane  ] =  JacOffsetToMeas[1][0];
      theDerivatives[nMeasPerHit*k+1][offsetPar+2*iPlane+1] =  JacOffsetToMeas[1][1];
    } else
    { // combined plane: (linear) interpolation
      unsigned int jPlane; // neighbor plane for interpolation
      if (fabs(sTot) < fabs(sPlane[iPlane])) { jPlane = (iPlane>0) ? iPlane - 1 : 1; }
      else  { jPlane = (iPlane<nPlane) ? iPlane + 1 : nPlane -1 ;}
      // interpolation weights
      double sDiff = sPlane[iPlane] - sPlane[jPlane];
      double iFrac = (sTot - sPlane[jPlane]) / sDiff;
      double jFrac = 1.0 - iFrac;
      theDerivatives[nMeasPerHit*k  ][offsetPar+2*iPlane  ] =  JacOffsetToMeas[0][0]*iFrac;
      theDerivatives[nMeasPerHit*k  ][offsetPar+2*iPlane+1] =  JacOffsetToMeas[0][1]*iFrac;
      theDerivatives[nMeasPerHit*k+1][offsetPar+2*iPlane  ] =  JacOffsetToMeas[1][0]*iFrac;
      theDerivatives[nMeasPerHit*k+1][offsetPar+2*iPlane+1] =  JacOffsetToMeas[1][1]*iFrac;
      theDerivatives[nMeasPerHit*k  ][offsetPar+2*jPlane  ] =  JacOffsetToMeas[0][0]*jFrac;
      theDerivatives[nMeasPerHit*k  ][offsetPar+2*jPlane+1] =  JacOffsetToMeas[0][1]*jFrac;
      theDerivatives[nMeasPerHit*k+1][offsetPar+2*jPlane  ] =  JacOffsetToMeas[1][0]*jFrac;
      theDerivatives[nMeasPerHit*k+1][offsetPar+2*jPlane+1] =  JacOffsetToMeas[1][1]*jFrac;
      // 2nd order neglected
      // theDerivatives[nMeasPerHit*k  ][                   0] = -0.5*bFac*sDiff*iFrac*sDiff*jFrac*cosLambda;
    }
  }

// measurement of MS kink
  for (unsigned int i = 1; i < nPlane; ++i) {
// CHK 
    int iMsMeas = i-1;
    int l    = i-1; // last hit
    int n    = i+1; // next hit

// amount of multiple scattering in plane k
    for (unsigned int k = first[i]; k <= last[i]; ++k) {
      tempMSCov = allDeltaParameterCovs[k].similarity(allLocalToCurv[k]);
      tempMSCovProj = tempMSCov.similarity(CurvToAngle);
      theMeasurementsCov[offsetMeas+nMeasPerHit*iMsMeas  ][offsetMeas+nMeasPerHit*iMsMeas  ] += tempMSCovProj[0][0];
      theMeasurementsCov[offsetMeas+nMeasPerHit*iMsMeas+1][offsetMeas+nMeasPerHit*iMsMeas+1] += tempMSCovProj[1][1];
    }
// broken line measurements for layer k, correlations between both planes neglected
    double stepK = sPlane[i] - sPlane[l];
    double stepN = sPlane[n] - sPlane[i];
    double deltaK (1.0/stepK);
    double deltaN (1.0/stepN);
    // bending (only in RPhi)
    theDerivatives[offsetMeas+nMeasPerHit*iMsMeas  ][              0] = -0.5*bFac*(stepK+stepN)*cosLambda;
    // last layer
    theDerivatives[offsetMeas+nMeasPerHit*iMsMeas  ][offsetPar+2*l  ] = deltaK;
    theDerivatives[offsetMeas+nMeasPerHit*iMsMeas+1][offsetPar+2*l+1] = deltaK;
    // current layer
    theDerivatives[offsetMeas+nMeasPerHit*iMsMeas  ][offsetPar+2*i  ] = -(deltaK + deltaN);
    theDerivatives[offsetMeas+nMeasPerHit*iMsMeas+1][offsetPar+2*i+1] = -(deltaK + deltaN);
    // next layer
    theDerivatives[offsetMeas+nMeasPerHit*iMsMeas  ][offsetPar+2*n  ] = deltaN;
    theDerivatives[offsetMeas+nMeasPerHit*iMsMeas+1][offsetPar+2*n+1] = deltaN;
  }

  return true;
}

//__________________________________________________________________________________

AlgebraicMatrix
ReferenceTrajectory::getHitProjectionMatrix
(const TransientTrackingRecHit::ConstRecHitPointer &hitPtr) const
{
  if (this->useRecHit(hitPtr)) {
    // check which templated non-member function to call:
    switch (hitPtr->dimension()) {
    case 1:
      return getHitProjectionMatrixT<1>(hitPtr);
    case 2:
      return getHitProjectionMatrixT<2>(hitPtr);
    case 3:
      return getHitProjectionMatrixT<3>(hitPtr);
    case 4:
      return getHitProjectionMatrixT<4>(hitPtr);
    case 5:
      return getHitProjectionMatrixT<5>(hitPtr);
    default:
      throw cms::Exception("ReferenceTrajectory::getHitProjectionMatrix")
        << "Unexpected hit dimension: " << hitPtr->dimension() << "\n";
    }
  }
  // invalid or (to please compiler) unknown dimension
  return AlgebraicMatrix(2, 5, 0); // get size from ???
}

//__________________________________________________________________________________

template<unsigned int N>
AlgebraicMatrix 
ReferenceTrajectory::getHitProjectionMatrixT
(const TransientTrackingRecHit::ConstRecHitPointer &hitPtr) const
{
  // define variables that will be used to setup the KfComponentsHolder
  // (their allocated memory is needed by 'hitPtr->getKfComponents(..)'
  // ProjectMatrix<double,5,N>  pf; // not needed
  typename AlgebraicROOTObject<N,5>::Matrix H; 
  typename AlgebraicROOTObject<N>::Vector r, rMeas; 
  typename AlgebraicROOTObject<N,N>::SymMatrix V, VMeas;
  // input for the holder - but dummy is OK here to just get the projection matrix:
  const AlgebraicVector5 dummyPars;
  const AlgebraicSymMatrix55 dummyErr;

  // setup the holder with the correct dimensions and get the values
  KfComponentsHolder holder;
  holder.setup<N>(&r, &V, &H, /*&pf,*/ &rMeas, &VMeas, dummyPars, dummyErr);
  hitPtr->getKfComponents(holder);

  return asHepMatrix<N,5>(holder.projection<N>());
}

