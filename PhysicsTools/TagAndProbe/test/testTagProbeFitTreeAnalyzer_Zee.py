import FWCore.ParameterSet.Config as cms

process = cms.Process("TagProbe")
process.source = cms.Source("EmptySource")
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(1) )

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.destinations = ['cout', 'cerr']
process.MessageLogger.cerr.FwkReport.reportEvery = 1000


isMC = False
HLTDef = "probe_passingHLT"
PDFName = "pdfSignalPlusBackground"

if isMC:
    PDFName = ""



EfficiencyBinningSpecification = cms.PSet(
    #specifies what unbinned variables to include in the dataset, the mass is needed for the fit
    UnbinnedVariables = cms.vstring("mass"),
    #specifies the binning of parameters
    BinnedVariables = cms.PSet(
    probe_gsfEle_pt = cms.vdouble( 20, 25, 30, 35, 40, 45, 50, 200 ),
    probe_gsfEle_eta = cms.vdouble( -2.5, -2.0, -1.5, -1.0, -0.5, 0.0, 0.5, 1.0, 1.5, 2.0, 2.5 )
    ),
    #first string is the default followed by binRegExp - PDFname pairs
    BinToPDFmap = cms.vstring(PDFName)
    #BinToPDFmap = cms.vstring()    
)



EfficiencyBinningSpecificationMC = cms.PSet(
    #specifies what unbinned variables to include in the dataset, the mass is needed for the fit
    UnbinnedVariables = cms.vstring("mass"),
    #specifies the binning of parameters
    BinnedVariables = cms.PSet(
    mcTrue = cms.vstring("true"),
    probe_gsfEle_pt = cms.vdouble( 20, 25, 30, 35, 40, 45, 50, 200 ),
    probe_gsfEle_eta = cms.vdouble( -2.5, -2.0, -1.5, -1.0, -0.5, 0.0, 0.5, 1.0, 1.5, 2.0, 2.5 )
    ),
    BinToPDFmap = cms.vstring()  
)



############################################################################################
############################################################################################
####### GsfElectron->Id / selection efficiency 
############################################################################################
############################################################################################

