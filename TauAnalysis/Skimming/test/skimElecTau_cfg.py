import FWCore.ParameterSet.Config as cms

process = cms.Process("elecTauSkim")

from TauAnalysis.Skimming.EventContent_cff import *

process.load('FWCore/MessageService/MessageLogger_cfi')
process.MessageLogger.cerr.FwkReport.reportEvery = 100
process.MessageLogger.cerr.threshold = cms.untracked.string('INFO')
process.load("Configuration.StandardSequences.Geometry_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = cms.string('MC_31X_V2::All')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        '/store/relval/CMSSW_3_1_2/RelValZTT/GEN-SIM-RECO/STARTUP31X_V2-v1/0007/A4DD1FAE-B178-DE11-B608-001D09F24EAC.root',
        '/store/relval/CMSSW_3_1_2/RelValZTT/GEN-SIM-RECO/STARTUP31X_V2-v1/0007/9408B54D-CB78-DE11-9AEB-001D09F2503C.root'
    )
)

#--------------------------------------------------------------------------------
# select electrons and tau-jets
#--------------------------------------------------------------------------------

process.selectedElectrons = cms.EDFilter("GsfElectronSelector",
    src = cms.InputTag("gsfElectrons"),
    cut = cms.string("abs(eta) < 2.5 & pt > 8."),
    filter = cms.bool(True)
)

process.selectedPFTaus = cms.EDFilter("PFTauSelector",
    src = cms.InputTag('shrinkingConePFTauProducer'),
    discriminators = cms.VPSet(
        cms.PSet(
            discriminator = cms.InputTag("shrinkingConePFTauDiscriminationByLeadingPionPtCut"),
            selectionCut = cms.double(0.5)
        )
    ),
    filter = cms.bool(True)
)

process.selectedCaloTaus = cms.EDFilter("CaloTauSelector",
    src = cms.InputTag('caloRecoTauProducer'),
    discriminators = cms.VPSet(
        cms.PSet(
            discriminator = cms.InputTag("caloRecoTauDiscriminationByLeadingTrackPtCut"),
            selectionCut = cms.double(0.5)
        )
    ),
    filter = cms.bool(True)
)

#--------------------------------------------------------------------------------
# combine selected electrons and tau-jets into pairs;
# require electrons and tau-jets to be separated by dR > 0.3 in eta-phi,
# in order to reject events in which the tau-jet refers to the same physical
# particle as the electron (note that almost all electrons get selected as tau-jets !!)
#--------------------------------------------------------------------------------

process.elecCaloTauPairs = cms.EDProducer("DiCandidatePairProducer",
    useLeadingTausOnly = cms.bool(False),
    srcLeg1 = cms.InputTag('selectedCaloTaus'),
    srcLeg2 = cms.InputTag('selectedElectrons'),
    dRmin12 = cms.double(0.),
    srcMET = cms.InputTag(''),
    recoMode = cms.string(""),
    verbosity = cms.untracked.int32(0)                                       
)

process.selectedElecCaloTauPairs = cms.EDFilter("DiCandidatePairSelector",
    src = cms.InputTag('elecCaloTauPairs'),
    cut = cms.string("dR12 > 0.3"),
    filter = cms.bool(True)                                     
)

process.elecPFTauPairs = cms.EDProducer("DiCandidatePairProducer",
    useLeadingTausOnly = cms.bool(False),
    srcLeg1 = cms.InputTag('selectedPFTaus'),
    srcLeg2 = cms.InputTag('selectedElectrons'),
    dRmin12 = cms.double(0.),
    srcMET = cms.InputTag(''),
    recoMode = cms.string(""),
    verbosity = cms.untracked.int32(0)
)

process.selectedElecPFTauPairs = cms.EDFilter("DiCandidatePairSelector",
    src = cms.InputTag('elecPFTauPairs'),
    cut = cms.string("dR12 > 0.3"),
    filter = cms.bool(True)                                     
)

#--------------------------------------------------------------------------------
# keep event in case it passed either the electron + pfTau or electron + caloTau selection
#--------------------------------------------------------------------------------

process.elecPFTauSkimPath = cms.Path(
    (process.selectedPFTaus + process.selectedElectrons)
   * process.elecPFTauPairs
   * process.selectedElecPFTauPairs
)

process.elecCaloTauSkimPath = cms.Path(
    (process.selectedCaloTaus + process.selectedElectrons)
   * process.elecCaloTauPairs
   * process.selectedElecCaloTauPairs
)

elecTauEventSelection = cms.untracked.PSet(
    SelectEvents = cms.untracked.PSet(
        SelectEvents = cms.vstring('elecPFTauSkimPath','elecCaloTauSkimPath')
    )
)

#--------------------------------------------------------------------------------
# fill validation histograms for events passing either the electron + pfTau or electron + caloTau selection
#--------------------------------------------------------------------------------

process.DQMStore = cms.Service("DQMStore")

from TauAnalysis.Skimming.ewkElecTauValHistManager_cfi import *

process.fillElecTauValPlots = cms.EDAnalyzer("EwkTauValidation",

    # list of individual channels                           
    channels = cms.VPSet(
        ewkElecTauValHistManager
    ),

    # disable all warnings
    maxNumWarnings = cms.int32(1)                      
)

process.saveElecTauValPlots = cms.EDAnalyzer("DQMSimpleFileSaver",
    outputFileName = cms.string('elecTauValPlots.root')
)

process.p = cms.Path(
    process.fillElecTauValPlots
   + process.saveElecTauValPlots
)

#--------------------------------------------------------------------------------
# save events passing either the electron + pfTau or electron + caloTau selection
#--------------------------------------------------------------------------------

process.elecTauSkimOutputModule = cms.OutputModule("PoolOutputModule",                                 
    tauAnalysisEventContent,                                               
    elecTauEventSelection,
    fileName = cms.untracked.string('skimElecTau.root')
)

process.options = cms.untracked.PSet(
    wantSummary = cms.untracked.bool(True)
)

process.o = cms.EndPath(process.elecTauSkimOutputModule)
