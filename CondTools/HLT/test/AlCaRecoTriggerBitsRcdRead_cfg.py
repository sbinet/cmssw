import FWCore.ParameterSet.Config as cms

process = cms.Process("READ")

process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr = cms.untracked.PSet(placeholder = cms.untracked.bool(True))
process.MessageLogger.cout = cms.untracked.PSet(INFO = cms.untracked.PSet(
    reportEvery = cms.untracked.int32(1)
    ))

# the module writing to DB
process.load("CondTools.HLT.AlCaRecoTriggerBitsRcdRead_cfi")
# 'twiki' is default - others are text, python (future: html?)
#process.AlCaRecoTriggerBitsRcdRead.outputType = 'twiki'
# If rawFileName empty, use message logger, otherwise add suffix according to outputType:
process.AlCaRecoTriggerBitsRcdRead.rawFileName = 'triggerBits'

# No data, but might want to specify 'firstRun' to check (default is 1):
process.source = cms.Source("EmptySource",
                            numberEventsInRun = cms.untracked.uint32(1), # do not change!
                            firstRun = cms.untracked.uint32(1)
                            )
# With 'numberEventsInRun = 1' above,
# this will check IOVs until run (!) number specified as 'input' here,
# so take care not to choose a one that is not too small...:
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(250000) )

# Input for AlCaRecoTriggerBitsRcd,
# either via GloblalTag (use of _cfi instead of _cff sufficient and faster):
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cfi")
process.GlobalTag.globaltag = "DESIGN_3X_V13::All" # choose your tag

# ...or specify database and tag:  
#import CondCore.DBCommon.CondDBSetup_cfi
#process.dbInput = cms.ESSource(
#    "PoolDBESSource",
#    CondCore.DBCommon.CondDBSetup_cfi.CondDBSetup,
##    connect = cms.string('sqlite_file:AlCaRecoTriggerBits.db'),
#    connect = cms.string('frontier://FrontierProd/CMS_COND_31X_HLT'),
#    toGet = cms.VPSet(cms.PSet(
#        record = cms.string('AlCaRecoTriggerBitsRcd'),
##        tag = cms.string('AlCaRecoHLTpaths8e29_1e31_v2') # choose tag you want
#        tag = cms.string('AlCaRecoHLTpaths8e29_1e31_v5_hlt') # choose tag you want
#
#        )
#                      )
#    )

# Put module in path:
process.p = cms.Path(process.AlCaRecoTriggerBitsRcdRead)
