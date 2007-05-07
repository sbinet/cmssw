/** \file
 *
 *  $Date: 2007/04/26 19:02:07 $
 *  $Revision: 1.35 $
 *  \author  M. Zanetti - INFN Padova
 *  \revision FRC 060906
 */

#include <EventFilter/DTRawToDigi/plugins/DTROS25Unpacker.h>

#include <EventFilter/DTRawToDigi/interface/DTDDUWords.h>
#include <EventFilter/DTRawToDigi/interface/DTControlData.h>
#include <EventFilter/DTRawToDigi/interface/DTROChainCoding.h>

#include <EventFilter/DTRawToDigi/interface/DTDataMonitorInterface.h>
#include "FWCore/ServiceRegistry/interface/Service.h"

#include <EventFilter/DTRawToDigi/plugins/DTROSErrorNotifier.h>
#include <EventFilter/DTRawToDigi/plugins/DTTDCErrorNotifier.h>

// Mapping
#include <CondFormats/DTObjects/interface/DTReadOutMapping.h>

#include <iostream>
#include <math.h>

using namespace std;
using namespace edm;




DTROS25Unpacker::DTROS25Unpacker(const edm::ParameterSet& ps): pset(ps) {
  
  if(pset.getUntrackedParameter<bool>("performDataIntegrityMonitor",false)){
    cout<<"[DTROS25Unpacker]: Enabling Data Integrity Checks"<<endl;
    dataMonitor = edm::Service<DTDataMonitorInterface>().operator->();
  }
  
  debug = pset.getUntrackedParameter<bool>("debugMode",false);
  writeSC = pset.getUntrackedParameter<bool>("writeSC",false);
  
  globalDAQ = pset.getUntrackedParameter<bool>("globalDAQ",true);
  if (globalDAQ) cout<<" ANALYZING GLOBAL RUN "<<endl;
  else cout<<" ANALYZING LOCAL RUN "<<endl;
  
}


DTROS25Unpacker::~DTROS25Unpacker() {
  cout<<"[DTROS25Unpacker]: Destructor"<<endl;
}

