#include "L1Trigger/GlobalCaloTrigger/test/gctTestHfEtSums.h"

#include "DataFormats/L1CaloTrigger/interface/L1CaloRegion.h"

#include "L1Trigger/GlobalCaloTrigger/interface/L1GctGlobalEnergyAlgos.h"
#include "L1Trigger/GlobalCaloTrigger/interface/L1GctGlobalHfSumAlgos.h"
#include "L1Trigger/GlobalCaloTrigger/interface/L1GlobalCaloTrigger.h"

#include <math.h>
#include <iostream>
#include <cassert>

using namespace std;

//=================================================================================================================
//
/// Constructor and destructor

gctTestHfEtSums::gctTestHfEtSums() {}
gctTestHfEtSums::~gctTestHfEtSums() {}

//=================================================================================================================
//
  /// Reset stored sums
void gctTestHfEtSums::reset() {
  m_expectedRing0EtSumPositiveEta.clear();
  m_expectedRing0EtSumNegativeEta.clear();
  m_expectedRing1EtSumPositiveEta.clear();
  m_expectedRing1EtSumNegativeEta.clear();
  m_expectedRing0BitCountPositiveEta.clear();
  m_expectedRing0BitCountNegativeEta.clear();
  m_expectedRing1BitCountPositiveEta.clear();
  m_expectedRing1BitCountNegativeEta.clear();
}

//=================================================================================================================
//
/// Check the Ht summing algorithms
void gctTestHfEtSums::fillExpectedHfSums(const std::vector<RegionsVector>& inputRegions)
{
  // A bunch of constants defining how the code works
  // Some now unused - comment to avoid compiler warnings
  //static const unsigned NUMBER_OF_FRWRD_RINGS=4;
  static const unsigned NUMBER_OF_INNER_RINGS=2;
  static const unsigned NUMBER_OF_RINGS_PER_WHEEL=L1CaloRegionDetId::N_ETA/2;
  //static const unsigned MIN_ETA_COUNTS =NUMBER_OF_RINGS_PER_WHEEL - NUMBER_OF_FRWRD_RINGS;
  static const unsigned MIN_ETA_HF_SUMS=NUMBER_OF_RINGS_PER_WHEEL - NUMBER_OF_INNER_RINGS;
  static const unsigned MAX_ETSUM_VALUE = L1GctHfLutSetup::kHfEtSumMaxValue;
  static const unsigned MAX_TOWER_COUNT = L1GctHfLutSetup::kHfCountMaxValue;

  unsigned numOfBx = inputRegions.size();
  m_expectedRing0EtSumPositiveEta.resize(numOfBx);
  m_expectedRing0EtSumNegativeEta.resize(numOfBx);
  m_expectedRing1EtSumPositiveEta.resize(numOfBx);
  m_expectedRing1EtSumNegativeEta.resize(numOfBx);
  m_expectedRing0BitCountPositiveEta.resize(numOfBx);
  m_expectedRing0BitCountNegativeEta.resize(numOfBx);
  m_expectedRing1BitCountPositiveEta.resize(numOfBx);
  m_expectedRing1BitCountNegativeEta.resize(numOfBx);

  for (unsigned bx=0; bx<inputRegions.size(); bx++) {
    std::vector<unsigned> etNegativeEta(NUMBER_OF_INNER_RINGS,0);
    std::vector<unsigned> etPositiveEta(NUMBER_OF_INNER_RINGS,0);
    std::vector<bool>     ofNegativeEta(NUMBER_OF_INNER_RINGS,false);
    std::vector<bool>     ofPositiveEta(NUMBER_OF_INNER_RINGS,false);
    std::vector<unsigned> bcNegativeEta(NUMBER_OF_INNER_RINGS,0);
    std::vector<unsigned> bcPositiveEta(NUMBER_OF_INNER_RINGS,0);
    // Loop over regions, selecting those in the outer ring(s) of the Hf
    for (RegionsVector::const_iterator region=inputRegions.at(bx).begin(); region!=inputRegions.at(bx).end(); region++) {
      if (region->id().rctEta() >= MIN_ETA_HF_SUMS) {
	unsigned ring = NUMBER_OF_RINGS_PER_WHEEL - region->id().rctEta() - 1;
	// Split into positive and negative eta
	if (region->id().ieta() < NUMBER_OF_RINGS_PER_WHEEL) {
	  etNegativeEta.at(ring) += region->et();
	  ofNegativeEta.at(ring) = ofNegativeEta.at(ring) || region->overFlow();
	  if (region->fineGrain()) ++bcNegativeEta.at(ring);
	} else {
	  etPositiveEta.at(ring) += region->et();
	  ofPositiveEta.at(ring) = ofPositiveEta.at(ring) || region->overFlow();
	  if (region->fineGrain()) ++bcPositiveEta.at(ring);
	}
      }
    }
    m_expectedRing0EtSumNegativeEta.at(bx) = ( (etNegativeEta.at(0) > MAX_ETSUM_VALUE) || ofNegativeEta.at(0) ? MAX_ETSUM_VALUE
					      : etNegativeEta.at(0) );
    m_expectedRing0EtSumPositiveEta.at(bx) = ( (etPositiveEta.at(0) > MAX_ETSUM_VALUE) || ofPositiveEta.at(0) ? MAX_ETSUM_VALUE
					      : etPositiveEta.at(0) );
    m_expectedRing1EtSumNegativeEta.at(bx) = ( (etNegativeEta.at(1) > MAX_ETSUM_VALUE) || ofNegativeEta.at(1) ? MAX_ETSUM_VALUE
					      : etNegativeEta.at(1) );
    m_expectedRing1EtSumPositiveEta.at(bx) = ( (etPositiveEta.at(1) > MAX_ETSUM_VALUE) || ofPositiveEta.at(1) ? MAX_ETSUM_VALUE
					      : etPositiveEta.at(1) );
    m_expectedRing0BitCountNegativeEta.at(bx) = bcNegativeEta.at(0);
    m_expectedRing0BitCountPositiveEta.at(bx) = bcPositiveEta.at(0);
    m_expectedRing1BitCountNegativeEta.at(bx) = bcNegativeEta.at(1);
    m_expectedRing1BitCountPositiveEta.at(bx) = bcPositiveEta.at(1);
    if (m_expectedRing0BitCountNegativeEta.at(bx) > MAX_TOWER_COUNT) m_expectedRing0BitCountNegativeEta.at(bx) = MAX_TOWER_COUNT;
    if (m_expectedRing0BitCountPositiveEta.at(bx) > MAX_TOWER_COUNT) m_expectedRing0BitCountPositiveEta.at(bx) = MAX_TOWER_COUNT;
    if (m_expectedRing1BitCountNegativeEta.at(bx) > MAX_TOWER_COUNT) m_expectedRing1BitCountNegativeEta.at(bx) = MAX_TOWER_COUNT;
    if (m_expectedRing1BitCountPositiveEta.at(bx) > MAX_TOWER_COUNT) m_expectedRing1BitCountPositiveEta.at(bx) = MAX_TOWER_COUNT;
  }
}

