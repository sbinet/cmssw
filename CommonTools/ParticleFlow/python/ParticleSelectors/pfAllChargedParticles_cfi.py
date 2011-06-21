import FWCore.ParameterSet.Config as cms

pfAllChargedParticles = cms.EDFilter("PdgIdPFCandidateSelector",
    src = cms.InputTag("pfNoPileUp"),
    pdgId = cms.vint32(211,-211,321,-321,999211,2212,-2212,11,-11,13,-13)
)



