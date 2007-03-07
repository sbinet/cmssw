#ifndef PerformanceAnalyzer_H
#define PerformanceAnalyzer_H

// user include files

#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "DQMServices/Core/interface/DaqMonitorBEInterface.h"
#include "DQMServices/Daemon/interface/MonitorDaemon.h"

class PerformanceAnalyzer : public edm::EDAnalyzer 
{

   public:
   explicit PerformanceAnalyzer(const edm::ParameterSet&);
   ~PerformanceAnalyzer();
   virtual void analyze(const edm::Event&, const edm::EventSetup&);
   virtual void beginJob(const edm::EventSetup&){} 
   virtual void endJob() ;
 

   private:
   DaqMonitorBEInterface*   fDBE ;
   std::string              fOutputFile ;
   MonitorElement*          fVtxSmeared ;
   MonitorElement*          fg4SimHits ;
   MonitorElement*          fMixing ;
   MonitorElement*          fSiPixelDigis ;
   MonitorElement*          fSiStripDigis ;
   MonitorElement*          fEcalUnsuppDigis ;
   MonitorElement*          fEcalZeroSuppDigis ;
   MonitorElement*          fPreShwZeroSuppDigis ;
   MonitorElement*          fHcalUnsuppDigis ;
   MonitorElement*          fMuonCSCDigis ;
   MonitorElement*          fMuonDTDigis ;
   MonitorElement*          fMuonRPCDigis ;

};

#endif

