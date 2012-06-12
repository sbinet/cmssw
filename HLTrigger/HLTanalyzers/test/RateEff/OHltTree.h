/////////////////////////////////////////////////////////
// This class has been automatically generated on Mon Sep 1 19:12:16
// 2008 by ROOT version 5.18/00a from TTree OHltTree/ found on file:
// TEST.root
//////////////////////////////////////////////////////////

#ifndef OHltTree_h
#define OHltTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TRandom3.h>
#include <TLorentzVector.h>
#include "Math/PtEtaPhiE4D.h"
#include "Math/PtEtaPhiM4D.h"
#include "Math/LorentzVector.h"

#include <vector>
#include <string>
#include <map>

#include "OHltConfig.h"
#include "OHltMenu.h"
#include "OHltRateCounter.h"

#include "L1GtLogicParser.h"

#include "TH1.h"
#include "TH2.h"


class OHltTree
{
public:
   TTree *fChain; //!pointer to the analyzed TTree or TChain
   Int_t fCurrent; //!current Tree number in a TChain

   // logic parser for m_l1SeedsLogicalExpression
   std::vector<L1GtLogicParser*> m_l1AlgoLogicParser;
   
   L1GtLogicParser* m_preFilterLogicParser;
   
   void SetLogicParser(std::string l1SeedsLogicalExpression);

   // Declaration of leaf types
   Int_t NohJetCal;
   Int_t NohJetCorCal;
   Int_t NohJetCorL1L2L3Cal;
   Int_t NrecoJetCal;
   Int_t NrecoJetCorCal;
   Int_t NrecoJetGen;
   Int_t NrecoTowCal;

   Float_t ohJetCalPt[43000]; //[NohJetCal]
   Float_t ohJetCalPhi[43000]; //[NohJetCal]
   Float_t ohJetCalEta[43000]; //[NohJetCal]
   Float_t ohJetCalE[43000]; //[NohJetCal]
   Float_t ohJetCalEMF[43000]; //[NohJetCal]
   Float_t ohJetCalN90[43000]; //[NohJetCal]
   Float_t ohJetCalN90hits[43000]; //[NohJetCal]

   Float_t ohJetCorCalPt[43000]; //[NohJetCorCal]
   Float_t ohJetCorCalPhi[43000]; //[NohJetCorCal]
   Float_t ohJetCorCalEta[43000]; //[NohJetCorCal]
   Float_t ohJetCorCalE[43000]; //[NohJetCorCal]
   Float_t ohJetCorCalEMF[43000]; //[NohJetCal]
   Float_t ohJetCorCalN90[43000]; //[NohJetCal]
   Float_t ohJetCorCalN90hits[43000]; //[NohJetCal]

   Float_t ohJetCorL1L2L3CalPt[43000]; //[NohJetCorL1L2L3Cal]
   Float_t ohJetCorL1L2L3CalPhi[43000]; //[NohJetCorL1L2L3Cal]
   Float_t ohJetCorL1L2L3CalEta[43000]; //[NohJetCorL1L2L3Cal]
   Float_t ohJetCorL1L2L3CalE[43000]; //[NohJetCorL1L2L3Cal]
   Float_t ohJetCorL1L2L3CalEMF[43000]; //[NohJetCal]
   Float_t ohJetCorL1L2L3CalN90[43000]; //[NohJetCal]
   Float_t ohJetCorL1L2L3CalN90hits[43000]; //[NohJetCal]

 
   Float_t recoJetCalPt[43000]; //[NrecoJetCal]
   Float_t recoJetCalPhi[43000]; //[NrecoJetCal]
   Float_t recoJetCalEta[43000]; //[NrecoJetCal]
   Float_t recoJetCalE[43000]; //[NrecoJetCal]
   Float_t recoJetCalEMF[43000]; //[NrecoJetCal]
   Float_t recoJetCalN90[43000]; //[NrecoJetCal]
   Float_t recoJetCalN90hits[43000]; //[NrecoJetCal]

   Float_t recoJetCorCalPt[43000]; //[NrecoJetCorCal]
   Float_t recoJetCorCalPhi[43000]; //[NrecoJetCorCal]
   Float_t recoJetCorCalEta[43000]; //[NrecoJetCorCal]
   Float_t recoJetCorCalE[43000]; //[NrecoJetCorCal]
   Float_t recoJetCorCalEMF[43000]; //[NrecoJetCal]
   Float_t recoJetCorCalN90[43000]; //[NrecoJetCal]
   Float_t recoJetCorCalN90hits[43000]; //[NrecoJetCal]

   Float_t recoJetGenPt[68000]; //[NrecoJetGen]
   Float_t recoJetGenPhi[68000]; //[NrecoJetGen]
   Float_t recoJetGenEta[68000]; //[NrecoJetGen]
   Float_t recoJetGenEt[68000]; //[NrecoJetGen]
   Float_t recoJetGenE[68000]; //[NrecoJetGen]
   Float_t recoTowEt[684000]; //[NrecoTowCal]
   Float_t recoTowEta[684000]; //[NrecoTowCal]
   Float_t recoTowPhi[684000]; //[NrecoTowCal]
   Float_t recoTowE[684000]; //[NrecoTowCal]
   Float_t recoTowEm[684000]; //[NrecoTowCal]
   Float_t recoTowHad[684000]; //[NrecoTowCal]
   Float_t recoTowOE[684000]; //[NrecoTowCal]

   Float_t recoMetCal;
   Float_t recoMetCalPhi;
   Float_t recoMetCalSum;
   Float_t recoMetGen;
   Float_t recoMetGenPhi;
   Float_t recoMetGenSum;
   Float_t recoHTCal;
   Float_t recoHTCalPhi;
   Float_t recoHTCalSum;
   Int_t NohTauL2;
   Float_t ohTauL2Pt[5000]; //[NohTauL2]
   Int_t NohTau;
   Float_t ohTauEta[5000]; //[NohTau]
   Float_t ohTauPhi[5000]; //[NohTau]
   Float_t ohTauPt[5000]; //[NohTau]
   Float_t ohTauEiso[5000]; //[NohTau]
   Float_t ohTauL25Tpt[5000]; //[NohTau]
   Int_t ohTauL25Tiso[5000]; //[NohTau]
   Float_t ohTauL3Tpt[5000]; //[NohTau]
   Int_t ohTauL3Tiso[5000]; //[NohTau]
   Int_t           NohpfTauTightCone; 
   Float_t         ohpfTauTightConeEta[5000];   //[NohTau] 
   Float_t         ohpfTauTightConePhi[5000];   //[NohTau] 
   Float_t         ohpfTauTightConePt[5000];   //[NohTau] 
   Float_t         ohpfTauTightConeLeadTrackPt[5000];   //[NoTau] 
   Float_t         ohpfTauTightConeGammaIso[5000]; 
   Float_t         ohpfTauTightConeTrkIso[5000]; 
   Int_t NohpfTau;
   Float_t ohpfTauEta[500];
   Float_t ohpfTauPhi[500];
   Float_t ohpfTauPt[500];
   Float_t ohpfTauJetPt[500];
   Float_t ohpfTauLeadTrackPt[500];
   Float_t ohpfTauLeadTrackVtxZ[500];
   Float_t ohpfTauLeadPionPt[500];
   Float_t ohpfTauTrkIso[500];
   Float_t ohpfTauGammaIso[500];
   Int_t   ohpfTauProngs[500];
   Int_t           NRecoPFTau;
   Float_t         pfTauEta[500];
   Float_t         pfTauPhi[500];
   Float_t         pfTauPt[500];
   Float_t         pfTauJetPt[500];
   Float_t         pfTauLeadTrackPt[500];
   Float_t         pfTauLeadPionPt[500];
   Int_t           pfTauTrkIso[500];
   Int_t           pfTauGammaIso[500];
   Int_t NohBJetL2; //
   Float_t ohBJetL2Et[5000]; //[NohBJetL2] 
   Float_t ohBJetL2Energy[5000]; //[NohBJetL2]  
   Float_t ohBJetL2Pt[5000]; //[NohBJetL2]  
   Float_t ohBJetL2Eta[5000]; //[NohBJetL2]  
   Float_t ohBJetL2Phi[5000]; //[NohBJetL2]  
   Int_t NohpfBJetL2; //
   Float_t ohpfBJetL2Et[10]; //[NohpfBJetL2] 
   Float_t ohpfBJetL2Energy[10]; //[NohpfBJetL2]  
   Float_t ohpfBJetL2Pt[10]; //[NohpfBJetL2]  
   Float_t ohpfBJetL2Eta[10]; //[NopfhBJetL2]  
   Float_t ohpfBJetL2Phi[10]; //[NopfhBJetL2]  
   Float_t ohpfBJetIPL3Tag[10]; //[NopfhBJetL2] 
   Int_t NohPixelTracksL3;
   Float_t ohPixelTracksL3Pt[10000]; //[NohPixelTracks]
   Float_t ohPixelTracksL3Eta[10000]; //[NohPixelTracks]
   Float_t ohPixelTracksL3Phi[10000]; //[NohPixelTracks]
   Float_t ohPixelTracksL3Vz[10000]; //[NohPixelTracks]
   Int_t ohIsoPixelTrackHBL2N;
   Float_t ohIsoPixelTrackHBL2P[200]; //[ohIsoPixelTrackHBL2N]
   Float_t ohIsoPixelTrackHBL2Eta[200]; //[ohIsoPixelTrackHBL2N]
   Float_t ohIsoPixelTrackHBL2Phi[200]; //[ohIsoPixelTrackHBL2N]
   Float_t ohIsoPixelTrackHBL2MaxNearP[200]; //[ohIsoPixelTrackHBL2N]
   Int_t ohIsoPixelTrackHBL3N;
   Float_t ohIsoPixelTrackHBL3P[200]; //[ohIsoPixelTrackHBL3N]
   Float_t ohIsoPixelTrackHBL3Eta[200]; //[ohIsoPixelTrackHBL3N]
   Float_t ohIsoPixelTrackHBL3Phi[200]; //[ohIsoPixelTrackHBL3N]
   Float_t ohIsoPixelTrackHBL3MaxNearP[200]; //[ohIsoPixelTrackHBL2N]
   Int_t ohIsoPixelTrackHEL2N;
   Float_t ohIsoPixelTrackHEL2P[200]; //[ohIsoPixelTrackHEL2N]
   Float_t ohIsoPixelTrackHEL2Eta[200]; //[ohIsoPixelTrackHEL2N]
   Float_t ohIsoPixelTrackHEL2Phi[200]; //[ohIsoPixelTrackHEL2N]
   Float_t ohIsoPixelTrackHEL2MaxNearP[200]; //[ohIsoPixelTrackHEL2N]
   Int_t ohIsoPixelTrackHEL3N;
   Float_t ohIsoPixelTrackHEL3P[200]; //[ohIsoPixelTrackHEL3N]
   Float_t ohIsoPixelTrackHEL3Eta[200]; //[ohIsoPixelTrackHEL3N]
   Float_t ohIsoPixelTrackHEL3Phi[200]; //[ohIsoPixelTrackHEL3N]
   Float_t ohIsoPixelTrackHEL3MaxNearP[200]; //[ohIsoPixelTrackHEL2N]
   Int_t NohBJetLife;
   Float_t ohBJetLifeL2E[1000]; //[NohBJetLife]
   Float_t ohBJetLifeL2ET[1000]; //[NohBJetLife]
   Float_t ohBJetLifeL2Eta[1000]; //[NohBJetLife]
   Float_t ohBJetLifeL2Phi[1000]; //[NohBJetLife]
   Float_t ohBJetLifeL25Discriminator[1000]; //[NohBJetLife]
   Float_t ohBJetLifeL3Discriminator[1000]; //[NohBJetLife]
   Int_t NohBJetPixelTracks;
   Float_t ohBJetLifePixelTrackPt[10000]; //[NohBJetPixelTracks]
   Float_t ohBJetLifePixelTrackEta[10000]; //[NohBJetPixelTracks]
   Float_t ohBJetLifePixelTrackPhi[10000]; //[NohBJetPixelTracks]
   Float_t ohBJetLifePixelTrackChi2[10000]; //[NohBJetPixelTracks]
   Int_t NohBJetRegionalTracks;
   Float_t ohBJetLifeRegionalTrackPt[10000]; //[NohBJetRegionalTracks]
   Float_t ohBJetLifeRegionalTrackEta[10000]; //[NohBJetRegionalTracks]
   Float_t ohBJetLifeRegionalTrackPhi[10000]; //[NohBJetRegionalTracks]
   Float_t ohBJetLifeRegionalTrackChi2[10000]; //[NohBJetRegionalTracks]
   Float_t ohBJetLifeRegionalSeedPt[10000]; //[NohBJetRegionalTracks]
   Float_t ohBJetLifeRegionalSeedEta[10000]; //[NohBJetRegionalTracks]
   Float_t ohBJetLifeRegionalSeedPhi[10000]; //[NohBJetRegionalTracks]
   Int_t NohBJetSoftm;
   Float_t ohBJetSoftmL2E[1000]; //[NohBJetSoftm]
   Float_t ohBJetSoftmL2ET[1000]; //[NohBJetSoftm]
   Float_t ohBJetSoftmL2Eta[1000]; //[NohBJetSoftm]
   Float_t ohBJetSoftmL2Phi[1000]; //[NohBJetSoftm]
   Int_t ohBJetSoftmL25Discriminator[1000]; //[NohBJetSoftm]
   Float_t ohBJetSoftmL3Discriminator[1000]; //[NohBJetSoftm]
   Int_t NohBJetL2Corrected;
   Float_t ohBJetPerfL2E[1000]; //[NohBJetL2Corrected]
   Float_t ohBJetPerfL2ET[1000]; //[NohBJetL2Corrected]
   Float_t ohBJetPerfL2Eta[1000]; //[NohBJetL2Corrected]
   Float_t ohBJetPerfL2Phi[1000]; //[NohBJetL2Corrected]
   Float_t ohBJetL2CorrectedEnergy[10]; //[NohBJetL2Corrected] 
   Float_t ohBJetL2CorrectedEt[10]; //[NohBJetL2Corrected] 
   Float_t ohBJetL2CorrectedPt[10]; //[NohBJetL2Corrected] 
   Float_t ohBJetL2CorrectedEta[10]; //[NohBJetL2Corrected] 
   Float_t ohBJetL2CorrectedPhi[10]; //[NohBJetL2Corrected] 
   Float_t ohBJetIPL25Tag[10]; //[NohBJetL2Corrected] 
   Float_t ohBJetIPL3Tag[10]; //[NohBJetL2Corrected] 
   Float_t ohBJetIPL25TagSingleTrack[10]; //[NohBJetL2Corrected] 
   Float_t ohBJetIPL3TagSingleTrack[10]; //[NohBJetL2Corrected] 
   Float_t ohBJetIPL25TagSingleTrackL1FastJet[10]; //[NohBJetL2Corrected] 
   Float_t ohBJetIPL3TagSingleTrackL1FastJet[10]; //[NohBJetL2Corrected] 
   Int_t ohBJetMuL25Tag[10]; //[NohBJetL2Corrected] 
   Float_t ohBJetMuL3Tag[10]; //[NohBJetL2Corrected] 
   Int_t ohBJetPerfL25Tag[10]; //[NohBJetL2Corrected] 
   Int_t ohBJetPerfL3Tag[10]; //[NohBJetL2Corrected] 
   Int_t NohBJetL2CorrectedL1FastJet;
   Float_t ohBJetL2CorrectedEnergyL1FastJet[10]; //[NohBJetL2CorrectedL1FastJet] 
   Float_t ohBJetL2CorrectedEtL1FastJet[10]; //[NohBJetL2CorrectedL1FastJet] 
   Float_t ohBJetL2CorrectedPtL1FastJet[10]; //[NohBJetL2CorrectedL1FastJet] 
   Float_t ohBJetL2CorrectedEtaL1FastJet[10]; //[NohBJetL2CorrectedL1FastJet] 
   Float_t ohBJetL2CorrectedPhiL1FastJet[10]; //[NohBJetL2CorrectedL1FastJet] 
   Float_t ohBJetIPL25TagL1FastJet[10]; //[NohBJetL2CorrectedL1FastJet] 
   Float_t ohBJetIPL3TagL1FastJet[10]; //[NohBJetL2CorrectedL1FastJet] 
   Int_t ohBJetPerfL25TagL1FastJet[10]; //[NohBJetL2CorrectedL1FastJet] 
   Int_t ohBJetPerfL3TagL1FastJet[10]; //[NohBJetL2CorrectedL1FastJet] 
   Int_t recoNVrt; // reconstructed vertex info
   Float_t recoVrtX[10]; //
   Float_t recoVrtY[10]; //
   Float_t recoVrtZ[10]; //
   Int_t recoVrtNtrk[10]; //
   Float_t recoVrtChi2[10]; //
   Float_t recoVrtNdof[10]; //
   Int_t NrecoElec;
   Float_t recoElecPt[4000]; //[NrecoElec]
   Float_t recoElecPhi[4000]; //[NrecoElec]
   Float_t recoElecEta[4000]; //[NrecoElec]
   Float_t recoElecEt[4000]; //[NrecoElec]
   Float_t recoElecE[4000]; //[NrecoElec]
   Int_t NrecoPhot;
   Float_t recoPhotPt[5000]; //[NrecoPhot]
   Float_t recoPhotPhi[5000]; //[NrecoPhot]
   Float_t recoPhotEta[5000]; //[NrecoPhot]
   Float_t recoPhotEt[5000]; //[NrecoPhot]
   Float_t recoPhotE[5000]; //[NrecoPhot]
   Int_t NohPhot;
   Float_t ohPhotEt[8000]; //[NohPhot]
   Float_t ohPhotEta[8000]; //[NohPhot]
   Float_t ohPhotPhi[8000]; //[NohPhot]
   Float_t ohPhotEiso[8000]; //[NohPhot]
   Float_t ohPhotHiso[8000]; //[NohPhot]
   Float_t ohPhotTiso[8000]; //[NohPhot]
   Int_t ohPhotL1iso[8000]; //[NohPhot]
   Float_t ohPhotR9[8000]; //[NohPhot] 
   Float_t ohPhotR9ID[8000]; //[NohPhot] 
   Float_t ohPhotHforHoverE[8000]; //[NohPhot] 
   Float_t ohPhotClusShap[8000]; //[NohPhot]
   Int_t NohEcalActiv;
   Float_t ohEcalActivEt[8000]; //[NohEcalActiv]
   Float_t ohEcalActivEta[8000]; //[NohEcalActiv]
   Float_t ohEcalActivPhi[8000]; //[NohEcalActiv]
   Float_t ohEcalActivEiso[8000]; //[NohEcalActiv]
   Float_t ohEcalActivHiso[8000]; //[NohEcalActiv]
   Float_t ohEcalActivTiso[8000]; //[NohEcalActiv]
   Int_t ohEcalActivL1iso[8000]; //[NohEcalActiv]
   Float_t ohEcalActivR9[8000]; //[NohEcalActiv] 
   Float_t ohEcalActivR9ID[8000]; //[NohEcalActiv] 
   Float_t ohEcalActivHforHoverE[8000]; //[NohEcalActiv] 
   Float_t ohEcalActivClusShap[8000]; //[NohEcalActiv]
   Int_t NohEle;
   Float_t ohEleClusShap[8000]; //[NohEle]
   Float_t ohEleDeta[8000]; //[NohEle]
   Float_t ohEleDphi[8000]; //[NohEle]
   Float_t ohEleEt[8000]; //[NohEle]
   Float_t ohEleEta[8000]; //[NohEle]
   Float_t ohElePhi[8000]; //[NohEle]
   Float_t ohEleE[8000]; //[NohEle]
   Float_t ohEleP[8000]; //[NohEle]
   Float_t ohEleHiso[8000]; //[NohEle]
   Float_t ohEleTiso[8000]; //[NohEle]
   Int_t ohEleL1iso[8000]; //[NohEle]
   Int_t ohElePixelSeeds[8000]; //[NohEle]
   Int_t ohEleNewSC[8000]; //[NohEle]
   Float_t ohEleR9[8000]; //[NohEle] 
   Float_t ohEleHforHoverE[8000]; //[NohEle] 
   Float_t ohEleEiso[8000]; //[NohEle] 
   Float_t ohEleVtxZ[8000]; //[NohEle]

   Int_t NohHFEle;
   Float_t ohHFElePt[10000]; //[NohHFEle]
   Float_t ohHFEleEta[10000]; //[NohHFEle]
   Int_t NohHFECALClus;
   Float_t ohHFEleClustere9e25[10000]; //[NohHFECALClus]
   Float_t ohHFEleClustere1e9[10000]; //[NohHFECALClus]
   Float_t ohHFEleClustereCOREe9[10000]; //[NohHFECALClus]
   Float_t ohHFEleClustereSeL[10000]; //[NohHFECALClus]
   Float_t ohHFEleCluster2Dcut[10000]; //[NohHFECALClus]
   Float_t ohHFEleClusterEta[10000]; //[NohHFECALClus]
   Float_t ohHFEleClusterPhi[10000]; //[NohHFECALClus]
	
   Int_t NrecoMuon;
   Float_t recoMuonPt[5000]; //[NrecoMuon]
   Float_t recoMuonPhi[5000]; //[NrecoMuon]
   Float_t recoMuonEta[5000]; //[NrecoMuon]
   Float_t recoMuonEt[5000]; //[NrecoMuon]
   Float_t recoMuonE[5000]; //[NrecoMuon]
   Int_t NohMuL2;
   Float_t ohMuL2Pt[2000]; //[NohMuL2]
   Float_t ohMuL2Phi[2000]; //[NohMuL2]
   Float_t ohMuL2Eta[2000]; //[NohMuL2]
   Int_t ohMuL2Chg[2000]; //[NohMuL2]
   Float_t ohMuL2PtErr[2000]; //[NohMuL2]
   Int_t ohMuL2Iso[2000]; //[NohMuL2]
   Float_t ohMuL2Dr[2000]; //[NohMuL2]
   Float_t ohMuL2Dz[2000]; //[NohMuL2]
   Int_t ohMuL2Nhits[2000]; //[NohMuL2]
   Int_t ohMuL2Nstat[2000]; //[NohMuL2]
   Int_t NohMuL3;
   Float_t ohMuL3Pt[1000]; //[NohMuL3]
   Float_t ohMuL3Phi[1000]; //[NohMuL3]
   Float_t ohMuL3Eta[1000]; //[NohMuL3]
   Int_t ohMuL3Chg[1000]; //[NohMuL3]
   Float_t ohMuL3PtErr[1000]; //[NohMuL3]
   Int_t ohMuL3Iso[1000]; //[NohMuL3]
   Float_t ohMuL3Dr[1000]; //[NohMuL3]
   Float_t ohMuL3Dz[1000]; //[NohMuL3]
   Int_t ohMuL3L2idx[1000]; //[NohMuL3]
   Int_t NpfMuon;
   Float_t pfMuonPt[1000]; //
   Float_t pfMuonPhi[1000]; //
   Float_t pfMuonEta[1000]; //
   Float_t pfMuonEt[1000]; //
   Float_t pfMuonE[1000]; //
   Int_t pfMuonCharge[1000]; //
   Int_t NohMuL2NoVtx; 
   Float_t ohMuL2NoVtxPt[2000]; //[NohMuL2NoVtx] 
   Float_t ohMuL2NoVtxPhi[2000]; //[NohMuL2NoVtx] 
   Float_t ohMuL2NoVtxEta[2000]; //[NohMuL2NoVtx] 
   Int_t ohMuL2NoVtxChg[2000]; //[NohMuL2NoVtx] 
   Float_t ohMuL2NoVtxPtErr[2000]; //[NohMuL2NoVtx] 
   Float_t ohMuL2NoVtxDr[2000]; //[NohMuL2NoVtx] 
   Float_t ohMuL2NoVtxDz[2000]; //[NohMuL2NoVtx]
   Int_t NohDiMu;
   Float_t ohDiMuDCA[1000]; //[NohDiMu]
   Int_t ohDiMu1st[1000]; //[NohDiMu]
   Int_t ohDiMu2nd[1000]; //[NohDiMu]
   Int_t NohDiMuVtx;
   Int_t ohDiMuVtx1st[1000]; //[NohDiMuVtx]
   Int_t ohDiMuVtx2nd[1000]; //[NohDiMuVtx]
   Float_t ohDiMuVtxChi2[1000]; //[NohDiMuVtx]
   Float_t ohDiMuVtxR[1000]; //[NohDiMuVtx]
   Float_t ohDiMuVtxRSig[1000]; //[NohDiMuVtx]
   Float_t ohDiMuVtxROverSig[1000]; //[NohDiMuVtx]
   Float_t ohDiMuVtxCosAlpha[1000]; //[NohDiMuVtx]
   Int_t NohOniaPixel;
   Float_t ohOniaPixelPt[200]; //[NohOniaPixel]
   Float_t ohOniaPixelPhi[200]; //[NohOniaPixel]
   Float_t ohOniaPixelEta[200]; //[NohOniaPixel]
   Int_t ohOniaPixelChg[200]; //[NohOniaPixel]
   Float_t ohOniaPixelDr[200]; //[NohOniaPixel]
   Float_t ohOniaPixelDz[200]; //[NohOniaPixel]
   Int_t ohOniaPixelHits[200]; //[NohOniaPixel]
   Float_t ohOniaPixelNormChi2[200]; //[NohOniaPixel]
   Int_t NohOniaTrack;
   Float_t ohOniaTrackPt[50]; //[NohOniaTrack]
   Float_t ohOniaTrackPhi[50]; //[NohOniaTrack]
   Float_t ohOniaTrackEta[50]; //[NohOniaTrack]
   Int_t ohOniaTrackChg[50]; //[NohOniaTrack]
   Float_t ohOniaTrackDr[50]; //[NohOniaTrack]
   Float_t ohOniaTrackDz[50]; //[NohOniaTrack]
   Int_t ohOniaTrackHits[50]; //[NohOniaTrack]
   Float_t ohOniaTrackNormChi2[50]; //[NohOniaTrack]
   Float_t ohHighestEnergyEERecHit;
   Float_t ohHighestEnergyEBRecHit;
   Float_t ohHighestEnergyHBHERecHit;
   Float_t ohHighestEnergyHORecHit;
   Float_t ohHighestEnergyHFRecHit;
   Int_t Nalcapi0clusters;
   Float_t ohAlcapi0ptClusAll[51]; //[Nalcapi0clusters] 
   Float_t ohAlcapi0etaClusAll[51]; //[Nalcapi0clusters] 
   Float_t ohAlcapi0phiClusAll[51]; //[Nalcapi0clusters] 
   Float_t ohAlcapi0s4s9ClusAll[51]; //[Nalcapi0clusters] 
   Float_t pfMHT;
   Int_t NohPFJet;
   Float_t pfJetPt[5000]; //[NohPFJet] 
   Float_t pfJetEta[5000]; //[NohPFJet] 
   Float_t pfJetPhi[5000]; //[NohPFJet] 
   Int_t NMCpart;
   Int_t MCpid[1203000]; //[NMCpart]
   Int_t MCstatus[1203000]; //[NMCpart]
   Float_t MCvtxX[1203000]; //[NMCpart]
   Float_t MCvtxY[1203000]; //[NMCpart]
   Float_t MCvtxZ[1203000]; //[NMCpart]
   Float_t MCpt[1203000]; //[NMCpart]
   Float_t MCeta[1203000]; //[NMCpart]
   Float_t MCphi[1203000]; //[NMCpart]
   Float_t MCPtHat;
   Int_t MCmu3;
   Int_t MCel3;
   Int_t MCbb;
   Int_t MCab;
   Int_t MCWenu;
   Int_t MCWmunu;
   Int_t MCZee;
   Int_t MCZmumu;
   Float_t MCptEleMax;
   Float_t MCptMuMax;
   Int_t NL1IsolEm;
   Float_t L1IsolEmEt[4000]; //[NL1IsolEm]
   Float_t L1IsolEmE[4000]; //[NL1IsolEm]
   Float_t L1IsolEmEta[4000]; //[NL1IsolEm]
   Float_t L1IsolEmPhi[4000]; //[NL1IsolEm]
   Int_t NL1NIsolEm;
   Float_t L1NIsolEmEt[4000]; //[NL1NIsolEm]
   Float_t L1NIsolEmE[4000]; //[NL1NIsolEm]
   Float_t L1NIsolEmEta[4000]; //[NL1NIsolEm]
   Float_t L1NIsolEmPhi[4000]; //[NL1NIsolEm]
   Int_t NL1Mu;
   Float_t L1MuPt[4000]; //[NL1Mu]
   Float_t L1MuE[4000]; //[NL1Mu]
   Float_t L1MuEta[4000]; //[NL1Mu]
   Float_t L1MuPhi[4000]; //[NL1Mu]
   Int_t L1MuIsol[4000]; //[NL1Mu]
   Int_t L1MuMip[4000]; //[NL1Mu]
   Int_t L1MuFor[4000]; //[NL1Mu]
   Int_t L1MuRPC[4000]; //[NL1Mu]
   Int_t L1MuQal[4000]; //[NL1Mu]
   Int_t NL1CenJet;
   Float_t L1CenJetEt[4000]; //[NL1CenJet]
   Float_t L1CenJetE[4000]; //[NL1CenJet]
   Float_t L1CenJetEta[4000]; //[NL1CenJet]
   Float_t L1CenJetPhi[4000]; //[NL1CenJet]
   Int_t NL1ForJet;
   Float_t L1ForJetEt[4000]; //[NL1ForJet]
   Float_t L1ForJetE[4000]; //[NL1ForJet]
   Float_t L1ForJetEta[4000]; //[NL1ForJet]
   Float_t L1ForJetPhi[4000]; //[NL1ForJet]
   Int_t NL1Tau;
   Float_t L1TauEt[4000]; //[NL1Tau]
   Float_t L1TauE[4000]; //[NL1Tau]
   Float_t L1TauEta[4000]; //[NL1Tau]
   Float_t L1TauPhi[4000]; //[NL1Tau]
   Float_t L1Met;
   Float_t L1MetPhi;
   Float_t L1MetTot;
   Float_t L1MetHad;
   Float_t L1EtTot;
   Int_t L1HfRing0EtSumPositiveEta;
   Int_t L1HfRing1EtSumPositiveEta;
   Int_t L1HfRing0EtSumNegativeEta;
   Int_t L1HfRing1EtSumNegativeEta;
   Int_t L1HfTowerCountPositiveEta;
   Int_t L1HfTowerCountNegativeEta;
   Int_t L1HfTowerCountNegativeEtaRing1;
   Int_t L1HfTowerCountPositiveEtaRing1;
   Int_t L1HfTowerCountNegativeEtaRing2;
   Int_t L1HfTowerCountPositiveEtaRing2;
   Int_t Run;
   Int_t Event;
   Int_t LumiBlock;
   Int_t Bx;
   Int_t Orbit;
   Double_t AvgInstDelLumi;

   bool ohEleL1Dupl[8000];
   bool ohPhotL1Dupl[8000];
   bool ohEcalActivL1Dupl[8000];

   // Autogenerated L1 - Int_t 
  Int_t           L1_SingleJet20_Central_NotBptxOR;
  Int_t           L1_SingleJet16_FwdVeto5;
  Int_t           L1_ETT80;
  Int_t           L1_DoubleForJet16_EtaOpp;
  Int_t           L1_DoubleMu0_HighQ_EtaCuts;
  Int_t           L1_DoubleEG3_FwdVeto;
  Int_t           L1_SingleForJet16;
  Int_t           L1_DoubleMu_5er_0er_HighQ_WdEta22;
  Int_t           L1_DoubleMu3er_HighQ_WdEta22;
  Int_t           L1_BeamHalo;
  Int_t           L1_InterBunch_Bptx;
  Int_t           L1_BeamGas_Hf_BptxPlusPostQuiet;
  Int_t           L1_BeamGas_Hf_BptxMinusPostQuiet;
  Int_t           L1_ZeroBias_Instance1;
  Int_t           L1_SingleMu6_NotBptxOR;
  Int_t           L1_SingleJetC20_NotBptxOR;
  Int_t           L1_SingleJetC32_NotBptxOR;
  Int_t           L1_TripleMu_5_5_0;
  Int_t           L1_TripleMu0_HighQ;
  Int_t           L1_DoubleMu_10_3p5;
  Int_t           L1_DoubleMu_12_5;
  Int_t           L1_DoubleMuHighQ_5_0_Eta2p1_WdEta22;
  Int_t           L1_DoubleMuHighQ_3_3_Eta2p1_WdEta22;
  Int_t           L1_DoubleMu0er_HighQ;
  Int_t           L1_SingleMu25er;
  Int_t           L1_SingleMu20er;
  Int_t           L1_SingleMu18er;
  Int_t           L1_SingleMu16er;
  Int_t           L1_SingleMu14er;
  Int_t           L1_DoubleJetC44_ETM30;
  Int_t           L1_DoubleJetC36_ETM30;
  Int_t           L1_Mu5_DoubleEG6;
  Int_t           L1_Mu5_DoubleEG5;
  Int_t           L1_DoubleMu5_EG5;
  Int_t           L1_DoubleMu3p5_EG5;
  Int_t           L1_Mu3p5_EG12;
  Int_t           L1_Mu12_EG7;
  Int_t           L1_EG8_DoubleJetC20;
  Int_t           L1_EG18er_JetC_Cen36_Tau28_dPhi1;
  Int_t           L1_IsoEG18er_JetC_Cen36_Tau28_dPhi1;
  Int_t           L1_IsoEG18er_JetC_Cen32_Tau24_dPhi1;
  Int_t           L1_EG18er_JetC_Cen28_Tau20_dPhi1;
  Int_t           L1_DoubleEG6_HTT125;
  Int_t           L1_DoubleEG6_HTT100;
  Int_t           L1_EG22_ForJet32;
  Int_t           L1_EG22_ForJet24;
  Int_t           L1_Mu8_DoubleJetC20;
  Int_t           L1_Mu10er_JetC12_WdEtaPhi1_DoubleJetC_32_12;
  Int_t           L1_Mu10er_JetC32;
  Int_t           L1_Mu10er_JetC12_WdEtaPhi1_DoubleJetC_20_12;
  Int_t           L1_Mu12er_ETM20;
  Int_t           L1_Mu4_HTT125;
  Int_t           L1_Mu0_HTT100;
  Int_t           L1_DoubleTauJet44er;
  Int_t           L1_QuadJetC40;
  Int_t           L1_QuadJetC36;
  Int_t           L1_QuadJetC32;
  Int_t           L1_TripleJetC_52_28_28;
  Int_t           L1_TripleJet_68_48_32_VBF;
  Int_t           L1_TripleJet_64_48_28_VBF;
  Int_t           L1_TripleJet_64_44_24_VBF;
  Int_t           L1_DoubleJetC64;
  Int_t           L1_DoubleJetC56;
  Int_t           L1_DoubleJetC56_Eta1p74_WdEta4;
  Int_t           L1_DoubleJetC52;
  Int_t           L1_DoubleJetC44_Eta1p74_WdEta4;
  Int_t           L1_DoubleJetC36;
  Int_t           L1_TripleEG_12_7_5;
  Int_t           L1_DoubleEG_13_7;
  Int_t           L1_SingleEG24;
  Int_t           L1_SingleEG22;
  Int_t           L1_SingleIsoEG20er;
  Int_t           L1_SingleIsoEG18er;
  Int_t           L1_SingleEG18er;
  Int_t           L1_SingleEG7;
  Int_t           L1_ETT300;
  Int_t           L1_HTT175;
  Int_t           L1_HTT150;
  Int_t           L1_HTT125;
  Int_t           L1_ETM100;
  Int_t           L1_ETM50;
  Int_t           L1_ETM36;
  Int_t           L1_QuadJet28_Central;
  Int_t           L1_SingleJet128;
  Int_t           L1_DoubleMu_10_Open;
  Int_t           L1_SingleEG18;
  Int_t           L1_Mu10_Eta2p1_DoubleJet_16_8_Central;
  Int_t           L1_Mu12_EG5;
  Int_t           L1_SingleMu16_Eta2p1;
  Int_t           L1_DoubleMu0_HighQ;
  Int_t           L1_SingleMu14_Eta2p1;
  Int_t           L1_HTT50_HTM30;
  Int_t           L1_DoubleEG5_HTT75;
  Int_t           L1_DoubleJet64_Central;
  Int_t           L1_DoubleTauJet44_Eta2p17;
  Int_t           L1_TripleJet_36_36_12_Central;
  Int_t           L1_EG5_HTT100;
  Int_t           L1_EG5_DoubleJet20_Central;
  Int_t           L1_TripleMu0;
  Int_t           L1_DoubleMu3p5;
  Int_t           L1_MuOpen_DoubleEG5;
  Int_t           L1_DoubleMuOpen_EG5;
  Int_t           L1_DoubleEG_12_5;
  Int_t           L1_DoubleTauJet36_Eta2p17;
  Int_t           L1_SingleJet52_Central;
  Int_t           L1_DoubleJet52_Central;
  Int_t           L1_DoubleTauJet40_Eta2p17;
  Int_t           L1_Jet52_Central_ETM30;
  Int_t           L1_DoubleJet44_Central;
  Int_t           L1_Mu7_EG5;
  Int_t           L1_MuOpen_EG12;
  Int_t           L1_DoubleTauJet36;
  Int_t           L1_TripleJet28_Central;
  Int_t           L1_SingleJet36_FwdVeto5;
  Int_t           L1_SingleTauJet68;
  Int_t           L1_MuOpen_EG5;
  Int_t           L1_SingleMu5_Eta1p5_Q80_v1;
  Int_t           L1_HTT75;
  Int_t           L1_ETT220;
  Int_t           L1_SingleJet20_NotBptxOR;
  Int_t           L1_BeamGas_Bsc;
  Int_t           L1_PreCollisions;
  Int_t           L1_BeamGas_Hf;
  Int_t           L1_Mu3_Jet20_Central;
  Int_t           L1_Mu3_Jet28_Central;
  Int_t           L1_Mu3_Jet16_Central;
  Int_t           L1_Mu7_Jet20_Central;
  Int_t           L1_Mu3_JetC16_WdEtaPhi2;
  Int_t           L1_Mu3_JetC52_WdEtaPhi2;

  Int_t           L1_DoubleEG5_HTT50;
  Int_t           L1_EG5_HTT75;
  Int_t           L1_DoubleJet52;
  Int_t           L1_SingleTauJet52;
  Int_t           L1_DoubleTauJet28;
  Int_t           L1_SingleJet20_NotBptxOR_NotMuBeamHalo;
  Int_t           L1_SingleJet16;
  Int_t           L1_SingleJet68;
  Int_t           L1_SingleJet92;
  Int_t           L1_DoubleForJet32_EtaOpp;
  Int_t           L1_DoubleForJet44_EtaOpp;
  Int_t           L1_DoubleEG2_FwdVeto;
  Int_t           L1_SingleJet36_FwdVeto;
  Int_t           L1_TripleEG7;
  Int_t           L1_TripleEG5;
  Int_t           L1_TripleJet28;
  Int_t           L1_Mu0_HTT50;
  Int_t           L1_SingleEG12_Eta2p17;
  Int_t           L1_SingleEG30;
  Int_t           L1_Mu3_Jet20;
  Int_t           L1_Mu3_Jet16;
  Int_t           L1_SingleMu16;
  Int_t           L1_SingleMu25;
  Int_t           L1_DoubleMu5;
  Int_t           L1_SingleMu5_Eta1p5_Q80;
  Int_t           L1_DoubleMu_0_5;
  Int_t           L1_SingleMu12;
  Int_t           L1_DoubleMu0;
  Int_t           L1_QuadJet20_Central;
  Int_t           L1_DoubleJet36_Central;
  Int_t           L1_SingleJet52;
  Int_t           L1_SingleJet36;
   Int_t L1_Mu3_Jet10;
   Int_t L1_SingleJet10U_NotBptxOR_Ext;
   Int_t L1_SingleJet10_NotBptxOR_Ext;
   Int_t L1_SingleJet10U_NotBptxOR;
   Int_t L1_SingleJet10_NotBptxOR;
   Int_t L1_Mu3_EG5;

   //L1 algorithm bits
   Int_t L1_DoubleEG05_TopBottom;
   Int_t L1_DoubleMuTopBottom;
   Int_t L1_Mu3QE8_Jet6;
   Int_t L1_Mu5QE8_Jet6;
   Int_t L1_IsoEG10_Jet6_ForJet6;
   Int_t L1_SingleJet20;
   Int_t L1_SingleJet40;
   Int_t L1_SingleJet60;
   Int_t L1_DoubleJet30;
   Int_t L1_SingleTauJet10;
   Int_t L1_SingleTauJet20;
   Int_t L1_SingleTauJet50;
   Int_t L1_DoubleTauJet14;
   Int_t L1_Mu5_Jet6;
   Int_t L1_EG5_TripleJet6;
   Int_t L1_SingleJet6;
   Int_t L1_SingleJet10;
   Int_t L1_SingleJet10_NotBptxC_Ext;
   Int_t L1_ETM30;
   Int_t L1_QuadJet6;
   Int_t L1_QuadJet8;
   Int_t L1_TripleJet14;
   Int_t L1_DoubleEG1;
   Int_t L1_DoubleEG2;
   Int_t L1_DoubleEG5;
   Int_t L1_DoubleHfBitCountsRing1_P1N1;
   Int_t L1_DoubleHfBitCountsRing2_P1N1;
   Int_t L1_DoubleHfRingEtSumsRing1_P200N200;
   Int_t L1_DoubleHfRingEtSumsRing1_P4N4;
   Int_t L1_DoubleHfRingEtSumsRing2_P200N200;
   Int_t L1_DoubleHfRingEtSumsRing2_P4N4;
   Int_t L1_DoubleJet70;
   Int_t L1_DoubleMu3;
   Int_t L1_DoubleMuOpen;
   Int_t L1_DoubleTauJet30;
   Int_t L1_EG10_Jet15;
   Int_t L1_EG5_TripleJet15;
   Int_t L1_ETM20;
   Int_t L1_ETM40;
   Int_t L1_ETM70;
   Int_t L1_ETM80;
   Int_t L1_ETT60;
   Int_t L1_ETT100;
   Int_t L1_ETT140;
   Int_t L1_HTT50;
   Int_t L1_HTT100;
   Int_t L1_HTT200;
   Int_t L1_HTT300;
   Int_t L1_IsoEG10_Jet15_ForJet10;
   Int_t L1_MinBias_HTT10;
   Int_t L1_Mu3QE8_EG5;
   Int_t L1_Mu3QE8_Jet15;
   Int_t L1_Mu5QE8_Jet15;
   Int_t L1_QuadJet15;
   Int_t L1_SingleEG1;
   Int_t L1_SingleEG10;
   Int_t L1_SingleEG12;
   Int_t L1_SingleEG15;
   Int_t L1_SingleEG2;
   Int_t L1_SingleEG20;
   Int_t L1_SingleEG5;
   Int_t L1_SingleEG8;
   Int_t L1_SingleHfBitCountsRing1_1;
   Int_t L1_SingleHfBitCountsRing2_1;
   Int_t L1_SingleHfRingEtSumsRing1_200;
   Int_t L1_SingleHfRingEtSumsRing1_4;
   Int_t L1_SingleHfRingEtSumsRing2_200;
   Int_t L1_SingleHfRingEtSumsRing2_4;
   Int_t L1_SingleIsoEG10;
   Int_t L1_SingleIsoEG12;
   Int_t L1_SingleIsoEG15;
   Int_t L1_SingleIsoEG5;
   Int_t L1_SingleIsoEG8;
   Int_t L1_SingleJet100;
   Int_t L1_SingleJet15;
   Int_t L1_SingleJet30;
   Int_t L1_SingleJet50;
   Int_t L1_SingleJet70;
   Int_t L1_SingleMu0;
   Int_t L1_SingleMu10;
   Int_t L1_SingleMu14;
   Int_t L1_SingleMu20;
   Int_t L1_SingleMu3;
   Int_t L1_SingleMu5;
   Int_t L1_SingleMu7;
   Int_t L1_SingleMuBeamHalo;
   Int_t L1_SingleMuOpen;
   Int_t L1_SingleTauJet30;
   Int_t L1_SingleTauJet40;
   Int_t L1_SingleTauJet60;
   Int_t L1_SingleTauJet80;
   Int_t L1_TripleJet30;
   Int_t L1_ZeroBias;
   Int_t L1_ZeroBias_Ext;
   Int_t L1_SingleCenJet2;
   Int_t L1_SingleCenJet4;
   Int_t L1_SingleForJet2;
   Int_t L1_SingleForJet4;
   Int_t L1_SingleTauJet2;
   Int_t L1_SingleTauJet4;
   Int_t L1_DoubleForJet10_EtaOpp;
   Int_t L1_Mu3_Jet6;

   // L1 Technical bits
   Int_t L1Tech_BPTX_minus_v0;
   Int_t L1Tech_BPTX_minus_v0_5bx;
   Int_t L1Tech_BPTX_minus_AND_not_plus_v0;
   Int_t L1Tech_BPTX_minus_AND_not_plus_v0_5bx;
   Int_t L1Tech_BPTX_plus_v0;
   Int_t L1Tech_BPTX_plus_v0_5bx;
   Int_t L1Tech_BPTX_plus_AND_NOT_minus_v0;
   Int_t L1Tech_BPTX_plus_AND_NOT_minus_v0_5bx;
   Int_t L1Tech_BPTX_plus_AND_minus_v0;
   Int_t L1Tech_BPTX_plus_AND_minus_v0_5bx;
   Int_t L1Tech_BPTX_plus_AND_minus_instance1_v0;
   Int_t L1Tech_BPTX_plus_AND_minus_instance1_v0_5bx;
   Int_t L1Tech_BPTX_plus_OR_minus_v0;
   Int_t L1Tech_BPTX_plus_OR_minus_v0_5bx;
   Int_t L1Tech_BPTX_quiet_v0;
   Int_t L1Tech_BPTX_quiet_v0_5bx;
   Int_t L1Tech_BSC_HighMultiplicity_v0;
   Int_t L1Tech_BSC_HighMultiplicity_v0_5bx;
   Int_t L1Tech_BSC_halo_beam1_inner_v0;
   Int_t L1Tech_BSC_halo_beam1_inner_v0_5bx;
   Int_t L1Tech_BSC_halo_beam1_outer_v0;
   Int_t L1Tech_BSC_halo_beam1_outer_v0_5bx;
   Int_t L1Tech_BSC_halo_beam2_inner_v0;
   Int_t L1Tech_BSC_halo_beam2_inner_v0_5bx;
   Int_t L1Tech_BSC_halo_beam2_outer_v0;
   Int_t L1Tech_BSC_halo_beam2_outer_v0_5bx;
   Int_t L1Tech_BSC_minBias_OR_v0;
   Int_t L1Tech_BSC_minBias_OR_v0_5bx;
   Int_t L1Tech_BSC_minBias_inner_threshold1_v0;
   Int_t L1Tech_BSC_minBias_inner_threshold1_v0_5bx;
   Int_t L1Tech_BSC_minBias_inner_threshold2_v0;
   Int_t L1Tech_BSC_minBias_inner_threshold2_v0_5bx;
   Int_t L1Tech_BSC_minBias_threshold1_v0;
   Int_t L1Tech_BSC_minBias_threshold1_v0_5bx;
   Int_t L1Tech_BSC_minBias_threshold2_v0;
   Int_t L1Tech_BSC_minBias_threshold2_v0_5bx;
   Int_t L1Tech_BSC_splash_beam1_v0;
   Int_t L1Tech_BSC_splash_beam1_v0_5bx;
   Int_t L1Tech_BSC_splash_beam2_v0;
   Int_t L1Tech_BSC_splash_beam2_v0_5bx;
   Int_t L1Tech_HCAL_HBHE_totalOR_v0;
   Int_t L1Tech_HCAL_HBHE_totalOR_v0_5bx;
   Int_t L1Tech_HCAL_HF_totalOR_coincidenceHFM_v0;
   Int_t L1Tech_HCAL_HF_totalOR_coincidenceHFM_v0_5bx;
   Int_t L1Tech_HCAL_HF_totalOR_coincidenceHFP_v0;
   Int_t L1Tech_HCAL_HF_totalOR_coincidenceHFP_v0_5bx;
   Int_t L1Tech_HCAL_HF_totalOR_minBias_v0;
   Int_t L1Tech_HCAL_HF_totalOR_minBias_v0_5bx;
   Int_t L1Tech_HCAL_HO_totalOR_v0;
   Int_t L1Tech_HCAL_HO_totalOR_v0_5bx;
   Int_t L1Tech_RPC_TTU_RB0_Cosmics_v0;
   Int_t L1Tech_RPC_TTU_RB0_Cosmics_v0_5bx;
   Int_t L1Tech_RPC_TTU_RBminus1_Cosmics_v0;
   Int_t L1Tech_RPC_TTU_RBminus1_Cosmics_v0_5bx;
   Int_t L1Tech_RPC_TTU_RBminus2_Cosmics_v0;
   Int_t L1Tech_RPC_TTU_RBminus2_Cosmics_v0_5bx;
   Int_t L1Tech_RPC_TTU_RBplus1_Cosmics_v0;
   Int_t L1Tech_RPC_TTU_RBplus1_Cosmics_v0_5bx;
   Int_t L1Tech_RPC_TTU_RBplus2_Cosmics_v0;
   Int_t L1Tech_RPC_TTU_RBplus2_Cosmics_v0_5bx;
   Int_t L1Tech_RPC_TTU_barrel_Cosmics_v0;
   Int_t L1Tech_RPC_TTU_barrel_Cosmics_v0_5bx;
   Int_t L1Tech_RPC_TTU_pointing_Cosmics_v0;
   Int_t L1Tech_RPC_TTU_pointing_Cosmics_v0_5bx;
   Int_t L1Tech_RPC_TTU_RBst1_collisions_v0;
   Int_t L1Tech_RPC_TTU_RBst1_collisions_v0_5bx;
   Int_t L1Tech_HCAL_HF_MM_or_PP_or_PM_v0;
   Int_t L1Tech_HCAL_HF_MM_or_PP_or_PM_v0_5bx;
   Int_t L1Tech_HCAL_HF_coincidence_PM_v1;
   Int_t L1Tech_HCAL_HF_coincidence_PM_v1_5bx;
   Int_t L1Tech_HCAL_HF_MMP_or_MPP_v0;
   Int_t L1Tech_HCAL_HF_MMP_or_MPP_v0_5bx;
   Int_t L1Tech_ZDC_loose_vertex_v0;
   Int_t L1Tech_ZDC_loose_vertex_v0_5bx;
   Int_t L1Tech_ZDC_minus_over_threshold_v0;
   Int_t L1Tech_ZDC_minus_over_threshold_v0_5bx;
   Int_t L1Tech_ZDC_plus_over_threshold_v0;
   Int_t L1Tech_ZDC_plus_over_threshold_v0_5bx;
   Int_t L1Tech_ZDC_tight_vertex_v0;
   Int_t L1Tech_ZDC_tight_vertex_v0_5bx;

   // BSC and BPTX algorithm bits
   Int_t L1_BptxMinus;
   Int_t L1_BptxMinus_5bx;
   Int_t L1_BptxPlus;
   Int_t L1_BptxPlus_5bx;
   Int_t L1_BptxPlusORMinus;
   Int_t L1_BptxPlusORMinus_5bx;
   Int_t L1_BptxPlus_NotBptxMinus;
   Int_t L1_BptxPlus_NotBptxMinus_5bx;
   Int_t L1_BptxMinus_NotBptxPlus;
   Int_t L1_BptxMinus_NotBptxPlus_5bx;
   Int_t L1_BptxXOR_BscMinBiasOR;
   Int_t L1_BptxXOR_BscMinBiasOR_5bx;
   Int_t L1_BscHighMultiplicity;
   Int_t L1_BscHighMultiplicity_5bx;
   Int_t L1_BscMinBiasInnerThreshold1;
   Int_t L1_BscMinBiasInnerThreshold1_5bx;
   Int_t L1_BscMinBiasInnerThreshold2;
   Int_t L1_BscMinBiasInnerThreshold2_5bx;
   Int_t L1_BscMinBiasOR;
   Int_t L1_BscMinBiasOR_5bx;
   Int_t L1_BscMinBiasOR_BptxPlusORMinus;
   Int_t L1_BscMinBiasOR_BptxPlusORMinus_5bx;
   Int_t L1_BscMinBiasOR_BptxPlusANDMinus;
   Int_t L1_BscMinBiasOR_BptxPlusANDMinus_5bx;

   // Autogenerated L1 - Prescale Int_t
  Int_t           L1_SingleJet20_Central_NotBptxOR_Prescl;
  Int_t           L1_SingleJet16_FwdVeto5_Prescl;
  Int_t           L1_ETT80_Prescl;
  Int_t           L1_DoubleForJet16_EtaOpp_Prescl;
  Int_t           L1_DoubleMu0_HighQ_EtaCuts_Prescl;
  Int_t           L1_DoubleEG3_FwdVeto_Prescl;
  Int_t           L1_SingleForJet16_Prescl;
  Int_t           L1_DoubleMu_5er_0er_HighQ_WdEta22_Prescl;
  Int_t           L1_DoubleMu3er_HighQ_WdEta22_Prescl;
  Int_t           L1_BeamHalo_Prescl;
  Int_t           L1_InterBunch_Bptx_Prescl;
  Int_t           L1_BeamGas_Hf_BptxPlusPostQuiet_Prescl;
  Int_t           L1_BeamGas_Hf_BptxMinusPostQuiet_Prescl;
  Int_t           L1_ZeroBias_Instance1_Prescl;
  Int_t           L1_SingleMu6_NotBptxOR_Prescl;
  Int_t           L1_SingleJetC20_NotBptxOR_Prescl;
  Int_t           L1_SingleJetC32_NotBptxOR_Prescl;
  Int_t           L1_TripleMu_5_5_0_Prescl;
  Int_t           L1_TripleMu0_HighQ_Prescl;
  Int_t           L1_DoubleMu_10_3p5_Prescl;
  Int_t           L1_DoubleMu_12_5_Prescl;
  Int_t           L1_DoubleMuHighQ_5_0_Eta2p1_WdEta22_Prescl;
  Int_t           L1_DoubleMuHighQ_3_3_Eta2p1_WdEta22_Prescl;
  Int_t           L1_DoubleMu0er_HighQ_Prescl;
  Int_t           L1_SingleMu25er_Prescl;
  Int_t           L1_SingleMu20er_Prescl;
  Int_t           L1_SingleMu18er_Prescl;
  Int_t           L1_SingleMu16er_Prescl;
  Int_t           L1_SingleMu14er_Prescl;
  Int_t           L1_DoubleJetC44_ETM30_Prescl;
  Int_t           L1_DoubleJetC36_ETM30_Prescl;
  Int_t           L1_Mu5_DoubleEG6_Prescl;
  Int_t           L1_Mu5_DoubleEG5_Prescl;
  Int_t           L1_DoubleMu5_EG5_Prescl;
  Int_t           L1_DoubleMu3p5_EG5_Prescl;
  Int_t           L1_Mu3p5_EG12_Prescl;
  Int_t           L1_Mu12_EG7_Prescl;
  Int_t           L1_EG8_DoubleJetC20_Prescl;
  Int_t           L1_EG18er_JetC_Cen36_Tau28_dPhi1_Prescl;
  Int_t           L1_IsoEG18er_JetC_Cen36_Tau28_dPhi1_Prescl;
  Int_t           L1_IsoEG18er_JetC_Cen32_Tau24_dPhi1_Prescl;
  Int_t           L1_EG18er_JetC_Cen28_Tau20_dPhi1_Prescl;
  Int_t           L1_DoubleEG6_HTT125_Prescl;
  Int_t           L1_DoubleEG6_HTT100_Prescl;
  Int_t           L1_EG22_ForJet32_Prescl;
  Int_t           L1_EG22_ForJet24_Prescl;
  Int_t           L1_Mu8_DoubleJetC20_Prescl;
  Int_t           L1_Mu10er_JetC12_WdEtaPhi1_DoubleJetC_32_12_Prescl;
  Int_t           L1_Mu10er_JetC32_Prescl;
  Int_t           L1_Mu10er_JetC12_WdEtaPhi1_DoubleJetC_20_12_Prescl;
  Int_t           L1_Mu12er_ETM20_Prescl;
  Int_t           L1_Mu4_HTT125_Prescl;
  Int_t           L1_Mu0_HTT100_Prescl;
  Int_t           L1_DoubleTauJet44er_Prescl;
  Int_t           L1_QuadJetC40_Prescl;
  Int_t           L1_QuadJetC36_Prescl;
  Int_t           L1_QuadJetC32_Prescl;
  Int_t           L1_TripleJetC_52_28_28_Prescl;
  Int_t           L1_TripleJet_68_48_32_VBF_Prescl;
  Int_t           L1_TripleJet_64_48_28_VBF_Prescl;
  Int_t           L1_TripleJet_64_44_24_VBF_Prescl;
  Int_t           L1_DoubleJetC64_Prescl;
  Int_t           L1_DoubleJetC56_Prescl;
  Int_t           L1_DoubleJetC56_Eta1p74_WdEta4_Prescl;
  Int_t           L1_DoubleJetC52_Prescl;
  Int_t           L1_DoubleJetC44_Eta1p74_WdEta4_Prescl;
  Int_t           L1_DoubleJetC36_Prescl;
  Int_t           L1_TripleEG_12_7_5_Prescl;
  Int_t           L1_DoubleEG_13_7_Prescl;
  Int_t           L1_SingleEG24_Prescl;
  Int_t           L1_SingleEG22_Prescl;
  Int_t           L1_SingleIsoEG20er_Prescl;
  Int_t           L1_SingleIsoEG18er_Prescl;
  Int_t           L1_SingleEG18er_Prescl;
  Int_t           L1_SingleEG7_Prescl;
  Int_t           L1_ETT300_Prescl;
  Int_t           L1_HTT175_Prescl;
  Int_t           L1_HTT150_Prescl;
  Int_t           L1_HTT125_Prescl;
  Int_t           L1_ETM100_Prescl;
  Int_t           L1_ETM50_Prescl;
  Int_t           L1_ETM36_Prescl;
  Int_t           L1_QuadJet28_Central_Prescl;
  Int_t           L1_SingleJet128_Prescl;
  Int_t           L1_DoubleMu_10_Open_Prescl;
  Int_t           L1_SingleEG18_Prescl;
  Int_t           L1_Mu10_Eta2p1_DoubleJet_16_8_Central_Prescl;
  Int_t           L1_Mu12_EG5_Prescl;
  Int_t           L1_SingleMu16_Eta2p1_Prescl;
  Int_t           L1_DoubleMu0_HighQ_Prescl;
  Int_t           L1_SingleMu14_Eta2p1_Prescl;
  Int_t           L1_HTT50_HTM30_Prescl;
  Int_t           L1_DoubleEG5_HTT75_Prescl;
  Int_t           L1_DoubleJet64_Central_Prescl;
  Int_t           L1_DoubleTauJet44_Eta2p17_Prescl;
  Int_t           L1_TripleJet_36_36_12_Central_Prescl;
  Int_t           L1_EG5_HTT100_Prescl;
  Int_t           L1_EG5_DoubleJet20_Central_Prescl;
  Int_t           L1_TripleMu0_Prescl;
  Int_t           L1_DoubleMu3p5_Prescl;
  Int_t           L1_MuOpen_DoubleEG5_Prescl;
  Int_t           L1_DoubleMuOpen_EG5_Prescl;
  Int_t           L1_DoubleEG_12_5_Prescl;
  Int_t           L1_DoubleTauJet36_Eta2p17_Prescl;
  Int_t           L1_SingleJet52_Central_Prescl;
  Int_t           L1_DoubleJet52_Central_Prescl;
  Int_t           L1_DoubleTauJet40_Eta2p17_Prescl;
  Int_t           L1_Jet52_Central_ETM30_Prescl;
  Int_t           L1_DoubleJet44_Central_Prescl;
  Int_t           L1_Mu7_EG5_Prescl;
  Int_t           L1_MuOpen_EG12_Prescl;
  Int_t           L1_DoubleTauJet36_Prescl;
  Int_t           L1_TripleJet28_Central_Prescl;
  Int_t           L1_SingleJet36_FwdVeto5_Prescl;
  Int_t           L1_SingleTauJet68_Prescl;
  Int_t           L1_MuOpen_EG5_Prescl;
  Int_t           L1_SingleMu5_Eta1p5_Q80_v1_Prescl;
  Int_t           L1_HTT75_Prescl;
  Int_t           L1_ETT220_Prescl;
  Int_t           L1_SingleJet20_NotBptxOR_Prescl;
  Int_t           L1_BeamGas_Bsc_Prescl;
  Int_t           L1_PreCollisions_Prescl;
  Int_t           L1_BeamGas_Hf_Prescl;
  Int_t           L1_Mu3_Jet20_Central_Prescl;
  Int_t           L1_Mu3_Jet28_Central_Prescl;
  Int_t           L1_Mu3_Jet16_Central_Prescl;
  Int_t           L1_Mu7_Jet20_Central_Prescl;
  Int_t           L1_Mu3_JetC16_WdEtaPhi2_Prescl;
  Int_t           L1_Mu3_JetC52_WdEtaPhi2_Prescl;

  Int_t           L1_DoubleEG5_HTT50_Prescl;
  Int_t           L1_EG5_HTT75_Prescl;
  Int_t           L1_DoubleJet52_Prescl;
  Int_t           L1_SingleTauJet52_Prescl;
  Int_t           L1_DoubleTauJet28_Prescl;
  Int_t           L1_SingleJet20_NotBptxOR_NotMuBeamHalo_Prescl;
  Int_t           L1_SingleJet16_Prescl;
  Int_t           L1_SingleJet68_Prescl;
  Int_t           L1_SingleJet92_Prescl;
  Int_t           L1_DoubleForJet32_EtaOpp_Prescl;
  Int_t           L1_DoubleForJet44_EtaOpp_Prescl;
  Int_t           L1_DoubleEG2_FwdVeto_Prescl;
  Int_t           L1_SingleJet36_FwdVeto_Prescl;
  Int_t           L1_TripleEG7_Prescl;
  Int_t           L1_TripleEG5_Prescl;
  Int_t           L1_TripleJet28_Prescl;
  Int_t           L1_Mu0_HTT50_Prescl;
  Int_t           L1_SingleEG12_Eta2p17_Prescl;
  Int_t           L1_SingleEG30_Prescl;
  Int_t           L1_Mu3_Jet20_Prescl;
  Int_t           L1_Mu3_Jet16_Prescl;
  Int_t           L1_SingleMu16_Prescl;
  Int_t           L1_SingleMu25_Prescl;
  Int_t           L1_DoubleMu5_Prescl;
  Int_t           L1_SingleMu5_Eta1p5_Q80_Prescl;
  Int_t           L1_DoubleMu_0_5_Prescl;
  Int_t           L1_SingleMu12_Prescl;
  Int_t           L1_DoubleMu0_Prescl;
  Int_t           L1_QuadJet20_Central_Prescl;
  Int_t           L1_DoubleJet36_Central_Prescl;
  Int_t           L1_SingleJet52_Prescl;
  Int_t           L1_SingleJet36_Prescl;
   Int_t L1_Mu3_Jet10_Prescl;
   Int_t L1_SingleJet10U_NotBptxOR_Ext_Prescl;
   Int_t L1_SingleJet10_NotBptxOR_Ext_Prescl;
   Int_t L1_SingleJet10U_NotBptxOR_Prescl;
   Int_t L1_SingleJet10_NotBptxOR_Prescl;
   Int_t L1_Mu3_EG5_Prescl;

   //L1 algorithm bit prescales
   Int_t L1_DoubleEG05_TopBottom_Prescl;
   Int_t L1_DoubleMuTopBottom_Prescl;
   Int_t L1_Mu3QE8_Jet6_Prescl;
   Int_t L1_Mu5QE8_Jet6_Prescl;
   Int_t L1_IsoEG10_Jet6_ForJet6_Prescl;
   Int_t L1_SingleJet20_Prescl;
   Int_t L1_SingleJet40_Prescl;
   Int_t L1_SingleJet60_Prescl;
   Int_t L1_DoubleJet30_Prescl;
   Int_t L1_SingleTauJet10_Prescl;
   Int_t L1_SingleTauJet20_Prescl;
   Int_t L1_SingleTauJet50_Prescl;
   Int_t L1_DoubleTauJet14_Prescl;
   Int_t L1_Mu5_Jet6_Prescl;
   Int_t L1_EG5_TripleJet6_Prescl;
   Int_t L1_SingleJet6_Prescl;
   Int_t L1_SingleJet10_Prescl;
   Int_t L1_SingleJet10_NotBptxC_Ext_Prescl;
   Int_t L1_ETM30_Prescl;
   Int_t L1_QuadJet6_Prescl;
   Int_t L1_QuadJet8_Prescl;
   Int_t L1_TripleJet14_Prescl;
   Int_t L1_DoubleEG1_Prescl;
   Int_t L1_DoubleEG2_Prescl;
   Int_t L1_DoubleEG5_Prescl;
   Int_t L1_DoubleHfBitCountsRing1_P1N1_Prescl;
   Int_t L1_DoubleHfBitCountsRing2_P1N1_Prescl;
   Int_t L1_DoubleHfRingEtSumsRing1_P200N200_Prescl;
   Int_t L1_DoubleHfRingEtSumsRing1_P4N4_Prescl;
   Int_t L1_DoubleHfRingEtSumsRing2_P200N200_Prescl;
   Int_t L1_DoubleHfRingEtSumsRing2_P4N4_Prescl;
   Int_t L1_DoubleJet70_Prescl;
   Int_t L1_DoubleMu3_Prescl;
   Int_t L1_DoubleMuOpen_Prescl;
   Int_t L1_DoubleTauJet30_Prescl;
   Int_t L1_EG10_Jet15_Prescl;
   Int_t L1_EG5_TripleJet15_Prescl;
   Int_t L1_ETM20_Prescl;
   Int_t L1_ETM40_Prescl;
   Int_t L1_ETM70_Prescl;
   Int_t L1_ETM80_Prescl;
   Int_t L1_ETT60_Prescl;
   Int_t L1_ETT100_Prescl;
   Int_t L1_ETT140_Prescl;
   Int_t L1_HTT50_Prescl;
   Int_t L1_HTT100_Prescl;
   Int_t L1_HTT200_Prescl;
   Int_t L1_HTT300_Prescl;
   Int_t L1_IsoEG10_Jet15_ForJet10_Prescl;
   Int_t L1_MinBias_HTT10_Prescl;
   Int_t L1_Mu3QE8_EG5_Prescl;
   Int_t L1_Mu3QE8_Jet15_Prescl;
   Int_t L1_Mu5QE8_Jet15_Prescl;
   Int_t L1_QuadJet15_Prescl;
   Int_t L1_SingleEG1_Prescl;
   Int_t L1_SingleEG10_Prescl;
   Int_t L1_SingleEG12_Prescl;
   Int_t L1_SingleEG15_Prescl;
   Int_t L1_SingleEG2_Prescl;
   Int_t L1_SingleEG20_Prescl;
   Int_t L1_SingleEG5_Prescl;
   Int_t L1_SingleEG8_Prescl;
   Int_t L1_SingleHfBitCountsRing1_1_Prescl;
   Int_t L1_SingleHfBitCountsRing2_1_Prescl;
   Int_t L1_SingleHfRingEtSumsRing1_200_Prescl;
   Int_t L1_SingleHfRingEtSumsRing1_4_Prescl;
   Int_t L1_SingleHfRingEtSumsRing2_200_Prescl;
   Int_t L1_SingleHfRingEtSumsRing2_4_Prescl;
   Int_t L1_SingleIsoEG10_Prescl;
   Int_t L1_SingleIsoEG12_Prescl;
   Int_t L1_SingleIsoEG15_Prescl;
   Int_t L1_SingleIsoEG5_Prescl;
   Int_t L1_SingleIsoEG8_Prescl;
   Int_t L1_SingleJet100_Prescl;
   Int_t L1_SingleJet15_Prescl;
   Int_t L1_SingleJet30_Prescl;
   Int_t L1_SingleJet50_Prescl;
   Int_t L1_SingleJet70_Prescl;
   Int_t L1_SingleMu0_Prescl;
   Int_t L1_SingleMu10_Prescl;
   Int_t L1_SingleMu14_Prescl;
   Int_t L1_SingleMu20_Prescl;
   Int_t L1_SingleMu3_Prescl;
   Int_t L1_SingleMu5_Prescl;
   Int_t L1_SingleMu7_Prescl;
   Int_t L1_SingleMuBeamHalo_Prescl;
   Int_t L1_SingleMuOpen_Prescl;
   Int_t L1_SingleTauJet30_Prescl;
   Int_t L1_SingleTauJet40_Prescl;
   Int_t L1_SingleTauJet60_Prescl;
   Int_t L1_SingleTauJet80_Prescl;
   Int_t L1_TripleJet30_Prescl;
   Int_t L1_ZeroBias_Prescl;
   Int_t L1_ZeroBias_Ext_Prescl;
   Int_t L1_SingleCenJet2_Prescl;
   Int_t L1_SingleCenJet4_Prescl;
   Int_t L1_SingleForJet2_Prescl;
   Int_t L1_SingleForJet4_Prescl;
   Int_t L1_SingleTauJet2_Prescl;
   Int_t L1_SingleTauJet4_Prescl;
   Int_t L1_DoubleForJet10_EtaOpp_Prescl;
   Int_t L1_Mu3_Jet6_Prescl;

   // L1 Technical bit prescales
   Int_t L1Tech_BPTX_minus_v0_Prescl;
   Int_t L1Tech_BPTX_minus_AND_not_plus_v0_Prescl;
   Int_t L1Tech_BPTX_plus_v0_Prescl;
   Int_t L1Tech_BPTX_plus_AND_NOT_minus_v0_Prescl;
   Int_t L1Tech_BPTX_plus_AND_minus_v0_Prescl;
   Int_t L1Tech_BPTX_plus_AND_minus_instance1_v0_Prescl;
   Int_t L1Tech_BPTX_plus_OR_minus_v0_Prescl;
   Int_t L1Tech_BPTX_quiet_v0_Prescl;
   Int_t L1Tech_BSC_HighMultiplicity_v0_Prescl;
   Int_t L1Tech_BSC_halo_beam1_inner_v0_Prescl;
   Int_t L1Tech_BSC_halo_beam1_outer_v0_Prescl;
   Int_t L1Tech_BSC_halo_beam2_inner_v0_Prescl;
   Int_t L1Tech_BSC_halo_beam2_outer_v0_Prescl;
   Int_t L1Tech_BSC_minBias_OR_v0_Prescl;
   Int_t L1Tech_BSC_minBias_inner_threshold1_v0_Prescl;
   Int_t L1Tech_BSC_minBias_inner_threshold2_v0_Prescl;
   Int_t L1Tech_BSC_minBias_threshold1_v0_Prescl;
   Int_t L1Tech_BSC_minBias_threshold2_v0_Prescl;
   Int_t L1Tech_BSC_splash_beam1_v0_Prescl;
   Int_t L1Tech_BSC_splash_beam2_v0_Prescl;
   Int_t L1Tech_HCAL_HBHE_totalOR_v0_Prescl;
   Int_t L1Tech_HCAL_HF_totalOR_coincidenceHFM_v0_Prescl;
   Int_t L1Tech_HCAL_HF_totalOR_coincidenceHFP_v0_Prescl;
   Int_t L1Tech_HCAL_HF_totalOR_minBias_v0_Prescl;
   Int_t L1Tech_HCAL_HO_totalOR_v0_Prescl;
   Int_t L1Tech_RPC_TTU_RB0_Cosmics_v0_Prescl;
   Int_t L1Tech_RPC_TTU_RBminus1_Cosmics_v0_Prescl;
   Int_t L1Tech_RPC_TTU_RBminus2_Cosmics_v0_Prescl;
   Int_t L1Tech_RPC_TTU_RBplus1_Cosmics_v0_Prescl;
   Int_t L1Tech_RPC_TTU_RBplus2_Cosmics_v0_Prescl;
   Int_t L1Tech_RPC_TTU_barrel_Cosmics_v0_Prescl;
   Int_t L1Tech_RPC_TTU_pointing_Cosmics_v0_Prescl;
   Int_t L1Tech_RPC_TTU_RBst1_collisions_v0_Prescl;
   Int_t L1Tech_HCAL_HF_MM_or_PP_or_PM_v0_Prescl;
   Int_t L1Tech_HCAL_HF_coincidence_PM_v1_Prescl;
   Int_t L1Tech_HCAL_HF_MMP_or_MPP_v0_Prescl;
   Int_t L1Tech_ZDC_loose_vertex_v0_Prescl;
   Int_t L1Tech_ZDC_minus_over_threshold_v0_Prescl;
   Int_t L1Tech_ZDC_plus_over_threshold_v0_Prescl;
   Int_t L1Tech_ZDC_tight_vertex_v0_Prescl;

   // BSC and BPTX algorithm bit prescales
   Int_t L1_BptxMinus_Prescl;
   Int_t L1_BptxPlus_Prescl;
   Int_t L1_BptxPlusORMinus_Prescl;
   Int_t L1_BptxPlus_NotBptxMinus_Prescl;
   Int_t L1_BptxMinus_NotBptxPlus_Prescl;
   Int_t L1_BptxXOR_BscMinBiasOR_Prescl;
   Int_t L1_BscHighMultiplicity_Prescl;
   Int_t L1_BscMinBiasInnerThreshold1_Prescl;
   Int_t L1_BscMinBiasInnerThreshold2_Prescl;
   Int_t L1_BscMinBiasOR_Prescl;
   Int_t L1_BscMinBiasOR_BptxPlusORMinus_Prescl;
   Int_t L1_BscMinBiasOR_BptxPlusANDMinus_Prescl;

   // Here we declare any emulated L1 bits 
   Int_t OpenL1_ZeroBias;
   Int_t OpenL1_Mu3EG5;
   Int_t OpenL1_EG5_HTT100;
   Int_t OpenL1_SingleMu30;
   Int_t OpenL1_SingleMu5_Eta1pt5_Qal7;
   Int_t OpenL1_SingleMu14_Eta2p1;
   Int_t OpenL1_SingleMu16_Eta2p1;
   Int_t OpenL1_EG18_ForJet16;

   // 5E32 menu
   Int_t OpenL1_DoubleEG8;
   Int_t OpenL1_DoubleEG10;
   Int_t OpenL1_DoubleMu0;
   Int_t OpenL1_DoubleMu5;
   Int_t OpenL1_ETT220;
   Int_t OpenL1_SingleJet20_FwdVeto;
   Int_t OpenL1_DoubleEG2_FwdVeto;
   Int_t OpenL1_QuadJet8U;


   // Autogenerated from ConfDB - Int_t
   Int_t HLT_PFJet40_v6;
   Int_t HLT_PFJet80_v6;
   Int_t HLT_PFJet140_v6;
   Int_t HLT_PFJet200_v6;
   Int_t HLT_PFJet260_v6;
   Int_t HLT_PFJet320_v6;
   Int_t HLT_Jet370_NoJetID_v14;
   Int_t HLT_PFJet400_v6;
   Int_t HLT_MonoCentralPFJet80_PFMETnoMu105_NHEF0p95_v1;
   Int_t HLT_SingleForJet25_v3;
   Int_t HLT_SingleForJet15_v3;
   Int_t HLT_DiPFJetAve40_v7;
   Int_t HLT_DiPFJetAve80_v7;
   Int_t HLT_DiPFJetAve140_v7;
   Int_t HLT_DiPFJetAve200_v7;
   Int_t HLT_DiPFJetAve260_v7;
   Int_t HLT_DiPFJetAve320_v7;
   Int_t HLT_DiPFJetAve400_v7;
   Int_t HLT_FatDiPFJetMass750_DR1p1_Deta1p5_v6;
   Int_t HLT_DoubleJet20_ForwardBackward_v3;
   Int_t HLT_DiJet80_DiJet60_DiJet20_v3;
   Int_t HLT_DiPFJet40_PFMETnoMu65_MJJ800VBF_AllJets_v6;
   Int_t HLT_DiPFJet40_PFMETnoMu65_MJJ600VBF_LeadingJets_v6;
   Int_t HLT_DiJet40Eta2p6_BTagIP3DFastPV_v5;
   Int_t HLT_DiJet80Eta2p6_BTagIP3DFastPVLoose_v5;
   Int_t HLT_Jet60Eta1p7_Jet53Eta1p7_DiBTagIP3DFastPV_v5;
   Int_t HLT_Jet80Eta1p7_Jet70Eta1p7_DiBTagIP3DFastPV_v5;
   Int_t HLT_Jet160Eta2p4_Jet120Eta2p4_DiBTagIP3DFastPVLoose_v5;
   Int_t HLT_QuadJet50_v3;
   Int_t HLT_QuadJet50_Jet20_v2;
   Int_t HLT_QuadJet60_DiJet20_v3;
   Int_t HLT_QuadJet70_v3;
   Int_t HLT_QuadJet80_v3;
   Int_t HLT_QuadJet90_v3;
   Int_t HLT_QuadJet75_55_35_20_BTagIP_VBF_v4;
   Int_t HLT_QuadJet75_55_38_20_BTagIP_VBF_v4;
   Int_t HLT_QuadPFJet78_61_44_31_BTagCSV_VBF_v2;
   Int_t HLT_QuadPFJet82_65_48_35_BTagCSV_VBF_v2;
   Int_t HLT_SixJet35_v3;
   Int_t HLT_SixJet45_v3;
   Int_t HLT_SixJet50_v3;
   Int_t HLT_EightJet30_eta3p0_v2;
   Int_t HLT_EightJet35_eta3p0_v2;
   Int_t HLT_ExclDiJet35_HFOR_v3;
   Int_t HLT_ExclDiJet35_HFAND_v3;
   Int_t HLT_ExclDiJet80_HFAND_v3;
   Int_t HLT_JetE30_NoBPTX_v13;
   Int_t HLT_JetE30_NoBPTX3BX_NoHalo_v14;
   Int_t HLT_JetE50_NoBPTX3BX_NoHalo_v11;
   Int_t HLT_JetE70_NoBPTX3BX_NoHalo_v3;
   Int_t HLT_HT200_AlphaT0p57_v6;
   Int_t HLT_HT200_v4;
   Int_t HLT_HT250_AlphaT0p55_v5;
   Int_t HLT_HT250_AlphaT0p57_v5;
   Int_t HLT_HT250_v4;
   Int_t HLT_HT300_AlphaT0p53_v5;
   Int_t HLT_HT300_AlphaT0p54_v11;
   Int_t HLT_HT300_v4;
   Int_t HLT_HT300_DoubleDisplacedPFJet60_v6;
   Int_t HLT_HT300_DoubleDisplacedPFJet60_ChgFraction10_v6;
   Int_t HLT_HT300_SingleDisplacedPFJet60_v6;
   Int_t HLT_HT300_SingleDisplacedPFJet60_ChgFraction10_v6;
   Int_t HLT_HT350_v4;
   Int_t HLT_HT350_AlphaT0p52_v5;
   Int_t HLT_HT350_AlphaT0p53_v16;
   Int_t HLT_HT400_v4;
   Int_t HLT_HT400_AlphaT0p51_v16;
   Int_t HLT_HT400_AlphaT0p52_v11;
   Int_t HLT_HT450_AlphaT0p51_v11;
   Int_t HLT_HT450_v4;
   Int_t HLT_HT500_v4;
   Int_t HLT_HT550_v4;
   Int_t HLT_HT650_v4;
   Int_t HLT_HT650_Track50_dEdx3p6_v7;
   Int_t HLT_HT650_Track60_dEdx3p7_v7;
   Int_t HLT_HT750_v4;
   Int_t HLT_PFNoPUHT350_v1;
   Int_t HLT_PFNoPUHT650_v1;
   Int_t HLT_PFNoPUHT650_DiCentralPFNoPUJet80_CenPFNoPUJet40_v1;
   Int_t HLT_PFNoPUHT700_v1;
   Int_t HLT_PFNoPUHT750_v1;
   Int_t HLT_PFMET150_v5;
   Int_t HLT_PFMET180_v5;
   Int_t HLT_DiCentralJetSumpT100_dPhi05_DiCentralPFJet60_25_PFMET100_HBHENoiseCleaned_v2;
   Int_t HLT_DiCentralPFJet30_PFMET80_v3;
   Int_t HLT_DiCentralPFNoPUJet50_PFMETORPFMETNoMu80_v1;
   Int_t HLT_DiCentralPFJet30_PFMET80_BTagCSV07_v2;
   Int_t HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05d03_v2;
   Int_t HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05d05_v2;
   Int_t HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05_v2;
   Int_t HLT_MET80_v4;
   Int_t HLT_MET80_Track50_dEdx3p6_v5;
   Int_t HLT_MET80_Track60_dEdx3p7_v5;
   Int_t HLT_MET120_v11;
   Int_t HLT_MET120_HBHENoiseCleaned_v4;
   Int_t HLT_MET200_v11;
   Int_t HLT_MET200_HBHENoiseCleaned_v4;
   Int_t HLT_MET300_v3;
   Int_t HLT_MET300_HBHENoiseCleaned_v4;
   Int_t HLT_MET400_v6;
   Int_t HLT_MET400_HBHENoiseCleaned_v4;
   Int_t HLT_L1SingleMuOpen_v7;
   Int_t HLT_L1SingleMu12_v2;
   Int_t HLT_L2Mu70_eta2p1_PFMET55_v2;
   Int_t HLT_L2Mu70_eta2p1_PFMET60_v2;
   Int_t HLT_L2Mu20_eta2p1_NoVertex_v2;
   Int_t HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo_v3;
   Int_t HLT_L2Mu20_NoVertex_2Cha_NoBPTX3BX_NoHalo_v1;
   Int_t HLT_L2Mu30_NoVertex_2Cha_NoBPTX3BX_NoHalo_v1;
   Int_t HLT_L2TripleMu10_0_0_NoVertex_PFJet40Neutral_v5;
   Int_t HLT_DoubleDisplacedMu4_DiPFJet40Neutral_v5;
   Int_t HLT_Mu5_v19;
   Int_t HLT_Mu8_v17;
   Int_t HLT_Mu12_v17;
   Int_t HLT_Mu17_v4;
   Int_t HLT_Mu12_eta2p1_L1Mu10erJetC12WdEtaPhi1DiJetsC_v4;
   Int_t HLT_Mu15_eta2p1_v4;
   Int_t HLT_Mu24_v15;
   Int_t HLT_Mu24_eta2p1_v4;
   Int_t HLT_Mu30_v15;
   Int_t HLT_Mu30_eta2p1_v4;
   Int_t HLT_Mu40_v13;
   Int_t HLT_Mu40_eta2p1_v10;
   Int_t HLT_Mu50_eta2p1_v7;
   Int_t HLT_RelIso1p0Mu5_v5;
   Int_t HLT_RelIso1p0Mu20_v2;
   Int_t HLT_IsoMu15_eta2p1_L1ETM20_v6;
   Int_t HLT_IsoMu20_eta2p1_v6;
   Int_t HLT_IsoMu24_v16;
   Int_t HLT_IsoMu24_eta2p1_v14;
   Int_t HLT_IsoMu30_v10;
   Int_t HLT_IsoMu30_eta2p1_v14;
   Int_t HLT_IsoMu34_eta2p1_v12;
   Int_t HLT_IsoMu40_eta2p1_v9;
   Int_t HLT_Mu40_eta2p1_Track50_dEdx3p6_v4;
   Int_t HLT_Mu40_eta2p1_Track60_dEdx3p7_v4;
   Int_t HLT_L2DoubleMu23_NoVertex_v11;
   Int_t HLT_L2DoubleMu23_NoVertex_2Cha_Angle2p5_v3;
   Int_t HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_v3;
   Int_t HLT_DoubleMu11_Acoplanarity03_v4;
   Int_t HLT_DoubleMu4_Jpsi_Displaced_v10;
   Int_t HLT_DoubleMu4_JpsiTk_Displaced_v4;
   Int_t HLT_DoubleMu3_4_Dimuon5_Bs_Central_v3;
   Int_t HLT_DoubleMu3p5_4_Dimuon5_Bs_Central_v3;
   Int_t HLT_DoubleMu4_Dimuon7_Bs_Forward_v3;
   Int_t HLT_DoubleMu3p5_LowMass_Displaced_v4;
   Int_t HLT_DoubleMu3p5_LowMassNonResonant_Displaced_v4;
   Int_t HLT_Dimuon0_Jpsi_v15;
   Int_t HLT_Dimuon0_Jpsi_NoVertexing_v12;
   Int_t HLT_Dimuon0_Upsilon_v15;
   Int_t HLT_Dimuon0_PsiPrime_v4;
   Int_t HLT_Dimuon5_Upsilon_v4;
   Int_t HLT_Dimuon5_PsiPrime_v4;
   Int_t HLT_Dimuon7_Upsilon_v5;
   Int_t HLT_Dimuon7_PsiPrime_v1;
   Int_t HLT_Dimuon8_Jpsi_v5;
   Int_t HLT_Dimuon8_Upsilon_v4;
   Int_t HLT_Dimuon10_Jpsi_v4;
   Int_t HLT_Dimuon11_Upsilon_v4;
   Int_t HLT_Dimuon0_Jpsi_Muon_v16;
   Int_t HLT_Dimuon0_Upsilon_Muon_v16;
   Int_t HLT_Dimuon3p5_SameSign_v4;
   Int_t HLT_DoubleMu4_Acoplanarity03_v4;
   Int_t HLT_Tau2Mu_ItTrack_v4;
   Int_t HLT_Mu13_Mu8_v18;
   Int_t HLT_Mu17_Mu8_v18;
   Int_t HLT_Mu17_TkMu8_v11;
   Int_t HLT_Mu22_TkMu8_v7;
   Int_t HLT_Mu22_TkMu22_v7;
   Int_t HLT_TripleMu5_v18;
   Int_t HLT_DoubleMu5_IsoMu5_v19;
   Int_t HLT_Mu5_L2Mu3_Jpsi_v5;
   Int_t HLT_Mu5_Track2_Jpsi_v19;
   Int_t HLT_Mu5_Track3p5_Jpsi_v5;
   Int_t HLT_Mu7_Track7_Jpsi_v19;
   Int_t HLT_Photon20_CaloIdVL_v4;
   Int_t HLT_Photon20_CaloIdVL_IsoL_v16;
   Int_t HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_v5;
   Int_t HLT_Photon26_Photon18_v12;
   Int_t HLT_Photon26_R9Id85_Photon18_R9Id85_Mass60_v4;
   Int_t HLT_Photon26_R9Id85_Photon18_CaloId10_Iso50_Mass60_v6;
   Int_t HLT_Photon26_CaloId10_Iso50_Photon18_R9Id85_Mass60_v6;
   Int_t HLT_Photon26_CaloId10_Iso50_Photon18_CaloId10_Iso50_Mass60_v6;
   Int_t HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass60_v6;
   Int_t HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass70_v2;
   Int_t HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_v5;
   Int_t HLT_Photon30_CaloIdVL_v14;
   Int_t HLT_Photon30_CaloIdVL_IsoL_v19;
   Int_t HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_v5;
   Int_t HLT_Photon36_Photon22_v6;
   Int_t HLT_Photon36_R9Id85_Photon22_R9Id85_v4;
   Int_t HLT_Photon36_R9Id85_Photon22_CaloId10_Iso50_v6;
   Int_t HLT_Photon36_CaloId10_Iso50_Photon22_R9Id85_v6;
   Int_t HLT_Photon36_CaloId10_Iso50_Photon22_CaloId10_Iso50_v6;
   Int_t HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_R9Id85_OR_CaloId10_Iso50_v6;
   Int_t HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_v5;
   Int_t HLT_Photon50_CaloIdVL_v10;
   Int_t HLT_Photon50_CaloIdVL_IsoL_v17;
   Int_t HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_v5;
   Int_t HLT_Photon60_CaloIdL_MHT70_v9;
   Int_t HLT_Photon60_CaloIdL_HT300_v2;
   Int_t HLT_Photon70_CaloIdXL_PFNoPUHT400_v1;
   Int_t HLT_Photon70_CaloIdXL_PFNoPUHT500_v1;
   Int_t HLT_Photon70_CaloIdXL_PFMET100_v5;
   Int_t HLT_Photon75_CaloIdVL_v13;
   Int_t HLT_Photon75_CaloIdVL_IsoL_v18;
   Int_t HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_v5;
   Int_t HLT_Photon90_CaloIdVL_v10;
   Int_t HLT_Photon90_CaloIdVL_IsoL_v15;
   Int_t HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_v5;
   Int_t HLT_DisplacedPhoton65_CaloIdVL_IsoL_PFMET25_v2;
   Int_t HLT_DisplacedPhoton65EBOnly_CaloIdVL_IsoL_PFMET30_v2;
   Int_t HLT_Photon135_v7;
   Int_t HLT_Photon150_v4;
   Int_t HLT_Photon160_v4;
   Int_t HLT_Photon300_NoHE_v5;
   Int_t HLT_DoublePhoton48_HEVT_v8;
   Int_t HLT_DoublePhoton53_HEVT_v2;
   Int_t HLT_DoublePhoton70_v6;
   Int_t HLT_DoublePhoton80_v7;
   Int_t HLT_DoublePhoton5_IsoVL_CEP_v16;
   Int_t HLT_L1SingleEG5_v6;
   Int_t HLT_L1SingleEG12_v6;
   Int_t HLT_L1DoubleEG3_FwdVeto_v2;
   Int_t HLT_L1ETM30_v2;
   Int_t HLT_L1ETM40_v2;
   Int_t HLT_L1ETM70_v2;
   Int_t HLT_L1ETM100_v2;
   Int_t HLT_Ele8_CaloIdT_TrkIdVL_v5;
   Int_t HLT_Ele8_CaloIdT_TrkIdVL_EG7_v2;
   Int_t HLT_Ele8_CaloIdT_TrkIdVL_Jet30_v5;
   Int_t HLT_Ele8_CaloIdL_CaloIsoVL_v17;
   Int_t HLT_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v15;
   Int_t HLT_Ele17_CaloIdL_CaloIsoVL_v17;
   Int_t HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v6;
   Int_t HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v18;
   Int_t HLT_Ele17_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_Ele8_Mass50_v6;
   Int_t HLT_Ele20_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_SC4_Mass50_v6;
   Int_t HLT_Ele22_CaloIdL_CaloIsoVL_v6;
   Int_t HLT_Ele27_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_v11;
   Int_t HLT_Ele27_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele15_CaloIdT_CaloIsoVL_trackless_v7;
   Int_t HLT_Ele27_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_HFT15_v7;
   Int_t HLT_Ele23_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_HFT30_v7;
   Int_t HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet30_v2;
   Int_t HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet50_40_30_v2;
   Int_t HLT_Ele27_WP80_v11;
   Int_t HLT_Ele27_WP80_PFMET_MT50_v5;
   Int_t HLT_Ele30_CaloIdVT_TrkIdT_v6;
   Int_t HLT_Ele32_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_v11;
   Int_t HLT_Ele32_CaloIdT_CaloIsoT_TrkIdT_TrkIsoT_SC17_Mass50_v6;
   Int_t HLT_Ele80_CaloIdVT_GsfTrkIdT_v2;
   Int_t HLT_Ele90_CaloIdVT_GsfTrkIdT_v2;
   Int_t HLT_DoubleEle8_CaloIdT_TrkIdVL_v12;
   Int_t HLT_DoubleEle33_CaloIdL_v14;
   Int_t HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v7;
   Int_t HLT_DoubleEle33_CaloIdT_v10;
   Int_t HLT_Ele15_Ele8_Ele5_CaloIdL_TrkIdVL_v6;
   Int_t HLT_LooseIsoPFTau35_Trk20_Prong1_v7;
   Int_t HLT_LooseIsoPFTau35_Trk20_Prong1_MET70_v7;
   Int_t HLT_LooseIsoPFTau35_Trk20_Prong1_MET75_v7;
   Int_t HLT_IsoMu15_eta2p1_LooseIsoPFTau35_Trk20_Prong1_L1ETM20_v7;
   Int_t HLT_DoubleMediumIsoPFTau30_Trk1_eta2p1_Jet30_v1;
   Int_t HLT_DoubleMediumIsoPFTau30_Trk1_eta2p1_v1;
   Int_t HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Prong1_v1;
   Int_t HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_v1;
   Int_t HLT_IsoMu18_eta2p1_MediumIsoPFTau25_Trk1_eta2p1_v1;
   Int_t HLT_BTagMu_DiJet20_Mu5_v4;
   Int_t HLT_BTagMu_DiJet40_Mu5_v4;
   Int_t HLT_BTagMu_DiJet70_Mu5_v4;
   Int_t HLT_BTagMu_DiJet110_Mu5_v4;
   Int_t HLT_BTagMu_Jet300_Mu5_v4;
   Int_t HLT_Mu7_Ele7_CaloIdT_CaloIsoVL_v6;
   Int_t HLT_Mu8_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v8;
   Int_t HLT_Mu8_DiJet30_v5;
   Int_t HLT_Mu8_TriJet30_v5;
   Int_t HLT_Mu8_QuadJet30_v5;
   Int_t HLT_IsoMu12_DoubleCentralJet65_v2;
   Int_t HLT_Mu15_eta2p1_L1ETM20_v4;
   Int_t HLT_Mu24_PFJet30_PFJet25_Deta3_CentralPFJet25_v2;
   Int_t HLT_Mu24_CentralPFJet30_CentralPFJet25_v2;
   Int_t HLT_IsoMu24_PFJet30_PFJet25_Deta3_CentralPFJet25_v2;
   Int_t HLT_IsoMu24_CentralPFJet30_CentralPFJet25_v2;
   Int_t HLT_IsoMu24_CentralPFJet30_CentralPFJet25_PFMET20_v2;
   Int_t HLT_Ele32_WP80_PFJet30_PFJet25_Deta3_v2;
   Int_t HLT_Ele32_WP80_PFJet30_PFJet25_Deta3_CentralPFJet30_v2;
   Int_t HLT_Ele32_WP80_CentralPFJet35_CentralPFJet25_v2;
   Int_t HLT_Ele32_WP80_CentralPFJet35_CentralPFJet25_PFMET20_v2;
   Int_t HLT_IsoMu17_eta2p1_CentralPFNoPUJet30_BTagIPIter_v2;
   Int_t HLT_IsoMu17_eta2p1_CentralPFNoPUJet30_v2;
   Int_t HLT_IsoMu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2;
   Int_t HLT_Mu17_eta2p1_CentralPFNoPUJet30_BTagIPIter_v2;
   Int_t HLT_Mu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2;
   Int_t HLT_IsoMu20_WCandPt80_v2;
   Int_t HLT_Mu17_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v8;
   Int_t HLT_Mu12_eta2p1_DiCentral_40_20_DiBTagIP3D1stTrack_v4;
   Int_t HLT_Mu12_eta2p1_DiCentral_40_20_BTagIP3D1stTrack_v4;
   Int_t HLT_Mu12_eta2p1_DiCentral_40_20_v4;
   Int_t HLT_Mu12_eta2p1_DiCentral_20_v4;
   Int_t HLT_Mu15_eta2p1_TriCentral_40_20_20_DiBTagIP3D1stTrack_v4;
   Int_t HLT_Mu15_eta2p1_TriCentral_40_20_20_BTagIP3D1stTrack_v4;
   Int_t HLT_Mu15_eta2p1_TriCentral_40_20_20_v4;
   Int_t HLT_Mu30_Ele30_CaloIdL_v7;
   Int_t HLT_IsoMu17_eta2p1_DiCentralPFNoPUJet30_PFNoPUHT350_PFMHT40_v1;
   Int_t HLT_IsoMu20_eta2p1_CentralPFJet80_v7;
   Int_t HLT_DoubleRelIso1p0Mu5_Mass8_PFNoPUHT175_v1;
   Int_t HLT_DoubleRelIso1p0Mu5_Mass8_PFNoPUHT225_v1;
   Int_t HLT_DoubleMu8_Mass8_PFNoPUHT175_v1;
   Int_t HLT_DoubleMu8_Mass8_PFNoPUHT225_v1;
   Int_t HLT_RelIso1p0Mu5_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1;
   Int_t HLT_RelIso1p0Mu5_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1;
   Int_t HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1;
   Int_t HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1;
   Int_t HLT_PFNoPUHT350_Mu15_PFMET45_v1;
   Int_t HLT_PFNoPUHT350_Mu15_PFMET50_v1;
   Int_t HLT_PFNoPUHT400_Mu5_PFMET45_v1;
   Int_t HLT_PFNoPUHT400_Mu5_PFMET50_v1;
   Int_t HLT_Mu40_PFNoPUHT350_v1;
   Int_t HLT_Mu60_PFNoPUHT350_v1;
   Int_t HLT_Mu40_HT200_v2;
   Int_t HLT_DoubleMu5_Ele8_CaloIdT_TrkIdVL_v15;
   Int_t HLT_DoubleMu8_Ele8_CaloIdT_TrkIdVL_v4;
   Int_t HLT_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Jet30_v6;
   Int_t HLT_Ele8_CaloIdT_TrkIdT_DiJet30_v16;
   Int_t HLT_Ele8_CaloIdT_TrkIdT_TriJet30_v16;
   Int_t HLT_Ele8_CaloIdT_TrkIdT_QuadJet30_v16;
   Int_t HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Jet30_v6;
   Int_t HLT_Ele25_CaloIdVT_TrkIdT_TriCentralPFNoPUJet30_30_20_v2;
   Int_t HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_CentralPFNoPUJet30_v6;
   Int_t HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2;
   Int_t HLT_Ele25_CaloIdVL_CaloIsoT_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2;
   Int_t HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_CentralPFNoPUJet30_BTagIPIter_v7;
   Int_t HLT_Ele27_WP80_CentralPFJet80_v7;
   Int_t HLT_Ele27_WP80_WCandPt80_v7;
   Int_t HLT_Ele30_CaloIdVT_TrkIdT_PFNoPUJet100_PFNoPUJet25_v6;
   Int_t HLT_Ele30_CaloIdVT_TrkIdT_PFNoPUJet150_PFNoPUJet25_v6;
   Int_t HLT_DoubleEle8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1;
   Int_t HLT_DoubleEle8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1;
   Int_t HLT_DoubleEle10_CaloIdL_TrkIdVL_Ele10_CaloIdT_TrkIdVL_v12;
   Int_t HLT_TripleEle10_CaloIdL_TrkIdVL_v18;
   Int_t HLT_RsqMR40_Rsq0p04_v4;
   Int_t HLT_RsqMR45_Rsq0p09_v3;
   Int_t HLT_RsqMR55_Rsq0p09_MR150_v4;
   Int_t HLT_RsqMR60_Rsq0p09_MR150_v4;
   Int_t HLT_RsqMR65_Rsq0p09_MR150_v3;
   Int_t HLT_IsoMu12_RsqMR30_Rsq0p04_MR200_v2;
   Int_t HLT_IsoMu12_RsqMR40_Rsq0p04_MR200_v2;
   Int_t HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_RsqMR30_Rsq0p04_MR200_v2;
   Int_t HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_RsqMR40_Rsq0p04_MR200_v2;
   Int_t HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_DoubleCentralJet65_v2;
   Int_t HLT_Photon40_CaloIdL_RsqMR35_Rsq0p09_MR150_v4;
   Int_t HLT_Photon40_CaloIdL_RsqMR40_Rsq0p09_MR150_v4;
   Int_t HLT_Photon40_CaloIdL_RsqMR45_Rsq0p09_MR150_v4;
   Int_t HLT_Photon40_CaloIdL_RsqMR50_Rsq0p09_MR150_v4;
   Int_t HLT_DoublePhoton40_CaloIdL_Rsq0p035_v4;
   Int_t HLT_DoublePhoton40_CaloIdL_Rsq0p06_v4;
   Int_t HLT_Mu22_Photon22_CaloIdL_v6;
   Int_t HLT_Mu8_DoubleEle8_CaloIdT_TrkIdVL_v6;
   Int_t HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Ele8_CaloIdL_TrkIdVL_v6;
   Int_t HLT_DoubleMu14_Mass8_PFMET40_v6;
   Int_t HLT_DoubleMu14_Mass8_PFMET50_v6;
   Int_t HLT_DoubleEle14_CaloIdT_TrkIdVL_Mass8_PFMET40_v6;
   Int_t HLT_DoubleEle14_CaloIdT_TrkIdVL_Mass8_PFMET50_v6;
   Int_t HLT_Mu14_Ele14_CaloIdT_TrkIdVL_Mass8_PFMET40_v6;
   Int_t HLT_Mu14_Ele14_CaloIdT_TrkIdVL_Mass8_PFMET50_v6;
   Int_t HLT_PFNoPUHT350_PFMET100_v1;
   Int_t HLT_PFNoPUHT400_PFMET100_v1;
   Int_t HLT_CleanPFNoPUHT350_Ele5_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET45_v1;
   Int_t HLT_CleanPFNoPUHT350_Ele5_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET50_v1;
   Int_t HLT_CleanPFNoPUHT300_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET45_v1;
   Int_t HLT_CleanPFNoPUHT300_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET50_v1;
   Int_t HLT_CleanPFNoPUHT300_Ele40_CaloIdVT_TrkIdT_v1;
   Int_t HLT_CleanPFNoPUHT300_Ele60_CaloIdVT_TrkIdT_v1;
   Int_t HLT_Ele5_SC5_Jpsi_Mass2to15_v4;
   Int_t HLT_DiJet35_MJJ650_AllJets_DEta3p5_VBF_v2;
   Int_t HLT_DiJet35_MJJ700_AllJets_DEta3p5_VBF_v2;
   Int_t HLT_DiJet35_MJJ750_AllJets_DEta3p5_VBF_v2;
   Int_t HLT_Ele22_eta2p1_WP90Rho_LooseIsoPFTau20_v3;
   Int_t HLT_Ele22_eta2p1_WP90NoIso_LooseIsoPFTau20_v3;
   Int_t HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v3;
   Int_t HLT_Mu17_eta2p1_LooseIsoPFTau20_v3;
   Int_t HLT_PixelTracks_Multiplicity70_v3;
   Int_t HLT_PixelTracks_Multiplicity80_v12;
   Int_t HLT_PixelTracks_Multiplicity90_v3;
   Int_t HLT_BeamGas_HF_Beam1_v5;
   Int_t HLT_BeamGas_HF_Beam2_v5;
   Int_t HLT_BeamHalo_v13;
   Int_t HLT_IsoTrackHE_v15;
   Int_t HLT_IsoTrackHB_v14;
   Int_t HLT_HcalPhiSym_v11;
   Int_t HLT_HcalNZS_v10;
   Int_t HLT_GlobalRunHPDNoise_v8;
   Int_t HLT_L1Tech_HBHEHO_totalOR_v6;
   Int_t HLT_L1Tech_HCAL_HF_single_channel_v4;
   Int_t HLT_ZeroBias_v7;
   Int_t HLT_ZeroBiasPixel_DoubleTrack_v2;
   Int_t HLT_Physics_v5;
   Int_t HLT_DTCalibration_v2;
   Int_t HLT_EcalCalibration_v3;
   Int_t HLT_HcalCalibration_v3;
   Int_t HLT_TrackerCalibration_v3;
   Int_t HLT_Random_v2;
   Int_t HLT_L1SingleMuOpen_AntiBPTX_v7;
   Int_t HLT_L1TrackerCosmics_v7;
   Int_t HLT_LogMonitor_v3;
   Int_t HLT_DTErrors_v3;
   Int_t HLT_L1DoubleJet36Central_v7;
   Int_t AlCa_EcalPi0EBonly_v6;
   Int_t AlCa_EcalPi0EEonly_v6;
   Int_t AlCa_EcalEtaEBonly_v6;
   Int_t AlCa_EcalEtaEEonly_v6;
   Int_t AlCa_EcalPhiSym_v13;
   Int_t AlCa_RPCMuonNoTriggers_v9;
   Int_t AlCa_RPCMuonNoHits_v9;
   Int_t AlCa_RPCMuonNormalisation_v9;
   Int_t AlCa_LumiPixels_v7;
   Int_t AlCa_LumiPixels_ZeroBias_v4;
   Int_t AlCa_LumiPixels_Random_v1;
   Int_t HLT_Activity_Ecal_SC7_v13;
   Int_t HLT_L1SingleJet16_v7;
   Int_t HLT_L1SingleJet36_v7;





   // Autogenerated from ConfDB - Prescale Int_t
   Int_t HLT_PFJet40_v6_Prescl;
   Int_t HLT_PFJet80_v6_Prescl;
   Int_t HLT_PFJet140_v6_Prescl;
   Int_t HLT_PFJet200_v6_Prescl;
   Int_t HLT_PFJet260_v6_Prescl;
   Int_t HLT_PFJet320_v6_Prescl;
   Int_t HLT_Jet370_NoJetID_v14_Prescl;
   Int_t HLT_PFJet400_v6_Prescl;
   Int_t HLT_MonoCentralPFJet80_PFMETnoMu105_NHEF0p95_v1_Prescl;
   Int_t HLT_SingleForJet25_v3_Prescl;
   Int_t HLT_SingleForJet15_v3_Prescl;
   Int_t HLT_DiPFJetAve40_v7_Prescl;
   Int_t HLT_DiPFJetAve80_v7_Prescl;
   Int_t HLT_DiPFJetAve140_v7_Prescl;
   Int_t HLT_DiPFJetAve200_v7_Prescl;
   Int_t HLT_DiPFJetAve260_v7_Prescl;
   Int_t HLT_DiPFJetAve320_v7_Prescl;
   Int_t HLT_DiPFJetAve400_v7_Prescl;
   Int_t HLT_FatDiPFJetMass750_DR1p1_Deta1p5_v6_Prescl;
   Int_t HLT_DoubleJet20_ForwardBackward_v3_Prescl;
   Int_t HLT_DiJet80_DiJet60_DiJet20_v3_Prescl;
   Int_t HLT_DiPFJet40_PFMETnoMu65_MJJ800VBF_AllJets_v6_Prescl;
   Int_t HLT_DiPFJet40_PFMETnoMu65_MJJ600VBF_LeadingJets_v6_Prescl;
   Int_t HLT_DiJet40Eta2p6_BTagIP3DFastPV_v5_Prescl;
   Int_t HLT_DiJet80Eta2p6_BTagIP3DFastPVLoose_v5_Prescl;
   Int_t HLT_Jet60Eta1p7_Jet53Eta1p7_DiBTagIP3DFastPV_v5_Prescl;
   Int_t HLT_Jet80Eta1p7_Jet70Eta1p7_DiBTagIP3DFastPV_v5_Prescl;
   Int_t HLT_Jet160Eta2p4_Jet120Eta2p4_DiBTagIP3DFastPVLoose_v5_Prescl;
   Int_t HLT_QuadJet50_v3_Prescl;
   Int_t HLT_QuadJet50_Jet20_v2_Prescl;
   Int_t HLT_QuadJet60_DiJet20_v3_Prescl;
   Int_t HLT_QuadJet70_v3_Prescl;
   Int_t HLT_QuadJet80_v3_Prescl;
   Int_t HLT_QuadJet90_v3_Prescl;
   Int_t HLT_QuadJet75_55_35_20_BTagIP_VBF_v4_Prescl;
   Int_t HLT_QuadJet75_55_38_20_BTagIP_VBF_v4_Prescl;
   Int_t HLT_QuadPFJet78_61_44_31_BTagCSV_VBF_v2_Prescl;
   Int_t HLT_QuadPFJet82_65_48_35_BTagCSV_VBF_v2_Prescl;
   Int_t HLT_SixJet35_v3_Prescl;
   Int_t HLT_SixJet45_v3_Prescl;
   Int_t HLT_SixJet50_v3_Prescl;
   Int_t HLT_EightJet30_eta3p0_v2_Prescl;
   Int_t HLT_EightJet35_eta3p0_v2_Prescl;
   Int_t HLT_ExclDiJet35_HFOR_v3_Prescl;
   Int_t HLT_ExclDiJet35_HFAND_v3_Prescl;
   Int_t HLT_ExclDiJet80_HFAND_v3_Prescl;
   Int_t HLT_JetE30_NoBPTX_v13_Prescl;
   Int_t HLT_JetE30_NoBPTX3BX_NoHalo_v14_Prescl;
   Int_t HLT_JetE50_NoBPTX3BX_NoHalo_v11_Prescl;
   Int_t HLT_JetE70_NoBPTX3BX_NoHalo_v3_Prescl;
   Int_t HLT_HT200_AlphaT0p57_v6_Prescl;
   Int_t HLT_HT200_v4_Prescl;
   Int_t HLT_HT250_AlphaT0p55_v5_Prescl;
   Int_t HLT_HT250_AlphaT0p57_v5_Prescl;
   Int_t HLT_HT250_v4_Prescl;
   Int_t HLT_HT300_AlphaT0p53_v5_Prescl;
   Int_t HLT_HT300_AlphaT0p54_v11_Prescl;
   Int_t HLT_HT300_v4_Prescl;
   Int_t HLT_HT300_DoubleDisplacedPFJet60_v6_Prescl;
   Int_t HLT_HT300_DoubleDisplacedPFJet60_ChgFraction10_v6_Prescl;
   Int_t HLT_HT300_SingleDisplacedPFJet60_v6_Prescl;
   Int_t HLT_HT300_SingleDisplacedPFJet60_ChgFraction10_v6_Prescl;
   Int_t HLT_HT350_v4_Prescl;
   Int_t HLT_HT350_AlphaT0p52_v5_Prescl;
   Int_t HLT_HT350_AlphaT0p53_v16_Prescl;
   Int_t HLT_HT400_v4_Prescl;
   Int_t HLT_HT400_AlphaT0p51_v16_Prescl;
   Int_t HLT_HT400_AlphaT0p52_v11_Prescl;
   Int_t HLT_HT450_AlphaT0p51_v11_Prescl;
   Int_t HLT_HT450_v4_Prescl;
   Int_t HLT_HT500_v4_Prescl;
   Int_t HLT_HT550_v4_Prescl;
   Int_t HLT_HT650_v4_Prescl;
   Int_t HLT_HT650_Track50_dEdx3p6_v7_Prescl;
   Int_t HLT_HT650_Track60_dEdx3p7_v7_Prescl;
   Int_t HLT_HT750_v4_Prescl;
   Int_t HLT_PFNoPUHT350_v1_Prescl;
   Int_t HLT_PFNoPUHT650_v1_Prescl;
   Int_t HLT_PFNoPUHT650_DiCentralPFNoPUJet80_CenPFNoPUJet40_v1_Prescl;
   Int_t HLT_PFNoPUHT700_v1_Prescl;
   Int_t HLT_PFNoPUHT750_v1_Prescl;
   Int_t HLT_PFMET150_v5_Prescl;
   Int_t HLT_PFMET180_v5_Prescl;
   Int_t HLT_DiCentralJetSumpT100_dPhi05_DiCentralPFJet60_25_PFMET100_HBHENoiseCleaned_v2_Prescl;
   Int_t HLT_DiCentralPFJet30_PFMET80_v3_Prescl;
   Int_t HLT_DiCentralPFNoPUJet50_PFMETORPFMETNoMu80_v1_Prescl;
   Int_t HLT_DiCentralPFJet30_PFMET80_BTagCSV07_v2_Prescl;
   Int_t HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05d03_v2_Prescl;
   Int_t HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05d05_v2_Prescl;
   Int_t HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05_v2_Prescl;
   Int_t HLT_MET80_v4_Prescl;
   Int_t HLT_MET80_Track50_dEdx3p6_v5_Prescl;
   Int_t HLT_MET80_Track60_dEdx3p7_v5_Prescl;
   Int_t HLT_MET120_v11_Prescl;
   Int_t HLT_MET120_HBHENoiseCleaned_v4_Prescl;
   Int_t HLT_MET200_v11_Prescl;
   Int_t HLT_MET200_HBHENoiseCleaned_v4_Prescl;
   Int_t HLT_MET300_v3_Prescl;
   Int_t HLT_MET300_HBHENoiseCleaned_v4_Prescl;
   Int_t HLT_MET400_v6_Prescl;
   Int_t HLT_MET400_HBHENoiseCleaned_v4_Prescl;
   Int_t HLT_L1SingleMuOpen_v7_Prescl;
   Int_t HLT_L1SingleMu12_v2_Prescl;
   Int_t HLT_L2Mu70_eta2p1_PFMET55_v2_Prescl;
   Int_t HLT_L2Mu70_eta2p1_PFMET60_v2_Prescl;
   Int_t HLT_L2Mu20_eta2p1_NoVertex_v2_Prescl;
   Int_t HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo_v3_Prescl;
   Int_t HLT_L2Mu20_NoVertex_2Cha_NoBPTX3BX_NoHalo_v1_Prescl;
   Int_t HLT_L2Mu30_NoVertex_2Cha_NoBPTX3BX_NoHalo_v1_Prescl;
   Int_t HLT_L2TripleMu10_0_0_NoVertex_PFJet40Neutral_v5_Prescl;
   Int_t HLT_DoubleDisplacedMu4_DiPFJet40Neutral_v5_Prescl;
   Int_t HLT_Mu5_v19_Prescl;
   Int_t HLT_Mu8_v17_Prescl;
   Int_t HLT_Mu12_v17_Prescl;
   Int_t HLT_Mu17_v4_Prescl;
   Int_t HLT_Mu12_eta2p1_L1Mu10erJetC12WdEtaPhi1DiJetsC_v4_Prescl;
   Int_t HLT_Mu15_eta2p1_v4_Prescl;
   Int_t HLT_Mu24_v15_Prescl;
   Int_t HLT_Mu24_eta2p1_v4_Prescl;
   Int_t HLT_Mu30_v15_Prescl;
   Int_t HLT_Mu30_eta2p1_v4_Prescl;
   Int_t HLT_Mu40_v13_Prescl;
   Int_t HLT_Mu40_eta2p1_v10_Prescl;
   Int_t HLT_Mu50_eta2p1_v7_Prescl;
   Int_t HLT_RelIso1p0Mu5_v5_Prescl;
   Int_t HLT_RelIso1p0Mu20_v2_Prescl;
   Int_t HLT_IsoMu15_eta2p1_L1ETM20_v6_Prescl;
   Int_t HLT_IsoMu20_eta2p1_v6_Prescl;
   Int_t HLT_IsoMu24_v16_Prescl;
   Int_t HLT_IsoMu24_eta2p1_v14_Prescl;
   Int_t HLT_IsoMu30_v10_Prescl;
   Int_t HLT_IsoMu30_eta2p1_v14_Prescl;
   Int_t HLT_IsoMu34_eta2p1_v12_Prescl;
   Int_t HLT_IsoMu40_eta2p1_v9_Prescl;
   Int_t HLT_Mu40_eta2p1_Track50_dEdx3p6_v4_Prescl;
   Int_t HLT_Mu40_eta2p1_Track60_dEdx3p7_v4_Prescl;
   Int_t HLT_L2DoubleMu23_NoVertex_v11_Prescl;
   Int_t HLT_L2DoubleMu23_NoVertex_2Cha_Angle2p5_v3_Prescl;
   Int_t HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_v3_Prescl;
   Int_t HLT_DoubleMu11_Acoplanarity03_v4_Prescl;
   Int_t HLT_DoubleMu4_Jpsi_Displaced_v10_Prescl;
   Int_t HLT_DoubleMu4_JpsiTk_Displaced_v4_Prescl;
   Int_t HLT_DoubleMu3_4_Dimuon5_Bs_Central_v3_Prescl;
   Int_t HLT_DoubleMu3p5_4_Dimuon5_Bs_Central_v3_Prescl;
   Int_t HLT_DoubleMu4_Dimuon7_Bs_Forward_v3_Prescl;
   Int_t HLT_DoubleMu3p5_LowMass_Displaced_v4_Prescl;
   Int_t HLT_DoubleMu3p5_LowMassNonResonant_Displaced_v4_Prescl;
   Int_t HLT_Dimuon0_Jpsi_v15_Prescl;
   Int_t HLT_Dimuon0_Jpsi_NoVertexing_v12_Prescl;
   Int_t HLT_Dimuon0_Upsilon_v15_Prescl;
   Int_t HLT_Dimuon0_PsiPrime_v4_Prescl;
   Int_t HLT_Dimuon5_Upsilon_v4_Prescl;
   Int_t HLT_Dimuon5_PsiPrime_v4_Prescl;
   Int_t HLT_Dimuon7_Upsilon_v5_Prescl;
   Int_t HLT_Dimuon7_PsiPrime_v1_Prescl;
   Int_t HLT_Dimuon8_Jpsi_v5_Prescl;
   Int_t HLT_Dimuon8_Upsilon_v4_Prescl;
   Int_t HLT_Dimuon10_Jpsi_v4_Prescl;
   Int_t HLT_Dimuon11_Upsilon_v4_Prescl;
   Int_t HLT_Dimuon0_Jpsi_Muon_v16_Prescl;
   Int_t HLT_Dimuon0_Upsilon_Muon_v16_Prescl;
   Int_t HLT_Dimuon3p5_SameSign_v4_Prescl;
   Int_t HLT_DoubleMu4_Acoplanarity03_v4_Prescl;
   Int_t HLT_Tau2Mu_ItTrack_v4_Prescl;
   Int_t HLT_Mu13_Mu8_v18_Prescl;
   Int_t HLT_Mu17_Mu8_v18_Prescl;
   Int_t HLT_Mu17_TkMu8_v11_Prescl;
   Int_t HLT_Mu22_TkMu8_v7_Prescl;
   Int_t HLT_Mu22_TkMu22_v7_Prescl;
   Int_t HLT_TripleMu5_v18_Prescl;
   Int_t HLT_DoubleMu5_IsoMu5_v19_Prescl;
   Int_t HLT_Mu5_L2Mu3_Jpsi_v5_Prescl;
   Int_t HLT_Mu5_Track2_Jpsi_v19_Prescl;
   Int_t HLT_Mu5_Track3p5_Jpsi_v5_Prescl;
   Int_t HLT_Mu7_Track7_Jpsi_v19_Prescl;
   Int_t HLT_Photon20_CaloIdVL_v4_Prescl;
   Int_t HLT_Photon20_CaloIdVL_IsoL_v16_Prescl;
   Int_t HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_v5_Prescl;
   Int_t HLT_Photon26_Photon18_v12_Prescl;
   Int_t HLT_Photon26_R9Id85_Photon18_R9Id85_Mass60_v4_Prescl;
   Int_t HLT_Photon26_R9Id85_Photon18_CaloId10_Iso50_Mass60_v6_Prescl;
   Int_t HLT_Photon26_CaloId10_Iso50_Photon18_R9Id85_Mass60_v6_Prescl;
   Int_t HLT_Photon26_CaloId10_Iso50_Photon18_CaloId10_Iso50_Mass60_v6_Prescl;
   Int_t HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass60_v6_Prescl;
   Int_t HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass70_v2_Prescl;
   Int_t HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_v5_Prescl;
   Int_t HLT_Photon30_CaloIdVL_v14_Prescl;
   Int_t HLT_Photon30_CaloIdVL_IsoL_v19_Prescl;
   Int_t HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_v5_Prescl;
   Int_t HLT_Photon36_Photon22_v6_Prescl;
   Int_t HLT_Photon36_R9Id85_Photon22_R9Id85_v4_Prescl;
   Int_t HLT_Photon36_R9Id85_Photon22_CaloId10_Iso50_v6_Prescl;
   Int_t HLT_Photon36_CaloId10_Iso50_Photon22_R9Id85_v6_Prescl;
   Int_t HLT_Photon36_CaloId10_Iso50_Photon22_CaloId10_Iso50_v6_Prescl;
   Int_t HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_R9Id85_OR_CaloId10_Iso50_v6_Prescl;
   Int_t HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_v5_Prescl;
   Int_t HLT_Photon50_CaloIdVL_v10_Prescl;
   Int_t HLT_Photon50_CaloIdVL_IsoL_v17_Prescl;
   Int_t HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_v5_Prescl;
   Int_t HLT_Photon60_CaloIdL_MHT70_v9_Prescl;
   Int_t HLT_Photon60_CaloIdL_HT300_v2_Prescl;
   Int_t HLT_Photon70_CaloIdXL_PFNoPUHT400_v1_Prescl;
   Int_t HLT_Photon70_CaloIdXL_PFNoPUHT500_v1_Prescl;
   Int_t HLT_Photon70_CaloIdXL_PFMET100_v5_Prescl;
   Int_t HLT_Photon75_CaloIdVL_v13_Prescl;
   Int_t HLT_Photon75_CaloIdVL_IsoL_v18_Prescl;
   Int_t HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_v5_Prescl;
   Int_t HLT_Photon90_CaloIdVL_v10_Prescl;
   Int_t HLT_Photon90_CaloIdVL_IsoL_v15_Prescl;
   Int_t HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_v5_Prescl;
   Int_t HLT_DisplacedPhoton65_CaloIdVL_IsoL_PFMET25_v2_Prescl;
   Int_t HLT_DisplacedPhoton65EBOnly_CaloIdVL_IsoL_PFMET30_v2_Prescl;
   Int_t HLT_Photon135_v7_Prescl;
   Int_t HLT_Photon150_v4_Prescl;
   Int_t HLT_Photon160_v4_Prescl;
   Int_t HLT_Photon300_NoHE_v5_Prescl;
   Int_t HLT_DoublePhoton48_HEVT_v8_Prescl;
   Int_t HLT_DoublePhoton53_HEVT_v2_Prescl;
   Int_t HLT_DoublePhoton70_v6_Prescl;
   Int_t HLT_DoublePhoton80_v7_Prescl;
   Int_t HLT_DoublePhoton5_IsoVL_CEP_v16_Prescl;
   Int_t HLT_L1SingleEG5_v6_Prescl;
   Int_t HLT_L1SingleEG12_v6_Prescl;
   Int_t HLT_L1DoubleEG3_FwdVeto_v2_Prescl;
   Int_t HLT_L1ETM30_v2_Prescl;
   Int_t HLT_L1ETM40_v2_Prescl;
   Int_t HLT_L1ETM70_v2_Prescl;
   Int_t HLT_L1ETM100_v2_Prescl;
   Int_t HLT_Ele8_CaloIdT_TrkIdVL_v5_Prescl;
   Int_t HLT_Ele8_CaloIdT_TrkIdVL_EG7_v2_Prescl;
   Int_t HLT_Ele8_CaloIdT_TrkIdVL_Jet30_v5_Prescl;
   Int_t HLT_Ele8_CaloIdL_CaloIsoVL_v17_Prescl;
   Int_t HLT_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v15_Prescl;
   Int_t HLT_Ele17_CaloIdL_CaloIsoVL_v17_Prescl;
   Int_t HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v6_Prescl;
   Int_t HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v18_Prescl;
   Int_t HLT_Ele17_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_Ele8_Mass50_v6_Prescl;
   Int_t HLT_Ele20_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_SC4_Mass50_v6_Prescl;
   Int_t HLT_Ele22_CaloIdL_CaloIsoVL_v6_Prescl;
   Int_t HLT_Ele27_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_v11_Prescl;
   Int_t HLT_Ele27_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele15_CaloIdT_CaloIsoVL_trackless_v7_Prescl;
   Int_t HLT_Ele27_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_HFT15_v7_Prescl;
   Int_t HLT_Ele23_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_HFT30_v7_Prescl;
   Int_t HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet30_v2_Prescl;
   Int_t HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet50_40_30_v2_Prescl;
   Int_t HLT_Ele27_WP80_v11_Prescl;
   Int_t HLT_Ele27_WP80_PFMET_MT50_v5_Prescl;
   Int_t HLT_Ele30_CaloIdVT_TrkIdT_v6_Prescl;
   Int_t HLT_Ele32_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_v11_Prescl;
   Int_t HLT_Ele32_CaloIdT_CaloIsoT_TrkIdT_TrkIsoT_SC17_Mass50_v6_Prescl;
   Int_t HLT_Ele80_CaloIdVT_GsfTrkIdT_v2_Prescl;
   Int_t HLT_Ele90_CaloIdVT_GsfTrkIdT_v2_Prescl;
   Int_t HLT_DoubleEle8_CaloIdT_TrkIdVL_v12_Prescl;
   Int_t HLT_DoubleEle33_CaloIdL_v14_Prescl;
   Int_t HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v7_Prescl;
   Int_t HLT_DoubleEle33_CaloIdT_v10_Prescl;
   Int_t HLT_Ele15_Ele8_Ele5_CaloIdL_TrkIdVL_v6_Prescl;
   Int_t HLT_LooseIsoPFTau35_Trk20_Prong1_v7_Prescl;
   Int_t HLT_LooseIsoPFTau35_Trk20_Prong1_MET70_v7_Prescl;
   Int_t HLT_LooseIsoPFTau35_Trk20_Prong1_MET75_v7_Prescl;
   Int_t HLT_IsoMu15_eta2p1_LooseIsoPFTau35_Trk20_Prong1_L1ETM20_v7_Prescl;
   Int_t HLT_DoubleMediumIsoPFTau30_Trk1_eta2p1_Jet30_v1_Prescl;
   Int_t HLT_DoubleMediumIsoPFTau30_Trk1_eta2p1_v1_Prescl;
   Int_t HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Prong1_v1_Prescl;
   Int_t HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_v1_Prescl;
   Int_t HLT_IsoMu18_eta2p1_MediumIsoPFTau25_Trk1_eta2p1_v1_Prescl;
   Int_t HLT_BTagMu_DiJet20_Mu5_v4_Prescl;
   Int_t HLT_BTagMu_DiJet40_Mu5_v4_Prescl;
   Int_t HLT_BTagMu_DiJet70_Mu5_v4_Prescl;
   Int_t HLT_BTagMu_DiJet110_Mu5_v4_Prescl;
   Int_t HLT_BTagMu_Jet300_Mu5_v4_Prescl;
   Int_t HLT_Mu7_Ele7_CaloIdT_CaloIsoVL_v6_Prescl;
   Int_t HLT_Mu8_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v8_Prescl;
   Int_t HLT_Mu8_DiJet30_v5_Prescl;
   Int_t HLT_Mu8_TriJet30_v5_Prescl;
   Int_t HLT_Mu8_QuadJet30_v5_Prescl;
   Int_t HLT_IsoMu12_DoubleCentralJet65_v2_Prescl;
   Int_t HLT_Mu15_eta2p1_L1ETM20_v4_Prescl;
   Int_t HLT_Mu24_PFJet30_PFJet25_Deta3_CentralPFJet25_v2_Prescl;
   Int_t HLT_Mu24_CentralPFJet30_CentralPFJet25_v2_Prescl;
   Int_t HLT_IsoMu24_PFJet30_PFJet25_Deta3_CentralPFJet25_v2_Prescl;
   Int_t HLT_IsoMu24_CentralPFJet30_CentralPFJet25_v2_Prescl;
   Int_t HLT_IsoMu24_CentralPFJet30_CentralPFJet25_PFMET20_v2_Prescl;
   Int_t HLT_Ele32_WP80_PFJet30_PFJet25_Deta3_v2_Prescl;
   Int_t HLT_Ele32_WP80_PFJet30_PFJet25_Deta3_CentralPFJet30_v2_Prescl;
   Int_t HLT_Ele32_WP80_CentralPFJet35_CentralPFJet25_v2_Prescl;
   Int_t HLT_Ele32_WP80_CentralPFJet35_CentralPFJet25_PFMET20_v2_Prescl;
   Int_t HLT_IsoMu17_eta2p1_CentralPFNoPUJet30_BTagIPIter_v2_Prescl;
   Int_t HLT_IsoMu17_eta2p1_CentralPFNoPUJet30_v2_Prescl;
   Int_t HLT_IsoMu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2_Prescl;
   Int_t HLT_Mu17_eta2p1_CentralPFNoPUJet30_BTagIPIter_v2_Prescl;
   Int_t HLT_Mu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2_Prescl;
   Int_t HLT_IsoMu20_WCandPt80_v2_Prescl;
   Int_t HLT_Mu17_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v8_Prescl;
   Int_t HLT_Mu12_eta2p1_DiCentral_40_20_DiBTagIP3D1stTrack_v4_Prescl;
   Int_t HLT_Mu12_eta2p1_DiCentral_40_20_BTagIP3D1stTrack_v4_Prescl;
   Int_t HLT_Mu12_eta2p1_DiCentral_40_20_v4_Prescl;
   Int_t HLT_Mu12_eta2p1_DiCentral_20_v4_Prescl;
   Int_t HLT_Mu15_eta2p1_TriCentral_40_20_20_DiBTagIP3D1stTrack_v4_Prescl;
   Int_t HLT_Mu15_eta2p1_TriCentral_40_20_20_BTagIP3D1stTrack_v4_Prescl;
   Int_t HLT_Mu15_eta2p1_TriCentral_40_20_20_v4_Prescl;
   Int_t HLT_Mu30_Ele30_CaloIdL_v7_Prescl;
   Int_t HLT_IsoMu17_eta2p1_DiCentralPFNoPUJet30_PFNoPUHT350_PFMHT40_v1_Prescl;
   Int_t HLT_IsoMu20_eta2p1_CentralPFJet80_v7_Prescl;
   Int_t HLT_DoubleRelIso1p0Mu5_Mass8_PFNoPUHT175_v1_Prescl;
   Int_t HLT_DoubleRelIso1p0Mu5_Mass8_PFNoPUHT225_v1_Prescl;
   Int_t HLT_DoubleMu8_Mass8_PFNoPUHT175_v1_Prescl;
   Int_t HLT_DoubleMu8_Mass8_PFNoPUHT225_v1_Prescl;
   Int_t HLT_RelIso1p0Mu5_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1_Prescl;
   Int_t HLT_RelIso1p0Mu5_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1_Prescl;
   Int_t HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1_Prescl;
   Int_t HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1_Prescl;
   Int_t HLT_PFNoPUHT350_Mu15_PFMET45_v1_Prescl;
   Int_t HLT_PFNoPUHT350_Mu15_PFMET50_v1_Prescl;
   Int_t HLT_PFNoPUHT400_Mu5_PFMET45_v1_Prescl;
   Int_t HLT_PFNoPUHT400_Mu5_PFMET50_v1_Prescl;
   Int_t HLT_Mu40_PFNoPUHT350_v1_Prescl;
   Int_t HLT_Mu60_PFNoPUHT350_v1_Prescl;
   Int_t HLT_Mu40_HT200_v2_Prescl;
   Int_t HLT_DoubleMu5_Ele8_CaloIdT_TrkIdVL_v15_Prescl;
   Int_t HLT_DoubleMu8_Ele8_CaloIdT_TrkIdVL_v4_Prescl;
   Int_t HLT_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Jet30_v6_Prescl;
   Int_t HLT_Ele8_CaloIdT_TrkIdT_DiJet30_v16_Prescl;
   Int_t HLT_Ele8_CaloIdT_TrkIdT_TriJet30_v16_Prescl;
   Int_t HLT_Ele8_CaloIdT_TrkIdT_QuadJet30_v16_Prescl;
   Int_t HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Jet30_v6_Prescl;
   Int_t HLT_Ele25_CaloIdVT_TrkIdT_TriCentralPFNoPUJet30_30_20_v2_Prescl;
   Int_t HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_CentralPFNoPUJet30_v6_Prescl;
   Int_t HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2_Prescl;
   Int_t HLT_Ele25_CaloIdVL_CaloIsoT_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2_Prescl;
   Int_t HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_CentralPFNoPUJet30_BTagIPIter_v7_Prescl;
   Int_t HLT_Ele27_WP80_CentralPFJet80_v7_Prescl;
   Int_t HLT_Ele27_WP80_WCandPt80_v7_Prescl;
   Int_t HLT_Ele30_CaloIdVT_TrkIdT_PFNoPUJet100_PFNoPUJet25_v6_Prescl;
   Int_t HLT_Ele30_CaloIdVT_TrkIdT_PFNoPUJet150_PFNoPUJet25_v6_Prescl;
   Int_t HLT_DoubleEle8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1_Prescl;
   Int_t HLT_DoubleEle8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1_Prescl;
   Int_t HLT_DoubleEle10_CaloIdL_TrkIdVL_Ele10_CaloIdT_TrkIdVL_v12_Prescl;
   Int_t HLT_TripleEle10_CaloIdL_TrkIdVL_v18_Prescl;
   Int_t HLT_RsqMR40_Rsq0p04_v4_Prescl;
   Int_t HLT_RsqMR45_Rsq0p09_v3_Prescl;
   Int_t HLT_RsqMR55_Rsq0p09_MR150_v4_Prescl;
   Int_t HLT_RsqMR60_Rsq0p09_MR150_v4_Prescl;
   Int_t HLT_RsqMR65_Rsq0p09_MR150_v3_Prescl;
   Int_t HLT_IsoMu12_RsqMR30_Rsq0p04_MR200_v2_Prescl;
   Int_t HLT_IsoMu12_RsqMR40_Rsq0p04_MR200_v2_Prescl;
   Int_t HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_RsqMR30_Rsq0p04_MR200_v2_Prescl;
   Int_t HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_RsqMR40_Rsq0p04_MR200_v2_Prescl;
   Int_t HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_DoubleCentralJet65_v2_Prescl;
   Int_t HLT_Photon40_CaloIdL_RsqMR35_Rsq0p09_MR150_v4_Prescl;
   Int_t HLT_Photon40_CaloIdL_RsqMR40_Rsq0p09_MR150_v4_Prescl;
   Int_t HLT_Photon40_CaloIdL_RsqMR45_Rsq0p09_MR150_v4_Prescl;
   Int_t HLT_Photon40_CaloIdL_RsqMR50_Rsq0p09_MR150_v4_Prescl;
   Int_t HLT_DoublePhoton40_CaloIdL_Rsq0p035_v4_Prescl;
   Int_t HLT_DoublePhoton40_CaloIdL_Rsq0p06_v4_Prescl;
   Int_t HLT_Mu22_Photon22_CaloIdL_v6_Prescl;
   Int_t HLT_Mu8_DoubleEle8_CaloIdT_TrkIdVL_v6_Prescl;
   Int_t HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Ele8_CaloIdL_TrkIdVL_v6_Prescl;
   Int_t HLT_DoubleMu14_Mass8_PFMET40_v6_Prescl;
   Int_t HLT_DoubleMu14_Mass8_PFMET50_v6_Prescl;
   Int_t HLT_DoubleEle14_CaloIdT_TrkIdVL_Mass8_PFMET40_v6_Prescl;
   Int_t HLT_DoubleEle14_CaloIdT_TrkIdVL_Mass8_PFMET50_v6_Prescl;
   Int_t HLT_Mu14_Ele14_CaloIdT_TrkIdVL_Mass8_PFMET40_v6_Prescl;
   Int_t HLT_Mu14_Ele14_CaloIdT_TrkIdVL_Mass8_PFMET50_v6_Prescl;
   Int_t HLT_PFNoPUHT350_PFMET100_v1_Prescl;
   Int_t HLT_PFNoPUHT400_PFMET100_v1_Prescl;
   Int_t HLT_CleanPFNoPUHT350_Ele5_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET45_v1_Prescl;
   Int_t HLT_CleanPFNoPUHT350_Ele5_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET50_v1_Prescl;
   Int_t HLT_CleanPFNoPUHT300_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET45_v1_Prescl;
   Int_t HLT_CleanPFNoPUHT300_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET50_v1_Prescl;
   Int_t HLT_CleanPFNoPUHT300_Ele40_CaloIdVT_TrkIdT_v1_Prescl;
   Int_t HLT_CleanPFNoPUHT300_Ele60_CaloIdVT_TrkIdT_v1_Prescl;
   Int_t HLT_Ele5_SC5_Jpsi_Mass2to15_v4_Prescl;
   Int_t HLT_DiJet35_MJJ650_AllJets_DEta3p5_VBF_v2_Prescl;
   Int_t HLT_DiJet35_MJJ700_AllJets_DEta3p5_VBF_v2_Prescl;
   Int_t HLT_DiJet35_MJJ750_AllJets_DEta3p5_VBF_v2_Prescl;
   Int_t HLT_Ele22_eta2p1_WP90Rho_LooseIsoPFTau20_v3_Prescl;
   Int_t HLT_Ele22_eta2p1_WP90NoIso_LooseIsoPFTau20_v3_Prescl;
   Int_t HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v3_Prescl;
   Int_t HLT_Mu17_eta2p1_LooseIsoPFTau20_v3_Prescl;
   Int_t HLT_PixelTracks_Multiplicity70_v3_Prescl;
   Int_t HLT_PixelTracks_Multiplicity80_v12_Prescl;
   Int_t HLT_PixelTracks_Multiplicity90_v3_Prescl;
   Int_t HLT_BeamGas_HF_Beam1_v5_Prescl;
   Int_t HLT_BeamGas_HF_Beam2_v5_Prescl;
   Int_t HLT_BeamHalo_v13_Prescl;
   Int_t HLT_IsoTrackHE_v15_Prescl;
   Int_t HLT_IsoTrackHB_v14_Prescl;
   Int_t HLT_HcalPhiSym_v11_Prescl;
   Int_t HLT_HcalNZS_v10_Prescl;
   Int_t HLT_GlobalRunHPDNoise_v8_Prescl;
   Int_t HLT_L1Tech_HBHEHO_totalOR_v6_Prescl;
   Int_t HLT_L1Tech_HCAL_HF_single_channel_v4_Prescl;
   Int_t HLT_ZeroBias_v7_Prescl;
   Int_t HLT_ZeroBiasPixel_DoubleTrack_v2_Prescl;
   Int_t HLT_Physics_v5_Prescl;
   Int_t HLT_DTCalibration_v2_Prescl;
   Int_t HLT_EcalCalibration_v3_Prescl;
   Int_t HLT_HcalCalibration_v3_Prescl;
   Int_t HLT_TrackerCalibration_v3_Prescl;
   Int_t HLT_Random_v2_Prescl;
   Int_t HLT_L1SingleMuOpen_AntiBPTX_v7_Prescl;
   Int_t HLT_L1TrackerCosmics_v7_Prescl;
   Int_t HLT_LogMonitor_v3_Prescl;
   Int_t HLT_DTErrors_v3_Prescl;
   Int_t HLT_L1DoubleJet36Central_v7_Prescl;
   Int_t AlCa_EcalPi0EBonly_v6_Prescl;
   Int_t AlCa_EcalPi0EEonly_v6_Prescl;
   Int_t AlCa_EcalEtaEBonly_v6_Prescl;
   Int_t AlCa_EcalEtaEEonly_v6_Prescl;
   Int_t AlCa_EcalPhiSym_v13_Prescl;
   Int_t AlCa_RPCMuonNoTriggers_v9_Prescl;
   Int_t AlCa_RPCMuonNoHits_v9_Prescl;
   Int_t AlCa_RPCMuonNormalisation_v9_Prescl;
   Int_t AlCa_LumiPixels_v7_Prescl;
   Int_t AlCa_LumiPixels_ZeroBias_v4_Prescl;
   Int_t AlCa_LumiPixels_Random_v1_Prescl;
   Int_t HLT_Activity_Ecal_SC7_v13_Prescl;
   Int_t HLT_L1SingleJet16_v7_Prescl;
   Int_t HLT_L1SingleJet36_v7_Prescl;








   // List of branches
   TBranch *b_NohJetCal; //!
   TBranch *b_NohJetCorCal; //!
   TBranch *b_NohJetCorL1L2L3Cal; //!
   TBranch *b_NrecoJetCal; //!
   TBranch *b_NrecoJetCorCal; //!
   TBranch *b_NrecoJetGen; //!
   TBranch *b_NrecoTowCal; //!

   TBranch *b_ohJetCalPt; //!
   TBranch *b_ohJetCalPhi; //!
   TBranch *b_ohJetCalEta; //!
   TBranch *b_ohJetCalE; //!
   TBranch *b_ohJetCalEMF; //!
   TBranch *b_ohJetCalN90; //!
   TBranch *b_ohJetCalN90hits; //!

   TBranch *b_ohJetCorCalPt; //!
   TBranch *b_ohJetCorCalPhi; //!
   TBranch *b_ohJetCorCalEta; //!
   TBranch *b_ohJetCorCalE; //!
   TBranch *b_ohJetCorCalEMF; //!
   TBranch *b_ohJetCorCalN90; // !  
   TBranch *b_ohJetCorCalN90hits; // !  

   TBranch *b_ohJetCorL1L2L3CalPt; //!
   TBranch *b_ohJetCorL1L2L3CalPhi; //!
   TBranch *b_ohJetCorL1L2L3CalEta; //!
   TBranch *b_ohJetCorL1L2L3CalE; //!
   TBranch *b_ohJetCorL1L2L3CalEMF; //!
   TBranch *b_ohJetCorL1L2L3CalN90; // !  
   TBranch *b_ohJetCorL1L2L3CalN90hits; // !  

   TBranch *b_recoJetCalPt; //!
   TBranch *b_recoJetCalPhi; //!
   TBranch *b_recoJetCalEta; //!
   TBranch *b_recoJetCalE; //!
   TBranch *b_recoJetCalEMF; //!
   TBranch *b_recoJetCalN90; //!
   TBranch *b_recoJetCalN90hits; //!

   TBranch *b_recoJetCorCalPt; //!
   TBranch *b_recoJetCorCalPhi; //!
   TBranch *b_recoJetCorCalEta; //!
   TBranch *b_recoJetCorCalE; //!
   TBranch *b_recoJetCorCalEMF; //!
   TBranch *b_recoJetCorCalN90; // !  
   TBranch *b_recoJetCorCalN90hits; // !  

   TBranch *b_recoJetGenPt; //!
   TBranch *b_recoJetGenPhi; //!
   TBranch *b_recoJetGenEta; //!
   TBranch *b_recoJetGenEt; //!
   TBranch *b_recoJetGenE; //!
   TBranch *b_recoTowEt; //!
   TBranch *b_recoTowEta; //!
   TBranch *b_recoTowPhi; //!
   TBranch *b_recoTowE; //!
   TBranch *b_recoTowEm; //!
   TBranch *b_recoTowHad; //!
   TBranch *b_recoTowOE; //!
   TBranch *b_recoMetCal; //!
   TBranch *b_recoMetCalPhi; //!
   TBranch *b_recoMetCalSum; //!
   TBranch *b_recoMetGen; //!
   TBranch *b_recoMetGenPhi; //!
   TBranch *b_recoMetGenSum; //!
   TBranch *b_recoHTCal; //!
   TBranch *b_recoHTCalPhi; //!
   TBranch *b_recoHTCalSum; //!
   TBranch *b_NohTauL2; //!
   TBranch *b_ohTauL2Pt; 
   TBranch *b_NohTau; //!
   TBranch *b_ohTauEta; //!
   TBranch *b_ohTauPhi; //!
   TBranch *b_ohTauPt; //!
   TBranch *b_ohTauEiso; //!
   TBranch *b_ohTauL25Tpt; //!
   TBranch *b_ohTauL25Tiso; //!
   TBranch *b_ohTauL3Tpt; //!
   TBranch *b_ohTauL3Tiso; //!
   TBranch *b_NohpfTauTightCone;   //! 
   TBranch *b_ohpfTauTightConeEta;  // ! 
   TBranch *b_ohpfTauTightConePhi;  // ! 
   TBranch *b_ohpfTauTightConePt;  // ! 
   TBranch *b_ohpfTauTightConeLeadTrackPt;   //! 
   TBranch *b_ohpfTauTightConeTrkIso; 
   TBranch *b_ohpfTauTightConeGammaIso; 
   TBranch *b_NohBJetLife; //!
   TBranch *b_ohBJetLifeL2E; //!
   TBranch *b_ohBJetLifeL2ET; //!
   TBranch *b_ohBJetLifeL2Eta; //!
   TBranch *b_ohBJetLifeL2Phi; //!
   TBranch *b_ohBJetLifeL25Discriminator; //!
   TBranch *b_ohBJetLifeL3Discriminator; //!
   TBranch *b_NohBJetPixelTracks; //!
   TBranch *b_ohBJetLifePixelTrackPt; //!
   TBranch *b_ohBJetLifePixelTrackEta; //!
   TBranch *b_ohBJetLifePixelTrackPhi; //!
   TBranch *b_ohBJetLifePixelTrackChi2; //!
   TBranch *b_NohBJetRegionalTracks; //!
   TBranch *b_ohBJetLifeRegionalTrackPt; //!
   TBranch *b_ohBJetLifeRegionalTrackEta; //!
   TBranch *b_ohBJetLifeRegionalTrackPhi; //!
   TBranch *b_ohBJetLifeRegionalTrackChi2; //!
   TBranch *b_ohBJetLifeRegionalSeedPt; //!
   TBranch *b_ohBJetLifeRegionalSeedEta; //!
   TBranch *b_ohBJetLifeRegionalSeedPhi; //!
   TBranch *b_NohBJetSoftm; //!
   TBranch *b_ohBJetSoftmL2E; //!
   TBranch *b_ohBJetSoftmL2ET; //!
   TBranch *b_ohBJetSoftmL2Eta; //!
   TBranch *b_ohBJetSoftmL2Phi; //!
   TBranch *b_ohBJetSoftmL25Discriminator; //!
   TBranch *b_ohBJetSoftmL3Discriminator; //!
   TBranch *b_ohBJetPerfL2E; //!
   TBranch *b_ohBJetPerfL2ET; //!
   TBranch *b_ohBJetPerfL2Eta; //!
   TBranch *b_ohBJetPerfL2Phi; //!
   TBranch *b_NohBJetL2; //! 
   TBranch *b_ohBJetL2Energy; //! 
   TBranch *b_ohBJetL2Et; //! 
   TBranch *b_ohBJetL2Pt; //! 
   TBranch *b_ohBJetL2Eta; //! 
   TBranch *b_ohBJetL2Phi; //! 
   TBranch *b_NohpfBJetL2; //! 
   TBranch *b_ohpfBJetL2Energy; //! 
   TBranch *b_ohpfBJetL2Et; //! 
   TBranch *b_ohpfBJetL2Pt; //! 
   TBranch *b_ohpfBJetL2Eta; //! 
   TBranch *b_ohpfBJetL2Phi; //! 
   TBranch *b_NohBJetL2Corrected; //! 
   TBranch *b_ohBJetL2CorrectedEnergy; //! 
   TBranch *b_ohBJetL2CorrectedEt; //! 
   TBranch *b_ohBJetL2CorrectedPt; //! 
   TBranch *b_ohBJetL2CorrectedEta; //! 
   TBranch *b_ohBJetL2CorrectedPhi; //! 
   TBranch *b_ohBJetIPL25Tag; //! 
   TBranch *b_ohBJetIPL3Tag; //! 
   TBranch *b_ohBJetIPL25TagSingleTrack; //! 
   TBranch *b_ohBJetIPL3TagSingleTrack; //! 
   TBranch *b_ohBJetIPL25TagSingleTrackL1FastJet; //! 
   TBranch *b_ohBJetIPL3TagSingleTrackL1FastJet; //! 
   TBranch *b_ohBJetMuL25Tag; //! 
   TBranch *b_ohBJetMuL3Tag; //! 
   TBranch *b_ohBJetPerfL25Tag; //! 
   TBranch *b_ohBJetPerfL3Tag; //! 
   TBranch *b_NohBJetL2CorrectedL1FastJet; //! 
   TBranch *b_ohBJetL2CorrectedEnergyL1FastJet; //! 
   TBranch *b_ohBJetL2CorrectedEtL1FastJet; //! 
   TBranch *b_ohBJetL2CorrectedPtL1FastJet; //! 
   TBranch *b_ohBJetL2CorrectedEtaL1FastJet; //! 
   TBranch *b_ohBJetL2CorrectedPhiL1FastJet; //! 
   TBranch *b_ohBJetIPL25TagL1FastJet; //! 
   TBranch *b_ohBJetIPL3TagL1FastJet; //! 
   TBranch *b_ohBJetPerfL25TagL1FastJet; //! 
   TBranch *b_ohBJetPerfL3TagL1FastJet; //! 

   TBranch *b_NohPixelTracksL3; //!
   TBranch *b_ohPixelTracksL3Pt; //!
   TBranch *b_ohPixelTracksL3Eta; //!
   TBranch *b_ohPixelTracksL3Phi; //!
   TBranch *b_ohPixelTracksL3Vz; //!
   TBranch *b_ohIsoPixelTrackHBL2N; //!
   TBranch *b_ohIsoPixelTrackHBL2P; //!
   TBranch *b_ohIsoPixelTrackHBL2Eta; //!
   TBranch *b_ohIsoPixelTrackHBL2Phi; //!
   TBranch *b_ohIsoPixelTrackHBL2MaxNearP; //!
   TBranch *b_ohIsoPixelTrackHBL3N; //!
   TBranch *b_ohIsoPixelTrackHBL3P; //!
   TBranch *b_ohIsoPixelTrackHBL3Eta; //!
   TBranch *b_ohIsoPixelTrackHBL3Phi; //!
   TBranch *b_ohIsoPixelTrackHBL3MaxNearP; //!
   TBranch *b_ohIsoPixelTrackHEL2N; //!
   TBranch *b_ohIsoPixelTrackHEL2P; //!
   TBranch *b_ohIsoPixelTrackHEL2Eta; //!
   TBranch *b_ohIsoPixelTrackHEL2Phi; //!
   TBranch *b_ohIsoPixelTrackHEL2MaxNearP; //!
   TBranch *b_ohIsoPixelTrackHEL3N; //!
   TBranch *b_ohIsoPixelTrackHEL3P; //!
   TBranch *b_ohIsoPixelTrackHEL3Eta; //!
   TBranch *b_ohIsoPixelTrackHEL3Phi; //!
   TBranch *b_ohIsoPixelTrackHEL3MaxNearP; //!
   TBranch *b_recoNVrt; //!
   TBranch *b_recoVrtX; //!
   TBranch *b_recoVrtY; //!
   TBranch *b_recoVrtZ; //!
   TBranch *b_recoVrtNtrk; //!
   TBranch *b_recoVrtChi2; //!
   TBranch *b_recoVrtNdof; //!
   TBranch *b_NrecoElec; //!
   TBranch *b_recoElecPt; //!
   TBranch *b_recoElecPhi; //!
   TBranch *b_recoElecEta; //!
   TBranch *b_recoElecEt; //!
   TBranch *b_recoElecE; //!
   TBranch *b_NrecoPhot; //!
   TBranch *b_recoPhotPt; //!
   TBranch *b_recoPhotPhi; //!
   TBranch *b_recoPhotEta; //!
   TBranch *b_recoPhotEt; //!
   TBranch *b_recoPhotE; //!
   TBranch *b_NohPhot; //!
   TBranch *b_ohPhotEt; //!
   TBranch *b_ohPhotEta; //!
   TBranch *b_ohPhotPhi; //!
   TBranch *b_ohPhotEiso; //!
   TBranch *b_ohPhotHiso; //!
   TBranch *b_ohPhotTiso; //!
   TBranch *b_ohPhotL1iso; //!
   TBranch *b_ohPhotR9; //!
   TBranch *b_ohPhotR9ID; //!
   TBranch *b_ohPhotHforHoverE; //! 
   TBranch *b_ohPhotClusShap; //!
   TBranch *b_NohEcalActiv;
   TBranch *b_ohEcalActivEt; //[NohEcalActiv]
   TBranch *b_ohEcalActivEta; //[NohEcalActiv]
   TBranch *b_ohEcalActivPhi; //[NohEcalActiv]
   TBranch *b_ohEcalActivEiso; //[NohEcalActiv]
   TBranch *b_ohEcalActivHiso; //[NohEcalActiv]
   TBranch *b_ohEcalActivTiso; //[NohEcalActiv]
   TBranch *b_ohEcalActivL1iso; //[NohEcalActiv]
   TBranch *b_ohEcalActivR9; //[NohEcalActiv] 
   TBranch *b_ohEcalActivR9ID; //[NohEcalActiv] 
   TBranch *b_ohEcalActivHforHoverE; //[NohEcalActiv] 
   TBranch *b_ohEcalActivClusShap; //[NohEcalActiv]
   TBranch *b_NohEle; //!
   TBranch *b_ohEleClusShap; //!
   TBranch *b_ohEleDeta; //!
   TBranch *b_ohEleDphi; //!
   TBranch *b_ohEleEt; //!
   TBranch *b_ohEleEta; //!
   TBranch *b_ohElePhi; //!
   TBranch *b_ohEleE; //!
   TBranch *b_ohEleP; //!
   TBranch *b_ohEleHiso; //!
   TBranch *b_ohEleTiso; //!
   TBranch *b_ohEleL1iso; //!
   TBranch *b_ohElePixelSeeds; //!
   TBranch *b_ohEleNewSC; //!
   TBranch *b_ohEleR9; //! 
   TBranch *b_ohEleHforHoverE; //! 
   TBranch *b_ohEleEiso; //!  
   TBranch *b_ohEleVtxZ;

   TBranch *b_NohHFEle; // !
   TBranch *b_ohHFElePt; //!
   TBranch *b_ohHFEleEta; //!
   TBranch *b_NohHFECALClus; // !
   TBranch *b_ohHFEleClustere9e25; //!
   TBranch *b_ohHFEleClustere1e9; //!
   TBranch *b_ohHFEleClustereCOREe9; //!
   TBranch *b_ohHFEleClustereSeL; //!
   TBranch *b_ohHFEleCluster2Dcut; //!
   TBranch *b_ohHFEleClusterEta; //!
   TBranch *b_ohHFEleClusterPhi; //!

   TBranch *b_NrecoMuon; //!
   TBranch *b_recoMuonPt; //!
   TBranch *b_recoMuonPhi; //!
   TBranch *b_recoMuonEta; //!
   TBranch *b_recoMuonEt; //!
   TBranch *b_recoMuonE; //!
   TBranch *b_NohMuL2; //!
   TBranch *b_ohMuL2Pt; //!
   TBranch *b_ohMuL2Phi; //!
   TBranch *b_ohMuL2Eta; //!
   TBranch *b_ohMuL2Chg; //!
   TBranch *b_ohMuL2PtErr; //!
   TBranch *b_ohMuL2Iso; //!
   TBranch *b_ohMuL2Dr; //!
   TBranch *b_ohMuL2Dz; //!
   TBranch *b_ohMuL2Nhits; //!
   TBranch *b_ohMuL2Nstat; //!
   TBranch *b_NohMuL3; //!
   TBranch *b_ohMuL3Pt; //!
   TBranch *b_ohMuL3Phi; //!
   TBranch *b_ohMuL3Eta; //!
   TBranch *b_ohMuL3Chg; //!
   TBranch *b_ohMuL3PtErr; //!
   TBranch *b_ohMuL3Iso; //!
   TBranch *b_ohMuL3Dr; //!
   TBranch *b_ohMuL3Dz; //!
   TBranch *b_ohMuL3L2idx; //!
   TBranch *b_NpfMuon; //!
   TBranch *b_pfMuonPt; //!
   TBranch *b_pfMuonPhi; //!
   TBranch *b_pfMuonEta; //!
   TBranch *b_pfMuonEt; //!
   TBranch *b_pfMuonE; //!
   TBranch *b_pfMuonCharge; //!
   TBranch *b_NohMuL2NoVtx; //! 
   TBranch *b_ohMuL2NoVtxPt; //! 
   TBranch *b_ohMuL2NoVtxPhi; //! 
   TBranch *b_ohMuL2NoVtxEta; //! 
   TBranch *b_ohMuL2NoVtxChg; //! 
   TBranch *b_ohMuL2NoVtxPtErr; //! 
   TBranch *b_ohMuL2NoVtxDr; //! 
   TBranch *b_ohMuL2NoVtxDz; //!
   TBranch *b_NohDiMu; //!
   TBranch *b_ohDiMuDCA; //!
   TBranch *b_ohDiMu1st; //!
   TBranch *b_ohDiMu2nd; //!
   TBranch *b_NohDiMuVtx; //!
   TBranch *b_ohDiMuVtx1st; //!
   TBranch *b_ohDiMuVtx2nd; //!
   TBranch *b_ohDiMuVtxChi2; //!
   TBranch *b_ohDiMuVtxR; //!
   TBranch *b_ohDiMuVtxRSig; //!
   TBranch *b_ohDiMuVtxROverSig; //!
   TBranch *b_ohDiMuVtxCosAlpha; //!
   TBranch *b_NohOniaPixel; //!
   TBranch *b_ohOniaPixelPt; //!
   TBranch *b_ohOniaPixelPhi; //!
   TBranch *b_ohOniaPixelEta; //!
   TBranch *b_ohOniaPixelChg; //!
   TBranch *b_ohOniaPixelDr; //!
   TBranch *b_ohOniaPixelDz; //!
   TBranch *b_ohOniaPixelHits; //!
   TBranch *b_ohOniaPixelNormChi2; //!
   TBranch *b_NohOniaTrack; //!
   TBranch *b_ohOniaTrackPt; //!
   TBranch *b_ohOniaTrackPhi; //!
   TBranch *b_ohOniaTrackEta; //!
   TBranch *b_ohOniaTrackChg; //!
   TBranch *b_ohOniaTrackDr; //!
   TBranch *b_ohOniaTrackDz; //!
   TBranch *b_ohOniaTrackHits; //!
   TBranch *b_ohOniaTrackNormChi2; //!
   TBranch *b_ohHighestEnergyEERecHit; //! 
   TBranch *b_ohHighestEnergyEBRecHit; //! 
   TBranch *b_ohHighestEnergyHBHERecHit; //! 
   TBranch *b_ohHighestEnergyHORecHit; //! 
   TBranch *b_ohHighestEnergyHFRecHit; //! 
   TBranch *b_Nalcapi0clusters; //! 
   TBranch *b_ohAlcapi0ptClusAll; //! 
   TBranch *b_ohAlcapi0etaClusAll; //! 
   TBranch *b_ohAlcapi0phiClusAll; //! 
   TBranch *b_ohAlcapi0s4s9ClusAll; //! 
   TBranch        *b_NRecoPFTau;   //!
   TBranch        *b_pfTauPt;   //!
   TBranch        *b_pfTauEta;   //!
   TBranch        *b_pfTauPhi;   //!
   TBranch        *b_pfTauLeadTrackPt;   //!
   TBranch        *b_pfTauLeadPionPt;   //!
   TBranch        *b_pfTauTrkIso;   //!
   TBranch        *b_pfTauGammaIso;   //!
   TBranch        *b_pfTauJetPt;   //!
   TBranch *b_NohpfTau; //! 
   TBranch *b_ohpfTauPt; //! 
   TBranch *b_ohpfTauEta; //! 
   TBranch *b_ohpfTauPhi; //! 
   TBranch *b_ohpfTauLeadTrackPt; //! 
   TBranch *b_ohpfTauLeadTrackVtxZ; //!
   TBranch *b_ohpfTauLeadPionPt; //! 
   TBranch *b_ohpfTauTrkIso; //! 
   TBranch *b_ohpfTauGammaIso; //!
   TBranch *b_ohpfTauProngs; //! 
   TBranch *b_ohpfTauJetPt; //! 
   TBranch *b_pfMHT; //! 
   TBranch *b_NohPFJet; //! 
   TBranch *b_pfJetPt; //! 
   TBranch *b_pfJetEta; //! 
   TBranch *b_pfJetPhi; //! 
   TBranch *b_NMCpart; //!
   TBranch *b_MCpid; //!
   TBranch *b_MCstatus; //!
   TBranch *b_MCvtxX; //!
   TBranch *b_MCvtxY; //!
   TBranch *b_MCvtxZ; //!
   TBranch *b_MCpt; //!
   TBranch *b_MCeta; //!
   TBranch *b_MCphi; //!
   TBranch *b_MCPtHat; //!
   TBranch *b_MCmu3; //!
   TBranch *b_MCel3; //!
   TBranch *b_MCbb; //!
   TBranch *b_MCab; //!
   TBranch *b_MCWenu; //!
   TBranch *b_MCmunu; //!
   TBranch *b_MCZee; //!
   TBranch *b_MCZmumu; //!
   TBranch *b_MCptEleMax; //!
   TBranch *b_MCptMuMax; //!
   TBranch *b_NL1IsolEm; //!
   TBranch *b_L1IsolEmEt; //!
   TBranch *b_L1IsolEmE; //!
   TBranch *b_L1IsolEmEta; //!
   TBranch *b_L1IsolEmPhi; //!
   TBranch *b_NL1NIsolEm; //!
   TBranch *b_L1NIsolEmEt; //!
   TBranch *b_L1NIsolEmE; //!
   TBranch *b_L1NIsolEmEta; //!
   TBranch *b_L1NIsolEmPhi; //!
   TBranch *b_NL1Mu; //!
   TBranch *b_L1MuPt; //!
   TBranch *b_L1MuE; //!
   TBranch *b_L1MuEta; //!
   TBranch *b_L1MuPhi; //!
   TBranch *b_L1MuIsol; //!
   TBranch *b_L1MuMip; //!
   TBranch *b_L1MuFor; //!
   TBranch *b_L1MuRPC; //!
   TBranch *b_L1MuQal; //!
   TBranch *b_NL1CenJet; //!
   TBranch *b_L1CenJetEt; //!
   TBranch *b_L1CenJetE; //!
   TBranch *b_L1CenJetEta; //!
   TBranch *b_L1CenJetPhi; //!
   TBranch *b_NL1ForJet; //!
   TBranch *b_L1ForJetEt; //!
   TBranch *b_L1ForJetE; //!
   TBranch *b_L1ForJetEta; //!
   TBranch *b_L1ForJetPhi; //!
   TBranch *b_NL1Tau; //!
   TBranch *b_L1TauEt; //!
   TBranch *b_L1TauE; //!
   TBranch *b_L1TauEta; //!
   TBranch *b_L1TauPhi; //!
   TBranch *b_L1Met; //!
   TBranch *b_L1MetPhi; //!
   TBranch *b_L1MetTot; //!
   TBranch *b_L1MetHad; //!
   TBranch *b_L1EtTot; //! 
   TBranch *b_L1HfRing0EtSumPositiveEta; //!
   TBranch *b_L1HfRing1EtSumPositiveEta; //!
   TBranch *b_L1HfRing0EtSumNegativeEta; //!
   TBranch *b_L1HfRing1EtSumNegativeEta; //!
   TBranch *b_L1HfTowerCountPositiveEta; //!
   TBranch *b_L1HfTowerCountNegativeEta; //!
   TBranch *b_L1HfTowerCountNegativeEtaRing1; //!
   TBranch *b_L1HfTowerCountPositiveEtaRing1; //!
   TBranch *b_L1HfTowerCountNegativeEtaRing2; //!
   TBranch *b_L1HfTowerCountPositiveEtaRing2; //!
   TBranch *b_Run; //!
   TBranch *b_Event; //!
   TBranch *b_LumiBlock; //!
   TBranch *b_Bx; //!
   TBranch *b_Orbit; //!
   TBranch *b_AvgInstDelLumi; //!

   // Autogenerated L1 - TBranch
  TBranch        *b_L1_SingleJet20_Central_NotBptxOR;   //!
  TBranch        *b_L1_SingleJet16_FwdVeto5;   //!
  TBranch        *b_L1_ETT80;   //!
  TBranch        *b_L1_DoubleForJet16_EtaOpp;   //!
  TBranch        *b_L1_DoubleMu0_HighQ_EtaCuts;   //!
  TBranch        *b_L1_DoubleEG3_FwdVeto;   //!
  TBranch        *b_L1_SingleForJet16;   //!
  TBranch        *b_L1_DoubleMu_5er_0er_HighQ_WdEta22;   //!
  TBranch        *b_L1_DoubleMu3er_HighQ_WdEta22;   //!
  TBranch        *b_L1_BeamHalo;   //!
  TBranch        *b_L1_InterBunch_Bptx;   //!
  TBranch        *b_L1_BeamGas_Hf_BptxPlusPostQuiet;   //!
  TBranch        *b_L1_BeamGas_Hf_BptxMinusPostQuiet;   //!
  TBranch        *b_L1_ZeroBias_Instance1;   //!
  TBranch        *b_L1_SingleMu6_NotBptxOR;   //!
  TBranch        *b_L1_SingleJetC20_NotBptxOR;   //!
  TBranch        *b_L1_SingleJetC32_NotBptxOR;   //!
  TBranch        *b_L1_TripleMu_5_5_0;   //!
  TBranch        *b_L1_TripleMu0_HighQ;   //!
  TBranch        *b_L1_DoubleMu_10_3p5;   //!
  TBranch        *b_L1_DoubleMu_12_5;   //!
  TBranch        *b_L1_DoubleMuHighQ_5_0_Eta2p1_WdEta22;   //!
  TBranch        *b_L1_DoubleMuHighQ_3_3_Eta2p1_WdEta22;   //!
  TBranch        *b_L1_DoubleMu0er_HighQ;   //!
  TBranch        *b_L1_SingleMu25er;   //!
  TBranch        *b_L1_SingleMu20er;   //!
  TBranch        *b_L1_SingleMu18er;   //!
  TBranch        *b_L1_SingleMu16er;   //!
  TBranch        *b_L1_SingleMu14er;   //!
  TBranch        *b_L1_DoubleJetC44_ETM30;   //!
  TBranch        *b_L1_DoubleJetC36_ETM30;   //!
  TBranch        *b_L1_Mu5_DoubleEG6;   //!
  TBranch        *b_L1_Mu5_DoubleEG5;   //!
  TBranch        *b_L1_DoubleMu5_EG5;   //!
  TBranch        *b_L1_DoubleMu3p5_EG5;   //!
  TBranch        *b_L1_Mu3p5_EG12;   //!
  TBranch        *b_L1_Mu12_EG7;   //!
  TBranch        *b_L1_EG8_DoubleJetC20;   //!
  TBranch        *b_L1_EG18er_JetC_Cen36_Tau28_dPhi1;   //!
  TBranch        *b_L1_IsoEG18er_JetC_Cen36_Tau28_dPhi1;   //!
  TBranch        *b_L1_IsoEG18er_JetC_Cen32_Tau24_dPhi1;   //!
  TBranch        *b_L1_EG18er_JetC_Cen28_Tau20_dPhi1;   //!
  TBranch        *b_L1_DoubleEG6_HTT125;   //!
  TBranch        *b_L1_DoubleEG6_HTT100;   //!
  TBranch        *b_L1_EG22_ForJet32;   //!
  TBranch        *b_L1_EG22_ForJet24;   //!
  TBranch        *b_L1_Mu8_DoubleJetC20;   //!
  TBranch        *b_L1_Mu10er_JetC12_WdEtaPhi1_DoubleJetC_32_12;   //!
  TBranch        *b_L1_Mu10er_JetC32;   //!
  TBranch        *b_L1_Mu10er_JetC12_WdEtaPhi1_DoubleJetC_20_12;   //!
  TBranch        *b_L1_Mu12er_ETM20;   //!
  TBranch        *b_L1_Mu4_HTT125;   //!
  TBranch        *b_L1_Mu0_HTT100;   //!
  TBranch        *b_L1_DoubleTauJet44er;   //!
  TBranch        *b_L1_QuadJetC40;   //!
  TBranch        *b_L1_QuadJetC36;   //!
  TBranch        *b_L1_QuadJetC32;   //!
  TBranch        *b_L1_TripleJetC_52_28_28;   //!
  TBranch        *b_L1_TripleJet_68_48_32_VBF;   //!
  TBranch        *b_L1_TripleJet_64_48_28_VBF;   //!
  TBranch        *b_L1_TripleJet_64_44_24_VBF;   //!
  TBranch        *b_L1_DoubleJetC64;   //!
  TBranch        *b_L1_DoubleJetC56;   //!
  TBranch        *b_L1_DoubleJetC56_Eta1p74_WdEta4;   //!
  TBranch        *b_L1_DoubleJetC52;   //!
  TBranch        *b_L1_DoubleJetC44_Eta1p74_WdEta4;   //!
  TBranch        *b_L1_DoubleJetC36;   //!
  TBranch        *b_L1_TripleEG_12_7_5;   //!
  TBranch        *b_L1_DoubleEG_13_7;   //!
  TBranch        *b_L1_SingleEG24;   //!
  TBranch        *b_L1_SingleEG22;   //!
  TBranch        *b_L1_SingleIsoEG20er;   //!
  TBranch        *b_L1_SingleIsoEG18er;   //!
  TBranch        *b_L1_SingleEG18er;   //!
  TBranch        *b_L1_SingleEG7;   //!
  TBranch        *b_L1_ETT300;   //!
  TBranch        *b_L1_HTT175;   //!
  TBranch        *b_L1_HTT150;   //!
  TBranch        *b_L1_HTT125;   //!
  TBranch        *b_L1_ETM100;   //!
  TBranch        *b_L1_ETM50;   //!
  TBranch        *b_L1_ETM36;   //!
  TBranch        *b_L1_QuadJet28_Central;   //!
  TBranch        *b_L1_SingleJet128;   //!
  TBranch        *b_L1_DoubleMu_10_Open;   //!
  TBranch        *b_L1_SingleEG18;   //!
  TBranch        *b_L1_Mu10_Eta2p1_DoubleJet_16_8_Central;   //!
  TBranch        *b_L1_Mu12_EG5;   //!
  TBranch        *b_L1_SingleMu16_Eta2p1;   //!
  TBranch        *b_L1_DoubleMu0_HighQ;   //!
  TBranch        *b_L1_SingleMu14_Eta2p1;   //!
  TBranch        *b_L1_HTT50_HTM30;   //!
  TBranch        *b_L1_DoubleEG5_HTT75;   //!
  TBranch        *b_L1_DoubleJet64_Central;   //!
  TBranch        *b_L1_DoubleTauJet44_Eta2p17;   //!
  TBranch        *b_L1_TripleJet_36_36_12_Central;   //!
  TBranch        *b_L1_EG5_HTT100;   //!
  TBranch        *b_L1_EG5_DoubleJet20_Central;   //!
  TBranch        *b_L1_TripleMu0;   //!
  TBranch        *b_L1_DoubleMu3p5;   //!
  TBranch        *b_L1_MuOpen_DoubleEG5;   //!
  TBranch        *b_L1_DoubleMuOpen_EG5;   //!
  TBranch        *b_L1_DoubleEG_12_5;   //!
  TBranch        *b_L1_DoubleTauJet36_Eta2p17;   //!
  TBranch        *b_L1_SingleJet52_Central;   //!
  TBranch        *b_L1_DoubleJet52_Central;   //!
  TBranch        *b_L1_DoubleTauJet40_Eta2p17;   //!
  TBranch        *b_L1_Jet52_Central_ETM30;   //!
  TBranch        *b_L1_DoubleJet44_Central;   //!
  TBranch        *b_L1_Mu7_EG5;   //!
  TBranch        *b_L1_MuOpen_EG12;   //!
  TBranch        *b_L1_DoubleTauJet36;   //!
  TBranch        *b_L1_TripleJet28_Central;   //!
  TBranch        *b_L1_SingleJet36_FwdVeto5;   //!
  TBranch        *b_L1_SingleTauJet68;   //!
  TBranch        *b_L1_MuOpen_EG5;   //!
  TBranch        *b_L1_SingleMu5_Eta1p5_Q80_v1;   //!
  TBranch        *b_L1_HTT75;   //!
  TBranch        *b_L1_ETT220;   //!
  TBranch        *b_L1_SingleJet20_NotBptxOR;   //!
  TBranch        *b_L1_BeamGas_Bsc;   //!
  TBranch        *b_L1_PreCollisions;   //!
  TBranch        *b_L1_BeamGas_Hf;   //!
  TBranch        *b_L1_Mu3_Jet20_Central;   //!
  TBranch        *b_L1_Mu3_Jet28_Central;   //!
  TBranch        *b_L1_Mu3_Jet16_Central;   //!
  TBranch        *b_L1_Mu7_Jet20_Central;   //!
  TBranch        *b_L1_Mu3_JetC16_WdEtaPhi2;   //!
  TBranch        *b_L1_Mu3_JetC52_WdEtaPhi2;   //!

  TBranch        *b_L1_DoubleEG5_HTT50;   //!
  TBranch        *b_L1_EG5_HTT75;   //!
  TBranch        *b_L1_DoubleJet52;   //!
  TBranch        *b_L1_SingleTauJet52;   //!
  TBranch        *b_L1_DoubleTauJet28;   //!
  TBranch        *b_L1_SingleJet20_NotBptxOR_NotMuBeamHalo;   //!
  TBranch        *b_L1_SingleJet16;   //!
  TBranch        *b_L1_SingleJet68;   //!
  TBranch        *b_L1_SingleJet92;   //!
  TBranch        *b_L1_DoubleForJet32_EtaOpp;   //!
  TBranch        *b_L1_DoubleForJet44_EtaOpp;   //!
  TBranch        *b_L1_DoubleEG2_FwdVeto;   //!
  TBranch        *b_L1_SingleJet36_FwdVeto;   //!
  TBranch        *b_L1_TripleEG7;   //!
  TBranch        *b_L1_TripleEG5;   //!
  TBranch        *b_L1_TripleJet28;   //!
  TBranch        *b_L1_Mu0_HTT50;   //!
  TBranch        *b_L1_SingleEG12_Eta2p17;   //!
  TBranch        *b_L1_SingleEG30;   //!
  TBranch        *b_L1_Mu3_Jet20;   //!
  TBranch        *b_L1_Mu3_Jet16;   //!
  TBranch        *b_L1_SingleMu16;   //!
  TBranch        *b_L1_SingleMu25;   //!
  TBranch        *b_L1_DoubleMu5;   //!
  TBranch        *b_L1_SingleMu5_Eta1p5_Q80;   //!
  TBranch        *b_L1_DoubleMu_0_5;   //!
  TBranch        *b_L1_SingleMu12;   //!
  TBranch        *b_L1_DoubleMu0;   //!
  TBranch        *b_L1_QuadJet20_Central;   //!
  TBranch        *b_L1_DoubleJet36_Central;   //!
  TBranch        *b_L1_SingleJet52;   //!
  TBranch        *b_L1_SingleJet36;   //!
   TBranch *b_L1_Mu3_Jet10; //!
   TBranch *b_L1_SingleJet10U_NotBptxOR_Ext; //!
   TBranch *b_L1_SingleJet10_NotBptxOR_Ext; //!
   TBranch *b_L1_SingleJet10U_NotBptxOR; //!
   TBranch *b_L1_SingleJet10_NotBptxOR; //!
   TBranch *b_L1_Mu3_EG5; //!

   //L1 algorithm bits 
   TBranch *b_L1_DoubleMuTopBottom; //! 
   TBranch *b_L1_DoubleEG05_TopBottom; //! 
   TBranch *b_L1_SingleJet20; //! 
   TBranch *b_L1_SingleJet40; //! 
   TBranch *b_L1_SingleJet60; //! 
   TBranch *b_L1_DoubleJet30; //!  
   TBranch *b_L1_SingleTauJet10; //! 
   TBranch *b_L1_SingleTauJet20; //! 
   TBranch *b_L1_SingleTauJet50; //! 
   TBranch *b_L1_DoubleTauJet14; //! 
   TBranch *b_L1_IsoEG10_Jet6_ForJet6; //! 
   TBranch *b_L1_Mu5_Jet6; //!
   TBranch *b_L1_EG5_TripleJet6; //!   
   TBranch *b_L1_SingleJet6; //!  
   TBranch *b_L1_SingleJet10; //!
   TBranch *b_L1_SingleJet10_NotBptxC_Ext; //!
   TBranch *b_L1_ETM30; //!  
   TBranch *b_L1_QuadJet6; //! 
   TBranch *b_L1_QuadJet8; //! 
   TBranch *b_L1_TripleJet14; //!  
   TBranch *b_L1_DoubleEG1; //! 
   TBranch *b_L1_DoubleEG2; //! 
   TBranch *b_L1_DoubleEG5; //! 
   TBranch *b_L1_DoubleHfBitCountsRing1_P1N1; //! 
   TBranch *b_L1_DoubleHfBitCountsRing2_P1N1; //! 
   TBranch *b_L1_DoubleHfRingEtSumsRing1_P200N200; //! 
   TBranch *b_L1_DoubleHfRingEtSumsRing1_P4N4; //! 
   TBranch *b_L1_DoubleHfRingEtSumsRing2_P200N200; //! 
   TBranch *b_L1_DoubleHfRingEtSumsRing2_P4N4; //! 
   TBranch *b_L1_DoubleJet70; //! 
   TBranch *b_L1_DoubleMu3; //! 
   TBranch *b_L1_DoubleMuOpen; //! 
   TBranch *b_L1_DoubleTauJet30; //! 
   TBranch *b_L1_EG10_Jet15; //! 
   TBranch *b_L1_EG5_TripleJet15; //! 
   TBranch *b_L1_ETM20; //! 
   TBranch *b_L1_ETM40; //! 
   TBranch *b_L1_ETM70; //! 
   TBranch *b_L1_ETM80; //! 
   TBranch *b_L1_ETT60; //!
   TBranch *b_L1_ETT100; //! 
   TBranch *b_L1_ETT140; //! 
   TBranch *b_L1_HTT50; //! 
   TBranch *b_L1_HTT100; //! 
   TBranch *b_L1_HTT200; //! 
   TBranch *b_L1_HTT300; //! 
   TBranch *b_L1_IsoEG10_Jet15_ForJet10; //! 
   TBranch *b_L1_MinBias_HTT10; //! 
   TBranch *b_L1_Mu3QE8_EG5; //!
   TBranch *b_L1_Mu3QE8_Jet15; //!  
   TBranch *b_L1_Mu5QE8_Jet15; //! 
   TBranch *b_L1_Mu3QE8_Jet6; //!  
   TBranch *b_L1_Mu5QE8_Jet6; //! 
   TBranch *b_L1_QuadJet15; //! 
   TBranch *b_L1_SingleEG1; //! 
   TBranch *b_L1_SingleEG10; //! 
   TBranch *b_L1_SingleEG12; //! 
   TBranch *b_L1_SingleEG15; //! 
   TBranch *b_L1_SingleEG2; //! 
   TBranch *b_L1_SingleEG20; //! 
   TBranch *b_L1_SingleEG5; //! 
   TBranch *b_L1_SingleEG8; //! 
   TBranch *b_L1_SingleHfBitCountsRing1_1; //! 
   TBranch *b_L1_SingleHfBitCountsRing2_1; //! 
   TBranch *b_L1_SingleHfRingEtSumsRing1_200; //! 
   TBranch *b_L1_SingleHfRingEtSumsRing1_4; //! 
   TBranch *b_L1_SingleHfRingEtSumsRing2_200; //! 
   TBranch *b_L1_SingleHfRingEtSumsRing2_4; //! 
   TBranch *b_L1_SingleIsoEG10; //! 
   TBranch *b_L1_SingleIsoEG12; //! 
   TBranch *b_L1_SingleIsoEG15; //! 
   TBranch *b_L1_SingleIsoEG5; //! 
   TBranch *b_L1_SingleIsoEG8; //! 
   TBranch *b_L1_SingleJet100; //! 
   TBranch *b_L1_SingleJet15; //! 
   TBranch *b_L1_SingleJet30; //! 
   TBranch *b_L1_SingleJet50; //! 
   TBranch *b_L1_SingleJet70; //! 
   TBranch *b_L1_SingleMu0; //! 
   TBranch *b_L1_SingleMu10; //! 
   TBranch *b_L1_SingleMu14; //! 
   TBranch *b_L1_SingleMu20; //! 
   TBranch *b_L1_SingleMu3; //! 
   TBranch *b_L1_SingleMu5; //! 
   TBranch *b_L1_SingleMu7; //! 
   TBranch *b_L1_SingleMuBeamHalo; //! 
   TBranch *b_L1_SingleMuOpen; //! 
   TBranch *b_L1_SingleTauJet30; //! 
   TBranch *b_L1_SingleTauJet40; //! 
   TBranch *b_L1_SingleTauJet60; //! 
   TBranch *b_L1_SingleTauJet80; //! 
   TBranch *b_L1_TripleJet30; //! 
   TBranch *b_L1_ZeroBias; //!
   TBranch *b_L1_ZeroBias_Ext; //!
   TBranch *b_L1_SingleCenJet2; //!    
   TBranch *b_L1_SingleCenJet4; //!    
   TBranch *b_L1_SingleForJet2; //!    
   TBranch *b_L1_SingleForJet4; //!    
   TBranch *b_L1_SingleTauJet2; //!    
   TBranch *b_L1_SingleTauJet4; //!    
   TBranch *b_L1_DoubleForJet10_EtaOpp; //!    
   TBranch *b_L1_Mu3_Jet6; //!

   // L1 Technical bits
   TBranch *b_L1Tech_BPTX_minus_v0; //!
   TBranch *b_L1Tech_BPTX_minus_v0_5bx; //!
   TBranch *b_L1Tech_BPTX_minus_AND_not_plus_v0; //!
   TBranch *b_L1Tech_BPTX_minus_AND_not_plus_v0_5bx; //!
   TBranch *b_L1Tech_BPTX_plus_v0; //!
   TBranch *b_L1Tech_BPTX_plus_v0_5bx; //!
   TBranch *b_L1Tech_BPTX_plus_AND_NOT_minus_v0; //!
   TBranch *b_L1Tech_BPTX_plus_AND_NOT_minus_v0_5bx; //!
   TBranch *b_L1Tech_BPTX_plus_AND_minus_v0; //!
   TBranch *b_L1Tech_BPTX_plus_AND_minus_v0_5bx; //!
   TBranch *b_L1Tech_BPTX_plus_AND_minus_instance1_v0; //!
   TBranch *b_L1Tech_BPTX_plus_AND_minus_instance1_v0_5bx; //!
   TBranch *b_L1Tech_BPTX_plus_OR_minus_v0; //!
   TBranch *b_L1Tech_BPTX_plus_OR_minus_v0_5bx; //!
   TBranch *b_L1Tech_BPTX_quiet_v0; //!
   TBranch *b_L1Tech_BPTX_quiet_v0_5bx; //!
   TBranch *b_L1Tech_BSC_HighMultiplicity_v0; //!
   TBranch *b_L1Tech_BSC_HighMultiplicity_v0_5bx; //!
   TBranch *b_L1Tech_BSC_halo_beam1_inner_v0; //!
   TBranch *b_L1Tech_BSC_halo_beam1_inner_v0_5bx; //!
   TBranch *b_L1Tech_BSC_halo_beam1_outer_v0; //!
   TBranch *b_L1Tech_BSC_halo_beam1_outer_v0_5bx; //!
   TBranch *b_L1Tech_BSC_halo_beam2_inner_v0; //!
   TBranch *b_L1Tech_BSC_halo_beam2_inner_v0_5bx; //!
   TBranch *b_L1Tech_BSC_halo_beam2_outer_v0; //!
   TBranch *b_L1Tech_BSC_halo_beam2_outer_v0_5bx; //!
   TBranch *b_L1Tech_BSC_minBias_OR_v0; //!
   TBranch *b_L1Tech_BSC_minBias_OR_v0_5bx; //!
   TBranch *b_L1Tech_BSC_minBias_inner_threshold1_v0; //!
   TBranch *b_L1Tech_BSC_minBias_inner_threshold1_v0_5bx; //!
   TBranch *b_L1Tech_BSC_minBias_inner_threshold2_v0; //!
   TBranch *b_L1Tech_BSC_minBias_inner_threshold2_v0_5bx; //!
   TBranch *b_L1Tech_BSC_minBias_threshold1_v0; //!
   TBranch *b_L1Tech_BSC_minBias_threshold1_v0_5bx; //!
   TBranch *b_L1Tech_BSC_minBias_threshold2_v0; //!
   TBranch *b_L1Tech_BSC_minBias_threshold2_v0_5bx; //!
   TBranch *b_L1Tech_BSC_splash_beam1_v0; //!
   TBranch *b_L1Tech_BSC_splash_beam1_v0_5bx; //!
   TBranch *b_L1Tech_BSC_splash_beam2_v0; //!
   TBranch *b_L1Tech_BSC_splash_beam2_v0_5bx; //!
   TBranch *b_L1Tech_HCAL_HBHE_totalOR_v0; //!
   TBranch *b_L1Tech_HCAL_HBHE_totalOR_v0_5bx; //!
   TBranch *b_L1Tech_HCAL_HF_totalOR_coincidenceHFM_v0; //!
   TBranch *b_L1Tech_HCAL_HF_totalOR_coincidenceHFM_v0_5bx; //!
   TBranch *b_L1Tech_HCAL_HF_totalOR_coincidenceHFP_v0; //!
   TBranch *b_L1Tech_HCAL_HF_totalOR_coincidenceHFP_v0_5bx; //!
   TBranch *b_L1Tech_HCAL_HF_totalOR_minBias_v0; //!
   TBranch *b_L1Tech_HCAL_HF_totalOR_minBias_v0_5bx; //!
   TBranch *b_L1Tech_HCAL_HO_totalOR_v0; //!
   TBranch *b_L1Tech_HCAL_HO_totalOR_v0_5bx; //!
   TBranch *b_L1Tech_RPC_TTU_RB0_Cosmics_v0; //!
   TBranch *b_L1Tech_RPC_TTU_RB0_Cosmics_v0_5bx; //!
   TBranch *b_L1Tech_RPC_TTU_RBminus1_Cosmics_v0; //!
   TBranch *b_L1Tech_RPC_TTU_RBminus1_Cosmics_v0_5bx; //!
   TBranch *b_L1Tech_RPC_TTU_RBminus2_Cosmics_v0; //!
   TBranch *b_L1Tech_RPC_TTU_RBminus2_Cosmics_v0_5bx; //!
   TBranch *b_L1Tech_RPC_TTU_RBplus1_Cosmics_v0; //!
   TBranch *b_L1Tech_RPC_TTU_RBplus1_Cosmics_v0_5bx; //!
   TBranch *b_L1Tech_RPC_TTU_RBplus2_Cosmics_v0; //!
   TBranch *b_L1Tech_RPC_TTU_RBplus2_Cosmics_v0_5bx; //!
   TBranch *b_L1Tech_RPC_TTU_barrel_Cosmics_v0; //!
   TBranch *b_L1Tech_RPC_TTU_barrel_Cosmics_v0_5bx; //!
   TBranch *b_L1Tech_RPC_TTU_pointing_Cosmics_v0; //!
   TBranch *b_L1Tech_RPC_TTU_pointing_Cosmics_v0_5bx; //!
   TBranch *b_L1Tech_RPC_TTU_RBst1_collisions_v0; //!
   TBranch *b_L1Tech_RPC_TTU_RBst1_collisions_v0_5bx; //!
   TBranch *b_L1Tech_HCAL_HF_MM_or_PP_or_PM_v0; //!
   TBranch *b_L1Tech_HCAL_HF_MM_or_PP_or_PM_v0_5bx; //!
   TBranch *b_L1Tech_HCAL_HF_coincidence_PM_v1; //!
   TBranch *b_L1Tech_HCAL_HF_coincidence_PM_v1_5bx; //!
   TBranch *b_L1Tech_HCAL_HF_MMP_or_MPP_v0; //!
   TBranch *b_L1Tech_HCAL_HF_MMP_or_MPP_v0_5bx; //!
   TBranch *b_L1Tech_ZDC_loose_vertex_v0; //!
   TBranch *b_L1Tech_ZDC_loose_vertex_v0_5bx; //!
   TBranch *b_L1Tech_ZDC_minus_over_threshold_v0; //!
   TBranch *b_L1Tech_ZDC_minus_over_threshold_v0_5bx; //!
   TBranch *b_L1Tech_ZDC_plus_over_threshold_v0; //!
   TBranch *b_L1Tech_ZDC_plus_over_threshold_v0_5bx; //!
   TBranch *b_L1Tech_ZDC_tight_vertex_v0; //!
   TBranch *b_L1Tech_ZDC_tight_vertex_v0_5bx; //!
   TBranch *b_L1_BptxMinus; //!
   TBranch *b_L1_BptxMinus_5bx; //!
   TBranch *b_L1_BptxPlus; //!
   TBranch *b_L1_BptxPlus_5bx; //!
   TBranch *b_L1_BptxPlusORMinus; //!
   TBranch *b_L1_BptxPlusORMinus_5bx; //!
   TBranch *b_L1_BptxPlus_NotBptxMinus; //!
   TBranch *b_L1_BptxPlus_NotBptxMinus_5bx; //!
   TBranch *b_L1_BptxXOR_BscMinBiasOR; //!
   TBranch *b_L1_BptxXOR_BscMinBiasOR_5bx; //!
   TBranch *b_L1_BptxMinus_NotBptxPlus; //!
   TBranch *b_L1_BptxMinus_NotBptxPlus_5bx; //!
   TBranch *b_L1_BscHighMultiplicity; //!
   TBranch *b_L1_BscHighMultiplicity_5bx; //!
   TBranch *b_L1_BscMinBiasInnerThreshold1; //!
   TBranch *b_L1_BscMinBiasInnerThreshold1_5bx; //!
   TBranch *b_L1_BscMinBiasInnerThreshold2; //!
   TBranch *b_L1_BscMinBiasInnerThreshold2_5bx; //!
   TBranch *b_L1_BscMinBiasOR; //!
   TBranch *b_L1_BscMinBiasOR_5bx; //!
   TBranch *b_L1_BscMinBiasOR_BptxPlusORMinus; //!
   TBranch *b_L1_BscMinBiasOR_BptxPlusORMinus_5bx; //!
   TBranch *b_L1_BscMinBiasOR_BptxPlusANDMinus; //! 
   TBranch *b_L1_BscMinBiasOR_BptxPlusANDMinus_5bx; //!

   // Autogenerated L1 - Prescale TBranch 
  TBranch        *b_L1_SingleJet20_Central_NotBptxOR_Prescl;   //!
  TBranch        *b_L1_SingleJet16_FwdVeto5_Prescl;   //!
  TBranch        *b_L1_ETT80_Prescl;   //!
  TBranch        *b_L1_DoubleForJet16_EtaOpp_Prescl;   //!
  TBranch        *b_L1_DoubleMu0_HighQ_EtaCuts_Prescl;   //!
  TBranch        *b_L1_DoubleEG3_FwdVeto_Prescl;   //!
  TBranch        *b_L1_SingleForJet16_Prescl;   //!
  TBranch        *b_L1_DoubleMu_5er_0er_HighQ_WdEta22_Prescl;   //!
  TBranch        *b_L1_DoubleMu3er_HighQ_WdEta22_Prescl;   //!
  TBranch        *b_L1_BeamHalo_Prescl;   //!
  TBranch        *b_L1_InterBunch_Bptx_Prescl;   //!
  TBranch        *b_L1_BeamGas_Hf_BptxPlusPostQuiet_Prescl;   //!
  TBranch        *b_L1_BeamGas_Hf_BptxMinusPostQuiet_Prescl;   //!
  TBranch        *b_L1_ZeroBias_Instance1_Prescl;   //!
  TBranch        *b_L1_SingleMu6_NotBptxOR_Prescl;   //!
  TBranch        *b_L1_SingleJetC20_NotBptxOR_Prescl;   //!
  TBranch        *b_L1_SingleJetC32_NotBptxOR_Prescl;   //!
  TBranch        *b_L1_TripleMu_5_5_0_Prescl;   //!
  TBranch        *b_L1_TripleMu0_HighQ_Prescl;   //!
  TBranch        *b_L1_DoubleMu_10_3p5_Prescl;   //!
  TBranch        *b_L1_DoubleMu_12_5_Prescl;   //!
  TBranch        *b_L1_DoubleMuHighQ_5_0_Eta2p1_WdEta22_Prescl;   //!
  TBranch        *b_L1_DoubleMuHighQ_3_3_Eta2p1_WdEta22_Prescl;   //!
  TBranch        *b_L1_DoubleMu0er_HighQ_Prescl;   //!
  TBranch        *b_L1_SingleMu25er_Prescl;   //!
  TBranch        *b_L1_SingleMu20er_Prescl;   //!
  TBranch        *b_L1_SingleMu18er_Prescl;   //!
  TBranch        *b_L1_SingleMu16er_Prescl;   //!
  TBranch        *b_L1_SingleMu14er_Prescl;   //!
  TBranch        *b_L1_DoubleJetC44_ETM30_Prescl;   //!
  TBranch        *b_L1_DoubleJetC36_ETM30_Prescl;   //!
  TBranch        *b_L1_Mu5_DoubleEG6_Prescl;   //!
  TBranch        *b_L1_Mu5_DoubleEG5_Prescl;   //!
  TBranch        *b_L1_DoubleMu5_EG5_Prescl;   //!
  TBranch        *b_L1_DoubleMu3p5_EG5_Prescl;   //!
  TBranch        *b_L1_Mu3p5_EG12_Prescl;   //!
  TBranch        *b_L1_Mu12_EG7_Prescl;   //!
  TBranch        *b_L1_EG8_DoubleJetC20_Prescl;   //!
  TBranch        *b_L1_EG18er_JetC_Cen36_Tau28_dPhi1_Prescl;   //!
  TBranch        *b_L1_IsoEG18er_JetC_Cen36_Tau28_dPhi1_Prescl;   //!
  TBranch        *b_L1_IsoEG18er_JetC_Cen32_Tau24_dPhi1_Prescl;   //!
  TBranch        *b_L1_EG18er_JetC_Cen28_Tau20_dPhi1_Prescl;   //!
  TBranch        *b_L1_DoubleEG6_HTT125_Prescl;   //!
  TBranch        *b_L1_DoubleEG6_HTT100_Prescl;   //!
  TBranch        *b_L1_EG22_ForJet32_Prescl;   //!
  TBranch        *b_L1_EG22_ForJet24_Prescl;   //!
  TBranch        *b_L1_Mu8_DoubleJetC20_Prescl;   //!
  TBranch        *b_L1_Mu10er_JetC12_WdEtaPhi1_DoubleJetC_32_12_Prescl;   //!
  TBranch        *b_L1_Mu10er_JetC32_Prescl;   //!
  TBranch        *b_L1_Mu10er_JetC12_WdEtaPhi1_DoubleJetC_20_12_Prescl;   //!
  TBranch        *b_L1_Mu12er_ETM20_Prescl;   //!
  TBranch        *b_L1_Mu4_HTT125_Prescl;   //!
  TBranch        *b_L1_Mu0_HTT100_Prescl;   //!
  TBranch        *b_L1_DoubleTauJet44er_Prescl;   //!
  TBranch        *b_L1_QuadJetC40_Prescl;   //!
  TBranch        *b_L1_QuadJetC36_Prescl;   //!
  TBranch        *b_L1_QuadJetC32_Prescl;   //!
  TBranch        *b_L1_TripleJetC_52_28_28_Prescl;   //!
  TBranch        *b_L1_TripleJet_68_48_32_VBF_Prescl;   //!
  TBranch        *b_L1_TripleJet_64_48_28_VBF_Prescl;   //!
  TBranch        *b_L1_TripleJet_64_44_24_VBF_Prescl;   //!
  TBranch        *b_L1_DoubleJetC64_Prescl;   //!
  TBranch        *b_L1_DoubleJetC56_Prescl;   //!
  TBranch        *b_L1_DoubleJetC56_Eta1p74_WdEta4_Prescl;   //!
  TBranch        *b_L1_DoubleJetC52_Prescl;   //!
  TBranch        *b_L1_DoubleJetC44_Eta1p74_WdEta4_Prescl;   //!
  TBranch        *b_L1_DoubleJetC36_Prescl;   //!
  TBranch        *b_L1_TripleEG_12_7_5_Prescl;   //!
  TBranch        *b_L1_DoubleEG_13_7_Prescl;   //!
  TBranch        *b_L1_SingleEG24_Prescl;   //!
  TBranch        *b_L1_SingleEG22_Prescl;   //!
  TBranch        *b_L1_SingleIsoEG20er_Prescl;   //!
  TBranch        *b_L1_SingleIsoEG18er_Prescl;   //!
  TBranch        *b_L1_SingleEG18er_Prescl;   //!
  TBranch        *b_L1_SingleEG7_Prescl;   //!
  TBranch        *b_L1_ETT300_Prescl;   //!
  TBranch        *b_L1_HTT175_Prescl;   //!
  TBranch        *b_L1_HTT150_Prescl;   //!
  TBranch        *b_L1_HTT125_Prescl;   //!
  TBranch        *b_L1_ETM100_Prescl;   //!
  TBranch        *b_L1_ETM50_Prescl;   //!
  TBranch        *b_L1_ETM36_Prescl;   //!
  TBranch        *b_L1_QuadJet28_Central_Prescl;   //!
  TBranch        *b_L1_SingleJet128_Prescl;   //!
  TBranch        *b_L1_DoubleMu_10_Open_Prescl;   //!
  TBranch        *b_L1_SingleEG18_Prescl;   //!
  TBranch        *b_L1_Mu10_Eta2p1_DoubleJet_16_8_Central_Prescl;   //!
  TBranch        *b_L1_Mu12_EG5_Prescl;   //!
  TBranch        *b_L1_SingleMu16_Eta2p1_Prescl;   //!
  TBranch        *b_L1_DoubleMu0_HighQ_Prescl;   //!
  TBranch        *b_L1_SingleMu14_Eta2p1_Prescl;   //!
  TBranch        *b_L1_HTT50_HTM30_Prescl;   //!
  TBranch        *b_L1_DoubleEG5_HTT75_Prescl;   //!
  TBranch        *b_L1_DoubleJet64_Central_Prescl;   //!
  TBranch        *b_L1_DoubleTauJet44_Eta2p17_Prescl;   //!
  TBranch        *b_L1_TripleJet_36_36_12_Central_Prescl;   //!
  TBranch        *b_L1_EG5_HTT100_Prescl;   //!
  TBranch        *b_L1_EG5_DoubleJet20_Central_Prescl;   //!
  TBranch        *b_L1_TripleMu0_Prescl;   //!
  TBranch        *b_L1_DoubleMu3p5_Prescl;   //!
  TBranch        *b_L1_MuOpen_DoubleEG5_Prescl;   //!
  TBranch        *b_L1_DoubleMuOpen_EG5_Prescl;   //!
  TBranch        *b_L1_DoubleEG_12_5_Prescl;   //!
  TBranch        *b_L1_DoubleTauJet36_Eta2p17_Prescl;   //!
  TBranch        *b_L1_SingleJet52_Central_Prescl;   //!
  TBranch        *b_L1_DoubleJet52_Central_Prescl;   //!
  TBranch        *b_L1_DoubleTauJet40_Eta2p17_Prescl;   //!
  TBranch        *b_L1_Jet52_Central_ETM30_Prescl;   //!
  TBranch        *b_L1_DoubleJet44_Central_Prescl;   //!
  TBranch        *b_L1_Mu7_EG5_Prescl;   //!
  TBranch        *b_L1_MuOpen_EG12_Prescl;   //!
  TBranch        *b_L1_DoubleTauJet36_Prescl;   //!
  TBranch        *b_L1_TripleJet28_Central_Prescl;   //!
  TBranch        *b_L1_SingleJet36_FwdVeto5_Prescl;   //!
  TBranch        *b_L1_SingleTauJet68_Prescl;   //!
  TBranch        *b_L1_MuOpen_EG5_Prescl;   //!
  TBranch        *b_L1_SingleMu5_Eta1p5_Q80_v1_Prescl;   //!
  TBranch        *b_L1_HTT75_Prescl;   //!
  TBranch        *b_L1_ETT220_Prescl;   //!
  TBranch        *b_L1_SingleJet20_NotBptxOR_Prescl;   //!
  TBranch        *b_L1_BeamGas_Bsc_Prescl;   //!
  TBranch        *b_L1_PreCollisions_Prescl;   //!
  TBranch        *b_L1_BeamGas_Hf_Prescl;   //!
  TBranch        *b_L1_Mu3_Jet20_Central_Prescl;   //!
  TBranch        *b_L1_Mu3_Jet28_Central_Prescl;   //!
  TBranch        *b_L1_Mu3_Jet16_Central_Prescl;   //!
  TBranch        *b_L1_Mu7_Jet20_Central_Prescl;   //!
  TBranch        *b_L1_Mu3_JetC16_WdEtaPhi2_Prescl;   //!
  TBranch        *b_L1_Mu3_JetC52_WdEtaPhi2_Prescl;   //!

  TBranch        *b_L1_DoubleEG5_HTT50_Prescl;   //!
  TBranch        *b_L1_EG5_HTT75_Prescl;   //!
  TBranch        *b_L1_DoubleJet52_Prescl;   //!
  TBranch        *b_L1_SingleTauJet52_Prescl;   //!
  TBranch        *b_L1_DoubleTauJet28_Prescl;   //!
  TBranch        *b_L1_SingleJet20_NotBptxOR_NotMuBeamHalo_Prescl;   //!
  TBranch        *b_L1_SingleJet16_Prescl;   //!
  TBranch        *b_L1_SingleJet68_Prescl;   //!
  TBranch        *b_L1_SingleJet92_Prescl;   //!
  TBranch        *b_L1_DoubleForJet32_EtaOpp_Prescl;   //!
  TBranch        *b_L1_DoubleForJet44_EtaOpp_Prescl;   //!
  TBranch        *b_L1_DoubleEG2_FwdVeto_Prescl;   //!
  TBranch        *b_L1_SingleJet36_FwdVeto_Prescl;   //!
  TBranch        *b_L1_TripleEG7_Prescl;   //!
  TBranch        *b_L1_TripleEG5_Prescl;   //!
  TBranch        *b_L1_TripleJet28_Prescl;   //!
  TBranch        *b_L1_Mu0_HTT50_Prescl;   //!
  TBranch        *b_L1_SingleEG12_Eta2p17_Prescl;   //!
  TBranch        *b_L1_SingleEG30_Prescl;   //!
  TBranch        *b_L1_Mu3_Jet20_Prescl;   //!
  TBranch        *b_L1_Mu3_Jet16_Prescl;   //!
  TBranch        *b_L1_SingleMu16_Prescl;   //!
  TBranch        *b_L1_SingleMu25_Prescl;   //!
  TBranch        *b_L1_DoubleMu5_Prescl;   //!
  TBranch        *b_L1_SingleMu5_Eta1p5_Q80_Prescl;   //!
  TBranch        *b_L1_DoubleMu_0_5_Prescl;   //!
  TBranch        *b_L1_SingleMu12_Prescl;   //!
  TBranch        *b_L1_DoubleMu0_Prescl;   //!
  TBranch        *b_L1_QuadJet20_Central_Prescl;   //!
  TBranch        *b_L1_DoubleJet36_Central_Prescl;   //!
  TBranch        *b_L1_SingleJet52_Prescl;   //!
  TBranch        *b_L1_SingleJet36_Prescl;   //!
   TBranch *b_L1_Mu3_Jet10_Prescl; //!
   TBranch *b_L1_SingleJet10U_NotBptxOR_Ext_Prescl; //!
   TBranch *b_L1_SingleJet10_NotBptxOR_Ext_Prescl; //!
   TBranch *b_L1_SingleJet10U_NotBptxOR_Prescl; //!
   TBranch *b_L1_SingleJet10_NotBptxOR_Prescl; //!
   TBranch *b_L1_Mu3_EG5_Prescl; //!


   //L1 algorithm bit prescales 
   TBranch *b_L1_DoubleMuTopBottom_Prescl; //! 
   TBranch *b_L1_DoubleEG05_TopBottom_Prescl; //! 
   TBranch *b_L1_SingleJet20_Prescl; //! 
   TBranch *b_L1_SingleJet40_Prescl; //! 
   TBranch *b_L1_SingleJet60_Prescl; //! 
   TBranch *b_L1_DoubleJet30_Prescl; //!  
   TBranch *b_L1_SingleTauJet10_Prescl; //! 
   TBranch *b_L1_SingleTauJet20_Prescl; //! 
   TBranch *b_L1_SingleTauJet50_Prescl; //! 
   TBranch *b_L1_DoubleTauJet14_Prescl; //! 
   TBranch *b_L1_IsoEG10_Jet6_ForJet6_Prescl; //! 
   TBranch *b_L1_Mu5_Jet6_Prescl; //!
   TBranch *b_L1_EG5_TripleJet6_Prescl; //!   
   TBranch *b_L1_SingleJet6_Prescl; //!  
   TBranch *b_L1_SingleJet10_Prescl; //!
   TBranch *b_L1_SingleJet10_NotBptxC_Ext_Prescl; //!
   TBranch *b_L1_ETM30_Prescl; //!  
   TBranch *b_L1_QuadJet6_Prescl; //! 
   TBranch *b_L1_QuadJet8_Prescl; //! 
   TBranch *b_L1_TripleJet14_Prescl; //!  
   TBranch *b_L1_DoubleEG1_Prescl; //! 
   TBranch *b_L1_DoubleEG2_Prescl; //! 
   TBranch *b_L1_DoubleEG5_Prescl; //! 
   TBranch *b_L1_DoubleHfBitCountsRing1_P1N1_Prescl; //! 
   TBranch *b_L1_DoubleHfBitCountsRing2_P1N1_Prescl; //! 
   TBranch *b_L1_DoubleHfRingEtSumsRing1_P200N200_Prescl; //! 
   TBranch *b_L1_DoubleHfRingEtSumsRing1_P4N4_Prescl; //! 
   TBranch *b_L1_DoubleHfRingEtSumsRing2_P200N200_Prescl; //! 
   TBranch *b_L1_DoubleHfRingEtSumsRing2_P4N4_Prescl; //! 
   TBranch *b_L1_DoubleJet70_Prescl; //! 
   TBranch *b_L1_DoubleMu3_Prescl; //! 
   TBranch *b_L1_DoubleMuOpen_Prescl; //! 
   TBranch *b_L1_DoubleTauJet30_Prescl; //! 
   TBranch *b_L1_EG10_Jet15_Prescl; //! 
   TBranch *b_L1_EG5_TripleJet15_Prescl; //! 
   TBranch *b_L1_ETM20_Prescl; //! 
   TBranch *b_L1_ETM40_Prescl; //! 
   TBranch *b_L1_ETM70_Prescl; //! 
   TBranch *b_L1_ETM80_Prescl; //! 
   TBranch *b_L1_ETT60_Prescl; //!
   TBranch *b_L1_ETT100_Prescl; //! 
   TBranch *b_L1_ETT140_Prescl; //! 
   TBranch *b_L1_HTT50_Prescl; //! 
   TBranch *b_L1_HTT100_Prescl; //! 
   TBranch *b_L1_HTT200_Prescl; //! 
   TBranch *b_L1_HTT300_Prescl; //! 
   TBranch *b_L1_IsoEG10_Jet15_ForJet10_Prescl; //! 
   TBranch *b_L1_MinBias_HTT10_Prescl; //! 
   TBranch *b_L1_Mu3QE8_EG5_Prescl; //!
   TBranch *b_L1_Mu3QE8_Jet15_Prescl; //!  
   TBranch *b_L1_Mu5QE8_Jet15_Prescl; //! 
   TBranch *b_L1_Mu3QE8_Jet6_Prescl; //!  
   TBranch *b_L1_Mu5QE8_Jet6_Prescl; //! 
   TBranch *b_L1_QuadJet15_Prescl; //! 
   TBranch *b_L1_SingleEG1_Prescl; //! 
   TBranch *b_L1_SingleEG10_Prescl; //! 
   TBranch *b_L1_SingleEG12_Prescl; //! 
   TBranch *b_L1_SingleEG15_Prescl; //! 
   TBranch *b_L1_SingleEG2_Prescl; //! 
   TBranch *b_L1_SingleEG20_Prescl; //! 
   TBranch *b_L1_SingleEG5_Prescl; //! 
   TBranch *b_L1_SingleEG8_Prescl; //! 
   TBranch *b_L1_SingleHfBitCountsRing1_1_Prescl; //! 
   TBranch *b_L1_SingleHfBitCountsRing2_1_Prescl; //! 
   TBranch *b_L1_SingleHfRingEtSumsRing1_200_Prescl; //! 
   TBranch *b_L1_SingleHfRingEtSumsRing1_4_Prescl; //! 
   TBranch *b_L1_SingleHfRingEtSumsRing2_200_Prescl; //! 
   TBranch *b_L1_SingleHfRingEtSumsRing2_4_Prescl; //! 
   TBranch *b_L1_SingleIsoEG10_Prescl; //! 
   TBranch *b_L1_SingleIsoEG12_Prescl; //! 
   TBranch *b_L1_SingleIsoEG15_Prescl; //! 
   TBranch *b_L1_SingleIsoEG5_Prescl; //! 
   TBranch *b_L1_SingleIsoEG8_Prescl; //! 
   TBranch *b_L1_SingleJet100_Prescl; //! 
   TBranch *b_L1_SingleJet15_Prescl; //! 
   TBranch *b_L1_SingleJet30_Prescl; //! 
   TBranch *b_L1_SingleJet50_Prescl; //! 
   TBranch *b_L1_SingleJet70_Prescl; //! 
   TBranch *b_L1_SingleMu0_Prescl; //! 
   TBranch *b_L1_SingleMu10_Prescl; //! 
   TBranch *b_L1_SingleMu14_Prescl; //! 
   TBranch *b_L1_SingleMu20_Prescl; //! 
   TBranch *b_L1_SingleMu3_Prescl; //! 
   TBranch *b_L1_SingleMu5_Prescl; //! 
   TBranch *b_L1_SingleMu7_Prescl; //! 
   TBranch *b_L1_SingleMuBeamHalo_Prescl; //! 
   TBranch *b_L1_SingleMuOpen_Prescl; //! 
   TBranch *b_L1_SingleTauJet30_Prescl; //! 
   TBranch *b_L1_SingleTauJet40_Prescl; //! 
   TBranch *b_L1_SingleTauJet60_Prescl; //! 
   TBranch *b_L1_SingleTauJet80_Prescl; //! 
   TBranch *b_L1_TripleJet30_Prescl; //! 
   TBranch *b_L1_ZeroBias_Prescl; //!
   TBranch *b_L1_ZeroBias_Ext_Prescl; //!
   TBranch *b_L1_SingleCenJet2_Prescl; //!    
   TBranch *b_L1_SingleCenJet4_Prescl; //!    
   TBranch *b_L1_SingleForJet2_Prescl; //!    
   TBranch *b_L1_SingleForJet4_Prescl; //!    
   TBranch *b_L1_SingleTauJet2_Prescl; //!    
   TBranch *b_L1_SingleTauJet4_Prescl; //!    
   TBranch *b_L1_DoubleForJet10_EtaOpp_Prescl; //!    
   TBranch *b_L1_Mu3_Jet6_Prescl; //!

   // L1 Technical bit prescales
   TBranch *b_L1Tech_BPTX_minus_v0_Prescl; //!
   TBranch *b_L1Tech_BPTX_minus_AND_not_plus_v0_Prescl; //!
   TBranch *b_L1Tech_BPTX_plus_v0_Prescl; //!
   TBranch *b_L1Tech_BPTX_plus_AND_NOT_minus_v0_Prescl; //!
   TBranch *b_L1Tech_BPTX_plus_AND_minus_v0_Prescl; //!
   TBranch *b_L1Tech_BPTX_plus_AND_minus_instance1_v0_Prescl; //!
   TBranch *b_L1Tech_BPTX_plus_OR_minus_v0_Prescl; //!
   TBranch *b_L1Tech_BPTX_quiet_v0_Prescl; //!
   TBranch *b_L1Tech_BSC_HighMultiplicity_v0_Prescl; //!
   TBranch *b_L1Tech_BSC_halo_beam1_inner_v0_Prescl; //!
   TBranch *b_L1Tech_BSC_halo_beam1_outer_v0_Prescl; //!
   TBranch *b_L1Tech_BSC_halo_beam2_inner_v0_Prescl; //!
   TBranch *b_L1Tech_BSC_halo_beam2_outer_v0_Prescl; //!
   TBranch *b_L1Tech_BSC_minBias_OR_v0_Prescl; //!
   TBranch *b_L1Tech_BSC_minBias_inner_threshold1_v0_Prescl; //!
   TBranch *b_L1Tech_BSC_minBias_inner_threshold2_v0_Prescl; //!
   TBranch *b_L1Tech_BSC_minBias_threshold1_v0_Prescl; //!
   TBranch *b_L1Tech_BSC_minBias_threshold2_v0_Prescl; //!
   TBranch *b_L1Tech_BSC_splash_beam1_v0_Prescl; //!
   TBranch *b_L1Tech_BSC_splash_beam2_v0_Prescl; //!
   TBranch *b_L1Tech_HCAL_HBHE_totalOR_v0_Prescl; //!
   TBranch *b_L1Tech_HCAL_HF_totalOR_coincidenceHFM_v0_Prescl; //!
   TBranch *b_L1Tech_HCAL_HF_totalOR_coincidenceHFP_v0_Prescl; //!
   TBranch *b_L1Tech_HCAL_HF_totalOR_minBias_v0_Prescl; //!
   TBranch *b_L1Tech_HCAL_HO_totalOR_v0_Prescl; //!
   TBranch *b_L1Tech_RPC_TTU_RB0_Cosmics_v0_Prescl; //!
   TBranch *b_L1Tech_RPC_TTU_RBminus1_Cosmics_v0_Prescl; //!
   TBranch *b_L1Tech_RPC_TTU_RBminus2_Cosmics_v0_Prescl; //!
   TBranch *b_L1Tech_RPC_TTU_RBplus1_Cosmics_v0_Prescl; //!
   TBranch *b_L1Tech_RPC_TTU_RBplus2_Cosmics_v0_Prescl; //!
   TBranch *b_L1Tech_RPC_TTU_barrel_Cosmics_v0_Prescl; //!
   TBranch *b_L1Tech_RPC_TTU_pointing_Cosmics_v0_Prescl; //!
   TBranch *b_L1Tech_RPC_TTU_RBst1_collisions_v0_Prescl; //!
   TBranch *b_L1Tech_HCAL_HF_MM_or_PP_or_PM_v0_Prescl; //!
   TBranch *b_L1Tech_HCAL_HF_coincidence_PM_v1_Prescl; //!
   TBranch *b_L1Tech_HCAL_HF_MMP_or_MPP_v0_Prescl; //!
   TBranch *b_L1Tech_ZDC_loose_vertex_v0_Prescl; //!
   TBranch *b_L1Tech_ZDC_minus_over_threshold_v0_Prescl; //!
   TBranch *b_L1Tech_ZDC_plus_over_threshold_v0_Prescl; //!
   TBranch *b_L1Tech_ZDC_tight_vertex_v0_Prescl; //!
   TBranch *b_L1_BptxMinus_Prescl; //!
   TBranch *b_L1_BptxPlus_Prescl; //!
   TBranch *b_L1_BptxPlusORMinus_Prescl; //!
   TBranch *b_L1_BptxPlus_NotBptxMinus_Prescl; //!
   TBranch *b_L1_BptxMinus_NotBptxPlus_Prescl; //!
   TBranch *b_L1_BscHighMultiplicity_Prescl; //!
   TBranch *b_L1_BscMinBiasInnerThreshold1_Prescl; //!
   TBranch *b_L1_BscMinBiasInnerThreshold2_Prescl; //!
   TBranch *b_L1_BscMinBiasOR_Prescl; //!
   TBranch *b_L1_BscMinBiasOR_BptxPlusORMinus_Prescl; //!
   TBranch *b_L1_BscMinBiasOR_BptxPlusANDMinus_Prescl; //!  



   // Autogenerated from ConfDB - TBranch
   TBranch *b_HLT_PFJet40_v6; //!
   TBranch *b_HLT_PFJet80_v6; //!
   TBranch *b_HLT_PFJet140_v6; //!
   TBranch *b_HLT_PFJet200_v6; //!
   TBranch *b_HLT_PFJet260_v6; //!
   TBranch *b_HLT_PFJet320_v6; //!
   TBranch *b_HLT_Jet370_NoJetID_v14; //!
   TBranch *b_HLT_PFJet400_v6; //!
   TBranch *b_HLT_MonoCentralPFJet80_PFMETnoMu105_NHEF0p95_v1; //!
   TBranch *b_HLT_SingleForJet25_v3; //!
   TBranch *b_HLT_SingleForJet15_v3; //!
   TBranch *b_HLT_DiPFJetAve40_v7; //!
   TBranch *b_HLT_DiPFJetAve80_v7; //!
   TBranch *b_HLT_DiPFJetAve140_v7; //!
   TBranch *b_HLT_DiPFJetAve200_v7; //!
   TBranch *b_HLT_DiPFJetAve260_v7; //!
   TBranch *b_HLT_DiPFJetAve320_v7; //!
   TBranch *b_HLT_DiPFJetAve400_v7; //!
   TBranch *b_HLT_FatDiPFJetMass750_DR1p1_Deta1p5_v6; //!
   TBranch *b_HLT_DoubleJet20_ForwardBackward_v3; //!
   TBranch *b_HLT_DiJet80_DiJet60_DiJet20_v3; //!
   TBranch *b_HLT_DiPFJet40_PFMETnoMu65_MJJ800VBF_AllJets_v6; //!
   TBranch *b_HLT_DiPFJet40_PFMETnoMu65_MJJ600VBF_LeadingJets_v6; //!
   TBranch *b_HLT_DiJet40Eta2p6_BTagIP3DFastPV_v5; //!
   TBranch *b_HLT_DiJet80Eta2p6_BTagIP3DFastPVLoose_v5; //!
   TBranch *b_HLT_Jet60Eta1p7_Jet53Eta1p7_DiBTagIP3DFastPV_v5; //!
   TBranch *b_HLT_Jet80Eta1p7_Jet70Eta1p7_DiBTagIP3DFastPV_v5; //!
   TBranch *b_HLT_Jet160Eta2p4_Jet120Eta2p4_DiBTagIP3DFastPVLoose_v5; //!
   TBranch *b_HLT_QuadJet50_v3; //!
   TBranch *b_HLT_QuadJet50_Jet20_v2; //!
   TBranch *b_HLT_QuadJet60_DiJet20_v3; //!
   TBranch *b_HLT_QuadJet70_v3; //!
   TBranch *b_HLT_QuadJet80_v3; //!
   TBranch *b_HLT_QuadJet90_v3; //!
   TBranch *b_HLT_QuadJet75_55_35_20_BTagIP_VBF_v4; //!
   TBranch *b_HLT_QuadJet75_55_38_20_BTagIP_VBF_v4; //!
   TBranch *b_HLT_QuadPFJet78_61_44_31_BTagCSV_VBF_v2; //!
   TBranch *b_HLT_QuadPFJet82_65_48_35_BTagCSV_VBF_v2; //!
   TBranch *b_HLT_SixJet35_v3; //!
   TBranch *b_HLT_SixJet45_v3; //!
   TBranch *b_HLT_SixJet50_v3; //!
   TBranch *b_HLT_EightJet30_eta3p0_v2; //!
   TBranch *b_HLT_EightJet35_eta3p0_v2; //!
   TBranch *b_HLT_ExclDiJet35_HFOR_v3; //!
   TBranch *b_HLT_ExclDiJet35_HFAND_v3; //!
   TBranch *b_HLT_ExclDiJet80_HFAND_v3; //!
   TBranch *b_HLT_JetE30_NoBPTX_v13; //!
   TBranch *b_HLT_JetE30_NoBPTX3BX_NoHalo_v14; //!
   TBranch *b_HLT_JetE50_NoBPTX3BX_NoHalo_v11; //!
   TBranch *b_HLT_JetE70_NoBPTX3BX_NoHalo_v3; //!
   TBranch *b_HLT_HT200_AlphaT0p57_v6; //!
   TBranch *b_HLT_HT200_v4; //!
   TBranch *b_HLT_HT250_AlphaT0p55_v5; //!
   TBranch *b_HLT_HT250_AlphaT0p57_v5; //!
   TBranch *b_HLT_HT250_v4; //!
   TBranch *b_HLT_HT300_AlphaT0p53_v5; //!
   TBranch *b_HLT_HT300_AlphaT0p54_v11; //!
   TBranch *b_HLT_HT300_v4; //!
   TBranch *b_HLT_HT300_DoubleDisplacedPFJet60_v6; //!
   TBranch *b_HLT_HT300_DoubleDisplacedPFJet60_ChgFraction10_v6; //!
   TBranch *b_HLT_HT300_SingleDisplacedPFJet60_v6; //!
   TBranch *b_HLT_HT300_SingleDisplacedPFJet60_ChgFraction10_v6; //!
   TBranch *b_HLT_HT350_v4; //!
   TBranch *b_HLT_HT350_AlphaT0p52_v5; //!
   TBranch *b_HLT_HT350_AlphaT0p53_v16; //!
   TBranch *b_HLT_HT400_v4; //!
   TBranch *b_HLT_HT400_AlphaT0p51_v16; //!
   TBranch *b_HLT_HT400_AlphaT0p52_v11; //!
   TBranch *b_HLT_HT450_AlphaT0p51_v11; //!
   TBranch *b_HLT_HT450_v4; //!
   TBranch *b_HLT_HT500_v4; //!
   TBranch *b_HLT_HT550_v4; //!
   TBranch *b_HLT_HT650_v4; //!
   TBranch *b_HLT_HT650_Track50_dEdx3p6_v7; //!
   TBranch *b_HLT_HT650_Track60_dEdx3p7_v7; //!
   TBranch *b_HLT_HT750_v4; //!
   TBranch *b_HLT_PFNoPUHT350_v1; //!
   TBranch *b_HLT_PFNoPUHT650_v1; //!
   TBranch *b_HLT_PFNoPUHT650_DiCentralPFNoPUJet80_CenPFNoPUJet40_v1; //!
   TBranch *b_HLT_PFNoPUHT700_v1; //!
   TBranch *b_HLT_PFNoPUHT750_v1; //!
   TBranch *b_HLT_PFMET150_v5; //!
   TBranch *b_HLT_PFMET180_v5; //!
   TBranch *b_HLT_DiCentralJetSumpT100_dPhi05_DiCentralPFJet60_25_PFMET100_HBHENoiseCleaned_v2; //!
   TBranch *b_HLT_DiCentralPFJet30_PFMET80_v3; //!
   TBranch *b_HLT_DiCentralPFNoPUJet50_PFMETORPFMETNoMu80_v1; //!
   TBranch *b_HLT_DiCentralPFJet30_PFMET80_BTagCSV07_v2; //!
   TBranch *b_HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05d03_v2; //!
   TBranch *b_HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05d05_v2; //!
   TBranch *b_HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05_v2; //!
   TBranch *b_HLT_MET80_v4; //!
   TBranch *b_HLT_MET80_Track50_dEdx3p6_v5; //!
   TBranch *b_HLT_MET80_Track60_dEdx3p7_v5; //!
   TBranch *b_HLT_MET120_v11; //!
   TBranch *b_HLT_MET120_HBHENoiseCleaned_v4; //!
   TBranch *b_HLT_MET200_v11; //!
   TBranch *b_HLT_MET200_HBHENoiseCleaned_v4; //!
   TBranch *b_HLT_MET300_v3; //!
   TBranch *b_HLT_MET300_HBHENoiseCleaned_v4; //!
   TBranch *b_HLT_MET400_v6; //!
   TBranch *b_HLT_MET400_HBHENoiseCleaned_v4; //!
   TBranch *b_HLT_L1SingleMuOpen_v7; //!
   TBranch *b_HLT_L1SingleMu12_v2; //!
   TBranch *b_HLT_L2Mu70_eta2p1_PFMET55_v2; //!
   TBranch *b_HLT_L2Mu70_eta2p1_PFMET60_v2; //!
   TBranch *b_HLT_L2Mu20_eta2p1_NoVertex_v2; //!
   TBranch *b_HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo_v3; //!
   TBranch *b_HLT_L2Mu20_NoVertex_2Cha_NoBPTX3BX_NoHalo_v1; //!
   TBranch *b_HLT_L2Mu30_NoVertex_2Cha_NoBPTX3BX_NoHalo_v1; //!
   TBranch *b_HLT_L2TripleMu10_0_0_NoVertex_PFJet40Neutral_v5; //!
   TBranch *b_HLT_DoubleDisplacedMu4_DiPFJet40Neutral_v5; //!
   TBranch *b_HLT_Mu5_v19; //!
   TBranch *b_HLT_Mu8_v17; //!
   TBranch *b_HLT_Mu12_v17; //!
   TBranch *b_HLT_Mu17_v4; //!
   TBranch *b_HLT_Mu12_eta2p1_L1Mu10erJetC12WdEtaPhi1DiJetsC_v4; //!
   TBranch *b_HLT_Mu15_eta2p1_v4; //!
   TBranch *b_HLT_Mu24_v15; //!
   TBranch *b_HLT_Mu24_eta2p1_v4; //!
   TBranch *b_HLT_Mu30_v15; //!
   TBranch *b_HLT_Mu30_eta2p1_v4; //!
   TBranch *b_HLT_Mu40_v13; //!
   TBranch *b_HLT_Mu40_eta2p1_v10; //!
   TBranch *b_HLT_Mu50_eta2p1_v7; //!
   TBranch *b_HLT_RelIso1p0Mu5_v5; //!
   TBranch *b_HLT_RelIso1p0Mu20_v2; //!
   TBranch *b_HLT_IsoMu15_eta2p1_L1ETM20_v6; //!
   TBranch *b_HLT_IsoMu20_eta2p1_v6; //!
   TBranch *b_HLT_IsoMu24_v16; //!
   TBranch *b_HLT_IsoMu24_eta2p1_v14; //!
   TBranch *b_HLT_IsoMu30_v10; //!
   TBranch *b_HLT_IsoMu30_eta2p1_v14; //!
   TBranch *b_HLT_IsoMu34_eta2p1_v12; //!
   TBranch *b_HLT_IsoMu40_eta2p1_v9; //!
   TBranch *b_HLT_Mu40_eta2p1_Track50_dEdx3p6_v4; //!
   TBranch *b_HLT_Mu40_eta2p1_Track60_dEdx3p7_v4; //!
   TBranch *b_HLT_L2DoubleMu23_NoVertex_v11; //!
   TBranch *b_HLT_L2DoubleMu23_NoVertex_2Cha_Angle2p5_v3; //!
   TBranch *b_HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_v3; //!
   TBranch *b_HLT_DoubleMu11_Acoplanarity03_v4; //!
   TBranch *b_HLT_DoubleMu4_Jpsi_Displaced_v10; //!
   TBranch *b_HLT_DoubleMu4_JpsiTk_Displaced_v4; //!
   TBranch *b_HLT_DoubleMu3_4_Dimuon5_Bs_Central_v3; //!
   TBranch *b_HLT_DoubleMu3p5_4_Dimuon5_Bs_Central_v3; //!
   TBranch *b_HLT_DoubleMu4_Dimuon7_Bs_Forward_v3; //!
   TBranch *b_HLT_DoubleMu3p5_LowMass_Displaced_v4; //!
   TBranch *b_HLT_DoubleMu3p5_LowMassNonResonant_Displaced_v4; //!
   TBranch *b_HLT_Dimuon0_Jpsi_v15; //!
   TBranch *b_HLT_Dimuon0_Jpsi_NoVertexing_v12; //!
   TBranch *b_HLT_Dimuon0_Upsilon_v15; //!
   TBranch *b_HLT_Dimuon0_PsiPrime_v4; //!
   TBranch *b_HLT_Dimuon5_Upsilon_v4; //!
   TBranch *b_HLT_Dimuon5_PsiPrime_v4; //!
   TBranch *b_HLT_Dimuon7_Upsilon_v5; //!
   TBranch *b_HLT_Dimuon7_PsiPrime_v1; //!
   TBranch *b_HLT_Dimuon8_Jpsi_v5; //!
   TBranch *b_HLT_Dimuon8_Upsilon_v4; //!
   TBranch *b_HLT_Dimuon10_Jpsi_v4; //!
   TBranch *b_HLT_Dimuon11_Upsilon_v4; //!
   TBranch *b_HLT_Dimuon0_Jpsi_Muon_v16; //!
   TBranch *b_HLT_Dimuon0_Upsilon_Muon_v16; //!
   TBranch *b_HLT_Dimuon3p5_SameSign_v4; //!
   TBranch *b_HLT_DoubleMu4_Acoplanarity03_v4; //!
   TBranch *b_HLT_Tau2Mu_ItTrack_v4; //!
   TBranch *b_HLT_Mu13_Mu8_v18; //!
   TBranch *b_HLT_Mu17_Mu8_v18; //!
   TBranch *b_HLT_Mu17_TkMu8_v11; //!
   TBranch *b_HLT_Mu22_TkMu8_v7; //!
   TBranch *b_HLT_Mu22_TkMu22_v7; //!
   TBranch *b_HLT_TripleMu5_v18; //!
   TBranch *b_HLT_DoubleMu5_IsoMu5_v19; //!
   TBranch *b_HLT_Mu5_L2Mu3_Jpsi_v5; //!
   TBranch *b_HLT_Mu5_Track2_Jpsi_v19; //!
   TBranch *b_HLT_Mu5_Track3p5_Jpsi_v5; //!
   TBranch *b_HLT_Mu7_Track7_Jpsi_v19; //!
   TBranch *b_HLT_Photon20_CaloIdVL_v4; //!
   TBranch *b_HLT_Photon20_CaloIdVL_IsoL_v16; //!
   TBranch *b_HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_v5; //!
   TBranch *b_HLT_Photon26_Photon18_v12; //!
   TBranch *b_HLT_Photon26_R9Id85_Photon18_R9Id85_Mass60_v4; //!
   TBranch *b_HLT_Photon26_R9Id85_Photon18_CaloId10_Iso50_Mass60_v6; //!
   TBranch *b_HLT_Photon26_CaloId10_Iso50_Photon18_R9Id85_Mass60_v6; //!
   TBranch *b_HLT_Photon26_CaloId10_Iso50_Photon18_CaloId10_Iso50_Mass60_v6; //!
   TBranch *b_HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass60_v6; //!
   TBranch *b_HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass70_v2; //!
   TBranch *b_HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_v5; //!
   TBranch *b_HLT_Photon30_CaloIdVL_v14; //!
   TBranch *b_HLT_Photon30_CaloIdVL_IsoL_v19; //!
   TBranch *b_HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_v5; //!
   TBranch *b_HLT_Photon36_Photon22_v6; //!
   TBranch *b_HLT_Photon36_R9Id85_Photon22_R9Id85_v4; //!
   TBranch *b_HLT_Photon36_R9Id85_Photon22_CaloId10_Iso50_v6; //!
   TBranch *b_HLT_Photon36_CaloId10_Iso50_Photon22_R9Id85_v6; //!
   TBranch *b_HLT_Photon36_CaloId10_Iso50_Photon22_CaloId10_Iso50_v6; //!
   TBranch *b_HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_R9Id85_OR_CaloId10_Iso50_v6; //!
   TBranch *b_HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_v5; //!
   TBranch *b_HLT_Photon50_CaloIdVL_v10; //!
   TBranch *b_HLT_Photon50_CaloIdVL_IsoL_v17; //!
   TBranch *b_HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_v5; //!
   TBranch *b_HLT_Photon60_CaloIdL_MHT70_v9; //!
   TBranch *b_HLT_Photon60_CaloIdL_HT300_v2; //!
   TBranch *b_HLT_Photon70_CaloIdXL_PFNoPUHT400_v1; //!
   TBranch *b_HLT_Photon70_CaloIdXL_PFNoPUHT500_v1; //!
   TBranch *b_HLT_Photon70_CaloIdXL_PFMET100_v5; //!
   TBranch *b_HLT_Photon75_CaloIdVL_v13; //!
   TBranch *b_HLT_Photon75_CaloIdVL_IsoL_v18; //!
   TBranch *b_HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_v5; //!
   TBranch *b_HLT_Photon90_CaloIdVL_v10; //!
   TBranch *b_HLT_Photon90_CaloIdVL_IsoL_v15; //!
   TBranch *b_HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_v5; //!
   TBranch *b_HLT_DisplacedPhoton65_CaloIdVL_IsoL_PFMET25_v2; //!
   TBranch *b_HLT_DisplacedPhoton65EBOnly_CaloIdVL_IsoL_PFMET30_v2; //!
   TBranch *b_HLT_Photon135_v7; //!
   TBranch *b_HLT_Photon150_v4; //!
   TBranch *b_HLT_Photon160_v4; //!
   TBranch *b_HLT_Photon300_NoHE_v5; //!
   TBranch *b_HLT_DoublePhoton48_HEVT_v8; //!
   TBranch *b_HLT_DoublePhoton53_HEVT_v2; //!
   TBranch *b_HLT_DoublePhoton70_v6; //!
   TBranch *b_HLT_DoublePhoton80_v7; //!
   TBranch *b_HLT_DoublePhoton5_IsoVL_CEP_v16; //!
   TBranch *b_HLT_L1SingleEG5_v6; //!
   TBranch *b_HLT_L1SingleEG12_v6; //!
   TBranch *b_HLT_L1DoubleEG3_FwdVeto_v2; //!
   TBranch *b_HLT_L1ETM30_v2; //!
   TBranch *b_HLT_L1ETM40_v2; //!
   TBranch *b_HLT_L1ETM70_v2; //!
   TBranch *b_HLT_L1ETM100_v2; //!
   TBranch *b_HLT_Ele8_CaloIdT_TrkIdVL_v5; //!
   TBranch *b_HLT_Ele8_CaloIdT_TrkIdVL_EG7_v2; //!
   TBranch *b_HLT_Ele8_CaloIdT_TrkIdVL_Jet30_v5; //!
   TBranch *b_HLT_Ele8_CaloIdL_CaloIsoVL_v17; //!
   TBranch *b_HLT_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v15; //!
   TBranch *b_HLT_Ele17_CaloIdL_CaloIsoVL_v17; //!
   TBranch *b_HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v6; //!
   TBranch *b_HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v18; //!
   TBranch *b_HLT_Ele17_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_Ele8_Mass50_v6; //!
   TBranch *b_HLT_Ele20_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_SC4_Mass50_v6; //!
   TBranch *b_HLT_Ele22_CaloIdL_CaloIsoVL_v6; //!
   TBranch *b_HLT_Ele27_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_v11; //!
   TBranch *b_HLT_Ele27_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele15_CaloIdT_CaloIsoVL_trackless_v7; //!
   TBranch *b_HLT_Ele27_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_HFT15_v7; //!
   TBranch *b_HLT_Ele23_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_HFT30_v7; //!
   TBranch *b_HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet30_v2; //!
   TBranch *b_HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet50_40_30_v2; //!
   TBranch *b_HLT_Ele27_WP80_v11; //!
   TBranch *b_HLT_Ele27_WP80_PFMET_MT50_v5; //!
   TBranch *b_HLT_Ele30_CaloIdVT_TrkIdT_v6; //!
   TBranch *b_HLT_Ele32_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_v11; //!
   TBranch *b_HLT_Ele32_CaloIdT_CaloIsoT_TrkIdT_TrkIsoT_SC17_Mass50_v6; //!
   TBranch *b_HLT_Ele80_CaloIdVT_GsfTrkIdT_v2; //!
   TBranch *b_HLT_Ele90_CaloIdVT_GsfTrkIdT_v2; //!
   TBranch *b_HLT_DoubleEle8_CaloIdT_TrkIdVL_v12; //!
   TBranch *b_HLT_DoubleEle33_CaloIdL_v14; //!
   TBranch *b_HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v7; //!
   TBranch *b_HLT_DoubleEle33_CaloIdT_v10; //!
   TBranch *b_HLT_Ele15_Ele8_Ele5_CaloIdL_TrkIdVL_v6; //!
   TBranch *b_HLT_LooseIsoPFTau35_Trk20_Prong1_v7; //!
   TBranch *b_HLT_LooseIsoPFTau35_Trk20_Prong1_MET70_v7; //!
   TBranch *b_HLT_LooseIsoPFTau35_Trk20_Prong1_MET75_v7; //!
   TBranch *b_HLT_IsoMu15_eta2p1_LooseIsoPFTau35_Trk20_Prong1_L1ETM20_v7; //!
   TBranch *b_HLT_DoubleMediumIsoPFTau30_Trk1_eta2p1_Jet30_v1; //!
   TBranch *b_HLT_DoubleMediumIsoPFTau30_Trk1_eta2p1_v1; //!
   TBranch *b_HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Prong1_v1; //!
   TBranch *b_HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_v1; //!
   TBranch *b_HLT_IsoMu18_eta2p1_MediumIsoPFTau25_Trk1_eta2p1_v1; //!
   TBranch *b_HLT_BTagMu_DiJet20_Mu5_v4; //!
   TBranch *b_HLT_BTagMu_DiJet40_Mu5_v4; //!
   TBranch *b_HLT_BTagMu_DiJet70_Mu5_v4; //!
   TBranch *b_HLT_BTagMu_DiJet110_Mu5_v4; //!
   TBranch *b_HLT_BTagMu_Jet300_Mu5_v4; //!
   TBranch *b_HLT_Mu7_Ele7_CaloIdT_CaloIsoVL_v6; //!
   TBranch *b_HLT_Mu8_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v8; //!
   TBranch *b_HLT_Mu8_DiJet30_v5; //!
   TBranch *b_HLT_Mu8_TriJet30_v5; //!
   TBranch *b_HLT_Mu8_QuadJet30_v5; //!
   TBranch *b_HLT_IsoMu12_DoubleCentralJet65_v2; //!
   TBranch *b_HLT_Mu15_eta2p1_L1ETM20_v4; //!
   TBranch *b_HLT_Mu24_PFJet30_PFJet25_Deta3_CentralPFJet25_v2; //!
   TBranch *b_HLT_Mu24_CentralPFJet30_CentralPFJet25_v2; //!
   TBranch *b_HLT_IsoMu24_PFJet30_PFJet25_Deta3_CentralPFJet25_v2; //!
   TBranch *b_HLT_IsoMu24_CentralPFJet30_CentralPFJet25_v2; //!
   TBranch *b_HLT_IsoMu24_CentralPFJet30_CentralPFJet25_PFMET20_v2; //!
   TBranch *b_HLT_Ele32_WP80_PFJet30_PFJet25_Deta3_v2; //!
   TBranch *b_HLT_Ele32_WP80_PFJet30_PFJet25_Deta3_CentralPFJet30_v2; //!
   TBranch *b_HLT_Ele32_WP80_CentralPFJet35_CentralPFJet25_v2; //!
   TBranch *b_HLT_Ele32_WP80_CentralPFJet35_CentralPFJet25_PFMET20_v2; //!
   TBranch *b_HLT_IsoMu17_eta2p1_CentralPFNoPUJet30_BTagIPIter_v2; //!
   TBranch *b_HLT_IsoMu17_eta2p1_CentralPFNoPUJet30_v2; //!
   TBranch *b_HLT_IsoMu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2; //!
   TBranch *b_HLT_Mu17_eta2p1_CentralPFNoPUJet30_BTagIPIter_v2; //!
   TBranch *b_HLT_Mu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2; //!
   TBranch *b_HLT_IsoMu20_WCandPt80_v2; //!
   TBranch *b_HLT_Mu17_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v8; //!
   TBranch *b_HLT_Mu12_eta2p1_DiCentral_40_20_DiBTagIP3D1stTrack_v4; //!
   TBranch *b_HLT_Mu12_eta2p1_DiCentral_40_20_BTagIP3D1stTrack_v4; //!
   TBranch *b_HLT_Mu12_eta2p1_DiCentral_40_20_v4; //!
   TBranch *b_HLT_Mu12_eta2p1_DiCentral_20_v4; //!
   TBranch *b_HLT_Mu15_eta2p1_TriCentral_40_20_20_DiBTagIP3D1stTrack_v4; //!
   TBranch *b_HLT_Mu15_eta2p1_TriCentral_40_20_20_BTagIP3D1stTrack_v4; //!
   TBranch *b_HLT_Mu15_eta2p1_TriCentral_40_20_20_v4; //!
   TBranch *b_HLT_Mu30_Ele30_CaloIdL_v7; //!
   TBranch *b_HLT_IsoMu17_eta2p1_DiCentralPFNoPUJet30_PFNoPUHT350_PFMHT40_v1; //!
   TBranch *b_HLT_IsoMu20_eta2p1_CentralPFJet80_v7; //!
   TBranch *b_HLT_DoubleRelIso1p0Mu5_Mass8_PFNoPUHT175_v1; //!
   TBranch *b_HLT_DoubleRelIso1p0Mu5_Mass8_PFNoPUHT225_v1; //!
   TBranch *b_HLT_DoubleMu8_Mass8_PFNoPUHT175_v1; //!
   TBranch *b_HLT_DoubleMu8_Mass8_PFNoPUHT225_v1; //!
   TBranch *b_HLT_RelIso1p0Mu5_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1; //!
   TBranch *b_HLT_RelIso1p0Mu5_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1; //!
   TBranch *b_HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1; //!
   TBranch *b_HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1; //!
   TBranch *b_HLT_PFNoPUHT350_Mu15_PFMET45_v1; //!
   TBranch *b_HLT_PFNoPUHT350_Mu15_PFMET50_v1; //!
   TBranch *b_HLT_PFNoPUHT400_Mu5_PFMET45_v1; //!
   TBranch *b_HLT_PFNoPUHT400_Mu5_PFMET50_v1; //!
   TBranch *b_HLT_Mu40_PFNoPUHT350_v1; //!
   TBranch *b_HLT_Mu60_PFNoPUHT350_v1; //!
   TBranch *b_HLT_Mu40_HT200_v2; //!
   TBranch *b_HLT_DoubleMu5_Ele8_CaloIdT_TrkIdVL_v15; //!
   TBranch *b_HLT_DoubleMu8_Ele8_CaloIdT_TrkIdVL_v4; //!
   TBranch *b_HLT_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Jet30_v6; //!
   TBranch *b_HLT_Ele8_CaloIdT_TrkIdT_DiJet30_v16; //!
   TBranch *b_HLT_Ele8_CaloIdT_TrkIdT_TriJet30_v16; //!
   TBranch *b_HLT_Ele8_CaloIdT_TrkIdT_QuadJet30_v16; //!
   TBranch *b_HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Jet30_v6; //!
   TBranch *b_HLT_Ele25_CaloIdVT_TrkIdT_TriCentralPFNoPUJet30_30_20_v2; //!
   TBranch *b_HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_CentralPFNoPUJet30_v6; //!
   TBranch *b_HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2; //!
   TBranch *b_HLT_Ele25_CaloIdVL_CaloIsoT_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2; //!
   TBranch *b_HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_CentralPFNoPUJet30_BTagIPIter_v7; //!
   TBranch *b_HLT_Ele27_WP80_CentralPFJet80_v7; //!
   TBranch *b_HLT_Ele27_WP80_WCandPt80_v7; //!
   TBranch *b_HLT_Ele30_CaloIdVT_TrkIdT_PFNoPUJet100_PFNoPUJet25_v6; //!
   TBranch *b_HLT_Ele30_CaloIdVT_TrkIdT_PFNoPUJet150_PFNoPUJet25_v6; //!
   TBranch *b_HLT_DoubleEle8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1; //!
   TBranch *b_HLT_DoubleEle8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1; //!
   TBranch *b_HLT_DoubleEle10_CaloIdL_TrkIdVL_Ele10_CaloIdT_TrkIdVL_v12; //!
   TBranch *b_HLT_TripleEle10_CaloIdL_TrkIdVL_v18; //!
   TBranch *b_HLT_RsqMR40_Rsq0p04_v4; //!
   TBranch *b_HLT_RsqMR45_Rsq0p09_v3; //!
   TBranch *b_HLT_RsqMR55_Rsq0p09_MR150_v4; //!
   TBranch *b_HLT_RsqMR60_Rsq0p09_MR150_v4; //!
   TBranch *b_HLT_RsqMR65_Rsq0p09_MR150_v3; //!
   TBranch *b_HLT_IsoMu12_RsqMR30_Rsq0p04_MR200_v2; //!
   TBranch *b_HLT_IsoMu12_RsqMR40_Rsq0p04_MR200_v2; //!
   TBranch *b_HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_RsqMR30_Rsq0p04_MR200_v2; //!
   TBranch *b_HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_RsqMR40_Rsq0p04_MR200_v2; //!
   TBranch *b_HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_DoubleCentralJet65_v2; //!
   TBranch *b_HLT_Photon40_CaloIdL_RsqMR35_Rsq0p09_MR150_v4; //!
   TBranch *b_HLT_Photon40_CaloIdL_RsqMR40_Rsq0p09_MR150_v4; //!
   TBranch *b_HLT_Photon40_CaloIdL_RsqMR45_Rsq0p09_MR150_v4; //!
   TBranch *b_HLT_Photon40_CaloIdL_RsqMR50_Rsq0p09_MR150_v4; //!
   TBranch *b_HLT_DoublePhoton40_CaloIdL_Rsq0p035_v4; //!
   TBranch *b_HLT_DoublePhoton40_CaloIdL_Rsq0p06_v4; //!
   TBranch *b_HLT_Mu22_Photon22_CaloIdL_v6; //!
   TBranch *b_HLT_Mu8_DoubleEle8_CaloIdT_TrkIdVL_v6; //!
   TBranch *b_HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Ele8_CaloIdL_TrkIdVL_v6; //!
   TBranch *b_HLT_DoubleMu14_Mass8_PFMET40_v6; //!
   TBranch *b_HLT_DoubleMu14_Mass8_PFMET50_v6; //!
   TBranch *b_HLT_DoubleEle14_CaloIdT_TrkIdVL_Mass8_PFMET40_v6; //!
   TBranch *b_HLT_DoubleEle14_CaloIdT_TrkIdVL_Mass8_PFMET50_v6; //!
   TBranch *b_HLT_Mu14_Ele14_CaloIdT_TrkIdVL_Mass8_PFMET40_v6; //!
   TBranch *b_HLT_Mu14_Ele14_CaloIdT_TrkIdVL_Mass8_PFMET50_v6; //!
   TBranch *b_HLT_PFNoPUHT350_PFMET100_v1; //!
   TBranch *b_HLT_PFNoPUHT400_PFMET100_v1; //!
   TBranch *b_HLT_CleanPFNoPUHT350_Ele5_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET45_v1; //!
   TBranch *b_HLT_CleanPFNoPUHT350_Ele5_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET50_v1; //!
   TBranch *b_HLT_CleanPFNoPUHT300_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET45_v1; //!
   TBranch *b_HLT_CleanPFNoPUHT300_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET50_v1; //!
   TBranch *b_HLT_CleanPFNoPUHT300_Ele40_CaloIdVT_TrkIdT_v1; //!
   TBranch *b_HLT_CleanPFNoPUHT300_Ele60_CaloIdVT_TrkIdT_v1; //!
   TBranch *b_HLT_Ele5_SC5_Jpsi_Mass2to15_v4; //!
   TBranch *b_HLT_DiJet35_MJJ650_AllJets_DEta3p5_VBF_v2; //!
   TBranch *b_HLT_DiJet35_MJJ700_AllJets_DEta3p5_VBF_v2; //!
   TBranch *b_HLT_DiJet35_MJJ750_AllJets_DEta3p5_VBF_v2; //!
   TBranch *b_HLT_Ele22_eta2p1_WP90Rho_LooseIsoPFTau20_v3; //!
   TBranch *b_HLT_Ele22_eta2p1_WP90NoIso_LooseIsoPFTau20_v3; //!
   TBranch *b_HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v3; //!
   TBranch *b_HLT_Mu17_eta2p1_LooseIsoPFTau20_v3; //!
   TBranch *b_HLT_PixelTracks_Multiplicity70_v3; //!
   TBranch *b_HLT_PixelTracks_Multiplicity80_v12; //!
   TBranch *b_HLT_PixelTracks_Multiplicity90_v3; //!
   TBranch *b_HLT_BeamGas_HF_Beam1_v5; //!
   TBranch *b_HLT_BeamGas_HF_Beam2_v5; //!
   TBranch *b_HLT_BeamHalo_v13; //!
   TBranch *b_HLT_IsoTrackHE_v15; //!
   TBranch *b_HLT_IsoTrackHB_v14; //!
   TBranch *b_HLT_HcalPhiSym_v11; //!
   TBranch *b_HLT_HcalNZS_v10; //!
   TBranch *b_HLT_GlobalRunHPDNoise_v8; //!
   TBranch *b_HLT_L1Tech_HBHEHO_totalOR_v6; //!
   TBranch *b_HLT_L1Tech_HCAL_HF_single_channel_v4; //!
   TBranch *b_HLT_ZeroBias_v7; //!
   TBranch *b_HLT_ZeroBiasPixel_DoubleTrack_v2; //!
   TBranch *b_HLT_Physics_v5; //!
   TBranch *b_HLT_DTCalibration_v2; //!
   TBranch *b_HLT_EcalCalibration_v3; //!
   TBranch *b_HLT_HcalCalibration_v3; //!
   TBranch *b_HLT_TrackerCalibration_v3; //!
   TBranch *b_HLT_Random_v2; //!
   TBranch *b_HLT_L1SingleMuOpen_AntiBPTX_v7; //!
   TBranch *b_HLT_L1TrackerCosmics_v7; //!
   TBranch *b_HLT_LogMonitor_v3; //!
   TBranch *b_HLT_DTErrors_v3; //!
   TBranch *b_HLT_L1DoubleJet36Central_v7; //!
   TBranch *b_AlCa_EcalPi0EBonly_v6; //!
   TBranch *b_AlCa_EcalPi0EEonly_v6; //!
   TBranch *b_AlCa_EcalEtaEBonly_v6; //!
   TBranch *b_AlCa_EcalEtaEEonly_v6; //!
   TBranch *b_AlCa_EcalPhiSym_v13; //!
   TBranch *b_AlCa_RPCMuonNoTriggers_v9; //!
   TBranch *b_AlCa_RPCMuonNoHits_v9; //!
   TBranch *b_AlCa_RPCMuonNormalisation_v9; //!
   TBranch *b_AlCa_LumiPixels_v7; //!
   TBranch *b_AlCa_LumiPixels_ZeroBias_v4; //!
   TBranch *b_AlCa_LumiPixels_Random_v1; //!
   TBranch *b_HLT_Activity_Ecal_SC7_v13; //!
   TBranch *b_HLT_L1SingleJet16_v7; //!
   TBranch *b_HLT_L1SingleJet36_v7; //!



   // Autogenerated from ConfDB - Prescale TBranch
   TBranch *b_HLT_PFJet40_v6_Prescl; //!
   TBranch *b_HLT_PFJet80_v6_Prescl; //!
   TBranch *b_HLT_PFJet140_v6_Prescl; //!
   TBranch *b_HLT_PFJet200_v6_Prescl; //!
   TBranch *b_HLT_PFJet260_v6_Prescl; //!
   TBranch *b_HLT_PFJet320_v6_Prescl; //!
   TBranch *b_HLT_Jet370_NoJetID_v14_Prescl; //!
   TBranch *b_HLT_PFJet400_v6_Prescl; //!
   TBranch *b_HLT_MonoCentralPFJet80_PFMETnoMu105_NHEF0p95_v1_Prescl; //!
   TBranch *b_HLT_SingleForJet25_v3_Prescl; //!
   TBranch *b_HLT_SingleForJet15_v3_Prescl; //!
   TBranch *b_HLT_DiPFJetAve40_v7_Prescl; //!
   TBranch *b_HLT_DiPFJetAve80_v7_Prescl; //!
   TBranch *b_HLT_DiPFJetAve140_v7_Prescl; //!
   TBranch *b_HLT_DiPFJetAve200_v7_Prescl; //!
   TBranch *b_HLT_DiPFJetAve260_v7_Prescl; //!
   TBranch *b_HLT_DiPFJetAve320_v7_Prescl; //!
   TBranch *b_HLT_DiPFJetAve400_v7_Prescl; //!
   TBranch *b_HLT_FatDiPFJetMass750_DR1p1_Deta1p5_v6_Prescl; //!
   TBranch *b_HLT_DoubleJet20_ForwardBackward_v3_Prescl; //!
   TBranch *b_HLT_DiJet80_DiJet60_DiJet20_v3_Prescl; //!
   TBranch *b_HLT_DiPFJet40_PFMETnoMu65_MJJ800VBF_AllJets_v6_Prescl; //!
   TBranch *b_HLT_DiPFJet40_PFMETnoMu65_MJJ600VBF_LeadingJets_v6_Prescl; //!
   TBranch *b_HLT_DiJet40Eta2p6_BTagIP3DFastPV_v5_Prescl; //!
   TBranch *b_HLT_DiJet80Eta2p6_BTagIP3DFastPVLoose_v5_Prescl; //!
   TBranch *b_HLT_Jet60Eta1p7_Jet53Eta1p7_DiBTagIP3DFastPV_v5_Prescl; //!
   TBranch *b_HLT_Jet80Eta1p7_Jet70Eta1p7_DiBTagIP3DFastPV_v5_Prescl; //!
   TBranch *b_HLT_Jet160Eta2p4_Jet120Eta2p4_DiBTagIP3DFastPVLoose_v5_Prescl; //!
   TBranch *b_HLT_QuadJet50_v3_Prescl; //!
   TBranch *b_HLT_QuadJet50_Jet20_v2_Prescl; //!
   TBranch *b_HLT_QuadJet60_DiJet20_v3_Prescl; //!
   TBranch *b_HLT_QuadJet70_v3_Prescl; //!
   TBranch *b_HLT_QuadJet80_v3_Prescl; //!
   TBranch *b_HLT_QuadJet90_v3_Prescl; //!
   TBranch *b_HLT_QuadJet75_55_35_20_BTagIP_VBF_v4_Prescl; //!
   TBranch *b_HLT_QuadJet75_55_38_20_BTagIP_VBF_v4_Prescl; //!
   TBranch *b_HLT_QuadPFJet78_61_44_31_BTagCSV_VBF_v2_Prescl; //!
   TBranch *b_HLT_QuadPFJet82_65_48_35_BTagCSV_VBF_v2_Prescl; //!
   TBranch *b_HLT_SixJet35_v3_Prescl; //!
   TBranch *b_HLT_SixJet45_v3_Prescl; //!
   TBranch *b_HLT_SixJet50_v3_Prescl; //!
   TBranch *b_HLT_EightJet30_eta3p0_v2_Prescl; //!
   TBranch *b_HLT_EightJet35_eta3p0_v2_Prescl; //!
   TBranch *b_HLT_ExclDiJet35_HFOR_v3_Prescl; //!
   TBranch *b_HLT_ExclDiJet35_HFAND_v3_Prescl; //!
   TBranch *b_HLT_ExclDiJet80_HFAND_v3_Prescl; //!
   TBranch *b_HLT_JetE30_NoBPTX_v13_Prescl; //!
   TBranch *b_HLT_JetE30_NoBPTX3BX_NoHalo_v14_Prescl; //!
   TBranch *b_HLT_JetE50_NoBPTX3BX_NoHalo_v11_Prescl; //!
   TBranch *b_HLT_JetE70_NoBPTX3BX_NoHalo_v3_Prescl; //!
   TBranch *b_HLT_HT200_AlphaT0p57_v6_Prescl; //!
   TBranch *b_HLT_HT200_v4_Prescl; //!
   TBranch *b_HLT_HT250_AlphaT0p55_v5_Prescl; //!
   TBranch *b_HLT_HT250_AlphaT0p57_v5_Prescl; //!
   TBranch *b_HLT_HT250_v4_Prescl; //!
   TBranch *b_HLT_HT300_AlphaT0p53_v5_Prescl; //!
   TBranch *b_HLT_HT300_AlphaT0p54_v11_Prescl; //!
   TBranch *b_HLT_HT300_v4_Prescl; //!
   TBranch *b_HLT_HT300_DoubleDisplacedPFJet60_v6_Prescl; //!
   TBranch *b_HLT_HT300_DoubleDisplacedPFJet60_ChgFraction10_v6_Prescl; //!
   TBranch *b_HLT_HT300_SingleDisplacedPFJet60_v6_Prescl; //!
   TBranch *b_HLT_HT300_SingleDisplacedPFJet60_ChgFraction10_v6_Prescl; //!
   TBranch *b_HLT_HT350_v4_Prescl; //!
   TBranch *b_HLT_HT350_AlphaT0p52_v5_Prescl; //!
   TBranch *b_HLT_HT350_AlphaT0p53_v16_Prescl; //!
   TBranch *b_HLT_HT400_v4_Prescl; //!
   TBranch *b_HLT_HT400_AlphaT0p51_v16_Prescl; //!
   TBranch *b_HLT_HT400_AlphaT0p52_v11_Prescl; //!
   TBranch *b_HLT_HT450_AlphaT0p51_v11_Prescl; //!
   TBranch *b_HLT_HT450_v4_Prescl; //!
   TBranch *b_HLT_HT500_v4_Prescl; //!
   TBranch *b_HLT_HT550_v4_Prescl; //!
   TBranch *b_HLT_HT650_v4_Prescl; //!
   TBranch *b_HLT_HT650_Track50_dEdx3p6_v7_Prescl; //!
   TBranch *b_HLT_HT650_Track60_dEdx3p7_v7_Prescl; //!
   TBranch *b_HLT_HT750_v4_Prescl; //!
   TBranch *b_HLT_PFNoPUHT350_v1_Prescl; //!
   TBranch *b_HLT_PFNoPUHT650_v1_Prescl; //!
   TBranch *b_HLT_PFNoPUHT650_DiCentralPFNoPUJet80_CenPFNoPUJet40_v1_Prescl; //!
   TBranch *b_HLT_PFNoPUHT700_v1_Prescl; //!
   TBranch *b_HLT_PFNoPUHT750_v1_Prescl; //!
   TBranch *b_HLT_PFMET150_v5_Prescl; //!
   TBranch *b_HLT_PFMET180_v5_Prescl; //!
   TBranch *b_HLT_DiCentralJetSumpT100_dPhi05_DiCentralPFJet60_25_PFMET100_HBHENoiseCleaned_v2_Prescl; //!
   TBranch *b_HLT_DiCentralPFJet30_PFMET80_v3_Prescl; //!
   TBranch *b_HLT_DiCentralPFNoPUJet50_PFMETORPFMETNoMu80_v1_Prescl; //!
   TBranch *b_HLT_DiCentralPFJet30_PFMET80_BTagCSV07_v2_Prescl; //!
   TBranch *b_HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05d03_v2_Prescl; //!
   TBranch *b_HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05d05_v2_Prescl; //!
   TBranch *b_HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05_v2_Prescl; //!
   TBranch *b_HLT_MET80_v4_Prescl; //!
   TBranch *b_HLT_MET80_Track50_dEdx3p6_v5_Prescl; //!
   TBranch *b_HLT_MET80_Track60_dEdx3p7_v5_Prescl; //!
   TBranch *b_HLT_MET120_v11_Prescl; //!
   TBranch *b_HLT_MET120_HBHENoiseCleaned_v4_Prescl; //!
   TBranch *b_HLT_MET200_v11_Prescl; //!
   TBranch *b_HLT_MET200_HBHENoiseCleaned_v4_Prescl; //!
   TBranch *b_HLT_MET300_v3_Prescl; //!
   TBranch *b_HLT_MET300_HBHENoiseCleaned_v4_Prescl; //!
   TBranch *b_HLT_MET400_v6_Prescl; //!
   TBranch *b_HLT_MET400_HBHENoiseCleaned_v4_Prescl; //!
   TBranch *b_HLT_L1SingleMuOpen_v7_Prescl; //!
   TBranch *b_HLT_L1SingleMu12_v2_Prescl; //!
   TBranch *b_HLT_L2Mu70_eta2p1_PFMET55_v2_Prescl; //!
   TBranch *b_HLT_L2Mu70_eta2p1_PFMET60_v2_Prescl; //!
   TBranch *b_HLT_L2Mu20_eta2p1_NoVertex_v2_Prescl; //!
   TBranch *b_HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo_v3_Prescl; //!
   TBranch *b_HLT_L2Mu20_NoVertex_2Cha_NoBPTX3BX_NoHalo_v1_Prescl; //!
   TBranch *b_HLT_L2Mu30_NoVertex_2Cha_NoBPTX3BX_NoHalo_v1_Prescl; //!
   TBranch *b_HLT_L2TripleMu10_0_0_NoVertex_PFJet40Neutral_v5_Prescl; //!
   TBranch *b_HLT_DoubleDisplacedMu4_DiPFJet40Neutral_v5_Prescl; //!
   TBranch *b_HLT_Mu5_v19_Prescl; //!
   TBranch *b_HLT_Mu8_v17_Prescl; //!
   TBranch *b_HLT_Mu12_v17_Prescl; //!
   TBranch *b_HLT_Mu17_v4_Prescl; //!
   TBranch *b_HLT_Mu12_eta2p1_L1Mu10erJetC12WdEtaPhi1DiJetsC_v4_Prescl; //!
   TBranch *b_HLT_Mu15_eta2p1_v4_Prescl; //!
   TBranch *b_HLT_Mu24_v15_Prescl; //!
   TBranch *b_HLT_Mu24_eta2p1_v4_Prescl; //!
   TBranch *b_HLT_Mu30_v15_Prescl; //!
   TBranch *b_HLT_Mu30_eta2p1_v4_Prescl; //!
   TBranch *b_HLT_Mu40_v13_Prescl; //!
   TBranch *b_HLT_Mu40_eta2p1_v10_Prescl; //!
   TBranch *b_HLT_Mu50_eta2p1_v7_Prescl; //!
   TBranch *b_HLT_RelIso1p0Mu5_v5_Prescl; //!
   TBranch *b_HLT_RelIso1p0Mu20_v2_Prescl; //!
   TBranch *b_HLT_IsoMu15_eta2p1_L1ETM20_v6_Prescl; //!
   TBranch *b_HLT_IsoMu20_eta2p1_v6_Prescl; //!
   TBranch *b_HLT_IsoMu24_v16_Prescl; //!
   TBranch *b_HLT_IsoMu24_eta2p1_v14_Prescl; //!
   TBranch *b_HLT_IsoMu30_v10_Prescl; //!
   TBranch *b_HLT_IsoMu30_eta2p1_v14_Prescl; //!
   TBranch *b_HLT_IsoMu34_eta2p1_v12_Prescl; //!
   TBranch *b_HLT_IsoMu40_eta2p1_v9_Prescl; //!
   TBranch *b_HLT_Mu40_eta2p1_Track50_dEdx3p6_v4_Prescl; //!
   TBranch *b_HLT_Mu40_eta2p1_Track60_dEdx3p7_v4_Prescl; //!
   TBranch *b_HLT_L2DoubleMu23_NoVertex_v11_Prescl; //!
   TBranch *b_HLT_L2DoubleMu23_NoVertex_2Cha_Angle2p5_v3_Prescl; //!
   TBranch *b_HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_v3_Prescl; //!
   TBranch *b_HLT_DoubleMu11_Acoplanarity03_v4_Prescl; //!
   TBranch *b_HLT_DoubleMu4_Jpsi_Displaced_v10_Prescl; //!
   TBranch *b_HLT_DoubleMu4_JpsiTk_Displaced_v4_Prescl; //!
   TBranch *b_HLT_DoubleMu3_4_Dimuon5_Bs_Central_v3_Prescl; //!
   TBranch *b_HLT_DoubleMu3p5_4_Dimuon5_Bs_Central_v3_Prescl; //!
   TBranch *b_HLT_DoubleMu4_Dimuon7_Bs_Forward_v3_Prescl; //!
   TBranch *b_HLT_DoubleMu3p5_LowMass_Displaced_v4_Prescl; //!
   TBranch *b_HLT_DoubleMu3p5_LowMassNonResonant_Displaced_v4_Prescl; //!
   TBranch *b_HLT_Dimuon0_Jpsi_v15_Prescl; //!
   TBranch *b_HLT_Dimuon0_Jpsi_NoVertexing_v12_Prescl; //!
   TBranch *b_HLT_Dimuon0_Upsilon_v15_Prescl; //!
   TBranch *b_HLT_Dimuon0_PsiPrime_v4_Prescl; //!
   TBranch *b_HLT_Dimuon5_Upsilon_v4_Prescl; //!
   TBranch *b_HLT_Dimuon5_PsiPrime_v4_Prescl; //!
   TBranch *b_HLT_Dimuon7_Upsilon_v5_Prescl; //!
   TBranch *b_HLT_Dimuon7_PsiPrime_v1_Prescl; //!
   TBranch *b_HLT_Dimuon8_Jpsi_v5_Prescl; //!
   TBranch *b_HLT_Dimuon8_Upsilon_v4_Prescl; //!
   TBranch *b_HLT_Dimuon10_Jpsi_v4_Prescl; //!
   TBranch *b_HLT_Dimuon11_Upsilon_v4_Prescl; //!
   TBranch *b_HLT_Dimuon0_Jpsi_Muon_v16_Prescl; //!
   TBranch *b_HLT_Dimuon0_Upsilon_Muon_v16_Prescl; //!
   TBranch *b_HLT_Dimuon3p5_SameSign_v4_Prescl; //!
   TBranch *b_HLT_DoubleMu4_Acoplanarity03_v4_Prescl; //!
   TBranch *b_HLT_Tau2Mu_ItTrack_v4_Prescl; //!
   TBranch *b_HLT_Mu13_Mu8_v18_Prescl; //!
   TBranch *b_HLT_Mu17_Mu8_v18_Prescl; //!
   TBranch *b_HLT_Mu17_TkMu8_v11_Prescl; //!
   TBranch *b_HLT_Mu22_TkMu8_v7_Prescl; //!
   TBranch *b_HLT_Mu22_TkMu22_v7_Prescl; //!
   TBranch *b_HLT_TripleMu5_v18_Prescl; //!
   TBranch *b_HLT_DoubleMu5_IsoMu5_v19_Prescl; //!
   TBranch *b_HLT_Mu5_L2Mu3_Jpsi_v5_Prescl; //!
   TBranch *b_HLT_Mu5_Track2_Jpsi_v19_Prescl; //!
   TBranch *b_HLT_Mu5_Track3p5_Jpsi_v5_Prescl; //!
   TBranch *b_HLT_Mu7_Track7_Jpsi_v19_Prescl; //!
   TBranch *b_HLT_Photon20_CaloIdVL_v4_Prescl; //!
   TBranch *b_HLT_Photon20_CaloIdVL_IsoL_v16_Prescl; //!
   TBranch *b_HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_v5_Prescl; //!
   TBranch *b_HLT_Photon26_Photon18_v12_Prescl; //!
   TBranch *b_HLT_Photon26_R9Id85_Photon18_R9Id85_Mass60_v4_Prescl; //!
   TBranch *b_HLT_Photon26_R9Id85_Photon18_CaloId10_Iso50_Mass60_v6_Prescl; //!
   TBranch *b_HLT_Photon26_CaloId10_Iso50_Photon18_R9Id85_Mass60_v6_Prescl; //!
   TBranch *b_HLT_Photon26_CaloId10_Iso50_Photon18_CaloId10_Iso50_Mass60_v6_Prescl; //!
   TBranch *b_HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass60_v6_Prescl; //!
   TBranch *b_HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass70_v2_Prescl; //!
   TBranch *b_HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_v5_Prescl; //!
   TBranch *b_HLT_Photon30_CaloIdVL_v14_Prescl; //!
   TBranch *b_HLT_Photon30_CaloIdVL_IsoL_v19_Prescl; //!
   TBranch *b_HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_v5_Prescl; //!
   TBranch *b_HLT_Photon36_Photon22_v6_Prescl; //!
   TBranch *b_HLT_Photon36_R9Id85_Photon22_R9Id85_v4_Prescl; //!
   TBranch *b_HLT_Photon36_R9Id85_Photon22_CaloId10_Iso50_v6_Prescl; //!
   TBranch *b_HLT_Photon36_CaloId10_Iso50_Photon22_R9Id85_v6_Prescl; //!
   TBranch *b_HLT_Photon36_CaloId10_Iso50_Photon22_CaloId10_Iso50_v6_Prescl; //!
   TBranch *b_HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_R9Id85_OR_CaloId10_Iso50_v6_Prescl; //!
   TBranch *b_HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_v5_Prescl; //!
   TBranch *b_HLT_Photon50_CaloIdVL_v10_Prescl; //!
   TBranch *b_HLT_Photon50_CaloIdVL_IsoL_v17_Prescl; //!
   TBranch *b_HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_v5_Prescl; //!
   TBranch *b_HLT_Photon60_CaloIdL_MHT70_v9_Prescl; //!
   TBranch *b_HLT_Photon60_CaloIdL_HT300_v2_Prescl; //!
   TBranch *b_HLT_Photon70_CaloIdXL_PFNoPUHT400_v1_Prescl; //!
   TBranch *b_HLT_Photon70_CaloIdXL_PFNoPUHT500_v1_Prescl; //!
   TBranch *b_HLT_Photon70_CaloIdXL_PFMET100_v5_Prescl; //!
   TBranch *b_HLT_Photon75_CaloIdVL_v13_Prescl; //!
   TBranch *b_HLT_Photon75_CaloIdVL_IsoL_v18_Prescl; //!
   TBranch *b_HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_v5_Prescl; //!
   TBranch *b_HLT_Photon90_CaloIdVL_v10_Prescl; //!
   TBranch *b_HLT_Photon90_CaloIdVL_IsoL_v15_Prescl; //!
   TBranch *b_HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_v5_Prescl; //!
   TBranch *b_HLT_DisplacedPhoton65_CaloIdVL_IsoL_PFMET25_v2_Prescl; //!
   TBranch *b_HLT_DisplacedPhoton65EBOnly_CaloIdVL_IsoL_PFMET30_v2_Prescl; //!
   TBranch *b_HLT_Photon135_v7_Prescl; //!
   TBranch *b_HLT_Photon150_v4_Prescl; //!
   TBranch *b_HLT_Photon160_v4_Prescl; //!
   TBranch *b_HLT_Photon300_NoHE_v5_Prescl; //!
   TBranch *b_HLT_DoublePhoton48_HEVT_v8_Prescl; //!
   TBranch *b_HLT_DoublePhoton53_HEVT_v2_Prescl; //!
   TBranch *b_HLT_DoublePhoton70_v6_Prescl; //!
   TBranch *b_HLT_DoublePhoton80_v7_Prescl; //!
   TBranch *b_HLT_DoublePhoton5_IsoVL_CEP_v16_Prescl; //!
   TBranch *b_HLT_L1SingleEG5_v6_Prescl; //!
   TBranch *b_HLT_L1SingleEG12_v6_Prescl; //!
   TBranch *b_HLT_L1DoubleEG3_FwdVeto_v2_Prescl; //!
   TBranch *b_HLT_L1ETM30_v2_Prescl; //!
   TBranch *b_HLT_L1ETM40_v2_Prescl; //!
   TBranch *b_HLT_L1ETM70_v2_Prescl; //!
   TBranch *b_HLT_L1ETM100_v2_Prescl; //!
   TBranch *b_HLT_Ele8_CaloIdT_TrkIdVL_v5_Prescl; //!
   TBranch *b_HLT_Ele8_CaloIdT_TrkIdVL_EG7_v2_Prescl; //!
   TBranch *b_HLT_Ele8_CaloIdT_TrkIdVL_Jet30_v5_Prescl; //!
   TBranch *b_HLT_Ele8_CaloIdL_CaloIsoVL_v17_Prescl; //!
   TBranch *b_HLT_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v15_Prescl; //!
   TBranch *b_HLT_Ele17_CaloIdL_CaloIsoVL_v17_Prescl; //!
   TBranch *b_HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v6_Prescl; //!
   TBranch *b_HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v18_Prescl; //!
   TBranch *b_HLT_Ele17_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_Ele8_Mass50_v6_Prescl; //!
   TBranch *b_HLT_Ele20_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_SC4_Mass50_v6_Prescl; //!
   TBranch *b_HLT_Ele22_CaloIdL_CaloIsoVL_v6_Prescl; //!
   TBranch *b_HLT_Ele27_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_v11_Prescl; //!
   TBranch *b_HLT_Ele27_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele15_CaloIdT_CaloIsoVL_trackless_v7_Prescl; //!
   TBranch *b_HLT_Ele27_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_HFT15_v7_Prescl; //!
   TBranch *b_HLT_Ele23_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_HFT30_v7_Prescl; //!
   TBranch *b_HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet30_v2_Prescl; //!
   TBranch *b_HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet50_40_30_v2_Prescl; //!
   TBranch *b_HLT_Ele27_WP80_v11_Prescl; //!
   TBranch *b_HLT_Ele27_WP80_PFMET_MT50_v5_Prescl; //!
   TBranch *b_HLT_Ele30_CaloIdVT_TrkIdT_v6_Prescl; //!
   TBranch *b_HLT_Ele32_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_v11_Prescl; //!
   TBranch *b_HLT_Ele32_CaloIdT_CaloIsoT_TrkIdT_TrkIsoT_SC17_Mass50_v6_Prescl; //!
   TBranch *b_HLT_Ele80_CaloIdVT_GsfTrkIdT_v2_Prescl; //!
   TBranch *b_HLT_Ele90_CaloIdVT_GsfTrkIdT_v2_Prescl; //!
   TBranch *b_HLT_DoubleEle8_CaloIdT_TrkIdVL_v12_Prescl; //!
   TBranch *b_HLT_DoubleEle33_CaloIdL_v14_Prescl; //!
   TBranch *b_HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v7_Prescl; //!
   TBranch *b_HLT_DoubleEle33_CaloIdT_v10_Prescl; //!
   TBranch *b_HLT_Ele15_Ele8_Ele5_CaloIdL_TrkIdVL_v6_Prescl; //!
   TBranch *b_HLT_LooseIsoPFTau35_Trk20_Prong1_v7_Prescl; //!
   TBranch *b_HLT_LooseIsoPFTau35_Trk20_Prong1_MET70_v7_Prescl; //!
   TBranch *b_HLT_LooseIsoPFTau35_Trk20_Prong1_MET75_v7_Prescl; //!
   TBranch *b_HLT_IsoMu15_eta2p1_LooseIsoPFTau35_Trk20_Prong1_L1ETM20_v7_Prescl; //!
   TBranch *b_HLT_DoubleMediumIsoPFTau30_Trk1_eta2p1_Jet30_v1_Prescl; //!
   TBranch *b_HLT_DoubleMediumIsoPFTau30_Trk1_eta2p1_v1_Prescl; //!
   TBranch *b_HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Prong1_v1_Prescl; //!
   TBranch *b_HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_v1_Prescl; //!
   TBranch *b_HLT_IsoMu18_eta2p1_MediumIsoPFTau25_Trk1_eta2p1_v1_Prescl; //!
   TBranch *b_HLT_BTagMu_DiJet20_Mu5_v4_Prescl; //!
   TBranch *b_HLT_BTagMu_DiJet40_Mu5_v4_Prescl; //!
   TBranch *b_HLT_BTagMu_DiJet70_Mu5_v4_Prescl; //!
   TBranch *b_HLT_BTagMu_DiJet110_Mu5_v4_Prescl; //!
   TBranch *b_HLT_BTagMu_Jet300_Mu5_v4_Prescl; //!
   TBranch *b_HLT_Mu7_Ele7_CaloIdT_CaloIsoVL_v6_Prescl; //!
   TBranch *b_HLT_Mu8_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v8_Prescl; //!
   TBranch *b_HLT_Mu8_DiJet30_v5_Prescl; //!
   TBranch *b_HLT_Mu8_TriJet30_v5_Prescl; //!
   TBranch *b_HLT_Mu8_QuadJet30_v5_Prescl; //!
   TBranch *b_HLT_IsoMu12_DoubleCentralJet65_v2_Prescl; //!
   TBranch *b_HLT_Mu15_eta2p1_L1ETM20_v4_Prescl; //!
   TBranch *b_HLT_Mu24_PFJet30_PFJet25_Deta3_CentralPFJet25_v2_Prescl; //!
   TBranch *b_HLT_Mu24_CentralPFJet30_CentralPFJet25_v2_Prescl; //!
   TBranch *b_HLT_IsoMu24_PFJet30_PFJet25_Deta3_CentralPFJet25_v2_Prescl; //!
   TBranch *b_HLT_IsoMu24_CentralPFJet30_CentralPFJet25_v2_Prescl; //!
   TBranch *b_HLT_IsoMu24_CentralPFJet30_CentralPFJet25_PFMET20_v2_Prescl; //!
   TBranch *b_HLT_Ele32_WP80_PFJet30_PFJet25_Deta3_v2_Prescl; //!
   TBranch *b_HLT_Ele32_WP80_PFJet30_PFJet25_Deta3_CentralPFJet30_v2_Prescl; //!
   TBranch *b_HLT_Ele32_WP80_CentralPFJet35_CentralPFJet25_v2_Prescl; //!
   TBranch *b_HLT_Ele32_WP80_CentralPFJet35_CentralPFJet25_PFMET20_v2_Prescl; //!
   TBranch *b_HLT_IsoMu17_eta2p1_CentralPFNoPUJet30_BTagIPIter_v2_Prescl; //!
   TBranch *b_HLT_IsoMu17_eta2p1_CentralPFNoPUJet30_v2_Prescl; //!
   TBranch *b_HLT_IsoMu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2_Prescl; //!
   TBranch *b_HLT_Mu17_eta2p1_CentralPFNoPUJet30_BTagIPIter_v2_Prescl; //!
   TBranch *b_HLT_Mu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2_Prescl; //!
   TBranch *b_HLT_IsoMu20_WCandPt80_v2_Prescl; //!
   TBranch *b_HLT_Mu17_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v8_Prescl; //!
   TBranch *b_HLT_Mu12_eta2p1_DiCentral_40_20_DiBTagIP3D1stTrack_v4_Prescl; //!
   TBranch *b_HLT_Mu12_eta2p1_DiCentral_40_20_BTagIP3D1stTrack_v4_Prescl; //!
   TBranch *b_HLT_Mu12_eta2p1_DiCentral_40_20_v4_Prescl; //!
   TBranch *b_HLT_Mu12_eta2p1_DiCentral_20_v4_Prescl; //!
   TBranch *b_HLT_Mu15_eta2p1_TriCentral_40_20_20_DiBTagIP3D1stTrack_v4_Prescl; //!
   TBranch *b_HLT_Mu15_eta2p1_TriCentral_40_20_20_BTagIP3D1stTrack_v4_Prescl; //!
   TBranch *b_HLT_Mu15_eta2p1_TriCentral_40_20_20_v4_Prescl; //!
   TBranch *b_HLT_Mu30_Ele30_CaloIdL_v7_Prescl; //!
   TBranch *b_HLT_IsoMu17_eta2p1_DiCentralPFNoPUJet30_PFNoPUHT350_PFMHT40_v1_Prescl; //!
   TBranch *b_HLT_IsoMu20_eta2p1_CentralPFJet80_v7_Prescl; //!
   TBranch *b_HLT_DoubleRelIso1p0Mu5_Mass8_PFNoPUHT175_v1_Prescl; //!
   TBranch *b_HLT_DoubleRelIso1p0Mu5_Mass8_PFNoPUHT225_v1_Prescl; //!
   TBranch *b_HLT_DoubleMu8_Mass8_PFNoPUHT175_v1_Prescl; //!
   TBranch *b_HLT_DoubleMu8_Mass8_PFNoPUHT225_v1_Prescl; //!
   TBranch *b_HLT_RelIso1p0Mu5_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1_Prescl; //!
   TBranch *b_HLT_RelIso1p0Mu5_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1_Prescl; //!
   TBranch *b_HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1_Prescl; //!
   TBranch *b_HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1_Prescl; //!
   TBranch *b_HLT_PFNoPUHT350_Mu15_PFMET45_v1_Prescl; //!
   TBranch *b_HLT_PFNoPUHT350_Mu15_PFMET50_v1_Prescl; //!
   TBranch *b_HLT_PFNoPUHT400_Mu5_PFMET45_v1_Prescl; //!
   TBranch *b_HLT_PFNoPUHT400_Mu5_PFMET50_v1_Prescl; //!
   TBranch *b_HLT_Mu40_PFNoPUHT350_v1_Prescl; //!
   TBranch *b_HLT_Mu60_PFNoPUHT350_v1_Prescl; //!
   TBranch *b_HLT_Mu40_HT200_v2_Prescl; //!
   TBranch *b_HLT_DoubleMu5_Ele8_CaloIdT_TrkIdVL_v15_Prescl; //!
   TBranch *b_HLT_DoubleMu8_Ele8_CaloIdT_TrkIdVL_v4_Prescl; //!
   TBranch *b_HLT_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Jet30_v6_Prescl; //!
   TBranch *b_HLT_Ele8_CaloIdT_TrkIdT_DiJet30_v16_Prescl; //!
   TBranch *b_HLT_Ele8_CaloIdT_TrkIdT_TriJet30_v16_Prescl; //!
   TBranch *b_HLT_Ele8_CaloIdT_TrkIdT_QuadJet30_v16_Prescl; //!
   TBranch *b_HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Jet30_v6_Prescl; //!
   TBranch *b_HLT_Ele25_CaloIdVT_TrkIdT_TriCentralPFNoPUJet30_30_20_v2_Prescl; //!
   TBranch *b_HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_CentralPFNoPUJet30_v6_Prescl; //!
   TBranch *b_HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2_Prescl; //!
   TBranch *b_HLT_Ele25_CaloIdVL_CaloIsoT_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2_Prescl; //!
   TBranch *b_HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_CentralPFNoPUJet30_BTagIPIter_v7_Prescl; //!
   TBranch *b_HLT_Ele27_WP80_CentralPFJet80_v7_Prescl; //!
   TBranch *b_HLT_Ele27_WP80_WCandPt80_v7_Prescl; //!
   TBranch *b_HLT_Ele30_CaloIdVT_TrkIdT_PFNoPUJet100_PFNoPUJet25_v6_Prescl; //!
   TBranch *b_HLT_Ele30_CaloIdVT_TrkIdT_PFNoPUJet150_PFNoPUJet25_v6_Prescl; //!
   TBranch *b_HLT_DoubleEle8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1_Prescl; //!
   TBranch *b_HLT_DoubleEle8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1_Prescl; //!
   TBranch *b_HLT_DoubleEle10_CaloIdL_TrkIdVL_Ele10_CaloIdT_TrkIdVL_v12_Prescl; //!
   TBranch *b_HLT_TripleEle10_CaloIdL_TrkIdVL_v18_Prescl; //!
   TBranch *b_HLT_RsqMR40_Rsq0p04_v4_Prescl; //!
   TBranch *b_HLT_RsqMR45_Rsq0p09_v3_Prescl; //!
   TBranch *b_HLT_RsqMR55_Rsq0p09_MR150_v4_Prescl; //!
   TBranch *b_HLT_RsqMR60_Rsq0p09_MR150_v4_Prescl; //!
   TBranch *b_HLT_RsqMR65_Rsq0p09_MR150_v3_Prescl; //!
   TBranch *b_HLT_IsoMu12_RsqMR30_Rsq0p04_MR200_v2_Prescl; //!
   TBranch *b_HLT_IsoMu12_RsqMR40_Rsq0p04_MR200_v2_Prescl; //!
   TBranch *b_HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_RsqMR30_Rsq0p04_MR200_v2_Prescl; //!
   TBranch *b_HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_RsqMR40_Rsq0p04_MR200_v2_Prescl; //!
   TBranch *b_HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_DoubleCentralJet65_v2_Prescl; //!
   TBranch *b_HLT_Photon40_CaloIdL_RsqMR35_Rsq0p09_MR150_v4_Prescl; //!
   TBranch *b_HLT_Photon40_CaloIdL_RsqMR40_Rsq0p09_MR150_v4_Prescl; //!
   TBranch *b_HLT_Photon40_CaloIdL_RsqMR45_Rsq0p09_MR150_v4_Prescl; //!
   TBranch *b_HLT_Photon40_CaloIdL_RsqMR50_Rsq0p09_MR150_v4_Prescl; //!
   TBranch *b_HLT_DoublePhoton40_CaloIdL_Rsq0p035_v4_Prescl; //!
   TBranch *b_HLT_DoublePhoton40_CaloIdL_Rsq0p06_v4_Prescl; //!
   TBranch *b_HLT_Mu22_Photon22_CaloIdL_v6_Prescl; //!
   TBranch *b_HLT_Mu8_DoubleEle8_CaloIdT_TrkIdVL_v6_Prescl; //!
   TBranch *b_HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Ele8_CaloIdL_TrkIdVL_v6_Prescl; //!
   TBranch *b_HLT_DoubleMu14_Mass8_PFMET40_v6_Prescl; //!
   TBranch *b_HLT_DoubleMu14_Mass8_PFMET50_v6_Prescl; //!
   TBranch *b_HLT_DoubleEle14_CaloIdT_TrkIdVL_Mass8_PFMET40_v6_Prescl; //!
   TBranch *b_HLT_DoubleEle14_CaloIdT_TrkIdVL_Mass8_PFMET50_v6_Prescl; //!
   TBranch *b_HLT_Mu14_Ele14_CaloIdT_TrkIdVL_Mass8_PFMET40_v6_Prescl; //!
   TBranch *b_HLT_Mu14_Ele14_CaloIdT_TrkIdVL_Mass8_PFMET50_v6_Prescl; //!
   TBranch *b_HLT_PFNoPUHT350_PFMET100_v1_Prescl; //!
   TBranch *b_HLT_PFNoPUHT400_PFMET100_v1_Prescl; //!
   TBranch *b_HLT_CleanPFNoPUHT350_Ele5_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET45_v1_Prescl; //!
   TBranch *b_HLT_CleanPFNoPUHT350_Ele5_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET50_v1_Prescl; //!
   TBranch *b_HLT_CleanPFNoPUHT300_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET45_v1_Prescl; //!
   TBranch *b_HLT_CleanPFNoPUHT300_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET50_v1_Prescl; //!
   TBranch *b_HLT_CleanPFNoPUHT300_Ele40_CaloIdVT_TrkIdT_v1_Prescl; //!
   TBranch *b_HLT_CleanPFNoPUHT300_Ele60_CaloIdVT_TrkIdT_v1_Prescl; //!
   TBranch *b_HLT_Ele5_SC5_Jpsi_Mass2to15_v4_Prescl; //!
   TBranch *b_HLT_DiJet35_MJJ650_AllJets_DEta3p5_VBF_v2_Prescl; //!
   TBranch *b_HLT_DiJet35_MJJ700_AllJets_DEta3p5_VBF_v2_Prescl; //!
   TBranch *b_HLT_DiJet35_MJJ750_AllJets_DEta3p5_VBF_v2_Prescl; //!
   TBranch *b_HLT_Ele22_eta2p1_WP90Rho_LooseIsoPFTau20_v3_Prescl; //!
   TBranch *b_HLT_Ele22_eta2p1_WP90NoIso_LooseIsoPFTau20_v3_Prescl; //!
   TBranch *b_HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v3_Prescl; //!
   TBranch *b_HLT_Mu17_eta2p1_LooseIsoPFTau20_v3_Prescl; //!
   TBranch *b_HLT_PixelTracks_Multiplicity70_v3_Prescl; //!
   TBranch *b_HLT_PixelTracks_Multiplicity80_v12_Prescl; //!
   TBranch *b_HLT_PixelTracks_Multiplicity90_v3_Prescl; //!
   TBranch *b_HLT_BeamGas_HF_Beam1_v5_Prescl; //!
   TBranch *b_HLT_BeamGas_HF_Beam2_v5_Prescl; //!
   TBranch *b_HLT_BeamHalo_v13_Prescl; //!
   TBranch *b_HLT_IsoTrackHE_v15_Prescl; //!
   TBranch *b_HLT_IsoTrackHB_v14_Prescl; //!
   TBranch *b_HLT_HcalPhiSym_v11_Prescl; //!
   TBranch *b_HLT_HcalNZS_v10_Prescl; //!
   TBranch *b_HLT_GlobalRunHPDNoise_v8_Prescl; //!
   TBranch *b_HLT_L1Tech_HBHEHO_totalOR_v6_Prescl; //!
   TBranch *b_HLT_L1Tech_HCAL_HF_single_channel_v4_Prescl; //!
   TBranch *b_HLT_ZeroBias_v7_Prescl; //!
   TBranch *b_HLT_ZeroBiasPixel_DoubleTrack_v2_Prescl; //!
   TBranch *b_HLT_Physics_v5_Prescl; //!
   TBranch *b_HLT_DTCalibration_v2_Prescl; //!
   TBranch *b_HLT_EcalCalibration_v3_Prescl; //!
   TBranch *b_HLT_HcalCalibration_v3_Prescl; //!
   TBranch *b_HLT_TrackerCalibration_v3_Prescl; //!
   TBranch *b_HLT_Random_v2_Prescl; //!
   TBranch *b_HLT_L1SingleMuOpen_AntiBPTX_v7_Prescl; //!
   TBranch *b_HLT_L1TrackerCosmics_v7_Prescl; //!
   TBranch *b_HLT_LogMonitor_v3_Prescl; //!
   TBranch *b_HLT_DTErrors_v3_Prescl; //!
   TBranch *b_HLT_L1DoubleJet36Central_v7_Prescl; //!
   TBranch *b_AlCa_EcalPi0EBonly_v6_Prescl; //!
   TBranch *b_AlCa_EcalPi0EEonly_v6_Prescl; //!
   TBranch *b_AlCa_EcalEtaEBonly_v6_Prescl; //!
   TBranch *b_AlCa_EcalEtaEEonly_v6_Prescl; //!
   TBranch *b_AlCa_EcalPhiSym_v13_Prescl; //!
   TBranch *b_AlCa_RPCMuonNoTriggers_v9_Prescl; //!
   TBranch *b_AlCa_RPCMuonNoHits_v9_Prescl; //!
   TBranch *b_AlCa_RPCMuonNormalisation_v9_Prescl; //!
   TBranch *b_AlCa_LumiPixels_v7_Prescl; //!
   TBranch *b_AlCa_LumiPixels_ZeroBias_v4_Prescl; //!
   TBranch *b_AlCa_LumiPixels_Random_v1_Prescl; //!
   TBranch *b_HLT_Activity_Ecal_SC7_v13_Prescl; //!
   TBranch *b_HLT_L1SingleJet16_v7_Prescl; //!
   TBranch *b_HLT_L1SingleJet36_v7_Prescl; //!


   // Cut on mu quality
   Int_t NL1OpenMu;
   Float_t L1OpenMuPt[10]; //[NL1OpenMu]
   Float_t L1OpenMuE[10]; //[NL1OpenMu]
   Float_t L1OpenMuEta[10]; //[NL1OpenMu]
   Float_t L1OpenMuPhi[10]; //[NL1OpenMu]
   Int_t L1OpenMuIsol[10]; //[NL1OpenMu]
   Int_t L1OpenMuMip[10]; //[NL1OpenMu]
   Int_t L1OpenMuFor[10]; //[NL1OpenMu]
   Int_t L1OpenMuRPC[10]; //[NL1OpenMu]
   Int_t L1OpenMuQal[10]; //[NL1OpenMu]

   Int_t NL1GoodSingleMu;
   Float_t L1GoodSingleMuPt[10]; //[NL1GoodSingleMu]
   Float_t L1GoodSingleMuE[10]; //[NL1GoodSingleMu]
   Float_t L1GoodSingleMuEta[10]; //[NL1GoodSingleMu]
   Float_t L1GoodSingleMuPhi[10]; //[NL1GoodSingleMu]
   Int_t L1GoodSingleMuIsol[10]; //[NL1GoodSingleMu]
   Int_t L1GoodSingleMuMip[10]; //[NL1GoodSingleMu]
   Int_t L1GoodSingleMuFor[10]; //[NL1GoodSingleMu]
   Int_t L1GoodSingleMuRPC[10]; //[NL1GoodSingleMu]
   Int_t L1GoodSingleMuQal[10]; //[NL1GoodSingleMu]

   Int_t NL1GoodDoubleMu;
   Float_t L1GoodDoubleMuPt[10]; //[NL1GoodDoubleMu]
   Float_t L1GoodDoubleMuE[10]; //[NL1GoodDoubleMu]
   Float_t L1GoodDoubleMuEta[10]; //[NL1GoodDoubleMu]
   Float_t L1GoodDoubleMuPhi[10]; //[NL1GoodDoubleMu]
   Int_t L1GoodDoubleMuIsol[10]; //[NL1GoodDoubleMu]
   Int_t L1GoodDoubleMuMip[10]; //[NL1GoodDoubleMu]
   Int_t L1GoodDoubleMuFor[10]; //[NL1GoodDoubleMu]
   Int_t L1GoodDoubleMuRPC[10]; //[NL1GoodDoubleMu]
   Int_t L1GoodDoubleMuQal[10]; //[NL1GoodDoubleMu]

   /*   TH1F *hEta[10][2][2]; //kNbInstances, kNbStages, kNbCuts */
   /*   TH1F *hPt[10][2][2]; */
   /*   TH1F *hHits[10][2][2]; */
   /*   TH1F *hNormChi2[10][2][2]; */
   /*   TH1F *hDxy[10][2][2]; */
   /*   TH1F *hDz[10][2][2]; */
   /*   TH1F *hP[10][2][2]; */

   /*   TH1F *hOniaEta[10][2][4]; */
   /*   TH1F *hOniaRap[10][2][4]; */
   /*   TH1F *hOniaPt[10][2][4]; */
   /*   TH1F *hOniaP[10][2][4]; */
   /*   TH1F *hOniaMass[10][2][4]; */
   /*   TH2F *hOniaEtaPt[10][2][4]; */
   /*   TH2F *hOniaRapP[10][2][4]; */

   /*   TH1F *hNCand[10][2]; */
   /*   TH1F *hPixCanddr[10]; */
   /*   TH1F *hPixCandEta[10]; */
   /*   TH1F *hPixCandPt[10]; */
   /*   TH1F *hPixCandP[10]; */

   OHltTree(TTree *tree=0, OHltMenu *menu=0);
   
   virtual ~OHltTree();
   
   virtual Bool_t Notify();
   
   virtual void Init(TTree *tree);

   inline Int_t GetEntry(Long64_t entry);
   
   inline Long64_t LoadTree(Long64_t entry);
   
   inline void SetMapL1BitOfStandardHLTPath(OHltMenu *menu);
   
   inline void SetMapL1SeedsOfStandardHLTPath(OHltMenu *menu);
   
   inline void SetMapL1BitOfStandardHLTPathUsingLogicParser(
         OHltMenu *menu,
         int nentry);
   
   inline void ApplyL1Prescales(
         OHltMenu *menu,
         OHltConfig *cfg,
         OHltRateCounter *rc);
   
   inline void RemoveEGOverlaps();
   
   inline void SetL1MuonQuality();
   
   inline void SetOpenL1Bits();
   
   bool passPreFilterLogicParser(TString, int);

   void Loop(
         OHltRateCounter *rc,
         OHltConfig *cfg,
         OHltMenu *menu,
         int pID,
         float &Den,
         TH1F* &h1,
         TH1F* &h2,
         TH1F* &h3,
         TH1F* &h4,
         SampleDiagnostics& primaryDatasetsDiagnostics);

   void PlotOHltEffCurves(
         OHltConfig *cfg,
         TString hlteffmode,
         TString ohltobject,
         TH1F* &h1,
         TH1F* &h2,
         TH1F* &h3,
         TH1F* &h4);
   
   void CheckOpenHlt(
         OHltConfig *cfg,
         OHltMenu *menu,
         OHltRateCounter *rc,
         int it);
   
   void PrintOhltVariables(int level, int type);
   
   int OpenHltPFTauPassedNoMuon(
         float Et,
         float L25TrkPt,
         float L3TrkIso,
         float L3GammaIso);
   
   int OpenHltPFTauPassedNoEle(
         float Et,
         float L25TrkPt,
         int L3TrkIso,
         int L3GammaIso);
   
   int OpenHltTauMuonMatching(float eta, float phi);
   
   int OpenHltTauEleMatching(float eta, float phi);

   int OpenHltTauMuonMatching_wMuonID(float eta, float phi, double ptl1, double ptl2, double ptl3, double dr, int iso);

   int OpenHltTauEleMatching_wEleID(float eta, float phi, float Et, int L1iso,
				    float Tisobarrel, float Tisoendcap,
				    float Tisoratiobarrel, float Tisoratioendcap,
				    float HisooverETbarrel, float HisooverETendcap,
				    float EisooverETbarrel, float EisooverETendcap,
				    float hoverebarrel, float hovereendcap,
				    float clusshapebarrel, float clusshapeendcap,
				    float r9barrel, float r9endcap,
				    float detabarrel, float detaendcap,
				    float dphibarrel, float dphiendcap);

   
   int OpenHltPFTauPassedNoMuonIDNoEleID(float Et,float L25TrkPt, float L3TrkIso, float L3GammaIso,
					 float mu_ptl1, float mu_ptl2, float mu_ptl3, float mu_dr, float mu_iso,
					 float Et_ele, int L1iso,
					 float Tisobarrel, float Tisoendcap,
					 float Tisoratiobarrel, float Tisoratioendcap,
					 float HisooverETbarrel, float HisooverETendcap,
					 float EisooverETbarrel, float EisooverETendcap,
					 float hoverebarrel, float hovereendcap,
					 float clusshapebarrel, float clusshapeendcap,
					 float r9barrel, float r9endcap,
					 float detabarrel, float detaendcap,
					 float dphibarrel, float dphiendcap);

   int OpenHltTauPFToCaloMatching(float eta, float phi);
   
   int OpenHltL1L2TauMatching(
               float eta,
               float phi,
               float tauThr,
               float jetThre);
   
   int OpenHltTauPassed(
         float Et,
         float Eiso,
         float L25Tpt,
         int L25Tiso,
         float L3Tpt,
         int L3Tiso,
         float L1TauEtThr,
         float L1CenJetThr);
   
   int OpenHltTauL2SCPassed(
         float Et,
         float L25Tpt,
         int L25Tiso,
         float L3Tpt,
         int L3Tiso,
         float L1TauEtThr,
         float L1CenJetThr);

   int OpenHltIsoPFTauPassed(
   		float Et,
		float eta,
		float LTpT,
		float L1TauThr,
		float L1CenJetThr);

   int OpenHltTightConeIsoPFTauPassed(
   		float Et,
		float eta,
		float LTpT,
		float L1TauThr,
		float L1CenJetThr);

   int OpenHltLooseIsoPFTauPassed(
                float Et,
                float eta,
                float LTpT,
                float L1_ETMThr,
                float L2TauEtThr,
                int   nprongs);

   int OpenHltTauL2SCMETPassed(
         float Et,
         float L25Tpt,
         int L25Tiso,
         float L3Tpt,
         int L3Tiso,
         float met,
         float L1TauThr,
         float L1CenJetThr);
   
   int OpenHltTauNoMuonPassed(float Et, float L25Tpt, int L3Tiso);
   
   int OpenHlt2Tau1LegL3IsoPassed(
         float Et,
         float L25Tpt,
         int L25Tiso,
         float L3Tpt,
         float L1TauEtThr,
         float L1CenJetThr);
   
   int OpenHltElecTauL2SCPassed(
         float elecEt,
         int elecL1iso,
         float elecTiso,
         float elecHiso,
         float tauEt,
         float tauL25Tpt,
         int tauL25Tiso,
         float tauL3Tpt,
         int tauL3Tiso);
   
   int OpenHlt1ElectronPassed(float Et, int L1iso, float Tiso, float Hiso);
   
   int OpenHlt1Ele1PFTauPassed(
         float Et,
         int L1iso,
         float Tisobarrel,
         float Tisoendcap,
         float Tisoratiobarrel,
         float Tisoratioendcap,
         float HisooverETbarrel,
         float HisooverETendcap,
         float EisooverETbarrel,
         float EisooverETendcap,
         float hoverebarrel,
         float hovereendcap,
         float clusshapebarrel,
         float clusshapeendcap,
         float r9barrel,
         float r9endcap,
         float detabarrel,
         float detaendcap,
         float dphibarrel,
         float dphiendcap,
         float TauEt,
         float TauEta,
         float L25TrkPt,
         float L3TrkIso,
         float L3GammaIso,
         float PFMHTCut,
         float dz);

   /**
    * tells if single electron with given threshold and R9 cut passes
    */
   bool OpenHLT_EleX_R9cut(const float& Et, const float& r9barrel);
   
   float deltaR(
         const float& eta1,
         const float& phi1,
         const float& eta2,
         const float& phi2);
   
   float deltaPhi(const float& phi1, const float& phi2);
   
   float deltaEta(const float& eta1, const float& eta2);
   
   int OpenHlt1ElectronVbfEleIDPassed(
         float Et,
         float L1SeedEt,
         bool iso,
         int& EtMaxIt,
         std::vector<int>* it,
         bool WP80);

   int OpenHltCleanedTriJetPassed(
        float Et1,
        float Et2,
        float Et3,
        float AbsEtaMax,
        bool cor,
        const std::string& algo,
        float Deta,
        float Mjj,
        bool etaOpposite,
        bool jetID,
        std::vector<int> ohEleIts);
   

   int OpenHltCleanedDiJetPassed(
         float Et1,
         float Et2,
         float AbsEtaMax,
         bool cor,
         const std::string& algo,
         float Deta,
         bool etaOpposite,
         bool jetID,
         std::vector<int> ohEleIts);

	
   int OpenHlt1ElectronPassed(float Et,
			      std::map< TString, float> caloId,
			      std::map< TString, float> caloIso,
			      std::map< TString, float> trkId,
			      std::map< TString, float> trkIso
			      );
	
	
   int OpenHlt1ElectronSamHarperPassed(
         float Et,
         int L1iso,
         float Tisobarrel,
         float Tisoendcap,
         float Tisoratiobarrel,
         float Tisoratioendcap,
         float HisooverETbarrel,
         float HisooverETendcap,
         float EisooverETbarrel,
         float EisooverETendcap,
         float hoverebarrel,
         float hovereendcap,
         float clusshapebarrel,
         float clusshapeendcap,
         float r9barrel,
         float r9endcap,
         float detabarrel,
         float detaendcap,
         float dphibarrel,
         float dphiendcap);
   
   std::vector<int> VectorOpenHlt1ElectronSamHarperPassed(
      float Et,
      int L1iso,
      float Tisobarrel,
      float Tisoendcap,
      float Tisoratiobarrel,
      float Tisoratioendcap,
      float HisooverETbarrel,
      float HisooverETendcap,
      float EisooverETbarrel,
      float EisooverETendcap,
      float hoverebarrel,
      float hovereendcap,
      float clusshapebarrel,
      float clusshapeendcap,
      float r9barrel,
      float r9endcap,
      float detabarrel,
      float detaendcap,
      float dphibarrel,
      float dphiendcap);


   int OpenHlt2ElectronsSamHarperPassed(
         float Et,
         int L1iso,
         float Tisobarrel,
         float Tisoendcap,
         float Tisoratiobarrel,
         float Tisoratioendcap,
         float HisooverETbarrel,
         float HisooverETendcap,
         float EisooverETbarrel,
         float EisooverETendcap,
         float hoverebarrel,
         float hovereendcap,
         float clusshapebarrel,
         float clusshapeendcap,
         float r9barrel,
         float r9endcap,
         float detabarrel,
         float detaendcap,
         float dphibarrel,
         float dphiendcap);
   
   int OpenHlt3ElectronsSamHarperPassed(
         float Et,
         int L1iso,
         float Tisobarrel,
         float Tisoendcap,
         float Tisoratiobarrel,
         float Tisoratioendcap,
         float HisooverETbarrel,
         float HisooverETendcap,
         float EisooverETbarrel,
         float EisooverETendcap,
         float hoverebarrel,
         float hovereendcap,
         float clusshapebarrel,
         float clusshapeendcap,
         float r9barrel,
         float r9endcap,
         float detabarrel,
         float detaendcap,
         float dphibarrel,
         float dphiendcap);
   
   int OpenHltGetElectronsSamHarperPassed(
         int* Passed,
         float Et,
         int L1iso,
         float Tisobarrel,
         float Tisoendcap,
         float Tisoratiobarrel,
         float Tisoratioendcap,
         float HisooverETbarrel,
         float HisooverETendcap,
         float EisooverETbarrel,
         float EisooverETendcap,
         float hoverebarrel,
         float hovereendcap,
         float clusshapebarrel,
         float clusshapeendcap,
         float r9barrel,
         float r9endcap,
         float detabarrel,
         float detaendcap,
         float dphibarrel,
         float dphiendcap);
   
   int OpenHlt2ElectronsAsymSamHarperPassed(
         float Et1,
         int L1iso1,
         float Tisobarrel1,
         float Tisoendcap1,
         float Tisoratiobarrel1,
         float Tisoratioendcap1,
         float HisooverETbarrel1,
         float HisooverETendcap1,
         float EisooverETbarrel1,
         float EisooverETendcap1,
         float hoverebarrel1,
         float hovereendcap1,
         float clusshapebarrel1,
         float clusshapeendcap1,
         float r9barrel1,
         float r9endcap1,
         float detabarrel1,
         float detaendcap1,
         float dphibarrel1,
         float dphiendcap1,
         float Et2,
         int L1iso2,
         float Tisobarrel2,
         float Tisoendcap2,
         float Tisoratiobarrel2,
         float Tisoratioendcap2,
         float HisooverETbarrel2,
         float HisooverETendcap2,
         float EisooverETbarrel2,
         float EisooverETendcap2,
         float hoverebarrel2,
         float hovereendcap2,
         float clusshapebarrel2,
         float clusshapeendcap2,
         float r9barrel2,
         float r9endcap2,
         float detabarrel2,
         float detaendcap2,
         float dphibarrel2,
         float dphiendcap2);
   
   int OpenHlt1PhotonSamHarperPassed(
         float Et,
         int L1iso,
         float Tisobarrel,
         float Tisoendcap,
         float Tisoratiobarrel,
         float Tisoratioendcap,
         float HisooverETbarrel,
         float HisooverETendcap,
         float EisooverETbarrel,
         float EisooverETendcap,
         float hoverebarrel,
         float hovereendcap,
         float clusshapebarrel,
         float clusshapeendcap,
         float r9barrel,
         float r9endcap,
         float detabarrel,
         float detaendcap,
         float dphibarrel,
         float dphiendcap);
   
   int OpenHlt1PhotonPassed(
			    float thresholdPhoton,
			    std::map< TString, float> r9Id,
			    std::map< TString, float> caloId,
			    std::map< TString, float> photonIso
			    );

   std::vector<int> VecOpenHlt1PhotonPassed(
			    float thresholdPhoton,
			    std::map< TString, float> r9Id,
			    std::map< TString, float> caloId,
			    std::map< TString, float> photonIso
			    );


   std::vector<int>  VecOpenHlt1EcalActivPassed(
			    float thresholdPhoton,
			    std::map< TString, float> r9Id,
			    std::map< TString, float> caloId,
			    std::map< TString, float> photonIso
			    );
						       

   std::vector<int> VectorOpenHlt1PhotonSamHarperPassed(
         float Et,
         int L1iso,
         float Tisobarrel,
         float Tisoendcap,
         float Tisoratiobarrel,
         float Tisoratioendcap,
         float HisooverETbarrel,
         float HisooverETendcap,
         float EisooverETbarrel,
         float EisooverETendcap,
         float hoverebarrel,
         float hovereendcap,
         float clusshapebarrel,
         float clusshapeendcap,
         float r9barrel,
         float r9endcap,
         float detabarrel,
         float detaendcap,
         float dphibarrel,
         float dphiendcap);

   int OpenHlt1PhotonPassedRA3(
         float Et,
         int L1iso,
         float HisooverETbarrel,
         float HisooverETendcap,
         float EisooverETbarrel,
         float EisooverETendcap,
         float hoverebarrel,
         float hovereendcap,
         float r9barrel,
         float r9endcap);
   
   int OpenHltPhoCuts(
         float e_t,
         float he_eb,
         float he_ee,
         float shape_eb,
         float shape_ee,
         float cal_iso,
         float trk_iso);
   
   int OpenHlt1PhotonPassed(
         float Et,
         int L1iso,
         float Tiso,
         float Eiso,
         float HisoBR,
         float HisoEC);
   
   std::vector<int>  VectorOpenHlt1PhotonPassed(
						float Et, 
						int L1iso, 
						float Tiso, 
						float Eiso, 
						float HisoBR, 
						float HisoEC,
						float HoverE, 
						float R9, 
						float ClusShapEB=999, 
						float ClusShapEC=999);

   std::vector<int> VectorOpenHlt1PhotonPassedEcalActiv(
							float Et, 
							int L1iso, 
							float Tiso, 
							float Eiso, 
							float HisoBR, 
							float HisoEC, 
							float HoverEBR=999,
							float HoverEEC=999, 
							float R9=999, 
							float ClusShapEB=999, 
							float ClusShapEC=999);

   std::vector<int>  VectorOpenHlt1PhotonPassedR9ID(
						    float Et,
						    float R9ID, 
						    int L1iso, 
						    float Tiso, 
						    float Eiso, 
						    float HisoBR, 
						    float HisoEC, 
						    float HoverEBR=999, 
						    float HoverEEC=999,
						    float R9=999, 
						    float ClusShapEB=999, 
						    float ClusShapEC=999);

   std::vector<int>  VectorOpenHlt1PhotonPassedNew(
						   float Et, 
						   int L1iso, 
						   float Tiso, 
						   float Eiso, 
						   float HisoBR, 
						   float HisoEC, 
						   float HoverEBR=999, 
						   float HoverEEC=999, 
						   float R9=999, 
						   float ClusShapEB=999, 
						   float ClusShapEC=999);

   std::vector<int>  VectorOpenHlt1PhotonPassedR9IDEcalActiv(
							     float Et, 
							     float R9ID, 
							     int L1iso, 
							     float Tiso, 
							     float Eiso, 
							     float HisoBR, 
							     float HisoEC, 
							     float HoverEBR=999, 
							     float HoverEEC=999,
							     float R9=999, 
							     float ClusShapEB=999, 
							     float ClusShapEC=999);

   int OpenHlt2PhotonMassWinPassed(
         float Et,
         int L1iso,
         float Tiso,
         float Eiso,
         float HisoBR,
         float HisoEC,
         float massLow,
         float massHigh);
   
   int OpenHlt2ElectronMassWinPassed(
         float Et,
         int L1iso,
         float Hiso,
         float massLow,
         float massHigh);
   
   int OpenHlt2Electron1LegIdPassed(
               float Et,
               int L1iso,
               float Tiso,
               float Hiso);
   
   int OpenHlt1L3MuonPassed(double pt, double eta);
   
   int OpenHlt1MuonPassed(
         double ptl1,
         double ptl2,
         double ptl3,
         double dr,
         int iso,
	 double etal2 = 2.5,
	 double etal3 = 2.5,
	 int minNHits = 0,
	 int minNStats = 0);

   int OpenHlt1MuonPassed(
			  std::vector<double>,
			  double dr,
			  int iso,
			  double etal2 = 2.5,
			  double etal3 = 2.5,
			  int minNHits = 0,
			  int minNStats = 0
			  );

   int OpenHlt2MuonPassed(
         double ptl1,
         double ptl2,
         double ptl3,
         double dr,
         int iso);

   int OpenHlt2MuonOSMassPassed(
	double ptl1,
	double ptl2,
	double ptl3,
	double dr,
	int iso,
	double masslow,
	double masshigh);
   
   int OpenHlt1L2MuonPassed(double ptl1, double ptl2, double dr);

   int OpenHlt1L2MuonNoVertexPassed(double ptl1, double ptl2, double dr); 
   
   int OpenHltMuTrackPassed(
         double ptTrack,
         double pTrack,
         double etaTrack,
         double DxyTrack,
         double DzTrack,
         int NHitsTrack,
         double normChi2Track,
         double *massMinTrack,
         double *massMaxTrack,
         double DzMuonTrack,
         bool checkChargeTrack);
   
   int OpenHltMuPixelPassed(
         double ptPix,
         double pPix,
         double etaPix,
         double DxyPix,
         double DzPix,
         int NHitsPix,
         double normChi2Pix,
         double *massMinPix,
         double *massMaxPix,
         double DzMuonPix,
         bool checkChargePix);
   
   int OpenHltMuTrackPassed_JPsi(
         double ptTrack,
         double pTrack,
         double etaTrack,
         double DxyTrack,
         double DzTrack,
         int NHitsTrack,
         double normChi2Track,
         double *massMinTrack,
         double *massMaxTrack,
         double DzMuonTrack,
         bool checkChargeTrack,
         int histIndex);
   
   int OpenHltMuPixelPassed_JPsi(
         double ptPix,
         double pPix,
         double etaPix,
         double DxyPix,
         double DzPix,
         int NHitsPix,
         double normChi2Pix,
         double *massMinPix,
         double *massMaxPix,
         double DzMuonPix,
         bool checkChargePix,
         int histIndex);
   
   int OpenHltMuTrackPassed_Ups(
         double ptTrack,
         double pTrack,
         double etaTrack,
         double DxyTrack,
         double DzTrack,
         int NHitsTrack,
         double normChi2Track,
         double *massMinTrack,
         double *massMaxTrack,
         double DzMuonTrack,
         bool checkChargeTrack,
         int histIndex);
   
   int OpenHltMuPixelPassed_Ups(
         double ptPix,
         double pPix,
         double etaPix,
         double DxyPix,
         double DzPix,
         int NHitsPix,
         double normChi2Pix,
         double *massMinPix,
         double *massMaxPix,
         double DzMuonPix,
         bool checkChargePix,
         int histIndex);

   bool OpenHltInvMassCutMu(int nMu, const float& invMassCut);   

   bool OpenHltInvMassCutEle(int nEle, const float& invMassCut);   
   
   bool OpenHltInvMassCutEleMu(int nEle, int nMu, const float& invMassCut);   

   int OpenHlt1JetPassed(double pt);
   
   int OpenHlt1JetPassed(double pt, double eta);
   
   int OpenHlt1JetPassed(double pt, double eta, double emfmin, double emfmax);

   bool OpenJetID(int jetindex);
   
   int OpenHlt1CorJetPassed(double pt);
   
   int OpenHlt1CorJetPassed(double pt, double eta);

   int OpenHlt1CorJetPassedNoJetID(double pt);  

   int OpenHlt1PFJetPassed(double pt, double eta); 

   int OpenHltFwdJetPassed(double esum);
   
   int OpenHltFwdCorJetPassed(double esum);
   
   int OpenL1QuadJet8(double jetPt, double jetEta);
   
   int OpenHltDiJetAvePassed(double pt);
   
   int OpenHltCorDiJetAvePassed(double pt);

   int OpenHltDiPFJetAvePassed(double pt);

   int OpenHltQuadJetPassed(double pt);
   
   int OpenHltQuadJetCORPassedPlusTauPFIdNewIso(double pt, double etaJet, double ptTau);

   int OpenHltQuadCorJetPassed(double pt);
   
   int OpenHlt1MuonIsoJetPassed(
         double ptl1,
         double ptl2,
         double ptl3,
         double dr,
         int iso,
         double JetPt,
         double JetEta);
   
   int OpenHltQuadJetPassedPlusTauPFId(double pt, double etaJet, double ptTau);
   
   int OpenHltJRMuonPassed(
         double ptl1,
         double ptl2,
         double ptl3,
         double dr,
         int iso,
         double ptl3hi);
   
   int OpenHltpfMHT(double pfMHTthreshold);

   int OpenHltSumHTPassed(double sumHTthreshold, double jetthreshold);
   
   int OpenHltSumHTPassed(
         double sumHTthreshold,
         double jetthreshold,
         double etajetthreshold);
   
   int OpenHltSumHTPassed(
         double sumHTthreshold,
         double jetthreshold,
         double etajetthreshold,
         int Njetthreshjold);
   
   int OpenHltSumCorHTPassed(double sumHTthreshold, double jetthreshold = 40., double etathreshold=3.0);

   int OpenHltSumFJCorHTPassed(double sumHTthreshold, double jetthreshold = 40., double etathreshold=3.0);

   int OpenHltSumPFHTPassed(double sumPFHTthreshold, double jetthreshold = 40., double etathreshold=3.0);
   
   int OpenHltMHT(double MHTthreshold, double jetthreshold = 30.0, double etathreshold=999.0);
   
   int OpenHltPFMHT(double PFMHTthreshold, double jetthreshold = 30.0, double etathreshold=999.0);

   int OpenHltMHTU(double MHTthreshold, double jetthreshold, double etathreshold=3.0);
   
   int OpenHltMeffU(double Meffthreshold, double jetthreshold, double etathreshold=3.0);
   
   int OpenHltMeff(double Meffthreshold, double jetthreshold, double etathreshold=3.0);
   
   int OpenHltPT12U(double PT12threshold, double jetthreshold);
   
   int OpenHltPT12(double PT12threshold, double jetthreshold);
   
   int OpenHltMhtOverHTPassed(
         double HardJetThreshold,
         double HtJetThreshold,
         double MhtJetThreshold,
         double MHTovHT,
         int NJets);
   
   int OpenHltMhtOverHTPassedHTthresh(double HT, double MHTovHT);

   int OpenHltRBTagPassed(
         float Rmin,
         float MRmin,
         bool MRP,
         int NJmax,
         float jetPt,
	 bool qcd=false,
	 bool pfmht=false);
   
   int OpenHlt1PixelTrackPassed(float minpt, float minsep, float miniso);
   
   int OpenHltHTJetNJPassed(
         double HTthreshold,
         double jetthreshold,
         double etamax,
         int nj);
   
   int OpenHlt1ElectronHTPassed(
         float Et,
         float HT,
         float jetThreshold,
         int L1iso,
         float Tiso,
         float Hiso,
         float dr);
   
   int OpenHlt1ElectronEleIDHTPassed(
         float Et,
         float HT,
         float jetThreshold,
         int L1iso,
         float Tiso,
         float Hiso,
         float dr);
   
   int OpenHltRUPassed(
         float Rmin,
         float MRmin,
         bool MRP,
         int NJmax,
         float jetPt);
   
   int OpenHltRPassed(
         float Rmin,
         float MRmin,
         int NJmax,
         float jetPt);

   int OpenHltRMRPassed(
			float Rmin,
			float MRmin,
			float RMRmin,
			float ROffset,
			float MROffset,
			int NJmax,
			float jetPt,
			float DiJetPt);

   int OpenHlt1BJetPassedEleRemoval(
         float jetEt,
         float jetEta,
         float drcut,
         float discL25,
         float discL3,
         float Et,
         int L1iso,
         float Tisobarrel,
         float Tisoendcap,
         float Tisoratiobarrel,
         float Tisoratioendcap,
         float HisooverETbarrel,
         float HisooverETendcap,
         float EisooverETbarrel,
         float EisooverETendcap,
         float hoverebarrel,
         float hovereendcap,
         float clusshapebarrel,
         float clusshapeendcap,
         float r9barrel,
         float r9endcap,
         float detabarrel,
         float detaendcap,
         float dphibarrel,
         float dphiendcap);

   int OpenHlt1BPFJetPassedEleRemoval(
				      float jetEt,
				      float jetEta,
				      float drcut,
				      float discL3,
				      float Et,
				      int L1iso,
				      float Tisobarrel,
				      float Tisoendcap,
				      float Tisoratiobarrel,
				      float Tisoratioendcap,
				      float HisooverETbarrel,
				      float HisooverETendcap,
				      float EisooverETbarrel,
				      float EisooverETendcap,
				      float hoverebarrel,
				      float hovereendcap,
				      float clusshapebarrel,
				      float clusshapeendcap,
				      float r9barrel,
				      float r9endcap,
				      float detabarrel,
				      float detaendcap,
				      float dphibarrel,
				      float dphiendcap);

   bool OpenHltNCorJetPassedEleRemoval(
	 int N,
         float jetPt,
	 float jetEta,
	 float drcut,
	 float Et,
	 int L1iso,
	 float Tisobarrel,
	 float Tisoendcap,
	 float Tisoratiobarrel,
	 float Tisoratioendcap,
	 float HisooverETbarrel,
	 float HisooverETendcap,
	 float EisooverETbarrel,
	 float EisooverETendcap,
	 float hoverebarrel,
	 float hovereendcap,
	 float clusshapebarrel,
	 float clusshapeendcap,
	 float r9barrel,
	 float r9endcap,
	 float detabarrel,
	 float detaendcap,
	 float dphibarrel,
	 float dphiendcap);

   bool OpenHltNPFJetPassedEleRemoval(
         int N,
         float jetPt,
         float jetEta,
         float drcut,
         float Et,
         int L1iso,
         float Tisobarrel,
         float Tisoendcap,
         float Tisoratiobarrel,
         float Tisoratioendcap,
         float HisooverETbarrel,
         float HisooverETendcap,
         float EisooverETbarrel,
         float EisooverETendcap,
         float hoverebarrel,
         float hovereendcap,
         float clusshapebarrel,
         float clusshapeendcap,
         float r9barrel,
         float r9endcap,
         float detabarrel,
         float detaendcap,
         float dphibarrel,
         float dphiendcap);

   int OpenHltHT_AlphaT(
		double HT, 
		double Beta , 
		double Jet);

   int OpenHltFatJetPassed(
			   float jetPt,
			   float DR,
			   float DEta,
			   float DiFatJetMass);

   int OpenHlt2MuonOSMassDCAPassed(
				   double ptl1,
				   double ptl2,
				   double ptl3,
				   double dr,
				   int iso,
				   double masslow,
				   double masshigh,
				   double etal3,
				   double dimupt,
				   double dca);

   int OpenHlt2MuonOSMassVtxPassed(
				   double ptl1,
				   double ptl2,
				   double ptl3,
				   double dr,
				   int iso,
				   double masslow,
				   double masshigh,
				   double etal3,
				   double dimupt,
				   double dca,
				   double chi2,
				   double cos,
				   double lxysig);

   int OpenHlt2MuonOSMassVtxHiggsPassed(
				   double ptl1,
				   double ptl2,
				   double ptl3,
				   double dr,
				   int iso,
				   double masslow,
				   double masshigh,
				   double etal3,
				   double dimupt,
				   double dca,
				   double chi2,
				   double cos,
				   double lxysig);
    
 
   int OpenHlt3MuonOSMassVtxPassed(
				   double ptl1,
				   double ptl2,
				   double ptl3,
				   double dr,
				   int iso,
				   double masslow,
				   double masshigh,
				   double etal3,
				   double dimupt,
				   double dca,
				   double chi2,
				   double cos,
				   double lxysig);

    bool OpenHltNJetPtPassed(int N, const double& pt);

    bool OpenHltNCentralJetFJPassed(int N, const double& pt);

    bool OpenHltNPFJetPassed(const int N, const double& pt, const double& eta);

    bool OpenHltNTowerEtPassed(int N, const double& Et);

   int readRefPrescaleFromFile(TString st);

   int OpenL1SetSingleJetBit(const float& thresh);

   std::map<TString, std::vector<TString> >& GetL1SeedsOfHLTPathMap()
   {
      return map_L1SeedsOfStandardHLTPath;
   }
   // mapping to all seeds

   int GetNLumiSections()
   {
      return nLumiSections;
   }

   void initEGammaWPMap();

   void initMuThresholdMap();

private:

   int nTrig;
   int nL1Trig;
   int nLumiSections;
   int previousLumiSection;
   int currentLumiSection;
   int nEventsProcessed;
   std::vector<int> triggerBit;
   std::vector<int> previousBitsFired;
   std::vector<int> allOtherBitsFired;
   std::vector<int> BitOfStandardHLTPath;
   std::vector<int> L3MuCandIDForOnia;
   std::vector<int> L3PixelCandIDForOnia;
   std::vector<int> L3MuPixCandIDForOnia;
   std::vector<int> L3PixelCandIDForJPsi;
   std::vector<int> L3MuPixCandIDForJPsi;
   std::vector<int> L3PixelCandIDForUps;
   std::vector<int> L3MuPixCandIDForUps;
   std::map<TString,int> map_BitOfStandardHLTPath;
   std::map<TString,int> map_L1BitOfStandardHLTPath;
   std::map<TString,int> map_RefPrescaleOfStandardHLTPath;

   std::map<TString, std::vector<TString> > map_L1SeedsOfStandardHLTPath; // mapping to all seeds
   std::map<TString, std::vector<int> > map_RpnTokenIdOfStandardHLTPath; // mapping to algo token

   // EGamma triggers working points
   std::map<TString, std::map< TString, float> > map_EGammaCaloId; 
   std::map<TString, std::map< TString, float> > map_EleCaloIso; 
   std::map<TString, std::map< TString, float> > map_EleTrkId; 
   std::map<TString, std::map< TString, float> > map_EleTrkIso;
   std::map<TString, std::map< TString, float> > map_PhotonIso;
   std::map<TString, std::map< TString, float> > map_PhotonR9ID;

   //Mu map
   std::map<double, std::vector<double> > map_muThresholds; 

   TRandom3 random; // for random prescale method
   
   inline int GetIntRandom()
   {
      return (int)(9999999.*random.Rndm());
   }
   
   inline int GetFloatRandom()
   {
      return (9999999.*random.Rndm());
   }

   bool prescaleResponse(
         OHltMenu *menu,
         OHltConfig *cfg,
         OHltRateCounter *rc,
         int i);
   
   bool prescaleResponseL1(
         OHltMenu *menu,
         OHltConfig *cfg,
         OHltRateCounter *rc,
         int i);
   
   bool isInRunLumiblockList(int, int, std::vector < std::vector <int> >);

   int nMissingTriggerWarnings;

   enum e_objType {
      muon,
      electron,
      tau,
      photon,
      jet};
};


#ifdef OHltTree_cxx

OHltTree::OHltTree(TTree *tree, OHltMenu *menu)
{
   random.SetSeed(0);

   std::cout<<"Initialising OHltTree."<<std::endl;
   if (tree == 0)
   {
      std::cerr<<"Error initialising tree!"<<std::endl;
      return;
   }
   if (menu == 0)
   {
      std::cerr<<"Error: no menu!"<<std::endl;
      return;
   }
   Init(tree);

   nMissingTriggerWarnings = 0;

   currentLumiSection = -999;
   previousLumiSection = -999;
   nLumiSections = 0;

   nTrig = menu->GetTriggerSize();
   nL1Trig = menu->GetL1TriggerSize();

   triggerBit.reserve(nTrig);
   previousBitsFired.reserve(nTrig);
   allOtherBitsFired.reserve(nTrig);
   BitOfStandardHLTPath.reserve(nTrig);
   L3MuCandIDForOnia.reserve(10);
   L3PixelCandIDForOnia.reserve(10);
   L3MuPixCandIDForOnia.reserve(10);
   L3PixelCandIDForJPsi.reserve(10);
   L3MuPixCandIDForJPsi.reserve(10);
   L3PixelCandIDForUps.reserve(10);
   L3MuPixCandIDForUps.reserve(10);

   for (int it = 0; it < nTrig; it++)
   {
      triggerBit.push_back(false);
      previousBitsFired.push_back(false);
      allOtherBitsFired.push_back(false);
   }
   for (int ic = 0; ic < 10; ic++)
   {
      L3MuCandIDForOnia.push_back(-1);
      L3PixelCandIDForOnia.push_back(-1);
      L3MuPixCandIDForOnia.push_back(-1);
      L3PixelCandIDForJPsi.push_back(-1);
      L3MuPixCandIDForJPsi.push_back(-1);
      L3PixelCandIDForUps.push_back(-1);
      L3MuPixCandIDForUps.push_back(-1);
   }

   for(int i=0;i<8000;i++)
   {  ohEleL1Dupl[i] = true;}

   for(int i=0;i<8000;i++)
   {  ohPhotL1Dupl[i] = true;}

   for(int i=0;i<8000;i++)
     {  ohEcalActivL1Dupl[i] = true;}

   /*   int binEta = 120; */
   /*   double EtabinMin = -4.0, EtabinMax = 4.0; */

   /*   int binPt = 100; */
   /*   double PtbinMin = 0., PtbinMax = 30.; */

   /*   int binP = 100; */
   /*   double PbinMin = 0., PbinMax = 50.; */

   /*   int binRap = 120; */
   /*   double RapbinMin = -3.0; */
   /*   double RapbinMax = 3.0; */

   /*   int binMass = 240; */
   /*   double MassbinMin = 0.; */
   /*   double MassbinMax = 12.; */

   /*   const char *histIndex[10] = {"Mu0_Track0_Jpsi","Mu1_Track0_Jpsi","Mu1p5_Track0_Jpsi","Mu2_Track0_Jpsi",  */
   /*                            "Mu2p5_Track0_Jpsi","Mu3_Track0_Jpsi","Mu5_Track0_Jpsi", */
   /*                            "Mu0_Track0_Ups","Mu3_Track0_Ups","Mu5_Track0_Ups"}; */

   /*   const char *Track[2] = {"Pixel","Track"}; */
   /*   const char *histIdxCut[4] = {"","_MassCut","_MassChgCut","_MassChgDzMuPixCut"}; */
   /*   //char name[100], title[300]; */

   /*   for(Int_t ihistIdx=0;ihistIdx<10;ihistIdx++){ */

   /*      hPixCanddr[ihistIdx] = new TH1F(Form("h%s_PixCanddr",histIndex[ihistIdx]), */
   /*                                      Form("%s: PixelCand;#DeltaR",histIndex[ihistIdx]),100,0,10); */
   /*      hPixCandEta[ihistIdx] = new TH1F(Form("h%s_PixCandEta",histIndex[ihistIdx]), */
   /*                                       Form("%s: PixelCand;#eta",histIndex[ihistIdx]),binEta,EtabinMin,EtabinMax); */
   /*      hPixCandPt[ihistIdx] = new TH1F(Form("h%s_PixCandPt",histIndex[ihistIdx]), */
   /*                                      Form("%s: PixelCand;p_{T} [GeV/c]",histIndex[ihistIdx]),100,0,10); */
   /*      hPixCandP[ihistIdx] = new TH1F(Form("h%s_PixCandP",histIndex[ihistIdx]), */
   /*                                     Form("%s: PixelCand;p [GeV/c]",histIndex[ihistIdx]),100,0,20); */

   /*      for(Int_t iTrk=0;iTrk<2;iTrk++){ */

   /*         hEta[ihistIdx][iTrk][0] = new TH1F(Form("h%s_%sEta", histIndex[ihistIdx],Track[iTrk]), */
   /*                                            Form("%s: %s;#eta",histIndex[ihistIdx], Track[iTrk]),binEta,EtabinMin,EtabinMax); */
   /*         hPt[ihistIdx][iTrk][0] = new TH1F(Form("h%s_%sPt", histIndex[ihistIdx], Track[iTrk]), */
   /*                                           Form("%s: %s;p_{T} [GeV/c]",histIndex[ihistIdx], Track[iTrk]), binPt,PtbinMin,PtbinMax); */
   /*         hHits[ihistIdx][iTrk][0] = new TH1F(Form("h%s_%sHits", histIndex[ihistIdx], Track[iTrk]),  */
   /*                                             Form("%s: # of %s Hits;#Hits",histIndex[ihistIdx], Track[iTrk]),11, -0.5, 10.5); */
   /*         hNormChi2[ihistIdx][iTrk][0] = new TH1F(Form("h%s_%sNormChi2", histIndex[ihistIdx], Track[iTrk]), */
   /*                                                 Form("%s: %s;#chi^{2} / ndf",histIndex[ihistIdx], Track[iTrk]),200,0.,20.); */
   /*         hDxy[ihistIdx][iTrk][0] = new TH1F(Form("h%s_%sDxy", histIndex[ihistIdx], Track[iTrk]), */
   /*                                            Form("%s: %s;d_{xy} [cm]",histIndex[ihistIdx], Track[iTrk]),100,-0.5,0.5); */
   /*         hDz[ihistIdx][iTrk][0] = new TH1F(Form("h%s_%sDz", histIndex[ihistIdx], Track[iTrk]), */
   /*                                           Form("%s: %s;d_{z} [cm]",histIndex[ihistIdx], Track[iTrk]),100,-20.,20.); */
   /*         hP[ihistIdx][iTrk][0] = new TH1F(Form("h%s_%sP", histIndex[ihistIdx], Track[iTrk]), */
   /*                                          Form("%s: %s;p [GeV/c]",histIndex[ihistIdx], Track[iTrk]),binPt,PtbinMin,PtbinMax); */
   /*         hEta[ihistIdx][iTrk][1] = new TH1F(Form("h%s_%sEta_EtaCut", histIndex[ihistIdx], Track[iTrk]), */
   /*                                            Form("%s: %s;#eta",histIndex[ihistIdx], Track[iTrk]), binEta,EtabinMin,EtabinMax); */
   /*         hPt[ihistIdx][iTrk][1] = new TH1F(Form("h%s_%sPt_PtCut", histIndex[ihistIdx], Track[iTrk]), */
   /*                                           Form("%s: %s;p_{T} [GeV/c]",histIndex[ihistIdx], Track[iTrk]), binPt,PtbinMin,PtbinMax); */

   /*         hHits[ihistIdx][iTrk][1] = new TH1F(Form("h%s_%sHits_HitCut", histIndex[ihistIdx], Track[iTrk]), */
   /*                                             Form("%s: # of %s Hits;#Hits",histIndex[ihistIdx], Track[iTrk]), 11, -0.5, 10.5); */
   /*         hNormChi2[ihistIdx][iTrk][1] = new TH1F(Form("h%s_%sNormChi2_Chi2Cut", histIndex[ihistIdx], Track[iTrk]), */
   /*                                                 Form("%s: %s;#chi^{2} / ndf",histIndex[ihistIdx], Track[iTrk]),200,0.,20.); */
   /*         hDxy[ihistIdx][iTrk][1] = new TH1F(Form("h%s_%sDxy_DxyCut", histIndex[ihistIdx], Track[iTrk]), */
   /*                                            Form("%s: %s;d_{xy} [cm]",histIndex[ihistIdx], Track[iTrk]),100,-0.5,0.5); */
   /*         hDz[ihistIdx][iTrk][1] = new TH1F(Form("h%s_%sDz_DzCut", histIndex[ihistIdx], Track[iTrk]), */
   /*                                           Form("%s: %s;d_{z} [cm]",histIndex[ihistIdx], Track[iTrk]),80,-20.,20.); */
   /*         hP[ihistIdx][iTrk][1] = new TH1F(Form("h%s_%sP_PCut", histIndex[ihistIdx], Track[iTrk]), */
   /*                                          Form("%s: %s;p [GeV/c]",histIndex[ihistIdx], Track[iTrk]),binPt,PtbinMin,PtbinMax); */
   /*         hNCand[ihistIdx][iTrk] = new TH1F(Form("h%s_%sNCand", histIndex[ihistIdx], Track[iTrk]), */
   /*                                           Form("%s: # of %s Candidates;#Cands",histIndex[ihistIdx], Track[iTrk]),12,-0.5,11.5); */

   /*         for(Int_t iCut=0; iCut<4; iCut++){ */

   /*           hOniaEta[ihistIdx][iTrk][iCut] = new TH1F(Form("h%s_%sMuEta%s", histIndex[ihistIdx], Track[iTrk], histIdxCut[iCut]), */
   /*                                                     Form("%s: (%s+Mu)%s;#eta", histIndex[ihistIdx], Track[iTrk], histIdxCut[iCut]), */
   /*                                                     binEta,EtabinMin,EtabinMax); */
   /*           hOniaRap[ihistIdx][iTrk][iCut] = new TH1F(Form("h%s_%sMuRap%s", histIndex[ihistIdx], Track[iTrk], histIdxCut[iCut]), */
   /*                                                     Form("%s: (%s+Mu)%s;y", histIndex[ihistIdx], Track[iTrk], histIdxCut[iCut]), */
   /*                                                     binRap,RapbinMin,RapbinMax); */
   /*           hOniaPt[ihistIdx][iTrk][iCut] = new TH1F(Form("h%s_%sMuPt%s", histIndex[ihistIdx],Track[iTrk],histIdxCut[iCut]), */
   /*                                                    Form("%s: (%s+Mu)%s;p_{T} [GeV/c]",histIndex[ihistIdx],Track[iTrk],histIdxCut[iCut]), */
   /*                                                    binPt,PtbinMin,PtbinMax); */
   /*           hOniaP[ihistIdx][iTrk][iCut] = new TH1F(Form("h%s_%sMuP%s", histIndex[ihistIdx], Track[iTrk], histIdxCut[iCut]), */
   /*                                                   Form("%s: (%s+Mu)%s;p [GeV/c]", histIndex[ihistIdx], Track[iTrk], histIdxCut[iCut]), */
   /*                                                   binP,PbinMin,PbinMax); */
   /*           hOniaMass[ihistIdx][iTrk][iCut] = new TH1F(Form("h%s_%sMuMass%s", histIndex[ihistIdx], Track[iTrk], histIdxCut[iCut]), */
   /*                                                      Form("%s: (%s+Mu)%s;M [GeV/c^{2}]", histIndex[ihistIdx], Track[iTrk], histIdxCut[iCut]), */
   /*                                                      binMass,MassbinMin,MassbinMax); */
   /*           hOniaEtaPt[ihistIdx][iTrk][iCut] = new TH2F(Form("h%s_%sMuEtaPt%s", histIndex[ihistIdx], Track[iTrk], histIdxCut[iCut]), */
   /*                                              Form("%s: (%s+Mu)%s;#eta;p_{T} [GeV/c]", histIndex[ihistIdx], Track[iTrk], histIdxCut[iCut]), */
   /*                                              binEta,EtabinMin,EtabinMax,binPt,PtbinMin,PtbinMax); */
   /*           hOniaRapP[ihistIdx][iTrk][iCut] = new TH2F(Form("h%s_%sMuRapP%s", histIndex[ihistIdx], Track[iTrk], histIdxCut[iCut]), */
   /*                                                      Form("%s: (%s+Mu)%s;y;p [GeV/c]", histIndex[ihistIdx],Track[iTrk],histIdxCut[iCut]), */
   /*                                                      binRap,RapbinMin,RapbinMax,binP,PbinMin,PbinMax); */
   /*         } */
   /*      } */
   /*   } */

   //SetMapL1SeedsOfStandardHLTPath(menu);

   std::cout<<"Succeeded initialising OHltTree. nEntries: "<<fChain->GetEntries()<<std::endl;

   initEGammaWPMap();
   initMuThresholdMap();
}

void OHltTree::initEGammaWPMap(){

  //EGCaloId 
  //default values
  (map_EGammaCaloId[""])["hoverebarrel"] = 0.15 ;
  (map_EGammaCaloId[""])["hovereendcap"] = 0.10  ;
  (map_EGammaCaloId[""])["clusshapebarrel"] = 999. ;
  (map_EGammaCaloId[""])["clusshapeendcap"] = 999. ;
  // IdVL
  (map_EGammaCaloId["CaloIdVL"])["hoverebarrel"] = 0.15 ;
  (map_EGammaCaloId["CaloIdVL"])["hovereendcap"] = 0.10 ;
  (map_EGammaCaloId["CaloIdVL"])["clusshapebarrel"] = 0.024;
  (map_EGammaCaloId["CaloIdVL"])["clusshapeendcap"] = 0.040;
  // IdL
  (map_EGammaCaloId["CaloIdL"])["hoverebarrel"] = 0.15 ;
  (map_EGammaCaloId["CaloIdL"])["hovereendcap"] = 0.10 ;
  (map_EGammaCaloId["CaloIdL"])["clusshapebarrel"] = 0.014;
  (map_EGammaCaloId["CaloIdL"])["clusshapeendcap"] = 0.035;
  //IdXL
  (map_EGammaCaloId["CaloIdXL"])["hoverebarrel"] = 0.10 ;
  (map_EGammaCaloId["CaloIdXL"])["hovereendcap"] = 0.10 ;
  (map_EGammaCaloId["CaloIdXL"])["clusshapebarrel"] = 0.014;
  (map_EGammaCaloId["CaloIdXL"])["clusshapeendcap"] = 0.035;
   // IdT
  (map_EGammaCaloId["CaloIdT"])["hoverebarrel"] = 0.10 ;
  (map_EGammaCaloId["CaloIdT"])["hovereendcap"] = 0.075;
  (map_EGammaCaloId["CaloIdT"])["clusshapebarrel"] = 0.011;
  (map_EGammaCaloId["CaloIdT"])["clusshapeendcap"] = 0.031;
  // IdVT
  (map_EGammaCaloId["CaloIdVT"])["hoverebarrel"] = 0.05 ;
  (map_EGammaCaloId["CaloIdVT"])["hovereendcap"] = 0.05 ;
  (map_EGammaCaloId["CaloIdVT"])["clusshapebarrel"] = 0.011;
  (map_EGammaCaloId["CaloIdVT"])["clusshapeendcap"] = 0.031;
  // WP80 Id
  (map_EGammaCaloId["WP80"])["hoverebarrel"] = 0.04 ; 
  (map_EGammaCaloId["WP80"])["hovereendcap"] = 0.025  ; 
  (map_EGammaCaloId["WP80"])["clusshapebarrel"] = 0.01 ; 
  (map_EGammaCaloId["WP80"])["clusshapeendcap"] = 0.03 ; 
  // WP70 Id
  (map_EGammaCaloId["WP70"])["hoverebarrel"] = 0.025 ;  
  (map_EGammaCaloId["WP70"])["hovereendcap"] = 0.025  ;  
  (map_EGammaCaloId["WP70"])["clusshapebarrel"] = 0.01 ;  
  (map_EGammaCaloId["WP70"])["clusshapeendcap"] = 0.03 ;  

  //EleCaloIso 
  //default values
  (map_EleCaloIso[""])["HisooverETbarrel"] = 999.;
  (map_EleCaloIso[""])["HisooverETendcap"] = 999.;
  (map_EleCaloIso[""])["EisooverETbarrel"] = 999.;
  (map_EleCaloIso[""])["EisooverETendcap"] = 999.;
  // CaloIsoVL
  (map_EleCaloIso["CaloIsoVL"])["HisooverETbarrel"] = 0.200;
  (map_EleCaloIso["CaloIsoVL"])["HisooverETendcap"] = 0.200;
  (map_EleCaloIso["CaloIsoVL"])["EisooverETbarrel"] = 0.200;
  (map_EleCaloIso["CaloIsoVL"])["EisooverETendcap"] = 0.200;
  // CaloIsoT
  (map_EleCaloIso["CaloIsoT"])["HisooverETbarrel"] = 0.125;
  (map_EleCaloIso["CaloIsoT"])["HisooverETendcap"] = 0.075;
  (map_EleCaloIso["CaloIsoT"])["EisooverETbarrel"] = 0.125;
  (map_EleCaloIso["CaloIsoT"])["EisooverETendcap"] = 0.075;
  // WP80 CaloIso
  (map_EleCaloIso["WP80"])["HisooverETbarrel"] = 0.10; 
  (map_EleCaloIso["WP80"])["HisooverETendcap"] = 0.025; 
  (map_EleCaloIso["WP80"])["EisooverETbarrel"] = 0.07; 
  (map_EleCaloIso["WP80"])["EisooverETendcap"] = 0.05; 
  // WP70 CaloIso
  (map_EleCaloIso["WP70"])["HisooverETbarrel"] = 0.03; 
  (map_EleCaloIso["WP70"])["HisooverETendcap"] = 0.02; 
  (map_EleCaloIso["WP70"])["EisooverETbarrel"] = 0.06; 
  (map_EleCaloIso["WP70"])["EisooverETendcap"] = 0.025; 

  //EleTrkId  
  // EleTrkIdVL// default values
  (map_EleTrkId[""])["detabarrel"] = 999.;
  (map_EleTrkId[""])["detaendcap"] = 999.;
  (map_EleTrkId[""])["dphibarrel"] = 999.;
  (map_EleTrkId[""])["dphiendcap"] = 999.;
  // EleTrkIdVL
  (map_EleTrkId["TrkIdVL"])["detabarrel"] = 0.01;
  (map_EleTrkId["TrkIdVL"])["detaendcap"] = 0.01;
  (map_EleTrkId["TrkIdVL"])["dphibarrel"] = 0.15;
  (map_EleTrkId["TrkIdVL"])["dphiendcap"] = 0.10;
  // EleTrkIdT
  (map_EleTrkId["TrkIdT"])["detabarrel"] = 0.008;
  (map_EleTrkId["TrkIdT"])["detaendcap"] = 0.008;
  (map_EleTrkId["TrkIdT"])["dphibarrel"] = 0.07;
  (map_EleTrkId["TrkIdT"])["dphiendcap"] = 0.05;
  // WP80 TrkId
  (map_EleTrkId["WP80"])["detabarrel"] = 0.004; 
  (map_EleTrkId["WP80"])["detaendcap"] = 0.007; 
  (map_EleTrkId["WP80"])["dphibarrel"] = 0.06; 
  (map_EleTrkId["WP80"])["dphiendcap"] = 0.03; 
  // WP70 TrkId
  (map_EleTrkId["WP70"])["detabarrel"] = 0.004; 
  (map_EleTrkId["WP70"])["detaendcap"] = 0.005; 
  (map_EleTrkId["WP70"])["dphibarrel"] = 0.03; 
  (map_EleTrkId["WP70"])["dphiendcap"] = 0.02; 

  //EleTrkIso 
  //default
  (map_EleTrkIso[""])["Tisoratiobarrel"] = 999.;
  (map_EleTrkIso[""])["Tisoratioendcap"] = 999.;
  //EleTrkIsoVL
  (map_EleTrkIso["TrkIsoVL"])["Tisoratiobarrel"] = 0.2;
  (map_EleTrkIso["TrkIsoVL"])["Tisoratioendcap"] = 0.2;
  //EleTrkIsoT
  (map_EleTrkIso["TrkIsoT"])["Tisoratiobarrel"] = 0.125;
  (map_EleTrkIso["TrkIsoT"])["Tisoratioendcap"] = 0.075;
  // WP80 TrkIso 
  (map_EleTrkIso["WP80"])["Tisoratiobarrel"] = 0.09; 
  (map_EleTrkIso["WP80"])["Tisoratioendcap"] = 0.04; 
  // WP70 TrkIso
  (map_EleTrkIso["WP70"])["Tisoratiobarrel"] = 0.05; 
  (map_EleTrkIso["WP70"])["Tisoratioendcap"] = 0.025; 

  //PhotonIso 
  //default values
  (map_PhotonIso[""])["Tiso"] = 999. ;
  (map_PhotonIso[""])["Eiso"] = 999.  ;
  (map_PhotonIso[""])["HisoBR"] = 999. ;
  (map_PhotonIso[""])["HisoEC"] = 999. ;
  // IsoVL
  (map_PhotonIso["IsoVL"])["Tiso"] = 4.0 ;
  (map_PhotonIso["IsoVL"])["Eiso"] = 6.0 ;
  (map_PhotonIso["IsoVL"])["HisoBR"] = 4.0 ;
  (map_PhotonIso["IsoVL"])["HisoEC"] = 4.0 ;
  // IsoXL
  (map_PhotonIso["IsoL"])["Tiso"] = 4.0 ;
  (map_PhotonIso["IsoL"])["Eiso"] = 4.0 ;
  (map_PhotonIso["IsoL"])["HisoBR"] = 4.0 ;
  (map_PhotonIso["IsoL"])["HisoEC"] = 4.0 ;
  // IsoL                                                                                                 
  (map_PhotonIso["IsoL"])["Tiso"] = 3.5 ;
  (map_PhotonIso["IsoL"])["Eiso"] = 5.5 ;
  (map_PhotonIso["IsoL"])["HisoBR"] = 3.5 ;
  (map_PhotonIso["IsoL"])["HisoEC"] = 3.5 ;
  // IsoT
  (map_PhotonIso["IsoT"])["Tiso"] = 3.0 ;
  (map_PhotonIso["IsoT"])["Eiso"] = 5.0 ;
  (map_PhotonIso["IsoT"])["HisoBR"] = 3.0 ;
  (map_PhotonIso["IsoT"])["HisoEC"] = 3.0 ;

  //PhotonR9Id
  //default
  (map_PhotonR9ID[""])["HoverEEB"] = 999.;
  (map_PhotonR9ID[""])["HoverEEC"] = 999.;
  //R9Id
  (map_PhotonR9ID["R9Id"])["HoverEEB"] = 0.15;
  (map_PhotonR9ID["R9Id"])["HoverEEC"] = 0.10;
 
}

void OHltTree::initMuThresholdMap(){

  map_muThresholds[3.].push_back(0.); 
  map_muThresholds[3.].push_back(0.);
  map_muThresholds[3.].push_back(3.);

  map_muThresholds[5.].push_back(0.);
  map_muThresholds[5.].push_back(3.);
  map_muThresholds[5.].push_back(5.);

  map_muThresholds[8.].push_back(0.);
  map_muThresholds[8.].push_back(3.);
  map_muThresholds[8.].push_back(8.);

  map_muThresholds[10.].push_back(0.);
  map_muThresholds[10.].push_back(3.);
  map_muThresholds[10.].push_back(10.);

  map_muThresholds[12.].push_back(0.);
  map_muThresholds[12.].push_back(7.);
  map_muThresholds[12.].push_back(12.);

  map_muThresholds[13.].push_back(0.);
  map_muThresholds[13.].push_back(7.);
  map_muThresholds[13.].push_back(13.);

  map_muThresholds[15.].push_back(0.);
  map_muThresholds[15.].push_back(10.);
  map_muThresholds[15.].push_back(15.);

  map_muThresholds[17.].push_back(0.);
  map_muThresholds[17.].push_back(10.);
  map_muThresholds[17.].push_back(17.);

  map_muThresholds[20.].push_back(0.);
  map_muThresholds[20.].push_back(12.);
  map_muThresholds[20.].push_back(20.);

  map_muThresholds[22.].push_back(0.);
  map_muThresholds[22.].push_back(16.);
  map_muThresholds[22.].push_back(22.);

  map_muThresholds[24.].push_back(0.);
  map_muThresholds[24.].push_back(12.);
  map_muThresholds[24.].push_back(24.);

  map_muThresholds[30.].push_back(0.);
  map_muThresholds[30.].push_back(12.);
  map_muThresholds[30.].push_back(30.);

  map_muThresholds[34.].push_back(0.);
  map_muThresholds[34.].push_back(14.);
  map_muThresholds[34.].push_back(34.);

  map_muThresholds[40.].push_back(0.);
  map_muThresholds[40.].push_back(16.);
  map_muThresholds[40.].push_back(40.);

  map_muThresholds[60.].push_back(0.);
  map_muThresholds[60.].push_back(16.);
  map_muThresholds[60.].push_back(60.);

  map_muThresholds[70.].push_back(0.);
  map_muThresholds[70.].push_back(16.);
  map_muThresholds[70.].push_back(70.);

  map_muThresholds[100.].push_back(0.);
  map_muThresholds[100.].push_back(16.);
  map_muThresholds[100.].push_back(100.);

}

OHltTree::~OHltTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t OHltTree::GetEntry(Long64_t entry)
{
   // Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}

Long64_t OHltTree::LoadTree(Long64_t entry)
{
   // Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (!fChain->InheritsFrom(TChain::Class())) return centry;
   TChain *chain = (TChain*)fChain;
   if (chain->GetTreeNumber() != fCurrent)
   {
      fCurrent = chain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void OHltTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("NohJetCal", &NohJetCal, &b_NohJetCal);
   fChain->SetBranchAddress("NohJetCorCal", &NohJetCorCal, &b_NohJetCorCal);
   fChain->SetBranchAddress("NohJetCorL1L2L3Cal", &NohJetCorL1L2L3Cal, &b_NohJetCorL1L2L3Cal);
   fChain->SetBranchAddress("NrecoJetCal", &NrecoJetCal, &b_NrecoJetCal);
   fChain->SetBranchAddress("NrecoJetCorCal", &NrecoJetCorCal, &b_NrecoJetCorCal);

   fChain->SetBranchAddress("NrecoJetGen", &NrecoJetGen, &b_NrecoJetGen);
   fChain->SetBranchAddress("NrecoTowCal", &NrecoTowCal, &b_NrecoTowCal);

   fChain->SetBranchAddress("ohJetCalPt", ohJetCalPt, &b_ohJetCalPt);
   fChain->SetBranchAddress("ohJetCalPhi", ohJetCalPhi, &b_ohJetCalPhi);
   fChain->SetBranchAddress("ohJetCalEta", ohJetCalEta, &b_ohJetCalEta);
   fChain->SetBranchAddress("ohJetCalE", ohJetCalE, &b_ohJetCalE);
   fChain->SetBranchAddress("ohJetCalEMF", ohJetCalEMF, &b_ohJetCalEMF);
   fChain->SetBranchAddress("ohJetCalN90", ohJetCalN90, &b_ohJetCalN90);
   fChain->SetBranchAddress("ohJetCalN90hits", ohJetCalN90hits, &b_ohJetCalN90hits);

   fChain->SetBranchAddress("ohJetCorCalPt", ohJetCorCalPt, &b_ohJetCorCalPt);
   fChain->SetBranchAddress("ohJetCorCalPhi", ohJetCorCalPhi, &b_ohJetCorCalPhi);
   fChain->SetBranchAddress("ohJetCorCalEta", ohJetCorCalEta, &b_ohJetCorCalEta);
   fChain->SetBranchAddress("ohJetCorCalE", ohJetCorCalE, &b_ohJetCorCalE);
   fChain->SetBranchAddress("ohJetCorCalEMF", ohJetCorCalEMF, &b_ohJetCorCalEMF);
   fChain->SetBranchAddress("ohJetCorCalN90", ohJetCorCalN90, &b_ohJetCorCalN90);
   fChain->SetBranchAddress("ohJetCorCalN90hits", ohJetCorCalN90hits, &b_ohJetCorCalN90hits);

   fChain->SetBranchAddress("ohJetCorL1L2L3CalPt", ohJetCorL1L2L3CalPt, &b_ohJetCorL1L2L3CalPt);
   fChain->SetBranchAddress("ohJetCorL1L2L3CalPhi", ohJetCorL1L2L3CalPhi, &b_ohJetCorL1L2L3CalPhi);
   fChain->SetBranchAddress("ohJetCorL1L2L3CalEta", ohJetCorL1L2L3CalEta, &b_ohJetCorL1L2L3CalEta);
   fChain->SetBranchAddress("ohJetCorL1L2L3CalE", ohJetCorL1L2L3CalE, &b_ohJetCorL1L2L3CalE);
   fChain->SetBranchAddress("ohJetCorL1L2L3CalEMF", ohJetCorL1L2L3CalEMF, &b_ohJetCorL1L2L3CalEMF);
   fChain->SetBranchAddress("ohJetCorL1L2L3CalN90", ohJetCorL1L2L3CalN90, &b_ohJetCorL1L2L3CalN90);
   fChain->SetBranchAddress("ohJetCorL1L2L3CalN90hits", ohJetCorL1L2L3CalN90hits, &b_ohJetCorL1L2L3CalN90hits);

   fChain->SetBranchAddress("recoJetCalPt", recoJetCalPt, &b_recoJetCalPt);
   fChain->SetBranchAddress("recoJetCalPhi", recoJetCalPhi, &b_recoJetCalPhi);
   fChain->SetBranchAddress("recoJetCalEta", recoJetCalEta, &b_recoJetCalEta);
   fChain->SetBranchAddress("recoJetCalE", recoJetCalE, &b_recoJetCalE);
   fChain->SetBranchAddress("recoJetCalEMF", recoJetCalEMF, &b_recoJetCalEMF);
   fChain->SetBranchAddress("recoJetCalN90", recoJetCalN90, &b_recoJetCalN90);
   fChain->SetBranchAddress("recoJetCalN90hits", recoJetCalN90hits, &b_recoJetCalN90hits);

   fChain->SetBranchAddress("recoJetCorCalPt", recoJetCorCalPt, &b_recoJetCorCalPt);
   fChain->SetBranchAddress("recoJetCorCalPhi", recoJetCorCalPhi, &b_recoJetCorCalPhi);
   fChain->SetBranchAddress("recoJetCorCalEta", recoJetCorCalEta, &b_recoJetCorCalEta);
   fChain->SetBranchAddress("recoJetCorCalE", recoJetCorCalE, &b_recoJetCorCalE);
   fChain->SetBranchAddress("recoJetCorCalEMF", recoJetCorCalEMF, &b_recoJetCorCalEMF);
   fChain->SetBranchAddress("recoJetCorCalN90", recoJetCorCalN90, &b_recoJetCorCalN90);
   fChain->SetBranchAddress("recoJetCorCalN90hits", recoJetCorCalN90hits, &b_recoJetCorCalN90hits);

   fChain->SetBranchAddress("recoJetGenPt", &recoJetGenPt, &b_recoJetGenPt);
   fChain->SetBranchAddress("recoJetGenPhi", &recoJetGenPhi, &b_recoJetGenPhi);
   fChain->SetBranchAddress("recoJetGenEta", &recoJetGenEta, &b_recoJetGenEta);
   fChain->SetBranchAddress("recoJetGenEt", &recoJetGenEt, &b_recoJetGenEt);
   fChain->SetBranchAddress("recoJetGenE", &recoJetGenE, &b_recoJetGenE);
   fChain->SetBranchAddress("recoTowEt", &recoTowEt, &b_recoTowEt);
   fChain->SetBranchAddress("recoTowEta", &recoTowEta, &b_recoTowEta);
   fChain->SetBranchAddress("recoTowPhi", &recoTowPhi, &b_recoTowPhi);
   fChain->SetBranchAddress("recoTowE", &recoTowE, &b_recoTowE);
   fChain->SetBranchAddress("recoTowEm", &recoTowEm, &b_recoTowEm);
   fChain->SetBranchAddress("recoTowHad", &recoTowHad, &b_recoTowHad);
   fChain->SetBranchAddress("recoTowOE", &recoTowOE, &b_recoTowOE);

   fChain->SetBranchAddress("recoMetCal", &recoMetCal, &b_recoMetCal);
   fChain->SetBranchAddress("recoMetCalPhi", &recoMetCalPhi, &b_recoMetCalPhi);
   fChain->SetBranchAddress("recoMetCalSum", &recoMetCalSum, &b_recoMetCalSum);
   fChain->SetBranchAddress("recoMetGen", &recoMetGen, &b_recoMetGen);
   fChain->SetBranchAddress("recoMetGenPhi", &recoMetGenPhi, &b_recoMetGenPhi);
   fChain->SetBranchAddress("recoMetGenSum", &recoMetGenSum, &b_recoMetGenSum);
   fChain->SetBranchAddress("recoHTCal", &recoHTCal, &b_recoHTCal);
   fChain->SetBranchAddress("recoHTCalPhi", &recoHTCalPhi, &b_recoHTCalPhi);
   fChain->SetBranchAddress("recoHTCalSum", &recoHTCalSum, &b_recoHTCalSum);
   fChain->SetBranchAddress("NohTauL2", &NohTauL2, &b_NohTauL2);
   fChain->SetBranchAddress("ohTauL2Pt", ohTauL2Pt, &b_ohTauL2Pt);
   fChain->SetBranchAddress("NohTau", &NohTau, &b_NohTau);
   fChain->SetBranchAddress("ohTauEta", ohTauEta, &b_ohTauEta);
   fChain->SetBranchAddress("ohTauPhi", ohTauPhi, &b_ohTauPhi);
   fChain->SetBranchAddress("ohTauPt", ohTauPt, &b_ohTauPt);
   fChain->SetBranchAddress("ohTauEiso", ohTauEiso, &b_ohTauEiso);
   fChain->SetBranchAddress("ohTauL25Tpt", ohTauL25Tpt, &b_ohTauL25Tpt);
   fChain->SetBranchAddress("ohTauL25Tiso", ohTauL25Tiso, &b_ohTauL25Tiso);
   fChain->SetBranchAddress("ohTauL3Tpt", ohTauL3Tpt, &b_ohTauL3Tpt);
   fChain->SetBranchAddress("ohTauL3Tiso", ohTauL3Tiso, &b_ohTauL3Tiso);
   fChain->SetBranchAddress("NohpfTauTightCone", &NohpfTauTightCone, &b_NohpfTauTightCone); 
   fChain->SetBranchAddress("ohpfTauTightConeEta", ohpfTauTightConeEta, &b_ohpfTauTightConeEta); 
   fChain->SetBranchAddress("ohpfTauTightConePhi", ohpfTauTightConePhi, &b_ohpfTauTightConePhi); 
   fChain->SetBranchAddress("ohpfTauTightConePt", ohpfTauTightConePt, &b_ohpfTauTightConePt); 
   fChain->SetBranchAddress("ohpfTauTightConeLeadTrackPt", ohpfTauTightConeLeadTrackPt, &b_ohpfTauTightConeLeadTrackPt); 
   fChain->SetBranchAddress("ohpfTauTightConeTrkIso", ohpfTauTightConeTrkIso, &b_ohpfTauTightConeTrkIso); 
   fChain->SetBranchAddress("ohpfTauTightConeGammaIso", ohpfTauTightConeGammaIso, &b_ohpfTauTightConeGammaIso); 
   fChain->SetBranchAddress("recoNVrt", &recoNVrt, &b_recoNVrt);
   fChain->SetBranchAddress("recoVrtX", &recoVrtX, &b_recoVrtX);
   fChain->SetBranchAddress("recoVrtY", &recoVrtY, &b_recoVrtY);
   fChain->SetBranchAddress("recoVrtZ", &recoVrtZ, &b_recoVrtZ);
   fChain->SetBranchAddress("recoVrtNtrk", &recoVrtNtrk, &b_recoVrtNtrk);
   fChain->SetBranchAddress("recoVrtChi2", &recoVrtChi2, &b_recoVrtChi2);
   fChain->SetBranchAddress("recoVrtNdof", &recoVrtNdof, &b_recoVrtNdof);

   fChain->SetBranchAddress("NohBJetLife", &NohBJetLife, &b_NohBJetLife);
   fChain->SetBranchAddress("ohBJetLifeL2E", ohBJetLifeL2E, &b_ohBJetLifeL2E);
   fChain->SetBranchAddress("ohBJetLifeL2ET", ohBJetLifeL2ET, &b_ohBJetLifeL2ET);
   fChain->SetBranchAddress("ohBJetLifeL2Eta", ohBJetLifeL2Eta, &b_ohBJetLifeL2Eta);
   fChain->SetBranchAddress("ohBJetLifeL2Phi", ohBJetLifeL2Phi, &b_ohBJetLifeL2Phi);
   fChain->SetBranchAddress("ohBJetLifeL25Discriminator", ohBJetLifeL25Discriminator, &b_ohBJetLifeL25Discriminator);
   fChain->SetBranchAddress("ohBJetLifeL3Discriminator", ohBJetLifeL3Discriminator, &b_ohBJetLifeL3Discriminator);
   fChain->SetBranchAddress("NohBJetPixelTracks", &NohBJetPixelTracks, &b_NohBJetPixelTracks);
   fChain->SetBranchAddress("ohBJetLifePixelTrackPt", ohBJetLifePixelTrackPt, &b_ohBJetLifePixelTrackPt);
   fChain->SetBranchAddress("ohBJetLifePixelTrackEta", ohBJetLifePixelTrackEta, &b_ohBJetLifePixelTrackEta);
   fChain->SetBranchAddress("ohBJetLifePixelTrackPhi", ohBJetLifePixelTrackPhi, &b_ohBJetLifePixelTrackPhi);
   fChain->SetBranchAddress("ohBJetLifePixelTrackChi2", ohBJetLifePixelTrackChi2, &b_ohBJetLifePixelTrackChi2);
   fChain->SetBranchAddress("NohBJetRegionalTracks", &NohBJetRegionalTracks, &b_NohBJetRegionalTracks);
   fChain->SetBranchAddress("ohBJetLifeRegionalTrackPt", ohBJetLifeRegionalTrackPt, &b_ohBJetLifeRegionalTrackPt);
   fChain->SetBranchAddress("ohBJetLifeRegionalTrackEta", ohBJetLifeRegionalTrackEta, &b_ohBJetLifeRegionalTrackEta);
   fChain->SetBranchAddress("ohBJetLifeRegionalTrackPhi", ohBJetLifeRegionalTrackPhi, &b_ohBJetLifeRegionalTrackPhi);
   fChain->SetBranchAddress("ohBJetLifeRegionalTrackChi2", ohBJetLifeRegionalTrackChi2, &b_ohBJetLifeRegionalTrackChi2);
   fChain->SetBranchAddress("ohBJetLifeRegionalSeedPt", ohBJetLifeRegionalSeedPt, &b_ohBJetLifeRegionalSeedPt);
   fChain->SetBranchAddress("ohBJetLifeRegionalSeedEta", ohBJetLifeRegionalSeedEta, &b_ohBJetLifeRegionalSeedEta);
   fChain->SetBranchAddress("ohBJetLifeRegionalSeedPhi", ohBJetLifeRegionalSeedPhi, &b_ohBJetLifeRegionalSeedPhi);
   fChain->SetBranchAddress("NohBJetSoftm", &NohBJetSoftm, &b_NohBJetSoftm);
   fChain->SetBranchAddress("ohBJetSoftmL2E", ohBJetSoftmL2E, &b_ohBJetSoftmL2E);
   fChain->SetBranchAddress("ohBJetSoftmL2ET", ohBJetSoftmL2ET, &b_ohBJetSoftmL2ET);
   fChain->SetBranchAddress("ohBJetSoftmL2Eta", ohBJetSoftmL2Eta, &b_ohBJetSoftmL2Eta);
   fChain->SetBranchAddress("ohBJetSoftmL2Phi", ohBJetSoftmL2Phi, &b_ohBJetSoftmL2Phi);
   fChain->SetBranchAddress("ohBJetSoftmL25Discriminator", ohBJetSoftmL25Discriminator, &b_ohBJetSoftmL25Discriminator);
   fChain->SetBranchAddress("ohBJetSoftmL3Discriminator", ohBJetSoftmL3Discriminator, &b_ohBJetSoftmL3Discriminator);
   fChain->SetBranchAddress("ohBJetPerfL2E", ohBJetPerfL2E, &b_ohBJetPerfL2E);
   fChain->SetBranchAddress("ohBJetPerfL2ET", ohBJetPerfL2ET, &b_ohBJetPerfL2ET);
   fChain->SetBranchAddress("ohBJetPerfL2Eta", ohBJetPerfL2Eta, &b_ohBJetPerfL2Eta);
   fChain->SetBranchAddress("ohBJetPerfL2Phi", ohBJetPerfL2Phi, &b_ohBJetPerfL2Phi);
   fChain->SetBranchAddress("NohBJetL2", &NohBJetL2, &b_NohBJetL2);
   fChain->SetBranchAddress("ohBJetL2Energy", ohBJetL2Energy, &b_ohBJetL2Energy);
   fChain->SetBranchAddress("ohBJetL2Et", ohBJetL2Et, &b_ohBJetL2Et);
   fChain->SetBranchAddress("ohBJetL2Pt", ohBJetL2Pt, &b_ohBJetL2Pt);
   fChain->SetBranchAddress("ohBJetL2Eta", ohBJetL2Eta, &b_ohBJetL2Eta);
   fChain->SetBranchAddress("ohBJetL2Phi", ohBJetL2Phi, &b_ohBJetL2Phi);
   fChain->SetBranchAddress("NohpfBJetL2", &NohpfBJetL2, &b_NohpfBJetL2);
   fChain->SetBranchAddress("ohpfBJetL2Energy", ohpfBJetL2Energy, &b_ohpfBJetL2Energy);
   fChain->SetBranchAddress("ohpfBJetL2Et", ohpfBJetL2Et, &b_ohpfBJetL2Et);
   fChain->SetBranchAddress("ohpfBJetL2Pt", ohpfBJetL2Pt, &b_ohpfBJetL2Pt);
   fChain->SetBranchAddress("ohpfBJetL2Eta", ohpfBJetL2Eta, &b_ohpfBJetL2Eta);
   fChain->SetBranchAddress("ohpfBJetL2Phi", ohpfBJetL2Phi, &b_ohpfBJetL2Phi);   
   fChain->SetBranchAddress("NohBJetL2Corrected", &NohBJetL2Corrected, &b_NohBJetL2Corrected);
   fChain->SetBranchAddress("ohBJetL2CorrectedEnergy", ohBJetL2CorrectedEnergy, &b_ohBJetL2CorrectedEnergy);
   fChain->SetBranchAddress("ohBJetL2CorrectedEt", ohBJetL2CorrectedEt, &b_ohBJetL2CorrectedEt);
   fChain->SetBranchAddress("ohBJetL2CorrectedPt", ohBJetL2CorrectedPt, &b_ohBJetL2CorrectedPt);
   fChain->SetBranchAddress("ohBJetL2CorrectedEta", ohBJetL2CorrectedEta, &b_ohBJetL2CorrectedEta);
   fChain->SetBranchAddress("ohBJetL2CorrectedPhi", ohBJetL2CorrectedPhi, &b_ohBJetL2CorrectedPhi);   
   fChain->SetBranchAddress("ohBJetIPL25Tag", ohBJetIPL25Tag, &b_ohBJetIPL25Tag);
   fChain->SetBranchAddress("ohBJetIPL3Tag", ohBJetIPL3Tag, &b_ohBJetIPL3Tag);
   fChain->SetBranchAddress("ohBJetIPL25TagSingleTrack", ohBJetIPL25TagSingleTrack, &b_ohBJetIPL25TagSingleTrack);
   fChain->SetBranchAddress("ohBJetIPL3TagSingleTrack", ohBJetIPL3TagSingleTrack, &b_ohBJetIPL3TagSingleTrack);
   fChain->SetBranchAddress("ohBJetIPL25TagSingleTrackL1FastJet", ohBJetIPL25TagSingleTrackL1FastJet, &b_ohBJetIPL25TagSingleTrackL1FastJet);
   fChain->SetBranchAddress("ohBJetIPL3TagSingleTrackL1FastJet", ohBJetIPL3TagSingleTrackL1FastJet, &b_ohBJetIPL3TagSingleTrackL1FastJet);
   fChain->SetBranchAddress("ohBJetMuL25Tag", ohBJetMuL25Tag, &b_ohBJetMuL25Tag);
   fChain->SetBranchAddress("ohBJetMuL3Tag", ohBJetMuL3Tag, &b_ohBJetMuL3Tag);
   fChain->SetBranchAddress("ohBJetPerfL25Tag", ohBJetPerfL25Tag, &b_ohBJetPerfL25Tag);
   fChain->SetBranchAddress("ohBJetPerfL3Tag", ohBJetPerfL3Tag, &b_ohBJetPerfL3Tag);
   fChain->SetBranchAddress("NohBJetL2CorrectedL1FastJet", &NohBJetL2CorrectedL1FastJet, &b_NohBJetL2CorrectedL1FastJet);
   fChain->SetBranchAddress("ohBJetL2CorrectedEnergyL1FastJet", ohBJetL2CorrectedEnergyL1FastJet, &b_ohBJetL2CorrectedEnergyL1FastJet);
   fChain->SetBranchAddress("ohBJetL2CorrectedEtL1FastJet", ohBJetL2CorrectedEtL1FastJet, &b_ohBJetL2CorrectedEtL1FastJet);
   fChain->SetBranchAddress("ohBJetL2CorrectedPtL1FastJet", ohBJetL2CorrectedPtL1FastJet, &b_ohBJetL2CorrectedPtL1FastJet);
   fChain->SetBranchAddress("ohBJetL2CorrectedEtaL1FastJet", ohBJetL2CorrectedEtaL1FastJet, &b_ohBJetL2CorrectedEtaL1FastJet);
   fChain->SetBranchAddress("ohBJetL2CorrectedPhiL1FastJet", ohBJetL2CorrectedPhiL1FastJet, &b_ohBJetL2CorrectedPhiL1FastJet);
   fChain->SetBranchAddress("ohBJetIPL25TagL1FastJet", ohBJetIPL25TagL1FastJet, &b_ohBJetIPL25TagL1FastJet);
   fChain->SetBranchAddress("ohBJetIPL3TagL1FastJet", ohBJetIPL3TagL1FastJet, &b_ohBJetIPL3TagL1FastJet);
   fChain->SetBranchAddress("ohBJetPerfL25TagL1FastJet", ohBJetPerfL25TagL1FastJet, &b_ohBJetPerfL25TagL1FastJet);
   fChain->SetBranchAddress("ohBJetPerfL3TagL1FastJet", ohBJetPerfL3TagL1FastJet, &b_ohBJetPerfL3TagL1FastJet);   
   fChain->SetBranchAddress("NrecoElec", &NrecoElec, &b_NrecoElec);
   fChain->SetBranchAddress("recoElecPt", &recoElecPt, &b_recoElecPt);
   fChain->SetBranchAddress("recoElecPhi", &recoElecPhi, &b_recoElecPhi);
   fChain->SetBranchAddress("recoElecEta", &recoElecEta, &b_recoElecEta);
   fChain->SetBranchAddress("recoElecEt", &recoElecEt, &b_recoElecEt);
   fChain->SetBranchAddress("recoElecE", &recoElecE, &b_recoElecE);
   fChain->SetBranchAddress("NrecoPhot", &NrecoPhot, &b_NrecoPhot);
   fChain->SetBranchAddress("recoPhotPt", &recoPhotPt, &b_recoPhotPt);
   fChain->SetBranchAddress("recoPhotPhi", &recoPhotPhi, &b_recoPhotPhi);
   fChain->SetBranchAddress("recoPhotEta", &recoPhotEta, &b_recoPhotEta);
   fChain->SetBranchAddress("recoPhotEt", &recoPhotEt, &b_recoPhotEt);
   fChain->SetBranchAddress("recoPhotE", &recoPhotE, &b_recoPhotE);
   fChain->SetBranchAddress("NohPhot", &NohPhot, &b_NohPhot);
   fChain->SetBranchAddress("ohPhotEt", ohPhotEt, &b_ohPhotEt);
   fChain->SetBranchAddress("ohPhotEta", ohPhotEta, &b_ohPhotEta);
   fChain->SetBranchAddress("ohPhotPhi", ohPhotPhi, &b_ohPhotPhi);
   fChain->SetBranchAddress("ohPhotEiso", ohPhotEiso, &b_ohPhotEiso);
   fChain->SetBranchAddress("ohPhotHiso", ohPhotHiso, &b_ohPhotHiso);
   fChain->SetBranchAddress("ohPhotTiso", ohPhotTiso, &b_ohPhotTiso);
   fChain->SetBranchAddress("ohPhotL1iso", ohPhotL1iso, &b_ohPhotL1iso);
   fChain->SetBranchAddress("ohPhotR9", ohPhotR9, &b_ohPhotR9);
   fChain->SetBranchAddress("ohPhotR9ID", ohPhotR9ID, &b_ohPhotR9ID);
   fChain->SetBranchAddress("ohPhotHforHoverE", ohPhotHforHoverE, &b_ohPhotHforHoverE);
   fChain->SetBranchAddress("ohPhotClusShap", ohPhotClusShap, &b_ohPhotClusShap);
   fChain->SetBranchAddress("NohEcalActiv", &NohEcalActiv, &b_NohEcalActiv);
   fChain->SetBranchAddress("ohEcalActivEt", ohEcalActivEt, &b_ohEcalActivEt);
   fChain->SetBranchAddress("ohEcalActivEta", ohEcalActivEta, &b_ohEcalActivEta);
   fChain->SetBranchAddress("ohEcalActivPhi", ohEcalActivPhi, &b_ohEcalActivPhi);
   fChain->SetBranchAddress("ohEcalActivEiso", ohEcalActivEiso, &b_ohEcalActivEiso);
   fChain->SetBranchAddress("ohEcalActivHiso", ohEcalActivHiso, &b_ohEcalActivHiso);
   fChain->SetBranchAddress("ohEcalActivTiso", ohEcalActivTiso, &b_ohEcalActivTiso);
   fChain->SetBranchAddress("ohEcalActivL1iso", ohEcalActivL1iso, &b_ohEcalActivL1iso);
   fChain->SetBranchAddress("ohEcalActivR9", ohEcalActivR9, &b_ohEcalActivR9);
   fChain->SetBranchAddress("ohEcalActivR9ID", ohEcalActivR9ID, &b_ohEcalActivR9ID);
   fChain->SetBranchAddress("ohEcalActivHforHoverE", ohEcalActivHforHoverE, &b_ohEcalActivHforHoverE);
   fChain->SetBranchAddress("ohEcalActivClusShap", ohEcalActivClusShap, &b_ohEcalActivClusShap);
   fChain->SetBranchAddress("NohEle", &NohEle, &b_NohEle);
   fChain->SetBranchAddress("ohEleClusShap", ohEleClusShap, &b_ohEleClusShap);
   fChain->SetBranchAddress("ohEleDeta", ohEleDeta, &b_ohEleDeta);
   fChain->SetBranchAddress("ohEleDphi", ohEleDphi, &b_ohEleDphi);
   fChain->SetBranchAddress("ohEleEt", ohEleEt, &b_ohEleEt);
   fChain->SetBranchAddress("ohEleEta", ohEleEta, &b_ohEleEta);
   fChain->SetBranchAddress("ohElePhi", ohElePhi, &b_ohElePhi);
   fChain->SetBranchAddress("ohEleE", ohEleE, &b_ohEleE);
   fChain->SetBranchAddress("ohEleP", ohEleP, &b_ohEleP);
   fChain->SetBranchAddress("ohEleHiso", ohEleHiso, &b_ohEleHiso);
   fChain->SetBranchAddress("ohEleTiso", ohEleTiso, &b_ohEleTiso);
   fChain->SetBranchAddress("ohEleL1iso", ohEleL1iso, &b_ohEleL1iso);
   fChain->SetBranchAddress("ohElePixelSeeds", ohElePixelSeeds, &b_ohElePixelSeeds);
   fChain->SetBranchAddress("ohEleNewSC", ohEleNewSC, &b_ohEleNewSC);
   fChain->SetBranchAddress("ohEleR9", ohEleR9, &b_ohEleR9);
   fChain->SetBranchAddress("ohEleHforHoverE", ohEleHforHoverE, &b_ohEleHforHoverE);
   fChain->SetBranchAddress("ohEleEiso", ohEleEiso, &b_ohEleEiso);
   fChain->SetBranchAddress("ohEleVtxZ", ohEleVtxZ, &b_ohEleVtxZ);
	
   fChain->SetBranchAddress("NohHFEle", &NohHFEle, &b_NohHFEle);
   fChain->SetBranchAddress("ohHFElePt", ohHFElePt, &b_ohHFElePt);
   fChain->SetBranchAddress("ohHFEleEta", ohHFEleEta, &b_ohHFEleEta);
   fChain->SetBranchAddress("NohHFECALClus", &NohHFECALClus, &b_NohHFECALClus);
   fChain->SetBranchAddress("ohHFEleClustere9e25", ohHFEleClustere9e25, &b_ohHFEleClustere9e25);
   fChain->SetBranchAddress("ohHFEleClustere1e9", ohHFEleClustere1e9, &b_ohHFEleClustere1e9);
   fChain->SetBranchAddress("ohHFEleClustereCOREe9", ohHFEleClustereCOREe9, &b_ohHFEleClustereCOREe9);
   fChain->SetBranchAddress("ohHFEleClustereSeL", ohHFEleClustereSeL, &b_ohHFEleClustereSeL);
   fChain->SetBranchAddress("ohHFEleCluster2Dcut", ohHFEleCluster2Dcut, &b_ohHFEleCluster2Dcut);
   fChain->SetBranchAddress("ohHFEleClusterEta", ohHFEleClusterEta, &b_ohHFEleClusterEta);
   fChain->SetBranchAddress("ohHFEleClusterPhi", ohHFEleClusterPhi, &b_ohHFEleClusterPhi);
	
   fChain->SetBranchAddress("NrecoMuon", &NrecoMuon, &b_NrecoMuon);
   fChain->SetBranchAddress("recoMuonPt", &recoMuonPt, &b_recoMuonPt);
   fChain->SetBranchAddress("recoMuonPhi", &recoMuonPhi, &b_recoMuonPhi);
   fChain->SetBranchAddress("recoMuonEta", &recoMuonEta, &b_recoMuonEta);
   fChain->SetBranchAddress("recoMuonEt", &recoMuonEt, &b_recoMuonEt);
   fChain->SetBranchAddress("recoMuonE", &recoMuonE, &b_recoMuonE);
   fChain->SetBranchAddress("NohMuL2", &NohMuL2, &b_NohMuL2);
   fChain->SetBranchAddress("ohMuL2Pt", ohMuL2Pt, &b_ohMuL2Pt);
   fChain->SetBranchAddress("ohMuL2Phi", ohMuL2Phi, &b_ohMuL2Phi);
   fChain->SetBranchAddress("ohMuL2Eta", ohMuL2Eta, &b_ohMuL2Eta);
   fChain->SetBranchAddress("ohMuL2Chg", ohMuL2Chg, &b_ohMuL2Chg);
   fChain->SetBranchAddress("ohMuL2PtErr", ohMuL2PtErr, &b_ohMuL2PtErr);
   fChain->SetBranchAddress("ohMuL2Iso", ohMuL2Iso, &b_ohMuL2Iso);
   fChain->SetBranchAddress("ohMuL2Dr", ohMuL2Dr, &b_ohMuL2Dr);
   fChain->SetBranchAddress("ohMuL2Dz", ohMuL2Dz, &b_ohMuL2Dz);
   fChain->SetBranchAddress("ohMuL2Nhits", ohMuL2Nhits, &b_ohMuL2Nhits);
   fChain->SetBranchAddress("ohMuL2Nstat", ohMuL2Nstat, &b_ohMuL2Nstat);
   fChain->SetBranchAddress("NohMuL3", &NohMuL3, &b_NohMuL3);
   fChain->SetBranchAddress("ohMuL3Pt", ohMuL3Pt, &b_ohMuL3Pt);
   fChain->SetBranchAddress("ohMuL3Phi", ohMuL3Phi, &b_ohMuL3Phi);
   fChain->SetBranchAddress("ohMuL3Eta", ohMuL3Eta, &b_ohMuL3Eta);
   fChain->SetBranchAddress("ohMuL3Chg", ohMuL3Chg, &b_ohMuL3Chg);
   fChain->SetBranchAddress("ohMuL3PtErr", ohMuL3PtErr, &b_ohMuL3PtErr);
   fChain->SetBranchAddress("ohMuL3Iso", ohMuL3Iso, &b_ohMuL3Iso);
   fChain->SetBranchAddress("ohMuL3Dr", ohMuL3Dr, &b_ohMuL3Dr);
   fChain->SetBranchAddress("ohMuL3Dz", ohMuL3Dz, &b_ohMuL3Dz);
   fChain->SetBranchAddress("ohMuL3L2idx", ohMuL3L2idx, &b_ohMuL3L2idx);
   fChain->SetBranchAddress("NpfMuon", &NpfMuon, &b_NpfMuon);
   fChain->SetBranchAddress("pfMuonPt", pfMuonPt, &b_pfMuonPt);
   fChain->SetBranchAddress("pfMuonPhi", pfMuonPhi, &b_pfMuonPhi);
   fChain->SetBranchAddress("pfMuonEta", pfMuonEta, &b_pfMuonEta);
   fChain->SetBranchAddress("pfMuonEt", pfMuonEt, &b_pfMuonEt);
   fChain->SetBranchAddress("pfMuonE", pfMuonE, &b_pfMuonE);
   fChain->SetBranchAddress("pfMuonCharge", pfMuonCharge, &b_pfMuonCharge);
   fChain->SetBranchAddress("NohMuL2NoVtx", &NohMuL2NoVtx, &b_NohMuL2NoVtx); 
   fChain->SetBranchAddress("ohMuL2NoVtxPt", ohMuL2NoVtxPt, &b_ohMuL2NoVtxPt); 
   fChain->SetBranchAddress("ohMuL2NoVtxPhi", ohMuL2NoVtxPhi, &b_ohMuL2NoVtxPhi); 
   fChain->SetBranchAddress("ohMuL2NoVtxEta", ohMuL2NoVtxEta, &b_ohMuL2NoVtxEta); 
   fChain->SetBranchAddress("ohMuL2NoVtxChg", ohMuL2NoVtxChg, &b_ohMuL2NoVtxChg); 
   fChain->SetBranchAddress("ohMuL2NoVtxPtErr", ohMuL2NoVtxPtErr, &b_ohMuL2NoVtxPtErr); 
   fChain->SetBranchAddress("ohMuL2NoVtxDr", ohMuL2NoVtxDr, &b_ohMuL2NoVtxDr); 
   fChain->SetBranchAddress("ohMuL2NoVtxDz", ohMuL2NoVtxDz, &b_ohMuL2NoVtxDz); 
   fChain->SetBranchAddress("ohHighestEnergyEERecHit", &ohHighestEnergyEERecHit, &b_ohHighestEnergyEERecHit);
   fChain->SetBranchAddress("ohHighestEnergyEBRecHit", &ohHighestEnergyEBRecHit, &b_ohHighestEnergyEBRecHit);
   fChain->SetBranchAddress("ohHighestEnergyHBHERecHit", &ohHighestEnergyHBHERecHit, &b_ohHighestEnergyHBHERecHit);
   fChain->SetBranchAddress("ohHighestEnergyHORecHit", &ohHighestEnergyHORecHit, &b_ohHighestEnergyHORecHit);
   fChain->SetBranchAddress("ohHighestEnergyHFRecHit", &ohHighestEnergyHFRecHit, &b_ohHighestEnergyHFRecHit);
   fChain->SetBranchAddress("Nalcapi0clusters", &Nalcapi0clusters, &b_Nalcapi0clusters);
   fChain->SetBranchAddress("ohAlcapi0ptClusAll", ohAlcapi0ptClusAll, &b_ohAlcapi0ptClusAll);
   fChain->SetBranchAddress("ohAlcapi0etaClusAll", ohAlcapi0etaClusAll, &b_ohAlcapi0etaClusAll);
   fChain->SetBranchAddress("ohAlcapi0phiClusAll", ohAlcapi0phiClusAll, &b_ohAlcapi0phiClusAll);
   fChain->SetBranchAddress("ohAlcapi0s4s9ClusAll", ohAlcapi0s4s9ClusAll, &b_ohAlcapi0s4s9ClusAll);
   fChain->SetBranchAddress("NohPixelTracksL3", &NohPixelTracksL3, &b_NohPixelTracksL3);
   fChain->SetBranchAddress("ohPixelTracksL3Pt", ohPixelTracksL3Pt, &b_ohPixelTracksL3Pt);
   fChain->SetBranchAddress("ohPixelTracksL3Eta", ohPixelTracksL3Eta, &b_ohPixelTracksL3Eta);
   fChain->SetBranchAddress("ohPixelTracksL3Phi", ohPixelTracksL3Phi, &b_ohPixelTracksL3Phi);
   fChain->SetBranchAddress("ohPixelTracksL3Vz", ohPixelTracksL3Vz, &b_ohPixelTracksL3Vz);
   fChain->SetBranchAddress("ohIsoPixelTrackHBL2N", &ohIsoPixelTrackHBL2N, &b_ohIsoPixelTrackHBL2N);
   fChain->SetBranchAddress("ohIsoPixelTrackHBL2P", ohIsoPixelTrackHBL2P, &b_ohIsoPixelTrackHBL2P);
   fChain->SetBranchAddress("ohIsoPixelTrackHBL2Eta", ohIsoPixelTrackHBL2Eta, &b_ohIsoPixelTrackHBL2Eta);
   fChain->SetBranchAddress("ohIsoPixelTrackHBL2Phi", ohIsoPixelTrackHBL2Phi, &b_ohIsoPixelTrackHBL2Phi);
   fChain->SetBranchAddress("ohIsoPixelTrackHBL2MaxNearP", ohIsoPixelTrackHBL2MaxNearP, &b_ohIsoPixelTrackHBL2MaxNearP);
   fChain->SetBranchAddress("ohIsoPixelTrackHBL3N", &ohIsoPixelTrackHBL3N, &b_ohIsoPixelTrackHBL3N);
   fChain->SetBranchAddress("ohIsoPixelTrackHBL3P", ohIsoPixelTrackHBL3P, &b_ohIsoPixelTrackHBL3P);
   fChain->SetBranchAddress("ohIsoPixelTrackHBL3Eta", ohIsoPixelTrackHBL3Eta, &b_ohIsoPixelTrackHBL3Eta);
   fChain->SetBranchAddress("ohIsoPixelTrackHBL3Phi", ohIsoPixelTrackHBL3Phi, &b_ohIsoPixelTrackHBL3Phi);
   fChain->SetBranchAddress("ohIsoPixelTrackHBL3MaxNearP", ohIsoPixelTrackHBL3MaxNearP, &b_ohIsoPixelTrackHBL3MaxNearP);
   fChain->SetBranchAddress("ohIsoPixelTrackHEL2N", &ohIsoPixelTrackHEL2N, &b_ohIsoPixelTrackHEL2N);
   fChain->SetBranchAddress("ohIsoPixelTrackHEL2P", ohIsoPixelTrackHEL2P, &b_ohIsoPixelTrackHEL2P);
   fChain->SetBranchAddress("ohIsoPixelTrackHEL2Eta", ohIsoPixelTrackHEL2Eta, &b_ohIsoPixelTrackHEL2Eta);
   fChain->SetBranchAddress("ohIsoPixelTrackHEL2Phi", ohIsoPixelTrackHEL2Phi, &b_ohIsoPixelTrackHEL2Phi);
   fChain->SetBranchAddress("ohIsoPixelTrackHEL2MaxNearP", ohIsoPixelTrackHEL2MaxNearP, &b_ohIsoPixelTrackHEL2MaxNearP);
   fChain->SetBranchAddress("ohIsoPixelTrackHEL3N", &ohIsoPixelTrackHEL3N, &b_ohIsoPixelTrackHEL3N);
   fChain->SetBranchAddress("ohIsoPixelTrackHEL3P", ohIsoPixelTrackHEL3P, &b_ohIsoPixelTrackHEL3P);
   fChain->SetBranchAddress("ohIsoPixelTrackHEL3Eta", ohIsoPixelTrackHEL3Eta, &b_ohIsoPixelTrackHEL3Eta);
   fChain->SetBranchAddress("ohIsoPixelTrackHEL3Phi", ohIsoPixelTrackHEL3Phi, &b_ohIsoPixelTrackHEL3Phi);
   fChain->SetBranchAddress("ohIsoPixelTrackHEL3MaxNearP", ohIsoPixelTrackHEL3MaxNearP, &b_ohIsoPixelTrackHEL3MaxNearP);
   fChain->SetBranchAddress("NohDiMu", &NohDiMu, &b_NohDiMu);
   fChain->SetBranchAddress("ohDiMuDCA", ohDiMuDCA, &b_ohDiMuDCA);
   fChain->SetBranchAddress("ohDiMu1st", ohDiMu1st, &b_ohDiMu1st);
   fChain->SetBranchAddress("ohDiMu2nd", ohDiMu2nd, &b_ohDiMu2nd);
   fChain->SetBranchAddress("NohDiMuVtx", &NohDiMuVtx, &b_NohDiMuVtx);
   fChain->SetBranchAddress("ohDiMuVtx1st", ohDiMuVtx1st, &b_ohDiMuVtx1st);
   fChain->SetBranchAddress("ohDiMuVtx2nd", ohDiMuVtx2nd, &b_ohDiMuVtx2nd);
   fChain->SetBranchAddress("ohDiMuVtxChi2", ohDiMuVtxChi2, &b_ohDiMuVtxChi2);
   fChain->SetBranchAddress("ohDiMuVtxR", ohDiMuVtxR, &b_ohDiMuVtxR);
   fChain->SetBranchAddress("ohDiMuVtxRSig", ohDiMuVtxRSig, &b_ohDiMuVtxRSig);
   fChain->SetBranchAddress("ohDiMuVtxROverSig", ohDiMuVtxROverSig, &b_ohDiMuVtxROverSig);
   fChain->SetBranchAddress("ohDiMuVtxCosAlpha", ohDiMuVtxCosAlpha, &b_ohDiMuVtxCosAlpha);
   fChain->SetBranchAddress("NohOniaPixel", &NohOniaPixel, &b_NohOniaPixel);
   fChain->SetBranchAddress("ohOniaPixelPt", ohOniaPixelPt, &b_ohOniaPixelPt);
   fChain->SetBranchAddress("ohOniaPixelPhi", ohOniaPixelPhi, &b_ohOniaPixelPhi);
   fChain->SetBranchAddress("ohOniaPixelEta", ohOniaPixelEta, &b_ohOniaPixelEta);
   fChain->SetBranchAddress("ohOniaPixelChg", ohOniaPixelChg, &b_ohOniaPixelChg);
   fChain->SetBranchAddress("ohOniaPixelDr", ohOniaPixelDr, &b_ohOniaPixelDr);
   fChain->SetBranchAddress("ohOniaPixelDz", ohOniaPixelDz, &b_ohOniaPixelDz);
   fChain->SetBranchAddress("ohOniaPixelHits", ohOniaPixelHits, &b_ohOniaPixelHits);
   fChain->SetBranchAddress("ohOniaPixelNormChi2", ohOniaPixelNormChi2, &b_ohOniaPixelNormChi2);
   fChain->SetBranchAddress("NohOniaTrack", &NohOniaTrack, &b_NohOniaTrack);
   fChain->SetBranchAddress("ohOniaTrackPt", ohOniaTrackPt, &b_ohOniaTrackPt);
   fChain->SetBranchAddress("ohOniaTrackPhi", ohOniaTrackPhi, &b_ohOniaTrackPhi);
   fChain->SetBranchAddress("ohOniaTrackEta", ohOniaTrackEta, &b_ohOniaTrackEta);
   fChain->SetBranchAddress("ohOniaTrackChg", ohOniaTrackChg, &b_ohOniaTrackChg);
   fChain->SetBranchAddress("ohOniaTrackDr", ohOniaTrackDr, &b_ohOniaTrackDr);
   fChain->SetBranchAddress("ohOniaTrackDz", ohOniaTrackDz, &b_ohOniaTrackDz);
   fChain->SetBranchAddress("ohOniaTrackHits", ohOniaTrackHits, &b_ohOniaTrackHits);
   fChain->SetBranchAddress("ohOniaTrackNormChi2", ohOniaTrackNormChi2, &b_ohOniaTrackNormChi2);
   fChain->SetBranchAddress("NohpfTau", &NohpfTau, &b_NohpfTau);
   fChain->SetBranchAddress("ohpfTauPt", ohpfTauPt, &b_ohpfTauPt);
   fChain->SetBranchAddress("ohpfTauEta", ohpfTauEta, &b_ohpfTauEta);
   fChain->SetBranchAddress("ohpfTauPhi", ohpfTauPhi, &b_ohpfTauPhi);
   fChain->SetBranchAddress("ohpfTauLeadTrackPt", ohpfTauLeadTrackPt, &b_ohpfTauLeadTrackPt);
   fChain->SetBranchAddress("ohpfTauLeadTrackVtxZ", ohpfTauLeadTrackVtxZ, &b_ohpfTauLeadTrackVtxZ);
   fChain->SetBranchAddress("ohpfTauLeadPionPt", ohpfTauLeadPionPt, &b_ohpfTauLeadPionPt);
   fChain->SetBranchAddress("ohpfTauTrkIso", ohpfTauTrkIso, &b_ohpfTauTrkIso);
   fChain->SetBranchAddress("ohpfTauGammaIso", ohpfTauGammaIso, &b_ohpfTauGammaIso);
   fChain->SetBranchAddress("ohpfTauProngs", ohpfTauProngs, &b_ohpfTauProngs);
   fChain->SetBranchAddress("ohpfTauJetPt", ohpfTauJetPt, &b_ohpfTauJetPt);
   fChain->SetBranchAddress("NRecoPFTau", &NRecoPFTau, &b_NRecoPFTau);
   fChain->SetBranchAddress("pfTauPt", pfTauPt, &b_pfTauPt);
   fChain->SetBranchAddress("pfTauEta", pfTauEta, &b_pfTauEta);
   fChain->SetBranchAddress("pfTauPhi", pfTauPhi, &b_pfTauPhi);
   fChain->SetBranchAddress("pfTauLeadTrackPt", pfTauLeadTrackPt, &b_pfTauLeadTrackPt);
   fChain->SetBranchAddress("pfTauLeadPionPt", pfTauLeadPionPt, &b_pfTauLeadPionPt);
   fChain->SetBranchAddress("pfTauTrkIso", pfTauTrkIso, &b_pfTauTrkIso);
   fChain->SetBranchAddress("pfTauGammaIso", pfTauGammaIso, &b_pfTauGammaIso);
   fChain->SetBranchAddress("pfTauJetPt", pfTauJetPt, &b_pfTauJetPt);
   fChain->SetBranchAddress("pfMHT", &pfMHT, &b_pfMHT);
   fChain->SetBranchAddress("NohPFJet", &NohPFJet, &b_NohPFJet);
   fChain->SetBranchAddress("pfJetPt", pfJetPt, &b_pfJetPt);
   fChain->SetBranchAddress("pfJetEta", pfJetEta, &b_pfJetEta);
   fChain->SetBranchAddress("pfJetPhi", pfJetPhi, &b_pfJetPhi);
   fChain->SetBranchAddress("NMCpart", &NMCpart, &b_NMCpart);
   fChain->SetBranchAddress("MCpid", MCpid, &b_MCpid);
   fChain->SetBranchAddress("MCstatus", MCstatus, &b_MCstatus);
   fChain->SetBranchAddress("MCvtxX", MCvtxX, &b_MCvtxX);
   fChain->SetBranchAddress("MCvtxY", MCvtxY, &b_MCvtxY);
   fChain->SetBranchAddress("MCvtxZ", MCvtxZ, &b_MCvtxZ);
   fChain->SetBranchAddress("MCpt", MCpt, &b_MCpt);
   fChain->SetBranchAddress("MCeta", MCeta, &b_MCeta);
   fChain->SetBranchAddress("MCphi", MCphi, &b_MCphi);
   fChain->SetBranchAddress("MCPtHat", &MCPtHat, &b_MCPtHat);
   fChain->SetBranchAddress("MCmu3", &MCmu3, &b_MCmu3);
   fChain->SetBranchAddress("MCel3", &MCel3, &b_MCel3);
   fChain->SetBranchAddress("MCbb", &MCbb, &b_MCbb);
   fChain->SetBranchAddress("MCab", &MCab, &b_MCab);
   fChain->SetBranchAddress("MCWenu", &MCWenu, &b_MCWenu);
   fChain->SetBranchAddress("MCWmunu", &MCWmunu, &b_MCmunu);
   fChain->SetBranchAddress("MCZee", &MCZee, &b_MCZee);
   fChain->SetBranchAddress("MCZmumu", &MCZmumu, &b_MCZmumu);
   fChain->SetBranchAddress("MCptEleMax", &MCptEleMax, &b_MCptEleMax);
   fChain->SetBranchAddress("MCptMuMax", &MCptMuMax, &b_MCptMuMax);
   fChain->SetBranchAddress("NL1IsolEm", &NL1IsolEm, &b_NL1IsolEm);
   fChain->SetBranchAddress("L1IsolEmEt", L1IsolEmEt, &b_L1IsolEmEt);
   fChain->SetBranchAddress("L1IsolEmE", L1IsolEmE, &b_L1IsolEmE);
   fChain->SetBranchAddress("L1IsolEmEta", L1IsolEmEta, &b_L1IsolEmEta);
   fChain->SetBranchAddress("L1IsolEmPhi", L1IsolEmPhi, &b_L1IsolEmPhi);
   fChain->SetBranchAddress("NL1NIsolEm", &NL1NIsolEm, &b_NL1NIsolEm);
   fChain->SetBranchAddress("L1NIsolEmEt", L1NIsolEmEt, &b_L1NIsolEmEt);
   fChain->SetBranchAddress("L1NIsolEmE", L1NIsolEmE, &b_L1NIsolEmE);
   fChain->SetBranchAddress("L1NIsolEmEta", L1NIsolEmEta, &b_L1NIsolEmEta);
   fChain->SetBranchAddress("L1NIsolEmPhi", L1NIsolEmPhi, &b_L1NIsolEmPhi);
   fChain->SetBranchAddress("NL1Mu", &NL1Mu, &b_NL1Mu);
   fChain->SetBranchAddress("L1MuPt", L1MuPt, &b_L1MuPt);
   fChain->SetBranchAddress("L1MuE", L1MuE, &b_L1MuE);
   fChain->SetBranchAddress("L1MuEta", L1MuEta, &b_L1MuEta);
   fChain->SetBranchAddress("L1MuPhi", L1MuPhi, &b_L1MuPhi);
   fChain->SetBranchAddress("L1MuIsol", L1MuIsol, &b_L1MuIsol);
   fChain->SetBranchAddress("L1MuMip", L1MuMip, &b_L1MuMip);
   fChain->SetBranchAddress("L1MuFor", L1MuFor, &b_L1MuFor);
   fChain->SetBranchAddress("L1MuRPC", L1MuRPC, &b_L1MuRPC);
   fChain->SetBranchAddress("L1MuQal", L1MuQal, &b_L1MuQal);
   fChain->SetBranchAddress("NL1CenJet", &NL1CenJet, &b_NL1CenJet);
   fChain->SetBranchAddress("L1CenJetEt", L1CenJetEt, &b_L1CenJetEt);
   fChain->SetBranchAddress("L1CenJetE", L1CenJetE, &b_L1CenJetE);
   fChain->SetBranchAddress("L1CenJetEta", L1CenJetEta, &b_L1CenJetEta);
   fChain->SetBranchAddress("L1CenJetPhi", L1CenJetPhi, &b_L1CenJetPhi);
   fChain->SetBranchAddress("NL1ForJet", &NL1ForJet, &b_NL1ForJet);
   fChain->SetBranchAddress("L1ForJetEt", L1ForJetEt, &b_L1ForJetEt);
   fChain->SetBranchAddress("L1ForJetE", L1ForJetE, &b_L1ForJetE);
   fChain->SetBranchAddress("L1ForJetEta", L1ForJetEta, &b_L1ForJetEta);
   fChain->SetBranchAddress("L1ForJetPhi", L1ForJetPhi, &b_L1ForJetPhi);
   fChain->SetBranchAddress("NL1Tau", &NL1Tau, &b_NL1Tau);
   fChain->SetBranchAddress("L1TauEt", L1TauEt, &b_L1TauEt);
   fChain->SetBranchAddress("L1TauE", L1TauE, &b_L1TauE);
   fChain->SetBranchAddress("L1TauEta", L1TauEta, &b_L1TauEta);
   fChain->SetBranchAddress("L1TauPhi", L1TauPhi, &b_L1TauPhi);
   fChain->SetBranchAddress("L1Met", &L1Met, &b_L1Met);
   fChain->SetBranchAddress("L1MetPhi", &L1MetPhi, &b_L1MetPhi);
   fChain->SetBranchAddress("L1MetTot", &L1MetTot, &b_L1MetTot);
   fChain->SetBranchAddress("L1MetHad", &L1MetHad, &b_L1MetHad);
   fChain->SetBranchAddress("L1EtTot", &L1EtTot, &b_L1EtTot);
   fChain->SetBranchAddress("L1HfRing0EtSumPositiveEta", &L1HfRing0EtSumPositiveEta, &b_L1HfRing0EtSumPositiveEta);
   fChain->SetBranchAddress("L1HfRing1EtSumPositiveEta", &L1HfRing1EtSumPositiveEta, &b_L1HfRing1EtSumPositiveEta);
   fChain->SetBranchAddress("L1HfRing0EtSumNegativeEta", &L1HfRing0EtSumNegativeEta, &b_L1HfRing0EtSumNegativeEta);
   fChain->SetBranchAddress("L1HfRing1EtSumNegativeEta", &L1HfRing1EtSumNegativeEta, &b_L1HfRing1EtSumNegativeEta);
   fChain->SetBranchAddress("L1HfTowerCountPositiveEta", &L1HfTowerCountPositiveEta, &b_L1HfTowerCountPositiveEta);
   fChain->SetBranchAddress("L1HfTowerCountNegativeEta", &L1HfTowerCountNegativeEta, &b_L1HfTowerCountNegativeEta);
   fChain->SetBranchAddress("L1HfTowerCountNegativeEtaRing1", &L1HfTowerCountNegativeEtaRing1, &b_L1HfTowerCountNegativeEtaRing1);
   fChain->SetBranchAddress("L1HfTowerCountPositiveEtaRing1", &L1HfTowerCountPositiveEtaRing1, &b_L1HfTowerCountPositiveEtaRing1);
   fChain->SetBranchAddress("L1HfTowerCountNegativeEtaRing2", &L1HfTowerCountNegativeEtaRing2, &b_L1HfTowerCountNegativeEtaRing2);
   fChain->SetBranchAddress("L1HfTowerCountPositiveEtaRing2", &L1HfTowerCountPositiveEtaRing2, &b_L1HfTowerCountPositiveEtaRing2);
   fChain->SetBranchAddress("Run", &Run, &b_Run);
   fChain->SetBranchAddress("Event", &Event, &b_Event);
   fChain->SetBranchAddress("LumiBlock", &LumiBlock, &b_LumiBlock);
   fChain->SetBranchAddress("Bx", &Bx, &b_Bx);
   fChain->SetBranchAddress("Orbit", &Orbit, &b_Orbit);
   fChain->SetBranchAddress("AvgInstDelLumi", &AvgInstDelLumi, &b_AvgInstDelLumi);

   // Autogenerated L1 - SetBranchAddressBits 
  fChain->SetBranchAddress("L1_SingleJet20_Central_NotBptxOR", &L1_SingleJet20_Central_NotBptxOR, &b_L1_SingleJet20_Central_NotBptxOR);
  fChain->SetBranchAddress("L1_SingleJet16_FwdVeto5", &L1_SingleJet16_FwdVeto5, &b_L1_SingleJet16_FwdVeto5);
  fChain->SetBranchAddress("L1_ETT80", &L1_ETT80, &b_L1_ETT80);
  fChain->SetBranchAddress("L1_DoubleForJet16_EtaOpp", &L1_DoubleForJet16_EtaOpp, &b_L1_DoubleForJet16_EtaOpp);
  fChain->SetBranchAddress("L1_DoubleMu0_HighQ_EtaCuts", &L1_DoubleMu0_HighQ_EtaCuts, &b_L1_DoubleMu0_HighQ_EtaCuts);
  fChain->SetBranchAddress("L1_DoubleEG3_FwdVeto", &L1_DoubleEG3_FwdVeto, &b_L1_DoubleEG3_FwdVeto);
  fChain->SetBranchAddress("L1_SingleForJet16", &L1_SingleForJet16, &b_L1_SingleForJet16);
  fChain->SetBranchAddress("L1_DoubleMu_5er_0er_HighQ_WdEta22", &L1_DoubleMu_5er_0er_HighQ_WdEta22, &b_L1_DoubleMu_5er_0er_HighQ_WdEta22);
  fChain->SetBranchAddress("L1_DoubleMu3er_HighQ_WdEta22", &L1_DoubleMu3er_HighQ_WdEta22, &b_L1_DoubleMu3er_HighQ_WdEta22);
  fChain->SetBranchAddress("L1_BeamHalo", &L1_BeamHalo, &b_L1_BeamHalo);
  fChain->SetBranchAddress("L1_InterBunch_Bptx", &L1_InterBunch_Bptx, &b_L1_InterBunch_Bptx);
  fChain->SetBranchAddress("L1_BeamGas_Hf_BptxPlusPostQuiet", &L1_BeamGas_Hf_BptxPlusPostQuiet, &b_L1_BeamGas_Hf_BptxPlusPostQuiet);
  fChain->SetBranchAddress("L1_BeamGas_Hf_BptxMinusPostQuiet", &L1_BeamGas_Hf_BptxMinusPostQuiet, &b_L1_BeamGas_Hf_BptxMinusPostQuiet);
  fChain->SetBranchAddress("L1_ZeroBias_Instance1", &L1_ZeroBias_Instance1, &b_L1_ZeroBias_Instance1);
  fChain->SetBranchAddress("L1_SingleMu6_NotBptxOR", &L1_SingleMu6_NotBptxOR, &b_L1_SingleMu6_NotBptxOR);
  fChain->SetBranchAddress("L1_SingleJetC20_NotBptxOR", &L1_SingleJetC20_NotBptxOR, &b_L1_SingleJetC20_NotBptxOR);
  fChain->SetBranchAddress("L1_SingleJetC32_NotBptxOR", &L1_SingleJetC32_NotBptxOR, &b_L1_SingleJetC32_NotBptxOR);
  fChain->SetBranchAddress("L1_TripleMu_5_5_0", &L1_TripleMu_5_5_0, &b_L1_TripleMu_5_5_0);
  fChain->SetBranchAddress("L1_TripleMu0_HighQ", &L1_TripleMu0_HighQ, &b_L1_TripleMu0_HighQ);
  fChain->SetBranchAddress("L1_DoubleMu_10_3p5", &L1_DoubleMu_10_3p5, &b_L1_DoubleMu_10_3p5);
  fChain->SetBranchAddress("L1_DoubleMu_12_5", &L1_DoubleMu_12_5, &b_L1_DoubleMu_12_5);
  fChain->SetBranchAddress("L1_DoubleMuHighQ_5_0_Eta2p1_WdEta22", &L1_DoubleMuHighQ_5_0_Eta2p1_WdEta22, &b_L1_DoubleMuHighQ_5_0_Eta2p1_WdEta22);
  fChain->SetBranchAddress("L1_DoubleMuHighQ_3_3_Eta2p1_WdEta22", &L1_DoubleMuHighQ_3_3_Eta2p1_WdEta22, &b_L1_DoubleMuHighQ_3_3_Eta2p1_WdEta22);
  fChain->SetBranchAddress("L1_DoubleMu0er_HighQ", &L1_DoubleMu0er_HighQ, &b_L1_DoubleMu0er_HighQ);
  fChain->SetBranchAddress("L1_SingleMu25er", &L1_SingleMu25er, &b_L1_SingleMu25er);
  fChain->SetBranchAddress("L1_SingleMu20er", &L1_SingleMu20er, &b_L1_SingleMu20er);
  fChain->SetBranchAddress("L1_SingleMu18er", &L1_SingleMu18er, &b_L1_SingleMu18er);
  fChain->SetBranchAddress("L1_SingleMu16er", &L1_SingleMu16er, &b_L1_SingleMu16er);
  fChain->SetBranchAddress("L1_SingleMu14er", &L1_SingleMu14er, &b_L1_SingleMu14er);
  fChain->SetBranchAddress("L1_DoubleJetC44_ETM30", &L1_DoubleJetC44_ETM30, &b_L1_DoubleJetC44_ETM30);
  fChain->SetBranchAddress("L1_DoubleJetC36_ETM30", &L1_DoubleJetC36_ETM30, &b_L1_DoubleJetC36_ETM30);
  fChain->SetBranchAddress("L1_Mu5_DoubleEG6", &L1_Mu5_DoubleEG6, &b_L1_Mu5_DoubleEG6);
  fChain->SetBranchAddress("L1_Mu5_DoubleEG5", &L1_Mu5_DoubleEG5, &b_L1_Mu5_DoubleEG5);
  fChain->SetBranchAddress("L1_DoubleMu5_EG5", &L1_DoubleMu5_EG5, &b_L1_DoubleMu5_EG5);
  fChain->SetBranchAddress("L1_DoubleMu3p5_EG5", &L1_DoubleMu3p5_EG5, &b_L1_DoubleMu3p5_EG5);
  fChain->SetBranchAddress("L1_Mu3p5_EG12", &L1_Mu3p5_EG12, &b_L1_Mu3p5_EG12);
  fChain->SetBranchAddress("L1_Mu12_EG7", &L1_Mu12_EG7, &b_L1_Mu12_EG7);
  fChain->SetBranchAddress("L1_EG8_DoubleJetC20", &L1_EG8_DoubleJetC20, &b_L1_EG8_DoubleJetC20);
  fChain->SetBranchAddress("L1_EG18er_JetC_Cen36_Tau28_dPhi1", &L1_EG18er_JetC_Cen36_Tau28_dPhi1, &b_L1_EG18er_JetC_Cen36_Tau28_dPhi1);
  fChain->SetBranchAddress("L1_IsoEG18er_JetC_Cen36_Tau28_dPhi1", &L1_IsoEG18er_JetC_Cen36_Tau28_dPhi1, &b_L1_IsoEG18er_JetC_Cen36_Tau28_dPhi1);
  fChain->SetBranchAddress("L1_IsoEG18er_JetC_Cen32_Tau24_dPhi1", &L1_IsoEG18er_JetC_Cen32_Tau24_dPhi1, &b_L1_IsoEG18er_JetC_Cen32_Tau24_dPhi1);
  fChain->SetBranchAddress("L1_EG18er_JetC_Cen28_Tau20_dPhi1", &L1_EG18er_JetC_Cen28_Tau20_dPhi1, &b_L1_EG18er_JetC_Cen28_Tau20_dPhi1);
  fChain->SetBranchAddress("L1_DoubleEG6_HTT125", &L1_DoubleEG6_HTT125, &b_L1_DoubleEG6_HTT125);
  fChain->SetBranchAddress("L1_DoubleEG6_HTT100", &L1_DoubleEG6_HTT100, &b_L1_DoubleEG6_HTT100);
  fChain->SetBranchAddress("L1_EG22_ForJet32", &L1_EG22_ForJet32, &b_L1_EG22_ForJet32);
  fChain->SetBranchAddress("L1_EG22_ForJet24", &L1_EG22_ForJet24, &b_L1_EG22_ForJet24);
  fChain->SetBranchAddress("L1_Mu8_DoubleJetC20", &L1_Mu8_DoubleJetC20, &b_L1_Mu8_DoubleJetC20);
  fChain->SetBranchAddress("L1_Mu10er_JetC12_WdEtaPhi1_DoubleJetC_32_12", &L1_Mu10er_JetC12_WdEtaPhi1_DoubleJetC_32_12, &b_L1_Mu10er_JetC12_WdEtaPhi1_DoubleJetC_32_12);
  fChain->SetBranchAddress("L1_Mu10er_JetC32", &L1_Mu10er_JetC32, &b_L1_Mu10er_JetC32);
  fChain->SetBranchAddress("L1_Mu10er_JetC12_WdEtaPhi1_DoubleJetC_20_12", &L1_Mu10er_JetC12_WdEtaPhi1_DoubleJetC_20_12, &b_L1_Mu10er_JetC12_WdEtaPhi1_DoubleJetC_20_12);
  fChain->SetBranchAddress("L1_Mu12er_ETM20", &L1_Mu12er_ETM20, &b_L1_Mu12er_ETM20);
  fChain->SetBranchAddress("L1_Mu4_HTT125", &L1_Mu4_HTT125, &b_L1_Mu4_HTT125);
  fChain->SetBranchAddress("L1_Mu0_HTT100", &L1_Mu0_HTT100, &b_L1_Mu0_HTT100);
  fChain->SetBranchAddress("L1_DoubleTauJet44er", &L1_DoubleTauJet44er, &b_L1_DoubleTauJet44er);
  fChain->SetBranchAddress("L1_QuadJetC40", &L1_QuadJetC40, &b_L1_QuadJetC40);
  fChain->SetBranchAddress("L1_QuadJetC36", &L1_QuadJetC36, &b_L1_QuadJetC36);
  fChain->SetBranchAddress("L1_QuadJetC32", &L1_QuadJetC32, &b_L1_QuadJetC32);
  fChain->SetBranchAddress("L1_TripleJetC_52_28_28", &L1_TripleJetC_52_28_28, &b_L1_TripleJetC_52_28_28);
  fChain->SetBranchAddress("L1_TripleJet_68_48_32_VBF", &L1_TripleJet_68_48_32_VBF, &b_L1_TripleJet_68_48_32_VBF);
  fChain->SetBranchAddress("L1_TripleJet_64_48_28_VBF", &L1_TripleJet_64_48_28_VBF, &b_L1_TripleJet_64_48_28_VBF);
  fChain->SetBranchAddress("L1_TripleJet_64_44_24_VBF", &L1_TripleJet_64_44_24_VBF, &b_L1_TripleJet_64_44_24_VBF);
  fChain->SetBranchAddress("L1_DoubleJetC64", &L1_DoubleJetC64, &b_L1_DoubleJetC64);
  fChain->SetBranchAddress("L1_DoubleJetC56", &L1_DoubleJetC56, &b_L1_DoubleJetC56);
  fChain->SetBranchAddress("L1_DoubleJetC56_Eta1p74_WdEta4", &L1_DoubleJetC56_Eta1p74_WdEta4, &b_L1_DoubleJetC56_Eta1p74_WdEta4);
  fChain->SetBranchAddress("L1_DoubleJetC52", &L1_DoubleJetC52, &b_L1_DoubleJetC52);
  fChain->SetBranchAddress("L1_DoubleJetC44_Eta1p74_WdEta4", &L1_DoubleJetC44_Eta1p74_WdEta4, &b_L1_DoubleJetC44_Eta1p74_WdEta4);
  fChain->SetBranchAddress("L1_DoubleJetC36", &L1_DoubleJetC36, &b_L1_DoubleJetC36);
  fChain->SetBranchAddress("L1_TripleEG_12_7_5", &L1_TripleEG_12_7_5, &b_L1_TripleEG_12_7_5);
  fChain->SetBranchAddress("L1_DoubleEG_13_7", &L1_DoubleEG_13_7, &b_L1_DoubleEG_13_7);
  fChain->SetBranchAddress("L1_SingleEG24", &L1_SingleEG24, &b_L1_SingleEG24);
  fChain->SetBranchAddress("L1_SingleEG22", &L1_SingleEG22, &b_L1_SingleEG22);
  fChain->SetBranchAddress("L1_SingleIsoEG20er", &L1_SingleIsoEG20er, &b_L1_SingleIsoEG20er);
  fChain->SetBranchAddress("L1_SingleIsoEG18er", &L1_SingleIsoEG18er, &b_L1_SingleIsoEG18er);
  fChain->SetBranchAddress("L1_SingleEG18er", &L1_SingleEG18er, &b_L1_SingleEG18er);
  fChain->SetBranchAddress("L1_SingleEG7", &L1_SingleEG7, &b_L1_SingleEG7);
  fChain->SetBranchAddress("L1_ETT300", &L1_ETT300, &b_L1_ETT300);
  fChain->SetBranchAddress("L1_HTT175", &L1_HTT175, &b_L1_HTT175);
  fChain->SetBranchAddress("L1_HTT150", &L1_HTT150, &b_L1_HTT150);
  fChain->SetBranchAddress("L1_HTT125", &L1_HTT125, &b_L1_HTT125);
  fChain->SetBranchAddress("L1_ETM100", &L1_ETM100, &b_L1_ETM100);
  fChain->SetBranchAddress("L1_ETM50", &L1_ETM50, &b_L1_ETM50);
  fChain->SetBranchAddress("L1_ETM36", &L1_ETM36, &b_L1_ETM36);
  fChain->SetBranchAddress("L1_QuadJet28_Central", &L1_QuadJet28_Central, &b_L1_QuadJet28_Central);
  fChain->SetBranchAddress("L1_SingleJet128", &L1_SingleJet128, &b_L1_SingleJet128);
  fChain->SetBranchAddress("L1_DoubleMu_10_Open", &L1_DoubleMu_10_Open, &b_L1_DoubleMu_10_Open);
  fChain->SetBranchAddress("L1_SingleEG18", &L1_SingleEG18, &b_L1_SingleEG18);
  fChain->SetBranchAddress("L1_Mu10_Eta2p1_DoubleJet_16_8_Central", &L1_Mu10_Eta2p1_DoubleJet_16_8_Central, &b_L1_Mu10_Eta2p1_DoubleJet_16_8_Central);
  fChain->SetBranchAddress("L1_Mu12_EG5", &L1_Mu12_EG5, &b_L1_Mu12_EG5);
  fChain->SetBranchAddress("L1_SingleMu16_Eta2p1", &L1_SingleMu16_Eta2p1, &b_L1_SingleMu16_Eta2p1);
  fChain->SetBranchAddress("L1_DoubleMu0_HighQ", &L1_DoubleMu0_HighQ, &b_L1_DoubleMu0_HighQ);
  fChain->SetBranchAddress("L1_SingleMu14_Eta2p1", &L1_SingleMu14_Eta2p1, &b_L1_SingleMu14_Eta2p1);
  fChain->SetBranchAddress("L1_HTT50_HTM30", &L1_HTT50_HTM30, &b_L1_HTT50_HTM30);
  fChain->SetBranchAddress("L1_DoubleEG5_HTT75", &L1_DoubleEG5_HTT75, &b_L1_DoubleEG5_HTT75);
  fChain->SetBranchAddress("L1_DoubleJet64_Central", &L1_DoubleJet64_Central, &b_L1_DoubleJet64_Central);
  fChain->SetBranchAddress("L1_DoubleTauJet44_Eta2p17", &L1_DoubleTauJet44_Eta2p17, &b_L1_DoubleTauJet44_Eta2p17);
  fChain->SetBranchAddress("L1_TripleJet_36_36_12_Central", &L1_TripleJet_36_36_12_Central, &b_L1_TripleJet_36_36_12_Central);
  fChain->SetBranchAddress("L1_EG5_HTT100", &L1_EG5_HTT100, &b_L1_EG5_HTT100);
  fChain->SetBranchAddress("L1_EG5_DoubleJet20_Central", &L1_EG5_DoubleJet20_Central, &b_L1_EG5_DoubleJet20_Central);
  fChain->SetBranchAddress("L1_TripleMu0", &L1_TripleMu0, &b_L1_TripleMu0);
  fChain->SetBranchAddress("L1_DoubleMu3p5", &L1_DoubleMu3p5, &b_L1_DoubleMu3p5);
  fChain->SetBranchAddress("L1_MuOpen_DoubleEG5", &L1_MuOpen_DoubleEG5, &b_L1_MuOpen_DoubleEG5);
  fChain->SetBranchAddress("L1_DoubleMuOpen_EG5", &L1_DoubleMuOpen_EG5, &b_L1_DoubleMuOpen_EG5);
  fChain->SetBranchAddress("L1_DoubleEG_12_5", &L1_DoubleEG_12_5, &b_L1_DoubleEG_12_5);
  fChain->SetBranchAddress("L1_DoubleTauJet36_Eta2p17", &L1_DoubleTauJet36_Eta2p17, &b_L1_DoubleTauJet36_Eta2p17);
  fChain->SetBranchAddress("L1_SingleJet52_Central", &L1_SingleJet52_Central, &b_L1_SingleJet52_Central);
  fChain->SetBranchAddress("L1_DoubleJet52_Central", &L1_DoubleJet52_Central, &b_L1_DoubleJet52_Central);
  fChain->SetBranchAddress("L1_DoubleTauJet40_Eta2p17", &L1_DoubleTauJet40_Eta2p17, &b_L1_DoubleTauJet40_Eta2p17);
  fChain->SetBranchAddress("L1_Jet52_Central_ETM30", &L1_Jet52_Central_ETM30, &b_L1_Jet52_Central_ETM30);
  fChain->SetBranchAddress("L1_DoubleJet44_Central", &L1_DoubleJet44_Central, &b_L1_DoubleJet44_Central);
  fChain->SetBranchAddress("L1_Mu7_EG5", &L1_Mu7_EG5, &b_L1_Mu7_EG5);
  fChain->SetBranchAddress("L1_MuOpen_EG12", &L1_MuOpen_EG12, &b_L1_MuOpen_EG12);
  fChain->SetBranchAddress("L1_DoubleTauJet36", &L1_DoubleTauJet36, &b_L1_DoubleTauJet36);
  fChain->SetBranchAddress("L1_TripleJet28_Central", &L1_TripleJet28_Central, &b_L1_TripleJet28_Central);
  fChain->SetBranchAddress("L1_SingleJet36_FwdVeto5", &L1_SingleJet36_FwdVeto5, &b_L1_SingleJet36_FwdVeto5);
  fChain->SetBranchAddress("L1_SingleTauJet68", &L1_SingleTauJet68, &b_L1_SingleTauJet68);
  fChain->SetBranchAddress("L1_MuOpen_EG5", &L1_MuOpen_EG5, &b_L1_MuOpen_EG5);
  fChain->SetBranchAddress("L1_SingleMu5_Eta1p5_Q80_v1", &L1_SingleMu5_Eta1p5_Q80_v1, &b_L1_SingleMu5_Eta1p5_Q80_v1);
  fChain->SetBranchAddress("L1_HTT75", &L1_HTT75, &b_L1_HTT75);
  fChain->SetBranchAddress("L1_ETT220", &L1_ETT220, &b_L1_ETT220);
  fChain->SetBranchAddress("L1_SingleJet20_NotBptxOR", &L1_SingleJet20_NotBptxOR, &b_L1_SingleJet20_NotBptxOR);
  fChain->SetBranchAddress("L1_BeamGas_Bsc", &L1_BeamGas_Bsc, &b_L1_BeamGas_Bsc);
  fChain->SetBranchAddress("L1_PreCollisions", &L1_PreCollisions, &b_L1_PreCollisions);
  fChain->SetBranchAddress("L1_BeamGas_Hf", &L1_BeamGas_Hf, &b_L1_BeamGas_Hf);
  fChain->SetBranchAddress("L1_Mu3_Jet20_Central", &L1_Mu3_Jet20_Central, &b_L1_Mu3_Jet20_Central);
  fChain->SetBranchAddress("L1_Mu3_Jet28_Central", &L1_Mu3_Jet28_Central, &b_L1_Mu3_Jet28_Central);
  fChain->SetBranchAddress("L1_Mu3_Jet16_Central", &L1_Mu3_Jet16_Central, &b_L1_Mu3_Jet16_Central);
  fChain->SetBranchAddress("L1_Mu7_Jet20_Central", &L1_Mu7_Jet20_Central, &b_L1_Mu7_Jet20_Central);
  fChain->SetBranchAddress("L1_Mu3_JetC16_WdEtaPhi2", &L1_Mu3_JetC16_WdEtaPhi2, &b_L1_Mu3_JetC16_WdEtaPhi2);
  fChain->SetBranchAddress("L1_Mu3_JetC52_WdEtaPhi2", &L1_Mu3_JetC52_WdEtaPhi2, &b_L1_Mu3_JetC52_WdEtaPhi2);

  fChain->SetBranchAddress("L1_DoubleEG5_HTT50", &L1_DoubleEG5_HTT50, &b_L1_DoubleEG5_HTT50);
  fChain->SetBranchAddress("L1_EG5_HTT75", &L1_EG5_HTT75, &b_L1_EG5_HTT75);
  fChain->SetBranchAddress("L1_DoubleJet52", &L1_DoubleJet52, &b_L1_DoubleJet52);
  fChain->SetBranchAddress("L1_SingleTauJet52", &L1_SingleTauJet52, &b_L1_SingleTauJet52);
  fChain->SetBranchAddress("L1_DoubleTauJet28", &L1_DoubleTauJet28, &b_L1_DoubleTauJet28);
  fChain->SetBranchAddress("L1_SingleJet20_NotBptxOR_NotMuBeamHalo", &L1_SingleJet20_NotBptxOR_NotMuBeamHalo, &b_L1_SingleJet20_NotBptxOR_NotMuBeamHalo);
  fChain->SetBranchAddress("L1_SingleJet16", &L1_SingleJet16, &b_L1_SingleJet16);
  fChain->SetBranchAddress("L1_SingleJet68", &L1_SingleJet68, &b_L1_SingleJet68);
  fChain->SetBranchAddress("L1_SingleJet92", &L1_SingleJet92, &b_L1_SingleJet92);
  fChain->SetBranchAddress("L1_DoubleForJet32_EtaOpp", &L1_DoubleForJet32_EtaOpp, &b_L1_DoubleForJet32_EtaOpp);
  fChain->SetBranchAddress("L1_DoubleForJet44_EtaOpp", &L1_DoubleForJet44_EtaOpp, &b_L1_DoubleForJet44_EtaOpp);
  fChain->SetBranchAddress("L1_DoubleEG2_FwdVeto", &L1_DoubleEG2_FwdVeto, &b_L1_DoubleEG2_FwdVeto);
  fChain->SetBranchAddress("L1_SingleJet36_FwdVeto", &L1_SingleJet36_FwdVeto, &b_L1_SingleJet36_FwdVeto);
  fChain->SetBranchAddress("L1_TripleEG7", &L1_TripleEG7, &b_L1_TripleEG7);
  fChain->SetBranchAddress("L1_TripleEG5", &L1_TripleEG5, &b_L1_TripleEG5);
  fChain->SetBranchAddress("L1_TripleJet28", &L1_TripleJet28, &b_L1_TripleJet28);
  fChain->SetBranchAddress("L1_Mu0_HTT50", &L1_Mu0_HTT50, &b_L1_Mu0_HTT50);
  fChain->SetBranchAddress("L1_SingleEG12_Eta2p17", &L1_SingleEG12_Eta2p17, &b_L1_SingleEG12_Eta2p17);
  fChain->SetBranchAddress("L1_SingleEG30", &L1_SingleEG30, &b_L1_SingleEG30);
  fChain->SetBranchAddress("L1_Mu3_Jet20", &L1_Mu3_Jet20, &b_L1_Mu3_Jet20);
  fChain->SetBranchAddress("L1_Mu3_Jet16", &L1_Mu3_Jet16, &b_L1_Mu3_Jet16);
  fChain->SetBranchAddress("L1_SingleMu16", &L1_SingleMu16, &b_L1_SingleMu16);
  fChain->SetBranchAddress("L1_SingleMu25", &L1_SingleMu25, &b_L1_SingleMu25);
  fChain->SetBranchAddress("L1_DoubleMu5", &L1_DoubleMu5, &b_L1_DoubleMu5);
  fChain->SetBranchAddress("L1_SingleMu5_Eta1p5_Q80", &L1_SingleMu5_Eta1p5_Q80, &b_L1_SingleMu5_Eta1p5_Q80);
  fChain->SetBranchAddress("L1_DoubleMu_0_5", &L1_DoubleMu_0_5, &b_L1_DoubleMu_0_5);
  fChain->SetBranchAddress("L1_SingleMu12", &L1_SingleMu12, &b_L1_SingleMu12);
  fChain->SetBranchAddress("L1_DoubleMu0", &L1_DoubleMu0, &b_L1_DoubleMu0);
  fChain->SetBranchAddress("L1_QuadJet20_Central", &L1_QuadJet20_Central, &b_L1_QuadJet20_Central);
  fChain->SetBranchAddress("L1_DoubleJet36_Central", &L1_DoubleJet36_Central, &b_L1_DoubleJet36_Central);
  fChain->SetBranchAddress("L1_SingleJet52", &L1_SingleJet52, &b_L1_SingleJet52);
  fChain->SetBranchAddress("L1_SingleJet36", &L1_SingleJet36, &b_L1_SingleJet36);
   fChain->SetBranchAddress("L1_Mu3_Jet10", &L1_Mu3_Jet10, &b_L1_Mu3_Jet10);
   fChain->SetBranchAddress("L1_SingleJet10U_NotBptxOR_Ext", &L1_SingleJet10U_NotBptxOR_Ext, &b_L1_SingleJet10U_NotBptxOR_Ext);
   fChain->SetBranchAddress("L1_SingleJet10_NotBptxOR_Ext", &L1_SingleJet10_NotBptxOR_Ext, &b_L1_SingleJet10_NotBptxOR_Ext);
   fChain->SetBranchAddress("L1_SingleJet10U_NotBptxOR", &L1_SingleJet10U_NotBptxOR, &b_L1_SingleJet10U_NotBptxOR);
   fChain->SetBranchAddress("L1_SingleJet10_NotBptxOR", &L1_SingleJet10_NotBptxOR, &b_L1_SingleJet10_NotBptxOR);
   fChain->SetBranchAddress("L1_Mu3_EG5", &L1_Mu3_EG5, &b_L1_Mu3_EG5);

   //L1 algorithm bits 
   fChain->SetBranchAddress("L1_DoubleMuTopBottom", &L1_DoubleMuTopBottom, &b_L1_DoubleMuTopBottom);
   fChain->SetBranchAddress("L1_DoubleEG05_TopBottom", &L1_DoubleEG05_TopBottom, &b_L1_DoubleEG05_TopBottom);
   fChain->SetBranchAddress("L1_IsoEG10_Jet6_ForJet6", &L1_IsoEG10_Jet6_ForJet6, &b_L1_IsoEG10_Jet6_ForJet6);
   fChain->SetBranchAddress("L1_SingleJet20", &L1_SingleJet20, &b_L1_SingleJet20);
   fChain->SetBranchAddress("L1_SingleJet40", &L1_SingleJet40, &b_L1_SingleJet40);
   fChain->SetBranchAddress("L1_SingleJet60", &L1_SingleJet60, &b_L1_SingleJet60);
   fChain->SetBranchAddress("L1_SingleTauJet10", &L1_SingleTauJet10, &b_L1_SingleTauJet10);
   fChain->SetBranchAddress("L1_SingleTauJet20", &L1_SingleTauJet20, &b_L1_SingleTauJet20);
   fChain->SetBranchAddress("L1_SingleTauJet50", &L1_SingleTauJet50, &b_L1_SingleTauJet50);
   fChain->SetBranchAddress("L1_DoubleJet30", &L1_DoubleJet30, &b_L1_DoubleJet30);
   fChain->SetBranchAddress("L1_TripleJet14", &L1_TripleJet14, &b_L1_TripleJet14);
   fChain->SetBranchAddress("L1_QuadJet6", &L1_QuadJet6, &b_L1_QuadJet6);
   fChain->SetBranchAddress("L1_QuadJet8", &L1_QuadJet8, &b_L1_QuadJet8);
   fChain->SetBranchAddress("L1_Mu5_Jet6", &L1_Mu5_Jet6, &b_L1_Mu5_Jet6);
   fChain->SetBranchAddress("L1_EG5_TripleJet6", &L1_EG5_TripleJet6, &b_L1_EG5_TripleJet6);
   fChain->SetBranchAddress("L1_SingleJet6", &L1_SingleJet6, &b_L1_SingleJet6);
   fChain->SetBranchAddress("L1_SingleJet10", &L1_SingleJet10, &b_L1_SingleJet10);
   fChain->SetBranchAddress("L1_SingleJet10_NotBptxC_Ext", &L1_SingleJet10_NotBptxC_Ext, &b_L1_SingleJet10_NotBptxC_Ext);
   fChain->SetBranchAddress("L1_DoubleEG1", &L1_DoubleEG1, &b_L1_DoubleEG1);
   fChain->SetBranchAddress("L1_DoubleEG2", &L1_DoubleEG2, &b_L1_DoubleEG2);
   fChain->SetBranchAddress("L1_DoubleEG5", &L1_DoubleEG5, &b_L1_DoubleEG5);
   fChain->SetBranchAddress("L1_DoubleHfBitCountsRing1_P1N1", &L1_DoubleHfBitCountsRing1_P1N1, &b_L1_DoubleHfBitCountsRing1_P1N1);
   fChain->SetBranchAddress("L1_DoubleHfBitCountsRing2_P1N1", &L1_DoubleHfBitCountsRing2_P1N1, &b_L1_DoubleHfBitCountsRing2_P1N1);
   fChain->SetBranchAddress("L1_DoubleHfRingEtSumsRing1_P200N200", &L1_DoubleHfRingEtSumsRing1_P200N200, &b_L1_DoubleHfRingEtSumsRing1_P200N200);
   fChain->SetBranchAddress("L1_DoubleHfRingEtSumsRing1_P4N4", &L1_DoubleHfRingEtSumsRing1_P4N4, &b_L1_DoubleHfRingEtSumsRing1_P4N4);
   fChain->SetBranchAddress("L1_DoubleHfRingEtSumsRing2_P200N200", &L1_DoubleHfRingEtSumsRing2_P200N200, &b_L1_DoubleHfRingEtSumsRing2_P200N200);
   fChain->SetBranchAddress("L1_DoubleHfRingEtSumsRing2_P4N4", &L1_DoubleHfRingEtSumsRing2_P4N4, &b_L1_DoubleHfRingEtSumsRing2_P4N4);
   fChain->SetBranchAddress("L1_DoubleJet70", &L1_DoubleJet70, &b_L1_DoubleJet70);
   fChain->SetBranchAddress("L1_DoubleMu3", &L1_DoubleMu3, &b_L1_DoubleMu3);
   fChain->SetBranchAddress("L1_DoubleMuOpen", &L1_DoubleMuOpen, &b_L1_DoubleMuOpen);
   fChain->SetBranchAddress("L1_DoubleTauJet30", &L1_DoubleTauJet30, &b_L1_DoubleTauJet30);
   fChain->SetBranchAddress("L1_EG10_Jet15", &L1_EG10_Jet15, &b_L1_EG10_Jet15);
   fChain->SetBranchAddress("L1_EG5_TripleJet15", &L1_EG5_TripleJet15, &b_L1_EG5_TripleJet15);
   fChain->SetBranchAddress("L1_ETM20", &L1_ETM20, &b_L1_ETM20);
   fChain->SetBranchAddress("L1_ETM30", &L1_ETM30, &b_L1_ETM30);
   fChain->SetBranchAddress("L1_ETM40", &L1_ETM40, &b_L1_ETM40);
   fChain->SetBranchAddress("L1_ETM70", &L1_ETM70, &b_L1_ETM70);
   fChain->SetBranchAddress("L1_ETM80", &L1_ETM80, &b_L1_ETM80);
   fChain->SetBranchAddress("L1_ETT60", &L1_ETT60, &b_L1_ETT60);
   fChain->SetBranchAddress("L1_ETT100", &L1_ETT100, &b_L1_ETT100);
   fChain->SetBranchAddress("L1_ETT140", &L1_ETT140, &b_L1_ETT140);
   fChain->SetBranchAddress("L1_HTT50", &L1_HTT50, &b_L1_HTT50);
   fChain->SetBranchAddress("L1_HTT100", &L1_HTT100, &b_L1_HTT100);
   fChain->SetBranchAddress("L1_HTT200", &L1_HTT200, &b_L1_HTT200);
   fChain->SetBranchAddress("L1_HTT300", &L1_HTT300, &b_L1_HTT300);
   fChain->SetBranchAddress("L1_IsoEG10_Jet15_ForJet10", &L1_IsoEG10_Jet15_ForJet10, &b_L1_IsoEG10_Jet15_ForJet10);
   fChain->SetBranchAddress("L1_MinBias_HTT10", &L1_MinBias_HTT10, &b_L1_MinBias_HTT10);
   fChain->SetBranchAddress("L1_Mu3QE8_EG5", &L1_Mu3QE8_EG5, &b_L1_Mu3QE8_EG5);
   fChain->SetBranchAddress("L1_Mu3QE8_Jet15", &L1_Mu3QE8_Jet15, &b_L1_Mu3QE8_Jet15);
   fChain->SetBranchAddress("L1_Mu5QE8_Jet15", &L1_Mu5QE8_Jet15, &b_L1_Mu5QE8_Jet15);
   fChain->SetBranchAddress("L1_Mu3QE8_Jet6", &L1_Mu3QE8_Jet6, &b_L1_Mu3QE8_Jet6);
   fChain->SetBranchAddress("L1_Mu5QE8_Jet6", &L1_Mu5QE8_Jet6, &b_L1_Mu5QE8_Jet6);
   fChain->SetBranchAddress("L1_QuadJet15", &L1_QuadJet15, &b_L1_QuadJet15);
   fChain->SetBranchAddress("L1_SingleEG1", &L1_SingleEG1, &b_L1_SingleEG1);
   fChain->SetBranchAddress("L1_SingleEG10", &L1_SingleEG10, &b_L1_SingleEG10);
   fChain->SetBranchAddress("L1_SingleEG12", &L1_SingleEG12, &b_L1_SingleEG12);
   fChain->SetBranchAddress("L1_SingleEG15", &L1_SingleEG15, &b_L1_SingleEG15);
   fChain->SetBranchAddress("L1_SingleEG2", &L1_SingleEG2, &b_L1_SingleEG2);
   fChain->SetBranchAddress("L1_SingleEG20", &L1_SingleEG20, &b_L1_SingleEG20);
   fChain->SetBranchAddress("L1_SingleEG5", &L1_SingleEG5, &b_L1_SingleEG5);
   fChain->SetBranchAddress("L1_SingleEG8", &L1_SingleEG8, &b_L1_SingleEG8);
   fChain->SetBranchAddress("L1_SingleHfBitCountsRing1_1", &L1_SingleHfBitCountsRing1_1, &b_L1_SingleHfBitCountsRing1_1);
   fChain->SetBranchAddress("L1_SingleHfBitCountsRing2_1", &L1_SingleHfBitCountsRing2_1, &b_L1_SingleHfBitCountsRing2_1);
   fChain->SetBranchAddress("L1_SingleHfRingEtSumsRing1_200", &L1_SingleHfRingEtSumsRing1_200, &b_L1_SingleHfRingEtSumsRing1_200);
   fChain->SetBranchAddress("L1_SingleHfRingEtSumsRing1_4", &L1_SingleHfRingEtSumsRing1_4, &b_L1_SingleHfRingEtSumsRing1_4);
   fChain->SetBranchAddress("L1_SingleHfRingEtSumsRing2_200", &L1_SingleHfRingEtSumsRing2_200, &b_L1_SingleHfRingEtSumsRing2_200);
   fChain->SetBranchAddress("L1_SingleHfRingEtSumsRing2_4", &L1_SingleHfRingEtSumsRing2_4, &b_L1_SingleHfRingEtSumsRing2_4);
   fChain->SetBranchAddress("L1_SingleIsoEG10", &L1_SingleIsoEG10, &b_L1_SingleIsoEG10);
   fChain->SetBranchAddress("L1_SingleIsoEG12", &L1_SingleIsoEG12, &b_L1_SingleIsoEG12);
   fChain->SetBranchAddress("L1_SingleIsoEG15", &L1_SingleIsoEG15, &b_L1_SingleIsoEG15);
   fChain->SetBranchAddress("L1_SingleIsoEG5", &L1_SingleIsoEG5, &b_L1_SingleIsoEG5);
   fChain->SetBranchAddress("L1_SingleIsoEG8", &L1_SingleIsoEG8, &b_L1_SingleIsoEG8);
   fChain->SetBranchAddress("L1_SingleJet100", &L1_SingleJet100, &b_L1_SingleJet100);
   fChain->SetBranchAddress("L1_SingleJet15", &L1_SingleJet15, &b_L1_SingleJet15);
   fChain->SetBranchAddress("L1_SingleJet30", &L1_SingleJet30, &b_L1_SingleJet30);
   fChain->SetBranchAddress("L1_SingleJet50", &L1_SingleJet50, &b_L1_SingleJet50);
   fChain->SetBranchAddress("L1_SingleJet70", &L1_SingleJet70, &b_L1_SingleJet70);
   fChain->SetBranchAddress("L1_SingleMu0", &L1_SingleMu0, &b_L1_SingleMu0);
   fChain->SetBranchAddress("L1_SingleMu10", &L1_SingleMu10, &b_L1_SingleMu10);
   fChain->SetBranchAddress("L1_SingleMu14", &L1_SingleMu14, &b_L1_SingleMu14);
   fChain->SetBranchAddress("L1_SingleMu20", &L1_SingleMu20, &b_L1_SingleMu20);
   fChain->SetBranchAddress("L1_SingleMu3", &L1_SingleMu3, &b_L1_SingleMu3);
   fChain->SetBranchAddress("L1_SingleMu5", &L1_SingleMu5, &b_L1_SingleMu5);
   fChain->SetBranchAddress("L1_SingleMu7", &L1_SingleMu7, &b_L1_SingleMu7);
   fChain->SetBranchAddress("L1_SingleMuBeamHalo", &L1_SingleMuBeamHalo, &b_L1_SingleMuBeamHalo);
   fChain->SetBranchAddress("L1_SingleMuOpen", &L1_SingleMuOpen, &b_L1_SingleMuOpen);
   fChain->SetBranchAddress("L1_SingleTauJet30", &L1_SingleTauJet30, &b_L1_SingleTauJet30);
   fChain->SetBranchAddress("L1_SingleTauJet40", &L1_SingleTauJet40, &b_L1_SingleTauJet40);
   fChain->SetBranchAddress("L1_SingleTauJet60", &L1_SingleTauJet60, &b_L1_SingleTauJet60);
   fChain->SetBranchAddress("L1_SingleTauJet80", &L1_SingleTauJet80, &b_L1_SingleTauJet80);
   fChain->SetBranchAddress("L1_TripleJet30", &L1_TripleJet30, &b_L1_TripleJet30);
   fChain->SetBranchAddress("L1_ZeroBias", &L1_ZeroBias, &b_L1_ZeroBias);
   fChain->SetBranchAddress("L1_ZeroBias_Ext", &L1_ZeroBias_Ext, &b_L1_ZeroBias_Ext);
   fChain->SetBranchAddress("L1_SingleCenJet2", &L1_SingleCenJet2, &b_L1_SingleCenJet2);
   fChain->SetBranchAddress("L1_SingleCenJet4", &L1_SingleCenJet4, &b_L1_SingleCenJet4);
   fChain->SetBranchAddress("L1_SingleForJet2", &L1_SingleForJet2, &b_L1_SingleForJet2);
   fChain->SetBranchAddress("L1_SingleForJet4", &L1_SingleForJet4, &b_L1_SingleForJet4);
   fChain->SetBranchAddress("L1_SingleTauJet2", &L1_SingleTauJet2, &b_L1_SingleTauJet2);
   fChain->SetBranchAddress("L1_SingleTauJet4", &L1_SingleTauJet4, &b_L1_SingleTauJet4);
   fChain->SetBranchAddress("L1_DoubleForJet10_EtaOpp", &L1_DoubleForJet10_EtaOpp, &b_L1_DoubleForJet10_EtaOpp);
   fChain->SetBranchAddress("L1_Mu3_Jet6", &L1_Mu3_Jet6, &b_L1_Mu3_Jet6);

   // L1 Technical bits
   fChain->SetBranchAddress("L1Tech_BPTX_minus.v0", &L1Tech_BPTX_minus_v0, &b_L1Tech_BPTX_minus_v0);
   fChain->SetBranchAddress("L1Tech_BPTX_minus.v0_5bx", &L1Tech_BPTX_minus_v0_5bx, &b_L1Tech_BPTX_minus_v0_5bx);
   fChain->SetBranchAddress("L1Tech_BPTX_minus_AND_not_plus.v0", &L1Tech_BPTX_minus_AND_not_plus_v0, &b_L1Tech_BPTX_minus_AND_not_plus_v0);
   fChain->SetBranchAddress("L1Tech_BPTX_minus_AND_not_plus.v0_5bx", &L1Tech_BPTX_minus_AND_not_plus_v0_5bx, &b_L1Tech_BPTX_minus_AND_not_plus_v0_5bx);
   fChain->SetBranchAddress("L1Tech_BPTX_plus.v0", &L1Tech_BPTX_plus_v0, &b_L1Tech_BPTX_plus_v0);
   fChain->SetBranchAddress("L1Tech_BPTX_plus.v0_5bx", &L1Tech_BPTX_plus_v0_5bx, &b_L1Tech_BPTX_plus_v0_5bx);
   fChain->SetBranchAddress("L1Tech_BPTX_plus_AND_NOT_minus.v0", &L1Tech_BPTX_plus_AND_NOT_minus_v0, &b_L1Tech_BPTX_plus_AND_NOT_minus_v0);
   fChain->SetBranchAddress("L1Tech_BPTX_plus_AND_NOT_minus.v0_5bx", &L1Tech_BPTX_plus_AND_NOT_minus_v0_5bx, &b_L1Tech_BPTX_plus_AND_NOT_minus_v0_5bx);
   fChain->SetBranchAddress("L1Tech_BPTX_plus_AND_minus.v0", &L1Tech_BPTX_plus_AND_minus_v0, &b_L1Tech_BPTX_plus_AND_minus_v0);
   fChain->SetBranchAddress("L1Tech_BPTX_plus_AND_minus.v0_5bx", &L1Tech_BPTX_plus_AND_minus_v0_5bx, &b_L1Tech_BPTX_plus_AND_minus_v0_5bx);
   fChain->SetBranchAddress("L1Tech_BPTX_plus_AND_minus_instance1.v0", &L1Tech_BPTX_plus_AND_minus_instance1_v0, &b_L1Tech_BPTX_plus_AND_minus_instance1_v0);
   fChain->SetBranchAddress("L1Tech_BPTX_plus_AND_minus_instance1.v0_5bx", &L1Tech_BPTX_plus_AND_minus_instance1_v0_5bx, &b_L1Tech_BPTX_plus_AND_minus_instance1_v0_5bx);
   fChain->SetBranchAddress("L1Tech_BPTX_plus_OR_minus.v0", &L1Tech_BPTX_plus_OR_minus_v0, &b_L1Tech_BPTX_plus_OR_minus_v0);
   fChain->SetBranchAddress("L1Tech_BPTX_plus_OR_minus.v0_5bx", &L1Tech_BPTX_plus_OR_minus_v0_5bx, &b_L1Tech_BPTX_plus_OR_minus_v0_5bx);
   fChain->SetBranchAddress("L1Tech_BPTX_quiet.v0", &L1Tech_BPTX_quiet_v0, &b_L1Tech_BPTX_quiet_v0);
   fChain->SetBranchAddress("L1Tech_BPTX_quiet.v0_5bx", &L1Tech_BPTX_quiet_v0_5bx, &b_L1Tech_BPTX_quiet_v0_5bx);
   fChain->SetBranchAddress("L1Tech_BSC_HighMultiplicity.v0", &L1Tech_BSC_HighMultiplicity_v0, &b_L1Tech_BSC_HighMultiplicity_v0);
   fChain->SetBranchAddress("L1Tech_BSC_HighMultiplicity.v0_5bx", &L1Tech_BSC_HighMultiplicity_v0_5bx, &b_L1Tech_BSC_HighMultiplicity_v0_5bx);
   fChain->SetBranchAddress("L1Tech_BSC_halo_beam1_inner.v0", &L1Tech_BSC_halo_beam1_inner_v0, &b_L1Tech_BSC_halo_beam1_inner_v0);
   fChain->SetBranchAddress("L1Tech_BSC_halo_beam1_inner.v0_5bx", &L1Tech_BSC_halo_beam1_inner_v0_5bx, &b_L1Tech_BSC_halo_beam1_inner_v0_5bx);
   fChain->SetBranchAddress("L1Tech_BSC_halo_beam1_outer.v0", &L1Tech_BSC_halo_beam1_outer_v0, &b_L1Tech_BSC_halo_beam1_outer_v0);
   fChain->SetBranchAddress("L1Tech_BSC_halo_beam1_outer.v0_5bx", &L1Tech_BSC_halo_beam1_outer_v0_5bx, &b_L1Tech_BSC_halo_beam1_outer_v0_5bx);
   fChain->SetBranchAddress("L1Tech_BSC_halo_beam2_inner.v0", &L1Tech_BSC_halo_beam2_inner_v0, &b_L1Tech_BSC_halo_beam2_inner_v0);
   fChain->SetBranchAddress("L1Tech_BSC_halo_beam2_inner.v0_5bx", &L1Tech_BSC_halo_beam2_inner_v0_5bx, &b_L1Tech_BSC_halo_beam2_inner_v0_5bx);
   fChain->SetBranchAddress("L1Tech_BSC_halo_beam2_outer.v0", &L1Tech_BSC_halo_beam2_outer_v0, &b_L1Tech_BSC_halo_beam2_outer_v0);
   fChain->SetBranchAddress("L1Tech_BSC_halo_beam2_outer.v0_5bx", &L1Tech_BSC_halo_beam2_outer_v0_5bx, &b_L1Tech_BSC_halo_beam2_outer_v0_5bx);
   fChain->SetBranchAddress("L1Tech_BSC_minBias_OR.v0", &L1Tech_BSC_minBias_OR_v0, &b_L1Tech_BSC_minBias_OR_v0);
   fChain->SetBranchAddress("L1Tech_BSC_minBias_OR.v0_5bx", &L1Tech_BSC_minBias_OR_v0_5bx, &b_L1Tech_BSC_minBias_OR_v0_5bx);
   fChain->SetBranchAddress("L1Tech_BSC_minBias_inner_threshold1.v0", &L1Tech_BSC_minBias_inner_threshold1_v0, &b_L1Tech_BSC_minBias_inner_threshold1_v0);
   fChain->SetBranchAddress("L1Tech_BSC_minBias_inner_threshold1.v0_5bx", &L1Tech_BSC_minBias_inner_threshold1_v0_5bx, &b_L1Tech_BSC_minBias_inner_threshold1_v0_5bx);
   fChain->SetBranchAddress("L1Tech_BSC_minBias_inner_threshold2.v0", &L1Tech_BSC_minBias_inner_threshold2_v0, &b_L1Tech_BSC_minBias_inner_threshold2_v0);
   fChain->SetBranchAddress("L1Tech_BSC_minBias_inner_threshold2.v0_5bx", &L1Tech_BSC_minBias_inner_threshold2_v0_5bx, &b_L1Tech_BSC_minBias_inner_threshold2_v0_5bx);
   fChain->SetBranchAddress("L1Tech_BSC_minBias_threshold1.v0", &L1Tech_BSC_minBias_threshold1_v0, &b_L1Tech_BSC_minBias_threshold1_v0);
   fChain->SetBranchAddress("L1Tech_BSC_minBias_threshold1.v0_5bx", &L1Tech_BSC_minBias_threshold1_v0_5bx, &b_L1Tech_BSC_minBias_threshold1_v0_5bx);
   fChain->SetBranchAddress("L1Tech_BSC_minBias_threshold2.v0", &L1Tech_BSC_minBias_threshold2_v0, &b_L1Tech_BSC_minBias_threshold2_v0);
   fChain->SetBranchAddress("L1Tech_BSC_minBias_threshold2.v0_5bx", &L1Tech_BSC_minBias_threshold2_v0_5bx, &b_L1Tech_BSC_minBias_threshold2_v0_5bx);
   fChain->SetBranchAddress("L1Tech_BSC_splash_beam1.v0", &L1Tech_BSC_splash_beam1_v0, &b_L1Tech_BSC_splash_beam1_v0);
   fChain->SetBranchAddress("L1Tech_BSC_splash_beam1.v0_5bx", &L1Tech_BSC_splash_beam1_v0_5bx, &b_L1Tech_BSC_splash_beam1_v0_5bx);
   fChain->SetBranchAddress("L1Tech_BSC_splash_beam2.v0", &L1Tech_BSC_splash_beam2_v0, &b_L1Tech_BSC_splash_beam2_v0);
   fChain->SetBranchAddress("L1Tech_BSC_splash_beam2.v0_5bx", &L1Tech_BSC_splash_beam2_v0_5bx, &b_L1Tech_BSC_splash_beam2_v0_5bx);
   fChain->SetBranchAddress("L1Tech_HCAL_HBHE_totalOR.v0", &L1Tech_HCAL_HBHE_totalOR_v0, &b_L1Tech_HCAL_HBHE_totalOR_v0);
   fChain->SetBranchAddress("L1Tech_HCAL_HBHE_totalOR.v0_5bx", &L1Tech_HCAL_HBHE_totalOR_v0_5bx, &b_L1Tech_HCAL_HBHE_totalOR_v0_5bx);
   fChain->SetBranchAddress("L1Tech_HCAL_HF_totalOR_coincidenceHFM.v0", &L1Tech_HCAL_HF_totalOR_coincidenceHFM_v0, &b_L1Tech_HCAL_HF_totalOR_coincidenceHFM_v0);
   fChain->SetBranchAddress("L1Tech_HCAL_HF_totalOR_coincidenceHFM.v0_5bx", &L1Tech_HCAL_HF_totalOR_coincidenceHFM_v0_5bx, &b_L1Tech_HCAL_HF_totalOR_coincidenceHFM_v0_5bx);
   fChain->SetBranchAddress("L1Tech_HCAL_HF_totalOR_coincidenceHFP.v0", &L1Tech_HCAL_HF_totalOR_coincidenceHFP_v0, &b_L1Tech_HCAL_HF_totalOR_coincidenceHFP_v0);
   fChain->SetBranchAddress("L1Tech_HCAL_HF_totalOR_coincidenceHFP.v0_5bx", &L1Tech_HCAL_HF_totalOR_coincidenceHFP_v0_5bx, &b_L1Tech_HCAL_HF_totalOR_coincidenceHFP_v0_5bx);
   fChain->SetBranchAddress("L1Tech_HCAL_HF_totalOR_minBias.v0", &L1Tech_HCAL_HF_totalOR_minBias_v0, &b_L1Tech_HCAL_HF_totalOR_minBias_v0);
   fChain->SetBranchAddress("L1Tech_HCAL_HF_totalOR_minBias.v0_5bx", &L1Tech_HCAL_HF_totalOR_minBias_v0_5bx, &b_L1Tech_HCAL_HF_totalOR_minBias_v0_5bx);
   fChain->SetBranchAddress("L1Tech_HCAL_HO_totalOR.v0", &L1Tech_HCAL_HO_totalOR_v0, &b_L1Tech_HCAL_HO_totalOR_v0);
   fChain->SetBranchAddress("L1Tech_HCAL_HO_totalOR.v0_5bx", &L1Tech_HCAL_HO_totalOR_v0_5bx, &b_L1Tech_HCAL_HO_totalOR_v0_5bx);
   fChain->SetBranchAddress("L1Tech_RPC_TTU_RB0_Cosmics.v0", &L1Tech_RPC_TTU_RB0_Cosmics_v0, &b_L1Tech_RPC_TTU_RB0_Cosmics_v0);
   fChain->SetBranchAddress("L1Tech_RPC_TTU_RB0_Cosmics.v0_5bx", &L1Tech_RPC_TTU_RB0_Cosmics_v0_5bx, &b_L1Tech_RPC_TTU_RB0_Cosmics_v0_5bx);
   fChain->SetBranchAddress("L1Tech_RPC_TTU_RBminus1_Cosmics.v0", &L1Tech_RPC_TTU_RBminus1_Cosmics_v0, &b_L1Tech_RPC_TTU_RBminus1_Cosmics_v0);
   fChain->SetBranchAddress("L1Tech_RPC_TTU_RBminus1_Cosmics.v0_5bx", &L1Tech_RPC_TTU_RBminus1_Cosmics_v0_5bx, &b_L1Tech_RPC_TTU_RBminus1_Cosmics_v0_5bx);
   fChain->SetBranchAddress("L1Tech_RPC_TTU_RBminus2_Cosmics.v0", &L1Tech_RPC_TTU_RBminus2_Cosmics_v0, &b_L1Tech_RPC_TTU_RBminus2_Cosmics_v0);
   fChain->SetBranchAddress("L1Tech_RPC_TTU_RBminus2_Cosmics.v0_5bx", &L1Tech_RPC_TTU_RBminus2_Cosmics_v0_5bx, &b_L1Tech_RPC_TTU_RBminus2_Cosmics_v0_5bx);
   fChain->SetBranchAddress("L1Tech_RPC_TTU_RBplus1_Cosmics.v0", &L1Tech_RPC_TTU_RBplus1_Cosmics_v0, &b_L1Tech_RPC_TTU_RBplus1_Cosmics_v0);
   fChain->SetBranchAddress("L1Tech_RPC_TTU_RBplus1_Cosmics.v0_5bx", &L1Tech_RPC_TTU_RBplus1_Cosmics_v0_5bx, &b_L1Tech_RPC_TTU_RBplus1_Cosmics_v0_5bx);
   fChain->SetBranchAddress("L1Tech_RPC_TTU_RBplus2_Cosmics.v0", &L1Tech_RPC_TTU_RBplus2_Cosmics_v0, &b_L1Tech_RPC_TTU_RBplus2_Cosmics_v0);
   fChain->SetBranchAddress("L1Tech_RPC_TTU_RBplus2_Cosmics.v0_5bx", &L1Tech_RPC_TTU_RBplus2_Cosmics_v0_5bx, &b_L1Tech_RPC_TTU_RBplus2_Cosmics_v0_5bx);
   fChain->SetBranchAddress("L1Tech_RPC_TTU_barrel_Cosmics.v0", &L1Tech_RPC_TTU_barrel_Cosmics_v0, &b_L1Tech_RPC_TTU_barrel_Cosmics_v0);
   fChain->SetBranchAddress("L1Tech_RPC_TTU_barrel_Cosmics.v0_5bx", &L1Tech_RPC_TTU_barrel_Cosmics_v0_5bx, &b_L1Tech_RPC_TTU_barrel_Cosmics_v0_5bx);
   fChain->SetBranchAddress("L1Tech_RPC_TTU_pointing_Cosmics.v0", &L1Tech_RPC_TTU_pointing_Cosmics_v0, &b_L1Tech_RPC_TTU_pointing_Cosmics_v0);
   fChain->SetBranchAddress("L1Tech_RPC_TTU_pointing_Cosmics.v0_5bx", &L1Tech_RPC_TTU_pointing_Cosmics_v0_5bx, &b_L1Tech_RPC_TTU_pointing_Cosmics_v0_5bx);
   fChain->SetBranchAddress("L1Tech_RPC_TTU_RBst1_collisions.v0", &L1Tech_RPC_TTU_RBst1_collisions_v0, &b_L1Tech_RPC_TTU_RBst1_collisions_v0);
   fChain->SetBranchAddress("L1Tech_RPC_TTU_RBst1_collisions.v0_5bx", &L1Tech_RPC_TTU_RBst1_collisions_v0_5bx, &b_L1Tech_RPC_TTU_RBst1_collisions_v0_5bx);
   fChain->SetBranchAddress("L1Tech_HCAL_HF_MM_or_PP_or_PM.v0", &L1Tech_HCAL_HF_MM_or_PP_or_PM_v0, &b_L1Tech_HCAL_HF_MM_or_PP_or_PM_v0);
   fChain->SetBranchAddress("L1Tech_HCAL_HF_MM_or_PP_or_PM.v0_5bx", &L1Tech_HCAL_HF_MM_or_PP_or_PM_v0_5bx, &b_L1Tech_HCAL_HF_MM_or_PP_or_PM_v0_5bx);
   fChain->SetBranchAddress("L1Tech_HCAL_HF_coincidence_PM.v1", &L1Tech_HCAL_HF_coincidence_PM_v1, &b_L1Tech_HCAL_HF_coincidence_PM_v1);
   fChain->SetBranchAddress("L1Tech_HCAL_HF_coincidence_PM.v1_5bx", &L1Tech_HCAL_HF_coincidence_PM_v1_5bx, &b_L1Tech_HCAL_HF_coincidence_PM_v1_5bx);
   fChain->SetBranchAddress("L1Tech_HCAL_HF_MMP_or_MPP.v0", &L1Tech_HCAL_HF_MMP_or_MPP_v0, &b_L1Tech_HCAL_HF_MMP_or_MPP_v0);
   fChain->SetBranchAddress("L1Tech_HCAL_HF_MMP_or_MPP.v0_5bx", &L1Tech_HCAL_HF_MMP_or_MPP_v0_5bx, &b_L1Tech_HCAL_HF_MMP_or_MPP_v0_5bx);
   fChain->SetBranchAddress("L1Tech_ZDC_loose_vertex.v0", &L1Tech_ZDC_loose_vertex_v0, &b_L1Tech_ZDC_loose_vertex_v0);
   fChain->SetBranchAddress("L1Tech_ZDC_loose_vertex.v0_5bx", &L1Tech_ZDC_loose_vertex_v0_5bx, &b_L1Tech_ZDC_loose_vertex_v0_5bx);
   fChain->SetBranchAddress("L1Tech_ZDC_minus_over_threshold.v0", &L1Tech_ZDC_minus_over_threshold_v0, &b_L1Tech_ZDC_minus_over_threshold_v0);
   fChain->SetBranchAddress("L1Tech_ZDC_minus_over_threshold.v0_5bx", &L1Tech_ZDC_minus_over_threshold_v0_5bx, &b_L1Tech_ZDC_minus_over_threshold_v0_5bx);
   fChain->SetBranchAddress("L1Tech_ZDC_plus_over_threshold.v0", &L1Tech_ZDC_plus_over_threshold_v0, &b_L1Tech_ZDC_plus_over_threshold_v0);
   fChain->SetBranchAddress("L1Tech_ZDC_plus_over_threshold.v0_5bx", &L1Tech_ZDC_plus_over_threshold_v0_5bx, &b_L1Tech_ZDC_plus_over_threshold_v0_5bx);
   fChain->SetBranchAddress("L1Tech_ZDC_tight_vertex.v0", &L1Tech_ZDC_tight_vertex_v0, &b_L1Tech_ZDC_tight_vertex_v0);
   fChain->SetBranchAddress("L1Tech_ZDC_tight_vertex.v0_5bx", &L1Tech_ZDC_tight_vertex_v0_5bx, &b_L1Tech_ZDC_tight_vertex_v0_5bx);
   fChain->SetBranchAddress("L1_BptxMinus", &L1_BptxMinus, &b_L1_BptxMinus);
   fChain->SetBranchAddress("L1_BptxMinus_5bx", &L1_BptxMinus_5bx, &b_L1_BptxMinus_5bx);
   fChain->SetBranchAddress("L1_BptxPlus", &L1_BptxPlus, &b_L1_BptxPlus);
   fChain->SetBranchAddress("L1_BptxPlus_5bx", &L1_BptxPlus_5bx, &b_L1_BptxPlus_5bx);
   fChain->SetBranchAddress("L1_BptxPlusORMinus", &L1_BptxPlusORMinus, &b_L1_BptxPlusORMinus);
   fChain->SetBranchAddress("L1_BptxPlusORMinus_5bx", &L1_BptxPlusORMinus_5bx, &b_L1_BptxPlusORMinus_5bx);
   fChain->SetBranchAddress("L1_BptxXOR_BscMinBiasOR", &L1_BptxXOR_BscMinBiasOR, &b_L1_BptxXOR_BscMinBiasOR);
   fChain->SetBranchAddress("L1_BptxXOR_BscMinBiasOR_5bx", &L1_BptxXOR_BscMinBiasOR_5bx, &b_L1_BptxXOR_BscMinBiasOR_5bx);
   fChain->SetBranchAddress("L1_BptxPlus_NotBptxMinus", &L1_BptxPlus_NotBptxMinus, &b_L1_BptxPlus_NotBptxMinus);
   fChain->SetBranchAddress("L1_BptxPlus_NotBptxMinus_5bx", &L1_BptxPlus_NotBptxMinus_5bx, &b_L1_BptxPlus_NotBptxMinus_5bx);
   fChain->SetBranchAddress("L1_BptxMinus_NotBptxPlus", &L1_BptxMinus_NotBptxPlus, &b_L1_BptxMinus_NotBptxPlus);
   fChain->SetBranchAddress("L1_BptxMinus_NotBptxPlus_5bx", &L1_BptxMinus_NotBptxPlus_5bx, &b_L1_BptxMinus_NotBptxPlus_5bx);
   fChain->SetBranchAddress("L1_BscHighMultiplicity", &L1_BscHighMultiplicity, &b_L1_BscHighMultiplicity);
   fChain->SetBranchAddress("L1_BscHighMultiplicity_5bx", &L1_BscHighMultiplicity_5bx, &b_L1_BscHighMultiplicity_5bx);
   fChain->SetBranchAddress("L1_BscMinBiasInnerThreshold1", &L1_BscMinBiasInnerThreshold1, &b_L1_BscMinBiasInnerThreshold1);
   fChain->SetBranchAddress("L1_BscMinBiasInnerThreshold1_5bx", &L1_BscMinBiasInnerThreshold1_5bx, &b_L1_BscMinBiasInnerThreshold1_5bx);
   fChain->SetBranchAddress("L1_BscMinBiasInnerThreshold2", &L1_BscMinBiasInnerThreshold2, &b_L1_BscMinBiasInnerThreshold2);
   fChain->SetBranchAddress("L1_BscMinBiasInnerThreshold2_5bx", &L1_BscMinBiasInnerThreshold2_5bx, &b_L1_BscMinBiasInnerThreshold2_5bx);
   fChain->SetBranchAddress("L1_BscMinBiasOR", &L1_BscMinBiasOR, &b_L1_BscMinBiasOR);
   fChain->SetBranchAddress("L1_BscMinBiasOR_5bx", &L1_BscMinBiasOR_5bx, &b_L1_BscMinBiasOR_5bx);
   fChain->SetBranchAddress("L1_BscMinBiasOR_BptxPlusORMinus", &L1_BscMinBiasOR_BptxPlusORMinus, &b_L1_BscMinBiasOR_BptxPlusORMinus);
   fChain->SetBranchAddress("L1_BscMinBiasOR_BptxPlusORMinus_5bx", &L1_BscMinBiasOR_BptxPlusORMinus_5bx, &b_L1_BscMinBiasOR_BptxPlusORMinus_5bx);
   fChain->SetBranchAddress("L1_BscMinBiasOR_BptxPlusANDMinus", &L1_BscMinBiasOR_BptxPlusANDMinus, &b_L1_BscMinBiasOR_BptxPlusANDMinus);
   fChain->SetBranchAddress("L1_BscMinBiasOR_BptxPlusANDMinus_5bx", &L1_BscMinBiasOR_BptxPlusANDMinus_5bx, &b_L1_BscMinBiasOR_BptxPlusANDMinus_5bx);

   // Autogenerated L1 - Prescale SetBranchAddressBits 
  fChain->SetBranchAddress("L1_SingleJet20_Central_NotBptxOR_Prescl", &L1_SingleJet20_Central_NotBptxOR_Prescl, &b_L1_SingleJet20_Central_NotBptxOR_Prescl);
  fChain->SetBranchAddress("L1_SingleJet16_FwdVeto5_Prescl", &L1_SingleJet16_FwdVeto5_Prescl, &b_L1_SingleJet16_FwdVeto5_Prescl);
  fChain->SetBranchAddress("L1_ETT80_Prescl", &L1_ETT80_Prescl, &b_L1_ETT80_Prescl);
  fChain->SetBranchAddress("L1_DoubleForJet16_EtaOpp_Prescl", &L1_DoubleForJet16_EtaOpp_Prescl, &b_L1_DoubleForJet16_EtaOpp_Prescl);
  fChain->SetBranchAddress("L1_DoubleMu0_HighQ_EtaCuts_Prescl", &L1_DoubleMu0_HighQ_EtaCuts_Prescl, &b_L1_DoubleMu0_HighQ_EtaCuts_Prescl);
  fChain->SetBranchAddress("L1_DoubleEG3_FwdVeto_Prescl", &L1_DoubleEG3_FwdVeto_Prescl, &b_L1_DoubleEG3_FwdVeto_Prescl);
  fChain->SetBranchAddress("L1_SingleForJet16_Prescl", &L1_SingleForJet16_Prescl, &b_L1_SingleForJet16_Prescl);
  fChain->SetBranchAddress("L1_DoubleMu_5er_0er_HighQ_WdEta22_Prescl", &L1_DoubleMu_5er_0er_HighQ_WdEta22_Prescl, &b_L1_DoubleMu_5er_0er_HighQ_WdEta22_Prescl);
  fChain->SetBranchAddress("L1_DoubleMu3er_HighQ_WdEta22_Prescl", &L1_DoubleMu3er_HighQ_WdEta22_Prescl, &b_L1_DoubleMu3er_HighQ_WdEta22_Prescl);
  fChain->SetBranchAddress("L1_BeamHalo_Prescl", &L1_BeamHalo_Prescl, &b_L1_BeamHalo_Prescl);
  fChain->SetBranchAddress("L1_InterBunch_Bptx_Prescl", &L1_InterBunch_Bptx_Prescl, &b_L1_InterBunch_Bptx_Prescl);
  fChain->SetBranchAddress("L1_BeamGas_Hf_BptxPlusPostQuiet_Prescl", &L1_BeamGas_Hf_BptxPlusPostQuiet_Prescl, &b_L1_BeamGas_Hf_BptxPlusPostQuiet_Prescl);
  fChain->SetBranchAddress("L1_BeamGas_Hf_BptxMinusPostQuiet_Prescl", &L1_BeamGas_Hf_BptxMinusPostQuiet_Prescl, &b_L1_BeamGas_Hf_BptxMinusPostQuiet_Prescl);
  fChain->SetBranchAddress("L1_ZeroBias_Instance1_Prescl", &L1_ZeroBias_Instance1_Prescl, &b_L1_ZeroBias_Instance1_Prescl);
  fChain->SetBranchAddress("L1_SingleMu6_NotBptxOR_Prescl", &L1_SingleMu6_NotBptxOR_Prescl, &b_L1_SingleMu6_NotBptxOR_Prescl);
  fChain->SetBranchAddress("L1_SingleJetC20_NotBptxOR_Prescl", &L1_SingleJetC20_NotBptxOR_Prescl, &b_L1_SingleJetC20_NotBptxOR_Prescl);
  fChain->SetBranchAddress("L1_SingleJetC32_NotBptxOR_Prescl", &L1_SingleJetC32_NotBptxOR_Prescl, &b_L1_SingleJetC32_NotBptxOR_Prescl);
  fChain->SetBranchAddress("L1_TripleMu_5_5_0_Prescl", &L1_TripleMu_5_5_0_Prescl, &b_L1_TripleMu_5_5_0_Prescl);
  fChain->SetBranchAddress("L1_TripleMu0_HighQ_Prescl", &L1_TripleMu0_HighQ_Prescl, &b_L1_TripleMu0_HighQ_Prescl);
  fChain->SetBranchAddress("L1_DoubleMu_10_3p5_Prescl", &L1_DoubleMu_10_3p5_Prescl, &b_L1_DoubleMu_10_3p5_Prescl);
  fChain->SetBranchAddress("L1_DoubleMu_12_5_Prescl", &L1_DoubleMu_12_5_Prescl, &b_L1_DoubleMu_12_5_Prescl);
  fChain->SetBranchAddress("L1_DoubleMuHighQ_5_0_Eta2p1_WdEta22_Prescl", &L1_DoubleMuHighQ_5_0_Eta2p1_WdEta22_Prescl, &b_L1_DoubleMuHighQ_5_0_Eta2p1_WdEta22_Prescl);
  fChain->SetBranchAddress("L1_DoubleMuHighQ_3_3_Eta2p1_WdEta22_Prescl", &L1_DoubleMuHighQ_3_3_Eta2p1_WdEta22_Prescl, &b_L1_DoubleMuHighQ_3_3_Eta2p1_WdEta22_Prescl);
  fChain->SetBranchAddress("L1_DoubleMu0er_HighQ_Prescl", &L1_DoubleMu0er_HighQ_Prescl, &b_L1_DoubleMu0er_HighQ_Prescl);
  fChain->SetBranchAddress("L1_SingleMu25er_Prescl", &L1_SingleMu25er_Prescl, &b_L1_SingleMu25er_Prescl);
  fChain->SetBranchAddress("L1_SingleMu20er_Prescl", &L1_SingleMu20er_Prescl, &b_L1_SingleMu20er_Prescl);
  fChain->SetBranchAddress("L1_SingleMu18er_Prescl", &L1_SingleMu18er_Prescl, &b_L1_SingleMu18er_Prescl);
  fChain->SetBranchAddress("L1_SingleMu16er_Prescl", &L1_SingleMu16er_Prescl, &b_L1_SingleMu16er_Prescl);
  fChain->SetBranchAddress("L1_SingleMu14er_Prescl", &L1_SingleMu14er_Prescl, &b_L1_SingleMu14er_Prescl);
  fChain->SetBranchAddress("L1_DoubleJetC44_ETM30_Prescl", &L1_DoubleJetC44_ETM30_Prescl, &b_L1_DoubleJetC44_ETM30_Prescl);
  fChain->SetBranchAddress("L1_DoubleJetC36_ETM30_Prescl", &L1_DoubleJetC36_ETM30_Prescl, &b_L1_DoubleJetC36_ETM30_Prescl);
  fChain->SetBranchAddress("L1_Mu5_DoubleEG6_Prescl", &L1_Mu5_DoubleEG6_Prescl, &b_L1_Mu5_DoubleEG6_Prescl);
  fChain->SetBranchAddress("L1_Mu5_DoubleEG5_Prescl", &L1_Mu5_DoubleEG5_Prescl, &b_L1_Mu5_DoubleEG5_Prescl);
  fChain->SetBranchAddress("L1_DoubleMu5_EG5_Prescl", &L1_DoubleMu5_EG5_Prescl, &b_L1_DoubleMu5_EG5_Prescl);
  fChain->SetBranchAddress("L1_DoubleMu3p5_EG5_Prescl", &L1_DoubleMu3p5_EG5_Prescl, &b_L1_DoubleMu3p5_EG5_Prescl);
  fChain->SetBranchAddress("L1_Mu3p5_EG12_Prescl", &L1_Mu3p5_EG12_Prescl, &b_L1_Mu3p5_EG12_Prescl);
  fChain->SetBranchAddress("L1_Mu12_EG7_Prescl", &L1_Mu12_EG7_Prescl, &b_L1_Mu12_EG7_Prescl);
  fChain->SetBranchAddress("L1_EG8_DoubleJetC20_Prescl", &L1_EG8_DoubleJetC20_Prescl, &b_L1_EG8_DoubleJetC20_Prescl);
  fChain->SetBranchAddress("L1_EG18er_JetC_Cen36_Tau28_dPhi1_Prescl", &L1_EG18er_JetC_Cen36_Tau28_dPhi1_Prescl, &b_L1_EG18er_JetC_Cen36_Tau28_dPhi1_Prescl);
  fChain->SetBranchAddress("L1_IsoEG18er_JetC_Cen36_Tau28_dPhi1_Prescl", &L1_IsoEG18er_JetC_Cen36_Tau28_dPhi1_Prescl, &b_L1_IsoEG18er_JetC_Cen36_Tau28_dPhi1_Prescl);
  fChain->SetBranchAddress("L1_IsoEG18er_JetC_Cen32_Tau24_dPhi1_Prescl", &L1_IsoEG18er_JetC_Cen32_Tau24_dPhi1_Prescl, &b_L1_IsoEG18er_JetC_Cen32_Tau24_dPhi1_Prescl);
  fChain->SetBranchAddress("L1_EG18er_JetC_Cen28_Tau20_dPhi1_Prescl", &L1_EG18er_JetC_Cen28_Tau20_dPhi1_Prescl, &b_L1_EG18er_JetC_Cen28_Tau20_dPhi1_Prescl);
  fChain->SetBranchAddress("L1_DoubleEG6_HTT125_Prescl", &L1_DoubleEG6_HTT125_Prescl, &b_L1_DoubleEG6_HTT125_Prescl);
  fChain->SetBranchAddress("L1_DoubleEG6_HTT100_Prescl", &L1_DoubleEG6_HTT100_Prescl, &b_L1_DoubleEG6_HTT100_Prescl);
  fChain->SetBranchAddress("L1_EG22_ForJet32_Prescl", &L1_EG22_ForJet32_Prescl, &b_L1_EG22_ForJet32_Prescl);
  fChain->SetBranchAddress("L1_EG22_ForJet24_Prescl", &L1_EG22_ForJet24_Prescl, &b_L1_EG22_ForJet24_Prescl);
  fChain->SetBranchAddress("L1_Mu8_DoubleJetC20_Prescl", &L1_Mu8_DoubleJetC20_Prescl, &b_L1_Mu8_DoubleJetC20_Prescl);
  fChain->SetBranchAddress("L1_Mu10er_JetC12_WdEtaPhi1_DoubleJetC_32_12_Prescl", &L1_Mu10er_JetC12_WdEtaPhi1_DoubleJetC_32_12_Prescl, &b_L1_Mu10er_JetC12_WdEtaPhi1_DoubleJetC_32_12_Prescl);
  fChain->SetBranchAddress("L1_Mu10er_JetC32_Prescl", &L1_Mu10er_JetC32_Prescl, &b_L1_Mu10er_JetC32_Prescl);
  fChain->SetBranchAddress("L1_Mu10er_JetC12_WdEtaPhi1_DoubleJetC_20_12_Prescl", &L1_Mu10er_JetC12_WdEtaPhi1_DoubleJetC_20_12_Prescl, &b_L1_Mu10er_JetC12_WdEtaPhi1_DoubleJetC_20_12_Prescl);
  fChain->SetBranchAddress("L1_Mu12er_ETM20_Prescl", &L1_Mu12er_ETM20_Prescl, &b_L1_Mu12er_ETM20_Prescl);
  fChain->SetBranchAddress("L1_Mu4_HTT125_Prescl", &L1_Mu4_HTT125_Prescl, &b_L1_Mu4_HTT125_Prescl);
  fChain->SetBranchAddress("L1_Mu0_HTT100_Prescl", &L1_Mu0_HTT100_Prescl, &b_L1_Mu0_HTT100_Prescl);
  fChain->SetBranchAddress("L1_DoubleTauJet44er_Prescl", &L1_DoubleTauJet44er_Prescl, &b_L1_DoubleTauJet44er_Prescl);
  fChain->SetBranchAddress("L1_QuadJetC40_Prescl", &L1_QuadJetC40_Prescl, &b_L1_QuadJetC40_Prescl);
  fChain->SetBranchAddress("L1_QuadJetC36_Prescl", &L1_QuadJetC36_Prescl, &b_L1_QuadJetC36_Prescl);
  fChain->SetBranchAddress("L1_QuadJetC32_Prescl", &L1_QuadJetC32_Prescl, &b_L1_QuadJetC32_Prescl);
  fChain->SetBranchAddress("L1_TripleJetC_52_28_28_Prescl", &L1_TripleJetC_52_28_28_Prescl, &b_L1_TripleJetC_52_28_28_Prescl);
  fChain->SetBranchAddress("L1_TripleJet_68_48_32_VBF_Prescl", &L1_TripleJet_68_48_32_VBF_Prescl, &b_L1_TripleJet_68_48_32_VBF_Prescl);
  fChain->SetBranchAddress("L1_TripleJet_64_48_28_VBF_Prescl", &L1_TripleJet_64_48_28_VBF_Prescl, &b_L1_TripleJet_64_48_28_VBF_Prescl);
  fChain->SetBranchAddress("L1_TripleJet_64_44_24_VBF_Prescl", &L1_TripleJet_64_44_24_VBF_Prescl, &b_L1_TripleJet_64_44_24_VBF_Prescl);
  fChain->SetBranchAddress("L1_DoubleJetC64_Prescl", &L1_DoubleJetC64_Prescl, &b_L1_DoubleJetC64_Prescl);
  fChain->SetBranchAddress("L1_DoubleJetC56_Prescl", &L1_DoubleJetC56_Prescl, &b_L1_DoubleJetC56_Prescl);
  fChain->SetBranchAddress("L1_DoubleJetC56_Eta1p74_WdEta4_Prescl", &L1_DoubleJetC56_Eta1p74_WdEta4_Prescl, &b_L1_DoubleJetC56_Eta1p74_WdEta4_Prescl);
  fChain->SetBranchAddress("L1_DoubleJetC52_Prescl", &L1_DoubleJetC52_Prescl, &b_L1_DoubleJetC52_Prescl);
  fChain->SetBranchAddress("L1_DoubleJetC44_Eta1p74_WdEta4_Prescl", &L1_DoubleJetC44_Eta1p74_WdEta4_Prescl, &b_L1_DoubleJetC44_Eta1p74_WdEta4_Prescl);
  fChain->SetBranchAddress("L1_DoubleJetC36_Prescl", &L1_DoubleJetC36_Prescl, &b_L1_DoubleJetC36_Prescl);
  fChain->SetBranchAddress("L1_TripleEG_12_7_5_Prescl", &L1_TripleEG_12_7_5_Prescl, &b_L1_TripleEG_12_7_5_Prescl);
  fChain->SetBranchAddress("L1_DoubleEG_13_7_Prescl", &L1_DoubleEG_13_7_Prescl, &b_L1_DoubleEG_13_7_Prescl);
  fChain->SetBranchAddress("L1_SingleEG24_Prescl", &L1_SingleEG24_Prescl, &b_L1_SingleEG24_Prescl);
  fChain->SetBranchAddress("L1_SingleEG22_Prescl", &L1_SingleEG22_Prescl, &b_L1_SingleEG22_Prescl);
  fChain->SetBranchAddress("L1_SingleIsoEG20er_Prescl", &L1_SingleIsoEG20er_Prescl, &b_L1_SingleIsoEG20er_Prescl);
  fChain->SetBranchAddress("L1_SingleIsoEG18er_Prescl", &L1_SingleIsoEG18er_Prescl, &b_L1_SingleIsoEG18er_Prescl);
  fChain->SetBranchAddress("L1_SingleEG18er_Prescl", &L1_SingleEG18er_Prescl, &b_L1_SingleEG18er_Prescl);
  fChain->SetBranchAddress("L1_SingleEG7_Prescl", &L1_SingleEG7_Prescl, &b_L1_SingleEG7_Prescl);
  fChain->SetBranchAddress("L1_ETT300_Prescl", &L1_ETT300_Prescl, &b_L1_ETT300_Prescl);
  fChain->SetBranchAddress("L1_HTT175_Prescl", &L1_HTT175_Prescl, &b_L1_HTT175_Prescl);
  fChain->SetBranchAddress("L1_HTT150_Prescl", &L1_HTT150_Prescl, &b_L1_HTT150_Prescl);
  fChain->SetBranchAddress("L1_HTT125_Prescl", &L1_HTT125_Prescl, &b_L1_HTT125_Prescl);
  fChain->SetBranchAddress("L1_ETM100_Prescl", &L1_ETM100_Prescl, &b_L1_ETM100_Prescl);
  fChain->SetBranchAddress("L1_ETM50_Prescl", &L1_ETM50_Prescl, &b_L1_ETM50_Prescl);
  fChain->SetBranchAddress("L1_ETM36_Prescl", &L1_ETM36_Prescl, &b_L1_ETM36_Prescl);
  fChain->SetBranchAddress("L1_QuadJet28_Central_Prescl", &L1_QuadJet28_Central_Prescl, &b_L1_QuadJet28_Central_Prescl);
  fChain->SetBranchAddress("L1_SingleJet128_Prescl", &L1_SingleJet128_Prescl, &b_L1_SingleJet128_Prescl);
  fChain->SetBranchAddress("L1_DoubleMu_10_Open_Prescl", &L1_DoubleMu_10_Open_Prescl, &b_L1_DoubleMu_10_Open_Prescl);
  fChain->SetBranchAddress("L1_SingleEG18_Prescl", &L1_SingleEG18_Prescl, &b_L1_SingleEG18_Prescl);
  fChain->SetBranchAddress("L1_Mu10_Eta2p1_DoubleJet_16_8_Central_Prescl", &L1_Mu10_Eta2p1_DoubleJet_16_8_Central_Prescl, &b_L1_Mu10_Eta2p1_DoubleJet_16_8_Central_Prescl);
  fChain->SetBranchAddress("L1_Mu12_EG5_Prescl", &L1_Mu12_EG5_Prescl, &b_L1_Mu12_EG5_Prescl);
  fChain->SetBranchAddress("L1_SingleMu16_Eta2p1_Prescl", &L1_SingleMu16_Eta2p1_Prescl, &b_L1_SingleMu16_Eta2p1_Prescl);
  fChain->SetBranchAddress("L1_DoubleMu0_HighQ_Prescl", &L1_DoubleMu0_HighQ_Prescl, &b_L1_DoubleMu0_HighQ_Prescl);
  fChain->SetBranchAddress("L1_SingleMu14_Eta2p1_Prescl", &L1_SingleMu14_Eta2p1_Prescl, &b_L1_SingleMu14_Eta2p1_Prescl);
  fChain->SetBranchAddress("L1_HTT50_HTM30_Prescl", &L1_HTT50_HTM30_Prescl, &b_L1_HTT50_HTM30_Prescl);
  fChain->SetBranchAddress("L1_DoubleEG5_HTT75_Prescl", &L1_DoubleEG5_HTT75_Prescl, &b_L1_DoubleEG5_HTT75_Prescl);
  fChain->SetBranchAddress("L1_DoubleJet64_Central_Prescl", &L1_DoubleJet64_Central_Prescl, &b_L1_DoubleJet64_Central_Prescl);
  fChain->SetBranchAddress("L1_DoubleTauJet44_Eta2p17_Prescl", &L1_DoubleTauJet44_Eta2p17_Prescl, &b_L1_DoubleTauJet44_Eta2p17_Prescl);
  fChain->SetBranchAddress("L1_TripleJet_36_36_12_Central_Prescl", &L1_TripleJet_36_36_12_Central_Prescl, &b_L1_TripleJet_36_36_12_Central_Prescl);
  fChain->SetBranchAddress("L1_EG5_HTT100_Prescl", &L1_EG5_HTT100_Prescl, &b_L1_EG5_HTT100_Prescl);
  fChain->SetBranchAddress("L1_EG5_DoubleJet20_Central_Prescl", &L1_EG5_DoubleJet20_Central_Prescl, &b_L1_EG5_DoubleJet20_Central_Prescl);
  fChain->SetBranchAddress("L1_TripleMu0_Prescl", &L1_TripleMu0_Prescl, &b_L1_TripleMu0_Prescl);
  fChain->SetBranchAddress("L1_DoubleMu3p5_Prescl", &L1_DoubleMu3p5_Prescl, &b_L1_DoubleMu3p5_Prescl);
  fChain->SetBranchAddress("L1_MuOpen_DoubleEG5_Prescl", &L1_MuOpen_DoubleEG5_Prescl, &b_L1_MuOpen_DoubleEG5_Prescl);
  fChain->SetBranchAddress("L1_DoubleMuOpen_EG5_Prescl", &L1_DoubleMuOpen_EG5_Prescl, &b_L1_DoubleMuOpen_EG5_Prescl);
  fChain->SetBranchAddress("L1_DoubleEG_12_5_Prescl", &L1_DoubleEG_12_5_Prescl, &b_L1_DoubleEG_12_5_Prescl);
  fChain->SetBranchAddress("L1_DoubleTauJet36_Eta2p17_Prescl", &L1_DoubleTauJet36_Eta2p17_Prescl, &b_L1_DoubleTauJet36_Eta2p17_Prescl);
  fChain->SetBranchAddress("L1_SingleJet52_Central_Prescl", &L1_SingleJet52_Central_Prescl, &b_L1_SingleJet52_Central_Prescl);
  fChain->SetBranchAddress("L1_DoubleJet52_Central_Prescl", &L1_DoubleJet52_Central_Prescl, &b_L1_DoubleJet52_Central_Prescl);
  fChain->SetBranchAddress("L1_DoubleTauJet40_Eta2p17_Prescl", &L1_DoubleTauJet40_Eta2p17_Prescl, &b_L1_DoubleTauJet40_Eta2p17_Prescl);
  fChain->SetBranchAddress("L1_Jet52_Central_ETM30_Prescl", &L1_Jet52_Central_ETM30_Prescl, &b_L1_Jet52_Central_ETM30_Prescl);
  fChain->SetBranchAddress("L1_DoubleJet44_Central_Prescl", &L1_DoubleJet44_Central_Prescl, &b_L1_DoubleJet44_Central_Prescl);
  fChain->SetBranchAddress("L1_Mu7_EG5_Prescl", &L1_Mu7_EG5_Prescl, &b_L1_Mu7_EG5_Prescl);
  fChain->SetBranchAddress("L1_MuOpen_EG12_Prescl", &L1_MuOpen_EG12_Prescl, &b_L1_MuOpen_EG12_Prescl);
  fChain->SetBranchAddress("L1_DoubleTauJet36_Prescl", &L1_DoubleTauJet36_Prescl, &b_L1_DoubleTauJet36_Prescl);
  fChain->SetBranchAddress("L1_TripleJet28_Central_Prescl", &L1_TripleJet28_Central_Prescl, &b_L1_TripleJet28_Central_Prescl);
  fChain->SetBranchAddress("L1_SingleJet36_FwdVeto5_Prescl", &L1_SingleJet36_FwdVeto5_Prescl, &b_L1_SingleJet36_FwdVeto5_Prescl);
  fChain->SetBranchAddress("L1_SingleTauJet68_Prescl", &L1_SingleTauJet68_Prescl, &b_L1_SingleTauJet68_Prescl);
  fChain->SetBranchAddress("L1_MuOpen_EG5_Prescl", &L1_MuOpen_EG5_Prescl, &b_L1_MuOpen_EG5_Prescl);
  fChain->SetBranchAddress("L1_SingleMu5_Eta1p5_Q80_v1_Prescl", &L1_SingleMu5_Eta1p5_Q80_v1_Prescl, &b_L1_SingleMu5_Eta1p5_Q80_v1_Prescl);
  fChain->SetBranchAddress("L1_HTT75_Prescl", &L1_HTT75_Prescl, &b_L1_HTT75_Prescl);
  fChain->SetBranchAddress("L1_ETT220_Prescl", &L1_ETT220_Prescl, &b_L1_ETT220_Prescl);
  fChain->SetBranchAddress("L1_SingleJet20_NotBptxOR_Prescl", &L1_SingleJet20_NotBptxOR_Prescl, &b_L1_SingleJet20_NotBptxOR_Prescl);
  fChain->SetBranchAddress("L1_BeamGas_Bsc_Prescl", &L1_BeamGas_Bsc_Prescl, &b_L1_BeamGas_Bsc_Prescl);
  fChain->SetBranchAddress("L1_PreCollisions_Prescl", &L1_PreCollisions_Prescl, &b_L1_PreCollisions_Prescl);
  fChain->SetBranchAddress("L1_BeamGas_Hf_Prescl", &L1_BeamGas_Hf_Prescl, &b_L1_BeamGas_Hf_Prescl);
  fChain->SetBranchAddress("L1_Mu3_Jet20_Central_Prescl", &L1_Mu3_Jet20_Central_Prescl, &b_L1_Mu3_Jet20_Central_Prescl);
  fChain->SetBranchAddress("L1_Mu3_Jet28_Central_Prescl", &L1_Mu3_Jet28_Central_Prescl, &b_L1_Mu3_Jet28_Central_Prescl);
  fChain->SetBranchAddress("L1_Mu3_Jet16_Central_Prescl", &L1_Mu3_Jet16_Central_Prescl, &b_L1_Mu3_Jet16_Central_Prescl);
  fChain->SetBranchAddress("L1_Mu7_Jet20_Central_Prescl", &L1_Mu7_Jet20_Central_Prescl, &b_L1_Mu7_Jet20_Central_Prescl);
  fChain->SetBranchAddress("L1_Mu3_JetC16_WdEtaPhi2_Prescl", &L1_Mu3_JetC16_WdEtaPhi2_Prescl, &b_L1_Mu3_JetC16_WdEtaPhi2_Prescl);
  fChain->SetBranchAddress("L1_Mu3_JetC52_WdEtaPhi2_Prescl", &L1_Mu3_JetC52_WdEtaPhi2_Prescl, &b_L1_Mu3_JetC52_WdEtaPhi2_Prescl);

  fChain->SetBranchAddress("L1_DoubleEG5_HTT50_Prescl", &L1_DoubleEG5_HTT50_Prescl, &b_L1_DoubleEG5_HTT50_Prescl);
  fChain->SetBranchAddress("L1_EG5_HTT75_Prescl", &L1_EG5_HTT75_Prescl, &b_L1_EG5_HTT75_Prescl);
  fChain->SetBranchAddress("L1_DoubleJet52_Prescl", &L1_DoubleJet52_Prescl, &b_L1_DoubleJet52_Prescl);
  fChain->SetBranchAddress("L1_SingleTauJet52_Prescl", &L1_SingleTauJet52_Prescl, &b_L1_SingleTauJet52_Prescl);
  fChain->SetBranchAddress("L1_DoubleTauJet28_Prescl", &L1_DoubleTauJet28_Prescl, &b_L1_DoubleTauJet28_Prescl);
  fChain->SetBranchAddress("L1_SingleJet20_NotBptxOR_NotMuBeamHalo_Prescl", &L1_SingleJet20_NotBptxOR_NotMuBeamHalo_Prescl, &b_L1_SingleJet20_NotBptxOR_NotMuBeamHalo_Prescl);
  fChain->SetBranchAddress("L1_SingleJet16_Prescl", &L1_SingleJet16_Prescl, &b_L1_SingleJet16_Prescl);
  fChain->SetBranchAddress("L1_SingleJet68_Prescl", &L1_SingleJet68_Prescl, &b_L1_SingleJet68_Prescl);
  fChain->SetBranchAddress("L1_SingleJet92_Prescl", &L1_SingleJet92_Prescl, &b_L1_SingleJet92_Prescl);
  fChain->SetBranchAddress("L1_DoubleForJet32_EtaOpp_Prescl", &L1_DoubleForJet32_EtaOpp_Prescl, &b_L1_DoubleForJet32_EtaOpp_Prescl);
  fChain->SetBranchAddress("L1_DoubleForJet44_EtaOpp_Prescl", &L1_DoubleForJet44_EtaOpp_Prescl, &b_L1_DoubleForJet44_EtaOpp_Prescl);
  fChain->SetBranchAddress("L1_DoubleEG2_FwdVeto_Prescl", &L1_DoubleEG2_FwdVeto_Prescl, &b_L1_DoubleEG2_FwdVeto_Prescl);
  fChain->SetBranchAddress("L1_SingleJet36_FwdVeto_Prescl", &L1_SingleJet36_FwdVeto_Prescl, &b_L1_SingleJet36_FwdVeto_Prescl);
  fChain->SetBranchAddress("L1_TripleEG7_Prescl", &L1_TripleEG7_Prescl, &b_L1_TripleEG7_Prescl);
  fChain->SetBranchAddress("L1_TripleEG5_Prescl", &L1_TripleEG5_Prescl, &b_L1_TripleEG5_Prescl);
  fChain->SetBranchAddress("L1_TripleJet28_Prescl", &L1_TripleJet28_Prescl, &b_L1_TripleJet28_Prescl);
  fChain->SetBranchAddress("L1_Mu0_HTT50_Prescl", &L1_Mu0_HTT50_Prescl, &b_L1_Mu0_HTT50_Prescl);
  fChain->SetBranchAddress("L1_SingleEG12_Eta2p17_Prescl", &L1_SingleEG12_Eta2p17_Prescl, &b_L1_SingleEG12_Eta2p17_Prescl);
  fChain->SetBranchAddress("L1_SingleEG30_Prescl", &L1_SingleEG30_Prescl, &b_L1_SingleEG30_Prescl);
  fChain->SetBranchAddress("L1_Mu3_Jet20_Prescl", &L1_Mu3_Jet20_Prescl, &b_L1_Mu3_Jet20_Prescl);
  fChain->SetBranchAddress("L1_Mu3_Jet16_Prescl", &L1_Mu3_Jet16_Prescl, &b_L1_Mu3_Jet16_Prescl);
  fChain->SetBranchAddress("L1_SingleMu16_Prescl", &L1_SingleMu16_Prescl, &b_L1_SingleMu16_Prescl);
  fChain->SetBranchAddress("L1_SingleMu25_Prescl", &L1_SingleMu25_Prescl, &b_L1_SingleMu25_Prescl);
  fChain->SetBranchAddress("L1_DoubleMu5_Prescl", &L1_DoubleMu5_Prescl, &b_L1_DoubleMu5_Prescl);
  fChain->SetBranchAddress("L1_SingleMu5_Eta1p5_Q80_Prescl", &L1_SingleMu5_Eta1p5_Q80_Prescl, &b_L1_SingleMu5_Eta1p5_Q80_Prescl);
  fChain->SetBranchAddress("L1_DoubleMu_0_5_Prescl", &L1_DoubleMu_0_5_Prescl, &b_L1_DoubleMu_0_5_Prescl);
  fChain->SetBranchAddress("L1_SingleMu12_Prescl", &L1_SingleMu12_Prescl, &b_L1_SingleMu12_Prescl);
  fChain->SetBranchAddress("L1_DoubleMu0_Prescl", &L1_DoubleMu0_Prescl, &b_L1_DoubleMu0_Prescl);
  fChain->SetBranchAddress("L1_QuadJet20_Central_Prescl", &L1_QuadJet20_Central_Prescl, &b_L1_QuadJet20_Central_Prescl);
  fChain->SetBranchAddress("L1_DoubleJet36_Central_Prescl", &L1_DoubleJet36_Central_Prescl, &b_L1_DoubleJet36_Central_Prescl);
  fChain->SetBranchAddress("L1_SingleJet52_Prescl", &L1_SingleJet52_Prescl, &b_L1_SingleJet52_Prescl);
  fChain->SetBranchAddress("L1_SingleJet36_Prescl", &L1_SingleJet36_Prescl, &b_L1_SingleJet36_Prescl);
   fChain->SetBranchAddress("L1_Mu3_Jet10_Prescl", &L1_Mu3_Jet10_Prescl, &b_L1_Mu3_Jet10_Prescl);
   fChain->SetBranchAddress("L1_SingleJet10U_NotBptxOR_Ext_Prescl", &L1_SingleJet10U_NotBptxOR_Ext_Prescl, &b_L1_SingleJet10U_NotBptxOR_Ext_Prescl);
   fChain->SetBranchAddress("L1_SingleJet10_NotBptxOR_Ext_Prescl", &L1_SingleJet10_NotBptxOR_Ext_Prescl, &b_L1_SingleJet10_NotBptxOR_Ext_Prescl);
   fChain->SetBranchAddress("L1_SingleJet10U_NotBptxOR_Prescl", &L1_SingleJet10U_NotBptxOR_Prescl, &b_L1_SingleJet10U_NotBptxOR_Prescl);
   fChain->SetBranchAddress("L1_SingleJet10_NotBptxOR_Prescl", &L1_SingleJet10_NotBptxOR_Prescl, &b_L1_SingleJet10_NotBptxOR_Prescl);
   fChain->SetBranchAddress("L1_Mu3_EG5_Prescl", &L1_Mu3_EG5_Prescl, &b_L1_Mu3_EG5_Prescl);

   //L1 algorithm bit prescales
   fChain->SetBranchAddress("L1_DoubleMuTopBottom_Prescl", &L1_DoubleMuTopBottom_Prescl, &b_L1_DoubleMuTopBottom_Prescl);
   fChain->SetBranchAddress("L1_DoubleEG05_TopBottom_Prescl", &L1_DoubleEG05_TopBottom_Prescl, &b_L1_DoubleEG05_TopBottom_Prescl);
   fChain->SetBranchAddress("L1_IsoEG10_Jet6_ForJet6_Prescl", &L1_IsoEG10_Jet6_ForJet6_Prescl, &b_L1_IsoEG10_Jet6_ForJet6_Prescl);
   fChain->SetBranchAddress("L1_SingleJet20_Prescl", &L1_SingleJet20_Prescl, &b_L1_SingleJet20_Prescl);
   fChain->SetBranchAddress("L1_SingleJet40_Prescl", &L1_SingleJet40_Prescl, &b_L1_SingleJet40_Prescl);
   fChain->SetBranchAddress("L1_SingleJet60_Prescl", &L1_SingleJet60_Prescl, &b_L1_SingleJet60_Prescl);
   fChain->SetBranchAddress("L1_SingleTauJet10_Prescl", &L1_SingleTauJet10_Prescl, &b_L1_SingleTauJet10_Prescl);
   fChain->SetBranchAddress("L1_SingleTauJet20_Prescl", &L1_SingleTauJet20_Prescl, &b_L1_SingleTauJet20_Prescl);
   fChain->SetBranchAddress("L1_SingleTauJet50_Prescl", &L1_SingleTauJet50_Prescl, &b_L1_SingleTauJet50_Prescl);
   fChain->SetBranchAddress("L1_DoubleJet30_Prescl", &L1_DoubleJet30_Prescl, &b_L1_DoubleJet30_Prescl);
   fChain->SetBranchAddress("L1_TripleJet14_Prescl", &L1_TripleJet14_Prescl, &b_L1_TripleJet14_Prescl);
   fChain->SetBranchAddress("L1_QuadJet6_Prescl", &L1_QuadJet6_Prescl, &b_L1_QuadJet6_Prescl);
   fChain->SetBranchAddress("L1_QuadJet8_Prescl", &L1_QuadJet8_Prescl, &b_L1_QuadJet8_Prescl);
   fChain->SetBranchAddress("L1_Mu5_Jet6_Prescl", &L1_Mu5_Jet6_Prescl, &b_L1_Mu5_Jet6_Prescl);
   fChain->SetBranchAddress("L1_EG5_TripleJet6_Prescl", &L1_EG5_TripleJet6_Prescl, &b_L1_EG5_TripleJet6_Prescl);
   fChain->SetBranchAddress("L1_SingleJet6_Prescl", &L1_SingleJet6_Prescl, &b_L1_SingleJet6_Prescl);
   fChain->SetBranchAddress("L1_SingleJet10_Prescl", &L1_SingleJet10_Prescl, &b_L1_SingleJet10_Prescl);
   fChain->SetBranchAddress("L1_SingleJet10_NotBptxC_Ext_Prescl", &L1_SingleJet10_NotBptxC_Ext_Prescl, &b_L1_SingleJet10_NotBptxC_Ext_Prescl);
   fChain->SetBranchAddress("L1_DoubleEG1_Prescl", &L1_DoubleEG1_Prescl, &b_L1_DoubleEG1_Prescl);
   fChain->SetBranchAddress("L1_DoubleEG2_Prescl", &L1_DoubleEG2_Prescl, &b_L1_DoubleEG2_Prescl);
   fChain->SetBranchAddress("L1_DoubleEG5_Prescl", &L1_DoubleEG5_Prescl, &b_L1_DoubleEG5_Prescl);
   fChain->SetBranchAddress("L1_DoubleHfBitCountsRing1_P1N1_Prescl", &L1_DoubleHfBitCountsRing1_P1N1_Prescl, &b_L1_DoubleHfBitCountsRing1_P1N1_Prescl);
   fChain->SetBranchAddress("L1_DoubleHfBitCountsRing2_P1N1_Prescl", &L1_DoubleHfBitCountsRing2_P1N1_Prescl, &b_L1_DoubleHfBitCountsRing2_P1N1_Prescl);
   fChain->SetBranchAddress("L1_DoubleHfRingEtSumsRing1_P200N200_Prescl", &L1_DoubleHfRingEtSumsRing1_P200N200_Prescl, &b_L1_DoubleHfRingEtSumsRing1_P200N200_Prescl);
   fChain->SetBranchAddress("L1_DoubleHfRingEtSumsRing1_P4N4_Prescl", &L1_DoubleHfRingEtSumsRing1_P4N4_Prescl, &b_L1_DoubleHfRingEtSumsRing1_P4N4_Prescl);
   fChain->SetBranchAddress("L1_DoubleHfRingEtSumsRing2_P200N200_Prescl", &L1_DoubleHfRingEtSumsRing2_P200N200_Prescl, &b_L1_DoubleHfRingEtSumsRing2_P200N200_Prescl);
   fChain->SetBranchAddress("L1_DoubleHfRingEtSumsRing2_P4N4_Prescl", &L1_DoubleHfRingEtSumsRing2_P4N4_Prescl, &b_L1_DoubleHfRingEtSumsRing2_P4N4_Prescl);
   fChain->SetBranchAddress("L1_DoubleJet70_Prescl", &L1_DoubleJet70_Prescl, &b_L1_DoubleJet70_Prescl);
   fChain->SetBranchAddress("L1_DoubleMu3_Prescl", &L1_DoubleMu3_Prescl, &b_L1_DoubleMu3_Prescl);
   fChain->SetBranchAddress("L1_DoubleMuOpen_Prescl", &L1_DoubleMuOpen_Prescl, &b_L1_DoubleMuOpen_Prescl);
   fChain->SetBranchAddress("L1_DoubleTauJet30_Prescl", &L1_DoubleTauJet30_Prescl, &b_L1_DoubleTauJet30_Prescl);
   fChain->SetBranchAddress("L1_EG10_Jet15_Prescl", &L1_EG10_Jet15_Prescl, &b_L1_EG10_Jet15_Prescl);
   fChain->SetBranchAddress("L1_EG5_TripleJet15_Prescl", &L1_EG5_TripleJet15_Prescl, &b_L1_EG5_TripleJet15_Prescl);
   fChain->SetBranchAddress("L1_ETM20_Prescl", &L1_ETM20_Prescl, &b_L1_ETM20_Prescl);
   fChain->SetBranchAddress("L1_ETM30_Prescl", &L1_ETM30_Prescl, &b_L1_ETM30_Prescl);
   fChain->SetBranchAddress("L1_ETM40_Prescl", &L1_ETM40_Prescl, &b_L1_ETM40_Prescl);
   fChain->SetBranchAddress("L1_ETM70_Prescl", &L1_ETM70_Prescl, &b_L1_ETM70_Prescl);
   fChain->SetBranchAddress("L1_ETM80_Prescl", &L1_ETM80_Prescl, &b_L1_ETM80_Prescl);
   fChain->SetBranchAddress("L1_ETT60_Prescl", &L1_ETT60_Prescl, &b_L1_ETT60_Prescl);
   fChain->SetBranchAddress("L1_ETT100_Prescl", &L1_ETT100_Prescl, &b_L1_ETT100_Prescl);
   fChain->SetBranchAddress("L1_ETT140_Prescl", &L1_ETT140_Prescl, &b_L1_ETT140_Prescl);
   fChain->SetBranchAddress("L1_HTT50_Prescl", &L1_HTT50_Prescl, &b_L1_HTT50_Prescl);
   fChain->SetBranchAddress("L1_HTT100_Prescl", &L1_HTT100_Prescl, &b_L1_HTT100_Prescl);
   fChain->SetBranchAddress("L1_HTT200_Prescl", &L1_HTT200_Prescl, &b_L1_HTT200_Prescl);
   fChain->SetBranchAddress("L1_HTT300_Prescl", &L1_HTT300_Prescl, &b_L1_HTT300_Prescl);
   fChain->SetBranchAddress("L1_IsoEG10_Jet15_ForJet10_Prescl", &L1_IsoEG10_Jet15_ForJet10_Prescl, &b_L1_IsoEG10_Jet15_ForJet10_Prescl);
   fChain->SetBranchAddress("L1_MinBias_HTT10_Prescl", &L1_MinBias_HTT10_Prescl, &b_L1_MinBias_HTT10_Prescl);
   fChain->SetBranchAddress("L1_Mu3_EG5_Prescl", &L1_Mu3QE8_EG5_Prescl, &b_L1_Mu3QE8_EG5_Prescl);
   fChain->SetBranchAddress("L1_Mu3QE8_Jet15_Prescl", &L1_Mu3QE8_Jet15_Prescl, &b_L1_Mu3QE8_Jet15_Prescl);
   fChain->SetBranchAddress("L1_Mu5QE8_Jet15_Prescl", &L1_Mu5QE8_Jet15_Prescl, &b_L1_Mu5QE8_Jet15_Prescl);
   fChain->SetBranchAddress("L1_Mu3QE8_Jet6_Prescl", &L1_Mu3QE8_Jet6_Prescl, &b_L1_Mu3QE8_Jet6_Prescl);
   fChain->SetBranchAddress("L1_Mu5QE8_Jet6_Prescl", &L1_Mu5QE8_Jet6_Prescl, &b_L1_Mu5QE8_Jet6_Prescl);
   fChain->SetBranchAddress("L1_QuadJet15_Prescl", &L1_QuadJet15_Prescl, &b_L1_QuadJet15_Prescl);
   fChain->SetBranchAddress("L1_SingleEG1_Prescl", &L1_SingleEG1_Prescl, &b_L1_SingleEG1_Prescl);
   fChain->SetBranchAddress("L1_SingleEG10_Prescl", &L1_SingleEG10_Prescl, &b_L1_SingleEG10_Prescl);
   fChain->SetBranchAddress("L1_SingleEG12_Prescl", &L1_SingleEG12_Prescl, &b_L1_SingleEG12_Prescl);
   fChain->SetBranchAddress("L1_SingleEG15_Prescl", &L1_SingleEG15_Prescl, &b_L1_SingleEG15_Prescl);
   fChain->SetBranchAddress("L1_SingleEG2_Prescl", &L1_SingleEG2_Prescl, &b_L1_SingleEG2_Prescl);
   fChain->SetBranchAddress("L1_SingleEG20_Prescl", &L1_SingleEG20_Prescl, &b_L1_SingleEG20_Prescl);
   fChain->SetBranchAddress("L1_SingleEG5_Prescl", &L1_SingleEG5_Prescl, &b_L1_SingleEG5_Prescl);
   fChain->SetBranchAddress("L1_SingleEG8_Prescl", &L1_SingleEG8_Prescl, &b_L1_SingleEG8_Prescl);
   fChain->SetBranchAddress("L1_SingleHfBitCountsRing1_1_Prescl", &L1_SingleHfBitCountsRing1_1_Prescl, &b_L1_SingleHfBitCountsRing1_1_Prescl);
   fChain->SetBranchAddress("L1_SingleHfBitCountsRing2_1_Prescl", &L1_SingleHfBitCountsRing2_1_Prescl, &b_L1_SingleHfBitCountsRing2_1_Prescl);
   fChain->SetBranchAddress("L1_SingleHfRingEtSumsRing1_200_Prescl", &L1_SingleHfRingEtSumsRing1_200_Prescl, &b_L1_SingleHfRingEtSumsRing1_200_Prescl);
   fChain->SetBranchAddress("L1_SingleHfRingEtSumsRing1_4_Prescl", &L1_SingleHfRingEtSumsRing1_4_Prescl, &b_L1_SingleHfRingEtSumsRing1_4_Prescl);
   fChain->SetBranchAddress("L1_SingleHfRingEtSumsRing2_200_Prescl", &L1_SingleHfRingEtSumsRing2_200_Prescl, &b_L1_SingleHfRingEtSumsRing2_200_Prescl);
   fChain->SetBranchAddress("L1_SingleHfRingEtSumsRing2_4_Prescl", &L1_SingleHfRingEtSumsRing2_4_Prescl, &b_L1_SingleHfRingEtSumsRing2_4_Prescl);
   fChain->SetBranchAddress("L1_SingleIsoEG10_Prescl", &L1_SingleIsoEG10_Prescl, &b_L1_SingleIsoEG10_Prescl);
   fChain->SetBranchAddress("L1_SingleIsoEG12_Prescl", &L1_SingleIsoEG12_Prescl, &b_L1_SingleIsoEG12_Prescl);
   fChain->SetBranchAddress("L1_SingleIsoEG15_Prescl", &L1_SingleIsoEG15_Prescl, &b_L1_SingleIsoEG15_Prescl);
   fChain->SetBranchAddress("L1_SingleIsoEG5_Prescl", &L1_SingleIsoEG5_Prescl, &b_L1_SingleIsoEG5_Prescl);
   fChain->SetBranchAddress("L1_SingleIsoEG8_Prescl", &L1_SingleIsoEG8_Prescl, &b_L1_SingleIsoEG8_Prescl);
   fChain->SetBranchAddress("L1_SingleJet100_Prescl", &L1_SingleJet100_Prescl, &b_L1_SingleJet100_Prescl);
   fChain->SetBranchAddress("L1_SingleJet15_Prescl", &L1_SingleJet15_Prescl, &b_L1_SingleJet15_Prescl);
   fChain->SetBranchAddress("L1_SingleJet30_Prescl", &L1_SingleJet30_Prescl, &b_L1_SingleJet30_Prescl);
   fChain->SetBranchAddress("L1_SingleJet50_Prescl", &L1_SingleJet50_Prescl, &b_L1_SingleJet50_Prescl);
   fChain->SetBranchAddress("L1_SingleJet70_Prescl", &L1_SingleJet70_Prescl, &b_L1_SingleJet70_Prescl);
   fChain->SetBranchAddress("L1_SingleMu0_Prescl", &L1_SingleMu0_Prescl, &b_L1_SingleMu0_Prescl);
   fChain->SetBranchAddress("L1_SingleMu10_Prescl", &L1_SingleMu10_Prescl, &b_L1_SingleMu10_Prescl);
   fChain->SetBranchAddress("L1_SingleMu14_Prescl", &L1_SingleMu14_Prescl, &b_L1_SingleMu14_Prescl);
   fChain->SetBranchAddress("L1_SingleMu20_Prescl", &L1_SingleMu20_Prescl, &b_L1_SingleMu20_Prescl);
   fChain->SetBranchAddress("L1_SingleMu3_Prescl", &L1_SingleMu3_Prescl, &b_L1_SingleMu3_Prescl);
   fChain->SetBranchAddress("L1_SingleMu5_Prescl", &L1_SingleMu5_Prescl, &b_L1_SingleMu5_Prescl);
   fChain->SetBranchAddress("L1_SingleMu7_Prescl", &L1_SingleMu7_Prescl, &b_L1_SingleMu7_Prescl);
   fChain->SetBranchAddress("L1_SingleMuBeamHalo_Prescl", &L1_SingleMuBeamHalo_Prescl, &b_L1_SingleMuBeamHalo_Prescl);
   fChain->SetBranchAddress("L1_SingleMuOpen_Prescl", &L1_SingleMuOpen_Prescl, &b_L1_SingleMuOpen_Prescl);
   fChain->SetBranchAddress("L1_SingleTauJet30_Prescl", &L1_SingleTauJet30_Prescl, &b_L1_SingleTauJet30_Prescl);
   fChain->SetBranchAddress("L1_SingleTauJet40_Prescl", &L1_SingleTauJet40_Prescl, &b_L1_SingleTauJet40_Prescl);
   fChain->SetBranchAddress("L1_SingleTauJet60_Prescl", &L1_SingleTauJet60_Prescl, &b_L1_SingleTauJet60_Prescl);
   fChain->SetBranchAddress("L1_SingleTauJet80_Prescl", &L1_SingleTauJet80_Prescl, &b_L1_SingleTauJet80_Prescl);
   fChain->SetBranchAddress("L1_TripleJet30_Prescl", &L1_TripleJet30_Prescl, &b_L1_TripleJet30_Prescl);
   fChain->SetBranchAddress("L1_ZeroBias_Prescl", &L1_ZeroBias_Prescl, &b_L1_ZeroBias_Prescl);
   fChain->SetBranchAddress("L1_ZeroBias_Ext_Prescl", &L1_ZeroBias_Ext_Prescl, &b_L1_ZeroBias_Ext_Prescl);
   fChain->SetBranchAddress("L1_SingleCenJet2_Prescl", &L1_SingleCenJet2_Prescl, &b_L1_SingleCenJet2_Prescl);
   fChain->SetBranchAddress("L1_SingleCenJet4_Prescl", &L1_SingleCenJet4_Prescl, &b_L1_SingleCenJet4_Prescl);
   fChain->SetBranchAddress("L1_SingleForJet2_Prescl", &L1_SingleForJet2_Prescl, &b_L1_SingleForJet2_Prescl);
   fChain->SetBranchAddress("L1_SingleForJet4_Prescl", &L1_SingleForJet4_Prescl, &b_L1_SingleForJet4_Prescl);
   fChain->SetBranchAddress("L1_SingleTauJet2_Prescl", &L1_SingleTauJet2_Prescl, &b_L1_SingleTauJet2_Prescl);
   fChain->SetBranchAddress("L1_SingleTauJet4_Prescl", &L1_SingleTauJet4_Prescl, &b_L1_SingleTauJet4_Prescl);
   fChain->SetBranchAddress("L1_DoubleForJet10_EtaOpp_Prescl", &L1_DoubleForJet10_EtaOpp_Prescl, &b_L1_DoubleForJet10_EtaOpp_Prescl);
   fChain->SetBranchAddress("L1_Mu3_Jet6_Prescl", &L1_Mu3_Jet6_Prescl, &b_L1_Mu3_Jet6_Prescl);

   // L1 Technical bit prescales
   fChain->SetBranchAddress("L1Tech_BPTX_minus.v0_Prescl", &L1Tech_BPTX_minus_v0_Prescl, &b_L1Tech_BPTX_minus_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_BPTX_minus_AND_not_plus.v0_Prescl", &L1Tech_BPTX_minus_AND_not_plus_v0_Prescl, &b_L1Tech_BPTX_minus_AND_not_plus_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_BPTX_plus.v0_Prescl", &L1Tech_BPTX_plus_v0_Prescl, &b_L1Tech_BPTX_plus_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_BPTX_plus_AND_NOT_minus.v0_Prescl", &L1Tech_BPTX_plus_AND_NOT_minus_v0_Prescl, &b_L1Tech_BPTX_plus_AND_NOT_minus_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_BPTX_plus_AND_minus.v0_Prescl", &L1Tech_BPTX_plus_AND_minus_v0_Prescl, &b_L1Tech_BPTX_plus_AND_minus_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_BPTX_plus_AND_minus_instance1.v0_Prescl", &L1Tech_BPTX_plus_AND_minus_instance1_v0_Prescl, &b_L1Tech_BPTX_plus_AND_minus_instance1_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_BPTX_plus_OR_minus.v0_Prescl", &L1Tech_BPTX_plus_OR_minus_v0_Prescl, &b_L1Tech_BPTX_plus_OR_minus_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_BPTX_quiet.v0_Prescl", &L1Tech_BPTX_quiet_v0_Prescl, &b_L1Tech_BPTX_quiet_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_BSC_HighMultiplicity.v0_Prescl", &L1Tech_BSC_HighMultiplicity_v0_Prescl, &b_L1Tech_BSC_HighMultiplicity_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_BSC_halo_beam1_inner.v0_Prescl", &L1Tech_BSC_halo_beam1_inner_v0_Prescl, &b_L1Tech_BSC_halo_beam1_inner_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_BSC_halo_beam1_outer.v0_Prescl", &L1Tech_BSC_halo_beam1_outer_v0_Prescl, &b_L1Tech_BSC_halo_beam1_outer_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_BSC_halo_beam2_inner.v0_Prescl", &L1Tech_BSC_halo_beam2_inner_v0_Prescl, &b_L1Tech_BSC_halo_beam2_inner_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_BSC_halo_beam2_outer.v0_Prescl", &L1Tech_BSC_halo_beam2_outer_v0_Prescl, &b_L1Tech_BSC_halo_beam2_outer_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_BSC_minBias_OR.v0_Prescl", &L1Tech_BSC_minBias_OR_v0_Prescl, &b_L1Tech_BSC_minBias_OR_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_BSC_minBias_inner_threshold1.v0_Prescl", &L1Tech_BSC_minBias_inner_threshold1_v0_Prescl, &b_L1Tech_BSC_minBias_inner_threshold1_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_BSC_minBias_inner_threshold2.v0_Prescl", &L1Tech_BSC_minBias_inner_threshold2_v0_Prescl, &b_L1Tech_BSC_minBias_inner_threshold2_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_BSC_minBias_threshold1.v0_Prescl", &L1Tech_BSC_minBias_threshold1_v0_Prescl, &b_L1Tech_BSC_minBias_threshold1_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_BSC_minBias_threshold2.v0_Prescl", &L1Tech_BSC_minBias_threshold2_v0_Prescl, &b_L1Tech_BSC_minBias_threshold2_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_BSC_splash_beam1.v0_Prescl", &L1Tech_BSC_splash_beam1_v0_Prescl, &b_L1Tech_BSC_splash_beam1_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_BSC_splash_beam2.v0_Prescl", &L1Tech_BSC_splash_beam2_v0_Prescl, &b_L1Tech_BSC_splash_beam2_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_HCAL_HBHE_totalOR.v0_Prescl", &L1Tech_HCAL_HBHE_totalOR_v0_Prescl, &b_L1Tech_HCAL_HBHE_totalOR_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_HCAL_HF_totalOR_coincidenceHFM.v0_Prescl", &L1Tech_HCAL_HF_totalOR_coincidenceHFM_v0_Prescl, &b_L1Tech_HCAL_HF_totalOR_coincidenceHFM_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_HCAL_HF_totalOR_coincidenceHFP.v0_Prescl", &L1Tech_HCAL_HF_totalOR_coincidenceHFP_v0_Prescl, &b_L1Tech_HCAL_HF_totalOR_coincidenceHFP_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_HCAL_HF_totalOR_minBias.v0_Prescl", &L1Tech_HCAL_HF_totalOR_minBias_v0_Prescl, &b_L1Tech_HCAL_HF_totalOR_minBias_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_HCAL_HO_totalOR.v0_Prescl", &L1Tech_HCAL_HO_totalOR_v0_Prescl, &b_L1Tech_HCAL_HO_totalOR_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_RPC_TTU_RB0_Cosmics.v0_Prescl", &L1Tech_RPC_TTU_RB0_Cosmics_v0_Prescl, &b_L1Tech_RPC_TTU_RB0_Cosmics_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_RPC_TTU_RBminus1_Cosmics.v0_Prescl", &L1Tech_RPC_TTU_RBminus1_Cosmics_v0_Prescl, &b_L1Tech_RPC_TTU_RBminus1_Cosmics_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_RPC_TTU_RBminus2_Cosmics.v0_Prescl", &L1Tech_RPC_TTU_RBminus2_Cosmics_v0_Prescl, &b_L1Tech_RPC_TTU_RBminus2_Cosmics_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_RPC_TTU_RBplus1_Cosmics.v0_Prescl", &L1Tech_RPC_TTU_RBplus1_Cosmics_v0_Prescl, &b_L1Tech_RPC_TTU_RBplus1_Cosmics_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_RPC_TTU_RBplus2_Cosmics.v0_Prescl", &L1Tech_RPC_TTU_RBplus2_Cosmics_v0_Prescl, &b_L1Tech_RPC_TTU_RBplus2_Cosmics_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_RPC_TTU_barrel_Cosmics.v0_Prescl", &L1Tech_RPC_TTU_barrel_Cosmics_v0_Prescl, &b_L1Tech_RPC_TTU_barrel_Cosmics_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_RPC_TTU_pointing_Cosmics.v0_Prescl", &L1Tech_RPC_TTU_pointing_Cosmics_v0_Prescl, &b_L1Tech_RPC_TTU_pointing_Cosmics_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_RPC_TTU_RBst1_collisions.v0_Prescl", &L1Tech_RPC_TTU_RBst1_collisions_v0_Prescl, &b_L1Tech_RPC_TTU_RBst1_collisions_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_HCAL_HF_MM_or_PP_or_PM.v0_Prescl", &L1Tech_HCAL_HF_MM_or_PP_or_PM_v0_Prescl, &b_L1Tech_HCAL_HF_MM_or_PP_or_PM_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_HCAL_HF_coincidence_PM.v1_Prescl", &L1Tech_HCAL_HF_coincidence_PM_v1_Prescl, &b_L1Tech_HCAL_HF_coincidence_PM_v1_Prescl);
   fChain->SetBranchAddress("L1Tech_HCAL_HF_MMP_or_MPP.v0_Prescl", &L1Tech_HCAL_HF_MMP_or_MPP_v0_Prescl, &b_L1Tech_HCAL_HF_MMP_or_MPP_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_ZDC_loose_vertex.v0_Prescl", &L1Tech_ZDC_loose_vertex_v0_Prescl, &b_L1Tech_ZDC_loose_vertex_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_ZDC_minus_over_threshold.v0_Prescl", &L1Tech_ZDC_minus_over_threshold_v0_Prescl, &b_L1Tech_ZDC_minus_over_threshold_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_ZDC_plus_over_threshold.v0_Prescl", &L1Tech_ZDC_plus_over_threshold_v0_Prescl, &b_L1Tech_ZDC_plus_over_threshold_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_ZDC_tight_vertex.v0_Prescl", &L1Tech_ZDC_tight_vertex_v0_Prescl, &b_L1Tech_ZDC_tight_vertex_v0_Prescl);
   fChain->SetBranchAddress("L1_BptxMinus_Prescl", &L1_BptxMinus_Prescl, &b_L1_BptxMinus_Prescl);
   fChain->SetBranchAddress("L1_BptxPlus_Prescl", &L1_BptxPlus_Prescl, &b_L1_BptxPlus_Prescl);
   fChain->SetBranchAddress("L1_BptxPlusORMinus_Prescl", &L1_BptxPlusORMinus_Prescl, &b_L1_BptxPlusORMinus_Prescl);
   fChain->SetBranchAddress("L1_BptxPlus_NotBptxMinus_Prescl", &L1_BptxPlus_NotBptxMinus_Prescl, &b_L1_BptxPlus_NotBptxMinus_Prescl);
   fChain->SetBranchAddress("L1_BptxMinus_NotBptxPlus_Prescl", &L1_BptxMinus_NotBptxPlus_Prescl, &b_L1_BptxMinus_NotBptxPlus_Prescl);
   fChain->SetBranchAddress("L1_BscHighMultiplicity_Prescl", &L1_BscHighMultiplicity_Prescl, &b_L1_BscHighMultiplicity_Prescl);
   fChain->SetBranchAddress("L1_BscMinBiasInnerThreshold1_Prescl", &L1_BscMinBiasInnerThreshold1_Prescl, &b_L1_BscMinBiasInnerThreshold1_Prescl);
   fChain->SetBranchAddress("L1_BscMinBiasInnerThreshold2_Prescl", &L1_BscMinBiasInnerThreshold2_Prescl, &b_L1_BscMinBiasInnerThreshold2_Prescl);
   fChain->SetBranchAddress("L1_BscMinBiasOR_Prescl", &L1_BscMinBiasOR_Prescl, &b_L1_BscMinBiasOR_Prescl);
   fChain->SetBranchAddress("L1_BscMinBiasOR_BptxPlusORMinus_Prescl", &L1_BscMinBiasOR_BptxPlusORMinus_Prescl, &b_L1_BscMinBiasOR_BptxPlusORMinus_Prescl);
   fChain->SetBranchAddress("L1_BscMinBiasOR_BptxPlusANDMinus_Prescl", &L1_BscMinBiasOR_BptxPlusANDMinus_Prescl, &b_L1_BscMinBiasOR_BptxPlusANDMinus_Prescl);



   // Autogenerated from ConfDB - SetBranchAddressBits
   fChain->SetBranchAddress("HLT_PFJet40_v6", &HLT_PFJet40_v6, &b_HLT_PFJet40_v6);
   fChain->SetBranchAddress("HLT_PFJet80_v6", &HLT_PFJet80_v6, &b_HLT_PFJet80_v6);
   fChain->SetBranchAddress("HLT_PFJet140_v6", &HLT_PFJet140_v6, &b_HLT_PFJet140_v6);
   fChain->SetBranchAddress("HLT_PFJet200_v6", &HLT_PFJet200_v6, &b_HLT_PFJet200_v6);
   fChain->SetBranchAddress("HLT_PFJet260_v6", &HLT_PFJet260_v6, &b_HLT_PFJet260_v6);
   fChain->SetBranchAddress("HLT_PFJet320_v6", &HLT_PFJet320_v6, &b_HLT_PFJet320_v6);
   fChain->SetBranchAddress("HLT_Jet370_NoJetID_v14", &HLT_Jet370_NoJetID_v14, &b_HLT_Jet370_NoJetID_v14);
   fChain->SetBranchAddress("HLT_PFJet400_v6", &HLT_PFJet400_v6, &b_HLT_PFJet400_v6);
   fChain->SetBranchAddress("HLT_MonoCentralPFJet80_PFMETnoMu105_NHEF0p95_v1", &HLT_MonoCentralPFJet80_PFMETnoMu105_NHEF0p95_v1, &b_HLT_MonoCentralPFJet80_PFMETnoMu105_NHEF0p95_v1);
   fChain->SetBranchAddress("HLT_SingleForJet25_v3", &HLT_SingleForJet25_v3, &b_HLT_SingleForJet25_v3);
   fChain->SetBranchAddress("HLT_SingleForJet15_v3", &HLT_SingleForJet15_v3, &b_HLT_SingleForJet15_v3);
   fChain->SetBranchAddress("HLT_DiPFJetAve40_v7", &HLT_DiPFJetAve40_v7, &b_HLT_DiPFJetAve40_v7);
   fChain->SetBranchAddress("HLT_DiPFJetAve80_v7", &HLT_DiPFJetAve80_v7, &b_HLT_DiPFJetAve80_v7);
   fChain->SetBranchAddress("HLT_DiPFJetAve140_v7", &HLT_DiPFJetAve140_v7, &b_HLT_DiPFJetAve140_v7);
   fChain->SetBranchAddress("HLT_DiPFJetAve200_v7", &HLT_DiPFJetAve200_v7, &b_HLT_DiPFJetAve200_v7);
   fChain->SetBranchAddress("HLT_DiPFJetAve260_v7", &HLT_DiPFJetAve260_v7, &b_HLT_DiPFJetAve260_v7);
   fChain->SetBranchAddress("HLT_DiPFJetAve320_v7", &HLT_DiPFJetAve320_v7, &b_HLT_DiPFJetAve320_v7);
   fChain->SetBranchAddress("HLT_DiPFJetAve400_v7", &HLT_DiPFJetAve400_v7, &b_HLT_DiPFJetAve400_v7);
   fChain->SetBranchAddress("HLT_FatDiPFJetMass750_DR1p1_Deta1p5_v6", &HLT_FatDiPFJetMass750_DR1p1_Deta1p5_v6, &b_HLT_FatDiPFJetMass750_DR1p1_Deta1p5_v6);
   fChain->SetBranchAddress("HLT_DoubleJet20_ForwardBackward_v3", &HLT_DoubleJet20_ForwardBackward_v3, &b_HLT_DoubleJet20_ForwardBackward_v3);
   fChain->SetBranchAddress("HLT_DiJet80_DiJet60_DiJet20_v3", &HLT_DiJet80_DiJet60_DiJet20_v3, &b_HLT_DiJet80_DiJet60_DiJet20_v3);
   fChain->SetBranchAddress("HLT_DiPFJet40_PFMETnoMu65_MJJ800VBF_AllJets_v6", &HLT_DiPFJet40_PFMETnoMu65_MJJ800VBF_AllJets_v6, &b_HLT_DiPFJet40_PFMETnoMu65_MJJ800VBF_AllJets_v6);
   fChain->SetBranchAddress("HLT_DiPFJet40_PFMETnoMu65_MJJ600VBF_LeadingJets_v6", &HLT_DiPFJet40_PFMETnoMu65_MJJ600VBF_LeadingJets_v6, &b_HLT_DiPFJet40_PFMETnoMu65_MJJ600VBF_LeadingJets_v6);
   fChain->SetBranchAddress("HLT_DiJet40Eta2p6_BTagIP3DFastPV_v5", &HLT_DiJet40Eta2p6_BTagIP3DFastPV_v5, &b_HLT_DiJet40Eta2p6_BTagIP3DFastPV_v5);
   fChain->SetBranchAddress("HLT_DiJet80Eta2p6_BTagIP3DFastPVLoose_v5", &HLT_DiJet80Eta2p6_BTagIP3DFastPVLoose_v5, &b_HLT_DiJet80Eta2p6_BTagIP3DFastPVLoose_v5);
   fChain->SetBranchAddress("HLT_Jet60Eta1p7_Jet53Eta1p7_DiBTagIP3DFastPV_v5", &HLT_Jet60Eta1p7_Jet53Eta1p7_DiBTagIP3DFastPV_v5, &b_HLT_Jet60Eta1p7_Jet53Eta1p7_DiBTagIP3DFastPV_v5);
   fChain->SetBranchAddress("HLT_Jet80Eta1p7_Jet70Eta1p7_DiBTagIP3DFastPV_v5", &HLT_Jet80Eta1p7_Jet70Eta1p7_DiBTagIP3DFastPV_v5, &b_HLT_Jet80Eta1p7_Jet70Eta1p7_DiBTagIP3DFastPV_v5);
   fChain->SetBranchAddress("HLT_Jet160Eta2p4_Jet120Eta2p4_DiBTagIP3DFastPVLoose_v5", &HLT_Jet160Eta2p4_Jet120Eta2p4_DiBTagIP3DFastPVLoose_v5, &b_HLT_Jet160Eta2p4_Jet120Eta2p4_DiBTagIP3DFastPVLoose_v5);
   fChain->SetBranchAddress("HLT_QuadJet50_v3", &HLT_QuadJet50_v3, &b_HLT_QuadJet50_v3);
   fChain->SetBranchAddress("HLT_QuadJet50_Jet20_v2", &HLT_QuadJet50_Jet20_v2, &b_HLT_QuadJet50_Jet20_v2);
   fChain->SetBranchAddress("HLT_QuadJet60_DiJet20_v3", &HLT_QuadJet60_DiJet20_v3, &b_HLT_QuadJet60_DiJet20_v3);
   fChain->SetBranchAddress("HLT_QuadJet70_v3", &HLT_QuadJet70_v3, &b_HLT_QuadJet70_v3);
   fChain->SetBranchAddress("HLT_QuadJet80_v3", &HLT_QuadJet80_v3, &b_HLT_QuadJet80_v3);
   fChain->SetBranchAddress("HLT_QuadJet90_v3", &HLT_QuadJet90_v3, &b_HLT_QuadJet90_v3);
   fChain->SetBranchAddress("HLT_QuadJet75_55_35_20_BTagIP_VBF_v4", &HLT_QuadJet75_55_35_20_BTagIP_VBF_v4, &b_HLT_QuadJet75_55_35_20_BTagIP_VBF_v4);
   fChain->SetBranchAddress("HLT_QuadJet75_55_38_20_BTagIP_VBF_v4", &HLT_QuadJet75_55_38_20_BTagIP_VBF_v4, &b_HLT_QuadJet75_55_38_20_BTagIP_VBF_v4);
   fChain->SetBranchAddress("HLT_QuadPFJet78_61_44_31_BTagCSV_VBF_v2", &HLT_QuadPFJet78_61_44_31_BTagCSV_VBF_v2, &b_HLT_QuadPFJet78_61_44_31_BTagCSV_VBF_v2);
   fChain->SetBranchAddress("HLT_QuadPFJet82_65_48_35_BTagCSV_VBF_v2", &HLT_QuadPFJet82_65_48_35_BTagCSV_VBF_v2, &b_HLT_QuadPFJet82_65_48_35_BTagCSV_VBF_v2);
   fChain->SetBranchAddress("HLT_SixJet35_v3", &HLT_SixJet35_v3, &b_HLT_SixJet35_v3);
   fChain->SetBranchAddress("HLT_SixJet45_v3", &HLT_SixJet45_v3, &b_HLT_SixJet45_v3);
   fChain->SetBranchAddress("HLT_SixJet50_v3", &HLT_SixJet50_v3, &b_HLT_SixJet50_v3);
   fChain->SetBranchAddress("HLT_EightJet30_eta3p0_v2", &HLT_EightJet30_eta3p0_v2, &b_HLT_EightJet30_eta3p0_v2);
   fChain->SetBranchAddress("HLT_EightJet35_eta3p0_v2", &HLT_EightJet35_eta3p0_v2, &b_HLT_EightJet35_eta3p0_v2);
   fChain->SetBranchAddress("HLT_ExclDiJet35_HFOR_v3", &HLT_ExclDiJet35_HFOR_v3, &b_HLT_ExclDiJet35_HFOR_v3);
   fChain->SetBranchAddress("HLT_ExclDiJet35_HFAND_v3", &HLT_ExclDiJet35_HFAND_v3, &b_HLT_ExclDiJet35_HFAND_v3);
   fChain->SetBranchAddress("HLT_ExclDiJet80_HFAND_v3", &HLT_ExclDiJet80_HFAND_v3, &b_HLT_ExclDiJet80_HFAND_v3);
   fChain->SetBranchAddress("HLT_JetE30_NoBPTX_v13", &HLT_JetE30_NoBPTX_v13, &b_HLT_JetE30_NoBPTX_v13);
   fChain->SetBranchAddress("HLT_JetE30_NoBPTX3BX_NoHalo_v14", &HLT_JetE30_NoBPTX3BX_NoHalo_v14, &b_HLT_JetE30_NoBPTX3BX_NoHalo_v14);
   fChain->SetBranchAddress("HLT_JetE50_NoBPTX3BX_NoHalo_v11", &HLT_JetE50_NoBPTX3BX_NoHalo_v11, &b_HLT_JetE50_NoBPTX3BX_NoHalo_v11);
   fChain->SetBranchAddress("HLT_JetE70_NoBPTX3BX_NoHalo_v3", &HLT_JetE70_NoBPTX3BX_NoHalo_v3, &b_HLT_JetE70_NoBPTX3BX_NoHalo_v3);
   fChain->SetBranchAddress("HLT_HT200_AlphaT0p57_v6", &HLT_HT200_AlphaT0p57_v6, &b_HLT_HT200_AlphaT0p57_v6);
   fChain->SetBranchAddress("HLT_HT200_v4", &HLT_HT200_v4, &b_HLT_HT200_v4);
   fChain->SetBranchAddress("HLT_HT250_AlphaT0p55_v5", &HLT_HT250_AlphaT0p55_v5, &b_HLT_HT250_AlphaT0p55_v5);
   fChain->SetBranchAddress("HLT_HT250_AlphaT0p57_v5", &HLT_HT250_AlphaT0p57_v5, &b_HLT_HT250_AlphaT0p57_v5);
   fChain->SetBranchAddress("HLT_HT250_v4", &HLT_HT250_v4, &b_HLT_HT250_v4);
   fChain->SetBranchAddress("HLT_HT300_AlphaT0p53_v5", &HLT_HT300_AlphaT0p53_v5, &b_HLT_HT300_AlphaT0p53_v5);
   fChain->SetBranchAddress("HLT_HT300_AlphaT0p54_v11", &HLT_HT300_AlphaT0p54_v11, &b_HLT_HT300_AlphaT0p54_v11);
   fChain->SetBranchAddress("HLT_HT300_v4", &HLT_HT300_v4, &b_HLT_HT300_v4);
   fChain->SetBranchAddress("HLT_HT300_DoubleDisplacedPFJet60_v6", &HLT_HT300_DoubleDisplacedPFJet60_v6, &b_HLT_HT300_DoubleDisplacedPFJet60_v6);
   fChain->SetBranchAddress("HLT_HT300_DoubleDisplacedPFJet60_ChgFraction10_v6", &HLT_HT300_DoubleDisplacedPFJet60_ChgFraction10_v6, &b_HLT_HT300_DoubleDisplacedPFJet60_ChgFraction10_v6);
   fChain->SetBranchAddress("HLT_HT300_SingleDisplacedPFJet60_v6", &HLT_HT300_SingleDisplacedPFJet60_v6, &b_HLT_HT300_SingleDisplacedPFJet60_v6);
   fChain->SetBranchAddress("HLT_HT300_SingleDisplacedPFJet60_ChgFraction10_v6", &HLT_HT300_SingleDisplacedPFJet60_ChgFraction10_v6, &b_HLT_HT300_SingleDisplacedPFJet60_ChgFraction10_v6);
   fChain->SetBranchAddress("HLT_HT350_v4", &HLT_HT350_v4, &b_HLT_HT350_v4);
   fChain->SetBranchAddress("HLT_HT350_AlphaT0p52_v5", &HLT_HT350_AlphaT0p52_v5, &b_HLT_HT350_AlphaT0p52_v5);
   fChain->SetBranchAddress("HLT_HT350_AlphaT0p53_v16", &HLT_HT350_AlphaT0p53_v16, &b_HLT_HT350_AlphaT0p53_v16);
   fChain->SetBranchAddress("HLT_HT400_v4", &HLT_HT400_v4, &b_HLT_HT400_v4);
   fChain->SetBranchAddress("HLT_HT400_AlphaT0p51_v16", &HLT_HT400_AlphaT0p51_v16, &b_HLT_HT400_AlphaT0p51_v16);
   fChain->SetBranchAddress("HLT_HT400_AlphaT0p52_v11", &HLT_HT400_AlphaT0p52_v11, &b_HLT_HT400_AlphaT0p52_v11);
   fChain->SetBranchAddress("HLT_HT450_AlphaT0p51_v11", &HLT_HT450_AlphaT0p51_v11, &b_HLT_HT450_AlphaT0p51_v11);
   fChain->SetBranchAddress("HLT_HT450_v4", &HLT_HT450_v4, &b_HLT_HT450_v4);
   fChain->SetBranchAddress("HLT_HT500_v4", &HLT_HT500_v4, &b_HLT_HT500_v4);
   fChain->SetBranchAddress("HLT_HT550_v4", &HLT_HT550_v4, &b_HLT_HT550_v4);
   fChain->SetBranchAddress("HLT_HT650_v4", &HLT_HT650_v4, &b_HLT_HT650_v4);
   fChain->SetBranchAddress("HLT_HT650_Track50_dEdx3p6_v7", &HLT_HT650_Track50_dEdx3p6_v7, &b_HLT_HT650_Track50_dEdx3p6_v7);
   fChain->SetBranchAddress("HLT_HT650_Track60_dEdx3p7_v7", &HLT_HT650_Track60_dEdx3p7_v7, &b_HLT_HT650_Track60_dEdx3p7_v7);
   fChain->SetBranchAddress("HLT_HT750_v4", &HLT_HT750_v4, &b_HLT_HT750_v4);
   fChain->SetBranchAddress("HLT_PFNoPUHT350_v1", &HLT_PFNoPUHT350_v1, &b_HLT_PFNoPUHT350_v1);
   fChain->SetBranchAddress("HLT_PFNoPUHT650_v1", &HLT_PFNoPUHT650_v1, &b_HLT_PFNoPUHT650_v1);
   fChain->SetBranchAddress("HLT_PFNoPUHT650_DiCentralPFNoPUJet80_CenPFNoPUJet40_v1", &HLT_PFNoPUHT650_DiCentralPFNoPUJet80_CenPFNoPUJet40_v1, &b_HLT_PFNoPUHT650_DiCentralPFNoPUJet80_CenPFNoPUJet40_v1);
   fChain->SetBranchAddress("HLT_PFNoPUHT700_v1", &HLT_PFNoPUHT700_v1, &b_HLT_PFNoPUHT700_v1);
   fChain->SetBranchAddress("HLT_PFNoPUHT750_v1", &HLT_PFNoPUHT750_v1, &b_HLT_PFNoPUHT750_v1);
   fChain->SetBranchAddress("HLT_PFMET150_v5", &HLT_PFMET150_v5, &b_HLT_PFMET150_v5);
   fChain->SetBranchAddress("HLT_PFMET180_v5", &HLT_PFMET180_v5, &b_HLT_PFMET180_v5);
   fChain->SetBranchAddress("HLT_DiCentralJetSumpT100_dPhi05_DiCentralPFJet60_25_PFMET100_HBHENoiseCleaned_v2", &HLT_DiCentralJetSumpT100_dPhi05_DiCentralPFJet60_25_PFMET100_HBHENoiseCleaned_v2, &b_HLT_DiCentralJetSumpT100_dPhi05_DiCentralPFJet60_25_PFMET100_HBHENoiseCleaned_v2);
   fChain->SetBranchAddress("HLT_DiCentralPFJet30_PFMET80_v3", &HLT_DiCentralPFJet30_PFMET80_v3, &b_HLT_DiCentralPFJet30_PFMET80_v3);
   fChain->SetBranchAddress("HLT_DiCentralPFNoPUJet50_PFMETORPFMETNoMu80_v1", &HLT_DiCentralPFNoPUJet50_PFMETORPFMETNoMu80_v1, &b_HLT_DiCentralPFNoPUJet50_PFMETORPFMETNoMu80_v1);
   fChain->SetBranchAddress("HLT_DiCentralPFJet30_PFMET80_BTagCSV07_v2", &HLT_DiCentralPFJet30_PFMET80_BTagCSV07_v2, &b_HLT_DiCentralPFJet30_PFMET80_BTagCSV07_v2);
   fChain->SetBranchAddress("HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05d03_v2", &HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05d03_v2, &b_HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05d03_v2);
   fChain->SetBranchAddress("HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05d05_v2", &HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05d05_v2, &b_HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05d05_v2);
   fChain->SetBranchAddress("HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05_v2", &HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05_v2, &b_HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05_v2);
   fChain->SetBranchAddress("HLT_MET80_v4", &HLT_MET80_v4, &b_HLT_MET80_v4);
   fChain->SetBranchAddress("HLT_MET80_Track50_dEdx3p6_v5", &HLT_MET80_Track50_dEdx3p6_v5, &b_HLT_MET80_Track50_dEdx3p6_v5);
   fChain->SetBranchAddress("HLT_MET80_Track60_dEdx3p7_v5", &HLT_MET80_Track60_dEdx3p7_v5, &b_HLT_MET80_Track60_dEdx3p7_v5);
   fChain->SetBranchAddress("HLT_MET120_v11", &HLT_MET120_v11, &b_HLT_MET120_v11);
   fChain->SetBranchAddress("HLT_MET120_HBHENoiseCleaned_v4", &HLT_MET120_HBHENoiseCleaned_v4, &b_HLT_MET120_HBHENoiseCleaned_v4);
   fChain->SetBranchAddress("HLT_MET200_v11", &HLT_MET200_v11, &b_HLT_MET200_v11);
   fChain->SetBranchAddress("HLT_MET200_HBHENoiseCleaned_v4", &HLT_MET200_HBHENoiseCleaned_v4, &b_HLT_MET200_HBHENoiseCleaned_v4);
   fChain->SetBranchAddress("HLT_MET300_v3", &HLT_MET300_v3, &b_HLT_MET300_v3);
   fChain->SetBranchAddress("HLT_MET300_HBHENoiseCleaned_v4", &HLT_MET300_HBHENoiseCleaned_v4, &b_HLT_MET300_HBHENoiseCleaned_v4);
   fChain->SetBranchAddress("HLT_MET400_v6", &HLT_MET400_v6, &b_HLT_MET400_v6);
   fChain->SetBranchAddress("HLT_MET400_HBHENoiseCleaned_v4", &HLT_MET400_HBHENoiseCleaned_v4, &b_HLT_MET400_HBHENoiseCleaned_v4);
   fChain->SetBranchAddress("HLT_L1SingleMuOpen_v7", &HLT_L1SingleMuOpen_v7, &b_HLT_L1SingleMuOpen_v7);
   fChain->SetBranchAddress("HLT_L1SingleMu12_v2", &HLT_L1SingleMu12_v2, &b_HLT_L1SingleMu12_v2);
   fChain->SetBranchAddress("HLT_L2Mu70_eta2p1_PFMET55_v2", &HLT_L2Mu70_eta2p1_PFMET55_v2, &b_HLT_L2Mu70_eta2p1_PFMET55_v2);
   fChain->SetBranchAddress("HLT_L2Mu70_eta2p1_PFMET60_v2", &HLT_L2Mu70_eta2p1_PFMET60_v2, &b_HLT_L2Mu70_eta2p1_PFMET60_v2);
   fChain->SetBranchAddress("HLT_L2Mu20_eta2p1_NoVertex_v2", &HLT_L2Mu20_eta2p1_NoVertex_v2, &b_HLT_L2Mu20_eta2p1_NoVertex_v2);
   fChain->SetBranchAddress("HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo_v3", &HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo_v3, &b_HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo_v3);
   fChain->SetBranchAddress("HLT_L2Mu20_NoVertex_2Cha_NoBPTX3BX_NoHalo_v1", &HLT_L2Mu20_NoVertex_2Cha_NoBPTX3BX_NoHalo_v1, &b_HLT_L2Mu20_NoVertex_2Cha_NoBPTX3BX_NoHalo_v1);
   fChain->SetBranchAddress("HLT_L2Mu30_NoVertex_2Cha_NoBPTX3BX_NoHalo_v1", &HLT_L2Mu30_NoVertex_2Cha_NoBPTX3BX_NoHalo_v1, &b_HLT_L2Mu30_NoVertex_2Cha_NoBPTX3BX_NoHalo_v1);
   fChain->SetBranchAddress("HLT_L2TripleMu10_0_0_NoVertex_PFJet40Neutral_v5", &HLT_L2TripleMu10_0_0_NoVertex_PFJet40Neutral_v5, &b_HLT_L2TripleMu10_0_0_NoVertex_PFJet40Neutral_v5);
   fChain->SetBranchAddress("HLT_DoubleDisplacedMu4_DiPFJet40Neutral_v5", &HLT_DoubleDisplacedMu4_DiPFJet40Neutral_v5, &b_HLT_DoubleDisplacedMu4_DiPFJet40Neutral_v5);
   fChain->SetBranchAddress("HLT_Mu5_v19", &HLT_Mu5_v19, &b_HLT_Mu5_v19);
   fChain->SetBranchAddress("HLT_Mu8_v17", &HLT_Mu8_v17, &b_HLT_Mu8_v17);
   fChain->SetBranchAddress("HLT_Mu12_v17", &HLT_Mu12_v17, &b_HLT_Mu12_v17);
   fChain->SetBranchAddress("HLT_Mu17_v4", &HLT_Mu17_v4, &b_HLT_Mu17_v4);
   fChain->SetBranchAddress("HLT_Mu12_eta2p1_L1Mu10erJetC12WdEtaPhi1DiJetsC_v4", &HLT_Mu12_eta2p1_L1Mu10erJetC12WdEtaPhi1DiJetsC_v4, &b_HLT_Mu12_eta2p1_L1Mu10erJetC12WdEtaPhi1DiJetsC_v4);
   fChain->SetBranchAddress("HLT_Mu15_eta2p1_v4", &HLT_Mu15_eta2p1_v4, &b_HLT_Mu15_eta2p1_v4);
   fChain->SetBranchAddress("HLT_Mu24_v15", &HLT_Mu24_v15, &b_HLT_Mu24_v15);
   fChain->SetBranchAddress("HLT_Mu24_eta2p1_v4", &HLT_Mu24_eta2p1_v4, &b_HLT_Mu24_eta2p1_v4);
   fChain->SetBranchAddress("HLT_Mu30_v15", &HLT_Mu30_v15, &b_HLT_Mu30_v15);
   fChain->SetBranchAddress("HLT_Mu30_eta2p1_v4", &HLT_Mu30_eta2p1_v4, &b_HLT_Mu30_eta2p1_v4);
   fChain->SetBranchAddress("HLT_Mu40_v13", &HLT_Mu40_v13, &b_HLT_Mu40_v13);
   fChain->SetBranchAddress("HLT_Mu40_eta2p1_v10", &HLT_Mu40_eta2p1_v10, &b_HLT_Mu40_eta2p1_v10);
   fChain->SetBranchAddress("HLT_Mu50_eta2p1_v7", &HLT_Mu50_eta2p1_v7, &b_HLT_Mu50_eta2p1_v7);
   fChain->SetBranchAddress("HLT_RelIso1p0Mu5_v5", &HLT_RelIso1p0Mu5_v5, &b_HLT_RelIso1p0Mu5_v5);
   fChain->SetBranchAddress("HLT_RelIso1p0Mu20_v2", &HLT_RelIso1p0Mu20_v2, &b_HLT_RelIso1p0Mu20_v2);
   fChain->SetBranchAddress("HLT_IsoMu15_eta2p1_L1ETM20_v6", &HLT_IsoMu15_eta2p1_L1ETM20_v6, &b_HLT_IsoMu15_eta2p1_L1ETM20_v6);
   fChain->SetBranchAddress("HLT_IsoMu20_eta2p1_v6", &HLT_IsoMu20_eta2p1_v6, &b_HLT_IsoMu20_eta2p1_v6);
   fChain->SetBranchAddress("HLT_IsoMu24_v16", &HLT_IsoMu24_v16, &b_HLT_IsoMu24_v16);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1_v14", &HLT_IsoMu24_eta2p1_v14, &b_HLT_IsoMu24_eta2p1_v14);
   fChain->SetBranchAddress("HLT_IsoMu30_v10", &HLT_IsoMu30_v10, &b_HLT_IsoMu30_v10);
   fChain->SetBranchAddress("HLT_IsoMu30_eta2p1_v14", &HLT_IsoMu30_eta2p1_v14, &b_HLT_IsoMu30_eta2p1_v14);
   fChain->SetBranchAddress("HLT_IsoMu34_eta2p1_v12", &HLT_IsoMu34_eta2p1_v12, &b_HLT_IsoMu34_eta2p1_v12);
   fChain->SetBranchAddress("HLT_IsoMu40_eta2p1_v9", &HLT_IsoMu40_eta2p1_v9, &b_HLT_IsoMu40_eta2p1_v9);
   fChain->SetBranchAddress("HLT_Mu40_eta2p1_Track50_dEdx3p6_v4", &HLT_Mu40_eta2p1_Track50_dEdx3p6_v4, &b_HLT_Mu40_eta2p1_Track50_dEdx3p6_v4);
   fChain->SetBranchAddress("HLT_Mu40_eta2p1_Track60_dEdx3p7_v4", &HLT_Mu40_eta2p1_Track60_dEdx3p7_v4, &b_HLT_Mu40_eta2p1_Track60_dEdx3p7_v4);
   fChain->SetBranchAddress("HLT_L2DoubleMu23_NoVertex_v11", &HLT_L2DoubleMu23_NoVertex_v11, &b_HLT_L2DoubleMu23_NoVertex_v11);
   fChain->SetBranchAddress("HLT_L2DoubleMu23_NoVertex_2Cha_Angle2p5_v3", &HLT_L2DoubleMu23_NoVertex_2Cha_Angle2p5_v3, &b_HLT_L2DoubleMu23_NoVertex_2Cha_Angle2p5_v3);
   fChain->SetBranchAddress("HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_v3", &HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_v3, &b_HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_v3);
   fChain->SetBranchAddress("HLT_DoubleMu11_Acoplanarity03_v4", &HLT_DoubleMu11_Acoplanarity03_v4, &b_HLT_DoubleMu11_Acoplanarity03_v4);
   fChain->SetBranchAddress("HLT_DoubleMu4_Jpsi_Displaced_v10", &HLT_DoubleMu4_Jpsi_Displaced_v10, &b_HLT_DoubleMu4_Jpsi_Displaced_v10);
   fChain->SetBranchAddress("HLT_DoubleMu4_JpsiTk_Displaced_v4", &HLT_DoubleMu4_JpsiTk_Displaced_v4, &b_HLT_DoubleMu4_JpsiTk_Displaced_v4);
   fChain->SetBranchAddress("HLT_DoubleMu3_4_Dimuon5_Bs_Central_v3", &HLT_DoubleMu3_4_Dimuon5_Bs_Central_v3, &b_HLT_DoubleMu3_4_Dimuon5_Bs_Central_v3);
   fChain->SetBranchAddress("HLT_DoubleMu3p5_4_Dimuon5_Bs_Central_v3", &HLT_DoubleMu3p5_4_Dimuon5_Bs_Central_v3, &b_HLT_DoubleMu3p5_4_Dimuon5_Bs_Central_v3);
   fChain->SetBranchAddress("HLT_DoubleMu4_Dimuon7_Bs_Forward_v3", &HLT_DoubleMu4_Dimuon7_Bs_Forward_v3, &b_HLT_DoubleMu4_Dimuon7_Bs_Forward_v3);
   fChain->SetBranchAddress("HLT_DoubleMu3p5_LowMass_Displaced_v4", &HLT_DoubleMu3p5_LowMass_Displaced_v4, &b_HLT_DoubleMu3p5_LowMass_Displaced_v4);
   fChain->SetBranchAddress("HLT_DoubleMu3p5_LowMassNonResonant_Displaced_v4", &HLT_DoubleMu3p5_LowMassNonResonant_Displaced_v4, &b_HLT_DoubleMu3p5_LowMassNonResonant_Displaced_v4);
   fChain->SetBranchAddress("HLT_Dimuon0_Jpsi_v15", &HLT_Dimuon0_Jpsi_v15, &b_HLT_Dimuon0_Jpsi_v15);
   fChain->SetBranchAddress("HLT_Dimuon0_Jpsi_NoVertexing_v12", &HLT_Dimuon0_Jpsi_NoVertexing_v12, &b_HLT_Dimuon0_Jpsi_NoVertexing_v12);
   fChain->SetBranchAddress("HLT_Dimuon0_Upsilon_v15", &HLT_Dimuon0_Upsilon_v15, &b_HLT_Dimuon0_Upsilon_v15);
   fChain->SetBranchAddress("HLT_Dimuon0_PsiPrime_v4", &HLT_Dimuon0_PsiPrime_v4, &b_HLT_Dimuon0_PsiPrime_v4);
   fChain->SetBranchAddress("HLT_Dimuon5_Upsilon_v4", &HLT_Dimuon5_Upsilon_v4, &b_HLT_Dimuon5_Upsilon_v4);
   fChain->SetBranchAddress("HLT_Dimuon5_PsiPrime_v4", &HLT_Dimuon5_PsiPrime_v4, &b_HLT_Dimuon5_PsiPrime_v4);
   fChain->SetBranchAddress("HLT_Dimuon7_Upsilon_v5", &HLT_Dimuon7_Upsilon_v5, &b_HLT_Dimuon7_Upsilon_v5);
   fChain->SetBranchAddress("HLT_Dimuon7_PsiPrime_v1", &HLT_Dimuon7_PsiPrime_v1, &b_HLT_Dimuon7_PsiPrime_v1);
   fChain->SetBranchAddress("HLT_Dimuon8_Jpsi_v5", &HLT_Dimuon8_Jpsi_v5, &b_HLT_Dimuon8_Jpsi_v5);
   fChain->SetBranchAddress("HLT_Dimuon8_Upsilon_v4", &HLT_Dimuon8_Upsilon_v4, &b_HLT_Dimuon8_Upsilon_v4);
   fChain->SetBranchAddress("HLT_Dimuon10_Jpsi_v4", &HLT_Dimuon10_Jpsi_v4, &b_HLT_Dimuon10_Jpsi_v4);
   fChain->SetBranchAddress("HLT_Dimuon11_Upsilon_v4", &HLT_Dimuon11_Upsilon_v4, &b_HLT_Dimuon11_Upsilon_v4);
   fChain->SetBranchAddress("HLT_Dimuon0_Jpsi_Muon_v16", &HLT_Dimuon0_Jpsi_Muon_v16, &b_HLT_Dimuon0_Jpsi_Muon_v16);
   fChain->SetBranchAddress("HLT_Dimuon0_Upsilon_Muon_v16", &HLT_Dimuon0_Upsilon_Muon_v16, &b_HLT_Dimuon0_Upsilon_Muon_v16);
   fChain->SetBranchAddress("HLT_Dimuon3p5_SameSign_v4", &HLT_Dimuon3p5_SameSign_v4, &b_HLT_Dimuon3p5_SameSign_v4);
   fChain->SetBranchAddress("HLT_DoubleMu4_Acoplanarity03_v4", &HLT_DoubleMu4_Acoplanarity03_v4, &b_HLT_DoubleMu4_Acoplanarity03_v4);
   fChain->SetBranchAddress("HLT_Tau2Mu_ItTrack_v4", &HLT_Tau2Mu_ItTrack_v4, &b_HLT_Tau2Mu_ItTrack_v4);
   fChain->SetBranchAddress("HLT_Mu13_Mu8_v18", &HLT_Mu13_Mu8_v18, &b_HLT_Mu13_Mu8_v18);
   fChain->SetBranchAddress("HLT_Mu17_Mu8_v18", &HLT_Mu17_Mu8_v18, &b_HLT_Mu17_Mu8_v18);
   fChain->SetBranchAddress("HLT_Mu17_TkMu8_v11", &HLT_Mu17_TkMu8_v11, &b_HLT_Mu17_TkMu8_v11);
   fChain->SetBranchAddress("HLT_Mu22_TkMu8_v7", &HLT_Mu22_TkMu8_v7, &b_HLT_Mu22_TkMu8_v7);
   fChain->SetBranchAddress("HLT_Mu22_TkMu22_v7", &HLT_Mu22_TkMu22_v7, &b_HLT_Mu22_TkMu22_v7);
   fChain->SetBranchAddress("HLT_TripleMu5_v18", &HLT_TripleMu5_v18, &b_HLT_TripleMu5_v18);
   fChain->SetBranchAddress("HLT_DoubleMu5_IsoMu5_v19", &HLT_DoubleMu5_IsoMu5_v19, &b_HLT_DoubleMu5_IsoMu5_v19);
   fChain->SetBranchAddress("HLT_Mu5_L2Mu3_Jpsi_v5", &HLT_Mu5_L2Mu3_Jpsi_v5, &b_HLT_Mu5_L2Mu3_Jpsi_v5);
   fChain->SetBranchAddress("HLT_Mu5_Track2_Jpsi_v19", &HLT_Mu5_Track2_Jpsi_v19, &b_HLT_Mu5_Track2_Jpsi_v19);
   fChain->SetBranchAddress("HLT_Mu5_Track3p5_Jpsi_v5", &HLT_Mu5_Track3p5_Jpsi_v5, &b_HLT_Mu5_Track3p5_Jpsi_v5);
   fChain->SetBranchAddress("HLT_Mu7_Track7_Jpsi_v19", &HLT_Mu7_Track7_Jpsi_v19, &b_HLT_Mu7_Track7_Jpsi_v19);
   fChain->SetBranchAddress("HLT_Photon20_CaloIdVL_v4", &HLT_Photon20_CaloIdVL_v4, &b_HLT_Photon20_CaloIdVL_v4);
   fChain->SetBranchAddress("HLT_Photon20_CaloIdVL_IsoL_v16", &HLT_Photon20_CaloIdVL_IsoL_v16, &b_HLT_Photon20_CaloIdVL_IsoL_v16);
   fChain->SetBranchAddress("HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_v5", &HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_v5, &b_HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_v5);
   fChain->SetBranchAddress("HLT_Photon26_Photon18_v12", &HLT_Photon26_Photon18_v12, &b_HLT_Photon26_Photon18_v12);
   fChain->SetBranchAddress("HLT_Photon26_R9Id85_Photon18_R9Id85_Mass60_v4", &HLT_Photon26_R9Id85_Photon18_R9Id85_Mass60_v4, &b_HLT_Photon26_R9Id85_Photon18_R9Id85_Mass60_v4);
   fChain->SetBranchAddress("HLT_Photon26_R9Id85_Photon18_CaloId10_Iso50_Mass60_v6", &HLT_Photon26_R9Id85_Photon18_CaloId10_Iso50_Mass60_v6, &b_HLT_Photon26_R9Id85_Photon18_CaloId10_Iso50_Mass60_v6);
   fChain->SetBranchAddress("HLT_Photon26_CaloId10_Iso50_Photon18_R9Id85_Mass60_v6", &HLT_Photon26_CaloId10_Iso50_Photon18_R9Id85_Mass60_v6, &b_HLT_Photon26_CaloId10_Iso50_Photon18_R9Id85_Mass60_v6);
   fChain->SetBranchAddress("HLT_Photon26_CaloId10_Iso50_Photon18_CaloId10_Iso50_Mass60_v6", &HLT_Photon26_CaloId10_Iso50_Photon18_CaloId10_Iso50_Mass60_v6, &b_HLT_Photon26_CaloId10_Iso50_Photon18_CaloId10_Iso50_Mass60_v6);
   fChain->SetBranchAddress("HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass60_v6", &HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass60_v6, &b_HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass60_v6);
   fChain->SetBranchAddress("HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass70_v2", &HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass70_v2, &b_HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass70_v2);
   fChain->SetBranchAddress("HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_v5", &HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_v5, &b_HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_v5);
   fChain->SetBranchAddress("HLT_Photon30_CaloIdVL_v14", &HLT_Photon30_CaloIdVL_v14, &b_HLT_Photon30_CaloIdVL_v14);
   fChain->SetBranchAddress("HLT_Photon30_CaloIdVL_IsoL_v19", &HLT_Photon30_CaloIdVL_IsoL_v19, &b_HLT_Photon30_CaloIdVL_IsoL_v19);
   fChain->SetBranchAddress("HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_v5", &HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_v5, &b_HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_v5);
   fChain->SetBranchAddress("HLT_Photon36_Photon22_v6", &HLT_Photon36_Photon22_v6, &b_HLT_Photon36_Photon22_v6);
   fChain->SetBranchAddress("HLT_Photon36_R9Id85_Photon22_R9Id85_v4", &HLT_Photon36_R9Id85_Photon22_R9Id85_v4, &b_HLT_Photon36_R9Id85_Photon22_R9Id85_v4);
   fChain->SetBranchAddress("HLT_Photon36_R9Id85_Photon22_CaloId10_Iso50_v6", &HLT_Photon36_R9Id85_Photon22_CaloId10_Iso50_v6, &b_HLT_Photon36_R9Id85_Photon22_CaloId10_Iso50_v6);
   fChain->SetBranchAddress("HLT_Photon36_CaloId10_Iso50_Photon22_R9Id85_v6", &HLT_Photon36_CaloId10_Iso50_Photon22_R9Id85_v6, &b_HLT_Photon36_CaloId10_Iso50_Photon22_R9Id85_v6);
   fChain->SetBranchAddress("HLT_Photon36_CaloId10_Iso50_Photon22_CaloId10_Iso50_v6", &HLT_Photon36_CaloId10_Iso50_Photon22_CaloId10_Iso50_v6, &b_HLT_Photon36_CaloId10_Iso50_Photon22_CaloId10_Iso50_v6);
   fChain->SetBranchAddress("HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_R9Id85_OR_CaloId10_Iso50_v6", &HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_R9Id85_OR_CaloId10_Iso50_v6, &b_HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_R9Id85_OR_CaloId10_Iso50_v6);
   fChain->SetBranchAddress("HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_v5", &HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_v5, &b_HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_v5);
   fChain->SetBranchAddress("HLT_Photon50_CaloIdVL_v10", &HLT_Photon50_CaloIdVL_v10, &b_HLT_Photon50_CaloIdVL_v10);
   fChain->SetBranchAddress("HLT_Photon50_CaloIdVL_IsoL_v17", &HLT_Photon50_CaloIdVL_IsoL_v17, &b_HLT_Photon50_CaloIdVL_IsoL_v17);
   fChain->SetBranchAddress("HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_v5", &HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_v5, &b_HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_v5);
   fChain->SetBranchAddress("HLT_Photon60_CaloIdL_MHT70_v9", &HLT_Photon60_CaloIdL_MHT70_v9, &b_HLT_Photon60_CaloIdL_MHT70_v9);
   fChain->SetBranchAddress("HLT_Photon60_CaloIdL_HT300_v2", &HLT_Photon60_CaloIdL_HT300_v2, &b_HLT_Photon60_CaloIdL_HT300_v2);
   fChain->SetBranchAddress("HLT_Photon70_CaloIdXL_PFNoPUHT400_v1", &HLT_Photon70_CaloIdXL_PFNoPUHT400_v1, &b_HLT_Photon70_CaloIdXL_PFNoPUHT400_v1);
   fChain->SetBranchAddress("HLT_Photon70_CaloIdXL_PFNoPUHT500_v1", &HLT_Photon70_CaloIdXL_PFNoPUHT500_v1, &b_HLT_Photon70_CaloIdXL_PFNoPUHT500_v1);
   fChain->SetBranchAddress("HLT_Photon70_CaloIdXL_PFMET100_v5", &HLT_Photon70_CaloIdXL_PFMET100_v5, &b_HLT_Photon70_CaloIdXL_PFMET100_v5);
   fChain->SetBranchAddress("HLT_Photon75_CaloIdVL_v13", &HLT_Photon75_CaloIdVL_v13, &b_HLT_Photon75_CaloIdVL_v13);
   fChain->SetBranchAddress("HLT_Photon75_CaloIdVL_IsoL_v18", &HLT_Photon75_CaloIdVL_IsoL_v18, &b_HLT_Photon75_CaloIdVL_IsoL_v18);
   fChain->SetBranchAddress("HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_v5", &HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_v5, &b_HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_v5);
   fChain->SetBranchAddress("HLT_Photon90_CaloIdVL_v10", &HLT_Photon90_CaloIdVL_v10, &b_HLT_Photon90_CaloIdVL_v10);
   fChain->SetBranchAddress("HLT_Photon90_CaloIdVL_IsoL_v15", &HLT_Photon90_CaloIdVL_IsoL_v15, &b_HLT_Photon90_CaloIdVL_IsoL_v15);
   fChain->SetBranchAddress("HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_v5", &HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_v5, &b_HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_v5);
   fChain->SetBranchAddress("HLT_DisplacedPhoton65_CaloIdVL_IsoL_PFMET25_v2", &HLT_DisplacedPhoton65_CaloIdVL_IsoL_PFMET25_v2, &b_HLT_DisplacedPhoton65_CaloIdVL_IsoL_PFMET25_v2);
   fChain->SetBranchAddress("HLT_DisplacedPhoton65EBOnly_CaloIdVL_IsoL_PFMET30_v2", &HLT_DisplacedPhoton65EBOnly_CaloIdVL_IsoL_PFMET30_v2, &b_HLT_DisplacedPhoton65EBOnly_CaloIdVL_IsoL_PFMET30_v2);
   fChain->SetBranchAddress("HLT_Photon135_v7", &HLT_Photon135_v7, &b_HLT_Photon135_v7);
   fChain->SetBranchAddress("HLT_Photon150_v4", &HLT_Photon150_v4, &b_HLT_Photon150_v4);
   fChain->SetBranchAddress("HLT_Photon160_v4", &HLT_Photon160_v4, &b_HLT_Photon160_v4);
   fChain->SetBranchAddress("HLT_Photon300_NoHE_v5", &HLT_Photon300_NoHE_v5, &b_HLT_Photon300_NoHE_v5);
   fChain->SetBranchAddress("HLT_DoublePhoton48_HEVT_v8", &HLT_DoublePhoton48_HEVT_v8, &b_HLT_DoublePhoton48_HEVT_v8);
   fChain->SetBranchAddress("HLT_DoublePhoton53_HEVT_v2", &HLT_DoublePhoton53_HEVT_v2, &b_HLT_DoublePhoton53_HEVT_v2);
   fChain->SetBranchAddress("HLT_DoublePhoton70_v6", &HLT_DoublePhoton70_v6, &b_HLT_DoublePhoton70_v6);
   fChain->SetBranchAddress("HLT_DoublePhoton80_v7", &HLT_DoublePhoton80_v7, &b_HLT_DoublePhoton80_v7);
   fChain->SetBranchAddress("HLT_DoublePhoton5_IsoVL_CEP_v16", &HLT_DoublePhoton5_IsoVL_CEP_v16, &b_HLT_DoublePhoton5_IsoVL_CEP_v16);
   fChain->SetBranchAddress("HLT_L1SingleEG5_v6", &HLT_L1SingleEG5_v6, &b_HLT_L1SingleEG5_v6);
   fChain->SetBranchAddress("HLT_L1SingleEG12_v6", &HLT_L1SingleEG12_v6, &b_HLT_L1SingleEG12_v6);
   fChain->SetBranchAddress("HLT_L1DoubleEG3_FwdVeto_v2", &HLT_L1DoubleEG3_FwdVeto_v2, &b_HLT_L1DoubleEG3_FwdVeto_v2);
   fChain->SetBranchAddress("HLT_L1ETM30_v2", &HLT_L1ETM30_v2, &b_HLT_L1ETM30_v2);
   fChain->SetBranchAddress("HLT_L1ETM40_v2", &HLT_L1ETM40_v2, &b_HLT_L1ETM40_v2);
   fChain->SetBranchAddress("HLT_L1ETM70_v2", &HLT_L1ETM70_v2, &b_HLT_L1ETM70_v2);
   fChain->SetBranchAddress("HLT_L1ETM100_v2", &HLT_L1ETM100_v2, &b_HLT_L1ETM100_v2);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdT_TrkIdVL_v5", &HLT_Ele8_CaloIdT_TrkIdVL_v5, &b_HLT_Ele8_CaloIdT_TrkIdVL_v5);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdT_TrkIdVL_EG7_v2", &HLT_Ele8_CaloIdT_TrkIdVL_EG7_v2, &b_HLT_Ele8_CaloIdT_TrkIdVL_EG7_v2);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdT_TrkIdVL_Jet30_v5", &HLT_Ele8_CaloIdT_TrkIdVL_Jet30_v5, &b_HLT_Ele8_CaloIdT_TrkIdVL_Jet30_v5);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdL_CaloIsoVL_v17", &HLT_Ele8_CaloIdL_CaloIsoVL_v17, &b_HLT_Ele8_CaloIdL_CaloIsoVL_v17);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v15", &HLT_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v15, &b_HLT_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v15);
   fChain->SetBranchAddress("HLT_Ele17_CaloIdL_CaloIsoVL_v17", &HLT_Ele17_CaloIdL_CaloIsoVL_v17, &b_HLT_Ele17_CaloIdL_CaloIsoVL_v17);
   fChain->SetBranchAddress("HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v6", &HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v6, &b_HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v6);
   fChain->SetBranchAddress("HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v18", &HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v18, &b_HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v18);
   fChain->SetBranchAddress("HLT_Ele17_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_Ele8_Mass50_v6", &HLT_Ele17_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_Ele8_Mass50_v6, &b_HLT_Ele17_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_Ele8_Mass50_v6);
   fChain->SetBranchAddress("HLT_Ele20_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_SC4_Mass50_v6", &HLT_Ele20_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_SC4_Mass50_v6, &b_HLT_Ele20_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_SC4_Mass50_v6);
   fChain->SetBranchAddress("HLT_Ele22_CaloIdL_CaloIsoVL_v6", &HLT_Ele22_CaloIdL_CaloIsoVL_v6, &b_HLT_Ele22_CaloIdL_CaloIsoVL_v6);
   fChain->SetBranchAddress("HLT_Ele27_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_v11", &HLT_Ele27_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_v11, &b_HLT_Ele27_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_v11);
   fChain->SetBranchAddress("HLT_Ele27_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele15_CaloIdT_CaloIsoVL_trackless_v7", &HLT_Ele27_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele15_CaloIdT_CaloIsoVL_trackless_v7, &b_HLT_Ele27_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele15_CaloIdT_CaloIsoVL_trackless_v7);
   fChain->SetBranchAddress("HLT_Ele27_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_HFT15_v7", &HLT_Ele27_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_HFT15_v7, &b_HLT_Ele27_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_HFT15_v7);
   fChain->SetBranchAddress("HLT_Ele23_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_HFT30_v7", &HLT_Ele23_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_HFT30_v7, &b_HLT_Ele23_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_HFT30_v7);
   fChain->SetBranchAddress("HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet30_v2", &HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet30_v2, &b_HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet30_v2);
   fChain->SetBranchAddress("HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet50_40_30_v2", &HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet50_40_30_v2, &b_HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet50_40_30_v2);
   fChain->SetBranchAddress("HLT_Ele27_WP80_v11", &HLT_Ele27_WP80_v11, &b_HLT_Ele27_WP80_v11);
   fChain->SetBranchAddress("HLT_Ele27_WP80_PFMET_MT50_v5", &HLT_Ele27_WP80_PFMET_MT50_v5, &b_HLT_Ele27_WP80_PFMET_MT50_v5);
   fChain->SetBranchAddress("HLT_Ele30_CaloIdVT_TrkIdT_v6", &HLT_Ele30_CaloIdVT_TrkIdT_v6, &b_HLT_Ele30_CaloIdVT_TrkIdT_v6);
   fChain->SetBranchAddress("HLT_Ele32_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_v11", &HLT_Ele32_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_v11, &b_HLT_Ele32_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_v11);
   fChain->SetBranchAddress("HLT_Ele32_CaloIdT_CaloIsoT_TrkIdT_TrkIsoT_SC17_Mass50_v6", &HLT_Ele32_CaloIdT_CaloIsoT_TrkIdT_TrkIsoT_SC17_Mass50_v6, &b_HLT_Ele32_CaloIdT_CaloIsoT_TrkIdT_TrkIsoT_SC17_Mass50_v6);
   fChain->SetBranchAddress("HLT_Ele80_CaloIdVT_GsfTrkIdT_v2", &HLT_Ele80_CaloIdVT_GsfTrkIdT_v2, &b_HLT_Ele80_CaloIdVT_GsfTrkIdT_v2);
   fChain->SetBranchAddress("HLT_Ele90_CaloIdVT_GsfTrkIdT_v2", &HLT_Ele90_CaloIdVT_GsfTrkIdT_v2, &b_HLT_Ele90_CaloIdVT_GsfTrkIdT_v2);
   fChain->SetBranchAddress("HLT_DoubleEle8_CaloIdT_TrkIdVL_v12", &HLT_DoubleEle8_CaloIdT_TrkIdVL_v12, &b_HLT_DoubleEle8_CaloIdT_TrkIdVL_v12);
   fChain->SetBranchAddress("HLT_DoubleEle33_CaloIdL_v14", &HLT_DoubleEle33_CaloIdL_v14, &b_HLT_DoubleEle33_CaloIdL_v14);
   fChain->SetBranchAddress("HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v7", &HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v7, &b_HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v7);
   fChain->SetBranchAddress("HLT_DoubleEle33_CaloIdT_v10", &HLT_DoubleEle33_CaloIdT_v10, &b_HLT_DoubleEle33_CaloIdT_v10);
   fChain->SetBranchAddress("HLT_Ele15_Ele8_Ele5_CaloIdL_TrkIdVL_v6", &HLT_Ele15_Ele8_Ele5_CaloIdL_TrkIdVL_v6, &b_HLT_Ele15_Ele8_Ele5_CaloIdL_TrkIdVL_v6);
   fChain->SetBranchAddress("HLT_LooseIsoPFTau35_Trk20_Prong1_v7", &HLT_LooseIsoPFTau35_Trk20_Prong1_v7, &b_HLT_LooseIsoPFTau35_Trk20_Prong1_v7);
   fChain->SetBranchAddress("HLT_LooseIsoPFTau35_Trk20_Prong1_MET70_v7", &HLT_LooseIsoPFTau35_Trk20_Prong1_MET70_v7, &b_HLT_LooseIsoPFTau35_Trk20_Prong1_MET70_v7);
   fChain->SetBranchAddress("HLT_LooseIsoPFTau35_Trk20_Prong1_MET75_v7", &HLT_LooseIsoPFTau35_Trk20_Prong1_MET75_v7, &b_HLT_LooseIsoPFTau35_Trk20_Prong1_MET75_v7);
   fChain->SetBranchAddress("HLT_IsoMu15_eta2p1_LooseIsoPFTau35_Trk20_Prong1_L1ETM20_v7", &HLT_IsoMu15_eta2p1_LooseIsoPFTau35_Trk20_Prong1_L1ETM20_v7, &b_HLT_IsoMu15_eta2p1_LooseIsoPFTau35_Trk20_Prong1_L1ETM20_v7);
   fChain->SetBranchAddress("HLT_DoubleMediumIsoPFTau30_Trk1_eta2p1_Jet30_v1", &HLT_DoubleMediumIsoPFTau30_Trk1_eta2p1_Jet30_v1, &b_HLT_DoubleMediumIsoPFTau30_Trk1_eta2p1_Jet30_v1);
   fChain->SetBranchAddress("HLT_DoubleMediumIsoPFTau30_Trk1_eta2p1_v1", &HLT_DoubleMediumIsoPFTau30_Trk1_eta2p1_v1, &b_HLT_DoubleMediumIsoPFTau30_Trk1_eta2p1_v1);
   fChain->SetBranchAddress("HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Prong1_v1", &HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Prong1_v1, &b_HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Prong1_v1);
   fChain->SetBranchAddress("HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_v1", &HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_v1, &b_HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_v1);
   fChain->SetBranchAddress("HLT_IsoMu18_eta2p1_MediumIsoPFTau25_Trk1_eta2p1_v1", &HLT_IsoMu18_eta2p1_MediumIsoPFTau25_Trk1_eta2p1_v1, &b_HLT_IsoMu18_eta2p1_MediumIsoPFTau25_Trk1_eta2p1_v1);
   fChain->SetBranchAddress("HLT_BTagMu_DiJet20_Mu5_v4", &HLT_BTagMu_DiJet20_Mu5_v4, &b_HLT_BTagMu_DiJet20_Mu5_v4);
   fChain->SetBranchAddress("HLT_BTagMu_DiJet40_Mu5_v4", &HLT_BTagMu_DiJet40_Mu5_v4, &b_HLT_BTagMu_DiJet40_Mu5_v4);
   fChain->SetBranchAddress("HLT_BTagMu_DiJet70_Mu5_v4", &HLT_BTagMu_DiJet70_Mu5_v4, &b_HLT_BTagMu_DiJet70_Mu5_v4);
   fChain->SetBranchAddress("HLT_BTagMu_DiJet110_Mu5_v4", &HLT_BTagMu_DiJet110_Mu5_v4, &b_HLT_BTagMu_DiJet110_Mu5_v4);
   fChain->SetBranchAddress("HLT_BTagMu_Jet300_Mu5_v4", &HLT_BTagMu_Jet300_Mu5_v4, &b_HLT_BTagMu_Jet300_Mu5_v4);
   fChain->SetBranchAddress("HLT_Mu7_Ele7_CaloIdT_CaloIsoVL_v6", &HLT_Mu7_Ele7_CaloIdT_CaloIsoVL_v6, &b_HLT_Mu7_Ele7_CaloIdT_CaloIsoVL_v6);
   fChain->SetBranchAddress("HLT_Mu8_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v8", &HLT_Mu8_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v8, &b_HLT_Mu8_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v8);
   fChain->SetBranchAddress("HLT_Mu8_DiJet30_v5", &HLT_Mu8_DiJet30_v5, &b_HLT_Mu8_DiJet30_v5);
   fChain->SetBranchAddress("HLT_Mu8_TriJet30_v5", &HLT_Mu8_TriJet30_v5, &b_HLT_Mu8_TriJet30_v5);
   fChain->SetBranchAddress("HLT_Mu8_QuadJet30_v5", &HLT_Mu8_QuadJet30_v5, &b_HLT_Mu8_QuadJet30_v5);
   fChain->SetBranchAddress("HLT_IsoMu12_DoubleCentralJet65_v2", &HLT_IsoMu12_DoubleCentralJet65_v2, &b_HLT_IsoMu12_DoubleCentralJet65_v2);
   fChain->SetBranchAddress("HLT_Mu15_eta2p1_L1ETM20_v4", &HLT_Mu15_eta2p1_L1ETM20_v4, &b_HLT_Mu15_eta2p1_L1ETM20_v4);
   fChain->SetBranchAddress("HLT_Mu24_PFJet30_PFJet25_Deta3_CentralPFJet25_v2", &HLT_Mu24_PFJet30_PFJet25_Deta3_CentralPFJet25_v2, &b_HLT_Mu24_PFJet30_PFJet25_Deta3_CentralPFJet25_v2);
   fChain->SetBranchAddress("HLT_Mu24_CentralPFJet30_CentralPFJet25_v2", &HLT_Mu24_CentralPFJet30_CentralPFJet25_v2, &b_HLT_Mu24_CentralPFJet30_CentralPFJet25_v2);
   fChain->SetBranchAddress("HLT_IsoMu24_PFJet30_PFJet25_Deta3_CentralPFJet25_v2", &HLT_IsoMu24_PFJet30_PFJet25_Deta3_CentralPFJet25_v2, &b_HLT_IsoMu24_PFJet30_PFJet25_Deta3_CentralPFJet25_v2);
   fChain->SetBranchAddress("HLT_IsoMu24_CentralPFJet30_CentralPFJet25_v2", &HLT_IsoMu24_CentralPFJet30_CentralPFJet25_v2, &b_HLT_IsoMu24_CentralPFJet30_CentralPFJet25_v2);
   fChain->SetBranchAddress("HLT_IsoMu24_CentralPFJet30_CentralPFJet25_PFMET20_v2", &HLT_IsoMu24_CentralPFJet30_CentralPFJet25_PFMET20_v2, &b_HLT_IsoMu24_CentralPFJet30_CentralPFJet25_PFMET20_v2);
   fChain->SetBranchAddress("HLT_Ele32_WP80_PFJet30_PFJet25_Deta3_v2", &HLT_Ele32_WP80_PFJet30_PFJet25_Deta3_v2, &b_HLT_Ele32_WP80_PFJet30_PFJet25_Deta3_v2);
   fChain->SetBranchAddress("HLT_Ele32_WP80_PFJet30_PFJet25_Deta3_CentralPFJet30_v2", &HLT_Ele32_WP80_PFJet30_PFJet25_Deta3_CentralPFJet30_v2, &b_HLT_Ele32_WP80_PFJet30_PFJet25_Deta3_CentralPFJet30_v2);
   fChain->SetBranchAddress("HLT_Ele32_WP80_CentralPFJet35_CentralPFJet25_v2", &HLT_Ele32_WP80_CentralPFJet35_CentralPFJet25_v2, &b_HLT_Ele32_WP80_CentralPFJet35_CentralPFJet25_v2);
   fChain->SetBranchAddress("HLT_Ele32_WP80_CentralPFJet35_CentralPFJet25_PFMET20_v2", &HLT_Ele32_WP80_CentralPFJet35_CentralPFJet25_PFMET20_v2, &b_HLT_Ele32_WP80_CentralPFJet35_CentralPFJet25_PFMET20_v2);
   fChain->SetBranchAddress("HLT_IsoMu17_eta2p1_CentralPFNoPUJet30_BTagIPIter_v2", &HLT_IsoMu17_eta2p1_CentralPFNoPUJet30_BTagIPIter_v2, &b_HLT_IsoMu17_eta2p1_CentralPFNoPUJet30_BTagIPIter_v2);
   fChain->SetBranchAddress("HLT_IsoMu17_eta2p1_CentralPFNoPUJet30_v2", &HLT_IsoMu17_eta2p1_CentralPFNoPUJet30_v2, &b_HLT_IsoMu17_eta2p1_CentralPFNoPUJet30_v2);
   fChain->SetBranchAddress("HLT_IsoMu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2", &HLT_IsoMu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2, &b_HLT_IsoMu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2);
   fChain->SetBranchAddress("HLT_Mu17_eta2p1_CentralPFNoPUJet30_BTagIPIter_v2", &HLT_Mu17_eta2p1_CentralPFNoPUJet30_BTagIPIter_v2, &b_HLT_Mu17_eta2p1_CentralPFNoPUJet30_BTagIPIter_v2);
   fChain->SetBranchAddress("HLT_Mu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2", &HLT_Mu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2, &b_HLT_Mu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2);
   fChain->SetBranchAddress("HLT_IsoMu20_WCandPt80_v2", &HLT_IsoMu20_WCandPt80_v2, &b_HLT_IsoMu20_WCandPt80_v2);
   fChain->SetBranchAddress("HLT_Mu17_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v8", &HLT_Mu17_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v8, &b_HLT_Mu17_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v8);
   fChain->SetBranchAddress("HLT_Mu12_eta2p1_DiCentral_40_20_DiBTagIP3D1stTrack_v4", &HLT_Mu12_eta2p1_DiCentral_40_20_DiBTagIP3D1stTrack_v4, &b_HLT_Mu12_eta2p1_DiCentral_40_20_DiBTagIP3D1stTrack_v4);
   fChain->SetBranchAddress("HLT_Mu12_eta2p1_DiCentral_40_20_BTagIP3D1stTrack_v4", &HLT_Mu12_eta2p1_DiCentral_40_20_BTagIP3D1stTrack_v4, &b_HLT_Mu12_eta2p1_DiCentral_40_20_BTagIP3D1stTrack_v4);
   fChain->SetBranchAddress("HLT_Mu12_eta2p1_DiCentral_40_20_v4", &HLT_Mu12_eta2p1_DiCentral_40_20_v4, &b_HLT_Mu12_eta2p1_DiCentral_40_20_v4);
   fChain->SetBranchAddress("HLT_Mu12_eta2p1_DiCentral_20_v4", &HLT_Mu12_eta2p1_DiCentral_20_v4, &b_HLT_Mu12_eta2p1_DiCentral_20_v4);
   fChain->SetBranchAddress("HLT_Mu15_eta2p1_TriCentral_40_20_20_DiBTagIP3D1stTrack_v4", &HLT_Mu15_eta2p1_TriCentral_40_20_20_DiBTagIP3D1stTrack_v4, &b_HLT_Mu15_eta2p1_TriCentral_40_20_20_DiBTagIP3D1stTrack_v4);
   fChain->SetBranchAddress("HLT_Mu15_eta2p1_TriCentral_40_20_20_BTagIP3D1stTrack_v4", &HLT_Mu15_eta2p1_TriCentral_40_20_20_BTagIP3D1stTrack_v4, &b_HLT_Mu15_eta2p1_TriCentral_40_20_20_BTagIP3D1stTrack_v4);
   fChain->SetBranchAddress("HLT_Mu15_eta2p1_TriCentral_40_20_20_v4", &HLT_Mu15_eta2p1_TriCentral_40_20_20_v4, &b_HLT_Mu15_eta2p1_TriCentral_40_20_20_v4);
   fChain->SetBranchAddress("HLT_Mu30_Ele30_CaloIdL_v7", &HLT_Mu30_Ele30_CaloIdL_v7, &b_HLT_Mu30_Ele30_CaloIdL_v7);
   fChain->SetBranchAddress("HLT_IsoMu17_eta2p1_DiCentralPFNoPUJet30_PFNoPUHT350_PFMHT40_v1", &HLT_IsoMu17_eta2p1_DiCentralPFNoPUJet30_PFNoPUHT350_PFMHT40_v1, &b_HLT_IsoMu17_eta2p1_DiCentralPFNoPUJet30_PFNoPUHT350_PFMHT40_v1);
   fChain->SetBranchAddress("HLT_IsoMu20_eta2p1_CentralPFJet80_v7", &HLT_IsoMu20_eta2p1_CentralPFJet80_v7, &b_HLT_IsoMu20_eta2p1_CentralPFJet80_v7);
   fChain->SetBranchAddress("HLT_DoubleRelIso1p0Mu5_Mass8_PFNoPUHT175_v1", &HLT_DoubleRelIso1p0Mu5_Mass8_PFNoPUHT175_v1, &b_HLT_DoubleRelIso1p0Mu5_Mass8_PFNoPUHT175_v1);
   fChain->SetBranchAddress("HLT_DoubleRelIso1p0Mu5_Mass8_PFNoPUHT225_v1", &HLT_DoubleRelIso1p0Mu5_Mass8_PFNoPUHT225_v1, &b_HLT_DoubleRelIso1p0Mu5_Mass8_PFNoPUHT225_v1);
   fChain->SetBranchAddress("HLT_DoubleMu8_Mass8_PFNoPUHT175_v1", &HLT_DoubleMu8_Mass8_PFNoPUHT175_v1, &b_HLT_DoubleMu8_Mass8_PFNoPUHT175_v1);
   fChain->SetBranchAddress("HLT_DoubleMu8_Mass8_PFNoPUHT225_v1", &HLT_DoubleMu8_Mass8_PFNoPUHT225_v1, &b_HLT_DoubleMu8_Mass8_PFNoPUHT225_v1);
   fChain->SetBranchAddress("HLT_RelIso1p0Mu5_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1", &HLT_RelIso1p0Mu5_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1, &b_HLT_RelIso1p0Mu5_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1);
   fChain->SetBranchAddress("HLT_RelIso1p0Mu5_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1", &HLT_RelIso1p0Mu5_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1, &b_HLT_RelIso1p0Mu5_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1);
   fChain->SetBranchAddress("HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1", &HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1, &b_HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1);
   fChain->SetBranchAddress("HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1", &HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1, &b_HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1);
   fChain->SetBranchAddress("HLT_PFNoPUHT350_Mu15_PFMET45_v1", &HLT_PFNoPUHT350_Mu15_PFMET45_v1, &b_HLT_PFNoPUHT350_Mu15_PFMET45_v1);
   fChain->SetBranchAddress("HLT_PFNoPUHT350_Mu15_PFMET50_v1", &HLT_PFNoPUHT350_Mu15_PFMET50_v1, &b_HLT_PFNoPUHT350_Mu15_PFMET50_v1);
   fChain->SetBranchAddress("HLT_PFNoPUHT400_Mu5_PFMET45_v1", &HLT_PFNoPUHT400_Mu5_PFMET45_v1, &b_HLT_PFNoPUHT400_Mu5_PFMET45_v1);
   fChain->SetBranchAddress("HLT_PFNoPUHT400_Mu5_PFMET50_v1", &HLT_PFNoPUHT400_Mu5_PFMET50_v1, &b_HLT_PFNoPUHT400_Mu5_PFMET50_v1);
   fChain->SetBranchAddress("HLT_Mu40_PFNoPUHT350_v1", &HLT_Mu40_PFNoPUHT350_v1, &b_HLT_Mu40_PFNoPUHT350_v1);
   fChain->SetBranchAddress("HLT_Mu60_PFNoPUHT350_v1", &HLT_Mu60_PFNoPUHT350_v1, &b_HLT_Mu60_PFNoPUHT350_v1);
   fChain->SetBranchAddress("HLT_Mu40_HT200_v2", &HLT_Mu40_HT200_v2, &b_HLT_Mu40_HT200_v2);
   fChain->SetBranchAddress("HLT_DoubleMu5_Ele8_CaloIdT_TrkIdVL_v15", &HLT_DoubleMu5_Ele8_CaloIdT_TrkIdVL_v15, &b_HLT_DoubleMu5_Ele8_CaloIdT_TrkIdVL_v15);
   fChain->SetBranchAddress("HLT_DoubleMu8_Ele8_CaloIdT_TrkIdVL_v4", &HLT_DoubleMu8_Ele8_CaloIdT_TrkIdVL_v4, &b_HLT_DoubleMu8_Ele8_CaloIdT_TrkIdVL_v4);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Jet30_v6", &HLT_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Jet30_v6, &b_HLT_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Jet30_v6);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdT_TrkIdT_DiJet30_v16", &HLT_Ele8_CaloIdT_TrkIdT_DiJet30_v16, &b_HLT_Ele8_CaloIdT_TrkIdT_DiJet30_v16);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdT_TrkIdT_TriJet30_v16", &HLT_Ele8_CaloIdT_TrkIdT_TriJet30_v16, &b_HLT_Ele8_CaloIdT_TrkIdT_TriJet30_v16);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdT_TrkIdT_QuadJet30_v16", &HLT_Ele8_CaloIdT_TrkIdT_QuadJet30_v16, &b_HLT_Ele8_CaloIdT_TrkIdT_QuadJet30_v16);
   fChain->SetBranchAddress("HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Jet30_v6", &HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Jet30_v6, &b_HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Jet30_v6);
   fChain->SetBranchAddress("HLT_Ele25_CaloIdVT_TrkIdT_TriCentralPFNoPUJet30_30_20_v2", &HLT_Ele25_CaloIdVT_TrkIdT_TriCentralPFNoPUJet30_30_20_v2, &b_HLT_Ele25_CaloIdVT_TrkIdT_TriCentralPFNoPUJet30_30_20_v2);
   fChain->SetBranchAddress("HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_CentralPFNoPUJet30_v6", &HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_CentralPFNoPUJet30_v6, &b_HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_CentralPFNoPUJet30_v6);
   fChain->SetBranchAddress("HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2", &HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2, &b_HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2);
   fChain->SetBranchAddress("HLT_Ele25_CaloIdVL_CaloIsoT_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2", &HLT_Ele25_CaloIdVL_CaloIsoT_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2, &b_HLT_Ele25_CaloIdVL_CaloIsoT_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2);
   fChain->SetBranchAddress("HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_CentralPFNoPUJet30_BTagIPIter_v7", &HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_CentralPFNoPUJet30_BTagIPIter_v7, &b_HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_CentralPFNoPUJet30_BTagIPIter_v7);
   fChain->SetBranchAddress("HLT_Ele27_WP80_CentralPFJet80_v7", &HLT_Ele27_WP80_CentralPFJet80_v7, &b_HLT_Ele27_WP80_CentralPFJet80_v7);
   fChain->SetBranchAddress("HLT_Ele27_WP80_WCandPt80_v7", &HLT_Ele27_WP80_WCandPt80_v7, &b_HLT_Ele27_WP80_WCandPt80_v7);
   fChain->SetBranchAddress("HLT_Ele30_CaloIdVT_TrkIdT_PFNoPUJet100_PFNoPUJet25_v6", &HLT_Ele30_CaloIdVT_TrkIdT_PFNoPUJet100_PFNoPUJet25_v6, &b_HLT_Ele30_CaloIdVT_TrkIdT_PFNoPUJet100_PFNoPUJet25_v6);
   fChain->SetBranchAddress("HLT_Ele30_CaloIdVT_TrkIdT_PFNoPUJet150_PFNoPUJet25_v6", &HLT_Ele30_CaloIdVT_TrkIdT_PFNoPUJet150_PFNoPUJet25_v6, &b_HLT_Ele30_CaloIdVT_TrkIdT_PFNoPUJet150_PFNoPUJet25_v6);
   fChain->SetBranchAddress("HLT_DoubleEle8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1", &HLT_DoubleEle8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1, &b_HLT_DoubleEle8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1);
   fChain->SetBranchAddress("HLT_DoubleEle8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1", &HLT_DoubleEle8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1, &b_HLT_DoubleEle8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1);
   fChain->SetBranchAddress("HLT_DoubleEle10_CaloIdL_TrkIdVL_Ele10_CaloIdT_TrkIdVL_v12", &HLT_DoubleEle10_CaloIdL_TrkIdVL_Ele10_CaloIdT_TrkIdVL_v12, &b_HLT_DoubleEle10_CaloIdL_TrkIdVL_Ele10_CaloIdT_TrkIdVL_v12);
   fChain->SetBranchAddress("HLT_TripleEle10_CaloIdL_TrkIdVL_v18", &HLT_TripleEle10_CaloIdL_TrkIdVL_v18, &b_HLT_TripleEle10_CaloIdL_TrkIdVL_v18);
   fChain->SetBranchAddress("HLT_RsqMR40_Rsq0p04_v4", &HLT_RsqMR40_Rsq0p04_v4, &b_HLT_RsqMR40_Rsq0p04_v4);
   fChain->SetBranchAddress("HLT_RsqMR45_Rsq0p09_v3", &HLT_RsqMR45_Rsq0p09_v3, &b_HLT_RsqMR45_Rsq0p09_v3);
   fChain->SetBranchAddress("HLT_RsqMR55_Rsq0p09_MR150_v4", &HLT_RsqMR55_Rsq0p09_MR150_v4, &b_HLT_RsqMR55_Rsq0p09_MR150_v4);
   fChain->SetBranchAddress("HLT_RsqMR60_Rsq0p09_MR150_v4", &HLT_RsqMR60_Rsq0p09_MR150_v4, &b_HLT_RsqMR60_Rsq0p09_MR150_v4);
   fChain->SetBranchAddress("HLT_RsqMR65_Rsq0p09_MR150_v3", &HLT_RsqMR65_Rsq0p09_MR150_v3, &b_HLT_RsqMR65_Rsq0p09_MR150_v3);
   fChain->SetBranchAddress("HLT_IsoMu12_RsqMR30_Rsq0p04_MR200_v2", &HLT_IsoMu12_RsqMR30_Rsq0p04_MR200_v2, &b_HLT_IsoMu12_RsqMR30_Rsq0p04_MR200_v2);
   fChain->SetBranchAddress("HLT_IsoMu12_RsqMR40_Rsq0p04_MR200_v2", &HLT_IsoMu12_RsqMR40_Rsq0p04_MR200_v2, &b_HLT_IsoMu12_RsqMR40_Rsq0p04_MR200_v2);
   fChain->SetBranchAddress("HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_RsqMR30_Rsq0p04_MR200_v2", &HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_RsqMR30_Rsq0p04_MR200_v2, &b_HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_RsqMR30_Rsq0p04_MR200_v2);
   fChain->SetBranchAddress("HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_RsqMR40_Rsq0p04_MR200_v2", &HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_RsqMR40_Rsq0p04_MR200_v2, &b_HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_RsqMR40_Rsq0p04_MR200_v2);
   fChain->SetBranchAddress("HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_DoubleCentralJet65_v2", &HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_DoubleCentralJet65_v2, &b_HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_DoubleCentralJet65_v2);
   fChain->SetBranchAddress("HLT_Photon40_CaloIdL_RsqMR35_Rsq0p09_MR150_v4", &HLT_Photon40_CaloIdL_RsqMR35_Rsq0p09_MR150_v4, &b_HLT_Photon40_CaloIdL_RsqMR35_Rsq0p09_MR150_v4);
   fChain->SetBranchAddress("HLT_Photon40_CaloIdL_RsqMR40_Rsq0p09_MR150_v4", &HLT_Photon40_CaloIdL_RsqMR40_Rsq0p09_MR150_v4, &b_HLT_Photon40_CaloIdL_RsqMR40_Rsq0p09_MR150_v4);
   fChain->SetBranchAddress("HLT_Photon40_CaloIdL_RsqMR45_Rsq0p09_MR150_v4", &HLT_Photon40_CaloIdL_RsqMR45_Rsq0p09_MR150_v4, &b_HLT_Photon40_CaloIdL_RsqMR45_Rsq0p09_MR150_v4);
   fChain->SetBranchAddress("HLT_Photon40_CaloIdL_RsqMR50_Rsq0p09_MR150_v4", &HLT_Photon40_CaloIdL_RsqMR50_Rsq0p09_MR150_v4, &b_HLT_Photon40_CaloIdL_RsqMR50_Rsq0p09_MR150_v4);
   fChain->SetBranchAddress("HLT_DoublePhoton40_CaloIdL_Rsq0p035_v4", &HLT_DoublePhoton40_CaloIdL_Rsq0p035_v4, &b_HLT_DoublePhoton40_CaloIdL_Rsq0p035_v4);
   fChain->SetBranchAddress("HLT_DoublePhoton40_CaloIdL_Rsq0p06_v4", &HLT_DoublePhoton40_CaloIdL_Rsq0p06_v4, &b_HLT_DoublePhoton40_CaloIdL_Rsq0p06_v4);
   fChain->SetBranchAddress("HLT_Mu22_Photon22_CaloIdL_v6", &HLT_Mu22_Photon22_CaloIdL_v6, &b_HLT_Mu22_Photon22_CaloIdL_v6);
   fChain->SetBranchAddress("HLT_Mu8_DoubleEle8_CaloIdT_TrkIdVL_v6", &HLT_Mu8_DoubleEle8_CaloIdT_TrkIdVL_v6, &b_HLT_Mu8_DoubleEle8_CaloIdT_TrkIdVL_v6);
   fChain->SetBranchAddress("HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Ele8_CaloIdL_TrkIdVL_v6", &HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Ele8_CaloIdL_TrkIdVL_v6, &b_HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Ele8_CaloIdL_TrkIdVL_v6);
   fChain->SetBranchAddress("HLT_DoubleMu14_Mass8_PFMET40_v6", &HLT_DoubleMu14_Mass8_PFMET40_v6, &b_HLT_DoubleMu14_Mass8_PFMET40_v6);
   fChain->SetBranchAddress("HLT_DoubleMu14_Mass8_PFMET50_v6", &HLT_DoubleMu14_Mass8_PFMET50_v6, &b_HLT_DoubleMu14_Mass8_PFMET50_v6);
   fChain->SetBranchAddress("HLT_DoubleEle14_CaloIdT_TrkIdVL_Mass8_PFMET40_v6", &HLT_DoubleEle14_CaloIdT_TrkIdVL_Mass8_PFMET40_v6, &b_HLT_DoubleEle14_CaloIdT_TrkIdVL_Mass8_PFMET40_v6);
   fChain->SetBranchAddress("HLT_DoubleEle14_CaloIdT_TrkIdVL_Mass8_PFMET50_v6", &HLT_DoubleEle14_CaloIdT_TrkIdVL_Mass8_PFMET50_v6, &b_HLT_DoubleEle14_CaloIdT_TrkIdVL_Mass8_PFMET50_v6);
   fChain->SetBranchAddress("HLT_Mu14_Ele14_CaloIdT_TrkIdVL_Mass8_PFMET40_v6", &HLT_Mu14_Ele14_CaloIdT_TrkIdVL_Mass8_PFMET40_v6, &b_HLT_Mu14_Ele14_CaloIdT_TrkIdVL_Mass8_PFMET40_v6);
   fChain->SetBranchAddress("HLT_Mu14_Ele14_CaloIdT_TrkIdVL_Mass8_PFMET50_v6", &HLT_Mu14_Ele14_CaloIdT_TrkIdVL_Mass8_PFMET50_v6, &b_HLT_Mu14_Ele14_CaloIdT_TrkIdVL_Mass8_PFMET50_v6);
   fChain->SetBranchAddress("HLT_PFNoPUHT350_PFMET100_v1", &HLT_PFNoPUHT350_PFMET100_v1, &b_HLT_PFNoPUHT350_PFMET100_v1);
   fChain->SetBranchAddress("HLT_PFNoPUHT400_PFMET100_v1", &HLT_PFNoPUHT400_PFMET100_v1, &b_HLT_PFNoPUHT400_PFMET100_v1);
   fChain->SetBranchAddress("HLT_CleanPFNoPUHT350_Ele5_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET45_v1", &HLT_CleanPFNoPUHT350_Ele5_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET45_v1, &b_HLT_CleanPFNoPUHT350_Ele5_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET45_v1);
   fChain->SetBranchAddress("HLT_CleanPFNoPUHT350_Ele5_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET50_v1", &HLT_CleanPFNoPUHT350_Ele5_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET50_v1, &b_HLT_CleanPFNoPUHT350_Ele5_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET50_v1);
   fChain->SetBranchAddress("HLT_CleanPFNoPUHT300_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET45_v1", &HLT_CleanPFNoPUHT300_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET45_v1, &b_HLT_CleanPFNoPUHT300_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET45_v1);
   fChain->SetBranchAddress("HLT_CleanPFNoPUHT300_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET50_v1", &HLT_CleanPFNoPUHT300_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET50_v1, &b_HLT_CleanPFNoPUHT300_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET50_v1);
   fChain->SetBranchAddress("HLT_CleanPFNoPUHT300_Ele40_CaloIdVT_TrkIdT_v1", &HLT_CleanPFNoPUHT300_Ele40_CaloIdVT_TrkIdT_v1, &b_HLT_CleanPFNoPUHT300_Ele40_CaloIdVT_TrkIdT_v1);
   fChain->SetBranchAddress("HLT_CleanPFNoPUHT300_Ele60_CaloIdVT_TrkIdT_v1", &HLT_CleanPFNoPUHT300_Ele60_CaloIdVT_TrkIdT_v1, &b_HLT_CleanPFNoPUHT300_Ele60_CaloIdVT_TrkIdT_v1);
   fChain->SetBranchAddress("HLT_Ele5_SC5_Jpsi_Mass2to15_v4", &HLT_Ele5_SC5_Jpsi_Mass2to15_v4, &b_HLT_Ele5_SC5_Jpsi_Mass2to15_v4);
   fChain->SetBranchAddress("HLT_DiJet35_MJJ650_AllJets_DEta3p5_VBF_v2", &HLT_DiJet35_MJJ650_AllJets_DEta3p5_VBF_v2, &b_HLT_DiJet35_MJJ650_AllJets_DEta3p5_VBF_v2);
   fChain->SetBranchAddress("HLT_DiJet35_MJJ700_AllJets_DEta3p5_VBF_v2", &HLT_DiJet35_MJJ700_AllJets_DEta3p5_VBF_v2, &b_HLT_DiJet35_MJJ700_AllJets_DEta3p5_VBF_v2);
   fChain->SetBranchAddress("HLT_DiJet35_MJJ750_AllJets_DEta3p5_VBF_v2", &HLT_DiJet35_MJJ750_AllJets_DEta3p5_VBF_v2, &b_HLT_DiJet35_MJJ750_AllJets_DEta3p5_VBF_v2);
   fChain->SetBranchAddress("HLT_Ele22_eta2p1_WP90Rho_LooseIsoPFTau20_v3", &HLT_Ele22_eta2p1_WP90Rho_LooseIsoPFTau20_v3, &b_HLT_Ele22_eta2p1_WP90Rho_LooseIsoPFTau20_v3);
   fChain->SetBranchAddress("HLT_Ele22_eta2p1_WP90NoIso_LooseIsoPFTau20_v3", &HLT_Ele22_eta2p1_WP90NoIso_LooseIsoPFTau20_v3, &b_HLT_Ele22_eta2p1_WP90NoIso_LooseIsoPFTau20_v3);
   fChain->SetBranchAddress("HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v3", &HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v3, &b_HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v3);
   fChain->SetBranchAddress("HLT_Mu17_eta2p1_LooseIsoPFTau20_v3", &HLT_Mu17_eta2p1_LooseIsoPFTau20_v3, &b_HLT_Mu17_eta2p1_LooseIsoPFTau20_v3);
   fChain->SetBranchAddress("HLT_PixelTracks_Multiplicity70_v3", &HLT_PixelTracks_Multiplicity70_v3, &b_HLT_PixelTracks_Multiplicity70_v3);
   fChain->SetBranchAddress("HLT_PixelTracks_Multiplicity80_v12", &HLT_PixelTracks_Multiplicity80_v12, &b_HLT_PixelTracks_Multiplicity80_v12);
   fChain->SetBranchAddress("HLT_PixelTracks_Multiplicity90_v3", &HLT_PixelTracks_Multiplicity90_v3, &b_HLT_PixelTracks_Multiplicity90_v3);
   fChain->SetBranchAddress("HLT_BeamGas_HF_Beam1_v5", &HLT_BeamGas_HF_Beam1_v5, &b_HLT_BeamGas_HF_Beam1_v5);
   fChain->SetBranchAddress("HLT_BeamGas_HF_Beam2_v5", &HLT_BeamGas_HF_Beam2_v5, &b_HLT_BeamGas_HF_Beam2_v5);
   fChain->SetBranchAddress("HLT_BeamHalo_v13", &HLT_BeamHalo_v13, &b_HLT_BeamHalo_v13);
   fChain->SetBranchAddress("HLT_IsoTrackHE_v15", &HLT_IsoTrackHE_v15, &b_HLT_IsoTrackHE_v15);
   fChain->SetBranchAddress("HLT_IsoTrackHB_v14", &HLT_IsoTrackHB_v14, &b_HLT_IsoTrackHB_v14);
   fChain->SetBranchAddress("HLT_HcalPhiSym_v11", &HLT_HcalPhiSym_v11, &b_HLT_HcalPhiSym_v11);
   fChain->SetBranchAddress("HLT_HcalNZS_v10", &HLT_HcalNZS_v10, &b_HLT_HcalNZS_v10);
   fChain->SetBranchAddress("HLT_GlobalRunHPDNoise_v8", &HLT_GlobalRunHPDNoise_v8, &b_HLT_GlobalRunHPDNoise_v8);
   fChain->SetBranchAddress("HLT_L1Tech_HBHEHO_totalOR_v6", &HLT_L1Tech_HBHEHO_totalOR_v6, &b_HLT_L1Tech_HBHEHO_totalOR_v6);
   fChain->SetBranchAddress("HLT_L1Tech_HCAL_HF_single_channel_v4", &HLT_L1Tech_HCAL_HF_single_channel_v4, &b_HLT_L1Tech_HCAL_HF_single_channel_v4);
   fChain->SetBranchAddress("HLT_ZeroBias_v7", &HLT_ZeroBias_v7, &b_HLT_ZeroBias_v7);
   fChain->SetBranchAddress("HLT_ZeroBiasPixel_DoubleTrack_v2", &HLT_ZeroBiasPixel_DoubleTrack_v2, &b_HLT_ZeroBiasPixel_DoubleTrack_v2);
   fChain->SetBranchAddress("HLT_Physics_v5", &HLT_Physics_v5, &b_HLT_Physics_v5);
   fChain->SetBranchAddress("HLT_DTCalibration_v2", &HLT_DTCalibration_v2, &b_HLT_DTCalibration_v2);
   fChain->SetBranchAddress("HLT_EcalCalibration_v3", &HLT_EcalCalibration_v3, &b_HLT_EcalCalibration_v3);
   fChain->SetBranchAddress("HLT_HcalCalibration_v3", &HLT_HcalCalibration_v3, &b_HLT_HcalCalibration_v3);
   fChain->SetBranchAddress("HLT_TrackerCalibration_v3", &HLT_TrackerCalibration_v3, &b_HLT_TrackerCalibration_v3);
   fChain->SetBranchAddress("HLT_Random_v2", &HLT_Random_v2, &b_HLT_Random_v2);
   fChain->SetBranchAddress("HLT_L1SingleMuOpen_AntiBPTX_v7", &HLT_L1SingleMuOpen_AntiBPTX_v7, &b_HLT_L1SingleMuOpen_AntiBPTX_v7);
   fChain->SetBranchAddress("HLT_L1TrackerCosmics_v7", &HLT_L1TrackerCosmics_v7, &b_HLT_L1TrackerCosmics_v7);
   fChain->SetBranchAddress("HLT_LogMonitor_v3", &HLT_LogMonitor_v3, &b_HLT_LogMonitor_v3);
   fChain->SetBranchAddress("HLT_DTErrors_v3", &HLT_DTErrors_v3, &b_HLT_DTErrors_v3);
   fChain->SetBranchAddress("HLT_L1DoubleJet36Central_v7", &HLT_L1DoubleJet36Central_v7, &b_HLT_L1DoubleJet36Central_v7);
   fChain->SetBranchAddress("AlCa_EcalPi0EBonly_v6", &AlCa_EcalPi0EBonly_v6, &b_AlCa_EcalPi0EBonly_v6);
   fChain->SetBranchAddress("AlCa_EcalPi0EEonly_v6", &AlCa_EcalPi0EEonly_v6, &b_AlCa_EcalPi0EEonly_v6);
   fChain->SetBranchAddress("AlCa_EcalEtaEBonly_v6", &AlCa_EcalEtaEBonly_v6, &b_AlCa_EcalEtaEBonly_v6);
   fChain->SetBranchAddress("AlCa_EcalEtaEEonly_v6", &AlCa_EcalEtaEEonly_v6, &b_AlCa_EcalEtaEEonly_v6);
   fChain->SetBranchAddress("AlCa_EcalPhiSym_v13", &AlCa_EcalPhiSym_v13, &b_AlCa_EcalPhiSym_v13);
   fChain->SetBranchAddress("AlCa_RPCMuonNoTriggers_v9", &AlCa_RPCMuonNoTriggers_v9, &b_AlCa_RPCMuonNoTriggers_v9);
   fChain->SetBranchAddress("AlCa_RPCMuonNoHits_v9", &AlCa_RPCMuonNoHits_v9, &b_AlCa_RPCMuonNoHits_v9);
   fChain->SetBranchAddress("AlCa_RPCMuonNormalisation_v9", &AlCa_RPCMuonNormalisation_v9, &b_AlCa_RPCMuonNormalisation_v9);
   fChain->SetBranchAddress("AlCa_LumiPixels_v7", &AlCa_LumiPixels_v7, &b_AlCa_LumiPixels_v7);
   fChain->SetBranchAddress("AlCa_LumiPixels_ZeroBias_v4", &AlCa_LumiPixels_ZeroBias_v4, &b_AlCa_LumiPixels_ZeroBias_v4);
   fChain->SetBranchAddress("AlCa_LumiPixels_Random_v1", &AlCa_LumiPixels_Random_v1, &b_AlCa_LumiPixels_Random_v1);
   fChain->SetBranchAddress("HLT_Activity_Ecal_SC7_v13", &HLT_Activity_Ecal_SC7_v13, &b_HLT_Activity_Ecal_SC7_v13);
   fChain->SetBranchAddress("HLT_L1SingleJet16_v7", &HLT_L1SingleJet16_v7, &b_HLT_L1SingleJet16_v7);
   fChain->SetBranchAddress("HLT_L1SingleJet36_v7", &HLT_L1SingleJet36_v7, &b_HLT_L1SingleJet36_v7);

   // Autogenerated from ConfDB - Prescale SetBranchAddressBits
   fChain->SetBranchAddress("HLT_PFJet40_v6_Prescl", &HLT_PFJet40_v6_Prescl, &b_HLT_PFJet40_v6_Prescl);
   fChain->SetBranchAddress("HLT_PFJet80_v6_Prescl", &HLT_PFJet80_v6_Prescl, &b_HLT_PFJet80_v6_Prescl);
   fChain->SetBranchAddress("HLT_PFJet140_v6_Prescl", &HLT_PFJet140_v6_Prescl, &b_HLT_PFJet140_v6_Prescl);
   fChain->SetBranchAddress("HLT_PFJet200_v6_Prescl", &HLT_PFJet200_v6_Prescl, &b_HLT_PFJet200_v6_Prescl);
   fChain->SetBranchAddress("HLT_PFJet260_v6_Prescl", &HLT_PFJet260_v6_Prescl, &b_HLT_PFJet260_v6_Prescl);
   fChain->SetBranchAddress("HLT_PFJet320_v6_Prescl", &HLT_PFJet320_v6_Prescl, &b_HLT_PFJet320_v6_Prescl);
   fChain->SetBranchAddress("HLT_Jet370_NoJetID_v14_Prescl", &HLT_Jet370_NoJetID_v14_Prescl, &b_HLT_Jet370_NoJetID_v14_Prescl);
   fChain->SetBranchAddress("HLT_PFJet400_v6_Prescl", &HLT_PFJet400_v6_Prescl, &b_HLT_PFJet400_v6_Prescl);
   fChain->SetBranchAddress("HLT_MonoCentralPFJet80_PFMETnoMu105_NHEF0p95_v1_Prescl", &HLT_MonoCentralPFJet80_PFMETnoMu105_NHEF0p95_v1_Prescl, &b_HLT_MonoCentralPFJet80_PFMETnoMu105_NHEF0p95_v1_Prescl);
   fChain->SetBranchAddress("HLT_SingleForJet25_v3_Prescl", &HLT_SingleForJet25_v3_Prescl, &b_HLT_SingleForJet25_v3_Prescl);
   fChain->SetBranchAddress("HLT_SingleForJet15_v3_Prescl", &HLT_SingleForJet15_v3_Prescl, &b_HLT_SingleForJet15_v3_Prescl);
   fChain->SetBranchAddress("HLT_DiPFJetAve40_v7_Prescl", &HLT_DiPFJetAve40_v7_Prescl, &b_HLT_DiPFJetAve40_v7_Prescl);
   fChain->SetBranchAddress("HLT_DiPFJetAve80_v7_Prescl", &HLT_DiPFJetAve80_v7_Prescl, &b_HLT_DiPFJetAve80_v7_Prescl);
   fChain->SetBranchAddress("HLT_DiPFJetAve140_v7_Prescl", &HLT_DiPFJetAve140_v7_Prescl, &b_HLT_DiPFJetAve140_v7_Prescl);
   fChain->SetBranchAddress("HLT_DiPFJetAve200_v7_Prescl", &HLT_DiPFJetAve200_v7_Prescl, &b_HLT_DiPFJetAve200_v7_Prescl);
   fChain->SetBranchAddress("HLT_DiPFJetAve260_v7_Prescl", &HLT_DiPFJetAve260_v7_Prescl, &b_HLT_DiPFJetAve260_v7_Prescl);
   fChain->SetBranchAddress("HLT_DiPFJetAve320_v7_Prescl", &HLT_DiPFJetAve320_v7_Prescl, &b_HLT_DiPFJetAve320_v7_Prescl);
   fChain->SetBranchAddress("HLT_DiPFJetAve400_v7_Prescl", &HLT_DiPFJetAve400_v7_Prescl, &b_HLT_DiPFJetAve400_v7_Prescl);
   fChain->SetBranchAddress("HLT_FatDiPFJetMass750_DR1p1_Deta1p5_v6_Prescl", &HLT_FatDiPFJetMass750_DR1p1_Deta1p5_v6_Prescl, &b_HLT_FatDiPFJetMass750_DR1p1_Deta1p5_v6_Prescl);
   fChain->SetBranchAddress("HLT_DoubleJet20_ForwardBackward_v3_Prescl", &HLT_DoubleJet20_ForwardBackward_v3_Prescl, &b_HLT_DoubleJet20_ForwardBackward_v3_Prescl);
   fChain->SetBranchAddress("HLT_DiJet80_DiJet60_DiJet20_v3_Prescl", &HLT_DiJet80_DiJet60_DiJet20_v3_Prescl, &b_HLT_DiJet80_DiJet60_DiJet20_v3_Prescl);
   fChain->SetBranchAddress("HLT_DiPFJet40_PFMETnoMu65_MJJ800VBF_AllJets_v6_Prescl", &HLT_DiPFJet40_PFMETnoMu65_MJJ800VBF_AllJets_v6_Prescl, &b_HLT_DiPFJet40_PFMETnoMu65_MJJ800VBF_AllJets_v6_Prescl);
   fChain->SetBranchAddress("HLT_DiPFJet40_PFMETnoMu65_MJJ600VBF_LeadingJets_v6_Prescl", &HLT_DiPFJet40_PFMETnoMu65_MJJ600VBF_LeadingJets_v6_Prescl, &b_HLT_DiPFJet40_PFMETnoMu65_MJJ600VBF_LeadingJets_v6_Prescl);
   fChain->SetBranchAddress("HLT_DiJet40Eta2p6_BTagIP3DFastPV_v5_Prescl", &HLT_DiJet40Eta2p6_BTagIP3DFastPV_v5_Prescl, &b_HLT_DiJet40Eta2p6_BTagIP3DFastPV_v5_Prescl);
   fChain->SetBranchAddress("HLT_DiJet80Eta2p6_BTagIP3DFastPVLoose_v5_Prescl", &HLT_DiJet80Eta2p6_BTagIP3DFastPVLoose_v5_Prescl, &b_HLT_DiJet80Eta2p6_BTagIP3DFastPVLoose_v5_Prescl);
   fChain->SetBranchAddress("HLT_Jet60Eta1p7_Jet53Eta1p7_DiBTagIP3DFastPV_v5_Prescl", &HLT_Jet60Eta1p7_Jet53Eta1p7_DiBTagIP3DFastPV_v5_Prescl, &b_HLT_Jet60Eta1p7_Jet53Eta1p7_DiBTagIP3DFastPV_v5_Prescl);
   fChain->SetBranchAddress("HLT_Jet80Eta1p7_Jet70Eta1p7_DiBTagIP3DFastPV_v5_Prescl", &HLT_Jet80Eta1p7_Jet70Eta1p7_DiBTagIP3DFastPV_v5_Prescl, &b_HLT_Jet80Eta1p7_Jet70Eta1p7_DiBTagIP3DFastPV_v5_Prescl);
   fChain->SetBranchAddress("HLT_Jet160Eta2p4_Jet120Eta2p4_DiBTagIP3DFastPVLoose_v5_Prescl", &HLT_Jet160Eta2p4_Jet120Eta2p4_DiBTagIP3DFastPVLoose_v5_Prescl, &b_HLT_Jet160Eta2p4_Jet120Eta2p4_DiBTagIP3DFastPVLoose_v5_Prescl);
   fChain->SetBranchAddress("HLT_QuadJet50_v3_Prescl", &HLT_QuadJet50_v3_Prescl, &b_HLT_QuadJet50_v3_Prescl);
   fChain->SetBranchAddress("HLT_QuadJet50_Jet20_v2_Prescl", &HLT_QuadJet50_Jet20_v2_Prescl, &b_HLT_QuadJet50_Jet20_v2_Prescl);
   fChain->SetBranchAddress("HLT_QuadJet60_DiJet20_v3_Prescl", &HLT_QuadJet60_DiJet20_v3_Prescl, &b_HLT_QuadJet60_DiJet20_v3_Prescl);
   fChain->SetBranchAddress("HLT_QuadJet70_v3_Prescl", &HLT_QuadJet70_v3_Prescl, &b_HLT_QuadJet70_v3_Prescl);
   fChain->SetBranchAddress("HLT_QuadJet80_v3_Prescl", &HLT_QuadJet80_v3_Prescl, &b_HLT_QuadJet80_v3_Prescl);
   fChain->SetBranchAddress("HLT_QuadJet90_v3_Prescl", &HLT_QuadJet90_v3_Prescl, &b_HLT_QuadJet90_v3_Prescl);
   fChain->SetBranchAddress("HLT_QuadJet75_55_35_20_BTagIP_VBF_v4_Prescl", &HLT_QuadJet75_55_35_20_BTagIP_VBF_v4_Prescl, &b_HLT_QuadJet75_55_35_20_BTagIP_VBF_v4_Prescl);
   fChain->SetBranchAddress("HLT_QuadJet75_55_38_20_BTagIP_VBF_v4_Prescl", &HLT_QuadJet75_55_38_20_BTagIP_VBF_v4_Prescl, &b_HLT_QuadJet75_55_38_20_BTagIP_VBF_v4_Prescl);
   fChain->SetBranchAddress("HLT_QuadPFJet78_61_44_31_BTagCSV_VBF_v2_Prescl", &HLT_QuadPFJet78_61_44_31_BTagCSV_VBF_v2_Prescl, &b_HLT_QuadPFJet78_61_44_31_BTagCSV_VBF_v2_Prescl);
   fChain->SetBranchAddress("HLT_QuadPFJet82_65_48_35_BTagCSV_VBF_v2_Prescl", &HLT_QuadPFJet82_65_48_35_BTagCSV_VBF_v2_Prescl, &b_HLT_QuadPFJet82_65_48_35_BTagCSV_VBF_v2_Prescl);
   fChain->SetBranchAddress("HLT_SixJet35_v3_Prescl", &HLT_SixJet35_v3_Prescl, &b_HLT_SixJet35_v3_Prescl);
   fChain->SetBranchAddress("HLT_SixJet45_v3_Prescl", &HLT_SixJet45_v3_Prescl, &b_HLT_SixJet45_v3_Prescl);
   fChain->SetBranchAddress("HLT_SixJet50_v3_Prescl", &HLT_SixJet50_v3_Prescl, &b_HLT_SixJet50_v3_Prescl);
   fChain->SetBranchAddress("HLT_EightJet30_eta3p0_v2_Prescl", &HLT_EightJet30_eta3p0_v2_Prescl, &b_HLT_EightJet30_eta3p0_v2_Prescl);
   fChain->SetBranchAddress("HLT_EightJet35_eta3p0_v2_Prescl", &HLT_EightJet35_eta3p0_v2_Prescl, &b_HLT_EightJet35_eta3p0_v2_Prescl);
   fChain->SetBranchAddress("HLT_ExclDiJet35_HFOR_v3_Prescl", &HLT_ExclDiJet35_HFOR_v3_Prescl, &b_HLT_ExclDiJet35_HFOR_v3_Prescl);
   fChain->SetBranchAddress("HLT_ExclDiJet35_HFAND_v3_Prescl", &HLT_ExclDiJet35_HFAND_v3_Prescl, &b_HLT_ExclDiJet35_HFAND_v3_Prescl);
   fChain->SetBranchAddress("HLT_ExclDiJet80_HFAND_v3_Prescl", &HLT_ExclDiJet80_HFAND_v3_Prescl, &b_HLT_ExclDiJet80_HFAND_v3_Prescl);
   fChain->SetBranchAddress("HLT_JetE30_NoBPTX_v13_Prescl", &HLT_JetE30_NoBPTX_v13_Prescl, &b_HLT_JetE30_NoBPTX_v13_Prescl);
   fChain->SetBranchAddress("HLT_JetE30_NoBPTX3BX_NoHalo_v14_Prescl", &HLT_JetE30_NoBPTX3BX_NoHalo_v14_Prescl, &b_HLT_JetE30_NoBPTX3BX_NoHalo_v14_Prescl);
   fChain->SetBranchAddress("HLT_JetE50_NoBPTX3BX_NoHalo_v11_Prescl", &HLT_JetE50_NoBPTX3BX_NoHalo_v11_Prescl, &b_HLT_JetE50_NoBPTX3BX_NoHalo_v11_Prescl);
   fChain->SetBranchAddress("HLT_JetE70_NoBPTX3BX_NoHalo_v3_Prescl", &HLT_JetE70_NoBPTX3BX_NoHalo_v3_Prescl, &b_HLT_JetE70_NoBPTX3BX_NoHalo_v3_Prescl);
   fChain->SetBranchAddress("HLT_HT200_AlphaT0p57_v6_Prescl", &HLT_HT200_AlphaT0p57_v6_Prescl, &b_HLT_HT200_AlphaT0p57_v6_Prescl);
   fChain->SetBranchAddress("HLT_HT200_v4_Prescl", &HLT_HT200_v4_Prescl, &b_HLT_HT200_v4_Prescl);
   fChain->SetBranchAddress("HLT_HT250_AlphaT0p55_v5_Prescl", &HLT_HT250_AlphaT0p55_v5_Prescl, &b_HLT_HT250_AlphaT0p55_v5_Prescl);
   fChain->SetBranchAddress("HLT_HT250_AlphaT0p57_v5_Prescl", &HLT_HT250_AlphaT0p57_v5_Prescl, &b_HLT_HT250_AlphaT0p57_v5_Prescl);
   fChain->SetBranchAddress("HLT_HT250_v4_Prescl", &HLT_HT250_v4_Prescl, &b_HLT_HT250_v4_Prescl);
   fChain->SetBranchAddress("HLT_HT300_AlphaT0p53_v5_Prescl", &HLT_HT300_AlphaT0p53_v5_Prescl, &b_HLT_HT300_AlphaT0p53_v5_Prescl);
   fChain->SetBranchAddress("HLT_HT300_AlphaT0p54_v11_Prescl", &HLT_HT300_AlphaT0p54_v11_Prescl, &b_HLT_HT300_AlphaT0p54_v11_Prescl);
   fChain->SetBranchAddress("HLT_HT300_v4_Prescl", &HLT_HT300_v4_Prescl, &b_HLT_HT300_v4_Prescl);
   fChain->SetBranchAddress("HLT_HT300_DoubleDisplacedPFJet60_v6_Prescl", &HLT_HT300_DoubleDisplacedPFJet60_v6_Prescl, &b_HLT_HT300_DoubleDisplacedPFJet60_v6_Prescl);
   fChain->SetBranchAddress("HLT_HT300_DoubleDisplacedPFJet60_ChgFraction10_v6_Prescl", &HLT_HT300_DoubleDisplacedPFJet60_ChgFraction10_v6_Prescl, &b_HLT_HT300_DoubleDisplacedPFJet60_ChgFraction10_v6_Prescl);
   fChain->SetBranchAddress("HLT_HT300_SingleDisplacedPFJet60_v6_Prescl", &HLT_HT300_SingleDisplacedPFJet60_v6_Prescl, &b_HLT_HT300_SingleDisplacedPFJet60_v6_Prescl);
   fChain->SetBranchAddress("HLT_HT300_SingleDisplacedPFJet60_ChgFraction10_v6_Prescl", &HLT_HT300_SingleDisplacedPFJet60_ChgFraction10_v6_Prescl, &b_HLT_HT300_SingleDisplacedPFJet60_ChgFraction10_v6_Prescl);
   fChain->SetBranchAddress("HLT_HT350_v4_Prescl", &HLT_HT350_v4_Prescl, &b_HLT_HT350_v4_Prescl);
   fChain->SetBranchAddress("HLT_HT350_AlphaT0p52_v5_Prescl", &HLT_HT350_AlphaT0p52_v5_Prescl, &b_HLT_HT350_AlphaT0p52_v5_Prescl);
   fChain->SetBranchAddress("HLT_HT350_AlphaT0p53_v16_Prescl", &HLT_HT350_AlphaT0p53_v16_Prescl, &b_HLT_HT350_AlphaT0p53_v16_Prescl);
   fChain->SetBranchAddress("HLT_HT400_v4_Prescl", &HLT_HT400_v4_Prescl, &b_HLT_HT400_v4_Prescl);
   fChain->SetBranchAddress("HLT_HT400_AlphaT0p51_v16_Prescl", &HLT_HT400_AlphaT0p51_v16_Prescl, &b_HLT_HT400_AlphaT0p51_v16_Prescl);
   fChain->SetBranchAddress("HLT_HT400_AlphaT0p52_v11_Prescl", &HLT_HT400_AlphaT0p52_v11_Prescl, &b_HLT_HT400_AlphaT0p52_v11_Prescl);
   fChain->SetBranchAddress("HLT_HT450_AlphaT0p51_v11_Prescl", &HLT_HT450_AlphaT0p51_v11_Prescl, &b_HLT_HT450_AlphaT0p51_v11_Prescl);
   fChain->SetBranchAddress("HLT_HT450_v4_Prescl", &HLT_HT450_v4_Prescl, &b_HLT_HT450_v4_Prescl);
   fChain->SetBranchAddress("HLT_HT500_v4_Prescl", &HLT_HT500_v4_Prescl, &b_HLT_HT500_v4_Prescl);
   fChain->SetBranchAddress("HLT_HT550_v4_Prescl", &HLT_HT550_v4_Prescl, &b_HLT_HT550_v4_Prescl);
   fChain->SetBranchAddress("HLT_HT650_v4_Prescl", &HLT_HT650_v4_Prescl, &b_HLT_HT650_v4_Prescl);
   fChain->SetBranchAddress("HLT_HT650_Track50_dEdx3p6_v7_Prescl", &HLT_HT650_Track50_dEdx3p6_v7_Prescl, &b_HLT_HT650_Track50_dEdx3p6_v7_Prescl);
   fChain->SetBranchAddress("HLT_HT650_Track60_dEdx3p7_v7_Prescl", &HLT_HT650_Track60_dEdx3p7_v7_Prescl, &b_HLT_HT650_Track60_dEdx3p7_v7_Prescl);
   fChain->SetBranchAddress("HLT_HT750_v4_Prescl", &HLT_HT750_v4_Prescl, &b_HLT_HT750_v4_Prescl);
   fChain->SetBranchAddress("HLT_PFNoPUHT350_v1_Prescl", &HLT_PFNoPUHT350_v1_Prescl, &b_HLT_PFNoPUHT350_v1_Prescl);
   fChain->SetBranchAddress("HLT_PFNoPUHT650_v1_Prescl", &HLT_PFNoPUHT650_v1_Prescl, &b_HLT_PFNoPUHT650_v1_Prescl);
   fChain->SetBranchAddress("HLT_PFNoPUHT650_DiCentralPFNoPUJet80_CenPFNoPUJet40_v1_Prescl", &HLT_PFNoPUHT650_DiCentralPFNoPUJet80_CenPFNoPUJet40_v1_Prescl, &b_HLT_PFNoPUHT650_DiCentralPFNoPUJet80_CenPFNoPUJet40_v1_Prescl);
   fChain->SetBranchAddress("HLT_PFNoPUHT700_v1_Prescl", &HLT_PFNoPUHT700_v1_Prescl, &b_HLT_PFNoPUHT700_v1_Prescl);
   fChain->SetBranchAddress("HLT_PFNoPUHT750_v1_Prescl", &HLT_PFNoPUHT750_v1_Prescl, &b_HLT_PFNoPUHT750_v1_Prescl);
   fChain->SetBranchAddress("HLT_PFMET150_v5_Prescl", &HLT_PFMET150_v5_Prescl, &b_HLT_PFMET150_v5_Prescl);
   fChain->SetBranchAddress("HLT_PFMET180_v5_Prescl", &HLT_PFMET180_v5_Prescl, &b_HLT_PFMET180_v5_Prescl);
   fChain->SetBranchAddress("HLT_DiCentralJetSumpT100_dPhi05_DiCentralPFJet60_25_PFMET100_HBHENoiseCleaned_v2_Prescl", &HLT_DiCentralJetSumpT100_dPhi05_DiCentralPFJet60_25_PFMET100_HBHENoiseCleaned_v2_Prescl, &b_HLT_DiCentralJetSumpT100_dPhi05_DiCentralPFJet60_25_PFMET100_HBHENoiseCleaned_v2_Prescl);
   fChain->SetBranchAddress("HLT_DiCentralPFJet30_PFMET80_v3_Prescl", &HLT_DiCentralPFJet30_PFMET80_v3_Prescl, &b_HLT_DiCentralPFJet30_PFMET80_v3_Prescl);
   fChain->SetBranchAddress("HLT_DiCentralPFNoPUJet50_PFMETORPFMETNoMu80_v1_Prescl", &HLT_DiCentralPFNoPUJet50_PFMETORPFMETNoMu80_v1_Prescl, &b_HLT_DiCentralPFNoPUJet50_PFMETORPFMETNoMu80_v1_Prescl);
   fChain->SetBranchAddress("HLT_DiCentralPFJet30_PFMET80_BTagCSV07_v2_Prescl", &HLT_DiCentralPFJet30_PFMET80_BTagCSV07_v2_Prescl, &b_HLT_DiCentralPFJet30_PFMET80_BTagCSV07_v2_Prescl);
   fChain->SetBranchAddress("HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05d03_v2_Prescl", &HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05d03_v2_Prescl, &b_HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05d03_v2_Prescl);
   fChain->SetBranchAddress("HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05d05_v2_Prescl", &HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05d05_v2_Prescl, &b_HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05d05_v2_Prescl);
   fChain->SetBranchAddress("HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05_v2_Prescl", &HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05_v2_Prescl, &b_HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05_v2_Prescl);
   fChain->SetBranchAddress("HLT_MET80_v4_Prescl", &HLT_MET80_v4_Prescl, &b_HLT_MET80_v4_Prescl);
   fChain->SetBranchAddress("HLT_MET80_Track50_dEdx3p6_v5_Prescl", &HLT_MET80_Track50_dEdx3p6_v5_Prescl, &b_HLT_MET80_Track50_dEdx3p6_v5_Prescl);
   fChain->SetBranchAddress("HLT_MET80_Track60_dEdx3p7_v5_Prescl", &HLT_MET80_Track60_dEdx3p7_v5_Prescl, &b_HLT_MET80_Track60_dEdx3p7_v5_Prescl);
   fChain->SetBranchAddress("HLT_MET120_v11_Prescl", &HLT_MET120_v11_Prescl, &b_HLT_MET120_v11_Prescl);
   fChain->SetBranchAddress("HLT_MET120_HBHENoiseCleaned_v4_Prescl", &HLT_MET120_HBHENoiseCleaned_v4_Prescl, &b_HLT_MET120_HBHENoiseCleaned_v4_Prescl);
   fChain->SetBranchAddress("HLT_MET200_v11_Prescl", &HLT_MET200_v11_Prescl, &b_HLT_MET200_v11_Prescl);
   fChain->SetBranchAddress("HLT_MET200_HBHENoiseCleaned_v4_Prescl", &HLT_MET200_HBHENoiseCleaned_v4_Prescl, &b_HLT_MET200_HBHENoiseCleaned_v4_Prescl);
   fChain->SetBranchAddress("HLT_MET300_v3_Prescl", &HLT_MET300_v3_Prescl, &b_HLT_MET300_v3_Prescl);
   fChain->SetBranchAddress("HLT_MET300_HBHENoiseCleaned_v4_Prescl", &HLT_MET300_HBHENoiseCleaned_v4_Prescl, &b_HLT_MET300_HBHENoiseCleaned_v4_Prescl);
   fChain->SetBranchAddress("HLT_MET400_v6_Prescl", &HLT_MET400_v6_Prescl, &b_HLT_MET400_v6_Prescl);
   fChain->SetBranchAddress("HLT_MET400_HBHENoiseCleaned_v4_Prescl", &HLT_MET400_HBHENoiseCleaned_v4_Prescl, &b_HLT_MET400_HBHENoiseCleaned_v4_Prescl);
   fChain->SetBranchAddress("HLT_L1SingleMuOpen_v7_Prescl", &HLT_L1SingleMuOpen_v7_Prescl, &b_HLT_L1SingleMuOpen_v7_Prescl);
   fChain->SetBranchAddress("HLT_L1SingleMu12_v2_Prescl", &HLT_L1SingleMu12_v2_Prescl, &b_HLT_L1SingleMu12_v2_Prescl);
   fChain->SetBranchAddress("HLT_L2Mu70_eta2p1_PFMET55_v2_Prescl", &HLT_L2Mu70_eta2p1_PFMET55_v2_Prescl, &b_HLT_L2Mu70_eta2p1_PFMET55_v2_Prescl);
   fChain->SetBranchAddress("HLT_L2Mu70_eta2p1_PFMET60_v2_Prescl", &HLT_L2Mu70_eta2p1_PFMET60_v2_Prescl, &b_HLT_L2Mu70_eta2p1_PFMET60_v2_Prescl);
   fChain->SetBranchAddress("HLT_L2Mu20_eta2p1_NoVertex_v2_Prescl", &HLT_L2Mu20_eta2p1_NoVertex_v2_Prescl, &b_HLT_L2Mu20_eta2p1_NoVertex_v2_Prescl);
   fChain->SetBranchAddress("HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo_v3_Prescl", &HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo_v3_Prescl, &b_HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo_v3_Prescl);
   fChain->SetBranchAddress("HLT_L2Mu20_NoVertex_2Cha_NoBPTX3BX_NoHalo_v1_Prescl", &HLT_L2Mu20_NoVertex_2Cha_NoBPTX3BX_NoHalo_v1_Prescl, &b_HLT_L2Mu20_NoVertex_2Cha_NoBPTX3BX_NoHalo_v1_Prescl);
   fChain->SetBranchAddress("HLT_L2Mu30_NoVertex_2Cha_NoBPTX3BX_NoHalo_v1_Prescl", &HLT_L2Mu30_NoVertex_2Cha_NoBPTX3BX_NoHalo_v1_Prescl, &b_HLT_L2Mu30_NoVertex_2Cha_NoBPTX3BX_NoHalo_v1_Prescl);
   fChain->SetBranchAddress("HLT_L2TripleMu10_0_0_NoVertex_PFJet40Neutral_v5_Prescl", &HLT_L2TripleMu10_0_0_NoVertex_PFJet40Neutral_v5_Prescl, &b_HLT_L2TripleMu10_0_0_NoVertex_PFJet40Neutral_v5_Prescl);
   fChain->SetBranchAddress("HLT_DoubleDisplacedMu4_DiPFJet40Neutral_v5_Prescl", &HLT_DoubleDisplacedMu4_DiPFJet40Neutral_v5_Prescl, &b_HLT_DoubleDisplacedMu4_DiPFJet40Neutral_v5_Prescl);
   fChain->SetBranchAddress("HLT_Mu5_v19_Prescl", &HLT_Mu5_v19_Prescl, &b_HLT_Mu5_v19_Prescl);
   fChain->SetBranchAddress("HLT_Mu8_v17_Prescl", &HLT_Mu8_v17_Prescl, &b_HLT_Mu8_v17_Prescl);
   fChain->SetBranchAddress("HLT_Mu12_v17_Prescl", &HLT_Mu12_v17_Prescl, &b_HLT_Mu12_v17_Prescl);
   fChain->SetBranchAddress("HLT_Mu17_v4_Prescl", &HLT_Mu17_v4_Prescl, &b_HLT_Mu17_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu12_eta2p1_L1Mu10erJetC12WdEtaPhi1DiJetsC_v4_Prescl", &HLT_Mu12_eta2p1_L1Mu10erJetC12WdEtaPhi1DiJetsC_v4_Prescl, &b_HLT_Mu12_eta2p1_L1Mu10erJetC12WdEtaPhi1DiJetsC_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu15_eta2p1_v4_Prescl", &HLT_Mu15_eta2p1_v4_Prescl, &b_HLT_Mu15_eta2p1_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu24_v15_Prescl", &HLT_Mu24_v15_Prescl, &b_HLT_Mu24_v15_Prescl);
   fChain->SetBranchAddress("HLT_Mu24_eta2p1_v4_Prescl", &HLT_Mu24_eta2p1_v4_Prescl, &b_HLT_Mu24_eta2p1_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu30_v15_Prescl", &HLT_Mu30_v15_Prescl, &b_HLT_Mu30_v15_Prescl);
   fChain->SetBranchAddress("HLT_Mu30_eta2p1_v4_Prescl", &HLT_Mu30_eta2p1_v4_Prescl, &b_HLT_Mu30_eta2p1_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu40_v13_Prescl", &HLT_Mu40_v13_Prescl, &b_HLT_Mu40_v13_Prescl);
   fChain->SetBranchAddress("HLT_Mu40_eta2p1_v10_Prescl", &HLT_Mu40_eta2p1_v10_Prescl, &b_HLT_Mu40_eta2p1_v10_Prescl);
   fChain->SetBranchAddress("HLT_Mu50_eta2p1_v7_Prescl", &HLT_Mu50_eta2p1_v7_Prescl, &b_HLT_Mu50_eta2p1_v7_Prescl);
   fChain->SetBranchAddress("HLT_RelIso1p0Mu5_v5_Prescl", &HLT_RelIso1p0Mu5_v5_Prescl, &b_HLT_RelIso1p0Mu5_v5_Prescl);
   fChain->SetBranchAddress("HLT_RelIso1p0Mu20_v2_Prescl", &HLT_RelIso1p0Mu20_v2_Prescl, &b_HLT_RelIso1p0Mu20_v2_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu15_eta2p1_L1ETM20_v6_Prescl", &HLT_IsoMu15_eta2p1_L1ETM20_v6_Prescl, &b_HLT_IsoMu15_eta2p1_L1ETM20_v6_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu20_eta2p1_v6_Prescl", &HLT_IsoMu20_eta2p1_v6_Prescl, &b_HLT_IsoMu20_eta2p1_v6_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu24_v16_Prescl", &HLT_IsoMu24_v16_Prescl, &b_HLT_IsoMu24_v16_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1_v14_Prescl", &HLT_IsoMu24_eta2p1_v14_Prescl, &b_HLT_IsoMu24_eta2p1_v14_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu30_v10_Prescl", &HLT_IsoMu30_v10_Prescl, &b_HLT_IsoMu30_v10_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu30_eta2p1_v14_Prescl", &HLT_IsoMu30_eta2p1_v14_Prescl, &b_HLT_IsoMu30_eta2p1_v14_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu34_eta2p1_v12_Prescl", &HLT_IsoMu34_eta2p1_v12_Prescl, &b_HLT_IsoMu34_eta2p1_v12_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu40_eta2p1_v9_Prescl", &HLT_IsoMu40_eta2p1_v9_Prescl, &b_HLT_IsoMu40_eta2p1_v9_Prescl);
   fChain->SetBranchAddress("HLT_Mu40_eta2p1_Track50_dEdx3p6_v4_Prescl", &HLT_Mu40_eta2p1_Track50_dEdx3p6_v4_Prescl, &b_HLT_Mu40_eta2p1_Track50_dEdx3p6_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu40_eta2p1_Track60_dEdx3p7_v4_Prescl", &HLT_Mu40_eta2p1_Track60_dEdx3p7_v4_Prescl, &b_HLT_Mu40_eta2p1_Track60_dEdx3p7_v4_Prescl);
   fChain->SetBranchAddress("HLT_L2DoubleMu23_NoVertex_v11_Prescl", &HLT_L2DoubleMu23_NoVertex_v11_Prescl, &b_HLT_L2DoubleMu23_NoVertex_v11_Prescl);
   fChain->SetBranchAddress("HLT_L2DoubleMu23_NoVertex_2Cha_Angle2p5_v3_Prescl", &HLT_L2DoubleMu23_NoVertex_2Cha_Angle2p5_v3_Prescl, &b_HLT_L2DoubleMu23_NoVertex_2Cha_Angle2p5_v3_Prescl);
   fChain->SetBranchAddress("HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_v3_Prescl", &HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_v3_Prescl, &b_HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_v3_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMu11_Acoplanarity03_v4_Prescl", &HLT_DoubleMu11_Acoplanarity03_v4_Prescl, &b_HLT_DoubleMu11_Acoplanarity03_v4_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMu4_Jpsi_Displaced_v10_Prescl", &HLT_DoubleMu4_Jpsi_Displaced_v10_Prescl, &b_HLT_DoubleMu4_Jpsi_Displaced_v10_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMu4_JpsiTk_Displaced_v4_Prescl", &HLT_DoubleMu4_JpsiTk_Displaced_v4_Prescl, &b_HLT_DoubleMu4_JpsiTk_Displaced_v4_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMu3_4_Dimuon5_Bs_Central_v3_Prescl", &HLT_DoubleMu3_4_Dimuon5_Bs_Central_v3_Prescl, &b_HLT_DoubleMu3_4_Dimuon5_Bs_Central_v3_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMu3p5_4_Dimuon5_Bs_Central_v3_Prescl", &HLT_DoubleMu3p5_4_Dimuon5_Bs_Central_v3_Prescl, &b_HLT_DoubleMu3p5_4_Dimuon5_Bs_Central_v3_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMu4_Dimuon7_Bs_Forward_v3_Prescl", &HLT_DoubleMu4_Dimuon7_Bs_Forward_v3_Prescl, &b_HLT_DoubleMu4_Dimuon7_Bs_Forward_v3_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMu3p5_LowMass_Displaced_v4_Prescl", &HLT_DoubleMu3p5_LowMass_Displaced_v4_Prescl, &b_HLT_DoubleMu3p5_LowMass_Displaced_v4_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMu3p5_LowMassNonResonant_Displaced_v4_Prescl", &HLT_DoubleMu3p5_LowMassNonResonant_Displaced_v4_Prescl, &b_HLT_DoubleMu3p5_LowMassNonResonant_Displaced_v4_Prescl);
   fChain->SetBranchAddress("HLT_Dimuon0_Jpsi_v15_Prescl", &HLT_Dimuon0_Jpsi_v15_Prescl, &b_HLT_Dimuon0_Jpsi_v15_Prescl);
   fChain->SetBranchAddress("HLT_Dimuon0_Jpsi_NoVertexing_v12_Prescl", &HLT_Dimuon0_Jpsi_NoVertexing_v12_Prescl, &b_HLT_Dimuon0_Jpsi_NoVertexing_v12_Prescl);
   fChain->SetBranchAddress("HLT_Dimuon0_Upsilon_v15_Prescl", &HLT_Dimuon0_Upsilon_v15_Prescl, &b_HLT_Dimuon0_Upsilon_v15_Prescl);
   fChain->SetBranchAddress("HLT_Dimuon0_PsiPrime_v4_Prescl", &HLT_Dimuon0_PsiPrime_v4_Prescl, &b_HLT_Dimuon0_PsiPrime_v4_Prescl);
   fChain->SetBranchAddress("HLT_Dimuon5_Upsilon_v4_Prescl", &HLT_Dimuon5_Upsilon_v4_Prescl, &b_HLT_Dimuon5_Upsilon_v4_Prescl);
   fChain->SetBranchAddress("HLT_Dimuon5_PsiPrime_v4_Prescl", &HLT_Dimuon5_PsiPrime_v4_Prescl, &b_HLT_Dimuon5_PsiPrime_v4_Prescl);
   fChain->SetBranchAddress("HLT_Dimuon7_Upsilon_v5_Prescl", &HLT_Dimuon7_Upsilon_v5_Prescl, &b_HLT_Dimuon7_Upsilon_v5_Prescl);
   fChain->SetBranchAddress("HLT_Dimuon7_PsiPrime_v1_Prescl", &HLT_Dimuon7_PsiPrime_v1_Prescl, &b_HLT_Dimuon7_PsiPrime_v1_Prescl);
   fChain->SetBranchAddress("HLT_Dimuon8_Jpsi_v5_Prescl", &HLT_Dimuon8_Jpsi_v5_Prescl, &b_HLT_Dimuon8_Jpsi_v5_Prescl);
   fChain->SetBranchAddress("HLT_Dimuon8_Upsilon_v4_Prescl", &HLT_Dimuon8_Upsilon_v4_Prescl, &b_HLT_Dimuon8_Upsilon_v4_Prescl);
   fChain->SetBranchAddress("HLT_Dimuon10_Jpsi_v4_Prescl", &HLT_Dimuon10_Jpsi_v4_Prescl, &b_HLT_Dimuon10_Jpsi_v4_Prescl);
   fChain->SetBranchAddress("HLT_Dimuon11_Upsilon_v4_Prescl", &HLT_Dimuon11_Upsilon_v4_Prescl, &b_HLT_Dimuon11_Upsilon_v4_Prescl);
   fChain->SetBranchAddress("HLT_Dimuon0_Jpsi_Muon_v16_Prescl", &HLT_Dimuon0_Jpsi_Muon_v16_Prescl, &b_HLT_Dimuon0_Jpsi_Muon_v16_Prescl);
   fChain->SetBranchAddress("HLT_Dimuon0_Upsilon_Muon_v16_Prescl", &HLT_Dimuon0_Upsilon_Muon_v16_Prescl, &b_HLT_Dimuon0_Upsilon_Muon_v16_Prescl);
   fChain->SetBranchAddress("HLT_Dimuon3p5_SameSign_v4_Prescl", &HLT_Dimuon3p5_SameSign_v4_Prescl, &b_HLT_Dimuon3p5_SameSign_v4_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMu4_Acoplanarity03_v4_Prescl", &HLT_DoubleMu4_Acoplanarity03_v4_Prescl, &b_HLT_DoubleMu4_Acoplanarity03_v4_Prescl);
   fChain->SetBranchAddress("HLT_Tau2Mu_ItTrack_v4_Prescl", &HLT_Tau2Mu_ItTrack_v4_Prescl, &b_HLT_Tau2Mu_ItTrack_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu13_Mu8_v18_Prescl", &HLT_Mu13_Mu8_v18_Prescl, &b_HLT_Mu13_Mu8_v18_Prescl);
   fChain->SetBranchAddress("HLT_Mu17_Mu8_v18_Prescl", &HLT_Mu17_Mu8_v18_Prescl, &b_HLT_Mu17_Mu8_v18_Prescl);
   fChain->SetBranchAddress("HLT_Mu17_TkMu8_v11_Prescl", &HLT_Mu17_TkMu8_v11_Prescl, &b_HLT_Mu17_TkMu8_v11_Prescl);
   fChain->SetBranchAddress("HLT_Mu22_TkMu8_v7_Prescl", &HLT_Mu22_TkMu8_v7_Prescl, &b_HLT_Mu22_TkMu8_v7_Prescl);
   fChain->SetBranchAddress("HLT_Mu22_TkMu22_v7_Prescl", &HLT_Mu22_TkMu22_v7_Prescl, &b_HLT_Mu22_TkMu22_v7_Prescl);
   fChain->SetBranchAddress("HLT_TripleMu5_v18_Prescl", &HLT_TripleMu5_v18_Prescl, &b_HLT_TripleMu5_v18_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMu5_IsoMu5_v19_Prescl", &HLT_DoubleMu5_IsoMu5_v19_Prescl, &b_HLT_DoubleMu5_IsoMu5_v19_Prescl);
   fChain->SetBranchAddress("HLT_Mu5_L2Mu3_Jpsi_v5_Prescl", &HLT_Mu5_L2Mu3_Jpsi_v5_Prescl, &b_HLT_Mu5_L2Mu3_Jpsi_v5_Prescl);
   fChain->SetBranchAddress("HLT_Mu5_Track2_Jpsi_v19_Prescl", &HLT_Mu5_Track2_Jpsi_v19_Prescl, &b_HLT_Mu5_Track2_Jpsi_v19_Prescl);
   fChain->SetBranchAddress("HLT_Mu5_Track3p5_Jpsi_v5_Prescl", &HLT_Mu5_Track3p5_Jpsi_v5_Prescl, &b_HLT_Mu5_Track3p5_Jpsi_v5_Prescl);
   fChain->SetBranchAddress("HLT_Mu7_Track7_Jpsi_v19_Prescl", &HLT_Mu7_Track7_Jpsi_v19_Prescl, &b_HLT_Mu7_Track7_Jpsi_v19_Prescl);
   fChain->SetBranchAddress("HLT_Photon20_CaloIdVL_v4_Prescl", &HLT_Photon20_CaloIdVL_v4_Prescl, &b_HLT_Photon20_CaloIdVL_v4_Prescl);
   fChain->SetBranchAddress("HLT_Photon20_CaloIdVL_IsoL_v16_Prescl", &HLT_Photon20_CaloIdVL_IsoL_v16_Prescl, &b_HLT_Photon20_CaloIdVL_IsoL_v16_Prescl);
   fChain->SetBranchAddress("HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_v5_Prescl", &HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_v5_Prescl, &b_HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_v5_Prescl);
   fChain->SetBranchAddress("HLT_Photon26_Photon18_v12_Prescl", &HLT_Photon26_Photon18_v12_Prescl, &b_HLT_Photon26_Photon18_v12_Prescl);
   fChain->SetBranchAddress("HLT_Photon26_R9Id85_Photon18_R9Id85_Mass60_v4_Prescl", &HLT_Photon26_R9Id85_Photon18_R9Id85_Mass60_v4_Prescl, &b_HLT_Photon26_R9Id85_Photon18_R9Id85_Mass60_v4_Prescl);
   fChain->SetBranchAddress("HLT_Photon26_R9Id85_Photon18_CaloId10_Iso50_Mass60_v6_Prescl", &HLT_Photon26_R9Id85_Photon18_CaloId10_Iso50_Mass60_v6_Prescl, &b_HLT_Photon26_R9Id85_Photon18_CaloId10_Iso50_Mass60_v6_Prescl);
   fChain->SetBranchAddress("HLT_Photon26_CaloId10_Iso50_Photon18_R9Id85_Mass60_v6_Prescl", &HLT_Photon26_CaloId10_Iso50_Photon18_R9Id85_Mass60_v6_Prescl, &b_HLT_Photon26_CaloId10_Iso50_Photon18_R9Id85_Mass60_v6_Prescl);
   fChain->SetBranchAddress("HLT_Photon26_CaloId10_Iso50_Photon18_CaloId10_Iso50_Mass60_v6_Prescl", &HLT_Photon26_CaloId10_Iso50_Photon18_CaloId10_Iso50_Mass60_v6_Prescl, &b_HLT_Photon26_CaloId10_Iso50_Photon18_CaloId10_Iso50_Mass60_v6_Prescl);
   fChain->SetBranchAddress("HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass60_v6_Prescl", &HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass60_v6_Prescl, &b_HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass60_v6_Prescl);
   fChain->SetBranchAddress("HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass70_v2_Prescl", &HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass70_v2_Prescl, &b_HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass70_v2_Prescl);
   fChain->SetBranchAddress("HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_v5_Prescl", &HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_v5_Prescl, &b_HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_v5_Prescl);
   fChain->SetBranchAddress("HLT_Photon30_CaloIdVL_v14_Prescl", &HLT_Photon30_CaloIdVL_v14_Prescl, &b_HLT_Photon30_CaloIdVL_v14_Prescl);
   fChain->SetBranchAddress("HLT_Photon30_CaloIdVL_IsoL_v19_Prescl", &HLT_Photon30_CaloIdVL_IsoL_v19_Prescl, &b_HLT_Photon30_CaloIdVL_IsoL_v19_Prescl);
   fChain->SetBranchAddress("HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_v5_Prescl", &HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_v5_Prescl, &b_HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_v5_Prescl);
   fChain->SetBranchAddress("HLT_Photon36_Photon22_v6_Prescl", &HLT_Photon36_Photon22_v6_Prescl, &b_HLT_Photon36_Photon22_v6_Prescl);
   fChain->SetBranchAddress("HLT_Photon36_R9Id85_Photon22_R9Id85_v4_Prescl", &HLT_Photon36_R9Id85_Photon22_R9Id85_v4_Prescl, &b_HLT_Photon36_R9Id85_Photon22_R9Id85_v4_Prescl);
   fChain->SetBranchAddress("HLT_Photon36_R9Id85_Photon22_CaloId10_Iso50_v6_Prescl", &HLT_Photon36_R9Id85_Photon22_CaloId10_Iso50_v6_Prescl, &b_HLT_Photon36_R9Id85_Photon22_CaloId10_Iso50_v6_Prescl);
   fChain->SetBranchAddress("HLT_Photon36_CaloId10_Iso50_Photon22_R9Id85_v6_Prescl", &HLT_Photon36_CaloId10_Iso50_Photon22_R9Id85_v6_Prescl, &b_HLT_Photon36_CaloId10_Iso50_Photon22_R9Id85_v6_Prescl);
   fChain->SetBranchAddress("HLT_Photon36_CaloId10_Iso50_Photon22_CaloId10_Iso50_v6_Prescl", &HLT_Photon36_CaloId10_Iso50_Photon22_CaloId10_Iso50_v6_Prescl, &b_HLT_Photon36_CaloId10_Iso50_Photon22_CaloId10_Iso50_v6_Prescl);
   fChain->SetBranchAddress("HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_R9Id85_OR_CaloId10_Iso50_v6_Prescl", &HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_R9Id85_OR_CaloId10_Iso50_v6_Prescl, &b_HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_R9Id85_OR_CaloId10_Iso50_v6_Prescl);
   fChain->SetBranchAddress("HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_v5_Prescl", &HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_v5_Prescl, &b_HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_v5_Prescl);
   fChain->SetBranchAddress("HLT_Photon50_CaloIdVL_v10_Prescl", &HLT_Photon50_CaloIdVL_v10_Prescl, &b_HLT_Photon50_CaloIdVL_v10_Prescl);
   fChain->SetBranchAddress("HLT_Photon50_CaloIdVL_IsoL_v17_Prescl", &HLT_Photon50_CaloIdVL_IsoL_v17_Prescl, &b_HLT_Photon50_CaloIdVL_IsoL_v17_Prescl);
   fChain->SetBranchAddress("HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_v5_Prescl", &HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_v5_Prescl, &b_HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_v5_Prescl);
   fChain->SetBranchAddress("HLT_Photon60_CaloIdL_MHT70_v9_Prescl", &HLT_Photon60_CaloIdL_MHT70_v9_Prescl, &b_HLT_Photon60_CaloIdL_MHT70_v9_Prescl);
   fChain->SetBranchAddress("HLT_Photon60_CaloIdL_HT300_v2_Prescl", &HLT_Photon60_CaloIdL_HT300_v2_Prescl, &b_HLT_Photon60_CaloIdL_HT300_v2_Prescl);
   fChain->SetBranchAddress("HLT_Photon70_CaloIdXL_PFNoPUHT400_v1_Prescl", &HLT_Photon70_CaloIdXL_PFNoPUHT400_v1_Prescl, &b_HLT_Photon70_CaloIdXL_PFNoPUHT400_v1_Prescl);
   fChain->SetBranchAddress("HLT_Photon70_CaloIdXL_PFNoPUHT500_v1_Prescl", &HLT_Photon70_CaloIdXL_PFNoPUHT500_v1_Prescl, &b_HLT_Photon70_CaloIdXL_PFNoPUHT500_v1_Prescl);
   fChain->SetBranchAddress("HLT_Photon70_CaloIdXL_PFMET100_v5_Prescl", &HLT_Photon70_CaloIdXL_PFMET100_v5_Prescl, &b_HLT_Photon70_CaloIdXL_PFMET100_v5_Prescl);
   fChain->SetBranchAddress("HLT_Photon75_CaloIdVL_v13_Prescl", &HLT_Photon75_CaloIdVL_v13_Prescl, &b_HLT_Photon75_CaloIdVL_v13_Prescl);
   fChain->SetBranchAddress("HLT_Photon75_CaloIdVL_IsoL_v18_Prescl", &HLT_Photon75_CaloIdVL_IsoL_v18_Prescl, &b_HLT_Photon75_CaloIdVL_IsoL_v18_Prescl);
   fChain->SetBranchAddress("HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_v5_Prescl", &HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_v5_Prescl, &b_HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_v5_Prescl);
   fChain->SetBranchAddress("HLT_Photon90_CaloIdVL_v10_Prescl", &HLT_Photon90_CaloIdVL_v10_Prescl, &b_HLT_Photon90_CaloIdVL_v10_Prescl);
   fChain->SetBranchAddress("HLT_Photon90_CaloIdVL_IsoL_v15_Prescl", &HLT_Photon90_CaloIdVL_IsoL_v15_Prescl, &b_HLT_Photon90_CaloIdVL_IsoL_v15_Prescl);
   fChain->SetBranchAddress("HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_v5_Prescl", &HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_v5_Prescl, &b_HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_v5_Prescl);
   fChain->SetBranchAddress("HLT_DisplacedPhoton65_CaloIdVL_IsoL_PFMET25_v2_Prescl", &HLT_DisplacedPhoton65_CaloIdVL_IsoL_PFMET25_v2_Prescl, &b_HLT_DisplacedPhoton65_CaloIdVL_IsoL_PFMET25_v2_Prescl);
   fChain->SetBranchAddress("HLT_DisplacedPhoton65EBOnly_CaloIdVL_IsoL_PFMET30_v2_Prescl", &HLT_DisplacedPhoton65EBOnly_CaloIdVL_IsoL_PFMET30_v2_Prescl, &b_HLT_DisplacedPhoton65EBOnly_CaloIdVL_IsoL_PFMET30_v2_Prescl);
   fChain->SetBranchAddress("HLT_Photon135_v7_Prescl", &HLT_Photon135_v7_Prescl, &b_HLT_Photon135_v7_Prescl);
   fChain->SetBranchAddress("HLT_Photon150_v4_Prescl", &HLT_Photon150_v4_Prescl, &b_HLT_Photon150_v4_Prescl);
   fChain->SetBranchAddress("HLT_Photon160_v4_Prescl", &HLT_Photon160_v4_Prescl, &b_HLT_Photon160_v4_Prescl);
   fChain->SetBranchAddress("HLT_Photon300_NoHE_v5_Prescl", &HLT_Photon300_NoHE_v5_Prescl, &b_HLT_Photon300_NoHE_v5_Prescl);
   fChain->SetBranchAddress("HLT_DoublePhoton48_HEVT_v8_Prescl", &HLT_DoublePhoton48_HEVT_v8_Prescl, &b_HLT_DoublePhoton48_HEVT_v8_Prescl);
   fChain->SetBranchAddress("HLT_DoublePhoton53_HEVT_v2_Prescl", &HLT_DoublePhoton53_HEVT_v2_Prescl, &b_HLT_DoublePhoton53_HEVT_v2_Prescl);
   fChain->SetBranchAddress("HLT_DoublePhoton70_v6_Prescl", &HLT_DoublePhoton70_v6_Prescl, &b_HLT_DoublePhoton70_v6_Prescl);
   fChain->SetBranchAddress("HLT_DoublePhoton80_v7_Prescl", &HLT_DoublePhoton80_v7_Prescl, &b_HLT_DoublePhoton80_v7_Prescl);
   fChain->SetBranchAddress("HLT_DoublePhoton5_IsoVL_CEP_v16_Prescl", &HLT_DoublePhoton5_IsoVL_CEP_v16_Prescl, &b_HLT_DoublePhoton5_IsoVL_CEP_v16_Prescl);
   fChain->SetBranchAddress("HLT_L1SingleEG5_v6_Prescl", &HLT_L1SingleEG5_v6_Prescl, &b_HLT_L1SingleEG5_v6_Prescl);
   fChain->SetBranchAddress("HLT_L1SingleEG12_v6_Prescl", &HLT_L1SingleEG12_v6_Prescl, &b_HLT_L1SingleEG12_v6_Prescl);
   fChain->SetBranchAddress("HLT_L1DoubleEG3_FwdVeto_v2_Prescl", &HLT_L1DoubleEG3_FwdVeto_v2_Prescl, &b_HLT_L1DoubleEG3_FwdVeto_v2_Prescl);
   fChain->SetBranchAddress("HLT_L1ETM30_v2_Prescl", &HLT_L1ETM30_v2_Prescl, &b_HLT_L1ETM30_v2_Prescl);
   fChain->SetBranchAddress("HLT_L1ETM40_v2_Prescl", &HLT_L1ETM40_v2_Prescl, &b_HLT_L1ETM40_v2_Prescl);
   fChain->SetBranchAddress("HLT_L1ETM70_v2_Prescl", &HLT_L1ETM70_v2_Prescl, &b_HLT_L1ETM70_v2_Prescl);
   fChain->SetBranchAddress("HLT_L1ETM100_v2_Prescl", &HLT_L1ETM100_v2_Prescl, &b_HLT_L1ETM100_v2_Prescl);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdT_TrkIdVL_v5_Prescl", &HLT_Ele8_CaloIdT_TrkIdVL_v5_Prescl, &b_HLT_Ele8_CaloIdT_TrkIdVL_v5_Prescl);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdT_TrkIdVL_EG7_v2_Prescl", &HLT_Ele8_CaloIdT_TrkIdVL_EG7_v2_Prescl, &b_HLT_Ele8_CaloIdT_TrkIdVL_EG7_v2_Prescl);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdT_TrkIdVL_Jet30_v5_Prescl", &HLT_Ele8_CaloIdT_TrkIdVL_Jet30_v5_Prescl, &b_HLT_Ele8_CaloIdT_TrkIdVL_Jet30_v5_Prescl);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdL_CaloIsoVL_v17_Prescl", &HLT_Ele8_CaloIdL_CaloIsoVL_v17_Prescl, &b_HLT_Ele8_CaloIdL_CaloIsoVL_v17_Prescl);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v15_Prescl", &HLT_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v15_Prescl, &b_HLT_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v15_Prescl);
   fChain->SetBranchAddress("HLT_Ele17_CaloIdL_CaloIsoVL_v17_Prescl", &HLT_Ele17_CaloIdL_CaloIsoVL_v17_Prescl, &b_HLT_Ele17_CaloIdL_CaloIsoVL_v17_Prescl);
   fChain->SetBranchAddress("HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v6_Prescl", &HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v6_Prescl, &b_HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v6_Prescl);
   fChain->SetBranchAddress("HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v18_Prescl", &HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v18_Prescl, &b_HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v18_Prescl);
   fChain->SetBranchAddress("HLT_Ele17_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_Ele8_Mass50_v6_Prescl", &HLT_Ele17_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_Ele8_Mass50_v6_Prescl, &b_HLT_Ele17_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_Ele8_Mass50_v6_Prescl);
   fChain->SetBranchAddress("HLT_Ele20_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_SC4_Mass50_v6_Prescl", &HLT_Ele20_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_SC4_Mass50_v6_Prescl, &b_HLT_Ele20_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_SC4_Mass50_v6_Prescl);
   fChain->SetBranchAddress("HLT_Ele22_CaloIdL_CaloIsoVL_v6_Prescl", &HLT_Ele22_CaloIdL_CaloIsoVL_v6_Prescl, &b_HLT_Ele22_CaloIdL_CaloIsoVL_v6_Prescl);
   fChain->SetBranchAddress("HLT_Ele27_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_v11_Prescl", &HLT_Ele27_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_v11_Prescl, &b_HLT_Ele27_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_v11_Prescl);
   fChain->SetBranchAddress("HLT_Ele27_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele15_CaloIdT_CaloIsoVL_trackless_v7_Prescl", &HLT_Ele27_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele15_CaloIdT_CaloIsoVL_trackless_v7_Prescl, &b_HLT_Ele27_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele15_CaloIdT_CaloIsoVL_trackless_v7_Prescl);
   fChain->SetBranchAddress("HLT_Ele27_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_HFT15_v7_Prescl", &HLT_Ele27_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_HFT15_v7_Prescl, &b_HLT_Ele27_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_HFT15_v7_Prescl);
   fChain->SetBranchAddress("HLT_Ele23_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_HFT30_v7_Prescl", &HLT_Ele23_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_HFT30_v7_Prescl, &b_HLT_Ele23_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_HFT30_v7_Prescl);
   fChain->SetBranchAddress("HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet30_v2_Prescl", &HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet30_v2_Prescl, &b_HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet30_v2_Prescl);
   fChain->SetBranchAddress("HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet50_40_30_v2_Prescl", &HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet50_40_30_v2_Prescl, &b_HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet50_40_30_v2_Prescl);
   fChain->SetBranchAddress("HLT_Ele27_WP80_v11_Prescl", &HLT_Ele27_WP80_v11_Prescl, &b_HLT_Ele27_WP80_v11_Prescl);
   fChain->SetBranchAddress("HLT_Ele27_WP80_PFMET_MT50_v5_Prescl", &HLT_Ele27_WP80_PFMET_MT50_v5_Prescl, &b_HLT_Ele27_WP80_PFMET_MT50_v5_Prescl);
   fChain->SetBranchAddress("HLT_Ele30_CaloIdVT_TrkIdT_v6_Prescl", &HLT_Ele30_CaloIdVT_TrkIdT_v6_Prescl, &b_HLT_Ele30_CaloIdVT_TrkIdT_v6_Prescl);
   fChain->SetBranchAddress("HLT_Ele32_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_v11_Prescl", &HLT_Ele32_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_v11_Prescl, &b_HLT_Ele32_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_v11_Prescl);
   fChain->SetBranchAddress("HLT_Ele32_CaloIdT_CaloIsoT_TrkIdT_TrkIsoT_SC17_Mass50_v6_Prescl", &HLT_Ele32_CaloIdT_CaloIsoT_TrkIdT_TrkIsoT_SC17_Mass50_v6_Prescl, &b_HLT_Ele32_CaloIdT_CaloIsoT_TrkIdT_TrkIsoT_SC17_Mass50_v6_Prescl);
   fChain->SetBranchAddress("HLT_Ele80_CaloIdVT_GsfTrkIdT_v2_Prescl", &HLT_Ele80_CaloIdVT_GsfTrkIdT_v2_Prescl, &b_HLT_Ele80_CaloIdVT_GsfTrkIdT_v2_Prescl);
   fChain->SetBranchAddress("HLT_Ele90_CaloIdVT_GsfTrkIdT_v2_Prescl", &HLT_Ele90_CaloIdVT_GsfTrkIdT_v2_Prescl, &b_HLT_Ele90_CaloIdVT_GsfTrkIdT_v2_Prescl);
   fChain->SetBranchAddress("HLT_DoubleEle8_CaloIdT_TrkIdVL_v12_Prescl", &HLT_DoubleEle8_CaloIdT_TrkIdVL_v12_Prescl, &b_HLT_DoubleEle8_CaloIdT_TrkIdVL_v12_Prescl);
   fChain->SetBranchAddress("HLT_DoubleEle33_CaloIdL_v14_Prescl", &HLT_DoubleEle33_CaloIdL_v14_Prescl, &b_HLT_DoubleEle33_CaloIdL_v14_Prescl);
   fChain->SetBranchAddress("HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v7_Prescl", &HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v7_Prescl, &b_HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v7_Prescl);
   fChain->SetBranchAddress("HLT_DoubleEle33_CaloIdT_v10_Prescl", &HLT_DoubleEle33_CaloIdT_v10_Prescl, &b_HLT_DoubleEle33_CaloIdT_v10_Prescl);
   fChain->SetBranchAddress("HLT_Ele15_Ele8_Ele5_CaloIdL_TrkIdVL_v6_Prescl", &HLT_Ele15_Ele8_Ele5_CaloIdL_TrkIdVL_v6_Prescl, &b_HLT_Ele15_Ele8_Ele5_CaloIdL_TrkIdVL_v6_Prescl);
   fChain->SetBranchAddress("HLT_LooseIsoPFTau35_Trk20_Prong1_v7_Prescl", &HLT_LooseIsoPFTau35_Trk20_Prong1_v7_Prescl, &b_HLT_LooseIsoPFTau35_Trk20_Prong1_v7_Prescl);
   fChain->SetBranchAddress("HLT_LooseIsoPFTau35_Trk20_Prong1_MET70_v7_Prescl", &HLT_LooseIsoPFTau35_Trk20_Prong1_MET70_v7_Prescl, &b_HLT_LooseIsoPFTau35_Trk20_Prong1_MET70_v7_Prescl);
   fChain->SetBranchAddress("HLT_LooseIsoPFTau35_Trk20_Prong1_MET75_v7_Prescl", &HLT_LooseIsoPFTau35_Trk20_Prong1_MET75_v7_Prescl, &b_HLT_LooseIsoPFTau35_Trk20_Prong1_MET75_v7_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu15_eta2p1_LooseIsoPFTau35_Trk20_Prong1_L1ETM20_v7_Prescl", &HLT_IsoMu15_eta2p1_LooseIsoPFTau35_Trk20_Prong1_L1ETM20_v7_Prescl, &b_HLT_IsoMu15_eta2p1_LooseIsoPFTau35_Trk20_Prong1_L1ETM20_v7_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMediumIsoPFTau30_Trk1_eta2p1_Jet30_v1_Prescl", &HLT_DoubleMediumIsoPFTau30_Trk1_eta2p1_Jet30_v1_Prescl, &b_HLT_DoubleMediumIsoPFTau30_Trk1_eta2p1_Jet30_v1_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMediumIsoPFTau30_Trk1_eta2p1_v1_Prescl", &HLT_DoubleMediumIsoPFTau30_Trk1_eta2p1_v1_Prescl, &b_HLT_DoubleMediumIsoPFTau30_Trk1_eta2p1_v1_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Prong1_v1_Prescl", &HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Prong1_v1_Prescl, &b_HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Prong1_v1_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_v1_Prescl", &HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_v1_Prescl, &b_HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_v1_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu18_eta2p1_MediumIsoPFTau25_Trk1_eta2p1_v1_Prescl", &HLT_IsoMu18_eta2p1_MediumIsoPFTau25_Trk1_eta2p1_v1_Prescl, &b_HLT_IsoMu18_eta2p1_MediumIsoPFTau25_Trk1_eta2p1_v1_Prescl);
   fChain->SetBranchAddress("HLT_BTagMu_DiJet20_Mu5_v4_Prescl", &HLT_BTagMu_DiJet20_Mu5_v4_Prescl, &b_HLT_BTagMu_DiJet20_Mu5_v4_Prescl);
   fChain->SetBranchAddress("HLT_BTagMu_DiJet40_Mu5_v4_Prescl", &HLT_BTagMu_DiJet40_Mu5_v4_Prescl, &b_HLT_BTagMu_DiJet40_Mu5_v4_Prescl);
   fChain->SetBranchAddress("HLT_BTagMu_DiJet70_Mu5_v4_Prescl", &HLT_BTagMu_DiJet70_Mu5_v4_Prescl, &b_HLT_BTagMu_DiJet70_Mu5_v4_Prescl);
   fChain->SetBranchAddress("HLT_BTagMu_DiJet110_Mu5_v4_Prescl", &HLT_BTagMu_DiJet110_Mu5_v4_Prescl, &b_HLT_BTagMu_DiJet110_Mu5_v4_Prescl);
   fChain->SetBranchAddress("HLT_BTagMu_Jet300_Mu5_v4_Prescl", &HLT_BTagMu_Jet300_Mu5_v4_Prescl, &b_HLT_BTagMu_Jet300_Mu5_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu7_Ele7_CaloIdT_CaloIsoVL_v6_Prescl", &HLT_Mu7_Ele7_CaloIdT_CaloIsoVL_v6_Prescl, &b_HLT_Mu7_Ele7_CaloIdT_CaloIsoVL_v6_Prescl);
   fChain->SetBranchAddress("HLT_Mu8_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v8_Prescl", &HLT_Mu8_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v8_Prescl, &b_HLT_Mu8_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v8_Prescl);
   fChain->SetBranchAddress("HLT_Mu8_DiJet30_v5_Prescl", &HLT_Mu8_DiJet30_v5_Prescl, &b_HLT_Mu8_DiJet30_v5_Prescl);
   fChain->SetBranchAddress("HLT_Mu8_TriJet30_v5_Prescl", &HLT_Mu8_TriJet30_v5_Prescl, &b_HLT_Mu8_TriJet30_v5_Prescl);
   fChain->SetBranchAddress("HLT_Mu8_QuadJet30_v5_Prescl", &HLT_Mu8_QuadJet30_v5_Prescl, &b_HLT_Mu8_QuadJet30_v5_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu12_DoubleCentralJet65_v2_Prescl", &HLT_IsoMu12_DoubleCentralJet65_v2_Prescl, &b_HLT_IsoMu12_DoubleCentralJet65_v2_Prescl);
   fChain->SetBranchAddress("HLT_Mu15_eta2p1_L1ETM20_v4_Prescl", &HLT_Mu15_eta2p1_L1ETM20_v4_Prescl, &b_HLT_Mu15_eta2p1_L1ETM20_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu24_PFJet30_PFJet25_Deta3_CentralPFJet25_v2_Prescl", &HLT_Mu24_PFJet30_PFJet25_Deta3_CentralPFJet25_v2_Prescl, &b_HLT_Mu24_PFJet30_PFJet25_Deta3_CentralPFJet25_v2_Prescl);
   fChain->SetBranchAddress("HLT_Mu24_CentralPFJet30_CentralPFJet25_v2_Prescl", &HLT_Mu24_CentralPFJet30_CentralPFJet25_v2_Prescl, &b_HLT_Mu24_CentralPFJet30_CentralPFJet25_v2_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu24_PFJet30_PFJet25_Deta3_CentralPFJet25_v2_Prescl", &HLT_IsoMu24_PFJet30_PFJet25_Deta3_CentralPFJet25_v2_Prescl, &b_HLT_IsoMu24_PFJet30_PFJet25_Deta3_CentralPFJet25_v2_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu24_CentralPFJet30_CentralPFJet25_v2_Prescl", &HLT_IsoMu24_CentralPFJet30_CentralPFJet25_v2_Prescl, &b_HLT_IsoMu24_CentralPFJet30_CentralPFJet25_v2_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu24_CentralPFJet30_CentralPFJet25_PFMET20_v2_Prescl", &HLT_IsoMu24_CentralPFJet30_CentralPFJet25_PFMET20_v2_Prescl, &b_HLT_IsoMu24_CentralPFJet30_CentralPFJet25_PFMET20_v2_Prescl);
   fChain->SetBranchAddress("HLT_Ele32_WP80_PFJet30_PFJet25_Deta3_v2_Prescl", &HLT_Ele32_WP80_PFJet30_PFJet25_Deta3_v2_Prescl, &b_HLT_Ele32_WP80_PFJet30_PFJet25_Deta3_v2_Prescl);
   fChain->SetBranchAddress("HLT_Ele32_WP80_PFJet30_PFJet25_Deta3_CentralPFJet30_v2_Prescl", &HLT_Ele32_WP80_PFJet30_PFJet25_Deta3_CentralPFJet30_v2_Prescl, &b_HLT_Ele32_WP80_PFJet30_PFJet25_Deta3_CentralPFJet30_v2_Prescl);
   fChain->SetBranchAddress("HLT_Ele32_WP80_CentralPFJet35_CentralPFJet25_v2_Prescl", &HLT_Ele32_WP80_CentralPFJet35_CentralPFJet25_v2_Prescl, &b_HLT_Ele32_WP80_CentralPFJet35_CentralPFJet25_v2_Prescl);
   fChain->SetBranchAddress("HLT_Ele32_WP80_CentralPFJet35_CentralPFJet25_PFMET20_v2_Prescl", &HLT_Ele32_WP80_CentralPFJet35_CentralPFJet25_PFMET20_v2_Prescl, &b_HLT_Ele32_WP80_CentralPFJet35_CentralPFJet25_PFMET20_v2_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu17_eta2p1_CentralPFNoPUJet30_BTagIPIter_v2_Prescl", &HLT_IsoMu17_eta2p1_CentralPFNoPUJet30_BTagIPIter_v2_Prescl, &b_HLT_IsoMu17_eta2p1_CentralPFNoPUJet30_BTagIPIter_v2_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu17_eta2p1_CentralPFNoPUJet30_v2_Prescl", &HLT_IsoMu17_eta2p1_CentralPFNoPUJet30_v2_Prescl, &b_HLT_IsoMu17_eta2p1_CentralPFNoPUJet30_v2_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2_Prescl", &HLT_IsoMu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2_Prescl, &b_HLT_IsoMu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2_Prescl);
   fChain->SetBranchAddress("HLT_Mu17_eta2p1_CentralPFNoPUJet30_BTagIPIter_v2_Prescl", &HLT_Mu17_eta2p1_CentralPFNoPUJet30_BTagIPIter_v2_Prescl, &b_HLT_Mu17_eta2p1_CentralPFNoPUJet30_BTagIPIter_v2_Prescl);
   fChain->SetBranchAddress("HLT_Mu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2_Prescl", &HLT_Mu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2_Prescl, &b_HLT_Mu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu20_WCandPt80_v2_Prescl", &HLT_IsoMu20_WCandPt80_v2_Prescl, &b_HLT_IsoMu20_WCandPt80_v2_Prescl);
   fChain->SetBranchAddress("HLT_Mu17_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v8_Prescl", &HLT_Mu17_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v8_Prescl, &b_HLT_Mu17_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v8_Prescl);
   fChain->SetBranchAddress("HLT_Mu12_eta2p1_DiCentral_40_20_DiBTagIP3D1stTrack_v4_Prescl", &HLT_Mu12_eta2p1_DiCentral_40_20_DiBTagIP3D1stTrack_v4_Prescl, &b_HLT_Mu12_eta2p1_DiCentral_40_20_DiBTagIP3D1stTrack_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu12_eta2p1_DiCentral_40_20_BTagIP3D1stTrack_v4_Prescl", &HLT_Mu12_eta2p1_DiCentral_40_20_BTagIP3D1stTrack_v4_Prescl, &b_HLT_Mu12_eta2p1_DiCentral_40_20_BTagIP3D1stTrack_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu12_eta2p1_DiCentral_40_20_v4_Prescl", &HLT_Mu12_eta2p1_DiCentral_40_20_v4_Prescl, &b_HLT_Mu12_eta2p1_DiCentral_40_20_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu12_eta2p1_DiCentral_20_v4_Prescl", &HLT_Mu12_eta2p1_DiCentral_20_v4_Prescl, &b_HLT_Mu12_eta2p1_DiCentral_20_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu15_eta2p1_TriCentral_40_20_20_DiBTagIP3D1stTrack_v4_Prescl", &HLT_Mu15_eta2p1_TriCentral_40_20_20_DiBTagIP3D1stTrack_v4_Prescl, &b_HLT_Mu15_eta2p1_TriCentral_40_20_20_DiBTagIP3D1stTrack_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu15_eta2p1_TriCentral_40_20_20_BTagIP3D1stTrack_v4_Prescl", &HLT_Mu15_eta2p1_TriCentral_40_20_20_BTagIP3D1stTrack_v4_Prescl, &b_HLT_Mu15_eta2p1_TriCentral_40_20_20_BTagIP3D1stTrack_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu15_eta2p1_TriCentral_40_20_20_v4_Prescl", &HLT_Mu15_eta2p1_TriCentral_40_20_20_v4_Prescl, &b_HLT_Mu15_eta2p1_TriCentral_40_20_20_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu30_Ele30_CaloIdL_v7_Prescl", &HLT_Mu30_Ele30_CaloIdL_v7_Prescl, &b_HLT_Mu30_Ele30_CaloIdL_v7_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu17_eta2p1_DiCentralPFNoPUJet30_PFNoPUHT350_PFMHT40_v1_Prescl", &HLT_IsoMu17_eta2p1_DiCentralPFNoPUJet30_PFNoPUHT350_PFMHT40_v1_Prescl, &b_HLT_IsoMu17_eta2p1_DiCentralPFNoPUJet30_PFNoPUHT350_PFMHT40_v1_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu20_eta2p1_CentralPFJet80_v7_Prescl", &HLT_IsoMu20_eta2p1_CentralPFJet80_v7_Prescl, &b_HLT_IsoMu20_eta2p1_CentralPFJet80_v7_Prescl);
   fChain->SetBranchAddress("HLT_DoubleRelIso1p0Mu5_Mass8_PFNoPUHT175_v1_Prescl", &HLT_DoubleRelIso1p0Mu5_Mass8_PFNoPUHT175_v1_Prescl, &b_HLT_DoubleRelIso1p0Mu5_Mass8_PFNoPUHT175_v1_Prescl);
   fChain->SetBranchAddress("HLT_DoubleRelIso1p0Mu5_Mass8_PFNoPUHT225_v1_Prescl", &HLT_DoubleRelIso1p0Mu5_Mass8_PFNoPUHT225_v1_Prescl, &b_HLT_DoubleRelIso1p0Mu5_Mass8_PFNoPUHT225_v1_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMu8_Mass8_PFNoPUHT175_v1_Prescl", &HLT_DoubleMu8_Mass8_PFNoPUHT175_v1_Prescl, &b_HLT_DoubleMu8_Mass8_PFNoPUHT175_v1_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMu8_Mass8_PFNoPUHT225_v1_Prescl", &HLT_DoubleMu8_Mass8_PFNoPUHT225_v1_Prescl, &b_HLT_DoubleMu8_Mass8_PFNoPUHT225_v1_Prescl);
   fChain->SetBranchAddress("HLT_RelIso1p0Mu5_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1_Prescl", &HLT_RelIso1p0Mu5_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1_Prescl, &b_HLT_RelIso1p0Mu5_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1_Prescl);
   fChain->SetBranchAddress("HLT_RelIso1p0Mu5_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1_Prescl", &HLT_RelIso1p0Mu5_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1_Prescl, &b_HLT_RelIso1p0Mu5_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1_Prescl);
   fChain->SetBranchAddress("HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1_Prescl", &HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1_Prescl, &b_HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1_Prescl);
   fChain->SetBranchAddress("HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1_Prescl", &HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1_Prescl, &b_HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1_Prescl);
   fChain->SetBranchAddress("HLT_PFNoPUHT350_Mu15_PFMET45_v1_Prescl", &HLT_PFNoPUHT350_Mu15_PFMET45_v1_Prescl, &b_HLT_PFNoPUHT350_Mu15_PFMET45_v1_Prescl);
   fChain->SetBranchAddress("HLT_PFNoPUHT350_Mu15_PFMET50_v1_Prescl", &HLT_PFNoPUHT350_Mu15_PFMET50_v1_Prescl, &b_HLT_PFNoPUHT350_Mu15_PFMET50_v1_Prescl);
   fChain->SetBranchAddress("HLT_PFNoPUHT400_Mu5_PFMET45_v1_Prescl", &HLT_PFNoPUHT400_Mu5_PFMET45_v1_Prescl, &b_HLT_PFNoPUHT400_Mu5_PFMET45_v1_Prescl);
   fChain->SetBranchAddress("HLT_PFNoPUHT400_Mu5_PFMET50_v1_Prescl", &HLT_PFNoPUHT400_Mu5_PFMET50_v1_Prescl, &b_HLT_PFNoPUHT400_Mu5_PFMET50_v1_Prescl);
   fChain->SetBranchAddress("HLT_Mu40_PFNoPUHT350_v1_Prescl", &HLT_Mu40_PFNoPUHT350_v1_Prescl, &b_HLT_Mu40_PFNoPUHT350_v1_Prescl);
   fChain->SetBranchAddress("HLT_Mu60_PFNoPUHT350_v1_Prescl", &HLT_Mu60_PFNoPUHT350_v1_Prescl, &b_HLT_Mu60_PFNoPUHT350_v1_Prescl);
   fChain->SetBranchAddress("HLT_Mu40_HT200_v2_Prescl", &HLT_Mu40_HT200_v2_Prescl, &b_HLT_Mu40_HT200_v2_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMu5_Ele8_CaloIdT_TrkIdVL_v15_Prescl", &HLT_DoubleMu5_Ele8_CaloIdT_TrkIdVL_v15_Prescl, &b_HLT_DoubleMu5_Ele8_CaloIdT_TrkIdVL_v15_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMu8_Ele8_CaloIdT_TrkIdVL_v4_Prescl", &HLT_DoubleMu8_Ele8_CaloIdT_TrkIdVL_v4_Prescl, &b_HLT_DoubleMu8_Ele8_CaloIdT_TrkIdVL_v4_Prescl);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Jet30_v6_Prescl", &HLT_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Jet30_v6_Prescl, &b_HLT_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Jet30_v6_Prescl);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdT_TrkIdT_DiJet30_v16_Prescl", &HLT_Ele8_CaloIdT_TrkIdT_DiJet30_v16_Prescl, &b_HLT_Ele8_CaloIdT_TrkIdT_DiJet30_v16_Prescl);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdT_TrkIdT_TriJet30_v16_Prescl", &HLT_Ele8_CaloIdT_TrkIdT_TriJet30_v16_Prescl, &b_HLT_Ele8_CaloIdT_TrkIdT_TriJet30_v16_Prescl);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdT_TrkIdT_QuadJet30_v16_Prescl", &HLT_Ele8_CaloIdT_TrkIdT_QuadJet30_v16_Prescl, &b_HLT_Ele8_CaloIdT_TrkIdT_QuadJet30_v16_Prescl);
   fChain->SetBranchAddress("HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Jet30_v6_Prescl", &HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Jet30_v6_Prescl, &b_HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Jet30_v6_Prescl);
   fChain->SetBranchAddress("HLT_Ele25_CaloIdVT_TrkIdT_TriCentralPFNoPUJet30_30_20_v2_Prescl", &HLT_Ele25_CaloIdVT_TrkIdT_TriCentralPFNoPUJet30_30_20_v2_Prescl, &b_HLT_Ele25_CaloIdVT_TrkIdT_TriCentralPFNoPUJet30_30_20_v2_Prescl);
   fChain->SetBranchAddress("HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_CentralPFNoPUJet30_v6_Prescl", &HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_CentralPFNoPUJet30_v6_Prescl, &b_HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_CentralPFNoPUJet30_v6_Prescl);
   fChain->SetBranchAddress("HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2_Prescl", &HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2_Prescl, &b_HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2_Prescl);
   fChain->SetBranchAddress("HLT_Ele25_CaloIdVL_CaloIsoT_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2_Prescl", &HLT_Ele25_CaloIdVL_CaloIsoT_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2_Prescl, &b_HLT_Ele25_CaloIdVL_CaloIsoT_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2_Prescl);
   fChain->SetBranchAddress("HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_CentralPFNoPUJet30_BTagIPIter_v7_Prescl", &HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_CentralPFNoPUJet30_BTagIPIter_v7_Prescl, &b_HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_CentralPFNoPUJet30_BTagIPIter_v7_Prescl);
   fChain->SetBranchAddress("HLT_Ele27_WP80_CentralPFJet80_v7_Prescl", &HLT_Ele27_WP80_CentralPFJet80_v7_Prescl, &b_HLT_Ele27_WP80_CentralPFJet80_v7_Prescl);
   fChain->SetBranchAddress("HLT_Ele27_WP80_WCandPt80_v7_Prescl", &HLT_Ele27_WP80_WCandPt80_v7_Prescl, &b_HLT_Ele27_WP80_WCandPt80_v7_Prescl);
   fChain->SetBranchAddress("HLT_Ele30_CaloIdVT_TrkIdT_PFNoPUJet100_PFNoPUJet25_v6_Prescl", &HLT_Ele30_CaloIdVT_TrkIdT_PFNoPUJet100_PFNoPUJet25_v6_Prescl, &b_HLT_Ele30_CaloIdVT_TrkIdT_PFNoPUJet100_PFNoPUJet25_v6_Prescl);
   fChain->SetBranchAddress("HLT_Ele30_CaloIdVT_TrkIdT_PFNoPUJet150_PFNoPUJet25_v6_Prescl", &HLT_Ele30_CaloIdVT_TrkIdT_PFNoPUJet150_PFNoPUJet25_v6_Prescl, &b_HLT_Ele30_CaloIdVT_TrkIdT_PFNoPUJet150_PFNoPUJet25_v6_Prescl);
   fChain->SetBranchAddress("HLT_DoubleEle8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1_Prescl", &HLT_DoubleEle8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1_Prescl, &b_HLT_DoubleEle8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1_Prescl);
   fChain->SetBranchAddress("HLT_DoubleEle8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1_Prescl", &HLT_DoubleEle8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1_Prescl, &b_HLT_DoubleEle8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1_Prescl);
   fChain->SetBranchAddress("HLT_DoubleEle10_CaloIdL_TrkIdVL_Ele10_CaloIdT_TrkIdVL_v12_Prescl", &HLT_DoubleEle10_CaloIdL_TrkIdVL_Ele10_CaloIdT_TrkIdVL_v12_Prescl, &b_HLT_DoubleEle10_CaloIdL_TrkIdVL_Ele10_CaloIdT_TrkIdVL_v12_Prescl);
   fChain->SetBranchAddress("HLT_TripleEle10_CaloIdL_TrkIdVL_v18_Prescl", &HLT_TripleEle10_CaloIdL_TrkIdVL_v18_Prescl, &b_HLT_TripleEle10_CaloIdL_TrkIdVL_v18_Prescl);
   fChain->SetBranchAddress("HLT_RsqMR40_Rsq0p04_v4_Prescl", &HLT_RsqMR40_Rsq0p04_v4_Prescl, &b_HLT_RsqMR40_Rsq0p04_v4_Prescl);
   fChain->SetBranchAddress("HLT_RsqMR45_Rsq0p09_v3_Prescl", &HLT_RsqMR45_Rsq0p09_v3_Prescl, &b_HLT_RsqMR45_Rsq0p09_v3_Prescl);
   fChain->SetBranchAddress("HLT_RsqMR55_Rsq0p09_MR150_v4_Prescl", &HLT_RsqMR55_Rsq0p09_MR150_v4_Prescl, &b_HLT_RsqMR55_Rsq0p09_MR150_v4_Prescl);
   fChain->SetBranchAddress("HLT_RsqMR60_Rsq0p09_MR150_v4_Prescl", &HLT_RsqMR60_Rsq0p09_MR150_v4_Prescl, &b_HLT_RsqMR60_Rsq0p09_MR150_v4_Prescl);
   fChain->SetBranchAddress("HLT_RsqMR65_Rsq0p09_MR150_v3_Prescl", &HLT_RsqMR65_Rsq0p09_MR150_v3_Prescl, &b_HLT_RsqMR65_Rsq0p09_MR150_v3_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu12_RsqMR30_Rsq0p04_MR200_v2_Prescl", &HLT_IsoMu12_RsqMR30_Rsq0p04_MR200_v2_Prescl, &b_HLT_IsoMu12_RsqMR30_Rsq0p04_MR200_v2_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu12_RsqMR40_Rsq0p04_MR200_v2_Prescl", &HLT_IsoMu12_RsqMR40_Rsq0p04_MR200_v2_Prescl, &b_HLT_IsoMu12_RsqMR40_Rsq0p04_MR200_v2_Prescl);
   fChain->SetBranchAddress("HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_RsqMR30_Rsq0p04_MR200_v2_Prescl", &HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_RsqMR30_Rsq0p04_MR200_v2_Prescl, &b_HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_RsqMR30_Rsq0p04_MR200_v2_Prescl);
   fChain->SetBranchAddress("HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_RsqMR40_Rsq0p04_MR200_v2_Prescl", &HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_RsqMR40_Rsq0p04_MR200_v2_Prescl, &b_HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_RsqMR40_Rsq0p04_MR200_v2_Prescl);
   fChain->SetBranchAddress("HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_DoubleCentralJet65_v2_Prescl", &HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_DoubleCentralJet65_v2_Prescl, &b_HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_DoubleCentralJet65_v2_Prescl);
   fChain->SetBranchAddress("HLT_Photon40_CaloIdL_RsqMR35_Rsq0p09_MR150_v4_Prescl", &HLT_Photon40_CaloIdL_RsqMR35_Rsq0p09_MR150_v4_Prescl, &b_HLT_Photon40_CaloIdL_RsqMR35_Rsq0p09_MR150_v4_Prescl);
   fChain->SetBranchAddress("HLT_Photon40_CaloIdL_RsqMR40_Rsq0p09_MR150_v4_Prescl", &HLT_Photon40_CaloIdL_RsqMR40_Rsq0p09_MR150_v4_Prescl, &b_HLT_Photon40_CaloIdL_RsqMR40_Rsq0p09_MR150_v4_Prescl);
   fChain->SetBranchAddress("HLT_Photon40_CaloIdL_RsqMR45_Rsq0p09_MR150_v4_Prescl", &HLT_Photon40_CaloIdL_RsqMR45_Rsq0p09_MR150_v4_Prescl, &b_HLT_Photon40_CaloIdL_RsqMR45_Rsq0p09_MR150_v4_Prescl);
   fChain->SetBranchAddress("HLT_Photon40_CaloIdL_RsqMR50_Rsq0p09_MR150_v4_Prescl", &HLT_Photon40_CaloIdL_RsqMR50_Rsq0p09_MR150_v4_Prescl, &b_HLT_Photon40_CaloIdL_RsqMR50_Rsq0p09_MR150_v4_Prescl);
   fChain->SetBranchAddress("HLT_DoublePhoton40_CaloIdL_Rsq0p035_v4_Prescl", &HLT_DoublePhoton40_CaloIdL_Rsq0p035_v4_Prescl, &b_HLT_DoublePhoton40_CaloIdL_Rsq0p035_v4_Prescl);
   fChain->SetBranchAddress("HLT_DoublePhoton40_CaloIdL_Rsq0p06_v4_Prescl", &HLT_DoublePhoton40_CaloIdL_Rsq0p06_v4_Prescl, &b_HLT_DoublePhoton40_CaloIdL_Rsq0p06_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu22_Photon22_CaloIdL_v6_Prescl", &HLT_Mu22_Photon22_CaloIdL_v6_Prescl, &b_HLT_Mu22_Photon22_CaloIdL_v6_Prescl);
   fChain->SetBranchAddress("HLT_Mu8_DoubleEle8_CaloIdT_TrkIdVL_v6_Prescl", &HLT_Mu8_DoubleEle8_CaloIdT_TrkIdVL_v6_Prescl, &b_HLT_Mu8_DoubleEle8_CaloIdT_TrkIdVL_v6_Prescl);
   fChain->SetBranchAddress("HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Ele8_CaloIdL_TrkIdVL_v6_Prescl", &HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Ele8_CaloIdL_TrkIdVL_v6_Prescl, &b_HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Ele8_CaloIdL_TrkIdVL_v6_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMu14_Mass8_PFMET40_v6_Prescl", &HLT_DoubleMu14_Mass8_PFMET40_v6_Prescl, &b_HLT_DoubleMu14_Mass8_PFMET40_v6_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMu14_Mass8_PFMET50_v6_Prescl", &HLT_DoubleMu14_Mass8_PFMET50_v6_Prescl, &b_HLT_DoubleMu14_Mass8_PFMET50_v6_Prescl);
   fChain->SetBranchAddress("HLT_DoubleEle14_CaloIdT_TrkIdVL_Mass8_PFMET40_v6_Prescl", &HLT_DoubleEle14_CaloIdT_TrkIdVL_Mass8_PFMET40_v6_Prescl, &b_HLT_DoubleEle14_CaloIdT_TrkIdVL_Mass8_PFMET40_v6_Prescl);
   fChain->SetBranchAddress("HLT_DoubleEle14_CaloIdT_TrkIdVL_Mass8_PFMET50_v6_Prescl", &HLT_DoubleEle14_CaloIdT_TrkIdVL_Mass8_PFMET50_v6_Prescl, &b_HLT_DoubleEle14_CaloIdT_TrkIdVL_Mass8_PFMET50_v6_Prescl);
   fChain->SetBranchAddress("HLT_Mu14_Ele14_CaloIdT_TrkIdVL_Mass8_PFMET40_v6_Prescl", &HLT_Mu14_Ele14_CaloIdT_TrkIdVL_Mass8_PFMET40_v6_Prescl, &b_HLT_Mu14_Ele14_CaloIdT_TrkIdVL_Mass8_PFMET40_v6_Prescl);
   fChain->SetBranchAddress("HLT_Mu14_Ele14_CaloIdT_TrkIdVL_Mass8_PFMET50_v6_Prescl", &HLT_Mu14_Ele14_CaloIdT_TrkIdVL_Mass8_PFMET50_v6_Prescl, &b_HLT_Mu14_Ele14_CaloIdT_TrkIdVL_Mass8_PFMET50_v6_Prescl);
   fChain->SetBranchAddress("HLT_PFNoPUHT350_PFMET100_v1_Prescl", &HLT_PFNoPUHT350_PFMET100_v1_Prescl, &b_HLT_PFNoPUHT350_PFMET100_v1_Prescl);
   fChain->SetBranchAddress("HLT_PFNoPUHT400_PFMET100_v1_Prescl", &HLT_PFNoPUHT400_PFMET100_v1_Prescl, &b_HLT_PFNoPUHT400_PFMET100_v1_Prescl);
   fChain->SetBranchAddress("HLT_CleanPFNoPUHT350_Ele5_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET45_v1_Prescl", &HLT_CleanPFNoPUHT350_Ele5_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET45_v1_Prescl, &b_HLT_CleanPFNoPUHT350_Ele5_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET45_v1_Prescl);
   fChain->SetBranchAddress("HLT_CleanPFNoPUHT350_Ele5_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET50_v1_Prescl", &HLT_CleanPFNoPUHT350_Ele5_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET50_v1_Prescl, &b_HLT_CleanPFNoPUHT350_Ele5_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET50_v1_Prescl);
   fChain->SetBranchAddress("HLT_CleanPFNoPUHT300_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET45_v1_Prescl", &HLT_CleanPFNoPUHT300_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET45_v1_Prescl, &b_HLT_CleanPFNoPUHT300_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET45_v1_Prescl);
   fChain->SetBranchAddress("HLT_CleanPFNoPUHT300_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET50_v1_Prescl", &HLT_CleanPFNoPUHT300_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET50_v1_Prescl, &b_HLT_CleanPFNoPUHT300_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET50_v1_Prescl);
   fChain->SetBranchAddress("HLT_CleanPFNoPUHT300_Ele40_CaloIdVT_TrkIdT_v1_Prescl", &HLT_CleanPFNoPUHT300_Ele40_CaloIdVT_TrkIdT_v1_Prescl, &b_HLT_CleanPFNoPUHT300_Ele40_CaloIdVT_TrkIdT_v1_Prescl);
   fChain->SetBranchAddress("HLT_CleanPFNoPUHT300_Ele60_CaloIdVT_TrkIdT_v1_Prescl", &HLT_CleanPFNoPUHT300_Ele60_CaloIdVT_TrkIdT_v1_Prescl, &b_HLT_CleanPFNoPUHT300_Ele60_CaloIdVT_TrkIdT_v1_Prescl);
   fChain->SetBranchAddress("HLT_Ele5_SC5_Jpsi_Mass2to15_v4_Prescl", &HLT_Ele5_SC5_Jpsi_Mass2to15_v4_Prescl, &b_HLT_Ele5_SC5_Jpsi_Mass2to15_v4_Prescl);
   fChain->SetBranchAddress("HLT_DiJet35_MJJ650_AllJets_DEta3p5_VBF_v2_Prescl", &HLT_DiJet35_MJJ650_AllJets_DEta3p5_VBF_v2_Prescl, &b_HLT_DiJet35_MJJ650_AllJets_DEta3p5_VBF_v2_Prescl);
   fChain->SetBranchAddress("HLT_DiJet35_MJJ700_AllJets_DEta3p5_VBF_v2_Prescl", &HLT_DiJet35_MJJ700_AllJets_DEta3p5_VBF_v2_Prescl, &b_HLT_DiJet35_MJJ700_AllJets_DEta3p5_VBF_v2_Prescl);
   fChain->SetBranchAddress("HLT_DiJet35_MJJ750_AllJets_DEta3p5_VBF_v2_Prescl", &HLT_DiJet35_MJJ750_AllJets_DEta3p5_VBF_v2_Prescl, &b_HLT_DiJet35_MJJ750_AllJets_DEta3p5_VBF_v2_Prescl);
   fChain->SetBranchAddress("HLT_Ele22_eta2p1_WP90Rho_LooseIsoPFTau20_v3_Prescl", &HLT_Ele22_eta2p1_WP90Rho_LooseIsoPFTau20_v3_Prescl, &b_HLT_Ele22_eta2p1_WP90Rho_LooseIsoPFTau20_v3_Prescl);
   fChain->SetBranchAddress("HLT_Ele22_eta2p1_WP90NoIso_LooseIsoPFTau20_v3_Prescl", &HLT_Ele22_eta2p1_WP90NoIso_LooseIsoPFTau20_v3_Prescl, &b_HLT_Ele22_eta2p1_WP90NoIso_LooseIsoPFTau20_v3_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v3_Prescl", &HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v3_Prescl, &b_HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v3_Prescl);
   fChain->SetBranchAddress("HLT_Mu17_eta2p1_LooseIsoPFTau20_v3_Prescl", &HLT_Mu17_eta2p1_LooseIsoPFTau20_v3_Prescl, &b_HLT_Mu17_eta2p1_LooseIsoPFTau20_v3_Prescl);
   fChain->SetBranchAddress("HLT_PixelTracks_Multiplicity70_v3_Prescl", &HLT_PixelTracks_Multiplicity70_v3_Prescl, &b_HLT_PixelTracks_Multiplicity70_v3_Prescl);
   fChain->SetBranchAddress("HLT_PixelTracks_Multiplicity80_v12_Prescl", &HLT_PixelTracks_Multiplicity80_v12_Prescl, &b_HLT_PixelTracks_Multiplicity80_v12_Prescl);
   fChain->SetBranchAddress("HLT_PixelTracks_Multiplicity90_v3_Prescl", &HLT_PixelTracks_Multiplicity90_v3_Prescl, &b_HLT_PixelTracks_Multiplicity90_v3_Prescl);
   fChain->SetBranchAddress("HLT_BeamGas_HF_Beam1_v5_Prescl", &HLT_BeamGas_HF_Beam1_v5_Prescl, &b_HLT_BeamGas_HF_Beam1_v5_Prescl);
   fChain->SetBranchAddress("HLT_BeamGas_HF_Beam2_v5_Prescl", &HLT_BeamGas_HF_Beam2_v5_Prescl, &b_HLT_BeamGas_HF_Beam2_v5_Prescl);
   fChain->SetBranchAddress("HLT_BeamHalo_v13_Prescl", &HLT_BeamHalo_v13_Prescl, &b_HLT_BeamHalo_v13_Prescl);
   fChain->SetBranchAddress("HLT_IsoTrackHE_v15_Prescl", &HLT_IsoTrackHE_v15_Prescl, &b_HLT_IsoTrackHE_v15_Prescl);
   fChain->SetBranchAddress("HLT_IsoTrackHB_v14_Prescl", &HLT_IsoTrackHB_v14_Prescl, &b_HLT_IsoTrackHB_v14_Prescl);
   fChain->SetBranchAddress("HLT_HcalPhiSym_v11_Prescl", &HLT_HcalPhiSym_v11_Prescl, &b_HLT_HcalPhiSym_v11_Prescl);
   fChain->SetBranchAddress("HLT_HcalNZS_v10_Prescl", &HLT_HcalNZS_v10_Prescl, &b_HLT_HcalNZS_v10_Prescl);
   fChain->SetBranchAddress("HLT_GlobalRunHPDNoise_v8_Prescl", &HLT_GlobalRunHPDNoise_v8_Prescl, &b_HLT_GlobalRunHPDNoise_v8_Prescl);
   fChain->SetBranchAddress("HLT_L1Tech_HBHEHO_totalOR_v6_Prescl", &HLT_L1Tech_HBHEHO_totalOR_v6_Prescl, &b_HLT_L1Tech_HBHEHO_totalOR_v6_Prescl);
   fChain->SetBranchAddress("HLT_L1Tech_HCAL_HF_single_channel_v4_Prescl", &HLT_L1Tech_HCAL_HF_single_channel_v4_Prescl, &b_HLT_L1Tech_HCAL_HF_single_channel_v4_Prescl);
   fChain->SetBranchAddress("HLT_ZeroBias_v7_Prescl", &HLT_ZeroBias_v7_Prescl, &b_HLT_ZeroBias_v7_Prescl);
   fChain->SetBranchAddress("HLT_ZeroBiasPixel_DoubleTrack_v2_Prescl", &HLT_ZeroBiasPixel_DoubleTrack_v2_Prescl, &b_HLT_ZeroBiasPixel_DoubleTrack_v2_Prescl);
   fChain->SetBranchAddress("HLT_Physics_v5_Prescl", &HLT_Physics_v5_Prescl, &b_HLT_Physics_v5_Prescl);
   fChain->SetBranchAddress("HLT_DTCalibration_v2_Prescl", &HLT_DTCalibration_v2_Prescl, &b_HLT_DTCalibration_v2_Prescl);
   fChain->SetBranchAddress("HLT_EcalCalibration_v3_Prescl", &HLT_EcalCalibration_v3_Prescl, &b_HLT_EcalCalibration_v3_Prescl);
   fChain->SetBranchAddress("HLT_HcalCalibration_v3_Prescl", &HLT_HcalCalibration_v3_Prescl, &b_HLT_HcalCalibration_v3_Prescl);
   fChain->SetBranchAddress("HLT_TrackerCalibration_v3_Prescl", &HLT_TrackerCalibration_v3_Prescl, &b_HLT_TrackerCalibration_v3_Prescl);
   fChain->SetBranchAddress("HLT_Random_v2_Prescl", &HLT_Random_v2_Prescl, &b_HLT_Random_v2_Prescl);
   fChain->SetBranchAddress("HLT_L1SingleMuOpen_AntiBPTX_v7_Prescl", &HLT_L1SingleMuOpen_AntiBPTX_v7_Prescl, &b_HLT_L1SingleMuOpen_AntiBPTX_v7_Prescl);
   fChain->SetBranchAddress("HLT_L1TrackerCosmics_v7_Prescl", &HLT_L1TrackerCosmics_v7_Prescl, &b_HLT_L1TrackerCosmics_v7_Prescl);
   fChain->SetBranchAddress("HLT_LogMonitor_v3_Prescl", &HLT_LogMonitor_v3_Prescl, &b_HLT_LogMonitor_v3_Prescl);
   fChain->SetBranchAddress("HLT_DTErrors_v3_Prescl", &HLT_DTErrors_v3_Prescl, &b_HLT_DTErrors_v3_Prescl);
   fChain->SetBranchAddress("HLT_L1DoubleJet36Central_v7_Prescl", &HLT_L1DoubleJet36Central_v7_Prescl, &b_HLT_L1DoubleJet36Central_v7_Prescl);
   fChain->SetBranchAddress("AlCa_EcalPi0EBonly_v6_Prescl", &AlCa_EcalPi0EBonly_v6_Prescl, &b_AlCa_EcalPi0EBonly_v6_Prescl);
   fChain->SetBranchAddress("AlCa_EcalPi0EEonly_v6_Prescl", &AlCa_EcalPi0EEonly_v6_Prescl, &b_AlCa_EcalPi0EEonly_v6_Prescl);
   fChain->SetBranchAddress("AlCa_EcalEtaEBonly_v6_Prescl", &AlCa_EcalEtaEBonly_v6_Prescl, &b_AlCa_EcalEtaEBonly_v6_Prescl);
   fChain->SetBranchAddress("AlCa_EcalEtaEEonly_v6_Prescl", &AlCa_EcalEtaEEonly_v6_Prescl, &b_AlCa_EcalEtaEEonly_v6_Prescl);
   fChain->SetBranchAddress("AlCa_EcalPhiSym_v13_Prescl", &AlCa_EcalPhiSym_v13_Prescl, &b_AlCa_EcalPhiSym_v13_Prescl);
   fChain->SetBranchAddress("AlCa_RPCMuonNoTriggers_v9_Prescl", &AlCa_RPCMuonNoTriggers_v9_Prescl, &b_AlCa_RPCMuonNoTriggers_v9_Prescl);
   fChain->SetBranchAddress("AlCa_RPCMuonNoHits_v9_Prescl", &AlCa_RPCMuonNoHits_v9_Prescl, &b_AlCa_RPCMuonNoHits_v9_Prescl);
   fChain->SetBranchAddress("AlCa_RPCMuonNormalisation_v9_Prescl", &AlCa_RPCMuonNormalisation_v9_Prescl, &b_AlCa_RPCMuonNormalisation_v9_Prescl);
   fChain->SetBranchAddress("AlCa_LumiPixels_v7_Prescl", &AlCa_LumiPixels_v7_Prescl, &b_AlCa_LumiPixels_v7_Prescl);
   fChain->SetBranchAddress("AlCa_LumiPixels_ZeroBias_v4_Prescl", &AlCa_LumiPixels_ZeroBias_v4_Prescl, &b_AlCa_LumiPixels_ZeroBias_v4_Prescl);
   fChain->SetBranchAddress("AlCa_LumiPixels_Random_v1_Prescl", &AlCa_LumiPixels_Random_v1_Prescl, &b_AlCa_LumiPixels_Random_v1_Prescl);
   fChain->SetBranchAddress("HLT_Activity_Ecal_SC7_v13_Prescl", &HLT_Activity_Ecal_SC7_v13_Prescl, &b_HLT_Activity_Ecal_SC7_v13_Prescl);
   fChain->SetBranchAddress("HLT_L1SingleJet16_v7_Prescl", &HLT_L1SingleJet16_v7_Prescl, &b_HLT_L1SingleJet16_v7_Prescl);
   fChain->SetBranchAddress("HLT_L1SingleJet36_v7_Prescl", &HLT_L1SingleJet36_v7_Prescl, &b_HLT_L1SingleJet36_v7_Prescl);






   //
   /* Also associate with the maps to speed up code! */
   // Autogenerated L1 - SetBranchAddressMaps 
  fChain->SetBranchAddress("L1_SingleJet20_Central_NotBptxOR", &map_BitOfStandardHLTPath["L1_SingleJet20_Central_NotBptxOR"], &b_L1_SingleJet20_Central_NotBptxOR);
  fChain->SetBranchAddress("L1_SingleJet16_FwdVeto5", &map_BitOfStandardHLTPath["L1_SingleJet16_FwdVeto5"], &b_L1_SingleJet16_FwdVeto5);
  fChain->SetBranchAddress("L1_ETT80", &map_BitOfStandardHLTPath["L1_ETT80"], &b_L1_ETT80);
  fChain->SetBranchAddress("L1_DoubleForJet16_EtaOpp", &map_BitOfStandardHLTPath["L1_DoubleForJet16_EtaOpp"], &b_L1_DoubleForJet16_EtaOpp);
  fChain->SetBranchAddress("L1_DoubleMu0_HighQ_EtaCuts", &map_BitOfStandardHLTPath["L1_DoubleMu0_HighQ_EtaCuts"], &b_L1_DoubleMu0_HighQ_EtaCuts);
  fChain->SetBranchAddress("L1_DoubleEG3_FwdVeto", &map_BitOfStandardHLTPath["L1_DoubleEG3_FwdVeto"], &b_L1_DoubleEG3_FwdVeto);
  fChain->SetBranchAddress("L1_SingleForJet16", &map_BitOfStandardHLTPath["L1_SingleForJet16"], &b_L1_SingleForJet16);
  fChain->SetBranchAddress("L1_DoubleMu_5er_0er_HighQ_WdEta22", &map_BitOfStandardHLTPath["L1_DoubleMu_5er_0er_HighQ_WdEta22"], &b_L1_DoubleMu_5er_0er_HighQ_WdEta22);
  fChain->SetBranchAddress("L1_DoubleMu3er_HighQ_WdEta22", &map_BitOfStandardHLTPath["L1_DoubleMu3er_HighQ_WdEta22"], &b_L1_DoubleMu3er_HighQ_WdEta22);
  fChain->SetBranchAddress("L1_BeamHalo", &map_BitOfStandardHLTPath["L1_BeamHalo"], &b_L1_BeamHalo);
  fChain->SetBranchAddress("L1_InterBunch_Bptx", &map_BitOfStandardHLTPath["L1_InterBunch_Bptx"], &b_L1_InterBunch_Bptx);
  fChain->SetBranchAddress("L1_BeamGas_Hf_BptxPlusPostQuiet", &map_BitOfStandardHLTPath["L1_BeamGas_Hf_BptxPlusPostQuiet"], &b_L1_BeamGas_Hf_BptxPlusPostQuiet);
  fChain->SetBranchAddress("L1_BeamGas_Hf_BptxMinusPostQuiet", &map_BitOfStandardHLTPath["L1_BeamGas_Hf_BptxMinusPostQuiet"], &b_L1_BeamGas_Hf_BptxMinusPostQuiet);
  fChain->SetBranchAddress("L1_ZeroBias_Instance1", &map_BitOfStandardHLTPath["L1_ZeroBias_Instance1"], &b_L1_ZeroBias_Instance1);
  fChain->SetBranchAddress("L1_SingleMu6_NotBptxOR", &map_BitOfStandardHLTPath["L1_SingleMu6_NotBptxOR"], &b_L1_SingleMu6_NotBptxOR);
  fChain->SetBranchAddress("L1_SingleJetC20_NotBptxOR", &map_BitOfStandardHLTPath["L1_SingleJetC20_NotBptxOR"], &b_L1_SingleJetC20_NotBptxOR);
  fChain->SetBranchAddress("L1_SingleJetC32_NotBptxOR", &map_BitOfStandardHLTPath["L1_SingleJetC32_NotBptxOR"], &b_L1_SingleJetC32_NotBptxOR);
  fChain->SetBranchAddress("L1_TripleMu_5_5_0", &map_BitOfStandardHLTPath["L1_TripleMu_5_5_0"], &b_L1_TripleMu_5_5_0);
  fChain->SetBranchAddress("L1_TripleMu0_HighQ", &map_BitOfStandardHLTPath["L1_TripleMu0_HighQ"], &b_L1_TripleMu0_HighQ);
  fChain->SetBranchAddress("L1_DoubleMu_10_3p5", &map_BitOfStandardHLTPath["L1_DoubleMu_10_3p5"], &b_L1_DoubleMu_10_3p5);
  fChain->SetBranchAddress("L1_DoubleMu_12_5", &map_BitOfStandardHLTPath["L1_DoubleMu_12_5"], &b_L1_DoubleMu_12_5);
  fChain->SetBranchAddress("L1_DoubleMuHighQ_5_0_Eta2p1_WdEta22", &map_BitOfStandardHLTPath["L1_DoubleMuHighQ_5_0_Eta2p1_WdEta22"], &b_L1_DoubleMuHighQ_5_0_Eta2p1_WdEta22);
  fChain->SetBranchAddress("L1_DoubleMuHighQ_3_3_Eta2p1_WdEta22", &map_BitOfStandardHLTPath["L1_DoubleMuHighQ_3_3_Eta2p1_WdEta22"], &b_L1_DoubleMuHighQ_3_3_Eta2p1_WdEta22);
  fChain->SetBranchAddress("L1_DoubleMu0er_HighQ", &map_BitOfStandardHLTPath["L1_DoubleMu0er_HighQ"], &b_L1_DoubleMu0er_HighQ);
  fChain->SetBranchAddress("L1_SingleMu25er", &map_BitOfStandardHLTPath["L1_SingleMu25er"], &b_L1_SingleMu25er);
  fChain->SetBranchAddress("L1_SingleMu20er", &map_BitOfStandardHLTPath["L1_SingleMu20er"], &b_L1_SingleMu20er);
  fChain->SetBranchAddress("L1_SingleMu18er", &map_BitOfStandardHLTPath["L1_SingleMu18er"], &b_L1_SingleMu18er);
  fChain->SetBranchAddress("L1_SingleMu16er", &map_BitOfStandardHLTPath["L1_SingleMu16er"], &b_L1_SingleMu16er);
  fChain->SetBranchAddress("L1_SingleMu14er", &map_BitOfStandardHLTPath["L1_SingleMu14er"], &b_L1_SingleMu14er);
  fChain->SetBranchAddress("L1_DoubleJetC44_ETM30", &map_BitOfStandardHLTPath["L1_DoubleJetC44_ETM30"], &b_L1_DoubleJetC44_ETM30);
  fChain->SetBranchAddress("L1_DoubleJetC36_ETM30", &map_BitOfStandardHLTPath["L1_DoubleJetC36_ETM30"], &b_L1_DoubleJetC36_ETM30);
  fChain->SetBranchAddress("L1_Mu5_DoubleEG6", &map_BitOfStandardHLTPath["L1_Mu5_DoubleEG6"], &b_L1_Mu5_DoubleEG6);
  fChain->SetBranchAddress("L1_Mu5_DoubleEG5", &map_BitOfStandardHLTPath["L1_Mu5_DoubleEG5"], &b_L1_Mu5_DoubleEG5);
  fChain->SetBranchAddress("L1_DoubleMu5_EG5", &map_BitOfStandardHLTPath["L1_DoubleMu5_EG5"], &b_L1_DoubleMu5_EG5);
  fChain->SetBranchAddress("L1_DoubleMu3p5_EG5", &map_BitOfStandardHLTPath["L1_DoubleMu3p5_EG5"], &b_L1_DoubleMu3p5_EG5);
  fChain->SetBranchAddress("L1_Mu3p5_EG12", &map_BitOfStandardHLTPath["L1_Mu3p5_EG12"], &b_L1_Mu3p5_EG12);
  fChain->SetBranchAddress("L1_Mu12_EG7", &map_BitOfStandardHLTPath["L1_Mu12_EG7"], &b_L1_Mu12_EG7);
  fChain->SetBranchAddress("L1_EG8_DoubleJetC20", &map_BitOfStandardHLTPath["L1_EG8_DoubleJetC20"], &b_L1_EG8_DoubleJetC20);
  fChain->SetBranchAddress("L1_EG18er_JetC_Cen36_Tau28_dPhi1", &map_BitOfStandardHLTPath["L1_EG18er_JetC_Cen36_Tau28_dPhi1"], &b_L1_EG18er_JetC_Cen36_Tau28_dPhi1);
  fChain->SetBranchAddress("L1_IsoEG18er_JetC_Cen36_Tau28_dPhi1", &map_BitOfStandardHLTPath["L1_IsoEG18er_JetC_Cen36_Tau28_dPhi1"], &b_L1_IsoEG18er_JetC_Cen36_Tau28_dPhi1);
  fChain->SetBranchAddress("L1_IsoEG18er_JetC_Cen32_Tau24_dPhi1", &map_BitOfStandardHLTPath["L1_IsoEG18er_JetC_Cen32_Tau24_dPhi1"], &b_L1_IsoEG18er_JetC_Cen32_Tau24_dPhi1);
  fChain->SetBranchAddress("L1_EG18er_JetC_Cen28_Tau20_dPhi1", &map_BitOfStandardHLTPath["L1_EG18er_JetC_Cen28_Tau20_dPhi1"], &b_L1_EG18er_JetC_Cen28_Tau20_dPhi1);
  fChain->SetBranchAddress("L1_DoubleEG6_HTT125", &map_BitOfStandardHLTPath["L1_DoubleEG6_HTT125"], &b_L1_DoubleEG6_HTT125);
  fChain->SetBranchAddress("L1_DoubleEG6_HTT100", &map_BitOfStandardHLTPath["L1_DoubleEG6_HTT100"], &b_L1_DoubleEG6_HTT100);
  fChain->SetBranchAddress("L1_EG22_ForJet32", &map_BitOfStandardHLTPath["L1_EG22_ForJet32"], &b_L1_EG22_ForJet32);
  fChain->SetBranchAddress("L1_EG22_ForJet24", &map_BitOfStandardHLTPath["L1_EG22_ForJet24"], &b_L1_EG22_ForJet24);
  fChain->SetBranchAddress("L1_Mu8_DoubleJetC20", &map_BitOfStandardHLTPath["L1_Mu8_DoubleJetC20"], &b_L1_Mu8_DoubleJetC20);
  fChain->SetBranchAddress("L1_Mu10er_JetC12_WdEtaPhi1_DoubleJetC_32_12", &map_BitOfStandardHLTPath["L1_Mu10er_JetC12_WdEtaPhi1_DoubleJetC_32_12"], &b_L1_Mu10er_JetC12_WdEtaPhi1_DoubleJetC_32_12);
  fChain->SetBranchAddress("L1_Mu10er_JetC32", &map_BitOfStandardHLTPath["L1_Mu10er_JetC32"], &b_L1_Mu10er_JetC32);
  fChain->SetBranchAddress("L1_Mu10er_JetC12_WdEtaPhi1_DoubleJetC_20_12", &map_BitOfStandardHLTPath["L1_Mu10er_JetC12_WdEtaPhi1_DoubleJetC_20_12"], &b_L1_Mu10er_JetC12_WdEtaPhi1_DoubleJetC_20_12);
  fChain->SetBranchAddress("L1_Mu12er_ETM20", &map_BitOfStandardHLTPath["L1_Mu12er_ETM20"], &b_L1_Mu12er_ETM20);
  fChain->SetBranchAddress("L1_Mu4_HTT125", &map_BitOfStandardHLTPath["L1_Mu4_HTT125"], &b_L1_Mu4_HTT125);
  fChain->SetBranchAddress("L1_Mu0_HTT100", &map_BitOfStandardHLTPath["L1_Mu0_HTT100"], &b_L1_Mu0_HTT100);
  fChain->SetBranchAddress("L1_DoubleTauJet44er", &map_BitOfStandardHLTPath["L1_DoubleTauJet44er"], &b_L1_DoubleTauJet44er);
  fChain->SetBranchAddress("L1_QuadJetC40", &map_BitOfStandardHLTPath["L1_QuadJetC40"], &b_L1_QuadJetC40);
  fChain->SetBranchAddress("L1_QuadJetC36", &map_BitOfStandardHLTPath["L1_QuadJetC36"], &b_L1_QuadJetC36);
  fChain->SetBranchAddress("L1_QuadJetC32", &map_BitOfStandardHLTPath["L1_QuadJetC32"], &b_L1_QuadJetC32);
  fChain->SetBranchAddress("L1_TripleJetC_52_28_28", &map_BitOfStandardHLTPath["L1_TripleJetC_52_28_28"], &b_L1_TripleJetC_52_28_28);
  fChain->SetBranchAddress("L1_TripleJet_68_48_32_VBF", &map_BitOfStandardHLTPath["L1_TripleJet_68_48_32_VBF"], &b_L1_TripleJet_68_48_32_VBF);
  fChain->SetBranchAddress("L1_TripleJet_64_48_28_VBF", &map_BitOfStandardHLTPath["L1_TripleJet_64_48_28_VBF"], &b_L1_TripleJet_64_48_28_VBF);
  fChain->SetBranchAddress("L1_TripleJet_64_44_24_VBF", &map_BitOfStandardHLTPath["L1_TripleJet_64_44_24_VBF"], &b_L1_TripleJet_64_44_24_VBF);
  fChain->SetBranchAddress("L1_DoubleJetC64", &map_BitOfStandardHLTPath["L1_DoubleJetC64"], &b_L1_DoubleJetC64);
  fChain->SetBranchAddress("L1_DoubleJetC56", &map_BitOfStandardHLTPath["L1_DoubleJetC56"], &b_L1_DoubleJetC56);
  fChain->SetBranchAddress("L1_DoubleJetC56_Eta1p74_WdEta4", &map_BitOfStandardHLTPath["L1_DoubleJetC56_Eta1p74_WdEta4"], &b_L1_DoubleJetC56_Eta1p74_WdEta4);
  fChain->SetBranchAddress("L1_DoubleJetC52", &map_BitOfStandardHLTPath["L1_DoubleJetC52"], &b_L1_DoubleJetC52);
  fChain->SetBranchAddress("L1_DoubleJetC44_Eta1p74_WdEta4", &map_BitOfStandardHLTPath["L1_DoubleJetC44_Eta1p74_WdEta4"], &b_L1_DoubleJetC44_Eta1p74_WdEta4);
  fChain->SetBranchAddress("L1_DoubleJetC36", &map_BitOfStandardHLTPath["L1_DoubleJetC36"], &b_L1_DoubleJetC36);
  fChain->SetBranchAddress("L1_TripleEG_12_7_5", &map_BitOfStandardHLTPath["L1_TripleEG_12_7_5"], &b_L1_TripleEG_12_7_5);
  fChain->SetBranchAddress("L1_DoubleEG_13_7", &map_BitOfStandardHLTPath["L1_DoubleEG_13_7"], &b_L1_DoubleEG_13_7);
  fChain->SetBranchAddress("L1_SingleEG24", &map_BitOfStandardHLTPath["L1_SingleEG24"], &b_L1_SingleEG24);
  fChain->SetBranchAddress("L1_SingleEG22", &map_BitOfStandardHLTPath["L1_SingleEG22"], &b_L1_SingleEG22);
  fChain->SetBranchAddress("L1_SingleIsoEG20er", &map_BitOfStandardHLTPath["L1_SingleIsoEG20er"], &b_L1_SingleIsoEG20er);
  fChain->SetBranchAddress("L1_SingleIsoEG18er", &map_BitOfStandardHLTPath["L1_SingleIsoEG18er"], &b_L1_SingleIsoEG18er);
  fChain->SetBranchAddress("L1_SingleEG18er", &map_BitOfStandardHLTPath["L1_SingleEG18er"], &b_L1_SingleEG18er);
  fChain->SetBranchAddress("L1_SingleEG7", &map_BitOfStandardHLTPath["L1_SingleEG7"], &b_L1_SingleEG7);
  fChain->SetBranchAddress("L1_ETT300", &map_BitOfStandardHLTPath["L1_ETT300"], &b_L1_ETT300);
  fChain->SetBranchAddress("L1_HTT175", &map_BitOfStandardHLTPath["L1_HTT175"], &b_L1_HTT175);
  fChain->SetBranchAddress("L1_HTT150", &map_BitOfStandardHLTPath["L1_HTT150"], &b_L1_HTT150);
  fChain->SetBranchAddress("L1_HTT125", &map_BitOfStandardHLTPath["L1_HTT125"], &b_L1_HTT125);
  fChain->SetBranchAddress("L1_ETM100", &map_BitOfStandardHLTPath["L1_ETM100"], &b_L1_ETM100);
  fChain->SetBranchAddress("L1_ETM50", &map_BitOfStandardHLTPath["L1_ETM50"], &b_L1_ETM50);
  fChain->SetBranchAddress("L1_ETM36", &map_BitOfStandardHLTPath["L1_ETM36"], &b_L1_ETM36);
  fChain->SetBranchAddress("L1_QuadJet28_Central", &map_BitOfStandardHLTPath["L1_QuadJet28_Central"], &b_L1_QuadJet28_Central);
  fChain->SetBranchAddress("L1_SingleJet128", &map_BitOfStandardHLTPath["L1_SingleJet128"], &b_L1_SingleJet128);
  fChain->SetBranchAddress("L1_DoubleMu_10_Open", &map_BitOfStandardHLTPath["L1_DoubleMu_10_Open"], &b_L1_DoubleMu_10_Open);
  fChain->SetBranchAddress("L1_SingleEG18", &map_BitOfStandardHLTPath["L1_SingleEG18"], &b_L1_SingleEG18);
  fChain->SetBranchAddress("L1_Mu10_Eta2p1_DoubleJet_16_8_Central", &map_BitOfStandardHLTPath["L1_Mu10_Eta2p1_DoubleJet_16_8_Central"], &b_L1_Mu10_Eta2p1_DoubleJet_16_8_Central);
  fChain->SetBranchAddress("L1_Mu12_EG5", &map_BitOfStandardHLTPath["L1_Mu12_EG5"], &b_L1_Mu12_EG5);
  fChain->SetBranchAddress("L1_SingleMu16_Eta2p1", &map_BitOfStandardHLTPath["L1_SingleMu16_Eta2p1"], &b_L1_SingleMu16_Eta2p1);
  fChain->SetBranchAddress("L1_DoubleMu0_HighQ", &map_BitOfStandardHLTPath["L1_DoubleMu0_HighQ"], &b_L1_DoubleMu0_HighQ);
  fChain->SetBranchAddress("L1_SingleMu14_Eta2p1", &map_BitOfStandardHLTPath["L1_SingleMu14_Eta2p1"], &b_L1_SingleMu14_Eta2p1);
  fChain->SetBranchAddress("L1_HTT50_HTM30", &map_BitOfStandardHLTPath["L1_HTT50_HTM30"], &b_L1_HTT50_HTM30);
  fChain->SetBranchAddress("L1_DoubleEG5_HTT75", &map_BitOfStandardHLTPath["L1_DoubleEG5_HTT75"], &b_L1_DoubleEG5_HTT75);
  fChain->SetBranchAddress("L1_DoubleJet64_Central", &map_BitOfStandardHLTPath["L1_DoubleJet64_Central"], &b_L1_DoubleJet64_Central);
  fChain->SetBranchAddress("L1_DoubleTauJet44_Eta2p17", &map_BitOfStandardHLTPath["L1_DoubleTauJet44_Eta2p17"], &b_L1_DoubleTauJet44_Eta2p17);
  fChain->SetBranchAddress("L1_TripleJet_36_36_12_Central", &map_BitOfStandardHLTPath["L1_TripleJet_36_36_12_Central"], &b_L1_TripleJet_36_36_12_Central);
  fChain->SetBranchAddress("L1_EG5_HTT100", &map_BitOfStandardHLTPath["L1_EG5_HTT100"], &b_L1_EG5_HTT100);
  fChain->SetBranchAddress("L1_EG5_DoubleJet20_Central", &map_BitOfStandardHLTPath["L1_EG5_DoubleJet20_Central"], &b_L1_EG5_DoubleJet20_Central);
  fChain->SetBranchAddress("L1_TripleMu0", &map_BitOfStandardHLTPath["L1_TripleMu0"], &b_L1_TripleMu0);
  fChain->SetBranchAddress("L1_DoubleMu3p5", &map_BitOfStandardHLTPath["L1_DoubleMu3p5"], &b_L1_DoubleMu3p5);
  fChain->SetBranchAddress("L1_MuOpen_DoubleEG5", &map_BitOfStandardHLTPath["L1_MuOpen_DoubleEG5"], &b_L1_MuOpen_DoubleEG5);
  fChain->SetBranchAddress("L1_DoubleMuOpen_EG5", &map_BitOfStandardHLTPath["L1_DoubleMuOpen_EG5"], &b_L1_DoubleMuOpen_EG5);
  fChain->SetBranchAddress("L1_DoubleEG_12_5", &map_BitOfStandardHLTPath["L1_DoubleEG_12_5"], &b_L1_DoubleEG_12_5);
  fChain->SetBranchAddress("L1_DoubleTauJet36_Eta2p17", &map_BitOfStandardHLTPath["L1_DoubleTauJet36_Eta2p17"], &b_L1_DoubleTauJet36_Eta2p17);
  fChain->SetBranchAddress("L1_SingleJet52_Central", &map_BitOfStandardHLTPath["L1_SingleJet52_Central"], &b_L1_SingleJet52_Central);
  fChain->SetBranchAddress("L1_DoubleJet52_Central", &map_BitOfStandardHLTPath["L1_DoubleJet52_Central"], &b_L1_DoubleJet52_Central);
  fChain->SetBranchAddress("L1_DoubleTauJet40_Eta2p17", &map_BitOfStandardHLTPath["L1_DoubleTauJet40_Eta2p17"], &b_L1_DoubleTauJet40_Eta2p17);
  fChain->SetBranchAddress("L1_Jet52_Central_ETM30", &map_BitOfStandardHLTPath["L1_Jet52_Central_ETM30"], &b_L1_Jet52_Central_ETM30);
  fChain->SetBranchAddress("L1_DoubleJet44_Central", &map_BitOfStandardHLTPath["L1_DoubleJet44_Central"], &b_L1_DoubleJet44_Central);
  fChain->SetBranchAddress("L1_Mu7_EG5", &map_BitOfStandardHLTPath["L1_Mu7_EG5"], &b_L1_Mu7_EG5);
  fChain->SetBranchAddress("L1_MuOpen_EG12", &map_BitOfStandardHLTPath["L1_MuOpen_EG12"], &b_L1_MuOpen_EG12);
  fChain->SetBranchAddress("L1_DoubleTauJet36", &map_BitOfStandardHLTPath["L1_DoubleTauJet36"], &b_L1_DoubleTauJet36);
  fChain->SetBranchAddress("L1_TripleJet28_Central", &map_BitOfStandardHLTPath["L1_TripleJet28_Central"], &b_L1_TripleJet28_Central);
  fChain->SetBranchAddress("L1_SingleJet36_FwdVeto5", &map_BitOfStandardHLTPath["L1_SingleJet36_FwdVeto5"], &b_L1_SingleJet36_FwdVeto5);
  fChain->SetBranchAddress("L1_SingleTauJet68", &map_BitOfStandardHLTPath["L1_SingleTauJet68"], &b_L1_SingleTauJet68);
  fChain->SetBranchAddress("L1_MuOpen_EG5", &map_BitOfStandardHLTPath["L1_MuOpen_EG5"], &b_L1_MuOpen_EG5);
  fChain->SetBranchAddress("L1_SingleMu5_Eta1p5_Q80_v1", &map_BitOfStandardHLTPath["L1_SingleMu5_Eta1p5_Q80_v1"], &b_L1_SingleMu5_Eta1p5_Q80_v1);
  fChain->SetBranchAddress("L1_HTT75", &map_BitOfStandardHLTPath["L1_HTT75"], &b_L1_HTT75);
  fChain->SetBranchAddress("L1_ETT220", &map_BitOfStandardHLTPath["L1_ETT220"], &b_L1_ETT220);
  fChain->SetBranchAddress("L1_SingleJet20_NotBptxOR", &map_BitOfStandardHLTPath["L1_SingleJet20_NotBptxOR"], &b_L1_SingleJet20_NotBptxOR);
  fChain->SetBranchAddress("L1_BeamGas_Bsc", &map_BitOfStandardHLTPath["L1_BeamGas_Bsc"], &b_L1_BeamGas_Bsc);
  fChain->SetBranchAddress("L1_PreCollisions", &map_BitOfStandardHLTPath["L1_PreCollisions"], &b_L1_PreCollisions);
  fChain->SetBranchAddress("L1_BeamGas_Hf", &map_BitOfStandardHLTPath["L1_BeamGas_Hf"], &b_L1_BeamGas_Hf);
  fChain->SetBranchAddress("L1_Mu3_Jet20_Central", &map_BitOfStandardHLTPath["L1_Mu3_Jet20_Central"], &b_L1_Mu3_Jet20_Central);
  fChain->SetBranchAddress("L1_Mu3_Jet28_Central", &map_BitOfStandardHLTPath["L1_Mu3_Jet28_Central"], &b_L1_Mu3_Jet28_Central);
  fChain->SetBranchAddress("L1_Mu3_Jet16_Central", &map_BitOfStandardHLTPath["L1_Mu3_Jet16_Central"], &b_L1_Mu3_Jet16_Central);
  fChain->SetBranchAddress("L1_Mu7_Jet20_Central", &map_BitOfStandardHLTPath["L1_Mu7_Jet20_Central"], &b_L1_Mu7_Jet20_Central);
  fChain->SetBranchAddress("L1_Mu3_JetC16_WdEtaPhi2", &map_BitOfStandardHLTPath["L1_Mu3_JetC16_WdEtaPhi2"], &b_L1_Mu3_JetC16_WdEtaPhi2);
  fChain->SetBranchAddress("L1_Mu3_JetC52_WdEtaPhi2", &map_BitOfStandardHLTPath["L1_Mu3_JetC52_WdEtaPhi2"], &b_L1_Mu3_JetC52_WdEtaPhi2);

  fChain->SetBranchAddress("L1_DoubleEG5_HTT50", &map_BitOfStandardHLTPath["L1_DoubleEG5_HTT50"], &b_L1_DoubleEG5_HTT50);
  fChain->SetBranchAddress("L1_EG5_HTT75", &map_BitOfStandardHLTPath["L1_EG5_HTT75"], &b_L1_EG5_HTT75);
  fChain->SetBranchAddress("L1_DoubleJet52", &map_BitOfStandardHLTPath["L1_DoubleJet52"], &b_L1_DoubleJet52);
  fChain->SetBranchAddress("L1_SingleTauJet52", &map_BitOfStandardHLTPath["L1_SingleTauJet52"], &b_L1_SingleTauJet52);
  fChain->SetBranchAddress("L1_DoubleTauJet28", &map_BitOfStandardHLTPath["L1_DoubleTauJet28"], &b_L1_DoubleTauJet28);
  fChain->SetBranchAddress("L1_SingleJet20_NotBptxOR_NotMuBeamHalo", &map_BitOfStandardHLTPath["L1_SingleJet20_NotBptxOR_NotMuBeamHalo"], &b_L1_SingleJet20_NotBptxOR_NotMuBeamHalo);
  fChain->SetBranchAddress("L1_SingleJet16", &map_BitOfStandardHLTPath["L1_SingleJet16"], &b_L1_SingleJet16);
  fChain->SetBranchAddress("L1_SingleJet68", &map_BitOfStandardHLTPath["L1_SingleJet68"], &b_L1_SingleJet68);
  fChain->SetBranchAddress("L1_SingleJet92", &map_BitOfStandardHLTPath["L1_SingleJet92"], &b_L1_SingleJet92);
  fChain->SetBranchAddress("L1_DoubleForJet32_EtaOpp", &map_BitOfStandardHLTPath["L1_DoubleForJet32_EtaOpp"], &b_L1_DoubleForJet32_EtaOpp);
  fChain->SetBranchAddress("L1_DoubleForJet44_EtaOpp", &map_BitOfStandardHLTPath["L1_DoubleForJet44_EtaOpp"], &b_L1_DoubleForJet44_EtaOpp);
  fChain->SetBranchAddress("L1_DoubleEG2_FwdVeto", &map_BitOfStandardHLTPath["L1_DoubleEG2_FwdVeto"], &b_L1_DoubleEG2_FwdVeto);
  fChain->SetBranchAddress("L1_SingleJet36_FwdVeto", &map_BitOfStandardHLTPath["L1_SingleJet36_FwdVeto"], &b_L1_SingleJet36_FwdVeto);
  fChain->SetBranchAddress("L1_TripleEG7", &map_BitOfStandardHLTPath["L1_TripleEG7"], &b_L1_TripleEG7);
  fChain->SetBranchAddress("L1_TripleEG5", &map_BitOfStandardHLTPath["L1_TripleEG5"], &b_L1_TripleEG5);
  fChain->SetBranchAddress("L1_TripleJet28", &map_BitOfStandardHLTPath["L1_TripleJet28"], &b_L1_TripleJet28);
  fChain->SetBranchAddress("L1_Mu0_HTT50", &map_BitOfStandardHLTPath["L1_Mu0_HTT50"], &b_L1_Mu0_HTT50);
  fChain->SetBranchAddress("L1_SingleEG12_Eta2p17", &map_BitOfStandardHLTPath["L1_SingleEG12_Eta2p17"], &b_L1_SingleEG12_Eta2p17);
  fChain->SetBranchAddress("L1_SingleEG30", &map_BitOfStandardHLTPath["L1_SingleEG30"], &b_L1_SingleEG30);
  fChain->SetBranchAddress("L1_Mu3_Jet20", &map_BitOfStandardHLTPath["L1_Mu3_Jet20"], &b_L1_Mu3_Jet20);
  fChain->SetBranchAddress("L1_Mu3_Jet16", &map_BitOfStandardHLTPath["L1_Mu3_Jet16"], &b_L1_Mu3_Jet16);
  fChain->SetBranchAddress("L1_SingleMu16", &map_BitOfStandardHLTPath["L1_SingleMu16"], &b_L1_SingleMu16);
  fChain->SetBranchAddress("L1_SingleMu25", &map_BitOfStandardHLTPath["L1_SingleMu25"], &b_L1_SingleMu25);
  fChain->SetBranchAddress("L1_DoubleMu5", &map_BitOfStandardHLTPath["L1_DoubleMu5"], &b_L1_DoubleMu5);
  fChain->SetBranchAddress("L1_SingleMu5_Eta1p5_Q80", &map_BitOfStandardHLTPath["L1_SingleMu5_Eta1p5_Q80"], &b_L1_SingleMu5_Eta1p5_Q80);
  fChain->SetBranchAddress("L1_DoubleMu_0_5", &map_BitOfStandardHLTPath["L1_DoubleMu_0_5"], &b_L1_DoubleMu_0_5);
  fChain->SetBranchAddress("L1_SingleMu12", &map_BitOfStandardHLTPath["L1_SingleMu12"], &b_L1_SingleMu12);
  fChain->SetBranchAddress("L1_DoubleMu0", &map_BitOfStandardHLTPath["L1_DoubleMu0"], &b_L1_DoubleMu0);
  fChain->SetBranchAddress("L1_QuadJet20_Central", &map_BitOfStandardHLTPath["L1_QuadJet20_Central"], &b_L1_QuadJet20_Central);
  fChain->SetBranchAddress("L1_DoubleJet36_Central", &map_BitOfStandardHLTPath["L1_DoubleJet36_Central"], &b_L1_DoubleJet36_Central);
  fChain->SetBranchAddress("L1_SingleJet52", &map_BitOfStandardHLTPath["L1_SingleJet52"], &b_L1_SingleJet52);
  fChain->SetBranchAddress("L1_SingleJet36", &map_BitOfStandardHLTPath["L1_SingleJet36"], &b_L1_SingleJet36);
   fChain->SetBranchAddress("L1_Mu3_Jet10", &map_BitOfStandardHLTPath["L1_Mu3_Jet10"], &b_L1_Mu3_Jet10);
   fChain->SetBranchAddress("L1_SingleJet10U_NotBptxOR_Ext", &map_BitOfStandardHLTPath["L1_SingleJet10U_NotBptxOR_Ext"], &b_L1_SingleJet10U_NotBptxOR_Ext);
   fChain->SetBranchAddress("L1_SingleJet10_NotBptxOR_Ext", &map_BitOfStandardHLTPath["L1_SingleJet10_NotBptxOR_Ext"], &b_L1_SingleJet10_NotBptxOR_Ext);
   fChain->SetBranchAddress("L1_SingleJet10U_NotBptxOR", &map_BitOfStandardHLTPath["L1_SingleJet10U_NotBptxOR"], &b_L1_SingleJet10U_NotBptxOR);
   fChain->SetBranchAddress("L1_SingleJet10_NotBptxOR", &map_BitOfStandardHLTPath["L1_SingleJet10_NotBptxOR"], &b_L1_SingleJet10_NotBptxOR);
   fChain->SetBranchAddress("L1_Mu3_EG5", &map_BitOfStandardHLTPath["L1_Mu3_EG5"], &b_L1_Mu3_EG5);

   fChain->SetBranchAddress("L1Tech_BPTX_plus_OR_minus.v0", &map_BitOfStandardHLTPath["L1Tech_BPTX_plus_OR_minus.v0"], &b_L1Tech_BPTX_plus_OR_minus_v0);
   fChain->SetBranchAddress("L1Tech_BPTX_plus_AND_minus_instance1.v0", &map_BitOfStandardHLTPath["L1Tech_BPTX_plus_AND_minus_instance1.v0"], &b_L1Tech_BPTX_plus_AND_minus_instance1_v0);
   fChain->SetBranchAddress("L1Tech_BSC_minBias_OR.v0", &map_BitOfStandardHLTPath["L1Tech_BSC_minBias_OR.v0"], &b_L1Tech_BSC_minBias_OR_v0);
   fChain->SetBranchAddress("L1Tech_BSC_minBias_threshold1.v0", &map_BitOfStandardHLTPath["L1Tech_BSC_minBias_threshold1.v0"], &b_L1Tech_BSC_minBias_threshold1_v0);
   fChain->SetBranchAddress("L1Tech_BSC_minBias_threshold2.v0", &map_BitOfStandardHLTPath["L1Tech_BSC_minBias_threshold2.v0"], &b_L1Tech_BSC_minBias_threshold2_v0);
   fChain->SetBranchAddress("L1Tech_BSC_minBias_inner_threshold1.v0", &map_BitOfStandardHLTPath["L1Tech_BSC_minBias_inner_threshold1.v0"], &b_L1Tech_BSC_minBias_inner_threshold1_v0);
   fChain->SetBranchAddress("L1Tech_BSC_minBias_inner_threshold2.v0", &map_BitOfStandardHLTPath["L1Tech_BSC_minBias_inner_threshold2.v0"], &b_L1Tech_BSC_minBias_inner_threshold2_v0);
   fChain->SetBranchAddress("L1Tech_BSC_halo_beam1_inner.v0", &map_BitOfStandardHLTPath["L1Tech_BSC_halo_beam1_inner.v0"], &b_L1Tech_BSC_halo_beam1_inner_v0);
   fChain->SetBranchAddress("L1Tech_BSC_halo_beam1_outer.v0", &map_BitOfStandardHLTPath["L1Tech_BSC_halo_beam1_outer.v0"], &b_L1Tech_BSC_halo_beam1_outer_v0);
   fChain->SetBranchAddress("L1Tech_BSC_halo_beam2_inner.v0", &map_BitOfStandardHLTPath["L1Tech_BSC_halo_beam2_inner.v0"], &b_L1Tech_BSC_halo_beam2_inner_v0);
   fChain->SetBranchAddress("L1Tech_BSC_halo_beam2_outer.v0", &map_BitOfStandardHLTPath["L1Tech_BSC_halo_beam2_outer.v0"], &b_L1Tech_BSC_halo_beam2_outer_v0);
   fChain->SetBranchAddress("L1Tech_BSC_HighMultiplicity.v0", &map_BitOfStandardHLTPath["L1Tech_BSC_HighMultiplicity.v0"], &b_L1Tech_BSC_HighMultiplicity_v0);
   fChain->SetBranchAddress("L1Tech_BSC_splash_beam1.v0", &map_BitOfStandardHLTPath["L1Tech_BSC_splash_beam1.v0"], &b_L1Tech_BSC_splash_beam1_v0);
   fChain->SetBranchAddress("L1Tech_BSC_splash_beam2.v0", &map_BitOfStandardHLTPath["L1Tech_BSC_splash_beam2.v0"], &b_L1Tech_BSC_splash_beam2_v0);
   fChain->SetBranchAddress("L1Tech_RPC_TTU_barrel_Cosmics.v0", &map_BitOfStandardHLTPath["L1Tech_RPC_TTU_barrel_Cosmics.v0"], &b_L1Tech_RPC_TTU_barrel_Cosmics_v0);
   fChain->SetBranchAddress("L1Tech_RPC_TTU_pointing_Cosmics.v0", &map_BitOfStandardHLTPath["L1Tech_RPC_TTU_pointing_Cosmics.v0"], &b_L1Tech_RPC_TTU_pointing_Cosmics_v0);
   fChain->SetBranchAddress("L1Tech_RPC_TTU_RBst1_collisions.v0", &map_BitOfStandardHLTPath["L1Tech_RPC_TTU_RBst1_collisions.v0"], &b_L1Tech_RPC_TTU_RBst1_collisions_v0);
   fChain->SetBranchAddress("L1Tech_HCAL_HF_MM_or_PP_or_PM.v0", &map_BitOfStandardHLTPath["L1Tech_HCAL_HF_MM_or_PP_or_PM.v0"], &b_L1Tech_HCAL_HF_MM_or_PP_or_PM_v0);
   fChain->SetBranchAddress("L1Tech_HCAL_HF_coincidence_PM.v1", &map_BitOfStandardHLTPath["L1Tech_HCAL_HF_coincidence_PM.v1"], &b_L1Tech_HCAL_HF_coincidence_PM_v1);
   fChain->SetBranchAddress("L1Tech_HCAL_HF_MMP_or_MPP.v0", &map_BitOfStandardHLTPath["L1Tech_HCAL_HF_MMP_or_MPP.v0"], &b_L1Tech_HCAL_HF_MMP_or_MPP_v0);
   fChain->SetBranchAddress("L1Tech_HCAL_HO_totalOR.v0", &map_BitOfStandardHLTPath["L1Tech_HCAL_HO_totalOR.v0"], &b_L1Tech_HCAL_HO_totalOR_v0);
   fChain->SetBranchAddress("L1Tech_HCAL_HBHE_totalOR.v0", &map_BitOfStandardHLTPath["L1Tech_HCAL_HBHE_totalOR.v0"], &b_L1Tech_HCAL_HBHE_totalOR_v0);
   fChain->SetBranchAddress("L1_BptxPlusORMinus", &map_BitOfStandardHLTPath["L1_BptxPlusORMinus"], &b_L1_BptxPlusORMinus);
   fChain->SetBranchAddress("L1_BptxPlus_NotBptxMinus", &map_BitOfStandardHLTPath["L1_BptxPlus_NotBptxMinus"], &b_L1_BptxPlus_NotBptxMinus);
   fChain->SetBranchAddress("L1_BptxMinus_NotBptxPlus", &map_BitOfStandardHLTPath["L1_BptxMinus_NotBptxPlus"], &b_L1_BptxMinus_NotBptxPlus);
   fChain->SetBranchAddress("L1_BptxXOR_BscMinBiasOR", &map_BitOfStandardHLTPath["L1_BptxXOR_BscMinBiasOR"], &b_L1_BptxXOR_BscMinBiasOR);
   fChain->SetBranchAddress("L1_Mu5_Jet6", &map_BitOfStandardHLTPath["L1_Mu5_Jet6"], &b_L1_Mu5_Jet6);
   fChain->SetBranchAddress("L1_EG5_TripleJet6", &map_BitOfStandardHLTPath["L1_EG5_TripleJet6"], &b_L1_EG5_TripleJet6);
   fChain->SetBranchAddress("L1_SingleJet6", &map_BitOfStandardHLTPath["L1_SingleJet6"], &b_L1_SingleJet6);
   fChain->SetBranchAddress("L1_SingleJet10", &map_BitOfStandardHLTPath["L1_SingleJet10"], &b_L1_SingleJet10);
   fChain->SetBranchAddress("L1_SingleJet10_NotBptxC_Ext", &map_BitOfStandardHLTPath["L1_SingleJet10_NotBptxC_Ext"], &b_L1_SingleJet10_NotBptxC_Ext);
   fChain->SetBranchAddress("L1_DoubleEG1", &map_BitOfStandardHLTPath["L1_DoubleEG1"], &b_L1_DoubleEG1);
   fChain->SetBranchAddress("L1_DoubleEG2", &map_BitOfStandardHLTPath["L1_DoubleEG2"], &b_L1_DoubleEG2);
   fChain->SetBranchAddress("L1_DoubleEG5", &map_BitOfStandardHLTPath["L1_DoubleEG5"], &b_L1_DoubleEG5);
   fChain->SetBranchAddress("L1_DoubleHfBitCountsRing1_P1N1", &map_BitOfStandardHLTPath["L1_DoubleHfBitCountsRing1_P1N1"], &b_L1_DoubleHfBitCountsRing1_P1N1);
   fChain->SetBranchAddress("L1_DoubleHfBitCountsRing2_P1N1", &map_BitOfStandardHLTPath["L1_DoubleHfBitCountsRing2_P1N1"], &b_L1_DoubleHfBitCountsRing2_P1N1);
   fChain->SetBranchAddress("L1_DoubleHfRingEtSumsRing1_P200N200", &map_BitOfStandardHLTPath["L1_DoubleHfRingEtSumsRing1_P200N200"], &b_L1_DoubleHfRingEtSumsRing1_P200N200);
   fChain->SetBranchAddress("L1_DoubleHfRingEtSumsRing1_P4N4", &map_BitOfStandardHLTPath["L1_DoubleHfRingEtSumsRing1_P4N4"], &b_L1_DoubleHfRingEtSumsRing1_P4N4);
   fChain->SetBranchAddress("L1_DoubleHfRingEtSumsRing2_P200N200", &map_BitOfStandardHLTPath["L1_DoubleHfRingEtSumsRing2_P200N200"], &b_L1_DoubleHfRingEtSumsRing2_P200N200);
   fChain->SetBranchAddress("L1_DoubleHfRingEtSumsRing2_P4N4", &map_BitOfStandardHLTPath["L1_DoubleHfRingEtSumsRing2_P4N4"], &b_L1_DoubleHfRingEtSumsRing2_P4N4);
   fChain->SetBranchAddress("L1_DoubleJet70", &map_BitOfStandardHLTPath["L1_DoubleJet70"], &b_L1_DoubleJet70);
   fChain->SetBranchAddress("L1_DoubleMu3", &map_BitOfStandardHLTPath["L1_DoubleMu3"], &b_L1_DoubleMu3);
   fChain->SetBranchAddress("L1_DoubleMuOpen", &map_BitOfStandardHLTPath["L1_DoubleMuOpen"], &b_L1_DoubleMuOpen);
   fChain->SetBranchAddress("L1_DoubleTauJet30", &map_BitOfStandardHLTPath["L1_DoubleTauJet30"], &b_L1_DoubleTauJet30);
   fChain->SetBranchAddress("L1_EG10_Jet15", &map_BitOfStandardHLTPath["L1_EG10_Jet15"], &b_L1_EG10_Jet15);
   fChain->SetBranchAddress("L1_EG5_TripleJet15", &map_BitOfStandardHLTPath["L1_EG5_TripleJet15"], &b_L1_EG5_TripleJet15);
   fChain->SetBranchAddress("L1_ETM20", &map_BitOfStandardHLTPath["L1_ETM20"], &b_L1_ETM20);
   fChain->SetBranchAddress("L1_ETM30", &map_BitOfStandardHLTPath["L1_ETM30"], &b_L1_ETM30);
   fChain->SetBranchAddress("L1_ETM40", &map_BitOfStandardHLTPath["L1_ETM40"], &b_L1_ETM40);
   fChain->SetBranchAddress("L1_ETM70", &map_BitOfStandardHLTPath["L1_ETM70"], &b_L1_ETM70);
   fChain->SetBranchAddress("L1_ETM80", &map_BitOfStandardHLTPath["L1_ETM80"], &b_L1_ETM80);
   fChain->SetBranchAddress("L1_ETT60", &map_BitOfStandardHLTPath["L1_ETT60"], &b_L1_ETT60);
   fChain->SetBranchAddress("L1_ETT100", &map_BitOfStandardHLTPath["L1_ETT100"], &b_L1_ETT100);
   fChain->SetBranchAddress("L1_ETT140", &map_BitOfStandardHLTPath["L1_ETT140"], &b_L1_ETT140);
   fChain->SetBranchAddress("L1_HTT50", &map_BitOfStandardHLTPath["L1_HTT50"], &b_L1_HTT50);
   fChain->SetBranchAddress("L1_HTT100", &map_BitOfStandardHLTPath["L1_HTT100"], &b_L1_HTT100);
   fChain->SetBranchAddress("L1_HTT200", &map_BitOfStandardHLTPath["L1_HTT200"], &b_L1_HTT200);
   fChain->SetBranchAddress("L1_HTT300", &map_BitOfStandardHLTPath["L1_HTT300"], &b_L1_HTT300);
   fChain->SetBranchAddress("L1_IsoEG10_Jet15_ForJet10", &map_BitOfStandardHLTPath["L1_IsoEG10_Jet15_ForJet10"], &b_L1_IsoEG10_Jet15_ForJet10);
   fChain->SetBranchAddress("L1_MinBias_HTT10", &map_BitOfStandardHLTPath["L1_MinBias_HTT10"], &b_L1_MinBias_HTT10);
   fChain->SetBranchAddress("L1_Mu3QE8_EG5", &map_BitOfStandardHLTPath["L1_Mu3QE8_EG5"], &b_L1_Mu3QE8_EG5);
   fChain->SetBranchAddress("L1_Mu3QE8_Jet15", &map_BitOfStandardHLTPath["L1_Mu3QE8_Jet15"], &b_L1_Mu3QE8_Jet15);
   fChain->SetBranchAddress("L1_Mu5QE8_Jet15", &map_BitOfStandardHLTPath["L1_Mu5QE8_Jet15"], &b_L1_Mu5QE8_Jet15);
   fChain->SetBranchAddress("L1_Mu3QE8_Jet6", &map_BitOfStandardHLTPath["L1_Mu3QE8_Jet6"], &b_L1_Mu3QE8_Jet6);
   fChain->SetBranchAddress("L1_Mu5QE8_Jet6", &map_BitOfStandardHLTPath["L1_Mu5QE8_Jet6"], &b_L1_Mu5QE8_Jet6);
   fChain->SetBranchAddress("L1_QuadJet15", &map_BitOfStandardHLTPath["L1_QuadJet15"], &b_L1_QuadJet15);
   fChain->SetBranchAddress("L1_SingleEG1", &map_BitOfStandardHLTPath["L1_SingleEG1"], &b_L1_SingleEG1);
   fChain->SetBranchAddress("L1_SingleEG10", &map_BitOfStandardHLTPath["L1_SingleEG10"], &b_L1_SingleEG10);
   fChain->SetBranchAddress("L1_SingleEG12", &map_BitOfStandardHLTPath["L1_SingleEG12"], &b_L1_SingleEG12);
   fChain->SetBranchAddress("L1_SingleEG15", &map_BitOfStandardHLTPath["L1_SingleEG15"], &b_L1_SingleEG15);
   fChain->SetBranchAddress("L1_SingleEG2", &map_BitOfStandardHLTPath["L1_SingleEG2"], &b_L1_SingleEG2);
   fChain->SetBranchAddress("L1_SingleEG20", &map_BitOfStandardHLTPath["L1_SingleEG20"], &b_L1_SingleEG20);
   fChain->SetBranchAddress("L1_SingleEG5", &map_BitOfStandardHLTPath["L1_SingleEG5"], &b_L1_SingleEG5);
   fChain->SetBranchAddress("L1_SingleEG8", &map_BitOfStandardHLTPath["L1_SingleEG8"], &b_L1_SingleEG8);
   fChain->SetBranchAddress("L1_SingleHfBitCountsRing1_1", &map_BitOfStandardHLTPath["L1_SingleHfBitCountsRing1_1"], &b_L1_SingleHfBitCountsRing1_1);
   fChain->SetBranchAddress("L1_SingleHfBitCountsRing2_1", &map_BitOfStandardHLTPath["L1_SingleHfBitCountsRing2_1"], &b_L1_SingleHfBitCountsRing2_1);
   fChain->SetBranchAddress("L1_SingleHfRingEtSumsRing1_200", &map_BitOfStandardHLTPath["L1_SingleHfRingEtSumsRing1_200"], &b_L1_SingleHfRingEtSumsRing1_200);
   fChain->SetBranchAddress("L1_SingleHfRingEtSumsRing1_4", &map_BitOfStandardHLTPath["L1_SingleHfRingEtSumsRing1_4"], &b_L1_SingleHfRingEtSumsRing1_4);
   fChain->SetBranchAddress("L1_SingleHfRingEtSumsRing2_200", &map_BitOfStandardHLTPath["L1_SingleHfRingEtSumsRing2_200"], &b_L1_SingleHfRingEtSumsRing2_200);
   fChain->SetBranchAddress("L1_SingleHfRingEtSumsRing2_4", &map_BitOfStandardHLTPath["L1_SingleHfRingEtSumsRing2_4"], &b_L1_SingleHfRingEtSumsRing2_4);
   fChain->SetBranchAddress("L1_SingleIsoEG10", &map_BitOfStandardHLTPath["L1_SingleIsoEG10"], &b_L1_SingleIsoEG10);
   fChain->SetBranchAddress("L1_SingleIsoEG12", &map_BitOfStandardHLTPath["L1_SingleIsoEG12"], &b_L1_SingleIsoEG12);
   fChain->SetBranchAddress("L1_SingleIsoEG15", &map_BitOfStandardHLTPath["L1_SingleIsoEG15"], &b_L1_SingleIsoEG15);
   fChain->SetBranchAddress("L1_SingleIsoEG5", &map_BitOfStandardHLTPath["L1_SingleIsoEG5"], &b_L1_SingleIsoEG5);
   fChain->SetBranchAddress("L1_SingleIsoEG8", &map_BitOfStandardHLTPath["L1_SingleIsoEG8"], &b_L1_SingleIsoEG8);
   fChain->SetBranchAddress("L1_SingleJet100", &map_BitOfStandardHLTPath["L1_SingleJet100"], &b_L1_SingleJet100);
   fChain->SetBranchAddress("L1_SingleJet15", &map_BitOfStandardHLTPath["L1_SingleJet15"], &b_L1_SingleJet15);
   fChain->SetBranchAddress("L1_SingleJet30", &map_BitOfStandardHLTPath["L1_SingleJet30"], &b_L1_SingleJet30);
   fChain->SetBranchAddress("L1_SingleJet50", &map_BitOfStandardHLTPath["L1_SingleJet50"], &b_L1_SingleJet50);
   fChain->SetBranchAddress("L1_SingleJet70", &map_BitOfStandardHLTPath["L1_SingleJet70"], &b_L1_SingleJet70);
   fChain->SetBranchAddress("L1_SingleMu0", &map_BitOfStandardHLTPath["L1_SingleMu0"], &b_L1_SingleMu0);
   fChain->SetBranchAddress("L1_SingleMu10", &map_BitOfStandardHLTPath["L1_SingleMu10"], &b_L1_SingleMu10);
   fChain->SetBranchAddress("L1_SingleMu14", &map_BitOfStandardHLTPath["L1_SingleMu14"], &b_L1_SingleMu14);
   fChain->SetBranchAddress("L1_SingleMu20", &map_BitOfStandardHLTPath["L1_SingleMu20"], &b_L1_SingleMu20);
   fChain->SetBranchAddress("L1_SingleMu3", &map_BitOfStandardHLTPath["L1_SingleMu3"], &b_L1_SingleMu3);
   fChain->SetBranchAddress("L1_SingleMu5", &map_BitOfStandardHLTPath["L1_SingleMu5"], &b_L1_SingleMu5);
   fChain->SetBranchAddress("L1_SingleMu7", &map_BitOfStandardHLTPath["L1_SingleMu7"], &b_L1_SingleMu7);
   fChain->SetBranchAddress("L1_SingleMuBeamHalo", &map_BitOfStandardHLTPath["L1_SingleMuBeamHalo"], &b_L1_SingleMuBeamHalo);
   fChain->SetBranchAddress("L1_SingleMuOpen", &map_BitOfStandardHLTPath["L1_SingleMuOpen"], &b_L1_SingleMuOpen);
   fChain->SetBranchAddress("L1_SingleTauJet40", &map_BitOfStandardHLTPath["L1_SingleTauJet40"], &b_L1_SingleTauJet40);
   fChain->SetBranchAddress("L1_SingleTauJet60", &map_BitOfStandardHLTPath["L1_SingleTauJet60"], &b_L1_SingleTauJet60);
   fChain->SetBranchAddress("L1_SingleTauJet80", &map_BitOfStandardHLTPath["L1_SingleTauJet80"], &b_L1_SingleTauJet80);
   fChain->SetBranchAddress("L1_TripleJet30", &map_BitOfStandardHLTPath["L1_TripleJet30"], &b_L1_TripleJet30);
   fChain->SetBranchAddress("L1_ZeroBias", &map_BitOfStandardHLTPath["L1_ZeroBias"], &b_L1_ZeroBias);
   fChain->SetBranchAddress("L1_ZeroBias_Ext", &map_BitOfStandardHLTPath["L1_ZeroBias_Ext"], &b_L1_ZeroBias_Ext);
   fChain->SetBranchAddress("L1_SingleCenJet2", &map_BitOfStandardHLTPath["L1_SingleCenJet2"], &b_L1_SingleCenJet2);
   fChain->SetBranchAddress("L1_SingleCenJet4", &map_BitOfStandardHLTPath["L1_SingleCenJet4"], &b_L1_SingleCenJet4);
   fChain->SetBranchAddress("L1_SingleForJet2", &map_BitOfStandardHLTPath["L1_SingleForJet2"], &b_L1_SingleForJet2);
   fChain->SetBranchAddress("L1_SingleForJet4", &map_BitOfStandardHLTPath["L1_SingleForJet4"], &b_L1_SingleForJet4);
   fChain->SetBranchAddress("L1_SingleTauJet2", &map_BitOfStandardHLTPath["L1_SingleTauJet2"], &b_L1_SingleTauJet2);
   fChain->SetBranchAddress("L1_SingleTauJet4", &map_BitOfStandardHLTPath["L1_SingleTauJet4"], &b_L1_SingleTauJet4);
   fChain->SetBranchAddress("L1_DoubleForJet10_EtaOpp", &map_BitOfStandardHLTPath["L1_DoubleForJet10_EtaOpp"], &b_L1_DoubleForJet10_EtaOpp);
   fChain->SetBranchAddress("L1_Mu3_Jet6", &map_BitOfStandardHLTPath["L1_Mu3_Jet6"], &b_L1_Mu3_Jet6);
   fChain->SetBranchAddress("L1_BscMinBiasOR_BptxPlusORMinus", &map_BitOfStandardHLTPath["L1_BscMinBiasOR_BptxPlusORMinus"], &b_L1_BscMinBiasOR_BptxPlusORMinus);
   fChain->SetBranchAddress("L1_BscMinBiasOR_BptxPlusANDMinus", &map_BitOfStandardHLTPath["L1_BscMinBiasOR_BptxPlusANDMinus"], &b_L1_BscMinBiasOR_BptxPlusANDMinus);
   fChain->SetBranchAddress("L1_DoubleMuTopBottom", &map_BitOfStandardHLTPath["L1_DoubleMuTopBottom"], &b_L1_DoubleMuTopBottom);
   fChain->SetBranchAddress("L1_DoubleEG05_TopBottom", &map_BitOfStandardHLTPath["L1_DoubleEG05_TopBottom"], &b_L1_DoubleEG05_TopBottom);
   fChain->SetBranchAddress("L1_SingleJet20", &map_BitOfStandardHLTPath["L1_SingleJet20"], &b_L1_SingleJet20);
   fChain->SetBranchAddress("L1_SingleJet40", &map_BitOfStandardHLTPath["L1_SingleJet40"], &b_L1_SingleJet40);
   fChain->SetBranchAddress("L1_SingleJet60", &map_BitOfStandardHLTPath["L1_SingleJet60"], &b_L1_SingleJet60);
   fChain->SetBranchAddress("L1_SingleTauJet10", &map_BitOfStandardHLTPath["L1_SingleTauJet10"], &b_L1_SingleTauJet10);
   fChain->SetBranchAddress("L1_SingleTauJet20", &map_BitOfStandardHLTPath["L1_SingleTauJet20"], &b_L1_SingleTauJet20);
   fChain->SetBranchAddress("L1_SingleTauJet30", &map_BitOfStandardHLTPath["L1_SingleTauJet30"], &b_L1_SingleTauJet30);
   fChain->SetBranchAddress("L1_SingleTauJet50", &map_BitOfStandardHLTPath["L1_SingleTauJet50"], &b_L1_SingleTauJet50);
   fChain->SetBranchAddress("L1_DoubleJet30", &map_BitOfStandardHLTPath["L1_DoubleJet30"], &b_L1_DoubleJet30);
   fChain->SetBranchAddress("L1_DoubleTauJet14", &map_BitOfStandardHLTPath["L1_DoubleTauJet14"], &b_L1_DoubleTauJet14);
   fChain->SetBranchAddress("L1_TripleJet14", &map_BitOfStandardHLTPath["L1_TripleJet14"], &b_L1_TripleJet14);
   fChain->SetBranchAddress("L1_QuadJet6", &map_BitOfStandardHLTPath["L1_QuadJet6"], &b_L1_QuadJet6);
   fChain->SetBranchAddress("L1_QuadJet8", &map_BitOfStandardHLTPath["L1_QuadJet8"], &b_L1_QuadJet8);
   fChain->SetBranchAddress("L1_IsoEG10_Jet6_ForJet6", &map_BitOfStandardHLTPath["L1_IsoEG10_Jet6_ForJet6"], &b_L1_IsoEG10_Jet6_ForJet6);

   // L1 Prescales
   // Autogenerated L1 - Prescale SetBranchAddressMaps 
  fChain->SetBranchAddress("L1_SingleJet20_Central_NotBptxOR_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleJet20_Central_NotBptxOR"], &b_L1_SingleJet20_Central_NotBptxOR_Prescl);
  fChain->SetBranchAddress("L1_SingleJet16_FwdVeto5_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleJet16_FwdVeto5"], &b_L1_SingleJet16_FwdVeto5_Prescl);
  fChain->SetBranchAddress("L1_ETT80_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_ETT80"], &b_L1_ETT80_Prescl);
  fChain->SetBranchAddress("L1_DoubleForJet16_EtaOpp_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleForJet16_EtaOpp"], &b_L1_DoubleForJet16_EtaOpp_Prescl);
  fChain->SetBranchAddress("L1_DoubleMu0_HighQ_EtaCuts_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleMu0_HighQ_EtaCuts"], &b_L1_DoubleMu0_HighQ_EtaCuts_Prescl);
  fChain->SetBranchAddress("L1_DoubleEG3_FwdVeto_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleEG3_FwdVeto"], &b_L1_DoubleEG3_FwdVeto_Prescl);
  fChain->SetBranchAddress("L1_SingleForJet16_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleForJet16"], &b_L1_SingleForJet16_Prescl);
  fChain->SetBranchAddress("L1_DoubleMu_5er_0er_HighQ_WdEta22_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleMu_5er_0er_HighQ_WdEta22"], &b_L1_DoubleMu_5er_0er_HighQ_WdEta22_Prescl);
  fChain->SetBranchAddress("L1_DoubleMu3er_HighQ_WdEta22_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleMu3er_HighQ_WdEta22"], &b_L1_DoubleMu3er_HighQ_WdEta22_Prescl);
  fChain->SetBranchAddress("L1_BeamHalo_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_BeamHalo"], &b_L1_BeamHalo_Prescl);
  fChain->SetBranchAddress("L1_InterBunch_Bptx_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_InterBunch_Bptx"], &b_L1_InterBunch_Bptx_Prescl);
  fChain->SetBranchAddress("L1_BeamGas_Hf_BptxPlusPostQuiet_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_BeamGas_Hf_BptxPlusPostQuiet"], &b_L1_BeamGas_Hf_BptxPlusPostQuiet_Prescl);
  fChain->SetBranchAddress("L1_BeamGas_Hf_BptxMinusPostQuiet_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_BeamGas_Hf_BptxMinusPostQuiet"], &b_L1_BeamGas_Hf_BptxMinusPostQuiet_Prescl);
  fChain->SetBranchAddress("L1_ZeroBias_Instance1_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_ZeroBias_Instance1"], &b_L1_ZeroBias_Instance1_Prescl);
  fChain->SetBranchAddress("L1_SingleMu6_NotBptxOR_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleMu6_NotBptxOR"], &b_L1_SingleMu6_NotBptxOR_Prescl);
  fChain->SetBranchAddress("L1_SingleJetC20_NotBptxOR_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleJetC20_NotBptxOR"], &b_L1_SingleJetC20_NotBptxOR_Prescl);
  fChain->SetBranchAddress("L1_SingleJetC32_NotBptxOR_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleJetC32_NotBptxOR"], &b_L1_SingleJetC32_NotBptxOR_Prescl);
  fChain->SetBranchAddress("L1_TripleMu_5_5_0_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_TripleMu_5_5_0"], &b_L1_TripleMu_5_5_0_Prescl);
  fChain->SetBranchAddress("L1_TripleMu0_HighQ_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_TripleMu0_HighQ"], &b_L1_TripleMu0_HighQ_Prescl);
  fChain->SetBranchAddress("L1_DoubleMu_10_3p5_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleMu_10_3p5"], &b_L1_DoubleMu_10_3p5_Prescl);
  fChain->SetBranchAddress("L1_DoubleMu_12_5_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleMu_12_5"], &b_L1_DoubleMu_12_5_Prescl);
  fChain->SetBranchAddress("L1_DoubleMuHighQ_5_0_Eta2p1_WdEta22_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleMuHighQ_5_0_Eta2p1_WdEta22"], &b_L1_DoubleMuHighQ_5_0_Eta2p1_WdEta22_Prescl);
  fChain->SetBranchAddress("L1_DoubleMuHighQ_3_3_Eta2p1_WdEta22_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleMuHighQ_3_3_Eta2p1_WdEta22"], &b_L1_DoubleMuHighQ_3_3_Eta2p1_WdEta22_Prescl);
  fChain->SetBranchAddress("L1_DoubleMu0er_HighQ_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleMu0er_HighQ"], &b_L1_DoubleMu0er_HighQ_Prescl);
  fChain->SetBranchAddress("L1_SingleMu25er_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleMu25er"], &b_L1_SingleMu25er_Prescl);
  fChain->SetBranchAddress("L1_SingleMu20er_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleMu20er"], &b_L1_SingleMu20er_Prescl);
  fChain->SetBranchAddress("L1_SingleMu18er_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleMu18er"], &b_L1_SingleMu18er_Prescl);
  fChain->SetBranchAddress("L1_SingleMu16er_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleMu16er"], &b_L1_SingleMu16er_Prescl);
  fChain->SetBranchAddress("L1_SingleMu14er_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleMu14er"], &b_L1_SingleMu14er_Prescl);
  fChain->SetBranchAddress("L1_DoubleJetC44_ETM30_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleJetC44_ETM30"], &b_L1_DoubleJetC44_ETM30_Prescl);
  fChain->SetBranchAddress("L1_DoubleJetC36_ETM30_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleJetC36_ETM30"], &b_L1_DoubleJetC36_ETM30_Prescl);
  fChain->SetBranchAddress("L1_Mu5_DoubleEG6_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Mu5_DoubleEG6"], &b_L1_Mu5_DoubleEG6_Prescl);
  fChain->SetBranchAddress("L1_Mu5_DoubleEG5_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Mu5_DoubleEG5"], &b_L1_Mu5_DoubleEG5_Prescl);
  fChain->SetBranchAddress("L1_DoubleMu5_EG5_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleMu5_EG5"], &b_L1_DoubleMu5_EG5_Prescl);
  fChain->SetBranchAddress("L1_DoubleMu3p5_EG5_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleMu3p5_EG5"], &b_L1_DoubleMu3p5_EG5_Prescl);
  fChain->SetBranchAddress("L1_Mu3p5_EG12_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Mu3p5_EG12"], &b_L1_Mu3p5_EG12_Prescl);
  fChain->SetBranchAddress("L1_Mu12_EG7_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Mu12_EG7"], &b_L1_Mu12_EG7_Prescl);
  fChain->SetBranchAddress("L1_EG8_DoubleJetC20_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_EG8_DoubleJetC20"], &b_L1_EG8_DoubleJetC20_Prescl);
  fChain->SetBranchAddress("L1_EG18er_JetC_Cen36_Tau28_dPhi1_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_EG18er_JetC_Cen36_Tau28_dPhi1"], &b_L1_EG18er_JetC_Cen36_Tau28_dPhi1_Prescl);
  fChain->SetBranchAddress("L1_IsoEG18er_JetC_Cen36_Tau28_dPhi1_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_IsoEG18er_JetC_Cen36_Tau28_dPhi1"], &b_L1_IsoEG18er_JetC_Cen36_Tau28_dPhi1_Prescl);
  fChain->SetBranchAddress("L1_IsoEG18er_JetC_Cen32_Tau24_dPhi1_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_IsoEG18er_JetC_Cen32_Tau24_dPhi1"], &b_L1_IsoEG18er_JetC_Cen32_Tau24_dPhi1_Prescl);
  fChain->SetBranchAddress("L1_EG18er_JetC_Cen28_Tau20_dPhi1_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_EG18er_JetC_Cen28_Tau20_dPhi1"], &b_L1_EG18er_JetC_Cen28_Tau20_dPhi1_Prescl);
  fChain->SetBranchAddress("L1_DoubleEG6_HTT125_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleEG6_HTT125"], &b_L1_DoubleEG6_HTT125_Prescl);
  fChain->SetBranchAddress("L1_DoubleEG6_HTT100_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleEG6_HTT100"], &b_L1_DoubleEG6_HTT100_Prescl);
  fChain->SetBranchAddress("L1_EG22_ForJet32_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_EG22_ForJet32"], &b_L1_EG22_ForJet32_Prescl);
  fChain->SetBranchAddress("L1_EG22_ForJet24_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_EG22_ForJet24"], &b_L1_EG22_ForJet24_Prescl);
  fChain->SetBranchAddress("L1_Mu8_DoubleJetC20_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Mu8_DoubleJetC20"], &b_L1_Mu8_DoubleJetC20_Prescl);
  fChain->SetBranchAddress("L1_Mu10er_JetC12_WdEtaPhi1_DoubleJetC_32_12_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Mu10er_JetC12_WdEtaPhi1_DoubleJetC_32_12"], &b_L1_Mu10er_JetC12_WdEtaPhi1_DoubleJetC_32_12_Prescl);
  fChain->SetBranchAddress("L1_Mu10er_JetC32_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Mu10er_JetC32"], &b_L1_Mu10er_JetC32_Prescl);
  fChain->SetBranchAddress("L1_Mu10er_JetC12_WdEtaPhi1_DoubleJetC_20_12_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Mu10er_JetC12_WdEtaPhi1_DoubleJetC_20_12"], &b_L1_Mu10er_JetC12_WdEtaPhi1_DoubleJetC_20_12_Prescl);
  fChain->SetBranchAddress("L1_Mu12er_ETM20_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Mu12er_ETM20"], &b_L1_Mu12er_ETM20_Prescl);
  fChain->SetBranchAddress("L1_Mu4_HTT125_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Mu4_HTT125"], &b_L1_Mu4_HTT125_Prescl);
  fChain->SetBranchAddress("L1_Mu0_HTT100_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Mu0_HTT100"], &b_L1_Mu0_HTT100_Prescl);
  fChain->SetBranchAddress("L1_DoubleTauJet44er_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleTauJet44er"], &b_L1_DoubleTauJet44er_Prescl);
  fChain->SetBranchAddress("L1_QuadJetC40_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_QuadJetC40"], &b_L1_QuadJetC40_Prescl);
  fChain->SetBranchAddress("L1_QuadJetC36_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_QuadJetC36"], &b_L1_QuadJetC36_Prescl);
  fChain->SetBranchAddress("L1_QuadJetC32_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_QuadJetC32"], &b_L1_QuadJetC32_Prescl);
  fChain->SetBranchAddress("L1_TripleJetC_52_28_28_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_TripleJetC_52_28_28"], &b_L1_TripleJetC_52_28_28_Prescl);
  fChain->SetBranchAddress("L1_TripleJet_68_48_32_VBF_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_TripleJet_68_48_32_VBF"], &b_L1_TripleJet_68_48_32_VBF_Prescl);
  fChain->SetBranchAddress("L1_TripleJet_64_48_28_VBF_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_TripleJet_64_48_28_VBF"], &b_L1_TripleJet_64_48_28_VBF_Prescl);
  fChain->SetBranchAddress("L1_TripleJet_64_44_24_VBF_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_TripleJet_64_44_24_VBF"], &b_L1_TripleJet_64_44_24_VBF_Prescl);
  fChain->SetBranchAddress("L1_DoubleJetC64_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleJetC64"], &b_L1_DoubleJetC64_Prescl);
  fChain->SetBranchAddress("L1_DoubleJetC56_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleJetC56"], &b_L1_DoubleJetC56_Prescl);
  fChain->SetBranchAddress("L1_DoubleJetC56_Eta1p74_WdEta4_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleJetC56_Eta1p74_WdEta4"], &b_L1_DoubleJetC56_Eta1p74_WdEta4_Prescl);
  fChain->SetBranchAddress("L1_DoubleJetC52_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleJetC52"], &b_L1_DoubleJetC52_Prescl);
  fChain->SetBranchAddress("L1_DoubleJetC44_Eta1p74_WdEta4_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleJetC44_Eta1p74_WdEta4"], &b_L1_DoubleJetC44_Eta1p74_WdEta4_Prescl);
  fChain->SetBranchAddress("L1_DoubleJetC36_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleJetC36"], &b_L1_DoubleJetC36_Prescl);
  fChain->SetBranchAddress("L1_TripleEG_12_7_5_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_TripleEG_12_7_5"], &b_L1_TripleEG_12_7_5_Prescl);
  fChain->SetBranchAddress("L1_DoubleEG_13_7_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleEG_13_7"], &b_L1_DoubleEG_13_7_Prescl);
  fChain->SetBranchAddress("L1_SingleEG24_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleEG24"], &b_L1_SingleEG24_Prescl);
  fChain->SetBranchAddress("L1_SingleEG22_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleEG22"], &b_L1_SingleEG22_Prescl);
  fChain->SetBranchAddress("L1_SingleIsoEG20er_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleIsoEG20er"], &b_L1_SingleIsoEG20er_Prescl);
  fChain->SetBranchAddress("L1_SingleIsoEG18er_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleIsoEG18er"], &b_L1_SingleIsoEG18er_Prescl);
  fChain->SetBranchAddress("L1_SingleEG18er_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleEG18er"], &b_L1_SingleEG18er_Prescl);
  fChain->SetBranchAddress("L1_SingleEG7_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleEG7"], &b_L1_SingleEG7_Prescl);
  fChain->SetBranchAddress("L1_ETT300_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_ETT300"], &b_L1_ETT300_Prescl);
  fChain->SetBranchAddress("L1_HTT175_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_HTT175"], &b_L1_HTT175_Prescl);
  fChain->SetBranchAddress("L1_HTT150_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_HTT150"], &b_L1_HTT150_Prescl);
  fChain->SetBranchAddress("L1_HTT125_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_HTT125"], &b_L1_HTT125_Prescl);
  fChain->SetBranchAddress("L1_ETM100_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_ETM100"], &b_L1_ETM100_Prescl);
  fChain->SetBranchAddress("L1_ETM50_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_ETM50"], &b_L1_ETM50_Prescl);
  fChain->SetBranchAddress("L1_ETM36_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_ETM36"], &b_L1_ETM36_Prescl);
  fChain->SetBranchAddress("L1_QuadJet28_Central_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_QuadJet28_Central"], &b_L1_QuadJet28_Central_Prescl);
  fChain->SetBranchAddress("L1_SingleJet128_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleJet128"], &b_L1_SingleJet128_Prescl);
  fChain->SetBranchAddress("L1_DoubleMu_10_Open_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleMu_10_Open"], &b_L1_DoubleMu_10_Open_Prescl);
  fChain->SetBranchAddress("L1_SingleEG18_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleEG18"], &b_L1_SingleEG18_Prescl);
  fChain->SetBranchAddress("L1_Mu10_Eta2p1_DoubleJet_16_8_Central_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Mu10_Eta2p1_DoubleJet_16_8_Central"], &b_L1_Mu10_Eta2p1_DoubleJet_16_8_Central_Prescl);
  fChain->SetBranchAddress("L1_Mu12_EG5_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Mu12_EG5"], &b_L1_Mu12_EG5_Prescl);
  fChain->SetBranchAddress("L1_SingleMu16_Eta2p1_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleMu16_Eta2p1"], &b_L1_SingleMu16_Eta2p1_Prescl);
  fChain->SetBranchAddress("L1_DoubleMu0_HighQ_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleMu0_HighQ"], &b_L1_DoubleMu0_HighQ_Prescl);
  fChain->SetBranchAddress("L1_SingleMu14_Eta2p1_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleMu14_Eta2p1"], &b_L1_SingleMu14_Eta2p1_Prescl);
  fChain->SetBranchAddress("L1_HTT50_HTM30_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_HTT50_HTM30"], &b_L1_HTT50_HTM30_Prescl);
  fChain->SetBranchAddress("L1_DoubleEG5_HTT75_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleEG5_HTT75"], &b_L1_DoubleEG5_HTT75_Prescl);
  fChain->SetBranchAddress("L1_DoubleJet64_Central_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleJet64_Central"], &b_L1_DoubleJet64_Central_Prescl);
  fChain->SetBranchAddress("L1_DoubleTauJet44_Eta2p17_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleTauJet44_Eta2p17"], &b_L1_DoubleTauJet44_Eta2p17_Prescl);
  fChain->SetBranchAddress("L1_TripleJet_36_36_12_Central_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_TripleJet_36_36_12_Central"], &b_L1_TripleJet_36_36_12_Central_Prescl);
  fChain->SetBranchAddress("L1_EG5_HTT100_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_EG5_HTT100"], &b_L1_EG5_HTT100_Prescl);
  fChain->SetBranchAddress("L1_EG5_DoubleJet20_Central_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_EG5_DoubleJet20_Central"], &b_L1_EG5_DoubleJet20_Central_Prescl);
  fChain->SetBranchAddress("L1_TripleMu0_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_TripleMu0"], &b_L1_TripleMu0_Prescl);
  fChain->SetBranchAddress("L1_DoubleMu3p5_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleMu3p5"], &b_L1_DoubleMu3p5_Prescl);
  fChain->SetBranchAddress("L1_MuOpen_DoubleEG5_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_MuOpen_DoubleEG5"], &b_L1_MuOpen_DoubleEG5_Prescl);
  fChain->SetBranchAddress("L1_DoubleMuOpen_EG5_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleMuOpen_EG5"], &b_L1_DoubleMuOpen_EG5_Prescl);
  fChain->SetBranchAddress("L1_DoubleEG_12_5_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleEG_12_5"], &b_L1_DoubleEG_12_5_Prescl);
  fChain->SetBranchAddress("L1_DoubleTauJet36_Eta2p17_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleTauJet36_Eta2p17"], &b_L1_DoubleTauJet36_Eta2p17_Prescl);
  fChain->SetBranchAddress("L1_SingleJet52_Central_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleJet52_Central"], &b_L1_SingleJet52_Central_Prescl);
  fChain->SetBranchAddress("L1_DoubleJet52_Central_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleJet52_Central"], &b_L1_DoubleJet52_Central_Prescl);
  fChain->SetBranchAddress("L1_DoubleTauJet40_Eta2p17_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleTauJet40_Eta2p17"], &b_L1_DoubleTauJet40_Eta2p17_Prescl);
  fChain->SetBranchAddress("L1_Jet52_Central_ETM30_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Jet52_Central_ETM30"], &b_L1_Jet52_Central_ETM30_Prescl);
  fChain->SetBranchAddress("L1_DoubleJet44_Central_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleJet44_Central"], &b_L1_DoubleJet44_Central_Prescl);
  fChain->SetBranchAddress("L1_Mu7_EG5_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Mu7_EG5"], &b_L1_Mu7_EG5_Prescl);
  fChain->SetBranchAddress("L1_MuOpen_EG12_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_MuOpen_EG12"], &b_L1_MuOpen_EG12_Prescl);
  fChain->SetBranchAddress("L1_DoubleTauJet36_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleTauJet36"], &b_L1_DoubleTauJet36_Prescl);
  fChain->SetBranchAddress("L1_TripleJet28_Central_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_TripleJet28_Central"], &b_L1_TripleJet28_Central_Prescl);
  fChain->SetBranchAddress("L1_SingleJet36_FwdVeto5_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleJet36_FwdVeto5"], &b_L1_SingleJet36_FwdVeto5_Prescl);
  fChain->SetBranchAddress("L1_SingleTauJet68_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleTauJet68"], &b_L1_SingleTauJet68_Prescl);
  fChain->SetBranchAddress("L1_MuOpen_EG5_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_MuOpen_EG5"], &b_L1_MuOpen_EG5_Prescl);
  fChain->SetBranchAddress("L1_SingleMu5_Eta1p5_Q80_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleMu5_Eta1p5_Q80_v1"], &b_L1_SingleMu5_Eta1p5_Q80_v1_Prescl);
  fChain->SetBranchAddress("L1_HTT75_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_HTT75"], &b_L1_HTT75_Prescl);
  fChain->SetBranchAddress("L1_ETT220_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_ETT220"], &b_L1_ETT220_Prescl);
  fChain->SetBranchAddress("L1_SingleJet20_NotBptxOR_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleJet20_NotBptxOR"], &b_L1_SingleJet20_NotBptxOR_Prescl);
  fChain->SetBranchAddress("L1_BeamGas_Bsc_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_BeamGas_Bsc"], &b_L1_BeamGas_Bsc_Prescl);
  fChain->SetBranchAddress("L1_PreCollisions_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_PreCollisions"], &b_L1_PreCollisions_Prescl);
  fChain->SetBranchAddress("L1_BeamGas_Hf_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_BeamGas_Hf"], &b_L1_BeamGas_Hf_Prescl);
  fChain->SetBranchAddress("L1_Mu3_Jet20_Central_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Mu3_Jet20_Central"], &b_L1_Mu3_Jet20_Central_Prescl);
  fChain->SetBranchAddress("L1_Mu3_Jet28_Central_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Mu3_Jet28_Central"], &b_L1_Mu3_Jet28_Central_Prescl);
  fChain->SetBranchAddress("L1_Mu3_Jet16_Central_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Mu3_Jet16_Central"], &b_L1_Mu3_Jet16_Central_Prescl);
  fChain->SetBranchAddress("L1_Mu7_Jet20_Central_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Mu7_Jet20_Central"], &b_L1_Mu7_Jet20_Central_Prescl);
  fChain->SetBranchAddress("L1_Mu3_JetC16_WdEtaPhi2_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Mu3_JetC16_WdEtaPhi2"], &b_L1_Mu3_JetC16_WdEtaPhi2_Prescl);
  fChain->SetBranchAddress("L1_Mu3_JetC52_WdEtaPhi2_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Mu3_JetC52_WdEtaPhi2"], &b_L1_Mu3_JetC52_WdEtaPhi2_Prescl);

  fChain->SetBranchAddress("L1_DoubleEG5_HTT50_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleEG5_HTT50"], &b_L1_DoubleEG5_HTT50_Prescl);
  fChain->SetBranchAddress("L1_EG5_HTT75_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_EG5_HTT75"], &b_L1_EG5_HTT75_Prescl);
  fChain->SetBranchAddress("L1_DoubleJet52_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleJet52"], &b_L1_DoubleJet52_Prescl);
  fChain->SetBranchAddress("L1_SingleTauJet52_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleTauJet52"], &b_L1_SingleTauJet52_Prescl);
  fChain->SetBranchAddress("L1_DoubleTauJet28_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleTauJet28"], &b_L1_DoubleTauJet28_Prescl);
  fChain->SetBranchAddress("L1_SingleJet20_NotBptxOR_NotMuBeamHalo_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleJet20_NotBptxOR_NotMuBeamHalo"], &b_L1_SingleJet20_NotBptxOR_NotMuBeamHalo_Prescl);
  fChain->SetBranchAddress("L1_SingleJet16_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleJet16"], &b_L1_SingleJet16_Prescl);
  fChain->SetBranchAddress("L1_SingleJet68_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleJet68"], &b_L1_SingleJet68_Prescl);
  fChain->SetBranchAddress("L1_SingleJet92_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleJet92"], &b_L1_SingleJet92_Prescl);
  fChain->SetBranchAddress("L1_DoubleForJet32_EtaOpp_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleForJet32_EtaOpp"], &b_L1_DoubleForJet32_EtaOpp_Prescl);
  fChain->SetBranchAddress("L1_DoubleForJet44_EtaOpp_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleForJet44_EtaOpp"], &b_L1_DoubleForJet44_EtaOpp_Prescl);
  fChain->SetBranchAddress("L1_DoubleEG2_FwdVeto_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleEG2_FwdVeto"], &b_L1_DoubleEG2_FwdVeto_Prescl);
  fChain->SetBranchAddress("L1_SingleJet36_FwdVeto_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleJet36_FwdVeto"], &b_L1_SingleJet36_FwdVeto_Prescl);
  fChain->SetBranchAddress("L1_TripleEG7_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_TripleEG7"], &b_L1_TripleEG7_Prescl);
  fChain->SetBranchAddress("L1_TripleEG5_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_TripleEG5"], &b_L1_TripleEG5_Prescl);
  fChain->SetBranchAddress("L1_TripleJet28_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_TripleJet28"], &b_L1_TripleJet28_Prescl);
  fChain->SetBranchAddress("L1_Mu0_HTT50_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Mu0_HTT50"], &b_L1_Mu0_HTT50_Prescl);
  fChain->SetBranchAddress("L1_SingleEG12_Eta2p17_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleEG12_Eta2p17"], &b_L1_SingleEG12_Eta2p17_Prescl);
  fChain->SetBranchAddress("L1_SingleEG30_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleEG30"], &b_L1_SingleEG30_Prescl);
  fChain->SetBranchAddress("L1_Mu3_Jet20_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Mu3_Jet20"], &b_L1_Mu3_Jet20_Prescl);
  fChain->SetBranchAddress("L1_Mu3_Jet16_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Mu3_Jet16"], &b_L1_Mu3_Jet16_Prescl);
  fChain->SetBranchAddress("L1_SingleMu16_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleMu16"], &b_L1_SingleMu16_Prescl);
  fChain->SetBranchAddress("L1_SingleMu25_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleMu25"], &b_L1_SingleMu25_Prescl);
  fChain->SetBranchAddress("L1_DoubleMu5_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleMu5"], &b_L1_DoubleMu5_Prescl);
  fChain->SetBranchAddress("L1_SingleMu5_Eta1p5_Q80_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleMu5_Eta1p5_Q80"], &b_L1_SingleMu5_Eta1p5_Q80_Prescl);
  fChain->SetBranchAddress("L1_DoubleMu_0_5_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleMu_0_5"], &b_L1_DoubleMu_0_5_Prescl);
  fChain->SetBranchAddress("L1_SingleMu12_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleMu12"], &b_L1_SingleMu12_Prescl);
  fChain->SetBranchAddress("L1_DoubleMu0_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleMu0"], &b_L1_DoubleMu0_Prescl);
  fChain->SetBranchAddress("L1_QuadJet20_Central_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_QuadJet20_Central"], &b_L1_QuadJet20_Central_Prescl);
  fChain->SetBranchAddress("L1_DoubleJet36_Central_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleJet36_Central"], &b_L1_DoubleJet36_Central_Prescl);
  fChain->SetBranchAddress("L1_SingleJet52_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleJet52"], &b_L1_SingleJet52_Prescl);
  fChain->SetBranchAddress("L1_SingleJet36_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleJet36"], &b_L1_SingleJet36_Prescl);
   fChain->SetBranchAddress("L1_Mu3_Jet10_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Mu3_Jet10"], &b_L1_Mu3_Jet10_Prescl);
   fChain->SetBranchAddress("L1_SingleJet10U_NotBptxOR_Ext_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleJet10U_NotBptxOR_Ext"], &b_L1_SingleJet10U_NotBptxOR_Ext_Prescl);
   fChain->SetBranchAddress("L1_SingleJet10_NotBptxOR_Ext_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleJet10_NotBptxOR_Ext"], &b_L1_SingleJet10_NotBptxOR_Ext_Prescl);
   fChain->SetBranchAddress("L1_SingleJet10U_NotBptxOR_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleJet10U_NotBptxOR"], &b_L1_SingleJet10U_NotBptxOR_Prescl);
   fChain->SetBranchAddress("L1_SingleJet10_NotBptxOR_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleJet10_NotBptxOR"], &b_L1_SingleJet10_NotBptxOR_Prescl);
   fChain->SetBranchAddress("L1_Mu3_EG5_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Mu3_EG5"], &b_L1_Mu3_EG5_Prescl);

   fChain->SetBranchAddress("L1Tech_BPTX_plus_OR_minus.v0_Prescl", &map_RefPrescaleOfStandardHLTPath["L1Tech_BPTX_plus_OR_minus.v0"], &b_L1Tech_BPTX_plus_OR_minus_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_BPTX_plus_AND_minus_instance1.v0_Prescl", &map_RefPrescaleOfStandardHLTPath["L1Tech_BPTX_plus_AND_minus_instance1.v0"], &b_L1Tech_BPTX_plus_AND_minus_instance1_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_BSC_minBias_OR.v0_Prescl", &map_RefPrescaleOfStandardHLTPath["L1Tech_BSC_minBias_OR.v0"], &b_L1Tech_BSC_minBias_OR_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_BSC_minBias_threshold1.v0_Prescl", &map_RefPrescaleOfStandardHLTPath["L1Tech_BSC_minBias_threshold1.v0"], &b_L1Tech_BSC_minBias_threshold1_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_BSC_minBias_threshold2.v0_Prescl", &map_RefPrescaleOfStandardHLTPath["L1Tech_BSC_minBias_threshold2.v0"], &b_L1Tech_BSC_minBias_threshold2_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_BSC_minBias_inner_threshold1.v0_Prescl", &map_RefPrescaleOfStandardHLTPath["L1Tech_BSC_minBias_inner_threshold1.v0"], &b_L1Tech_BSC_minBias_inner_threshold1_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_BSC_minBias_inner_threshold2.v0_Prescl", &map_RefPrescaleOfStandardHLTPath["L1Tech_BSC_minBias_inner_threshold2.v0"], &b_L1Tech_BSC_minBias_inner_threshold2_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_BSC_halo_beam1_inner.v0_Prescl", &map_RefPrescaleOfStandardHLTPath["L1Tech_BSC_halo_beam1_inner.v0"], &b_L1Tech_BSC_halo_beam1_inner_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_BSC_halo_beam1_outer.v0_Prescl", &map_RefPrescaleOfStandardHLTPath["L1Tech_BSC_halo_beam1_outer.v0"], &b_L1Tech_BSC_halo_beam1_outer_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_BSC_halo_beam2_inner.v0_Prescl", &map_RefPrescaleOfStandardHLTPath["L1Tech_BSC_halo_beam2_inner.v0"], &b_L1Tech_BSC_halo_beam2_inner_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_BSC_halo_beam2_outer.v0_Prescl", &map_RefPrescaleOfStandardHLTPath["L1Tech_BSC_halo_beam2_outer.v0"], &b_L1Tech_BSC_halo_beam2_outer_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_BSC_HighMultiplicity.v0_Prescl", &map_RefPrescaleOfStandardHLTPath["L1Tech_BSC_HighMultiplicity.v0"], &b_L1Tech_BSC_HighMultiplicity_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_BSC_splash_beam1.v0_Prescl", &map_RefPrescaleOfStandardHLTPath["L1Tech_BSC_splash_beam1.v0"], &b_L1Tech_BSC_splash_beam1_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_BSC_splash_beam2.v0_Prescl", &map_RefPrescaleOfStandardHLTPath["L1Tech_BSC_splash_beam2.v0"], &b_L1Tech_BSC_splash_beam2_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_RPC_TTU_barrel_Cosmics.v0_Prescl", &map_RefPrescaleOfStandardHLTPath["L1Tech_RPC_TTU_barrel_Cosmics.v0"], &b_L1Tech_RPC_TTU_barrel_Cosmics_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_RPC_TTU_pointing_Cosmics.v0_Prescl", &map_RefPrescaleOfStandardHLTPath["L1Tech_RPC_TTU_pointing_Cosmics.v0"], &b_L1Tech_RPC_TTU_pointing_Cosmics_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_RPC_TTU_RBst1_collisions.v0_Prescl", &map_RefPrescaleOfStandardHLTPath["L1Tech_RPC_TTU_RBst1_collisions.v0"], &b_L1Tech_RPC_TTU_RBst1_collisions_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_HCAL_HF_MM_or_PP_or_PM.v0_Prescl", &map_RefPrescaleOfStandardHLTPath["L1Tech_HCAL_HF_MM_or_PP_or_PM.v0"], &b_L1Tech_HCAL_HF_MM_or_PP_or_PM_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_HCAL_HF_coincidence_PM.v1_Prescl", &map_RefPrescaleOfStandardHLTPath["L1Tech_HCAL_HF_coincidence_PM.v1"], &b_L1Tech_HCAL_HF_coincidence_PM_v1_Prescl);
   fChain->SetBranchAddress("L1Tech_HCAL_HF_MMP_or_MPP.v0_Prescl", &map_RefPrescaleOfStandardHLTPath["L1Tech_HCAL_HF_MMP_or_MPP.v0"], &b_L1Tech_HCAL_HF_MMP_or_MPP_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_HCAL_HO_totalOR.v0_Prescl", &map_RefPrescaleOfStandardHLTPath["L1Tech_HCAL_HO_totalOR.v0"], &b_L1Tech_HCAL_HO_totalOR_v0_Prescl);
   fChain->SetBranchAddress("L1Tech_HCAL_HBHE_totalOR.v0_Prescl", &map_RefPrescaleOfStandardHLTPath["L1Tech_HCAL_HBHE_totalOR.v0"], &b_L1Tech_HCAL_HBHE_totalOR_v0_Prescl);
   fChain->SetBranchAddress("L1_BptxPlusORMinus_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_BptxPlusORMinus"], &b_L1_BptxPlusORMinus_Prescl);
   fChain->SetBranchAddress("L1_BptxPlus_NotBptxMinus_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_BptxPlus_NotBptxMinus"], &b_L1_BptxPlus_NotBptxMinus_Prescl);
   fChain->SetBranchAddress("L1_BptxMinus_NotBptxPlus_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_BptxMinus_NotBptxPlus"], &b_L1_BptxMinus_NotBptxPlus_Prescl);
   fChain->SetBranchAddress("L1_BptxXOR_BscMinBiasOR_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_BptxXOR_BscMinBiasOR"], &b_L1_BptxXOR_BscMinBiasOR);
   fChain->SetBranchAddress("L1_Mu5_Jet6_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Mu5_Jet6"], &b_L1_Mu5_Jet6_Prescl);
   fChain->SetBranchAddress("L1_EG5_TripleJet6_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_EG5_TripleJet6"], &b_L1_EG5_TripleJet6_Prescl);
   fChain->SetBranchAddress("L1_SingleJet6_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleJet6"], &b_L1_SingleJet6_Prescl);
   fChain->SetBranchAddress("L1_SingleJet10_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleJet10"], &b_L1_SingleJet10_Prescl);
   fChain->SetBranchAddress("L1_SingleJet10_NotBptxC_Ext_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleJet10_NotBptxC_Ext"], &b_L1_SingleJet10_NotBptxC_Ext);
   fChain->SetBranchAddress("L1_DoubleEG1_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleEG1"], &b_L1_DoubleEG1_Prescl);
   fChain->SetBranchAddress("L1_DoubleEG2_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleEG2"], &b_L1_DoubleEG2_Prescl);
   fChain->SetBranchAddress("L1_DoubleEG5_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleEG5"], &b_L1_DoubleEG5_Prescl);
   fChain->SetBranchAddress("L1_DoubleHfBitCountsRing1_P1N1_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleHfBitCountsRing1_P1N1"], &b_L1_DoubleHfBitCountsRing1_P1N1_Prescl);
   fChain->SetBranchAddress("L1_DoubleHfBitCountsRing2_P1N1_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleHfBitCountsRing2_P1N1"], &b_L1_DoubleHfBitCountsRing2_P1N1_Prescl);
   fChain->SetBranchAddress("L1_DoubleHfRingEtSumsRing1_P200N200_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleHfRingEtSumsRing1_P200N200"], &b_L1_DoubleHfRingEtSumsRing1_P200N200_Prescl);
   fChain->SetBranchAddress("L1_DoubleHfRingEtSumsRing1_P4N4_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleHfRingEtSumsRing1_P4N4"], &b_L1_DoubleHfRingEtSumsRing1_P4N4_Prescl);
   fChain->SetBranchAddress("L1_DoubleHfRingEtSumsRing2_P200N200_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleHfRingEtSumsRing2_P200N200"], &b_L1_DoubleHfRingEtSumsRing2_P200N200_Prescl);
   fChain->SetBranchAddress("L1_DoubleHfRingEtSumsRing2_P4N4_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleHfRingEtSumsRing2_P4N4"], &b_L1_DoubleHfRingEtSumsRing2_P4N4_Prescl);
   fChain->SetBranchAddress("L1_DoubleJet70_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleJet70"], &b_L1_DoubleJet70_Prescl);
   fChain->SetBranchAddress("L1_DoubleMu3_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleMu3"], &b_L1_DoubleMu3_Prescl);
   fChain->SetBranchAddress("L1_DoubleMuOpen_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleMuOpen"], &b_L1_DoubleMuOpen_Prescl);
   fChain->SetBranchAddress("L1_DoubleTauJet30_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleTauJet30"], &b_L1_DoubleTauJet30_Prescl);
   fChain->SetBranchAddress("L1_EG10_Jet15_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_EG10_Jet15"], &b_L1_EG10_Jet15_Prescl);
   fChain->SetBranchAddress("L1_EG5_TripleJet15_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_EG5_TripleJet15"], &b_L1_EG5_TripleJet15_Prescl);
   fChain->SetBranchAddress("L1_ETM20_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_ETM20"], &b_L1_ETM20_Prescl);
   fChain->SetBranchAddress("L1_ETM30_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_ETM30"], &b_L1_ETM30_Prescl);
   fChain->SetBranchAddress("L1_ETM40_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_ETM40"], &b_L1_ETM40_Prescl);
   fChain->SetBranchAddress("L1_ETM70_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_ETM70"], &b_L1_ETM70_Prescl);
   fChain->SetBranchAddress("L1_ETM80_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_ETM80"], &b_L1_ETM80_Prescl);
   fChain->SetBranchAddress("L1_ETT60_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_ETT60"], &b_L1_ETT60_Prescl);
   fChain->SetBranchAddress("L1_ETT100_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_ETT100"], &b_L1_ETT100_Prescl);
   fChain->SetBranchAddress("L1_ETT140_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_ETT140"], &b_L1_ETT140_Prescl);
   fChain->SetBranchAddress("L1_HTT50_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_HTT50"], &b_L1_HTT50_Prescl);
   fChain->SetBranchAddress("L1_HTT100_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_HTT100"], &b_L1_HTT100_Prescl);
   fChain->SetBranchAddress("L1_HTT200_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_HTT200"], &b_L1_HTT200_Prescl);
   fChain->SetBranchAddress("L1_HTT300_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_HTT300"], &b_L1_HTT300_Prescl);
   fChain->SetBranchAddress("L1_IsoEG10_Jet15_ForJet10_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_IsoEG10_Jet15_ForJet10"], &b_L1_IsoEG10_Jet15_ForJet10_Prescl);
   fChain->SetBranchAddress("L1_MinBias_HTT10_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_MinBias_HTT10"], &b_L1_MinBias_HTT10_Prescl);
   fChain->SetBranchAddress("L1_Mu3QE8_EG5_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Mu3QE8_EG5"], &b_L1_Mu3QE8_EG5_Prescl);
   fChain->SetBranchAddress("L1_Mu3QE8_Jet15_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Mu3QE8_Jet15"], &b_L1_Mu3QE8_Jet15_Prescl);
   fChain->SetBranchAddress("L1_Mu5QE8_Jet15_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Mu5QE8_Jet15"], &b_L1_Mu5QE8_Jet15_Prescl);
   fChain->SetBranchAddress("L1_Mu3QE8_Jet6_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Mu3QE8_Jet6"], &b_L1_Mu3QE8_Jet6_Prescl);
   fChain->SetBranchAddress("L1_Mu5QE8_Jet6_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Mu5QE8_Jet6"], &b_L1_Mu5QE8_Jet6_Prescl);
   fChain->SetBranchAddress("L1_QuadJet15_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_QuadJet15"], &b_L1_QuadJet15_Prescl);
   fChain->SetBranchAddress("L1_SingleEG1_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleEG1"], &b_L1_SingleEG1_Prescl);
   fChain->SetBranchAddress("L1_SingleEG10_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleEG10"], &b_L1_SingleEG10_Prescl);
   fChain->SetBranchAddress("L1_SingleEG12_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleEG12"], &b_L1_SingleEG12_Prescl);
   fChain->SetBranchAddress("L1_SingleEG15_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleEG15"], &b_L1_SingleEG15_Prescl);
   fChain->SetBranchAddress("L1_SingleEG2_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleEG2"], &b_L1_SingleEG2_Prescl);
   fChain->SetBranchAddress("L1_SingleEG20_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleEG20"], &b_L1_SingleEG20_Prescl);
   fChain->SetBranchAddress("L1_SingleEG5_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleEG5"], &b_L1_SingleEG5_Prescl);
   fChain->SetBranchAddress("L1_SingleEG8_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleEG8"], &b_L1_SingleEG8_Prescl);
   fChain->SetBranchAddress("L1_SingleHfBitCountsRing1_1_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleHfBitCountsRing1_1"], &b_L1_SingleHfBitCountsRing1_1_Prescl);
   fChain->SetBranchAddress("L1_SingleHfBitCountsRing2_1_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleHfBitCountsRing2_1"], &b_L1_SingleHfBitCountsRing2_1_Prescl);
   fChain->SetBranchAddress("L1_SingleHfRingEtSumsRing1_200_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleHfRingEtSumsRing1_200"], &b_L1_SingleHfRingEtSumsRing1_200_Prescl);
   fChain->SetBranchAddress("L1_SingleHfRingEtSumsRing1_4_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleHfRingEtSumsRing1_4"], &b_L1_SingleHfRingEtSumsRing1_4_Prescl);
   fChain->SetBranchAddress("L1_SingleHfRingEtSumsRing2_200_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleHfRingEtSumsRing2_200"], &b_L1_SingleHfRingEtSumsRing2_200_Prescl);
   fChain->SetBranchAddress("L1_SingleHfRingEtSumsRing2_4_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleHfRingEtSumsRing2_4"], &b_L1_SingleHfRingEtSumsRing2_4_Prescl);
   fChain->SetBranchAddress("L1_SingleIsoEG10_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleIsoEG10"], &b_L1_SingleIsoEG10_Prescl);
   fChain->SetBranchAddress("L1_SingleIsoEG12_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleIsoEG12"], &b_L1_SingleIsoEG12_Prescl);
   fChain->SetBranchAddress("L1_SingleIsoEG15_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleIsoEG15"], &b_L1_SingleIsoEG15_Prescl);
   fChain->SetBranchAddress("L1_SingleIsoEG5_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleIsoEG5"], &b_L1_SingleIsoEG5_Prescl);
   fChain->SetBranchAddress("L1_SingleIsoEG8_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleIsoEG8"], &b_L1_SingleIsoEG8_Prescl);
   fChain->SetBranchAddress("L1_SingleJet100_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleJet100"], &b_L1_SingleJet100_Prescl);
   fChain->SetBranchAddress("L1_SingleJet15_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleJet15"], &b_L1_SingleJet15_Prescl);
   fChain->SetBranchAddress("L1_SingleJet30_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleJet30"], &b_L1_SingleJet30_Prescl);
   fChain->SetBranchAddress("L1_SingleJet50_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleJet50"], &b_L1_SingleJet50_Prescl);
   fChain->SetBranchAddress("L1_SingleJet70_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleJet70"], &b_L1_SingleJet70_Prescl);
   fChain->SetBranchAddress("L1_SingleMu0_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleMu0"], &b_L1_SingleMu0_Prescl);
   fChain->SetBranchAddress("L1_SingleMu10_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleMu10"], &b_L1_SingleMu10_Prescl);
   fChain->SetBranchAddress("L1_SingleMu14_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleMu14"], &b_L1_SingleMu14_Prescl);
   fChain->SetBranchAddress("L1_SingleMu20_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleMu20"], &b_L1_SingleMu20_Prescl);
   fChain->SetBranchAddress("L1_SingleMu3_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleMu3"], &b_L1_SingleMu3_Prescl);
   fChain->SetBranchAddress("L1_SingleMu5_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleMu5"], &b_L1_SingleMu5_Prescl);
   fChain->SetBranchAddress("L1_SingleMu7_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleMu7"], &b_L1_SingleMu7_Prescl);
   fChain->SetBranchAddress("L1_SingleMuBeamHalo_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleMuBeamHalo"], &b_L1_SingleMuBeamHalo_Prescl);
   fChain->SetBranchAddress("L1_SingleMuOpen_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleMuOpen"], &b_L1_SingleMuOpen_Prescl);
   fChain->SetBranchAddress("L1_SingleTauJet40_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleTauJet40"], &b_L1_SingleTauJet40_Prescl);
   fChain->SetBranchAddress("L1_SingleTauJet60_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleTauJet60"], &b_L1_SingleTauJet60_Prescl);
   fChain->SetBranchAddress("L1_SingleTauJet80_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleTauJet80"], &b_L1_SingleTauJet80_Prescl);
   fChain->SetBranchAddress("L1_TripleJet30_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_TripleJet30"], &b_L1_TripleJet30_Prescl);
   fChain->SetBranchAddress("L1_ZeroBias_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_ZeroBias"], &b_L1_ZeroBias_Prescl);
   fChain->SetBranchAddress("L1_ZeroBias_Ext_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_ZeroBias_Ext"], &b_L1_ZeroBias_Ext_Prescl);
   fChain->SetBranchAddress("L1_SingleCenJet2_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleCenJet2"], &b_L1_SingleCenJet2_Prescl);
   fChain->SetBranchAddress("L1_SingleCenJet4_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleCenJet4"], &b_L1_SingleCenJet4_Prescl);
   fChain->SetBranchAddress("L1_SingleForJet2_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleForJet2"], &b_L1_SingleForJet2_Prescl);
   fChain->SetBranchAddress("L1_SingleForJet4_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleForJet4"], &b_L1_SingleForJet4_Prescl);
   fChain->SetBranchAddress("L1_SingleTauJet2_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleTauJet2"], &b_L1_SingleTauJet2_Prescl);
   fChain->SetBranchAddress("L1_SingleTauJet4_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleTauJet4"], &b_L1_SingleTauJet4_Prescl);
   fChain->SetBranchAddress("L1_DoubleForJet10_EtaOpp_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleForJet10_EtaOpp"], &b_L1_DoubleForJet10_EtaOpp_Prescl);
   fChain->SetBranchAddress("L1_Mu3_Jet6_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_Mu3_Jet6"], &b_L1_Mu3_Jet6_Prescl);
   fChain->SetBranchAddress("L1_BscMinBiasOR_BptxPlusORMinus_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_BscMinBiasOR_BptxPlusORMinus"], &b_L1_BscMinBiasOR_BptxPlusORMinus_Prescl);
   fChain->SetBranchAddress("L1_BscMinBiasOR_BptxPlusANDMinus_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_BscMinBiasOR_BptxPlusANDMinus"], &b_L1_BscMinBiasOR_BptxPlusANDMinus_Prescl);
   fChain->SetBranchAddress("L1_DoubleMuTopBottom_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleMuTopBottom"], &b_L1_DoubleMuTopBottom_Prescl);
   fChain->SetBranchAddress("L1_DoubleEG05_TopBottom_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleEG05_TopBottom"], &b_L1_DoubleEG05_TopBottom_Prescl);
   fChain->SetBranchAddress("L1_SingleJet20_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleJet20"], &b_L1_SingleJet20_Prescl);
   fChain->SetBranchAddress("L1_SingleJet40_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleJet40"], &b_L1_SingleJet40_Prescl);
   fChain->SetBranchAddress("L1_SingleJet60_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleJet60"], &b_L1_SingleJet60_Prescl);
   fChain->SetBranchAddress("L1_SingleTauJet10_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleTauJet10"], &b_L1_SingleTauJet10_Prescl);
   fChain->SetBranchAddress("L1_SingleTauJet20_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleTauJet20"], &b_L1_SingleTauJet20_Prescl);
   fChain->SetBranchAddress("L1_SingleTauJet30_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleTauJet30"], &b_L1_SingleTauJet30_Prescl);
   fChain->SetBranchAddress("L1_SingleTauJet50_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_SingleTauJet50"], &b_L1_SingleTauJet50_Prescl);
   fChain->SetBranchAddress("L1_DoubleJet30_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleJet30"], &b_L1_DoubleJet30_Prescl);
   fChain->SetBranchAddress("L1_DoubleTauJet14_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_DoubleTauJet14"], &b_L1_DoubleTauJet14_Prescl);
   fChain->SetBranchAddress("L1_TripleJet14_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_TripleJet14"], &b_L1_TripleJet14_Prescl);
   fChain->SetBranchAddress("L1_QuadJet6_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_QuadJet6"], &b_L1_QuadJet6_Prescl);
   fChain->SetBranchAddress("L1_QuadJet8_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_QuadJet8"], &b_L1_QuadJet8_Prescl);
   fChain->SetBranchAddress("L1_IsoEG10_Jet6_ForJet6_Prescl", &map_RefPrescaleOfStandardHLTPath["L1_IsoEG10_Jet6_ForJet6"], &b_L1_IsoEG10_Jet6_ForJet6_Prescl);



   // Autogenerated from ConfDB - SetBranchAddressMaps
   fChain->SetBranchAddress("HLT_PFJet40_v6", &map_BitOfStandardHLTPath["HLT_PFJet40_v6"], &b_HLT_PFJet40_v6);
   fChain->SetBranchAddress("HLT_PFJet80_v6", &map_BitOfStandardHLTPath["HLT_PFJet80_v6"], &b_HLT_PFJet80_v6);
   fChain->SetBranchAddress("HLT_PFJet140_v6", &map_BitOfStandardHLTPath["HLT_PFJet140_v6"], &b_HLT_PFJet140_v6);
   fChain->SetBranchAddress("HLT_PFJet200_v6", &map_BitOfStandardHLTPath["HLT_PFJet200_v6"], &b_HLT_PFJet200_v6);
   fChain->SetBranchAddress("HLT_PFJet260_v6", &map_BitOfStandardHLTPath["HLT_PFJet260_v6"], &b_HLT_PFJet260_v6);
   fChain->SetBranchAddress("HLT_PFJet320_v6", &map_BitOfStandardHLTPath["HLT_PFJet320_v6"], &b_HLT_PFJet320_v6);
   fChain->SetBranchAddress("HLT_Jet370_NoJetID_v14", &map_BitOfStandardHLTPath["HLT_Jet370_NoJetID_v14"], &b_HLT_Jet370_NoJetID_v14);
   fChain->SetBranchAddress("HLT_PFJet400_v6", &map_BitOfStandardHLTPath["HLT_PFJet400_v6"], &b_HLT_PFJet400_v6);
   fChain->SetBranchAddress("HLT_MonoCentralPFJet80_PFMETnoMu105_NHEF0p95_v1", &map_BitOfStandardHLTPath["HLT_MonoCentralPFJet80_PFMETnoMu105_NHEF0p95_v1"], &b_HLT_MonoCentralPFJet80_PFMETnoMu105_NHEF0p95_v1);
   fChain->SetBranchAddress("HLT_SingleForJet25_v3", &map_BitOfStandardHLTPath["HLT_SingleForJet25_v3"], &b_HLT_SingleForJet25_v3);
   fChain->SetBranchAddress("HLT_SingleForJet15_v3", &map_BitOfStandardHLTPath["HLT_SingleForJet15_v3"], &b_HLT_SingleForJet15_v3);
   fChain->SetBranchAddress("HLT_DiPFJetAve40_v7", &map_BitOfStandardHLTPath["HLT_DiPFJetAve40_v7"], &b_HLT_DiPFJetAve40_v7);
   fChain->SetBranchAddress("HLT_DiPFJetAve80_v7", &map_BitOfStandardHLTPath["HLT_DiPFJetAve80_v7"], &b_HLT_DiPFJetAve80_v7);
   fChain->SetBranchAddress("HLT_DiPFJetAve140_v7", &map_BitOfStandardHLTPath["HLT_DiPFJetAve140_v7"], &b_HLT_DiPFJetAve140_v7);
   fChain->SetBranchAddress("HLT_DiPFJetAve200_v7", &map_BitOfStandardHLTPath["HLT_DiPFJetAve200_v7"], &b_HLT_DiPFJetAve200_v7);
   fChain->SetBranchAddress("HLT_DiPFJetAve260_v7", &map_BitOfStandardHLTPath["HLT_DiPFJetAve260_v7"], &b_HLT_DiPFJetAve260_v7);
   fChain->SetBranchAddress("HLT_DiPFJetAve320_v7", &map_BitOfStandardHLTPath["HLT_DiPFJetAve320_v7"], &b_HLT_DiPFJetAve320_v7);
   fChain->SetBranchAddress("HLT_DiPFJetAve400_v7", &map_BitOfStandardHLTPath["HLT_DiPFJetAve400_v7"], &b_HLT_DiPFJetAve400_v7);
   fChain->SetBranchAddress("HLT_FatDiPFJetMass750_DR1p1_Deta1p5_v6", &map_BitOfStandardHLTPath["HLT_FatDiPFJetMass750_DR1p1_Deta1p5_v6"], &b_HLT_FatDiPFJetMass750_DR1p1_Deta1p5_v6);
   fChain->SetBranchAddress("HLT_DoubleJet20_ForwardBackward_v3", &map_BitOfStandardHLTPath["HLT_DoubleJet20_ForwardBackward_v3"], &b_HLT_DoubleJet20_ForwardBackward_v3);
   fChain->SetBranchAddress("HLT_DiJet80_DiJet60_DiJet20_v3", &map_BitOfStandardHLTPath["HLT_DiJet80_DiJet60_DiJet20_v3"], &b_HLT_DiJet80_DiJet60_DiJet20_v3);
   fChain->SetBranchAddress("HLT_DiPFJet40_PFMETnoMu65_MJJ800VBF_AllJets_v6", &map_BitOfStandardHLTPath["HLT_DiPFJet40_PFMETnoMu65_MJJ800VBF_AllJets_v6"], &b_HLT_DiPFJet40_PFMETnoMu65_MJJ800VBF_AllJets_v6);
   fChain->SetBranchAddress("HLT_DiPFJet40_PFMETnoMu65_MJJ600VBF_LeadingJets_v6", &map_BitOfStandardHLTPath["HLT_DiPFJet40_PFMETnoMu65_MJJ600VBF_LeadingJets_v6"], &b_HLT_DiPFJet40_PFMETnoMu65_MJJ600VBF_LeadingJets_v6);
   fChain->SetBranchAddress("HLT_DiJet40Eta2p6_BTagIP3DFastPV_v5", &map_BitOfStandardHLTPath["HLT_DiJet40Eta2p6_BTagIP3DFastPV_v5"], &b_HLT_DiJet40Eta2p6_BTagIP3DFastPV_v5);
   fChain->SetBranchAddress("HLT_DiJet80Eta2p6_BTagIP3DFastPVLoose_v5", &map_BitOfStandardHLTPath["HLT_DiJet80Eta2p6_BTagIP3DFastPVLoose_v5"], &b_HLT_DiJet80Eta2p6_BTagIP3DFastPVLoose_v5);
   fChain->SetBranchAddress("HLT_Jet60Eta1p7_Jet53Eta1p7_DiBTagIP3DFastPV_v5", &map_BitOfStandardHLTPath["HLT_Jet60Eta1p7_Jet53Eta1p7_DiBTagIP3DFastPV_v5"], &b_HLT_Jet60Eta1p7_Jet53Eta1p7_DiBTagIP3DFastPV_v5);
   fChain->SetBranchAddress("HLT_Jet80Eta1p7_Jet70Eta1p7_DiBTagIP3DFastPV_v5", &map_BitOfStandardHLTPath["HLT_Jet80Eta1p7_Jet70Eta1p7_DiBTagIP3DFastPV_v5"], &b_HLT_Jet80Eta1p7_Jet70Eta1p7_DiBTagIP3DFastPV_v5);
   fChain->SetBranchAddress("HLT_Jet160Eta2p4_Jet120Eta2p4_DiBTagIP3DFastPVLoose_v5", &map_BitOfStandardHLTPath["HLT_Jet160Eta2p4_Jet120Eta2p4_DiBTagIP3DFastPVLoose_v5"], &b_HLT_Jet160Eta2p4_Jet120Eta2p4_DiBTagIP3DFastPVLoose_v5);
   fChain->SetBranchAddress("HLT_QuadJet50_v3", &map_BitOfStandardHLTPath["HLT_QuadJet50_v3"], &b_HLT_QuadJet50_v3);
   fChain->SetBranchAddress("HLT_QuadJet50_Jet20_v2", &map_BitOfStandardHLTPath["HLT_QuadJet50_Jet20_v2"], &b_HLT_QuadJet50_Jet20_v2);
   fChain->SetBranchAddress("HLT_QuadJet60_DiJet20_v3", &map_BitOfStandardHLTPath["HLT_QuadJet60_DiJet20_v3"], &b_HLT_QuadJet60_DiJet20_v3);
   fChain->SetBranchAddress("HLT_QuadJet70_v3", &map_BitOfStandardHLTPath["HLT_QuadJet70_v3"], &b_HLT_QuadJet70_v3);
   fChain->SetBranchAddress("HLT_QuadJet80_v3", &map_BitOfStandardHLTPath["HLT_QuadJet80_v3"], &b_HLT_QuadJet80_v3);
   fChain->SetBranchAddress("HLT_QuadJet90_v3", &map_BitOfStandardHLTPath["HLT_QuadJet90_v3"], &b_HLT_QuadJet90_v3);
   fChain->SetBranchAddress("HLT_QuadJet75_55_35_20_BTagIP_VBF_v4", &map_BitOfStandardHLTPath["HLT_QuadJet75_55_35_20_BTagIP_VBF_v4"], &b_HLT_QuadJet75_55_35_20_BTagIP_VBF_v4);
   fChain->SetBranchAddress("HLT_QuadJet75_55_38_20_BTagIP_VBF_v4", &map_BitOfStandardHLTPath["HLT_QuadJet75_55_38_20_BTagIP_VBF_v4"], &b_HLT_QuadJet75_55_38_20_BTagIP_VBF_v4);
   fChain->SetBranchAddress("HLT_QuadPFJet78_61_44_31_BTagCSV_VBF_v2", &map_BitOfStandardHLTPath["HLT_QuadPFJet78_61_44_31_BTagCSV_VBF_v2"], &b_HLT_QuadPFJet78_61_44_31_BTagCSV_VBF_v2);
   fChain->SetBranchAddress("HLT_QuadPFJet82_65_48_35_BTagCSV_VBF_v2", &map_BitOfStandardHLTPath["HLT_QuadPFJet82_65_48_35_BTagCSV_VBF_v2"], &b_HLT_QuadPFJet82_65_48_35_BTagCSV_VBF_v2);
   fChain->SetBranchAddress("HLT_SixJet35_v3", &map_BitOfStandardHLTPath["HLT_SixJet35_v3"], &b_HLT_SixJet35_v3);
   fChain->SetBranchAddress("HLT_SixJet45_v3", &map_BitOfStandardHLTPath["HLT_SixJet45_v3"], &b_HLT_SixJet45_v3);
   fChain->SetBranchAddress("HLT_SixJet50_v3", &map_BitOfStandardHLTPath["HLT_SixJet50_v3"], &b_HLT_SixJet50_v3);
   fChain->SetBranchAddress("HLT_EightJet30_eta3p0_v2", &map_BitOfStandardHLTPath["HLT_EightJet30_eta3p0_v2"], &b_HLT_EightJet30_eta3p0_v2);
   fChain->SetBranchAddress("HLT_EightJet35_eta3p0_v2", &map_BitOfStandardHLTPath["HLT_EightJet35_eta3p0_v2"], &b_HLT_EightJet35_eta3p0_v2);
   fChain->SetBranchAddress("HLT_ExclDiJet35_HFOR_v3", &map_BitOfStandardHLTPath["HLT_ExclDiJet35_HFOR_v3"], &b_HLT_ExclDiJet35_HFOR_v3);
   fChain->SetBranchAddress("HLT_ExclDiJet35_HFAND_v3", &map_BitOfStandardHLTPath["HLT_ExclDiJet35_HFAND_v3"], &b_HLT_ExclDiJet35_HFAND_v3);
   fChain->SetBranchAddress("HLT_ExclDiJet80_HFAND_v3", &map_BitOfStandardHLTPath["HLT_ExclDiJet80_HFAND_v3"], &b_HLT_ExclDiJet80_HFAND_v3);
   fChain->SetBranchAddress("HLT_JetE30_NoBPTX_v13", &map_BitOfStandardHLTPath["HLT_JetE30_NoBPTX_v13"], &b_HLT_JetE30_NoBPTX_v13);
   fChain->SetBranchAddress("HLT_JetE30_NoBPTX3BX_NoHalo_v14", &map_BitOfStandardHLTPath["HLT_JetE30_NoBPTX3BX_NoHalo_v14"], &b_HLT_JetE30_NoBPTX3BX_NoHalo_v14);
   fChain->SetBranchAddress("HLT_JetE50_NoBPTX3BX_NoHalo_v11", &map_BitOfStandardHLTPath["HLT_JetE50_NoBPTX3BX_NoHalo_v11"], &b_HLT_JetE50_NoBPTX3BX_NoHalo_v11);
   fChain->SetBranchAddress("HLT_JetE70_NoBPTX3BX_NoHalo_v3", &map_BitOfStandardHLTPath["HLT_JetE70_NoBPTX3BX_NoHalo_v3"], &b_HLT_JetE70_NoBPTX3BX_NoHalo_v3);
   fChain->SetBranchAddress("HLT_HT200_AlphaT0p57_v6", &map_BitOfStandardHLTPath["HLT_HT200_AlphaT0p57_v6"], &b_HLT_HT200_AlphaT0p57_v6);
   fChain->SetBranchAddress("HLT_HT200_v4", &map_BitOfStandardHLTPath["HLT_HT200_v4"], &b_HLT_HT200_v4);
   fChain->SetBranchAddress("HLT_HT250_AlphaT0p55_v5", &map_BitOfStandardHLTPath["HLT_HT250_AlphaT0p55_v5"], &b_HLT_HT250_AlphaT0p55_v5);
   fChain->SetBranchAddress("HLT_HT250_AlphaT0p57_v5", &map_BitOfStandardHLTPath["HLT_HT250_AlphaT0p57_v5"], &b_HLT_HT250_AlphaT0p57_v5);
   fChain->SetBranchAddress("HLT_HT250_v4", &map_BitOfStandardHLTPath["HLT_HT250_v4"], &b_HLT_HT250_v4);
   fChain->SetBranchAddress("HLT_HT300_AlphaT0p53_v5", &map_BitOfStandardHLTPath["HLT_HT300_AlphaT0p53_v5"], &b_HLT_HT300_AlphaT0p53_v5);
   fChain->SetBranchAddress("HLT_HT300_AlphaT0p54_v11", &map_BitOfStandardHLTPath["HLT_HT300_AlphaT0p54_v11"], &b_HLT_HT300_AlphaT0p54_v11);
   fChain->SetBranchAddress("HLT_HT300_v4", &map_BitOfStandardHLTPath["HLT_HT300_v4"], &b_HLT_HT300_v4);
   fChain->SetBranchAddress("HLT_HT300_DoubleDisplacedPFJet60_v6", &map_BitOfStandardHLTPath["HLT_HT300_DoubleDisplacedPFJet60_v6"], &b_HLT_HT300_DoubleDisplacedPFJet60_v6);
   fChain->SetBranchAddress("HLT_HT300_DoubleDisplacedPFJet60_ChgFraction10_v6", &map_BitOfStandardHLTPath["HLT_HT300_DoubleDisplacedPFJet60_ChgFraction10_v6"], &b_HLT_HT300_DoubleDisplacedPFJet60_ChgFraction10_v6);
   fChain->SetBranchAddress("HLT_HT300_SingleDisplacedPFJet60_v6", &map_BitOfStandardHLTPath["HLT_HT300_SingleDisplacedPFJet60_v6"], &b_HLT_HT300_SingleDisplacedPFJet60_v6);
   fChain->SetBranchAddress("HLT_HT300_SingleDisplacedPFJet60_ChgFraction10_v6", &map_BitOfStandardHLTPath["HLT_HT300_SingleDisplacedPFJet60_ChgFraction10_v6"], &b_HLT_HT300_SingleDisplacedPFJet60_ChgFraction10_v6);
   fChain->SetBranchAddress("HLT_HT350_v4", &map_BitOfStandardHLTPath["HLT_HT350_v4"], &b_HLT_HT350_v4);
   fChain->SetBranchAddress("HLT_HT350_AlphaT0p52_v5", &map_BitOfStandardHLTPath["HLT_HT350_AlphaT0p52_v5"], &b_HLT_HT350_AlphaT0p52_v5);
   fChain->SetBranchAddress("HLT_HT350_AlphaT0p53_v16", &map_BitOfStandardHLTPath["HLT_HT350_AlphaT0p53_v16"], &b_HLT_HT350_AlphaT0p53_v16);
   fChain->SetBranchAddress("HLT_HT400_v4", &map_BitOfStandardHLTPath["HLT_HT400_v4"], &b_HLT_HT400_v4);
   fChain->SetBranchAddress("HLT_HT400_AlphaT0p51_v16", &map_BitOfStandardHLTPath["HLT_HT400_AlphaT0p51_v16"], &b_HLT_HT400_AlphaT0p51_v16);
   fChain->SetBranchAddress("HLT_HT400_AlphaT0p52_v11", &map_BitOfStandardHLTPath["HLT_HT400_AlphaT0p52_v11"], &b_HLT_HT400_AlphaT0p52_v11);
   fChain->SetBranchAddress("HLT_HT450_AlphaT0p51_v11", &map_BitOfStandardHLTPath["HLT_HT450_AlphaT0p51_v11"], &b_HLT_HT450_AlphaT0p51_v11);
   fChain->SetBranchAddress("HLT_HT450_v4", &map_BitOfStandardHLTPath["HLT_HT450_v4"], &b_HLT_HT450_v4);
   fChain->SetBranchAddress("HLT_HT500_v4", &map_BitOfStandardHLTPath["HLT_HT500_v4"], &b_HLT_HT500_v4);
   fChain->SetBranchAddress("HLT_HT550_v4", &map_BitOfStandardHLTPath["HLT_HT550_v4"], &b_HLT_HT550_v4);
   fChain->SetBranchAddress("HLT_HT650_v4", &map_BitOfStandardHLTPath["HLT_HT650_v4"], &b_HLT_HT650_v4);
   fChain->SetBranchAddress("HLT_HT650_Track50_dEdx3p6_v7", &map_BitOfStandardHLTPath["HLT_HT650_Track50_dEdx3p6_v7"], &b_HLT_HT650_Track50_dEdx3p6_v7);
   fChain->SetBranchAddress("HLT_HT650_Track60_dEdx3p7_v7", &map_BitOfStandardHLTPath["HLT_HT650_Track60_dEdx3p7_v7"], &b_HLT_HT650_Track60_dEdx3p7_v7);
   fChain->SetBranchAddress("HLT_HT750_v4", &map_BitOfStandardHLTPath["HLT_HT750_v4"], &b_HLT_HT750_v4);
   fChain->SetBranchAddress("HLT_PFNoPUHT350_v1", &map_BitOfStandardHLTPath["HLT_PFNoPUHT350_v1"], &b_HLT_PFNoPUHT350_v1);
   fChain->SetBranchAddress("HLT_PFNoPUHT650_v1", &map_BitOfStandardHLTPath["HLT_PFNoPUHT650_v1"], &b_HLT_PFNoPUHT650_v1);
   fChain->SetBranchAddress("HLT_PFNoPUHT650_DiCentralPFNoPUJet80_CenPFNoPUJet40_v1", &map_BitOfStandardHLTPath["HLT_PFNoPUHT650_DiCentralPFNoPUJet80_CenPFNoPUJet40_v1"], &b_HLT_PFNoPUHT650_DiCentralPFNoPUJet80_CenPFNoPUJet40_v1);
   fChain->SetBranchAddress("HLT_PFNoPUHT700_v1", &map_BitOfStandardHLTPath["HLT_PFNoPUHT700_v1"], &b_HLT_PFNoPUHT700_v1);
   fChain->SetBranchAddress("HLT_PFNoPUHT750_v1", &map_BitOfStandardHLTPath["HLT_PFNoPUHT750_v1"], &b_HLT_PFNoPUHT750_v1);
   fChain->SetBranchAddress("HLT_PFMET150_v5", &map_BitOfStandardHLTPath["HLT_PFMET150_v5"], &b_HLT_PFMET150_v5);
   fChain->SetBranchAddress("HLT_PFMET180_v5", &map_BitOfStandardHLTPath["HLT_PFMET180_v5"], &b_HLT_PFMET180_v5);
   fChain->SetBranchAddress("HLT_DiCentralJetSumpT100_dPhi05_DiCentralPFJet60_25_PFMET100_HBHENoiseCleaned_v2", &map_BitOfStandardHLTPath["HLT_DiCentralJetSumpT100_dPhi05_DiCentralPFJet60_25_PFMET100_HBHENoiseCleaned_v2"], &b_HLT_DiCentralJetSumpT100_dPhi05_DiCentralPFJet60_25_PFMET100_HBHENoiseCleaned_v2);
   fChain->SetBranchAddress("HLT_DiCentralPFJet30_PFMET80_v3", &map_BitOfStandardHLTPath["HLT_DiCentralPFJet30_PFMET80_v3"], &b_HLT_DiCentralPFJet30_PFMET80_v3);
   fChain->SetBranchAddress("HLT_DiCentralPFNoPUJet50_PFMETORPFMETNoMu80_v1", &map_BitOfStandardHLTPath["HLT_DiCentralPFNoPUJet50_PFMETORPFMETNoMu80_v1"], &b_HLT_DiCentralPFNoPUJet50_PFMETORPFMETNoMu80_v1);
   fChain->SetBranchAddress("HLT_DiCentralPFJet30_PFMET80_BTagCSV07_v2", &map_BitOfStandardHLTPath["HLT_DiCentralPFJet30_PFMET80_BTagCSV07_v2"], &b_HLT_DiCentralPFJet30_PFMET80_BTagCSV07_v2);
   fChain->SetBranchAddress("HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05d03_v2", &map_BitOfStandardHLTPath["HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05d03_v2"], &b_HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05d03_v2);
   fChain->SetBranchAddress("HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05d05_v2", &map_BitOfStandardHLTPath["HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05d05_v2"], &b_HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05d05_v2);
   fChain->SetBranchAddress("HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05_v2", &map_BitOfStandardHLTPath["HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05_v2"], &b_HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05_v2);
   fChain->SetBranchAddress("HLT_MET80_v4", &map_BitOfStandardHLTPath["HLT_MET80_v4"], &b_HLT_MET80_v4);
   fChain->SetBranchAddress("HLT_MET80_Track50_dEdx3p6_v5", &map_BitOfStandardHLTPath["HLT_MET80_Track50_dEdx3p6_v5"], &b_HLT_MET80_Track50_dEdx3p6_v5);
   fChain->SetBranchAddress("HLT_MET80_Track60_dEdx3p7_v5", &map_BitOfStandardHLTPath["HLT_MET80_Track60_dEdx3p7_v5"], &b_HLT_MET80_Track60_dEdx3p7_v5);
   fChain->SetBranchAddress("HLT_MET120_v11", &map_BitOfStandardHLTPath["HLT_MET120_v11"], &b_HLT_MET120_v11);
   fChain->SetBranchAddress("HLT_MET120_HBHENoiseCleaned_v4", &map_BitOfStandardHLTPath["HLT_MET120_HBHENoiseCleaned_v4"], &b_HLT_MET120_HBHENoiseCleaned_v4);
   fChain->SetBranchAddress("HLT_MET200_v11", &map_BitOfStandardHLTPath["HLT_MET200_v11"], &b_HLT_MET200_v11);
   fChain->SetBranchAddress("HLT_MET200_HBHENoiseCleaned_v4", &map_BitOfStandardHLTPath["HLT_MET200_HBHENoiseCleaned_v4"], &b_HLT_MET200_HBHENoiseCleaned_v4);
   fChain->SetBranchAddress("HLT_MET300_v3", &map_BitOfStandardHLTPath["HLT_MET300_v3"], &b_HLT_MET300_v3);
   fChain->SetBranchAddress("HLT_MET300_HBHENoiseCleaned_v4", &map_BitOfStandardHLTPath["HLT_MET300_HBHENoiseCleaned_v4"], &b_HLT_MET300_HBHENoiseCleaned_v4);
   fChain->SetBranchAddress("HLT_MET400_v6", &map_BitOfStandardHLTPath["HLT_MET400_v6"], &b_HLT_MET400_v6);
   fChain->SetBranchAddress("HLT_MET400_HBHENoiseCleaned_v4", &map_BitOfStandardHLTPath["HLT_MET400_HBHENoiseCleaned_v4"], &b_HLT_MET400_HBHENoiseCleaned_v4);
   fChain->SetBranchAddress("HLT_L1SingleMuOpen_v7", &map_BitOfStandardHLTPath["HLT_L1SingleMuOpen_v7"], &b_HLT_L1SingleMuOpen_v7);
   fChain->SetBranchAddress("HLT_L1SingleMu12_v2", &map_BitOfStandardHLTPath["HLT_L1SingleMu12_v2"], &b_HLT_L1SingleMu12_v2);
   fChain->SetBranchAddress("HLT_L2Mu70_eta2p1_PFMET55_v2", &map_BitOfStandardHLTPath["HLT_L2Mu70_eta2p1_PFMET55_v2"], &b_HLT_L2Mu70_eta2p1_PFMET55_v2);
   fChain->SetBranchAddress("HLT_L2Mu70_eta2p1_PFMET60_v2", &map_BitOfStandardHLTPath["HLT_L2Mu70_eta2p1_PFMET60_v2"], &b_HLT_L2Mu70_eta2p1_PFMET60_v2);
   fChain->SetBranchAddress("HLT_L2Mu20_eta2p1_NoVertex_v2", &map_BitOfStandardHLTPath["HLT_L2Mu20_eta2p1_NoVertex_v2"], &b_HLT_L2Mu20_eta2p1_NoVertex_v2);
   fChain->SetBranchAddress("HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo_v3", &map_BitOfStandardHLTPath["HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo_v3"], &b_HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo_v3);
   fChain->SetBranchAddress("HLT_L2Mu20_NoVertex_2Cha_NoBPTX3BX_NoHalo_v1", &map_BitOfStandardHLTPath["HLT_L2Mu20_NoVertex_2Cha_NoBPTX3BX_NoHalo_v1"], &b_HLT_L2Mu20_NoVertex_2Cha_NoBPTX3BX_NoHalo_v1);
   fChain->SetBranchAddress("HLT_L2Mu30_NoVertex_2Cha_NoBPTX3BX_NoHalo_v1", &map_BitOfStandardHLTPath["HLT_L2Mu30_NoVertex_2Cha_NoBPTX3BX_NoHalo_v1"], &b_HLT_L2Mu30_NoVertex_2Cha_NoBPTX3BX_NoHalo_v1);
   fChain->SetBranchAddress("HLT_L2TripleMu10_0_0_NoVertex_PFJet40Neutral_v5", &map_BitOfStandardHLTPath["HLT_L2TripleMu10_0_0_NoVertex_PFJet40Neutral_v5"], &b_HLT_L2TripleMu10_0_0_NoVertex_PFJet40Neutral_v5);
   fChain->SetBranchAddress("HLT_DoubleDisplacedMu4_DiPFJet40Neutral_v5", &map_BitOfStandardHLTPath["HLT_DoubleDisplacedMu4_DiPFJet40Neutral_v5"], &b_HLT_DoubleDisplacedMu4_DiPFJet40Neutral_v5);
   fChain->SetBranchAddress("HLT_Mu5_v19", &map_BitOfStandardHLTPath["HLT_Mu5_v19"], &b_HLT_Mu5_v19);
   fChain->SetBranchAddress("HLT_Mu8_v17", &map_BitOfStandardHLTPath["HLT_Mu8_v17"], &b_HLT_Mu8_v17);
   fChain->SetBranchAddress("HLT_Mu12_v17", &map_BitOfStandardHLTPath["HLT_Mu12_v17"], &b_HLT_Mu12_v17);
   fChain->SetBranchAddress("HLT_Mu17_v4", &map_BitOfStandardHLTPath["HLT_Mu17_v4"], &b_HLT_Mu17_v4);
   fChain->SetBranchAddress("HLT_Mu12_eta2p1_L1Mu10erJetC12WdEtaPhi1DiJetsC_v4", &map_BitOfStandardHLTPath["HLT_Mu12_eta2p1_L1Mu10erJetC12WdEtaPhi1DiJetsC_v4"], &b_HLT_Mu12_eta2p1_L1Mu10erJetC12WdEtaPhi1DiJetsC_v4);
   fChain->SetBranchAddress("HLT_Mu15_eta2p1_v4", &map_BitOfStandardHLTPath["HLT_Mu15_eta2p1_v4"], &b_HLT_Mu15_eta2p1_v4);
   fChain->SetBranchAddress("HLT_Mu24_v15", &map_BitOfStandardHLTPath["HLT_Mu24_v15"], &b_HLT_Mu24_v15);
   fChain->SetBranchAddress("HLT_Mu24_eta2p1_v4", &map_BitOfStandardHLTPath["HLT_Mu24_eta2p1_v4"], &b_HLT_Mu24_eta2p1_v4);
   fChain->SetBranchAddress("HLT_Mu30_v15", &map_BitOfStandardHLTPath["HLT_Mu30_v15"], &b_HLT_Mu30_v15);
   fChain->SetBranchAddress("HLT_Mu30_eta2p1_v4", &map_BitOfStandardHLTPath["HLT_Mu30_eta2p1_v4"], &b_HLT_Mu30_eta2p1_v4);
   fChain->SetBranchAddress("HLT_Mu40_v13", &map_BitOfStandardHLTPath["HLT_Mu40_v13"], &b_HLT_Mu40_v13);
   fChain->SetBranchAddress("HLT_Mu40_eta2p1_v10", &map_BitOfStandardHLTPath["HLT_Mu40_eta2p1_v10"], &b_HLT_Mu40_eta2p1_v10);
   fChain->SetBranchAddress("HLT_Mu50_eta2p1_v7", &map_BitOfStandardHLTPath["HLT_Mu50_eta2p1_v7"], &b_HLT_Mu50_eta2p1_v7);
   fChain->SetBranchAddress("HLT_RelIso1p0Mu5_v5", &map_BitOfStandardHLTPath["HLT_RelIso1p0Mu5_v5"], &b_HLT_RelIso1p0Mu5_v5);
   fChain->SetBranchAddress("HLT_RelIso1p0Mu20_v2", &map_BitOfStandardHLTPath["HLT_RelIso1p0Mu20_v2"], &b_HLT_RelIso1p0Mu20_v2);
   fChain->SetBranchAddress("HLT_IsoMu15_eta2p1_L1ETM20_v6", &map_BitOfStandardHLTPath["HLT_IsoMu15_eta2p1_L1ETM20_v6"], &b_HLT_IsoMu15_eta2p1_L1ETM20_v6);
   fChain->SetBranchAddress("HLT_IsoMu20_eta2p1_v6", &map_BitOfStandardHLTPath["HLT_IsoMu20_eta2p1_v6"], &b_HLT_IsoMu20_eta2p1_v6);
   fChain->SetBranchAddress("HLT_IsoMu24_v16", &map_BitOfStandardHLTPath["HLT_IsoMu24_v16"], &b_HLT_IsoMu24_v16);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1_v14", &map_BitOfStandardHLTPath["HLT_IsoMu24_eta2p1_v14"], &b_HLT_IsoMu24_eta2p1_v14);
   fChain->SetBranchAddress("HLT_IsoMu30_v10", &map_BitOfStandardHLTPath["HLT_IsoMu30_v10"], &b_HLT_IsoMu30_v10);
   fChain->SetBranchAddress("HLT_IsoMu30_eta2p1_v14", &map_BitOfStandardHLTPath["HLT_IsoMu30_eta2p1_v14"], &b_HLT_IsoMu30_eta2p1_v14);
   fChain->SetBranchAddress("HLT_IsoMu34_eta2p1_v12", &map_BitOfStandardHLTPath["HLT_IsoMu34_eta2p1_v12"], &b_HLT_IsoMu34_eta2p1_v12);
   fChain->SetBranchAddress("HLT_IsoMu40_eta2p1_v9", &map_BitOfStandardHLTPath["HLT_IsoMu40_eta2p1_v9"], &b_HLT_IsoMu40_eta2p1_v9);
   fChain->SetBranchAddress("HLT_Mu40_eta2p1_Track50_dEdx3p6_v4", &map_BitOfStandardHLTPath["HLT_Mu40_eta2p1_Track50_dEdx3p6_v4"], &b_HLT_Mu40_eta2p1_Track50_dEdx3p6_v4);
   fChain->SetBranchAddress("HLT_Mu40_eta2p1_Track60_dEdx3p7_v4", &map_BitOfStandardHLTPath["HLT_Mu40_eta2p1_Track60_dEdx3p7_v4"], &b_HLT_Mu40_eta2p1_Track60_dEdx3p7_v4);
   fChain->SetBranchAddress("HLT_L2DoubleMu23_NoVertex_v11", &map_BitOfStandardHLTPath["HLT_L2DoubleMu23_NoVertex_v11"], &b_HLT_L2DoubleMu23_NoVertex_v11);
   fChain->SetBranchAddress("HLT_L2DoubleMu23_NoVertex_2Cha_Angle2p5_v3", &map_BitOfStandardHLTPath["HLT_L2DoubleMu23_NoVertex_2Cha_Angle2p5_v3"], &b_HLT_L2DoubleMu23_NoVertex_2Cha_Angle2p5_v3);
   fChain->SetBranchAddress("HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_v3", &map_BitOfStandardHLTPath["HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_v3"], &b_HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_v3);
   fChain->SetBranchAddress("HLT_DoubleMu11_Acoplanarity03_v4", &map_BitOfStandardHLTPath["HLT_DoubleMu11_Acoplanarity03_v4"], &b_HLT_DoubleMu11_Acoplanarity03_v4);
   fChain->SetBranchAddress("HLT_DoubleMu4_Jpsi_Displaced_v10", &map_BitOfStandardHLTPath["HLT_DoubleMu4_Jpsi_Displaced_v10"], &b_HLT_DoubleMu4_Jpsi_Displaced_v10);
   fChain->SetBranchAddress("HLT_DoubleMu4_JpsiTk_Displaced_v4", &map_BitOfStandardHLTPath["HLT_DoubleMu4_JpsiTk_Displaced_v4"], &b_HLT_DoubleMu4_JpsiTk_Displaced_v4);
   fChain->SetBranchAddress("HLT_DoubleMu3_4_Dimuon5_Bs_Central_v3", &map_BitOfStandardHLTPath["HLT_DoubleMu3_4_Dimuon5_Bs_Central_v3"], &b_HLT_DoubleMu3_4_Dimuon5_Bs_Central_v3);
   fChain->SetBranchAddress("HLT_DoubleMu3p5_4_Dimuon5_Bs_Central_v3", &map_BitOfStandardHLTPath["HLT_DoubleMu3p5_4_Dimuon5_Bs_Central_v3"], &b_HLT_DoubleMu3p5_4_Dimuon5_Bs_Central_v3);
   fChain->SetBranchAddress("HLT_DoubleMu4_Dimuon7_Bs_Forward_v3", &map_BitOfStandardHLTPath["HLT_DoubleMu4_Dimuon7_Bs_Forward_v3"], &b_HLT_DoubleMu4_Dimuon7_Bs_Forward_v3);
   fChain->SetBranchAddress("HLT_DoubleMu3p5_LowMass_Displaced_v4", &map_BitOfStandardHLTPath["HLT_DoubleMu3p5_LowMass_Displaced_v4"], &b_HLT_DoubleMu3p5_LowMass_Displaced_v4);
   fChain->SetBranchAddress("HLT_DoubleMu3p5_LowMassNonResonant_Displaced_v4", &map_BitOfStandardHLTPath["HLT_DoubleMu3p5_LowMassNonResonant_Displaced_v4"], &b_HLT_DoubleMu3p5_LowMassNonResonant_Displaced_v4);
   fChain->SetBranchAddress("HLT_Dimuon0_Jpsi_v15", &map_BitOfStandardHLTPath["HLT_Dimuon0_Jpsi_v15"], &b_HLT_Dimuon0_Jpsi_v15);
   fChain->SetBranchAddress("HLT_Dimuon0_Jpsi_NoVertexing_v12", &map_BitOfStandardHLTPath["HLT_Dimuon0_Jpsi_NoVertexing_v12"], &b_HLT_Dimuon0_Jpsi_NoVertexing_v12);
   fChain->SetBranchAddress("HLT_Dimuon0_Upsilon_v15", &map_BitOfStandardHLTPath["HLT_Dimuon0_Upsilon_v15"], &b_HLT_Dimuon0_Upsilon_v15);
   fChain->SetBranchAddress("HLT_Dimuon0_PsiPrime_v4", &map_BitOfStandardHLTPath["HLT_Dimuon0_PsiPrime_v4"], &b_HLT_Dimuon0_PsiPrime_v4);
   fChain->SetBranchAddress("HLT_Dimuon5_Upsilon_v4", &map_BitOfStandardHLTPath["HLT_Dimuon5_Upsilon_v4"], &b_HLT_Dimuon5_Upsilon_v4);
   fChain->SetBranchAddress("HLT_Dimuon5_PsiPrime_v4", &map_BitOfStandardHLTPath["HLT_Dimuon5_PsiPrime_v4"], &b_HLT_Dimuon5_PsiPrime_v4);
   fChain->SetBranchAddress("HLT_Dimuon7_Upsilon_v5", &map_BitOfStandardHLTPath["HLT_Dimuon7_Upsilon_v5"], &b_HLT_Dimuon7_Upsilon_v5);
   fChain->SetBranchAddress("HLT_Dimuon7_PsiPrime_v1", &map_BitOfStandardHLTPath["HLT_Dimuon7_PsiPrime_v1"], &b_HLT_Dimuon7_PsiPrime_v1);
   fChain->SetBranchAddress("HLT_Dimuon8_Jpsi_v5", &map_BitOfStandardHLTPath["HLT_Dimuon8_Jpsi_v5"], &b_HLT_Dimuon8_Jpsi_v5);
   fChain->SetBranchAddress("HLT_Dimuon8_Upsilon_v4", &map_BitOfStandardHLTPath["HLT_Dimuon8_Upsilon_v4"], &b_HLT_Dimuon8_Upsilon_v4);
   fChain->SetBranchAddress("HLT_Dimuon10_Jpsi_v4", &map_BitOfStandardHLTPath["HLT_Dimuon10_Jpsi_v4"], &b_HLT_Dimuon10_Jpsi_v4);
   fChain->SetBranchAddress("HLT_Dimuon11_Upsilon_v4", &map_BitOfStandardHLTPath["HLT_Dimuon11_Upsilon_v4"], &b_HLT_Dimuon11_Upsilon_v4);
   fChain->SetBranchAddress("HLT_Dimuon0_Jpsi_Muon_v16", &map_BitOfStandardHLTPath["HLT_Dimuon0_Jpsi_Muon_v16"], &b_HLT_Dimuon0_Jpsi_Muon_v16);
   fChain->SetBranchAddress("HLT_Dimuon0_Upsilon_Muon_v16", &map_BitOfStandardHLTPath["HLT_Dimuon0_Upsilon_Muon_v16"], &b_HLT_Dimuon0_Upsilon_Muon_v16);
   fChain->SetBranchAddress("HLT_Dimuon3p5_SameSign_v4", &map_BitOfStandardHLTPath["HLT_Dimuon3p5_SameSign_v4"], &b_HLT_Dimuon3p5_SameSign_v4);
   fChain->SetBranchAddress("HLT_DoubleMu4_Acoplanarity03_v4", &map_BitOfStandardHLTPath["HLT_DoubleMu4_Acoplanarity03_v4"], &b_HLT_DoubleMu4_Acoplanarity03_v4);
   fChain->SetBranchAddress("HLT_Tau2Mu_ItTrack_v4", &map_BitOfStandardHLTPath["HLT_Tau2Mu_ItTrack_v4"], &b_HLT_Tau2Mu_ItTrack_v4);
   fChain->SetBranchAddress("HLT_Mu13_Mu8_v18", &map_BitOfStandardHLTPath["HLT_Mu13_Mu8_v18"], &b_HLT_Mu13_Mu8_v18);
   fChain->SetBranchAddress("HLT_Mu17_Mu8_v18", &map_BitOfStandardHLTPath["HLT_Mu17_Mu8_v18"], &b_HLT_Mu17_Mu8_v18);
   fChain->SetBranchAddress("HLT_Mu17_TkMu8_v11", &map_BitOfStandardHLTPath["HLT_Mu17_TkMu8_v11"], &b_HLT_Mu17_TkMu8_v11);
   fChain->SetBranchAddress("HLT_Mu22_TkMu8_v7", &map_BitOfStandardHLTPath["HLT_Mu22_TkMu8_v7"], &b_HLT_Mu22_TkMu8_v7);
   fChain->SetBranchAddress("HLT_Mu22_TkMu22_v7", &map_BitOfStandardHLTPath["HLT_Mu22_TkMu22_v7"], &b_HLT_Mu22_TkMu22_v7);
   fChain->SetBranchAddress("HLT_TripleMu5_v18", &map_BitOfStandardHLTPath["HLT_TripleMu5_v18"], &b_HLT_TripleMu5_v18);
   fChain->SetBranchAddress("HLT_DoubleMu5_IsoMu5_v19", &map_BitOfStandardHLTPath["HLT_DoubleMu5_IsoMu5_v19"], &b_HLT_DoubleMu5_IsoMu5_v19);
   fChain->SetBranchAddress("HLT_Mu5_L2Mu3_Jpsi_v5", &map_BitOfStandardHLTPath["HLT_Mu5_L2Mu3_Jpsi_v5"], &b_HLT_Mu5_L2Mu3_Jpsi_v5);
   fChain->SetBranchAddress("HLT_Mu5_Track2_Jpsi_v19", &map_BitOfStandardHLTPath["HLT_Mu5_Track2_Jpsi_v19"], &b_HLT_Mu5_Track2_Jpsi_v19);
   fChain->SetBranchAddress("HLT_Mu5_Track3p5_Jpsi_v5", &map_BitOfStandardHLTPath["HLT_Mu5_Track3p5_Jpsi_v5"], &b_HLT_Mu5_Track3p5_Jpsi_v5);
   fChain->SetBranchAddress("HLT_Mu7_Track7_Jpsi_v19", &map_BitOfStandardHLTPath["HLT_Mu7_Track7_Jpsi_v19"], &b_HLT_Mu7_Track7_Jpsi_v19);
   fChain->SetBranchAddress("HLT_Photon20_CaloIdVL_v4", &map_BitOfStandardHLTPath["HLT_Photon20_CaloIdVL_v4"], &b_HLT_Photon20_CaloIdVL_v4);
   fChain->SetBranchAddress("HLT_Photon20_CaloIdVL_IsoL_v16", &map_BitOfStandardHLTPath["HLT_Photon20_CaloIdVL_IsoL_v16"], &b_HLT_Photon20_CaloIdVL_IsoL_v16);
   fChain->SetBranchAddress("HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_v5", &map_BitOfStandardHLTPath["HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_v5"], &b_HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_v5);
   fChain->SetBranchAddress("HLT_Photon26_Photon18_v12", &map_BitOfStandardHLTPath["HLT_Photon26_Photon18_v12"], &b_HLT_Photon26_Photon18_v12);
   fChain->SetBranchAddress("HLT_Photon26_R9Id85_Photon18_R9Id85_Mass60_v4", &map_BitOfStandardHLTPath["HLT_Photon26_R9Id85_Photon18_R9Id85_Mass60_v4"], &b_HLT_Photon26_R9Id85_Photon18_R9Id85_Mass60_v4);
   fChain->SetBranchAddress("HLT_Photon26_R9Id85_Photon18_CaloId10_Iso50_Mass60_v6", &map_BitOfStandardHLTPath["HLT_Photon26_R9Id85_Photon18_CaloId10_Iso50_Mass60_v6"], &b_HLT_Photon26_R9Id85_Photon18_CaloId10_Iso50_Mass60_v6);
   fChain->SetBranchAddress("HLT_Photon26_CaloId10_Iso50_Photon18_R9Id85_Mass60_v6", &map_BitOfStandardHLTPath["HLT_Photon26_CaloId10_Iso50_Photon18_R9Id85_Mass60_v6"], &b_HLT_Photon26_CaloId10_Iso50_Photon18_R9Id85_Mass60_v6);
   fChain->SetBranchAddress("HLT_Photon26_CaloId10_Iso50_Photon18_CaloId10_Iso50_Mass60_v6", &map_BitOfStandardHLTPath["HLT_Photon26_CaloId10_Iso50_Photon18_CaloId10_Iso50_Mass60_v6"], &b_HLT_Photon26_CaloId10_Iso50_Photon18_CaloId10_Iso50_Mass60_v6);
   fChain->SetBranchAddress("HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass60_v6", &map_BitOfStandardHLTPath["HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass60_v6"], &b_HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass60_v6);
   fChain->SetBranchAddress("HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass70_v2", &map_BitOfStandardHLTPath["HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass70_v2"], &b_HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass70_v2);
   fChain->SetBranchAddress("HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_v5", &map_BitOfStandardHLTPath["HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_v5"], &b_HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_v5);
   fChain->SetBranchAddress("HLT_Photon30_CaloIdVL_v14", &map_BitOfStandardHLTPath["HLT_Photon30_CaloIdVL_v14"], &b_HLT_Photon30_CaloIdVL_v14);
   fChain->SetBranchAddress("HLT_Photon30_CaloIdVL_IsoL_v19", &map_BitOfStandardHLTPath["HLT_Photon30_CaloIdVL_IsoL_v19"], &b_HLT_Photon30_CaloIdVL_IsoL_v19);
   fChain->SetBranchAddress("HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_v5", &map_BitOfStandardHLTPath["HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_v5"], &b_HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_v5);
   fChain->SetBranchAddress("HLT_Photon36_Photon22_v6", &map_BitOfStandardHLTPath["HLT_Photon36_Photon22_v6"], &b_HLT_Photon36_Photon22_v6);
   fChain->SetBranchAddress("HLT_Photon36_R9Id85_Photon22_R9Id85_v4", &map_BitOfStandardHLTPath["HLT_Photon36_R9Id85_Photon22_R9Id85_v4"], &b_HLT_Photon36_R9Id85_Photon22_R9Id85_v4);
   fChain->SetBranchAddress("HLT_Photon36_R9Id85_Photon22_CaloId10_Iso50_v6", &map_BitOfStandardHLTPath["HLT_Photon36_R9Id85_Photon22_CaloId10_Iso50_v6"], &b_HLT_Photon36_R9Id85_Photon22_CaloId10_Iso50_v6);
   fChain->SetBranchAddress("HLT_Photon36_CaloId10_Iso50_Photon22_R9Id85_v6", &map_BitOfStandardHLTPath["HLT_Photon36_CaloId10_Iso50_Photon22_R9Id85_v6"], &b_HLT_Photon36_CaloId10_Iso50_Photon22_R9Id85_v6);
   fChain->SetBranchAddress("HLT_Photon36_CaloId10_Iso50_Photon22_CaloId10_Iso50_v6", &map_BitOfStandardHLTPath["HLT_Photon36_CaloId10_Iso50_Photon22_CaloId10_Iso50_v6"], &b_HLT_Photon36_CaloId10_Iso50_Photon22_CaloId10_Iso50_v6);
   fChain->SetBranchAddress("HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_R9Id85_OR_CaloId10_Iso50_v6", &map_BitOfStandardHLTPath["HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_R9Id85_OR_CaloId10_Iso50_v6"], &b_HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_R9Id85_OR_CaloId10_Iso50_v6);
   fChain->SetBranchAddress("HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_v5", &map_BitOfStandardHLTPath["HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_v5"], &b_HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_v5);
   fChain->SetBranchAddress("HLT_Photon50_CaloIdVL_v10", &map_BitOfStandardHLTPath["HLT_Photon50_CaloIdVL_v10"], &b_HLT_Photon50_CaloIdVL_v10);
   fChain->SetBranchAddress("HLT_Photon50_CaloIdVL_IsoL_v17", &map_BitOfStandardHLTPath["HLT_Photon50_CaloIdVL_IsoL_v17"], &b_HLT_Photon50_CaloIdVL_IsoL_v17);
   fChain->SetBranchAddress("HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_v5", &map_BitOfStandardHLTPath["HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_v5"], &b_HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_v5);
   fChain->SetBranchAddress("HLT_Photon60_CaloIdL_MHT70_v9", &map_BitOfStandardHLTPath["HLT_Photon60_CaloIdL_MHT70_v9"], &b_HLT_Photon60_CaloIdL_MHT70_v9);
   fChain->SetBranchAddress("HLT_Photon60_CaloIdL_HT300_v2", &map_BitOfStandardHLTPath["HLT_Photon60_CaloIdL_HT300_v2"], &b_HLT_Photon60_CaloIdL_HT300_v2);
   fChain->SetBranchAddress("HLT_Photon70_CaloIdXL_PFNoPUHT400_v1", &map_BitOfStandardHLTPath["HLT_Photon70_CaloIdXL_PFNoPUHT400_v1"], &b_HLT_Photon70_CaloIdXL_PFNoPUHT400_v1);
   fChain->SetBranchAddress("HLT_Photon70_CaloIdXL_PFNoPUHT500_v1", &map_BitOfStandardHLTPath["HLT_Photon70_CaloIdXL_PFNoPUHT500_v1"], &b_HLT_Photon70_CaloIdXL_PFNoPUHT500_v1);
   fChain->SetBranchAddress("HLT_Photon70_CaloIdXL_PFMET100_v5", &map_BitOfStandardHLTPath["HLT_Photon70_CaloIdXL_PFMET100_v5"], &b_HLT_Photon70_CaloIdXL_PFMET100_v5);
   fChain->SetBranchAddress("HLT_Photon75_CaloIdVL_v13", &map_BitOfStandardHLTPath["HLT_Photon75_CaloIdVL_v13"], &b_HLT_Photon75_CaloIdVL_v13);
   fChain->SetBranchAddress("HLT_Photon75_CaloIdVL_IsoL_v18", &map_BitOfStandardHLTPath["HLT_Photon75_CaloIdVL_IsoL_v18"], &b_HLT_Photon75_CaloIdVL_IsoL_v18);
   fChain->SetBranchAddress("HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_v5", &map_BitOfStandardHLTPath["HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_v5"], &b_HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_v5);
   fChain->SetBranchAddress("HLT_Photon90_CaloIdVL_v10", &map_BitOfStandardHLTPath["HLT_Photon90_CaloIdVL_v10"], &b_HLT_Photon90_CaloIdVL_v10);
   fChain->SetBranchAddress("HLT_Photon90_CaloIdVL_IsoL_v15", &map_BitOfStandardHLTPath["HLT_Photon90_CaloIdVL_IsoL_v15"], &b_HLT_Photon90_CaloIdVL_IsoL_v15);
   fChain->SetBranchAddress("HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_v5", &map_BitOfStandardHLTPath["HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_v5"], &b_HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_v5);
   fChain->SetBranchAddress("HLT_DisplacedPhoton65_CaloIdVL_IsoL_PFMET25_v2", &map_BitOfStandardHLTPath["HLT_DisplacedPhoton65_CaloIdVL_IsoL_PFMET25_v2"], &b_HLT_DisplacedPhoton65_CaloIdVL_IsoL_PFMET25_v2);
   fChain->SetBranchAddress("HLT_DisplacedPhoton65EBOnly_CaloIdVL_IsoL_PFMET30_v2", &map_BitOfStandardHLTPath["HLT_DisplacedPhoton65EBOnly_CaloIdVL_IsoL_PFMET30_v2"], &b_HLT_DisplacedPhoton65EBOnly_CaloIdVL_IsoL_PFMET30_v2);
   fChain->SetBranchAddress("HLT_Photon135_v7", &map_BitOfStandardHLTPath["HLT_Photon135_v7"], &b_HLT_Photon135_v7);
   fChain->SetBranchAddress("HLT_Photon150_v4", &map_BitOfStandardHLTPath["HLT_Photon150_v4"], &b_HLT_Photon150_v4);
   fChain->SetBranchAddress("HLT_Photon160_v4", &map_BitOfStandardHLTPath["HLT_Photon160_v4"], &b_HLT_Photon160_v4);
   fChain->SetBranchAddress("HLT_Photon300_NoHE_v5", &map_BitOfStandardHLTPath["HLT_Photon300_NoHE_v5"], &b_HLT_Photon300_NoHE_v5);
   fChain->SetBranchAddress("HLT_DoublePhoton48_HEVT_v8", &map_BitOfStandardHLTPath["HLT_DoublePhoton48_HEVT_v8"], &b_HLT_DoublePhoton48_HEVT_v8);
   fChain->SetBranchAddress("HLT_DoublePhoton53_HEVT_v2", &map_BitOfStandardHLTPath["HLT_DoublePhoton53_HEVT_v2"], &b_HLT_DoublePhoton53_HEVT_v2);
   fChain->SetBranchAddress("HLT_DoublePhoton70_v6", &map_BitOfStandardHLTPath["HLT_DoublePhoton70_v6"], &b_HLT_DoublePhoton70_v6);
   fChain->SetBranchAddress("HLT_DoublePhoton80_v7", &map_BitOfStandardHLTPath["HLT_DoublePhoton80_v7"], &b_HLT_DoublePhoton80_v7);
   fChain->SetBranchAddress("HLT_DoublePhoton5_IsoVL_CEP_v16", &map_BitOfStandardHLTPath["HLT_DoublePhoton5_IsoVL_CEP_v16"], &b_HLT_DoublePhoton5_IsoVL_CEP_v16);
   fChain->SetBranchAddress("HLT_L1SingleEG5_v6", &map_BitOfStandardHLTPath["HLT_L1SingleEG5_v6"], &b_HLT_L1SingleEG5_v6);
   fChain->SetBranchAddress("HLT_L1SingleEG12_v6", &map_BitOfStandardHLTPath["HLT_L1SingleEG12_v6"], &b_HLT_L1SingleEG12_v6);
   fChain->SetBranchAddress("HLT_L1DoubleEG3_FwdVeto_v2", &map_BitOfStandardHLTPath["HLT_L1DoubleEG3_FwdVeto_v2"], &b_HLT_L1DoubleEG3_FwdVeto_v2);
   fChain->SetBranchAddress("HLT_L1ETM30_v2", &map_BitOfStandardHLTPath["HLT_L1ETM30_v2"], &b_HLT_L1ETM30_v2);
   fChain->SetBranchAddress("HLT_L1ETM40_v2", &map_BitOfStandardHLTPath["HLT_L1ETM40_v2"], &b_HLT_L1ETM40_v2);
   fChain->SetBranchAddress("HLT_L1ETM70_v2", &map_BitOfStandardHLTPath["HLT_L1ETM70_v2"], &b_HLT_L1ETM70_v2);
   fChain->SetBranchAddress("HLT_L1ETM100_v2", &map_BitOfStandardHLTPath["HLT_L1ETM100_v2"], &b_HLT_L1ETM100_v2);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdT_TrkIdVL_v5", &map_BitOfStandardHLTPath["HLT_Ele8_CaloIdT_TrkIdVL_v5"], &b_HLT_Ele8_CaloIdT_TrkIdVL_v5);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdT_TrkIdVL_EG7_v2", &map_BitOfStandardHLTPath["HLT_Ele8_CaloIdT_TrkIdVL_EG7_v2"], &b_HLT_Ele8_CaloIdT_TrkIdVL_EG7_v2);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdT_TrkIdVL_Jet30_v5", &map_BitOfStandardHLTPath["HLT_Ele8_CaloIdT_TrkIdVL_Jet30_v5"], &b_HLT_Ele8_CaloIdT_TrkIdVL_Jet30_v5);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdL_CaloIsoVL_v17", &map_BitOfStandardHLTPath["HLT_Ele8_CaloIdL_CaloIsoVL_v17"], &b_HLT_Ele8_CaloIdL_CaloIsoVL_v17);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v15", &map_BitOfStandardHLTPath["HLT_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v15"], &b_HLT_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v15);
   fChain->SetBranchAddress("HLT_Ele17_CaloIdL_CaloIsoVL_v17", &map_BitOfStandardHLTPath["HLT_Ele17_CaloIdL_CaloIsoVL_v17"], &b_HLT_Ele17_CaloIdL_CaloIsoVL_v17);
   fChain->SetBranchAddress("HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v6", &map_BitOfStandardHLTPath["HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v6"], &b_HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v6);
   fChain->SetBranchAddress("HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v18", &map_BitOfStandardHLTPath["HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v18"], &b_HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v18);
   fChain->SetBranchAddress("HLT_Ele17_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_Ele8_Mass50_v6", &map_BitOfStandardHLTPath["HLT_Ele17_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_Ele8_Mass50_v6"], &b_HLT_Ele17_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_Ele8_Mass50_v6);
   fChain->SetBranchAddress("HLT_Ele20_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_SC4_Mass50_v6", &map_BitOfStandardHLTPath["HLT_Ele20_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_SC4_Mass50_v6"], &b_HLT_Ele20_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_SC4_Mass50_v6);
   fChain->SetBranchAddress("HLT_Ele22_CaloIdL_CaloIsoVL_v6", &map_BitOfStandardHLTPath["HLT_Ele22_CaloIdL_CaloIsoVL_v6"], &b_HLT_Ele22_CaloIdL_CaloIsoVL_v6);
   fChain->SetBranchAddress("HLT_Ele27_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_v11", &map_BitOfStandardHLTPath["HLT_Ele27_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_v11"], &b_HLT_Ele27_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_v11);
   fChain->SetBranchAddress("HLT_Ele27_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele15_CaloIdT_CaloIsoVL_trackless_v7", &map_BitOfStandardHLTPath["HLT_Ele27_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele15_CaloIdT_CaloIsoVL_trackless_v7"], &b_HLT_Ele27_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele15_CaloIdT_CaloIsoVL_trackless_v7);
   fChain->SetBranchAddress("HLT_Ele27_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_HFT15_v7", &map_BitOfStandardHLTPath["HLT_Ele27_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_HFT15_v7"], &b_HLT_Ele27_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_HFT15_v7);
   fChain->SetBranchAddress("HLT_Ele23_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_HFT30_v7", &map_BitOfStandardHLTPath["HLT_Ele23_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_HFT30_v7"], &b_HLT_Ele23_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_HFT30_v7);
   fChain->SetBranchAddress("HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet30_v2", &map_BitOfStandardHLTPath["HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet30_v2"], &b_HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet30_v2);
   fChain->SetBranchAddress("HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet50_40_30_v2", &map_BitOfStandardHLTPath["HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet50_40_30_v2"], &b_HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet50_40_30_v2);
   fChain->SetBranchAddress("HLT_Ele27_WP80_v11", &map_BitOfStandardHLTPath["HLT_Ele27_WP80_v11"], &b_HLT_Ele27_WP80_v11);
   fChain->SetBranchAddress("HLT_Ele27_WP80_PFMET_MT50_v5", &map_BitOfStandardHLTPath["HLT_Ele27_WP80_PFMET_MT50_v5"], &b_HLT_Ele27_WP80_PFMET_MT50_v5);
   fChain->SetBranchAddress("HLT_Ele30_CaloIdVT_TrkIdT_v6", &map_BitOfStandardHLTPath["HLT_Ele30_CaloIdVT_TrkIdT_v6"], &b_HLT_Ele30_CaloIdVT_TrkIdT_v6);
   fChain->SetBranchAddress("HLT_Ele32_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_v11", &map_BitOfStandardHLTPath["HLT_Ele32_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_v11"], &b_HLT_Ele32_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_v11);
   fChain->SetBranchAddress("HLT_Ele32_CaloIdT_CaloIsoT_TrkIdT_TrkIsoT_SC17_Mass50_v6", &map_BitOfStandardHLTPath["HLT_Ele32_CaloIdT_CaloIsoT_TrkIdT_TrkIsoT_SC17_Mass50_v6"], &b_HLT_Ele32_CaloIdT_CaloIsoT_TrkIdT_TrkIsoT_SC17_Mass50_v6);
   fChain->SetBranchAddress("HLT_Ele80_CaloIdVT_GsfTrkIdT_v2", &map_BitOfStandardHLTPath["HLT_Ele80_CaloIdVT_GsfTrkIdT_v2"], &b_HLT_Ele80_CaloIdVT_GsfTrkIdT_v2);
   fChain->SetBranchAddress("HLT_Ele90_CaloIdVT_GsfTrkIdT_v2", &map_BitOfStandardHLTPath["HLT_Ele90_CaloIdVT_GsfTrkIdT_v2"], &b_HLT_Ele90_CaloIdVT_GsfTrkIdT_v2);
   fChain->SetBranchAddress("HLT_DoubleEle8_CaloIdT_TrkIdVL_v12", &map_BitOfStandardHLTPath["HLT_DoubleEle8_CaloIdT_TrkIdVL_v12"], &b_HLT_DoubleEle8_CaloIdT_TrkIdVL_v12);
   fChain->SetBranchAddress("HLT_DoubleEle33_CaloIdL_v14", &map_BitOfStandardHLTPath["HLT_DoubleEle33_CaloIdL_v14"], &b_HLT_DoubleEle33_CaloIdL_v14);
   fChain->SetBranchAddress("HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v7", &map_BitOfStandardHLTPath["HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v7"], &b_HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v7);
   fChain->SetBranchAddress("HLT_DoubleEle33_CaloIdT_v10", &map_BitOfStandardHLTPath["HLT_DoubleEle33_CaloIdT_v10"], &b_HLT_DoubleEle33_CaloIdT_v10);
   fChain->SetBranchAddress("HLT_Ele15_Ele8_Ele5_CaloIdL_TrkIdVL_v6", &map_BitOfStandardHLTPath["HLT_Ele15_Ele8_Ele5_CaloIdL_TrkIdVL_v6"], &b_HLT_Ele15_Ele8_Ele5_CaloIdL_TrkIdVL_v6);
   fChain->SetBranchAddress("HLT_LooseIsoPFTau35_Trk20_Prong1_v7", &map_BitOfStandardHLTPath["HLT_LooseIsoPFTau35_Trk20_Prong1_v7"], &b_HLT_LooseIsoPFTau35_Trk20_Prong1_v7);
   fChain->SetBranchAddress("HLT_LooseIsoPFTau35_Trk20_Prong1_MET70_v7", &map_BitOfStandardHLTPath["HLT_LooseIsoPFTau35_Trk20_Prong1_MET70_v7"], &b_HLT_LooseIsoPFTau35_Trk20_Prong1_MET70_v7);
   fChain->SetBranchAddress("HLT_LooseIsoPFTau35_Trk20_Prong1_MET75_v7", &map_BitOfStandardHLTPath["HLT_LooseIsoPFTau35_Trk20_Prong1_MET75_v7"], &b_HLT_LooseIsoPFTau35_Trk20_Prong1_MET75_v7);
   fChain->SetBranchAddress("HLT_IsoMu15_eta2p1_LooseIsoPFTau35_Trk20_Prong1_L1ETM20_v7", &map_BitOfStandardHLTPath["HLT_IsoMu15_eta2p1_LooseIsoPFTau35_Trk20_Prong1_L1ETM20_v7"], &b_HLT_IsoMu15_eta2p1_LooseIsoPFTau35_Trk20_Prong1_L1ETM20_v7);
   fChain->SetBranchAddress("HLT_DoubleMediumIsoPFTau30_Trk1_eta2p1_Jet30_v1", &map_BitOfStandardHLTPath["HLT_DoubleMediumIsoPFTau30_Trk1_eta2p1_Jet30_v1"], &b_HLT_DoubleMediumIsoPFTau30_Trk1_eta2p1_Jet30_v1);
   fChain->SetBranchAddress("HLT_DoubleMediumIsoPFTau30_Trk1_eta2p1_v1", &map_BitOfStandardHLTPath["HLT_DoubleMediumIsoPFTau30_Trk1_eta2p1_v1"], &b_HLT_DoubleMediumIsoPFTau30_Trk1_eta2p1_v1);
   fChain->SetBranchAddress("HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Prong1_v1", &map_BitOfStandardHLTPath["HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Prong1_v1"], &b_HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Prong1_v1);
   fChain->SetBranchAddress("HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_v1", &map_BitOfStandardHLTPath["HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_v1"], &b_HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_v1);
   fChain->SetBranchAddress("HLT_IsoMu18_eta2p1_MediumIsoPFTau25_Trk1_eta2p1_v1", &map_BitOfStandardHLTPath["HLT_IsoMu18_eta2p1_MediumIsoPFTau25_Trk1_eta2p1_v1"], &b_HLT_IsoMu18_eta2p1_MediumIsoPFTau25_Trk1_eta2p1_v1);
   fChain->SetBranchAddress("HLT_BTagMu_DiJet20_Mu5_v4", &map_BitOfStandardHLTPath["HLT_BTagMu_DiJet20_Mu5_v4"], &b_HLT_BTagMu_DiJet20_Mu5_v4);
   fChain->SetBranchAddress("HLT_BTagMu_DiJet40_Mu5_v4", &map_BitOfStandardHLTPath["HLT_BTagMu_DiJet40_Mu5_v4"], &b_HLT_BTagMu_DiJet40_Mu5_v4);
   fChain->SetBranchAddress("HLT_BTagMu_DiJet70_Mu5_v4", &map_BitOfStandardHLTPath["HLT_BTagMu_DiJet70_Mu5_v4"], &b_HLT_BTagMu_DiJet70_Mu5_v4);
   fChain->SetBranchAddress("HLT_BTagMu_DiJet110_Mu5_v4", &map_BitOfStandardHLTPath["HLT_BTagMu_DiJet110_Mu5_v4"], &b_HLT_BTagMu_DiJet110_Mu5_v4);
   fChain->SetBranchAddress("HLT_BTagMu_Jet300_Mu5_v4", &map_BitOfStandardHLTPath["HLT_BTagMu_Jet300_Mu5_v4"], &b_HLT_BTagMu_Jet300_Mu5_v4);
   fChain->SetBranchAddress("HLT_Mu7_Ele7_CaloIdT_CaloIsoVL_v6", &map_BitOfStandardHLTPath["HLT_Mu7_Ele7_CaloIdT_CaloIsoVL_v6"], &b_HLT_Mu7_Ele7_CaloIdT_CaloIsoVL_v6);
   fChain->SetBranchAddress("HLT_Mu8_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v8", &map_BitOfStandardHLTPath["HLT_Mu8_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v8"], &b_HLT_Mu8_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v8);
   fChain->SetBranchAddress("HLT_Mu8_DiJet30_v5", &map_BitOfStandardHLTPath["HLT_Mu8_DiJet30_v5"], &b_HLT_Mu8_DiJet30_v5);
   fChain->SetBranchAddress("HLT_Mu8_TriJet30_v5", &map_BitOfStandardHLTPath["HLT_Mu8_TriJet30_v5"], &b_HLT_Mu8_TriJet30_v5);
   fChain->SetBranchAddress("HLT_Mu8_QuadJet30_v5", &map_BitOfStandardHLTPath["HLT_Mu8_QuadJet30_v5"], &b_HLT_Mu8_QuadJet30_v5);
   fChain->SetBranchAddress("HLT_IsoMu12_DoubleCentralJet65_v2", &map_BitOfStandardHLTPath["HLT_IsoMu12_DoubleCentralJet65_v2"], &b_HLT_IsoMu12_DoubleCentralJet65_v2);
   fChain->SetBranchAddress("HLT_Mu15_eta2p1_L1ETM20_v4", &map_BitOfStandardHLTPath["HLT_Mu15_eta2p1_L1ETM20_v4"], &b_HLT_Mu15_eta2p1_L1ETM20_v4);
   fChain->SetBranchAddress("HLT_Mu24_PFJet30_PFJet25_Deta3_CentralPFJet25_v2", &map_BitOfStandardHLTPath["HLT_Mu24_PFJet30_PFJet25_Deta3_CentralPFJet25_v2"], &b_HLT_Mu24_PFJet30_PFJet25_Deta3_CentralPFJet25_v2);
   fChain->SetBranchAddress("HLT_Mu24_CentralPFJet30_CentralPFJet25_v2", &map_BitOfStandardHLTPath["HLT_Mu24_CentralPFJet30_CentralPFJet25_v2"], &b_HLT_Mu24_CentralPFJet30_CentralPFJet25_v2);
   fChain->SetBranchAddress("HLT_IsoMu24_PFJet30_PFJet25_Deta3_CentralPFJet25_v2", &map_BitOfStandardHLTPath["HLT_IsoMu24_PFJet30_PFJet25_Deta3_CentralPFJet25_v2"], &b_HLT_IsoMu24_PFJet30_PFJet25_Deta3_CentralPFJet25_v2);
   fChain->SetBranchAddress("HLT_IsoMu24_CentralPFJet30_CentralPFJet25_v2", &map_BitOfStandardHLTPath["HLT_IsoMu24_CentralPFJet30_CentralPFJet25_v2"], &b_HLT_IsoMu24_CentralPFJet30_CentralPFJet25_v2);
   fChain->SetBranchAddress("HLT_IsoMu24_CentralPFJet30_CentralPFJet25_PFMET20_v2", &map_BitOfStandardHLTPath["HLT_IsoMu24_CentralPFJet30_CentralPFJet25_PFMET20_v2"], &b_HLT_IsoMu24_CentralPFJet30_CentralPFJet25_PFMET20_v2);
   fChain->SetBranchAddress("HLT_Ele32_WP80_PFJet30_PFJet25_Deta3_v2", &map_BitOfStandardHLTPath["HLT_Ele32_WP80_PFJet30_PFJet25_Deta3_v2"], &b_HLT_Ele32_WP80_PFJet30_PFJet25_Deta3_v2);
   fChain->SetBranchAddress("HLT_Ele32_WP80_PFJet30_PFJet25_Deta3_CentralPFJet30_v2", &map_BitOfStandardHLTPath["HLT_Ele32_WP80_PFJet30_PFJet25_Deta3_CentralPFJet30_v2"], &b_HLT_Ele32_WP80_PFJet30_PFJet25_Deta3_CentralPFJet30_v2);
   fChain->SetBranchAddress("HLT_Ele32_WP80_CentralPFJet35_CentralPFJet25_v2", &map_BitOfStandardHLTPath["HLT_Ele32_WP80_CentralPFJet35_CentralPFJet25_v2"], &b_HLT_Ele32_WP80_CentralPFJet35_CentralPFJet25_v2);
   fChain->SetBranchAddress("HLT_Ele32_WP80_CentralPFJet35_CentralPFJet25_PFMET20_v2", &map_BitOfStandardHLTPath["HLT_Ele32_WP80_CentralPFJet35_CentralPFJet25_PFMET20_v2"], &b_HLT_Ele32_WP80_CentralPFJet35_CentralPFJet25_PFMET20_v2);
   fChain->SetBranchAddress("HLT_IsoMu17_eta2p1_CentralPFNoPUJet30_BTagIPIter_v2", &map_BitOfStandardHLTPath["HLT_IsoMu17_eta2p1_CentralPFNoPUJet30_BTagIPIter_v2"], &b_HLT_IsoMu17_eta2p1_CentralPFNoPUJet30_BTagIPIter_v2);
   fChain->SetBranchAddress("HLT_IsoMu17_eta2p1_CentralPFNoPUJet30_v2", &map_BitOfStandardHLTPath["HLT_IsoMu17_eta2p1_CentralPFNoPUJet30_v2"], &b_HLT_IsoMu17_eta2p1_CentralPFNoPUJet30_v2);
   fChain->SetBranchAddress("HLT_IsoMu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2", &map_BitOfStandardHLTPath["HLT_IsoMu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2"], &b_HLT_IsoMu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2);
   fChain->SetBranchAddress("HLT_Mu17_eta2p1_CentralPFNoPUJet30_BTagIPIter_v2", &map_BitOfStandardHLTPath["HLT_Mu17_eta2p1_CentralPFNoPUJet30_BTagIPIter_v2"], &b_HLT_Mu17_eta2p1_CentralPFNoPUJet30_BTagIPIter_v2);
   fChain->SetBranchAddress("HLT_Mu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2", &map_BitOfStandardHLTPath["HLT_Mu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2"], &b_HLT_Mu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2);
   fChain->SetBranchAddress("HLT_IsoMu20_WCandPt80_v2", &map_BitOfStandardHLTPath["HLT_IsoMu20_WCandPt80_v2"], &b_HLT_IsoMu20_WCandPt80_v2);
   fChain->SetBranchAddress("HLT_Mu17_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v8", &map_BitOfStandardHLTPath["HLT_Mu17_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v8"], &b_HLT_Mu17_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v8);
   fChain->SetBranchAddress("HLT_Mu12_eta2p1_DiCentral_40_20_DiBTagIP3D1stTrack_v4", &map_BitOfStandardHLTPath["HLT_Mu12_eta2p1_DiCentral_40_20_DiBTagIP3D1stTrack_v4"], &b_HLT_Mu12_eta2p1_DiCentral_40_20_DiBTagIP3D1stTrack_v4);
   fChain->SetBranchAddress("HLT_Mu12_eta2p1_DiCentral_40_20_BTagIP3D1stTrack_v4", &map_BitOfStandardHLTPath["HLT_Mu12_eta2p1_DiCentral_40_20_BTagIP3D1stTrack_v4"], &b_HLT_Mu12_eta2p1_DiCentral_40_20_BTagIP3D1stTrack_v4);
   fChain->SetBranchAddress("HLT_Mu12_eta2p1_DiCentral_40_20_v4", &map_BitOfStandardHLTPath["HLT_Mu12_eta2p1_DiCentral_40_20_v4"], &b_HLT_Mu12_eta2p1_DiCentral_40_20_v4);
   fChain->SetBranchAddress("HLT_Mu12_eta2p1_DiCentral_20_v4", &map_BitOfStandardHLTPath["HLT_Mu12_eta2p1_DiCentral_20_v4"], &b_HLT_Mu12_eta2p1_DiCentral_20_v4);
   fChain->SetBranchAddress("HLT_Mu15_eta2p1_TriCentral_40_20_20_DiBTagIP3D1stTrack_v4", &map_BitOfStandardHLTPath["HLT_Mu15_eta2p1_TriCentral_40_20_20_DiBTagIP3D1stTrack_v4"], &b_HLT_Mu15_eta2p1_TriCentral_40_20_20_DiBTagIP3D1stTrack_v4);
   fChain->SetBranchAddress("HLT_Mu15_eta2p1_TriCentral_40_20_20_BTagIP3D1stTrack_v4", &map_BitOfStandardHLTPath["HLT_Mu15_eta2p1_TriCentral_40_20_20_BTagIP3D1stTrack_v4"], &b_HLT_Mu15_eta2p1_TriCentral_40_20_20_BTagIP3D1stTrack_v4);
   fChain->SetBranchAddress("HLT_Mu15_eta2p1_TriCentral_40_20_20_v4", &map_BitOfStandardHLTPath["HLT_Mu15_eta2p1_TriCentral_40_20_20_v4"], &b_HLT_Mu15_eta2p1_TriCentral_40_20_20_v4);
   fChain->SetBranchAddress("HLT_Mu30_Ele30_CaloIdL_v7", &map_BitOfStandardHLTPath["HLT_Mu30_Ele30_CaloIdL_v7"], &b_HLT_Mu30_Ele30_CaloIdL_v7);
   fChain->SetBranchAddress("HLT_IsoMu17_eta2p1_DiCentralPFNoPUJet30_PFNoPUHT350_PFMHT40_v1", &map_BitOfStandardHLTPath["HLT_IsoMu17_eta2p1_DiCentralPFNoPUJet30_PFNoPUHT350_PFMHT40_v1"], &b_HLT_IsoMu17_eta2p1_DiCentralPFNoPUJet30_PFNoPUHT350_PFMHT40_v1);
   fChain->SetBranchAddress("HLT_IsoMu20_eta2p1_CentralPFJet80_v7", &map_BitOfStandardHLTPath["HLT_IsoMu20_eta2p1_CentralPFJet80_v7"], &b_HLT_IsoMu20_eta2p1_CentralPFJet80_v7);
   fChain->SetBranchAddress("HLT_DoubleRelIso1p0Mu5_Mass8_PFNoPUHT175_v1", &map_BitOfStandardHLTPath["HLT_DoubleRelIso1p0Mu5_Mass8_PFNoPUHT175_v1"], &b_HLT_DoubleRelIso1p0Mu5_Mass8_PFNoPUHT175_v1);
   fChain->SetBranchAddress("HLT_DoubleRelIso1p0Mu5_Mass8_PFNoPUHT225_v1", &map_BitOfStandardHLTPath["HLT_DoubleRelIso1p0Mu5_Mass8_PFNoPUHT225_v1"], &b_HLT_DoubleRelIso1p0Mu5_Mass8_PFNoPUHT225_v1);
   fChain->SetBranchAddress("HLT_DoubleMu8_Mass8_PFNoPUHT175_v1", &map_BitOfStandardHLTPath["HLT_DoubleMu8_Mass8_PFNoPUHT175_v1"], &b_HLT_DoubleMu8_Mass8_PFNoPUHT175_v1);
   fChain->SetBranchAddress("HLT_DoubleMu8_Mass8_PFNoPUHT225_v1", &map_BitOfStandardHLTPath["HLT_DoubleMu8_Mass8_PFNoPUHT225_v1"], &b_HLT_DoubleMu8_Mass8_PFNoPUHT225_v1);
   fChain->SetBranchAddress("HLT_RelIso1p0Mu5_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1", &map_BitOfStandardHLTPath["HLT_RelIso1p0Mu5_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1"], &b_HLT_RelIso1p0Mu5_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1);
   fChain->SetBranchAddress("HLT_RelIso1p0Mu5_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1", &map_BitOfStandardHLTPath["HLT_RelIso1p0Mu5_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1"], &b_HLT_RelIso1p0Mu5_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1);
   fChain->SetBranchAddress("HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1", &map_BitOfStandardHLTPath["HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1"], &b_HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1);
   fChain->SetBranchAddress("HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1", &map_BitOfStandardHLTPath["HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1"], &b_HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1);
   fChain->SetBranchAddress("HLT_PFNoPUHT350_Mu15_PFMET45_v1", &map_BitOfStandardHLTPath["HLT_PFNoPUHT350_Mu15_PFMET45_v1"], &b_HLT_PFNoPUHT350_Mu15_PFMET45_v1);
   fChain->SetBranchAddress("HLT_PFNoPUHT350_Mu15_PFMET50_v1", &map_BitOfStandardHLTPath["HLT_PFNoPUHT350_Mu15_PFMET50_v1"], &b_HLT_PFNoPUHT350_Mu15_PFMET50_v1);
   fChain->SetBranchAddress("HLT_PFNoPUHT400_Mu5_PFMET45_v1", &map_BitOfStandardHLTPath["HLT_PFNoPUHT400_Mu5_PFMET45_v1"], &b_HLT_PFNoPUHT400_Mu5_PFMET45_v1);
   fChain->SetBranchAddress("HLT_PFNoPUHT400_Mu5_PFMET50_v1", &map_BitOfStandardHLTPath["HLT_PFNoPUHT400_Mu5_PFMET50_v1"], &b_HLT_PFNoPUHT400_Mu5_PFMET50_v1);
   fChain->SetBranchAddress("HLT_Mu40_PFNoPUHT350_v1", &map_BitOfStandardHLTPath["HLT_Mu40_PFNoPUHT350_v1"], &b_HLT_Mu40_PFNoPUHT350_v1);
   fChain->SetBranchAddress("HLT_Mu60_PFNoPUHT350_v1", &map_BitOfStandardHLTPath["HLT_Mu60_PFNoPUHT350_v1"], &b_HLT_Mu60_PFNoPUHT350_v1);
   fChain->SetBranchAddress("HLT_Mu40_HT200_v2", &map_BitOfStandardHLTPath["HLT_Mu40_HT200_v2"], &b_HLT_Mu40_HT200_v2);
   fChain->SetBranchAddress("HLT_DoubleMu5_Ele8_CaloIdT_TrkIdVL_v15", &map_BitOfStandardHLTPath["HLT_DoubleMu5_Ele8_CaloIdT_TrkIdVL_v15"], &b_HLT_DoubleMu5_Ele8_CaloIdT_TrkIdVL_v15);
   fChain->SetBranchAddress("HLT_DoubleMu8_Ele8_CaloIdT_TrkIdVL_v4", &map_BitOfStandardHLTPath["HLT_DoubleMu8_Ele8_CaloIdT_TrkIdVL_v4"], &b_HLT_DoubleMu8_Ele8_CaloIdT_TrkIdVL_v4);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Jet30_v6", &map_BitOfStandardHLTPath["HLT_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Jet30_v6"], &b_HLT_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Jet30_v6);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdT_TrkIdT_DiJet30_v16", &map_BitOfStandardHLTPath["HLT_Ele8_CaloIdT_TrkIdT_DiJet30_v16"], &b_HLT_Ele8_CaloIdT_TrkIdT_DiJet30_v16);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdT_TrkIdT_TriJet30_v16", &map_BitOfStandardHLTPath["HLT_Ele8_CaloIdT_TrkIdT_TriJet30_v16"], &b_HLT_Ele8_CaloIdT_TrkIdT_TriJet30_v16);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdT_TrkIdT_QuadJet30_v16", &map_BitOfStandardHLTPath["HLT_Ele8_CaloIdT_TrkIdT_QuadJet30_v16"], &b_HLT_Ele8_CaloIdT_TrkIdT_QuadJet30_v16);
   fChain->SetBranchAddress("HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Jet30_v6", &map_BitOfStandardHLTPath["HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Jet30_v6"], &b_HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Jet30_v6);
   fChain->SetBranchAddress("HLT_Ele25_CaloIdVT_TrkIdT_TriCentralPFNoPUJet30_30_20_v2", &map_BitOfStandardHLTPath["HLT_Ele25_CaloIdVT_TrkIdT_TriCentralPFNoPUJet30_30_20_v2"], &b_HLT_Ele25_CaloIdVT_TrkIdT_TriCentralPFNoPUJet30_30_20_v2);
   fChain->SetBranchAddress("HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_CentralPFNoPUJet30_v6", &map_BitOfStandardHLTPath["HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_CentralPFNoPUJet30_v6"], &b_HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_CentralPFNoPUJet30_v6);
   fChain->SetBranchAddress("HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2", &map_BitOfStandardHLTPath["HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2"], &b_HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2);
   fChain->SetBranchAddress("HLT_Ele25_CaloIdVL_CaloIsoT_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2", &map_BitOfStandardHLTPath["HLT_Ele25_CaloIdVL_CaloIsoT_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2"], &b_HLT_Ele25_CaloIdVL_CaloIsoT_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2);
   fChain->SetBranchAddress("HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_CentralPFNoPUJet30_BTagIPIter_v7", &map_BitOfStandardHLTPath["HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_CentralPFNoPUJet30_BTagIPIter_v7"], &b_HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_CentralPFNoPUJet30_BTagIPIter_v7);
   fChain->SetBranchAddress("HLT_Ele27_WP80_CentralPFJet80_v7", &map_BitOfStandardHLTPath["HLT_Ele27_WP80_CentralPFJet80_v7"], &b_HLT_Ele27_WP80_CentralPFJet80_v7);
   fChain->SetBranchAddress("HLT_Ele27_WP80_WCandPt80_v7", &map_BitOfStandardHLTPath["HLT_Ele27_WP80_WCandPt80_v7"], &b_HLT_Ele27_WP80_WCandPt80_v7);
   fChain->SetBranchAddress("HLT_Ele30_CaloIdVT_TrkIdT_PFNoPUJet100_PFNoPUJet25_v6", &map_BitOfStandardHLTPath["HLT_Ele30_CaloIdVT_TrkIdT_PFNoPUJet100_PFNoPUJet25_v6"], &b_HLT_Ele30_CaloIdVT_TrkIdT_PFNoPUJet100_PFNoPUJet25_v6);
   fChain->SetBranchAddress("HLT_Ele30_CaloIdVT_TrkIdT_PFNoPUJet150_PFNoPUJet25_v6", &map_BitOfStandardHLTPath["HLT_Ele30_CaloIdVT_TrkIdT_PFNoPUJet150_PFNoPUJet25_v6"], &b_HLT_Ele30_CaloIdVT_TrkIdT_PFNoPUJet150_PFNoPUJet25_v6);
   fChain->SetBranchAddress("HLT_DoubleEle8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1", &map_BitOfStandardHLTPath["HLT_DoubleEle8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1"], &b_HLT_DoubleEle8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1);
   fChain->SetBranchAddress("HLT_DoubleEle8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1", &map_BitOfStandardHLTPath["HLT_DoubleEle8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1"], &b_HLT_DoubleEle8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1);
   fChain->SetBranchAddress("HLT_DoubleEle10_CaloIdL_TrkIdVL_Ele10_CaloIdT_TrkIdVL_v12", &map_BitOfStandardHLTPath["HLT_DoubleEle10_CaloIdL_TrkIdVL_Ele10_CaloIdT_TrkIdVL_v12"], &b_HLT_DoubleEle10_CaloIdL_TrkIdVL_Ele10_CaloIdT_TrkIdVL_v12);
   fChain->SetBranchAddress("HLT_TripleEle10_CaloIdL_TrkIdVL_v18", &map_BitOfStandardHLTPath["HLT_TripleEle10_CaloIdL_TrkIdVL_v18"], &b_HLT_TripleEle10_CaloIdL_TrkIdVL_v18);
   fChain->SetBranchAddress("HLT_RsqMR40_Rsq0p04_v4", &map_BitOfStandardHLTPath["HLT_RsqMR40_Rsq0p04_v4"], &b_HLT_RsqMR40_Rsq0p04_v4);
   fChain->SetBranchAddress("HLT_RsqMR45_Rsq0p09_v3", &map_BitOfStandardHLTPath["HLT_RsqMR45_Rsq0p09_v3"], &b_HLT_RsqMR45_Rsq0p09_v3);
   fChain->SetBranchAddress("HLT_RsqMR55_Rsq0p09_MR150_v4", &map_BitOfStandardHLTPath["HLT_RsqMR55_Rsq0p09_MR150_v4"], &b_HLT_RsqMR55_Rsq0p09_MR150_v4);
   fChain->SetBranchAddress("HLT_RsqMR60_Rsq0p09_MR150_v4", &map_BitOfStandardHLTPath["HLT_RsqMR60_Rsq0p09_MR150_v4"], &b_HLT_RsqMR60_Rsq0p09_MR150_v4);
   fChain->SetBranchAddress("HLT_RsqMR65_Rsq0p09_MR150_v3", &map_BitOfStandardHLTPath["HLT_RsqMR65_Rsq0p09_MR150_v3"], &b_HLT_RsqMR65_Rsq0p09_MR150_v3);
   fChain->SetBranchAddress("HLT_IsoMu12_RsqMR30_Rsq0p04_MR200_v2", &map_BitOfStandardHLTPath["HLT_IsoMu12_RsqMR30_Rsq0p04_MR200_v2"], &b_HLT_IsoMu12_RsqMR30_Rsq0p04_MR200_v2);
   fChain->SetBranchAddress("HLT_IsoMu12_RsqMR40_Rsq0p04_MR200_v2", &map_BitOfStandardHLTPath["HLT_IsoMu12_RsqMR40_Rsq0p04_MR200_v2"], &b_HLT_IsoMu12_RsqMR40_Rsq0p04_MR200_v2);
   fChain->SetBranchAddress("HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_RsqMR30_Rsq0p04_MR200_v2", &map_BitOfStandardHLTPath["HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_RsqMR30_Rsq0p04_MR200_v2"], &b_HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_RsqMR30_Rsq0p04_MR200_v2);
   fChain->SetBranchAddress("HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_RsqMR40_Rsq0p04_MR200_v2", &map_BitOfStandardHLTPath["HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_RsqMR40_Rsq0p04_MR200_v2"], &b_HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_RsqMR40_Rsq0p04_MR200_v2);
   fChain->SetBranchAddress("HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_DoubleCentralJet65_v2", &map_BitOfStandardHLTPath["HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_DoubleCentralJet65_v2"], &b_HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_DoubleCentralJet65_v2);
   fChain->SetBranchAddress("HLT_Photon40_CaloIdL_RsqMR35_Rsq0p09_MR150_v4", &map_BitOfStandardHLTPath["HLT_Photon40_CaloIdL_RsqMR35_Rsq0p09_MR150_v4"], &b_HLT_Photon40_CaloIdL_RsqMR35_Rsq0p09_MR150_v4);
   fChain->SetBranchAddress("HLT_Photon40_CaloIdL_RsqMR40_Rsq0p09_MR150_v4", &map_BitOfStandardHLTPath["HLT_Photon40_CaloIdL_RsqMR40_Rsq0p09_MR150_v4"], &b_HLT_Photon40_CaloIdL_RsqMR40_Rsq0p09_MR150_v4);
   fChain->SetBranchAddress("HLT_Photon40_CaloIdL_RsqMR45_Rsq0p09_MR150_v4", &map_BitOfStandardHLTPath["HLT_Photon40_CaloIdL_RsqMR45_Rsq0p09_MR150_v4"], &b_HLT_Photon40_CaloIdL_RsqMR45_Rsq0p09_MR150_v4);
   fChain->SetBranchAddress("HLT_Photon40_CaloIdL_RsqMR50_Rsq0p09_MR150_v4", &map_BitOfStandardHLTPath["HLT_Photon40_CaloIdL_RsqMR50_Rsq0p09_MR150_v4"], &b_HLT_Photon40_CaloIdL_RsqMR50_Rsq0p09_MR150_v4);
   fChain->SetBranchAddress("HLT_DoublePhoton40_CaloIdL_Rsq0p035_v4", &map_BitOfStandardHLTPath["HLT_DoublePhoton40_CaloIdL_Rsq0p035_v4"], &b_HLT_DoublePhoton40_CaloIdL_Rsq0p035_v4);
   fChain->SetBranchAddress("HLT_DoublePhoton40_CaloIdL_Rsq0p06_v4", &map_BitOfStandardHLTPath["HLT_DoublePhoton40_CaloIdL_Rsq0p06_v4"], &b_HLT_DoublePhoton40_CaloIdL_Rsq0p06_v4);
   fChain->SetBranchAddress("HLT_Mu22_Photon22_CaloIdL_v6", &map_BitOfStandardHLTPath["HLT_Mu22_Photon22_CaloIdL_v6"], &b_HLT_Mu22_Photon22_CaloIdL_v6);
   fChain->SetBranchAddress("HLT_Mu8_DoubleEle8_CaloIdT_TrkIdVL_v6", &map_BitOfStandardHLTPath["HLT_Mu8_DoubleEle8_CaloIdT_TrkIdVL_v6"], &b_HLT_Mu8_DoubleEle8_CaloIdT_TrkIdVL_v6);
   fChain->SetBranchAddress("HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Ele8_CaloIdL_TrkIdVL_v6", &map_BitOfStandardHLTPath["HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Ele8_CaloIdL_TrkIdVL_v6"], &b_HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Ele8_CaloIdL_TrkIdVL_v6);
   fChain->SetBranchAddress("HLT_DoubleMu14_Mass8_PFMET40_v6", &map_BitOfStandardHLTPath["HLT_DoubleMu14_Mass8_PFMET40_v6"], &b_HLT_DoubleMu14_Mass8_PFMET40_v6);
   fChain->SetBranchAddress("HLT_DoubleMu14_Mass8_PFMET50_v6", &map_BitOfStandardHLTPath["HLT_DoubleMu14_Mass8_PFMET50_v6"], &b_HLT_DoubleMu14_Mass8_PFMET50_v6);
   fChain->SetBranchAddress("HLT_DoubleEle14_CaloIdT_TrkIdVL_Mass8_PFMET40_v6", &map_BitOfStandardHLTPath["HLT_DoubleEle14_CaloIdT_TrkIdVL_Mass8_PFMET40_v6"], &b_HLT_DoubleEle14_CaloIdT_TrkIdVL_Mass8_PFMET40_v6);
   fChain->SetBranchAddress("HLT_DoubleEle14_CaloIdT_TrkIdVL_Mass8_PFMET50_v6", &map_BitOfStandardHLTPath["HLT_DoubleEle14_CaloIdT_TrkIdVL_Mass8_PFMET50_v6"], &b_HLT_DoubleEle14_CaloIdT_TrkIdVL_Mass8_PFMET50_v6);
   fChain->SetBranchAddress("HLT_Mu14_Ele14_CaloIdT_TrkIdVL_Mass8_PFMET40_v6", &map_BitOfStandardHLTPath["HLT_Mu14_Ele14_CaloIdT_TrkIdVL_Mass8_PFMET40_v6"], &b_HLT_Mu14_Ele14_CaloIdT_TrkIdVL_Mass8_PFMET40_v6);
   fChain->SetBranchAddress("HLT_Mu14_Ele14_CaloIdT_TrkIdVL_Mass8_PFMET50_v6", &map_BitOfStandardHLTPath["HLT_Mu14_Ele14_CaloIdT_TrkIdVL_Mass8_PFMET50_v6"], &b_HLT_Mu14_Ele14_CaloIdT_TrkIdVL_Mass8_PFMET50_v6);
   fChain->SetBranchAddress("HLT_PFNoPUHT350_PFMET100_v1", &map_BitOfStandardHLTPath["HLT_PFNoPUHT350_PFMET100_v1"], &b_HLT_PFNoPUHT350_PFMET100_v1);
   fChain->SetBranchAddress("HLT_PFNoPUHT400_PFMET100_v1", &map_BitOfStandardHLTPath["HLT_PFNoPUHT400_PFMET100_v1"], &b_HLT_PFNoPUHT400_PFMET100_v1);
   fChain->SetBranchAddress("HLT_CleanPFNoPUHT350_Ele5_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET45_v1", &map_BitOfStandardHLTPath["HLT_CleanPFNoPUHT350_Ele5_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET45_v1"], &b_HLT_CleanPFNoPUHT350_Ele5_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET45_v1);
   fChain->SetBranchAddress("HLT_CleanPFNoPUHT350_Ele5_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET50_v1", &map_BitOfStandardHLTPath["HLT_CleanPFNoPUHT350_Ele5_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET50_v1"], &b_HLT_CleanPFNoPUHT350_Ele5_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET50_v1);
   fChain->SetBranchAddress("HLT_CleanPFNoPUHT300_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET45_v1", &map_BitOfStandardHLTPath["HLT_CleanPFNoPUHT300_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET45_v1"], &b_HLT_CleanPFNoPUHT300_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET45_v1);
   fChain->SetBranchAddress("HLT_CleanPFNoPUHT300_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET50_v1", &map_BitOfStandardHLTPath["HLT_CleanPFNoPUHT300_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET50_v1"], &b_HLT_CleanPFNoPUHT300_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET50_v1);
   fChain->SetBranchAddress("HLT_CleanPFNoPUHT300_Ele40_CaloIdVT_TrkIdT_v1", &map_BitOfStandardHLTPath["HLT_CleanPFNoPUHT300_Ele40_CaloIdVT_TrkIdT_v1"], &b_HLT_CleanPFNoPUHT300_Ele40_CaloIdVT_TrkIdT_v1);
   fChain->SetBranchAddress("HLT_CleanPFNoPUHT300_Ele60_CaloIdVT_TrkIdT_v1", &map_BitOfStandardHLTPath["HLT_CleanPFNoPUHT300_Ele60_CaloIdVT_TrkIdT_v1"], &b_HLT_CleanPFNoPUHT300_Ele60_CaloIdVT_TrkIdT_v1);
   fChain->SetBranchAddress("HLT_Ele5_SC5_Jpsi_Mass2to15_v4", &map_BitOfStandardHLTPath["HLT_Ele5_SC5_Jpsi_Mass2to15_v4"], &b_HLT_Ele5_SC5_Jpsi_Mass2to15_v4);
   fChain->SetBranchAddress("HLT_DiJet35_MJJ650_AllJets_DEta3p5_VBF_v2", &map_BitOfStandardHLTPath["HLT_DiJet35_MJJ650_AllJets_DEta3p5_VBF_v2"], &b_HLT_DiJet35_MJJ650_AllJets_DEta3p5_VBF_v2);
   fChain->SetBranchAddress("HLT_DiJet35_MJJ700_AllJets_DEta3p5_VBF_v2", &map_BitOfStandardHLTPath["HLT_DiJet35_MJJ700_AllJets_DEta3p5_VBF_v2"], &b_HLT_DiJet35_MJJ700_AllJets_DEta3p5_VBF_v2);
   fChain->SetBranchAddress("HLT_DiJet35_MJJ750_AllJets_DEta3p5_VBF_v2", &map_BitOfStandardHLTPath["HLT_DiJet35_MJJ750_AllJets_DEta3p5_VBF_v2"], &b_HLT_DiJet35_MJJ750_AllJets_DEta3p5_VBF_v2);
   fChain->SetBranchAddress("HLT_Ele22_eta2p1_WP90Rho_LooseIsoPFTau20_v3", &map_BitOfStandardHLTPath["HLT_Ele22_eta2p1_WP90Rho_LooseIsoPFTau20_v3"], &b_HLT_Ele22_eta2p1_WP90Rho_LooseIsoPFTau20_v3);
   fChain->SetBranchAddress("HLT_Ele22_eta2p1_WP90NoIso_LooseIsoPFTau20_v3", &map_BitOfStandardHLTPath["HLT_Ele22_eta2p1_WP90NoIso_LooseIsoPFTau20_v3"], &b_HLT_Ele22_eta2p1_WP90NoIso_LooseIsoPFTau20_v3);
   fChain->SetBranchAddress("HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v3", &map_BitOfStandardHLTPath["HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v3"], &b_HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v3);
   fChain->SetBranchAddress("HLT_Mu17_eta2p1_LooseIsoPFTau20_v3", &map_BitOfStandardHLTPath["HLT_Mu17_eta2p1_LooseIsoPFTau20_v3"], &b_HLT_Mu17_eta2p1_LooseIsoPFTau20_v3);
   fChain->SetBranchAddress("HLT_PixelTracks_Multiplicity70_v3", &map_BitOfStandardHLTPath["HLT_PixelTracks_Multiplicity70_v3"], &b_HLT_PixelTracks_Multiplicity70_v3);
   fChain->SetBranchAddress("HLT_PixelTracks_Multiplicity80_v12", &map_BitOfStandardHLTPath["HLT_PixelTracks_Multiplicity80_v12"], &b_HLT_PixelTracks_Multiplicity80_v12);
   fChain->SetBranchAddress("HLT_PixelTracks_Multiplicity90_v3", &map_BitOfStandardHLTPath["HLT_PixelTracks_Multiplicity90_v3"], &b_HLT_PixelTracks_Multiplicity90_v3);
   fChain->SetBranchAddress("HLT_BeamGas_HF_Beam1_v5", &map_BitOfStandardHLTPath["HLT_BeamGas_HF_Beam1_v5"], &b_HLT_BeamGas_HF_Beam1_v5);
   fChain->SetBranchAddress("HLT_BeamGas_HF_Beam2_v5", &map_BitOfStandardHLTPath["HLT_BeamGas_HF_Beam2_v5"], &b_HLT_BeamGas_HF_Beam2_v5);
   fChain->SetBranchAddress("HLT_BeamHalo_v13", &map_BitOfStandardHLTPath["HLT_BeamHalo_v13"], &b_HLT_BeamHalo_v13);
   fChain->SetBranchAddress("HLT_IsoTrackHE_v15", &map_BitOfStandardHLTPath["HLT_IsoTrackHE_v15"], &b_HLT_IsoTrackHE_v15);
   fChain->SetBranchAddress("HLT_IsoTrackHB_v14", &map_BitOfStandardHLTPath["HLT_IsoTrackHB_v14"], &b_HLT_IsoTrackHB_v14);
   fChain->SetBranchAddress("HLT_HcalPhiSym_v11", &map_BitOfStandardHLTPath["HLT_HcalPhiSym_v11"], &b_HLT_HcalPhiSym_v11);
   fChain->SetBranchAddress("HLT_HcalNZS_v10", &map_BitOfStandardHLTPath["HLT_HcalNZS_v10"], &b_HLT_HcalNZS_v10);
   fChain->SetBranchAddress("HLT_GlobalRunHPDNoise_v8", &map_BitOfStandardHLTPath["HLT_GlobalRunHPDNoise_v8"], &b_HLT_GlobalRunHPDNoise_v8);
   fChain->SetBranchAddress("HLT_L1Tech_HBHEHO_totalOR_v6", &map_BitOfStandardHLTPath["HLT_L1Tech_HBHEHO_totalOR_v6"], &b_HLT_L1Tech_HBHEHO_totalOR_v6);
   fChain->SetBranchAddress("HLT_L1Tech_HCAL_HF_single_channel_v4", &map_BitOfStandardHLTPath["HLT_L1Tech_HCAL_HF_single_channel_v4"], &b_HLT_L1Tech_HCAL_HF_single_channel_v4);
   fChain->SetBranchAddress("HLT_ZeroBias_v7", &map_BitOfStandardHLTPath["HLT_ZeroBias_v7"], &b_HLT_ZeroBias_v7);
   fChain->SetBranchAddress("HLT_ZeroBiasPixel_DoubleTrack_v2", &map_BitOfStandardHLTPath["HLT_ZeroBiasPixel_DoubleTrack_v2"], &b_HLT_ZeroBiasPixel_DoubleTrack_v2);
   fChain->SetBranchAddress("HLT_Physics_v5", &map_BitOfStandardHLTPath["HLT_Physics_v5"], &b_HLT_Physics_v5);
   fChain->SetBranchAddress("HLT_DTCalibration_v2", &map_BitOfStandardHLTPath["HLT_DTCalibration_v2"], &b_HLT_DTCalibration_v2);
   fChain->SetBranchAddress("HLT_EcalCalibration_v3", &map_BitOfStandardHLTPath["HLT_EcalCalibration_v3"], &b_HLT_EcalCalibration_v3);
   fChain->SetBranchAddress("HLT_HcalCalibration_v3", &map_BitOfStandardHLTPath["HLT_HcalCalibration_v3"], &b_HLT_HcalCalibration_v3);
   fChain->SetBranchAddress("HLT_TrackerCalibration_v3", &map_BitOfStandardHLTPath["HLT_TrackerCalibration_v3"], &b_HLT_TrackerCalibration_v3);
   fChain->SetBranchAddress("HLT_Random_v2", &map_BitOfStandardHLTPath["HLT_Random_v2"], &b_HLT_Random_v2);
   fChain->SetBranchAddress("HLT_L1SingleMuOpen_AntiBPTX_v7", &map_BitOfStandardHLTPath["HLT_L1SingleMuOpen_AntiBPTX_v7"], &b_HLT_L1SingleMuOpen_AntiBPTX_v7);
   fChain->SetBranchAddress("HLT_L1TrackerCosmics_v7", &map_BitOfStandardHLTPath["HLT_L1TrackerCosmics_v7"], &b_HLT_L1TrackerCosmics_v7);
   fChain->SetBranchAddress("HLT_LogMonitor_v3", &map_BitOfStandardHLTPath["HLT_LogMonitor_v3"], &b_HLT_LogMonitor_v3);
   fChain->SetBranchAddress("HLT_DTErrors_v3", &map_BitOfStandardHLTPath["HLT_DTErrors_v3"], &b_HLT_DTErrors_v3);
   fChain->SetBranchAddress("HLT_L1DoubleJet36Central_v7", &map_BitOfStandardHLTPath["HLT_L1DoubleJet36Central_v7"], &b_HLT_L1DoubleJet36Central_v7);
   fChain->SetBranchAddress("AlCa_EcalPi0EBonly_v6", &map_BitOfStandardHLTPath["AlCa_EcalPi0EBonly_v6"], &b_AlCa_EcalPi0EBonly_v6);
   fChain->SetBranchAddress("AlCa_EcalPi0EEonly_v6", &map_BitOfStandardHLTPath["AlCa_EcalPi0EEonly_v6"], &b_AlCa_EcalPi0EEonly_v6);
   fChain->SetBranchAddress("AlCa_EcalEtaEBonly_v6", &map_BitOfStandardHLTPath["AlCa_EcalEtaEBonly_v6"], &b_AlCa_EcalEtaEBonly_v6);
   fChain->SetBranchAddress("AlCa_EcalEtaEEonly_v6", &map_BitOfStandardHLTPath["AlCa_EcalEtaEEonly_v6"], &b_AlCa_EcalEtaEEonly_v6);
   fChain->SetBranchAddress("AlCa_EcalPhiSym_v13", &map_BitOfStandardHLTPath["AlCa_EcalPhiSym_v13"], &b_AlCa_EcalPhiSym_v13);
   fChain->SetBranchAddress("AlCa_RPCMuonNoTriggers_v9", &map_BitOfStandardHLTPath["AlCa_RPCMuonNoTriggers_v9"], &b_AlCa_RPCMuonNoTriggers_v9);
   fChain->SetBranchAddress("AlCa_RPCMuonNoHits_v9", &map_BitOfStandardHLTPath["AlCa_RPCMuonNoHits_v9"], &b_AlCa_RPCMuonNoHits_v9);
   fChain->SetBranchAddress("AlCa_RPCMuonNormalisation_v9", &map_BitOfStandardHLTPath["AlCa_RPCMuonNormalisation_v9"], &b_AlCa_RPCMuonNormalisation_v9);
   fChain->SetBranchAddress("AlCa_LumiPixels_v7", &map_BitOfStandardHLTPath["AlCa_LumiPixels_v7"], &b_AlCa_LumiPixels_v7);
   fChain->SetBranchAddress("AlCa_LumiPixels_ZeroBias_v4", &map_BitOfStandardHLTPath["AlCa_LumiPixels_ZeroBias_v4"], &b_AlCa_LumiPixels_ZeroBias_v4);
   fChain->SetBranchAddress("AlCa_LumiPixels_Random_v1", &map_BitOfStandardHLTPath["AlCa_LumiPixels_Random_v1"], &b_AlCa_LumiPixels_Random_v1);
   fChain->SetBranchAddress("HLT_Activity_Ecal_SC7_v13", &map_BitOfStandardHLTPath["HLT_Activity_Ecal_SC7_v13"], &b_HLT_Activity_Ecal_SC7_v13);
   fChain->SetBranchAddress("HLT_L1SingleJet16_v7", &map_BitOfStandardHLTPath["HLT_L1SingleJet16_v7"], &b_HLT_L1SingleJet16_v7);
   fChain->SetBranchAddress("HLT_L1SingleJet36_v7", &map_BitOfStandardHLTPath["HLT_L1SingleJet36_v7"], &b_HLT_L1SingleJet36_v7);


   // Autogenerated from ConfDB - Prescale SetBranchAddressMaps
   fChain->SetBranchAddress("HLT_PFJet40_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_PFJet40_v6"], &b_HLT_PFJet40_v6_Prescl);
   fChain->SetBranchAddress("HLT_PFJet80_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_PFJet80_v6"], &b_HLT_PFJet80_v6_Prescl);
   fChain->SetBranchAddress("HLT_PFJet140_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_PFJet140_v6"], &b_HLT_PFJet140_v6_Prescl);
   fChain->SetBranchAddress("HLT_PFJet200_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_PFJet200_v6"], &b_HLT_PFJet200_v6_Prescl);
   fChain->SetBranchAddress("HLT_PFJet260_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_PFJet260_v6"], &b_HLT_PFJet260_v6_Prescl);
   fChain->SetBranchAddress("HLT_PFJet320_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_PFJet320_v6"], &b_HLT_PFJet320_v6_Prescl);
   fChain->SetBranchAddress("HLT_Jet370_NoJetID_v14_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Jet370_NoJetID_v14"], &b_HLT_Jet370_NoJetID_v14_Prescl);
   fChain->SetBranchAddress("HLT_PFJet400_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_PFJet400_v6"], &b_HLT_PFJet400_v6_Prescl);
   fChain->SetBranchAddress("HLT_MonoCentralPFJet80_PFMETnoMu105_NHEF0p95_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_MonoCentralPFJet80_PFMETnoMu105_NHEF0p95_v1"], &b_HLT_MonoCentralPFJet80_PFMETnoMu105_NHEF0p95_v1_Prescl);
   fChain->SetBranchAddress("HLT_SingleForJet25_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_SingleForJet25_v3"], &b_HLT_SingleForJet25_v3_Prescl);
   fChain->SetBranchAddress("HLT_SingleForJet15_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_SingleForJet15_v3"], &b_HLT_SingleForJet15_v3_Prescl);
   fChain->SetBranchAddress("HLT_DiPFJetAve40_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DiPFJetAve40_v7"], &b_HLT_DiPFJetAve40_v7_Prescl);
   fChain->SetBranchAddress("HLT_DiPFJetAve80_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DiPFJetAve80_v7"], &b_HLT_DiPFJetAve80_v7_Prescl);
   fChain->SetBranchAddress("HLT_DiPFJetAve140_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DiPFJetAve140_v7"], &b_HLT_DiPFJetAve140_v7_Prescl);
   fChain->SetBranchAddress("HLT_DiPFJetAve200_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DiPFJetAve200_v7"], &b_HLT_DiPFJetAve200_v7_Prescl);
   fChain->SetBranchAddress("HLT_DiPFJetAve260_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DiPFJetAve260_v7"], &b_HLT_DiPFJetAve260_v7_Prescl);
   fChain->SetBranchAddress("HLT_DiPFJetAve320_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DiPFJetAve320_v7"], &b_HLT_DiPFJetAve320_v7_Prescl);
   fChain->SetBranchAddress("HLT_DiPFJetAve400_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DiPFJetAve400_v7"], &b_HLT_DiPFJetAve400_v7_Prescl);
   fChain->SetBranchAddress("HLT_FatDiPFJetMass750_DR1p1_Deta1p5_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_FatDiPFJetMass750_DR1p1_Deta1p5_v6"], &b_HLT_FatDiPFJetMass750_DR1p1_Deta1p5_v6_Prescl);
   fChain->SetBranchAddress("HLT_DoubleJet20_ForwardBackward_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleJet20_ForwardBackward_v3"], &b_HLT_DoubleJet20_ForwardBackward_v3_Prescl);
   fChain->SetBranchAddress("HLT_DiJet80_DiJet60_DiJet20_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DiJet80_DiJet60_DiJet20_v3"], &b_HLT_DiJet80_DiJet60_DiJet20_v3_Prescl);
   fChain->SetBranchAddress("HLT_DiPFJet40_PFMETnoMu65_MJJ800VBF_AllJets_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DiPFJet40_PFMETnoMu65_MJJ800VBF_AllJets_v6"], &b_HLT_DiPFJet40_PFMETnoMu65_MJJ800VBF_AllJets_v6_Prescl);
   fChain->SetBranchAddress("HLT_DiPFJet40_PFMETnoMu65_MJJ600VBF_LeadingJets_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DiPFJet40_PFMETnoMu65_MJJ600VBF_LeadingJets_v6"], &b_HLT_DiPFJet40_PFMETnoMu65_MJJ600VBF_LeadingJets_v6_Prescl);
   fChain->SetBranchAddress("HLT_DiJet40Eta2p6_BTagIP3DFastPV_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DiJet40Eta2p6_BTagIP3DFastPV_v5"], &b_HLT_DiJet40Eta2p6_BTagIP3DFastPV_v5_Prescl);
   fChain->SetBranchAddress("HLT_DiJet80Eta2p6_BTagIP3DFastPVLoose_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DiJet80Eta2p6_BTagIP3DFastPVLoose_v5"], &b_HLT_DiJet80Eta2p6_BTagIP3DFastPVLoose_v5_Prescl);
   fChain->SetBranchAddress("HLT_Jet60Eta1p7_Jet53Eta1p7_DiBTagIP3DFastPV_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Jet60Eta1p7_Jet53Eta1p7_DiBTagIP3DFastPV_v5"], &b_HLT_Jet60Eta1p7_Jet53Eta1p7_DiBTagIP3DFastPV_v5_Prescl);
   fChain->SetBranchAddress("HLT_Jet80Eta1p7_Jet70Eta1p7_DiBTagIP3DFastPV_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Jet80Eta1p7_Jet70Eta1p7_DiBTagIP3DFastPV_v5"], &b_HLT_Jet80Eta1p7_Jet70Eta1p7_DiBTagIP3DFastPV_v5_Prescl);
   fChain->SetBranchAddress("HLT_Jet160Eta2p4_Jet120Eta2p4_DiBTagIP3DFastPVLoose_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Jet160Eta2p4_Jet120Eta2p4_DiBTagIP3DFastPVLoose_v5"], &b_HLT_Jet160Eta2p4_Jet120Eta2p4_DiBTagIP3DFastPVLoose_v5_Prescl);
   fChain->SetBranchAddress("HLT_QuadJet50_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_QuadJet50_v3"], &b_HLT_QuadJet50_v3_Prescl);
   fChain->SetBranchAddress("HLT_QuadJet50_Jet20_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_QuadJet50_Jet20_v2"], &b_HLT_QuadJet50_Jet20_v2_Prescl);
   fChain->SetBranchAddress("HLT_QuadJet60_DiJet20_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_QuadJet60_DiJet20_v3"], &b_HLT_QuadJet60_DiJet20_v3_Prescl);
   fChain->SetBranchAddress("HLT_QuadJet70_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_QuadJet70_v3"], &b_HLT_QuadJet70_v3_Prescl);
   fChain->SetBranchAddress("HLT_QuadJet80_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_QuadJet80_v3"], &b_HLT_QuadJet80_v3_Prescl);
   fChain->SetBranchAddress("HLT_QuadJet90_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_QuadJet90_v3"], &b_HLT_QuadJet90_v3_Prescl);
   fChain->SetBranchAddress("HLT_QuadJet75_55_35_20_BTagIP_VBF_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_QuadJet75_55_35_20_BTagIP_VBF_v4"], &b_HLT_QuadJet75_55_35_20_BTagIP_VBF_v4_Prescl);
   fChain->SetBranchAddress("HLT_QuadJet75_55_38_20_BTagIP_VBF_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_QuadJet75_55_38_20_BTagIP_VBF_v4"], &b_HLT_QuadJet75_55_38_20_BTagIP_VBF_v4_Prescl);
   fChain->SetBranchAddress("HLT_QuadPFJet78_61_44_31_BTagCSV_VBF_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_QuadPFJet78_61_44_31_BTagCSV_VBF_v2"], &b_HLT_QuadPFJet78_61_44_31_BTagCSV_VBF_v2_Prescl);
   fChain->SetBranchAddress("HLT_QuadPFJet82_65_48_35_BTagCSV_VBF_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_QuadPFJet82_65_48_35_BTagCSV_VBF_v2"], &b_HLT_QuadPFJet82_65_48_35_BTagCSV_VBF_v2_Prescl);
   fChain->SetBranchAddress("HLT_SixJet35_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_SixJet35_v3"], &b_HLT_SixJet35_v3_Prescl);
   fChain->SetBranchAddress("HLT_SixJet45_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_SixJet45_v3"], &b_HLT_SixJet45_v3_Prescl);
   fChain->SetBranchAddress("HLT_SixJet50_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_SixJet50_v3"], &b_HLT_SixJet50_v3_Prescl);
   fChain->SetBranchAddress("HLT_EightJet30_eta3p0_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_EightJet30_eta3p0_v2"], &b_HLT_EightJet30_eta3p0_v2_Prescl);
   fChain->SetBranchAddress("HLT_EightJet35_eta3p0_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_EightJet35_eta3p0_v2"], &b_HLT_EightJet35_eta3p0_v2_Prescl);
   fChain->SetBranchAddress("HLT_ExclDiJet35_HFOR_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_ExclDiJet35_HFOR_v3"], &b_HLT_ExclDiJet35_HFOR_v3_Prescl);
   fChain->SetBranchAddress("HLT_ExclDiJet35_HFAND_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_ExclDiJet35_HFAND_v3"], &b_HLT_ExclDiJet35_HFAND_v3_Prescl);
   fChain->SetBranchAddress("HLT_ExclDiJet80_HFAND_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_ExclDiJet80_HFAND_v3"], &b_HLT_ExclDiJet80_HFAND_v3_Prescl);
   fChain->SetBranchAddress("HLT_JetE30_NoBPTX_v13_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_JetE30_NoBPTX_v13"], &b_HLT_JetE30_NoBPTX_v13_Prescl);
   fChain->SetBranchAddress("HLT_JetE30_NoBPTX3BX_NoHalo_v14_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_JetE30_NoBPTX3BX_NoHalo_v14"], &b_HLT_JetE30_NoBPTX3BX_NoHalo_v14_Prescl);
   fChain->SetBranchAddress("HLT_JetE50_NoBPTX3BX_NoHalo_v11_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_JetE50_NoBPTX3BX_NoHalo_v11"], &b_HLT_JetE50_NoBPTX3BX_NoHalo_v11_Prescl);
   fChain->SetBranchAddress("HLT_JetE70_NoBPTX3BX_NoHalo_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_JetE70_NoBPTX3BX_NoHalo_v3"], &b_HLT_JetE70_NoBPTX3BX_NoHalo_v3_Prescl);
   fChain->SetBranchAddress("HLT_HT200_AlphaT0p57_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_HT200_AlphaT0p57_v6"], &b_HLT_HT200_AlphaT0p57_v6_Prescl);
   fChain->SetBranchAddress("HLT_HT200_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_HT200_v4"], &b_HLT_HT200_v4_Prescl);
   fChain->SetBranchAddress("HLT_HT250_AlphaT0p55_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_HT250_AlphaT0p55_v5"], &b_HLT_HT250_AlphaT0p55_v5_Prescl);
   fChain->SetBranchAddress("HLT_HT250_AlphaT0p57_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_HT250_AlphaT0p57_v5"], &b_HLT_HT250_AlphaT0p57_v5_Prescl);
   fChain->SetBranchAddress("HLT_HT250_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_HT250_v4"], &b_HLT_HT250_v4_Prescl);
   fChain->SetBranchAddress("HLT_HT300_AlphaT0p53_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_HT300_AlphaT0p53_v5"], &b_HLT_HT300_AlphaT0p53_v5_Prescl);
   fChain->SetBranchAddress("HLT_HT300_AlphaT0p54_v11_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_HT300_AlphaT0p54_v11"], &b_HLT_HT300_AlphaT0p54_v11_Prescl);
   fChain->SetBranchAddress("HLT_HT300_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_HT300_v4"], &b_HLT_HT300_v4_Prescl);
   fChain->SetBranchAddress("HLT_HT300_DoubleDisplacedPFJet60_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_HT300_DoubleDisplacedPFJet60_v6"], &b_HLT_HT300_DoubleDisplacedPFJet60_v6_Prescl);
   fChain->SetBranchAddress("HLT_HT300_DoubleDisplacedPFJet60_ChgFraction10_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_HT300_DoubleDisplacedPFJet60_ChgFraction10_v6"], &b_HLT_HT300_DoubleDisplacedPFJet60_ChgFraction10_v6_Prescl);
   fChain->SetBranchAddress("HLT_HT300_SingleDisplacedPFJet60_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_HT300_SingleDisplacedPFJet60_v6"], &b_HLT_HT300_SingleDisplacedPFJet60_v6_Prescl);
   fChain->SetBranchAddress("HLT_HT300_SingleDisplacedPFJet60_ChgFraction10_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_HT300_SingleDisplacedPFJet60_ChgFraction10_v6"], &b_HLT_HT300_SingleDisplacedPFJet60_ChgFraction10_v6_Prescl);
   fChain->SetBranchAddress("HLT_HT350_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_HT350_v4"], &b_HLT_HT350_v4_Prescl);
   fChain->SetBranchAddress("HLT_HT350_AlphaT0p52_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_HT350_AlphaT0p52_v5"], &b_HLT_HT350_AlphaT0p52_v5_Prescl);
   fChain->SetBranchAddress("HLT_HT350_AlphaT0p53_v16_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_HT350_AlphaT0p53_v16"], &b_HLT_HT350_AlphaT0p53_v16_Prescl);
   fChain->SetBranchAddress("HLT_HT400_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_HT400_v4"], &b_HLT_HT400_v4_Prescl);
   fChain->SetBranchAddress("HLT_HT400_AlphaT0p51_v16_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_HT400_AlphaT0p51_v16"], &b_HLT_HT400_AlphaT0p51_v16_Prescl);
   fChain->SetBranchAddress("HLT_HT400_AlphaT0p52_v11_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_HT400_AlphaT0p52_v11"], &b_HLT_HT400_AlphaT0p52_v11_Prescl);
   fChain->SetBranchAddress("HLT_HT450_AlphaT0p51_v11_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_HT450_AlphaT0p51_v11"], &b_HLT_HT450_AlphaT0p51_v11_Prescl);
   fChain->SetBranchAddress("HLT_HT450_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_HT450_v4"], &b_HLT_HT450_v4_Prescl);
   fChain->SetBranchAddress("HLT_HT500_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_HT500_v4"], &b_HLT_HT500_v4_Prescl);
   fChain->SetBranchAddress("HLT_HT550_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_HT550_v4"], &b_HLT_HT550_v4_Prescl);
   fChain->SetBranchAddress("HLT_HT650_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_HT650_v4"], &b_HLT_HT650_v4_Prescl);
   fChain->SetBranchAddress("HLT_HT650_Track50_dEdx3p6_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_HT650_Track50_dEdx3p6_v7"], &b_HLT_HT650_Track50_dEdx3p6_v7_Prescl);
   fChain->SetBranchAddress("HLT_HT650_Track60_dEdx3p7_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_HT650_Track60_dEdx3p7_v7"], &b_HLT_HT650_Track60_dEdx3p7_v7_Prescl);
   fChain->SetBranchAddress("HLT_HT750_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_HT750_v4"], &b_HLT_HT750_v4_Prescl);
   fChain->SetBranchAddress("HLT_PFNoPUHT350_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_PFNoPUHT350_v1"], &b_HLT_PFNoPUHT350_v1_Prescl);
   fChain->SetBranchAddress("HLT_PFNoPUHT650_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_PFNoPUHT650_v1"], &b_HLT_PFNoPUHT650_v1_Prescl);
   fChain->SetBranchAddress("HLT_PFNoPUHT650_DiCentralPFNoPUJet80_CenPFNoPUJet40_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_PFNoPUHT650_DiCentralPFNoPUJet80_CenPFNoPUJet40_v1"], &b_HLT_PFNoPUHT650_DiCentralPFNoPUJet80_CenPFNoPUJet40_v1_Prescl);
   fChain->SetBranchAddress("HLT_PFNoPUHT700_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_PFNoPUHT700_v1"], &b_HLT_PFNoPUHT700_v1_Prescl);
   fChain->SetBranchAddress("HLT_PFNoPUHT750_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_PFNoPUHT750_v1"], &b_HLT_PFNoPUHT750_v1_Prescl);
   fChain->SetBranchAddress("HLT_PFMET150_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_PFMET150_v5"], &b_HLT_PFMET150_v5_Prescl);
   fChain->SetBranchAddress("HLT_PFMET180_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_PFMET180_v5"], &b_HLT_PFMET180_v5_Prescl);
   fChain->SetBranchAddress("HLT_DiCentralJetSumpT100_dPhi05_DiCentralPFJet60_25_PFMET100_HBHENoiseCleaned_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DiCentralJetSumpT100_dPhi05_DiCentralPFJet60_25_PFMET100_HBHENoiseCleaned_v2"], &b_HLT_DiCentralJetSumpT100_dPhi05_DiCentralPFJet60_25_PFMET100_HBHENoiseCleaned_v2_Prescl);
   fChain->SetBranchAddress("HLT_DiCentralPFJet30_PFMET80_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DiCentralPFJet30_PFMET80_v3"], &b_HLT_DiCentralPFJet30_PFMET80_v3_Prescl);
   fChain->SetBranchAddress("HLT_DiCentralPFNoPUJet50_PFMETORPFMETNoMu80_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DiCentralPFNoPUJet50_PFMETORPFMETNoMu80_v1"], &b_HLT_DiCentralPFNoPUJet50_PFMETORPFMETNoMu80_v1_Prescl);
   fChain->SetBranchAddress("HLT_DiCentralPFJet30_PFMET80_BTagCSV07_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DiCentralPFJet30_PFMET80_BTagCSV07_v2"], &b_HLT_DiCentralPFJet30_PFMET80_BTagCSV07_v2_Prescl);
   fChain->SetBranchAddress("HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05d03_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05d03_v2"], &b_HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05d03_v2_Prescl);
   fChain->SetBranchAddress("HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05d05_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05d05_v2"], &b_HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05d05_v2_Prescl);
   fChain->SetBranchAddress("HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05_v2"], &b_HLT_DiPFJet80_DiPFJet30_BTagCSVd07d05_v2_Prescl);
   fChain->SetBranchAddress("HLT_MET80_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_MET80_v4"], &b_HLT_MET80_v4_Prescl);
   fChain->SetBranchAddress("HLT_MET80_Track50_dEdx3p6_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_MET80_Track50_dEdx3p6_v5"], &b_HLT_MET80_Track50_dEdx3p6_v5_Prescl);
   fChain->SetBranchAddress("HLT_MET80_Track60_dEdx3p7_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_MET80_Track60_dEdx3p7_v5"], &b_HLT_MET80_Track60_dEdx3p7_v5_Prescl);
   fChain->SetBranchAddress("HLT_MET120_v11_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_MET120_v11"], &b_HLT_MET120_v11_Prescl);
   fChain->SetBranchAddress("HLT_MET120_HBHENoiseCleaned_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_MET120_HBHENoiseCleaned_v4"], &b_HLT_MET120_HBHENoiseCleaned_v4_Prescl);
   fChain->SetBranchAddress("HLT_MET200_v11_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_MET200_v11"], &b_HLT_MET200_v11_Prescl);
   fChain->SetBranchAddress("HLT_MET200_HBHENoiseCleaned_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_MET200_HBHENoiseCleaned_v4"], &b_HLT_MET200_HBHENoiseCleaned_v4_Prescl);
   fChain->SetBranchAddress("HLT_MET300_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_MET300_v3"], &b_HLT_MET300_v3_Prescl);
   fChain->SetBranchAddress("HLT_MET300_HBHENoiseCleaned_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_MET300_HBHENoiseCleaned_v4"], &b_HLT_MET300_HBHENoiseCleaned_v4_Prescl);
   fChain->SetBranchAddress("HLT_MET400_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_MET400_v6"], &b_HLT_MET400_v6_Prescl);
   fChain->SetBranchAddress("HLT_MET400_HBHENoiseCleaned_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_MET400_HBHENoiseCleaned_v4"], &b_HLT_MET400_HBHENoiseCleaned_v4_Prescl);
   fChain->SetBranchAddress("HLT_L1SingleMuOpen_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_L1SingleMuOpen_v7"], &b_HLT_L1SingleMuOpen_v7_Prescl);
   fChain->SetBranchAddress("HLT_L1SingleMu12_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_L1SingleMu12_v2"], &b_HLT_L1SingleMu12_v2_Prescl);
   fChain->SetBranchAddress("HLT_L2Mu70_eta2p1_PFMET55_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_L2Mu70_eta2p1_PFMET55_v2"], &b_HLT_L2Mu70_eta2p1_PFMET55_v2_Prescl);
   fChain->SetBranchAddress("HLT_L2Mu70_eta2p1_PFMET60_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_L2Mu70_eta2p1_PFMET60_v2"], &b_HLT_L2Mu70_eta2p1_PFMET60_v2_Prescl);
   fChain->SetBranchAddress("HLT_L2Mu20_eta2p1_NoVertex_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_L2Mu20_eta2p1_NoVertex_v2"], &b_HLT_L2Mu20_eta2p1_NoVertex_v2_Prescl);
   fChain->SetBranchAddress("HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo_v3"], &b_HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo_v3_Prescl);
   fChain->SetBranchAddress("HLT_L2Mu20_NoVertex_2Cha_NoBPTX3BX_NoHalo_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_L2Mu20_NoVertex_2Cha_NoBPTX3BX_NoHalo_v1"], &b_HLT_L2Mu20_NoVertex_2Cha_NoBPTX3BX_NoHalo_v1_Prescl);
   fChain->SetBranchAddress("HLT_L2Mu30_NoVertex_2Cha_NoBPTX3BX_NoHalo_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_L2Mu30_NoVertex_2Cha_NoBPTX3BX_NoHalo_v1"], &b_HLT_L2Mu30_NoVertex_2Cha_NoBPTX3BX_NoHalo_v1_Prescl);
   fChain->SetBranchAddress("HLT_L2TripleMu10_0_0_NoVertex_PFJet40Neutral_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_L2TripleMu10_0_0_NoVertex_PFJet40Neutral_v5"], &b_HLT_L2TripleMu10_0_0_NoVertex_PFJet40Neutral_v5_Prescl);
   fChain->SetBranchAddress("HLT_DoubleDisplacedMu4_DiPFJet40Neutral_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleDisplacedMu4_DiPFJet40Neutral_v5"], &b_HLT_DoubleDisplacedMu4_DiPFJet40Neutral_v5_Prescl);
   fChain->SetBranchAddress("HLT_Mu5_v19_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu5_v19"], &b_HLT_Mu5_v19_Prescl);
   fChain->SetBranchAddress("HLT_Mu8_v17_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu8_v17"], &b_HLT_Mu8_v17_Prescl);
   fChain->SetBranchAddress("HLT_Mu12_v17_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu12_v17"], &b_HLT_Mu12_v17_Prescl);
   fChain->SetBranchAddress("HLT_Mu17_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu17_v4"], &b_HLT_Mu17_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu12_eta2p1_L1Mu10erJetC12WdEtaPhi1DiJetsC_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu12_eta2p1_L1Mu10erJetC12WdEtaPhi1DiJetsC_v4"], &b_HLT_Mu12_eta2p1_L1Mu10erJetC12WdEtaPhi1DiJetsC_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu15_eta2p1_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu15_eta2p1_v4"], &b_HLT_Mu15_eta2p1_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu24_v15_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu24_v15"], &b_HLT_Mu24_v15_Prescl);
   fChain->SetBranchAddress("HLT_Mu24_eta2p1_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu24_eta2p1_v4"], &b_HLT_Mu24_eta2p1_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu30_v15_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu30_v15"], &b_HLT_Mu30_v15_Prescl);
   fChain->SetBranchAddress("HLT_Mu30_eta2p1_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu30_eta2p1_v4"], &b_HLT_Mu30_eta2p1_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu40_v13_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu40_v13"], &b_HLT_Mu40_v13_Prescl);
   fChain->SetBranchAddress("HLT_Mu40_eta2p1_v10_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu40_eta2p1_v10"], &b_HLT_Mu40_eta2p1_v10_Prescl);
   fChain->SetBranchAddress("HLT_Mu50_eta2p1_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu50_eta2p1_v7"], &b_HLT_Mu50_eta2p1_v7_Prescl);
   fChain->SetBranchAddress("HLT_RelIso1p0Mu5_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_RelIso1p0Mu5_v5"], &b_HLT_RelIso1p0Mu5_v5_Prescl);
   fChain->SetBranchAddress("HLT_RelIso1p0Mu20_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_RelIso1p0Mu20_v2"], &b_HLT_RelIso1p0Mu20_v2_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu15_eta2p1_L1ETM20_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_IsoMu15_eta2p1_L1ETM20_v6"], &b_HLT_IsoMu15_eta2p1_L1ETM20_v6_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu20_eta2p1_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_IsoMu20_eta2p1_v6"], &b_HLT_IsoMu20_eta2p1_v6_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu24_v16_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_IsoMu24_v16"], &b_HLT_IsoMu24_v16_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1_v14_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_IsoMu24_eta2p1_v14"], &b_HLT_IsoMu24_eta2p1_v14_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu30_v10_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_IsoMu30_v10"], &b_HLT_IsoMu30_v10_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu30_eta2p1_v14_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_IsoMu30_eta2p1_v14"], &b_HLT_IsoMu30_eta2p1_v14_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu34_eta2p1_v12_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_IsoMu34_eta2p1_v12"], &b_HLT_IsoMu34_eta2p1_v12_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu40_eta2p1_v9_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_IsoMu40_eta2p1_v9"], &b_HLT_IsoMu40_eta2p1_v9_Prescl);
   fChain->SetBranchAddress("HLT_Mu40_eta2p1_Track50_dEdx3p6_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu40_eta2p1_Track50_dEdx3p6_v4"], &b_HLT_Mu40_eta2p1_Track50_dEdx3p6_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu40_eta2p1_Track60_dEdx3p7_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu40_eta2p1_Track60_dEdx3p7_v4"], &b_HLT_Mu40_eta2p1_Track60_dEdx3p7_v4_Prescl);
   fChain->SetBranchAddress("HLT_L2DoubleMu23_NoVertex_v11_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_L2DoubleMu23_NoVertex_v11"], &b_HLT_L2DoubleMu23_NoVertex_v11_Prescl);
   fChain->SetBranchAddress("HLT_L2DoubleMu23_NoVertex_2Cha_Angle2p5_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_L2DoubleMu23_NoVertex_2Cha_Angle2p5_v3"], &b_HLT_L2DoubleMu23_NoVertex_2Cha_Angle2p5_v3_Prescl);
   fChain->SetBranchAddress("HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_v3"], &b_HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_v3_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMu11_Acoplanarity03_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleMu11_Acoplanarity03_v4"], &b_HLT_DoubleMu11_Acoplanarity03_v4_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMu4_Jpsi_Displaced_v10_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleMu4_Jpsi_Displaced_v10"], &b_HLT_DoubleMu4_Jpsi_Displaced_v10_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMu4_JpsiTk_Displaced_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleMu4_JpsiTk_Displaced_v4"], &b_HLT_DoubleMu4_JpsiTk_Displaced_v4_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMu3_4_Dimuon5_Bs_Central_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleMu3_4_Dimuon5_Bs_Central_v3"], &b_HLT_DoubleMu3_4_Dimuon5_Bs_Central_v3_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMu3p5_4_Dimuon5_Bs_Central_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleMu3p5_4_Dimuon5_Bs_Central_v3"], &b_HLT_DoubleMu3p5_4_Dimuon5_Bs_Central_v3_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMu4_Dimuon7_Bs_Forward_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleMu4_Dimuon7_Bs_Forward_v3"], &b_HLT_DoubleMu4_Dimuon7_Bs_Forward_v3_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMu3p5_LowMass_Displaced_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleMu3p5_LowMass_Displaced_v4"], &b_HLT_DoubleMu3p5_LowMass_Displaced_v4_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMu3p5_LowMassNonResonant_Displaced_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleMu3p5_LowMassNonResonant_Displaced_v4"], &b_HLT_DoubleMu3p5_LowMassNonResonant_Displaced_v4_Prescl);
   fChain->SetBranchAddress("HLT_Dimuon0_Jpsi_v15_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Dimuon0_Jpsi_v15"], &b_HLT_Dimuon0_Jpsi_v15_Prescl);
   fChain->SetBranchAddress("HLT_Dimuon0_Jpsi_NoVertexing_v12_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Dimuon0_Jpsi_NoVertexing_v12"], &b_HLT_Dimuon0_Jpsi_NoVertexing_v12_Prescl);
   fChain->SetBranchAddress("HLT_Dimuon0_Upsilon_v15_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Dimuon0_Upsilon_v15"], &b_HLT_Dimuon0_Upsilon_v15_Prescl);
   fChain->SetBranchAddress("HLT_Dimuon0_PsiPrime_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Dimuon0_PsiPrime_v4"], &b_HLT_Dimuon0_PsiPrime_v4_Prescl);
   fChain->SetBranchAddress("HLT_Dimuon5_Upsilon_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Dimuon5_Upsilon_v4"], &b_HLT_Dimuon5_Upsilon_v4_Prescl);
   fChain->SetBranchAddress("HLT_Dimuon5_PsiPrime_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Dimuon5_PsiPrime_v4"], &b_HLT_Dimuon5_PsiPrime_v4_Prescl);
   fChain->SetBranchAddress("HLT_Dimuon7_Upsilon_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Dimuon7_Upsilon_v5"], &b_HLT_Dimuon7_Upsilon_v5_Prescl);
   fChain->SetBranchAddress("HLT_Dimuon7_PsiPrime_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Dimuon7_PsiPrime_v1"], &b_HLT_Dimuon7_PsiPrime_v1_Prescl);
   fChain->SetBranchAddress("HLT_Dimuon8_Jpsi_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Dimuon8_Jpsi_v5"], &b_HLT_Dimuon8_Jpsi_v5_Prescl);
   fChain->SetBranchAddress("HLT_Dimuon8_Upsilon_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Dimuon8_Upsilon_v4"], &b_HLT_Dimuon8_Upsilon_v4_Prescl);
   fChain->SetBranchAddress("HLT_Dimuon10_Jpsi_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Dimuon10_Jpsi_v4"], &b_HLT_Dimuon10_Jpsi_v4_Prescl);
   fChain->SetBranchAddress("HLT_Dimuon11_Upsilon_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Dimuon11_Upsilon_v4"], &b_HLT_Dimuon11_Upsilon_v4_Prescl);
   fChain->SetBranchAddress("HLT_Dimuon0_Jpsi_Muon_v16_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Dimuon0_Jpsi_Muon_v16"], &b_HLT_Dimuon0_Jpsi_Muon_v16_Prescl);
   fChain->SetBranchAddress("HLT_Dimuon0_Upsilon_Muon_v16_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Dimuon0_Upsilon_Muon_v16"], &b_HLT_Dimuon0_Upsilon_Muon_v16_Prescl);
   fChain->SetBranchAddress("HLT_Dimuon3p5_SameSign_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Dimuon3p5_SameSign_v4"], &b_HLT_Dimuon3p5_SameSign_v4_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMu4_Acoplanarity03_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleMu4_Acoplanarity03_v4"], &b_HLT_DoubleMu4_Acoplanarity03_v4_Prescl);
   fChain->SetBranchAddress("HLT_Tau2Mu_ItTrack_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Tau2Mu_ItTrack_v4"], &b_HLT_Tau2Mu_ItTrack_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu13_Mu8_v18_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu13_Mu8_v18"], &b_HLT_Mu13_Mu8_v18_Prescl);
   fChain->SetBranchAddress("HLT_Mu17_Mu8_v18_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu17_Mu8_v18"], &b_HLT_Mu17_Mu8_v18_Prescl);
   fChain->SetBranchAddress("HLT_Mu17_TkMu8_v11_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu17_TkMu8_v11"], &b_HLT_Mu17_TkMu8_v11_Prescl);
   fChain->SetBranchAddress("HLT_Mu22_TkMu8_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu22_TkMu8_v7"], &b_HLT_Mu22_TkMu8_v7_Prescl);
   fChain->SetBranchAddress("HLT_Mu22_TkMu22_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu22_TkMu22_v7"], &b_HLT_Mu22_TkMu22_v7_Prescl);
   fChain->SetBranchAddress("HLT_TripleMu5_v18_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_TripleMu5_v18"], &b_HLT_TripleMu5_v18_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMu5_IsoMu5_v19_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleMu5_IsoMu5_v19"], &b_HLT_DoubleMu5_IsoMu5_v19_Prescl);
   fChain->SetBranchAddress("HLT_Mu5_L2Mu3_Jpsi_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu5_L2Mu3_Jpsi_v5"], &b_HLT_Mu5_L2Mu3_Jpsi_v5_Prescl);
   fChain->SetBranchAddress("HLT_Mu5_Track2_Jpsi_v19_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu5_Track2_Jpsi_v19"], &b_HLT_Mu5_Track2_Jpsi_v19_Prescl);
   fChain->SetBranchAddress("HLT_Mu5_Track3p5_Jpsi_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu5_Track3p5_Jpsi_v5"], &b_HLT_Mu5_Track3p5_Jpsi_v5_Prescl);
   fChain->SetBranchAddress("HLT_Mu7_Track7_Jpsi_v19_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu7_Track7_Jpsi_v19"], &b_HLT_Mu7_Track7_Jpsi_v19_Prescl);
   fChain->SetBranchAddress("HLT_Photon20_CaloIdVL_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon20_CaloIdVL_v4"], &b_HLT_Photon20_CaloIdVL_v4_Prescl);
   fChain->SetBranchAddress("HLT_Photon20_CaloIdVL_IsoL_v16_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon20_CaloIdVL_IsoL_v16"], &b_HLT_Photon20_CaloIdVL_IsoL_v16_Prescl);
   fChain->SetBranchAddress("HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_v5"], &b_HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_v5_Prescl);
   fChain->SetBranchAddress("HLT_Photon26_Photon18_v12_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon26_Photon18_v12"], &b_HLT_Photon26_Photon18_v12_Prescl);
   fChain->SetBranchAddress("HLT_Photon26_R9Id85_Photon18_R9Id85_Mass60_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon26_R9Id85_Photon18_R9Id85_Mass60_v4"], &b_HLT_Photon26_R9Id85_Photon18_R9Id85_Mass60_v4_Prescl);
   fChain->SetBranchAddress("HLT_Photon26_R9Id85_Photon18_CaloId10_Iso50_Mass60_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon26_R9Id85_Photon18_CaloId10_Iso50_Mass60_v6"], &b_HLT_Photon26_R9Id85_Photon18_CaloId10_Iso50_Mass60_v6_Prescl);
   fChain->SetBranchAddress("HLT_Photon26_CaloId10_Iso50_Photon18_R9Id85_Mass60_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon26_CaloId10_Iso50_Photon18_R9Id85_Mass60_v6"], &b_HLT_Photon26_CaloId10_Iso50_Photon18_R9Id85_Mass60_v6_Prescl);
   fChain->SetBranchAddress("HLT_Photon26_CaloId10_Iso50_Photon18_CaloId10_Iso50_Mass60_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon26_CaloId10_Iso50_Photon18_CaloId10_Iso50_Mass60_v6"], &b_HLT_Photon26_CaloId10_Iso50_Photon18_CaloId10_Iso50_Mass60_v6_Prescl);
   fChain->SetBranchAddress("HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass60_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass60_v6"], &b_HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass60_v6_Prescl);
   fChain->SetBranchAddress("HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass70_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass70_v2"], &b_HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass70_v2_Prescl);
   fChain->SetBranchAddress("HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_v5"], &b_HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_v5_Prescl);
   fChain->SetBranchAddress("HLT_Photon30_CaloIdVL_v14_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon30_CaloIdVL_v14"], &b_HLT_Photon30_CaloIdVL_v14_Prescl);
   fChain->SetBranchAddress("HLT_Photon30_CaloIdVL_IsoL_v19_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon30_CaloIdVL_IsoL_v19"], &b_HLT_Photon30_CaloIdVL_IsoL_v19_Prescl);
   fChain->SetBranchAddress("HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_v5"], &b_HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_v5_Prescl);
   fChain->SetBranchAddress("HLT_Photon36_Photon22_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon36_Photon22_v6"], &b_HLT_Photon36_Photon22_v6_Prescl);
   fChain->SetBranchAddress("HLT_Photon36_R9Id85_Photon22_R9Id85_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon36_R9Id85_Photon22_R9Id85_v4"], &b_HLT_Photon36_R9Id85_Photon22_R9Id85_v4_Prescl);
   fChain->SetBranchAddress("HLT_Photon36_R9Id85_Photon22_CaloId10_Iso50_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon36_R9Id85_Photon22_CaloId10_Iso50_v6"], &b_HLT_Photon36_R9Id85_Photon22_CaloId10_Iso50_v6_Prescl);
   fChain->SetBranchAddress("HLT_Photon36_CaloId10_Iso50_Photon22_R9Id85_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon36_CaloId10_Iso50_Photon22_R9Id85_v6"], &b_HLT_Photon36_CaloId10_Iso50_Photon22_R9Id85_v6_Prescl);
   fChain->SetBranchAddress("HLT_Photon36_CaloId10_Iso50_Photon22_CaloId10_Iso50_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon36_CaloId10_Iso50_Photon22_CaloId10_Iso50_v6"], &b_HLT_Photon36_CaloId10_Iso50_Photon22_CaloId10_Iso50_v6_Prescl);
   fChain->SetBranchAddress("HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_R9Id85_OR_CaloId10_Iso50_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_R9Id85_OR_CaloId10_Iso50_v6"], &b_HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_R9Id85_OR_CaloId10_Iso50_v6_Prescl);
   fChain->SetBranchAddress("HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_v5"], &b_HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_v5_Prescl);
   fChain->SetBranchAddress("HLT_Photon50_CaloIdVL_v10_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon50_CaloIdVL_v10"], &b_HLT_Photon50_CaloIdVL_v10_Prescl);
   fChain->SetBranchAddress("HLT_Photon50_CaloIdVL_IsoL_v17_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon50_CaloIdVL_IsoL_v17"], &b_HLT_Photon50_CaloIdVL_IsoL_v17_Prescl);
   fChain->SetBranchAddress("HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_v5"], &b_HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_v5_Prescl);
   fChain->SetBranchAddress("HLT_Photon60_CaloIdL_MHT70_v9_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon60_CaloIdL_MHT70_v9"], &b_HLT_Photon60_CaloIdL_MHT70_v9_Prescl);
   fChain->SetBranchAddress("HLT_Photon60_CaloIdL_HT300_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon60_CaloIdL_HT300_v2"], &b_HLT_Photon60_CaloIdL_HT300_v2_Prescl);
   fChain->SetBranchAddress("HLT_Photon70_CaloIdXL_PFNoPUHT400_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon70_CaloIdXL_PFNoPUHT400_v1"], &b_HLT_Photon70_CaloIdXL_PFNoPUHT400_v1_Prescl);
   fChain->SetBranchAddress("HLT_Photon70_CaloIdXL_PFNoPUHT500_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon70_CaloIdXL_PFNoPUHT500_v1"], &b_HLT_Photon70_CaloIdXL_PFNoPUHT500_v1_Prescl);
   fChain->SetBranchAddress("HLT_Photon70_CaloIdXL_PFMET100_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon70_CaloIdXL_PFMET100_v5"], &b_HLT_Photon70_CaloIdXL_PFMET100_v5_Prescl);
   fChain->SetBranchAddress("HLT_Photon75_CaloIdVL_v13_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon75_CaloIdVL_v13"], &b_HLT_Photon75_CaloIdVL_v13_Prescl);
   fChain->SetBranchAddress("HLT_Photon75_CaloIdVL_IsoL_v18_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon75_CaloIdVL_IsoL_v18"], &b_HLT_Photon75_CaloIdVL_IsoL_v18_Prescl);
   fChain->SetBranchAddress("HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_v5"], &b_HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_v5_Prescl);
   fChain->SetBranchAddress("HLT_Photon90_CaloIdVL_v10_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon90_CaloIdVL_v10"], &b_HLT_Photon90_CaloIdVL_v10_Prescl);
   fChain->SetBranchAddress("HLT_Photon90_CaloIdVL_IsoL_v15_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon90_CaloIdVL_IsoL_v15"], &b_HLT_Photon90_CaloIdVL_IsoL_v15_Prescl);
   fChain->SetBranchAddress("HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_v5"], &b_HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_v5_Prescl);
   fChain->SetBranchAddress("HLT_DisplacedPhoton65_CaloIdVL_IsoL_PFMET25_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DisplacedPhoton65_CaloIdVL_IsoL_PFMET25_v2"], &b_HLT_DisplacedPhoton65_CaloIdVL_IsoL_PFMET25_v2_Prescl);
   fChain->SetBranchAddress("HLT_DisplacedPhoton65EBOnly_CaloIdVL_IsoL_PFMET30_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DisplacedPhoton65EBOnly_CaloIdVL_IsoL_PFMET30_v2"], &b_HLT_DisplacedPhoton65EBOnly_CaloIdVL_IsoL_PFMET30_v2_Prescl);
   fChain->SetBranchAddress("HLT_Photon135_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon135_v7"], &b_HLT_Photon135_v7_Prescl);
   fChain->SetBranchAddress("HLT_Photon150_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon150_v4"], &b_HLT_Photon150_v4_Prescl);
   fChain->SetBranchAddress("HLT_Photon160_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon160_v4"], &b_HLT_Photon160_v4_Prescl);
   fChain->SetBranchAddress("HLT_Photon300_NoHE_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon300_NoHE_v5"], &b_HLT_Photon300_NoHE_v5_Prescl);
   fChain->SetBranchAddress("HLT_DoublePhoton48_HEVT_v8_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoublePhoton48_HEVT_v8"], &b_HLT_DoublePhoton48_HEVT_v8_Prescl);
   fChain->SetBranchAddress("HLT_DoublePhoton53_HEVT_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoublePhoton53_HEVT_v2"], &b_HLT_DoublePhoton53_HEVT_v2_Prescl);
   fChain->SetBranchAddress("HLT_DoublePhoton70_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoublePhoton70_v6"], &b_HLT_DoublePhoton70_v6_Prescl);
   fChain->SetBranchAddress("HLT_DoublePhoton80_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoublePhoton80_v7"], &b_HLT_DoublePhoton80_v7_Prescl);
   fChain->SetBranchAddress("HLT_DoublePhoton5_IsoVL_CEP_v16_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoublePhoton5_IsoVL_CEP_v16"], &b_HLT_DoublePhoton5_IsoVL_CEP_v16_Prescl);
   fChain->SetBranchAddress("HLT_L1SingleEG5_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_L1SingleEG5_v6"], &b_HLT_L1SingleEG5_v6_Prescl);
   fChain->SetBranchAddress("HLT_L1SingleEG12_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_L1SingleEG12_v6"], &b_HLT_L1SingleEG12_v6_Prescl);
   fChain->SetBranchAddress("HLT_L1DoubleEG3_FwdVeto_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_L1DoubleEG3_FwdVeto_v2"], &b_HLT_L1DoubleEG3_FwdVeto_v2_Prescl);
   fChain->SetBranchAddress("HLT_L1ETM30_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_L1ETM30_v2"], &b_HLT_L1ETM30_v2_Prescl);
   fChain->SetBranchAddress("HLT_L1ETM40_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_L1ETM40_v2"], &b_HLT_L1ETM40_v2_Prescl);
   fChain->SetBranchAddress("HLT_L1ETM70_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_L1ETM70_v2"], &b_HLT_L1ETM70_v2_Prescl);
   fChain->SetBranchAddress("HLT_L1ETM100_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_L1ETM100_v2"], &b_HLT_L1ETM100_v2_Prescl);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdT_TrkIdVL_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele8_CaloIdT_TrkIdVL_v5"], &b_HLT_Ele8_CaloIdT_TrkIdVL_v5_Prescl);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdT_TrkIdVL_EG7_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele8_CaloIdT_TrkIdVL_EG7_v2"], &b_HLT_Ele8_CaloIdT_TrkIdVL_EG7_v2_Prescl);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdT_TrkIdVL_Jet30_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele8_CaloIdT_TrkIdVL_Jet30_v5"], &b_HLT_Ele8_CaloIdT_TrkIdVL_Jet30_v5_Prescl);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdL_CaloIsoVL_v17_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele8_CaloIdL_CaloIsoVL_v17"], &b_HLT_Ele8_CaloIdL_CaloIsoVL_v17_Prescl);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v15_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v15"], &b_HLT_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v15_Prescl);
   fChain->SetBranchAddress("HLT_Ele17_CaloIdL_CaloIsoVL_v17_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele17_CaloIdL_CaloIsoVL_v17"], &b_HLT_Ele17_CaloIdL_CaloIsoVL_v17_Prescl);
   fChain->SetBranchAddress("HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v6"], &b_HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v6_Prescl);
   fChain->SetBranchAddress("HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v18_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v18"], &b_HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v18_Prescl);
   fChain->SetBranchAddress("HLT_Ele17_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_Ele8_Mass50_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele17_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_Ele8_Mass50_v6"], &b_HLT_Ele17_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_Ele8_Mass50_v6_Prescl);
   fChain->SetBranchAddress("HLT_Ele20_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_SC4_Mass50_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele20_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_SC4_Mass50_v6"], &b_HLT_Ele20_CaloIdVT_CaloIsoVT_TrkIdT_TrkIsoVT_SC4_Mass50_v6_Prescl);
   fChain->SetBranchAddress("HLT_Ele22_CaloIdL_CaloIsoVL_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele22_CaloIdL_CaloIsoVL_v6"], &b_HLT_Ele22_CaloIdL_CaloIsoVL_v6_Prescl);
   fChain->SetBranchAddress("HLT_Ele27_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_v11_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele27_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_v11"], &b_HLT_Ele27_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_v11_Prescl);
   fChain->SetBranchAddress("HLT_Ele27_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele15_CaloIdT_CaloIsoVL_trackless_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele27_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele15_CaloIdT_CaloIsoVL_trackless_v7"], &b_HLT_Ele27_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele15_CaloIdT_CaloIsoVL_trackless_v7_Prescl);
   fChain->SetBranchAddress("HLT_Ele27_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_HFT15_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele27_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_HFT15_v7"], &b_HLT_Ele27_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_HFT15_v7_Prescl);
   fChain->SetBranchAddress("HLT_Ele23_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_HFT30_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele23_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_HFT30_v7"], &b_HLT_Ele23_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_HFT30_v7_Prescl);
   fChain->SetBranchAddress("HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet30_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet30_v2"], &b_HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet30_v2_Prescl);
   fChain->SetBranchAddress("HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet50_40_30_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet50_40_30_v2"], &b_HLT_Ele25_CaloIdVT_CaloIsoVL_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet50_40_30_v2_Prescl);
   fChain->SetBranchAddress("HLT_Ele27_WP80_v11_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele27_WP80_v11"], &b_HLT_Ele27_WP80_v11_Prescl);
   fChain->SetBranchAddress("HLT_Ele27_WP80_PFMET_MT50_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele27_WP80_PFMET_MT50_v5"], &b_HLT_Ele27_WP80_PFMET_MT50_v5_Prescl);
   fChain->SetBranchAddress("HLT_Ele30_CaloIdVT_TrkIdT_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele30_CaloIdVT_TrkIdT_v6"], &b_HLT_Ele30_CaloIdVT_TrkIdT_v6_Prescl);
   fChain->SetBranchAddress("HLT_Ele32_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_v11_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele32_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_v11"], &b_HLT_Ele32_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_v11_Prescl);
   fChain->SetBranchAddress("HLT_Ele32_CaloIdT_CaloIsoT_TrkIdT_TrkIsoT_SC17_Mass50_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele32_CaloIdT_CaloIsoT_TrkIdT_TrkIsoT_SC17_Mass50_v6"], &b_HLT_Ele32_CaloIdT_CaloIsoT_TrkIdT_TrkIsoT_SC17_Mass50_v6_Prescl);
   fChain->SetBranchAddress("HLT_Ele80_CaloIdVT_GsfTrkIdT_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele80_CaloIdVT_GsfTrkIdT_v2"], &b_HLT_Ele80_CaloIdVT_GsfTrkIdT_v2_Prescl);
   fChain->SetBranchAddress("HLT_Ele90_CaloIdVT_GsfTrkIdT_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele90_CaloIdVT_GsfTrkIdT_v2"], &b_HLT_Ele90_CaloIdVT_GsfTrkIdT_v2_Prescl);
   fChain->SetBranchAddress("HLT_DoubleEle8_CaloIdT_TrkIdVL_v12_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleEle8_CaloIdT_TrkIdVL_v12"], &b_HLT_DoubleEle8_CaloIdT_TrkIdVL_v12_Prescl);
   fChain->SetBranchAddress("HLT_DoubleEle33_CaloIdL_v14_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleEle33_CaloIdL_v14"], &b_HLT_DoubleEle33_CaloIdL_v14_Prescl);
   fChain->SetBranchAddress("HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v7"], &b_HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v7_Prescl);
   fChain->SetBranchAddress("HLT_DoubleEle33_CaloIdT_v10_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleEle33_CaloIdT_v10"], &b_HLT_DoubleEle33_CaloIdT_v10_Prescl);
   fChain->SetBranchAddress("HLT_Ele15_Ele8_Ele5_CaloIdL_TrkIdVL_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele15_Ele8_Ele5_CaloIdL_TrkIdVL_v6"], &b_HLT_Ele15_Ele8_Ele5_CaloIdL_TrkIdVL_v6_Prescl);
   fChain->SetBranchAddress("HLT_LooseIsoPFTau35_Trk20_Prong1_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_LooseIsoPFTau35_Trk20_Prong1_v7"], &b_HLT_LooseIsoPFTau35_Trk20_Prong1_v7_Prescl);
   fChain->SetBranchAddress("HLT_LooseIsoPFTau35_Trk20_Prong1_MET70_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_LooseIsoPFTau35_Trk20_Prong1_MET70_v7"], &b_HLT_LooseIsoPFTau35_Trk20_Prong1_MET70_v7_Prescl);
   fChain->SetBranchAddress("HLT_LooseIsoPFTau35_Trk20_Prong1_MET75_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_LooseIsoPFTau35_Trk20_Prong1_MET75_v7"], &b_HLT_LooseIsoPFTau35_Trk20_Prong1_MET75_v7_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu15_eta2p1_LooseIsoPFTau35_Trk20_Prong1_L1ETM20_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_IsoMu15_eta2p1_LooseIsoPFTau35_Trk20_Prong1_L1ETM20_v7"], &b_HLT_IsoMu15_eta2p1_LooseIsoPFTau35_Trk20_Prong1_L1ETM20_v7_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMediumIsoPFTau30_Trk1_eta2p1_Jet30_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleMediumIsoPFTau30_Trk1_eta2p1_Jet30_v1"], &b_HLT_DoubleMediumIsoPFTau30_Trk1_eta2p1_Jet30_v1_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMediumIsoPFTau30_Trk1_eta2p1_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleMediumIsoPFTau30_Trk1_eta2p1_v1"], &b_HLT_DoubleMediumIsoPFTau30_Trk1_eta2p1_v1_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Prong1_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Prong1_v1"], &b_HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Prong1_v1_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_v1"], &b_HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_v1_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu18_eta2p1_MediumIsoPFTau25_Trk1_eta2p1_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_IsoMu18_eta2p1_MediumIsoPFTau25_Trk1_eta2p1_v1"], &b_HLT_IsoMu18_eta2p1_MediumIsoPFTau25_Trk1_eta2p1_v1_Prescl);
   fChain->SetBranchAddress("HLT_BTagMu_DiJet20_Mu5_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_BTagMu_DiJet20_Mu5_v4"], &b_HLT_BTagMu_DiJet20_Mu5_v4_Prescl);
   fChain->SetBranchAddress("HLT_BTagMu_DiJet40_Mu5_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_BTagMu_DiJet40_Mu5_v4"], &b_HLT_BTagMu_DiJet40_Mu5_v4_Prescl);
   fChain->SetBranchAddress("HLT_BTagMu_DiJet70_Mu5_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_BTagMu_DiJet70_Mu5_v4"], &b_HLT_BTagMu_DiJet70_Mu5_v4_Prescl);
   fChain->SetBranchAddress("HLT_BTagMu_DiJet110_Mu5_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_BTagMu_DiJet110_Mu5_v4"], &b_HLT_BTagMu_DiJet110_Mu5_v4_Prescl);
   fChain->SetBranchAddress("HLT_BTagMu_Jet300_Mu5_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_BTagMu_Jet300_Mu5_v4"], &b_HLT_BTagMu_Jet300_Mu5_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu7_Ele7_CaloIdT_CaloIsoVL_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu7_Ele7_CaloIdT_CaloIsoVL_v6"], &b_HLT_Mu7_Ele7_CaloIdT_CaloIsoVL_v6_Prescl);
   fChain->SetBranchAddress("HLT_Mu8_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v8_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu8_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v8"], &b_HLT_Mu8_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v8_Prescl);
   fChain->SetBranchAddress("HLT_Mu8_DiJet30_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu8_DiJet30_v5"], &b_HLT_Mu8_DiJet30_v5_Prescl);
   fChain->SetBranchAddress("HLT_Mu8_TriJet30_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu8_TriJet30_v5"], &b_HLT_Mu8_TriJet30_v5_Prescl);
   fChain->SetBranchAddress("HLT_Mu8_QuadJet30_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu8_QuadJet30_v5"], &b_HLT_Mu8_QuadJet30_v5_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu12_DoubleCentralJet65_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_IsoMu12_DoubleCentralJet65_v2"], &b_HLT_IsoMu12_DoubleCentralJet65_v2_Prescl);
   fChain->SetBranchAddress("HLT_Mu15_eta2p1_L1ETM20_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu15_eta2p1_L1ETM20_v4"], &b_HLT_Mu15_eta2p1_L1ETM20_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu24_PFJet30_PFJet25_Deta3_CentralPFJet25_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu24_PFJet30_PFJet25_Deta3_CentralPFJet25_v2"], &b_HLT_Mu24_PFJet30_PFJet25_Deta3_CentralPFJet25_v2_Prescl);
   fChain->SetBranchAddress("HLT_Mu24_CentralPFJet30_CentralPFJet25_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu24_CentralPFJet30_CentralPFJet25_v2"], &b_HLT_Mu24_CentralPFJet30_CentralPFJet25_v2_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu24_PFJet30_PFJet25_Deta3_CentralPFJet25_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_IsoMu24_PFJet30_PFJet25_Deta3_CentralPFJet25_v2"], &b_HLT_IsoMu24_PFJet30_PFJet25_Deta3_CentralPFJet25_v2_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu24_CentralPFJet30_CentralPFJet25_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_IsoMu24_CentralPFJet30_CentralPFJet25_v2"], &b_HLT_IsoMu24_CentralPFJet30_CentralPFJet25_v2_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu24_CentralPFJet30_CentralPFJet25_PFMET20_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_IsoMu24_CentralPFJet30_CentralPFJet25_PFMET20_v2"], &b_HLT_IsoMu24_CentralPFJet30_CentralPFJet25_PFMET20_v2_Prescl);
   fChain->SetBranchAddress("HLT_Ele32_WP80_PFJet30_PFJet25_Deta3_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele32_WP80_PFJet30_PFJet25_Deta3_v2"], &b_HLT_Ele32_WP80_PFJet30_PFJet25_Deta3_v2_Prescl);
   fChain->SetBranchAddress("HLT_Ele32_WP80_PFJet30_PFJet25_Deta3_CentralPFJet30_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele32_WP80_PFJet30_PFJet25_Deta3_CentralPFJet30_v2"], &b_HLT_Ele32_WP80_PFJet30_PFJet25_Deta3_CentralPFJet30_v2_Prescl);
   fChain->SetBranchAddress("HLT_Ele32_WP80_CentralPFJet35_CentralPFJet25_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele32_WP80_CentralPFJet35_CentralPFJet25_v2"], &b_HLT_Ele32_WP80_CentralPFJet35_CentralPFJet25_v2_Prescl);
   fChain->SetBranchAddress("HLT_Ele32_WP80_CentralPFJet35_CentralPFJet25_PFMET20_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele32_WP80_CentralPFJet35_CentralPFJet25_PFMET20_v2"], &b_HLT_Ele32_WP80_CentralPFJet35_CentralPFJet25_PFMET20_v2_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu17_eta2p1_CentralPFNoPUJet30_BTagIPIter_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_IsoMu17_eta2p1_CentralPFNoPUJet30_BTagIPIter_v2"], &b_HLT_IsoMu17_eta2p1_CentralPFNoPUJet30_BTagIPIter_v2_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu17_eta2p1_CentralPFNoPUJet30_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_IsoMu17_eta2p1_CentralPFNoPUJet30_v2"], &b_HLT_IsoMu17_eta2p1_CentralPFNoPUJet30_v2_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_IsoMu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2"], &b_HLT_IsoMu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2_Prescl);
   fChain->SetBranchAddress("HLT_Mu17_eta2p1_CentralPFNoPUJet30_BTagIPIter_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu17_eta2p1_CentralPFNoPUJet30_BTagIPIter_v2"], &b_HLT_Mu17_eta2p1_CentralPFNoPUJet30_BTagIPIter_v2_Prescl);
   fChain->SetBranchAddress("HLT_Mu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2"], &b_HLT_Mu17_eta2p1_TriCentralPFNoPUJet30_30_20_v2_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu20_WCandPt80_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_IsoMu20_WCandPt80_v2"], &b_HLT_IsoMu20_WCandPt80_v2_Prescl);
   fChain->SetBranchAddress("HLT_Mu17_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v8_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu17_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v8"], &b_HLT_Mu17_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v8_Prescl);
   fChain->SetBranchAddress("HLT_Mu12_eta2p1_DiCentral_40_20_DiBTagIP3D1stTrack_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu12_eta2p1_DiCentral_40_20_DiBTagIP3D1stTrack_v4"], &b_HLT_Mu12_eta2p1_DiCentral_40_20_DiBTagIP3D1stTrack_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu12_eta2p1_DiCentral_40_20_BTagIP3D1stTrack_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu12_eta2p1_DiCentral_40_20_BTagIP3D1stTrack_v4"], &b_HLT_Mu12_eta2p1_DiCentral_40_20_BTagIP3D1stTrack_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu12_eta2p1_DiCentral_40_20_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu12_eta2p1_DiCentral_40_20_v4"], &b_HLT_Mu12_eta2p1_DiCentral_40_20_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu12_eta2p1_DiCentral_20_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu12_eta2p1_DiCentral_20_v4"], &b_HLT_Mu12_eta2p1_DiCentral_20_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu15_eta2p1_TriCentral_40_20_20_DiBTagIP3D1stTrack_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu15_eta2p1_TriCentral_40_20_20_DiBTagIP3D1stTrack_v4"], &b_HLT_Mu15_eta2p1_TriCentral_40_20_20_DiBTagIP3D1stTrack_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu15_eta2p1_TriCentral_40_20_20_BTagIP3D1stTrack_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu15_eta2p1_TriCentral_40_20_20_BTagIP3D1stTrack_v4"], &b_HLT_Mu15_eta2p1_TriCentral_40_20_20_BTagIP3D1stTrack_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu15_eta2p1_TriCentral_40_20_20_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu15_eta2p1_TriCentral_40_20_20_v4"], &b_HLT_Mu15_eta2p1_TriCentral_40_20_20_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu30_Ele30_CaloIdL_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu30_Ele30_CaloIdL_v7"], &b_HLT_Mu30_Ele30_CaloIdL_v7_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu17_eta2p1_DiCentralPFNoPUJet30_PFNoPUHT350_PFMHT40_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_IsoMu17_eta2p1_DiCentralPFNoPUJet30_PFNoPUHT350_PFMHT40_v1"], &b_HLT_IsoMu17_eta2p1_DiCentralPFNoPUJet30_PFNoPUHT350_PFMHT40_v1_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu20_eta2p1_CentralPFJet80_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_IsoMu20_eta2p1_CentralPFJet80_v7"], &b_HLT_IsoMu20_eta2p1_CentralPFJet80_v7_Prescl);
   fChain->SetBranchAddress("HLT_DoubleRelIso1p0Mu5_Mass8_PFNoPUHT175_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleRelIso1p0Mu5_Mass8_PFNoPUHT175_v1"], &b_HLT_DoubleRelIso1p0Mu5_Mass8_PFNoPUHT175_v1_Prescl);
   fChain->SetBranchAddress("HLT_DoubleRelIso1p0Mu5_Mass8_PFNoPUHT225_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleRelIso1p0Mu5_Mass8_PFNoPUHT225_v1"], &b_HLT_DoubleRelIso1p0Mu5_Mass8_PFNoPUHT225_v1_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMu8_Mass8_PFNoPUHT175_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleMu8_Mass8_PFNoPUHT175_v1"], &b_HLT_DoubleMu8_Mass8_PFNoPUHT175_v1_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMu8_Mass8_PFNoPUHT225_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleMu8_Mass8_PFNoPUHT225_v1"], &b_HLT_DoubleMu8_Mass8_PFNoPUHT225_v1_Prescl);
   fChain->SetBranchAddress("HLT_RelIso1p0Mu5_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_RelIso1p0Mu5_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1"], &b_HLT_RelIso1p0Mu5_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1_Prescl);
   fChain->SetBranchAddress("HLT_RelIso1p0Mu5_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_RelIso1p0Mu5_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1"], &b_HLT_RelIso1p0Mu5_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1_Prescl);
   fChain->SetBranchAddress("HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1"], &b_HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1_Prescl);
   fChain->SetBranchAddress("HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1"], &b_HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1_Prescl);
   fChain->SetBranchAddress("HLT_PFNoPUHT350_Mu15_PFMET45_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_PFNoPUHT350_Mu15_PFMET45_v1"], &b_HLT_PFNoPUHT350_Mu15_PFMET45_v1_Prescl);
   fChain->SetBranchAddress("HLT_PFNoPUHT350_Mu15_PFMET50_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_PFNoPUHT350_Mu15_PFMET50_v1"], &b_HLT_PFNoPUHT350_Mu15_PFMET50_v1_Prescl);
   fChain->SetBranchAddress("HLT_PFNoPUHT400_Mu5_PFMET45_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_PFNoPUHT400_Mu5_PFMET45_v1"], &b_HLT_PFNoPUHT400_Mu5_PFMET45_v1_Prescl);
   fChain->SetBranchAddress("HLT_PFNoPUHT400_Mu5_PFMET50_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_PFNoPUHT400_Mu5_PFMET50_v1"], &b_HLT_PFNoPUHT400_Mu5_PFMET50_v1_Prescl);
   fChain->SetBranchAddress("HLT_Mu40_PFNoPUHT350_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu40_PFNoPUHT350_v1"], &b_HLT_Mu40_PFNoPUHT350_v1_Prescl);
   fChain->SetBranchAddress("HLT_Mu60_PFNoPUHT350_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu60_PFNoPUHT350_v1"], &b_HLT_Mu60_PFNoPUHT350_v1_Prescl);
   fChain->SetBranchAddress("HLT_Mu40_HT200_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu40_HT200_v2"], &b_HLT_Mu40_HT200_v2_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMu5_Ele8_CaloIdT_TrkIdVL_v15_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleMu5_Ele8_CaloIdT_TrkIdVL_v15"], &b_HLT_DoubleMu5_Ele8_CaloIdT_TrkIdVL_v15_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMu8_Ele8_CaloIdT_TrkIdVL_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleMu8_Ele8_CaloIdT_TrkIdVL_v4"], &b_HLT_DoubleMu8_Ele8_CaloIdT_TrkIdVL_v4_Prescl);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Jet30_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Jet30_v6"], &b_HLT_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Jet30_v6_Prescl);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdT_TrkIdT_DiJet30_v16_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele8_CaloIdT_TrkIdT_DiJet30_v16"], &b_HLT_Ele8_CaloIdT_TrkIdT_DiJet30_v16_Prescl);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdT_TrkIdT_TriJet30_v16_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele8_CaloIdT_TrkIdT_TriJet30_v16"], &b_HLT_Ele8_CaloIdT_TrkIdT_TriJet30_v16_Prescl);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdT_TrkIdT_QuadJet30_v16_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele8_CaloIdT_TrkIdT_QuadJet30_v16"], &b_HLT_Ele8_CaloIdT_TrkIdT_QuadJet30_v16_Prescl);
   fChain->SetBranchAddress("HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Jet30_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Jet30_v6"], &b_HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Jet30_v6_Prescl);
   fChain->SetBranchAddress("HLT_Ele25_CaloIdVT_TrkIdT_TriCentralPFNoPUJet30_30_20_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele25_CaloIdVT_TrkIdT_TriCentralPFNoPUJet30_30_20_v2"], &b_HLT_Ele25_CaloIdVT_TrkIdT_TriCentralPFNoPUJet30_30_20_v2_Prescl);
   fChain->SetBranchAddress("HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_CentralPFNoPUJet30_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_CentralPFNoPUJet30_v6"], &b_HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_CentralPFNoPUJet30_v6_Prescl);
   fChain->SetBranchAddress("HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2"], &b_HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2_Prescl);
   fChain->SetBranchAddress("HLT_Ele25_CaloIdVL_CaloIsoT_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele25_CaloIdVL_CaloIsoT_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2"], &b_HLT_Ele25_CaloIdVL_CaloIsoT_TrkIdVL_TrkIsoT_TriCentralPFNoPUJet30_30_20_v2_Prescl);
   fChain->SetBranchAddress("HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_CentralPFNoPUJet30_BTagIPIter_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_CentralPFNoPUJet30_BTagIPIter_v7"], &b_HLT_Ele25_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_CentralPFNoPUJet30_BTagIPIter_v7_Prescl);
   fChain->SetBranchAddress("HLT_Ele27_WP80_CentralPFJet80_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele27_WP80_CentralPFJet80_v7"], &b_HLT_Ele27_WP80_CentralPFJet80_v7_Prescl);
   fChain->SetBranchAddress("HLT_Ele27_WP80_WCandPt80_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele27_WP80_WCandPt80_v7"], &b_HLT_Ele27_WP80_WCandPt80_v7_Prescl);
   fChain->SetBranchAddress("HLT_Ele30_CaloIdVT_TrkIdT_PFNoPUJet100_PFNoPUJet25_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele30_CaloIdVT_TrkIdT_PFNoPUJet100_PFNoPUJet25_v6"], &b_HLT_Ele30_CaloIdVT_TrkIdT_PFNoPUJet100_PFNoPUJet25_v6_Prescl);
   fChain->SetBranchAddress("HLT_Ele30_CaloIdVT_TrkIdT_PFNoPUJet150_PFNoPUJet25_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele30_CaloIdVT_TrkIdT_PFNoPUJet150_PFNoPUJet25_v6"], &b_HLT_Ele30_CaloIdVT_TrkIdT_PFNoPUJet150_PFNoPUJet25_v6_Prescl);
   fChain->SetBranchAddress("HLT_DoubleEle8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleEle8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1"], &b_HLT_DoubleEle8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT175_v1_Prescl);
   fChain->SetBranchAddress("HLT_DoubleEle8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleEle8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1"], &b_HLT_DoubleEle8_CaloIdT_TrkIdVL_Mass8_PFNoPUHT225_v1_Prescl);
   fChain->SetBranchAddress("HLT_DoubleEle10_CaloIdL_TrkIdVL_Ele10_CaloIdT_TrkIdVL_v12_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleEle10_CaloIdL_TrkIdVL_Ele10_CaloIdT_TrkIdVL_v12"], &b_HLT_DoubleEle10_CaloIdL_TrkIdVL_Ele10_CaloIdT_TrkIdVL_v12_Prescl);
   fChain->SetBranchAddress("HLT_TripleEle10_CaloIdL_TrkIdVL_v18_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_TripleEle10_CaloIdL_TrkIdVL_v18"], &b_HLT_TripleEle10_CaloIdL_TrkIdVL_v18_Prescl);
   fChain->SetBranchAddress("HLT_RsqMR40_Rsq0p04_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_RsqMR40_Rsq0p04_v4"], &b_HLT_RsqMR40_Rsq0p04_v4_Prescl);
   fChain->SetBranchAddress("HLT_RsqMR45_Rsq0p09_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_RsqMR45_Rsq0p09_v3"], &b_HLT_RsqMR45_Rsq0p09_v3_Prescl);
   fChain->SetBranchAddress("HLT_RsqMR55_Rsq0p09_MR150_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_RsqMR55_Rsq0p09_MR150_v4"], &b_HLT_RsqMR55_Rsq0p09_MR150_v4_Prescl);
   fChain->SetBranchAddress("HLT_RsqMR60_Rsq0p09_MR150_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_RsqMR60_Rsq0p09_MR150_v4"], &b_HLT_RsqMR60_Rsq0p09_MR150_v4_Prescl);
   fChain->SetBranchAddress("HLT_RsqMR65_Rsq0p09_MR150_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_RsqMR65_Rsq0p09_MR150_v3"], &b_HLT_RsqMR65_Rsq0p09_MR150_v3_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu12_RsqMR30_Rsq0p04_MR200_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_IsoMu12_RsqMR30_Rsq0p04_MR200_v2"], &b_HLT_IsoMu12_RsqMR30_Rsq0p04_MR200_v2_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu12_RsqMR40_Rsq0p04_MR200_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_IsoMu12_RsqMR40_Rsq0p04_MR200_v2"], &b_HLT_IsoMu12_RsqMR40_Rsq0p04_MR200_v2_Prescl);
   fChain->SetBranchAddress("HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_RsqMR30_Rsq0p04_MR200_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_RsqMR30_Rsq0p04_MR200_v2"], &b_HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_RsqMR30_Rsq0p04_MR200_v2_Prescl);
   fChain->SetBranchAddress("HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_RsqMR40_Rsq0p04_MR200_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_RsqMR40_Rsq0p04_MR200_v2"], &b_HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_RsqMR40_Rsq0p04_MR200_v2_Prescl);
   fChain->SetBranchAddress("HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_DoubleCentralJet65_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_DoubleCentralJet65_v2"], &b_HLT_Ele12_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_DoubleCentralJet65_v2_Prescl);
   fChain->SetBranchAddress("HLT_Photon40_CaloIdL_RsqMR35_Rsq0p09_MR150_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon40_CaloIdL_RsqMR35_Rsq0p09_MR150_v4"], &b_HLT_Photon40_CaloIdL_RsqMR35_Rsq0p09_MR150_v4_Prescl);
   fChain->SetBranchAddress("HLT_Photon40_CaloIdL_RsqMR40_Rsq0p09_MR150_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon40_CaloIdL_RsqMR40_Rsq0p09_MR150_v4"], &b_HLT_Photon40_CaloIdL_RsqMR40_Rsq0p09_MR150_v4_Prescl);
   fChain->SetBranchAddress("HLT_Photon40_CaloIdL_RsqMR45_Rsq0p09_MR150_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon40_CaloIdL_RsqMR45_Rsq0p09_MR150_v4"], &b_HLT_Photon40_CaloIdL_RsqMR45_Rsq0p09_MR150_v4_Prescl);
   fChain->SetBranchAddress("HLT_Photon40_CaloIdL_RsqMR50_Rsq0p09_MR150_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Photon40_CaloIdL_RsqMR50_Rsq0p09_MR150_v4"], &b_HLT_Photon40_CaloIdL_RsqMR50_Rsq0p09_MR150_v4_Prescl);
   fChain->SetBranchAddress("HLT_DoublePhoton40_CaloIdL_Rsq0p035_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoublePhoton40_CaloIdL_Rsq0p035_v4"], &b_HLT_DoublePhoton40_CaloIdL_Rsq0p035_v4_Prescl);
   fChain->SetBranchAddress("HLT_DoublePhoton40_CaloIdL_Rsq0p06_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoublePhoton40_CaloIdL_Rsq0p06_v4"], &b_HLT_DoublePhoton40_CaloIdL_Rsq0p06_v4_Prescl);
   fChain->SetBranchAddress("HLT_Mu22_Photon22_CaloIdL_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu22_Photon22_CaloIdL_v6"], &b_HLT_Mu22_Photon22_CaloIdL_v6_Prescl);
   fChain->SetBranchAddress("HLT_Mu8_DoubleEle8_CaloIdT_TrkIdVL_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu8_DoubleEle8_CaloIdT_TrkIdVL_v6"], &b_HLT_Mu8_DoubleEle8_CaloIdT_TrkIdVL_v6_Prescl);
   fChain->SetBranchAddress("HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Ele8_CaloIdL_TrkIdVL_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Ele8_CaloIdL_TrkIdVL_v6"], &b_HLT_Mu8_Ele8_CaloIdT_TrkIdVL_Ele8_CaloIdL_TrkIdVL_v6_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMu14_Mass8_PFMET40_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleMu14_Mass8_PFMET40_v6"], &b_HLT_DoubleMu14_Mass8_PFMET40_v6_Prescl);
   fChain->SetBranchAddress("HLT_DoubleMu14_Mass8_PFMET50_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleMu14_Mass8_PFMET50_v6"], &b_HLT_DoubleMu14_Mass8_PFMET50_v6_Prescl);
   fChain->SetBranchAddress("HLT_DoubleEle14_CaloIdT_TrkIdVL_Mass8_PFMET40_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleEle14_CaloIdT_TrkIdVL_Mass8_PFMET40_v6"], &b_HLT_DoubleEle14_CaloIdT_TrkIdVL_Mass8_PFMET40_v6_Prescl);
   fChain->SetBranchAddress("HLT_DoubleEle14_CaloIdT_TrkIdVL_Mass8_PFMET50_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DoubleEle14_CaloIdT_TrkIdVL_Mass8_PFMET50_v6"], &b_HLT_DoubleEle14_CaloIdT_TrkIdVL_Mass8_PFMET50_v6_Prescl);
   fChain->SetBranchAddress("HLT_Mu14_Ele14_CaloIdT_TrkIdVL_Mass8_PFMET40_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu14_Ele14_CaloIdT_TrkIdVL_Mass8_PFMET40_v6"], &b_HLT_Mu14_Ele14_CaloIdT_TrkIdVL_Mass8_PFMET40_v6_Prescl);
   fChain->SetBranchAddress("HLT_Mu14_Ele14_CaloIdT_TrkIdVL_Mass8_PFMET50_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu14_Ele14_CaloIdT_TrkIdVL_Mass8_PFMET50_v6"], &b_HLT_Mu14_Ele14_CaloIdT_TrkIdVL_Mass8_PFMET50_v6_Prescl);
   fChain->SetBranchAddress("HLT_PFNoPUHT350_PFMET100_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_PFNoPUHT350_PFMET100_v1"], &b_HLT_PFNoPUHT350_PFMET100_v1_Prescl);
   fChain->SetBranchAddress("HLT_PFNoPUHT400_PFMET100_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_PFNoPUHT400_PFMET100_v1"], &b_HLT_PFNoPUHT400_PFMET100_v1_Prescl);
   fChain->SetBranchAddress("HLT_CleanPFNoPUHT350_Ele5_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET45_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_CleanPFNoPUHT350_Ele5_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET45_v1"], &b_HLT_CleanPFNoPUHT350_Ele5_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET45_v1_Prescl);
   fChain->SetBranchAddress("HLT_CleanPFNoPUHT350_Ele5_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET50_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_CleanPFNoPUHT350_Ele5_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET50_v1"], &b_HLT_CleanPFNoPUHT350_Ele5_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET50_v1_Prescl);
   fChain->SetBranchAddress("HLT_CleanPFNoPUHT300_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET45_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_CleanPFNoPUHT300_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET45_v1"], &b_HLT_CleanPFNoPUHT300_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET45_v1_Prescl);
   fChain->SetBranchAddress("HLT_CleanPFNoPUHT300_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET50_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_CleanPFNoPUHT300_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET50_v1"], &b_HLT_CleanPFNoPUHT300_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_PFMET50_v1_Prescl);
   fChain->SetBranchAddress("HLT_CleanPFNoPUHT300_Ele40_CaloIdVT_TrkIdT_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_CleanPFNoPUHT300_Ele40_CaloIdVT_TrkIdT_v1"], &b_HLT_CleanPFNoPUHT300_Ele40_CaloIdVT_TrkIdT_v1_Prescl);
   fChain->SetBranchAddress("HLT_CleanPFNoPUHT300_Ele60_CaloIdVT_TrkIdT_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_CleanPFNoPUHT300_Ele60_CaloIdVT_TrkIdT_v1"], &b_HLT_CleanPFNoPUHT300_Ele60_CaloIdVT_TrkIdT_v1_Prescl);
   fChain->SetBranchAddress("HLT_Ele5_SC5_Jpsi_Mass2to15_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele5_SC5_Jpsi_Mass2to15_v4"], &b_HLT_Ele5_SC5_Jpsi_Mass2to15_v4_Prescl);
   fChain->SetBranchAddress("HLT_DiJet35_MJJ650_AllJets_DEta3p5_VBF_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DiJet35_MJJ650_AllJets_DEta3p5_VBF_v2"], &b_HLT_DiJet35_MJJ650_AllJets_DEta3p5_VBF_v2_Prescl);
   fChain->SetBranchAddress("HLT_DiJet35_MJJ700_AllJets_DEta3p5_VBF_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DiJet35_MJJ700_AllJets_DEta3p5_VBF_v2"], &b_HLT_DiJet35_MJJ700_AllJets_DEta3p5_VBF_v2_Prescl);
   fChain->SetBranchAddress("HLT_DiJet35_MJJ750_AllJets_DEta3p5_VBF_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DiJet35_MJJ750_AllJets_DEta3p5_VBF_v2"], &b_HLT_DiJet35_MJJ750_AllJets_DEta3p5_VBF_v2_Prescl);
   fChain->SetBranchAddress("HLT_Ele22_eta2p1_WP90Rho_LooseIsoPFTau20_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele22_eta2p1_WP90Rho_LooseIsoPFTau20_v3"], &b_HLT_Ele22_eta2p1_WP90Rho_LooseIsoPFTau20_v3_Prescl);
   fChain->SetBranchAddress("HLT_Ele22_eta2p1_WP90NoIso_LooseIsoPFTau20_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Ele22_eta2p1_WP90NoIso_LooseIsoPFTau20_v3"], &b_HLT_Ele22_eta2p1_WP90NoIso_LooseIsoPFTau20_v3_Prescl);
   fChain->SetBranchAddress("HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v3"], &b_HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v3_Prescl);
   fChain->SetBranchAddress("HLT_Mu17_eta2p1_LooseIsoPFTau20_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Mu17_eta2p1_LooseIsoPFTau20_v3"], &b_HLT_Mu17_eta2p1_LooseIsoPFTau20_v3_Prescl);
   fChain->SetBranchAddress("HLT_PixelTracks_Multiplicity70_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_PixelTracks_Multiplicity70_v3"], &b_HLT_PixelTracks_Multiplicity70_v3_Prescl);
   fChain->SetBranchAddress("HLT_PixelTracks_Multiplicity80_v12_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_PixelTracks_Multiplicity80_v12"], &b_HLT_PixelTracks_Multiplicity80_v12_Prescl);
   fChain->SetBranchAddress("HLT_PixelTracks_Multiplicity90_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_PixelTracks_Multiplicity90_v3"], &b_HLT_PixelTracks_Multiplicity90_v3_Prescl);
   fChain->SetBranchAddress("HLT_BeamGas_HF_Beam1_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_BeamGas_HF_Beam1_v5"], &b_HLT_BeamGas_HF_Beam1_v5_Prescl);
   fChain->SetBranchAddress("HLT_BeamGas_HF_Beam2_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_BeamGas_HF_Beam2_v5"], &b_HLT_BeamGas_HF_Beam2_v5_Prescl);
   fChain->SetBranchAddress("HLT_BeamHalo_v13_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_BeamHalo_v13"], &b_HLT_BeamHalo_v13_Prescl);
   fChain->SetBranchAddress("HLT_IsoTrackHE_v15_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_IsoTrackHE_v15"], &b_HLT_IsoTrackHE_v15_Prescl);
   fChain->SetBranchAddress("HLT_IsoTrackHB_v14_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_IsoTrackHB_v14"], &b_HLT_IsoTrackHB_v14_Prescl);
   fChain->SetBranchAddress("HLT_HcalPhiSym_v11_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_HcalPhiSym_v11"], &b_HLT_HcalPhiSym_v11_Prescl);
   fChain->SetBranchAddress("HLT_HcalNZS_v10_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_HcalNZS_v10"], &b_HLT_HcalNZS_v10_Prescl);
   fChain->SetBranchAddress("HLT_GlobalRunHPDNoise_v8_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_GlobalRunHPDNoise_v8"], &b_HLT_GlobalRunHPDNoise_v8_Prescl);
   fChain->SetBranchAddress("HLT_L1Tech_HBHEHO_totalOR_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_L1Tech_HBHEHO_totalOR_v6"], &b_HLT_L1Tech_HBHEHO_totalOR_v6_Prescl);
   fChain->SetBranchAddress("HLT_L1Tech_HCAL_HF_single_channel_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_L1Tech_HCAL_HF_single_channel_v4"], &b_HLT_L1Tech_HCAL_HF_single_channel_v4_Prescl);
   fChain->SetBranchAddress("HLT_ZeroBias_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_ZeroBias_v7"], &b_HLT_ZeroBias_v7_Prescl);
   fChain->SetBranchAddress("HLT_ZeroBiasPixel_DoubleTrack_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_ZeroBiasPixel_DoubleTrack_v2"], &b_HLT_ZeroBiasPixel_DoubleTrack_v2_Prescl);
   fChain->SetBranchAddress("HLT_Physics_v5_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Physics_v5"], &b_HLT_Physics_v5_Prescl);
   fChain->SetBranchAddress("HLT_DTCalibration_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DTCalibration_v2"], &b_HLT_DTCalibration_v2_Prescl);
   fChain->SetBranchAddress("HLT_EcalCalibration_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_EcalCalibration_v3"], &b_HLT_EcalCalibration_v3_Prescl);
   fChain->SetBranchAddress("HLT_HcalCalibration_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_HcalCalibration_v3"], &b_HLT_HcalCalibration_v3_Prescl);
   fChain->SetBranchAddress("HLT_TrackerCalibration_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_TrackerCalibration_v3"], &b_HLT_TrackerCalibration_v3_Prescl);
   fChain->SetBranchAddress("HLT_Random_v2_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Random_v2"], &b_HLT_Random_v2_Prescl);
   fChain->SetBranchAddress("HLT_L1SingleMuOpen_AntiBPTX_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_L1SingleMuOpen_AntiBPTX_v7"], &b_HLT_L1SingleMuOpen_AntiBPTX_v7_Prescl);
   fChain->SetBranchAddress("HLT_L1TrackerCosmics_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_L1TrackerCosmics_v7"], &b_HLT_L1TrackerCosmics_v7_Prescl);
   fChain->SetBranchAddress("HLT_LogMonitor_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_LogMonitor_v3"], &b_HLT_LogMonitor_v3_Prescl);
   fChain->SetBranchAddress("HLT_DTErrors_v3_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_DTErrors_v3"], &b_HLT_DTErrors_v3_Prescl);
   fChain->SetBranchAddress("HLT_L1DoubleJet36Central_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_L1DoubleJet36Central_v7"], &b_HLT_L1DoubleJet36Central_v7_Prescl);
   fChain->SetBranchAddress("AlCa_EcalPi0EBonly_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["AlCa_EcalPi0EBonly_v6"], &b_AlCa_EcalPi0EBonly_v6_Prescl);
   fChain->SetBranchAddress("AlCa_EcalPi0EEonly_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["AlCa_EcalPi0EEonly_v6"], &b_AlCa_EcalPi0EEonly_v6_Prescl);
   fChain->SetBranchAddress("AlCa_EcalEtaEBonly_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["AlCa_EcalEtaEBonly_v6"], &b_AlCa_EcalEtaEBonly_v6_Prescl);
   fChain->SetBranchAddress("AlCa_EcalEtaEEonly_v6_Prescl", &map_RefPrescaleOfStandardHLTPath["AlCa_EcalEtaEEonly_v6"], &b_AlCa_EcalEtaEEonly_v6_Prescl);
   fChain->SetBranchAddress("AlCa_EcalPhiSym_v13_Prescl", &map_RefPrescaleOfStandardHLTPath["AlCa_EcalPhiSym_v13"], &b_AlCa_EcalPhiSym_v13_Prescl);
   fChain->SetBranchAddress("AlCa_RPCMuonNoTriggers_v9_Prescl", &map_RefPrescaleOfStandardHLTPath["AlCa_RPCMuonNoTriggers_v9"], &b_AlCa_RPCMuonNoTriggers_v9_Prescl);
   fChain->SetBranchAddress("AlCa_RPCMuonNoHits_v9_Prescl", &map_RefPrescaleOfStandardHLTPath["AlCa_RPCMuonNoHits_v9"], &b_AlCa_RPCMuonNoHits_v9_Prescl);
   fChain->SetBranchAddress("AlCa_RPCMuonNormalisation_v9_Prescl", &map_RefPrescaleOfStandardHLTPath["AlCa_RPCMuonNormalisation_v9"], &b_AlCa_RPCMuonNormalisation_v9_Prescl);
   fChain->SetBranchAddress("AlCa_LumiPixels_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["AlCa_LumiPixels_v7"], &b_AlCa_LumiPixels_v7_Prescl);
   fChain->SetBranchAddress("AlCa_LumiPixels_ZeroBias_v4_Prescl", &map_RefPrescaleOfStandardHLTPath["AlCa_LumiPixels_ZeroBias_v4"], &b_AlCa_LumiPixels_ZeroBias_v4_Prescl);
   fChain->SetBranchAddress("AlCa_LumiPixels_Random_v1_Prescl", &map_RefPrescaleOfStandardHLTPath["AlCa_LumiPixels_Random_v1"], &b_AlCa_LumiPixels_Random_v1_Prescl);
   fChain->SetBranchAddress("HLT_Activity_Ecal_SC7_v13_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_Activity_Ecal_SC7_v13"], &b_HLT_Activity_Ecal_SC7_v13_Prescl);
   fChain->SetBranchAddress("HLT_L1SingleJet16_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_L1SingleJet16_v7"], &b_HLT_L1SingleJet16_v7_Prescl);
   fChain->SetBranchAddress("HLT_L1SingleJet36_v7_Prescl", &map_RefPrescaleOfStandardHLTPath["HLT_L1SingleJet36_v7"], &b_HLT_L1SingleJet36_v7_Prescl);



   Notify();
}

void OHltTree::SetMapL1SeedsOfStandardHLTPath(OHltMenu *menu)
{
   map_L1SeedsOfStandardHLTPath = menu->GetL1SeedsOfHLTPathMap();
}

void OHltTree::ApplyL1Prescales(OHltMenu *menu, OHltConfig *cfg, OHltRateCounter *rc)
{
   TString st;
   unsigned int tt = menu->GetL1TriggerSize();
   for (unsigned int i=0;i<tt;i++)
   {
      st = menu->GetL1TriggerName(i);
      if (map_BitOfStandardHLTPath.find(st)->second == 1)
      {
         if (!prescaleResponseL1(menu,cfg,rc,i))
         {
            map_BitOfStandardHLTPath[st] = 0;
         }
      }
   }
}

void OHltTree::SetMapL1BitOfStandardHLTPath(OHltMenu *menu)
{
   int tt = 0;
   TString st;
   unsigned ts = menu->GetTriggerSize();
   for (unsigned int i=0;i<ts;i++)
   {
      st = menu->GetTriggerName(i);
      std::map< TString, std::vector<TString> >::const_iterator it = map_L1SeedsOfStandardHLTPath.find(st);
      if (it != map_L1SeedsOfStandardHLTPath.end())
      {
         tt = 0;
         unsigned ts2 = it->second.size();
         for (unsigned int j=0;j<ts2;j++)
         {
            tt += (map_BitOfStandardHLTPath.find((map_L1SeedsOfStandardHLTPath.find(st)->second)[j]))->second;
         }
      }
      map_L1BitOfStandardHLTPath[st] = tt;
   }
}

void OHltTree::RemoveEGOverlaps()
{
   //remove duplicated SC
   for(int i=0;i<NohEle;i++)
   {
      if (ohEleL1iso[i] == 1)
      {  ohEleL1Dupl[i]=false;}
      else
      {
         float dist = 1000;
         for(int j=0;j<NohEle;j++)
         {
            if(ohEleL1iso[j]==1)
            {
               float distTemp = fabs(ohEleEta[i]-ohEleEta[j])+fabs(ohEleE[i]-ohEleE[j]);
               if(distTemp < dist)
               {  dist=distTemp;}
            }
         }//loop over j
         if (dist < 0.01)
         {  ohEleL1Dupl[i]=true;}
         else
         {  ohEleL1Dupl[i]=false;}
      }
   }

   for(int i=0;i<NohPhot;i++)
   {
      if (ohPhotL1iso[i] == 1)
      {  ohPhotL1Dupl[i]=false;}
      else
      {
         float dist = 1000;
         for(int j=0;j<NohPhot;j++)
         {
            if(ohPhotL1iso[j]==1)
            {
               float distTemp = fabs(ohPhotEta[i]-ohPhotEta[j])+fabs(ohPhotEt[i]-ohPhotEt[j]);
               if(distTemp < dist)
               {  dist=distTemp;}
            }
         }//loop over j 
         if (dist < 0.01)
         {  ohPhotL1Dupl[i]=true;}
         else
         {  ohPhotL1Dupl[i]=false;}
      }
   }

 for(int i=0;i<NohEcalActiv;i++)
   {
      if (ohEcalActivL1iso[i] == 1)
      {  ohEcalActivL1Dupl[i]=false;}
      else
      {
         float dist = 1000;
         for(int j=0;j<NohEcalActiv;j++)
         {
            if(ohEcalActivL1iso[j]==1)
            {
               float distTemp = fabs(ohEcalActivEta[i]-ohEcalActivEta[j])+fabs(ohEcalActivEt[i]-ohEcalActivEt[j]);
               if(distTemp < dist)
               {  dist=distTemp;}
            }
         }//loop over j 
         if (dist < 0.01)
         {  ohEcalActivL1Dupl[i]=true;}
         else
         {  ohEcalActivL1Dupl[i]=false;}
      }
   }

}


void OHltTree::SetL1MuonQuality()
{
   // Cut on muon quality
   // init
   NL1OpenMu = 0;
   for (int i=0;i<10;i++)
   {
      L1OpenMuPt[i] = -999.;
      L1OpenMuE[i] = -999.;
      L1OpenMuEta[i] = -999.;
      L1OpenMuPhi[i] = -999.;
      L1OpenMuIsol[i] = -999;
      L1OpenMuMip[i] = -999;
      L1OpenMuFor[i] = -999;
      L1OpenMuRPC[i] = -999;
      L1OpenMuQal[i] = -999;
   }
   for (int i=0;i<NL1Mu;i++)
   {
      if ( L1MuQal[i]==2 || L1MuQal[i]==3 || L1MuQal[i]==4 ||
            L1MuQal[i]==5 || L1MuQal[i]==6 || L1MuQal[i]==7 )
      {
         L1OpenMuPt[NL1OpenMu] = L1MuPt[i];
         L1OpenMuE[NL1OpenMu] = L1MuE[i];
         L1OpenMuEta[NL1OpenMu] = L1MuEta[i];
         L1OpenMuPhi[NL1OpenMu] = L1MuPhi[i];
         L1OpenMuIsol[NL1OpenMu] = L1MuIsol[i];
         L1OpenMuMip[NL1OpenMu] = L1MuMip[i];
         L1OpenMuFor[NL1OpenMu] = L1MuFor[i];
         L1OpenMuRPC[NL1OpenMu] = L1MuRPC[i];
         L1OpenMuQal[NL1OpenMu] = L1MuQal[i];
         NL1OpenMu++;
      }
   }
   // init
   NL1GoodSingleMu = 0;
   for (int i=0;i<10;i++)
   {
      L1GoodSingleMuPt[i] = -999.;
      L1GoodSingleMuE[i] = -999.;
      L1GoodSingleMuEta[i] = -999.;
      L1GoodSingleMuPhi[i] = -999.;
      L1GoodSingleMuIsol[i] = -999;
      L1GoodSingleMuMip[i] = -999;
      L1GoodSingleMuFor[i] = -999;
      L1GoodSingleMuRPC[i] = -999;
      L1GoodSingleMuQal[i] = -999;
   }
   // Cut on muon quality      
   for (int i=0;i<NL1Mu;i++)
   {
      if ( L1MuQal[i]==4 || L1MuQal[i]==5 || L1MuQal[i]==6 || L1MuQal[i]==7 )
      {
         L1GoodSingleMuPt[NL1GoodSingleMu] = L1MuPt[i];
         L1GoodSingleMuE[NL1GoodSingleMu] = L1MuE[i];
         L1GoodSingleMuEta[NL1GoodSingleMu] = L1MuEta[i];
         L1GoodSingleMuPhi[NL1GoodSingleMu] = L1MuPhi[i];
         L1GoodSingleMuIsol[NL1GoodSingleMu] = L1MuIsol[i];
         L1GoodSingleMuMip[NL1GoodSingleMu] = L1MuMip[i];
         L1GoodSingleMuFor[NL1GoodSingleMu] = L1MuFor[i];
         L1GoodSingleMuRPC[NL1GoodSingleMu] = L1MuRPC[i];
         L1GoodSingleMuQal[NL1GoodSingleMu] = L1MuQal[i];
         NL1GoodSingleMu++;
      }
   }

   // init
   NL1GoodDoubleMu = 0;
   for (int i=0;i<10;i++)
   {
      L1GoodDoubleMuPt[i] = -999.;
      L1GoodDoubleMuE[i] = -999.;
      L1GoodDoubleMuEta[i] = -999.;
      L1GoodDoubleMuPhi[i] = -999.;
      L1GoodDoubleMuIsol[i] = -999;
      L1GoodDoubleMuMip[i] = -999;
      L1GoodDoubleMuFor[i] = -999;
      L1GoodDoubleMuRPC[i] = -999;
      L1GoodDoubleMuQal[i] = -999;
   }
   // Cut on muon quality
   for (int i=0;i<NL1Mu;i++)
   {
      if ( L1MuQal[i]==3 || L1MuQal[i]==5 || L1MuQal[i]==6 || L1MuQal[i]==7 )
      {
         L1GoodDoubleMuPt[NL1GoodDoubleMu] = L1MuPt[i];
         L1GoodDoubleMuE[NL1GoodDoubleMu] = L1MuE[i];
         L1GoodDoubleMuEta[NL1GoodDoubleMu] = L1MuEta[i];
         L1GoodDoubleMuPhi[NL1GoodDoubleMu] = L1MuPhi[i];
         L1GoodDoubleMuIsol[NL1GoodDoubleMu] = L1MuIsol[i];
         L1GoodDoubleMuMip[NL1GoodDoubleMu] = L1MuMip[i];
         L1GoodDoubleMuFor[NL1GoodDoubleMu] = L1MuFor[i];
         L1GoodDoubleMuRPC[NL1GoodDoubleMu] = L1MuRPC[i];
         L1GoodDoubleMuQal[NL1GoodDoubleMu] = L1MuQal[i];
         NL1GoodDoubleMu++;
      }
   }
}

void OHltTree::SetOpenL1Bits()
{
   OpenL1_ZeroBias = 1;
   OpenL1_Mu3EG5 = 0;
   OpenL1_EG5_HTT100 = 0;
   OpenL1_SingleMu30 = 0;
   OpenL1_DoubleEG8 = 0;
   OpenL1_DoubleEG10 = 0;
   OpenL1_DoubleMu0 = 0;
   OpenL1_DoubleMu5 = 0;
   OpenL1_SingleJet20_FwdVeto = 0;
   OpenL1_DoubleEG2_FwdVeto = 0;
   OpenL1_ETT220 = 0;
   OpenL1_SingleMu5_Eta1pt5_Qal7 = 0;
   OpenL1_QuadJet8U = 0;
   OpenL1_SingleMu14_Eta2p1 = 0;
   OpenL1_SingleMu16_Eta2p1 = 0;
   OpenL1_EG18_ForJet16 = 0;

   if(L1GoodSingleMuPt[0]> 3.0 && (L1NIsolEmEt[0]> 5.0 || L1IsolEmEt[0]> 5.0))
   OpenL1_Mu3EG5 = 1;

   if((map_BitOfStandardHLTPath.find("L1_SingleEG5")->second == 1) &&
         (map_BitOfStandardHLTPath.find("L1_HTT100")->second == 1))
   OpenL1_EG5_HTT100 = 1;

   if(L1OpenMuPt[0]> 30.0)
     OpenL1_SingleMu30 = 1;

   if((L1IsolEmEt[0] >= 18.0 || L1NIsolEmEt[0] >= 18.0) && (L1ForJetEt[0] >= 16.0))
     OpenL1_EG18_ForJet16 = 1;

   if((L1IsolEmEt[0] >= 8 || L1NIsolEmEt[0] >= 8) && (L1IsolEmEt[1] >= 8 || L1NIsolEmEt[1] >= 8))
     OpenL1_DoubleEG8 = 1;
   
   if((L1IsolEmEt[0] >= 10 || L1NIsolEmEt[0] >= 10) && (L1IsolEmEt[1] >= 10 || L1NIsolEmEt[1] >= 10))
     OpenL1_DoubleEG10 = 1;

   Int_t rc0 = 0;
   Int_t rc5 = 0;
   Int_t rc14 = 0;
   Int_t rc16 = 0;
   for(Int_t i = 0; i < NL1Mu; i++)
   {
      if(L1MuQal[i]> 2)
      {
         if(fabs(L1MuEta[i]) < 1.5)
         {
            if(L1MuPt[i]> 0)
            rc0++;
         }
         if(L1MuPt[i]> 5)
         rc5++;
      }
      if(L1MuQal[i]>=4)
	{
	  if(fabs(L1MuEta[i]) < 2.1)
	    {
	      if(L1MuPt[i]> 14.)
		rc14++;
              if(L1MuPt[i]> 16.)
                rc16++;
	    }
	}
   }
   if(rc0 >= 2)
   OpenL1_DoubleMu0 = 1;
   if(rc5 >= 2)
   OpenL1_DoubleMu5 = 1;

   if(rc14 >= 1)
     OpenL1_SingleMu14_Eta2p1 = 1;
   if(rc14 >= 1)
     OpenL1_SingleMu16_Eta2p1 = 1;


   Int_t rc = 0;
   for(Int_t i = 0; i < NL1Mu; i++)
   {
      if(L1MuQal[i] == 7)
      {
         if(fabs(L1MuEta[i]) < 1.5)
         {
            if(L1MuPt[i]> 5)
            {
               rc++;
            }
         }
      }
   }
   if(rc >= 1)
   OpenL1_SingleMu5_Eta1pt5_Qal7 = 1;

   if(L1CenJetEt[0] >= 20.0 || L1ForJetEt[0] >= 20.0 || L1TauEt[0] >= 20.0)
   {
      if((L1HfTowerCountNegativeEtaRing1 < 2) &&
            (L1HfTowerCountPositiveEtaRing1 < 2) &&
            (L1HfTowerCountNegativeEtaRing2 < 2) &&
            (L1HfTowerCountPositiveEtaRing2 < 2))
      OpenL1_SingleJet20_FwdVeto = 1;
   }

   if((L1IsolEmEt[0]> 2 || L1NIsolEmEt[0]> 2) && (L1IsolEmEt[1]> 2 || L1NIsolEmEt[1]> 2))
   {
      if((L1HfTowerCountNegativeEtaRing1 < 2) &&
            (L1HfTowerCountPositiveEtaRing1 < 2) &&
            (L1HfTowerCountNegativeEtaRing2 < 2) &&
            (L1HfTowerCountPositiveEtaRing2 < 2))
      OpenL1_DoubleEG2_FwdVeto = 1;
   }

   if(L1EtTot> 220)
   OpenL1_ETT220 = 1;

   Int_t njetsforquad = 0;
   for(Int_t j = 0; j < NL1ForJet;j++)
   {
      if(L1ForJetEt[j]> 8.0)
      njetsforquad++;
   }
   for(Int_t k = 0;k < NL1CenJet;k++)
   {
      if(L1CenJetEt[k]> 8.0)
      njetsforquad++;
   }
   if(njetsforquad >= 4)
   OpenL1_QuadJet8U = 1;

   map_BitOfStandardHLTPath["OpenL1_ZeroBias"] = OpenL1_ZeroBias;
   map_BitOfStandardHLTPath["OpenL1_Mu3EG5"] = OpenL1_Mu3EG5;
   map_BitOfStandardHLTPath["OpenL1_EG5_HTT100"] = OpenL1_EG5_HTT100;
   map_BitOfStandardHLTPath["OpenL1_SingleMu30"] = OpenL1_SingleMu30;
   map_BitOfStandardHLTPath["OpenL1_DoubleEG10"] = OpenL1_DoubleEG10;
   map_BitOfStandardHLTPath["OpenL1_DoubleMu0"] = OpenL1_DoubleMu0;
   map_BitOfStandardHLTPath["OpenL1_DoubleMu5"] = OpenL1_DoubleMu5;
   map_BitOfStandardHLTPath["OpenL1_SingleJet20_FwdVeto"] = OpenL1_SingleJet20_FwdVeto;
   map_BitOfStandardHLTPath["OpenL1_DoubleEG2_FwdVeto"] = OpenL1_DoubleEG2_FwdVeto;
   map_BitOfStandardHLTPath["OpenL1_ETT220"] = OpenL1_ETT220;
   map_BitOfStandardHLTPath["OpenL1_SingleMu5_Eta1pt5_Qal7"] = OpenL1_SingleMu5_Eta1pt5_Qal7;
   map_BitOfStandardHLTPath["OpenL1_QuadJet8U"] = OpenL1_QuadJet8U;
   map_BitOfStandardHLTPath["OpenL1_SingleMu14_Eta2p1"] = OpenL1_SingleMu14_Eta2p1;
   map_BitOfStandardHLTPath["OpenL1_SingleMu16_Eta2p1"] = OpenL1_SingleMu16_Eta2p1;
   map_BitOfStandardHLTPath["OpenL1_EG18_ForJet16"] = OpenL1_EG18_ForJet16;
   map_BitOfStandardHLTPath["OpenL1_SingleJet6"] = OpenL1SetSingleJetBit(6)>=1;
   map_BitOfStandardHLTPath["OpenL1_SingleJet10"] = OpenL1SetSingleJetBit(10)>=1;
   map_BitOfStandardHLTPath["OpenL1_SingleJet20"] = OpenL1SetSingleJetBit(20)>=1;
   map_BitOfStandardHLTPath["OpenL1_SingleJet30"] = OpenL1SetSingleJetBit(30)>=1;
   map_BitOfStandardHLTPath["OpenL1_SingleJet40"] = OpenL1SetSingleJetBit(40)>=1;
   map_BitOfStandardHLTPath["OpenL1_SingleJet50"] = OpenL1SetSingleJetBit(50)>=1;
   map_BitOfStandardHLTPath["OpenL1_SingleJet60"] = OpenL1SetSingleJetBit(60)>=1;

   map_BitOfStandardHLTPath["OpenL1_SingleJet16"] = OpenL1SetSingleJetBit(16)>=1;
   map_BitOfStandardHLTPath["OpenL1_SingleJet36"] = OpenL1SetSingleJetBit(36)>=1;
   map_BitOfStandardHLTPath["OpenL1_SingleJet52"] = OpenL1SetSingleJetBit(52)>=1;
   map_BitOfStandardHLTPath["OpenL1_SingleJet68"] = OpenL1SetSingleJetBit(68)>=1;
   map_BitOfStandardHLTPath["OpenL1_SingleJet92"] = OpenL1SetSingleJetBit(92)>=1;
   map_BitOfStandardHLTPath["OpenL1_SingleJet128"] = OpenL1SetSingleJetBit(128)>=1;

}

void OHltTree::SetMapL1BitOfStandardHLTPathUsingLogicParser(OHltMenu *menu, int nentry)
{
   typedef std::vector<TString> myvec;
   typedef std::pair< TString, std::vector<TString> > mypair;
   typedef std::pair< TString, std::vector<int> > mypair2;
   myvec vtmp;
   std::vector<int> vtokentmp;

   TString st, l1st, seeds;
   unsigned ts = menu->GetTriggerSize();
   unsigned l1ts = menu->GetL1TriggerSize();
   //  std::cout<<"########################### \n";
   //  std::cout <<  "@@@ Level1GTSeedResult\n";

   if (nentry == 0)
   { // do this only for first event - speed up code!
      for (unsigned int i=0;i<ts;i++)
      {
         vtmp.clear();
         vtokentmp.clear();
         st = menu->GetTriggerName(i);
         seeds = menu->GetSeedCondition(st);

         //if (seeds != "") continue; // if no seeds skip to avoid error messages

         SetLogicParser((std::string) seeds);

         //      std::cout << "Trigger name: " << st << std::endl;
         //      std::cout << "Seed condition: " << seeds << std::endl;

         std::vector<L1GtLogicParser::OperandToken>& algOpTokenVector =
         (m_l1AlgoLogicParser[i])->operandTokenVector();

         //std::cout<<"@@@@@@@@@@@@ "<<st<<std::endl;

         for (unsigned int j=0;j<l1ts;j++)
         {
            l1st = menu->GetL1TriggerName(j);

            for (size_t k = 0; k < algOpTokenVector.size(); ++k)
            {
               bool iResult = false;
               //	  std::cout << "Token name: " << (algOpTokenVector[k]).tokenName << std::endl;
               if (l1st.CompareTo((algOpTokenVector[k]).tokenName) == 0)
               {
                  if (map_BitOfStandardHLTPath.find(l1st)->second==1)
                  iResult = true;
                  else
                  iResult = false;

                  //	    std::cout << "Token result: " << map_BitOfStandardHLTPath.find(l1st)->second << std::endl;
                  //	    std::cout << "Token result: " << iResult << std::endl;
                  (algOpTokenVector[k]).tokenResult = iResult;
                  vtmp.push_back(l1st);
                  vtokentmp.push_back((int)k);
               }
            }
         }
         map_L1SeedsOfStandardHLTPath.insert(mypair(st, vtmp));
         map_RpnTokenIdOfStandardHLTPath.insert(mypair2(st, vtokentmp));

         bool seedsResult = (m_l1AlgoLogicParser[i])->expressionResult();

         //      std::cout << "Expression result: " << seedsResult << std::endl;

         if (seedsResult)
         map_L1BitOfStandardHLTPath[st] = 1;
         else
         map_L1BitOfStandardHLTPath[st] = 0;
      }
   }
   else
   {
      for (unsigned int i=0;i<ts;i++)
      {
         st = menu->GetTriggerName(i);
         seeds = menu->GetSeedCondition(st);

         if (seeds == "") continue; // 

         std::vector<L1GtLogicParser::OperandToken>& algOpTokenVector =
         (m_l1AlgoLogicParser[i])->operandTokenVector();

         //      std::cout << "************** " << st << " " << nentry << std::endl;

         std::map< TString, std::vector<TString> >::const_iterator it = map_L1SeedsOfStandardHLTPath.find(st);

         if (it != map_L1SeedsOfStandardHLTPath.end())
         {
            unsigned ts2 = it->second.size();
            //	std::cout << "########## " << ts2 << std::endl;
            for (unsigned int j=0;j<ts2;j++)
            {
               //	  std::cout << "               " << it->second[j] << std::endl;
               bool iResult = false;
               if ((map_BitOfStandardHLTPath.find(it->second[j])->second)==1)
               iResult = true;
               else
               iResult = false;

               (algOpTokenVector[ (map_RpnTokenIdOfStandardHLTPath.find(st))->second[j] ]).tokenResult = iResult;

            }
         }

         bool seedsResult = (m_l1AlgoLogicParser[i])->expressionResult();
         //      std::cout << "Expression result: " << seedsResult << std::endl;

         if (seedsResult)
         map_L1BitOfStandardHLTPath[st] = 1;
         else
         map_L1BitOfStandardHLTPath[st] = 0;
      }
   }

}

bool OHltTree::passPreFilterLogicParser(TString str, int nentry)
{

   if (str == "") return true;

   if (nentry == 0)
   { // do this only for first event - speed up code!
      m_preFilterLogicParser = new L1GtLogicParser((std::string)str);
   }

   //cout<<  map_BitOfStandardHLTPath["HLT_Activity_L1A"]<<std::endl;

   //std::cout << "Token string: " << (std::string)str << std::endl;

   std::vector<L1GtLogicParser::OperandToken>& prefOpTokenVector =
   m_preFilterLogicParser->operandTokenVector();

   //std::cout << "Token size: " << prefOpTokenVector.size() << std::endl;
   for (size_t k = 0; k < prefOpTokenVector.size(); ++k)
   {
      bool iResult = false;
      //std::cout << "Token name: " << (prefOpTokenVector[k]).tokenName << std::endl;
      if (map_BitOfStandardHLTPath.find((prefOpTokenVector[k]).tokenName)->second==1)
      iResult = true;
      else
      iResult = false;
      //std::cout << "Token result: " << iResult << std::endl;

      (prefOpTokenVector[k]).tokenResult = iResult;
   }
   bool expResult = m_preFilterLogicParser->expressionResult();
   //bool expResult = true;

   if (expResult)
   return true;
   else
   return false;

}

Bool_t OHltTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef OHltTree_cxx

#endif // #ifdef OHltTree_h
