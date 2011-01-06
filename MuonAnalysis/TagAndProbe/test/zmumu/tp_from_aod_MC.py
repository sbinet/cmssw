import FWCore.ParameterSet.Config as cms

process = cms.Process("TagProbe")

process.load('FWCore.MessageService.MessageLogger_cfi')
process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )
process.MessageLogger.cerr.FwkReport.reportEvery = 100

process.source = cms.Source("PoolSource", 
    fileNames = cms.untracked.vstring(
        '/store/mc/Fall10/DYToMuMu_M-20_CT10_TuneZ2_7TeV-powheg-pythia/GEN-SIM-RECO/E7TeV_ProbDist_2010Data_BX156_START38_V12-v1/0000/2CEF8004-17E4-DF11-8960-00237DA1680E.root',
        #'/store/mc/Fall10/DYJetsToLL_TuneD6T_M-50_7TeV-madgraph-tauola/AODSIM/START38_V12-v2/0017/CCEE6478-EFE1-DF11-85E9-0026B94D1A94.root',
	#/store/relval/CMSSW_3_9_7/RelValZmumuJets_Pt_20_300_GEN/GEN-SIM-RECO/MC_39Y_V7_PU_E7TeV_AVE_2_BX2808-v1/0054/08350812-AD0F-E011-9C92-001A92810AA6.root',
    ),
)
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(20000) )    

