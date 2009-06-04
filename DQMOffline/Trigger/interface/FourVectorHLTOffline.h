#ifndef FOURVECTORHLTOFFLINE_H
#define FOURVECTORHLTOFFLINE_H
// -*- C++ -*-
//
// Package:    FourVectorHLTOffline
// Class:      FourVectorHLTOffline
// 
/**\class FourVectorHLTOffline FourVectorHLTOffline.cc DQM/FourVectorHLTOffline/src/FourVectorHLTOffline.cc

 Description: This is a DQM source meant to plot high-level HLT trigger
 quantities as stored in the HLT results object TriggerResults

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  Jeffrey Berryhill
//         Created:  June 2008
// Rewritten by: Vladimir Rekovic
//         Date:  May 2009
//
// $Id: FourVectorHLTOffline.h,v 1.18 2009/03/27 03:13:58 berryhil Exp $
//
//


// system include files
#include <memory>
#include <unistd.h>
#include <vector>


// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "DataFormats/HLTReco/interface/TriggerEvent.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"

#include "DQMServices/Core/interface/DQMStore.h"
#include "DQMServices/Core/interface/MonitorElement.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

// added VR
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/Framework/interface/Run.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/ESHandle.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
//#include "HLTriggerOffline/Common/interface/FourVectorHLTOffline.h"

#include "DataFormats/HLTReco/interface/TriggerObject.h"
#include "FWCore/Framework/interface/TriggerNames.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/HLTReco/interface/TriggerEvent.h"
#include "DataFormats/HLTReco/interface/TriggerTypeDefs.h"
#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"

#include "DataFormats/EgammaCandidates/interface/GsfElectronFwd.h"
#include "DataFormats/EgammaCandidates/interface/PhotonFwd.h"
#include "DataFormats/EgammaCandidates/interface/Photon.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackExtra.h"
#include "DataFormats/MuonReco/interface/MuonFwd.h"
#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/JetReco/interface/CaloJetCollection.h"
#include "DataFormats/JetReco/interface/CaloJet.h"
#include "DataFormats/TauReco/interface/CaloTauFwd.h"
#include "DataFormats/TauReco/interface/CaloTau.h"
#include "DataFormats/METReco/interface/CaloMETCollection.h"
#include "DataFormats/METReco/interface/CaloMET.h"
#include "DataFormats/BTauReco/interface/JetTag.h"

/*
// MC
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/HepMCCandidate/interface/GenParticleFwd.h"
#include "DataFormats/JetReco/interface/GenJetCollection.h"
#include "DataFormats/METReco/interface/GenMETCollection.h"
#include "DataFormats/METReco/interface/GenMET.h"
*/

#include "DataFormats/Math/interface/deltaR.h"

#include "DQMServices/Core/interface/MonitorElement.h"

#include <iostream>
#include <fstream>
#include <vector>

// $Id: FourVectorHLTOffline.h,v 1.12 2009/06/03 23:38:10 rekovic Exp $
// See header file for information. 
/*
#include "TMath.h"

#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/Framework/interface/Run.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/ESHandle.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/HLTReco/interface/TriggerObject.h"
#include "FWCore/Framework/interface/TriggerNames.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/HLTReco/interface/TriggerEvent.h"
#include "DataFormats/HLTReco/interface/TriggerTypeDefs.h"
#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"
*/

/*
#include "DataFormats/EgammaCandidates/interface/GsfElectronFwd.h"
#include "DataFormats/EgammaCandidates/interface/PhotonFwd.h"
#include "DataFormats/EgammaCandidates/interface/Photon.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackExtra.h"
#include "DataFormats/MuonReco/interface/MuonFwd.h"
#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/JetReco/interface/CaloJetCollection.h"
#include "DataFormats/JetReco/interface/CaloJet.h"
#include "DataFormats/TauReco/interface/CaloTauFwd.h"
#include "DataFormats/TauReco/interface/CaloTau.h"
#include "DataFormats/METReco/interface/CaloMETCollection.h"
*/
/*
#include "DataFormats/METReco/interface/CaloMET.h"
#include "DataFormats/BTauReco/interface/JetTag.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/HepMCCandidate/interface/GenParticleFwd.h"
#include "DataFormats/JetReco/interface/GenJetCollection.h"
*/
/*
#include "DataFormats/METReco/interface/GenMETCollection.h"
*/
/*
#include "DataFormats/METReco/interface/GenMET.h"
*/

/*
#include "DataFormats/Math/interface/deltaR.h"

#include "DQMServices/Core/interface/MonitorElement.h"

#include <map>
#include <utility>
*/

using namespace std;
using namespace edm;
using namespace trigger;

typedef multimap<float,int> fimmap ;
typedef set<fimmap , less<fimmap> > mmset;


class FourVectorHLTOffline : public edm::EDAnalyzer {
   public:
      explicit FourVectorHLTOffline(const edm::ParameterSet&);
      ~FourVectorHLTOffline();

      void cleanDRMatchSet(mmset& tempSet);

   private:
      virtual void beginJob(const edm::EventSetup&) ;
      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      virtual void endJob() ;

      // BeginRun
      void beginRun(const edm::Run& run, const edm::EventSetup& c);

      // EndRun
      void endRun(const edm::Run& run, const edm::EventSetup& c);


      // ----------member data --------------------------- 
      int nev_;
      DQMStore * dbe_;

      MonitorElement* total_;

      bool plotAll_;
      bool resetMe_;
      int currentRun_;
 
      unsigned int nBins_; 
      double ptMin_ ;
      double ptMax_ ;
      
      double electronEtaMax_;
      double electronEtMin_;
      double electronDRMatch_;
      double muonEtaMax_;
      double muonEtMin_;
      double muonDRMatch_;
      double tauEtaMax_;
      double tauEtMin_;
      double tauDRMatch_;
      double jetEtaMax_;
      double jetEtMin_;
      double jetDRMatch_;
      double bjetEtaMax_;
      double bjetEtMin_;
      double bjetDRMatch_;
      double photonEtaMax_;
      double photonEtMin_;
      double photonDRMatch_;
      double trackEtaMax_;
      double trackEtMin_;
      double trackDRMatch_;
      double metMin_;
      double htMin_;
      double sumEtMin_;

      std::vector<std::pair<std::string, std::string> > custompathnamepairs_;


      std::string dirname_;
      std::string processname_;
      bool monitorDaemon_;
      int theHLTOutputType;
      edm::InputTag triggerSummaryLabel_;
      edm::InputTag triggerResultsLabel_;
      HLTConfigProvider hltConfig_;
      // data across paths
      MonitorElement* scalersSelect;
      // helper class to store the data path

