import FWCore.ParameterSet.Config as cms

#
# module to combine the persistent genParticles
# from the top decay and top mothers
#
genEvt_SingleTop = cms.EDProducer("StGenEventReco",
    src  = cms.InputTag("decaySubset"),
    init = cms.InputTag("initSubset")
)
