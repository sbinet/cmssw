#ifndef LaserTask_H
#define LaserTask_H

#include "DQWorkerTask.h"

#include "DataFormats/EcalRawData/interface/EcalRawDataCollections.h"
#include "DataFormats/EcalDigi/interface/EcalDigiCollections.h"
#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"

namespace ecaldqm {

  class LaserTask : public DQWorkerTask {
  public:
    LaserTask(edm::ParameterSet const&, edm::ParameterSet const&);
    ~LaserTask() {}

    void setDependencies(DependencySet&);

    bool filterRunType(const std::vector<short>&);

    void beginEvent(const edm::Event &, const edm::EventSetup &);

    void analyze(const void*, Collections);

    void runOnRawData(EcalRawDataCollection const&);
    void runOnDigis(const EcalDigiCollection&, Collections);
    void runOnPnDigis(const EcalPnDiodeDigiCollection&);
    void runOnUncalibRecHits(const EcalUncalibratedRecHitCollection&, Collections);

    enum MESets {
      kAmplitudeSummary,
      kAmplitude,
      kOccupancy,
      kTiming,
      kShape,
      kAOverP,
      kPNAmplitude,
      nMESets
    };

    static void setMEOrdering(std::map<std::string, unsigned>&);

  private:
    std::map<int, unsigned> wlToME_;

    bool enable_[BinService::nDCC];
    unsigned wavelength_[BinService::nDCC];
    unsigned rtHalf_[BinService::nDCC];
    std::map<unsigned, std::vector<float> > pnAmp_;

    unsigned ievt_;
  };

  inline void LaserTask::analyze(const void* _p, Collections _collection){
    switch(_collection){
    case kEcalRawData:
      runOnRawData(*static_cast<EcalRawDataCollection const*>(_p));
      break;
    case kEBDigi:
    case kEEDigi:
      runOnDigis(*static_cast<const EcalDigiCollection*>(_p), _collection);
      break;
    case kPnDiodeDigi:
      runOnPnDigis(*static_cast<const EcalPnDiodeDigiCollection*>(_p));
      break;
    case kEBLaserLedUncalibRecHit:
    case kEELaserLedUncalibRecHit:
      runOnUncalibRecHits(*static_cast<const EcalUncalibratedRecHitCollection*>(_p), _collection);
      break;
    default:
      break;
    }
  }

}

#endif
