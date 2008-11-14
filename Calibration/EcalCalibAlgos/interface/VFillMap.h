#ifndef VFillMap_H
#ifndef __CINT__
#define VFillMap_H

#include <map>
#include <vector>
#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"
#include "DataFormats/DetId/interface/DetId.h"
#include "CondFormats/DataRecord/interface/EcalIntercalibConstantsRcd.h"
#include "CondFormats/EcalObjects/interface/EcalIntercalibConstants.h"

class VFillMap
{
	public:
	//!ctor
	VFillMap (int ,
		  int ,
		  std::map<int,int> ,
		  double,
		  double, 
		  std::map<int,int>,
	          EcalIntercalibConstantMap *,
		  EcalIntercalibConstantMap *); 
	
	//!dtor
	virtual ~VFillMap () {};
	//! The Map filler
        virtual DetId fillMap (const std::vector<DetId> &, 
			const EcalRecHitCollection *, 
			const EcalRecHitCollection *,
			std::map<int,double> & xtlMap,
			double & ) = 0;

	protected:
        DetId findMaxHit (const std::vector<DetId> &,const EcalRecHitCollection *, 
			const EcalRecHitCollection *);
	int m_recoWindowSidex;
	int m_recoWindowSidey;
        std::map<int,int> m_xtalRegionId;
        double m_minEnergyPerCrystal;
        double m_maxEnergyPerCrystal;
        std::map<int,int> m_IndexInRegion;
        EcalIntercalibConstantMap * m_barrelMap;
        EcalIntercalibConstantMap * m_endcapMap;

};
#endif
#endif
