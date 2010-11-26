#include "xsReader.hh"
#include <vector>
#include "TRandom.h"
#define MMUON 0.10566
#define MKAON 0.49368

// ----------------------------------------------------------------------
// Run with: ./runXSReaders -c chains/bg-test -D root 
//           ./runXSReaders -f test.root 
// ----------------------------------------------------------------------
const int  xsReader::fNpt;
const int  xsReader::fNy;

// ----------------------------------------------------------------------
xsReader::xsReader(TChain *tree, TString evtClassName): treeReaderXS(tree, evtClassName) {
  cout << "--> xsReader> This is the start ..." << endl;
  fpJSON = new JSON("/shome/bora/root/json/json_147196_149442");
  fPTbin[0] = 0.; fPTbin[1] = 2.; fPTbin[2] = 3.; fPTbin[3] = 5.; fPTbin[4] = 8.; fPTbin[5] =12.; fPTbin[6] = 20.;
  fYbin[0] = -2.; fYbin[1] = -1.; fYbin[2] = 0.; fYbin[3] = 1.; fYbin[4] = 2.;
  //fPidTableMuIDPos = new PidTable("../tnp/PidTables/MC/Upsilon/MuID/PtTnpPos-upsilon.dat");
  //fPidTableMuIDNeg = new PidTable("../tnp/PidTables/MC/Upsilon/MuID/PtTnpNeg-upsilon.dat");
  //fPidTableTrigPos = new PidTable("../tnp/PidTables/MC/Upsilon/Trig/PtTnpPos-upsilon.dat");   // MC 
  //fPidTableTrigNeg = new PidTable("../tnp/PidTables/MC/Upsilon/Trig/PtTnpNeg-upsilon.dat"); 
  
  //fPidTableMuIDPos = new PidTable("../tnp/PidTables/DATA/Jpsi/MuID/PtMmbPos-jpsi.dat");
  //fPidTableMuIDNeg = new PidTable("../tnp/PidTables/DATA/Jpsi/MuID/PtMmbNeg-jpsi.dat");
  //fPidTableTrigPos = new PidTable("../tnp/PidTables/DATA/Jpsi/Trig/PtMmbPos-jpsi.dat");     // DATA
  //fPidTableTrigNeg = new PidTable("../tnp/PidTables/DATA/Jpsi/Trig/PtMmbNeg-jpsi.dat"); 
  
}
// ----------------------------------------------------------------------
xsReader::~xsReader() {
  cout << "--> xsReader> This is the end ..." << endl;
}

// ----------------------------------------------------------------------
void xsReader::startAnalysis() {
  cout << "--> xsReader> startAnalysis: ..." << endl;
}


void xsReader::eventProcessing() {
  
  //cout << fRun << " " << fLS << ": " << fpJSON->good(fRun, fLS) << endl;
  
  //if ( MODE == 1  ) acceptance();  // FOR MC only
  //if ( isPathPreScaled(HLTPATH) ) goto end;
  //if ( !isPathFired(HLTPATH) ) goto end;
  PathStudy();
  //candidateSelection(2); 
  //if ( 0 != fpCand  ){
  //calculateWeights(0); 
  //fillCandHist(); 
  //if ( 0 != fgCand && MODE == 1 ) MCstudy(); // FOr MC only
    ////x_btest();
    //// x_brestframe();
  //}
	   
  //fpHistFile->cd();
  
  //end:
  //fillHist();
}

void xsReader::x_brestframe(){
  
  TGenCand *gCand(0);
  TGenCand *gDau1(0);
  TGenCand *gDau2(0);
  TVector3 xb;
  TLorentzVector genCand;
  TLorentzVector upsCand;
  TLorentzVector gammaCand;
  double GenAngle(-99.), SgMatchedAngle(-99.), BgMatchedAngle(-99.), NoMatchedAngle(-99.);
  cout << " NEW EVENT " << endl;
  
  for (int iG = 0; iG < fpEvt->nGenCands(); ++iG) {
    gCand = fpEvt->getGenCand(iG);
    
    if ( (gCand->fID == 20553 || gCand->fID == 10551 || gCand->fID == 555) && gCand->fStatus == 2 ){
      genCand.SetPtEtaPhiE(gCand->fP.Perp(),gCand->fP.Eta(),gCand->fP.Phi(),gCand->fP.Energy());
      xb = genCand.BoostVector();
      xb*=-1.;
      //cout << "Boost Momentum = "  << xb.Mag()  << endl;
      //cout << "Momentum = "  << genCand.P()  << endl;
      genCand.Boost(xb);
      //cout << "Boosted Momentum = "  << genCand.P()  << endl;
      
      gDau1 = fpEvt->getGenCand(gCand->fDau1);
      gDau2 = fpEvt->getGenCand(gCand->fDau2);
      
      if ( gDau1->fID == 553 ){
	//cout << " Dau1  "  << endl;
	upsCand.SetPtEtaPhiE(gDau1->fP.Perp(),gDau1->fP.Eta(),gDau1->fP.Phi(),gDau1->fP.Energy());  
	upsCand.Boost(xb);
	//cout << "upsCand = " << upsCand.P() << endl;
	if ( gDau2->fID == 22 ){
	  gammaCand.SetPtEtaPhiE(gDau2->fP.Perp(),gDau2->fP.Eta(),gDau2->fP.Phi(),gDau2->fP.Energy());
	  gammaCand.Boost(xb);
	  //cout << "gammaCand = " << gammaCand.P() << endl;
	  GenAngle = upsCand.Angle(gammaCand.Vect());
	  //cout << " GenAngle "  << GenAngle  << endl;
	  ((TH1D*)fpHistFile->Get("hGenAngle"))->Fill(GenAngle);
	}
      } 
	
      if ( gDau1->fID == 22 ){
	//cout << " Dau2  "  << endl;
	gammaCand.SetPtEtaPhiE(gDau1->fP.Perp(),gDau1->fP.Eta(),gDau1->fP.Phi(),gDau1->fP.Energy());
	gammaCand.Boost(xb);
	//cout << "gammaCand = " << gammaCand.P() << endl;
	if ( gDau2->fID == 553 ){
	  upsCand.SetPtEtaPhiE(gDau2->fP.Perp(),gDau2->fP.Eta(),gDau2->fP.Phi(),gDau2->fP.Energy());  
	  upsCand.Boost(xb);
	  //cout << "upsCand = " << upsCand.P() << endl; 
	  GenAngle = upsCand.Angle(gammaCand.Vect());
	  //cout << " GenAngle "  << GenAngle << endl;
	  ((TH1D*)fpHistFile->Get("hGenAngle"))->Fill(GenAngle);
	}
      }   
    }
    
  }

  TAnaTrack *pTrack(0);
  TLorentzVector Cand, Gamma, gamma, x_b;
  TVector3 xB;
  int n(-1);
  
  Cand.SetPtEtaPhiM(fpCand->fPlab.Perp(),fpCand->fPlab.Eta(),fpCand->fPlab.Phi(),fpCand->fMass);
  for (int iG = 0; iG < fpEvt->nRecTracks(); ++iG) {
    pTrack = fpEvt->getRecTrack(iG);
    if ( pTrack->fMCID == 22 && pTrack->fQ == 0  ){
      ++n;
      TGenCand  *gGamma = fpEvt->getGenCand(pTrack->fGenIndex);
      TGenCand  *geCand = fpEvt->getGenCand(gGamma->fMom1);
      if ( geCand->fID == 555 || geCand->fID == 20553 || geCand->fID == 10551 ) {
	Gamma.SetPtEtaPhiM(pTrack->fPlab.Perp(),pTrack->fPlab.Eta(),pTrack->fPlab.Phi(), 0.);
	TAnaTrack *pl1 = fpEvt->getSigTrack(fpCand->fSig1); 
	TAnaTrack *pl2 = fpEvt->getSigTrack(fpCand->fSig2);
	if ( (pl1->fGenIndex > -1) && (pl2->fGenIndex > -1) && (pl1->fGenIndex != pl2->fGenIndex) ){
	  TGenCand  *gl1 = fpEvt->getGenCand(pl1->fGenIndex);
	  TGenCand  *gl2 = fpEvt->getGenCand(pl2->fGenIndex);
	  if ( gl1->fMom1 == gl2->fMom1 ) {
	    TGenCand  *GenCand = fpEvt->getGenCand(gl1->fMom1);
	    if ( GenCand->fID == RESTYPE ) {
	      x_b = Cand + Gamma;
	      xB = x_b.BoostVector();
	      xB*=-1.;
	      Cand.Boost(xB);
	      Gamma.Boost(xB);
	      SgMatchedAngle = Cand.Angle(Gamma.Vect());
	      ((TH1D*)fpHistFile->Get("hSgMatchedAngle"))->Fill(SgMatchedAngle);
	    }
	  }
	}
      } 
      
      if ( !(geCand->fID == 555 || geCand->fID == 20553 || geCand->fID == 10551) ){
	gamma.SetPtEtaPhiM(pTrack->fPlab.Perp(),pTrack->fPlab.Eta(),pTrack->fPlab.Phi(), 0.);
	x_b = Cand + Gamma;
	xB = x_b.BoostVector();
	xB*=-1.;
	Cand.Boost(xB);
	gamma.Boost(xB);
	BgMatchedAngle = Cand.Angle(gamma.Vect());
	((TH1D*)fpHistFile->Get("hBgMatchedAngle"))->Fill(BgMatchedAngle);
      }
    }
  }

  TLorentzVector g, X_b;
  TVector3 XB;
  for (int iG = 0; iG < fpEvt->nRecTracks(); ++iG) {
    pTrack = fpEvt->getRecTrack(iG);
    if ( pTrack->fQ == 0  ){  
      g.SetPtEtaPhiM(pTrack->fPlab.Perp(),pTrack->fPlab.Eta(),pTrack->fPlab.Phi(), 0.);
      X_b = Cand + Gamma;
      XB = X_b.BoostVector();
      XB*=-1.;
      Cand.Boost(XB);
      g.Boost(XB);
      NoMatchedAngle = Cand.Angle(g.Vect());
      ((TH1D*)fpHistFile->Get("hAngle"))->Fill(NoMatchedAngle);
    }
  }
  
   
  
}



