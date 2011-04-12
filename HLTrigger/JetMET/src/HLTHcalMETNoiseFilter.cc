// -*- C++ -*-
//
// Class:      HLTHcalMETNoiseFilter
// 
/**\class HLTHcalMETNoiseFilter

 Description: HLT filter module for rejecting MET events due to noise in the HCAL

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  Leonard Apanasevich
//         Created:  Wed Mar 25 16:01:27 CDT 2009
// $Id: HLTHcalMETNoiseFilter.cc,v 1.13 2011/02/11 20:55:24 wdd Exp $
//
//

#include "HLTrigger/JetMET/interface/HLTHcalMETNoiseFilter.h"

#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/METReco/interface/HcalNoiseRBX.h"

#include "FWCore/ParameterSet/interface/ConfigurationDescriptions.h"
#include "FWCore/ParameterSet/interface/ParameterSetDescription.h"
#include "FWCore/Utilities/interface/InputTag.h"

#include <iostream>

HLTHcalMETNoiseFilter::HLTHcalMETNoiseFilter(const edm::ParameterSet& iConfig)
  : HcalNoiseRBXCollectionTag_(iConfig.getParameter<edm::InputTag>("HcalNoiseRBXCollection")),
    severity_(iConfig.getParameter<int> ("severity")),
    maxNumRBXs_(iConfig.getParameter<int>("maxNumRBXs")),
    numRBXsToConsider_(iConfig.getParameter<int>("numRBXsToConsider")),
    needEMFCoincidence_(iConfig.getParameter<bool>("needEMFCoincidence")),
    minRBXEnergy_(iConfig.getParameter<double>("minRBXEnergy")),
    minRatio_(iConfig.getParameter<double>("minRatio")),
    maxRatio_(iConfig.getParameter<double>("maxRatio")),
    minHPDHits_(iConfig.getParameter<int>("minHPDHits")),
    minRBXHits_(iConfig.getParameter<int>("minRBXHits")),
    minHPDNoOtherHits_(iConfig.getParameter<int>("minHPDNoOtherHits")),
    minZeros_(iConfig.getParameter<int>("minZeros")),
    minHighEHitTime_(iConfig.getParameter<double>("minHighEHitTime")),
    maxHighEHitTime_(iConfig.getParameter<double>("maxHighEHitTime")),
    maxRBXEMF_(iConfig.getParameter<double>("maxRBXEMF")),
    minRecHitE_(iConfig.getParameter<double>("minRecHitE")),
    minLowHitE_(iConfig.getParameter<double>("minLowHitE")),
    minHighHitE_(iConfig.getParameter<double>("minHighHitE")),
    TS4TS5EnergyThreshold_(iConfig.getParameter<double>("TS4TS5EnergyThreshold"))
{

  std::vector<double> TS4TS5UpperThresholdTemp = iConfig.getParameter<std::vector<double> >("TS4TS5UpperThreshold");
  std::vector<double> TS4TS5UpperCutTemp = iConfig.getParameter<std::vector<double> >("TS4TS5UpperCut");
  std::vector<double> TS4TS5LowerThresholdTemp = iConfig.getParameter<std::vector<double> >("TS4TS5LowerThreshold");
  std::vector<double> TS4TS5LowerCutTemp = iConfig.getParameter<std::vector<double> >("TS4TS5LowerCut");

  for(int i = 0; i < (int)TS4TS5UpperThresholdTemp.size() && i < (int)TS4TS5UpperCutTemp.size(); i++)
     TS4TS5UpperCut_.push_back(std::pair<double, double>(TS4TS5UpperThresholdTemp[i], TS4TS5UpperCutTemp[i]));
  sort(TS4TS5UpperCut_.begin(), TS4TS5UpperCut_.end());

  for(int i = 0; i < (int)TS4TS5LowerThresholdTemp.size() && i < (int)TS4TS5LowerCutTemp.size(); i++)
     TS4TS5LowerCut_.push_back(std::pair<double, double>(TS4TS5LowerThresholdTemp[i], TS4TS5LowerCutTemp[i]));
  sort(TS4TS5LowerCut_.begin(), TS4TS5LowerCut_.end());
}


HLTHcalMETNoiseFilter::~HLTHcalMETNoiseFilter(){}

void
HLTHcalMETNoiseFilter::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  edm::ParameterSetDescription desc;
  desc.add<edm::InputTag>("HcalNoiseRBXCollection",edm::InputTag("hltHcalNoiseInfoProducer"));
  desc.add<int>("severity",1);
  desc.add<int>("maxNumRBXs",2);
  desc.add<int>("numRBXsToConsider",2);
  desc.add<bool>("needEMFCoincidence",true);
  desc.add<double>("minRBXEnergy",50.0);
  desc.add<double>("minRatio",0.65);
  desc.add<double>("maxRatio",0.98);
  desc.add<int>("minHPDHits",17);
  desc.add<int>("minRBXHits",999);
  desc.add<int>("minHPDNoOtherHits",10);
  desc.add<int>("minZeros",10);
  desc.add<double>("minHighEHitTime",-9999.0);
  desc.add<double>("maxHighEHitTime",9999.0);
  desc.add<double>("maxRBXEMF",0.02);
  desc.add<double>("minRecHitE",1.5);
  desc.add<double>("minLowHitE",10.0);
  desc.add<double>("minHighHitE",25.0);
  desc.add<double>("TS4TS5EnergyThreshold",50.0);

  double TS4TS5UpperThresholdArray[5] = {70, 90, 100, 400, 4000 };
  double TS4TS5UpperCutArray[5] = {1, 0.8, 0.75, 0.72, 0.72};
  double TS4TS5LowerThresholdArray[7] = {100, 120, 150, 200, 300, 400, 500};
  double TS4TS5LowerCutArray[7] = {-1, -0.7, -0.4, -0.2, -0.08, 0, 0.1};
  std::vector<double> TS4TS5UpperThreshold(TS4TS5UpperThresholdArray, TS4TS5UpperThresholdArray+5);
  std::vector<double> TS4TS5UpperCut(TS4TS5UpperCutArray, TS4TS5UpperCutArray+5);
  std::vector<double> TS4TS5LowerThreshold(TS4TS5LowerThresholdArray, TS4TS5LowerThresholdArray+7);
  std::vector<double> TS4TS5LowerCut(TS4TS5LowerCutArray, TS4TS5LowerCutArray+7);

  desc.add<std::vector<double> >("TS4TS5UpperThreshold", TS4TS5UpperThreshold);
  desc.add<std::vector<double> >("TS4TS5UpperCut", TS4TS5UpperCut);
  desc.add<std::vector<double> >("TS4TS5LowerThreshold", TS4TS5LowerThreshold);
  desc.add<std::vector<double> >("TS4TS5LowerCut", TS4TS5LowerCut);
  descriptions.add("hltHcalMETNoiseFilter",desc);
}

//
// member functions
//

bool HLTHcalMETNoiseFilter::filter(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace reco;

  // in this case, do not filter anything
  if(severity_==0) return true;

  // get the RBXs produced by RecoMET/METProducers/HcalNoiseInfoProducer
  edm::Handle<HcalNoiseRBXCollection> rbxs_h;
  iEvent.getByLabel(HcalNoiseRBXCollectionTag_,rbxs_h);
  if(!rbxs_h.isValid()) {
    edm::LogError("DataNotFound") << "HLTHcalMETNoiseFilter: Could not find HcalNoiseRBXCollection product named "
				  << HcalNoiseRBXCollectionTag_ << "." << std::endl;
    return true;
  }

  // reject events with too many RBXs
  if(static_cast<int>(rbxs_h->size())>maxNumRBXs_) return true;

  // create a sorted set of the RBXs, ordered by energy
  noisedataset_t data;
  for(HcalNoiseRBXCollection::const_iterator it=rbxs_h->begin(); it!=rbxs_h->end(); ++it) {
    const HcalNoiseRBX &rbx=(*it);
    CommonHcalNoiseRBXData d(rbx, minRecHitE_, minLowHitE_, minHighHitE_, TS4TS5EnergyThreshold_,
			     TS4TS5UpperCut_, TS4TS5LowerCut_);
    data.insert(d);
  }

  // data is now sorted by RBX energy
  // only consider top N=numRBXsToConsider_ energy RBXs
  int cntr=0;
  for(noisedataset_t::const_iterator it=data.begin();
      it!=data.end() && cntr<numRBXsToConsider_;
      ++it, ++cntr) {

    bool passFilter=true;
    bool passEMF=true;
    if(it->energy()>minRBXEnergy_) {
      if(it->validRatio() && it->ratio()<minRatio_)        passFilter=false;
      else if(it->validRatio() && it->ratio()>maxRatio_)   passFilter=false;
      else if(it->numHPDHits()>=minHPDHits_)               passFilter=false;
      else if(it->numRBXHits()>=minRBXHits_)               passFilter=false;
      else if(it->numHPDNoOtherHits()>=minHPDNoOtherHits_) passFilter=false;
      else if(it->numZeros()>=minZeros_)                   passFilter=false;
      else if(it->minHighEHitTime()<minHighEHitTime_)      passFilter=false;
      else if(it->maxHighEHitTime()>maxHighEHitTime_)      passFilter=false;
      // don't implement the TS5TS5 cut at all
      //      else if(!it->PassTS4TS5())                           passFilter=false;

      if(it->RBXEMF()<maxRBXEMF_) passEMF=false;
    }

    if((needEMFCoincidence_ && !passEMF && !passFilter) ||
       (!needEMFCoincidence_ && !passFilter)) {
      LogDebug("") << "HLTHcalMETNoiseFilter debug: Found a noisy RBX: "
		   << "energy=" << it->energy() << "; "
		   << "ratio=" << it->ratio() << "; "
		   << "# RBX hits=" << it->numRBXHits() << "; "
		   << "# HPD hits=" << it->numHPDHits() << "; "
		   << "# Zeros=" << it->numZeros() << "; "
		   << "min time=" << it->minHighEHitTime() << "; "
		   << "max time=" << it->maxHighEHitTime() << "; "
		   << "RBX EMF=" << it->RBXEMF()
		   << std::endl;
      return false;
    }
  }

  // no problems found
  return true;
}
