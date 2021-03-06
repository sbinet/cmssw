#include <iostream>

#include "HeavyFlavorAnalysis/Examples/interface/HFDumpSignal.h"

#include "AnalysisDataFormats/HeavyFlavorObjects/rootio/TAna01Event.hh"
#include "AnalysisDataFormats/HeavyFlavorObjects/rootio/TAnaTrack.hh"
#include "AnalysisDataFormats/HeavyFlavorObjects/rootio/TAnaCand.hh"
#include "AnalysisDataFormats/HeavyFlavorObjects/rootio/TGenCand.hh"
#include "AnalysisDataFormats/HeavyFlavorObjects/rootio/TAnaVertex.hh"

#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "RecoVertex/VertexTools/interface/VertexDistance3D.h"
#include "RecoVertex/VertexTools/interface/VertexDistanceXY.h"
#include "RecoVertex/KalmanVertexFit/interface/KalmanVertexFitter.h"
#include "TrackingTools/TransientTrack/interface/TransientTrackBuilder.h"
#include "CommonTools/Statistics/interface/ChiSquared.h"

#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/Common/interface/Wrapper.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/MuonReco/interface/MuonFwd.h"
#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/TrackReco/interface/TrackExtraFwd.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/TrackReco/interface/Track.h"

// ----------------------------------------------------------------------
// WARNING: This is just to get you started! Not how it should be done! 
//
// VERY simple routine to reconstruct the decay B+/- -> J/psi(-> mu+ mu-) K+/-
//   it naively requires exactly two muons
//   does not check their charges
//   and takes one RANDOM track for the K+/-
// ----------------------------------------------------------------------


// -- Yikes!
extern TAna01Event *gHFEvent;

using namespace std;
using namespace reco;
using namespace edm;

#define MMUON 0.10566
#define MKAON 0.49368

// ----------------------------------------------------------------------
HFDumpSignal::HFDumpSignal(const edm::ParameterSet& iConfig) :
  fVerbose(iConfig.getUntrackedParameter<int>("verbose", 0)),
  fTracksLabel(iConfig.getUntrackedParameter<string>("tracksLabel", string("goodTracks"))), 
  fPrimaryVertexLabel(iConfig.getUntrackedParameter<string>("PrimaryVertexLabel", string("offlinePrimaryVertices"))),
  //  fMuonsLabel(iConfig.getUntrackedParameter<InputTag>("muonsLabel", string("goodTracks"))),
  fMuonsLabel(iConfig.getUntrackedParameter<InputTag>("muonsLabel")),
  fMuonPt(iConfig.getUntrackedParameter<double>("muonPt", 1.0)), 
  fKaonPt(iConfig.getUntrackedParameter<double>("kaonPt", 1.0)), 
  fDeltaR(iConfig.getUntrackedParameter<double>("deltaR", 1.5)) {
  using namespace std;
  cout << "----------------------------------------------------------------------" << endl;
  cout << "--- HFDumpSignal constructor" << endl;
  cout << "---  tracksLabel:              " << fTracksLabel.c_str() << endl;
  cout << "---  muonsLabel:               " << fMuonsLabel << endl;
  cout << "---  kaonPt:                   " << fKaonPt << endl;
  cout << "---  deltaR:                   " << fDeltaR << endl;
  cout << "----------------------------------------------------------------------" << endl;

}


// ----------------------------------------------------------------------
HFDumpSignal::~HFDumpSignal() {
  
}


