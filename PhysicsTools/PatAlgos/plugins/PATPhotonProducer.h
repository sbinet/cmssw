//
// $Id: PATPhotonProducer.h,v 1.2 2008/03/05 14:56:50 fronga Exp $
//

#ifndef PhysicsTools_PatAlgos_PATPhotonProducer_h
#define PhysicsTools_PatAlgos_PATPhotonProducer_h

/**
  \class    pat::PATPhotonProducer PATPhotonProducer.h "PhysicsTools/PatAlgos/interface/PATPhotonProducer.h"
  \brief    Produces the pat::Photon

   The PATPhotonProducer produces the analysis-level pat::Photon starting from
   a collection of objects of PhotonType.

  \author   Steven Lowette
  \version  $Id: PATPhotonProducer.h,v 1.2 2008/03/05 14:56:50 fronga Exp $
*/


#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "PhysicsTools/Utilities/interface/EtComparator.h"

#include "DataFormats/PatCandidates/interface/Photon.h"


namespace pat {


  class ObjectResolutionCalc;


  class PATPhotonProducer : public edm::EDProducer {

    public:

      explicit PATPhotonProducer(const edm::ParameterSet & iConfig);
      ~PATPhotonProducer();

      virtual void produce(edm::Event & iEvent, const edm::EventSetup & iSetup);

    private:

      // configurables
      edm::InputTag photonSrc_;
      // tools
      GreaterByEt<Photon> eTComparator_;

  };


}

#endif