//=================================================================================================================
//
/// Check the Ht summing algorithms
bool gctTestHfEtSums::checkHfEtSums(const L1GlobalCaloTrigger* gct, const int numOfBx) const
{
  bool testPass = true;

  for (int bx=0; bx<numOfBx; bx++) {
    // Get the jet count bits for this bunch crossing
    std::vector< unsigned > jetCounts=gct->getEnergyFinalStage()->getJetCountValuesColl().at(bx);
    assert (jetCounts.size()==12);

    unsigned bitCountRing0PositiveEta = gct->getHfSumProcessor()->hfSumsOutput(L1GctHfLutSetup::bitCountPosEtaRing1).at(bx);
    unsigned bitCountRing0NegativeEta = gct->getHfSumProcessor()->hfSumsOutput(L1GctHfLutSetup::bitCountNegEtaRing1).at(bx);
    unsigned bitCountRing1PositiveEta = gct->getHfSumProcessor()->hfSumsOutput(L1GctHfLutSetup::bitCountPosEtaRing2).at(bx);
    unsigned bitCountRing1NegativeEta = gct->getHfSumProcessor()->hfSumsOutput(L1GctHfLutSetup::bitCountNegEtaRing2).at(bx);
    unsigned etSumRing0PositiveEta = gct->getHfSumProcessor()->hfSumsOutput(L1GctHfLutSetup::etSumPosEtaRing1).at(bx);
    unsigned etSumRing0NegativeEta = gct->getHfSumProcessor()->hfSumsOutput(L1GctHfLutSetup::etSumNegEtaRing1).at(bx);
    unsigned etSumRing1PositiveEta = gct->getHfSumProcessor()->hfSumsOutput(L1GctHfLutSetup::etSumPosEtaRing2).at(bx);
    unsigned etSumRing1NegativeEta = gct->getHfSumProcessor()->hfSumsOutput(L1GctHfLutSetup::etSumNegEtaRing2).at(bx);

    if (etSumRing0PositiveEta != etSumLut(m_expectedRing0EtSumPositiveEta.at(bx)))
      { cout << "Hf Et Sum Positive Eta, expected " << etSumLut(m_expectedRing0EtSumPositiveEta.at(bx)) 
	     << ", found " << etSumRing0PositiveEta << endl;
      testPass = false; }
    if (etSumRing0NegativeEta != etSumLut(m_expectedRing0EtSumNegativeEta.at(bx)))
      { cout << "Hf Et Sum Negative Eta, expected " << etSumLut(m_expectedRing0EtSumNegativeEta.at(bx)) 
	     << ", found " << etSumRing0NegativeEta << endl;
      testPass = false; }
    if (etSumRing1PositiveEta != etSumLut(m_expectedRing1EtSumPositiveEta.at(bx)))
      { cout << "Hf Et Sum Positive Eta, expected " << etSumLut(m_expectedRing1EtSumPositiveEta.at(bx)) 
	     << ", found " << etSumRing1PositiveEta << endl;
      testPass = false; }
    if (etSumRing1NegativeEta != etSumLut(m_expectedRing1EtSumNegativeEta.at(bx)))
      { cout << "Hf Et Sum Negative Eta, expected " << etSumLut(m_expectedRing1EtSumNegativeEta.at(bx)) 
	     << ", found " << etSumRing1NegativeEta << endl;
      testPass = false; }
    if (bitCountRing0PositiveEta != countLut(m_expectedRing0BitCountPositiveEta.at(bx)))
      { cout << "000Hf Tower Count Positive Eta, expected " << countLut(m_expectedRing0BitCountPositiveEta.at(bx))
	     << ", found " << bitCountRing0PositiveEta << endl;
      testPass = false; }
    if (bitCountRing0NegativeEta != countLut(m_expectedRing0BitCountNegativeEta.at(bx)))
      { cout << "111Hf Tower Count Negative Eta, expected " << countLut(m_expectedRing0BitCountNegativeEta.at(bx))
	     << ", found " << bitCountRing0NegativeEta << endl;
      testPass = false; }
    if (bitCountRing1PositiveEta != countLut(m_expectedRing1BitCountPositiveEta.at(bx)))
      { cout << "222Hf Tower Count Positive Eta, expected " << countLut(m_expectedRing1BitCountPositiveEta.at(bx))
	     << ", found " << bitCountRing1PositiveEta << endl;
      testPass = false; }
    if (bitCountRing1NegativeEta != countLut(m_expectedRing1BitCountNegativeEta.at(bx)))
      { cout << "333Hf Tower Count Negative Eta, expected " << countLut(m_expectedRing1BitCountNegativeEta.at(bx))
	     << ", found " << bitCountRing1NegativeEta << endl;
      testPass = false; }

    // end of loop over bunch crossings
  }
  return testPass;
}

unsigned gctTestHfEtSums::etSumLut (const unsigned expectedValue) const
{
  // Note this assumes a particluar set of LUT thresholds and will
  // have to be re-written if the LUT changes
  static const unsigned maxLut = L1GctHfLutSetup::kHfOutputMaxValue;
  unsigned result = maxLut;
  unsigned compressedEt = expectedValue >> 1;
  if (compressedEt < maxLut) result = compressedEt;
  return result;
}

unsigned gctTestHfEtSums::countLut (const unsigned expectedValue) const
{
  // Note this assumes a particluar set of LUT thresholds and will
  // have to be re-written if the LUT changes
  static const unsigned maxLut = L1GctHfLutSetup::kHfOutputMaxValue;
  unsigned result = maxLut;
  unsigned compressedEt = expectedValue;
  if (compressedEt < maxLut) result = compressedEt;
  return result;
}
