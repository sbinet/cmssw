#ifndef RECOLOCALCALO_CALOTOWERSCREATOR_CALOTOWERSRECREATOR_H
#define RECOLOCALCALO_CALOTOWERSCREATOR_CALOTOWERSRECREATOR_H 1

#include "FWCore/Framework/interface/EDProducer.h"
#include "DataFormats/Common/interface/EDProduct.h"
#include "FWCore/Framework/interface/Event.h"
#include "DataFormats/Common/interface/Handle.h"

#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "Geometry/CaloTopology/interface/HcalTopology.h"

#include "RecoLocalCalo/CaloTowersCreator/interface/CaloTowersCreationAlgo.h"

/** \class CaloTowersReCreator
  *  
  * $Date: 2006/08/17 15:23:34 $
  * $Revision: 1.0 $
  */
class CaloTowersReCreator : public edm::EDProducer {
public:
  explicit CaloTowersReCreator(const edm::ParameterSet& ps);
  virtual ~CaloTowersReCreator() { }
  virtual void produce(edm::Event& e, const edm::EventSetup& c);
  double EBEScale, EEEScale, HBEScale, HESEScale;
  double HEDEScale, HOEScale, HF1EScale, HF2EScale;
private:
  CaloTowersCreationAlgo algo_;
  edm::InputTag caloLabel_;
  bool allowMissingInputs_;
};

#endif
