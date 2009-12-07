import FWCore.ParameterSet.Config as cms

#
# $Id: GenJetParticles_cff.py,v 1.4 2009/10/22 18:06:42 srappocc Exp $
#
# ShR 27 Mar 07: move modules producing candidates for Jets from RecoGenJets.cff
# 
#
genParticlesForJets = cms.EDFilter("InputGenJetsParticleSelector",
    src = cms.InputTag("genParticles"),
    ignoreParticleIDs = cms.vuint32(
         1000022,
         1000012, 1000014, 1000016,
         2000012, 2000014, 2000016,
         1000039, 5100039,
         4000012, 4000014, 4000016,
         9900012, 9900014, 9900016,
         39),
    partonicFinalState = cms.bool(False),
    excludeResonances = cms.bool(True),
    excludeFromResonancePids = cms.vuint32(12, 13, 14, 16),
    tausAsJets = cms.bool(False)
)

genJetParticles = cms.Sequence(genParticlesForJets)

genParticlesForJetsNoNu = genParticlesForJets.clone()
genParticlesForJetsNoNu.ignoreParticleIDs += cms.vuint32( 12,14,16)

genParticlesForJetsNoMuNoNu = genParticlesForJets.clone()
genParticlesForJetsNoMuNoNu.ignoreParticleIDs += cms.vuint32( 12,13,14,16)