process.GsfElectronToId = cms.EDAnalyzer("TagProbeFitTreeAnalyzer",
    # IO parameters:
    InputFileNames = cms.vstring("testNewWrite.root"),
    #InputFileNames = cms.vstring("/uscms_data/d2/kalanand/allTPtrees_35invpb.root"),
    #InputFileNames = cms.vstring("/uscms_data/d2/kalanand/allTPtrees_mc.root"),
    InputDirectoryName = cms.string("GsfElectronToId"),
    InputTreeName = cms.string("fitter_tree"),
    OutputFileName = cms.string("efficiency-GsfElectronToId.root"),
    #numbrer of CPUs to use for fitting
    NumCPU = cms.uint32(1),
    # specifies wether to save the RooWorkspace containing the data for each bin and
    # the pdf object with the initial and final state snapshots
    SaveWorkspace = cms.bool(True),
    floatShapeParameters = cms.bool(True),
    #fixVars = cms.vstring("mean"),
                                                 
    # defines all the real variables of the probes available in the input tree and intended for use in the efficiencies
    Variables = cms.PSet(
        mass = cms.vstring("Tag-Probe Mass", "60.0", "120.0", "GeV/c^{2}"),
        probe_gsfEle_pt = cms.vstring("Probe p_{T}", "0", "1000", "GeV/c"),
        probe_gsfEle_eta = cms.vstring("Probe #eta", "-2.5", "2.5", ""),                
    ),

    # defines all the discrete variables of the probes available in the input tree and intended for use in the efficiency calculations
    Categories = cms.PSet(
        #mcTrue = cms.vstring("MC true", "dummy[true=1,false=0]"),
        #mcTrue = cms.vstring("MC true", "dummy[false=1,true=0]"),            
        probe_passingHLT = cms.vstring("probe_passingHLT", "dummy[pass=1,fail=0]"),               
        probe_passConvRej = cms.vstring("probe_passConvRej", "dummy[pass=1,fail=0]"),        
        probe_isWP95 = cms.vstring("probe_isWP95", "dummy[pass=1,fail=0]"),
        probe_isWP90 = cms.vstring("probe_isWP90", "dummy[pass=1,fail=0]"),
        probe_isWP85 = cms.vstring("probe_isWP85", "dummy[pass=1,fail=0]"),
        probe_isWP80 = cms.vstring("probe_isWP80", "dummy[pass=1,fail=0]"),
        probe_isWP70 = cms.vstring("probe_isWP70", "dummy[pass=1,fail=0]"),
        probe_isWP60 = cms.vstring("probe_isWP60", "dummy[pass=1,fail=0]"),
        probe_isCicVeryLoose = cms.vstring("probe_isCicVeryLoose", "dummy[pass=1,fail=0]"),
        probe_isCicLoose = cms.vstring("probe_isCicLoose", "dummy[pass=1,fail=0]"),
        probe_isCicMedium = cms.vstring("probe_isCicMedium", "dummy[pass=1,fail=0]"),
        probe_isCicTight = cms.vstring("probe_isCicTight", "dummy[pass=1,fail=0]"),
        probe_isCicSuperTight = cms.vstring("probe_isCicSuperTight", "dummy[pass=1,fail=0]"),
        probe_isCicHyperTight1 = cms.vstring("probe_isCicHyperTight1", "dummy[pass=1,fail=0]"),
        probe_isCicHyperTight2 = cms.vstring("probe_isCicHyperTight2", "dummy[pass=1,fail=0]"),
        probe_isCicHyperTight3 = cms.vstring("probe_isCicHyperTight3", "dummy[pass=1,fail=0]"),
        probe_isCicHyperTight4 = cms.vstring("probe_isCicHyperTight4", "dummy[pass=1,fail=0]"),          
    ),
    # defines all the PDFs that will be available for the efficiency calculations; uses RooFit's "factory" syntax;
    # each pdf needs to define "signal", "backgroundPass", "backgroundFail" pdfs, "efficiency[0.9,0,1]" and "signalFractionInPassing[0.9]" are used for initial values  
    PDFs = cms.PSet(
        pdfSignalPlusBackground = cms.vstring(
##     "CBExGaussShape::signalRes(mass, mean[2.0946e-01], sigma[8.5695e-04],alpha[3.8296e-04], n[6.7489e+00], sigma_2[2.5849e+00], frac[6.5704e-01])",  ### the signal function goes here
     "CBExGaussShape::signalResPass(mass, mean[2.0946e-01, -5., 5.], sigma[8.5695e-04, 0., 5.],alpha[3.8296e-04], n[6.7489e+00], sigma_2[2.5849e+00], frac[6.5704e-01])",  ### signal resolution for "pass" sample
     "CBExGaussShape::signalResPass(mass, mean[2.0946e-01, -5., 5.], sigma[8.5695e-04, 0., 5.],alpha[3.8296e-04], n[6.7489e+00], sigma_2[2.5849e+00], frac[6.5704e-01])",  ### signal resolution for "fail" sample     
    "ZGeneratorLineShape::signalPhy(mass)", ### NLO line shape
    "RooExponential::backgroundPass(mass, cPass[-0.02, -5, 0])",
    "RooExponential::backgroundFail(mass, cFail[-0.02, -5, 0])",
    "FCONV::signalPass(mass, signalPhy, signalResPass)",
    "FCONV::signalFail(mass, signalPhy, signalResFail)",     
    "efficiency[0.9,0,1]",
    "signalFractionInPassing[1.0]"
    #"Gaussian::signal(mass, mean[91.2, 89.0, 93.0], sigma[2.3, 0.5, 10.0])",
    #"RooExponential::backgroundPass(mass, cPass[0,-10,10])",
    #"RooExponential::backgroundFail(mass, cFail[0,-10,10])",
    #"efficiency[0.9,0,1]",
    #"signalFractionInPassing[0.9]"
        ),
    ),

    # defines a set of efficiency calculations, what PDF to use for fitting and how to bin the data;
    # there will be a separate output directory for each calculation that includes a simultaneous fit, side band subtraction and counting. 
    Efficiencies = cms.PSet(
        #the name of the parameter set becomes the name of the directory
        WP95 = cms.PSet(
             EfficiencyBinningSpecification,
            #specifies the efficiency of which category and state to measure 
            EfficiencyCategoryAndState = cms.vstring("probe_isWP95","pass"),
        ),
        WP90 = cms.PSet(
            EfficiencyBinningSpecification,
            EfficiencyCategoryAndState = cms.vstring("probe_passConvRej","pass","probe_isWP90","pass"),
        ),
        WP85 = cms.PSet(
            EfficiencyBinningSpecification,    
            EfficiencyCategoryAndState = cms.vstring("probe_passConvRej","pass","probe_isWP85","pass"),
        ),
         WP80 = cms.PSet(
            EfficiencyBinningSpecification,   
            EfficiencyCategoryAndState = cms.vstring("probe_passConvRej","pass","probe_isWP80","pass"),
        ),
        WP70 = cms.PSet(
            EfficiencyBinningSpecification,    
            EfficiencyCategoryAndState = cms.vstring("probe_passConvRej","pass","probe_isWP70","pass"),
        ),      
        WP60 = cms.PSet(
            EfficiencyBinningSpecification,      
            EfficiencyCategoryAndState = cms.vstring("probe_passConvRej","pass","probe_isWP60","pass"),
        ),
        CicVeryLoose = cms.PSet(
            EfficiencyBinningSpecification,     
            EfficiencyCategoryAndState = cms.vstring("probe_passConvRej","pass","probe_isCicVeryLoose","pass"),
        ),
        CicLoose = cms.PSet(
            EfficiencyBinningSpecification,    
            EfficiencyCategoryAndState = cms.vstring("probe_passConvRej","pass","probe_isCicLoose","pass"),
        ),
        CicMedium = cms.PSet(
            EfficiencyBinningSpecification,    
            EfficiencyCategoryAndState = cms.vstring("probe_passConvRej","pass","probe_isCicMedium","pass"),
        ),
        CicTight = cms.PSet(
            EfficiencyBinningSpecification,
            EfficiencyCategoryAndState = cms.vstring("probe_passConvRej","pass","probe_isCicTight","pass"),
        ),
        CicSuperTight = cms.PSet(
            EfficiencyBinningSpecification,    
            EfficiencyCategoryAndState = cms.vstring("probe_passConvRej","pass","probe_isCicSuperTight","pass"),
        ),        
        CicHyperTight1 = cms.PSet(
            EfficiencyBinningSpecification,    
            EfficiencyCategoryAndState = cms.vstring("probe_passConvRej","pass","probe_isCicHyperTight1","pass"),
        ),
        CicHyperTight2 = cms.PSet(
            EfficiencyBinningSpecification,    
            EfficiencyCategoryAndState = cms.vstring("probe_passConvRej","pass","probe_isCicHyperTight2","pass"),
        ),
        CicHyperTight3 = cms.PSet(
            EfficiencyBinningSpecification,    
            EfficiencyCategoryAndState = cms.vstring("probe_passConvRej","pass","probe_isCicHyperTight3","pass"),
        ),
        CicHyperTight4 = cms.PSet(
            EfficiencyBinningSpecification, 
            EfficiencyCategoryAndState = cms.vstring("probe_passConvRej","pass","probe_isCicHyperTight4","pass"),
        ),  
        ############################################################################################
        ############################################################################################
        ############################################################################################
##         MCtruth_WP95 = cms.PSet(
##             EfficiencyBinningSpecificationMC,
##             EfficiencyCategoryAndState = cms.vstring("probe_isWP95","pass"),
##         ),
##         MCtruth_WP90 = cms.PSet(
##             EfficiencyBinningSpecificationMC,
##             EfficiencyCategoryAndState = cms.vstring("probe_passConvRej","pass","probe_isWP90","pass"),
##         ),
##         MCtruth_WP85 = cms.PSet(
##             EfficiencyBinningSpecificationMC,    
##             EfficiencyCategoryAndState = cms.vstring("probe_passConvRej","pass","probe_isWP85","pass"),
##         ),
##         MCtruth_WP80 = cms.PSet(
##             EfficiencyBinningSpecificationMC,   
##             EfficiencyCategoryAndState = cms.vstring("probe_passConvRej","pass","probe_isWP80","pass"),
##         ),
##         MCtruth_WP70 = cms.PSet(
##             EfficiencyBinningSpecificationMC,    
##             EfficiencyCategoryAndState = cms.vstring("probe_passConvRej","pass","probe_isWP70","pass"),
##         ),      
##         MCtruth_WP60 = cms.PSet(
##             EfficiencyBinningSpecificationMC,      
##             EfficiencyCategoryAndState = cms.vstring("probe_passConvRej","pass","probe_isWP60","pass"),
##         ),
##         MCtruth_CicVeryLoose = cms.PSet(
##             EfficiencyBinningSpecificationMC,     
##             EfficiencyCategoryAndState = cms.vstring("probe_passConvRej","pass","probe_isCicVeryLoose","pass"),
##         ),
##         MCtruth_CicLoose = cms.PSet(
##             EfficiencyBinningSpecificationMC,    
##             EfficiencyCategoryAndState = cms.vstring("probe_passConvRej","pass","probe_isCicLoose","pass"),
##         ),
##         MCtruth_CicMedium = cms.PSet(
##             EfficiencyBinningSpecificationMC,    
##             EfficiencyCategoryAndState = cms.vstring("probe_passConvRej","pass","probe_isCicMedium","pass"),
##         ),
##         MCtruth_CicTight = cms.PSet(
##             EfficiencyBinningSpecificationMC,
##             EfficiencyCategoryAndState = cms.vstring("probe_passConvRej","pass","probe_isCicTight","pass"),
##         ),
##         MCtruth_CicSuperTight = cms.PSet(
##             EfficiencyBinningSpecificationMC,    
##             EfficiencyCategoryAndState = cms.vstring("probe_passConvRej","pass","probe_isCicSuperTight","pass"),
##         ),        
##         MCtruth_CicHyperTight1 = cms.PSet(
##             EfficiencyBinningSpecificationMC,    
##             EfficiencyCategoryAndState = cms.vstring("probe_passConvRej","pass","probe_isCicHyperTight1","pass"),
##         ),
##         MCtruth_CicHyperTight2 = cms.PSet(
##             EfficiencyBinningSpecificationMC,    
##             EfficiencyCategoryAndState = cms.vstring("probe_passConvRej","pass","probe_isCicHyperTight2","pass"),
##         ),
##         MCtruth_CicHyperTight3 = cms.PSet(
##             EfficiencyBinningSpecificationMC,    
##             EfficiencyCategoryAndState = cms.vstring("probe_passConvRej","pass","probe_isCicHyperTight3","pass"),
##         ),
##         MCtruth_CicHyperTight4 = cms.PSet(
##             EfficiencyBinningSpecificationMC, 
##             EfficiencyCategoryAndState = cms.vstring("probe_passConvRej","pass","probe_isCicHyperTight4","pass"),
##         ),
        ############################################################################################
    )
)


