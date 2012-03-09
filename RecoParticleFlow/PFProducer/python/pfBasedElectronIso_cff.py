import FWCore.ParameterSet.Config as cms

from CommonTools.ParticleFlow.pfParticleSelection_cff import *
from CommonTools.ParticleFlow.Isolation.pfElectronIsolation_cff import *
from CommonTools.ParticleFlow.Isolation.pfElectronIsolationFromDeposits_cff import *

pfSelectedElectrons = cms.EDFilter(
    "GenericPFCandidateSelector",
    src = cms.InputTag("particleFlow"),
    cut = cms.string("abs(pdgId())==11")
)

pfBasedElectronIsoSequence = cms.Sequence(
    pfParticleSelectionSequence +
    pfSelectedElectrons +
    pfElectronIsolationSequence+
    pfElectronIsolationFromDepositsSequence
    )

#COLIN: is this file used in RECO? in PF2PAT? same for photons. 
