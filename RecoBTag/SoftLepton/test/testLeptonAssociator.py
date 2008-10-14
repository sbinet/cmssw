#! /usr/bin/env cmsRun

import FWCore.ParameterSet.Config as cms

process = cms.Process("TestEfficiency")
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load("SimTracker.TrackAssociation.TrackAssociatorByChi2_cfi")
process.load("SimTracker.TrackAssociation.TrackAssociatorByHits_cfi")
process.TrackAssociatorByHitsESProducer.MinHitFraction = 0.3

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring('/store/relval/CMSSW_2_1_9/RelValBJets_Pt_50_120/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/STARTUP_V7_v2/0000/206C1E7D-0E86-DD11-9C2B-000423D98DB4.root')
)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(10)
)

process.testAnalyzer = cms.EDFilter("testLeptonAssociator",
    leptonFlavour        = cms.uint32(13),
    minPt                = cms.double(1.2),
    muons                = cms.InputTag("muons"),
    globalMuonTracks     = cms.InputTag("globalMuons"),
    standAloneMuonTracks = cms.InputTag("standAloneMuons"),
    tracks               = cms.InputTag("ctfWithMaterialTracks"),
    trackingTruth        = cms.InputTag("trackingParticles")
)

process.path = cms.Path(process.testAnalyzer)
