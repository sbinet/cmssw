//--------------------------------------------------------------------------------------------------
// $Id $
//
// ElectronEnergyRegressionEvaluate
//
// Helper Class for applying electron energy regression calculation
//
// Authors: A.Takeda, S.Xie, E. Di Marco
//--------------------------------------------------------------------------------------------------


/// --> NOTE if you want to use this class as standalone without the CMSSW part 
///  you need to uncomment the below line and compile normally with scramv1 b 
///  Then you need just to load it in your root macro the lib with the correct path, eg:
///  gSystem->Load("/data/benedet/CMSSW_5_2_2/lib/slc5_amd64_gcc462/pluginEGammaEGammaAnalysisTools.so");

//#define STANDALONE   // <---- this line


#ifndef ELECTRONENERGYREGRESSIONEVALUATE_H
#define ELECTRONENERGYREGRESSIONEVALUATE_H

#include "TFile.h"
#include "TTree.h"

// For applying regression
#include "CondFormats/EgammaObjects/interface/GBRForest.h"
#ifndef STANDALONE
#include "DataFormats/EgammaCandidates/interface/GsfElectronFwd.h"
#include "EgammaAnalysis/ElectronTools/interface/SuperClusterHelper.h"
//#include "RecoEcal/EgammaCoreTools/interface/EcalClusterLazyTools.h"
#endif


class ElectronEnergyRegressionEvaluate{
 public:
  ElectronEnergyRegressionEvaluate();
  ~ElectronEnergyRegressionEvaluate();

  enum ElectronEnergyRegressionType {
    kNoTrkVar,
    kNoTrkVarV1,
    kWithTrkVar,
    kWithTrkVarV1,
    kWithTrkVarV2,
    kWithSubCluVar
  };

  void initialize(std::string weightsFile,
                  ElectronEnergyRegressionEvaluate::ElectronEnergyRegressionType type);

  bool isInitialized() const {return fIsInitialized;}
                
#ifndef STANDALONE
  double calculateRegressionEnergy(const reco::GsfElectron *ele, 
          SuperClusterHelper& mySCHelper, 
          double rho, double nvertices, 
          bool printDebug = false);
  double calculateRegressionEnergyUncertainty(const reco::GsfElectron *ele, 
          SuperClusterHelper& mySCHelper,
          double rho, double nvertices, 
          bool printDebug = false);
#endif

  // Evaluates regression without tracker variables
  double regressionValueNoTrkVar(
                                 double SCRawEnergy,
                                 double scEta,
                                 double scPhi,
                                 double R9,
                                 double etawidth,
                                 double phiwidth,
                                 double NClusters,
                                 double HoE,
                                 double rho,
                                 double vertices,
                                 double EtaSeed,
                                 double PhiSeed,
                                 double ESeed,
                                 double E3x3Seed,
                                 double E5x5Seed,
                                 double see,
                                 double spp,
                                 double sep,
                                 double EMaxSeed,
                                 double E2ndSeed,
                                 double ETopSeed,
                                 double EBottomSeed,
                                 double ELeftSeed,
                                 double ERightSeed,
                                 double E2x5MaxSeed,
                                 double E2x5TopSeed,
                                 double E2x5BottomSeed,
                                 double E2x5LeftSeed,
                                 double E2x5RightSeed,
                                 double IEtaSeed,
                                 double IPhiSeed,
                                 double EtaCrySeed,
                                 double PhiCrySeed,
                                 double PreShowerOverRaw,
                                 bool printDebug = false);

  // Evaluates regression without tracker variables
  double regressionUncertaintyNoTrkVar(
                                       double SCRawEnergy,
                                       double scEta,
                                       double scPhi,
                                       double R9,
                                       double etawidth,
                                       double phiwidth,
                                       double NClusters,
                                       double HoE,
                                       double rho,
                                       double vertices,
                                       double EtaSeed,
                                       double PhiSeed,
                                       double ESeed,
                                       double E3x3Seed,
                                       double E5x5Seed,
                                       double see,
                                       double spp,
                                       double sep,
                                       double EMaxSeed,
                                       double E2ndSeed,
                                       double ETopSeed,
                                       double EBottomSeed,
                                       double ELeftSeed,
                                       double ERightSeed,
                                       double E2x5MaxSeed,
                                       double E2x5TopSeed,
                                       double E2x5BottomSeed,
                                       double E2x5LeftSeed,
                                       double E2x5RightSeed,
                                       double IEtaSeed,
                                       double IPhiSeed,
                                       double EtaCrySeed,
                                       double PhiCrySeed,
                                       double PreShowerOverRaw,
                                       bool printDebug = false);

