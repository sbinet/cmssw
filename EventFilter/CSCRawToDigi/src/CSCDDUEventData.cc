/* CSCDDUEventData.cc
 * Modified 4/21/03 to get rid of arrays and store all CSC data 
 * in vectors. 
 * A.Tumanov
 */

#include "EventFilter/CSCRawToDigi/interface/CSCDDUEventData.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include <iostream>
#include <cstdio>

#include "EventFilter/CSCRawToDigi/src/bitset_append.h"

bool CSCDDUEventData::debug = false;
unsigned int CSCDDUEventData::errMask = 0xFFFFFFFF;


CSCDDUEventData::CSCDDUEventData(const CSCDDUHeader & header) 
{
  theDDUHeader = header;
}

  
CSCDDUEventData::CSCDDUEventData(unsigned short *buf, CSCDCCExaminer* examiner) 
{
  unpack_data(buf, examiner);
}

CSCDDUEventData::~CSCDDUEventData() 
{
}


void CSCDDUEventData::add(CSCEventData & cscData) 
{
  ++(theDDUHeader.ncsc_);
  cscData.setEventInformation(theDDUHeader.bxnum(), theDDUHeader.lvl1num());
  theData.push_back(cscData);
}

void CSCDDUEventData::decodeStatus() const 
{
  this->decodeStatus(theDDUTrailer.errorstat());
}

void CSCDDUEventData::decodeStatus(int code) const 
{
  // JRG is Jason Gilmore
  // JRG, low-order 16-bit status (most serious errors):
  if((code&errMask)>0)
    {///this is a mask for printing out errors
      // JRG, low-order 16-bit status (most serious errors):
      if((code&0x0000F000)>0)
        {
          if((0x00008000&code)>0)
            LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   DDU Critical Error, ** needs reset **";
          if((0x00004000&code)>0)
            LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   DDU Single Error, bad event";
          if((0x00002000&code)>0)
            LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   DDU Single Warning";
          if((0x00001000&code)>0)
            LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   DDU Near Full Warning";
        }
      if((code&0x00000F00)>0)
        {
          if((0x00000800&code)>0) 
            LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   DDU 64-bit Alignment Error";
          if((0x00000400&code)>0)
            LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   DDU Control DLL Error occured";
          if((0x00000200&code)>0)
            LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   DDU DMB Error occurred";
          if((0x00000100&code)>0)
            LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   DDU Lost In Event Error";
        }
      if((code&0x000000F0)>0)
        {
          if((0x00000080&code)>0)
            LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   DDU Lost In Data Error occurred";
          if((0x00000040&code)>0)
            LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   DDU Timeout Error";
          if((0x00000020&code)>0)
            LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   TMB or ALCT CRC Error";
          if((0x00000010&code)>0)
            LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   DDU Multiple Transmit Errors";
        }
      if((code&0x0000000F)>0)
        {
          if((0x00000008&code)>0)
            LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   DDU Sync Lost or FIFO Full Error";
          if((0x00000004&code)>0)
            LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   DDU Fiber/FIFO Connection Error";
          if((0x00000002&code)>0)
            LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   DDU L1A Match Error";
          if((0x00000001&code)>0)
            LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   DDU DMB or CFEB CRC Error";
        }
      if((code&0xF0000000)>0)
        {
          // JRG, high-order 16-bit status (not-so-serious errors):
          if((0x80000000&code)>0)
            LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   DDU DMB LCT/DAV/Movlp Mismatch";
          if((0x40000000&code)>0)
            LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   DDU-CFEB L1 Mismatch";
          if((0x20000000&code)>0)
            LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   DDU saw no good DMB CRCs";
          if((0x10000000&code)>0)
            LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   DDU CFEB Count Error";
        }
      if((code&0x0F000000)>0)
        {
          if((0x08000000&code)>0)
            LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   DDU FirstDat Error";
          if((0x04000000&code)>0)
            LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   DDU L1A-FIFO Full Error";
          if((0x02000000&code)>0)
            LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   DDU Data Stuck in FIFO";
          if((0x01000000&code)>0)
            LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   DDU NoLiveFibers Error";
        }
      if((code&0x00F00000)>0)
        {
          if((0x00800000&code)>0)
            LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   DDU Spwd single-bit Warning";
          if((0x00400000&code)>0)
            LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   DDU Input FPGA Error";
          if((0x00200000&code)>0)
            LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   DDU DAQ Stop bit set";
          if((0x00100000&code)>0)
            LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   DDU DAQ says Not Ready";
          if((0x00300000&code)==0x00200000)
	    LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   DDU DAQ Applied Backpressure";
        }
      if((code&0x000F0000)>0)
        {
          if((0x00080000&code)>0)
            LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   DDU TMB Error";
          if((0x00040000&code)>0)
            LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   DDU ALCT Error";
          if((0x00020000&code)>0)
            LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   DDU Trigger Readout Wordcount Error";
          if((0x00010000&code)>0)
            LogTrace ("CSCDDUEventData|CSCRawToDigi") << "   DDU Trigger L1A Match Error";
        }
    }
}

