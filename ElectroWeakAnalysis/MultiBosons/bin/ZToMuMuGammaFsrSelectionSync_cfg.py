import os
import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYZE")

process.inputs = cms.PSet (
    fileNames = cms.vstring(
        # Your data goes here:
#         "file:VGammaPAT_DimuonSkim_testWinter10.root"
        os.path.join("file:",
                     "uscms/home/veverka/3DayLifetime/veverka/mu",
                     "VGammaSkim_LyonSyncTest_DimuonSkim_testWinter10.root"
                     )
    )
)

process.outputs = cms.PSet (
    outputName = cms.string('basicExample.root')
)

process.analysis = cms.PSet(
    muonSrc = cms.InputTag("cleanPatMuonsTriggerMatch"),
    photonSrc = cms.InputTag("cleanPatPhotonsTriggerMatch")
)