void xsReader::x_btest(){
  TGenCand *gCand(0);
  TGenCand *gDau1(0);
  TGenCand *gDau2(0);
  TLorentzVector genCand;
  int u1(0); int xb0(0); int xb1(0); int xb2(0);
  
  ((TH1D*)fpHistFile->Get("h"))->GetXaxis()->SetBinLabel(2, Form("Upsilon1S"));
  ((TH1D*)fpHistFile->Get("h"))->GetXaxis()->SetBinLabel(4, Form("xb_0")); 
  ((TH1D*)fpHistFile->Get("h"))->GetXaxis()->SetBinLabel(6, Form("xb_1"));
  ((TH1D*)fpHistFile->Get("h"))->GetXaxis()->SetBinLabel(8, Form("xb_2"));
  
  for (int iG = 0; iG < fpEvt->nGenCands(); ++iG) {
    gCand = fpEvt->getGenCand(iG);
    
    if ( gCand->fID == 553 && gCand->fStatus == 2 ){
      u1++;
      genCand.SetPtEtaPhiE(gCand->fP.Perp(),gCand->fP.Eta(),gCand->fP.Phi(),gCand->fP.Energy());
      ((TH1D*)fpHistFile->Get("h0"))->Fill(genCand.M());
    }
    
    if ( gCand->fID == 10551 && gCand->fStatus == 2 ){
      xb0++;
      genCand.SetPtEtaPhiE(gCand->fP.Perp(),gCand->fP.Eta(),gCand->fP.Phi(),gCand->fP.Energy());
      ((TH1D*)fpHistFile->Get("h0"))->Fill(genCand.M());
      gDau1 = fpEvt->getGenCand(gCand->fDau1);
      gDau2 = fpEvt->getGenCand(gCand->fDau2);
      if ( gDau1->fID == 22 && gDau2->fID == 553 ) {
	((TH1D*)fpHistFile->Get("h1"))->Fill(gDau1->fP.Energy());
      }
      if ( gDau2->fID == 22 && gDau1->fID == 553 ) {
	((TH1D*)fpHistFile->Get("h1"))->Fill(gDau2->fP.Energy());
      }
    
    }
    
    if ( gCand->fID == 20553 && gCand->fStatus == 2 ){
      xb1++;
      genCand.SetPtEtaPhiE(gCand->fP.Perp(),gCand->fP.Eta(),gCand->fP.Phi(),gCand->fP.Energy());
      ((TH1D*)fpHistFile->Get("h0"))->Fill(genCand.M());
      gDau1 = fpEvt->getGenCand(gCand->fDau1);
      gDau2 = fpEvt->getGenCand(gCand->fDau2);
      if ( gDau1->fID == 22 && gDau2->fID == 553 ) {
	((TH1D*)fpHistFile->Get("h1"))->Fill(gDau1->fP.Energy());
      }
      if ( gDau2->fID == 22 && gDau1->fID == 553 ) {
	((TH1D*)fpHistFile->Get("h1"))->Fill(gDau2->fP.Energy());
      }
      
    }     
    if ( gCand->fID == 555 && gCand->fStatus == 2 ){
      xb2++;
      genCand.SetPtEtaPhiE(gCand->fP.Perp(),gCand->fP.Eta(),gCand->fP.Phi(),gCand->fP.Energy());
      ((TH1D*)fpHistFile->Get("h0"))->Fill(genCand.M());
      gDau1 = fpEvt->getGenCand(gCand->fDau1);
      gDau2 = fpEvt->getGenCand(gCand->fDau2);
      if ( gDau1->fID == 22 && gDau2->fID == 553 ) {
	((TH1D*)fpHistFile->Get("h1"))->Fill(gDau1->fP.Energy());
      }
      if ( gDau2->fID == 22 && gDau1->fID == 553 ) {
	((TH1D*)fpHistFile->Get("h1"))->Fill(gDau2->fP.Energy());
      }
    }     
  }
  
    
  ((TH1D*)fpHistFile->Get("h"))->AddBinContent(2, u1);
  ((TH1D*)fpHistFile->Get("h"))->AddBinContent(4, xb0); 
  ((TH1D*)fpHistFile->Get("h"))->AddBinContent(6, xb1);
  ((TH1D*)fpHistFile->Get("h"))->AddBinContent(8, xb2);
  
  TAnaCand *pCand(0);
  TAnaTrack *pTrack(0);
  TLorentzVector Cand, Gamma, photon, x_b, xbg_b;
  int n(-1);
  Cand.SetPtEtaPhiM(fpCand->fPlab.Perp(),fpCand->fPlab.Eta(),fpCand->fPlab.Phi(),fpCand->fMass);
  for (int iG = 0; iG < fpEvt->nRecTracks(); ++iG) {
    pTrack = fpEvt->getRecTrack(iG);
    if ( pTrack->fMCID == 22 && pTrack->fQ == 0  ){
      ++n;
      TGenCand  *gGamma = fpEvt->getGenCand(pTrack->fGenIndex);
      TGenCand  *genCand = fpEvt->getGenCand(gGamma->fMom1);
      if ( genCand->fID == 555 || genCand->fID == 20553 || genCand->fID == 10551 ) {
	Gamma.SetPtEtaPhiM(pTrack->fPlab.Perp(),pTrack->fPlab.Eta(),pTrack->fPlab.Phi(), 0.);
	TAnaTrack *pl1 = fpEvt->getSigTrack(fpCand->fSig1); 
	TAnaTrack *pl2 = fpEvt->getSigTrack(fpCand->fSig2);
	if ( (pl1->fGenIndex > -1) && (pl2->fGenIndex > -1) && (pl1->fGenIndex != pl2->fGenIndex) ){
	  TGenCand  *gl1 = fpEvt->getGenCand(pl1->fGenIndex);
	  TGenCand  *gl2 = fpEvt->getGenCand(pl2->fGenIndex);
	  if ( gl1->fMom1 == gl2->fMom1 ) {
	    TGenCand  *GenCand = fpEvt->getGenCand(gl1->fMom1);
	    if ( GenCand->fID == RESTYPE ) {
	      m_ge = pTrack->fPlab.Eta();
	      m_gp = pTrack->fPlab.Phi();
	      m_gP = pTrack->fPlab.Perp();
	      m_gE = Gamma.E();
	      m_ue = fpCand->fPlab.Eta();
	      m_up = fpCand->fPlab.Phi();
	      m_uP = fpCand->fPlab.Perp();
	      m_um = Cand.M();
	      double deltaR = Gamma.DeltaR(Cand);
	      m_dR = deltaR;
	      x_b = Cand + Gamma;
	      m_xbm = x_b.M();
	      m_xbid = genCand->fID;
	      fTree->Fill();
	      ((TH1D*)fpHistFile->Get("h2"))->Fill(x_b.M()-Cand.M());
	      if ( genCand->fID == 555 ) ((TH1D*)fpHistFile->Get("h3"))->Fill(x_b.M()-Cand.M());
	      if ( genCand->fID == 10551 ) ((TH1D*)fpHistFile->Get("h4"))->Fill(x_b.M()-Cand.M());
	      if ( genCand->fID == 20553 ) ((TH1D*)fpHistFile->Get("h5"))->Fill(x_b.M()-Cand.M());
	      
	    }
	  }
	  
	}
      }
      
      if ( !(genCand->fID == 555 || genCand->fID == 20553 || genCand->fID == 10551) ) {
	photon.SetPtEtaPhiM(pTrack->fPlab.Perp(),pTrack->fPlab.Eta(),pTrack->fPlab.Phi(), 0.);
	mbg_ge = pTrack->fPlab.Eta();
	mbg_gp = pTrack->fPlab.Phi();
	mbg_gP = pTrack->fPlab.Perp();
	mbg_gE = photon.E();
	mbg_ue = fpCand->fPlab.Eta();
	mbg_up = fpCand->fPlab.Phi();
	mbg_uP = fpCand->fPlab.Perp();
	mbg_um = Cand.M();
	double dltaR = photon.DeltaR(Cand);
	mbg_dR = dltaR;
	xbg_b = Cand + photon;
	mbg_xbm = xbg_b.M();
	fTree2->Fill();
      }
    }
  }
  
  
  ((TH1D*)fpHistFile->Get("h6"))->Fill(fpCand->fMass);
  ((TH1D*)fpHistFile->Get("n"))->Fill(n);
  TAnaTrack *pTrack1(0);
  TLorentzVector gamma, x_B;
  for (int iG = 0; iG < fpEvt->nRecTracks(); ++iG) {
    pTrack1 = fpEvt->getRecTrack(iG);
    //if ( pTrack1->fMCID == 22 && pTrack1->fQ == 0  ){
    if ( pTrack1->fQ == 0  ){  
      gamma.SetPtEtaPhiM(pTrack1->fPlab.Perp(),pTrack1->fPlab.Eta(),pTrack1->fPlab.Phi(), 0.);
      ge = pTrack->fPlab.Eta();
      gp = pTrack->fPlab.Phi();
      gP = pTrack->fPlab.Perp();
      gE = gamma.E();
      double deltar = gamma.DeltaR(Cand);
      dR = deltar;
      x_B = Cand + gamma;
      xbm = x_B.M();
      ue = fpCand->fPlab.Eta();
      up = fpCand->fPlab.Phi();
      uP = fpCand->fPlab.Perp();
      um = Cand.M();
      fTree1->Fill();
    }
  }
  
}

