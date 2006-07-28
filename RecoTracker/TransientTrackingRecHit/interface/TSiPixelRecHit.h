#ifndef RECOTRACKER_TRANSIENTRACKINGRECHIT_TSiPixelRecHit_H
#define RECOTRACKER_TRANSIENTRACKINGRECHIT_TSiPixelRecHit_H

#include "DataFormats/TrackerRecHit2D/interface/SiPixelRecHit.h"
#include "TrackingTools/TransientTrackingRecHit/interface/TransientTrackingRecHit.h"
#include "RecoLocalTracker/ClusterParameterEstimator/interface/PixelClusterParameterEstimator.h"

class GeomDetUnit;

class TSiPixelRecHit : public TransientTrackingRecHit {
public:

  typedef const edm::Ref<edm::DetSetVector<SiPixelCluster>, SiPixelCluster, edm::refhelper::FindForDetSetVector<SiPixelCluster> > clusterRef;

//RC   /// This constructor clones the TrackingRecHit, it should be used when the 
//RC   /// TrackingRecHit exist already in some collection
//RC   TSiPixelRecHit(const GeomDet * geom, const SiPixelRecHit* rh, 
//RC 		 const PixelClusterParameterEstimator* cpe) : 
//RC     TransientTrackingRecHit(geom), theHitData(rh->clone()), theCPE(cpe) {}

//RC   /// Creates the TrackingRecHit internally, avoids redundent cloning
//RC   TSiPixelRecHit( const LocalPoint& pos, const LocalError& err,
//RC 		  const GeomDet* det, 
//RC 		  //		  const SiPixelCluster& cluster,
//RC 		  clusterRef cluster,
//RC 		  const PixelClusterParameterEstimator* cpe);

//RC   TSiPixelRecHit( const TSiPixelRecHit& other ) :
//RC     TransientTrackingRecHit( other.det()), 
//RC     theHitData( other.specificHit()->clone()),
//RC     theCPE( other.cpe())  {}

  virtual ~TSiPixelRecHit() {delete theHitData;}

//RC   virtual TSiPixelRecHit * clone() const {
//RC     return new TSiPixelRecHit(*this);
//RC   }

  virtual AlgebraicVector parameters() const {return theHitData->parameters();}
  virtual AlgebraicSymMatrix parametersError() const {return theHitData->parametersError();}
  virtual DetId geographicalId() const {return theHitData->geographicalId();}
  virtual AlgebraicMatrix projectionMatrix() const {return theHitData->projectionMatrix();}
  virtual int dimension() const {return theHitData->dimension();}

  virtual LocalPoint localPosition() const {return theHitData->localPosition();}
  virtual LocalError localPositionError() const {return theHitData->localPositionError();}

  virtual const TrackingRecHit * hit() const {return theHitData;};
  
  virtual bool isValid() const {return theHitData->isValid();}

  virtual std::vector<const TrackingRecHit*> recHits() const {
    return hit()->recHits();
  }
  virtual std::vector<TrackingRecHit*> recHits() {
    return theHitData->recHits();
  }

  virtual bool canImproveWithTrack() const {return true;}

  //RC  virtual TSiPixelRecHit* clone (const TrajectoryStateOnSurface& ts) const;
  virtual RecHitPointer clone (const TrajectoryStateOnSurface& ts) const;

  virtual const GeomDetUnit* detUnit() const;

  // Extension of the TransientTrackingRecHit interface

  const SiPixelRecHit* specificHit() const {return theHitData;};
  const PixelClusterParameterEstimator* cpe() const {return theCPE;}

  static RecHitPointer build( const GeomDet * geom, const SiPixelRecHit* rh, 
			      const PixelClusterParameterEstimator* cpe) {
    return RecHitPointer( new TSiPixelRecHit( geom, rh, cpe));
  }

  static RecHitPointer build( const LocalPoint& pos, const LocalError& err,
			      const GeomDet* det, 
			      clusterRef cluster,
			      const PixelClusterParameterEstimator* cpe) {
    return RecHitPointer( new TSiPixelRecHit( pos, err, det, cluster, cpe));
  }


private:

  SiPixelRecHit*                        theHitData;
  const PixelClusterParameterEstimator* theCPE;

  /// This constructor clones the TrackingRecHit, it should be used when the 
  /// TrackingRecHit exist already in some collection
  TSiPixelRecHit(const GeomDet * geom, const SiPixelRecHit* rh, 
		 const PixelClusterParameterEstimator* cpe) : 
    TransientTrackingRecHit(geom), theHitData(rh->clone()), theCPE(cpe) {}

  /// Creates the TrackingRecHit internally, avoids redundent cloning
  TSiPixelRecHit( const LocalPoint& pos, const LocalError& err,
		  const GeomDet* det, 
		  //		  const SiPixelCluster& cluster,
		  clusterRef cluster,
		  const PixelClusterParameterEstimator* cpe);

  TSiPixelRecHit( const TSiPixelRecHit& other ) :
    TransientTrackingRecHit( other.det()), 
    theHitData( other.specificHit()->clone()),
    theCPE( other.cpe())  {}

  virtual TSiPixelRecHit * clone() const {
    return new TSiPixelRecHit(*this);
  }

};



#endif
