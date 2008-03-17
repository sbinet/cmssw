#ifndef DQM_SiStripCommissioningSummary_PedsOnlySummaryFactory_H
#define DQM_SiStripCommissioningSummary_PedsOnlySummaryFactory_H

#include "DQM/SiStripCommissioningSummary/interface/CommissioningSummaryFactory.h"

class PedsOnlySummaryFactory : public SummaryPlotFactory<CommissioningAnalysis*> {
  
 protected:
  
  void extract( Iterator );
  
  void format();
  
};

#endif // DQM_SiStripCommissioningSummary_PedsOnlySummaryFactory_H
