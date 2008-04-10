#include <iostream>

#include <TRandom.h>

#include "HeavyFlavorAnalysis/Examples/interface/HFDumpGenerator.h"
#include "SimDataFormats/HepMCProduct/interface/HepMCProduct.h"

#include "HepMC/GenVertex.h"
#include "DataFormats/HepMCCandidate/interface/GenParticleCandidate.h"

#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/Candidate/interface/CandidateFwd.h"

#include "AnalysisDataFormats/HeavyFlavorObjects/rootio/TAna00Event.hh"
#include "AnalysisDataFormats/HeavyFlavorObjects/rootio/TAnaTrack.hh"
#include "AnalysisDataFormats/HeavyFlavorObjects/rootio/TAnaCand.hh"
#include "AnalysisDataFormats/HeavyFlavorObjects/rootio/TGenCand.hh"
#include "AnalysisDataFormats/HeavyFlavorObjects/rootio/TAnaVertex.hh"

// -- Yikes!
extern TAna00Event *gHFEvent;

using namespace std;
using namespace edm;
using namespace reco;
using namespace HepMC;

// ----------------------------------------------------------------------
HFDumpGenerator::HFDumpGenerator(const ParameterSet& iConfig):
  fVerbose(iConfig.getUntrackedParameter<int>("verbose", 0)),
  fGenCandidatesLabel(iConfig.getUntrackedParameter<string>("generatorCandidates", string("MCCandidate"))), 
  fGenEventLabel(iConfig.getUntrackedParameter<string>("generatorEvent", string("Source")))  {
  using namespace std;
  cout << "----------------------------------------------------------------------" << endl;
  cout << "--- HFDumpGenerator constructor: " << fGenCandidatesLabel << "  " << fGenEventLabel << endl;
  cout << "----------------------------------------------------------------------" << endl;

}


// ----------------------------------------------------------------------
HFDumpGenerator::~HFDumpGenerator() {
  
}


// ----------------------------------------------------------------------
void HFDumpGenerator::analyze(const Event& iEvent, const EventSetup& iSetup) {

  // -- CAREFUL!
  gHFEvent->Clear();

  static int nevt(0); 
  ++nevt;
  //  cout << "==> HFDumpGenerator> new  event  " << nevt << endl;

  // -- Get candidates from generator block
  //    https://twiki.cern.ch/twiki/bin/view/CMS/WorkBookGenParticleCandidate
  Handle<CandidateCollection> hMCCandidates;
  try {
    iEvent.getByLabel(fGenCandidatesLabel.c_str(), hMCCandidates);
    TGenCand  *aGen = new TGenCand;
    for (int i = 0; i < hMCCandidates->size(); ++ i ) {
      const Candidate &p = (*hMCCandidates)[i];
      aGen->fID    = p.pdgId();
      aGen->fStatus = p.status();  
      aGen->fNumber = i;  
      const Candidate *mom = p.mother();
      double pt = p.pt(), eta = p.eta(), phi = p.phi(), mass = p.mass();
      double vx = p.vx(), vy = p.vy(), vz = p.vz();
      aGen->fP.SetXYZT(p.px(), 
		       p.py(), 
		       p.pz(), 
		       p.energy());
      aGen->fV.SetXYZ(vx, vy, vz);
      
      //aGen->dump();
      
    }
  } catch (Exception event) {
    //    cout << "==> HFDumpGenerator> CandidateCollection with label " << fGenCandidatesLabel.c_str() 
    //	 << " not found " << endl;
  }
  
  // ----------------------------------------------------------------------
  // -- Get generator block directly
  Handle<HepMCProduct> evt;
  iEvent.getByLabel(fGenEventLabel.c_str(), evt);
  const HepMC::GenEvent *genEvent = evt->GetEvent();

  TGenCand  *pGen;
  int gcnt(0); 
  double x, y, z;
  for (HepMC::GenEvent::particle_const_iterator p = genEvent->particles_begin();
       p != genEvent->particles_end();
       ++p) {
    pGen = gHFEvent->addGenCand();
    pGen->fNumber = (*p)->barcode() - 1;
    pGen->fID     = (*p)->pdg_id();
    pGen->fStatus = (*p)->status();
    pGen->fP.SetXYZT((*p)->momentum().x(), 
		     (*p)->momentum().y(), 
		     (*p)->momentum().z(), 
		     (*p)->momentum().e());

    GenVertex* pVertex = (*p)->end_vertex();
    if (0 != pVertex) {
      x = pVertex->position().x(); 
      y = pVertex->position().y();
      z = pVertex->position().z(); 
    } else {
      x = y = z = 9999.;
    }
    pGen->fV.SetXYZ(x, y, z);

    // -- Get one mother barcode
    int motherBarcode = (*p)->production_vertex() && 
      (*p)->production_vertex()->particles_in_const_begin() !=
      (*p)->production_vertex()->particles_in_const_end() ?
      (*((*p)->production_vertex()->particles_in_const_begin()))->barcode()-1 : 0;
    pGen->fMom1 = motherBarcode;
    pGen->fMom2 = -1;

    // -- Get daughters barcodes (there must be an easier way to do this?!)
    pGen->fDau1 = 99999;
    pGen->fDau2 = -1;
    if (0 != pVertex) {
      for (std::set<GenParticle*>::const_iterator pChild = pVertex->particles_out_const_begin();
	   pChild != pVertex->particles_out_const_end(); 
	   pChild++) {

	int selfBarcode = (*pChild)->production_vertex() && 
	  (*pChild)->production_vertex()->particles_in_const_begin() !=
	  (*pChild)->production_vertex()->particles_in_const_end() ?
	  (*((*pChild)->production_vertex()->particles_in_const_begin()))->barcode()-1 : 0;
	
	if (selfBarcode == pGen->fNumber) {
	  if ((*pChild)->barcode()-1 < pGen->fDau1) {
	    pGen->fDau1 = (*pChild)->barcode()-1;
	  }
	  if ((*pChild)->barcode()-1 > pGen->fDau2) {
	    pGen->fDau2 = (*pChild)->barcode()-1;
	  }
	}
      }
      // -- sort them
      if (pGen->fDau1 > pGen->fDau2) {
	int bla = pGen->fDau1; 
	pGen->fDau1 = pGen->fDau2; 
	pGen->fDau2 = bla; 
      }
    } else {
      pGen->fDau1 = -1;
      pGen->fDau2 = -1;
    }

    //pGen->dump();
    ++gcnt; 
  }

 
}

// ------------ method called once each job just before starting event loop  ------------
void  HFDumpGenerator::beginJob(const EventSetup& setup) {
}

// ------------ method called once each job just after ending the event loop  ------------
void  HFDumpGenerator::endJob() {
}

//define this as a plug-in
//DEFINE_FWK_MODULE(HFDumpGenerator);
