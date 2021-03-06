#ifndef RecoBTag_LikelihoodRatio_h
#define RecoBTag_LikelihoodRatio_h

#include "RecoBTag/CombinedSV/interface/AbstractDiscriminatorComputer.h"
#include "RecoBTag/CombinedSV/interface/CombinedSVCalibrationCategory.h"
#include "RecoBTag/CombinedSV/interface/BTagAlgorithmCalibration.h"

class LikelihoodRatio : public AbstractDiscriminatorComputer {
  /** compute discriminator value from a given set 
   *  of tagging variables */
public:
  /**
   * \paramname tp  The likelihood ratio is specific to a certain vertex category
   * \paramname calib FIXME pointer semantics because of ownership problem 
   * with AlgorithmCalibration. We do not wish to copy an AlgorithmCalibration object.
   */
  LikelihoodRatio ( const BTagAlgorithmCalibration * calib,
       reco::btag::Vertices::VertexType tp, double priorCharmInBG=0.25 );
  ~LikelihoodRatio();

  double compute ( const reco::TaggingVariableList & ) const;

  void setCharmPrior( double charmPrior );

  const BTagAlgorithmCalibration & calibration() const;

private:
  long double getPDFValue( double value, const combsv::CombinedSVCalibInput & ) const;

private:
  const BTagAlgorithmCalibration * bTagCalibration_;
  double priorCharmInBG_;
  double priorUDSG_;
  reco::btag::Vertices::VertexType vtxtype_;
};

#endif
