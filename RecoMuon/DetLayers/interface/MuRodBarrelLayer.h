#ifndef DetLayers_MuRodBarrelLayer_H
#define DetLayers_MuRodBarrelLayer_H

/** \class MuRodBarrelLayer
 *  A cylinder composed of rods. Represents barrel muon DT/RPC stations.
 *
 *  $Date: 2006/06/02 12:21:38 $
 *  $Revision: 1.5 $
 *  \author N. Amapane - INFN Torino
 *
 */
#include "TrackingTools/DetLayers/interface/RodBarrelLayer.h"
#include "Utilities/BinningTools/interface/BaseBinFinder.h"

class DetRod;
class DetRodBuilder;
class GeomDet;

class MuRodBarrelLayer : public RodBarrelLayer {
public:

  MuRodBarrelLayer(std::vector<const DetRod*>& rods);

  virtual ~MuRodBarrelLayer();

  // GeometricSearchDet interface

  virtual const std::vector<const GeomDet*>& basicComponents() const {return theBasicComps;}

  virtual const std::vector<const GeometricSearchDet*>& components() const;
  
  virtual std::pair<bool, TrajectoryStateOnSurface>
  compatible( const TrajectoryStateOnSurface& ts, const Propagator& prop, 
	      const MeasurementEstimator&) const;

  virtual std::vector<DetWithState> 
  compatibleDets( const TrajectoryStateOnSurface& startingState,
		  const Propagator& prop, 
		  const MeasurementEstimator& est) const;
  
  virtual std::vector<DetGroup> 
  groupedCompatibleDets( const TrajectoryStateOnSurface& startingState,
			 const Propagator& prop,
			 const MeasurementEstimator& est) const;


  virtual bool hasGroups() const;


  // DetLayer interface

  virtual Module module() const;


  // Extension of the interface

  /// Return the vector of rods.
  virtual const std::vector<const DetRod*>& rods() const {return theRods;}


private:
  std::vector<const DetRod*> theRods;
  std::vector <const GeometricSearchDet*> theComponents; // duplication of the above
  std::vector<const GeomDet*> theBasicComps; // All chambers
  BaseBinFinder<double> * theBinFinder;
  bool isOverlapping;
};

#endif
