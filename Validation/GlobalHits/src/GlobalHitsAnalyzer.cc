/** \file GlobalHitsAnalyzer.cc
 *  
 *  See header file for description of class
 *
 *  $Date: 2008/03/13 21:17:08 $
 *  $Revision: 1.10 $
 *  \author M. Strang SUNY-Buffalo
 */

#include "Validation/GlobalHits/interface/GlobalHitsAnalyzer.h"
#include "DQMServices/Core/interface/DQMStore.h"

GlobalHitsAnalyzer::GlobalHitsAnalyzer(const edm::ParameterSet& iPSet) :
  fName(""), verbosity(0), frequency(0), vtxunit(0), label(""), 
  getAllProvenances(false), printProvenanceInfo(false), count(0)
{
  std::string MsgLoggerCat = "GlobalHitsAnalyzer_GlobalHitsAnalyzer";

  // get information from parameter set
  fName = iPSet.getUntrackedParameter<std::string>("Name");
  verbosity = iPSet.getUntrackedParameter<int>("Verbosity");
  frequency = iPSet.getUntrackedParameter<int>("Frequency");
  vtxunit = iPSet.getUntrackedParameter<int>("VtxUnit");
  edm::ParameterSet m_Prov =
    iPSet.getParameter<edm::ParameterSet>("ProvenanceLookup");
  getAllProvenances = 
    m_Prov.getUntrackedParameter<bool>("GetAllProvenances");
  printProvenanceInfo = 
    m_Prov.getUntrackedParameter<bool>("PrintProvenanceInfo");

  //get Labels to use to extract information
  PxlBrlLowSrc_ = iPSet.getParameter<edm::InputTag>("PxlBrlLowSrc");
  PxlBrlHighSrc_ = iPSet.getParameter<edm::InputTag>("PxlBrlHighSrc");
  PxlFwdLowSrc_ = iPSet.getParameter<edm::InputTag>("PxlFwdLowSrc");
  PxlFwdHighSrc_ = iPSet.getParameter<edm::InputTag>("PxlFwdHighSrc");

  SiTIBLowSrc_ = iPSet.getParameter<edm::InputTag>("SiTIBLowSrc");
  SiTIBHighSrc_ = iPSet.getParameter<edm::InputTag>("SiTIBHighSrc");
  SiTOBLowSrc_ = iPSet.getParameter<edm::InputTag>("SiTOBLowSrc");
  SiTOBHighSrc_ = iPSet.getParameter<edm::InputTag>("SiTOBHighSrc");
  SiTIDLowSrc_ = iPSet.getParameter<edm::InputTag>("SiTIDLowSrc");
  SiTIDHighSrc_ = iPSet.getParameter<edm::InputTag>("SiTIDHighSrc");
  SiTECLowSrc_ = iPSet.getParameter<edm::InputTag>("SiTECLowSrc");
  SiTECHighSrc_ = iPSet.getParameter<edm::InputTag>("SiTECHighSrc");

  MuonCscSrc_ = iPSet.getParameter<edm::InputTag>("MuonCscSrc");
  MuonDtSrc_ = iPSet.getParameter<edm::InputTag>("MuonDtSrc");
  MuonRpcSrc_ = iPSet.getParameter<edm::InputTag>("MuonRpcSrc");

  ECalEBSrc_ = iPSet.getParameter<edm::InputTag>("ECalEBSrc");
  ECalEESrc_ = iPSet.getParameter<edm::InputTag>("ECalEESrc");
  ECalESSrc_ = iPSet.getParameter<edm::InputTag>("ECalESSrc");

  HCalSrc_ = iPSet.getParameter<edm::InputTag>("HCalSrc");

  // use value of first digit to determine default output level (inclusive)
  // 0 is none, 1 is basic, 2 is fill output, 3 is gather output
  verbosity %= 10;

  // create persistent object
  //produces<PGlobalSimHit>(label);

  // print out Parameter Set information being used
  if (verbosity >= 0) {
    edm::LogInfo(MsgLoggerCat) 
      << "\n===============================\n"
      << "Initialized as EDAnalyzer with parameter values:\n"
      << "    Name          = " << fName << "\n"
      << "    Verbosity     = " << verbosity << "\n"
      << "    Frequency     = " << frequency << "\n"
      << "    VtxUnit       = " << vtxunit << "\n"
      << "    GetProv       = " << getAllProvenances << "\n"
      << "    PrintProv     = " << printProvenanceInfo << "\n"
      << "    PxlBrlLowSrc  = " << PxlBrlLowSrc_.label() 
      << ":" << PxlBrlLowSrc_.instance() << "\n"
      << "    PxlBrlHighSrc = " << PxlBrlHighSrc_.label() 
      << ":" << PxlBrlHighSrc_.instance() << "\n"
      << "    PxlFwdLowSrc  = " << PxlFwdLowSrc_.label() 
      << ":" << PxlBrlLowSrc_.instance() << "\n"
      << "    PxlFwdHighSrc = " << PxlFwdHighSrc_.label() 
      << ":" << PxlBrlHighSrc_.instance() << "\n"
      << "    SiTIBLowSrc   = " << SiTIBLowSrc_.label() 
      << ":" << SiTIBLowSrc_.instance() << "\n"
      << "    SiTIBHighSrc  = " << SiTIBHighSrc_.label() 
      << ":" << SiTIBHighSrc_.instance() << "\n"
      << "    SiTOBLowSrc   = " << SiTOBLowSrc_.label() 
      << ":" << SiTOBLowSrc_.instance() << "\n"
      << "    SiTOBHighSrc  = " << SiTOBHighSrc_.label() 
      << ":" << SiTOBHighSrc_.instance() << "\n"
      << "    SiTIDLowSrc   = " << SiTIDLowSrc_.label() 
      << ":" << SiTIDLowSrc_.instance() << "\n"
      << "    SiTIDHighSrc  = " << SiTIDHighSrc_.label() 
      << ":" << SiTIDHighSrc_.instance() << "\n"
      << "    SiTECLowSrc   = " << SiTECLowSrc_.label() 
      << ":" << SiTECLowSrc_.instance() << "\n"
      << "    SiTECHighSrc  = " << SiTECHighSrc_.label() 
      << ":" << SiTECHighSrc_.instance() << "\n"
      << "    MuonCscSrc    = " << MuonCscSrc_.label() 
      << ":" << MuonCscSrc_.instance() << "\n"
      << "    MuonDtSrc     = " << MuonDtSrc_.label() 
      << ":" << MuonDtSrc_.instance() << "\n"
      << "    MuonRpcSrc    = " << MuonRpcSrc_.label() 
      << ":" << MuonRpcSrc_.instance() << "\n"
      << "    ECalEBSrc     = " << ECalEBSrc_.label() 
      << ":" << ECalEBSrc_.instance() << "\n"
      << "    ECalEESrc     = " << ECalEESrc_.label() 
      << ":" << ECalEESrc_.instance() << "\n"
      << "    ECalESSrc     = " << ECalESSrc_.label() 
      << ":" << ECalESSrc_.instance() << "\n"
      << "    HCalSrc       = " << HCalSrc_.label() 
      << ":" << HCalSrc_.instance() << "\n"
      << "===============================\n";
  }

  // get dqm info
  dbe = 0;
  dbe = edm::Service<DQMStore>().operator->();
  if (dbe) {
    if (verbosity > 0 ) {
      dbe->setVerbose(1);
    } else {
      dbe->setVerbose(0);
    }
  }

  if (dbe) {
    if (verbosity > 0 ) dbe->showDirStructure();
  }

  // initialize monitor elements
  for (Int_t i = 0; i < 2; ++i) {
    meMCRGP[i] = 0;
    meMCG4Vtx[i] = 0;
    meGeantVtxX[i] = 0;
    meGeantVtxY[i] = 0;
    meGeantVtxZ[i] = 0; 
    meMCG4Trk[i] = 0;
    meCaloEcal[i] = 0;
    meCaloEcalE[i] = 0;
    meCaloEcalToF[i] = 0;
    meCaloPreSh[i] = 0;
    meCaloPreShE[i] = 0;
    meCaloPreShToF[i] = 0;
    meCaloHcal[i] = 0;
    meCaloHcalE[i] = 0;
    meCaloHcalToF[i] = 0;
    meTrackerPx[i] = 0;
    meTrackerSi[i] = 0;
    meMuon[i] = 0;
    meMuonDtToF[i] = 0;
    meMuonCscToF[i] = 0;
    meMuonRpcFToF[i] = 0;
    meMuonRpcBToF[i] = 0;
  }
  meGeantTrkPt = 0;
  meGeantTrkE = 0;
  meCaloEcalPhi = 0;
  meCaloEcalEta = 0;
  meCaloPreShPhi = 0;
  meCaloPreShEta = 0;
  meCaloHcalPhi = 0;
  meCaloHcalEta = 0;
  meTrackerPxPhi = 0;
  meTrackerPxEta = 0;
  meTrackerPxBToF = 0;
  meTrackerPxBR = 0;
  meTrackerPxFToF = 0;
  meTrackerPxFZ = 0;
  meTrackerSiPhi = 0;
  meTrackerSiEta = 0;
  meTrackerSiBToF = 0;
  meTrackerSiBR = 0;
  meTrackerSiFToF = 0;
  meTrackerSiFZ = 0;
  meMuonPhi = 0;
  meMuonEta = 0;
  meMuonDtR = 0;
  meMuonCscZ = 0;
  meMuonRpcBR = 0;
  meMuonRpcFZ = 0;

  //create histograms
  Char_t hname[200];
  Char_t htitle[200];
  if (dbe) {

    // MCGeant
    dbe->setCurrentFolder("GlobalHitsV/MCGeant");
    sprintf(hname,"hMCRGP1");
    sprintf(htitle,"RawGenParticles");
    meMCRGP[0] = dbe->book1D(hname,htitle,100,0.,5000.);
    sprintf(hname,"hMCRGP2");
    meMCRGP[1] = dbe->book1D(hname,htitle,100,0.,500.);  
    for (Int_t i = 0; i < 2; ++i) {
      meMCRGP[i]->setAxisTitle("Number of Raw Generated Particles",1);
      meMCRGP[i]->setAxisTitle("Count",2);
    }

    sprintf(hname,"hMCG4Vtx1");
    sprintf(htitle,"G4 Vertices");
    meMCG4Vtx[0] = dbe->book1D(hname,htitle,100,0.,50000.);
    sprintf(hname,"hMCG4Vtx2");
    meMCG4Vtx[1] = dbe->book1D(hname,htitle,100,-0.5,99.5); 
    for (Int_t i = 0; i < 2; ++i) {
      meMCG4Vtx[i]->setAxisTitle("Number of Vertices",1);
      meMCG4Vtx[i]->setAxisTitle("Count",2);
    }

    sprintf(hname,"hMCG4Trk1");
    sprintf(htitle,"G4 Tracks");
    meMCG4Trk[0] = dbe->book1D(hname,htitle,150,0.,15000.);
    sprintf(hname,"hMCG4Trk2");
    meMCG4Trk[1] = dbe->book1D(hname,htitle,150,-0.5,99.5);    
    for (Int_t i = 0; i < 2; ++i) {
      meMCG4Trk[i]->setAxisTitle("Number of Tracks",1);
      meMCG4Trk[i]->setAxisTitle("Count",2);
    }

    sprintf(hname,"hGeantVtxX1");
    sprintf(htitle,"Geant vertex x/micrometer");
    meGeantVtxX[0] = dbe->book1D(hname,htitle,100,-8000000.,8000000.);
    sprintf(hname,"hGeantVtxX2");
    meGeantVtxX[1] = dbe->book1D(hname,htitle,100,-50.,50.); 
    for (Int_t i = 0; i < 2; ++i) {
      meGeantVtxX[i]->setAxisTitle("x of Vertex (um)",1);
      meGeantVtxX[i]->setAxisTitle("Count",2);
    }

    sprintf(hname,"hGeantVtxY1");
    sprintf(htitle,"Geant vertex y/micrometer");
    meGeantVtxY[0] = dbe->book1D(hname,htitle,100,-8000000,8000000.);
    sprintf(hname,"hGeantVtxY2");
    meGeantVtxY[1] = dbe->book1D(hname,htitle,100,-50.,50.); 
    for (Int_t i = 0; i < 2; ++i) {
      meGeantVtxY[i]->setAxisTitle("y of Vertex (um)",1);
      meGeantVtxY[i]->setAxisTitle("Count",2);
    }

    sprintf(hname,"hGeantVtxZ1");
    sprintf(htitle,"Geant vertex z/millimeter");
    meGeantVtxZ[0] = dbe->book1D(hname,htitle,100,-11000.,11000.);
    sprintf(hname,"hGeantVtxZ2");
    meGeantVtxZ[1] = dbe->book1D(hname,htitle,100,-250.,250.);
    for (Int_t i = 0; i < 2; ++i) {
      meGeantVtxZ[i]->setAxisTitle("z of Vertex (mm)",1);
      meGeantVtxZ[i]->setAxisTitle("Count",2);
    }

    sprintf(hname,"hGeantTrkPt");
    sprintf(htitle,"Geant track pt/GeV");
    meGeantTrkPt = dbe->book1D(hname,htitle,100,0.,200.);
    meGeantTrkPt->setAxisTitle("pT of Track (GeV)",1);
    meGeantTrkPt->setAxisTitle("Count",2);

    sprintf(hname,"hGeantTrkE");
    sprintf(htitle,"Geant track E/GeV");
    meGeantTrkE = dbe->book1D(hname,htitle,100,0.,5000.);
    meGeantTrkE->setAxisTitle("E of Track (GeV)",1);
    meGeantTrkE->setAxisTitle("Count",2);

    // ECal
    dbe->setCurrentFolder("GlobalHitsV/ECals");
    sprintf(hname,"hCaloEcal1");
    sprintf(htitle,"Ecal hits");
    meCaloEcal[0] = dbe->book1D(hname,htitle,100,0.,10000.);
    sprintf(hname,"hCaloEcal2");
    meCaloEcal[1] = dbe->book1D(hname,htitle,100,-0.5,99.5);

    sprintf(hname,"hCaloEcalE1");
    sprintf(htitle,"Ecal hits, energy/GeV");
    meCaloEcalE[0] = dbe->book1D(hname,htitle,100,0.,10.);
    sprintf(hname,"hCaloEcalE2");
    meCaloEcalE[1] = dbe->book1D(hname,htitle,100,0.,0.1);
    sprintf(hname,"hCaloEcalToF1");
    sprintf(htitle,"Ecal hits, ToF/ns");
    meCaloEcalToF[0] = dbe->book1D(hname,htitle,100,0.,1000.);
    sprintf(hname,"hCaloEcalToF2");
    meCaloEcalToF[1] = dbe->book1D(hname,htitle,100,0.,100.);
 
    for (Int_t i = 0; i < 2; ++i) {
      meCaloEcal[i]->setAxisTitle("Number of Hits",1);
      meCaloEcal[i]->setAxisTitle("Count",2);
      meCaloEcalE[i]->setAxisTitle("Energy of Hits (GeV)",1);
      meCaloEcalE[i]->setAxisTitle("Count",2);
      meCaloEcalToF[i]->setAxisTitle("Time of Flight of Hits (ns)",1);
      meCaloEcalToF[i]->setAxisTitle("Count",2);
    }

    sprintf(hname,"hCaloEcalPhi");
    sprintf(htitle,"Ecal hits, phi/rad");
    meCaloEcalPhi = dbe->book1D(hname,htitle,100,-3.2,3.2);
    meCaloEcalPhi->setAxisTitle("Phi of Hits (rad)",1);
    meCaloEcalPhi->setAxisTitle("Count",2);

    sprintf(hname,"hCaloEcalEta");
    sprintf(htitle,"Ecal hits, eta");
    meCaloEcalEta = dbe->book1D(hname,htitle,100,-5.5,5.5);
    meCaloEcalEta->setAxisTitle("Eta of Hits",1);
    meCaloEcalEta->setAxisTitle("Count",2);

    sprintf(hname,"hCaloPreSh1");
    sprintf(htitle,"PreSh hits");
    meCaloPreSh[0] = dbe->book1D(hname,htitle,100,0.,10000.);
    sprintf(hname,"hCaloPreSh2");
    meCaloPreSh[1] = dbe->book1D(hname,htitle,100,-0.5,99.5);

    sprintf(hname,"hCaloPreShE1");
    sprintf(htitle,"PreSh hits, energy/GeV");
    meCaloPreShE[0] = dbe->book1D(hname,htitle,100,0.,10.);
    sprintf(hname,"hCaloPreShE2");
    meCaloPreShE[1] = dbe->book1D(hname,htitle,100,0.,0.1);

    sprintf(hname,"hCaloPreShToF1");
    sprintf(htitle,"PreSh hits, ToF/ns");
    meCaloPreShToF[0] = dbe->book1D(hname,htitle,100,0.,1000.);
    sprintf(hname,"hCaloPreShToF2");
    meCaloPreShToF[1] = dbe->book1D(hname,htitle,100,0.,100.);

    for (Int_t i = 0; i < 2; ++i) {
      meCaloPreSh[i]->setAxisTitle("Number of Hits",1);
      meCaloPreSh[i]->setAxisTitle("Count",2);
      meCaloPreShE[i]->setAxisTitle("Energy of Hits (GeV)",1);
      meCaloPreShE[i]->setAxisTitle("Count",2);
      meCaloPreShToF[i]->setAxisTitle("Time of Flight of Hits (ns)",1);
      meCaloPreShToF[i]->setAxisTitle("Count",2);
    }

    sprintf(hname,"hCaloPreShPhi");
    sprintf(htitle,"PreSh hits, phi/rad");
    meCaloPreShPhi = dbe->book1D(hname,htitle,100,-3.2,3.2);
    meCaloPreShPhi->setAxisTitle("Phi of Hits (rad)",1);
    meCaloPreShPhi->setAxisTitle("Count",2);

    sprintf(hname,"hCaloPreShEta");
    sprintf(htitle,"PreSh hits, eta");
    meCaloPreShEta = dbe->book1D(hname,htitle,100,-5.5,5.5);
    meCaloPreShEta->setAxisTitle("Eta of Hits",1);
    meCaloPreShEta->setAxisTitle("Count",2);

    // Hcal
    dbe->setCurrentFolder("GlobalHitsV/HCals");
    sprintf(hname,"hCaloHcal1");
    sprintf(htitle,"Hcal hits");
    meCaloHcal[0] = dbe->book1D(hname,htitle,100,0.,10000.);
    sprintf(hname,"hCaloHcal2");
    meCaloHcal[1] = dbe->book1D(hname,htitle,100,-0.5,99.5);

    sprintf(hname,"hCaloHcalE1");
    sprintf(htitle,"Hcal hits, energy/GeV");
    meCaloHcalE[0] = dbe->book1D(hname,htitle,100,0.,10.);
    sprintf(hname,"hCaloHcalE2");
    meCaloHcalE[1] = dbe->book1D(hname,htitle,100,0.,0.1);

    sprintf(hname,"hCaloHcalToF1");
    sprintf(htitle,"Hcal hits, ToF/ns");
    meCaloHcalToF[0] = dbe->book1D(hname,htitle,100,0.,1000.);
    sprintf(hname,"hCaloHcalToF2");
    meCaloHcalToF[1] = dbe->book1D(hname,htitle,100,0.,100.);

    for (Int_t i = 0; i < 2; ++i) {
      meCaloHcal[i]->setAxisTitle("Number of Hits",1);
      meCaloHcal[i]->setAxisTitle("Count",2);
      meCaloHcalE[i]->setAxisTitle("Energy of Hits (GeV)",1);
      meCaloHcalE[i]->setAxisTitle("Count",2);
      meCaloHcalToF[i]->setAxisTitle("Time of Flight of Hits (ns)",1);
      meCaloHcalToF[i]->setAxisTitle("Count",2);
    }

    sprintf(hname,"hCaloHcalPhi");
    sprintf(htitle,"Hcal hits, phi/rad");
    meCaloHcalPhi = dbe->book1D(hname,htitle,100,-3.2,3.2);
    meCaloHcalPhi->setAxisTitle("Phi of Hits (rad)",1);
    meCaloHcalPhi->setAxisTitle("Count",2);

    sprintf(hname,"hCaloHcalEta");
    sprintf(htitle,"Hcal hits, eta");
    meCaloHcalEta = dbe->book1D(hname,htitle,100,-5.5,5.5);
    meCaloHcalEta->setAxisTitle("Eta of Hits",1);
    meCaloHcalEta->setAxisTitle("Count",2);
    
    // SiPixels
    dbe->setCurrentFolder("GlobalHitsV/SiPixels");
    sprintf(hname,"hTrackerPx1");
    sprintf(htitle,"Pixel hits");
    meTrackerPx[0] = dbe->book1D(hname,htitle,100,0.,10000.);
    sprintf(hname,"hTrackerPx2");
    meTrackerPx[1] = dbe->book1D(hname,htitle,100,-0.5,99.5);
    for (Int_t i = 0; i < 2; ++i) {
      meTrackerPx[i]->setAxisTitle("Number of Pixel Hits",1);
      meTrackerPx[i]->setAxisTitle("Count",2);
    }

    sprintf(hname,"hTrackerPxPhi");
    sprintf(htitle,"Pixel hits phi/rad");
    meTrackerPxPhi = dbe->book1D(hname,htitle,100,-3.2,3.2);
    meTrackerPxPhi->setAxisTitle("Phi of Hits (rad)",1);
    meTrackerPxPhi->setAxisTitle("Count",2);

    sprintf(hname,"hTrackerPxEta");
    sprintf(htitle,"Pixel hits eta");
    meTrackerPxEta = dbe->book1D(hname,htitle,100,-3.5,3.5);
    meTrackerPxEta->setAxisTitle("Eta of Hits",1);
    meTrackerPxEta->setAxisTitle("Count",2);

    sprintf(hname,"hTrackerPxBToF");
    sprintf(htitle,"Pixel barrel hits, ToF/ns");
    meTrackerPxBToF = dbe->book1D(hname,htitle,100,0.,40.);
    meTrackerPxBToF->setAxisTitle("Time of Flight of Hits (ns)",1);
    meTrackerPxBToF->setAxisTitle("Count",2);

    sprintf(hname,"hTrackerPxBR");
    sprintf(htitle,"Pixel barrel hits, R/cm");
    meTrackerPxBR = dbe->book1D(hname,htitle,100,0.,50.);
    meTrackerPxBR->setAxisTitle("R of Hits (cm)",1);
    meTrackerPxBR->setAxisTitle("Count",2);

    sprintf(hname,"hTrackerPxFToF");
    sprintf(htitle,"Pixel forward hits, ToF/ns");
    meTrackerPxFToF = dbe->book1D(hname,htitle,100,0.,50.);
    meTrackerPxFToF->setAxisTitle("Time of Flight of Hits (ns)",1);
    meTrackerPxFToF->setAxisTitle("Count",2);

    sprintf(hname,"hTrackerPxFZ");
    sprintf(htitle,"Pixel forward hits, Z/cm");
    meTrackerPxFZ = 
      dbe->book1D(hname,htitle,200,-100.,100.);
    meTrackerPxFZ->setAxisTitle("Z of Hits (cm)",1);
    meTrackerPxFZ->setAxisTitle("Count",2);

    // SiStrips
    dbe->setCurrentFolder("GlobalHitsV/SiStrips");
    sprintf(hname,"hTrackerSi1");
    sprintf(htitle,"Silicon hits");
    meTrackerSi[0] = dbe->book1D(hname,htitle,100,0.,10000.);
    sprintf(hname,"hTrackerSi2");
    meTrackerSi[1] = dbe->book1D(hname,htitle,100,-0.5,99.5);
    for (Int_t i = 0; i < 2; ++i) { 
      meTrackerSi[i]->setAxisTitle("Number of Silicon Hits",1);
      meTrackerSi[i]->setAxisTitle("Count",2);
    }

    sprintf(hname,"hTrackerSiPhi");
    sprintf(htitle,"Silicon hits phi/rad");
    meTrackerSiPhi = dbe->book1D(hname,htitle,100,-3.2,3.2);
    meTrackerSiPhi->setAxisTitle("Phi of Hits (rad)",1);
    meTrackerSiPhi->setAxisTitle("Count",2);

    sprintf(hname,"hTrackerSiEta");
    sprintf(htitle,"Silicon hits eta");
    meTrackerSiEta = dbe->book1D(hname,htitle,100,-3.5,3.5);
    meTrackerSiEta->setAxisTitle("Eta of Hits",1);
    meTrackerSiEta->setAxisTitle("Count",2);

    sprintf(hname,"hTrackerSiBToF");
    sprintf(htitle,"Silicon barrel hits, ToF/ns");
    meTrackerSiBToF = dbe->book1D(hname,htitle,100,0.,50.);
    meTrackerSiBToF->setAxisTitle("Time of Flight of Hits (ns)",1);
    meTrackerSiBToF->setAxisTitle("Count",2);

    sprintf(hname,"hTrackerSiBR");
    sprintf(htitle,"Silicon barrel hits, R/cm");
    meTrackerSiBR = dbe->book1D(hname,htitle,100,0.,200.);
    meTrackerSiBR->setAxisTitle("R of Hits (cm)",1);
    meTrackerSiBR->setAxisTitle("Count",2);

    sprintf(hname,"hTrackerSiFToF");
    sprintf(htitle,"Silicon forward hits, ToF/ns");
    meTrackerSiFToF = dbe->book1D(hname,htitle,100,0.,75.);
    meTrackerSiFToF->setAxisTitle("Time of Flight of Hits (ns)",1);
    meTrackerSiFToF->setAxisTitle("Count",2);

    sprintf(hname,"hTrackerSiFZ");
    sprintf(htitle,"Silicon forward hits, Z/cm");
    meTrackerSiFZ = dbe->book1D(hname,htitle,200,-300.,300.);
    meTrackerSiFZ->setAxisTitle("Z of Hits (cm)",1);
    meTrackerSiFZ->setAxisTitle("Count",2);

    // Muon
    dbe->setCurrentFolder("GlobalHitsV/Muons");
    sprintf(hname,"hMuon1");
    sprintf(htitle,"Muon hits");
    meMuon[0] = dbe->book1D(hname,htitle,100,0.,10000.);
    sprintf(hname,"hMuon2");
    meMuon[1] = dbe->book1D(hname,htitle,100,-0.5,99.5);
    for (Int_t i = 0; i < 2; ++i) { 
      meMuon[i]->setAxisTitle("Number of Muon Hits",1);
      meMuon[i]->setAxisTitle("Count",2);
    }  

    sprintf(hname,"hMuonPhi");
    sprintf(htitle,"Muon hits phi/rad");
    meMuonPhi = dbe->book1D(hname,htitle,100,-3.2,3.2);
    meMuonPhi->setAxisTitle("Phi of Hits (rad)",1);
    meMuonPhi->setAxisTitle("Count",2);

    sprintf(hname,"hMuonEta");
    sprintf(htitle,"Muon hits eta");
    meMuonEta = dbe->book1D(hname,htitle,100,-3.5,3.5);
    meMuonEta->setAxisTitle("Eta of Hits",1);
    meMuonEta->setAxisTitle("Count",2);

    sprintf(hname,"hMuonCscToF1");
    sprintf(htitle,"Muon CSC hits, ToF/ns");
    meMuonCscToF[0] = dbe->book1D(hname,htitle,100,0.,250.);
    sprintf(hname,"hMuonCscToF2");
    meMuonCscToF[1] = dbe->book1D(hname,htitle,100,0.,50.);
    for (Int_t i = 0; i < 2; ++i) {   
      meMuonCscToF[i]->setAxisTitle("Time of Flight of Hits (ns)",1);
      meMuonCscToF[i]->setAxisTitle("Count",2);
    }  

    sprintf(hname,"hMuonCscZ");
    sprintf(htitle,"Muon CSC hits, Z/cm");
    meMuonCscZ = dbe->book1D(hname,htitle,200,-1500.,1500.);
    meMuonCscZ->setAxisTitle("Z of Hits (cm)",1);
    meMuonCscZ->setAxisTitle("Count",2);

    sprintf(hname,"hMuonDtToF1");
    sprintf(htitle,"Muon DT hits, ToF/ns");
    meMuonDtToF[0] = dbe->book1D(hname,htitle,100,0.,250.);
    sprintf(hname,"hMuonDtToF2");
    meMuonDtToF[1] = dbe->book1D(hname,htitle,100,0.,50.);
    for (Int_t i = 0; i < 2; ++i) {   
      meMuonDtToF[i]->setAxisTitle("Time of Flight of Hits (ns)",1);
      meMuonDtToF[i]->setAxisTitle("Count",2);
    } 

    sprintf(hname,"hMuonDtR");
    sprintf(htitle,"Muon DT hits, R/cm");
    meMuonDtR = dbe->book1D(hname,htitle,100,0.,1500.); 
    meMuonDtR->setAxisTitle("R of Hits (cm)",1);
    meMuonDtR->setAxisTitle("Count",2);

    sprintf(hname,"hMuonRpcFToF1");
    sprintf(htitle,"Muon RPC forward hits, ToF/ns");
    meMuonRpcFToF[0] = dbe->book1D(hname,htitle,100,0.,250.);
    sprintf(hname,"hMuonRpcFToF2");
    meMuonRpcFToF[1] = dbe->book1D(hname,htitle,100,0.,50.);
    for (Int_t i = 0; i < 2; ++i) {   
      meMuonRpcFToF[i]->setAxisTitle("Time of Flight of Hits (ns)",1);
      meMuonRpcFToF[i]->setAxisTitle("Count",2);
    }  
    sprintf(hname,"hMuonRpcFZ");
    sprintf(htitle,"Muon RPC forward hits, Z/cm");
    meMuonRpcFZ = dbe->book1D(hname,htitle,201,-1500.,1500.);
    meMuonRpcFZ->setAxisTitle("Z of Hits (cm)",1);
    meMuonRpcFZ->setAxisTitle("Count",2);

    sprintf(hname,"hMuonRpcBToF1");
    sprintf(htitle,"Muon RPC barrel hits, ToF/ns");
    meMuonRpcBToF[0] = dbe->book1D(hname,htitle,100,0.,250.);
    sprintf(hname,"hMuonRpcBToF2");
    meMuonRpcBToF[1] = dbe->book1D(hname,htitle,100,0.,50.);
    for (Int_t i = 0; i < 2; ++i) {   
      meMuonRpcBToF[i]->setAxisTitle("Time of Flight of Hits (ns)",1);
      meMuonRpcBToF[i]->setAxisTitle("Count",2);
    }

    sprintf(hname,"hMuonRpcBR");
    sprintf(htitle,"Muon RPC barrel hits, R/cm");
    meMuonRpcBR = dbe->book1D(hname,htitle,100,0.,1500.);
    meMuonRpcBR->setAxisTitle("R of Hits (cm)",1);
    meMuonRpcBR->setAxisTitle("Count",2); 
  }
}

