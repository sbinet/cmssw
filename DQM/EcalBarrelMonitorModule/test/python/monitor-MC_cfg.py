import FWCore.ParameterSet.Config as cms

process = cms.Process("ECALDQM")

import RecoLocalCalo.EcalRecProducers.ecalFixedAlphaBetaFitUncalibRecHit_cfi

process.ecalUncalibHit = RecoLocalCalo.EcalRecProducers.ecalFixedAlphaBetaFitUncalibRecHit_cfi.ecalFixedAlphaBetaFitUncalibRecHit.clone()
process.load("RecoLocalCalo.EcalRecProducers.ecalRecHit_cfi")

#import RecoLocalCalo.EcalRecProducers.ecalWeightUncalibRecHit_cfi
#process.ecalUncalibHit = RecoLocalCalo.EcalRecProducers.ecalWeightUncalibRecHit_cfi.ecalWeightUncalibRecHit.clone()

process.load("Geometry.CaloEventSetup.CaloGeometry_cfi")

process.load("Geometry.CaloEventSetup.EcalTrigTowerConstituents_cfi")

process.load("Geometry.CMSCommonData.cmsIdealGeometryXML_cfi")

process.load("Geometry.EcalMapping.EcalMapping_cfi")

process.load("Geometry.EcalMapping.EcalMappingRecord_cfi")

process.load("DQM.EcalBarrelMonitorModule.EcalBarrelMonitorModule_cfi")

process.load("DQM.EcalBarrelMonitorTasks.EcalBarrelMonitorTasks_cfi")

process.load("DQM.EcalBarrelMonitorTasks.mergeRuns_cff")

process.load("DQM.EcalBarrelMonitorClient.EcalBarrelMonitorClient_cfi")

process.load("RecoEcal.EgammaClusterProducers.ecalClusteringSequence_cff")

process.load("CalibCalorimetry.EcalLaserCorrection.ecalLaserCorrectionService_cfi")

process.load("DQMServices.Core.DQM_cfg")

process.preScaler = cms.EDFilter("Prescaler",
    prescaleFactor = cms.int32(1)
)

process.dqmInfoEB = cms.EDFilter("DQMEventInfo",
    subSystemFolder = cms.untracked.string('EcalBarrel')
)

process.dqmSaverEB = cms.EDFilter("DQMFileSaver",
    fileName = cms.untracked.string('EcalBarrel'),
    dirName = cms.untracked.string('.'),
    convention = cms.untracked.string('Online')
)

process.maxEvents = cms.untracked.PSet(
#    input = cms.untracked.int32(150)
    input = cms.untracked.int32(300)
)
process.source = cms.Source("PoolSource",
#---
#    fileNames = cms.untracked.vstring('/store/users/dellaric/data/5E883D60-4B98-DC11-BD17-000423D6A6F4.root')
    fileNames = cms.untracked.vstring('/store/unmerged/relval/2008/7/9/RelVal-RelValSingleMuPt10-1215646486/GEN-SIM-DIGI-RAW-HLTDEBUG/IDEAL_V5/0000/FEB7BCD4-124E-DD11-8E40-001D09F2B30B.root')
#---
)

process.EcalTrivialConditionRetriever = cms.ESSource("EcalTrivialConditionRetriever",
    adcToGeVEBConstant = cms.untracked.double(0.035),
    adcToGeVEEConstant = cms.untracked.double(0.06),
    pedWeights = cms.untracked.vdouble(0.333, 0.333, 0.333, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0),
    amplWeights = cms.untracked.vdouble(-0.333, -0.333, -0.333, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0),
    jittWeights = cms.untracked.vdouble(0.041, 0.041, 0.041, 0.0, 1.325, -0.05, -0.504, -0.502, -0.390, 0.0)
)

process.MessageLogger = cms.Service("MessageLogger",
    cout = cms.untracked.PSet(
        threshold = cms.untracked.string('WARNING'),
        default = cms.untracked.PSet(
            limit = cms.untracked.int32(0)
        ),
        noTimeStamps = cms.untracked.bool(True),
        EcalBarrelMonitorModule = cms.untracked.PSet(
            limit = cms.untracked.int32(0)
        ),
        noLineBreaks = cms.untracked.bool(True)
    ),
    categories = cms.untracked.vstring('EcalBarrelMonitorModule'),
    destinations = cms.untracked.vstring('cout')
)

process.ecalDataSequence = cms.Sequence(process.preScaler*process.ecalUncalibHit*process.ecalRecHit*process.islandBasicClusters*process.islandSuperClusters*process.hybridSuperClusters)
process.ecalBarrelMonitorSequence = cms.Sequence(process.ecalBarrelMonitorModule*process.dqmInfoEB*process.ecalBarrelMonitorClient*process.dqmSaverEB)

process.p = cms.Path(process.ecalDataSequence*process.ecalBarrelMonitorSequence)
process.q = cms.EndPath(process.ecalBarrelDefaultTasksSequence*process.ecalBarrelClusterTask)

process.ecalUncalibHit.MinAmplBarrel = 12.
process.ecalUncalibHit.MinAmplEndcap = 16.
process.ecalUncalibHit.EBdigiCollection = cms.InputTag("simEcalDigis","ebDigis")
process.ecalUncalibHit.EEdigiCollection = cms.InputTag("simEcalDigis","eeDigis")

process.ecalRecHit.EBuncalibRecHitCollection = cms.InputTag("ecalUncalibHit","EcalUncalibRecHitsEB")
process.ecalRecHit.EEuncalibRecHitCollection = cms.InputTag("ecalUncalibHit","EcalUncalibRecHitsEE")

process.ecalBarrelMonitorModule.mergeRuns = True
process.ecalBarrelMonitorModule.EBDigiCollection = cms.InputTag("simEcalDigis","ebDigis")
process.ecalBarrelMonitorModule.runType = 3 # MTCC/PHYSICS
process.ecalBarrelMonitorModule.EcalTrigPrimDigiCollection = 'ecalTriggerPrimitiveDigis'

process.ecalBarrelOccupancyTask.EBDigiCollection = cms.InputTag("simEcalDigis","ebDigis")
process.ecalBarrelOccupancyTask.EcalTrigPrimDigiCollection = 'ecalTriggerPrimitiveDigis'

process.ecalBarrelPedestalOnlineTask.EBDigiCollection = cms.InputTag("simEcalDigis","ebDigis")

process.ecalBarrelMonitorClient.maskFile = 'maskfile-EB.dat'
process.ecalBarrelMonitorClient.mergeRuns = True
process.ecalBarrelMonitorClient.location = 'H4'
process.ecalBarrelMonitorClient.baseHtmlDir = '.'
process.ecalBarrelMonitorClient.enabledClients = ['Integrity', 'Occupancy', 'PedestalOnline', 'Timing', 'Cluster', 'Summary']

process.DQM.collectorHost = ''