void xsReader::PathStudy(){
  
  int n(0), m15(0), m13(0), m11(0);
  int v1(0), v2(0), v3(0);
  for (int a = 0; a < NHLT ; ++a) {
    if ( fpEvt->fHLTNames[a] ==  HLTPATH  && fpEvt->fHLTResult[a] == 1 ) {
      n++;
      //cout << " Fired !!!   "   << fpEvt->fHLTNames[a] << endl;
      
      // for (int c = 0; c < NHLT ; ++c) {
      //if ( fpEvt->fHLTResult[c] == 1 ) cout  << fpEvt->fHLTNames[c] << endl;
      //}
      
      for (int b = 0; b < NHLT ; ++b) {
	if (  fpEvt->fHLTNames[b] ==  HLTPATH1  &&  fpEvt->fHLTResult[b] == 1 ) m15++;
	if (  fpEvt->fHLTNames[b] ==  HLTPATH2  &&  fpEvt->fHLTResult[b] == 1 ) m13++;
	if (  fpEvt->fHLTNames[b] ==  HLTPATH3  &&  fpEvt->fHLTResult[b] == 1 ) m11++;
	if (  fpEvt->fHLTNames[b] == "HLT_HT160U_v1" &&  fpEvt->fHLTResult[b] == 1 ) v1++;
	if (  fpEvt->fHLTNames[b] == "HLT_HT160U_v2" &&  fpEvt->fHLTResult[b] == 1 ) v2++;
	if (  fpEvt->fHLTNames[b] == "HLT_HT160U_v3" &&  fpEvt->fHLTResult[b] == 1 ) v3++;
      }
    }
  }
  
  ((TH1D*)fpHistFile->Get("hTriggerStudy"))->GetXaxis()->SetBinLabel(2, Form("HLT_DoubleMu0_Quarkonium_v1"));
  ((TH1D*)fpHistFile->Get("hTriggerStudy"))->GetXaxis()->SetBinLabel(4, Form("HLT_Mu15_v1"));
  ((TH1D*)fpHistFile->Get("hTriggerStudy"))->GetXaxis()->SetBinLabel(6, Form("HLT_Mu13_v1"));
  ((TH1D*)fpHistFile->Get("hTriggerStudy"))->GetXaxis()->SetBinLabel(8, Form("HLT_Mu11"));
  ((TH1D*)fpHistFile->Get("hTriggerStudy"))->GetXaxis()->SetBinLabel(10, Form("HLT_HT160U_v1"));
  ((TH1D*)fpHistFile->Get("hTriggerStudy"))->GetXaxis()->SetBinLabel(12, Form("HLT_HT160U_v2"));
  ((TH1D*)fpHistFile->Get("hTriggerStudy"))->GetXaxis()->SetBinLabel(14, Form("HLT_HT160U_v3"));
  ((TH1D*)fpHistFile->Get("hTriggerStudy"))->AddBinContent(2, n);
  ((TH1D*)fpHistFile->Get("hTriggerStudy"))->AddBinContent(4, m15);  
  ((TH1D*)fpHistFile->Get("hTriggerStudy"))->AddBinContent(6, m13); 
  ((TH1D*)fpHistFile->Get("hTriggerStudy"))->AddBinContent(8, m11);
  ((TH1D*)fpHistFile->Get("hTriggerStudy"))->AddBinContent(10, v1);  
  ((TH1D*)fpHistFile->Get("hTriggerStudy"))->AddBinContent(12, v2); 
  ((TH1D*)fpHistFile->Get("hTriggerStudy"))->AddBinContent(14, v3);  
  
}

void xsReader::acceptance(){
  
  TGenCand *gCand(0); TAnaTrack *pTrack(0); 
  TGenCand *gDau1(0); TGenCand *gDau2(0);  
  double pt, rapidity; bool match1 = false; bool match2 = false;
  double pt1(-1), pt2(-1);
  int index1(-1), index2(-1); 
  TLorentzVector genCand;
  for (int iG = 0; iG < fpEvt->nGenCands(); ++iG) {
    gCand = fpEvt->getGenCand(iG);
    if ( gCand->fID == RESTYPE && gCand->fStatus == 2 ){
      genCand.SetPtEtaPhiE(gCand->fP.Perp(),gCand->fP.Eta(),gCand->fP.Phi(),gCand->fP.Energy());
      if ( (gCand->fP.Perp() <= 20.) && (fabs(genCand.Rapidity()) <= 2.) ){
	getBinCenters(gCand, pt ,rapidity);
	((TH2D*)fpHistFile->Get(Form("AllGenRes_%.1dS",UPSTYPE)))->Fill(rapidity, pt); 
            
	gDau1 = fpEvt->getGenCand(gCand->fDau1);
	gDau2 = fpEvt->getGenCand(gCand->fDau2);
	
	if ( ((fabs(gDau1->fID)) == 13) && ((fabs(gDau2->fID)) == 13) ){
	  for (int iR = 0; iR < fpEvt->nRecTracks(); ++iR) {
	    pTrack = fpEvt->getRecTrack(iR);
	    if ( pTrack->fGenIndex == gDau1->fNumber ) {
	      index1 = pTrack->fGenIndex;
	      pt1 = pTrack->fPlab.Perp();
	      match1 = true;
	    } 
	    if ( pTrack->fGenIndex == gDau2->fNumber ) {
	      index2 = pTrack->fGenIndex;
	      pt2 = pTrack->fPlab.Perp();
	      match2 = true;
	    }
	    
	  }
	  
	  if ( match1 && match2 ){
	    if ((pt1 > 3.) && (pt2 > 3.) ){
	      ((TH2D*)fpHistFile->Get(Form("RecoGenRes_%.1dS",UPSTYPE)))->Fill(rapidity, pt);
	      match1 = false; match2 = false;
	    }
	  }
	}
      }
    }
  }
  
}

void xsReader::getBinCenters(TGenCand *gCand, double &pt, double &rapidity ){
  
  double ymin(-9), ymax(-9), ptmin(-9), ptmax(-9);
  TLorentzVector genCand;
  genCand.SetPtEtaPhiE(gCand->fP.Perp(),gCand->fP.Eta(),gCand->fP.Phi(),gCand->fP.Energy());
  for ( int iy = 0; iy <= fNy; ++iy ){
    if ( genCand.Rapidity() < fYbin[iy] ){
      ymax = fYbin[iy];
      ymin = fYbin[iy-1];
      break;
    }
  }
  
  for ( int ipt = 0; ipt <= fNpt; ++ipt ){
    if ( gCand->fP.Perp() < fPTbin[ipt] ){
      ptmax = fPTbin[ipt];
      ptmin = fPTbin[ipt-1];
      break;
    }
  }
  
  pt = 0.5*(ptmax+ptmin);
  rapidity = 0.5*(ymax+ymin);
  
}

