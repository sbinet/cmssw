/** \class HLTTriggerTypeFilter
 *
 * See header file for documentation
 *
 *  $Date: 2008/01/09 14:16:15 $
 *  $Revision: 1.3 $
 *
 *  \author:  Giovanni FRANZONI
 *
 */

// include files
#include "HLTrigger/special/interface/HLTTriggerTypeFilter.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include <memory>
#include <string>
#include <iostream>

//
// constructors and destructor
//
HLTTriggerTypeFilter::HLTTriggerTypeFilter(const edm::ParameterSet& iConfig)
{
  //now do what ever initialization is needed
  SelectedTriggerType_ = static_cast<unsigned short>(iConfig.getParameter<int>("SelectedTriggerType"));
}


HLTTriggerTypeFilter::~HLTTriggerTypeFilter()
{
 
  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called on each new Event  ------------
bool
HLTTriggerTypeFilter::filter(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  if (iEvent.isRealData()) {
    return (iEvent.experimentType() == SelectedTriggerType_); 
  } else {
    return true;
  }
}

// ------------ method called once each job just before starting event loop  ------------
void 
HLTTriggerTypeFilter::beginJob(const edm::EventSetup&)
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
HLTTriggerTypeFilter::endJob() {
}
