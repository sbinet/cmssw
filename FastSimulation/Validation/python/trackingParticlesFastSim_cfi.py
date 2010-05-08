import FWCore.ParameterSet.Config as cms

mergedtruth = cms.EDProducer("TrackingTruthProducer",

    simHitLabel = cms.string('famosSimHits'),
    volumeRadius = cms.double(1200.0),
    vertexDistanceCut = cms.double(0.003),
    volumeZ = cms.double(3000.0),
    mergedBremsstrahlung = cms.bool(True),
    removeDeadModules = cms.bool(False),

    HepMCDataLabels = cms.vstring('VtxSmeared', 
        'generator', 
        'PythiaSource', 
        'source'
    ),

    useMultipleHepMCLabels = cms.bool(False),

    simHitCollections = cms.PSet(
       tracker = cms.vstring("famosSimHitsTrackerHits"),
#       muon = cms.vstring (
#           'MuonSimHitsMuonDTHits',
#           'MuonSimHitsMuonCSCHits',
#           'MuonSimHitsMuonRPCHits'            
#       )
    )
)

mergedtruthMuon = cms.EDProducer("TrackingTruthProducer",

    simHitLabel = cms.string('famosSimHits'),
    volumeRadius = cms.double(1200.0),
    vertexDistanceCut = cms.double(0.003),
    volumeZ = cms.double(3000.0),
    mergedBremsstrahlung = cms.bool(True),
    removeDeadModules = cms.bool(False),

    HepMCDataLabels = cms.vstring('VtxSmeared', 
        'generator', 
        'PythiaSource', 
        'source'
    ),

    useMultipleHepMCLabels = cms.bool(False),

    simHitCollections = cms.PSet(
       tracker = cms.vstring("famosSimHitsTrackerHits"),
       muon = cms.vstring (
           'MuonSimHitsMuonDTHits',
           'MuonSimHitsMuonCSCHits',
           'MuonSimHitsMuonRPCHits'            
       )
    )
)

trackingParticles = cms.Sequence(mergedtruth+mergedtruthMuon)