bool xsReader::isPathPreScaled( TString Path ){
  bool PreScale = false;
  for (int a = 0; a < NHLT ; ++a) {
    if ( fpEvt->fHLTNames[a] ==  Path  && fpEvt->fHLTError[a] & 1  ) {
      PreScale = true;
      //cout << Path << " is prescaled!!!! "  << endl;
    }
  }
  return PreScale;
}

bool xsReader::isPathFired( TString Path ){
  bool HLT_Path = false;
  for (int a = 0; a < NHLT ; ++a) {
    if ( fpEvt->fHLTNames[a] ==  Path  && fpEvt->fHLTResult[a] == 1  ) {
      HLT_Path = true;
      //cout << Path << " fired!!!! "  << endl;
    }
  }
  return HLT_Path;
}


void xsReader::candidateSelection(int mode){

  fCandY = fCandPt = fCandMass = -1.; 
  fpCand = 0;
  fGenCandY = fGenCandPt = -1.;
  fgCand = 0;
  fMuon1Eta = fMuon1Pt = fMuon2Eta = fMuon2Pt = -1.;
  fGenMuon1Eta = fGenMuon1Pt = fGenMuon2Eta = fGenMuon2Pt = -1.;
  TAnaCand *pCand(0);
  vector<int> lCands, lCands_CT, lCands_CT_M1T, lCands_CT_M1T_M2T, lCands_CT_M1T_M2T_Pt1, lCands_CT_M1T_M2T_Pt1_Pt2, lCands_CT_M1T_M2T_Pt1_Pt2_CHI2; 

  for (int iC = 0; iC < fpEvt->nCands(); ++iC) {
    pCand = fpEvt->getCand(iC);
    if ( MODE == 1 ) AnaEff(pCand, 1); // 1 -- # of TruthCand before Cuts, 2 -- # of TruthCand After Cuts 
    lCands.push_back(iC);
    if (TYPE != pCand->fType) continue;
    if (pCand->fMass < MASSLO) continue;
    if (pCand->fMass > MASSHI) continue;
    lCands_CT.push_back(iC);
    TAnaTrack *pl1 = fpEvt->getSigTrack(pCand->fSig1); 
    TAnaTrack *pl2 = fpEvt->getSigTrack(pCand->fSig2);
    if ( pl1->fQ*pl2->fQ > 0 ) continue ;
    if ( (pl1->fMuID & MUTYPE1) != MUTYPE1 ) continue;
    lCands_CT_M1T.push_back(iC);
    if ( (pl2->fMuID & MUTYPE2) != MUTYPE2 ) continue;
    lCands_CT_M1T_M2T.push_back(iC);
    if ( (pl1->fPlab.Perp() > PTHI) || ( (fabs(pl1->fPlab.Eta()) < 1.2) && (pl1->fPlab.Perp() < PTLO) ) || (  (fabs(pl1->fPlab.Eta()) > 1.2) && (pl1->fPlab.Perp() < 3.) ) ) continue;
    //if ( (pl1->fPlab.Perp() > PTHI) || (pl1->fPlab.Perp() < PTLO) ) continue;
    if ( (pl1->fPlab.Eta() > ETAHI) || (pl1->fPlab.Eta() < ETALO) ) continue;
    lCands_CT_M1T_M2T_Pt1.push_back(iC);
    if ( (pl2->fPlab.Perp() > PTHI) || ( (fabs(pl2->fPlab.Eta()) < 1.2) && (pl2->fPlab.Perp() < PTLO) ) || (  (fabs(pl2->fPlab.Eta()) > 1.2) && (pl2->fPlab.Perp() < 3.) ) ) continue;
    //if ( (pl2->fPlab.Perp() > PTHI) || (pl2->fPlab.Perp() < PTLO) ) continue;
    if ( (pl2->fPlab.Eta() > ETAHI) || (pl2->fPlab.Eta() < ETALO) ) continue;
    lCands_CT_M1T_M2T_Pt1_Pt2.push_back(iC);
    if ( pCand->fVtx.fChi2 > CHI2 ) continue;
    lCands_CT_M1T_M2T_Pt1_Pt2_CHI2.push_back(iC);
  }
  
    
  int nc(lCands.size()); int nc_CT(lCands_CT.size()); int nc_CT_M1T(lCands_CT_M1T.size()); int nc_CT_M1T_M2T(lCands_CT_M1T_M2T.size());
  int nc_CT_M1T_M2T_Pt1(lCands_CT_M1T_M2T_Pt1.size()); int nc_CT_M1T_M2T_Pt1_Pt2(lCands_CT_M1T_M2T_Pt1_Pt2.size());
  int nc_CT_M1T_M2T_Pt1_Pt2_CHI2(lCands_CT_M1T_M2T_Pt1_Pt2_CHI2.size());
  ((TH1D*)fpHistFile->Get("n2"))->Fill(nc); 
  ((TH1D*)fpHistFile->Get("n2_CandType"))->Fill(nc_CT);
  ((TH1D*)fpHistFile->Get("n2_CandType_MuType1"))->Fill(nc_CT_M1T);
  ((TH1D*)fpHistFile->Get("n2_CandType_MuType1&2"))->Fill(nc_CT_M1T_M2T);
  ((TH1D*)fpHistFile->Get("n2_CandType_MuType1&2_Pt1"))->Fill(nc_CT_M1T_M2T_Pt1);
  ((TH1D*)fpHistFile->Get("n2_CandType_MuType1&2_Pt1&2"))->Fill(nc_CT_M1T_M2T_Pt1_Pt2);
  ((TH1D*)fpHistFile->Get("n2_CandType_MuType1&2_Pt1&2_Chi2"))->Fill(nc_CT_M1T_M2T_Pt1_Pt2_CHI2);
  
  ((TH1D*)fpHistFile->Get("n2_cuts"))->AddBinContent(10, nc);
  ((TH1D*)fpHistFile->Get("n2_cuts"))->GetXaxis()->SetBinLabel(10, "NOCUT");
  ((TH1D*)fpHistFile->Get("n2_cuts"))->AddBinContent(12, nc_CT);
  ((TH1D*)fpHistFile->Get("n2_cuts"))->GetXaxis()->SetBinLabel(12, Form("Type^{Cand}=%d",TYPE));
  ((TH1D*)fpHistFile->Get("n2_cuts"))->AddBinContent(14, nc_CT_M1T);
  ((TH1D*)fpHistFile->Get("n2_cuts"))->GetXaxis()->SetBinLabel(14, Form("ID^{#mu_{1}}=%d",MUTYPE1));
  ((TH1D*)fpHistFile->Get("n2_cuts"))->AddBinContent(16, nc_CT_M1T_M2T);
  ((TH1D*)fpHistFile->Get("n2_cuts"))->GetXaxis()->SetBinLabel(16, Form("ID^{#mu_{2}}=%d",MUTYPE2));
  ((TH1D*)fpHistFile->Get("n2_cuts"))->AddBinContent(18, nc_CT_M1T_M2T_Pt1);
  ((TH1D*)fpHistFile->Get("n2_cuts"))->GetXaxis()->SetBinLabel(18, Form("p_{T}^{#mu_{1}}=%.1f",PTLO));
  ((TH1D*)fpHistFile->Get("n2_cuts"))->AddBinContent(20, nc_CT_M1T_M2T_Pt1_Pt2);
  ((TH1D*)fpHistFile->Get("n2_cuts"))->GetXaxis()->SetBinLabel(20, Form("p_{T}^{#mu_{2}}=%.1f",PTLO));
  ((TH1D*)fpHistFile->Get("n2_cuts"))->AddBinContent(22, nc_CT_M1T_M2T_Pt1_Pt2_CHI2);
  ((TH1D*)fpHistFile->Get("n2_cuts"))->GetXaxis()->SetBinLabel(22, Form("#chi^{2}<%.1f",CHI2));

  
  if (0 == nc_CT_M1T_M2T_Pt1_Pt2_CHI2) return; 
  int best(0);
  if (nc_CT_M1T_M2T_Pt1_Pt2_CHI2 > 1) {
    //cout << "MORE THAN ONE CANDIDATE  " << nc_CT_M1T_M2T_Pt1_Pt2_CHI2   <<  endl;
    double ptMax(0.), pt(0.);
    double maxDocaMax(99.), maxDoca(0.);
    double chi2Max(99.), chi2(0.);
    for (unsigned int iC = 0; iC < lCands_CT_M1T_M2T_Pt1_Pt2_CHI2.size(); ++iC) {
      pCand = fpEvt->getCand(lCands_CT_M1T_M2T_Pt1_Pt2_CHI2[iC]);       
      if ( mode == 1 ){
	pt = pCand->fPlab.Perp(); 
	if (pt > ptMax) {
	  best = lCands_CT_M1T_M2T_Pt1_Pt2_CHI2[iC]; 
	  ptMax = pt;
	}
      } else if ( mode == 2 ){
	maxDoca = pCand->fMaxDoca;
	if (maxDoca < maxDocaMax) {
	  best = lCands_CT_M1T_M2T_Pt1_Pt2_CHI2[iC]; 
	  maxDocaMax = maxDoca;
	  }
      } else if ( mode == 3 ){
	chi2 = pCand->fVtx.fChi2;
	  if (chi2 < chi2Max) {
	    best = lCands_CT_M1T_M2T_Pt1_Pt2_CHI2[iC]; 
	    chi2Max = chi2;
	  }
      } 	
    }
  } else if (nc_CT_M1T_M2T_Pt1_Pt2_CHI2 == 1) {best = lCands_CT_M1T_M2T_Pt1_Pt2_CHI2[0];}
  
  int truth(0);
  TLorentzVector Cand, gCand;
  if ( best > -1 ) {
    fpCand = fpEvt->getCand(best);
    if ( MODE == 1 ) AnaEff(fpCand, 2);
    fCandPt   = fpCand->fPlab.Perp();
    fCandMass = fpCand->fMass;
    Cand.SetPtEtaPhiM(fpCand->fPlab.Perp(),fpCand->fPlab.Eta(),fpCand->fPlab.Phi(),fpCand->fMass);
    fCandY = Cand.Rapidity();
    TAnaTrack *pl1 = fpEvt->getSigTrack(fpCand->fSig1); 
    TAnaTrack *pl2 = fpEvt->getSigTrack(fpCand->fSig2);
    if ( (pl1->fGenIndex > -1) && (pl2->fGenIndex > -1) && (pl1->fGenIndex != pl2->fGenIndex) ){
      TGenCand  *gl1 = fpEvt->getGenCand(pl1->fGenIndex);
      TGenCand  *gl2 = fpEvt->getGenCand(pl2->fGenIndex);
      if ( gl1->fMom1 == gl2->fMom1 ) {
	TGenCand  *genCand = fpEvt->getGenCand(gl1->fMom1);
	((TH1D*)fpHistFile->Get("TruthCand"))->Fill(genCand->fID);
	if ( genCand->fID == RESTYPE ) {
	  truth++;
	  fgCand = fpEvt->getGenCand(gl1->fMom1); 
	  fGenCandPt   = fgCand->fP.Perp();
	  gCand.SetPtEtaPhiE(fgCand->fP.Perp(),fgCand->fP.Eta(),fgCand->fP.Phi(),fgCand->fP.Energy());
	  fGenCandY = gCand.Rapidity();
	  fGenMuon1Pt = gl1->fP.Perp(); fGenMuon2Pt = gl2->fP.Perp(); fMuon1Pt = pl1->fPlab.Perp(); fMuon2Pt = pl2->fPlab.Perp(); 
	  fGenMuon1Eta = gl1->fP.Eta(); fGenMuon2Eta = gl2->fP.Eta(); fMuon1Eta = pl1->fPlab.Eta(); fMuon2Eta = pl2->fPlab.Eta();
	}
	((TH1D*)fpHistFile->Get("n2_cuts"))->AddBinContent(2, truth);
	((TH1D*)fpHistFile->Get("n2_cuts"))->GetXaxis()->SetBinLabel(2, Form("TruthCand"));	
      }	
    }
  }
  
  
}

