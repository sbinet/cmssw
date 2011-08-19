import FWCore.ParameterSet.Config as cms

#--------------------------------------------------------------------------------
# compute neutral particle density for out-of-time pile-up reweighting
## from CommonTools.ParticleFlow.ParticleSelectors.pfAllNeutralHadrons_cfi import pfAllNeutralHadrons
## from CommonTools.ParticleFlow.ParticleSelectors.pfAllPhotons_cfi import pfAllPhotons
## pfNeutralCandPdgIds = []
## pfNeutralCandPdgIds.extend(pfAllNeutralHadrons.pdgId.value())
## pfNeutralCandPdgIds.extend(pfAllPhotons.pdgId.value())
##  
## pfNeutralCands = cms.EDFilter("PdgIdPFCandidateSelector",
##     src = cms.InputTag('particleFlow'),
##     pdgId = cms.vint32(pfNeutralCandPdgIds)
## )
##
## from RecoJets.JetProducers.kt4PFJets_cfi import kt4PFJets
## kt6PFNeutralJets = kt4PFJets.clone(
##     src = cms.InputTag('pfNeutralCands'),
##     rParam = cms.double(0.6),
##     doRhoFastjet = cms.bool(True),
##     Rho_EtaMax = cms.double(2.5)
## )    
#--------------------------------------------------------------------------------

vertexMultiplicityVsRhoPFNeutralReweight = cms.EDProducer("VertexMultiplicityVsRhoPFNeutralReweightProducer",
    srcVertices = cms.InputTag('selectedPrimaryVertexPosition'),
    ##srcRhoPFNeutral = cms.InputTag('kt6PFNeutralJets', 'rho'),
    srcRhoPFNeutral = cms.InputTag('kt6PFJets', 'rho'),
                                                          
    ##inputFileName = cms.FileInPath('TauAnalysis/RecoTools/data/vertexMultiplicityVsRhoPFNeutralReweight.root'),
    ##meName = cms.string('histoReweight'),
    src = cms.InputTag('addPileupInfo'),
    type = cms.string("gen"),
                                                          
    minPUreweight = cms.double(1.e-1),
    maxPUreweight = cms.double(1.e+1)
)

produceVertexMultiplicityVsRhoPFNeutralReweights = cms.Sequence(
##    pfNeutralCands
##   * kt6PFNeutralJets
    vertexMultiplicityVsRhoPFNeutralReweight
)
