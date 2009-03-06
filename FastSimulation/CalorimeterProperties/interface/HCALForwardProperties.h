#ifndef HCALForwardProperties_H
#define HCALForwardProperties_H

#include "FastSimulation/CalorimeterProperties/interface/HCALProperties.h"

#include <cmath>

namespace edm { 
  class ParameterSet;
}

/** 
 * Functions to return atomic properties of the material
 * A_eff and Z_eff are computed as the A-weighted sums 
 * of the A's and the Z's of Pb, W and O
 *
 * \author Patrick Janot
 * \date: 25-Jan-2004
 */ 

class HCALForwardProperties : public HCALProperties
{

 public:

  HCALForwardProperties(const edm::ParameterSet& fastDet):HCALProperties(fastDet) {; } 

  virtual ~HCALForwardProperties() { }

  /// Radiation length in cm
  inline double radLenIncm()  const { return radiationLengthIncm(); }

  /// Radiation length in cm but static 
  static inline double radiationLengthIncm() { return 1.43; }
 
  /// Radiation length in g/cm^2
  inline double radLenIngcm2() const { return 12.86; }

  ///Interaction length in cm
  inline double interactionLength() const { return 15.05; }

  double getHcalDepth(double);

  double thickness(double eta) const { 
    
    double feta = fabs(eta);
    if(feta > 3.0 && feta < 5.19)
      {return HCALProperties::getHcalDepth(eta) * interactionLength();}
    else {return 0.;}
      
  }

 private:

};

#endif