GlobalHitsAnalyzer::~GlobalHitsAnalyzer() {}

void GlobalHitsAnalyzer::beginJob(const edm::EventSetup& iSetup)
{
  return;
}

void GlobalHitsAnalyzer::endJob()
{
  std::string MsgLoggerCat = "GlobalHitsAnalyzer_endJob";
  if (verbosity >= 0)
    edm::LogInfo(MsgLoggerCat) 
      << "Terminating having processed " << count << " events.";
  return;
}

void GlobalHitsAnalyzer::analyze(const edm::Event& iEvent, 
				 const edm::EventSetup& iSetup)
{
  std::string MsgLoggerCat = "GlobalHitsAnalyzer_analyze";

  // keep track of number of events processed
  ++count;

  // get event id information
  int nrun = iEvent.id().run();
  int nevt = iEvent.id().event();

  if (verbosity > 0) {
    edm::LogInfo(MsgLoggerCat)
      << "Processing run " << nrun << ", event " << nevt
      << " (" << count << " events total)";
  } else if (verbosity == 0) {
    if (nevt%frequency == 0 || nevt == 1) {
      edm::LogInfo(MsgLoggerCat)
	<< "Processing run " << nrun << ", event " << nevt
	<< " (" << count << " events total)";
    }
  }

  // look at information available in the event
  if (getAllProvenances) {

    std::vector<const edm::Provenance*> AllProv;
    iEvent.getAllProvenance(AllProv);

    if (verbosity >= 0)
      edm::LogInfo(MsgLoggerCat)
	<< "Number of Provenances = " << AllProv.size();

    if (printProvenanceInfo && (verbosity >= 0)) {
      TString eventout("\nProvenance info:\n");      

      for (unsigned int i = 0; i < AllProv.size(); ++i) {
	eventout += "\n       ******************************";
	eventout += "\n       Module       : ";
	eventout += AllProv[i]->moduleLabel();
	eventout += "\n       ProductID    : ";
	eventout += AllProv[i]->productID().id();
	eventout += "\n       ClassName    : ";
	eventout += AllProv[i]->className();
	eventout += "\n       InstanceName : ";
	eventout += AllProv[i]->productInstanceName();
	eventout += "\n       BranchName   : ";
	eventout += AllProv[i]->branchName();
      }
      eventout += "\n       ******************************\n";
      edm::LogInfo(MsgLoggerCat) << eventout << "\n";
      printProvenanceInfo = false;
    }
    getAllProvenances = false;
  }

  // call fill functions
  //gather G4MC information from event
  fillG4MC(iEvent);
  // gather Tracker information from event
  fillTrk(iEvent,iSetup);
  // gather muon information from event
  fillMuon(iEvent, iSetup);
  // gather Ecal information from event
  fillECal(iEvent, iSetup);
  // gather Hcal information from event
  fillHCal(iEvent, iSetup);

  if (verbosity > 0)
    edm::LogInfo (MsgLoggerCat)
      << "Done gathering data from event.";

  return;
}

