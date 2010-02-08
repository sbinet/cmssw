#include "RecoLocalCalo/EcalRecAlgos/interface/EcalSeverityLevelAlgo.h"

#include "FWCore/MessageLogger/interface/MessageLogger.h"

int EcalSeverityLevelAlgo::severityLevel( const DetId id, 
                const EcalRecHitCollection &recHits, 
                const EcalChannelStatus &chStatus )
{
        // get DB flag
        uint16_t dbStatus = retrieveDBStatus( id, chStatus );
        // get recHit flags
        EcalRecHitCollection::const_iterator it = recHits.find( id );
        if ( it == recHits.end() ) {
                // the channel is not in the recHit collection:
                // dead or zero-suppressed?
                if ( dbStatus >= 10 ) { // originally dead
                        return kBad;
                } else if ( dbStatus > 0 && dbStatus < 10 ) {
                        // zero-suppressed and originally problematic
                        return kProblematic;
                } else if ( dbStatus == 0 ) {
                        // zero-suppressed and originally good
                        return kGood;
                }
        } else {
                // the channel is in the recHit collection
                if ( spikeFromNeighbours(id, recHits) > 0.95  ) return kWeird;
                return severityLevel( *it, chStatus );
        }
        return 0;
}

int EcalSeverityLevelAlgo::severityLevel( const EcalRecHit &recHit, 
                const EcalChannelStatus &chStatus )
{
        // the channel is there, check its flags
        // and combine with DB (not needed at the moment)
        uint32_t rhFlag = recHit.recoFlag();
        uint16_t dbStatus = retrieveDBStatus( recHit.id(), chStatus );
        return severityLevel( rhFlag, dbStatus );
}

int EcalSeverityLevelAlgo::severityLevel( uint32_t rhFlag, uint16_t chStatus )
{
        // DB info currently not used at this level
        if       (  rhFlag == EcalRecHit::kPoorReco 
                 || rhFlag == EcalRecHit::kOutOfTime
                 || rhFlag == EcalRecHit::kNoisy
                 || rhFlag == EcalRecHit::kPoorCalib 
                 || rhFlag == EcalRecHit::kFaultyHardware
                 ) {
                // problematic
                return kProblematic;
        } else if ( rhFlag == EcalRecHit::kLeadingEdgeRecovered
                 || rhFlag == EcalRecHit::kNeighboursRecovered
                 || rhFlag == EcalRecHit::kTowerRecovered
                 ) {
                // recovered
                return kRecovered;
        } else if ( rhFlag == EcalRecHit::kDead
                 || rhFlag == EcalRecHit::kSaturated
                 || rhFlag == EcalRecHit::kFake
                 || rhFlag == EcalRecHit::kFakeNeighbours
                 || rhFlag == EcalRecHit::kKilled ) {
                // recovery failed (or not tried) or signal is fake or channel
                // is dead
                return kBad;
        }
        // good
        return kGood;
}

uint16_t EcalSeverityLevelAlgo::retrieveDBStatus( const DetId id, const EcalChannelStatus &chStatus )
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

float EcalSeverityLevelAlgo::spikeFromNeighbours( const DetId id, const EcalRecHitCollection & recHits )
{
        // compute R9
        if ( id.subdetId() == EcalBarrel ) {
                EBDetId ebId( id );
                float s9 = 0;
                int ieta0 = iEta2cIndex( ebId.ieta() );
                int iphi0 = iPhi2cIndex( ebId.iphi() );
                for ( int deta = -1; deta <= +1; ++deta ) {
                        for ( int dphi = -1; dphi <= +1; ++dphi ) {
                                int eta = ieta0 + deta;
                                int phi = ( iphi0 + dphi ) % 360;
                                if ( phi < 0  ) phi += 360;
                                if ( ! EBDetId::validDetId( cIndex2iEta(eta), cIndex2iPhi(phi) ) ) continue;
                                EBDetId hitId( cIndex2iEta(eta), cIndex2iPhi(phi) );
                                s9 += recHitEnergy( hitId, recHits );
                        }
                }
                return recHitEnergy(id, recHits) / s9;
        }
        return 0;
}

float EcalSeverityLevelAlgo::recHitEnergy( const DetId id, const EcalRecHitCollection &recHits )
{
        if ( id == DetId(0) ) {
                return 0;
        } else {
                EcalRecHitCollection::const_iterator it = recHits.find( id );
                if ( it != recHits.end() ) return (*it).energy();
        }
        return 0;
}