  // Evaluates regression without tracker variables
  double regressionValueNoTrkVarV1(
                                 double SCRawEnergy,
                                 double scEta,
                                 double scPhi,
                                 double R9,
                                 double etawidth,
                                 double phiwidth,
                                 double NClusters,
                                 double HoE,
                                 double rho,
                                 double vertices,
                                 double EtaSeed,
                                 double PhiSeed,
                                 double ESeed,
                                 double E3x3Seed,
                                 double E5x5Seed,
                                 double see,
                                 double spp,
                                 double sep,
                                 double EMaxSeed,
                                 double E2ndSeed,
                                 double ETopSeed,
                                 double EBottomSeed,
                                 double ELeftSeed,
                                 double ERightSeed,
                                 double E2x5MaxSeed,
                                 double E2x5TopSeed,
                                 double E2x5BottomSeed,
                                 double E2x5LeftSeed,
                                 double E2x5RightSeed,
                                 double IEtaSeed,
                                 double IPhiSeed,
                                 double EtaCrySeed,
                                 double PhiCrySeed,
                                 double PreShowerOverRaw,
                                 int    IsEcalDriven,
                                 bool printDebug = false);

  // Evaluates regression without tracker variables
  double regressionUncertaintyNoTrkVarV1(
                                       double SCRawEnergy,
                                       double scEta,
                                       double scPhi,
                                       double R9,
                                       double etawidth,
                                       double phiwidth,
                                       double NClusters,
                                       double HoE,
                                       double rho,
                                       double vertices,
                                       double EtaSeed,
                                       double PhiSeed,
                                       double ESeed,
                                       double E3x3Seed,
                                       double E5x5Seed,
                                       double see,
                                       double spp,
                                       double sep,
                                       double EMaxSeed,
                                       double E2ndSeed,
                                       double ETopSeed,
                                       double EBottomSeed,
                                       double ELeftSeed,
                                       double ERightSeed,
                                       double E2x5MaxSeed,
                                       double E2x5TopSeed,
                                       double E2x5BottomSeed,
                                       double E2x5LeftSeed,
                                       double E2x5RightSeed,
                                       double IEtaSeed,
                                       double IPhiSeed,
                                       double EtaCrySeed,
                                       double PhiCrySeed,
                                       double PreShowerOverRaw,
                                       int    IsEcalDriven,
                                       bool printDebug = false);

  // Evaluates regression using tracker variables
  // This option is now deprecated. we keep it only
  // for backwards compatibility
  double regressionValueWithTrkVar(				
                                   double electronP,
                                   double SCRawEnergy,
                                   double scEta,
                                   double scPhi,
                                   double R9,
                                   double etawidth,
                                   double phiwidth,
                                   double NClusters,
                                   double HoE,
                                   double rho,
                                   double vertices,
                                   double EtaSeed,
                                   double PhiSeed,
                                   double ESeed,
                                   double E3x3Seed,
                                   double E5x5Seed,
                                   double see,
                                   double spp,
                                   double sep,
                                   double EMaxSeed,
                                   double E2ndSeed,
                                   double ETopSeed,
                                   double EBottomSeed,
                                   double ELeftSeed,
                                   double ERightSeed,
                                   double E2x5MaxSeed,
                                   double E2x5TopSeed,
                                   double E2x5BottomSeed,
                                   double E2x5LeftSeed,
                                   double E2x5RightSeed,
                                   double pt,
                                   double GsfTrackPIn,
                                   double fbrem,
                                   double Charge,
                                   double EoP,
                                   double IEtaSeed,
                                   double IPhiSeed,
                                   double EtaCrySeed,
                                   double PhiCrySeed,
                                   double PreShowerOverRaw,
                                   bool printDebug = false );


