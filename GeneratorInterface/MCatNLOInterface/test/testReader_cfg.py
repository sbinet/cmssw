#!/usr/bin/env cmsRun
import FWCore.ParameterSet.Config as cms

process = cms.Process("LHE")

process.source = cms.Source("MCatNLOSource",
	fileNames = cms.untracked.vstring('file:/home/xv/fabstoec/mcnloscratch/Z.events'),
        processCode = cms.int32(-11361)                       

)

process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(10))

process.LHE = cms.OutputModule("PoolOutputModule",
	dataset = cms.untracked.PSet(dataTier = cms.untracked.string('LHE')),
	fileName = cms.untracked.string('lhe.root')
)

process.outpath = cms.EndPath(process.LHE)
