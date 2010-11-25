import sys
import os
from math import sqrt
from optparse import OptionParser

import ROOT

#where the magic happens
def main(options,args):

    obsMax = float(options.obsMax)
    obsMax = float(options.obsMax)
    

    dataChain = ROOT.TChain(options.treeName)
    for dFile in str(options.inputData).split(','):
        print 'Adding: ',dFile
        dataChain.Add(dFile)

    mcChain = ROOT.TChain(options.treeName)
    for mcFile in str(options.inputMC).split(','):
        print 'Adding: ', mcFile
        mcChain.Add(mcFile)

    output = ROOT.TFile.Open(options.workspaceName+'.root','RECREATE')
    
    ws = ROOT.RooWorkspace(options.workspaceName)    

    #ws.Print("v")
    
    setupWorkspace(dataChain,mcChain,ws,output,options)        

    #create -log(likelihood)
    theNLL = ws.pdf('TopLevelPdf').createNLL(ws.data('aTGCDataUnitWeight'),
                                             ROOT.RooFit.NumCPU(2),
                                             ROOT.RooFit.ExternalConstraints(ROOT.RooArgSet(ws.pdf('lumiErr'),
                                                                                            ws.pdf('selectionErr'),
                                                                                            ws.pdf('backgroundErr')))
                                             )
    getattr(ws,'import')(theNLL)
                                            
    minuit = ROOT.RooMinuit(theNLL)
        
    #find the values of the errors that minimize the likelihood
    minuit.setStrategy(2)
    minuit.hesse()
    minuit.migrad()    

    #ws.var('err_x_gl').setConstant(True)
    #ws.var('err_x_gs').setConstant(True)
    #ws.var('err_x_gb').setConstant(True)

    ws.defineSet('POI',
                 ROOT.RooArgSet(ws.var(options.couplingType+'_'+options.par1Name),
                                ws.var(options.couplingType+'_'+options.par2Name)))

    h3_best = ROOT.RooRealVar(ws.var(options.couplingType+'_'+options.par1Name),options.couplingType+' '+options.par1Name)
    h4_best = ROOT.RooRealVar(ws.var(options.couplingType+'_'+options.par2Name),options.couplingType+'_'+options.par2Name)
    ROOT.RooArgSet(ROOT.RooArgSet(h3_best,h4_best))
    
    nll_fit_result = minuit.save(options.couplingType+'_NLL_fitResult')
        
    #create profile likelihood    
    profileLL = theNLL.createProfile(ws.set('POI'))
    profileLL.getVal() # to cache the values of the constrained params

    level_68 = ROOT.TMath.ChisquareQuantile(.68,2)/2.0 # delta NLL for 68% confidence level for -log(LR)
    level_95 = ROOT.TMath.ChisquareQuantile(.95,2)/2.0 # delta NLL for 95% confidence level for -log(LR)

    print '68% CL Delta-NLL=',level_68
    print '95% CL Delta-NLL=',level_95

    profMinuit = profileLL.minuit()
    profMinuit.setStrategy(2)
    profMinuit.setPrintLevel(1)

    profMinuit.migrad()
    profMinuit.minos(ws.set('POI'))

    thePlot = profMinuit.contour(ws.var(options.couplingType+'_'+options.par1Name),
                                 ws.var(options.couplingType+'_'+options.par2Name),
                                 sqrt(2*level_68),sqrt(2*level_95))

    theCanvas = ROOT.TCanvas('contours','',500,500)
    
    thePlot.SetTitle('68% & 95% CL on the Best Fit Values of '+options.par1Name+' and '+options.par2Name)
    thePlot.Draw()

    theCanvas.Print(options.workspaceName+'_contour.root')
    
    #theLHInterval = ROOT.RooStats.LikelihoodInterval('profLikelihoodInterval',
    #                                                 profileLL,
    #                                                 ws.set('POI'),
    #                                                 ws.set('POI_snapshot'))
    #theLHInterval.SetConfidenceLevel(.05) #95% confidence interval, 1-alpha, alpha is passed
    
    #getattr(ws,'import')(theLHInterval) !! likelihood interval not persistable !!
    

    #create the interval plotter, set POI's, ranges
    #theLHplot = ROOT.RooStats.LikelihoodIntervalPlot(theLHInterval)
    #theLHplot.SetPlotParameters(ws.set('POI'))
    #theLHplot.SetRange(-h3Max,-h4Max,
    #                   h3Max,h4Max)
    #LikelihoodPlot isn't persistable either....
    

    #makePlots(theLHplot,options)

    #ws.Print("v")

    ws.Write()
    output.Close()
    
    #really, that's all I had to do??


