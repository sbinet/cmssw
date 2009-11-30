#include "CondFormats/SiStripObjects/interface/SiStripFedCabling.h"
#include "CondFormats/SiStripObjects/interface/FedChannelConnection.h"
#include "CondFormats/SiStripObjects/interface/SiStripPedestals.h"
#include "CondFormats/SiStripObjects/interface/SiStripNoises.h"
#include "CondFormats/SiStripObjects/interface/SiStripThreshold.h"
#include "CondFormats/SiStripObjects/interface/SiStripApvGain.h"
#include "CondFormats/SiStripObjects/interface/SiStripLorentzAngle.h"
#include "CondFormats/SiStripObjects/interface/SiStripBadStrip.h"
#include "CondFormats/SiStripObjects/interface/SiStripModuleHV.h"
#include "CondFormats/SiStripObjects/interface/SiStripDetVOff.h"
#include "CondFormats/SiStripObjects/interface/SiStripLatency.h"
#include "CondFormats/SiStripObjects/interface/SiStripRunSummary.h"
#include "CondFormats/SiStripObjects/interface/SiStripPerformanceSummary.h"
#include "CondFormats/SiStripObjects/interface/SiStripSummary.h"
#include "CondFormats/SiStripObjects/interface/SiStripConfObject.h"

namespace {
  struct dictionary {
    std::vector< std::vector<FedChannelConnection> > tmp1;
  
#ifdef SISTRIPCABLING_USING_NEW_STRUCTURE
  
//    SiStripFedCabling::Registry            temp12;

#endif
   
    std::vector<SiStripThreshold::Container>  tmp22;
    std::vector< SiStripThreshold::DetRegistry >  tmp24;
 
  };
}  
  