void xsReader::AnaEff(TAnaCand *pCand, int mode) {
  
  TLorentzVector Cand;
  int truth(0);
  TAnaTrack *pl1 = fpEvt->getSigTrack(pCand->fSig1); 
  TAnaTrack *pl2 = fpEvt->getSigTrack(pCand->fSig2);
  
  if ( (pl1->fGenIndex > -1) && (pl2->fGenIndex > -1) && (pl1->fGenIndex != pl2->fGenIndex)  ){
    TGenCand  *gl1 = fpEvt->getGenCand(pl1->fGenIndex);
    TGenCand  *gl2 = fpEvt->getGenCand(pl2->fGenIndex);
    if ( (gl1->fMom1 == gl2->fMom1) && ( gl1->fMom1 > -1 ) && ( gl2->fMom1 > -1 )  ) {
      TGenCand  *genCand = fpEvt->getGenCand(gl1->fMom1);
      if ( (genCand->fID == RESTYPE) && (genCand->fStatus == 2) ) {
	truth++;
      }
      
      if ( mode == 1 ) ((TH1D*)fpHistFile->Get(Form("AnaEff_%.1dS,OverAll", UPSTYPE)))->AddBinContent(2,truth);
      if ( mode == 2 ) ((TH1D*)fpHistFile->Get(Form("AnaEff_%.1dS,OverAll", UPSTYPE)))->AddBinContent(8,truth);
      
      Cand.SetPtEtaPhiM(pCand->fPlab.Perp(),pCand->fPlab.Eta(),pCand->fPlab.Phi(),pCand->fMass);
      for ( int iy = 0; iy < fNy; ++iy ){
	for ( int ipt = 0; ipt < fNpt; ++ipt ){
	  if( ( Cand.Rapidity() < fYbin[iy+1] ) && ( Cand.Rapidity() >= fYbin[iy] ) ){
	    if ( ( pCand->fPlab.Perp() >= fPTbin[ipt] ) && ( pCand->fPlab.Perp() < fPTbin[ipt+1] ) ){
	      if ( mode == 1 ) ((TH1D*)fpHistFile->Get(Form("AnaEff_%.1dS,rapidity%.1f_%.1f,pt%.1f_%.1f", UPSTYPE,  fYbin[iy], fYbin[iy+1], fPTbin[ipt], fPTbin[ipt+1])))->AddBinContent(2,truth);
	      if ( mode == 2 ) ((TH1D*)fpHistFile->Get(Form("AnaEff_%.1dS,rapidity%.1f_%.1f,pt%.1f_%.1f", UPSTYPE,  fYbin[iy], fYbin[iy+1], fPTbin[ipt], fPTbin[ipt+1])))->AddBinContent(8,truth);
	    }
	  }
	}
      }
      
    }	
  }
  
}
// ----------------------------------------------------------------------
void xsReader::fillCandHist() {
  
  ((TH1D*)fpHistFile->Get("CandMass"))->Fill(fCandMass,fWeight);
  ((TH1D*)fpHistFile->Get("CandPt"))->Fill(fCandPt,fWeight);
  ((TH1D*)fpHistFile->Get("CandRapidity"))->Fill(fCandY,fWeight);
  ((TH1D*)fpHistFile->Get("CandEta"))->Fill(fpCand->fPlab.Eta(),fWeight);
  ((TH1D*)fpHistFile->Get("UpsilonMass"))->Fill(fCandMass,fWeight);
    
  for ( int iy = 0; iy < fNy; ++iy ){
    for ( int ipt = 0; ipt < fNpt; ++ipt ){
      if ( ( fCandY >= fYbin[iy] ) && ( fCandY < fYbin[iy+1] ) ){
	if ( ( fCandPt >= fPTbin[ipt] ) && ( fCandPt < fPTbin[ipt+1] ) ){
	  ((TH1D*)fpHistFile->Get(Form("UpsilonMass,rapidity%.1f_%.1f,pt%.1f_%.1f", fYbin[iy], fYbin[iy+1], fPTbin[ipt], fPTbin[ipt+1])))->Fill(fCandMass,fWeight);
	}
      }
    }
  }
}


