#include "RecoTracker/TransientTrackingRecHit/interface/ProjectedRecHit2D.h"
#include "TrackingTools/TransientTrackingRecHit/interface/TrackingRecHitProjector.h"
#include "RecoTracker/TransientTrackingRecHit/interface/TSiStripRecHit2DLocalPos.h"
#include "DataFormats/SiStripCluster/interface/SiStripCluster.h"


ProjectedRecHit2D::ProjectedRecHit2D( const LocalPoint& pos, const LocalError& err,
				      const GeomDet* det, const GeomDet* originalDet,
				      const TransientTrackingRecHit& originalTransientHit,
				      float weight, float annealing ) :
  GenericTransientTrackingRecHit( det, new ProjectedSiStripRecHit2D( pos, err, det->geographicalId(), 
								     static_cast<const SiStripRecHit2D*>(originalTransientHit.hit())),weight, annealing) 
{
  const TSiStripRecHit2DLocalPos* specificOriginalTransientHit = static_cast<const TSiStripRecHit2DLocalPos*>(&originalTransientHit);
  theCPE = specificOriginalTransientHit->cpe();
  theOriginalDet = originalDet;
}

ProjectedRecHit2D::RecHitPointer 
ProjectedRecHit2D::clone( const TrajectoryStateOnSurface& ts) const
{
  if (theCPE != 0) {
    TrackingRecHitProjector<ProjectedRecHit2D> proj;
    if(!originalHit().cluster().isNull()){
      const SiStripCluster& clust = *(originalHit().cluster());  
      
      StripClusterParameterEstimator::LocalValues lv = 
	theCPE->localParameters( clust, *detUnit(), ts.localParameters());
      
      RecHitPointer updatedOriginalHit = 
	TSiStripRecHit2DLocalPos::build( lv.first, lv.second, theOriginalDet, 
					 originalHit().cluster(), theCPE, weight(), getAnnealingFactor());
      
      RecHitPointer hit = proj.project( *updatedOriginalHit, *det(), ts); 
      
    return hit;
    }else{
      const SiStripCluster& clust = *(originalHit().cluster_regional());  
      
      StripClusterParameterEstimator::LocalValues lv = 
	theCPE->localParameters( clust, *detUnit(), ts.localParameters());
      
      RecHitPointer updatedOriginalHit = 
	TSiStripRecHit2DLocalPos::build( lv.first, lv.second, theOriginalDet, 
					 originalHit().cluster_regional(), theCPE, weight(), getAnnealingFactor());
      
      RecHitPointer hit = proj.project( *updatedOriginalHit, *det(), ts); 
      
      return hit;
      
    }
  }
  /// FIXME: should report the problem somehow
  else return clone();
}
  