      class PathInfo {
	PathInfo():
	  pathIndex_(-1), denomPathName_("unset"), pathName_("unset"), l1pathName_("unset"), filterName_("unset"), processName_("unset"), objectType_(-1)
	  {};
      public:
	void setHistos(
                       MonitorElement* const NMc, 
                       MonitorElement* const mcEtMc, 
                       MonitorElement* const mcEtavsmcPhiMc,  
                       MonitorElement* const NOn, 
                       MonitorElement* const onEtOn, 
                       MonitorElement* const onEtavsonPhiOn,  
                       MonitorElement* const NOff, 
                       MonitorElement* const offEtOff, 
                       MonitorElement* const offEtavsoffPhiOff,
                       MonitorElement* const NL1, 
                       MonitorElement* const l1EtL1, 
		       MonitorElement* const l1Etavsl1PhiL1,
                       MonitorElement* const NL1On, 
                       MonitorElement* const l1EtL1On, 
		       MonitorElement* const l1Etavsl1PhiL1On,
                       MonitorElement* const NL1Off,   
                       MonitorElement* const offEtL1Off, 
		       MonitorElement* const offEtavsoffPhiL1Off,
                       MonitorElement* const NOnOff, 
                       MonitorElement* const offEtOnOff, 
		       MonitorElement* const offEtavsoffPhiOnOff,
                       MonitorElement* const NL1Mc, 
                       MonitorElement* const mcEtL1Mc, 
		       MonitorElement* const mcEtavsmcPhiL1Mc,
                       MonitorElement* const NOffMc, 
                       MonitorElement* const mcEtOffMc, 
		       MonitorElement* const mcEtavsmcPhiOffMc,
                       MonitorElement* const NOnMc, 
                       MonitorElement* const mcEtOnMc, 
		       MonitorElement* const mcEtavsmcPhiOnMc,
                       MonitorElement* const NL1OnUM, 
                       MonitorElement* const l1EtL1OnUM, 
		       MonitorElement* const l1Etavsl1PhiL1OnUM,
                       MonitorElement* const NL1OffUM,   
                       MonitorElement* const offEtL1OffUM, 
		       MonitorElement* const offEtavsoffPhiL1OffUM,
                       MonitorElement* const NOnOffUM, 
                       MonitorElement* const offEtOnOffUM, 
		       MonitorElement* const offEtavsoffPhiOnOffUM,
                       MonitorElement* const NL1McUM, 
                       MonitorElement* const mcEtL1McUM, 
		       MonitorElement* const mcEtavsmcPhiL1McUM,
                       MonitorElement* const NOffMcUM, 
                       MonitorElement* const mcEtOffMcUM, 
		       MonitorElement* const mcEtavsmcPhiOffMcUM,
                       MonitorElement* const NOnMcUM, 
                       MonitorElement* const mcEtOnMcUM, 
		       MonitorElement* const mcEtavsmcPhiOnMcUM,
                       MonitorElement* const mcDRL1Mc, 
                       MonitorElement* const mcDROnMc, 
                       MonitorElement* const mcDROffMc, 
                       MonitorElement* const offDRL1Off, 
                       MonitorElement* const offDROnOff, 
                       MonitorElement* const l1DRL1On 
					 ) {
	  NMc_ = NMc;
	  mcEtMc_ = mcEtMc;
	  mcEtavsmcPhiMc_ = mcEtavsmcPhiMc;
          NOn_ = NOn;
	  onEtOn_ = onEtOn;
	  onEtavsonPhiOn_ = onEtavsonPhiOn;
          NOff_ = NOff;
	  offEtOff_ = offEtOff;
	  offEtavsoffPhiOff_ = offEtavsoffPhiOff;
          NL1_ = NL1;
	  l1EtL1_ = l1EtL1;
	  l1Etavsl1PhiL1_ = l1Etavsl1PhiL1;
          NL1On_ = NL1On;
	  l1EtL1On_ = l1EtL1On;
	  l1Etavsl1PhiL1On_ = l1Etavsl1PhiL1On;
          NL1Off_ = NL1Off;
	  offEtL1Off_ = offEtL1Off;
	  offEtavsoffPhiL1Off_ = offEtavsoffPhiL1Off;
          NOnOff_ = NOnOff;
	  offEtOnOff_ = offEtOnOff;
	  offEtavsoffPhiOnOff_ = offEtavsoffPhiOnOff;
          NL1Mc_ = NL1Mc;
	  mcEtL1Mc_ = mcEtL1Mc;
	  mcEtavsmcPhiL1Mc_ = mcEtavsmcPhiL1Mc;
          NOffMc_ = NOffMc;
	  mcEtOffMc_ = mcEtOffMc;
	  mcEtavsmcPhiOffMc_ = mcEtavsmcPhiOffMc;
          NOnMc_ = NOnMc;
	  mcEtOnMc_ = mcEtOnMc;
	  mcEtavsmcPhiOnMc_ = mcEtavsmcPhiOnMc;
          NL1OnUM_ = NL1OnUM;
	  l1EtL1OnUM_ = l1EtL1OnUM;
	  l1Etavsl1PhiL1OnUM_ = l1Etavsl1PhiL1OnUM;
          NL1OffUM_ = NL1OffUM;
	  offEtL1OffUM_ = offEtL1OffUM;
	  offEtavsoffPhiL1OffUM_ = offEtavsoffPhiL1OffUM;
          NOnOffUM_ = NOnOffUM;
	  offEtOnOffUM_ = offEtOnOffUM;
	  offEtavsoffPhiOnOffUM_ = offEtavsoffPhiOnOffUM;
          NL1McUM_ = NL1McUM;
	  mcEtL1McUM_ = mcEtL1McUM;
	  mcEtavsmcPhiL1McUM_ = mcEtavsmcPhiL1McUM;
          NOffMcUM_ = NOffMcUM;
	  mcEtOffMcUM_ = mcEtOffMcUM;
	  mcEtavsmcPhiOffMcUM_ = mcEtavsmcPhiOffMcUM;
          NOnMcUM_ = NOnMcUM;
	  mcEtOnMcUM_ = mcEtOnMcUM;
	  mcEtavsmcPhiOnMcUM_ = mcEtavsmcPhiOnMcUM;
    mcDRL1Mc_   =  mcDRL1Mc; 
    mcDROnMc_   =  mcDROnMc; 
    mcDROffMc_  =  mcDROffMc; 
    offDRL1Off_ =  offDRL1Off; 
    offDROnOff_ =  offDROnOff; 
    l1DRL1On_   =  l1DRL1On;
	}
	MonitorElement * getNMcHisto() {
	  return NMc_;
	}
	MonitorElement * getMcEtMcHisto() {
	  return mcEtMc_;
	}
	MonitorElement * getMcEtaVsMcPhiMcHisto() {
	  return mcEtavsmcPhiMc_;
	}
	MonitorElement * getNOnHisto() {
	  return NOn_;
	}
	MonitorElement * getOnEtOnHisto() {
	  return onEtOn_;
	}
	MonitorElement * getOnEtaVsOnPhiOnHisto() {
	  return onEtavsonPhiOn_;
	}
	MonitorElement * getNOffHisto() {
	  return NOff_;
	}
	MonitorElement * getOffEtOffHisto() {
	  return offEtOff_;
	}
	MonitorElement * getOffEtaVsOffPhiOffHisto() {
	  return offEtavsoffPhiOff_;
	}
	MonitorElement * getNL1Histo() {
	  return NL1_;
	}
	MonitorElement * getL1EtL1Histo() {
	  return l1EtL1_;
	}
	MonitorElement * getL1EtaVsL1PhiL1Histo() {
	  return l1Etavsl1PhiL1_;
	}
	MonitorElement * getNL1OnHisto() {
	  return NL1On_;
	}
	MonitorElement * getL1EtL1OnHisto() {
	  return l1EtL1On_;
	}
	MonitorElement * getL1EtaVsL1PhiL1OnHisto() {
	  return l1Etavsl1PhiL1On_;
	}
	MonitorElement * getNL1OffHisto() {
	  return NL1Off_;
	}
	MonitorElement * getOffEtL1OffHisto() {
	  return offEtL1Off_;
	}
	MonitorElement * getOffEtaVsOffPhiL1OffHisto() {
	  return offEtavsoffPhiL1Off_;
	}
	MonitorElement * getNOnOffHisto() {
	  return NOnOff_;
	}
	MonitorElement * getOffEtOnOffHisto() {
	  return offEtOnOff_;
	}
	MonitorElement * getOffEtaVsOffPhiOnOffHisto() {
	  return offEtavsoffPhiOnOff_;
	}
	MonitorElement * getNL1McHisto() {
	  return NL1Mc_;
	}
	MonitorElement * getMcEtL1McHisto() {
	  return mcEtL1Mc_;
	}
	MonitorElement * getMcEtaVsMcPhiL1McHisto() {
	  return mcEtavsmcPhiL1Mc_;
	}

	MonitorElement * getNOffMcHisto() {
	  return NOffMc_;
	}
	MonitorElement * getMcEtOffMcHisto() {
	  return mcEtOffMc_;
	}
	MonitorElement * getMcEtaVsMcPhiOffMcHisto() {
	  return mcEtavsmcPhiOffMc_;
	}

