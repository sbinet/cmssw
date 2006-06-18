#ifndef RecoEcal_EgammaClusterProducers_EgammaSimpleAnalyzer_h
#define RecoEcal_EgammaClusterProducers_EgammaSimpleAnalyzer_h
/**\class EgammaSimpleAnalyzer

 Description: Analyzer to fetch collection of objects from event and make simple plots

 Implementation:
     \\\author: Shahram Rahatlou, May 2006
*/
//
// $Id: EgammaSimpleAnalyzer.h,v 1.4 2006/06/16 10:16:43 rahatlou Exp $
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include <string>
#include "TH1.h"
class TFile;

//
// class declaration
//

class EgammaSimpleAnalyzer : public edm::EDAnalyzer {
   public:
      explicit EgammaSimpleAnalyzer( const edm::ParameterSet& );
      ~EgammaSimpleAnalyzer();


      virtual void analyze( const edm::Event&, const edm::EventSetup& );
      virtual void beginJob(edm::EventSetup const&);
      virtual void endJob();
 private:

      std::string outputFile_; // output file

      std::string islandBarrelBasicClusterCollection_;
      std::string islandBarrelBasicClusterProducer_;

      std::string islandBarrelSuperClusterCollection_;
      std::string islandBarrelSuperClusterProducer_;

      std::string correctedIslandBarrelSuperClusterCollection_;
      std::string correctedIslandBarrelSuperClusterProducer_;

      std::string islandEndcapBasicClusterCollection_;
      std::string islandEndcapBasicClusterProducer_;

      std::string islandEndcapSuperClusterCollection_;
      std::string islandEndcapSuperClusterProducer_;

      std::string correctedIslandEndcapSuperClusterCollection_;
      std::string correctedIslandEndcapSuperClusterProducer_;

      std::string hybridSuperClusterCollection_;
      std::string hybridSuperClusterProducer_;

      std::string correctedHybridSuperClusterCollection_;
      std::string correctedHybridSuperClusterProducer_;

      // root file to store histograms
      TFile*  rootFile_;

      // min and max of energy histograms
      double xMinHist_;
      double xMaxHist_;
      int    nbinHist_;

      // data members for histograms to be filled

      // per event quantities
      TH1F* h1_nIslandEBBC_;
      TH1F* h1_nIslandEEBC_;
      TH1F* h1_nIslandEBSC_;
      TH1F* h1_nIslandEESC_;
      TH1F* h1_nHybridSC_;

      TH1F* h1_islandEBBCEnergy_;
      TH1F* h1_islandEBBCXtals_;

      TH1F* h1_islandEBSCEnergy_;
      TH1F* h1_corrIslandEBSCEnergy_;
      TH1F* h1_islandEBSCClusters_;

      TH1F* h1_islandEEBCEnergy_;
      TH1F* h1_islandEEBCXtals_;

      TH1F* h1_islandEESCEnergy_;
      TH1F* h1_corrIslandEESCEnergy_;
      TH1F* h1_islandEESCClusters_;

      TH1F* h1_hybridSCEnergy_;
      TH1F* h1_corrHybridSCEnergy_;
      TH1F* h1_corrHybridSCET_;
      TH1F* h1_corrHybridSCEta_;
      TH1F* h1_corrHybridSCPhi_;
      TH1F* h1_hybridSCClusters_;

      TH1F* h1_eCorrIslandEB;
      TH1F* h1_eCorrIslandEE;
      TH1F* h1_eCorrHybrid;

};
#endif