def setupWorkspace(dataTree,mcTree,ws,output,options):
    # explanation forthcoming...

    nObsBins = int(options.nObsBins)
    obsMin = float(options.obsMin)
    obsMax = float(options.obsMax)
        
    if not isinstance(ws,ROOT.RooWorkspace):
        print "You didn't pass a RooWorkspace!"
        exit(1)

    obs = ROOT.RooRealVar(options.obsVar,'The Observable',obsMin,obsMax) #observable
    obs.setBins(int(options.nObsBins))
    par1 = ROOT.RooRealVar(options.couplingType+'_'+options.par1Name,
                         options.par1Name+'_{'+options.couplingType+'}',
                         -float(options.par1Max),
                         float(options.par1Max)) #parameter
    
    par2 = ROOT.RooRealVar(options.couplingType+'_'+options.par2Name,
                         options.par2Name+'_{'+options.couplingType+'}',
                         -float(options.par2Max),
                         float(options.par2Max)) #parameter
    #acc = ROOT.RooRealVar('acceptance','The acceptance in this pT bin',0)
    #acc_err = ROOT.RooRealVar('acceptance_error','The error on the accpetance in the pT bin',0) 

    evSelErr = ROOT.RooRealVar('eventSelectionError',
                               'Fractional Error on the MC event selection',
                               sqrt(.02*.02 + .02*.02 + .15*.15)) #acceptance error + XS err + 15%
    bkgErr = ROOT.RooRealVar('backgroundError',
                             'Fractional Error on the expected number of background events',
                             .1) # fix background error to be 10% for now
    lumiErr = ROOT.RooRealVar('luminosityError',
                              'Fractional Error on the luminosity',
                              .1) #fix lumi error to 10%    
    
    #start hack to always make last bin include overflow
    aTGCObsHist = ROOT.TH1F('aTGCObsHist',
                            'Histogram Containing the pt Spectrum',
                            nObsBins,
                            obsMin,obsMax) # because including overflow bins in roofit sucks, alot...
    
    dataTree.Draw(options.obsVar+' >> aTGCObsHist','','goff')

    lastBin = aTGCObsHist.GetBinContent(nObsBins) + aTGCObsHist.GetBinContent(nObsBins+1)
    lastBinError = sqrt(aTGCObsHist.GetBinError(nObsBins)*aTGCObsHist.GetBinError(nObsBins) +
                        aTGCObsHist.GetBinError(nObsBins+1)*aTGCObsHist.GetBinError(nObsBins+1))

    for i in range(nObsBins-1):
        aTGCObsHist.SetBinError(i+1,sqrt(aTGCObsHist.GetBinContent(i+1)))

    aTGCObsHist.SetBinContent(nObsBins,lastBin)
    aTGCObsHist.SetBinError(nObsBins,lastBinError)

    aTGCObsHist.Write()
    #end hack to make last bin include overflow

    aTGCData = ROOT.RooDataHist('aTGCData',
                                'Photon E_{T} Spectrum from Data',
                                ROOT.RooArgList(obs),aTGCObsHist)

    #Ok, this does look a little insane but what we want as our actual dataset
    #is each pT bin with unit weight and a poisson assigned to it
    #with some expectation... We do this to fake out RooFit.

    aTGCDataUnitWeight = ROOT.RooDataHist(aTGCData,'aTGCDataUnitWeight')

    aTGCDataUnitWeight.reset()

    for i in range(nObsBins):
        aTGCDataUnitWeight.get(i)
        aTGCDataUnitWeight.set(1.0)

    aTGCData.createHistogram('dataHist',obs).Write()
    
    getattr(ws,'import')(aTGCData)
    getattr(ws,'import')(aTGCDataUnitWeight)
    getattr(ws,'import')(obs)    
    getattr(ws,'import')(par1)
    getattr(ws,'import')(par2)
    #getattr(ws,'import')(acc)
    #getattr(ws,'import')(acc_err)    
    getattr(ws,'import')(evSelErr)
    getattr(ws,'import')(bkgErr)
    getattr(ws,'import')(lumiErr)
    #getattr(ws,'import')(aRow)

    #get the fitted polynomial coefficients from the 3x3 grid info
    (c,p_0,p_1,p_2,p_3,p_4) = fitATGCExpectedYields(ws,mcTree,options) #returns roodatahist describing polynomial terms in bins of pT :-D

    getattr(ws,'import')(c)
    getattr(ws,'import')(p_0)
    getattr(ws,'import')(p_1)
    getattr(ws,'import')(p_2)
    getattr(ws,'import')(p_3)
    getattr(ws,'import')(p_4)

    ws.var(options.obsVar).setVal(1.5*(obsMax-obsMin)/nObsBins)

    #set up functiont the returns number of observed signal
    nObserved = ROOT.RooHistFunc('nObserved','Number of Observed Events in Data',
                                 ROOT.RooArgSet(obs),ws.data('aTGCData'))
    getattr(ws,'import')(nObserved)

    ws.function('nObserved').Print()

    #set up the signal expectation description
    #this needs a little care, they *are* nuisance parameters but I don't yet have a way of saving this info
    #since I use RooHistFunc.... hmmm
    polyC = ROOT.RooHistFunc('polyC',
                             'Constant Term for aTGC polynomial description',
                             ROOT.RooArgSet(obs),ws.data('c_bin_pt'))
    polyP_0 = ROOT.RooHistFunc('polyP_0',
                               'Linear par1 Term for aTGC polynomial description',
                               ROOT.RooArgSet(obs),ws.data('p0_bin_pt'))
    polyP_1 = ROOT.RooHistFunc('polyP_1',
                               'Linear par2 Term for aTGC polynomial description',
                               ROOT.RooArgSet(obs),ws.data('p1_bin_pt'))
    polyP_2 = ROOT.RooHistFunc('polyP_2',
                               'par1*par2 Term for aTGC polynomial description',
                               ROOT.RooArgSet(obs),ws.data('p2_bin_pt'))
    polyP_3 = ROOT.RooHistFunc('polyP_3',
                               'Quadratic par1 Term for aTGC polynomial description',
                               ROOT.RooArgSet(obs),ws.data('p3_bin_pt'))
    polyP_4 = ROOT.RooHistFunc('polyP_4',
                               'Quadratic par2 Term for aTGC polynomial description',
                               ROOT.RooArgSet(obs),ws.data('p4_bin_pt'))
    nExpectedSignal = ROOT.RooFormulaVar('nExpectedSignal','The expected number of signal events in (h3,h4) in bins',
                                         '(@3(@0) + @4(@0)*@1 + @5(@0)*@2 + @6(@0)*@1*@2 + @7(@0)*@1*@1 + @8(@0)*@2*@2)',
                                         ROOT.RooArgList(obs,par1,par2,polyC,polyP_0,polyP_1,polyP_2,polyP_3,polyP_4))
    #getattr(ws,'import')(polyC)
    #getattr(ws,'import')(polyP_0)
    #getattr(ws,'import')(polyP_1)
    #getattr(ws,'import')(polyP_2)
    #getattr(ws,'import')(polyP_3)
    #getattr(ws,'import')(polyP_4)
    getattr(ws,'import')(nExpectedSignal)    

    ws.function('nExpectedSignal').Print()

    #build nExpectedBackground RooHistFunc
    bkg = loadBackgroundHist(ws,output,options)
    getattr(ws,'import')(bkg)
    
    nExpectedBackground = ROOT.RooHistFunc('nExpectedBackground','Number of expected background in bins of pT',
                                           ROOT.RooArgSet(obs),ws.data('bkgShape'))
    getattr(ws,'import')(nExpectedBackground)

    ws.function('nExpectedBackground').Print()

    #finally make the pdf
    makeATGCExpectationPdf(ws,options)
        
