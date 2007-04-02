#ifndef DCCEBSRPBLOCK_HH
#define DCCEBSRPBLOCK_HH


/*
 *\ Class DCCEBSRPBlock
 *
 * Class responsible for the SR flag unpacking in the EB.
 *
 * \file DCCEBSRPBlock.h
 *
 * $Date: 2007/03/28 00:43:17 $
 * $Revision: 1.1.2.2 $
 *
 * \author N. Almeida
 *
*/


#include <iostream>
#include <memory>
#include <stdint.h>
#include <string>
#include <vector>
#include <map>
#include <utility>

#include "DCCSRPBlock.h"

#include <DataFormats/EcalDigi/interface/EcalDigiCollections.h>
#include <DataFormats/EcalRawData/interface/EcalRawDataCollections.h>
#include <DataFormats/EcalDetId/interface/EcalDetIdCollections.h>


class DCCEBSRPBlock : public DCCSRPBlock{
	
  public :

    DCCEBSRPBlock( DCCDataUnpacker * u,EcalElectronicsMapper * m, DCCEventBlock * e, bool unpack);
    
    void updateCollectors();
	 
	 
  protected :
  
    void addSRFlagToCollection();
	 
    void checkSrpIdAndNumbSRFlags();
    
    auto_ptr<EBSrFlagCollection>  * ebSrFlagsDigis_;
    
    EcalTrigTowerDetId * pTTDetId_;
		
};


#endif
