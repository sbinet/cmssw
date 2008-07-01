#ifndef RecoEcal_EgammaClusterProducers_Multi5x5ClusterProducer_h_
#define RecoEcal_EgammaClusterProducers_Multi5x5ClusterProducer_h_

#include <memory>
#include <time.h>

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"
#include "RecoEcal/EgammaClusterAlgos/interface/Multi5x5ClusterAlgo.h"
#include "RecoEcal/EgammaCoreTools/interface/PositionCalc.h"
#include "RecoEcal/EgammaCoreTools/interface/ClusterShapeAlgo.h"
#include "Geometry/CaloTopology/interface/CaloSubdetectorTopology.h"

#include "DataFormats/EgammaReco/interface/BasicClusterFwd.h"

//


class Multi5x5ClusterProducer : public edm::EDProducer 
{
  public:

      Multi5x5ClusterProducer(const edm::ParameterSet& ps);

      ~Multi5x5ClusterProducer();

      virtual void produce(edm::Event&, const edm::EventSetup&);

   private:

      int nMaxPrintout_; // max # of printouts
      int nEvt_;         // internal counter of events

      // cluster which regions
      bool doBarrel_;
      bool doEndcap_;

      Multi5x5ClusterAlgo::VerbosityLevel verbosity;

      std::string barrelHitProducer_;
      std::string endcapHitProducer_;
      std::string barrelHitCollection_;
      std::string endcapHitCollection_;

      std::string barrelClusterCollection_;
      std::string endcapClusterCollection_;

      std::string clustershapecollectionEB_;
      std::string clustershapecollectionEE_;

      //BasicClusterShape AssociationMap
      std::string barrelClusterShapeAssociation_;
      std::string endcapClusterShapeAssociation_; 

      PositionCalc posCalculator_; // position calculation algorithm
      ClusterShapeAlgo shapeAlgo_; // cluster shape algorithm
      Multi5x5ClusterAlgo * island_p;

      bool counterExceeded() const { return ((nEvt_ > nMaxPrintout_) || (nMaxPrintout_ < 0)); }

      const EcalRecHitCollection * getCollection(edm::Event& evt,
                                                 const std::string& hitProducer_,
                                                 const std::string& hitCollection_);


      void clusterizeECALPart(edm::Event &evt, const edm::EventSetup &es,
                              const std::string& hitProducer,
                              const std::string& hitCollection,
                              const std::string& clusterCollection,
			      const std::string& clusterShapeAssociation,
                              const Multi5x5ClusterAlgo::EcalPart& ecalPart);

      void outputValidationInfo(reco::BasicClusterRefVector &clusterRefVector);
};


#endif
