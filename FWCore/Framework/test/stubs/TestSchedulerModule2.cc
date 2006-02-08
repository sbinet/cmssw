/**
   \file
   Test Module for testScheduler

   \author Stefano ARGIRO
   \version $Id: TestSchedulerModule2.cc,v 1.9 2005/07/25 10:07:51 argiro Exp $
   \date 19 May 2005
*/

static const char CVSId[] = "$Id: TestSchedulerModule2.cc,v 1.9 2005/07/25 10:07:51 argiro Exp $";


#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/Handle.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/Common/interface/ToyProducts.h"
#include <memory>
#include <string>

namespace edm{

  class TestSchedulerModule2 : public EDProducer
  {
  public:
    explicit TestSchedulerModule2(ParameterSet const& p):pset_(p){
       produces<edmtest::StringProduct>();
    }

    void produce(Event& e, EventSetup const&);

  private:
    ParameterSet pset_;
  };


  void TestSchedulerModule2::produce(Event& e, EventSetup const&)
  {

    std::string myname = pset_.getParameter<std::string>("module_name");
    std::auto_ptr<edmtest::StringProduct> product(new edmtest::StringProduct(myname));
    e.put(product);
    
  }
}//namespace  
using edm::TestSchedulerModule2;
DEFINE_FWK_MODULE(TestSchedulerModule2)

// Configure (x)emacs for this file ...
// Local Variables:
// mode:c++
// compile-command: "make -C .. -k"
// End:
