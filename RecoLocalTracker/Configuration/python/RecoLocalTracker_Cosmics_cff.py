import FWCore.ParameterSet.Config as cms

from RecoLocalTracker.SiStripRecHitConverter import SiStripRecHitConverter_cfi 
siStripMatchedRecHits = SiStripRecHitConverter_cfi.siStripMatchedRecHits.clone(
    maximumHits2BeforeMatching = cms.uint32(1000)
)
from RecoLocalTracker.SiStripRecHitConverter.SiStripRecHitMatcher_cfi import *
from RecoLocalTracker.SiStripRecHitConverter.StripCPEfromTrackAngle_cfi import *
from RecoLocalTracker.SiStripZeroSuppression.SiStripZeroSuppression_cfi import *
from RecoLocalTracker.SiStripClusterizer.SiStripClusterizer_cfi import *
from RecoLocalTracker.SiPixelClusterizer.SiPixelClusterizer_cfi import *
from RecoLocalTracker.SiPixelRecHits.SiPixelRecHits_cfi import *
from RecoLocalTracker.SiPixelRecHits.PixelCPEESProducers_cff import *
pixeltrackerlocalreco = cms.Sequence(siPixelClusters*siPixelRecHits)
striptrackerlocalreco = cms.Sequence(siStripZeroSuppression*siStripClusters*siStripMatchedRecHits)
trackerlocalreco = cms.Sequence(pixeltrackerlocalreco*striptrackerlocalreco)

