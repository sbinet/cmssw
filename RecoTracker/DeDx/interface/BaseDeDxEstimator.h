#ifndef RecoTrackerDeDx_BaseDeDxEstimator_h
#define RecoTrackerDeDx_BaseDeDxEstimator_h
#include "DataFormats/TrackReco/interface/DeDxHit.h"

class BaseDeDxEstimator
{
public: 
 virtual float dedx(const reco::DeDxHitCollection & Hits) = 0;



};

#endif