// ----------------------------------------------------------------------
void HFDumpSignal::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup) {

  // -- get the primary vertex
  edm::Handle<VertexCollection> recoPrimaryVertexCollection;
  iEvent.getByLabel(fPrimaryVertexLabel.c_str(), recoPrimaryVertexCollection);
  const reco::VertexCollection vertices = *(recoPrimaryVertexCollection.product());
  if (vertices.size() == 0) {
    cout << "==>HFDumpSignal> No primary vertex found, skipping" << endl;
    return;
  }
  const Vertex pV = vertices[0]; // ???? 

  // -- get the collection of muons
  Handle<MuonCollection> hMuons;
  iEvent.getByLabel(fMuonsLabel, hMuons);

  // -- get the collection of tracks
  Handle<TrackCollection> hTracks;
  iEvent.getByLabel(fTracksLabel.c_str(), hTracks);  

  std::vector<const reco::Track*> recTracks; 
  TAnaTrack *pTrack;

  // -- Fill muons into recTracks
  if (fVerbose > 0) cout << "==>HFDumpSignal> nMuons = " << hMuons->size() << endl;
  if (fVerbose > 0) cout << "==>HFDumpSignal> fMuonsLabel = " << fMuonsLabel << endl;
  vector<int> muonIndices;
  const reco::Track* tt = 0;
  for (reco::MuonCollection::const_iterator muon = hMuons->begin(); muon != hMuons->end(); ++muon) {
    TrackRef track = muon->track();
    tt = &(*track);
    if (tt->pt() <  fMuonPt) continue;
    recTracks.push_back(tt);
    
    pTrack   = gHFEvent->addSigTrack();  
    pTrack->fMCID     = tt->charge()*-13; 
    pTrack->fGenIndex = -1; 
    pTrack->fQ        = tt->charge();
    pTrack->fPlab.SetPtEtaPhi(tt->pt(),
			      tt->eta(),
			      tt->phi()
			      ); 
    pTrack->fIndex  = (muon->track()).index();
    muonIndices.push_back((muon->track()).index());
    if (fVerbose > 0) {
      pTrack->dump();
    }
  }

  printf("nRecTracks = %i\n", recTracks.size());

  
  // -- Choose another (random) track close to muons
  if (recTracks.size() == 2) {
    TLorentzVector m1, m2, k, psi, b; 
    m1.SetPtEtaPhiM(recTracks.at(0)->pt(),
		    recTracks.at(0)->eta(),
		    recTracks.at(0)->phi(),
		    MMUON); 
    m2.SetPtEtaPhiM(recTracks.at(1)->pt(),
		    recTracks.at(1)->eta(),
		    recTracks.at(1)->phi(),
		    MMUON); 

    psi = m1 + m2; 
    cout << "J/psi mass = " << psi.M() << endl;

    int foundTrack(-1); 
    for (int i = 0; i < static_cast<int>(hTracks->size()); ++i){    
      if (i == muonIndices[0] || i == muonIndices[1]) continue; // skip muons!
      reco::TrackRef rTrack(hTracks, i);
      reco::Track track(*rTrack);

      k.SetPtEtaPhiM(track.pt(),
		     track.eta(),
		     track.phi(),
		     MKAON); 

      b = psi + k; 
   
      if (k.Perp() < fKaonPt) continue;
      if (psi.DeltaR(k) > fDeltaR) continue;
      if (b.M() < 4.0) continue;
      if (b.M() > 6.0) continue;
      foundTrack = i;
    }
    if (-1 == foundTrack) {
      cout << "==>HFDumpSignal> No additional track found close to dimuons" << endl;
      return;
    }
    reco::TrackRef rTrack(hTracks, foundTrack);
    reco::Track track(*rTrack);
    recTracks.push_back(&track); 
    pTrack   = gHFEvent->addSigTrack();  
    pTrack->fMCID     = track.charge()*-13; 
    pTrack->fGenIndex = -1; 
    pTrack->fQ        = track.charge();
    pTrack->fPlab.SetPtEtaPhi(track.pt(),
			      track.eta(),
			      track.phi()
			      ); 
    pTrack->fIndex  = rTrack.index();
 
 
    // -- Make transient tracks needed for vertexing
    edm::ESHandle<TransientTrackBuilder> theB;
    iSetup.get<TransientTrackRecord>().get("TransientTrackBuilder", theB);

    std::vector<reco::TransientTrack> RecoTransientTrack;
    for (unsigned int i=0; i < recTracks.size(); i++ ) { 
      RecoTransientTrack.push_back(theB->build(recTracks[i]));
    }

    // -- Do the vertexing
    KalmanVertexFitter theFitter(true);
    TransientVertex TransSecVtx = theFitter.vertex(RecoTransientTrack); 
    if ( TransSecVtx.isValid() ) {
      if ( isnan(TransSecVtx.position().x()) 
	   || isnan(TransSecVtx.position().y()) 
	   || isnan(TransSecVtx.position().z()) ) {
	cout << "==>HFDumpSignal> Something went wrong! SecVtx nan - Aborting... !" << endl;
	return;
      }
    } else {
      cout << "==>HFDumpSignal> KVF failed! Aborting... !" << endl;
      return;
    }

    // -- Get refitted tracks
    std::vector<reco::TransientTrack> refTT = TransSecVtx.refittedTracks();
    std::vector<reco::Track> refT;
    for(vector<reco::TransientTrack>::const_iterator i = refTT.begin(); i != refTT.end(); i++) {
      const Track & ftt = i->track();
      refT.push_back(ftt);
    }

    // -- Build composite
    TLorentzVector comp, M1, M2, K1;
    M1.SetXYZM(refT[0].px(), refT[0].py(), refT[0].pz(), MMUON); 
    M2.SetXYZM(refT[1].px(), refT[1].py(), refT[1].pz(), MMUON); 
    K1.SetXYZM(refT[2].px(), refT[2].py(), refT[2].pz(), MKAON); 
    comp = M1 + M2 + K1;

    // -- Update signal tracks with refitted momentum
    gHFEvent->getSigTrack(0)->fPlab.SetXYZ(refT[0].px(),
					   refT[0].py(),
					   refT[0].pz()
					   ); 
    gHFEvent->getSigTrack(1)->fPlab.SetXYZ(refT[1].px(),
					   refT[1].py(),
					   refT[1].pz()
					   ); 
    gHFEvent->getSigTrack(2)->fPlab.SetXYZ(refT[2].px(),
					   refT[2].py(),
					   refT[2].pz()
					   ); 

    ChiSquared chi(TransSecVtx.totalChiSquared(), TransSecVtx.degreesOfFreedom());

    TVector3 SecVtx; 
    SecVtx.SetX(TransSecVtx.position().x()*10.);  //*10 to get mm (same unit as gen info)
    SecVtx.SetY(TransSecVtx.position().y()*10.);
    SecVtx.SetZ(TransSecVtx.position().z()*10.);


    // -- Build vertex for ntuple
    TAnaVertex *pVtx = new TAnaVertex();
    pVtx->setInfo(chi.value(), chi.degreesOfFreedom(), chi.probability(), 0, 0);
    pVtx->fPoint.SetXYZ(TransSecVtx.position().x(), 
			TransSecVtx.position().y(), 
			TransSecVtx.position().z());
 
    pVtx->addTrack(gHFEvent->getSigTrack(0)->fIndex);
    pVtx->addTrack(gHFEvent->getSigTrack(1)->fIndex);
    pVtx->addTrack(gHFEvent->getSigTrack(2)->fIndex);

    // -- Distance to primary vertex

    VertexDistanceXY axy;
    double dXY      = axy.distance(pV, TransSecVtx).value();
    double dXYE     = axy.distance(pV, TransSecVtx).error();
    //    double compXY   = axy.compatibility(pV, TransSecVtx);
 
    VertexDistance3D a3d;
    double d3d      = a3d.distance(pV, TransSecVtx).value();
    double d3dE     = a3d.distance(pV, TransSecVtx).error();
    //    double comp3d   = a3d.compatibility(pV, TransSecVtx);
 
    pVtx->fDxy  = dXY; 
    pVtx->fDxyE = dXYE; 
    //     pVtx->fCxy  = compXY; 

    pVtx->fD3d  = d3d; 
    pVtx->fD3dE = d3dE; 
    //     pVtx->fC3d  = comp3d; 

 
    // -- Build candidate: B+
    TAnaCand  *pCand = gHFEvent->addCand();
 
    pCand->fPlab = comp.Vect();
    pCand->fMass = comp.M();
 
    pCand->fSig1 = 0;  
    pCand->fSig2 = 2;  
    pCand->fType = 521;
 
    pCand->fVtx  = *pVtx;    

    cout << "==>HFDumpSignal: Fitted and filled B candidate !!!!!!!!!!!!!!! " << endl;

  } else {
    cout << "==>HFDumpSignal: Found only " << recTracks.size() << " muons, not fitting" << endl;
  }

    

}

// ------------ method called once each job just before starting event loop  ------------
void  HFDumpSignal::beginJob(const edm::EventSetup& setup) {
}

// ------------ method called once each job just after ending the event loop  ------------
void  HFDumpSignal::endJob() {
}

//define this as a plug-in
//DEFINE_FWK_MODULE(HFDumpSignal);