void DTROS25Unpacker::interpretRawData(const unsigned int* index, int datasize,
				       int dduIDfromDDU,
				       edm::ESHandle<DTReadOutMapping>& mapping,
				       std::auto_ptr<DTDigiCollection>& product,
				       std::auto_ptr<DTLocalTriggerCollection>& product2,
				       uint16_t rosList) {


  int dduID;
  if (pset.getUntrackedParameter<bool>("readDDUIDfromDDU",true))
    dduID = dduIDfromDDU;
  else
    dduID = pset.getUntrackedParameter<int>("dduID",770);
  
  const int wordLength = 4;
  int numberOfWords = datasize / wordLength;
  
  int rosID = 0;
  DTROS25Data controlData(rosID);
  controlDataFromAllROS.clear();
  
  int wordCounter = 0;
  uint32_t word = index[swap(wordCounter)];

  map<uint32_t,int> hitOrder;


  /******************************************************
  / The the loop is performed with "do-while" statements
  / because the ORDER of the words in the event data
  / is assumed to be fixed. Eventual changes into the
  / structure should be considered as data corruption
  *******************************************************/
  
  // Loop on ROSs
  while (wordCounter < numberOfWords) {

    controlData.clean();
    
    rosID++; // to be mapped;

    if ( pset.getUntrackedParameter<bool>("readingDDU",true) ) {
      // matching the ROS number with the enabled DDU channel
      if ( rosID <= 12 && !((rosList & int(pow(2., (rosID-1) )) ) >> (rosID-1) ) ) continue;
      if (debug) cout<<"[DTROS25Unpacker]: ros list: "<<rosList
		     <<" ROS ID "<<rosID<<endl;
    }

    // FRC prepare info for DTLocalTrigger: wheel and sector corresponding to this ROS

    int SCwheel=-3;
    int SCsector=0;
    int dum1, dum2, dum3, dum4;

    if (writeSC && ! mapping->readOutToGeometry(dduID, rosID, 1, 1, 1,
						SCwheel, dum1, SCsector, dum2, dum3, dum4) ) {
      if (debug) cout <<" found SCwheel: "<<SCwheel<<" and SCsector: "<<SCsector<<endl;
    }
    else {
      if (writeSC && debug) cout <<" WARNING failed to find WHEEL and SECTOR for ROS "<<rosID<<" !"<<endl;
    }


    // ROS Header;
    if (DTROSWordType(word).type() == DTROSWordType::ROSHeader) {
      DTROSHeaderWord rosHeaderWord(word);

      if (debug) cout<<"[DTROS25Unpacker]: ROSHeader "<<rosHeaderWord.TTCEventCounter()<<endl;

      // container for words to be sent to DQM
      controlData.setROSId(rosID);
      controlData.addROSHeader(rosHeaderWord);
      

      // Loop on ROBs
      do {
	wordCounter++; word = index[swap(wordCounter)];

	// Eventual ROS Error: occurs when some errors are found in a ROB
	if (DTROSWordType(word).type() == DTROSWordType::ROSError) {
	  DTROSErrorWord dtROSErrorWord(word);
	  controlData.addROSError(dtROSErrorWord);
	  if (debug) cout<<"[DTROS25Unpacker]: ROSError, Error type "<<dtROSErrorWord.errorType()
			 <<" robID "<<dtROSErrorWord.robID()<<endl;
	}

	// Eventual ROS Debugging;
	else if (DTROSWordType(word).type() == DTROSWordType::ROSDebug) {
	  DTROSDebugWord rosDebugWord(word);
	  controlData.addROSDebug(rosDebugWord);
	  if (debug) cout<<"[DTROS25Unpacker]: ROSDebug, type "<<rosDebugWord.debugType()
			 <<"  message "<<rosDebugWord.debugMessage()<<endl;
	}

	// Check ROB header
	else if (DTROSWordType(word).type() == DTROSWordType::GroupHeader) {

	  DTROBHeaderWord robHeaderWord(word);
	  int eventID = robHeaderWord.eventID(); // from the TDCs
	  int bunchID = robHeaderWord.bunchID(); // from the TDCs
	  int robID = robHeaderWord.robID(); // to be mapped

	  DTROBHeader robHeader(robID,robHeaderWord);  // IJ
	  controlData.addROBHeader(robHeader);    // IJ

	  if (debug) cout<<"[DTROS25Unpacker] ROB: ID "<<robID
			 <<" Event ID "<<eventID
			 <<" BXID "<<bunchID<<endl;

	  // Loop on TDCs data (headers and trailers are not there)
	  do {
	    wordCounter++; word = index[swap(wordCounter)];

	    // Eventual TDC Error
	    if ( DTROSWordType(word).type() == DTROSWordType::TDCError) {
	      DTTDCErrorWord dtTDCErrorWord(word);
	      DTTDCError tdcError(robID,dtTDCErrorWord);
	      controlData.addTDCError(tdcError);

	      DTTDCErrorNotifier dtTDCError(dtTDCErrorWord);
	      if (debug) dtTDCError.print();
	    }

	    // Eventual TDC Debug
	    else if ( DTROSWordType(word).type() == DTROSWordType::TDCDebug) {
	      if (debug) cout<<"TDC Debugging"<<endl;
	    }
	    
	    // The TDC information
	    else if (DTROSWordType(word).type() == DTROSWordType::TDCMeasurement) {

	      DTTDCMeasurementWord tdcMeasurementWord(word);
	      DTTDCData tdcData(robID,tdcMeasurementWord);
	      controlData.addTDCData(tdcData);

	      int tdcID = tdcMeasurementWord.tdcID();
	      int tdcChannel = tdcMeasurementWord.tdcChannel();

	      if (debug) cout<<"[DTROS25Unpacker] TDC: ID "<<tdcID
			     <<" Channel "<< tdcChannel
			     <<" Time "<<tdcMeasurementWord.tdcTime()<<endl;

	      DTROChainCoding channelIndex(dduID, rosID, robID, tdcID, tdcChannel);

	      hitOrder[channelIndex.getCode()]++;

	      if (debug) {
		cout<<"[DTROS25Unpacker] ROAddress: DDU "<< dduID
		    <<", ROS "<< rosID
		    <<", ROB "<< robID
		    <<", TDC "<< tdcID
		    <<", Channel "<< tdcChannel<<endl;
	      }

	      // FRC if not already done for this ROS, find wheel and sector for SC data
	      if (writeSC && (SCsector < 1 || SCwheel < -2) ) {

		if (debug) cout <<" second try to find SCwheel and SCsector "<<endl;
		if ( ! mapping->readOutToGeometry(dduID, rosID, robID, tdcID, tdcChannel,
						  SCwheel, dum1, SCsector, dum2, dum3, dum4) ) {
		  if (debug) cout<<" ROS "<<rosID<<" SC wheel "<<SCwheel<<" SC sector "<<SCsector<<endl;
		}
		else {
		  if (debug) cout<<" WARNING !! ROS "<<rosID<<" failed again to map for SC!! "<<endl;
		}
	      }


	      // Map the RO channel to the DetId and wire
	      DTWireId detId;
	      if ( ! mapping->readOutToGeometry(dduID, rosID, robID, tdcID, tdcChannel, detId)) {
		if (debug) cout<<"[DTROS25Unpacker] "<<detId<<endl;
		int wire = detId.wire();

		// Produce the digi
		DTDigi digi( wire, tdcMeasurementWord.tdcTime(), hitOrder[channelIndex.getCode()]-1);

		// Commit to the event
		product->insertDigi(detId.layerId(),digi);
	      }
	      else if (debug) cout<<"[DTROS25Unpacker] Missing wire!"<<endl;

	    } // TDC information

	  } while ( DTROSWordType(word).type() != DTROSWordType::GroupTrailer &&
                    DTROSWordType(word).type() != DTROSWordType::ROSError); // loop on TDC's?

	  // Check ROB Trailer (condition already verified)
	  if (DTROSWordType(word).type() == DTROSWordType::GroupTrailer) {
	    DTROBTrailerWord robTrailerWord(word);
	    controlData.addROBTrailer(robTrailerWord);
	    if (debug) cout<<"[DTROS25Unpacker]: ROBTrailer, robID  "<<robTrailerWord.robID()
			   <<" eventID  "<<robTrailerWord.eventID()
			   <<" wordCount  "<<robTrailerWord.wordCount()<<endl;
	  }
	} // ROB header

	// Check the eventual Sector Collector Header
	else if (DTROSWordType(word).type() == DTROSWordType::SCHeader) {
	  DTLocalTriggerHeaderWord scHeaderWord(word);
	  if (debug) cout<<"[DTROS25Unpacker]: SCHeader  eventID "<<scHeaderWord.eventID()<<endl;

	  // RT added : first word following SCHeader is a SC private header
	  wordCounter++; word = index[swap(wordCounter)];

	  if(DTROSWordType(word).type() == DTROSWordType::SCData){
	    DTLocalTriggerSectorCollectorHeaderWord scPrivateHeaderWord(word);

	    int numofscword = scPrivateHeaderWord.NumberOf16bitWords();
	    int leftword = numofscword;

	    if(debug)  cout<<"[DTROS25Unpacker]: SCPrivateHeader (number of data + subheader = " <<
			 scPrivateHeaderWord.NumberOf16bitWords() << " " <<endl;

	    // if no SC data -> no loop ;
	    // otherwise subtract 1 word (subheader) and countdown for bx assignment
	    if(numofscword > 0){

	      int bx_received = (numofscword - 1) / 2;
	      if(debug)  cout<<"[DTROS25Unpacker]: number of bx " << bx_received << endl;

	      wordCounter++; word = index[swap(wordCounter)];
	      if (DTROSWordType(word).type() == DTROSWordType::SCData) {
		//second word following SCHeader is a SC private SUB-header
		leftword--;

		DTLocalTriggerSectorCollectorSubHeaderWord scPrivateSubHeaderWord(word);
		if(debug)  {
		  cout<<"[DTROS25Unpacker]: SC trigger delay = " <<
		    scPrivateSubHeaderWord.TriggerDelay() << endl;
		  cout<<"[DTROS25Unpacker]: SC bunch counter = " <<
		    scPrivateSubHeaderWord.LocalBunchCounter() << endl;
		}


		// actual loop on SC time slots
		int stationGroup=0;
		do {
		  wordCounter++; word = index[swap(wordCounter)];
		  int SCstation=0;

		  if (DTROSWordType(word).type() == DTROSWordType::SCData) {
		    leftword--;
		    //RT: bx are sent from SC in reverse order starting from the one
		    //which stopped the spy buffer
		    int bx_counter = int(round( (leftword + 1)/ 2.));

		    if(debug){
		      if(bx_counter < 0 || leftword < 0)
			cout<<"[DTROS25Unpacker]: SC data more than expected; negative bx counter reached! "<<endl;
		    }
		    
		    DTLocalTriggerDataWord scDataWord(word);

		    // DTSectorCollectorData scData(scDataWord, int(round(bx_counter/2.))); M.Z.
		    DTSectorCollectorData scData(scDataWord,bx_counter);
		    controlData.addSCData(scData);

		    if (debug) {
		      //cout<<"[DTROS25Unpacker]: SCData bits "<<scDataWord.SCData()<<endl;
		      //cout << " word in esadecimale: " << hex << word << dec << endl;
		      if (scDataWord.hasTrigger(0))
			cout<<" at BX "<< bx_counter //round(bx_counter/2.)
			    <<" lower part has trigger! with track quality "
			    << scDataWord.trackQuality(0)<<endl;
		      if (scDataWord.hasTrigger(1))
			cout<<" at BX "<< bx_counter //round(bx_counter/2.)
			    <<" upper part has trigger! with track quality "
			    << scDataWord.trackQuality(1)<<endl;
		    }

		    if (writeSC && SCwheel >= -2  && SCsector >=1 ) {

		      // FRC: start constructing persistent SC objects:
		      // first identify the station (data come in 2 triggers per word: MB1+MB2, MB3+MB4)
		      if ( scDataWord.hasTrigger(0) || (scDataWord.getBits(0) & 0x30) ) {
			if ( stationGroup%2 == 0) SCstation = 1;
			else                      SCstation = 3;

			// construct localtrigger for first station of this "group" ...
			DTLocalTrigger localtrigger(bx_counter,(scDataWord.SCData()) & 0xFF);
			// ... and commit it to the event
			DTChamberId chamberId (SCwheel,SCstation,SCsector);
			product2->insertDigi(chamberId,localtrigger);
			if (debug) { 
			  cout<<"FRC: just put in product2: "<<chamberId.wheel()
			      <<" "<<chamberId.station()<<" "<<chamberId.sector()
			      <<endl;;
			  localtrigger.print(); }
		      }
		      if ( scDataWord.hasTrigger(1) || (scDataWord.getBits(1) & 0x30) ) {
			if ( stationGroup%2 == 0) SCstation = 2;
			else                      SCstation = 4;

			// construct localtrigger for second station of this "group" ...
			DTLocalTrigger localtrigger(bx_counter,(scDataWord.SCData()) >> 8);
			// ... and commit it to the event
			DTChamberId chamberId (SCwheel,SCstation,SCsector);
			product2->insertDigi(chamberId,localtrigger);
			if (debug) { 
			  cout<<"FRC: just put in product2: "
			      <<chamberId.wheel()<<" "<<chamberId.station()<<" "<<chamberId.sector()
			      <<endl;;
			localtrigger.print(); }
		      }
		      
		      stationGroup++;
		    } // if writeSC
		  } // if SC data
		} while ( DTROSWordType(word).type() != DTROSWordType::SCTrailer );

	      } // end SC subheader
	    } // end if SC send more than only its own header!
	  } //  end if first data following SCheader is not SCData

	  if (DTROSWordType(word).type() == DTROSWordType::SCTrailer) {
	    DTLocalTriggerTrailerWord scTrailerWord(word);
	    if (debug) cout<<"[DTROS25Unpacker]: SCTrailer, number of words "
			   <<scTrailerWord.wordCount()<<endl;
	  }
	}

      } while ( DTROSWordType(word).type() != DTROSWordType::ROSTrailer ); // loop on ROBS

      // check ROS Trailer (condition already verified)
      if (DTROSWordType(word).type() == DTROSWordType::ROSTrailer){
	DTROSTrailerWord rosTrailerWord(word);
	controlData.addROSTrailer(rosTrailerWord);
	if (debug) cout<<"[DTROS25Unpacker]: ROSTrailer "<<rosTrailerWord.EventWordCount()<<endl;
      }
      
      // Perform dqm if requested:
      // DQM IS PERFORMED FOR EACH ROS SEPARATELY
      if (pset.getUntrackedParameter<bool>("performDataIntegrityMonitor",false)) {
	dataMonitor->processROS25(controlData, dduID, rosID);
	// fill the vector with ROS's control data
	controlDataFromAllROS.push_back(controlData);
      }

    }

    else if (index[swap(wordCounter)] == 0) {
      // in the case of odd number of words of a given ROS the header of
      // the next one is postponed by 4 bytes word set to 0.
      // rosID needs to be step back by 1 unit
      if (debug) cout<<"[DTROS25Unpacker]: odd number of ROS words"<<endl;
      rosID--;
    } // if ROS header
    
    else {
      cout<<"[DTROS25Unpacker]: ERROR! First word is not a ROS Header"<<endl;
    }
    
    // (needed if there are more than 1 ROS)
    wordCounter++; word = index[swap(wordCounter)];

  } // loop on ROS!

}


int DTROS25Unpacker::swap(int n) {

  int result=n;

  if (globalDAQ) {
    if (n%2==0) result = (n+1);
    if (n%2==1) result = (n-1);
  }
  
  return result;
}

