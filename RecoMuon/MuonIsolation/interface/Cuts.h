#ifndef MuonIsolation_Cuts_H
#define MuonIsolation_Cuts_H

#include "RecoMuon/MuonIsolation/interface/Range.h"
#include <vector>

namespace muonisolation {

class Cuts {
public:

  struct CutSpec { muonisolation::Range<double> etaRange; double conesize; double threshold; }; 

  Cuts( const std::vector<double> & etaBounds, 
        const std::vector<double> & coneSizes, 
        const std::vector<double> & thresholds);

  const CutSpec & operator()(double eta) const;

private:
  std::vector<CutSpec> theCuts;
};

}
#endif
