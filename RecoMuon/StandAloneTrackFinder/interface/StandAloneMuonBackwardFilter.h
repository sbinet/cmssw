#ifndef RecoMuon_StandAloneTrackFinder_StandAloneMuonBackwardFilter_H
#define RecoMuon_StandAloneTrackFinder_StandAloneMuonBackwardFilter_H

/** \class StandAloneMuonBackwardFilter
 *  The outward-inward fitter (starts from StandAloneMuonRefitter outermost state).
 *
 *  $Date: 2006/05/19 15:24:35 $
 *  $Revision: 1.3 $
 *  \author R. Bellan - INFN Torino
 */

namespace edm {class ParameterSet; class EventSetup; class Event;}

class StandAloneMuonBackwardFilter {
public:
  /// Constructor
  StandAloneMuonBackwardFilter(const edm::ParameterSet& par);

  /// Destructor
  virtual ~StandAloneMuonBackwardFilter(){};

  // Operations
  virtual void setES(const edm::EventSetup& setup);

  /// Pass the Event to the algo at each event
  virtual void setEvent(const edm::Event& event);


protected:

private:

};
#endif