process.load("Configuration.StandardSequences.MagneticField_cff")
process.load("Configuration.StandardSequences.Geometry_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.load("Configuration.StandardSequences.Reconstruction_cff")
process.GlobalTag.globaltag = cms.string('START39_V6::All')

##    __  __                       
##   |  \/  |_   _  ___  _ __  ___ 
##   | |\/| | | | |/ _ \| '_ \/ __|
##   | |  | | |_| | (_) | | | \__ \
##   |_|  |_|\__,_|\___/|_| |_|___/
##                                 
## ==== Merge CaloMuons and Tracks into the collection of reco::Muons  ====
from RecoMuon.MuonIdentification.calomuons_cfi import calomuons;
process.mergedMuons = cms.EDProducer("CaloMuonMerger",
    mergeCaloMuons = cms.bool(False), # AOD
    mergeTracks    = cms.bool(True),
    muons     = cms.InputTag("muons"), 
    caloMuons = cms.InputTag("calomuons"),
    tracks    = cms.InputTag("generalTracks"),
    minCaloCompatibility = calomuons.minCaloCompatibility,
    ## Apply some minimal pt cut
    muonsCut     = cms.string("pt > 5 && track.isNonnull"),
    caloMuonsCut = cms.string("pt > 5"),
    tracksCut    = cms.string("pt > 5"),
)

## ==== Trigger matching
process.load("MuonAnalysis.MuonAssociators.patMuonsWithTrigger_cff")
## with some customization
process.muonMatchHLTL2.maxDeltaR = 0.5
process.muonMatchHLTL3.maxDeltaR = 0.1
from MuonAnalysis.MuonAssociators.patMuonsWithTrigger_cff import *
changeRecoMuonInput(process, "mergedMuons")
changeTriggerProcessName(process, "*") # auto-guess

from MuonAnalysis.TagAndProbe.common_variables_cff import *
process.load("MuonAnalysis.TagAndProbe.common_modules_cff")

process.tagMuons = cms.EDFilter("PATMuonSelector",
    src = cms.InputTag("patMuonsWithTrigger"),
    cut = cms.string("pt > 15 && "+MuonIDFlags.VBTF.value()+" && (!triggerObjectMatchesByPath('HLT_Mu9').empty())"),
)

process.probeMuons = cms.EDFilter("PATMuonSelector",
    src = cms.InputTag("patMuonsWithTrigger"),
    cut = cms.string("track.isNonnull"),  # no real cut now
)

process.tpPairs = cms.EDProducer("CandViewShallowCloneCombiner",
    cut = cms.string('60 < mass < 140'),
    decay = cms.string('tagMuons@+ probeMuons@-')
)

process.tagMuonsMCMatch = cms.EDProducer("MCTruthDeltaRMatcherNew",
    src = cms.InputTag("tagMuons"),
    matched = cms.InputTag("genParticles"),
    pdgId = cms.vint32(13),
    distMin = cms.double(0.3),
)
process.probeMuonsMCMatch = process.tagMuonsMCMatch.clone(src = "probeMuons")

process.tpTree = cms.EDAnalyzer("TagProbeFitTreeProducer",
    # choice of tag and probe pairs, and arbitration
    tagProbePairs = cms.InputTag("tpPairs"),
    arbitration   = cms.string("OneProbe"),
    # probe variables: all useful ones
    variables = AllVariables,
    flags = cms.PSet(
       TrackQualityFlags,
       MuonIDFlags,
       HighPtTriggerFlags,
       ## Isolation
       Isol    = cms.string("(isolationR03.emEt + isolationR03.hadEt + isolationR03.sumPt)/pt < 0.15"), 
       IsolTk3 = cms.string("isolationR03.sumPt < 3"), 
    ),
    tagVariables = cms.PSet(
        nVertices = cms.InputTag("nverticesModule"),
    ),
    tagFlags = cms.PSet(),
    pairVariables = cms.PSet(
        dZ      = cms.string("daughter(0).vz - daughter(1).vz"),
        nJets15 = cms.InputTag("njets15Module"),
        nJets30 = cms.InputTag("njets30Module"),
    ),
    pairFlags = cms.PSet(),
    isMC           = cms.bool(True),
    tagMatches       = cms.InputTag("tagMuonsMCMatch"),
    probeMatches     = cms.InputTag("probeMuonsMCMatch"),
    motherPdgId      = cms.vint32(22, 23),
    makeMCUnbiasTree       = cms.bool(False), # save space
    checkMotherInUnbiasEff = cms.bool(True),
    allProbes              = cms.InputTag("probeMuons"),
)

process.tnpSimpleSequence = cms.Sequence(
    process.tagMuons   * process.tagMuonsMCMatch   +
    process.probeMuons * process.probeMuonsMCMatch +
    process.tpPairs    +
    process.nverticesModule +
    process.njets15Module +
    process.njets30Module +
    process.tpTree
)

process.tagAndProbe = cms.Path( 
    process.mergedMuons                 *
    process.patMuonsWithTriggerSequence +
    process.tnpSimpleSequence
)

##    _____               _    _             
##   |_   _| __ __ _  ___| | _(_)_ __   __ _ 
##     | || '__/ _` |/ __| |/ / | '_ \ / _` |
##     | || | | (_| | (__|   <| | | | | (_| |
##     |_||_|  \__,_|\___|_|\_\_|_| |_|\__, |
##                                     |___/ 

## Then make another collection for standalone muons, using standalone track to define the 4-momentum
process.muonsSta = cms.EDProducer("RedefineMuonP4FromTrack",
    src   = cms.InputTag("muons"),
    track = cms.string("outer"),
)
## Match to trigger, to measure the efficiency of HLT tracking
from PhysicsTools.PatAlgos.tools.helpers import *
process.patMuonsWithTriggerSequenceSta = cloneProcessingSnippet(process, process.patMuonsWithTriggerSequence, "Sta")
process.muonMatchHLTL2Sta.maxDeltaR = 0.5
process.muonMatchHLTL3Sta.maxDeltaR = 0.5
massSearchReplaceAnyInputTag(process.patMuonsWithTriggerSequenceSta, "mergedMuons", "muonsSta")

## Define probes and T&P pairs
process.probeMuonsSta = cms.EDFilter("PATMuonSelector",
    src = cms.InputTag("patMuonsWithTriggerSta"),
    cut = cms.string("outerTrack.isNonnull"), # no real cut now
)
process.probeMuonsMCMatchSta = process.tagMuonsMCMatch.clone(src = "probeMuonsSta")
process.tpPairsSta = process.tpPairs.clone(decay = "tagMuons@+ probeMuonsSta@-")

## Now I have to define the passing probes for tracking
process.tkTracks = cms.EDProducer("ConcreteChargedCandidateProducer", 
    src = cms.InputTag("generalTracks"),      
    particleType = cms.string("mu+"),
) 
process.staToTkMatch = cms.EDProducer("MatcherUsingTracks",
    src     = cms.InputTag("probeMuonsSta"),
    matched = cms.InputTag("tkTracks"),  
    algorithm = cms.string("byDirectComparison"), 
    srcTrack     = cms.string("muon"),    srcState = cms.string("atVertex"), 
    matchedTrack = cms.string("tracker"), matchedState = cms.string("atVertex"),
    maxDeltaR        = cms.double(0.3), 
    maxDeltaPtRel    = cms.double(2),   # |pt(sta) - pt(tk)|/pt(tk)
    maxDeltaLocalPos = cms.double(100),
    sortBy           = cms.string("deltaR"),
)
process.staToTkNoZMatch = process.staToTkMatch.clone(matched = "tkTracksNoZ")
process.staPassingTk = cms.EDProducer("MatchedCandidateSelector",
    src   = cms.InputTag("probeMuonsSta"),
    match = cms.InputTag("staToTkMatch"),
)
process.staPassingTkNoZ = process.staPassingTk.clone(match = "staToTkNoZMatch")

process.tpTreeSta = process.tpTree.clone(
    tagProbePairs = "tpPairsSta",
    variables = cms.PSet(
        KinematicVariables, 
        TriggerVariables, 
        ## extra standalone muon quality variables
        outerHits      = cms.string("outerTrack.hitPattern.numberOfHits"),
        outerValidHits = cms.string("outerTrack.numberOfValidHits"),
        outerStationsAny   = cms.string("outerTrack.hitPattern.muonStationsWithAnyHits"),
        outerStationsValid = cms.string("outerTrack.hitPattern.muonStationsWithValidHits"),
        ## track matching variables
        tk_deltaR     = cms.InputTag("staToTkMatch","deltaR"),
        tk_deltaPtRel = cms.InputTag("staToTkMatch","deltaPtRel"),
        tk_deltaEta   = cms.InputTag("staToTkMatch","deltaEta"),
        tk_deltaPhi   = cms.InputTag("staToTkMatch","deltaPhi"),
        ## track matching variables for fake rates
        tkNoZ_deltaR     = cms.InputTag("staToTkNoZMatch","deltaR"),
        tkNoZ_deltaPtRel = cms.InputTag("staToTkNoZMatch","deltaPtRel"),
        tkNoZ_deltaEta   = cms.InputTag("staToTkNoZMatch","deltaEta"),
        tkNoZ_deltaPhi   = cms.InputTag("staToTkNoZMatch","deltaPhi"),
    ),
    flags = cms.PSet(
        #HighPtTriggerFlags, 
        Glb      = MuonIDFlags.Glb,
        TM       = MuonIDFlags.TM,
        TMA      = MuonIDFlags.TMA,
        hasTrack    = cms.InputTag("staPassingTk"),
        hasTrackNoZ = cms.InputTag("staPassingTkNoZ"),
        #L1DoubleMuOpen       = LowPtTriggerFlagsPhysics.L1DoubleMuOpen,
        #L1DoubleMuOpen_Tight = LowPtTriggerFlagsPhysics.L1DoubleMuOpen_Tight,
        #L2DoubleMu0          = LowPtTriggerFlagsPhysics.L2DoubleMu0,
    ),
    allProbes     = "probeMuonsSta",
    probeMatches  = "probeMuonsMCMatchSta",
)
process.tpTreeSta.variables.l1pt = process.tpTreeSta.variables.l1pt.value().replace("muonL1Info","muonL1InfoSta")
process.tpTreeSta.variables.l1q  = process.tpTreeSta.variables.l1q.value( ).replace("muonL1Info","muonL1InfoSta")
process.tpTreeSta.variables.l1dr = process.tpTreeSta.variables.l1dr.value().replace("muonL1Info","muonL1InfoSta")
process.tpTreeSta.tagFlags = process.tpTreeSta.flags.clone(hasTrack = cms.string(""), hasTrackNoZ  = cms.string(""))
process.tpTreeSta.pairVariables.nJets15 = "njets15ModuleSta"
process.tpTreeSta.pairVariables.nJets30 = "njets30ModuleSta"
process.njets15ModuleSta = process.njets15Module.clone(pairs = "tpPairsSta")
process.njets30ModuleSta = process.njets30Module.clone(pairs = "tpPairsSta")

process.tnpSimpleSequenceSta = cms.Sequence(
    process.tagMuons   * process.tagMuonsMCMatch   +
    process.probeMuonsSta * process.probeMuonsMCMatchSta +
    ( process.tkTracks    * process.staToTkMatch    * process.staPassingTk    ) +
    ( process.tkTracksNoZ * process.staToTkNoZMatch * process.staPassingTkNoZ ) +
    process.tpPairsSta      +
    process.nverticesModule +
    process.njets15ModuleSta +
    process.njets30ModuleSta +
    process.tpTreeSta
)

process.tagAndProbeSta = cms.Path( 
    process.muonsSta                       +
    process.patMuonsWithTriggerSequenceSta +
    process.tnpSimpleSequenceSta
)

process.TFileService = cms.Service("TFileService", fileName = cms.string("tnpZ_MC.root"))
