#ifndef CSCBaseValidation_h
#define CSCBaseValidation_h

// user include files

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/ParameterSet/interface/InputTag.h"

#include "DQMServices/Core/interface/DQMStore.h"
#include "SimMuon/MCTruth/interface/PSimHitMap.h"
#include "Geometry/CSCGeometry/interface/CSCGeometry.h"


class CSCBaseValidation {
public:
  CSCBaseValidation(DQMStore* dbe, const edm::InputTag & inputTag);
  virtual ~CSCBaseValidation() {}
 
  void setGeometry(const CSCGeometry * geom) {theCSCGeometry = geom;}
  void setSimHitMap(const  PSimHitMap * simHitMap) {theSimHitMap = simHitMap;}

  virtual void analyze(const edm::Event&e, const edm::EventSetup& eventSetup) = 0;

 protected:
  const CSCLayer * findLayer(int detId) const;

  DQMStore* dbe_;
  edm::InputTag theInputTag;
  const PSimHitMap * theSimHitMap;
  const CSCGeometry * theCSCGeometry;
};

#endif

