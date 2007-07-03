#ifndef TrajectoryStateClosestToBeamLineBuilder_H
#define TrajectoryStateClosestToBeamLineBuilder_H

#include "TrackingTools/TrajectoryState/interface/TrajectoryStateClosestToBeamLine.h"
#include "DataFormats/BeamSpot/interface/BeamSpot.h"
#include "TrackingTools/TrajectoryState/interface/FreeTrajectoryState.h"

/**
 * This class builds a TrajectoryStateClosestToBeamLine given an original 
 * FreeTrajectoryState. This new state is then 
 * defined at the point of closest approach to the beam line.
 */

class TrajectoryStateClosestToBeamLineBuilder
{
public: 

  typedef FreeTrajectoryState		FTS;

  TrajectoryStateClosestToBeamLine operator()
    (const FTS& originalFTS, const reco::BeamSpot & beamSpot);

};
#endif
