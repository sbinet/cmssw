#include "EventFilter/EcalRawToDigi/plugins/EcalRawToRecHitFacility.h"

EcalRawToRecHitFacility::EcalRawToRecHitFacility(const edm::ParameterSet& iConfig)
{
  sourceTag_=iConfig.getParameter<edm::InputTag>("sourceTag");
  workerName_=iConfig.getParameter<std::string>("workerName");

  //the lazy getter
  produces<EcalRecHitLazyGetter>();

  LogDebug("EcalRawToRecHit|Facility")<<"{ctor} ready to read raw data from: "<<sourceTag_
				      <<"\n using unpacker worker: "<<workerName_
				      <<"\n producing a lazy getter.";
}

EcalRawToRecHitFacility::~EcalRawToRecHitFacility()
{
}


//
// member functions
//

// ------------ method called to produce the data  ------------
void
EcalRawToRecHitFacility::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  MyWatcher watcher("Facility");
  LogDebug("EcalRawToRecHit|Facility")<<watcher.lap();

  // get raw data
  edm::Handle<FEDRawDataCollection> buffers;
  iEvent.getByLabel(sourceTag_, buffers);
  LogDebug("EcalRawToRecHit|Facility")<<"raw data from: "<<sourceTag_<<" retrieved."
				      << watcher.lap();
  
  // retreive cabling
  edm::ESHandle<EcalRegionCabling> cabling;
  iSetup.get<EcalRegionCablingRecord>().get(cabling);
  LogDebug("EcalRawToRecHit|Facility")<<"cabling retrieved."
				      << watcher.lap();
    
  //retreive worker
  edm::ESHandle<EcalUnpackerWorker> worker;
  iSetup.get<EcalUnpackerWorkerRecord>().get(workerName_, worker);
  LogDebug("EcalRawToRecHit|Facility")<<"worker retrieved."
				      << watcher.lap();

  //need to set the event because the worker will be accessing data from the event
  worker->update(iEvent);
  LogDebug("EcalRawToRecHit|Facility")<<"worker updated."
				      << watcher.lap();
  
  //construct a lazy unpacker
  boost::shared_ptr<EcalRawToRecHitLazyUnpacker> unpacker(new EcalRawToRecHitLazyUnpacker(*cabling, *worker, *buffers));
  LogDebug("EcalRawToRecHit|Facility")<<"lazy unpacker created."
				      << watcher.lap();
  
  //store the lazy getter
  std::auto_ptr<EcalRecHitLazyGetter> collection(new EcalRecHitLazyGetter(EcalRegionCabling::maxElementIndex(),unpacker));
  LogDebug("EcalRawToRecHit|Facility")<<"lazy getter created."
				      << watcher.lap();
  
  edm::OrphanHandle<EcalRecHitLazyGetter> lgetter = iEvent.put(collection);
  LogDebug("EcalRawToRecHit|Facility")<<"lazy getter put in the event."
				      << watcher.lap();
}

// ------------ method called once each job just before starting event loop  ------------
void 
EcalRawToRecHitFacility::beginJob(const edm::EventSetup&)
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
EcalRawToRecHitFacility::endJob() {
}