############################################################################################
############################################################################################
####### SC->GsfElectron efficiency 
############################################################################################
############################################################################################
if isMC:
    EfficienciesPset = cms.PSet(
        efficiency = cms.PSet(
        EfficiencyBinningSpecification,
        EfficiencyCategoryAndState = cms.vstring( "probe_passingGsf", "pass" ),
        ),
        MCtruth_efficiency = cms.PSet(
        EfficiencyBinningSpecificationMC,
        EfficiencyCategoryAndState = cms.vstring( "probe_passingGsf", "pass" ),
        ),
     )
else:
    EfficienciesPset = cms.PSet(
        efficiency = cms.PSet(
        EfficiencyBinningSpecification,
        EfficiencyCategoryAndState = cms.vstring("probe_passingGsf", "pass"),
        ),    
     )
########
process.SCToGsfElectron = process.GsfElectronToId.clone()
process.SCToGsfElectron.InputDirectoryName = cms.string("PhotonToGsfElectron")
process.SCToGsfElectron.OutputFileName = cms.string("efficiency-SCToGsfElectron.root")
process.SCToGsfElectron.Categories = cms.PSet(
    mcTrue = cms.vstring("MC true", "dummy[true=1,false=0]"),           
    probe_passingGsf = cms.vstring("probe_passingGsf", "dummy[pass=1,fail=0]"),                        
    )