	MonitorElement * getNOnMcHisto() {
	  return NOnMc_;
	}
	MonitorElement * getMcEtOnMcHisto() {
	  return mcEtOnMc_;
	}
	MonitorElement * getMcEtaVsMcPhiOnMcHisto() {
	  return mcEtavsmcPhiOnMc_;
	}
	MonitorElement * getNL1OnUMHisto() {
	  return NL1OnUM_;
	}
	MonitorElement * getL1EtL1OnUMHisto() {
	  return l1EtL1OnUM_;
	}
	MonitorElement * getL1EtaVsL1PhiL1OnUMHisto() {
	  return l1Etavsl1PhiL1OnUM_;
	}
	MonitorElement * getNL1OffUMHisto() {
	  return NL1OffUM_;
	}
	MonitorElement * getOffEtL1OffUMHisto() {
	  return offEtL1OffUM_;
	}
	MonitorElement * getOffEtaVsOffPhiL1OffUMHisto() {
	  return offEtavsoffPhiL1OffUM_;
	}
	MonitorElement * getNOnOffUMHisto() {
	  return NOnOffUM_;
	}
	MonitorElement * getOffEtOnOffUMHisto() {
	  return offEtOnOffUM_;
	}
	MonitorElement * getOffEtaVsOffPhiOnOffUMHisto() {
	  return offEtavsoffPhiOnOffUM_;
	}
	MonitorElement * getNL1McUMHisto() {
	  return NL1McUM_;
	}
	MonitorElement * getMcEtL1McUMHisto() {
	  return mcEtL1McUM_;
	}
	MonitorElement * getMcEtaVsMcPhiL1McUMHisto() {
	  return mcEtavsmcPhiL1McUM_;
	}

	MonitorElement * getNOffMcUMHisto() {
	  return NOffMcUM_;
	}
	MonitorElement * getMcEtOffMcUMHisto() {
	  return mcEtOffMcUM_;
	}
	MonitorElement * getMcEtaVsMcPhiOffMcUMHisto() {
	  return mcEtavsmcPhiOffMcUM_;
	}

	MonitorElement * getNOnMcUMHisto() {
	  return NOnMcUM_;
	}
	MonitorElement * getMcEtOnMcUMHisto() {
	  return mcEtOnMcUM_;
	}
	MonitorElement * getMcEtaVsMcPhiOnMcUMHisto() {
	  return mcEtavsmcPhiOnMcUM_;
	}
	MonitorElement * getMcDRL1McHisto() {
	  return mcDRL1Mc_;
	}
	MonitorElement * getOffDRL1OffHisto() {
	  return offDRL1Off_;
	}
	MonitorElement * getOffDROnOffHisto() {
	  return offDROnOff_;
	}
	MonitorElement * getMcDROnMcHisto() {
	  return mcDROnMc_;
	}
	MonitorElement * getMcDROffMcHisto() {
	  return mcDROffMc_;
	}
	MonitorElement * getL1DROnL1Histo() {
	  return l1DRL1On_;
	}
	const std::string getLabel(void ) const {
	  return filterName_;
	}
	void setLabel(std::string labelName){
	  filterName_ = labelName;
          return;
	}
	const std::string getPath(void ) const {
	  return pathName_;
	}
	const std::string getl1Path(void ) const {
	  return l1pathName_;
	}
	const std::string getDenomPath(void ) const {
	  return denomPathName_;
	}
	const std::string getProcess(void ) const {
	  return processName_;
	}
	const int getObjectType(void ) const {
	  return objectType_;
	}

        const edm::InputTag getTag(void) const{
	  edm::InputTag tagName(filterName_,"",processName_);
          return tagName;
	}
	~PathInfo() {};
	PathInfo(std::string denomPathName, std::string pathName, std::string l1pathName, std::string filterName, std::string processName, size_t type, float ptmin, 
		 float ptmax):
	  denomPathName_(denomPathName), pathName_(pathName), l1pathName_(l1pathName), filterName_(filterName), processName_(processName), objectType_(type),
	  NMc_(0), mcEtMc_(0), mcEtavsmcPhiMc_(0),
          NOn_(0), onEtOn_(0), onEtavsonPhiOn_(0),
	  NOff_(0), offEtOff_(0), offEtavsoffPhiOff_(0),
	  NL1_(0), l1EtL1_(0), l1Etavsl1PhiL1_(0),
          NL1On_(0), l1EtL1On_(0), l1Etavsl1PhiL1On_(0),
	  NL1Off_(0), offEtL1Off_(0), offEtavsoffPhiL1Off_(0),
	  NOnOff_(0), offEtOnOff_(0), offEtavsoffPhiOnOff_(0),
	  NL1Mc_(0), mcEtL1Mc_(0), mcEtavsmcPhiL1Mc_(0),
	  NOffMc_(0), mcEtOffMc_(0), mcEtavsmcPhiOffMc_(0),
	  NOnMc_(0), mcEtOnMc_(0), mcEtavsmcPhiOnMc_(0),
          NL1OnUM_(0), l1EtL1OnUM_(0), l1Etavsl1PhiL1OnUM_(0),
	  NL1OffUM_(0), offEtL1OffUM_(0), offEtavsoffPhiL1OffUM_(0),
	  NOnOffUM_(0), offEtOnOffUM_(0), offEtavsoffPhiOnOffUM_(0),
	  NL1McUM_(0), mcEtL1McUM_(0), mcEtavsmcPhiL1McUM_(0),
	  NOffMcUM_(0), mcEtOffMcUM_(0), mcEtavsmcPhiOffMcUM_(0),
	  NOnMcUM_(0), mcEtOnMcUM_(0), mcEtavsmcPhiOnMcUM_(0),
    mcDRL1Mc_(0), mcDROnMc_(0), mcDROffMc_(0), offDRL1Off_(0),
    offDROnOff_(0), l1DRL1On_(0),
	  ptmin_(ptmin), ptmax_(ptmax)
	  {
	  };
	  PathInfo(std::string denomPathName, std::string pathName, std::string l1pathName, std::string filterName, std::string processName, size_t type,
		   MonitorElement *NMc,
		   MonitorElement *mcEtMc,
		   MonitorElement *mcEtavsmcPhiMc,
		   MonitorElement *NOn,
		   MonitorElement *onEtOn,
		   MonitorElement *onEtavsonPhiOn,
		   MonitorElement *NOff,
		   MonitorElement *offEtOff,
		   MonitorElement *offEtavsoffPhiOff,
		   MonitorElement *NL1,
		   MonitorElement *l1EtL1,
		   MonitorElement *l1Etavsl1PhiL1,
		   MonitorElement *NL1On,
		   MonitorElement *l1EtL1On,
		   MonitorElement *l1Etavsl1PhiL1On,
		   MonitorElement *NL1Off,
		   MonitorElement *offEtL1Off,
		   MonitorElement *offEtavsoffPhiL1Off,
		   MonitorElement *NOnOff,
		   MonitorElement *offEtOnOff,
		   MonitorElement *offEtavsoffPhiOnOff,
		   MonitorElement *NL1Mc,
		   MonitorElement *mcEtL1Mc,
		   MonitorElement *mcEtavsmcPhiL1Mc,
		   MonitorElement *NOffMc,
		   MonitorElement *mcEtOffMc,
		   MonitorElement *mcEtavsmcPhiOffMc,
		   MonitorElement *NOnMc,
		   MonitorElement *mcEtOnMc,
		   MonitorElement *mcEtavsmcPhiOnMc,
		   MonitorElement *NL1OnUM,
		   MonitorElement *l1EtL1OnUM,
		   MonitorElement *l1Etavsl1PhiL1OnUM,
		   MonitorElement *NL1OffUM,
		   MonitorElement *offEtL1OffUM,
		   MonitorElement *offEtavsoffPhiL1OffUM,
		   MonitorElement *NOnOffUM,
		   MonitorElement *offEtOnOffUM,
		   MonitorElement *offEtavsoffPhiOnOffUM,
		   MonitorElement *NL1McUM,
		   MonitorElement *mcEtL1McUM,
		   MonitorElement *mcEtavsmcPhiL1McUM,
		   MonitorElement *NOffMcUM,
		   MonitorElement *mcEtOffMcUM,
		   MonitorElement *mcEtavsmcPhiOffMcUM,
		   MonitorElement *NOnMcUM,
		   MonitorElement *mcEtOnMcUM,
		   MonitorElement *mcEtavsmcPhiOnMcUM,
       MonitorElement *mcDRL1Mc, 
       MonitorElement *mcDROnMc, 
       MonitorElement *mcDROffMc, 
       MonitorElement *offDRL1Off, 
       MonitorElement *offDROnOff, 
       MonitorElement *l1DRL1On,
		   float ptmin, float ptmax
		   ):
	    denomPathName_(denomPathName), pathName_(pathName), l1pathName_(l1pathName), filterName_(filterName), processName_(processName), objectType_(type),
	    NMc_(NMc), mcEtMc_(mcEtMc), mcEtavsmcPhiMc_(mcEtavsmcPhiMc),
            NOn_(NOn), onEtOn_(onEtOn), onEtavsonPhiOn_(onEtavsonPhiOn),
	    NOff_(NOff), offEtOff_(offEtOff), offEtavsoffPhiOff_(offEtavsoffPhiOff),
	    NL1_(NL1), l1EtL1_(l1EtL1), l1Etavsl1PhiL1_(l1Etavsl1PhiL1),
            NL1On_(NL1On), l1EtL1On_(l1EtL1On), l1Etavsl1PhiL1On_(l1Etavsl1PhiL1On),
	    NL1Off_(NL1Off), offEtL1Off_(offEtL1Off), offEtavsoffPhiL1Off_(offEtavsoffPhiL1Off),
	    NOnOff_(NOnOff), offEtOnOff_(offEtOnOff), offEtavsoffPhiOnOff_(offEtavsoffPhiOnOff),
	    NL1Mc_(NL1Mc), mcEtL1Mc_(mcEtL1Mc), mcEtavsmcPhiL1Mc_(mcEtavsmcPhiL1Mc),
	    NOffMc_(NOffMc), mcEtOffMc_(mcEtOffMc), mcEtavsmcPhiOffMc_(mcEtavsmcPhiOffMc),
	    NOnMc_(NOnMc), mcEtOnMc_(mcEtOnMc), mcEtavsmcPhiOnMc_(mcEtavsmcPhiOnMc),
            NL1OnUM_(NL1OnUM), l1EtL1OnUM_(l1EtL1OnUM), l1Etavsl1PhiL1OnUM_(l1Etavsl1PhiL1OnUM),
	    NL1OffUM_(NL1OffUM), offEtL1OffUM_(offEtL1OffUM), offEtavsoffPhiL1OffUM_(offEtavsoffPhiL1OffUM),
	    NOnOffUM_(NOnOffUM), offEtOnOffUM_(offEtOnOffUM), offEtavsoffPhiOnOffUM_(offEtavsoffPhiOnOffUM),
	    NL1McUM_(NL1McUM), mcEtL1McUM_(mcEtL1McUM), mcEtavsmcPhiL1McUM_(mcEtavsmcPhiL1McUM),
	    NOffMcUM_(NOffMcUM), mcEtOffMcUM_(mcEtOffMcUM), mcEtavsmcPhiOffMcUM_(mcEtavsmcPhiOffMcUM),
	    NOnMcUM_(NOnMcUM), mcEtOnMcUM_(mcEtOnMcUM), mcEtavsmcPhiOnMcUM_(mcEtavsmcPhiOnMcUM),
    mcDRL1Mc_(mcDRL1Mc), 
    mcDROnMc_(mcDROnMc), 
    mcDROffMc_(mcDROffMc), 
    offDRL1Off_(offDRL1Off), 
    offDROnOff_(offDROnOff), 
    l1DRL1On_(l1DRL1On),
	    ptmin_(ptmin), ptmax_(ptmax)
	    {};
	    bool operator==(const std::string v) 
	    {
	      return v==filterName_;
	    }
      private:
	  int pathIndex_;
	  std::string denomPathName_;
	  std::string pathName_;
	  std::string l1pathName_;
	  std::string filterName_;
	  std::string processName_;
	  int objectType_;

