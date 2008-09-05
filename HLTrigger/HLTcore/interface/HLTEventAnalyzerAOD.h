#ifndef HLTcore_HLTEventAnalyzerAOD_h
#define HLTcore_HLTEventAnalyzerAOD_h

/** \class HLTEventAnalyzerAOD
 *
 *  
 *  This class is an EDAnalyzer analyzing the combined HLT information for AOD
 *
 *  $Date: 2008/04/11 18:09:11 $
 *  $Revision: 1.2 $
 *
 *  \author Martin Grunewald
 *
 */

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/HLTReco/interface/TriggerEvent.h"

//
// class declaration
//
class HLTEventAnalyzerAOD : public edm::EDAnalyzer {
  
 public:
  explicit HLTEventAnalyzerAOD(const edm::ParameterSet&);
  ~HLTEventAnalyzerAOD();

  virtual void beginRun(edm::Run const &, edm::EventSetup const&);
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void analyzeTrigger(const std::string& triggerName);

 private:
  /// Process name of HLT process to analyze
  std::string   processName_;
  std::string   triggerName_;
  edm::InputTag triggerResultsTag_;
  edm::InputTag triggerEventTag_;
  edm::Handle<edm::TriggerResults>   triggerResultsHandle_;
  edm::Handle<trigger::TriggerEvent> triggerEventHandle_;

  /// HLTConfigProvider
  HLTConfigProvider hltConfig_;

};
#endif