process.SCToGsfElectron.Efficiencies = EfficienciesPset





############################################################################################
############################################################################################
####### HLT efficiency 
############################################################################################
############################################################################################
if isMC:
    EfficienciesPset = cms.PSet(
        efficiency = cms.PSet(
        EfficiencyBinningSpecification,
        EfficiencyCategoryAndState = cms.vstring( HLTDef, "pass" ),
        ),
        MCtruth_efficiency = cms.PSet(
        EfficiencyBinningSpecificationMC,
        EfficiencyCategoryAndState = cms.vstring( HLTDef, "pass" ),
        ),
     )
else:
    EfficienciesPset = cms.PSet(
        efficiency = cms.PSet(
        EfficiencyBinningSpecification,
        EfficiencyCategoryAndState = cms.vstring(HLTDef, "pass"),
        ),    
     )
########
process.WP95ToHLT = process.GsfElectronToId.clone()
process.WP95ToHLT.InputDirectoryName = cms.string("WP95ToHLT")
process.WP95ToHLT.OutputFileName = cms.string("efficiency-WP95ToHLT.root")
process.WP95ToHLT.Categories = cms.PSet(
    mcTrue = cms.vstring("MC true", "dummy[true=1,false=0]"),           
    probe_passingHLT = cms.vstring("probe_passingHLT", "dummy[pass=1,fail=0]"),                        
    )
