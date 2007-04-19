#ifndef EcalTrigPrimFunctionalAlgo_h
#define EcalTrigPrimFunctionalAlgo_h
/** \class EcalTrigPrimFunctionalAlgo
 *
 * EcalTrigPrimFunctionalAlgo is the main algorithm class for TPG
 * It coordinates all the other algorithms
 * Structure is very close to electronics
 *
 *
 * \author Ursula Berthon, Stephanie Baffioni,  LLR Palaiseau
 *
 * \version   1st Version may 2006
 * \version   2nd Version jul 2006

 *
 ************************************************************/

#include "Geometry/CaloTopology/interface/EcalTrigTowerConstituentsMap.h"

#include "SimCalorimetry/EcalTrigPrimAlgos/interface/EcalBarrelFenixStrip.h"
#include "SimCalorimetry/EcalTrigPrimAlgos/interface/EcalBarrelFenixTcp.h"

//#include "DataFormats/EcalDigi/interface/EBDataFrame.h"
//#include "DataFormats/EcalDigi/interface/EEDataFrame.h"
#include "DataFormats/EcalDigi/interface/EcalDigiCollections.h"

#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/ESHandle.h"
//#include <sys/time.h>

#include <vector>
//#include <map>
//#include <utility>

class TTree;

class EBDataFrame;
class EEDataFrame;
class EcalTrigTowerDetId;
class EcalTPParameters;
class ETPCoherenceTest;
class EcalTriggerPrimitiveSample;
class CaloSubdetectorGeometry;

/** Main Algo for Ecal trigger primitives. */
class EcalTrigPrimFunctionalAlgo
{  
 public:
  
  //  typedef PRecDet<EcalTrigPrim> precdet;

  explicit EcalTrigPrimFunctionalAlgo(const edm::EventSetup & setup,int binofmax, int nrsamples, bool tccFormat, bool barrelOnly, bool debug, double ebDccAdcToGeV, double eeDccAdcToGeV);
  EcalTrigPrimFunctionalAlgo(const edm::EventSetup & setup, TTree *tree, int binofmax, int nrsamples, bool tccFormat, bool barrelOnly,  bool debug, double ebDccAdcToGeV, double eeDccAdcToGeV);
  virtual ~EcalTrigPrimFunctionalAlgo();

  void updateESRecord(double ttfLowEB, double ttfHighEB, double ttfLowEE, double ttfHighEE);
  /** this actually calculates the trigger primitives (from Digis) */

  void run(const EBDigiCollection * ebdcol, const EEDigiCollection* eedcol, EcalTrigPrimDigiCollection & result,EcalTrigPrimDigiCollection & resultTcc);


 private:

  void init(const edm::EventSetup & setup);

  int linADC(const EcalMGPASample & sample) ; 

  void fillBarrel(const EcalTrigTowerDetId & coarser, const EBDataFrame & frame);

  void fillEndcap(const EcalTrigTowerDetId & coarser, const EEDataFrame & frame);

  int findTowerNrInSM(const EcalTrigTowerDetId &id);

  int calculateTTF(const int en);



  typedef std::map<EcalTrigTowerDetId,std::vector<std::vector<const EBDataFrame * > >,std::less<EcalTrigTowerDetId> > SUMVB;
  //  typedef std::map<EcalTrigTowerDetId,std::vector<std::vector<EEDataFrame> >,std::less<EcalTrigTowerDetId> > SUMVE;

  // typedef std::map<CellID,CaloTimeSample,less<CellID> > SUM;
  // temporary, waiting for pseudostrip geometry
  // SUMVE sumEndcap_;
  // this contains for each trigger tower, first the summed energies, then all EEDataFrames beloonging to this tower
  typedef std::map<EcalTrigTowerDetId,std::vector<int> > SUMVE;
  SUMVE sumEndcap_;
  typedef std::map<EcalTrigTowerDetId,std::vector<EEDataFrame> > MAPE;
  MAPE mapEndcap_;

  /** map of (coarse granularity) cell to the CaloTimeSample objects
      associated to this cell for the EcalBarrel. */
  SUMVB sumBarrel_; 

  /** number of 'strips' (crystals of same eta index) per trigger
      tower in ecal barrel */
  enum {ecal_barrel_strips_per_trigger_tower = 5};  //FIXME
  
  /** number of crystal per such 'strip' */
  enum {ecal_barrel_crystals_per_strip = 5};  //FIXME

  /** max number of crystals per pseudostrip in Endcap */
  enum {ecal_endcap_maxcrystals_per_strip = 5};  //FIXME

  /** max number of crystals per pseudostrip in Endcap */
  enum {ecal_endcap_maxstrips_per_tower = 5};  //FIXME

  //
  EcalBarrelFenixStrip * ebstrip_;
  EcalBarrelFenixTcp * ebtcp_;


  //  EcalEndcapFenixTcp eetcp_;

  edm::ESHandle<EcalTrigTowerConstituentsMap> eTTmap_;
  const CaloSubdetectorGeometry *theEndcapGeometry;

  // for debugging
  ETPCoherenceTest *cTest_;  //FIXME

  //for validation
  bool valid_;
  TTree * valTree_;

  int binOfMaximum_;
  unsigned int nrSamplesToWrite_;

  bool tcpFormat_;
  bool barrelOnly_;
  bool debug_;

  //parameters from EB(E)DataFrames
  double ebDccAdcToGeV_,eeDccAdcToGeV_;

  EcalTPParameters *ecaltpp_;

};

#endif
