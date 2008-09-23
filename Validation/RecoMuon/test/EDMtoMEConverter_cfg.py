# The following comments couldn"t be translated into the new config version:
#sigma(pt) vs 
import FWCore.ParameterSet.Config as cms

process = cms.Process("EDMtoMEConvert")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.load("DQMServices.Components.EDMtoMEConverter_cff")
process.load("DQMServices.Components.DQMEnvironment_cfi")
#process.load("Configuration.StandardSequences.FakeConditions_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.GlobalTag.globaltag = "STARTUP_V5::All"

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring("file:validationEDM.root")
)

process.postProcessorMuonMultiTrack = cms.EDFilter("PostProcessor",
    subDir = cms.untracked.string("RecoMuonV/MultiTrack/*"),
    effCmds = cms.vstring("",),
    resCmds = cms.vstring("cotThetares_vs_eta '#sigma(cot(#theta)) vs #eta' cotThetares_vs_eta",
                          "cotThetares_vs_pt '#sigma(cot(#theta)) vs p_{T}' cotThetares_vs_pt",
                          "dxypull_vs_eta 'd_{xy} Pull vs #eta' dxypull_vs_eta",
                          "dxyres_vs_eta '#sigma(d_{xy}) vs #eta' dxyres_vs_eta",
                          "dxyres_vs_pt '#sigma(d_{xy}) vs p_{T}' dxyres_vs_pt",
                          "dzpull_vs_eta 'd_{z} Pull vs #eta' dzpull_vs_eta",
                          "dzres_vs_eta '#sigma(d_{z}) vs #eta' dzres_vs_eta",
                          "dzres_vs_pt '#sigma(d_{z}) vs p_{T}' dzres_vs_pt",
                          "etares_vs_eta '#sigma(#eta) vs #eta' etares_vs_eta",
                          "phipull_vs_eta '#phi Pull vs #eta' phipull_vs_eta",
                          "phipull_vs_phi '#phi Pull vs #phi' phipull_vs_phi",
                          "phires_vs_eta '#sigma(#phi) vs #eta' phires_vs_eta",
                          "phires_vs_phi '#sigma(#phi) vs #phi' phires_vs_phi",
                          "phires_vs_pt '#sigma(#phi) vs p_{T}' phires_vs_pt",
                          "ptpull_vs_eta 'p_{T} Pull vs #eta' ptpull_vs_eta",
                          "ptpull_vs_phi 'p_{T} Pull vs #phi' ptpull_vs_phi",
                          "ptres_vs_eta '#sigma(p_{T}) vs #eta' ptres_vs_eta",
                          "ptres_vs_phi '#sigma(p_{T}) vs #phi' ptres_vs_phi",
                          "ptres_vs_pt '#sigma(p_{T}) vs p_{T}' ptres_vs_pt",
                          "thetapull_vs_eta '#theta Pull vs #eta' thetapull_vs_eta",
                          "thetapull_vs_phi '#theta Pull vs #phi' thetapull_vs_phi"),
    commands = cms.vstring(""),
    outputFileName = cms.untracked.string("")
)