def fitATGCExpectedYields(ws,mcChain,options):

    nObsBins = int(options.nObsBins)
    obsMin = float(options.obsMin)
    obsMax = float(options.obsMax)
    nGridParBins = int(options.nGridParBins)
    par1GridMax = float(options.par1GridMax)
    par2GridMax = float(options.par2GridMax)
    par1PadSize = 2*par1GridMax/(nGridParBins+1)
    par2PadSize = 2*par2GridMax/(nGridParBins+1)
    par1GridMax = par1GridMax + par1PadSize #add padding to put values at bin centers, assuming evently spaced points
    par2GridMax = par2GridMax + par2PadSize
    
    #create the variables for the nxn grid, doesn't go in the workspace
    obs_mc = ROOT.RooRealVar(ws.var(options.obsVar),options.obsVar)
    #h3_3x3 and h4_3x3 do not go in the workspace
    #figure out how to determine binning on the fly.... can probably do by finding max h3,h4 in tree + info that we have 9 bins
    par1_grid = ROOT.RooRealVar(options.par1Name+'_grid',
                               'temp par1 to extrapolate grid',
                               -par1GridMax,
                               par1GridMax) #above calulation should put grid values in bin centers
    par1_grid.setBins(nGridParBins)
    par2_grid = ROOT.RooRealVar(options.par2Name+'_grid',
                               'temp par2 to extrapolate grid',
                               -par2GridMax,
                               par2GridMax) # same
    par2_grid.setBins(nGridParBins)
    weight = ROOT.RooRealVar('weight','the weight of the data',0,1000)

    binSize = (obsMax-obsMin)/nObsBins

    hc = ROOT.TH1F('hc','const term',nObsBins,obsMin,obsMax)
    hp0 = ROOT.TH1F('hp0','h3 linear term',nObsBins,obsMin,obsMax)
    hp1 = ROOT.TH1F('hp1','h4 linear term',nObsBins,obsMin,obsMax)
    hp2 = ROOT.TH1F('hp2','h3h4 cross term',nObsBins,obsMin,obsMax)
    hp3 = ROOT.TH1F('hp3','h3 quadratic term',nObsBins,obsMin,obsMax)
    hp4 = ROOT.TH1F('hp4','h4 quadratic term',nObsBins,obsMin,obsMax)

    for i in range(nObsBins):
        binMin = obsMin+i*binSize
        binMax = binMin + binSize

        theBaseData = ROOT.TH2F('theBaseData_'+str(i),'Base Histogram for RooDataHist',
                                3,par1_grid.getMin(),par1_grid.getMax(),
                                3,par2_grid.getMin(),par2_grid.getMax())
                
        if i == (nObsBins - 1):
            print obs_mc.GetName(),' > ',str(binMin)
            mcChain.Draw(options.par2Name+'_grid:'+options.par1Name+'_grid >> theBaseData_'+str(i),
                         'weight*('+obs_mc.GetName() +
                         ' > ' + str(binMin)+')','goff')
        else:
            print obs_mc.GetName(),' > ',str(binMin),' && ',obs_mc.GetName(),' < ',str(binMax)
            mcChain.Draw(options.par2Name+'_grid:'+options.par1Name+'_grid >> theBaseData_'+str(i),
                         'weight*('+obs_mc.GetName() +
                         ' > ' + str(binMin) +
                         ' && ' + obs_mc.GetName() +
                         ' < ' + str(binMax)+')','goff')

        

        #for k in range(1,nObsBins):
        #    for j in range(1,nObsBins):
        #        theBaseData.SetBinError(k,j,.3e-3)        

        func = ROOT.TF2('fittingFunction'+str(i),'[0] + [1]*x + [2]*y + [3]*x*y + [4]*x*x + [5]*y*y',
                        par1_grid.getMin(),par1_grid.getMax(),
                        par2_grid.getMin(),par2_grid.getMax())

        theBaseData.Fit(func,'R','NODRAW')

        theBaseData.Write()
        
        #theBaseData.Write()
        #hist.Write()
        
        hc.SetBinContent(i+1,func.GetParameter(0))
        hc.SetBinError(i+1,func.GetParError(0))
        hp0.SetBinContent(i+1,func.GetParameter(1))
        hp0.SetBinError(i+1,func.GetParError(1))
        hp1.SetBinContent(i+1,func.GetParameter(2))
        hp1.SetBinError(i+1,func.GetParError(2))
        hp2.SetBinContent(i+1,func.GetParameter(3))
        hp2.SetBinError(i+1,func.GetParError(3))
        hp3.SetBinContent(i+1,func.GetParameter(4))
        hp3.SetBinError(i+1,func.GetParError(4))
        hp4.SetBinContent(i+1,func.GetParameter(5))
        hp4.SetBinError(i+1,func.GetParError(5))


    hc.Write()
    hp0.Write()
    hp1.Write()
    hp2.Write()
    hp3.Write()
    hp4.Write()
    
    getattr(ws,'import')(hc)
    getattr(ws,'import')(hp0)
    getattr(ws,'import')(hp1)
    getattr(ws,'import')(hp2)
    getattr(ws,'import')(hp3)
    getattr(ws,'import')(hp4)

    #note that here we change the variable of the histogram to the main photon eT!!
    c = ROOT.RooDataHist('c_bin_pt','Constant Term for Each Bin',
                         ROOT.RooArgList(ws.var(options.obsVar)),hc)
    p0 = ROOT.RooDataHist('p0_bin_pt','h3 Linear Term for Each Bin',
                          ROOT.RooArgList(ws.var(options.obsVar)),hp0)
    p1 = ROOT.RooDataHist('p1_bin_pt','h4 Linear Term for Each Bin',
                          ROOT.RooArgList(ws.var(options.obsVar)),hp1)
    p2 = ROOT.RooDataHist('p2_bin_pt','h3h4 Cross Term for Each Bin',
                          ROOT.RooArgList(ws.var(options.obsVar)),hp2)
    p3 = ROOT.RooDataHist('p3_bin_pt','h3 Quadratic Term for Each Bin',
                          ROOT.RooArgList(ws.var(options.obsVar)),hp3)
    p4 = ROOT.RooDataHist('p4_bin_pt','h4 Quadratic Term for Each Bin',
                          ROOT.RooArgList(ws.var(options.obsVar)),hp4)
    
    return c,p0,p1,p2,p3,p4

