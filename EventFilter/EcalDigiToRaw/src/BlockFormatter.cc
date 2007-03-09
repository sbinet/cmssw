#include <memory>
#include <iostream>

// user include files

#include "EventFilter/EcalDigiToRaw/interface/EcalDigiToRaw.h"
#include "EventFilter/EcalDigiToRaw/interface/BlockFormatter.h"
#include "DataFormats/FEDRawData/interface/FEDNumbering.h"
#include "DataFormats/EcalDetId/interface/EcalElectronicsId.h"


using namespace std;

BlockFormatter::BlockFormatter() {

  EcalFEDIds=FEDNumbering::getEcalFEDIds();
}

BlockFormatter::~BlockFormatter() {
}


void BlockFormatter::SetParam(EcalDigiToRaw* base) {

 pcounter_ = (base -> GetCounter());
 debug_   = base -> GetDebug();
 porbit_number_ = (base -> GetOrbit());
 plv1_ = (base -> GetLV1());
 pbx_  = (base -> GetBX());
 prunnumber_ = (base -> GetRunNumber());
 doBarrel_ = base -> GetDoBarrel();
 doEndCap_ = base -> GetDoEndCap();
 doTCC_ = base -> GetDoTCC();
 doSR_ = base -> GetDoSR();
 doTower_ = base -> GetDoTower();

}


void BlockFormatter::DigiToRaw(FEDRawDataCollection* productRawData) {

 int run_number = *prunnumber_;
 int orbit_number_ = *porbit_number_;
 int bx = *pbx_;
 int lv1 = *plv1_;

 if (debug_) cout << "in BlockFormatter::DigiToRaw  run_number orbit_number bx lv1 " << dec << run_number << " " <<
         orbit_number_ << " " << bx << " " << lv1 << endl;

 for (int idcc=1; idcc <= 54; idcc++) {
	if ( (! doBarrel_) && 
	     (idcc >= EcalElectronicsId::MIN_DCCID_EBM && idcc <= EcalElectronicsId::MAX_DCCID_EBP)) continue;
	if ( (! doEndCap_) && 
             (idcc <= EcalElectronicsId::MAX_DCCID_EEM || idcc >= EcalElectronicsId::MIN_DCCID_EEP)) continue;
 
	int FEDid = EcalFEDIds.first + idcc;
	FEDRawData& rawdata = productRawData -> FEDData(FEDid);
        unsigned char * pData;
        short int DCC_ERRORS = 0;

	if (rawdata.size() == 0) {
                rawdata.resize(8);
                pData = rawdata.data();

                Word64 word = 0x18 + ((FEDid & 0xFFF)<<8)
			    + ((Word64)((Word64)bx & 0xFFF)<<20)
                            + ((Word64)((Word64)lv1 & 0xFFFFFF)<<32)
                            + (Word64)((Word64)0x51<<56);
                Word64* pw = reinterpret_cast<Word64*>(const_cast<unsigned char*>(pData));
                *pw = word;    // DAQ header

                rawdata.resize(rawdata.size() + 8*8);   // DCC header
                pData = rawdata.data();
                pData[11] = DCC_ERRORS & 0xFF;
                pData[12] = run_number & 0xFF;
                pData[13] = run_number & 0xFF00;
                pData[14] = run_number & 0xFF0000;
                pData[15] = 0x01;

                for (int i=16; i <= 22; i++) {
                 pData[i] = 0;    // to be filled for local data taking or calibration
                }
                pData[23] = 0x02;
                pData[24] = orbit_number_ & 0xFFFFFFFF;
		int SRenable_ = 1;
                int SR = SRenable_;
                int ZS = 0;
                int TZS = 0;
                // int SR_CHSTATUS = 0;
                pData[28] = (SR&0x1) + ((ZS&0x1)<<1) + ((TZS&0x1)<<2);
                pData[31] = 0x03;

                for (int i=0; i<=4; i++) {
                  for (int j=0; j<7; j++) {
                   pData[32 +8*i + j] = 0;
                  }
                  pData[32 +8*i + 7] = 0x04;
                }

	} // endif rawdatasize == 0
 } // loop on id

}



void BlockFormatter::print(FEDRawData& rawdata) {
        int size = rawdata.size();
        cout << "Print RawData  size " << dec << size << endl;
        unsigned char* pData = rawdata.data();

        int n = size/8;
        for (int i=0; i < n; i++) {
                for (int j=7; j>=0; j--) {
                  if (8*i+j <= size) cout << hex << (int)pData[8*i+j] << " ";
                }
                cout << endl;
        }
}



void BlockFormatter::CleanUp(FEDRawDataCollection* productRawData) {


 for (int id=0; id < 36 + 18; id++) {
        if ( (! doBarrel_) && (id >= 9 && id <= 44)) continue;
        if ( (! doEndCap_) && (id <= 8 || id >= 45)) continue;


        int FEDid = EcalFEDIds.first + id +1;
        FEDRawData& rawdata = productRawData -> FEDData(FEDid);

	// ---- Add the trailer word
	int lastline = rawdata.size();
	rawdata.resize( lastline + 8);
	unsigned char * pData = rawdata.data(); 
	int event_length = (lastline + 8) / 8;   // in 64 bits words

	pData[lastline+7] = 0xa0;
 	pData[lastline+4] = event_length & 0xFFFFFF;
        int event_status = 0;
        pData[lastline+1] = event_status & 0x0F;
        int tts = 0 <<4;
        pData[lastline] = tts & 0xF0;

        // ---- Write the event length in the DCC header
        pData[8] = event_length & 0xFFFFFF;
	

 	
 }
}


void BlockFormatter::PrintSizes(FEDRawDataCollection* productRawData) {


 for (int id=0; id < 36 + 18; id++) {

        // if ( (! doBarrel_) && (id >= 9 && id <= 44)) continue;
        // if ( (! doEndCap_) && (id <= 8 || id >= 45)) continue;


        int FEDid = EcalFEDIds.first + id;
        FEDRawData& rawdata = productRawData -> FEDData(FEDid);
        if (rawdata.size() > 0)
	cout << "Size of FED id " << dec << FEDid << " is : " << dec << rawdata.size() << endl;

 }
}


