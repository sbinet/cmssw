
/*----------------------------------------------------------------------
$Id: OutputWorker.cc,v 1.11 2005/10/12 02:30:39 wmtan Exp $
----------------------------------------------------------------------*/

#include "FWCore/Framework/interface/EventPrincipal.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/OutputModule.h"
#include "FWCore/Framework/interface/Actions.h"
#include "FWCore/Framework/src/WorkerParams.h"
#include "FWCore/Framework/src/OutputWorker.h"
#include "FWCore/Utilities/interface/Exception.h"

#include <iostream>

using namespace std;

namespace edm {
  OutputWorker::OutputWorker(std::auto_ptr<OutputModule> mod,
			     ModuleDescription const& md,
			     WorkerParams const& wp):
      Worker(md,wp),
      mod_(mod) {
  }

  OutputWorker::~OutputWorker() {
  }

  bool 
  OutputWorker::implDoWork(EventPrincipal& ep, EventSetup const&) {
    // EventSetup is not (yet) used. Should it be passed to the
    // OutputModule?
    bool rc = false;

    mod_->write(ep);
    rc=true;
    return rc;
  }

  void 
  OutputWorker::implBeginJob(EventSetup const& es) {
    mod_->beginJob(es);
  }

  void 
  OutputWorker::implEndJob() {
    mod_->endJob();
  }

  std::string OutputWorker::workerType() const {
    return "OutputModule";
  }
  
}