//==================fill and store functions================================
void GlobalHitsAnalyzer::fillG4MC(const edm::Event& iEvent)
{

  std::string MsgLoggerCat = "GlobalHitsAnalyzer_fillG4MC";
 
  TString eventout;
  if (verbosity > 0)
    eventout = "\nGathering info:";

  //////////////////////
  // get MC information
  /////////////////////
  edm::Handle<edm::HepMCProduct> HepMCEvt;
  std::vector<edm::Handle<edm::HepMCProduct> > AllHepMCEvt;
  iEvent.getManyByType(AllHepMCEvt);

  // loop through products and extract VtxSmearing if available. Any of them
  // should have the information needed
  for (unsigned int i = 0; i < AllHepMCEvt.size(); ++i) {
    HepMCEvt = AllHepMCEvt[i];
    if ((HepMCEvt.provenance()->product()).moduleLabel() == "VtxSmeared")
      break;
  }

  if (!HepMCEvt.isValid()) {
    edm::LogWarning(MsgLoggerCat)
      << "Unable to find HepMCProduct in event!";
    return;
  } else {
    eventout += "\n          Using HepMCProduct: ";
    eventout += (HepMCEvt.provenance()->product()).moduleLabel();
  }
  const HepMC::GenEvent* MCEvt = HepMCEvt->GetEvent();
  nRawGenPart = MCEvt->particles_size();

  if (verbosity > 1) {
    eventout += "\n          Number of Raw Particles collected:......... ";
    eventout += nRawGenPart;
  }  

  if (meMCRGP[0]) meMCRGP[0]->Fill((float)nRawGenPart);
  if (meMCRGP[1]) meMCRGP[1]->Fill((float)nRawGenPart);  

  ////////////////////////////
  // get G4Vertex information
  ////////////////////////////
  // convert unit stored in SimVertex to mm
  float unit = 0.;
  if (vtxunit == 0) unit = 1.;  // already in mm
  if (vtxunit == 1) unit = 10.; // stored in cm, convert to mm

  edm::Handle<edm::SimVertexContainer> G4VtxContainer;
  iEvent.getByType(G4VtxContainer);
  if (!G4VtxContainer.isValid()) {
    edm::LogWarning(MsgLoggerCat)
      << "Unable to find SimVertex in event!";
    return;
  }
  int i = 0;
  edm::SimVertexContainer::const_iterator itVtx;
  for (itVtx = G4VtxContainer->begin(); itVtx != G4VtxContainer->end(); 
       ++itVtx) {
    
    ++i;

    const math::XYZTLorentzVector G4Vtx1(itVtx->position().x(),
					 itVtx->position().y(),
					 itVtx->position().z(),
					 itVtx->position().e());

    double G4Vtx[4];
    G4Vtx1.GetCoordinates(G4Vtx);

    if (meGeantVtxX[0]) meGeantVtxX[0]->Fill((G4Vtx[0]*unit)/micrometer);
    if (meGeantVtxX[1]) meGeantVtxX[1]->Fill((G4Vtx[0]*unit)/micrometer);
    
    if (meGeantVtxY[0]) meGeantVtxY[0]->Fill((G4Vtx[1]*unit)/micrometer);
    if (meGeantVtxY[1]) meGeantVtxY[1]->Fill((G4Vtx[1]*unit)/micrometer);
    
    if (meGeantVtxZ[0]) meGeantVtxZ[0]->Fill((G4Vtx[2]*unit)/millimeter);
    if (meGeantVtxZ[1]) meGeantVtxZ[1]->Fill((G4Vtx[2]*unit)/millimeter); 
    
  }

  if (verbosity > 1) {
    eventout += "\n          Number of G4Vertices collected:............ ";
    eventout += i;
  }  

  if (meMCG4Vtx[0]) meMCG4Vtx[0]->Fill((float)i);
  if (meMCG4Vtx[1]) meMCG4Vtx[1]->Fill((float)i);  

  ///////////////////////////
  // get G4Track information
  ///////////////////////////
  edm::Handle<edm::SimTrackContainer> G4TrkContainer;
  iEvent.getByType(G4TrkContainer);
  if (!G4TrkContainer.isValid()) {
    edm::LogWarning(MsgLoggerCat)
      << "Unable to find SimTrack in event!";
    return;
  }
  i = 0;
  edm::SimTrackContainer::const_iterator itTrk;
  for (itTrk = G4TrkContainer->begin(); itTrk != G4TrkContainer->end(); 
       ++itTrk) {

    ++i;

    const math::XYZTLorentzVector G4Trk1(itTrk->momentum().x(),
					 itTrk->momentum().y(),
					 itTrk->momentum().z(),
					 itTrk->momentum().e());
    double G4Trk[4];
    G4Trk1.GetCoordinates(G4Trk);

    if (meGeantTrkPt) meGeantTrkPt->
			Fill(sqrt(G4Trk[0]*G4Trk[0]+G4Trk[1]*G4Trk[1]));
    if (meGeantTrkE) meGeantTrkE->Fill(G4Trk[3]);
  } 

  if (verbosity > 1) {
    eventout += "\n          Number of G4Tracks collected:.............. ";
    eventout += i;
  }  

  if (meMCG4Trk[0]) meMCG4Trk[0]->Fill((float)i);
  if (meMCG4Trk[1]) meMCG4Trk[1]->Fill((float)i); 

  if (verbosity > 0)
    edm::LogInfo(MsgLoggerCat) << eventout << "\n";
    
  return;
}

