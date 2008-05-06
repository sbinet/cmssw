#ifndef Integration_OtherThingAnalyzer_h
#define Integration_OtherThingAnalyzer_h

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

namespace edmtest {

  class OtherThingAnalyzer : public edm::EDAnalyzer {
  public:

    explicit OtherThingAnalyzer(edm::ParameterSet const& pset);

    virtual ~OtherThingAnalyzer() {}

    virtual void analyze(edm::Event const& e, edm::EventSetup const& c);

    void doit(edm::DataViewImpl const& dv, std::string const& label);

  private:
    bool thingWasDropped_;
  };

}

#endif
