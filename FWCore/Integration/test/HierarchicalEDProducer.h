#ifndef FWCORE_INTEGRATION_TEST_HIERARCHICAL_EDPRODUCER_H
#define FWCORE_INTEGRATION_TEST_HIERARCHICAL_EDPRODUCER_H

/** \class HierarchicalEDProducer
 *
 * \version   1st Version Apr. 6, 2005  

 *
 ************************************************************/

#include "FWCore/CoreFramework/interface/CoreFrameworkfwd.h"
#include "FWCore/CoreFramework/interface/EDProducer.h"
#include "FWCore/FWCoreIntegration/test/HierarchicalAlgorithms.h"

namespace edm {
  class ParameterSet;
}

namespace edmtest {
  class HierarchicalEDProducer : public edm::EDProducer {
  public:

    explicit HierarchicalEDProducer(edm::ParameterSet const& ps);

    virtual ~HierarchicalEDProducer();

    virtual void produce(edm::Event& e, edm::EventSetup const& c);

  private:
    double       radius_;
    alg_1        outer_alg_;
  };
}
#endif
