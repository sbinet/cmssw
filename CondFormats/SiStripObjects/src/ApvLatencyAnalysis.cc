#include "CondFormats/SiStripObjects/interface/ApvLatencyAnalysis.h"
#include "DataFormats/SiStripCommon/interface/SiStripHistoTitle.h"
#include "DataFormats/SiStripCommon/interface/SiStripEnumsAndStrings.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "TProfile.h"
#include <iostream>
#include <cmath>

using namespace sistrip;

// ----------------------------------------------------------------------------
// 
ApvLatencyAnalysis::ApvLatencyAnalysis( const uint32_t& key ) 
  : CommissioningAnalysis(key,"ApvLatencyAnalysis"),
    latency_(sistrip::invalid_),
    histo_(0,"")
{;}

// ----------------------------------------------------------------------------
// 
ApvLatencyAnalysis::ApvLatencyAnalysis() 
  : CommissioningAnalysis("ApvLatencyAnalysis"),
    latency_(sistrip::invalid_),
    histo_(0,"")
{;}

// ----------------------------------------------------------------------------
// 
void ApvLatencyAnalysis::print( std::stringstream& ss, uint32_t not_used ) { 
  header( ss );
  ss << " APV latency setting : " << latency_ << "\n";
}

// ----------------------------------------------------------------------------
// 
void ApvLatencyAnalysis::reset() {
  latency_ = sistrip::invalid_; 
  histo_ = Histo(0,"");
}

// ----------------------------------------------------------------------------
// 
void ApvLatencyAnalysis::extract( const std::vector<TH1*>& histos ) { 
  
  // Check
  if ( histos.size() != 1 ) {
    edm::LogWarning(mlCommissioning_) 
      << "[" << myName() << "::" << __func__ << "]"
      << " Unexpected number of histograms: " 
      << histos.size();
  }
  
  // Extract FED key from histo title
  if ( !histos.empty() ) extractFedKey( histos.front() );

  // Extract
  std::vector<TH1*>::const_iterator ihis = histos.begin();
  for ( ; ihis != histos.end(); ihis++ ) {
    
    // Check pointer
    if ( !(*ihis) ) {
      edm::LogWarning(mlCommissioning_) 
	<< "[" << myName() << "::" << __func__ << "]"
	<< " NULL pointer to histogram!";
      continue;
    }
    
    // Check name
    SiStripHistoTitle title( (*ihis)->GetName() );
    if ( title.runType() != sistrip::APV_LATENCY ) {
      edm::LogWarning(mlCommissioning_) 
	<< "[" << myName() << "::" << __func__ << "]"
	<< " Unexpected commissioning task: "
	<< SiStripEnumsAndStrings::runType(title.runType());
      continue;
    }
    
    // Extract timing histo
    histo_.first = *ihis;
    histo_.second = (*ihis)->GetName();
    
  }
  
}

// ----------------------------------------------------------------------------
// 
void ApvLatencyAnalysis::analyse() { 
  deprecated(); //@@ use matt's method...
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
//
void ApvLatencyAnalysis::deprecated() {
  
  std::vector<const TProfile*> histos; 
  std::vector<unsigned short> monitorables;
    
  histos.clear();
  histos.push_back( const_cast<const TProfile*>( dynamic_cast<TProfile*>(histo_.first) ) );
  if ( !histos[0] ) {
    edm::LogWarning(mlCommissioning_) 
      << "[" << myName() << "::" << __func__ << "]"
      << " NULL pointer to latency histo!";
    return;
  }
  
  monitorables.clear();
  analysis( histos, monitorables );
  latency_ = monitorables[0];
  
}

// -----------------------------------------------------------------------------
//
void ApvLatencyAnalysis::analysis( const std::vector<const TProfile*>& histos, 
				   std::vector<unsigned short>& monitorables ) {
  //LogDebug("Commissioning|Analysis") << "[ApvLatencyAnalysis::analysis]";

    //extract root histogram
    //check 
  if (histos.size() != 1) { 
//     edm::LogWarning("Commissioning|Analysis") << "[ApvLatencyAnalysis::analysis]: Requires \"const std::vector<const TH1F*>& \" argument to have size 1. Actual size: " << histos.size() << ". Monitorables set to 0."; 
    monitorables.push_back(0);
    return; 
  }
  const TProfile* histo = histos[0];

  //monitorable
  unsigned short latency;

 std::vector<unsigned short> binContent; binContent.reserve((unsigned short)histo->GetNbinsX()); binContent.resize((unsigned short)histo->GetNbinsX(), 0);

 for (unsigned short k = 0; k < (unsigned short)histo->GetNbinsX(); k++) { // k is bin number

//fill std::vector with histogram contents
    binContent.push_back((unsigned int)(histo->GetBinContent(k)));}

 //calculate median
  
 sort(binContent.begin(), binContent.end());
 
 //calculate mean and mean2 of the readout within cutoffs
 
 float meanNoise = 0.;//M.W method
 float mean2Noise = 0.;
 
 for (unsigned short k = (unsigned short)(binContent.size()*.1); k < (unsigned short)(binContent.size()*.9); k++) {
   meanNoise += binContent[k];
   mean2Noise += binContent[k]*binContent[k];;
 }
 
 meanNoise = meanNoise * binContent.size() * 0.8;
 mean2Noise = mean2Noise * binContent.size() * 0.8;
 float sigmaNoise = sqrt(fabs(meanNoise*meanNoise - mean2Noise));
 
 //loop to look for signal > 5* sigma_noise
 unsigned short count = 0;
 unsigned short maxlatency = 0;
 unsigned int maxhits = 0;
 
 for (unsigned short k = 1; k < ((unsigned short)histo->GetNbinsX() + 1); k++) { // k is bin number
   if (histo->GetBinContent((Int_t)k) > maxhits) maxlatency = k - 1;
   if ((float)histo->GetBinContent((Int_t)k) > (meanNoise + 5 * sigmaNoise)) { 
     latency = k - 1; count++;
   }
 }
 
 if (!count) {
 //   LogDebug("Commissioning|Analysis") << "[ApvLatencyAnalysis::analysis]: Warning: no signal found > mean + 5*sigma(noise). Returning latency of highest number of recorded hits.";
   latency = maxlatency;
 }
 
 if (count > 1) {
//    LogDebug("Commissioning|Analysis") << "[ApvLatencyAnalysis::analysis]: Warning: more than one signal found > mean + 5*sigma(noise). Returning latency of highest number of recorded hits.";
   latency = maxlatency;
 }

 //set monitorables
 monitorables.clear();
 monitorables.push_back(latency);
}
