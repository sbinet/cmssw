import FWCore.ParameterSet.Config as cms
import FWCore.ParameterSet.VarParsing as VarParsing
import os 

process = cms.Process("RERECO")

process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")
process.load("Configuration.StandardSequences.Services_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load("Configuration.StandardSequences.Geometry_cff")

#global tags for conditions data: https://twiki.cern.ch/twiki/bin/view/CMS/SWGuideFrontierConditions
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.GlobalTag.globaltag = 'MC_3XY_V21::All'

##################################################################################

# setup 'standard'  options
options = VarParsing.VarParsing ('standard')

# setup any defaults you want
options.output = 'test_out.root'
#options.files= '/store/relval/CMSSW_3_5_2/RelValPyquen_DiJet_pt80to120_4TeV/GEN-SIM-RECO/MC_3XY_V21-v1/0001/FA961928-A01F-DF11-85F6-0030487CD7C0.root'
options.files= '/store/relval/CMSSW_3_5_2/RelValPyquen_ZeemumuJets_pt10_4TeV/GEN-SIM-RECO/MC_3XY_V21-v1/0001/F8612C2E-A01F-DF11-A2CC-00304879FA4A.root'
options.maxEvents = 1 

# get and parse the command line arguments
options.parseArguments()


##################################################################################
# Some Services

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.debugModules = ['*']  
process.MessageLogger.categories = ['HeavyIonVertexing','heavyIonHLTVertexing','MuonTrackingRegionBuilder']
process.MessageLogger.cerr = cms.untracked.PSet(
    threshold = cms.untracked.string('DEBUG'),
    DEBUG = cms.untracked.PSet(
        limit = cms.untracked.int32(0)
    ),
    INFO = cms.untracked.PSet(
        limit = cms.untracked.int32(0)
    ),
    HeavyIonVertexing = cms.untracked.PSet(
        limit = cms.untracked.int32(-1)
	),
    heavyIonHLTVertexing = cms.untracked.PSet(
        limit = cms.untracked.int32(-1)
    ),
    MuonTrackingRegionBuilder = cms.untracked.PSet(
        limit = cms.untracked.int32(-1)
    )
)
	   
process.SimpleMemoryCheck = cms.Service('SimpleMemoryCheck',
                                        ignoreTotal=cms.untracked.int32(0),
                                        oncePerEventMode = cms.untracked.bool(False)
                                        )

process.Timing = cms.Service("Timing")

##################################################################################
# Input Source
process.source = cms.Source('PoolSource',fileNames = cms.untracked.vstring(options.files))
process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(options.maxEvents))

#Reconstruction			
process.load("Configuration.StandardSequences.RawToDigi_cff")		    # RawToDigi
process.load("Configuration.StandardSequences.ReconstructionHeavyIons_cff") # full heavy ion reconstruction
process.load("RecoHI.HiTracking.secondStep_cff")                            # pair-seeding extension
process.hiNewClusters.Common.maxChi2 = 0 # for testing: remove none of clusters from previous iteration


### re-run tracking only seeded by stand-alone muons
process.goodStaMuons = cms.EDFilter("TrackSelector",
                                 src = cms.InputTag("standAloneMuons","UpdatedAtVtx"),
                                 cut = cms.string("pt > 5.0"),
                                 filter = cms.bool(True)
                                 )

process.HiTrackingRegionFactoryFromSTAMuonsBlock.MuonSrc="goodStaMuons"
process.hiPixel3PrimTracks.RegionFactoryPSet = process.HiTrackingRegionFactoryFromSTAMuonsBlock
process.hiNewSeedFromPairs.RegionFactoryPSet = process.HiTrackingRegionFactoryFromSTAMuonsBlock

# Output EDM File
process.load("Configuration.EventContent.EventContentHeavyIons_cff")        #load keep/drop output commands
process.output = cms.OutputModule("PoolOutputModule",
                                  #process.FEVTDEBUGEventContent,
                                  compressionLevel = cms.untracked.int32(2),
                                  commitInterval = cms.untracked.uint32(1),
                                  fileName = cms.untracked.string(options.output)
                                  )

##################################################################################
# Paths
process.rechits = cms.Sequence(process.siPixelRecHits*process.siStripMatchedRecHits)
process.vtxreco = cms.Sequence(process.offlineBeamSpot * process.trackerlocalreco * process.hiPixelVertices)
process.pxlreco = cms.Sequence(process.vtxreco * process.hiPixel3PrimTracks)
process.trkreco = cms.Sequence(process.offlineBeamSpot * process.trackerlocalreco * process.heavyIonTracking)

process.reco        = cms.Sequence(process.RawToDigi * process.trkreco)
process.rereco      = cms.Sequence(process.rechits * process.heavyIonTracking)
process.rerecomuons = cms.Sequence(process.goodStaMuons * process.rechits * process.heavyIonTracking)

process.path = cms.Path(process.rerecomuons # triplet-seeded regional step
                        #*process.secondStep # pair-seeded regional step
                        )

process.save = cms.EndPath(process.output)

