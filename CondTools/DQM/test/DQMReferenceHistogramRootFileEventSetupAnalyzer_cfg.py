import FWCore.ParameterSet.Config as cms

process = cms.Process('ROOTFILERETRIEVER')

# setting the Global Tag
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.GlobalTag.globaltag = 'GR09_P_V2::All' 

# import of standard configurations
process.load("DQMServices.Core.DQMStore_cfg")
process.DQMStore.verbose   = cms.untracked.int32(1)
process.DQMStore.verboseQT = cms.untracked.int32(0)

process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(-1))

# Input source
process.source = cms.Source("EmptyIOVSource",
                            timetype = cms.string('runnumber'),
                            firstValue = cms.uint64(1),
                            lastValue = cms.uint64(1),
                            interval = cms.uint64(1)
                            )

process.load('CondTools/DQM/DQMReferenceHistogramRootFileEventSetupAnalyzer_cfi')

process.path = cms.Path(process.dqmRefHistoRootFileGetter)