void GlobalHitsAnalyzer::fillTrk(const edm::Event& iEvent, 
				 const edm::EventSetup& iSetup)
{

  nPxlHits = 0;
  std::string MsgLoggerCat = "GlobalHitsAnalyzer_fillTrk";

  TString eventout;
  if (verbosity > 0)
    eventout = "\nGathering info:";  
  
  // access the tracker geometry
  edm::ESHandle<TrackerGeometry> theTrackerGeometry;
  iSetup.get<TrackerDigiGeometryRecord>().get(theTrackerGeometry);
  if (!theTrackerGeometry.isValid()) {
    edm::LogWarning(MsgLoggerCat)
      << "Unable to find TrackerDigiGeometryRecord in event!";
    return;
  }
  const TrackerGeometry& theTracker(*theTrackerGeometry);
    
  // iterator to access containers
  edm::PSimHitContainer::const_iterator itHit;

  ///////////////////////////////
  // get Pixel Barrel information
  ///////////////////////////////
  edm::PSimHitContainer thePxlBrlHits;
  // extract low container
  edm::Handle<edm::PSimHitContainer> PxlBrlLowContainer;
  iEvent.getByLabel(PxlBrlLowSrc_,PxlBrlLowContainer);
  if (!PxlBrlLowContainer.isValid()) {
    edm::LogWarning(MsgLoggerCat)
      << "Unable to find TrackerHitsPixelBarrelLowTof in event!";
    return;
  }
  // extract high container
  edm::Handle<edm::PSimHitContainer> PxlBrlHighContainer;
  iEvent.getByLabel(PxlBrlHighSrc_,PxlBrlHighContainer);
  if (!PxlBrlHighContainer.isValid()) {
    edm::LogWarning(MsgLoggerCat)
      << "Unable to find TrackerHitsPixelBarrelHighTof in event!";
    return;
  }
  // place both containers into new container
  thePxlBrlHits.insert(thePxlBrlHits.end(),PxlBrlLowContainer->begin(),
		       PxlBrlLowContainer->end());
  thePxlBrlHits.insert(thePxlBrlHits.end(),PxlBrlHighContainer->begin(),
		       PxlBrlHighContainer->end());

  // cycle through new container
  int i = 0, j = 0;
  for (itHit = thePxlBrlHits.begin(); itHit != thePxlBrlHits.end(); ++itHit) {

    ++i;

    // create a DetId from the detUnitId
    DetId theDetUnitId(itHit->detUnitId());
    int detector = theDetUnitId.det();
    int subdetector = theDetUnitId.subdetId();

    // check that expected detector is returned
    if ((detector == dTrk) && (subdetector == sdPxlBrl)) {

      // get the GeomDetUnit from the geometry using theDetUnitID
      const GeomDetUnit *theDet = theTracker.idToDetUnit(theDetUnitId);

      if (!theDet) {
	edm::LogWarning(MsgLoggerCat)
	  << "Unable to get GeomDetUnit from PxlBrlHits for Hit " << i;
	continue;
      }

      ++j;

      // get the Surface of the hit (knows how to go from local <-> global)
      const BoundPlane& bSurface = theDet->surface();

      if(meTrackerPxBToF) meTrackerPxBToF->Fill(itHit->tof());
      if(meTrackerPxBR) 
	meTrackerPxBR->Fill(bSurface.toGlobal(itHit->localPosition()).perp());
      if(meTrackerPxPhi) 
	meTrackerPxPhi->Fill(bSurface.toGlobal(itHit->localPosition()).phi());
      if(meTrackerPxEta) 
	meTrackerPxEta->Fill(bSurface.toGlobal(itHit->localPosition()).eta());

    } else {
      edm::LogWarning(MsgLoggerCat)
	<< "PxlBrl PSimHit " << i 
	<< " is expected to be (det,subdet) = (" 
	<< dTrk << "," << sdPxlBrl
	<< "); value returned is: ("
	<< detector << "," << subdetector << ")";
      continue;
    } // end detector type check
  } // end loop through PxlBrl Hits

  if (verbosity > 1) {
    eventout += "\n          Number of Pixel Barrel Hits collected:..... ";
    eventout += j;
  }  
  
  nPxlHits += j;

  /////////////////////////////////
  // get Pixel Forward information
  ////////////////////////////////
  edm::PSimHitContainer thePxlFwdHits;
  // extract low container
  edm::Handle<edm::PSimHitContainer> PxlFwdLowContainer;
  iEvent.getByLabel(PxlFwdLowSrc_,PxlFwdLowContainer);
  if (!PxlFwdLowContainer.isValid()) {
    edm::LogWarning(MsgLoggerCat)
      << "Unable to find TrackerHitsPixelEndcapLowTof in event!";
    return;
  }
  // extract high container
  edm::Handle<edm::PSimHitContainer> PxlFwdHighContainer;
  iEvent.getByLabel(PxlFwdHighSrc_,PxlFwdHighContainer);
  if (!PxlFwdHighContainer.isValid()) {
    edm::LogWarning("GlobalHitsAnalyzer_fillTrk")
      << "Unable to find TrackerHitsPixelEndcapHighTof in event!";
    return;
  }
  // place both containers into new container
  thePxlFwdHits.insert(thePxlFwdHits.end(),PxlFwdLowContainer->begin(),
		       PxlFwdLowContainer->end());
  thePxlFwdHits.insert(thePxlFwdHits.end(),PxlFwdHighContainer->begin(),
		       PxlFwdHighContainer->end());

  // cycle through new container
  i = 0; j = 0;
  for (itHit = thePxlFwdHits.begin(); itHit != thePxlFwdHits.end(); ++itHit) {

    ++i;

    // create a DetId from the detUnitId
    DetId theDetUnitId(itHit->detUnitId());
    int detector = theDetUnitId.det();
    int subdetector = theDetUnitId.subdetId();

    // check that expected detector is returned
    if ((detector == dTrk) && (subdetector == sdPxlFwd)) {

      // get the GeomDetUnit from the geometry using theDetUnitID
      const GeomDetUnit *theDet = theTracker.idToDetUnit(theDetUnitId);

      if (!theDet) {
	edm::LogWarning(MsgLoggerCat)
	  << "Unable to get GeomDetUnit from PxlFwdHits for Hit " << i;;
	continue;
      }

      ++j;

      // get the Surface of the hit (knows how to go from local <-> global)
      const BoundPlane& bSurface = theDet->surface();

      if(meTrackerPxFToF) meTrackerPxFToF->Fill(itHit->tof());
      if(meTrackerPxFZ) 
	meTrackerPxFZ->Fill(bSurface.toGlobal(itHit->localPosition()).z());
      if(meTrackerPxPhi) 
	meTrackerPxPhi->Fill(bSurface.toGlobal(itHit->localPosition()).phi());
      if(meTrackerPxEta) 
	meTrackerPxEta->Fill(bSurface.toGlobal(itHit->localPosition()).eta());

    } else {
      edm::LogWarning(MsgLoggerCat)
	<< "PxlFwd PSimHit " << i 
	<< " is expected to be (det,subdet) = (" 
	<< dTrk << "," << sdPxlFwd
	<< "); value returned is: ("
	<< detector << "," << subdetector << ")";
      continue;
    } // end detector type check
  } // end loop through PxlFwd Hits

  if (verbosity > 1) {
    eventout += "\n          Number of Pixel Forward Hits collected:.... ";
    eventout += j;
  }  

  nPxlHits += j;

  if (meTrackerPx[0]) meTrackerPx[0]->Fill((float)nPxlHits);
  if (meTrackerPx[1]) meTrackerPx[1]->Fill((float)nPxlHits); 

  ///////////////////////////////////
  // get Silicon Barrel information
  //////////////////////////////////
  nSiHits = 0;
  edm::PSimHitContainer theSiBrlHits;
  // extract TIB low container
  edm::Handle<edm::PSimHitContainer> SiTIBLowContainer;
  iEvent.getByLabel(SiTIBLowSrc_,SiTIBLowContainer);
  if (!SiTIBLowContainer.isValid()) {
    edm::LogWarning(MsgLoggerCat)
      << "Unable to find TrackerHitsTIBLowTof in event!";
    return;
  }
  // extract TIB high container
  edm::Handle<edm::PSimHitContainer> SiTIBHighContainer;
  iEvent.getByLabel(SiTIBHighSrc_,SiTIBHighContainer);
  if (!SiTIBHighContainer.isValid()) {
    edm::LogWarning(MsgLoggerCat)
      << "Unable to find TrackerHitsTIBHighTof in event!";
    return;
  }
  // extract TOB low container
  edm::Handle<edm::PSimHitContainer> SiTOBLowContainer;
  iEvent.getByLabel(SiTOBLowSrc_,SiTOBLowContainer);
  if (!SiTOBLowContainer.isValid()) {
    edm::LogWarning(MsgLoggerCat)
      << "Unable to find TrackerHitsTOBLowTof in event!";
    return;
  }
  // extract TOB high container
  edm::Handle<edm::PSimHitContainer> SiTOBHighContainer;
  iEvent.getByLabel(SiTOBHighSrc_,SiTOBHighContainer);
  if (!SiTOBHighContainer.isValid()) {
    edm::LogWarning(MsgLoggerCat)
      << "Unable to find TrackerHitsTOBHighTof in event!";
    return;
  }
  // place all containers into new container
  theSiBrlHits.insert(theSiBrlHits.end(),SiTIBLowContainer->begin(),
		       SiTIBLowContainer->end());
  theSiBrlHits.insert(theSiBrlHits.end(),SiTIBHighContainer->begin(),
		       SiTIBHighContainer->end());
  theSiBrlHits.insert(theSiBrlHits.end(),SiTOBLowContainer->begin(),
		       SiTOBLowContainer->end());
  theSiBrlHits.insert(theSiBrlHits.end(),SiTOBHighContainer->begin(),
		       SiTOBHighContainer->end());

  // cycle through new container
  i = 0; j = 0;
  for (itHit = theSiBrlHits.begin(); itHit != theSiBrlHits.end(); ++itHit) {

    ++i;

    // create a DetId from the detUnitId
    DetId theDetUnitId(itHit->detUnitId());
    int detector = theDetUnitId.det();
    int subdetector = theDetUnitId.subdetId();

    // check that expected detector is returned
    if ((detector == dTrk) && 
	((subdetector == sdSiTIB) ||
	 (subdetector == sdSiTOB))) {

      // get the GeomDetUnit from the geometry using theDetUnitID
      const GeomDetUnit *theDet = theTracker.idToDetUnit(theDetUnitId);

      if (!theDet) {
	edm::LogWarning(MsgLoggerCat)
	  << "Unable to get GeomDetUnit from SiBrlHits for Hit " << i;
	continue;
      }

      ++j;

      // get the Surface of the hit (knows how to go from local <-> global)
      const BoundPlane& bSurface = theDet->surface();

      if(meTrackerSiBToF) meTrackerSiBToF->Fill(itHit->tof());
      if(meTrackerSiBR) 
	meTrackerSiBR->Fill(bSurface.toGlobal(itHit->localPosition()).perp());
      if(meTrackerSiPhi) 
	meTrackerSiPhi->Fill(bSurface.toGlobal(itHit->localPosition()).phi());
      if(meTrackerSiEta) 
	meTrackerSiEta->Fill(bSurface.toGlobal(itHit->localPosition()).eta());

    } else {
      edm::LogWarning(MsgLoggerCat)
	<< "SiBrl PSimHit " << i 
	<< " is expected to be (det,subdet) = (" 
	<< dTrk << "," << sdSiTIB
	<< " || " << sdSiTOB << "); value returned is: ("
	<< detector << "," << subdetector << ")";
      continue;
    } // end detector type check
  } // end loop through SiBrl Hits

  if (verbosity > 1) {
    eventout += "\n          Number of Silicon Barrel Hits collected:... ";
    eventout += j;
  }  

  nSiHits += j;

  ///////////////////////////////////
  // get Silicon Forward information
  ///////////////////////////////////
  edm::PSimHitContainer theSiFwdHits;
  // extract TID low container
  edm::Handle<edm::PSimHitContainer> SiTIDLowContainer;
  iEvent.getByLabel(SiTIDLowSrc_,SiTIDLowContainer);
  if (!SiTIDLowContainer.isValid()) {
    edm::LogWarning(MsgLoggerCat)
      << "Unable to find TrackerHitsTIDLowTof in event!";
    return;
  }
  // extract TID high container
  edm::Handle<edm::PSimHitContainer> SiTIDHighContainer;
  iEvent.getByLabel(SiTIDHighSrc_,SiTIDHighContainer);
  if (!SiTIDHighContainer.isValid()) {
    edm::LogWarning("GlobalHitsAnalyzer_fillTrk")
      << "Unable to find TrackerHitsTIDHighTof in event!";
    return;
  }
  // extract TEC low container
  edm::Handle<edm::PSimHitContainer> SiTECLowContainer;
  iEvent.getByLabel(SiTECLowSrc_,SiTECLowContainer);
  if (!SiTECLowContainer.isValid()) {
    edm::LogWarning(MsgLoggerCat)
      << "Unable to find TrackerHitsTECLowTof in event!";
    return;
  }
  // extract TEC high container
  edm::Handle<edm::PSimHitContainer> SiTECHighContainer;
  iEvent.getByLabel(SiTECHighSrc_,SiTECHighContainer);
  if (!SiTECHighContainer.isValid()) {
    edm::LogWarning(MsgLoggerCat)
      << "Unable to find TrackerHitsTECHighTof in event!";
    return;
  }
  // place all containers into new container
  theSiFwdHits.insert(theSiFwdHits.end(),SiTIDLowContainer->begin(),
		       SiTIDLowContainer->end());
  theSiFwdHits.insert(theSiFwdHits.end(),SiTIDHighContainer->begin(),
		       SiTIDHighContainer->end());
  theSiFwdHits.insert(theSiFwdHits.end(),SiTECLowContainer->begin(),
		       SiTECLowContainer->end());
  theSiFwdHits.insert(theSiFwdHits.end(),SiTECHighContainer->begin(),
		       SiTECHighContainer->end());

  // cycle through container
  i = 0; j = 0;
  for (itHit = theSiFwdHits.begin(); itHit != theSiFwdHits.end(); ++itHit) {

    ++i;

    // create a DetId from the detUnitId
    DetId theDetUnitId(itHit->detUnitId());
    int detector = theDetUnitId.det();
    int subdetector = theDetUnitId.subdetId();

    // check that expected detector is returned 
    if ((detector == dTrk) && 
	((subdetector == sdSiTID) ||
	 (subdetector == sdSiTEC))) {
      
      // get the GeomDetUnit from the geometry using theDetUnitID
      const GeomDetUnit *theDet = theTracker.idToDetUnit(theDetUnitId);
      
      if (!theDet) {
	edm::LogWarning(MsgLoggerCat)
	  << "Unable to get GeomDetUnit from SiFwdHits Hit " << i;
	return;
      }
      
      ++j;

      // get the Surface of the hit (knows how to go from local <-> global)
      const BoundPlane& bSurface = theDet->surface();
      
      if(meTrackerSiFToF) meTrackerSiFToF->Fill(itHit->tof());
      if(meTrackerSiFZ) 
	meTrackerSiFZ->Fill(bSurface.toGlobal(itHit->localPosition()).z());
      if(meTrackerSiPhi) 
	meTrackerSiPhi->Fill(bSurface.toGlobal(itHit->localPosition()).phi());
      if(meTrackerSiEta) 
	meTrackerSiEta->Fill(bSurface.toGlobal(itHit->localPosition()).eta());

    } else {
      edm::LogWarning(MsgLoggerCat)
	<< "SiFwd PSimHit " << i 
	<< " is expected to be (det,subdet) = (" 
	<< dTrk << "," << sdSiTOB
	<< " || " << sdSiTEC << "); value returned is: ("
	<< detector << "," << subdetector << ")";
      continue;
    } // end check detector type
  } // end loop through SiFwd Hits

  if (verbosity > 1) {
    eventout += "\n          Number of Silicon Forward Hits collected:.. ";
    eventout += j;
  }  

  nSiHits +=j;

  if (meTrackerSi[0]) meTrackerSi[0]->Fill((float)nSiHits);
  if (meTrackerSi[1]) meTrackerSi[1]->Fill((float)nSiHits); 

  if (verbosity > 0)
    edm::LogInfo(MsgLoggerCat) << eventout << "\n";

  return;
}

