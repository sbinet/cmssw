// -*- C++ -*-
//
// Package:    L1CaloTriggerProducer
// Class:      FastL1CaloSim
// 
/**\class FastL1CaloSim FastL1CaloSim.cc FastSimuluation/L1CaloTriggerProducer/src/FastL1CaloSim.cc

 Description: Fast Simulation of the L1 Calo Trigger.

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  Chi Nhan Nguyen
//         Created:  Mon Feb 19 13:25:24 CST 2007
// $Id: FastL1CaloSim.cc,v 1.6 2007/07/27 19:35:18 chinhan Exp $
//
//

#include "FastSimulation/L1CaloTriggerProducer/interface/FastL1CaloSim.h"


//
// constructors and destructor
//
FastL1CaloSim::FastL1CaloSim(const edm::ParameterSet& iConfig)
{
  //register your products
  /* old labels
  produces<l1extra::L1EtMissParticle>("MET");
  produces<l1extra::L1JetParticleCollection>("TauJets");
  produces<l1extra::L1JetParticleCollection>("CenJets");
  produces<l1extra::L1JetParticleCollection>("ForJets");
  produces<l1extra::L1EmParticleCollection>("Egammas");
  produces<l1extra::L1EmParticleCollection>("isoEgammas");
  */

  produces<l1extra::L1EtMissParticle>();
  produces<l1extra::L1JetParticleCollection>("Tau");
  produces<l1extra::L1JetParticleCollection>("Central");
  produces<l1extra::L1JetParticleCollection>("Forward");
  produces<l1extra::L1EmParticleCollection>("NonIsolated");
  produces<l1extra::L1EmParticleCollection>("Isolated");
  produces<l1extra::L1MuonParticleCollection>(); // muon is dummy for L1extraParticleMap!

  m_AlgorithmSource = iConfig.getParameter<std::string>("AlgorithmSource");

  // No BitInfos for release versions
  /*
  m_DoBitInfo = iConfig.getParameter<bool>("DoBitInfo");

  if (m_DoBitInfo)
    produces<FastL1BitInfoCollection>("FastL1BitInfos");
  */

  //now do what ever other initialization is needed
  m_L1GlobalAlgo = new FastL1GlobalAlgo(iConfig);
}

FastL1CaloSim::~FastL1CaloSim()
{
  delete m_L1GlobalAlgo;
}


//
// member functions
//

// ------------ method called to produce the data  ------------
void
FastL1CaloSim::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  //edm::LogInfo("FastL1CaloSim::produce()");

  if (m_AlgorithmSource == "RecHits") {
    m_L1GlobalAlgo->FillL1Regions(iEvent, iSetup);
  } else if (m_AlgorithmSource == "TrigPrims") {
    m_L1GlobalAlgo->FillL1RegionsTP(iEvent,iSetup);
  } else {
    std::cerr<<"AlgorithmSource not valid: "<<m_AlgorithmSource<<std::endl;
    return;
  }
  //m_L1GlobalAlgo->FillMET(iEvent); // using CaloTowers
  m_L1GlobalAlgo->FillMET();     // using Regions
  m_L1GlobalAlgo->FillJets(iSetup);
  m_L1GlobalAlgo->FillEgammas(iEvent);
  
  /*
  if (m_DoBitInfo)
    m_L1GlobalAlgo->FillBitInfos();
  */

  std::auto_ptr<l1extra::L1EtMissParticle> METResult(new l1extra::L1EtMissParticle);
  std::auto_ptr<l1extra::L1JetParticleCollection> TauJetResult(new l1extra::L1JetParticleCollection);
  std::auto_ptr<l1extra::L1JetParticleCollection> CenJetResult(new l1extra::L1JetParticleCollection);
  std::auto_ptr<l1extra::L1JetParticleCollection> ForJetResult(new l1extra::L1JetParticleCollection);
  std::auto_ptr<l1extra::L1EmParticleCollection> EgammaResult(new l1extra::L1EmParticleCollection);
  std::auto_ptr<l1extra::L1EmParticleCollection> isoEgammaResult(new l1extra::L1EmParticleCollection);
  // muon is dummy!
  std::auto_ptr<l1extra::L1MuonParticleCollection> muonDummy(new l1extra::L1MuonParticleCollection);
  //std::auto_ptr<FastL1BitInfoCollection> FastL1BitInfoResult(new FastL1BitInfoCollection);

  //
  *METResult = m_L1GlobalAlgo->getMET();
  for (int i=0; i<std::min(4,(int)m_L1GlobalAlgo->getTauJets().size()); i++) {
    TauJetResult->push_back(m_L1GlobalAlgo->getTauJets().at(i));
  }
  for (int i=0; i<std::min(4,(int)m_L1GlobalAlgo->getCenJets().size()); i++) {
    CenJetResult->push_back(m_L1GlobalAlgo->getCenJets().at(i));
  }
  for (int i=0; i<std::min(4,(int)m_L1GlobalAlgo->getForJets().size()); i++) {
    ForJetResult->push_back(m_L1GlobalAlgo->getForJets().at(i));
  }
  for (int i=0; i<std::min(4,(int)m_L1GlobalAlgo->getEgammas().size()); i++) {
    EgammaResult->push_back(m_L1GlobalAlgo->getEgammas().at(i));
  }
  for (int i=0; i<std::min(4,(int)m_L1GlobalAlgo->getisoEgammas().size()); i++) {
    isoEgammaResult->push_back(m_L1GlobalAlgo->getisoEgammas().at(i));
  }

  /*
  if (m_DoBitInfo) {
    for (int i=0; i<(int)m_L1GlobalAlgo->getBitInfos().size(); i++) {
      FastL1BitInfoResult->push_back(m_L1GlobalAlgo->getBitInfos().at(i));
    }
  }
  */

  // put the collections into the event
  /* old labels
  iEvent.put(METResult,"MET");
  iEvent.put(TauJetResult,"TauJets");
  iEvent.put(CenJetResult,"CenJets");
  iEvent.put(ForJetResult,"ForJets");
  iEvent.put(EgammaResult,"Egammas");
  iEvent.put(isoEgammaResult,"isoEgammas");
  */
  iEvent.put(METResult);
  iEvent.put(TauJetResult,"Tau");
  iEvent.put(CenJetResult,"Central");
  iEvent.put(ForJetResult,"Forward");
  iEvent.put(EgammaResult,"NonIsolated");
  iEvent.put(isoEgammaResult,"Isolated");
  iEvent.put(muonDummy);

  /*
  if (m_DoBitInfo) 
    iEvent.put(FastL1BitInfoResult,"FastL1BitInfos");
  */
}


//define this as a plug-in
DEFINE_FWK_MODULE(FastL1CaloSim);