// ----------------------------------------------------------------------
void xsReader::MCstudy(){
  
  double deltaPtCand(-99), deltaYCand(-99), deltaPtMuon1(-99), deltaEtaMuon1(-99), deltaPtMuon2(-99), deltaEtaMuon2(-99);
  ((TH2D*)fpHistFile->Get("PtResolution_Cand"))->Fill(fGenCandPt,fCandPt);
  ((TH2D*)fpHistFile->Get("PtResolution_Cand"))->GetXaxis()->SetTitle(Form("P_{T}^{GenCand}"));
  ((TH2D*)fpHistFile->Get("PtResolution_Cand"))->GetYaxis()->SetTitle(Form("P_{T}^{RecoCand}"));
  
  deltaPtCand = (fCandPt - fGenCandPt)/fGenCandPt;
  ((TH1D*)fpHistFile->Get("DeltaPtoverPt_Cand"))->Fill(deltaPtCand);
  
  ((TH2D*)fpHistFile->Get("YResolution_Cand"))->Fill(fGenCandY,fCandY);
  ((TH2D*)fpHistFile->Get("YResolution_Cand"))->GetXaxis()->SetTitle(Form("Y^{GenCand}"));
  ((TH2D*)fpHistFile->Get("YResolution_Cand"))->GetYaxis()->SetTitle(Form("Y^{RecoCand}")); 
  
  deltaYCand = (fCandY - fGenCandY)/fGenCandY;
  ((TH1D*)fpHistFile->Get("DeltaYoverY_Cand"))->Fill(deltaYCand);  
  
  ((TH2D*)fpHistFile->Get("PtResolution_Muon"))->Fill(fGenMuon1Pt,fMuon1Pt);
  ((TH2D*)fpHistFile->Get("PtResolution_Muon"))->Fill(fGenMuon2Pt,fMuon2Pt);
  ((TH2D*)fpHistFile->Get("PtResolution_Muon"))->GetXaxis()->SetTitle(Form("P_{T}^{GenMuon}"));
  ((TH2D*)fpHistFile->Get("PtResolution_Muon"))->GetYaxis()->SetTitle(Form("P_{T}^{Recomuon}"));
  
  deltaPtMuon1 = (fMuon1Pt - fGenMuon1Pt)/fGenMuon1Pt;
  deltaPtMuon2 = (fMuon2Pt - fGenMuon2Pt)/fGenMuon2Pt;
  ((TH1D*)fpHistFile->Get("DeltaPtoverPt_Muon"))->Fill(deltaPtMuon1);
  ((TH1D*)fpHistFile->Get("DeltaPtoverPt_Muon"))->Fill(deltaPtMuon2);
  
  ((TH2D*)fpHistFile->Get("#etaResolution_Muon"))->Fill(fGenMuon1Eta,fMuon1Eta);
  ((TH2D*)fpHistFile->Get("#etaResolution_Muon"))->Fill(fGenMuon2Eta,fMuon2Eta);
  ((TH2D*)fpHistFile->Get("#etaResolution_Muon"))->GetXaxis()->SetTitle(Form("#eta^{GenMuon}"));
  ((TH2D*)fpHistFile->Get("#etaResolution_Muon"))->GetYaxis()->SetTitle(Form("#eta^{Recomuon}"));
  
  deltaEtaMuon1 = (fMuon1Eta - fGenMuon1Eta)/fGenMuon1Eta;
  deltaEtaMuon2 = (fMuon2Eta - fGenMuon2Eta)/fGenMuon2Eta;
  ((TH1D*)fpHistFile->Get("DeltaEtaoverEta_Muon"))->Fill(deltaEtaMuon1);
  ((TH1D*)fpHistFile->Get("DeltaEtaoverEta_Muon"))->Fill(deltaEtaMuon2);
  
  ((TH1D*)fpHistFile->Get("MaxDoca_Cand"))->Fill(fpCand->fMaxDoca);
  
}

// ----------------------------------------------------------------------
void xsReader::calculateWeights(int mode){
  double effID1(-99); double effID2(-99);
  double effTR1(-99); double effTR2(-99);
  double MuIdWeight(-99); double TrigWeight(-99);
  TAnaTrack *pl1 = fpEvt->getSigTrack(fpCand->fSig1); 
  TAnaTrack *pl2 = fpEvt->getSigTrack(fpCand->fSig2);
  
  if ( pl1->fQ > 0 ){
    effID1 = fPidTableMuIDPos->effD(pl1->fPlab.Perp(), pl1->fPlab.Eta(), 0.);
    effTR1 = fPidTableTrigPos->effD(pl1->fPlab.Perp(), pl1->fPlab.Eta(), 0.);

  } else if ( pl1->fQ < 0 ){
    effID1 = fPidTableMuIDNeg->effD(pl1->fPlab.Perp(), pl1->fPlab.Eta(), 0.);
    effTR1 = fPidTableTrigNeg->effD(pl1->fPlab.Perp(), pl1->fPlab.Eta(), 0.);
  }
  
  if ( pl2->fQ > 0 ){
    effID2 = fPidTableMuIDPos->effD(pl2->fPlab.Perp(), pl2->fPlab.Eta(), 0.);
    effTR2 = fPidTableTrigPos->effD(pl2->fPlab.Perp(), pl2->fPlab.Eta(), 0.);
  }  else if ( pl2->fQ < 0 ){
    effID2 = fPidTableMuIDNeg->effD(pl2->fPlab.Perp(), pl2->fPlab.Eta(), 0.);
    effTR2 = fPidTableTrigNeg->effD(pl2->fPlab.Perp(), pl2->fPlab.Eta(), 0.);
  }
  
  fWeight = 1/(effID1*effID2*effTR1*effTR2);
  
  fWeight = 1;
  
  MuIdWeight = effID1*effID2;
  TrigWeight = effTR1*effTR2;
  
  
  for ( int iy = 0; iy < fNy; ++iy ){
    for ( int ipt = 0; ipt < fNpt; ++ipt ){
      if ( ( fCandY >= fYbin[iy] ) && ( fCandY < fYbin[iy+1] ) ){
	if ( ( fCandPt >= fPTbin[ipt] ) && ( fCandPt < fPTbin[ipt+1] ) ){
	  ((TH1D*)fpHistFile->Get(Form("MuIDEff_%.1dS,rapidity%.1f_%.1f,pt%.1f_%.1f",UPSTYPE, fYbin[iy], fYbin[iy+1], fPTbin[ipt], fPTbin[ipt+1])))->Fill(MuIdWeight);
	  ((TH1D*)fpHistFile->Get(Form("TrigEff_%.1dS,rapidity%.1f_%.1f,pt%.1f_%.1f",UPSTYPE, fYbin[iy], fYbin[iy+1], fPTbin[ipt], fPTbin[ipt+1])))->Fill(TrigWeight);
	}
      }
    }
  }  
  
  
  
  
  
  
}
// ----------------------------------------------------------------------
bool xsReader::isMatchedToTrig(TAnaTrack *pTag, TString Label){
	bool a=false;
	TTrgObj *pTrig;
	TLorentzVector tag;
	tag.SetPtEtaPhiM(pTag->fPlab.Pt(), pTag->fPlab.Eta(), pTag->fPlab.Phi(), 0.);
	((TH1D*)fpHistFile->Get("tag_pt"))->Fill(pTag->fPlab.Pt());
	for (int s = 0; s < fpEvt->nTrgObj() ; ++s) {
    		pTrig = fpEvt->getTrgObj(s);
		//cout << "pTrig->fLabel is " << pTrig->fLabel << endl;
		
		if ( !(Label.CompareTo(pTrig->fLabel)) ) {
			cout << "pTrig->fLabel is " << pTrig->fLabel << endl;;
			double dR = tag.DeltaR(pTrig->fP);
	        	double dEta = TMath::Abs(pTag->fPlab.Eta() - pTrig->fP.Eta());
			double dPhi = TMath::Abs(pTag->fPlab.Phi() - pTrig->fP.Phi());
			((TH1D*)fpHistFile->Get("trig_dR"))->Fill(dR);
			((TH1D*)fpHistFile->Get("trig_dEta"))->Fill(dEta);
			((TH1D*)fpHistFile->Get("trig_dPhi"))->Fill(dPhi);
		//	if ( (dPhi < 0.7) && (dPhi > 0.3) ) ((TH1D*)fpHistFile->Get("trig_dEta_aftercut"))->Fill(dEta);		// Used for J/Psi
			if ( (dPhi < 0.55) && (dPhi > 0.15) ) ((TH1D*)fpHistFile->Get("trig_dEta_aftercut"))->Fill(dEta);		// Usedfor Ups1S
			if ( (dPhi < 0.7) && (dPhi > 0.3) && (dEta < 0.14)) a=true;				
	
		}
  	}
	return a;
}

// ----------------------------------------------------------------------
void xsReader::fillHist() {


}