def loadBackgroundHist(ws,output,options):

    nObsBins = int(options.nObsBins)
    obsMin = float(options.obsMin)
    obsMax = float(options.obsMax)
    binSize = (obsMax-obsMin)/nObsBins
    
    bkgFile = ROOT.TFile.Open(options.bkgFile)
    bkgData = None 

    if isinstance(bkgFile.Get(options.treeName),ROOT.TH1F):
        print 'Background Data Given as TH1F!'
        inpHist = bkgFile.Get(options.treeName)

        output.cd()
        
        bkgHist = ROOT.TH1F('bkgHist','Background Shape',nObsBins,obsMin,obsMax)

        for bin in range(inpHist.GetNbinsX()):
            if bkgHist.GetBinWidth(bin+1) != binSize:
                print 'Bin sizes not the same!!'
                exit(1)
            
            if not bin+1 > inpHist.GetNbinsX():
                bkgHist.SetBinContent(bin+1,inpHist.GetBinContent(bin+1))
                bkgHist.SetBinError(bin+1,inpHist.GetBinError(bin+1))
            else:
                total = bkgHist.GetBinContent(bkgHist.GetNbinsX()) + inpHist.GetBinContent(bin+1)
                tot_err = sqrt(bkgHist.GetBinError(bkgHist.GetNbinsX())**2 + inpHist.GetBinError(bin+1)**2)
                bkgHist.SetBinContent(bkgHist.GetNbinsX(),total)
                bkgHist.SetBinError(bkgHist.GetNbinsX(),tot_err)
        
        

        bkgHist.Write()

        getattr(ws,'import')(bkgHist)

        bkgData = ROOT.RooDataHist('bkgShape','The shape of the background in photon eT',
                                   ROOT.RooArgList(ws.var(options.obsVar)),
                                   bkgHist)
                                   
        
    elif isinstance(bkgFile.Get(options.treeName),ROOT.TTree):
        print 'Background Data Given as TTree!'
        temp = bkgFile.Get(options.treeName)       

        bkgHist = ROOT.TH1F('bkgHist','Background Shape',nObsBins,obsMin,obsMax)

        if(options.MCbackground):
            temp.Draw(options.obsVar+' >> bkgHist','weight','goff')
        else:
            temp.Draw(options.obsVar+' >> bkgHist','','goff')

        output.cd()

        lastBin = bkgHist.GetBinContent(nObsBins) + bkgHist.GetBinContent(nObsBins+1)
        lastBinError = sqrt(bkgHist.GetBinError(nObsBins)*bkgHist.GetBinError(nObsBins) +
                            bkgHist.GetBinError(nObsBins+1)*bkgHist.GetBinError(nObsBins+1))
        
        bkgHist.SetBinContent(nObsBins,lastBin)
        bkgHist.SetBinError(nObsBins,lastBinError)

        bkgHist.Write()

        getattr(ws,'import')(bkgHist)

        bkgData = ROOT.RooDataHist('bkgShape','The shape of the background in photon eT',
                                   ROOT.RooArgList(ws.var(options.obsVar)),
                                   bkgHist)

        bkgData.Print()
        
    else:
        print 'Data given in invalid format! Aborting!'
        exit(1)

        bkgFile.Close()
    
    return bkgData