process.postProcessorRecoMuon = cms.EDFilter("PostProcessor",
    subDir = cms.untracked.string("RecoMuonV/RecoMuon_*"),
    commands = cms.vstring(""),

    effCmds = cms.vstring("Trk/EffP   'Efficiency vs p'     Trk/P   Muons/SimP  ",
                          "Trk/EffPt  'Efficiency vs p_{T}' Trk/P   Muons/SimP  ",
                          "Trk/EffEta 'Efficiency vs #eta'  Trk/Eta Muons/SimEta",
                          "Trk/EffPhi 'Efficiency vs #phi'  Trk/Phi Muons/SimPhi",
                          "Sta/EffP   'Efficiency vs p'     Sta/P   Muons/SimP  ",
                          "Sta/EffPt  'Efficiency vs p_{T}' Sta/P   Muons/SimP  ",
                          "Sta/EffEta 'Efficiency vs #eta'  Sta/Eta Muons/SimEta",
                          "Sta/EffPhi 'Efficiency vs #phi'  Sta/Phi Muons/SimPhi",
                          "Glb/EffP   'Efficiency vs p'     Glb/P   Muons/SimP  ",
                          "Glb/EffPt  'Efficiency vs p_{T}' Glb/P   Muons/SimP  ",
                          "Glb/EffEta 'Efficiency vs #eta'  Glb/Eta Muons/SimEta",
                          "Glb/EffPhi 'Efficiency vs #phi'  Glb/Phi Muons/SimPhi"),

    resCmds = cms.vstring("Trk/ErrP_vs_P      '#sigma(p) vs p'           Trk/ErrP_vs_P     ",
                          "Trk/ErrP_vs_Eta    '#sigma(p) vs #eta'        Trk/ErrP_vs_Eta   ",
                          "Trk/ErrPt_vs_Pt    '#sigma(p) vs p_{T}'       Trk/ErrPt_vs_Pt   ",
                          "Trk/ErrPt_vs_Eta   '#sigma(p) vs #eta'        Trk/ErrPt_vs_Eta  ",
                          "Trk/ErrEta_vs_Eta  '#sigma(#eta) vs #eta '    Trk/ErrEta_vs_Eta ",
                          "Trk/ErrQPt_vs_Pt   '#sigma(q/p_{T}) vs p_{T}' Trk/ErrQPt_vs_Pt  ",
                          "Trk/ErrQPt_vs_Eta  '#sigma(q/p_{T}) vs #eta'  Trk/ErrQPt_vs_Eta ",
                          "Trk/PullEta_vs_Pt  'Pull of #eta vs p_{T}'    Trk/PullEta_vs_Pt ",
                          "Trk/PullEta_vs_Eta 'Pull of #eta vs #eta'     Trk/PullEta_vs_Eta",
                          "Trk/PullPhi_vs_Eta 'Pull of #phi vs #eta'     Trk/PullPhi_vs_Eta",
                          "Trk/PullPt_vs_Pt   'Pull of p_{T} vs p_{T}'   Trk/PullPt_vs_Pt  ",
                          "Trk/PullPt_vs_Eta  'Pull of p_{T} vs #eta'    Trk/PullPt_vs_Eta ",

                          "Sta/ErrP_vs_P      '#sigma(p) vs p'           Sta/ErrP_vs_P     ",
                          "Sta/ErrP_vs_Eta    '#sigma(p) vs #eta'        Sta/ErrP_vs_Eta   ",
                          "Sta/ErrPt_vs_Pt    '#sigma(p) vs p_{T}'       Sta/ErrPt_vs_Pt   ",
                          "Sta/ErrPt_vs_Eta   '#sigma(p) vs #eta'        Sta/ErrPt_vs_Eta  ",
                          "Sta/ErrEta_vs_Eta  '#sigma(#eta) vs #eta '    Sta/ErrEta_vs_Eta ",
                          "Sta/ErrQPt_vs_Pt   '#sigma(q/p_{T}) vs p_{T}' Sta/ErrQPt_vs_Pt  ",
                          "Sta/ErrQPt_vs_Eta  '#sigma(q/p_{T}) vs #eta'  Sta/ErrQPt_vs_Eta ",
                          "Sta/PullEta_vs_Pt  'Pull of #eta vs p_{T}'    Sta/PullEta_vs_Pt ",
                          "Sta/PullEta_vs_Eta 'Pull of #eta vs #eta'     Sta/PullEta_vs_Eta",
                          "Sta/PullPhi_vs_Eta 'Pull of #phi vs #eta'     Sta/PullPhi_vs_Eta",
                          "Sta/PullPt_vs_Pt   'Pull of p_{T} vs p_{T}'   Sta/PullPt_vs_Pt  ",
                          "Sta/PullPt_vs_Eta  'Pull of p_{T} vs #eta'    Sta/PullPt_vs_Eta ",

                          "Glb/ErrP_vs_P      '#sigma(p) vs p'           Glb/ErrP_vs_P     ",
                          "Glb/ErrP_vs_Eta    '#sigma(p) vs #eta'        Glb/ErrP_vs_Eta   ",
                          "Glb/ErrPt_vs_Pt    '#sigma(p) vs p_{T}'       Glb/ErrPt_vs_Pt   ",
                          "Glb/ErrPt_vs_Eta   '#sigma(p) vs #eta'        Glb/ErrPt_vs_Eta  ",
                          "Glb/ErrEta_vs_Eta  '#sigma(#eta) vs #eta '    Glb/ErrEta_vs_Eta ",
                          "Glb/ErrQPt_vs_Pt   '#sigma(q/p_{T}) vs p_{T}' Glb/ErrQPt_vs_Pt  ",
                          "Glb/ErrQPt_vs_Eta  '#sigma(q/p_{T}) vs #eta'  Glb/ErrQPt_vs_Eta ",
                          "Glb/PullEta_vs_Pt  'Pull of #eta vs p_{T}'    Glb/PullEta_vs_Pt ",
                          "Glb/PullEta_vs_Eta 'Pull of #eta vs #eta'     Glb/PullEta_vs_Eta",
                          "Glb/PullPhi_vs_Eta 'Pull of #phi vs #eta'     Glb/PullPhi_vs_Eta",
                          "Glb/PullPt_vs_Pt   'Pull of p_{T} vs p_{T}'   Glb/PullPt_vs_Pt  ",
                          "Glb/PullPt_vs_Eta  'Pull of p_{T} vs #eta'    Glb/PullPt_vs_Eta "),
    # Leave outputFileName to be Null string 
    # if don"t want to save histograms manually
    # untracked string outputFileName = "" 
    outputFileName = cms.untracked.string("Result.root")
)

process.DQMStore.referenceFileName = ""

process.dqmSaver.convention = "RelVal"
process.dqmSaver.workflow = "/GlobalValidation/Test/RECO"

process.p1 = cms.Path(process.EDMtoMEConverter*
                      process.postProcessorMuonMultiTrack*process.postProcessorRecoMuon*
                      process.dqmSaver)
