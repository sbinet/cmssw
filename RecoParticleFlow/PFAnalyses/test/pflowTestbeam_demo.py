import FWCore.ParameterSet.Config as cms

process = cms.Process("PROD")
process.load("RecoParticleFlow.PFAnalyses.pflowProcessTestbeam_cff")

runs = cms.untracked.vstring("rfio:///castor/cern.ch/cms/store/h2tb2006/reco/v6/h2.00030379.combined.OutServ_0.0-cmsswreco.root", )

#process.TFileService.fileName = cms.string("demo_outputtree_7GeV_m.root")
#process.finishup.fileName = cms.untracked.string("demo_reprocessed_7GeV_m.root")

# This should be updated as necessary
process.faketracks.runinfo_cuts = cms.string("/afs/cern.ch/user/b/ballin/scratch0/cmssw/src/RecoParticleFlow/PFAnalyses/macros/testbeam_cuts_v1_3X.root")
process.extraction.runinfo_cuts = cms.string("/afs/cern.ch/user/b/ballin/scratch0/cmssw/src/RecoParticleFlow/PFAnalyses/macros/testbeam_cuts_v1_3X.root")

#process.extraction.debug = cms.int32(4)

process.maxEvents = cms.untracked.PSet(
    input=cms.untracked.int32(200)
)
#process.particleFlowCluster.verbose = cms.bool(True)

process.source = cms.Source("PoolSource",
        fileNames = runs,
        inputCommands=cms.untracked.vstring('keep *', 'drop EBDataFramesSorted_*')
)

process.p1 = cms.Path(process.particleFlowClustering)
process.outpath = cms.EndPath(process.finishup)
