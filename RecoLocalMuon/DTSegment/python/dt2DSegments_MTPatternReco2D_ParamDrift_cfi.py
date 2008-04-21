import FWCore.ParameterSet.Config as cms

# Module for 2D rechit building 
# The algo uses the Param Drift Velocity (which is a 1D rec hit algo)
# The block of the reconstruction algo
from RecoLocalMuon.DTSegment.DTMeantimerPatternReco2DAlgo_ParamDrift_cfi import *
dt2DSegments = cms.EDProducer("DTRecSegment2DProducer",
    # The reconstruction algo and its parameter set
    DTMeantimerPatternReco2DAlgo_ParamDrift,
    # debug option
    debug = cms.untracked.bool(False),
    # name of the rechit 1D collection in the event
    recHits1DLabel = cms.InputTag("dt1DRecHits")
)


