#include "FWCore/Integration/test/ThingProducer.h"
#include "DataFormats/TestObjects/interface/ThingCollection.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/LuminosityBlock.h"
#include "FWCore/Framework/interface/Run.h"
#include "FWCore/Framework/interface/MakerMacros.h"

namespace edmtest {
  ThingProducer::ThingProducer(edm::ParameterSet const& iConfig): 
  alg_(iConfig.getParameter<int>("offsetDelta")), //this really should be tracked, but I want backwards compatibility
  noPut_(iConfig.getUntrackedParameter<bool>("noPut")) // used for testing with missing products
  {
    produces<ThingCollection>();
    produces<ThingCollection, edm::InLumi>("beginLumi");
    produces<ThingCollection, edm::InLumi>("endLumi");
    produces<ThingCollection, edm::InRun>("beginRun");
    produces<ThingCollection, edm::InRun>("endRun");
  }

  // Virtual destructor needed.
  ThingProducer::~ThingProducer() { }  

  // Functions that gets called by framework every event
  void ThingProducer::produce(edm::Event& e, edm::EventSetup const&) {
    // Step A: Get Inputs 

    // Step B: Create empty output 
    std::auto_ptr<ThingCollection> result(new ThingCollection);  //Empty

    // Step C: Invoke the algorithm, passing in inputs (NONE) and getting back outputs.
    alg_.run(*result);

    // Step D: Put outputs into event
    if (!noPut_) e.put(result);
  }

  // Functions that gets called by framework every luminosity block
  void ThingProducer::beginLuminosityBlock(edm::LuminosityBlock& lb, edm::EventSetup const&) {
    // Step A: Get Inputs 

    // Step B: Create empty output 
    std::auto_ptr<ThingCollection> result(new ThingCollection);  //Empty

    // Step C: Invoke the algorithm, passing in inputs (NONE) and getting back outputs.
    alg_.run(*result);

    // Step D: Put outputs into lumi block
    if (!noPut_) lb.put(result, "beginLumi");
  }

  void ThingProducer::endLuminosityBlock(edm::LuminosityBlock& lb, edm::EventSetup const&) {
    // Step A: Get Inputs 

    // Step B: Create empty output 
    std::auto_ptr<ThingCollection> result(new ThingCollection);  //Empty

    // Step C: Invoke the algorithm, passing in inputs (NONE) and getting back outputs.
    alg_.run(*result);

    // Step D: Put outputs into lumi block
    if (!noPut_) lb.put(result, "endLumi");
  }

  // Functions that gets called by framework every run
  void ThingProducer::beginRun(edm::Run& r, edm::EventSetup const&) {
    // Step A: Get Inputs 

    // Step B: Create empty output 
    std::auto_ptr<ThingCollection> result(new ThingCollection);  //Empty

    // Step C: Invoke the algorithm, passing in inputs (NONE) and getting back outputs.
    alg_.run(*result);

    // Step D: Put outputs into event
    if (!noPut_) r.put(result, "beginRun");
  }

  void ThingProducer::endRun(edm::Run& r, edm::EventSetup const&) {
    // Step A: Get Inputs 

    // Step B: Create empty output 
    std::auto_ptr<ThingCollection> result(new ThingCollection);  //Empty

    // Step C: Invoke the algorithm, passing in inputs (NONE) and getting back outputs.
    alg_.run(*result);

    // Step D: Put outputs into event
    if (!noPut_) r.put(result, "endRun");
  }

  void ThingProducer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
    edm::ParameterSetDescription desc;
    desc.add<int>("offsetDelta",0)->setComment("How much extra to increment the value used when creating Things for a new container. E.g. the last value used to create Thing from the previous event is incremented by 'offsetDelta' to compute the value to use of the first Thing created in the next Event.");
    desc.addUntracked<bool>("noPut",false)->setComment("If true, data is not put into the Principal. This is used to test missing products.");
    descriptions.add("thingProd", desc);
  }

}
using edmtest::ThingProducer;
DEFINE_FWK_MODULE(ThingProducer);