// ----------------------------------------------------------------------
void xsReader::bookHist() {
  
  fBin = BIN;
  fMassLow = MASSLO;
  fMassHigh = MASSHI;
  
  TH1 *h;
  TH2 *k;
 
  h = new TH1D("r101a", "(Matched) Muon -- Pt, Neg", fNpt, fPTbin);
  k = new TH2D("mt,pt-eta", "mt,pt-eta", fNpt, fPTbin, fNy, fYbin);
  k = new TH2D("mmmbar,pt-eta", "mmbar,pt-eta", fNpt, fPTbin, fNy, fYbin);
  cout << "--> xsReader> bookHist> " << endl;
  
  
  // Acceptance Histograms
  k = new TH2D(Form("AllGenRes_%1.dS",  UPSTYPE), Form("AllGenRes_%1.dS", UPSTYPE), fNy, fYbin, fNpt, fPTbin); 
  k = new TH2D(Form("RecoGenRes_%1.dS", UPSTYPE), Form("RecoGenRes_%1.dS", UPSTYPE), fNy, fYbin, fNpt, fPTbin); 
  ((TH2D*)fpHistFile->Get(Form("AllGenRes_%.1dS", UPSTYPE)))->Sumw2();
  ((TH2D*)fpHistFile->Get(Form("RecoGenRes_%.1dS", UPSTYPE)))->Sumw2();
  
  // candidateSelection() histograms
  h = new TH1D("n2_cuts", "n2_cuts", 100, 0., 100.);
  h = new TH1D("n2", "ncand", 20, 0, 20.);
  h = new TH1D("n2_CandType", "ncand_CandType", 20, 0, 20.);
  h = new TH1D("n2_CandType_MuType1", "ncand_CandType_MuType1", 20, 0, 20.);
  h = new TH1D("n2_CandType_MuType1&2", "ncand_CandType_MuType1&2", 20, 0, 20.);
  h = new TH1D("n2_CandType_MuType1&2_Pt1", "ncand_CandType_MuType1&2_Pt1", 20, 0, 20.);
  h = new TH1D("n2_CandType_MuType1&2_Pt1&2", "ncand_CandType_MuType1&2_Pt1&2", 20, 0, 20.);
  h = new TH1D("n2_CandType_MuType1&2_Pt1&2_Chi2", "ncand_CandType_MuType1&2_Pt1&2_Chi2", 20, 0, 20.);
  h = new TH1D("TruthCand", "TruthCand", 10, 550., 560.);
  
  
  // MuID Efficiency Histograms
  for ( int iy = 0; iy < fNy; ++iy ){
    for ( int ipt = 0; ipt < fNpt; ++ipt ){
      h = new TH1D(Form("MuIDEff_%.1dS,rapidity%.1f_%.1f,pt%.1f_%.1f", UPSTYPE, fYbin[iy], fYbin[iy+1], fPTbin[ipt], fPTbin[ipt+1]),
		   Form("MuIDEff_%.1dS,rapidity%.1f_%.1f,pt%.1f_%.1f", UPSTYPE, fYbin[iy], fYbin[iy+1], fPTbin[ipt], fPTbin[ipt+1]),
		   100, 0., 1.);  
      ((TH1D*)fpHistFile->Get(Form("MuIDEff_%.1dS,rapidity%.1f_%.1f,pt%.1f_%.1f", UPSTYPE, fYbin[iy], fYbin[iy+1], fPTbin[ipt], fPTbin[ipt+1])))->Sumw2(); 
    }
  }
  
  
  // Trig Efficiency Histograms
  for ( int iy = 0; iy < fNy; ++iy ){
    for ( int ipt = 0; ipt < fNpt; ++ipt ){
      h = new TH1D(Form("TrigEff_%.1dS,rapidity%.1f_%.1f,pt%.1f_%.1f", UPSTYPE, fYbin[iy], fYbin[iy+1], fPTbin[ipt], fPTbin[ipt+1]),
		   Form("TrigEff_%.1dS,rapidity%.1f_%.1f,pt%.1f_%.1f", UPSTYPE, fYbin[iy], fYbin[iy+1], fPTbin[ipt], fPTbin[ipt+1]),
		   100, 0., 1.);  
      ((TH1D*)fpHistFile->Get(Form("TrigEff_%.1dS,rapidity%.1f_%.1f,pt%.1f_%.1f", UPSTYPE, fYbin[iy], fYbin[iy+1], fPTbin[ipt], fPTbin[ipt+1])))->Sumw2(); 
    }
  }  
  
  // Analysis Efficiency Histograms
  for ( int iy = 0; iy < fNy; ++iy ){
    for ( int ipt = 0; ipt < fNpt; ++ipt ){
      h = new TH1D(Form("AnaEff_%.1dS,rapidity%.1f_%.1f,pt%.1f_%.1f", UPSTYPE, fYbin[iy], fYbin[iy+1], fPTbin[ipt], fPTbin[ipt+1]),
		   Form("AnaEff_%.1dS,rapidity%.1f_%.1f,pt%.1f_%.1f", UPSTYPE, fYbin[iy], fYbin[iy+1], fPTbin[ipt], fPTbin[ipt+1]),
		   10, 0., 10.);
      ((TH1D*)fpHistFile->Get(Form("AnaEff_%.1dS,rapidity%.1f_%.1f,pt%.1f_%.1f", UPSTYPE,  fYbin[iy], fYbin[iy+1], fPTbin[ipt], fPTbin[ipt+1])))->GetXaxis()->SetBinLabel(2, Form("TruthCand"));
      ((TH1D*)fpHistFile->Get(Form("AnaEff_%.1dS,rapidity%.1f_%.1f,pt%.1f_%.1f", UPSTYPE,  fYbin[iy], fYbin[iy+1], fPTbin[ipt], fPTbin[ipt+1])))->GetXaxis()->SetBinLabel(8, Form("TruthCand_AfterCuts"));
      ((TH1D*)fpHistFile->Get(Form("AnaEff_%.1dS,rapidity%.1f_%.1f,pt%.1f_%.1f", UPSTYPE,  fYbin[iy], fYbin[iy+1], fPTbin[ipt], fPTbin[ipt+1])))->Sumw2(); 
    }	
  }
  
  h = new TH1D(Form("AnaEff_%.1dS,OverAll", UPSTYPE), Form("AnaEff_%.1dS,OverAll", UPSTYPE), 10, 0., 10.);
  ((TH1D*)fpHistFile->Get(Form("AnaEff_%.1dS,OverAll", UPSTYPE)))->GetXaxis()->SetBinLabel(2, Form("TruthCand"));;
  ((TH1D*)fpHistFile->Get(Form("AnaEff_%.1dS,OverAll", UPSTYPE)))->GetXaxis()->SetBinLabel(8, Form("TruthCand_AfterCuts"));;
  ((TH1D*)fpHistFile->Get(Form("AnaEff_%.1dS,OverAll", UPSTYPE)))->Sumw2();
  
  
  // fillCandHist() histograms
  h = new TH1D("CandMass", "CandMass", 44, 1, 12.);
  h = new TH1D("CandPt", "CandPt", 80, 0, 40.);
  h = new TH1D("CandRapidity", "CandRapidity", 80, -4, 4.);
  h = new TH1D("CandEta", "CandEta", 80, -4, 4.);
  h = new TH1D("UpsilonMass", "UpsilonMass", BIN, fMassLow, fMassHigh); 
  
  for ( int iy = 0; iy < fNy; ++iy ){
    for ( int ipt = 0; ipt < fNpt; ++ipt ){
      h = new TH1D(Form("UpsilonMass,rapidity%.1f_%.1f,pt%.1f_%.1f", fYbin[iy], fYbin[iy+1], fPTbin[ipt], fPTbin[ipt+1]),
		   Form("UpsilonMass,rapidity%.1f_%.1f,pt%.1f_%.1f", fYbin[iy], fYbin[iy+1], fPTbin[ipt], fPTbin[ipt+1]),
		   fBin, fMassLow, fMassHigh);
      ((TH1D*)fpHistFile->Get(Form("UpsilonMass,rapidity%.1f_%.1f,pt%.1f_%.1f",  fYbin[iy], fYbin[iy+1], fPTbin[ipt], fPTbin[ipt+1])))->Sumw2(); 
    }	
  }
  
  // MCstudy() histograms
  k = new TH2D("PtResolution_Cand", "PtResolution_Cand", 100, 0, 50, 100, 0, 50);
  k = new TH2D("YResolution_Cand", "YResolution_Cand", 100, -5, 5, 100, -5, 5);
  k = new TH2D("PtResolution_Muon", "PtResolution_Muon", 100, 0, 50, 100, 0, 50);
  k = new TH2D("#etaResolution_Muon", "#etaResolution_Muon", 80, -4, 4, 80, -4, 4);
  h = new TH1D("DeltaPtoverPt_Cand", "DeltaPtoverPt_Cand", 50, -0.1, 0.1);
  h = new TH1D("DeltaYoverY_Cand", "DeltaYoverY_Cand", 50, -0.05, 0.05);
  h = new TH1D("DeltaPtoverPt_Muon", "DeltaPtoverPt_Muon", 50, -0.1, 0.1);
  h = new TH1D("DeltaEtaoverEta_Muon", "DeltaEtaoverEta_Muon", 50, -0.05, 0.05); 
  h = new TH1D("MaxDoca_Cand", "MaxDoca_Cand", 60, 0., 0.03); 
  
  
  ///////////////////////////////////////////// ---- Reduced Tree
  fTree = new TTree("m", "m");
  fTree->Branch("m_um",  &m_um ,"m_um/F");
  fTree->Branch("m_uP",  &m_uP ,"m_uP/F");
  fTree->Branch("m_ue",  &m_ue ,"m_ue/F");
  fTree->Branch("m_up",  &m_up ,"m_up/F");
  fTree->Branch("m_gE",  &m_gE ,"m_gE/F");
  fTree->Branch("m_gP",  &m_gP ,"m_gP/F");
  fTree->Branch("m_ge",  &m_ge ,"m_ge/F");
  fTree->Branch("m_gp",  &m_gp ,"m_gp/F");
  fTree->Branch("m_xbm",  &m_xbm ,"m_xbm/F");
  fTree->Branch("m_xbid",  &m_xbid ,"m_xbid/I");
  fTree->Branch("m_dR",  &m_dR ,"m_dR/F");
  
  fTree1 = new TTree("nm", "nm");
  fTree1->Branch("um",  &um ,"um/F");
  fTree1->Branch("uP",  &uP ,"uP/F");
  fTree1->Branch("ue",  &ue ,"ue/F");
  fTree1->Branch("up",  &up ,"up/F");  
  fTree1->Branch("gE",  &gE ,"gE/F");
  fTree1->Branch("gP",  &gP ,"gP/F");
  fTree1->Branch("ge",  &ge ,"ge/F");
  fTree1->Branch("gp",  &gp ,"gp/F");
  fTree1->Branch("dR",  &dR ,"dR/F");
  fTree1->Branch("xbm",  &xbm ,"xbm/F");
  
  fTree2 = new TTree("mbg", "mbg");
  fTree2->Branch("mbg_um",  &mbg_um ,"mbg_um/F");
  fTree2->Branch("mbg_uP",  &mbg_uP ,"mbg_uP/F");
  fTree2->Branch("mbg_ue",  &mbg_ue ,"mbg_ue/F");
  fTree2->Branch("mbg_up",  &mbg_up ,"mbg_up/F");
  fTree2->Branch("mbg_gE",  &mbg_gE ,"mbg_gE/F");
  fTree2->Branch("mbg_gP",  &mbg_gP ,"mbg_gP/F");
  fTree2->Branch("mbg_ge",  &mbg_ge ,"mbg_ge/F");
  fTree2->Branch("mbg_gp",  &mbg_gp ,"mbg_gp/F");
  fTree2->Branch("mbg_xbm", &mbg_xbm ,"mbg_xbm/F");
  fTree2->Branch("mbg_dR",  &mbg_dR ,"mbg_dR/F");
    
  

  // x_b histos
  h = new TH1D("h","Histo", 10, 0., 10.);
  h = new TH1D("n","Number of Photons per Event", 100, 0., 100.);
  h = new TH1D("h0","Mass", 100, 9., 10.);
  h = new TH1D("h1","Photon Energy", 100, 0., 5.);
  h = new TH1D("h2","Mass_mumugamma", 40, 0.2, 0.6);
  h = new TH1D("h3","Mass_mumugamma x_b2", 40, 0.2, 0.6);
  h = new TH1D("h4","Mass_mumugamma x_b0", 40, 0.2, 0.6);
  h = new TH1D("h5","Mass_mumugamma x_b1", 40, 0.2, 0.6);
  h = new TH1D("h6","DiMuon Mass", 50, 8.7, 11.2);
  h = new TH1D("hGenAngle","hGenAngle", 1000, 0., 10.);
  h = new TH1D("hSgMatchedAngle","hSgMatchedAngle", 1000, 0., 10.);
  h = new TH1D("hBgMatchedAngle","hBgMatchedAngle", 1000, 0., 10.);
  h = new TH1D("hAngle","hAngle", 1000, 0., 10.);
  
 
  // trigger study
  h = new TH1D("hTriggerStudy","Trigger Study", 20, 0., 20.);
  
}


