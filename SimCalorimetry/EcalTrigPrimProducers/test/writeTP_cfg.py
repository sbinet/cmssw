import FWCore.ParameterSet.Config as cms

process = cms.Process("PROTPGD")
# ecal mapping
process.load("Geometry.EcalMapping.EcalMapping_cfi")

process.load("Geometry.EcalMapping.EcalMappingRecord_cfi")

# magnetic field
process.load("Configuration.StandardSequences.MagneticField_cff")

# Calo geometry service model
process.load("Geometry.CaloEventSetup.CaloGeometry_cfi")

# Calo geometry service model
process.load("Geometry.CaloEventSetup.EcalTrigTowerConstituents_cfi")

# IdealGeometryRecord
process.load("Geometry.CMSCommonData.cmsIdealGeometryXML_cfi")

process.load("CalibCalorimetry.Configuration.Ecal_FakeConditions_cff")

#include  "SimCalorimetry/EcalTrigPrimProducers/data/ecalTriggerPrimitiveDigis_with_suppressed.cff"
process.load("SimCalorimetry.EcalTrigPrimProducers.ecalTriggerPrimitiveDigis_cff")

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring('file:/data/uberthon/tpg/elec_unsupp_pt10-100.root')
)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(10)
)
process.out = cms.OutputModule("PoolOutputModule",
    outputCommands = cms.untracked.vstring('drop *_*_*_*', 
        'keep *_simEcalTriggerPrimitiveDigis_*_*', 
        'keep *_ecalDigis_*_*', 
        'keep *_ecalRecHit_*_*', 
        'keep *_ecalWeightUncalibRecHit_*_*', 
        'keep PCaloHits_*_EcalHitsEB_*', 
        'keep PCaloHits_*_EcalHitsEE_*', 
        'keep edmHepMCProduct_*_*_*'),
    fileName = cms.untracked.string('TrigPrim.root')
)

process.Timing = cms.Service("Timing")

process.SimpleMemoryCheck = cms.Service("SimpleMemoryCheck")

process.MessageLogger = cms.Service("MessageLogger",
    debugModules = cms.untracked.vstring('simEcalTriggerPrimitiveDigis'),
    cout = cms.untracked.PSet(
        threshold = cms.untracked.string('DEBUG'),
        DEBUG = cms.untracked.PSet(
            limit = cms.untracked.int32(0)
        ),
        EcalTPG = cms.untracked.PSet(
            limit = cms.untracked.int32(1000000)
        )
    ),
    categories = cms.untracked.vstring('EcalTPG'),
    destinations = cms.untracked.vstring('cout')
)

process.p = cms.Path(process.simEcalTriggerPrimitiveDigis)
process.outpath = cms.EndPath(process.out)


