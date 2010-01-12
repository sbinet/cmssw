import FWCore.ParameterSet.Config as cms

electronTrackIsolationLcone = cms.EDProducer("EgammaElectronTkIsolationProducer",
    absolut = cms.bool(True),
    trackProducer = cms.InputTag("generalTracks"),
    intRadiusBarrel = cms.double(0.015),
    intRadiusEndcap = cms.double(0.015),
    stripBarrel = cms.double(0.015),
    stripEndcap = cms.double(0.015),
    electronProducer = cms.InputTag("gsfElectrons"),
    extRadius = cms.double(0.4),
    ptMin = cms.double(0.7),
    maxVtxDist = cms.double(0.2),
    BeamspotProducer = cms.InputTag("offlineBeamSpot"),
    maxVtxDistXY     = cms.double(9999.0)
)


