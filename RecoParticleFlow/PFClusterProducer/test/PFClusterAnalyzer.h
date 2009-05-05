#ifndef RecoParticleFlow_PFClusterProducer_PFClusterAnalyzer_
#define RecoParticleFlow_PFClusterProducer_PFClusterAnalyzer_

// system include files
#include <memory>
#include <string>
#include <iostream>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "DataFormats/ParticleFlowReco/interface/PFClusterFwd.h"

/**\class PFClusterAnalyzer 
\brief test analyzer for PFClusters
*/




class PFClusterAnalyzer : public edm::EDAnalyzer {
 public:

  explicit PFClusterAnalyzer(const edm::ParameterSet&);

  ~PFClusterAnalyzer();
  
  virtual void analyze(const edm::Event&, const edm::EventSetup&);

  virtual void beginRun(edm::Run & r, const edm::EventSetup & c);

 private:
  
  void 
    fetchCandidateCollection(edm::Handle<reco::PFClusterCollection>& c, 
			     const edm::InputTag& tag, 
			     const edm::Event& iSetup) const;

/*   void printElementsInBlocks(const reco::PFCluster& cluster, */
/* 			     std::ostream& out=std::cout) const; */


  
  /// PFClusters in which we'll look for pile up particles 
  edm::InputTag   inputTagPFClusters_;
  
  /// verbose ?
  bool   verbose_;

  /// print the blocks associated to a given candidate ?
  bool   printBlocks_;

};

#endif
