#include "RooRealVar.h"
#include "RooRealConstant.h"
#include "RooGaussian.h"
#include "RooExponential.h"
#include "RooAddPdf.h"
#include "RooAddition.h"
#include "RooDataSet.h"
#include "RooDataHist.h"
#include "RooHistPdf.h"
#include "RooChebychev.h"
#include "RooExponential.h"
#include "RooProdPdf.h"
#include "RooChi2Var.h"
#include "RooGlobalFunc.h" 
#include "RooPlot.h"
#include "RooMinuit.h"
#include "RooFitResult.h"
#include "RooFormulaVar.h"
#include "RooGenericPdf.h"
#include "RooExtendPdf.h"
#include "TCanvas.h"
#include "TROOT.h"
#include "TFile.h"
#include "TH1.h"
#include "RooMCStudy.h"
#include "RooRandom.h"
#include <iostream>
#include <fstream>
#include <boost/program_options.hpp>
using namespace boost;
namespace po = boost::program_options;
#include <vector>

using namespace RooFit;

// A function that get histogram, restricting it on fit range  and sets contents to 0.01 if entries are too small


TH1F * getHisto(TFile * file, const char * name, double fMin, double fMax, unsigned int rebin) {
  TObject * h = file->Get(name);
  if(h == 0)
    cout  << "Can't find object " << name << "\n";
  TH1F * histo = dynamic_cast<TH1F*>(h);
  if(histo == 0)
    cout << "Object " << name << " is of type " << h->ClassName() << ", not TH1\n";
  TH1F * new_histo = new TH1F(name, name, (int) (fMax-fMin), fMin, fMax);
  int bin_num=0;
  for (int i = (int)fMin; i <= (int)fMax; ++i ) {
    bin_num= (i - (int)fMin + 1);  
    new_histo->SetBinContent( bin_num, histo->GetBinContent(i) );				    
  } 
  delete histo;
  new_histo->Rebin(rebin);
  for(int i = 1; i <= new_histo->GetNbinsX(); ++i) {
    if(new_histo->GetBinContent(i) == 0.00) {
      cout<< " WARNING: histo " << name << " has 0 enter in bin number " << i << endl;   
    }
  }
  return new_histo;
}

// a function that create fromm a model pdf a toy RooDataHist

RooDataHist * genHistFromModelPdf(const char * name, RooAbsPdf *model,  RooRealVar *var,    double ScaleLumi,  int rebin ) {
  double genEvents =  ScaleLumi * model->expectedEvents(*var);
  RooDataSet * data = model->generate(*var ,   (int)genEvents ,    Extended(kTRUE) );
  cout<< " data->numEntries() for name " << name << " == " << data->numEntries()<< endl;
  double integ = model->expectedEvents(*var);
  cout<< " expected events for " << name << " = "<< integ << endl; 
  RooAbsData *binned_data = data->binnedClone();
  TH1 * toy_hist = binned_data->createHistogram( name, *var, Binning(rebin)  );
  RooDataHist * toy_rooHist = new RooDataHist(name, name , RooArgList(*var), toy_hist );
  return toy_rooHist; 
}


// a function to create the pdf used for the fit, need the histo model, should be zmm except for zmusta case..... 

RooHistPdf * createHistPdf( const char * name, TH1F *model,  RooRealVar *var,  int rebin){
  TH1F * model_clone = new TH1F(*model);
  model_clone-> Rebin( rebin ); 
  RooDataHist * model_dataHist = new RooDataHist(name, name , RooArgList(*var), model_clone ); 
  RooHistPdf * HistPdf = new RooHistPdf(name, name, *var, *model_dataHist,  0);
  return HistPdf;
}



void fit( RooAbsReal & chi2, int numberOfBins, const char * outFileNameWithFitResult ){
  TFile * out_root_file = new TFile(outFileNameWithFitResult , "recreate");
  RooMinuit m_tot(chi2) ;
  m_tot.migrad();
  // m_tot.hesse();
  RooFitResult* r_chi2 = m_tot.save() ;
  cout << "==> Chi2 Fit results " << endl ;
  r_chi2->Print("v") ;
  r_chi2->floatParsFinal().Print("s") ;
  int NumberOfFreeParameters =  r_chi2->floatParsFinal().getSize() ;
  cout<<"Normalized Chi2  = " << chi2.getVal()/ (numberOfBins - NumberOfFreeParameters)<<endl; 
  r_chi2->Write( ) ;
  delete out_root_file;
}