	  // we don't own this data
	  MonitorElement *NMc_, *mcEtMc_, *mcEtavsmcPhiMc_;
    MonitorElement *NOn_, *onEtOn_, *onEtavsonPhiOn_;
	  MonitorElement *NOff_, *offEtOff_, *offEtavsoffPhiOff_;
	  MonitorElement *NL1_, *l1EtL1_, *l1Etavsl1PhiL1_;
	  MonitorElement *NL1On_, *l1EtL1On_, *l1Etavsl1PhiL1On_;
	  MonitorElement *NL1Off_, *offEtL1Off_, *offEtavsoffPhiL1Off_;
	  MonitorElement *NOnOff_, *offEtOnOff_, *offEtavsoffPhiOnOff_;
	  MonitorElement *NL1Mc_, *mcEtL1Mc_, *mcEtavsmcPhiL1Mc_;
	  MonitorElement *NOffMc_, *mcEtOffMc_, *mcEtavsmcPhiOffMc_;
	  MonitorElement *NOnMc_, *mcEtOnMc_, *mcEtavsmcPhiOnMc_;
	  MonitorElement *NL1OnUM_, *l1EtL1OnUM_, *l1Etavsl1PhiL1OnUM_;
	  MonitorElement *NL1OffUM_, *offEtL1OffUM_, *offEtavsoffPhiL1OffUM_;
	  MonitorElement *NOnOffUM_, *offEtOnOffUM_, *offEtavsoffPhiOnOffUM_;
	  MonitorElement *NL1McUM_, *mcEtL1McUM_, *mcEtavsmcPhiL1McUM_;
	  MonitorElement *NOffMcUM_, *mcEtOffMcUM_, *mcEtavsmcPhiOffMcUM_;
	  MonitorElement *NOnMcUM_, *mcEtOnMcUM_, *mcEtavsmcPhiOnMcUM_;
    MonitorElement *mcDRL1Mc_, *mcDROnMc_, *mcDROffMc_,
                   *offDRL1Off_, *offDROnOff_, *l1DRL1On_;

	  float ptmin_, ptmax_;

	  const int index() { 
	    return pathIndex_;
	  }
	  const int type() { 
	    return objectType_;
	  }
      public:
	  float getPtMin() const { return ptmin_; }
	  float getPtMax() const { return ptmax_; }
      };

      // simple collection - just 
      class PathInfoCollection: public std::vector<PathInfo> {
      public:
	PathInfoCollection(): std::vector<PathInfo>() 
	  {};
	  std::vector<PathInfo>::iterator find(std::string pathName) {
	    return std::find(begin(), end(), pathName);
	  }
      };
      PathInfoCollection hltPaths_;


};

template <class T> 
class objMon {
public:
    objMon() { EtaMax_= 2.5; EtMin_=3.0; GenJetsFlag_ = false; BJetsFlag_ = false; }
		void setLimits(float etaMax, float etMin, float drMatch) 
		{
		 EtaMax_= etaMax; 
		 EtMin_= etMin; 
		 DRMatch_= drMatch;
		}
		void setTriggerType(vector<int> trigType) { triggerType_ = trigType; }
		void pushTriggerType(int trigType) { triggerType_.push_back(trigType); }
		void setL1TriggerType(vector<int> trigType) { l1triggerType_ = trigType; }
		void pushL1TriggerType(int trigType) { l1triggerType_.push_back(trigType); }
		void setPath(FourVectorHLTOffline::PathInfoCollection::iterator v) { v_ = v; }
		void setReco(Handle<T> offColl) { offColl_ = offColl; }
		/*
		void setMC(Handle<GenParticleCollection> genParticles, int pdgId, int status)
		{

      genParticles_ = genParticles;
			pdgId_ = pdgId;
			pdgStatus_ = status;
			
		}
		*/

    //void fillMC();
    void fillOff();
		void monitorL1(const Vids & idtype, const Keys & l1k, const TriggerObjectCollection & toc);
    void monitorDenominator(FourVectorHLTOffline::PathInfoCollection::iterator v, bool l1accept, const Vids & idtype, const Keys & l1k, const TriggerObjectCollection& toc);

		void fillL1OffMatch(FourVectorHLTOffline* fv);
		//void fillL1MCMatch(FourVectorHLTOffline* fv);
		void fillL1Match(FourVectorHLTOffline* fv)
		{
		  fillL1OffMatch(fv);
		  //fillL1MCMatch(fv);
		}

