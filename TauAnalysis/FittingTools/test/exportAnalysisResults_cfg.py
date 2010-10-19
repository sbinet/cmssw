import FWCore.ParameterSet.Config as cms

from TauAnalysis.Configuration.recoSampleDefinitionsAHtoMuTau_7TeV_grid_cfi import *

#--------------------------------------------------------------------------------
# Export analysis results into ASCII files,
# in the format used by the CDF collaboration
#--------------------------------------------------------------------------------

process = cms.Process('exportAnalysisResults')

process.DQMStore = cms.Service("DQMStore")

process.maxEvents = cms.untracked.PSet(            
    input = cms.untracked.int32(0)         
)

process.source = cms.Source("EmptySource")

process.loadAnalysisResults = cms.EDAnalyzer("DQMFileLoader",
    all = cms.PSet(
        inputFileNames = cms.vstring(
            #'/data1/veelken/CMSSW_3_8_x/plots/AHtoMuTau/export/plotsAHtoMuTau.root'
            '/data1/veelken/CMSSW_3_8_x/plots/AHtoMuTau/plotsAHtoMuTau_all.root'
        ),
        #dqmDirectory_store = cms.string('harvested/AH120')
        dqmDirectory_store = cms.string('')
    )
)

process.dumpDQMStore = cms.EDAnalyzer("DQMStoreDump")

