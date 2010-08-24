// -*- C++ -*-
//
// Package:    SimpleEventDumper
// Class:      SimpleEventDumper
// 
/**\class SimpleEventDumper SimpleEventDumper.cc TopQuarkAnalysis/SimpleEventDumper/src/SimpleEventDumper.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Andrea Giammanco,40 4-B20,+41227671567,
//         Created:  Sun Aug 15 18:30:03 CEST 2010
// $Id: SimpleEventDumper.cc,v 1.9 2010/08/24 13:12:12 giamman Exp $
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/Candidate/interface/Particle.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/MET.h"
#include "DataFormats/METReco/interface/MET.h"
#include "DataFormats/METReco/interface/CaloMET.h"
#include "DataFormats/METReco/interface/PFMET.h"

#include "TrackingTools/IPTools/interface/IPTools.h"
#include "TrackingTools/Records/interface/TransientTrackRecord.h"
#include "TrackingTools/TransientTrack/interface/TransientTrack.h"
#include "TrackingTools/TransientTrack/interface/TransientTrackBuilder.h"

//
// class declaration
//
using namespace edm;
using namespace std;

class SimpleEventDumper : public edm::EDAnalyzer {
   public:
      explicit SimpleEventDumper(const edm::ParameterSet&);
      ~SimpleEventDumper();
  

   private:
      virtual void beginJob() ;
      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      virtual void endJob() ;
  double MT(double lx, double ly, double nx, double ny);
  double Mtop(double lx, double ly, double lz, double nx, double ny, double jx, double jy, double jz);
  double AddQuadratically( const double nr1, const double nr2 );
  double DeltaPhi(double v1, double v2);
  double GetDeltaR(double eta1, double eta2, double phi1, double phi2);
      // ----------member data ---------------------------
  edm::InputTag vertices_;
  edm::InputTag muonSource_;
  edm::InputTag electronSource_;
  edm::InputTag patmetSource_;
  edm::InputTag calometSource_;
  edm::InputTag pfmetSource_;
  edm::InputTag tcmetSource_;
  edm::InputTag patjetSource_;
  edm::InputTag pfjetSource_;
  edm::InputTag pfpatjetSource_;
  edm::Handle<std::vector<pat::Muon> > muons;
  edm::Handle<std::vector<pat::Electron> > electrons;
  edm::Handle<std::vector<pat::MET> > patmets;
  edm::Handle<std::vector<reco::CaloMET> > calomets;
  edm::Handle<std::vector<reco::PFMET> > pfmets;
  edm::Handle<std::vector<reco::MET> > tcmets;
  edm::Handle<std::vector<pat::Jet> > patjets;
  edm::Handle<std::vector<reco::PFJet> > pfjets;
  edm::Handle<std::vector<pat::Jet> > pfpatjets;
  double jet_threshold;
  bool l5corr,l5corr_inclGlu;
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
SimpleEventDumper::SimpleEventDumper(const edm::ParameterSet& iConfig)

{
  vertices_       = iConfig.getParameter<edm::InputTag>("verticesSource");
  muonSource_     = iConfig.getParameter<edm::InputTag>("muonSource");
  electronSource_     = iConfig.getParameter<edm::InputTag>("electronSource");
  patmetSource_     = iConfig.getParameter<edm::InputTag>("patmetSource");
  calometSource_     = iConfig.getParameter<edm::InputTag>("calometSource");
  pfmetSource_     = iConfig.getParameter<edm::InputTag>("pfmetSource");
  tcmetSource_     = iConfig.getParameter<edm::InputTag>("tcmetSource");
  patjetSource_     = iConfig.getParameter<edm::InputTag>("patjetSource");
  pfjetSource_     = iConfig.getParameter<edm::InputTag>("pfjetSource");
  pfpatjetSource_     = iConfig.getParameter<edm::InputTag>("pfpatjetSource");
  jet_threshold  = iConfig.getParameter<double>("jet_pt_min");
  l5corr = iConfig.getParameter<bool>("useL5corr");
  l5corr_inclGlu = iConfig.getParameter<bool>("useL5corr_including_gluons");
}


SimpleEventDumper::~SimpleEventDumper()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called to for each event  ------------
void
SimpleEventDumper::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  // identity of the event
  int r,ls,e;
  cout << "############################################" << endl;
  r=iEvent.id().run(); ls=iEvent.luminosityBlock(); e=iEvent.id().event(); 
  cout << "Run/LS/Event: " << r << "/" << ls << "/" << e << endl; 
  cout << "############################################" << endl;

  // General
  edm::Handle<reco::VertexCollection> vertices;
  iEvent.getByLabel(vertices_, vertices);
  const reco::Vertex &vertex = *vertices->begin();

  cout << "number of good primary vertices: " << vertices->size() << endl;

  edm::ESHandle<TransientTrackBuilder> trackBuilder;
  iSetup.get<TransientTrackRecord>().get("TransientTrackBuilder", trackBuilder);

  // Muons
  try {
    iEvent.getByLabel(muonSource_, muons);
  } catch (std::exception & err) {
    std::cout <<"ERROR: muon label not found ("<<muonSource_<<")"<< std::endl;
    return;
  }

  double mux = 0.;
  double muy = 0.;
  double muz = 0.;
  double mut = 0.;
  if (muons->size() > 0) {
    for (unsigned int j = 0; j < muons->size(); j++){
      cout << "-----------------------------------" << endl;
      cout << "@muon " << j << endl;
      double pt = (*muons)[j].pt();
      double eta = (*muons)[j].eta();
      double phi = (*muons)[j].phi();
      int nhits = -1;
      if ((*muons)[j].track().isNonnull()) nhits = (*muons)[j].innerTrack()->numberOfValidHits();
      cout << "pt = " << pt << ", eta = " << eta << ", phi = " << phi << ", nhits(tk) = " << nhits << endl;
      //      cout << "px = " << (*muons)[j].px() << ", py = " << (*muons)[j].py() << endl;
      bool global = (*muons)[j].isGlobalMuon();
      bool tracker = (*muons)[j].isTrackerMuon();
      bool gpt = (*muons)[j].isGood("GlobalMuonPromptTight");
      cout << "global = " << global << ", tracker = " << tracker << ", globalPromptTight = " << gpt << endl;

      double tkIso = (*muons)[j].trackIso();
      double ecalIso = (*muons)[j].ecalIso();
      double hcalIso = (*muons)[j].hcalIso();
      double relIso = (tkIso+ecalIso+hcalIso)/pt;
      cout << "tkIso = " << tkIso << ", ecalIso = " << ecalIso << ", hcalIso = " << hcalIso << ", relIso = " << relIso << endl;
      
      double tipSign = -10.;
      reco::TransientTrack transTrack;
      reco::TrackRef trackRef = (*muons)[j].track();
      if(!(trackRef.isNonnull() && trackRef.isAvailable()))
	continue;
      transTrack = trackBuilder->build(trackRef);
      if (vertices->size()>0) {
	tipSign = IPTools::absoluteTransverseImpactParameter(transTrack, vertex).second.significance();
      }
      cout << "IP significance = " << tipSign << endl;
    }  
    mux = (*muons)[0].px(); // it will be filled only for the leading one passing selection
    muy = (*muons)[0].py();
    muz = (*muons)[0].pz();
    mut = (*muons)[0].pt();
  }

  // Electrons
  try {
    iEvent.getByLabel(electronSource_, electrons);
  } catch (std::exception & err) {
    std::cout <<"ERROR: electron label not found ("<<electronSource_<<")"<< std::endl;
    return;
  }

  double ex = 0.;
  double ey = 0.;
  double ez = 0.;
  double et = 0.;
  if (electrons->size() > 0) {
    for (unsigned int j = 0; j < electrons->size(); j++){
      cout << "-----------------------------------" << endl;
      cout << "@electron " << j << endl;
      double etaSC = (*electrons)[j].superCluster()->eta();
      if (fabs(etaSC)<1.4442) {
	cout << " is a barrel electron" << endl;
      } else if (fabs(etaSC)>1.4442 && fabs(etaSC)<1.5660) {
	cout << " is in the ECAL crack" << endl;
      } else {
	cout << " is an endcap electron" << endl;
      }
      double pt = (*electrons)[j].pt();
      double eta = (*electrons)[j].eta();
      double phi = (*electrons)[j].phi();
      int nlost = (*electrons)[j].gsfTrack()->trackerExpectedHitsInner().numberOfHits();
      cout << "pt = " << pt << ", eta = " << eta << ", phi = " << phi << ", lost hits = " << nlost << endl;
      
      double tkIso = (*electrons)[j].dr03TkSumPt();
      double ecalIso = (*electrons)[j].dr03EcalRecHitSumEt(); // note: TOPDIL, differently from TOPLJ, doesn't subtract the 1 GeV offset in the barrel
      double hcalIso = (*electrons)[j].dr03HcalTowerSumEt();
      double relIso = (tkIso+ecalIso+hcalIso)/pt;
      cout << "tkIso = " << tkIso << ", ecalIso = " << ecalIso << ", hcalIso = " << hcalIso << ", relIso = " << relIso << endl;

      double tipSign = -10.;
      reco::TransientTrack transTrack;
      reco::GsfTrackRef trackRef = (*electrons)[j].gsfTrack();
      if(!(trackRef.isNonnull() && trackRef.isAvailable()))
	continue;
      transTrack = trackBuilder->build(trackRef);
      if (vertices->size()>0) {
	tipSign = IPTools::absoluteTransverseImpactParameter(transTrack, vertex).second.significance();
      }
      cout << "IP significance = " << tipSign << endl;
    }  
    ex = (*electrons)[0].px();
    ey = (*electrons)[0].py();
    ez = (*electrons)[0].pz();
    et = (*electrons)[0].pt();
  }

  // Choose leading lepton
  double lx=0;
  double ly=0;
  double lz=0;
  double lt=0;
  cout << "-----------------------------------" << endl;
  if ( muons->size()>=1 ) {
    if (electrons->size()==0 || mut >=et) {
      lx=mux;ly=muy;lz=muz;lt=mut;
      cout << "leading lepton is a muon" << endl;
    }
  } else if (electrons->size()>=1) {
    lx=ex;ly=ey;lz=ez;lt=et;
    cout << "leading lepton is an electron" << endl;
  } else {
    cout << "no selected lepton" << endl;
  }
  // note: asap I will add lepton selection as in TOPLJ, and here the check will be based on number_of_selected_muons and _electrons

  // Jets
  try {
    iEvent.getByLabel(patjetSource_, patjets);
  } catch (std::exception & err) {
    std::cout <<"ERROR: jet label not found ("<<patjetSource_<<")"<< std::endl;
    return;
  }
  double max_tchp = -999.;
  double max_pt_bveto = -999.;
  int index_max_tchp = -1;
  int index_bveto = -1;
  double jx_pat=0;
  double jy_pat=0;
  double jz_pat=0;
  if (patjets->size() > 0) {
    for (unsigned int j = 0; j < patjets->size(); j++){
      double pt = (*patjets)[j].pt();
      double eta = (*patjets)[j].eta();
      double phi = (*patjets)[j].phi();
      double emf = (*patjets)[j].emEnergyFraction();
      reco::JetID jID = (*patjets)[j].jetID();
      double fHPD = jID.fHPD;
      int n90hits = jID.n90Hits;
      double tchp = (*patjets)[j].bDiscriminator("trackCountingHighPurBJetTags");
      double tche = (*patjets)[j].bDiscriminator("trackCountingHighEffBJetTags");
      double ssvhp = (*patjets)[j].bDiscriminator("simpleSecondaryVertexHighPurBJetTags");
      double ssvhe = (*patjets)[j].bDiscriminator("simpleSecondaryVertexHighEffBJetTags");
      if (pt > jet_threshold) {
	cout << "-----------------------------------" << endl;
	cout << "@PAT jet " << j << endl;
	cout << "pt = " << pt << ", eta = " << eta << ", phi = " << phi << endl;
	cout << "EM fraction = " << emf << ", fHPD = " << fHPD << ", N90 = " << n90hits << endl;
	cout << "b-tagging, TCHP = " << tchp << ", TCHE = " << tche << ", SSVHP = " << ssvhp << ", SSVHE = " << ssvhe << endl;
	if (l5corr) {
	  cout << "L5 correction factor under the hypothesis B: " <<  (*patjets)[j].corrFactor("had", "B") << endl;
	  cout << "L5 correction factor under the hypothesis UDS: " <<  (*patjets)[j].corrFactor("had", "UDS") << endl;
	  cout << "L5 correction factor under the hypothesis GLU: " <<  (*patjets)[j].corrFactor("had", "GLU") << endl;
	}
	// find highest-TCHP jet:
	if (tchp > max_tchp) {
	  max_tchp = tchp;
	  index_max_tchp = j;
	}
	// find b-veto jet (highest-pt jet below TCHE loose threshold):
	if (tche < 1.7 && pt > max_pt_bveto) {
	  max_pt_bveto = pt;
	  index_bveto = j;
	}
      }
    }
    cout << "-----------------------------------" << endl;
    cout << "The highest-TCHP PAT jet is #" << index_max_tchp << endl;
    jx_pat = (*patjets)[index_max_tchp].px();
    jy_pat = (*patjets)[index_max_tchp].py();
    jz_pat = (*patjets)[index_max_tchp].pz();
  }

  try {
    iEvent.getByLabel(pfjetSource_, pfjets);
  } catch (std::exception & err) {
    std::cout <<"ERROR: jet label not found ("<<pfjetSource_<<")"<< std::endl;
    return;
  }
  double min_dr = 999.;
  int index_matched_pf_patbtag = -1;
  double jx_pf=0;
  double jy_pf=0;
  double jz_pf=0;
  if (pfjets->size() > 0) {
    for (unsigned int j = 0; j < pfjets->size(); j++){
      double pt = (*pfjets)[j].pt();
      double eta = (*pfjets)[j].eta();
      double phi = (*pfjets)[j].phi();
      double chf = (*pfjets)[j].chargedHadronEnergyFraction();
      double nhf = (*pfjets)[j].neutralHadronEnergyFraction();
      double cef = (*pfjets)[j].chargedEmEnergyFraction();
      double nef = (*pfjets)[j].neutralEmEnergyFraction();
      int nch = (*pfjets)[j].chargedMultiplicity();
      int nconstituents = (*pfjets)[j].numberOfDaughters();
      if (pt > jet_threshold) {
	cout << "-----------------------------------" << endl;
	cout << "@PF jet " << j << endl;
	cout << "pt = " << pt << ", eta = " << eta << ", phi = " << phi << endl;
	cout << "N.constituents = " << nconstituents << ", ch.hadron fraction = " << chf << ", ne.hadron fraction = " << nhf << ", ch.EM fraction = " << cef << ", ne.EM fraction = " << nef << ", charged multiplicity = " << nch << endl;
	// find the PFjet matched in angle to the b-tagged PATjet:
	if (index_max_tchp > -1) {
	  double dr = GetDeltaR(eta,(*patjets)[index_max_tchp].eta(),phi,(*patjets)[index_max_tchp].phi());
	  cout << "distance from the highest-TCHP PAT jet: " << dr << endl;
	  if (dr < min_dr) {
	    min_dr = dr;
	    index_matched_pf_patbtag = j;
	  }
	}
      }
    }
    cout << "-----------------------------------" << endl;
    cout << "The PF jet matched to the highest-TCHP PAT jet is #" << index_matched_pf_patbtag << endl;
    jx_pf = (*pfjets)[index_matched_pf_patbtag].px();
    jy_pf = (*pfjets)[index_matched_pf_patbtag].py();
    jz_pf = (*pfjets)[index_matched_pf_patbtag].pz();
  }

  try {
    iEvent.getByLabel(pfpatjetSource_, pfpatjets);
  } catch (std::exception & err) {
    std::cout <<"ERROR: jet label not found ("<<pfpatjetSource_<<")"<< std::endl;
    return;
  }
  max_tchp = -999.;
  int index_max_tchp_pf = -1;
  double jx_pfpat=0;
  double jy_pfpat=0;
  double jz_pfpat=0;
  if (pfpatjets->size() > 0) {
    for (unsigned int j = 0; j < pfpatjets->size(); j++){
      double pt = (*pfpatjets)[j].pt();
      double eta = (*pfpatjets)[j].eta();
      double phi = (*pfpatjets)[j].phi();
      double chf = (*pfpatjets)[j].chargedHadronEnergyFraction();
      double nhf = (*pfpatjets)[j].neutralHadronEnergyFraction();
      double cef = (*pfpatjets)[j].chargedEmEnergyFraction();
      double nef = (*pfpatjets)[j].neutralEmEnergyFraction();
      int nch = (*pfpatjets)[j].chargedMultiplicity();
      int nconstituents = (*pfpatjets)[j].numberOfDaughters();
      double tchp = (*pfpatjets)[j].bDiscriminator("trackCountingHighPurBJetTags");
      double tche = (*pfpatjets)[j].bDiscriminator("trackCountingHighEffBJetTags");
      double ssvhp = (*pfpatjets)[j].bDiscriminator("simpleSecondaryVertexHighPurBJetTags");
      double ssvhe = (*pfpatjets)[j].bDiscriminator("simpleSecondaryVertexHighEffBJetTags");
      if (pt > jet_threshold) {
	cout << "-----------------------------------" << endl;
	cout << "@PF jet through PAT " << j << endl;
	cout << "pt = " << pt << ", eta = " << eta << ", phi = " << phi << endl;
	cout << "N.constituents = " << nconstituents << ", ch.hadron fraction = " << chf << ", ne.hadron fraction = " << nhf << ", ch.EM fraction = " << cef << ", ne.EM fraction = " << nef << ", charged multiplicity = " << nch << endl;
	cout << "b-tagging, TCHP = " << tchp << ", TCHE = " << tche << ", SSVHP = " << ssvhp << ", SSVHE = " << ssvhe << endl;
	// find highest-TCHP jet:
	if (tchp > max_tchp) {
	  max_tchp = tchp;
	  index_max_tchp_pf = j;
	}
      }
    }
    cout << "-----------------------------------" << endl;
    cout << "The highest-TCHP PF-through-PAT jet is #" << index_max_tchp_pf << endl;
    jx_pfpat = (*patjets)[index_max_tchp_pf].px();
    jy_pfpat = (*patjets)[index_max_tchp_pf].py();
    jz_pfpat = (*patjets)[index_max_tchp_pf].pz();
  }

  // MET

  cout << "-----------------------------------" << endl;
  cout << "MET " << endl;

  double met_pat_x = 0.;
  double met_pat_y = 0.;
  double met_patL5_x = 0.;
  double met_patL5_y = 0.;
  double metL5 = 0.;
  double phiL5 = 0.;
  try {
    iEvent.getByLabel(patmetSource_, patmets);
    if (patmets->size()>=1){
      double met = (*patmets)[0].et();
      double phi = (*patmets)[0].phi();
      double sumet = (*patmets)[0].sumEt();
      double metsig = (*patmets)[0].mEtSig();
      cout << "PAT met = " << met << ", phi = " << phi << ", SumEt = " << sumet << ", MET significance = " << metsig << endl;
      met_pat_x = (*patmets)[0].px();
      met_pat_y = (*patmets)[0].py();
      //      cout << "met_x = " << met_pat_x << ", met_y = " << met_pat_y << endl;
      if (l5corr) {
	met_patL5_x = met_pat_x + (1.-(*patjets)[index_max_tchp].corrFactor("had", "B"))*(*patjets)[index_max_tchp].px() + (1.-(*patjets)[index_bveto].corrFactor("had", "UDS"))*(*patjets)[index_bveto].px();
	met_patL5_y = met_pat_y + (1.-(*patjets)[index_max_tchp].corrFactor("had", "B"))*(*patjets)[index_max_tchp].py() + (1.-(*patjets)[index_bveto].corrFactor("had", "UDS"))*(*patjets)[index_bveto].py();
	if (l5corr_inclGlu) { // correct all other jets, if any, as gluons
	  for (int j = 0; j < (int)patjets->size(); j++){
	    if (j != index_max_tchp && j != index_bveto) {
	      met_patL5_x += (1.-(*patjets)[j].corrFactor("had", "GLU"))*(*patjets)[j].px();
	      met_patL5_y += (1.-(*patjets)[j].corrFactor("had", "GLU"))*(*patjets)[j].py();
	    }
	  }
	}
	metL5 = AddQuadratically(met_patL5_x,met_patL5_y);
	phiL5 = atan2(met_patL5_y,met_patL5_x);
	cout << "PAT+L5 met = " << metL5 << ", phi = " << phiL5 << endl;
      }
    }
  } catch (std::exception & err) {
    std::cout <<"ERROR: MET label not found ("<<patmetSource_<<")"<< std::endl;
    return;
  }

  double met_calo_x = 0.;
  double met_calo_y = 0.;
  try {
    iEvent.getByLabel(calometSource_, calomets);
    if (calomets->size()>=1){
      double met = (*calomets)[0].et();
      double phi = (*calomets)[0].phi();
      double sumet = (*calomets)[0].sumEt();
      double metsig = (*calomets)[0].mEtSig();
      cout << "calo met = " << met << ", phi = " << phi << ", SumEt = " << sumet << ", MET significance = " << metsig << endl;
      met_calo_x = (*calomets)[0].px();
      met_calo_y = (*calomets)[0].py();
      //      cout << "met_x = " << met_calo_x << ", met_y = " << met_calo_y << endl;
    }
  } catch (std::exception & err) {
    std::cout <<"ERROR: MET label not found ("<<calometSource_<<")"<< std::endl;
    return;
  }

  double met_pf_x = 0.;
  double met_pf_y = 0.;
  try {
    iEvent.getByLabel(pfmetSource_, pfmets);
    if (pfmets->size()>=1){
      double met = (*pfmets)[0].et();
      double phi = (*pfmets)[0].phi();
      double sumet = (*pfmets)[0].sumEt();
      double metsig = (*pfmets)[0].mEtSig();
      cout << "PF met = " << met << ", phi = " << phi << ", SumEt = " << sumet << ", MET significance = " << metsig << endl;
      met_pf_x = (*pfmets)[0].px();
      met_pf_y = (*pfmets)[0].py();
      //cout << "met_x = " << met_pf_x << ", met_y = " << met_pf_y << endl;
    }
  } catch (std::exception & err) {
    std::cout <<"ERROR: MET label not found ("<<pfmetSource_<<")"<< std::endl;
    return;
  }

  double met_tc_x = 0.;
  double met_tc_y = 0.;
  try {
    iEvent.getByLabel(tcmetSource_, tcmets);
    if (tcmets->size()>=1){
      double met = (*tcmets)[0].et();
      double phi = (*tcmets)[0].phi();
      double sumet = (*tcmets)[0].sumEt();
      double metsig = (*tcmets)[0].mEtSig();
      cout << "tc met = " << met << ", phi = " << phi << ", SumEt = " << sumet << ", MET significance = " << metsig << endl;
      met_tc_x = (*tcmets)[0].px();
      met_tc_y = (*tcmets)[0].py();
      //      cout << "met_x = " << met_tc_x << ", met_y = " << met_tc_y << endl;
    }
  } catch (std::exception & err) {
    std::cout <<"ERROR: MET label not found ("<<tcmetSource_<<")"<< std::endl;
    return;
  }
  
  // MT
  cout << "-----------------------------------" << endl;
  cout << "MT " << endl;
  if (muons->size()>=1 || electrons->size()>=1){ // also here the check will be based on number_of_selected_muons and _electrons
    double mt_pat = MT(lx,ly,met_pat_x,met_pat_y);
    double mt_patL5 = MT(lx,ly,met_patL5_x,met_patL5_y);
    double mt_calo = MT(lx,ly,met_calo_x,met_calo_y);
    double mt_pf = MT(lx,ly,met_pf_x,met_pf_y);
    double mt_tc = MT(lx,ly,met_tc_x,met_tc_y);
    cout << " with MET from PAT: " << mt_pat << endl;
    if (l5corr) cout << " with MET from PAT+L5: " << mt_patL5 << endl;
    cout << " with MET from calo: " << mt_calo << endl;
    cout << " with MET from PF: " << mt_pf << endl;
    cout << " with tcMET: " << mt_tc << endl;
  }

  // Top
  cout << "-----------------------------------" << endl;
  cout << "Top reconstruction " << endl;
  cout << " PAT: " << endl;
  double mtop_pat = Mtop(lx,ly,lz,met_pat_x,met_pat_y,jx_pat,jy_pat,jz_pat);
  cout << " mtop = " << mtop_pat << endl;
  cout << " PF, uncorrected: " << endl;
  double mtop_pf = Mtop(lx,ly,lz,met_pf_x,met_pf_y,jx_pf,jy_pf,jz_pf);
  cout << " mtop = " << mtop_pf << endl;
  cout << " PF, corrected: " << endl;
  double mtop_pfpat = Mtop(lx,ly,lz,met_pf_x,met_pf_y,jx_pfpat,jy_pfpat,jz_pfpat);
  cout << " mtop = " << mtop_pfpat << endl;


}


// ------------ method called once each job just before starting event loop  ------------
void 
SimpleEventDumper::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
SimpleEventDumper::endJob() {
}

double SimpleEventDumper::MT(double lx, double ly, double nx, double ny) {
  double lt = AddQuadratically(lx,ly);
  double nt = AddQuadratically(nx,ny);
  return sqrt(pow(lt+nt,2) - pow(lx+nx,2) - pow(ly+ny,2) );
}

double SimpleEventDumper::Mtop(double lx, double ly, double lz, double nx, double ny, double jx, double jy, double jz) {

  // solve W constraint equation for the z component of neutrino momentum
  double pz1=0;
  double pz2=0;
  double mW = 80.4;  //  (PDG 2006)
  double le2 = lx*lx + ly*ly + lz*lz;
  double met2 = nx*nx + ny*ny;
  double a = (mW*mW)/2 + nx*lx + ny*ly;
  double delta = a*a - le2*met2 + lz*lz*met2;
  pz1 = a*lz/(lx*lx + ly*ly);
  pz2 = pz1;
  if (delta < 0) {
    cout << "  complex solutions" << endl;
    // here I'm applying the Very Simple Algorithm (simpler even than TOP-09-005): just drop the imaginary part
    // in the future I'll add a switch between different algorithms
  } else {
    cout << "  real solutions" << endl;
    double root = sqrt(delta*le2)/(lx*lx + ly*ly);
    pz1 += root;
    pz2 -= root;
  }
  cout << "  neutrino Pz 1: " << pz1 << ", Pz 2: " << pz2 << endl; 

  // create W candidate
  double nz = 0;
  if (fabs(pz1)<fabs(pz2)) {
    nz = pz1;
  } else {
    nz = pz2;
  }
  double wx = lx+nx;
  double wy = ly+ny;
  double wz = lz+nz;
  double we = sqrt(mW*mW + wx*wx + wy*wy + wz*wz);

  // create top candidate
  double tx = wx+jx;
  double ty = wy+jy;
  double tz = wz+jz;
  double te = we+sqrt(jx*jx + jy*jy + jz*jz);
  double mtop = sqrt(te*te - tx*tx - ty*ty - tz*tz);
  return mtop;
}

double SimpleEventDumper::AddQuadratically( const double nr1, const double nr2 ){
  return sqrt(nr1*nr1+nr2*nr2);
}

double SimpleEventDumper::DeltaPhi(double v1, double v2)
{ // Computes the correctly normalized phi difference
  // v1, v2 = phi of object 1 and 2
 double diff = fabs(v2 - v1);
 double corr = 2*acos(-1.) - diff;
 if (diff < acos(-1.)){ return diff;} else { return corr;}

}

double SimpleEventDumper::GetDeltaR(double eta1, double eta2, double phi1, double phi2){
 return AddQuadratically((eta1-eta2),DeltaPhi(phi1, phi2) );
}


//define this as a plug-in
DEFINE_FWK_MODULE(SimpleEventDumper);
