#ifndef __MultipleAlgoIterator_h_
#define __MultipleAlgoIterator_h_

#include "RecoJets/JetProducers/interface/PileUpSubtractor.h"

class MultipleAlgoIterator : public PileUpSubtractor {
 public:
   MultipleAlgoIterator(const edm::ParameterSet& iConfig) : PileUpSubtractor(iConfig),
      sumRecHits_(iConfig.getParameter<bool>("sumRecHits")){;}
    virtual void offsetCorrectJets();
    void rescaleRMS(double s);
    double getEt(const reco::CandidatePtr & in) const;
    double getEta(const reco::CandidatePtr & in) const;
    virtual void calculatePedestal(std::vector<fastjet::PseudoJet> const & coll);
    virtual void subtractPedestal(std::vector<fastjet::PseudoJet> & coll);

    bool sumRecHits_;
    ~MultipleAlgoIterator(){;}
    
};


#endif