process.exportAnalysisResults_woBtag = cms.EDAnalyzer("DQMExportAnalysisResults",

    dqmDirectory = cms.string('harvested/#PROCESSDIR#/ahMuTauAnalyzer_woBtag'),
    outputFilePath = cms.string("/data1/veelken/CMSSW_3_8_x/plots/AHtoMuTau/export"),                 

    processes = cms.PSet(
	AH120 = cms.PSet(
            dqmDirectory = cms.string('AH120'),
	    outputFilePath = cms.string("m120"),
	    outputFileName = cms.string("ggA_#CHANNEL_OUTPUTFILENAME#.hst"),
	    numEvents = cms.double(
                TARGET_LUMI*RECO_SAMPLES['AH120']['x_sec']
            ),
            hasSysUncertainties = cms.bool(True)
        ),
        bbAH120 = cms.PSet(
            dqmDirectory = cms.string('bbAH120'),
	    outputFilePath = cms.string("m120"),
	    outputFileName = cms.string("bbA_#CHANNEL_OUTPUTFILENAME#.hst"),
	    numEvents = cms.double(
                TARGET_LUMI*RECO_SAMPLES['bbAH120']['x_sec']
            ),
            hasSysUncertainties = cms.bool(True)
        ),
        AH130 = cms.PSet(
            dqmDirectory = cms.string('AH130'),
	    outputFilePath = cms.string("m130"),
	    outputFileName = cms.string("ggA_#CHANNEL_OUTPUTFILENAME#.hst"),
	    numEvents = cms.double(
                TARGET_LUMI*RECO_SAMPLES['AH130']['x_sec']
            ),
            hasSysUncertainties = cms.bool(True)
        ),
        bbAH130 = cms.PSet(
            dqmDirectory = cms.string('bbAH130'),
	    outputFilePath = cms.string("m130"),
	    outputFileName = cms.string("bbA_#CHANNEL_OUTPUTFILENAME#.hst"),
	    numEvents = cms.double(
                TARGET_LUMI*RECO_SAMPLES['bbAH130']['x_sec']
            ),
            hasSysUncertainties = cms.bool(True)
        ),
        AH200 = cms.PSet(
            dqmDirectory = cms.string('AH200'),
	    outputFilePath = cms.string("m200"),
	    outputFileName = cms.string("ggA_#CHANNEL_OUTPUTFILENAME#.hst"),
	    numEvents = cms.double(
                TARGET_LUMI*RECO_SAMPLES['AH200']['x_sec']
            ),
            hasSysUncertainties = cms.bool(True)
        ),
        bbAH200 = cms.PSet(
            dqmDirectory = cms.string('bbAH200'),
	    outputFilePath = cms.string("m200"),
	    outputFileName = cms.string("bbA_#CHANNEL_OUTPUTFILENAME#.hst"),
	    numEvents = cms.double(
                TARGET_LUMI*RECO_SAMPLES['bbAH200']['x_sec']
            ),
            hasSysUncertainties = cms.bool(True)
        ),
        Ztautau = cms.PSet(
            dqmDirectory = cms.string('Ztautau'),
	    outputFilePath = cms.string(""),
	    outputFileName = cms.string("ztt_#CHANNEL_OUTPUTFILENAME#.hst"),
	    numEvents = cms.double(
                TARGET_LUMI*RECO_SAMPLES['Ztautau']['x_sec']
            ),
            hasSysUncertainties = cms.bool(True)
        ),
        Zmumu = cms.PSet(
            dqmDirectory = cms.string('Zmumu'),
	    outputFilePath = cms.string(""),
	    outputFileName = cms.string("zmm_#CHANNEL_OUTPUTFILENAME#.hst"),
	    numEvents = cms.double(
                TARGET_LUMI*RECO_SAMPLES['Zmumu']['x_sec']
            ),
            hasSysUncertainties = cms.bool(False)
        ),
        QCD = cms.PSet(
            dqmDirectory = cms.string('Zmumu'),
	    outputFilePath = cms.string(""),
	    outputFileName = cms.string("qcd_#CHANNEL_OUTPUTFILENAME#.hst"),
	    numEvents = cms.double(
                TARGET_LUMI*RECO_SAMPLES['InclusivePPmuX']['x_sec']*0.00   # efficiency to pass genPhaseSpaceCut
               + TARGET_LUMI*RECO_SAMPLES['PPmuXptGt20Mu10']['x_sec']*0.00 #  -""-
               + TARGET_LUMI*RECO_SAMPLES['PPmuXptGt20Mu15']['x_sec']*1.00 #  -""-
            ),
            hasSysUncertainties = cms.bool(False)
        ),
        WplusJets = cms.PSet(
            dqmDirectory = cms.string('WplusJets'),
	    outputFilePath = cms.string(""),
	    outputFileName = cms.string("wjets_#CHANNEL_OUTPUTFILENAME#.hst"),
	    numEvents = cms.double(
                TARGET_LUMI*RECO_SAMPLES['WplusJets']['x_sec']
            ),
            hasSysUncertainties = cms.bool(False)
        ),
        TTplusJets = cms.PSet(
            dqmDirectory = cms.string('TTplusJets'),
	    outputFilePath = cms.string(""),
	    outputFileName = cms.string("ttbar_#CHANNEL_OUTPUTFILENAME#.hst"),
	    numEvents = cms.double(
                TARGET_LUMI*RECO_SAMPLES['TTplusJets']['x_sec']
            ),
            hasSysUncertainties = cms.bool(False)
        ),
        data = cms.PSet(
            dqmDirectory = cms.string('data'),
	    outputFilePath = cms.string(""),
	    outputFileName = cms.string("data_#CHANNEL_OUTPUTFILENAME#.hst"),
	    numEvents = cms.double(
                TARGET_LUMI*100._millibarns # rough estimate of total pp cross-section at 7 TeV center-of-mass energy
            ),
            hasSysUncertainties = cms.bool(False)
        ),
    ),

    channels = cms.PSet(
	AHtoMuTau = cms.PSet(
	    meName = cms.string(
	       'afterEvtSelNonCentralJetEt20bTag/#SYSTEMATICSDIR#/DiTauCandidateSVfitQuantities/psKine_MEt_ptBalance/Mass'
            ),
            outputFileName = cms.string("ma")
        )
    ),

    systematics = cms.PSet(
	tauJetEnUp = cms.PSet(
	    dqmDirectory = cms.string('sysUncertaintyHistManagerResults/sysTauJetEnUp'),
	    outputFilePath = cms.string("tes+1")
        ),
	tauJetEnDown = cms.PSet(
	    dqmDirectory = cms.string('sysUncertaintyHistManagerResults/sysTauJetEnDown'),
	    outputFilePath = cms.string("tes-1")
        )
    )
)
 
process.p = cms.Path(
    process.loadAnalysisResults
  #+ process.dumpDQMStore 
   + process.exportAnalysisResults_woBtag
)