process.WP95ToHLT.Efficiencies = EfficienciesPset
process.WP95ToHLT.Efficiencies.efficiency.BinToPDFmap = cms.vstring()
########  
process.WP90ToHLT = process.WP95ToHLT.clone()
process.WP90ToHLT.InputDirectoryName = cms.string("WP90ToHLT")
process.WP90ToHLT.OutputFileName = cms.string("efficiency-WP90ToHLT.root")
########  
process.WP85ToHLT = process.WP95ToHLT.clone()
process.WP85ToHLT.InputDirectoryName = cms.string("WP85ToHLT")
process.WP85ToHLT.OutputFileName = cms.string("efficiency-WP85ToHLT.root")
########  
process.WP80ToHLT = process.WP95ToHLT.clone()
process.WP80ToHLT.InputDirectoryName = cms.string("WP80ToHLT")
process.WP80ToHLT.OutputFileName = cms.string("efficiency-WP80ToHLT.root")
########  
process.WP70ToHLT = process.WP95ToHLT.clone()
process.WP70ToHLT.InputDirectoryName = cms.string("WP70ToHLT")
process.WP70ToHLT.OutputFileName = cms.string("efficiency-WP70ToHLT.root")
########  
process.WP60ToHLT = process.WP95ToHLT.clone()
process.WP60ToHLT.InputDirectoryName = cms.string("WP60ToHLT")
process.WP60ToHLT.OutputFileName = cms.string("efficiency-WP60ToHLT.root")
########  
process.CicVeryLooseToHLT = process.WP95ToHLT.clone()
process.CicVeryLooseToHLT.InputDirectoryName = cms.string("CicVeryLooseToHLT")
process.CicVeryLooseToHLT.OutputFileName = cms.string("efficiency-CicVeryLooseToHLT.root")
########  
process.CicLooseToHLT = process.WP95ToHLT.clone()
process.CicLooseToHLT.InputDirectoryName = cms.string("CicLooseToHLT")
process.CicLooseToHLT.OutputFileName = cms.string("efficiency-CicLooseToHLT.root")
########  
process.CicMediumToHLT = process.WP95ToHLT.clone()
process.CicMediumToHLT.InputDirectoryName = cms.string("CicMediumToHLT")
process.CicMediumToHLT.OutputFileName = cms.string("efficiency-CicMediumToHLT.root")
########  
process.CicTightToHLT = process.WP95ToHLT.clone()
process.CicTightToHLT.InputDirectoryName = cms.string("CicTightToHLT")
process.CicTightToHLT.OutputFileName = cms.string("efficiency-CicTightToHLT.root")
########  
process.CicSuperTightToHLT = process.WP95ToHLT.clone()
process.CicSuperTightToHLT.InputDirectoryName = cms.string("")
process.CicSuperTightToHLT.OutputFileName = cms.string("efficiency-CicSuperTightToHLT.root")
########  
process.CicHyperTight1ToHLT = process.WP95ToHLT.clone()
process.CicHyperTight1ToHLT.InputDirectoryName = cms.string("CicHyperTight1ToHLT")
process.CicHyperTight1ToHLT.OutputFileName = cms.string("efficiency-CicHyperTight1ToHLT.root")
########  
process.CicHyperTight2ToHLT = process.WP95ToHLT.clone()
process.CicHyperTight2ToHLT.InputDirectoryName = cms.string("CicHyperTight2ToHLT")
process.CicHyperTight2ToHLT.OutputFileName = cms.string("efficiency-CicHyperTight2ToHLT.root")
########  
process.CicHyperTight3ToHLT = process.WP95ToHLT.clone()
process.CicHyperTight3ToHLT.InputDirectoryName = cms.string("")
process.CicHyperTight3ToHLT.OutputFileName = cms.string("efficiency-CicHyperTight3ToHLT.root")
########  
process.CicHyperTight4ToHLT = process.WP95ToHLT.clone()
process.CicHyperTight4ToHLT.InputDirectoryName = cms.string("")
process.CicHyperTight4ToHLT.OutputFileName = cms.string("efficiency-CicHyperTight4ToHLT.root")
########

process.fit = cms.Path(
    process.GsfElectronToId  +
    process.SCToGsfElectron + 
##     process.WP95ToHLT +
##     process.WP90ToHLT +
##     process.WP85ToHLT + 
    process.WP80ToHLT ## +
##     process.WP70ToHLT + 
##     process.WP60ToHLT +
##     process.CicVeryLooseToHLT +
##     process.CicLooseToHLT +
##     process.CicMediumToHLT +
##     process.CicTightToHLT +
##     process.CicSuperTightToHLT +
##     process.CicHyperTight1ToHLT +
##     process.CicHyperTight2ToHLT +
##     process.CicHyperTight3ToHLT +
##     process.CicHyperTight4ToHLT   
    )