  // Evaluates regression using tracker variables
  // This option is now deprecated. we keep it only
  // for backwards compatibility
  double regressionUncertaintyWithTrkVar(				
                                         double electronP,
                                         double SCRawEnergy,
                                         double scEta,
                                         double scPhi,
                                         double R9,
                                         double etawidth,
                                         double phiwidth,
                                         double NClusters,
                                         double HoE,
                                         double rho,
                                         double vertices,
                                         double EtaSeed,
                                         double PhiSeed,
                                         double ESeed,
                                         double E3x3Seed,
                                         double E5x5Seed,
                                         double see,
                                         double spp,
                                         double sep,
                                         double EMaxSeed,
                                         double E2ndSeed,
                                         double ETopSeed,
                                         double EBottomSeed,
                                         double ELeftSeed,
                                         double ERightSeed,
                                         double E2x5MaxSeed,
                                         double E2x5TopSeed,
                                         double E2x5BottomSeed,
                                         double E2x5LeftSeed,
                                         double E2x5RightSeed,
                                         double pt,
                                         double GsfTrackPIn,
                                         double fbrem,
                                         double Charge,
                                         double EoP,
                                         double IEtaSeed,
                                         double IPhiSeed,
                                         double EtaCrySeed,
                                         double PhiCrySeed,
                                         double PreShowerOverRaw,
                                         bool printDebug = false );


  // Evaluates regression using tracker variables
  double regressionValueWithTrkVarV1(				
                                   double SCRawEnergy,
                                   double scEta,
                                   double scPhi,
                                   double R9,
                                   double etawidth,
                                   double phiwidth,
                                   double NClusters,
                                   double HoE,
                                   double rho,
                                   double vertices,
                                   double EtaSeed,
                                   double PhiSeed,
                                   double ESeed,
                                   double E3x3Seed,
                                   double E5x5Seed,
                                   double see,
                                   double spp,
                                   double sep,
                                   double EMaxSeed,
                                   double E2ndSeed,
                                   double ETopSeed,
                                   double EBottomSeed,
                                   double ELeftSeed,
                                   double ERightSeed,
                                   double E2x5MaxSeed,
                                   double E2x5TopSeed,
                                   double E2x5BottomSeed,
                                   double E2x5LeftSeed,
                                   double E2x5RightSeed,                                  
                                   double IEtaSeed,
                                   double IPhiSeed,
                                   double EtaCrySeed,
                                   double PhiCrySeed,
                                   double PreShowerOverRaw, 
                                   int    IsEcalDriven,
                                   double GsfTrackPIn,
                                   double fbrem,
                                   double Charge,
                                   double EoP,
                                   double TrackMomentumError,
                                   double EcalEnergyError,
                                   int    Classification,                           
                                   bool printDebug = false );


  // Evaluates regression using tracker variables
  double regressionUncertaintyWithTrkVarV1(				
                                         double SCRawEnergy,
                                         double scEta,
                                         double scPhi,
                                         double R9,
                                         double etawidth,
                                         double phiwidth,
                                         double NClusters,
                                         double HoE,
                                         double rho,
                                         double vertices,
                                         double EtaSeed,
                                         double PhiSeed,
                                         double ESeed,
                                         double E3x3Seed,
                                         double E5x5Seed,
                                         double see,
                                         double spp,
                                         double sep,
                                         double EMaxSeed,
                                         double E2ndSeed,
                                         double ETopSeed,
                                         double EBottomSeed,
                                         double ELeftSeed,
                                         double ERightSeed,
                                         double E2x5MaxSeed,
                                         double E2x5TopSeed,
                                         double E2x5BottomSeed,
                                         double E2x5LeftSeed,
                                         double E2x5RightSeed,
                                         double IEtaSeed,
                                         double IPhiSeed,
                                         double EtaCrySeed,
                                         double PhiCrySeed,
                                         double PreShowerOverRaw,                   
                                         int    IsEcalDriven,
                                         double GsfTrackPIn,
                                         double fbrem,
                                         double Charge,
                                         double EoP,
                                         double TrackMomentumError,
                                         double EcalEnergyError,
                                         int    Classification,
                                         bool printDebug = false );

    double regressionValueWithTrkVarV1( std::vector<double> &inputvars, 			                                                         
                                        bool printDebug = false );
    double regressionUncertaintyWithTrkVarV1( std::vector<double> &inputvars, 			                                                         
                                              bool printDebug = false );
    

