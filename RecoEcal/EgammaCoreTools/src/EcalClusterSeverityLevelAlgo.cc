#include "RecoEcal/EgammaCoreTools/interface/EcalClusterSeverityLevelAlgo.h"
#include "RecoEcal/EgammaCoreTools/interface/EcalClusterTools.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "DataFormats/EcalDetId/interface/EcalSubdetector.h"
#include "DataFormats/EcalDetId/interface/EBDetId.h"
#include "Geometry/CaloTopology/interface/CaloTopology.h"

float EcalClusterSeverityLevelAlgo::goodFraction( const reco::CaloCluster & cluster, 
                                                   const EcalRecHitCollection & recHits, const EcalChannelStatus & chStatus) 
{
        float fraction = 0.;
        std::vector< std::pair<DetId, float> > hitsAndFracs = cluster.hitsAndFractions();
        std::vector< std::pair<DetId, float> >::const_iterator it;
        for ( it = hitsAndFracs.begin(); it != hitsAndFracs.end(); ++it ) {
                DetId id = (*it).first;
                EcalRecHitCollection::const_iterator jrh = recHits.find( id );
                if ( jrh == recHits.end() ) {
                        edm::LogError("EcalClusterSeverityLevelAlgo") << "The cluster DetId " << id.rawId() << " is not in the recHit collection!!";
                        return -1;
                }
                uint32_t flag = (*jrh).recoFlag();
                uint32_t sev = EcalSeverityLevelAlgo::severityLevel( flag, retrieveDBStatus(id,chStatus) );
		//                if ( sev == EcalSeverityLevelAlgo::kBad ) ++recoveryFailed;
                if ( sev == EcalSeverityLevelAlgo::kProblematic 
                     || sev == EcalSeverityLevelAlgo::kRecovered || sev == EcalSeverityLevelAlgo::kBad ) 
		  {
// 		    std::cout << "[goodFraction] Found a problematic channel " << EBDetId(id) << " " << flag << " energy: " <<  (*jrh).energy() << std::endl;
		    fraction += (*jrh).energy() * (*it).second / cluster.energy();
		  }
        }
        return 1. - fraction;
}

float EcalClusterSeverityLevelAlgo::fractionAroundClosestProblematic( const reco::CaloCluster & cluster, 
                                                   const EcalRecHitCollection & recHits, const EcalChannelStatus & chStatus, const CaloTopology* topology )
{
  DetId closestProb = closestProblematic(cluster , recHits, chStatus, topology);
  //  std::cout << "%%%%%%%%%%% Closest prob is " << EBDetId(closestProb) << std::endl;
  if (closestProb.null())
    return 0.;
  
  std::vector<DetId> neighbours = topology->getWindow(closestProb,3,3);
  std::vector<DetId>::const_iterator itn;

  std::vector< std::pair<DetId, float> > hitsAndFracs = cluster.hitsAndFractions();
  std::vector< std::pair<DetId, float> >::const_iterator it;

  float fraction = 0.;  

  for ( itn = neighbours.begin(); itn != neighbours.end(); ++itn )
    {
      //      std::cout << "Checking detId " << EBDetId((*itn)) << std::endl;
      for ( it = hitsAndFracs.begin(); it != hitsAndFracs.end(); ++it ) 
	{
	  DetId id = (*it).first;
	  if ( id != (*itn) )
	    continue;
	  //	  std::cout << "Is in cluster detId " << EBDetId(id) << std::endl;
	  EcalRecHitCollection::const_iterator jrh = recHits.find( id );
	  if ( jrh == recHits.end() ) 
	    {
	      edm::LogError("EcalClusterSeverityLevelAlgo") << "The cluster DetId " << id.rawId() << " is not in the recHit collection!!";
	      return -1;
	    }

	  // 	  uint32_t flag = (*jrh).recoFlag();
	  // 	  uint32_t sev = EcalSeverityLevelAlgo::severityLevel( flag, retrieveDBStatus(id,chStatus) );

	  //	  std::cout << "Energy is " << (*jrh).energy() * (*it).second << std::endl;
	  fraction += (*jrh).energy() * (*it).second  / cluster.energy();
	}
    }
  //  std::cout << "%%%%%%%%%%% Fraction is " << fraction << std::endl;
  return fraction;
}

