#ifndef HiggsAnalysis_CombinedLimit_MarkovChainMC_h
#define HiggsAnalysis_CombinedLimit_MarkovChainMC_h
/** \class MarkovChainMC
 *
 * abstract interface for physics objects
 *
 * \author Luca Lista (INFN), from initial implementation by Giovanni Petrucciani (UCSD)
 *
 *
 */
#include "HiggsAnalysis/CombinedLimit/interface/LimitAlgo.h"

class MarkovChainMC : public LimitAlgo {
public:
  MarkovChainMC() ;
  virtual void applyOptions(const boost::program_options::variables_map &vm) ;
  bool run(RooWorkspace *w, RooAbsData &data, double &limit);
  virtual const std::string & name() const {
    static const std::string name("MarkovChainMC");
    return name;
  }
private:
  enum ProposalType { FitP, UniformP, MultiGaussianP };
  std::string proposalTypeName_;
  ProposalType proposalType_;
  bool runMinos_, noReset_, updateProposalParams_;
  unsigned int iterations_;
  unsigned int burnInSteps_;
  unsigned int numberOfBins_;
  unsigned int proposalHelperCacheSize_;
  float        proposalHelperWidthRangeDivisor_, proposalHelperUniformFraction_;
};

#endif
