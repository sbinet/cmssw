#ifndef MCTruth_DTHitAssociator_h
#define MCTruth_DTHitAssociator_h

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "DataFormats/Common/interface/Handle.h"
#include "SimDataFormats/EncodedEventId/interface/EncodedEventId.h"
#include "SimDataFormats/TrackingHit/interface/PSimHitContainer.h"
#include "DataFormats/TrackingRecHit/interface/TrackingRecHit.h"
#include "DataFormats/DTRecHit/interface/DTRecHitCollection.h"
#include "DataFormats/DTRecHit/interface/DTRecHit1D.h"
#include "DataFormats/MuonDetId/interface/DTWireId.h"
#include "DataFormats/DTDigi/interface/DTDigiCollection.h"
#include "SimDataFormats/DigiSimLinks/interface/DTDigiSimLinkCollection.h"
#include "Geometry/DTGeometry/interface/DTGeometry.h"

#include <vector>
#include <map>
#include <string>

class DTHitAssociator {

 public:
  typedef std::pair <uint32_t, EncodedEventId> SimHitIdpr;
  typedef std::pair<PSimHit,bool> PSimHit_withFlag;
  typedef std::map<DTWireId, std::vector<PSimHit_withFlag> > SimHitMap;
  typedef std::map<DTWireId, std::vector<DTRecHit1DPair> > RecHitMap;
  typedef std::map<DTWireId, std::vector<DTDigi> > DigiMap;
  typedef std::map<DTWireId, std::vector<DTDigiSimLink> > LinksMap;

  DTHitAssociator(const edm::Event&, const edm::EventSetup&, const edm::ParameterSet&); 
  virtual ~DTHitAssociator(){}

  std::vector<SimHitIdpr> associateHitId(const TrackingRecHit & hit);
  std::vector<SimHitIdpr> associateDTHitId(const DTRecHit1D * dtrechit);
  
  std::vector<const PSimHit *> associateHit(const TrackingRecHit & hit);

  SimHitMap mapOfSimHit;
  RecHitMap mapOfRecHit;
  DigiMap mapOfDigi;
  LinksMap mapOfLinks;

 private:
  bool dumpDT;
  bool crossingframe;
  bool links_exist;
  bool associatorByWire;
  
  bool SimHitOK(const edm::ESHandle<DTGeometry> &, const PSimHit &);

};

#endif



