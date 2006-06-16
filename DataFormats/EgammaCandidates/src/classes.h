#include "DataFormats/Common/interface/Wrapper.h"
#include "DataFormats/EgammaCandidates/interface/Photon.h"
#include "DataFormats/EgammaCandidates/interface/Electron.h"
#include "DataFormats/EgammaCandidates/interface/ConvertedPhotonCandidate.h"
#include "DataFormats/EgammaCandidates/interface/SiStripElectronCandidate.h"
#include "DataFormats/Common/interface/RefToBase.h"

namespace {
  namespace {
    reco::PhotonCollection v1;
    edm::Wrapper<reco::PhotonCollection> w1;
    edm::Ref<reco::PhotonCollection> r1;
    edm::RefProd<reco::PhotonCollection> rp1;
    edm::RefVector<reco::PhotonCollection> rv1;

    reco::ElectronCollection v2;
    edm::Wrapper<reco::ElectronCollection> w2;
    edm::Ref<reco::ElectronCollection> r2;
    edm::RefProd<reco::ElectronCollection> rp2;
    edm::RefVector<reco::ElectronCollection> rv2;

    reco::SiStripElectronCandidateCollection v5;
    edm::Wrapper<reco::SiStripElectronCandidateCollection> w5;
    edm::Ref<reco::SiStripElectronCandidateCollection> r5;
    edm::RefProd<reco::SiStripElectronCandidateCollection> rp5;
    edm::RefVector<reco::SiStripElectronCandidateCollection> rv5;

    reco::ConvertedPhotonCandidateCollection v6;
    edm::Wrapper<reco::ConvertedPhotonCandidateCollection> w6;
    edm::Ref<reco::ConvertedPhotonCandidateCollection> r6;
    edm::RefProd<reco::ConvertedPhotonCandidateCollection> rp6;
    edm::RefVector<reco::ConvertedPhotonCandidateCollection> rv6;

    edm::reftobase::Holder<reco::Candidate, reco::ElectronRef> rb1;
    edm::reftobase::Holder<reco::Candidate, reco::PhotonRef> rb2;
    edm::reftobase::Holder<reco::Candidate, reco::SiStripElectronCandidateRef> rb3;
    edm::reftobase::Holder<reco::Candidate, reco::ConvertedPhotonCandidateRef> rb4;
  }
}
