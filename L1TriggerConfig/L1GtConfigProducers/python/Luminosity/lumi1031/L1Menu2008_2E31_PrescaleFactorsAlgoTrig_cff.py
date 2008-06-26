import FWCore.ParameterSet.Config as cms

from L1TriggerConfig.L1GtConfigProducers.l1GtPrescaleFactorsAlgoTrig_cfi import *
l1GtPrescaleFactorsAlgoTrig.PrescaleFactorsSet = cms.VPSet(cms.PSet(
    PrescaleFactors = cms.vint32(1000000, 1000000, 1000, 1, 10000, 
        1000, 1, 10000, 1000, 1, 
        1, 1, 1, 1, 1, 
        1000, 1, 1, 1, 1, 
        1, 1, 100, 1, 1, 
        1, 1, 1, 100, 10, 
        1, 1, 1, 1000, 100, 
        10, 1, 1, 1, 100, 
        10, 1, 1, 1, 800, 
        800, 1, 1, 1, 1, 
        1, 1, 10, 10, 1, 
        1, 1, 1, 1, 1, 
        1, 1, 1, 1, 1, 
        1, 1, 1, 1, 1, 
        1, 10, 10, 1, 1, 
        1, 1, 1, 1, 1, 
        1, 1, 1, 1, 1, 
        1, 1, 1, 1, 1, 
        1, 1, 1, 1, 1, 
        1, 1500, 800, 1, 400, 
        400, 1, 1, 1, 1, 
        1, 1, 1, 100, 1, 
        1, 1000, 1, 300, 300, 
        1000, 1000, 1000, 1000, 1, 
        1, 1, 1, 1, 1, 
        1, 1, 1)
))

