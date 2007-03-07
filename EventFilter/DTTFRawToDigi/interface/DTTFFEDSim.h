//-------------------------------------------------
//
/**  \class DTTFFEDSim
 *
 *   L1 DT Track Finder Digi-to-Raw
 *
 *
 *   $Date: 2006/06/01 00:00:00 $
 *   $Revision: 1.1 $
 *
 *   J. Troconiz  UAM Madrid
 */
//
//--------------------------------------------------
#ifndef DTTFRawToDigi_DTTFFEDSim_h
#define DTTFRawToDigi_DTTFFEDSim_h

#include "DataFormats/FEDRawData/interface/FEDRawDataCollection.h"

#include <FWCore/Framework/interface/EDProducer.h>
#include <FWCore/ParameterSet/interface/ParameterSet.h>

#include <string>

class DTTFFEDSim : public edm::EDProducer {

 public:

  /// Constructor
  DTTFFEDSim(const edm::ParameterSet& pset);

  /// Destructor
  virtual ~DTTFFEDSim();

  /// Produce digis out of raw data
  void produce(edm::Event & e, const edm::EventSetup& c);

  /// Generate and fill FED raw data for a full event
  bool fillRawData(edm::Event& e,
                   FEDRawDataCollection& data);

 private:
  
  unsigned int eventNum;

 // utilities
  int channel(int wheel, int sector, int bx);

  int bxNr(int channel);

  int sector(int channel);

  int wheel(int channel);

  void calcCRC(long myD1, long myD2, int &myC);

};
#endif