// --------------------------------------------------------------------------------------------------
void xsReader::readCuts(TString filename, int dump) {
  char  buffer[200];
  fCutFile = filename;
  if (dump) cout << "Reading " << fCutFile.Data() << " for xsReader cut settings" << endl;
  sprintf(buffer, "%s", fCutFile.Data());
  ifstream is(buffer);
  char CutName[100];
  char SetName[100];
  float CutValue;
  int ok(0);

  TString fn(fCutFile.Data());

  if (dump) {
    cout << "====================================" << endl;
    cout << "Cut file  " << fCutFile.Data() << endl;
    cout << "------------------------------------" << endl;
  }

  TH1D *hcuts = new TH1D("hcuts", "", 1000, 0., 1000.);
  hcuts->GetXaxis()->SetBinLabel(1, fn.Data());
  int ibin; 

  while (is.getline(buffer, 200, '\n')) {
    ok = 0;
    if (buffer[0] == '#') {continue;}
    if (buffer[0] == '/') {continue;}
    sscanf(buffer, "%s %f %s", CutName, &CutValue, SetName);

    if (!strcmp(CutName, "TYPE")) {
      TYPE = int(CutValue); ok = 1;
      if (dump) cout << "TYPE:           " << TYPE << endl;
    }
    
    if (!strcmp(CutName, "MODE")) {
      MODE = int(CutValue); ok = 1;
      if (dump) cout << "MODE:           " << MODE << endl;
    }
        
    if (!strcmp(CutName, "MUTYPE1")) {
      MUTYPE1 = int(CutValue); ok = 1;
      if (dump) cout << "MUTYPE1:           " << MUTYPE1 << endl;
    }    
    
    if (!strcmp(CutName, "MUTYPE2")) {
      MUTYPE2 = int(CutValue); ok = 1;
      if (dump) cout << "MUTYPE2:           " << MUTYPE2 << endl;
    }       
    
    if (!strcmp(CutName, "CHI2")) {
      CHI2 = CutValue; ok = 1;
      if (dump) cout << "CHI2:              " << CHI2 << endl;
    }   
    
    if (!strcmp(CutName, "RESTYPE")) {
      RESTYPE = int(CutValue); ok = 1;
      if (dump) cout << "RESTYPE:         " << RESTYPE << endl;
    }
    
    if (!strcmp(CutName, "UPSTYPE")) {
      UPSTYPE = int(CutValue); ok = 1;
      if (dump) cout << "UPSTYPE:         " << UPSTYPE << endl;
    }
    
    if (!strcmp(CutName, "MASSLO")) {
      MASSLO = CutValue; ok = 1;
      if (dump) cout << "MASSLO:          " << MASSLO << endl;
    }           
    
    if (!strcmp(CutName, "MASSHI")) {
      MASSHI = CutValue; ok = 1;
      if (dump) cout << "MASSHI:         " << MASSHI << endl;
    }   
    
    if (!strcmp(CutName, "BIN")) {
      BIN = int(CutValue); ok = 1;
      if (dump) cout << "BIN:              " << BIN << endl;
    }
    
    if (!strcmp(CutName, "HLTPATH")) {
      HLTPATH = SetName; ok = 1;
      if (dump) cout << "HLTPATH:   " << HLTPATH  << endl;
    } 
    
    if (!strcmp(CutName, "HLTPATH1")) {
      HLTPATH1 = SetName; ok = 1;
      if (dump) cout << "HLTPATH1:   " << HLTPATH1  << endl;
    }   
    
    if (!strcmp(CutName, "HLTPATH2")) {
      HLTPATH2 = SetName; ok = 1;
      if (dump) cout << "HLTPATH2:   " << HLTPATH2  << endl;
    }
     
     if (!strcmp(CutName, "HLTPATH3")) {
       HLTPATH3 = SetName; ok = 1;
       if (dump) cout << "HLTPATH3:   " << HLTPATH3  << endl;
    }   

    if (!strcmp(CutName, "PTLO")) {
      PTLO = CutValue; ok = 1;
      if (dump) cout << "PTLO:           " << PTLO << " GeV" << endl;
      ibin = 11;
      hcuts->SetBinContent(ibin, PTLO);
      hcuts->GetXaxis()->SetBinLabel(ibin, "p_{T}^{min}(l) [GeV]");
    }

    if (!strcmp(CutName, "PTHI")) {
      PTHI = CutValue; ok = 1;
      if (dump) cout << "PTHI:           " << PTHI << " GeV" << endl;
      ibin = 11;
      hcuts->SetBinContent(ibin, PTHI);
      hcuts->GetXaxis()->SetBinLabel(ibin, "p_{T}^{min}(l) [GeV]");
    }    
    
    if (!strcmp(CutName, "ETALO")) {
      ETALO = CutValue; ok = 1;
      if (dump) cout << "ETALO:           " << ETALO << endl;
      ibin = 13;
      hcuts->SetBinContent(ibin, ETALO);
      hcuts->GetXaxis()->SetBinLabel(ibin, "#eta_{T}^{min}(l)");
    }

    if (!strcmp(CutName, "ETAHI")) {
      ETAHI = CutValue; ok = 1;
      if (dump) cout << "ETAHI:           " << ETAHI << endl;
      ibin = 14;
      hcuts->SetBinContent(ibin, ETAHI);
      hcuts->GetXaxis()->SetBinLabel(ibin, "#eta_{T}^{max}(l)");
    }

    if (!ok) cout << "==> ERROR: Don't know about variable " << CutName << endl;
  }

  if (dump)  cout << "------------------------------------" << endl;
}