  // Evaluates regression using tracker variables
  double regressionValueWithTrkVarV2(				
                                   double SCRawEnergy,
                                   double scEta,
                                   double scPhi,
                                   double R9,
                                   double etawidth,
                                   double phiwidth,
                                   double NClusters,
                                   double HoE,
                                   double rho,
                                   double vertices,
                                   double EtaSeed,
                                   double PhiSeed,
                                   double ESeed,
                                   double E3x3Seed,
                                   double E5x5Seed,
                                   double see,
                                   double spp,
                                   double sep,
                                   double EMaxSeed,
                                   double E2ndSeed,
                                   double ETopSeed,
                                   double EBottomSeed,
                                   double ELeftSeed,
                                   double ERightSeed,
                                   double E2x5MaxSeed,
                                   double E2x5TopSeed,
                                   double E2x5BottomSeed,
                                   double E2x5LeftSeed,
                                   double E2x5RightSeed,                                  
                                   double IEtaSeed,
                                   double IPhiSeed,
                                   double EtaCrySeed,
                                   double PhiCrySeed,
                                   double PreShowerOverRaw, 
                                   int    IsEcalDriven,
                                   double GsfTrackPIn,
                                   double fbrem,
                                   double Charge,
                                   double EoP,
                                   double TrackMomentumError,
                                   double EcalEnergyError,
                                   int    Classification,
                                   double detaIn,
                                   double dphiIn,
                                   double detaCalo,
                                   double dphiCalo,
                                   double GsfTrackChiSqr,
                                   double KFTrackNLayers,
                                   double ElectronEnergyOverPout,
                                   bool printDebug = false );


  // Evaluates regression using tracker variables
  double regressionUncertaintyWithTrkVarV2(				
                                         double SCRawEnergy,
                                         double scEta,
                                         double scPhi,
                                         double R9,
                                         double etawidth,
                                         double phiwidth,
                                         double NClusters,
                                         double HoE,
                                         double rho,
                                         double vertices,
                                         double EtaSeed,
                                         double PhiSeed,
                                         double ESeed,
                                         double E3x3Seed,
                                         double E5x5Seed,
                                         double see,
                                         double spp,
                                         double sep,
                                         double EMaxSeed,
                                         double E2ndSeed,
                                         double ETopSeed,
                                         double EBottomSeed,
                                         double ELeftSeed,
                                         double ERightSeed,
                                         double E2x5MaxSeed,
                                         double E2x5TopSeed,
                                         double E2x5BottomSeed,
                                         double E2x5LeftSeed,
                                         double E2x5RightSeed,
                                         double IEtaSeed,
                                         double IPhiSeed,
                                         double EtaCrySeed,
                                         double PhiCrySeed,
                                         double PreShowerOverRaw,                   
                                         int    IsEcalDriven,
                                         double GsfTrackPIn,
                                         double fbrem,
                                         double Charge,
                                         double EoP,
                                         double TrackMomentumError,
                                         double EcalEnergyError,
                                         int    Classification,
                                         double detaIn,
                                         double dphiIn,
                                         double detaCalo,
                                         double dphiCalo,
                                         double GsfTrackChiSqr,
                                         double KFTrackNLayers,
                                         double ElectronEnergyOverPout,
                                         bool printDebug = false );

    double regressionValueWithTrkVarV2( std::vector<double> &inputvars, 			                                                         
                                        bool printDebug = false );
    double regressionUncertaintyWithTrkVarV2( std::vector<double> &inputvars, 			                                                         
                                              bool printDebug = false );