void CSCDDUEventData::unpack_data(unsigned short *buf, CSCDCCExaminer* examiner) 
{
  // just to calculate length
  unsigned short * inputBuf = buf;
  theData.clear();
  if (debug) LogTrace ("CSCDDUEventData|CSCRawToDigi") << "CSCDDUEventData::unpack_data() is called";
  if (debug) for (int i=0;i<4;++i) 
    {
      LogTrace ("CSCDDUEventData|CSCRawToDigi") << i << std::hex << buf[4*i+3] << buf[4*i+2] 
						<< buf[4*i+1] << buf[4*i];
    }

  memcpy(&theDDUHeader, buf, theDDUHeader.sizeInWords()*2);
  
  if (debug) {
    LogTrace ("CSCDDUEventData|CSCRawToDigi") << "size of ddu header in words = " << theDDUHeader.sizeInWords();
    LogTrace ("CSCDDUEventData|CSCRawToDigi") << "sizeof(DDUHeader) = " << sizeof(theDDUHeader);
  }
  buf += theDDUHeader.sizeInWords();




  //std::cout << "sandrik dduID =" << theDDUHeader.source_id() << std::endl; 
  //int i=-1;

 
  // we really don't want to copy CSCEventData's while filling the vec
  theData.clear();
  theData.reserve(theDDUHeader.ncsc());

  if (examiner!= NULL) { // Use selective unpacking mode

    if (debug) LogTrace ("CSCDDUEventData|CSCRawToDigi") << "selective unpacking starting";

    // Find this DDU in examiner's DDUs list
    int dduID = theDDUHeader.source_id();	
	
    std::map<short,std::map<short,const unsigned short*> > ddus = examiner->DMB_block();
    std::map<short,std::map<short,const unsigned short*> >::iterator ddu_itr = ddus.find(dduID);
    unsigned short* dduBlock = (unsigned short*)((examiner->DDU_block())[dduID]);
    unsigned long dduBufSize = (examiner->DDU_size())[dduID];
		
    if (ddu_itr != ddus.end() && dduBufSize!=0 && dduBlock==inputBuf) {
      std::map<short,const unsigned short*> &cscs = ddu_itr->second;
      std::map<short,const unsigned short*>::iterator csc_itr;

      for (csc_itr=cscs.begin(); csc_itr != cscs.end(); ++csc_itr) {
	short cscid = csc_itr->first;
	unsigned short* pos = (unsigned short*)csc_itr->second;
	
	
        long errors = examiner->errorsForChamber(cscid);
        if ((errors & examiner->getMask()) > 0 ) {	
         	if (debug) 
		LogTrace ("CSCDDUEventData|CSCRawToDigi" )
                       << "skip unpacking of CSC " << cscid << " due format errors: 0x" << std::hex << errors << std::dec;
	  continue;
        } 
	
	theData.push_back(CSCEventData(pos));
      }

      if (debug)
	{
	  LogTrace ("CSCDDUEventData|CSCRawToDigi") << "size of vector of cscData = " << theData.size();
	}

      // decode ddu tail
      memcpy(&theDDUTrailer, inputBuf+dduBufSize, theDDUTrailer.sizeInWords()*2);
      // memcpy(&theDDUTrailer, dduBlock+(dduBufSize-theDDUTrailer.sizeInWords())*2, theDDUTrailer.sizeInWords()*2);
      if (debug) LogTrace ("CSCDDUEventData|CSCRawToDigi") << theDDUTrailer.check();
      errorstat=theDDUTrailer.errorstat();
      if ((errorstat&errMask) != 0)
	{
	  if (theDDUTrailer.check())
	    {
	      if (debug) LogTrace ("CSCDDUEventData|CSCRawToDigi")
		<< "+++ CSCDDUEventData warning: DDU Trailer errors = " << std::hex << errorstat << " +++ ";
	      if (debug) decodeStatus(errorstat);
	    }
	  else
	    {
	      if (debug) LogTrace ("CSCDDUEventData|CSCRawToDigi" )
		<< " Unpacking lost DDU trailer - check() failed and 8 8 ffff 8 was not found ";
	    }
	}

      if (debug) {
	LogTrace ("CSCDDUEventData|CSCRawToDigi")  << " Final errorstat " << std::hex << errorstat << std::dec ;
      }
      // the trailer counts in 64-bit words

      // theSizeInWords = dduBufSize;
      // buf=inputBuf+dduBufSize;

    }
    theSizeInWords = dduBufSize+12;
    buf=inputBuf+dduBufSize;
	
  } else {


    while( (((buf[0]&0xf000) == 0x9000)||((buf[0]&0xf000) == 0xa000)) 
	   && (buf[3] != 0x8000)) {
	// ++i;
	if (debug) LogTrace ("CSCDDUEventData|CSCRawToDigi") << "unpack csc data loop started";
	theData.push_back(CSCEventData(buf));
	buf += (theData.back()).size();
	if (debug) {
	    LogTrace ("CSCDDUEventData|CSCRawToDigi") << "size of vector of cscData = " << theData.size();
	}
    }
 
    if (debug) {
	LogTrace ("CSCDDUEventData|CSCRawToDigi") << "unpacking ddu trailer ";
	LogTrace ("CSCDDUEventData|CSCRawToDigi") << std::hex << buf[3]<<" " << buf[2] 
					 <<" " << buf[1]<<" " << buf[0];
    }

    // decode ddu tail
    memcpy(&theDDUTrailer, buf, theDDUTrailer.sizeInWords()*2);
    if (debug) LogTrace ("CSCDDUEventData|CSCRawToDigi") << theDDUTrailer.check();
    errorstat=theDDUTrailer.errorstat();
    if ((errorstat&errMask) != 0)  
      {
	if (theDDUTrailer.check())
	  {
	    if (debug) LogTrace ("CSCDDUEventData|CSCRawToDigi") 
	      << "+++ CSCDDUEventData warning: DDU Trailer errors = " << std::hex << errorstat << " +++ ";
	    if (debug) decodeStatus(errorstat);
	  } 
	else 
	  {
	    if (debug) LogTrace ("CSCDDUEventData|CSCRawToDigi" ) 
	      << " Unpacking lost DDU trailer - check() failed and 8 8 ffff 8 was not found ";
	  }
      }
   
    if (debug) 
      LogTrace ("CSCDDUEventData|CSCRawToDigi")  << " Final errorstat " << std::hex << errorstat << std::dec ;
    // the trailer counts in 64-bit words
    buf += theDDUTrailer.sizeInWords();
  
    theSizeInWords = buf - inputBuf;
  }
}


