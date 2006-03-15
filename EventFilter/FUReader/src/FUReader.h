#ifndef DaqSource_FUReader_h
#define DaqSource_FUReader_h

/** \class FUReader
 *  $Date: 2005/11/22 09:50:42 $
 *  $Revision: 1.3 $
 *  \author E. Meschi - CERN PH/CMD
 */
#include "EventFilter/Unit/interface/FURawEvent.h"
#include "EventFilter/Unit/interface/EventSink.h"
#include <IORawData/DaqSource/interface/DaqBaseReader.h>
#include <DataFormats/Common/interface/EventID.h>
#include <algorithm>
#include <pthread.h>

class FUReader : public DaqBaseReader, public EventSink {
 public:
  /// Constructor
  FUReader(const edm::ParameterSet& pset);

  /// Destructor
  virtual ~FUReader();

  /// Generate and fill FED raw data for a full event
  virtual bool fillRawData(edm::EventID& eID,
			   edm::Timestamp& tstamp, 
			   FEDRawDataCollection& data);

  void sink(){}
 private:
  void fillFEDs(const std::pair<int,int>&,
		FEDRawDataCollection&,
		FURawEvent &);

  edm::RunNumber_t runNum;
  edm::EventNumber_t eventNum;
  pthread_cond_t ready_;
  pthread_mutex_t lock_;
};
#endif

