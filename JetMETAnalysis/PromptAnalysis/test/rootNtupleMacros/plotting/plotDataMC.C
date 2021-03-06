using namespace std;
#include "tdrstyle.C"

void plotDataMC(){
   
  // specify the DATA/MC root file!!!
  // --------------------------------------------------------------------------
  TFile *data = TFile::Open("ALLDATAseriously.root"); 
  TFile *mc = TFile::Open("MC_7Tev_DIJETS.root");

  char *legDataTitle = "Data";
  char *legMCTitle = "Simulation";
  TString dataset="";
  TString overallTitle="CMS preliminary 2010";
  TString CMen="#sqrt{s}=7TeV";
  TString cuts1="";
  TString cuts2="";
  double rebin=4.;
  bool isptplot;
  //---------------------------------------------------------------------------
  setTDRStyle();
  gROOT->ForceStyle();
  TIter next (data->GetListOfKeys ());

  TString name;
  TRegexp jpt("JPT");  
  TRegexp pf("PF");
  int colour;
  TRegexp twodim("map");
  //non log plots 
  TRegexp eta("eta");
  TRegexp phi("phi");
  TRegexp hits("hits");
  //
  TRegexp pt("pt");
  TRegexp dphi("dphi");
  TRegexp mass("mass");

  TRegexp emf("emf");
  TRegexp CHF("CHF");
  TRegexp NHF("NHF");
  TRegexp NEF("NEF");
  TRegexp METover("METover");
  TRegexp dijet("DiJet");
  TRegexp cons("cons");

  int islog=1;

  for (TKey* key = 0; (key = (TKey *) next());) {
    isptplot=false;
    //determine wether it is a Calo/JPT or PF plots to make
    name=key->GetName();
    if(name.Index(twodim)>-1) continue; //dont want comparisons for 2D histos
    colour=5;
      cuts1="p_{T}(jet)> 25 GeV";
      cuts2="|#eta(jet)| < 3";
    if(name.Index(jpt)>-1) {
      colour=896;
      cuts1="p_{T}(jet)> 25 GeV";
      cuts2="|#eta(jet)| < 3";
    }
    if(name.Index(pf)>-1){
      colour=38;
      cuts1="p_{T}(jet)> 25 GeV";
      cuts2="|#eta(jet)| < 3";

    } 
     
    islog=1;
    if(name.Index(eta)>-1||name.Index(phi)>-1||name.Index(hits)>-1 || name.Index(emf)>-1 || name.Index(CHF)>-1 || name.Index(NHF)>-1|| name.Index(NEF)>-1||name.Index(cons)>-1) islog=0;
    TH1D * h_data= data->Get(key->GetName());
    TH1D * h_mc=mc->Get(key->GetName());; 
    // only for filled histos
    if( h_mc->GetEntries()!=0) {
      //
      h_data->SetTitle(overallTitle);
      h_mc->SetTitle(overallTitle);
      if(name.Index(pt)>-1) {
	h_data->SetYTitle("Jets/GeV");
	h_mc->SetYTitle("Jets/GeV");
	isptplot=true;  
	//	cout << 	h_data->GetXaxis()->GetBinWidth(1)<< endl;  
      }
      if(name.Index(eta)>-1||name.Index(phi)>-1) {
	h_data->SetYTitle("Jets");
	h_mc->SetYTitle("Jets");
      }
      if(name.Index(dphi)>-1) {
	h_data->SetYTitle("Events");
	h_mc->SetYTitle("Events");
      }
      if(name.Index(mass)>-1){
	h_data->SetYTitle("Events/GeV");
	h_mc->SetYTitle("Events/GeV");
	isptplot=true;
      }

    TCanvas *c = new TCanvas("c","",600,600); 
    double scalefactor= h_data->Integral()/h_mc->Integral();
    if (isptplot) { 
      // h_mc->Sumw2(); //for some reason it doesnt plot this one if i do sumw2, so i comment it out. anyhow we dont see its errors, but to be checked!
      //      h_data->Sumw2();
      for(int j=0 ; j<=h_mc->GetNbinsX(); ++j){
	h_data->SetBinError(j,sqrt(h_data->GetBinContent(j))/h_data->GetBinWidth(j));
	//
	h_mc->SetBinContent(j,h_mc->GetBinContent(j)/h_mc->GetBinWidth(j));
	h_data->SetBinContent(j,h_data->GetBinContent(j)/h_data->GetBinWidth(j));
      }
    }
    h_mc->Scale(scalefactor);
    //    h_mc->Rebin(rebin);
    //    h_data->Rebin(rebin);
    h_mc->SetMaximum(1.5*h_data->GetMaximum());
    h_mc->SetFillColor(colour);
    h_data->SetMarkerStyle(20);
    //    h_data->SetTitle(overallTitle);
    //    h_mc->SetTitle(overallTitle);
    std::cout << "Plotting: " << key->GetName()  <<  std::endl;
    h_mc->SetMinimum(0.01);
    h_data->SetMinimum(0.01);

    //draw title
    MoveStatsAndDraw(h_data , h_mc, legDataTitle, legMCTitle, overallTitle, CMen, islog, colour, false, cuts1, cuts2,isptplot);
    char histname [256];
    sprintf (histname, "%s.pdf", key->GetName());
    c->Print (histname);
    delete c;
    } //if Entries != 0 
  } // loop over keys


  cout << "------ Calo Jets --------" <<endl;
   TH1D * temp =data->Get("dijetptall");
   cout << "CaloJets       " << temp->GetEntries() <<endl;
   TH1D *temp2 =data->Get("dijetptallJIDloose");
   cout << "Loose CaloJets " << temp2->GetEntries() <<endl;
   TH1D *temp3 =data->Get("dijetptallJIDtight");
   cout << "Tight CaloJets " << temp3->GetEntries() <<endl;
  
   cout << "------ PF Jets --------" <<endl;
   TH1D * temp5 =data->Get("diPFjetptall");
   cout << "PFJets       " << temp5->GetEntries() <<endl;
   TH1D *temp6 =data->Get("diPFjetptallJIDloose");
   cout << "Loose PFJets " << temp6->GetEntries() <<endl;
   TH1D *temp7 =data->Get("diPFjetptallJIDtight");
   cout << "Tight PFJets " << temp7->GetEntries() <<endl;  

   cout << "------ JPT Jets --------" <<endl;
   TH1D * temp8 =data->Get("diJPTjetptall");
   cout << "JPTJets       " << temp8->GetEntries() <<endl;
   TH1D *temp9 =data->Get("diJPTjetptallJIDloose");
   cout << "Loose JPTJets " << temp9->GetEntries() <<endl;
   TH1D *temp10 =data->Get("diJPTjetptallJIDtight");
   cout << "Tight JPTJets " << temp10->GetEntries() <<endl;
}



