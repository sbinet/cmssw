#ifndef DQM_SiPixelMonitorClient_SiPixelDcsInfo_H
#define DQM_SiPixelMonitorClient_SiPixelDcsInfo_H

// system include files
#include <memory>
#include <iostream>
#include <fstream>

// FWCore
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/LuminosityBlock.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

//DQM
#include "DQMServices/Core/interface/DQMStore.h"
#include "DQMServices/Core/interface/MonitorElement.h"


class SiPixelDcsInfo : public edm::EDAnalyzer {
public:
  explicit SiPixelDcsInfo(const edm::ParameterSet&);
  ~SiPixelDcsInfo();
  

private:
  virtual void beginJob(const edm::EventSetup&) ;
  virtual void beginLuminosityBlock(const edm::LuminosityBlock& , const  edm::EventSetup&);
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endLuminosityBlock(const edm::LuminosityBlock& , const  edm::EventSetup&);
  virtual void endJob() ;
  
  DQMStore *dbe_;  
  
  MonitorElement*  DcsFraction_;
  MonitorElement*  DcsFractionBarrel_;
  MonitorElement*  DcsFractionEndcap_;
  MonitorElement*  DcsFractionShellmI_;
  MonitorElement*  DcsFractionShellmO_;
  MonitorElement*  DcsFractionShellpI_;
  MonitorElement*  DcsFractionShellpO_;
  MonitorElement*  DcsFractionHalfCylindermI_;
  MonitorElement*  DcsFractionHalfCylindermO_;
  MonitorElement*  DcsFractionHalfCylinderpI_;
  MonitorElement*  DcsFractionHalfCylinderpO_;

  std::pair<int,int> DCSPixelRange_;

  int  NumberOfDcsChannels_;
 
};

#endif
