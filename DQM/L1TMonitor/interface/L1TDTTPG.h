#ifndef L1TDTTPG_H
#define L1TDTTPG_H

/*
 * \file L1TDTTPG.h
 *
 * $Date: 2007/07/12 16:06:18 $
 * $Revision: 1.5 $
 * \author J. Berryhill
 *
*/

// system include files
#include <memory>
#include <unistd.h>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"



#include "DQMServices/Core/interface/DaqMonitorBEInterface.h"

//
// class decleration
//

class L1TDTTPG : public edm::EDAnalyzer {

public:

// Constructor
L1TDTTPG(const edm::ParameterSet& ps);

// Destructor
virtual ~L1TDTTPG();

protected:
// Analyze
void analyze(const edm::Event& e, const edm::EventSetup& c);

// BeginJob
void beginJob(const edm::EventSetup& c);

// EndJob
void endJob(void);

private:
  // ----------member data ---------------------------
  DaqMonitorBEInterface * dbe;

  MonitorElement* dttpgphbx[8];  
  MonitorElement* dttpgphbxcomp;
  MonitorElement* dttpgphwheel[3];  
  MonitorElement* dttpgphsector[3];  
  MonitorElement* dttpgphstation[3];  
  MonitorElement* dttpgphphi[3];  
  MonitorElement* dttpgphphiB[3];  
  MonitorElement* dttpgphquality[3];  
  MonitorElement* dttpgphts2tag[3];  
  MonitorElement* dttpgphbxcnt[3];  
  MonitorElement* dttpgphntrack;  

  MonitorElement* dttpgthbx[3];  
  MonitorElement* dttpgthwheel[3];  
  MonitorElement* dttpgthsector[3];  
  MonitorElement* dttpgthstation[3];  
  MonitorElement* dttpgththeta[3];  
  MonitorElement* dttpgthquality[3];    
  MonitorElement* dttpgthntrack;  

  MonitorElement *dttf_p_phi[3];
  MonitorElement *dttf_p_pt[3];
  MonitorElement *dttf_p_q[3];
  MonitorElement *dttf_p_qual[3];

  int nev_; // Number of events processed
  std::string outputFile_; //file name for ROOT ouput
  bool verbose_;
  bool monitorDaemon_;
  ofstream logFile_;
  edm::InputTag dttpgSource_;
};

#endif
