#ifndef RecoMuon_GlobalTrackFinder_GlobalMuonTrajectoryBuilder_H
#define RecoMuon_GlobalTrackFinder_GlobalMuonTrajectoryBuilder_H

/** \class GlobalMuonTrajectoryBuilder
 *  class to build muon trajectory
 *
 *  $Date: 2008/04/02 06:37:11 $
 *  $Revision: 1.64 $
 *
 *  \author N. Neumeister 	 Purdue University
 *  \author C. Liu 		 Purdue University
 *  \author A. Everett 		 Purdue University
 */

#include "RecoMuon/GlobalTrackingTools/interface/GlobalTrajectoryBuilderBase.h"
#include "TrackingTools/PatternTools/interface/TrajTrackAssociation.h"
#include "FWCore/ParameterSet/interface/InputTag.h"

namespace edm {class ParameterSet; class Event; class EventSetup; }

class MuonServiceProxy;
class Trajectory;

class GlobalMuonTrajectoryBuilder : public GlobalTrajectoryBuilderBase {

  public:

    /// constructor with Parameter Set and MuonServiceProxy
    GlobalMuonTrajectoryBuilder(const edm::ParameterSet&, const MuonServiceProxy*);
          
    /// destructor
    ~GlobalMuonTrajectoryBuilder();

    /// reconstruct trajectories from standalone and tracker only Tracks    
    MuonTrajectoryBuilder::CandidateContainer trajectories(const TrackCand&);

    /// pass the Event to the algo at each event
    virtual void setEvent(const edm::Event&);

  private:
  
    /// make a TrackCand collection using tracker Track, Trajectory information
    std::vector<TrackCand> makeTkCandCollection(const TrackCand&);

  private:
  
    edm::InputTag theTkTrackLabel;

    edm::Handle<reco::TrackCollection> allTrackerTracks;

};
#endif
