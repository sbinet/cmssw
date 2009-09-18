#ifndef GsfTrajectoryFitter_H_
#define GsfTrajectoryFitter_H_

#include "TrackingTools/GeomPropagators/interface/Propagator.h"
#include "TrackingTools/TrajectoryState/interface/TrajectoryStateOnSurface.h"
#include "TrackingTools/PatternTools/interface/TrajectoryStateUpdator.h"
#include "TrackingTools/PatternTools/interface/Trajectory.h"
#include "TrackingTools/PatternTools/interface/TrajectoryFitter.h"
#include "TrackingTools/PatternTools/interface/TrajectoryMeasurement.h"
#include "TrackingTools/PatternTools/interface/MeasurementEstimator.h"

#include <vector>

class MultiTrajectoryStateMerger;

/** A GSF fitter, similar to KFTrajectoryFitter.
 */

class GsfTrajectoryFitter : public TrajectoryFitter {

private:
  typedef TrajectoryStateOnSurface TSOS;
  typedef TrajectoryMeasurement TM;

public:

  /** Constructor with explicit components for propagation, update,
   *  chi2 calculation, merging and flag for merging before / after
   *  the update (i.e. fully configured) */
  GsfTrajectoryFitter(const Propagator& aPropagator,
		      const TrajectoryStateUpdator& aUpdator,
		      const MeasurementEstimator& aEstimator,
		      const MultiTrajectoryStateMerger& aMerger);
  
  virtual ~GsfTrajectoryFitter(); 
  
  virtual std::vector<Trajectory> fit(const Trajectory& aTraj) const;
  virtual std::vector<Trajectory> fit(const TrajectorySeed& aSeed,
				      const RecHitContainer& hits) const;
  virtual std::vector<Trajectory> fit(const TrajectorySeed& aSeed,
				      const RecHitContainer& hits, 
				      const TSOS& firstPredTsos) const;

  const Propagator* propagator() const {return thePropagator;}
  const TrajectoryStateUpdator* updator() const {return theUpdator;}
  const MeasurementEstimator* estimator() const {return theEstimator;}
  const MultiTrajectoryStateMerger* merger() const {return theMerger;}
  
  virtual GsfTrajectoryFitter* clone() const
  {
    return new GsfTrajectoryFitter(*thePropagator,*theUpdator,*theEstimator,*theMerger);
  }

private:
  const Propagator* thePropagator;
  const TrajectoryStateUpdator* theUpdator;
  const MeasurementEstimator* theEstimator;
  const MultiTrajectoryStateMerger* theMerger;

  bool theTiming;
};

#endif //TR_GsfTrajectoryFitter_H_