#define the PDF that defines the likelihood
def makeATGCExpectationPdf(ws,options):
    if not isinstance(ws,ROOT.RooWorkspace):
        print "You didn't pass a RooWorkspace!"
        exit(1)

    #nuisance parameters
    x_gs = ROOT.RooRealVar('err_x_gs','Range for Selection Error',1,
                           1-4*ws.var('eventSelectionError').getVal(),
                           1+4*ws.var('eventSelectionError').getVal())
    x_gb = ROOT.RooRealVar('err_x_gb','Range for Background Error',1,
                           1-4*ws.var('backgroundError').getVal(),
                           1+4*ws.var('backgroundError').getVal())
    x_gl = ROOT.RooRealVar('err_x_gl','Range for Lumi Error',1,
                           1-4*ws.var('luminosityError').getVal(),
                           1+4*ws.var('luminosityError').getVal())
    
    getattr(ws,'import')(x_gs)
    getattr(ws,'import')(x_gb)
    getattr(ws,'import')(x_gl)
    
    #define the Gaussians for the errors
    ws.factory("RooGaussian::selectionErr(err_x_gs,1,eventSelectionError)")
    ws.factory("RooGaussian::backgroundErr(err_x_gb,1,backgroundError)")
    ws.factory("RooGaussian::lumiErr(err_x_gl,1,luminosityError)")

    ws.factory('prod::sigExp(nExpectedSignal,err_x_gl,err_x_gs)') #
    ws.factory('prod::bkgExp(nExpectedBackground,err_x_gb)') #
    ws.factory('sum::expected(sigExp,bkgExp)')
    
    #now we create the core poisson pdf with errors left as floating
    ws.factory("RooPoisson::corePoisson(nObserved,expected)")    
    #now we create the top level pdf, which will be evaluated at each pT bin to create the likelihood.
    ws.factory('PROD::TopLevelPdf(corePoisson)')  #
    

