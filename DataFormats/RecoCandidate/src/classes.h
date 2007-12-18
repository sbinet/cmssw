#include "Rtypes.h" 
#include "Math/Cartesian3D.h" 
#include "Math/Polar3D.h" 
#include "Math/CylindricalEta3D.h" 
#include "Math/PxPyPzE4D.h" 
#include <boost/cstdint.hpp> 
#include "DataFormats/RecoCandidate/interface/RecoCandidate.h"
#include "DataFormats/RecoCandidate/interface/RecoChargedCandidate.h"
#include "DataFormats/RecoCandidate/interface/RecoChargedCandidateFwd.h" 
#include "DataFormats/RecoCandidate/interface/RecoStandAloneMuonCandidate.h"
#include "DataFormats/RecoCandidate/interface/RecoStandAloneMuonCandidateFwd.h"
#include "DataFormats/RecoCandidate/interface/RecoEcalCandidate.h"
#include "DataFormats/RecoCandidate/interface/RecoEcalCandidateFwd.h" 
#include "DataFormats/RecoCandidate/interface/RecoCaloTowerCandidate.h"
#include "DataFormats/RecoCandidate/interface/RecoEcalCandidateIsolation.h"
#include "DataFormats/RecoCandidate/interface/FitResult.h"
#include "DataFormats/RecoCandidate/interface/CaloRecHitCandidate.h"
#include "DataFormats/RecoCandidate/interface/TrackAssociation.h"
#include "DataFormats/HcalRecHit/interface/HcalRecHitCollections.h"
#include "DataFormats/RecoCandidate/interface/TrackCandidateAssociation.h"
#include "DataFormats/HcalDetId/interface/HcalSubdetector.h" 
#include "DataFormats/HcalRecHit/interface/HcalRecHitFwd.h" 
#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"
#include "DataFormats/Common/interface/RefProd.h" 
#include "DataFormats/Common/interface/Wrapper.h"
#include "DataFormats/Common/interface/RefToBase.h"
#include "DataFormats/Common/interface/Ref.h"
#include "DataFormats/Common/interface/RefVector.h"
#include "DataFormats/Common/interface/AssociationMap.h"
#include "DataFormats/Common/interface/OneToValue.h"
#include "DataFormats/Common/interface/OneToManyWithQuality.h"
#include "DataFormats/Common/interface/OneToManyWithQualityGeneric.h"

namespace {
  namespace {
    reco::RecoChargedCandidateCollection v1;
    edm::Wrapper<reco::RecoChargedCandidateCollection> w1;
    edm::Ref<reco::RecoChargedCandidateCollection> r1;
    edm::RefProd<reco::RecoChargedCandidateCollection> rp1;
    edm::RefVector<reco::RecoChargedCandidateCollection> rv1;

    reco::RecoEcalCandidateCollection v2;
    edm::Wrapper<reco::RecoEcalCandidateCollection> w2;
    edm::Ref<reco::RecoEcalCandidateCollection> r2;
    edm::RefProd<reco::RecoEcalCandidateCollection> rp2;
    edm::RefVector<reco::RecoEcalCandidateCollection> rv2;

    reco::RecoEcalCandidateIsolationMap v3;
    edm::Wrapper<reco::RecoEcalCandidateIsolationMap> w3;
    edm::helpers::Key<edm::RefProd<reco::RecoEcalCandidateCollection > > h3;

    reco::RecoStandAloneMuonCandidateCollection v4;
    edm::Wrapper<reco::RecoStandAloneMuonCandidateCollection> w4;
    edm::Ref<reco::RecoStandAloneMuonCandidateCollection> r4;
    edm::RefProd<reco::RecoStandAloneMuonCandidateCollection> rp4;
    edm::RefVector<reco::RecoStandAloneMuonCandidateCollection> rv4;


    edm::reftobase::Holder<reco::Candidate, reco::RecoEcalCandidateRef> rb1;
    edm::reftobase::Holder<reco::Candidate, reco::RecoChargedCandidateRef> rb2;
    edm::reftobase::Holder<CaloRecHit, HBHERecHitRef> rb4;
    edm::reftobase::Holder<CaloRecHit, HORecHitRef > rb5;
    edm::reftobase::Holder<CaloRecHit, HFRecHitRef> rb6;
    edm::reftobase::Holder<CaloRecHit, ZDCRecHitRef> rb7;
    edm::reftobase::Holder<CaloRecHit, EcalRecHitRef> rb8;
    edm::RefToBase<CaloRecHit> rbh3;

    edm::Wrapper<reco::FitResultCollection> wfr1;
    edm::Wrapper<reco::TrackCandidateAssociation> tca1;

    reco::SimToRecoCollection ii3;
    reco::SimToRecoCollection::const_iterator itii3;
    edm::Wrapper<reco::SimToRecoCollection > ii2;
    edm::helpers::KeyVal<TrackingParticleRefProd, edm::View<reco::Track> > ij2;

    reco::RecoToSimCollection jj3;
    reco::RecoToSimCollection::const_iterator  itjj3;
    edm::Wrapper<reco::RecoToSimCollection > jj2;
    edm::helpers::KeyVal<edm::View<reco::Track>, TrackingParticleRefProd> ij3;
          
    edm::reftobase::Holder<reco::Candidate, reco::RecoChargedCandidateRef> rbc1;
    edm::reftobase::RefHolder<reco::RecoChargedCandidateRef> rbc2;
    edm::reftobase::VectorHolder<reco::Candidate, reco::RecoChargedCandidateRefVector> rbc3;
    edm::reftobase::RefVectorHolder<reco::RecoChargedCandidateRefVector> rbc4;
          
    edm::reftobase::Holder<reco::Candidate, reco::RecoStandAloneMuonCandidateRef> rbsa1;
    edm::reftobase::RefHolder<reco::RecoStandAloneMuonCandidateRef> rbsa2;
    edm::reftobase::VectorHolder<reco::Candidate, reco::RecoStandAloneMuonCandidateRefVector> rbsa3;
    edm::reftobase::RefVectorHolder<reco::RecoStandAloneMuonCandidateRefVector> rbsa4;
          
    edm::reftobase::Holder<reco::Candidate, reco::RecoEcalCandidateRef> rbe1;
    edm::reftobase::RefHolder<reco::RecoEcalCandidateRef> rbe2;
    edm::reftobase::VectorHolder<reco::Candidate, reco::RecoEcalCandidateRefVector> rbe3;
    edm::reftobase::RefVectorHolder<reco::RecoEcalCandidateRefVector> rbe4;
  }
}