		void monitorOnline(const Vids & idtype, const Keys & l1k, Keys::const_iterator ki, const TriggerObjectCollection & toc, int & NOn);
    //void monitorOffline(FourVectorHLTOffline* fv);
		void fillOnOffMatch(FourVectorHLTOffline* fv);
		//void fillOnMCMatch(FourVectorHLTOffline* fv);
		void fillOnL1Match(FourVectorHLTOffline* fv, const Keys & l1k,  const TriggerObjectCollection & toc);
		void fillOnlineMatch(FourVectorHLTOffline* fv, const Keys & l1k,  const TriggerObjectCollection & toc)
		{
      if(! isTriggerType(v_->getObjectType()) ) return;
	    fillOnOffMatch(fv);
	    //fillOnMCMatch(fv);
	    fillOnL1Match(fv, l1k, toc);
	  }

    //void fillOffMCMatch(FourVectorHLTOffline* fv);
		void fillOffMatch(FourVectorHLTOffline* fv)
		{
      if(! isTriggerType(v_->getObjectType()) ) return;
		  //fillOffMCMatch(fv);
		}
		void clearSets();

		bool isTriggerType(int t);
		bool isL1TriggerType(int t);
    //bool hasBPartonInCone(GenJetCollection::const_iterator gjet, float coneSize);

    mmset L1OffDRMatchSet;
    mmset L1MCDRMatchSet;
    mmset OnOffDRMatchSet;
    mmset OnMCDRMatchSet;
    mmset OnL1DRMatchSet;
    mmset OffMCDRMatchSet;


		/*
		void setGenJets(bool flag, Handle<GenJetCollection> genJets ) 
		{ 
		  GenJetsFlag_ = flag;  
			genJets_ = genJets; 
		}
		*/
		void setBJetsFlag(bool flag) 
		{ 
		  BJetsFlag_ = flag; 
		}
		

private:

		int   pdgId_;
		int   pdgStatus_;

    float EtaMax_;
    float EtMin_;

		float DRMatch_;

		bool GenJetsFlag_;
		bool BJetsFlag_;

		vector<int> triggerType_;
		vector<int> l1triggerType_;

    Handle<T> offColl_;

    //Handle<GenParticleCollection> genParticles_;
    //Handle<GenJetCollection> genJets_;
    FourVectorHLTOffline::PathInfoCollection::iterator v_;

};

template <class T> 
bool objMon<T>::isTriggerType(int t)
{
  bool rc = false;

  for(vector<int>::const_iterator it = triggerType_.begin(); it != triggerType_.end(); ++it)
	{
        //LogTrace("FourVectorHLTOffline") << " monitorDenominator()::isTriggerTypeC()::  path type = " << t << "  trigger type = " << *it  << endl;

	 if(t == *it) { rc = true; break; }

  } // end for

	return rc;

}


template <class T> 
bool objMon<T>::isL1TriggerType(int t)
{
  bool rc = false;

  for(vector<int>::const_iterator it = l1triggerType_.begin(); it != l1triggerType_.end(); ++it)
	{

	 if(t == *it) { rc = true; break; }

  } // end for

	return rc;

}

template <class T> 
void objMon<T>::monitorDenominator(FourVectorHLTOffline::PathInfoCollection::iterator v, bool l1accept, const Vids & idtype, const Keys & l1k, const TriggerObjectCollection& toc)
{
        //LogTrace("FourVectorHLTOffline") << " monitorDenominator()  "  << endl;

        //LogTrace("FourVectorHLTOffline") << " monitorDenominator()::setPath(v)  "  << endl;
        setPath(v);
				
        //LogTrace("FourVectorHLTOffline") << " monitorDenominator()::isTriggerType()  "  << endl;
				if(! isTriggerType(v_->getObjectType()) ) return;

        //LogTrace("FourVectorHLTOffline") << " monitorDenominator()::fillMC()  "  << endl;
	      //fillMC();
        //LogTrace("FourVectorHLTOffline") << " monitorDenominator()::fillOff()  "  << endl;

	      fillOff();

        if (l1accept) monitorL1(idtype, l1k, toc);


}

template <class T> 
void objMon<T>::fillOff()
{

 int NOff = 0;
 if(! offColl_.isValid()) return;

 typedef typename T::const_iterator const_iterator;
 for( const_iterator iter = offColl_->begin(), iend = offColl_->end(); iter != iend; ++iter )
 {

	 NOff++;

   if (fabs(iter->eta()) <= EtaMax_ && iter->pt() >=  EtMin_ )
   {
	   

     v_->getOffEtOffHisto()->Fill(iter->pt());
     v_->getOffEtaVsOffPhiOffHisto()->Fill(iter->eta(), iter->phi());

   }

 }

 return;

}

/*
template <class T> 
void objMon<T>::fillMC()
{

 if(GenJetsFlag_)
 {

	if (! genJets_.isValid()) return;

  for(GenJetCollection::const_iterator gjet=genJets_->begin(); gjet!=genJets_->end(); gjet++) {

    if (fabs(gjet->eta()) <= EtaMax_ && gjet->pt() >= EtMin_ ){

			  if (BJetsFlag_) {
			 
				 // this jet must have b in the cone
         if( !hasBPartonInCone(gjet,0.7)) {

				   continue;

				 }
				}


        //NMc++; 
        v_->getMcEtMcHisto()->Fill(gjet->pt());
        v_->getMcEtaVsMcPhiMcHisto()->Fill(gjet->eta(),gjet->phi());

    }

  } // end for

	return;

 } // end if GenJetsFlag_


 if(! genParticles_.isValid()) return;

 for(size_t i = 0; i < genParticles_->size(); ++ i) {

   const GenParticle & p = (*genParticles_)[i];
   if (abs(p.pdgId()) == pdgId_ && p.status() == pdgStatus_ && fabs(p.eta()) <= EtaMax_ && p.pt() >= EtMin_ ){
    
		//   NMc++;
    v_->getMcEtMcHisto()->Fill(p.pt());
    v_->getMcEtaVsMcPhiMcHisto()->Fill(p.eta(),p.phi());

	 }

 } // end for

 return;

}
*/

