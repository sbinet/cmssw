import FWCore.ParameterSet.Config as cms

wmunuAnalyzer = cms.EDFilter("WMuNuAnalyzer",
    # Defaults follow...
    #
    # Input collections ->
    MuonTag = cms.InputTag("muons"),
    METTag = cms.InputTag("met"),
    JetTag = cms.InputTag("iterativeCone5CaloJets"),
    UseOnlyGlobalMuons = cms.bool(True),
    #
    # Main cuts ->
    PtCut = cms.double(25.0),
    EtaCut = cms.double(2.0),
    IsRelativeIso = cms.bool(True),
    IsoCut03 = cms.double(0.09),
    MassTMin = cms.double(50.0),
    MassTMax = cms.double(200.0),
    #
    # To suppress Zmm ->
    PtThrForZCount = cms.double(20.0),
    #
    # To suppress ttbar ->
    AcopCut = cms.double(999999.),
    EJetMin = cms.double(999999.),
    NJetMax = cms.int32(999999)
)
