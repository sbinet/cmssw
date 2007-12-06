// -*- C++ -*-
//
// Package:    SiPixelIsAliveCalibrationAnalyzer
// Class:      SiPixelIsAliveCalibrationAnalyzer
// 
/**\class SiPixelIsAliveCalibration SiPixelIsAliveCalibration.cc CalibTracker/SiPixelIsAliveCalibration/src/SiPixelIsAliveCalibration.cc

 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  Freya Blekman
//         Created:  Mon Dec  3 14:07:42 CET 2007
// $Id$
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "CalibTracker/SiPixelTools/interface/SiPixelOfflineCalibAnalysisBase.h"
#include "DataFormats/SiPixelDigi/interface/SiPixelCalibDigi.h"

//
// class decleration
//

class SiPixelIsAliveCalibration : public SiPixelOfflineCalibAnalysisBase {
   public:
      explicit SiPixelIsAliveCalibration(const edm::ParameterSet&);
      ~SiPixelIsAliveCalibration();

  void doSetup(const edm::ParameterSet &);
      virtual bool doFits(uint32_t detid, std::vector<SiPixelCalibDigi>::const_iterator ipix);
  

   private:
  
      virtual void calibrationSetup(const edm::EventSetup&) ;
      virtual void calibrationEnd() ;
  virtual void newDetID(uint32_t detid);
      // ----------member data ---------------------------

  std::map<uint32_t, MonitorElement *> bookkeeper_;
  double mineff_;
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
SiPixelIsAliveCalibration::SiPixelIsAliveCalibration(const edm::ParameterSet& iConfig):
  SiPixelOfflineCalibAnalysisBase(iConfig),
  mineff_(iConfig.getUntrackedParameter<double>("minEfficiencyForAliveDef",0.8))
{
   //now do what ever initialization is needed

}


SiPixelIsAliveCalibration::~SiPixelIsAliveCalibration()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//
void 
SiPixelIsAliveCalibration::newDetID(uint32_t detid){
  setDQMDirectory(detid);
  std::string tempname=translateDetIdToString(detid);
  bookkeeper_[detid]= bookDQMHistoPlaquetteSummary2D("pixelAlive_"+tempname,"pixel alive for "+tempname, detid);
}
void SiPixelIsAliveCalibration::doSetup(const edm::ParameterSet &iConf){

}
void 
SiPixelIsAliveCalibration::calibrationSetup(const edm::EventSetup & iSetup){

}
bool
SiPixelIsAliveCalibration::doFits(uint32_t detid, std::vector<SiPixelCalibDigi>::const_iterator ipix){
  std::cout << "now looking at DetID " << detid << ", pixel " << ipix->row() << "," << ipix->col() << std::endl;
  
  double denom=0;
  double nom=0;
  for(uint32_t i=0; i<ipix->getnpoints(); i++){
    nom+=ipix->getnentries(i);
    denom+=calib_->getNTriggers();
    if(i>0)
      std::cout << "SiPixelIsAliveCalibration::doFits" << " ERROR!!" << " number of vcal points is now " << i << " for detid " << detid << std::endl;
  }
  std::cout << "DetID/col/row " << detid << "/"<< ipix->col() << "/" << ipix->row() << ", now calculating efficiency: " << nom << "/" << denom <<"=" << nom/denom << std::endl;
  double eff = -1;
  if(denom>0)
    eff = nom;
  if(bookkeeper_[detid]->getBinContent(ipix->col(),ipix->row())==0)
    bookkeeper_[detid]->Fill(ipix->col(), ipix->row(), eff);
  else
    bookkeeper_[detid]->setBinContent(ipix->col(),ipix->row(),-2);
  return true;
}

void
SiPixelIsAliveCalibration::calibrationEnd(){
  // print summary of bad modules:
  for(std::map<uint32_t,MonitorElement *>::const_iterator idet= bookkeeper_.begin(); idet!=bookkeeper_.end();++idet){
    float idead = 0;
    float iunderthres=0;
    float imultiplefill=0;
    float itot=0;
    uint32_t detid=idet->first;
    for(int icol=0; icol < bookkeeper_[detid]->getNbinsX(); ++icol){
      for(int irow=0; irow < bookkeeper_[detid]->getNbinsY(); ++irow){
	itot++;
	double val = bookkeeper_[detid]->getBinContent(icol,irow);
	if(val==0)
	  idead++;
	if(val<mineff_*calib_->getNTriggers())
	  iunderthres++;
	if(val==-2)
	  imultiplefill++;
	
	if(val>0)
	  bookkeeper_[detid]->setBinContent(icol,irow,val/calib_->getNTriggers());
      }
    }
    std::cout << "summary for " << translateDetIdToString(detid) << "\tfrac dead:" << idead/itot << " frac below " << mineff_ << ":" << iunderthres/itot << " bad " <<  imultiplefill/itot << std::endl;
  }

}
// ---------- method called to for each event  ------------

//define this as a plug-in
DEFINE_FWK_MODULE(SiPixelIsAliveCalibration);