//-------------------------------------------------------------------------------------
void MoveStatsAndDraw (TH1 *data, TH1 *mc, char *dataTitle, char* mcTitle, char* firstline, char* secondline, int log, int col, bool stat, TString cut1, TString cut2, bool movepave){
  c->SetLogy(log);
  mc->Draw();
  data->Draw("pesames");   
  gStyle->SetOptStat(00000000); 
  stat=0;  
  if(stat) gStyle->SetOptStat(1111111111); 

  /*  TPaveText *TITLE = new TPaveText(0.2,0.65,0.55,0.9,"blNDC");
  TITLE->SetFillStyle(4000);
  TITLE->SetFillColor(kWhite);
  TITLE->SetBorderSize(0.1);
  TITLE->SetTextFont(42);
  TITLE->AddText(firstline);
  TITLE->Draw();  */

  if(!movepave) {
  TPaveText *title = new TPaveText(0.2,0.7,0.55,0.93,"blNDC");
  } else {
    //  TPaveText *title = new TPaveText(0.6,0.58,0.95,0.83,"blNDC");
  TPaveText *title = new TPaveText(0.6,0.7,0.95,0.93,"blNDC");
  }
  title->SetFillStyle(4000);
  title->SetFillColor(kWhite);
  title->SetBorderSize(0.1);
  title->SetTextFont(42);
  title->AddText(firstline);
  title->AddText(secondline);
  title->AddText(cut1);
  title->AddText(cut2);
  title->Draw();  
  if(!movepave) {
    TLegend *leg = new TLegend(0.65,0.83,1.,0.93);
  } else {
    TLegend *leg = new TLegend(0.65,0.60,1.,0.7);
  }
  leg->SetFillStyle(4000);
  leg->SetFillColor(kWhite);
  leg->SetBorderSize(0.1);
  leg->SetTextFont(42);
  leg->AddEntry(data,dataTitle,"p");
  leg->AddEntry(mc,mcTitle,"f");
  leg->Draw();

  c->Modified();
  c->Update();



  if(stat){
  TPaveStats * ps = (TPaveStats *) mc->GetListOfFunctions()->FindObject("stats"); 
  TPaveStats * ps2 = (TPaveStats *) data->GetListOfFunctions()->FindObject("stats");
  Int_t ci; 
  ci = TColor::GetColor(col);
  if( ps ){ 
    ps->SetTextColor(1); 
    ps->SetLineColor(col);   
  }
  else std::cout << "Null pointer to TPaveStats: " << ps << std::endl; 
  ps->SetY1NDC(0.40);
  ps->SetY2NDC(0.68);
  if( ps2 ) ps2->SetTextColor(ci); else std::cout << "Null pointer to TPaveStats: " << ps2 << std::endl;
  }
}
