#ifndef EventFilter_SiStripRawToDigi_SiStripRawToClustersDummyUnpacker_H
#define EventFilter_SiStripRawToDigi_SiStripRawToClustersDummyUnpacker_H

#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/SiStripCommon/interface/SiStripRefGetter.h"
#include "DataFormats/SiStripCluster/interface/SiStripCluster.h"
#include <string>
#include <memory>
#include "boost/bind.hpp"

/**
   @file EventFilter/SiStripRawToDigi/interface/SiStripRawToClustersDummyUnpacker.h
   @class SiStripRawToClustersDummyUnpacker
*/

class SiStripRawToClustersDummyUnpacker : public edm::EDAnalyzer {
  
 public:

  typedef edm::DetSet<SiStripCluster> DetSet;
  typedef edm::SiStripLazyGetter<SiStripCluster> LazyGetter;
  typedef edm::SiStripRefGetter<SiStripCluster> RefGetter;

  SiStripRawToClustersDummyUnpacker( const edm::ParameterSet& );
  ~SiStripRawToClustersDummyUnpacker();
  
  virtual void beginJob( const edm::EventSetup& );
  virtual void endJob();
  virtual void analyze( const edm::Event&, const edm::EventSetup& );
  
 private: 

  /** Input label */
  edm::InputTag siStripLazyGetter_;
  edm::InputTag siStripRefGetter_;
};

#endif //  EventFilter_SiStripRawToDigi_SiStripRawToClustersDummyRoI_H