void GlobalHitsAnalyzer::fillMuon(const edm::Event& iEvent, 
				  const edm::EventSetup& iSetup)
{
  nMuonHits = 0;
  std::string MsgLoggerCat = "GlobalHitsAnalyzer_fillMuon";

  TString eventout;
  if (verbosity > 0)
    eventout = "\nGathering info:";  

  // iterator to access containers
  edm::PSimHitContainer::const_iterator itHit;

  ///////////////////////
  // access the CSC Muon
  ///////////////////////
  // access the CSC Muon geometry
  edm::ESHandle<CSCGeometry> theCSCGeometry;
  iSetup.get<MuonGeometryRecord>().get(theCSCGeometry);
  if (!theCSCGeometry.isValid()) {
    edm::LogWarning(MsgLoggerCat)
      << "Unable to find MuonGeometryRecord for the CSCGeometry in event!";
    return;
  }
  const CSCGeometry& theCSCMuon(*theCSCGeometry);

  // get Muon CSC information
  edm::Handle<edm::PSimHitContainer> MuonCSCContainer;
  iEvent.getByLabel(MuonCscSrc_,MuonCSCContainer);
  if (!MuonCSCContainer.isValid()) {
    edm::LogWarning(MsgLoggerCat)
      << "Unable to find MuonCSCHits in event!";
    return;
  }

  // cycle through container
  int i = 0, j = 0;
  for (itHit = MuonCSCContainer->begin(); itHit != MuonCSCContainer->end(); 
       ++itHit) {

    ++i;

    // create a DetId from the detUnitId
    DetId theDetUnitId(itHit->detUnitId());
    int detector = theDetUnitId.det();
    int subdetector = theDetUnitId.subdetId();

    // check that expected detector is returned
    if ((detector == dMuon) && 
        (subdetector == sdMuonCSC)) {

      // get the GeomDetUnit from the geometry using theDetUnitID
      const GeomDetUnit *theDet = theCSCMuon.idToDetUnit(theDetUnitId);
    
      if (!theDet) {
	edm::LogWarning(MsgLoggerCat)
	  << "Unable to get GeomDetUnit from theCSCMuon for hit " << i;
	continue;
      }
     
      ++j;

      // get the Surface of the hit (knows how to go from local <-> global)
      const BoundPlane& bSurface = theDet->surface();
    
      if (meMuonCscToF[0]) meMuonCscToF[0]->Fill(itHit->tof());
      if (meMuonCscToF[1]) meMuonCscToF[1]->Fill(itHit->tof());
      if (meMuonCscZ) 
	meMuonCscZ->Fill(bSurface.toGlobal(itHit->localPosition()).z());
      if (meMuonPhi)
	meMuonPhi->Fill(bSurface.toGlobal(itHit->localPosition()).phi());
      if (meMuonEta)
	meMuonEta->Fill(bSurface.toGlobal(itHit->localPosition()).eta());

    } else {
      edm::LogWarning(MsgLoggerCat)
        << "MuonCsc PSimHit " << i 
        << " is expected to be (det,subdet) = (" 
        << dMuon << "," << sdMuonCSC
        << "); value returned is: ("
        << detector << "," << subdetector << ")";
      continue;
    } // end detector type check
  } // end loop through CSC Hits

  if (verbosity > 1) {
    eventout += "\n          Number of CSC muon Hits collected:......... ";
    eventout += j;
  }  

  nMuonHits += j;

  /////////////////////
  // access the DT Muon
  /////////////////////
  // access the DT Muon geometry
  edm::ESHandle<DTGeometry> theDTGeometry;
  iSetup.get<MuonGeometryRecord>().get(theDTGeometry);
  if (!theDTGeometry.isValid()) {
    edm::LogWarning(MsgLoggerCat)
      << "Unable to find MuonGeometryRecord for the DTGeometry in event!";
    return;
  }
  const DTGeometry& theDTMuon(*theDTGeometry);

  // get Muon DT information
  edm::Handle<edm::PSimHitContainer> MuonDtContainer;
  iEvent.getByLabel(MuonDtSrc_,MuonDtContainer);
  if (!MuonDtContainer.isValid()) {
    edm::LogWarning(MsgLoggerCat)
      << "Unable to find MuonDTHits in event!";
    return;
  }

  // cycle through container
  i = 0, j = 0;
  for (itHit = MuonDtContainer->begin(); itHit != MuonDtContainer->end(); 
       ++itHit) {

    ++i;

    // create a DetId from the detUnitId
    DetId theDetUnitId(itHit->detUnitId());
    int detector = theDetUnitId.det();
    int subdetector = theDetUnitId.subdetId();

    // check that expected detector is returned
    if ((detector == dMuon) && 
        (subdetector == sdMuonDT)) {

      // CSC uses wires and layers rather than the full detID
      // get the wireId
      DTWireId wireId(itHit->detUnitId());

      // get the DTLayer from the geometry using the wireID
      const DTLayer *theDet = theDTMuon.layer(wireId.layerId());

      if (!theDet) {
	edm::LogWarning(MsgLoggerCat)
	  << "Unable to get GeomDetUnit from theDtMuon for hit " << i;
	continue;
      }
     
      ++j;

      // get the Surface of the hit (knows how to go from local <-> global)
      const BoundPlane& bSurface = theDet->surface();
    
      if (meMuonDtToF[0]) meMuonDtToF[0]->Fill(itHit->tof());
      if (meMuonDtToF[1]) meMuonDtToF[1]->Fill(itHit->tof());
      if (meMuonDtR) 
	meMuonDtR->Fill(bSurface.toGlobal(itHit->localPosition()).perp());
      if (meMuonPhi)
	meMuonPhi->Fill(bSurface.toGlobal(itHit->localPosition()).phi());
      if (meMuonEta)
	meMuonEta->Fill(bSurface.toGlobal(itHit->localPosition()).eta());

    } else {
      edm::LogWarning(MsgLoggerCat)
        << "MuonDt PSimHit " << i 
        << " is expected to be (det,subdet) = (" 
        << dMuon << "," << sdMuonDT
        << "); value returned is: ("
        << detector << "," << subdetector << ")";
      continue;
    } // end detector type check
  } // end loop through DT Hits

  if (verbosity > 1) {
    eventout += "\n          Number of DT muon Hits collected:.......... ";
    eventout += j;
  } 

  nMuonHits += j;

  //int RPCBrl = 0, RPCFwd = 0;
  ///////////////////////
  // access the RPC Muon
  ///////////////////////
  // access the RPC Muon geometry
  edm::ESHandle<RPCGeometry> theRPCGeometry;
  iSetup.get<MuonGeometryRecord>().get(theRPCGeometry);
  if (!theRPCGeometry.isValid()) {
    edm::LogWarning(MsgLoggerCat)
      << "Unable to find MuonGeometryRecord for the RPCGeometry in event!";
    return;
  }
  const RPCGeometry& theRPCMuon(*theRPCGeometry);

  // get Muon RPC information
  edm::Handle<edm::PSimHitContainer> MuonRPCContainer;
  iEvent.getByLabel(MuonRpcSrc_,MuonRPCContainer);
  if (!MuonRPCContainer.isValid()) {
    edm::LogWarning(MsgLoggerCat)
      << "Unable to find MuonRPCHits in event!";
    return;
  }

  // cycle through container
  i = 0, j = 0;
  int RPCBrl =0, RPCFwd = 0;
  for (itHit = MuonRPCContainer->begin(); itHit != MuonRPCContainer->end(); 
       ++itHit) {

    ++i;

    // create a DetID from the detUnitId
    DetId theDetUnitId(itHit->detUnitId());
    int detector = theDetUnitId.det();
    int subdetector = theDetUnitId.subdetId();

    // check that expected detector is returned
    if ((detector == dMuon) && 
        (subdetector == sdMuonRPC)) {
      
      // get an RPCDetID from the detUnitID
      RPCDetId RPCId(itHit->detUnitId());      

      // find the region of the RPC hit
      int region = RPCId.region();

      // get the GeomDetUnit from the geometry using the RPCDetId
      const GeomDetUnit *theDet = theRPCMuon.idToDetUnit(theDetUnitId);

      if (!theDet) {
	edm::LogWarning(MsgLoggerCat)
	  << "Unable to get GeomDetUnit from theRPCMuon for hit " << i;
	continue;
      }

      ++j;

      // get the Surface of the hit (knows how to go from local <-> global)
      const BoundPlane& bSurface = theDet->surface();
    
      // gather necessary information
      if ((region == sdMuonRPCRgnFwdp) || (region == sdMuonRPCRgnFwdn)) {
	++RPCFwd;

	if (meMuonRpcFToF[0]) meMuonRpcFToF[0]->Fill(itHit->tof());
	if (meMuonRpcFToF[1]) meMuonRpcFToF[1]->Fill(itHit->tof());
	if (meMuonRpcFZ) 
	  meMuonRpcFZ->Fill(bSurface.toGlobal(itHit->localPosition()).z());
	if (meMuonPhi)
	  meMuonPhi->Fill(bSurface.toGlobal(itHit->localPosition()).phi());
	if (meMuonEta)
	  meMuonEta->Fill(bSurface.toGlobal(itHit->localPosition()).eta());

      } else if (region == sdMuonRPCRgnBrl) {
	++RPCBrl;

	if (meMuonRpcBToF[0]) meMuonRpcBToF[0]->Fill(itHit->tof());
	if (meMuonRpcBToF[1]) meMuonRpcBToF[1]->Fill(itHit->tof());
	if (meMuonRpcBR) 
	  meMuonRpcBR->Fill(bSurface.toGlobal(itHit->localPosition()).perp());
	if (meMuonPhi)
	  meMuonPhi->Fill(bSurface.toGlobal(itHit->localPosition()).phi());
	if (meMuonEta)
	  meMuonEta->Fill(bSurface.toGlobal(itHit->localPosition()).eta());
	
      } else {
	edm::LogWarning(MsgLoggerCat)
	  << "Invalid region for RPC Muon hit" << i;
	continue;
      } // end check of region
    } else {
      edm::LogWarning(MsgLoggerCat)
        << "MuonRpc PSimHit " << i 
        << " is expected to be (det,subdet) = (" 
        << dMuon << "," << sdMuonRPC
        << "); value returned is: ("
        << detector << "," << subdetector << ")";
      continue;
    } // end detector type check
  } // end loop through RPC Hits

  if (verbosity > 1) {
    eventout += "\n          Number of RPC muon Hits collected:......... ";
    eventout += j;
    eventout += "\n                    RPC Barrel muon Hits:............ ";
    eventout += RPCBrl;
    eventout += "\n                    RPC Forward muon Hits:........... ";
    eventout += RPCFwd;    
  }  

  nMuonHits += j;

  if (meMuon[0]) meMuon[0]->Fill((float)nMuonHits);
  if (meMuon[1]) meMuon[1]->Fill((float)nMuonHits); 

  if (verbosity > 0)
    edm::LogInfo(MsgLoggerCat) << eventout << "\n";

  return;
}