int main(int argc, char** argv){
  gROOT->SetStyle("Plain");
  double fMin , fMax,  lumi, scaleLumi =1;
  int seed;
  Bool_t toy = kFALSE;
  Bool_t  fitFromData = kFALSE;
  string  infile, outfile;
  int rebinZMuMu =1, rebinZMuSa = 1,   rebinZMuTk = 1,  rebinZMuMuNoIso=1,  rebinZMuMuHlt =  1; 
  po::options_description desc("Allowed options");
  desc.add_options()
    ("help,h", "produce help message")
    ("toy,t", "toy enabled")
    ("seed,s", po::value<int>(&seed)->default_value(34567), "seed value for toy")
    ("luminosity,l", po::value<double>(&lumi)->default_value(45.), "luminosity value for toy ")
    ("fit,f", "fit from data enabled")
    ("rebin,r", po::value< vector<int> > (), "rebin value: r_mutrk r mumuNotIso r_musa r _muhlt")
    ("input-file,i", po::value< string> (&infile), "input file")
    ("output-file,o", po::value< string> (&outfile), "output file with fit results")
    ("min,m", po::value<double>(&fMin)->default_value(60), "minimum value for fit range")
    ("max,M", po::value<double>(&fMax)->default_value(120), "maximum value for fit range");
  po::positional_options_description p;
  p.add("rebin", -1);
  po::variables_map vm;
  po::store(po::command_line_parser(argc, argv).
	    options(desc).positional(p).run(), vm);
  po::notify(vm);
  if (vm.count("help")) {
    cout << "Usage: options_description [options]\n";
    cout << desc;
      return 0;
  }      

  if (vm.count("toy")) {
    cout << "toy enabled with seed " << seed << "\n";
    toy = kTRUE;
    RooRandom::randomGenerator()->SetSeed(seed); 
    // lumi should be intented as pb-1 and passed from outside
    scaleLumi=  lumi / 45.0 ; // 45 is the current lumi correspondent to the histogram.....
  }      
    if (vm.count("fit")) {
      cout << "fit from data enabled \n";
      fitFromData = kTRUE;
    }      
    
    if (!vm.count("toy") && !vm.count("fit")) {
      cerr << "Choose one beetween  fitting form data or with a toy MC \n";
      return 1;
    }      

    if ( toy == fitFromData ){
      cerr << "Choose if fit from data or with a toy MC \n";
      return 1;
    }
  
    if (vm.count("rebin") ) {
      vector<int> v_rebin = vm["rebin"].as< vector<int> >();
      if (v_rebin.size()!=4){
	cerr << " please provide 4 numbers in the given order:r_mutrk r mumuNotIso r_musa r _muhlt \n";
	return 1;
      }
      rebinZMuTk = v_rebin[0];  rebinZMuMuNoIso=v_rebin[1];   rebinZMuSa = v_rebin[2];rebinZMuMuHlt = v_rebin[3]; 
      
    }

    RooRealVar * mass = new RooRealVar("mass", "mass (GeV)", fMin, fMax );
    TFile * root_file = new TFile(infile.c_str(), "read");
    int range = (int)(fMax - fMin);
    int numberOfBins = range/rebinZMuSa  + range/rebinZMuTk + range/rebinZMuMuNoIso + 2* range/rebinZMuMuHlt ;
    // zmm histograms used for pdf 
    TH1F * zmm = getHisto(root_file, "goodZToMuMuPlots/zMass",fMin, fMax, rebinZMuMu );  
    // zmsta used for pdf
    TH1F *zmsta = getHisto(root_file, "zmumuSaMassHistogram/zMass",fMin, fMax, 1);  // histogramms to fit.....
    TH1F *zmmsta = getHisto(root_file, "goodZToMuMuOneStandAloneMuonPlots/zMass",fMin, fMax,  rebinZMuSa/rebinZMuMu);  
    TH1F *zmt = getHisto(root_file, "goodZToMuMuOneTrackPlots/zMass", fMin, fMax, rebinZMuTk / rebinZMuMu);  
    TH1F *zmmNotIso = getHisto(root_file,"nonIsolatedZToMuMuPlots/zMass",  fMin, fMax, rebinZMuMuNoIso / rebinZMuMu); 
    TH1F *zmm1hlt = getHisto(root_file, "goodZToMuMu1HLTPlots/zMass", fMin, fMax, rebinZMuMuHlt / rebinZMuMu);   
    TH1F *zmm2hlt = getHisto(root_file, "goodZToMuMu2HLTPlots/zMass", fMin, fMax, rebinZMuMuHlt / rebinZMuMu);   
    
    // creating a pdf for Zmt
    
    RooHistPdf * ZmtPdf = createHistPdf( "ZmtPdf", zmm, mass, rebinZMuTk/ rebinZMuMu  );
    // creating a pdf for Zmm not iso
    RooHistPdf * ZmmNoIsoPdf = createHistPdf( "ZmmNoIsoPdf", zmm, mass, rebinZMuMuNoIso/ rebinZMuMu   );
    // creating a pdf for Zms from zmsta!!!
    RooHistPdf * ZmsPdf = createHistPdf( "ZmsPdf", zmsta, mass, rebinZMuSa/ rebinZMuMu  );
    // creating a pdf for Zmmhlt
    RooHistPdf * ZmmHltPdf = createHistPdf( "ZmmHltPdf", zmm, mass, rebinZMuMuHlt/ rebinZMuMu  );
    
    // creating the variable with random init values
    
    RooRealVar Yield("Yield","Yield", 15000.,345.,3567890.)  ;
    RooRealVar nbkg_mutrk("nbkg_mutrk","background _mutrk fraction",500,0.,100000.) ; 
    RooRealVar nbkg_mumuNotIso("nbkg_mumuNotIso","background fraction",500,0.,100000.) ;
    RooRealVar eff_tk("eff_tk","signal _mutrk fraction",.99,0.8,1.0) ;
    RooRealVar eff_sa("eff_sa","eff musta",0.99,0.8,1.0) ;
    RooRealVar eff_iso("eff_iso","eff mumuNotIso",.99,0.8,1.0) ;
    RooRealVar eff_hlt("eff_hlt","eff 1hlt",0.99, 0.8,1.0) ;
    RooRealVar alpha  ("alpha","coefficient alpha", -0.01 , -1., 0.) ;
    RooRealVar a0 ("a0","coefficient 0", 1,0.,2.) ;
    RooRealVar a1 ("a1","coefficient 1", -0.001,-100,100.) ;
    RooRealVar a2 ("a2","coefficient 2", 0.0,-100.,100.) ;
    RooRealVar beta ("beta","coefficient beta", -0.01,-1.0 , 0. ) ;
    RooRealVar b0 ("b0","coefficient 0", 1,0.,2.) ;
    RooRealVar b1 ("b1","coefficient 1", -0.001,-100,100.) ;
    RooRealVar b2("b2","coefficient 2", 0.0,-100.,100.) ;
    
    // fit parameters setted from datacard 
    filebuf fb;
    fb.open ("zMuMuRooFit.txt",ios::in);
    istream is(&fb);
    char line[1000];
    
    Yield.readFromStream(is.getline(line, 1000), kFALSE);  
    nbkg_mutrk.readFromStream(is.getline(line,1000), kFALSE);
    nbkg_mumuNotIso.readFromStream(is.getline(line,1000),  kFALSE);
    eff_tk.readFromStream(is.getline(line,1000),  kFALSE);
    eff_sa.readFromStream(is.getline(line,1000),  kFALSE);
    eff_iso.readFromStream(is.getline(line,1000),  kFALSE);
    eff_hlt.readFromStream(is.getline(line,1000),  kFALSE);
    alpha.readFromStream(is.getline(line,1000),  kFALSE);
    a0.readFromStream(is.getline(line,1000),  kFALSE);  
    a1.readFromStream(is.getline(line,1000), kFALSE );  
    a2.readFromStream(is.getline(line,1000), kFALSE);  
    beta.readFromStream(is.getline(line,1000), kFALSE);
    b0.readFromStream(is.getline(line,1000), kFALSE);  
    b1.readFromStream(is.getline(line,1000), kFALSE);  
    b2.readFromStream(is.getline(line,1000), kFALSE);  
    fb.close();

    /* scaling to lumi if toy is enabled, not necessary is scaleLumi is used....
       if (vm.count("toy")) {
       Yield.setVal(scaleLumi * (Yield.getVal()));
       nbkg_mutrk.setVal(scaleLumi * (nbkg_mutrk.getVal()));
       nbkg_mumuNotIso.setVal(scaleLumi * (nbkg_mumuNotIso.getVal()));
       }   
    */
    
    //efficiency term
    
    //zMuMuEff1HLTTerm = _2 * (effTk ^ _2) *  (effSa ^ _2) * (effIso ^ _2) * effHLT * (_1 - effHLT); 
    RooFormulaVar zMuMu1HLTEffTerm("zMuMu1HLTEffTerm", " @4 * (2.* (@0)^2 * (@1)^2 * (@2)^2 * @3 *(1.- @3))", RooArgList(eff_tk, eff_sa,eff_iso, eff_hlt, Yield)); //zMuMuEff2HLTTerm = (effTk ^ _2) *  (effSa ^ _2) * (effIso ^ _2) * (effHLT ^ _2) ; 
    RooFormulaVar zMuMu2HLTEffTerm("zMuMu2HLTEffTerm", " @4 * ((@0)^2 * (@1)^2 * (@2)^2 * (@3)^2)", RooArgList(eff_tk, eff_sa,eff_iso, eff_hlt, Yield));
    //zMuMuNoIsoEffTerm = (effTk ^ _2) * (effSa ^ _2) * (_1 - (effIso ^ _2)) * (_1 - ((_1 - effHLT)^_2));
    RooFormulaVar zMuMuNoIsoEffTerm("zMuMuNoIsoEffTerm", " @4 * ((@0)^2 * (@1)^2 * (1.- (@2)^2) * (1.- ((1.-@3)^2)))", RooArgList(eff_tk, eff_sa,eff_iso, eff_hlt, Yield));
    //zMuTkEffTerm = _2 * (effTk ^ _2) * effSa * (_1 - effSa) * (effIso ^ _2) * effHLT;
    RooFormulaVar zMuTkEffTerm("zMuTkEffTerm", " @4 * (2. *(@0)^2 * @1 * (1.-@1)* (@2)^2 * @3)", RooArgList(eff_tk, eff_sa,eff_iso, eff_hlt, Yield));
    //zMuSaEffTerm = _2 * (effSa ^ _2) * effTk * (_1 - effTk) * (effIso ^ _2) * effHLT;
    RooFormulaVar zMuSaEffTerm("zMuSaEffTerm", "@4 * (2. *(@1)^2 * @0 * (1.-@0)* (@2)^2 * @3)", RooArgList(eff_tk, eff_sa,eff_iso, eff_hlt, Yield));
    
    
    // creating model for the  fit 
    // z mu track
    
    RooGenericPdf *bkg_mutrk = new RooGenericPdf("bkg_mutrk","zmt bkg_model", "exp(alpha*mass) * ( a0 + a1 * mass + a2 * mass^2 )", RooArgSet( *mass, alpha, a0, a1,a2) );
    RooFormulaVar fracSigMutrk("fracSigMutrk", "@0 / (@0 + @1)", RooArgList(zMuTkEffTerm, nbkg_mutrk ));
    RooAddPdf * model_mutrk= new RooAddPdf("model_mutrk","model_mutrk",RooArgList(*ZmtPdf,*bkg_mutrk),RooArgList(zMuTkEffTerm , nbkg_mutrk)) ;
    // z mu mu not Iso
    
    // creating background pdf for zmu mu not Iso
    RooGenericPdf *bkg_mumuNotIso = new RooGenericPdf("bkg_mumuNotIso","zmumuNotIso bkg_model", "exp(beta * mass) * (b0 + b1 * mass + b2 * mass^2)", RooArgSet( *mass, beta, b0, b1,b2) );
    RooFormulaVar fracSigMuMuNoIso("fracSigMuMuNoIso", "@0 / (@0 + @1)", RooArgList(zMuMuNoIsoEffTerm, nbkg_mumuNotIso ));
    RooAddPdf * model_mumuNotIso= new RooAddPdf("model_mumuNotIso","model_mumuNotIso",RooArgList(*ZmmNoIsoPdf,*bkg_mumuNotIso), RooArgList(zMuMuNoIsoEffTerm, nbkg_mumuNotIso)); 
    // z mu sta
    
    RooGenericPdf model_musta("model_musta",  " ZmsPdf * zMuSaEffTerm ", RooArgSet( *ZmsPdf, zMuSaEffTerm)) ;
    RooExtendPdf * eZmsSig= new RooExtendPdf("eZmsSig","extended signal p.d.f for zms ",*ZmsPdf,  zMuSaEffTerm ) ;
    // z mu mu HLT
    
    // count ZMuMu Yield
    double nZMuMu = 0.;
    double nZMuMu1HLT = 0.;
    double  nZMuMu2HLT = 0.;
    unsigned int nBins = zmm->GetNbinsX();
    double xMin = zmm->GetXaxis()->GetXmin();
    double xMax = zmm->GetXaxis()->GetXmax();
    double deltaX =(xMax - xMin) / nBins;
    for(size_t i = 0; i < nBins; ++i) { 
      
      double x = xMin + (i +.5) * deltaX;
      if(x > fMin && x < fMax){
	nZMuMu += zmm->GetBinContent(i+1);
	
	nZMuMu1HLT += zmm1hlt->GetBinContent(i+1);
	
	nZMuMu2HLT += zmm2hlt->GetBinContent(i+1);
      }
    }
    
    cout << ">>> count of ZMuMu yield in the range [" << fMin << ", " << fMax << "]: " << nZMuMu << endl;
    cout << ">>> count of ZMuMu (1HLT) yield in the range [" << fMin << ", " << fMax << "]: "  << nZMuMu1HLT << endl;
    cout << ">>> count of ZMuMu (2HLT) yield in the range [" << fMin << ", " << fMax << "]: "  << nZMuMu2HLT << endl;
    // we set eff_hlt 
    //eff_hlt.setVal( 1. / (1. + (nZMuMu1HLT/ (2 * nZMuMu2HLT))) ) ;
    // creating the pdf for z mu mu 1hlt
    
    RooExtendPdf * eZmm1hltSig= new RooExtendPdf("eZmm1hltSig","extended signal p.d.f for zmm 1hlt",*ZmmHltPdf,  zMuMu1HLTEffTerm ) ;
    // creating the pdf for z mu mu 2hlt 
    RooExtendPdf * eZmm2hltSig= new RooExtendPdf("eZmm2hltSig","extended signal p.d.f for zmm 2hlt",*ZmmHltPdf,  zMuMu2HLTEffTerm ) ;
    
    
// getting the data if fit otherwise constructed the data for model if toy....
 
   RooDataHist *zmtMass, * zmmNotIsoMass, *zmsMass, *zmm1hltMass,  *zmm2hltMass;
   
   if (toy){
     zmtMass = genHistFromModelPdf("zmtMass", model_mutrk, mass,  scaleLumi, range/rebinZMuTk);
     zmmNotIsoMass = genHistFromModelPdf("zmmNotIsoMass", model_mumuNotIso, mass, scaleLumi,  range/rebinZMuMuNoIso);
     zmsMass = genHistFromModelPdf("zmsMass", eZmsSig, mass,  scaleLumi, range/rebinZMuSa );
     zmm1hltMass = genHistFromModelPdf("zmm1hltMass", eZmm1hltSig, mass, scaleLumi,  range/rebinZMuMuHlt );
     zmm2hltMass = genHistFromModelPdf("zmm2hltMass", eZmm2hltSig, mass,   scaleLumi, range/rebinZMuMuHlt);
   }else {// if  fit from data....
     zmtMass = new RooDataHist("zmtMass", "good z mu track" , RooArgList(*mass), zmt );
     zmmNotIsoMass = new RooDataHist("ZmmNotIso", "good z mu mu not isolated" , RooArgList(*mass), zmmNotIso );
     zmsMass = new RooDataHist("zmsMass", "good z mu sta mass" , RooArgList(*mass), zmmsta );
     zmm1hltMass = new RooDataHist("zmm1hltMass", "good Z mu mu 1hlt" , RooArgList(*mass),   zmm1hlt );
     zmm2hltMass = new RooDataHist("zmm2hltMass", "good Z mu mu 2hlt" , RooArgList(*mass),   zmm2hlt );
   }
   
   // creting the chi2s 
   RooChi2Var *chi2_mutrk = new RooChi2Var("chi2_mutrk","chi2_mutrk",*model_mutrk,*zmtMass, Extended(kTRUE)) ;
   RooChi2Var *chi2_mumuNotIso = new RooChi2Var("chi2_mumuNotIso","chi2_mumuNotIso",*model_mumuNotIso,*zmmNotIsoMass,Extended(kTRUE)) ;
   RooChi2Var *chi2_musta = new RooChi2Var("chi2_musta","chi2_musta",*eZmsSig, *zmsMass,  Extended(kTRUE) ) ;
   RooChi2Var *chi2_mu1hlt = new RooChi2Var("chi2_mu1hlt","chi2_mu1hlt", *eZmm1hltSig, *zmm1hltMass,  Extended(kTRUE) ) ;
   RooChi2Var *chi2_mu2hlt = new RooChi2Var("chi2_mu2hlt","chi2_mu2hlt", *eZmm2hltSig, *zmm2hltMass,  Extended(kTRUE) ) ;  
   
   // adding the chi2
   RooAddition totChi2("totChi2","chi2_mutrk + chi2_mumuNotIso + chi2_musta   + chi2_mu1hlt  +  chi2_mu2hlt " , RooArgSet(*chi2_mutrk   ,*chi2_mumuNotIso  , *chi2_musta  ,*chi2_mu1hlt  ,  *chi2_mu2hlt  )) ;
   
   fit( totChi2,  numberOfBins, outfile.c_str());
   
   //fracSigMutrk.Print();
   //fracSigMuMuNoIso.Print();
   
   //plotting
   RooPlot * massFrame_mutrk = mass->frame() ; 
   RooPlot * massFrame_mumuNotIso = mass->frame() ;
   RooPlot * massFrame_musta = mass->frame() ;
   RooPlot * massFrame_mumu1hlt = mass->frame() ;
   RooPlot * massFrame_mumu2hlt = mass->frame() ;
   
   TCanvas  * c1 = new TCanvas("canvas");
   c1->Divide(2,3);
   c1->cd(1);
   c1->SetLogy(kTRUE);
   zmtMass->plotOn(massFrame_mutrk, LineColor(kBlue)) ;
   model_mutrk->plotOn(massFrame_mutrk,LineColor(kRed)) ;
   model_mutrk->plotOn(massFrame_mutrk,Components(*bkg_mutrk),LineColor(kGreen)) ;
   massFrame_mutrk->SetTitle("Z -> #mu track");
   // massFrame_mutrk->GetYaxis()->SetLogScale();
   massFrame_mutrk->Draw(); 
   gPad->SetLogy(1); 
  
   c1->cd(2);
   zmmNotIsoMass->plotOn(massFrame_mumuNotIso, LineColor(kBlue)) ;
   model_mumuNotIso->plotOn(massFrame_mumuNotIso,LineColor(kRed)) ;
   model_mumuNotIso->plotOn(massFrame_mumuNotIso,Components(*bkg_mumuNotIso), LineColor(kGreen)) ;
   massFrame_mumuNotIso->SetTitle("Z -> #mu #mu not isolated");
   massFrame_mumuNotIso->Draw(); 
   gPad->SetLogy(1); 
   c1->cd(3);
   zmsMass->plotOn(massFrame_musta, LineColor(kBlue)) ;
   eZmsSig->plotOn(massFrame_musta,LineColor(kRed)) ;
   massFrame_musta->SetTitle("Z -> #mu sta");
   massFrame_musta->Draw(); 
   
   
   c1->cd(4);  
   zmm1hltMass->plotOn(massFrame_mumu1hlt, LineColor(kBlue)) ;
   eZmm1hltSig->plotOn(massFrame_mumu1hlt,LineColor(kRed)) ;
   massFrame_mumu1hlt->SetTitle("Z -> #mu #mu 1hlt");
   massFrame_mumu1hlt->Draw(); 
   
   c1->cd(5);
   zmm2hltMass->plotOn(massFrame_mumu2hlt, LineColor(kBlue)) ;
   eZmm2hltSig->plotOn(massFrame_mumu2hlt,LineColor(kRed)) ;
   massFrame_mumu2hlt->SetTitle("Z -> #mu #mu 2hlt");
   massFrame_mumu2hlt->Draw(); 
  
   c1->SaveAs("mass.eps");

 /* how to read the fit result in root 
TH1D h_Yield("h_Yield", "h_Yield", 100, 10000, 30000)
for (int i =0: i < 100; i++){ 
RooFitResult* r = gDirectory->Get(Form("toy_totChi2;%d)",i)
//r->floatParsFinal().Print("s");
// without s return a list,  can we get the number?
 RooFitResult* r = gDirectory->Get("toy_totChi2;1")
// chi2
r->minNll();
//distamce form chi2.....
//r->edm();
// yield
r->floatParsFinal()[0]->Print();
//RooAbsReal * l = r->floatParsFinal()->first()
RooAbsReal * y = r->floatParsFinal()->find("Yield");
h_Yield->Fill(y->getVal());
}

  */

   delete root_file;
   //delete out_root_file;
   return 0;
 
}