template <class T> 
void objMon<T>::monitorL1(const Vids & idtype, const Keys & l1k, const TriggerObjectCollection& toc)
{

 int NL1=0;
 //LogTrace("FourVectorHLTOffline") << " fillL1()  "  << endl;
 Vids::const_iterator idtypeiter = idtype.begin(); 
 for (Keys::const_iterator l1ki = l1k.begin(); l1ki !=l1k.end(); ++l1ki ) {
   //LogTrace("FourVectorHLTOffline") << "fillL1(): idtype = " << *idtypeiter << " TriggerL1Mu = " <<  TriggerL1Mu << endl;

	 TriggerObject l1FV = toc[*l1ki];
	 if(isL1TriggerType(*idtypeiter))
	 {

			NL1++;

      //LogTrace("FourVectorHLTOffline") << "fillL1(): eta = " << fabs(toc[*l1ki].eta()) <<  " pt = " <<  toc[*l1ki].pt() << endl;

      if (fabs(l1FV.eta()) <= EtaMax_ && l1FV.pt() >= EtMin_)
      { 
		  
        //LogTrace("FourVectorHLTOffline") << " filling L1 histos  "  << endl;
        v_->getL1EtL1Histo()->Fill(l1FV.pt());
	      v_->getL1EtaVsL1PhiL1Histo()->Fill(l1FV.eta(), l1FV.phi());

	    }

	    if (offColl_.isValid())
      {

        //LogTrace("FourVectorHLTOffline") << " fillL1() offColl_ is valid "  << endl;
        fimmap L1OffDRMatchMap;
	      int j=0;
        typedef typename T::const_iterator const_iterator;
        for( const_iterator iter = offColl_->begin(), iend = offColl_->end(); iter != iend; ++iter )
        {

          if (fabs(iter->eta()) <= EtaMax_ && iter->pt() >=  EtMin_ )
          {

				    // fill UM histos (no matching required)
				    if(NL1 == 1) {

	            v_->getOffEtL1OffUMHisto()->Fill(iter->pt());
	            v_->getOffEtaVsOffPhiL1OffUMHisto()->Fill(iter->eta(),iter->phi());

						}

						// make maps of matched objects
	          float dR = reco::deltaR(iter->eta(),iter->phi(),l1FV.eta(),l1FV.phi());
	          if ( dR < 1.0) 
						{

             //LogTrace("FourVectorHLTOffline") << " filling L1-Off map  "  << endl;
		         L1OffDRMatchMap.insert(std::pair<float,int>(dR,j));

						}

          }

	        j++;

        }

        if(! L1OffDRMatchMap.empty())  L1OffDRMatchSet.insert(L1OffDRMatchMap);

	     }

			 /*
			 // fillL1MCUM
			 ////////////

	    if (GenJetsFlag_ && genJets_.isValid())
			{
        //LogTrace("FourVectorHLTOffline") << " fillL1() genParticles_ is valid "  << endl;

	      fimmap L1MCDRMatchMap;
	      int j=0;

        for(GenJetCollection::const_iterator gjet=genJets_->begin(); gjet!=genJets_->end(); gjet++) {
       
          if (fabs(gjet->eta()) <= EtaMax_ && gjet->pt() >= EtMin_ ){

			       if (BJetsFlag_) { 
						  
							 // this jet must have b in the cone
						   if(! hasBPartonInCone(gjet,0.7)) {
							  
								continue;

							 }
						 }

				     // fill UM histos (no matching required)
				     if(NL1 == 1) {

	             v_->getMcEtL1McUMHisto()->Fill(gjet->pt());
	             v_->getMcEtaVsMcPhiL1McUMHisto()->Fill(gjet->eta(),gjet->phi());
						
						 }

						 // make maps of matched objects
	           float dR = reco::deltaR(gjet->eta(),gjet->phi(),l1FV.eta(),l1FV.phi());
	           if ( dR < 1.0) 
						 {

		          L1MCDRMatchMap.insert(pair<float,int>(dR,j));

						 }

       
          } // end if eta, Et

	        j++;
       
        } // end for genJets

        if(! L1MCDRMatchMap.empty()) L1MCDRMatchSet.insert(L1MCDRMatchMap);

	    } // end if genJets


	    if ( ! GenJetsFlag_ && genParticles_.isValid())
			{
        //LogTrace("FourVectorHLTOffline") << " fillL1() genParticles_ is valid "  << endl;

	      fimmap L1MCDRMatchMap;
        for(size_t i = 0; i < genParticles_->size(); ++ i) 
				{

           const GenParticle & p = (*genParticles_)[i];
           if (abs(p.pdgId()) == pdgId_ && p.status() == pdgStatus_ && fabs(p.eta()) <= EtaMax_ && p.pt() >= EtMin_)
					 { 

				     // fill UM histos (no matching required)
				     if(NL1 == 1) {

	             v_->getMcEtL1McUMHisto()->Fill(p.pt());
	             v_->getMcEtaVsMcPhiL1McUMHisto()->Fill(p.eta(),p.phi());

						 }

						 // make maps of matched objects
	           float dR = reco::deltaR(p.eta(),p.phi(),l1FV.eta(),l1FV.phi());
	           if ( dR < 1.0) 
						 {

              //LogTrace("FourVectorHLTOffline") << " filling L1-MC map  "  << endl;
		          L1MCDRMatchMap.insert(pair<float,int>(dR,i));

						 }

	         } // end if pdg, status, eta, pt
        } // end for

        if(! L1MCDRMatchMap.empty()) L1MCDRMatchSet.insert(L1MCDRMatchMap);

	    } // end if genParticle_
			*/

	   } // end if isL1TriggerType
     ++idtypeiter;

	 } // end for l1ki

}

template <class T> 
void objMon<T>::monitorOnline(const Vids & idtype, const Keys & l1k, Keys::const_iterator ki, const TriggerObjectCollection & toc, int & NOn)
{

		 if(! isTriggerType(v_->getObjectType()) ) return;

		 TriggerObject onlineFV = toc[*ki];

	   NOn++;    

     if (fabs(onlineFV.eta()) <= EtaMax_ && onlineFV.pt() >= EtMin_)
     { 

       v_->getOnEtOnHisto()->Fill(onlineFV.pt());
	     v_->getOnEtaVsOnPhiOnHisto()->Fill(onlineFV.eta(), onlineFV.phi());

	   }

	   if (offColl_.isValid())
     {


        fimmap OnOffDRMatchMap;
	      int j=0;
        typedef typename T::const_iterator const_iterator;
        for( const_iterator iter = offColl_->begin(), iend = offColl_->end(); iter != iend; ++iter )
        {

					/*
					float recoEta;
					float recoPhi;
					float recoPt;

			    if (BJetsFlag_) { 

					  recoEta = (*iter).first->eta();
					  recoPhi = (*iter).first->phi();
					  recoPt = (*iter).first->pt();

						continue;


					}
					*/
          if (fabs(iter->eta()) <= EtaMax_ && iter->pt() >=  EtMin_ )
          {

				    // fill UM histos (no matching required)
				    if(NOn == 1) {

	            v_->getOffEtOnOffUMHisto()->Fill(iter->pt());
	            v_->getOffEtaVsOffPhiOnOffUMHisto()->Fill(iter->eta(),iter->phi());

						}

						 // make maps of matched objects
	          float dR = reco::deltaR(iter->eta(),iter->phi(),onlineFV.eta(),onlineFV.phi());
	          if ( dR < 1.0)
						{

		          OnOffDRMatchMap.insert(std::pair<float,int>(dR,j));

						}

          }

	        j++;


        }

        if(! OnOffDRMatchMap.empty())  OnOffDRMatchSet.insert(OnOffDRMatchMap);

	     }


       fimmap OnL1DRMatchMap;
	     int j=0;
       Vids::const_iterator idtypeiter = idtype.begin(); 
       for (Keys::const_iterator l1ki = l1k.begin(); l1ki !=l1k.end(); ++l1ki ) 
			 {

			   

	       if(isL1TriggerType(*idtypeiter))
	       {

		       TriggerObject l1FV = toc[*l1ki];

	         if ( fabs(l1FV.eta()) <= EtaMax_ && l1FV.pt() >= EtMin_ )
           {

				      // fill UM histos (no matching required)
				      if(NOn == 1) {

	             v_->getL1EtL1OnUMHisto()->Fill(l1FV.pt());
	             v_->getL1EtaVsL1PhiL1OnUMHisto()->Fill(l1FV.eta(),l1FV.phi());

						   }


               float dR = reco::deltaR(l1FV.eta(),l1FV.phi(),onlineFV.eta(),onlineFV.phi());

	             if ( dR < 1.0) 
						   {

	               OnL1DRMatchMap.insert(std::pair<float,int>(dR,j));

						   }

						 } // end if l1FV eta, pt

          } // end if isL1TriggerType

	        ++idtypeiter;
	        j++;

	    } // end for

      if(! OnL1DRMatchMap.empty()) OnL1DRMatchSet.insert(OnL1DRMatchMap);


			/*
			// fillOnMCUM
			//////////////

	    if (GenJetsFlag_ && genJets_.isValid())
			{
        //LogTrace("FourVectorHLTOffline") << " fillL1() genParticles_ is valid "  << endl;

	      fimmap OnMCDRMatchMap;
	      int j=0;

        for(GenJetCollection::const_iterator gjet=genJets_->begin(); gjet!=genJets_->end(); gjet++) {
       
          if (fabs(gjet->eta()) <= EtaMax_ && gjet->pt() >= EtMin_ ){
       
			       if (BJetsFlag_) { 
						  
							 // this jet must have b in the cone
						   if(! hasBPartonInCone(gjet,0.7)) {
							  
								continue;

							 }
						 }
				     // fill UM histos (no matching required)
				     if(NOn == 1) {

	             v_->getMcEtOnMcUMHisto()->Fill(gjet->pt());
	             v_->getMcEtaVsMcPhiOnMcUMHisto()->Fill(gjet->eta(),gjet->phi());
						
						 }

						 // make maps of matched objects
	           float dR = reco::deltaR(gjet->eta(),gjet->phi(),onlineFV.eta(),onlineFV.phi());
	           if ( dR < 1.0) 
						 {

              //LogTrace("FourVectorHLTOffline") << " filling L1-MC map  "  << endl;
		          OnMCDRMatchMap.insert(pair<float,int>(dR,j));

						 }
       
          } // end if eta, Et

	        j++;
       
        } // end for genJets

        if(! OnMCDRMatchMap.empty()) OnMCDRMatchSet.insert(OnMCDRMatchMap);

	    } // end if genJets

	    if (!GenJetsFlag_ && genParticles_.isValid())
			{

	      fimmap OnMCDRMatchMap;
        for(size_t i = 0; i < genParticles_->size(); ++ i) 
				{

           const GenParticle & p = (*genParticles_)[i];
           if (abs(p.pdgId()) == pdgId_ && p.status() == pdgStatus_ && fabs(p.eta()) <= EtaMax_ && p.pt() >= EtMin_)
					 { 

				     // fill UM histos (no matching required)
				     if(NOn == 1) {

	             v_->getMcEtOnMcUMHisto()->Fill(p.pt());
	             v_->getMcEtaVsMcPhiOnMcUMHisto()->Fill(p.eta(),p.phi());

						 }

						 // make maps of matched objects
	           float dR = reco::deltaR(p.eta(),p.phi(),onlineFV.eta(),onlineFV.phi());
	           if ( dR < 1.0)
						 {

		          OnMCDRMatchMap.insert(pair<float,int>(dR,i));
	            //NOnMc++;

						 }
	         } // end if
        } // end for

        if(! OnMCDRMatchMap.empty()) OnMCDRMatchSet.insert(OnMCDRMatchMap);

	    } 
			*/

}

