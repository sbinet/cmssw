#ifndef DCCSRPBLOCK_HH
#define DCCSRPBLOCK_HH


/*
 *\ Class DCCSRPBlock
 *
 * Class responsible for SR flag unpacking.
 *
 * \file DCCSRPBlock.h
 *
 * $Date: 2007/03/20 01:10:21 $
 * $Revision: 1.1.2.1 $
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

#include "DCCDataBlockPrototype.h"

#include <DataFormats/EcalDigi/interface/EcalDigiCollections.h>
#include <DataFormats/EcalRawData/interface/EcalRawDataCollections.h>
#include <DataFormats/EcalDetId/interface/EcalDetIdCollections.h>


class DCCSRPBlock : public DCCDataBlockPrototype {
	
  public :

    DCCSRPBlock( DCCDataUnpacker * u,EcalElectronicsMapper * m, DCCEventBlock * e, bool unpack);
	 
    void display(ostream & o); 

    void unpack(uint64_t ** data, uint * dwToEnd, uint numbFlags = SRP_NUMBFLAGS);     	 
    
    ushort srFlag(uint feChannel){ return srFlags_[feChannel-1]; }
    			
  protected :
    
    virtual void addSRFlagToCollection(){};
	 
    virtual void checkSrpIdAndNumbSRFlags(){};
	 
    uint srpId_         ;  
    uint bx_            ;  
    uint l1_            ;   
    uint nSRFlags_      ; 
    uint expNumbSrFlags_;
	 
    ushort srFlags_[SRP_NUMBFLAGS]; 
	 
	 
	 
};


#endif
