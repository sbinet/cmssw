import FWCore.ParameterSet.Config as cms

process = cms.Process("TEST")
process.load("CondCore.DBCommon.CondDBSetup_cfi")

process.PoolDBESSource = cms.ESSource("PoolDBESSource",
    process.CondDBSetup,
    toGet = cms.VPSet(cms.PSet(
        record = cms.string('PedestalsRcd'),
        tag = cms.string('mytest')
    )),
    connect = cms.string('frontier://cmsfrontier.cern.ch:8000/FrontierDev/CMS_COND_PRESH')
)

process.source = cms.Source("EmptyIOVSource",
    lastRun = cms.untracked.uint32(10),
    timetype = cms.string('runnumber'),
    firstRun = cms.untracked.uint32(1),
    interval = cms.uint32(1)
)

process.get = cms.EDAnalyzer("EventSetupRecordDataGetter",
    toGet = cms.VPSet(cms.PSet(
        record = cms.string('PedestalsRcd'),
        data = cms.vstring('Pedestals')
    )),
    verbose = cms.untracked.bool(True)
)

process.p = cms.Path(process.get)


