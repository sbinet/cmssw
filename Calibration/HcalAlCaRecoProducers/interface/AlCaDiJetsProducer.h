#ifndef AlCaDiJetsProducer_AlCaHcalProducers_h
#define AlCaDiJetsProducer_AlCaHcalProducers_h


// -*- C++ -*-


// system include files
#include <memory>
#include <string>
// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/Common/interface/Ref.h"
#include "DataFormats/CaloTowers/interface/CaloTowerCollection.h"
#include "DataFormats/DetId/interface/DetId.h"

#include "Geometry/Records/interface/IdealGeometryRecord.h"
#include "Geometry/CaloGeometry/interface/CaloGeometry.h"
#include "DataFormats/GeometryVector/interface/GlobalPoint.h"
#include "DataFormats/CaloTowers/interface/CaloTowerDetId.h"
#include "DataFormats/HcalRecHit/interface/HcalRecHitCollections.h"
#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"
#include "RecoTracker/TrackProducer/interface/TrackProducerBase.h"
#include "TrackingTools/TransientTrack/interface/TransientTrack.h"
#include "DataFormats/JetReco/interface/CaloJetCollection.h"
#include "Geometry/CaloGeometry/interface/CaloGeometry.h"

//
// class declaration
//
namespace edm {
  class ParameterSet;
  class Event;
  class EventSetup;
}

//namespace cms
//{

class AlCaDiJetsProducer : public edm::EDProducer {
   public:
      explicit AlCaDiJetsProducer(const edm::ParameterSet&);
      ~AlCaDiJetsProducer();

      virtual void beginJob(const edm::EventSetup& ) ;

      virtual void produce(edm::Event &, const edm::EventSetup&);
   private:
      // ----------member data ---------------------------
     std::vector<edm::InputTag> ecalLabels_;
     std::vector<edm::InputTag> mInputCalo;
     bool allowMissingInputs_;
     edm::InputTag hbheLabel_;
     edm::InputTag hoLabel_;
     edm::InputTag hfLabel_;
     std::string m_inputTrackLabel;
 // Calo geometry
  const CaloGeometry* geo;

};
//}// end namespace cms
#endif
