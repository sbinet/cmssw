#ifndef RecoLocalCalo_EcalRecAlgos_EcalRecHitSimpleAlgo_HH
#define RecoLocalCalo_EcalRecAlgos_EcalRecHitSimpleAlgo_HH

/** \class EcalRecHitSimpleAlgo
  *  Simple algoritm to make rechits from uncalibrated rechits
  *
  *  $Id: EcalRecHitSimpleAlgo.h,v 1.4 2009/03/27 18:07:38 ferriff Exp $
  *  $Date: 2009/03/27 18:07:38 $
  *  $Revision: 1.4 $
  *  \author Shahram Rahatlou, University of Rome & INFN, March 2006
  */

#include "RecoLocalCalo/EcalRecAlgos/interface/EcalRecHitAbsAlgo.h"
#include "DataFormats/EcalDigi/interface/EcalDataFrame.h"
#include "TMath.h"
#include <iostream>

class EcalRecHitSimpleAlgo : public EcalRecHitAbsAlgo {
 public:
  // default ctor
  EcalRecHitSimpleAlgo() {
    adcToGeVConstant_ = -1;
    adcToGeVConstantIsSet_ = false;
  }

  virtual void setADCToGeVConstant(const float& value) {
    adcToGeVConstant_ = value;
    adcToGeVConstantIsSet_ = true;
  }


  // destructor
  virtual ~EcalRecHitSimpleAlgo() { };

  /// Compute parameters
  virtual EcalRecHit makeRecHit(const EcalUncalibratedRecHit& uncalibRH,
                                const float& intercalibConstant,
                                const float& timeIntercalib = 0,
                                const uint32_t& flags = 0) const {

    if(!adcToGeVConstantIsSet_) {
      std::cout << "EcalRecHitSimpleAlgo::makeRecHit: adcToGeVConstant_ not set before calling this method!" << 
                   " will use -1 and produce bogus rechits!" << std::endl;
    }

    float clockToNsConstant = 25;
    float energy = uncalibRH.amplitude()*adcToGeVConstant_*intercalibConstant;
    float time   = uncalibRH.jitter() * clockToNsConstant + timeIntercalib;
    uint32_t recoFlag = flags;
    if (uncalibRH.isSaturated()) recoFlag = EcalUncalibratedRecHit::kSaturated;

    EcalRecHit rh( uncalibRH.id(), energy, time );
    rh.setRecoFlag( recoFlag );
    rh.setChi2Prob( TMath::Prob( uncalibRH.chi2(), EcalDataFrame::MAXSAMPLES ) );
    if ( uncalibRH.recoFlag() == EcalUncalibratedRecHit::kOutOfTime ) {
            rh.setOutOfTimeEnergy( rh.outOfTimeEnergy() * adcToGeVConstant_ * intercalibConstant );
            rh.setRecoFlag( EcalRecHit::kOutOfTime );
    }
    return rh;
  }

private:
  float adcToGeVConstant_;
  bool  adcToGeVConstantIsSet_;

};
#endif