void GlobalHitsAnalyzer::fillECal(const edm::Event& iEvent, 
				  const edm::EventSetup& iSetup)
{
  std::string MsgLoggerCat = "GlobalHitsAnalyzer_fillECal";

  TString eventout;
  if (verbosity > 0)
    eventout = "\nGathering info:";  
  
  // access the calorimeter geometry
  edm::ESHandle<CaloGeometry> theCaloGeometry;
  iSetup.get<IdealGeometryRecord>().get(theCaloGeometry);
  if (!theCaloGeometry.isValid()) {
    edm::LogWarning(MsgLoggerCat)
      << "Unable to find IdealGeometryRecord in event!";
    return;
  }
  const CaloGeometry& theCalo(*theCaloGeometry);
    
  // iterator to access containers
  edm::PCaloHitContainer::const_iterator itHit;

  ///////////////////////////////
  // get  ECal information
  ///////////////////////////////
  edm::PCaloHitContainer theECalHits;
  // extract EB container
  edm::Handle<edm::PCaloHitContainer> EBContainer;
  iEvent.getByLabel(ECalEBSrc_,EBContainer);
  if (!EBContainer.isValid()) {
    edm::LogWarning(MsgLoggerCat)
      << "Unable to find EcalHitsEB in event!";
    return;
  }
  // extract EE container
  edm::Handle<edm::PCaloHitContainer> EEContainer;
  iEvent.getByLabel(ECalEESrc_,EEContainer);
  if (!EEContainer.isValid()) {
    edm::LogWarning(MsgLoggerCat)
      << "Unable to find EcalHitsEE in event!";
    return;
  }
  // place both containers into new container
  theECalHits.insert(theECalHits.end(),EBContainer->begin(),
		       EBContainer->end());
  theECalHits.insert(theECalHits.end(),EEContainer->begin(),
		       EEContainer->end());

  // cycle through new container
  int i = 0, j = 0;
  for (itHit = theECalHits.begin(); itHit != theECalHits.end(); ++itHit) {

    ++i;

    // create a DetId from the detUnitId
    DetId theDetUnitId(itHit->id());
    int detector = theDetUnitId.det();
    int subdetector = theDetUnitId.subdetId();

    // check that expected detector is returned
    if ((detector == dEcal) && 
	((subdetector == sdEcalBrl) ||
	 (subdetector == sdEcalFwd))) {

      // get the Cell geometry
      const CaloCellGeometry *theDet = theCalo.
	getSubdetectorGeometry(theDetUnitId)->getGeometry(theDetUnitId);

      if (!theDet) {
	edm::LogWarning(MsgLoggerCat)
	  << "Unable to get CaloCellGeometry from ECalHits for Hit " << i;
	continue;
      }

      ++j;

      // get the global position of the cell
      const GlobalPoint& globalposition = theDet->getPosition();

      if (meCaloEcalE[0]) meCaloEcalE[0]->Fill(itHit->energy());
      if (meCaloEcalE[1]) meCaloEcalE[1]->Fill(itHit->energy());
      if (meCaloEcalToF[0]) meCaloEcalToF[0]->Fill(itHit->time());
      if (meCaloEcalToF[1]) meCaloEcalToF[1]->Fill(itHit->time());
      if (meCaloEcalPhi) meCaloEcalPhi->Fill(globalposition.phi());
      if (meCaloEcalEta) meCaloEcalEta->Fill(globalposition.eta());

    } else {
      edm::LogWarning(MsgLoggerCat)
	<< "ECal PCaloHit " << i 
	<< " is expected to be (det,subdet) = (" 
	<< dEcal << "," << sdEcalBrl
	<< " || " << sdEcalFwd << "); value returned is: ("
	<< detector << "," << subdetector << ")";
      continue;
    } // end detector type check
  } // end loop through ECal Hits

  if (verbosity > 1) {
    eventout += "\n          Number of ECal Hits collected:............. ";
    eventout += j;
  }  

  if (meCaloEcal[0]) meCaloEcal[0]->Fill((float)j);
  if (meCaloEcal[1]) meCaloEcal[1]->Fill((float)j); 

  ////////////////////////////
  // Get Preshower information
  ////////////////////////////
  // extract PreShower container
  edm::Handle<edm::PCaloHitContainer> PreShContainer;
  iEvent.getByLabel(ECalESSrc_,PreShContainer);
  if (!PreShContainer.isValid()) {
    edm::LogWarning(MsgLoggerCat)
      << "Unable to find EcalHitsES in event!";
    return;
  }

  // cycle through container
  i = 0, j = 0;
  for (itHit = PreShContainer->begin(); 
       itHit != PreShContainer->end(); ++itHit) {

    ++i;

    // create a DetId from the detUnitId
    DetId theDetUnitId(itHit->id());
    int detector = theDetUnitId.det();
    int subdetector = theDetUnitId.subdetId();

    // check that expected detector is returned
    if ((detector == dEcal) && 
	(subdetector == sdEcalPS)) {

      // get the Cell geometry
      const CaloCellGeometry *theDet = theCalo.
	getSubdetectorGeometry(theDetUnitId)->getGeometry(theDetUnitId);

      if (!theDet) {
	edm::LogWarning(MsgLoggerCat)
	  << "Unable to get CaloCellGeometry from PreShContainer for Hit " 
	  << i;
	continue;
      }

      ++j;

      // get the global position of the cell
      const GlobalPoint& globalposition = theDet->getPosition();

      if (meCaloPreShE[0]) meCaloPreShE[0]->Fill(itHit->energy());
      if (meCaloPreShE[1]) meCaloPreShE[1]->Fill(itHit->energy());
      if (meCaloPreShToF[0]) meCaloPreShToF[0]->Fill(itHit->time());
      if (meCaloPreShToF[1]) meCaloPreShToF[1]->Fill(itHit->time());
      if (meCaloPreShPhi) meCaloPreShPhi->Fill(globalposition.phi());
      if (meCaloPreShEta) meCaloPreShEta->Fill(globalposition.eta());

    } else {
      edm::LogWarning(MsgLoggerCat)
	<< "PreSh PCaloHit " << i 
	<< " is expected to be (det,subdet) = (" 
	<< dEcal << "," << sdEcalPS
	<< "); value returned is: ("
	<< detector << "," << subdetector << ")";
      continue;
    } // end detector type check
  } // end loop through PreShower Hits

  if (verbosity > 1) {
    eventout += "\n          Number of PreSh Hits collected:............ ";
    eventout += j;
  }  

  if (meCaloPreSh[0]) meCaloPreSh[0]->Fill((float)j);
  if (meCaloPreSh[1]) meCaloPreSh[1]->Fill((float)j); 

  if (verbosity > 0)
    edm::LogInfo(MsgLoggerCat) << eventout << "\n";

  return;
}