/*
template <class T> 
void objMon<T>::monitorOffline(FourVectorHLTOffline* fv)
{

 if(! isTriggerType(v_->getObjectType()) ) return;

 int numNOff = 0;
 if(! offColl_.isValid()) return;

 typedef typename T::const_iterator const_iterator;
 for( const_iterator iter = offColl_->begin(), iend = offColl_->end(); iter != iend; ++iter )
 {

					numNOff++;

	        if (GenJetsFlag_ && genJets_.isValid())
		      {
             //LogTrace("FourVectorHLTOffline") << " fillL1() genParticles_ is valid "  << endl;

             fimmap OffMCDRMatchMap;
	           int j=0;

             for(GenJetCollection::const_iterator gjet=genJets_->begin(); gjet!=genJets_->end(); gjet++) {
            
               if (fabs(gjet->eta()) <= EtaMax_ && gjet->pt() >= EtMin_ ){
            
			           if (BJetsFlag_) { 
						  
							     // this jet must have b in the cone
						       if(! hasBPartonInCone(gjet,0.7)) {
							    
								     continue;

							     }
						     }

		       	     // fill UM histos (no matching required)
 	               if(numNOff == 1) {

                   v_->getMcEtOffMcUMHisto()->Fill(gjet->pt());
                   v_->getMcEtaVsMcPhiOffMcUMHisto()->Fill(gjet->eta(),gjet->phi());
		       			
		       			 }

		       			 // make maps of matched objects
	                float dR = reco::deltaR(gjet->eta(),gjet->phi(),iter->eta(),iter->phi());
	                if ( dR < 1.0) 
		       			 {

                   //LogTrace("FourVectorHLTOffline") << " filling L1-MC map  "  << endl;
		               OffMCDRMatchMap.insert(pair<float,int>(dR,j));

		       			 }
            
               } // end if eta, Et

	             j++;
            
             } // end for genJets

             if(! OffMCDRMatchMap.empty()) OffMCDRMatchSet.insert(OffMCDRMatchMap);

	        } // end if genJets

          if (!GenJetsFlag_ && genParticles_.isValid())
 	        {
            //LogTrace("FourVectorHLTOffline") << " fillOff() genParticles_ is valid "  << endl;

            fimmap OffMCDRMatchMap;
            for(size_t i = 0; i < genParticles_->size(); ++ i) 
 	         {

               const GenParticle & p = (*genParticles_)[i];
               if (abs(p.pdgId()) == pdgId_ && p.status() == pdgStatus_ && fabs(p.eta()) <= EtaMax_ && p.pt() >= EtMin_)
 	         	 { 

 	              // fill UM histos (no matching required)
 	              if(numNOff == 1) {

                   v_->getMcEtOffMcUMHisto()->Fill(p.pt());
                   v_->getMcEtaVsMcPhiOffMcUMHisto()->Fill(p.eta(),p.phi());

 	         		 }

 	         		 // make maps of matched objects
                 float dR = reco::deltaR(p.eta(),p.phi(),iter->eta(),iter->phi());
                 if ( dR < 1.0) 
 	         		 {

                  //LogTrace("FourVectorHLTOffline") << " filling Off-MC map  "  << endl;
                  OffMCDRMatchMap.insert(pair<float,int>(dR,i));

 	         		 }

               } // end if pdg, status, eta, pt
            } // end for

            if(! OffMCDRMatchMap.empty()) OffMCDRMatchSet.insert(OffMCDRMatchMap);

          } // end if genParticle_

 } // end for offline objects

}
*/

template <class T> 
void objMon<T>::fillL1OffMatch(FourVectorHLTOffline* fv)
{

 if(! offColl_.isValid()) return;


	// clean the set L1-Off
  if(L1OffDRMatchSet.size() > 1) fv->cleanDRMatchSet(L1OffDRMatchSet);
	// now fill histos
  for ( mmset::iterator setIter = L1OffDRMatchSet.begin( ); setIter != L1OffDRMatchSet.end( ); setIter++ ) 
  {

       fimmap tempMap = *setIter;
         
       fimmap::iterator it = tempMap.begin(); 
       int i  = (*it).second ;
			 float dR = (*it).first;
	     v_->getOffDRL1OffHisto()->Fill(dR);

       if (dR > DRMatch_) continue;
       typedef typename T::const_iterator const_iterator;
			 const_iterator iter = offColl_->begin();
       for (int count = 0; count < i; count++) iter++;

       //LogTrace("FourVectorHLTOffline") << " Filling Electron L1Off   LOffDRMatchMap.insert(std::pair<float,int>(dR,j)): pt = " << iter->pt() << endl;

	     //NL1Off++;
	     v_->getOffEtL1OffHisto()->Fill(iter->pt());
	     v_->getOffEtaVsOffPhiL1OffHisto()->Fill(iter->eta(),iter->phi());

	}

  return;
}

/*
template <class T> 
void objMon<T>::fillL1MCMatch(FourVectorHLTOffline* fv)
{

  if(GenJetsFlag_)
  {
  
   if (! genJets_.isValid()) return;

	 // clean the set L1-MC
	 if(L1MCDRMatchSet.size() > 1) fv->cleanDRMatchSet(L1MCDRMatchSet);

	// now fill histos
  for ( mmset::iterator setIter = L1MCDRMatchSet.begin( ); setIter != L1MCDRMatchSet.end( ); setIter++ ) 
  {
  
       fimmap tempMap = *setIter;
         
       fimmap::iterator it = tempMap.begin(); 
       int i  = (*it).second ;
			 float dR = (*it).first;

       v_->getMcDRL1McHisto()->Fill(dR);

       if (dR > DRMatch_) continue;

       GenJetCollection::const_iterator gjet=genJets_->begin(); 
       for (int count = 0; count < i; count++) gjet++;
  
  
       //NMc++; 
       v_->getMcEtL1McHisto()->Fill(gjet->pt());
       v_->getMcEtaVsMcPhiL1McHisto()->Fill(gjet->eta(),gjet->phi());
  
	 } // end for set

	 return;
  
  } // end if GenJetsFlag_


	if(! genParticles_.isValid()) return;

	// clean the set L1-MC
	if(L1MCDRMatchSet.size() > 1) fv->cleanDRMatchSet(L1MCDRMatchSet);

	// now fill histos
  for ( mmset::iterator setIter = L1MCDRMatchSet.begin( ); setIter != L1MCDRMatchSet.end( ); setIter++ ) 
  {

     fimmap tempMap = *setIter;
       
     fimmap::iterator it = tempMap.begin(); 
     int i  = (*it).second ;
		 float dR = (*it).first;

     v_->getMcDRL1McHisto()->Fill(dR);

     if (dR > DRMatch_) continue;

     const GenParticle & p = (*genParticles_)[i];
	   //NL1Mc++;
	   v_->getMcEtL1McHisto()->Fill(p.pt());
	   v_->getMcEtaVsMcPhiL1McHisto()->Fill(p.eta(),p.phi());

	}

}
*/

