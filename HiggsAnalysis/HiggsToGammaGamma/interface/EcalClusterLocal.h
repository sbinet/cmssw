#ifndef RecoEcal_EgammaCoreTools_EcalClusterLocal_h
#define RecoEcal_EgammaCoreTools_EcalClusterLocal_h

/** \class EcalClusterLocal
  *  Function to compute local coordinates of Ecal clusters
  *  (adapted from RecoEcal/EgammaCoreTools/plugins/EcalClusterLocal)
  *  $Id: EcalClusterLocal.h
  *  $Date:
  *  $Revision:
  *  \author Josh Bendavid, MIT, 2011
  */


//#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "DataFormats/EgammaReco/interface/BasicClusterFwd.h"


class EcalClusterLocal {
        public:
          EcalClusterLocal();
          ~EcalClusterLocal();
          
          void localCoordsEB( const reco::BasicCluster &bclus, const edm::EventSetup &es, float &etacry, float &phicry, int &ieta, int &iphi) const;
          void localCoordsEE( const reco::BasicCluster &bclus, const edm::EventSetup &es, float &xcry, float &ycry, int &ix, int &iy) const;



		 
};

#endif
