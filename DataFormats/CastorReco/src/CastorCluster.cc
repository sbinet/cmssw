#include "DataFormats/CastorReco/interface/CastorCluster.h"

using namespace reco;

CastorCluster::CastorCluster(const double energy, const ROOT::Math::XYZPoint& position, const double emEnergy, const double hadEnergy, 
			     const double fem, const double width, const double depth, const double fhot, const double sigmaz,
			     const CastorTowerRefVector& usedTowers) {
  position_ = position;
  energy_ = energy;
  emEnergy_ = emEnergy;
  hadEnergy_ = hadEnergy;
  fem_ = fem;
  width_ = width;
  depth_ = depth;
  fhot_ = fhot;
  sigmaz_ = sigmaz;
  for(CastorTowerRefVector::const_iterator towerit  = usedTowers.begin(); towerit != usedTowers.end();++towerit) {
    usedTowers_.push_back( (*towerit) );
  }
}

CastorCluster::~CastorCluster() {

}
