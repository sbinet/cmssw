#ifndef TauAnalysis_CandidateTools_HtRatioProducer_h
#define TauAnalysis_CandidateTools_HtRatioProducer_h

/** \class MEtTopologyProducer
 *
 * Produce data-formats providing information 
 * about distribution of energy deposits in the event 
 * with respect to direction of missing Et vector
 * 
 * \authors Christian Veelken
 *
 * \version $Revision: 1.2 $
 *
 * $Id: MEtTopologyProducer.h,v 1.2 2010/09/28 11:23:28 jkolb Exp $
 *
 */

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"

#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"

#include "TauAnalysis/CandidateTools/interface/HtRatioAlgorithm.h"

class HtRatioProducer : public edm::EDProducer 
{
 public:

  explicit HtRatioProducer(const edm::ParameterSet&);
  ~HtRatioProducer();

  void produce(edm::Event&, const edm::EventSetup&);

 private:

  HtRatioAlgorithm algorithm_;

  edm::InputTag srcJet_;
  edm::InputTag srcTau_;

};

#endif