void GlobalHitsAnalyzer::fillHCal(const edm::Event& iEvent, 
				  const edm::EventSetup& iSetup)
{
  std::string MsgLoggerCat = "GlobalHitsAnalyzer_fillHCal";

  TString eventout;
  if (verbosity > 0)
    eventout = "\nGathering info:";  
  
  // access the calorimeter geometry
  edm::ESHandle<CaloGeometry> theCaloGeometry;
  iSetup.get<IdealGeometryRecord>().get(theCaloGeometry);
  if (!theCaloGeometry.isValid()) {
    edm::LogWarning(MsgLoggerCat)
      << "Unable to find IdealGeometryRecord in event!";
    return;
  }
  const CaloGeometry& theCalo(*theCaloGeometry);
    
  // iterator to access containers
  edm::PCaloHitContainer::const_iterator itHit;

  ///////////////////////////////
  // get  HCal information
  ///////////////////////////////
  // extract HCal container
  edm::Handle<edm::PCaloHitContainer> HCalContainer;
  iEvent.getByLabel(HCalSrc_,HCalContainer);
  if (!HCalContainer.isValid()) {
    edm::LogWarning(MsgLoggerCat)
      << "Unable to find HCalHits in event!";
    return;
  }

  // cycle through container
  int i = 0, j = 0;
  for (itHit = HCalContainer->begin(); 
       itHit != HCalContainer->end(); ++itHit) {

    ++i;

    // create a DetId from the detUnitId
    DetId theDetUnitId(itHit->id());
    int detector = theDetUnitId.det();
    int subdetector = theDetUnitId.subdetId();

    // check that expected detector is returned
    if ((detector == dHcal) && 
	((subdetector == sdHcalBrl) ||
	 (subdetector == sdHcalEC) ||
	 (subdetector == sdHcalOut) ||
	 (subdetector == sdHcalFwd))) {

      // get the Cell geometry
      const CaloCellGeometry *theDet = theCalo.
	getSubdetectorGeometry(theDetUnitId)->getGeometry(theDetUnitId);

      if (!theDet) {
	edm::LogWarning(MsgLoggerCat)
	  << "Unable to get CaloCellGeometry from HCalContainer for Hit " << i;
	continue;
      }

      ++j;

      // get the global position of the cell
      const GlobalPoint& globalposition = theDet->getPosition();

      if (meCaloHcalE[0]) meCaloHcalE[0]->Fill(itHit->energy());
      if (meCaloHcalE[1]) meCaloHcalE[1]->Fill(itHit->energy());
      if (meCaloHcalToF[0]) meCaloHcalToF[0]->Fill(itHit->time());
      if (meCaloHcalToF[1]) meCaloHcalToF[1]->Fill(itHit->time());
      if (meCaloHcalPhi) meCaloHcalPhi->Fill(globalposition.phi());
      if (meCaloHcalEta) meCaloHcalEta->Fill(globalposition.eta());

    } else {
      edm::LogWarning(MsgLoggerCat)
	<< "HCal PCaloHit " << i 
	<< " is expected to be (det,subdet) = (" 
	<< dHcal << "," << sdHcalBrl
	<< " || " << sdHcalEC << " || " << sdHcalOut << " || " << sdHcalFwd
	<< "); value returned is: ("
	<< detector << "," << subdetector << ")";
      continue;
    } // end detector type check
  } // end loop through HCal Hits

  if (verbosity > 1) {
    eventout += "\n          Number of HCal Hits collected:............. ";
    eventout += j;
  }  

  if (meCaloHcal[0]) meCaloHcal[0]->Fill((float)j);
  if (meCaloHcal[1]) meCaloHcal[1]->Fill((float)j); 

  if (verbosity > 0)
    edm::LogInfo(MsgLoggerCat) << eventout << "\n";

  return;
}
