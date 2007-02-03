// -*- C++ -*-
//
// Package:    TestIsoTracks
// Class:      IsolatedParticles
// 
/*


 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  Sergey Petrushanko
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/Handle.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/OrphanHandle.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackExtra.h"
#include "DataFormats/CaloTowers/interface/CaloTower.h"
#include "DataFormats/CaloTowers/interface/CaloTowerCollection.h"
#include "DataFormats/EgammaReco/interface/SuperCluster.h"
//#include "DataFormats/DTRecHit/interface/DTRecHitCollection.h"
#include "DataFormats/EcalDetId/interface/EBDetId.h"

#include "SimDataFormats/TrackingHit/interface/PSimHit.h"
#include "SimDataFormats/TrackingHit/interface/PSimHitContainer.h"
#include "SimDataFormats/Track/interface/SimTrack.h"
#include "SimDataFormats/Track/interface/SimTrackContainer.h"
#include "SimDataFormats/Vertex/interface/SimVertex.h"
#include "SimDataFormats/Vertex/interface/SimVertexContainer.h"
#include "SimDataFormats/CaloHit/interface/PCaloHit.h"
#include "SimDataFormats/CaloHit/interface/PCaloHitContainer.h"

// calorimeter info
#include "Geometry/Records/interface/IdealGeometryRecord.h"
#include "Geometry/CaloGeometry/interface/CaloGeometry.h"
#include "Geometry/CaloGeometry/interface/CaloSubdetectorGeometry.h"
#include "Geometry/CaloGeometry/interface/CaloCellGeometry.h"
#include "DataFormats/EcalDetId/interface/EcalSubdetector.h"
#include "DataFormats/HcalDetId/interface/HcalSubdetector.h"

//#include "Geometry/DTGeometry/interface/DTLayer.h"
//#include "Geometry/DTGeometry/interface/DTGeometry.h"
//#include "Geometry/Records/interface/MuonGeometryRecord.h"

#include "Geometry/Surface/interface/Cylinder.h"
#include "Geometry/Surface/interface/Plane.h"

#include "Geometry/CommonDetUnit/interface/GeomDetUnit.h"


#include "MagneticField/Engine/interface/MagneticField.h"
#include "MagneticField/Records/interface/IdealMagneticFieldRecord.h"

#include "TrackPropagation/SteppingHelixPropagator/interface/SteppingHelixPropagator.h"

#include <boost/regex.hpp>

#include "TrackingTools/TrackAssociator/interface/TrackDetectorAssociator.h"
#include "TrackingTools/TrackAssociator/interface/TimerStack.h"

#include "TH1F.h"
#include <TFile.h>

#include "RecoTracker/TrackProducer/interface/TrackProducerBase.h"
#include "TrackingTools/TransientTrack/interface/TransientTrack.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"

#include <map>
#include <string>
#include <vector>
#include "CLHEP/Vector/LorentzVector.h"

using namespace std;
using namespace reco;


class TestIsoTracks : public edm::EDAnalyzer {
 public:
   explicit TestIsoTracks(const edm::ParameterSet&);
   virtual ~TestIsoTracks(){};
   
  void setPrimaryVertex(const reco::Vertex & a){theRecVertex = a;}
  void setTracksFromPrimaryVertex(vector<reco::Track> & a){theTrack = a;}
   virtual void analyze (const edm::Event&, const edm::EventSetup&);
   void endJob(void);

 private:
  TFile* m_Hfile;
      struct{
        TH1F* eta;
        TH1F* phi;
        TH1F* p;
        TH1F* pt;
        TH1F* isomult;
      } IsoHists;  

    edm::InputTag mInputPVfCTF;
    std::string m_inputTrackLabel;


  double theRvert;
  reco::Vertex theRecVertex; 
  vector<reco::Track> theTrack; 
   TrackDetectorAssociator trackAssociator_;
   bool useEcal_;
   bool useHcal_;
   bool useMuon_;
};

TestIsoTracks::TestIsoTracks(const edm::ParameterSet& iConfig): 
					   mInputPVfCTF(iConfig.getParameter<edm::InputTag>("src3")),
					   theRvert(iConfig.getParameter<double>("rvert"))
{
   m_inputTrackLabel = iConfig.getUntrackedParameter<std::string>("inputTrackLabel","ctfWithMaterialTracks");

   useEcal_ = iConfig.getParameter<bool>("useEcal");
   useHcal_ = iConfig.getParameter<bool>("useHcal");
   useMuon_ = iConfig.getParameter<bool>("useMuon");
   
   // Fill data labels
   std::vector<std::string> labels = iConfig.getParameter<std::vector<std::string> >("labels");
   boost::regex regExp1 ("([^\\s,]+)[\\s,]+([^\\s,]+)$");
   boost::regex regExp2 ("([^\\s,]+)[\\s,]+([^\\s,]+)[\\s,]+([^\\s,]+)$");
   boost::smatch matches;
	
   m_Hfile=new TFile("IsoHists.root","RECREATE");
    IsoHists.eta = new TH1F("Eta","Track eta",50,-2.5,2.5);
    IsoHists.phi = new TH1F("Phi","Track phi",50,-3.2,3.2);
    IsoHists.p = new TH1F("Momentum","Track momentum",100,0.,20.);
    IsoHists.pt = new TH1F("pt","Track pt",100,0.,10.);
    IsoHists.isomult = new TH1F("IsoMult","Iso Mult",10,-0.5,9.5);

   for(std::vector<std::string>::const_iterator label = labels.begin(); label != labels.end(); label++) {
      if (boost::regex_match(*label,matches,regExp1))
	trackAssociator_.addDataLabels(matches[1],matches[2]);
      else if (boost::regex_match(*label,matches,regExp2))
	trackAssociator_.addDataLabels(matches[1],matches[2],matches[3]);
      else
	edm::LogError("ConfigurationError") << "Failed to parse label:\n" << *label << "Skipped.\n";
   }
   
   // trackAssociator_.addDataLabels("EBRecHitCollection","ecalrechit","EcalRecHitsEB");
   // trackAssociator_.addDataLabels("CaloTowerCollection","towermaker");
   // trackAssociator_.addDataLabels("DTRecSegment4DCollection","recseg4dbuilder");
   
   trackAssociator_.useDefaultPropagator();
}

void TestIsoTracks::analyze( const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;

// mine! b

     std::vector<GlobalPoint> AllTracks;
     std::vector<GlobalPoint> AllTracks1;
     
// mine! e

// Take Reco Vertex collection   
   edm::Handle<reco::VertexCollection> primary_vertices;                 //Define Inputs (vertices)
   iEvent.getByLabel(mInputPVfCTF, primary_vertices);                  //Get Inputs    (vertices)

 // Take Reco Track Collection
   edm::Handle<reco::TrackCollection> trackCollection;
   iEvent.getByLabel(m_inputTrackLabel,trackCollection);
   const reco::TrackCollection tC = *(trackCollection.product());

   // get list of tracks and their vertices
   Handle<SimTrackContainer> simTracks;
   iEvent.getByType<SimTrackContainer>(simTracks);
   
   Handle<SimVertexContainer> simVertices;
   iEvent.getByType<SimVertexContainer>(simVertices);
   if (! simVertices.isValid() ) throw cms::Exception("FatalError") << "No vertices found\n";

   
   // loop over tracks

   std::cout << "Number of tracks found in the event: " << trackCollection->size() << std::endl;

//   for(SimTrackContainer::const_iterator tracksCI = simTracks->begin(); 
//       tracksCI != simTracks->end(); tracksCI++){

  for(reco::TrackCollection::const_iterator tracksCI=tC.begin(); tracksCI!=tC.end(); tracksCI++){ 
       
                double mome_pt =   sqrt ( tracksCI->momentum().x()*tracksCI->momentum().x() +
			          tracksCI->momentum().y()*tracksCI->momentum().y());    
				   
				  // skip low Pt tracks
      if (mome_pt < 0.5) {
	 std::cout << "Skipped low Pt track (Pt: " << mome_pt << ")" <<std::endl;
	 continue;
      }
      
      // get vertex
//      int vertexIndex = tracksCI->vertIndex();
      // uint trackIndex = tracksCI->genpartIndex();
      
//      SimVertex vertex(Hep3Vector(0.,0.,0.),0);
//      if (vertexIndex >= 0) vertex = (*simVertices)[vertexIndex];
      
      // skip tracks originated away from the IP
//      if (vertex.position().rho() > 50) {
//	 std::cout << "Skipped track originated away from IP: " <<vertex.position().rho()<<std::endl;
//	 continue;
//      }
      
      std::cout << "\n-------------------------------------------------------\n Track (pt,eta,phi): " << mome_pt << " , " <<
	tracksCI->momentum().eta() << " , " << tracksCI->momentum().phi() << std::endl;
      
      // Simply get ECAL energy of the crossed crystals
//      std::cout << "ECAL energy of crossed crystals: " << 
//	trackAssociator_.getEcalEnergy(iEvent, iSetup,
//				       trackAssociator_.getFreeTrajectoryState(iSetup, *tracksCI, vertex) )
//	  << " GeV" << std::endl;
				       
      // Get HCAL energy in more generic way
      TrackDetectorAssociator::AssociatorParameters parameters;
      parameters.useEcal = useEcal_ ;
      parameters.useHcal = useHcal_ ;
      parameters.useMuon = useMuon_ ;
      parameters.dRHcal = 0.03;
      parameters.dRHcal = 0.07;
      parameters.dRMuon = 0.1;
      
//      std::cout << "Details:\n" <<std::endl;
      TrackDetMatchInfo info = trackAssociator_.associate(iEvent, iSetup,
							  trackAssociator_.getFreeTrajectoryState(iSetup, *tracksCI),
							  parameters);
//      std::cout << "ECAL, if track reach ECAL:     " << info.isGoodEcal << std::endl;
//      std::cout << "ECAL, number of crossed cells: " << info.crossedEcalRecHits.size() << std::endl;
//      std::cout << "ECAL, energy of crossed cells: " << info.ecalEnergy() << " GeV" << std::endl;
//      std::cout << "ECAL, number of cells in the cone: " << info.ecalRecHits.size() << std::endl;
//      std::cout << "ECAL, energy in the cone: " << info.ecalConeEnergy() << " GeV" << std::endl;
//      std::cout << "ECAL, trajectory point (z,R,eta,phi): " << info.trkGlobPosAtEcal.z() << ", "
//	<< info.trkGlobPosAtEcal.R() << " , "	<< info.trkGlobPosAtEcal.eta() << " , " 
//	<< info.trkGlobPosAtEcal.phi()<< std::endl;

// mine! b

	  double rfa =     sqrt (info.trkGlobPosAtEcal.x()*info.trkGlobPosAtEcal.x() +
	                         info.trkGlobPosAtEcal.y()*info.trkGlobPosAtEcal.y() + 
				 info.trkGlobPosAtEcal.z()*info.trkGlobPosAtEcal.z()) /
		           sqrt ( tracksCI->momentum().x()*tracksCI->momentum().x() +
			          tracksCI->momentum().y()*tracksCI->momentum().y() +
				  tracksCI->momentum().z()*tracksCI->momentum().z());

          if (info.isGoodEcal==1 && fabs(info.trkGlobPosAtEcal.eta()) < 2.6){
 	   AllTracks.push_back(GlobalPoint(info.trkGlobPosAtEcal.x()/rfa, info.trkGlobPosAtEcal.y()/rfa, info.trkGlobPosAtEcal.z()/rfa));
	    if (mome_pt > 2. && fabs(info.trkGlobPosAtEcal.eta()) < 2.1) 
	    if (fabs(info.trkGlobPosAtEcal.eta()) < 2.1) 
	     {				 
	     AllTracks1.push_back(GlobalPoint(info.trkGlobPosAtEcal.x()/rfa, info.trkGlobPosAtEcal.y()/rfa, info.trkGlobPosAtEcal.z()/rfa));
	     }
	  }

// mine! e   
   
//      std::cout << "HCAL, if track reach HCAL:      " << info.isGoodHcal << std::endl;
//      std::cout << "HCAL, number of crossed towers: " << info.crossedTowers.size() << std::endl;
//      std::cout << "HCAL, energy of crossed towers: " << info.hcalEnergy() << " GeV" << std::endl;
//      std::cout << "HCAL, number of towers in the cone: " << info.towers.size() << std::endl;
//      std::cout << "HCAL, energy in the cone: " << info.hcalConeEnergy() << " GeV" << std::endl;
//      std::cout << "HCAL, trajectory point (z,R,eta,phi): " << info.trkGlobPosAtHcal.z() << ", "
//	<< info.trkGlobPosAtHcal.R() << " , "	<< info.trkGlobPosAtHcal.eta() << " , "
//	<< info.trkGlobPosAtHcal.phi()<< std::endl;

   }

// mine! b

  std::cout << " NUMBER of tracks  " << AllTracks.size() << "  and candidates for iso tracks  " << AllTracks1.size() <<std::endl;
  
  double imult=0.;
      
  for (unsigned int ia1=0; ia1<AllTracks1.size(); ia1++) 
  {

    double delta_min=3.141592;
  
   for (unsigned int ia=0; ia<AllTracks.size(); ia++) 
   {
     double delta_phi = fabs(AllTracks1[ia1].phi() - AllTracks[ia].phi());
     if (delta_phi > 3.141592) delta_phi = 6.283184 - delta_phi;
     double delta_eta = fabs(AllTracks1[ia1].eta() - AllTracks[ia].eta());
     double delta_actual = sqrt( delta_phi*delta_phi + delta_eta*delta_eta );

     if (delta_actual < delta_min && delta_actual != 0.) delta_min = delta_actual;

   }    
    
    if (delta_min > 0.5) {
    
    std::cout << "FIND ISOLATED TRACK " << AllTracks1[ia1].mag() << "  " << AllTracks1[ia1].eta()<< "  "<< AllTracks1[ia1].phi()<< std::endl;    

    IsoHists.eta->Fill(AllTracks1[ia1].eta());
    IsoHists.phi->Fill(AllTracks1[ia1].phi());
    IsoHists.p->Fill(AllTracks1[ia1].mag());
    IsoHists.pt->Fill(AllTracks1[ia1].perp());
    
    imult = imult+1.;

    }
  }

    IsoHists.isomult->Fill(imult);

// mine! e

}


void TestIsoTracks::endJob(void) {

    m_Hfile->cd();
    IsoHists.eta->Write();
    IsoHists.phi->Write();
    IsoHists.p->Write();
    IsoHists.pt->Write();
    IsoHists.isomult->Write();
    m_Hfile->Close();

}



//define this as a plug-in
DEFINE_FWK_MODULE(TestIsoTracks);
