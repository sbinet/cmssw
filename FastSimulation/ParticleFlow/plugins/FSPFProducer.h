#ifndef FastSimulation_ParticleFlow_FSPFProducer_h_
#define FastSimulation_ParticleFlow_FSPFProducer_h_

// system include files
#include <string>

// framework include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

class PFCandidate;

class FSPFProducer : public edm::EDProducer {
 public:
  explicit FSPFProducer(const edm::ParameterSet&);
  ~FSPFProducer();
  
  virtual void produce(edm::Event&, const edm::EventSetup&);
  virtual void beginJob();
  virtual void beginRun(edm::Run &, const edm::EventSetup &);

 private:

  edm::InputTag labelPFCandidateCollection_;
  double barrel_correction;
  double endcap_correction;

};

#endif