def makePlots(LLplot,options):
    print "not done yet"
    theCanvas = ROOT.TCanvas("Likelihood Plot")
    LLplot.Draw("tf1")
    theCanvas.Print("contour.root")
    

if __name__ == "__main__":
    parser = OptionParser(description="%prog : A RooStats Implementation of Anomalous Triple Gauge Coupling Analysis.",
                          usage="aTGCRooStats --intLumi=TheLumi --lumiErr=Err")
    parser.add_option("--workspaceName",dest="workspaceName",help="The name of your RooWorkspace")
    parser.add_option("--backgroundFile",dest="bkgFile",help="The path to the file containing the estimated background in each bin.")
    parser.add_option("--intLumi",dest="intLumi",help="Integrated luminosity.")
    parser.add_option("--lumiErr",dest="lumiErr",help="Integrated luminosity fractional error.")

    #parameters of the observable
    parser.add_option("--obsVar",dest="obsVar",help="Name of the observable variable in the input trees.")
    parser.add_option("--nObsBins",dest="nObsBins",help="Number of uniform bins in the observable.")
    parser.add_option("--obsMin",dest="obsMin",help="Minimum of the observable.")
    parser.add_option("--obsMax",dest="obsMax",help="Maximum of the observable (last bin contains overflow).")

    #parameters of the aTGCs
    parser.add_option("--par1Name",dest="par1Name",help="Name of aTGC Parameter 1")
    parser.add_option("--par2Name",dest="par2Name",help="Name of aTGC Parameter 2")
    parser.add_option("--par1Max",dest="par1Max",help="Bound on |aTGC 1|")
    parser.add_option("--par2Max",dest="par2Max",help="Bound on |aTGC 2|")

    #definitions for MC grid of aTGCs (assumed to be a fully populated square grid, that is symmetric about zero)
    parser.add_option("--nGridParBins",dest="nGridParBins",help="Number of Bins of one side of the input parameter grid.")
    parser.add_option("--par1GridMax",dest="par1GridMax",help="Max of |par1| in the input grid.")
    parser.add_option("--par2GridMax",dest="par2GridMax",help="Max of |par2| in the input grid.")
    
    parser.add_option("--treeName",dest="treeName",help="Name of the TTree, assumed to be the same between all input samples.")
    parser.add_option("--inputData",dest="inputData",help="Name of input data file. Multiple files given in comma separated list.")
    parser.add_option("--inputMC",dest="inputMC",help="Name of input MC file used to extract quadratic dependence of shapes. Multiple files in comma separated list.")
    parser.add_option("--couplingType",dest="couplingType",help="Name of the coupling (i.e. ZZg, Zgg, WWg, etc.")
    parser.add_option("--MCbackground",dest="MCbackground",help="Is background from MC?",action="store_true")
    (options,args) = parser.parse_args()

    miss_options = False

    if options.workspaceName is None:
        print 'Need to specify --workspaceName'
        miss_options=True
    if options.bkgFile is None:
        print 'Need to specify --backgroundFile'
        miss_options=True
    if options.inputData is None:
        print 'Need to specify --inputData'
        miss_options=True
    if options.inputMC is None:
        print 'Need to specify --inputMC'
        miss_options=True
    if options.couplingType is None:
        print 'Need to specify --couplingType (ZZg, Zgg, WWg, etc..)'
        miss_options=True
        
    if options.obsVar is None:
        print 'Need to specify --obsVar'
        miss_options=True
    if options.obsMin is None:
        print 'Need to specify --obsMin'
        miss_options=True
    if options.obsMax is None:
        print 'Need to specify --obsMax'
        miss_options=True
    if options.nObsBins is None:
        print 'Need to specify --nObsBins'
        miss_options=True

    if options.par1Name is None:
        print 'Need to specify --par1Name'
        miss_options=True
    if options.par2Name is None:
        print 'Need to specify --par2Name'
        miss_options=True
    if options.par1Max is None:
        print 'Need to specify --par1Max'
        miss_options=True
    if options.par2Max is None:
        print 'Need to specify --par2Max'
        miss_options=True

    if options.nGridParBins is None:
        print 'Need to specify --nGridParBins'
        miss_options=True
    if options.par1GridMax is None:
        print 'Need to specify --par1GridMax'
        miss_options=True
    if options.par2GridMax is None:
        print 'Need to specify --par2GridMax'
        miss_options=True
        
    if options.treeName is None:
        print 'Need to specify --treeName'
        miss_options=True
    if options.intLumi is None:
        print 'Need to specify --intLumi'
        miss_options=True
    if options.lumiErr is None:
        print 'Need to specify --lumiErr'
        miss_options=True

    if miss_options:
        exit(1)

    main(options,args)
