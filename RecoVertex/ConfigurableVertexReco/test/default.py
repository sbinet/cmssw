#!/usr/bin/env cmsRun

import FWCore.ParameterSet.Config as cms

process = cms.Process("cvrtest")

process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load("Configuration.StandardSequences.GeometryIdeal_cff")
# process.load("Geometry.CMSCommonData.cmsAllGeometryXML_cfi")
# process.load("Geometry.CommonDetUnit.globalTrackingGeometry_cfi")
# process.load("Geometry.CommonDetUnit.bareGlobalTrackingGeometry_cfi")
# process.load("Configuration.StandardSequences.AlCaRecoStreams_cff")
# process.load("Configuration.StandardSequences.OfflineDQM_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.GlobalTag.globaltag = cms.string('GR09_P_V6::All')
process.load("TrackingTools.TransientTrack.TransientTrackBuilder_cfi")
process.load("RecoVertex.PrimaryVertexProducer.OfflinePrimaryVertices_cfi")
process.load("RecoVertex.BeamSpotProducer.BeamSpot_cff")
# GlobalTrackingGeometryRecord

process.load("PhysicsTools.UtilAlgos.TFileService_cfi")
TFileService.fileName = cms.string('vertices.root')

process.source = cms.Source("PoolSource",
#    fileNames = 
#cms.untracked.vstring('/store/relval/CMSSW_2_1_10/RelValBJets_Pt_50_120/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/STARTUP_V7_v2/0000/246E6DD9-B299-DD11-987C-000423D6B2D8.root')

	fileNames = cms.untracked.vstring('file:/afs/cern.ch/cms/CAF/CMSCOMM/COMM_GLOBAL/bit40or41skim.root')
)

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(11))


process.cVRTest = cms.EDFilter("CVRTest",
    trackcoll = cms.string('generalTracks'),
    vertexreco = cms.PSet(
        seccut = cms.double(6.0),
        primcut = cms.double(2.0),
        smoothing = cms.bool(False),
        finder = cms.string('avr'),
        minweight = cms.double(0.5),
        weightthreshold = cms.double(0.001)
    ),
    vertexcoll = cms.string('offlinePrimaryVertices'),
    beamspot = cms.string('offlineBeamSpot')
)

process.p = cms.Path( process.offlinePrimaryVertices + process.cVRTest )
process.MessageLogger.debugModules = ['cVRTest']