bool CSCDDUEventData::check() const 
{
  // the trailer counts in 64-bit words
  if (debug)
    {
      LogTrace ("CSCDDUEventData|CSCRawToDigi") << sizeInWords();
      LogTrace ("CSCDDUEventData|CSCRawToDigi") << "wordcount = " << theDDUTrailer.wordcount()*4;
    }

  return theDDUHeader.check() && theDDUTrailer.check();
}

boost::dynamic_bitset<> CSCDDUEventData::pack() 
{
  boost::dynamic_bitset<> result = bitset_utilities::ushortToBitset( theDDUHeader.sizeInWords()*16,
								     theDDUHeader.data());
  //std::cout <<"SANDRIK inside DDUEvdata check = ";
  //theDDUHeader.check();
  //std::cout <<std::endl;
  //std::cout <<"printing out ddu header words"<<std::endl;
  //for (unsigned int i=0;i<theDDUHeader.sizeInWords();i++) {
  //  unsigned short * buf = theDDUHeader.data();
  //  printf("%04x %04x %04x %04x\n",buf[i+3],buf[i+2],buf[i+1],buf[i]);
  //  i+=3;
  //}
  //std::cout <<"printing out ddu header words via bitset"<<std::endl;
  //bitset_utilities::printWords(result);
 
    
  for(unsigned int i = 0; i < theData.size(); ++i) 
    {
      result = bitset_utilities::append(result,theData[i].pack());
    }
  theSizeInWords = result.size()*16 + theDDUTrailer.sizeInWords();
  theDDUTrailer.setWordCount(theSizeInWords); 
  boost::dynamic_bitset<> dduTrailer = bitset_utilities::ushortToBitset ( theDDUTrailer.sizeInWords()*16, 
									  theDDUTrailer.data());
  result =  bitset_utilities::append(result,dduTrailer);

  return result;
}