    // Evaluates regression uncertainty with subcluster variables and without track variables
    double regressionValueWithSubClusters(
                                 double SCRawEnergy,
                                 double scEta,
                                 double scPhi,
                                 double R9,
                                 double etawidth,
                                 double phiwidth,
                                 double NClusters,
                                 double HoE,
                                 double rho,
                                 double vertices,
                                 double EtaSeed,
                                 double PhiSeed,
                                 double ESeed,
                                 double E3x3Seed,
                                 double E5x5Seed,
                                 double see,
                                 double spp,
                                 double sep,
                                 double EMaxSeed,
                                 double E2ndSeed,
                                 double ETopSeed,
                                 double EBottomSeed,
                                 double ELeftSeed,
                                 double ERightSeed,
                                 double E2x5MaxSeed,
                                 double E2x5TopSeed,
                                 double E2x5BottomSeed,
                                 double E2x5LeftSeed,
                                 double E2x5RightSeed,
                                 double IEtaSeed,
                                 double IPhiSeed,
                                 double EtaCrySeed,
                                 double PhiCrySeed,
                                 double PreShowerOverRaw,
                                 double isEcalDriven,
                                 double isEtaGap,
                                 double isPhiGap,
                                 double isDeeGap, 
                                 double ESubs,
                                 double ESub1,
                                 double EtaSub1,
                                 double PhiSub1,
                                 double EMaxSub1,
                                 double E3x3Sub1,
                                 double ESub2,
                                 double EtaSub2,
                                 double PhiSub2,
                                 double EMaxSub2,
                                 double E3x3Sub2,
                                 double ESub3,
                                 double EtaSub3,
                                 double PhiSub3,
                                 double EMaxSub3,
                                 double E3x3Sub3,
                                 double NPshwClusters,
                                 double EPshwSubs,
                                 double EPshwSub1,
                                 double EtaPshwSub1,
                                 double PhiPshwSub1,
                                 double EPshwSub2,
                                 double EtaPshwSub2,
                                 double PhiPshwSub2,
                                 double EPshwSub3,
                                 double EtaPshwSub3,
                                 double PhiPshwSub3,
                                 bool isEB,
                                 bool printDebug = false);

  // Evaluates regression uncertainty with subcluster variables and without track variables
  double regressionUncertaintyWithSubClusters(
                                       double SCRawEnergy,
                                       double scEta,
                                       double scPhi,
                                       double R9,
                                       double etawidth,
                                       double phiwidth,
                                       double NClusters,
                                       double HoE,
                                       double rho,
                                       double vertices,
                                       double EtaSeed,
                                       double PhiSeed,
                                       double ESeed,
                                       double E3x3Seed,
                                       double E5x5Seed,
                                       double see,
                                       double spp,
                                       double sep,
                                       double EMaxSeed,
                                       double E2ndSeed,
                                       double ETopSeed,
                                       double EBottomSeed,
                                       double ELeftSeed,
                                       double ERightSeed,
                                       double E2x5MaxSeed,
                                       double E2x5TopSeed,
                                       double E2x5BottomSeed,
                                       double E2x5LeftSeed,
                                       double E2x5RightSeed,
                                       double IEtaSeed,
                                       double IPhiSeed,
                                       double EtaCrySeed,
                                       double PhiCrySeed,
                                       double PreShowerOverRaw,
                                       double isEcalDriven,
                                       double isEtaGap,
                                       double isPhiGap,
                                       double isDeeGap, 
                                       double ESubs,
                                       double ESub1,
                                       double EtaSub1,
                                       double PhiSub1,
                                       double EMaxSub1,
                                       double E3x3Sub1,
                                       double ESub2,
                                       double EtaSub2,
                                       double PhiSub2,
                                       double EMaxSub2,
                                       double E3x3Sub2,
                                       double ESub3,
                                       double EtaSub3,
                                       double PhiSub3,
                                       double EMaxSub3,
                                       double E3x3Sub3,
                                       double NPshwClusters,
                                       double EPshwSubs,
                                       double EPshwSub1,
                                       double EtaPshwSub1,
                                       double PhiPshwSub1,
                                       double EPshwSub2,
                                       double EtaPshwSub2,
                                       double PhiPshwSub2,
                                       double EPshwSub3,
                                       double EtaPshwSub3,
                                       double PhiPshwSub3,
                                       bool isEB,
                                       bool printDebug = false);


 private:
  bool fIsInitialized;
  ElectronEnergyRegressionEvaluate::ElectronEnergyRegressionType fVersionType;
  GBRForest *forestCorrection_eb;		// Pointer to the GBRForest for barrel
  GBRForest *forestCorrection_ee;		// Pointer to the GBRForest for endcap

  GBRForest *forestUncertainty_eb;	
  GBRForest *forestUncertainty_ee;		
};

#endif
