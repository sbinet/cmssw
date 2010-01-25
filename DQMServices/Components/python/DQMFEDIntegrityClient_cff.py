import FWCore.ParameterSet.Config as cms

dqmFEDIntegrity = cms.EDFilter("DQMFEDIntegrityClient",
   fillInEventloop = cms.untracked.bool(True),
   fillOnEndLumi = cms.untracked.bool(True),
   fillOnEndRun = cms.untracked.bool(True),
   fillOnEndJob = cms.untracked.bool(False),
   moduleName = cms.untracked.string('FED')
   )

dqmQTestDQMFED = cms.EDFilter("QualityTester",
   prescaleFactor = cms.untracked.int32(1),
   qtList = cms.untracked.FileInPath('DQMServices/Components/data/DQMFEDQualityTests.xml'),
   getQualityTestsFromFile = cms.untracked.bool(True),
   qtestOnEndLumi = cms.untracked.bool(True),
   qtestOnEndRun = cms.untracked.bool(True),
   qtestOnEndJob = cms.untracked.bool(False)
   )

dqmFEDIntegrityClient = cms.Sequence(dqmFEDIntegrity*dqmQTestDQMFED)