template <class T> 
void objMon<T>::fillOnOffMatch(FourVectorHLTOffline* fv)
{

 if(! offColl_.isValid()) return;


	// clean the set L1-Off
  if(OnOffDRMatchSet.size() > 1) fv->cleanDRMatchSet(OnOffDRMatchSet);
	// now fill histos
  for ( mmset::iterator setIter = OnOffDRMatchSet.begin( ); setIter != OnOffDRMatchSet.end( ); setIter++ ) 
  {

       fimmap tempMap = *setIter;
         
       fimmap::iterator it = tempMap.begin(); 
       int i  = (*it).second ;
			 float dR = (*it).first;
	     v_->getOffDROnOffHisto()->Fill(dR);

       if (dR > DRMatch_) continue;

       typedef typename T::const_iterator const_iterator;
			 const_iterator iter = offColl_->begin();
       for (int count = 0; count < i; count++) iter++;

	     //NL1Off++;
	     v_->getOffEtOnOffHisto()->Fill(iter->pt());
	     v_->getOffEtaVsOffPhiOnOffHisto()->Fill(iter->eta(),iter->phi());

	}

  return;

}

/*
template <class T> 
void objMon<T>::fillOnMCMatch(FourVectorHLTOffline* fv)
{
  if(GenJetsFlag_)
  {
  
   if (! genJets_.isValid()) return;

	 // clean the set L1-MC
	 if(OnMCDRMatchSet.size() > 1) fv->cleanDRMatchSet(OnMCDRMatchSet);

	// now fill histos
  for ( mmset::iterator setIter = OnMCDRMatchSet.begin( ); setIter != OnMCDRMatchSet.end( ); setIter++ ) 
  {
  
       fimmap tempMap = *setIter;
         
       fimmap::iterator it = tempMap.begin(); 
       int i  = (*it).second ;
			 float dR = (*it).first;
	     v_->getMcDROnMcHisto()->Fill(dR);

       if (dR > DRMatch_) continue;

       GenJetCollection::const_iterator gjet=genJets_->begin(); 
       for (int count = 0; count < i; count++) gjet++;
  
  
       //NMc++; 
       v_->getMcEtOnMcHisto()->Fill(gjet->pt());
       v_->getMcEtaVsMcPhiOnMcHisto()->Fill(gjet->eta(),gjet->phi());
  
	 } // end for set

	 return;
  
  } // end if GenJetsFlag_


	if(! genParticles_.isValid()) return;

	// clean the set L1-MC
	if(OnMCDRMatchSet.size() > 1) fv->cleanDRMatchSet(OnMCDRMatchSet);

	// now fill histos
  for ( mmset::iterator setIter = OnMCDRMatchSet.begin( ); setIter != OnMCDRMatchSet.end( ); setIter++ ) 
  {

     fimmap tempMap = *setIter;
       
     fimmap::iterator it = tempMap.begin(); 
     int i  = (*it).second ;
		 float dR = (*it).first;
	   v_->getMcDROnMcHisto()->Fill(dR);

     if (dR > DRMatch_) continue;
          
     const GenParticle & p = (*genParticles_)[i];
	   //NL1Mc++;
	   v_->getMcEtOnMcHisto()->Fill(p.pt());
	   v_->getMcEtaVsMcPhiOnMcHisto()->Fill(p.eta(),p.phi());

	}

}
*/

/*
template <class T> 
void objMon<T>::fillOffMCMatch(FourVectorHLTOffline* fv)
{

  if(GenJetsFlag_)
  {
  
   if (! genJets_.isValid()) return;

	 // clean the set L1-MC
	 if(OffMCDRMatchSet.size() > 1) fv->cleanDRMatchSet(OffMCDRMatchSet);

	// now fill histos
  for ( mmset::iterator setIter = OffMCDRMatchSet.begin( ); setIter != OffMCDRMatchSet.end( ); setIter++ ) 
  {
  
       fimmap tempMap = *setIter;
         
       fimmap::iterator it = tempMap.begin(); 
       int i  = (*it).second ;
			 float dR = (*it).first;
	     v_->getMcDROffMcHisto()->Fill(dR);

       if (dR > DRMatch_) continue;

       GenJetCollection::const_iterator gjet=genJets_->begin(); 
       for (int count = 0; count < i; count++) gjet++;
  
       //NMc++; 
       v_->getMcEtOffMcHisto()->Fill(gjet->pt());
       v_->getMcEtaVsMcPhiOffMcHisto()->Fill(gjet->eta(),gjet->phi());
  
	 } // end for set

	 return;
  
  } // end if GenJetsFlag_



	if(! genParticles_.isValid()) return;

  if(! offColl_.isValid()) return;

	// clean the set L1-MC
	if(OffMCDRMatchSet.size() > 1) fv->cleanDRMatchSet(OffMCDRMatchSet);

	// now fill histos
  for ( mmset::iterator setIter = OffMCDRMatchSet.begin( ); setIter != OffMCDRMatchSet.end( ); setIter++ ) 
  {

     fimmap tempMap = *setIter;
       
     fimmap::iterator it = tempMap.begin(); 
     int i  = (*it).second ;
		 float dR = (*it).first;
	   v_->getMcDROffMcHisto()->Fill(dR);

     if (dR > DRMatch_) continue;
          
     const GenParticle & p = (*genParticles_)[i];
	   //NL1Mc++;
	   v_->getMcEtOffMcHisto()->Fill(p.pt());
	   v_->getMcEtaVsMcPhiOffMcHisto()->Fill(p.eta(),p.phi());

	}

}
*/

template <class T> 
void objMon<T>::fillOnL1Match(FourVectorHLTOffline* fv, const Keys & l1k,  const TriggerObjectCollection & toc)
{

	// clean the set On-L1
	if(OnL1DRMatchSet.size() > 1) fv->cleanDRMatchSet(OnL1DRMatchSet);
	// now fill histos
  for ( mmset::iterator setIter = OnL1DRMatchSet.begin( ); setIter != OnL1DRMatchSet.end( ); setIter++ ) 
  {

    fimmap tempMap = *setIter;
      
    fimmap::iterator it = tempMap.begin(); 
    int i  = (*it).second ;
		float dR = (*it).first;
	  v_->getL1DROnL1Histo()->Fill(dR);

    if (dR > DRMatch_) continue;

    trigger::Keys::const_iterator l1ki = l1k.begin();
    for (int count = 0; count < i; count++) l1ki++;

	  //NL1On++;
	  v_->getL1EtL1OnHisto()->Fill(toc[*l1ki].pt());
	  v_->getL1EtaVsL1PhiL1OnHisto()->Fill(toc[*l1ki].eta(),toc[*l1ki].phi());

	}


}

/*
template <class T> 
bool objMon<T>::hasBPartonInCone(GenJetCollection::const_iterator gjet, float coneSize)
{

  bool rc = false;
  if (! genParticles_.isValid()) return rc;

  for(size_t i = 0; i < genParticles_->size(); ++ i) {
	
    const GenParticle & p = (*genParticles_)[i];
    if (abs(p.pdgId()) == 5){ 

	    if (reco::deltaR(p.eta(),p.phi(),gjet->eta(),gjet->phi()) < 0.7){

        rc = true;

	    }

		 }

	}
  

	return rc;

}
*/

template <class T> 
void objMon<T>::clearSets()
{

     L1OffDRMatchSet.clear();
     L1MCDRMatchSet.clear();
     OnOffDRMatchSet.clear();
     OnMCDRMatchSet.clear();
     OnL1DRMatchSet.clear();
     OffMCDRMatchSet.clear();

}


#endif