DetId EcalClusterSeverityLevelAlgo::closestProblematic(const reco::CaloCluster & cluster, 
						     const EcalRecHitCollection & recHits, const EcalChannelStatus & chStatus , 
						      const CaloTopology* topology )
{
  DetId seed=EcalClusterTools::getMaximum(cluster,&recHits).first;
  if ( (seed.det() != DetId::Ecal) || 
       (EcalSubdetector(seed.subdetId()) != EcalBarrel) )
    {
      //method not supported if not in Barrel
      edm::LogError("EcalClusterSeverityLevelAlgo") << "The cluster seed is not in the BARREL";
      return DetId(0);
    }

  int minDist=9999; DetId closestProb(0);   
  //Get a window of DetId around the seed crystal
  std::vector<DetId> neighbours = topology->getWindow(seed,51,11);

  for ( std::vector<DetId>::const_iterator it = neighbours.begin(); it != neighbours.end(); ++it ) 
    {
      EcalRecHitCollection::const_iterator jrh = recHits.find(*it);
      if ( jrh == recHits.end() ) 
	continue;
      //Now checking rh flag
      uint32_t flag = (*jrh).recoFlag();
      uint32_t sev = EcalSeverityLevelAlgo::severityLevel( flag, retrieveDBStatus(*it,chStatus) );
      if (sev == EcalSeverityLevelAlgo::kGood)
	continue;
      //      std::cout << "[closestProblematic] Found a problematic channel " << EBDetId(*it) << " " << flag << std::endl;
      //Find the closest DetId in eta,phi space (distance defined by deta^2 + dphi^2)
      int deta=distanceEta(EBDetId(seed),EBDetId(*it));
      int dphi=distancePhi(EBDetId(seed),EBDetId(*it));
      if (sqrt(deta*deta + dphi*dphi) < minDist)
	closestProb = *it;
    }
      
  return closestProb;
}

std::pair<int,int> EcalClusterSeverityLevelAlgo::etaphiDistanceClosestProblematic( const reco::CaloCluster & cluster, 
						     const EcalRecHitCollection & recHits, const EcalChannelStatus & chStatus , 
						      const CaloTopology* topology )
{
  DetId seed=EcalClusterTools::getMaximum(cluster,&recHits).first;
  if ( (seed.det() != DetId::Ecal) || 
       (EcalSubdetector(seed.subdetId()) != EcalBarrel) )
    {
      edm::LogError("EcalClusterSeverityLevelAlgo") << "The cluster seed is not in the BARREL";
      //method not supported if not in Barrel
      return std::pair<int,int>(-1,-1);
    }

  DetId closestProb = closestProblematic(cluster , recHits, chStatus, topology);

  if (! closestProb.null())
    return std::pair<int,int>(distanceEta(EBDetId(seed),EBDetId(closestProb)),distancePhi(EBDetId(seed),EBDetId(closestProb)));
  else
    return std::pair<int,int>(-1,-1);
} 


int EcalClusterSeverityLevelAlgo::distanceEta(const EBDetId& a,const EBDetId& b)
{
  if (a.ieta() * b.ieta() > 0)
    return abs(a.ieta()-b.ieta());
  else
    return abs(a.ieta()-b.ieta())-1;
}

int EcalClusterSeverityLevelAlgo::distancePhi(const EBDetId& a,const EBDetId& b)
{
  if (abs(a.iphi() -b.iphi()) > 180)
    return abs(a.iphi() - b.iphi()) - 180;
  else
    return abs(a.iphi()-b.iphi());
}

int EcalClusterSeverityLevelAlgo::distanceX(const EEDetId& a,const EEDetId& b)
{
    return abs(a.ix()-b.ix());
}

int EcalClusterSeverityLevelAlgo::distanceY(const EEDetId& a,const EEDetId& b)
{
  return abs(a.iy() - b.iy()); 
}

uint16_t EcalClusterSeverityLevelAlgo::retrieveDBStatus( const DetId id, const EcalChannelStatus &chStatus ) 
{
        EcalChannelStatus::const_iterator chIt = chStatus.find( id );
        uint16_t dbStatus = 0;
        if ( chIt != chStatus.end() ) {
                dbStatus = chIt->getStatusCode();
        } else {
                edm::LogError("EcalSeveritylevelError") << "No channel status found for xtal " 
                        << id.rawId() 
                        << "! something wrong with EcalChannelStatus in your DB? ";
        }
        return dbStatus;
}
