/*
 *  $Date: 2006/01/19 20:03:55 $
 *  $Revision: 1.9 $
 *  \author N. Amapane - S. Argiro'
 *  \author G. Franzoni
 */

#include "DAQEcalTBInputService.h"

#include "IORawData/EcalTBInputService/src/EcalTBDaqFileReader.h"

#include <FWCore/Framework/interface/Event.h>
#include <FWCore/ParameterSet/interface/ParameterSet.h>


#include <iostream>

using namespace edm;
using namespace std;


DAQEcalTBInputService::DAQEcalTBInputService(const ParameterSet& pset, 
					     const InputSourceDescription& desc) : 
  edm::ExternalInputSource(pset,desc), reader_(EcalTBDaqFileReader::instance()), fileCounter_(0)
{    
  isBinary_= pset.getUntrackedParameter<bool>("isBinary",true);
  if ( isBinary_ ) {
    cout << "[DAQEcalTBInputService] BINARY input data file" << endl;
  } else {
    cout << "[DAQEcalTBInputService] ASCII input data file" << endl;
  }
  
  produces<FEDRawDataCollection>("EcalDaqRawData");
}



DAQEcalTBInputService::~DAQEcalTBInputService(){
  
  //  clear();
}


// void DAQEcalTBInputService::clear() {
//   for(map<int, DaqFEDRawData *>::iterator it = daqevdata_.begin();
//       it != daqevdata_.end(); ++it) {
//     delete (*it).second;
//   }
//   daqevdata_.clear();
// }

void DAQEcalTBInputService::setRunAndEventInfo()
{
  if ( !reader_->isInitialized() || reader_->checkEndOfFile() )
    {
      if (fileCounter_>=(unsigned int)(fileNames().size())) return; // nothing good
      reader_->initialize(fileNames()[fileCounter_],isBinary_);
      fileCounter_++;
    }
  
  bool eventRead=reader_->fillDaqEventData();
  
  if (eventRead)
    {
      setRunNumber(reader_->getRunNumber());
      //For the moment adding 1 by hand (CMS has event number starting from 1)
      setEventNumber(reader_->getEventNumber()+1);
      // time is a hack
      edm::TimeValue_t present_time = presentTime();
      unsigned long time_between_events = timeBetweenEvents();
      setTime(present_time + time_between_events);
    }
  else
    return;
}

bool DAQEcalTBInputService::produce(edm::Event& e) 
{

  if ( reader_->checkEndOfFile() )
    return false;

  std::auto_ptr<FEDRawDataCollection> bare_product(new  FEDRawDataCollection());

  FEDRawData& eventfeddata = (*bare_product).FEDData(reader_->getFedId());
  eventfeddata.resize(reader_->getFedData().len);
  copy(reader_->getFedData().fedData, reader_->getFedData().fedData + reader_->getFedData().len , eventfeddata.data());

  cout << " DAQEcalTBInputService::read run " << reader_->getRunNumber() << " ev " << reader_->getEventNumber()<< endl;
  e.put(bare_product,"EcalDaqRawData");

  return true;
}


#include "PluginManager/ModuleDef.h"
#include "FWCore/Framework/interface/InputSourceMacros.h"

DEFINE_FWK_INPUT_SOURCE(DAQEcalTBInputService)
