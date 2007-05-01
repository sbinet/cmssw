#ifndef Framework_Frameworkfwd_h
#define Framework_Frameworkfwd_h

/*----------------------------------------------------------------------
  
Forward declarations of types in the EDM.

$Id: Frameworkfwd.h,v 1.37 2007/04/09 22:18:55 wdd Exp $

----------------------------------------------------------------------*/

#include "DataFormats/Common/interface/EDProductfwd.h"
#include "DataFormats/Provenance/interface/ProvenanceFwd.h"

namespace edm {
  class ConfigurableInputSource;
  class CurrentProcessingContext;
  class DelayedReader;
  class DataViewImpl;
  class EDAnalyzer;
  class EDFilter;
  class EDLooper;
  class EDLooperHelper;
  class EDProducer;
  class Event;
  class EventPrincipal;
  class EventSetup;
  class GeneratedInputSource;
  class Group;
  class InputSource;
  class InputSourceDescription;
  class LuminosityBlock;
  class LuminosityBlockPrincipal;
  class OutputModule;
  class ParameterSet;
  class Principal;
  class ProcessNameSelector;
  class ProductRegistryHelper;
  class Run;
  class RunPrincipal;
  class Schedule;
  class Selector;
  class SelectorBase;
  class TypeID;
  class UnsheduledHandler;

  struct EventSummary;
  struct PathSummary;
  struct TriggerReport;
  template <typename T> class View;
}

// The following are trivial enough so that the real headers can be included.
#include "FWCore/Framework/interface/BranchActionType.h"

#endif
