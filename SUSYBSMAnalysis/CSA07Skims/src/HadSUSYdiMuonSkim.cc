/** \class HadSUSYdiMuonSkim
 *
 * all hadronic SUSY Skim
 * >= 2 barrel muons 30 GeV, Pt(2muons)>150
 * Z-Candle, dimuon/Z trigger path
 *
 * $Date: 2007/08/31 14:17:19 $
 * $Revision: 1.3 $
 *
 * \author Michael Tytgat, Maria Spiropulu - CERN
 *
 */

#include <iostream>
#include <string>
#include <list>
#include <cmath>
#include <cstdio>
#include <vector>
#include <memory>

#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "DataFormats/Common/interface/Handle.h"    

#include "SUSYBSMAnalysis/CSA07Skims/interface/HadSUSYdiMuonSkim.h"
#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/MuonReco/interface/MuonFwd.h"

using namespace edm;
using namespace std;
using namespace reco;

class PtSorter {
public:
  template <class T> bool operator() ( const T& a, const T& b ) {
    return ( a.pt() > b.pt() );
  }
};

HadSUSYdiMuonSkim::HadSUSYdiMuonSkim( const edm::ParameterSet& iConfig ) :
  nEvents_(0), nAccepted_(0)
{
  Muonsrc_ = iConfig.getParameter<InputTag>( "Muonsrc" );
  NminMuon_ = iConfig.getParameter<int>( "NminMuon");
  MuonPtmin_ = iConfig.getParameter<double>( "MuonPtmin");
  PtmindiMuon_ = iConfig.getParameter<double>( "PtmindiMuon");
}

/*------------------------------------------------------------------------*/

HadSUSYdiMuonSkim::~HadSUSYdiMuonSkim() 
{}

/*------------------------------------------------------------------------*/

bool HadSUSYdiMuonSkim::filter( edm::Event& iEvent, 
				const edm::EventSetup& iSetup )
{
  nEvents_++;

  Handle<MuonCollection> MuonHandle;
//  try {
    iEvent.getByLabel( Muonsrc_, MuonHandle );
//  }
//  catch ( cms::Exception& ex ) {
//    edm::LogError( "HadSUSYdiMuonSkim" ) 
//      << "Unable to get Muon collection "
//      << Muonsrc_.label();
//    return false;
//  }
  if ( MuonHandle->empty() ) return false;
  MuonCollection TheMuons = *MuonHandle;
  std::stable_sort( TheMuons.begin(), TheMuons.end(), PtSorter() );
  
  int nMuon = 0;
  double Pxdimuon = 0., Pydimuon = 0.;
  for ( MuonCollection::const_iterator it = TheMuons.begin();
	it != TheMuons.end(); it++ ) {
    if ( (it->pt() > MuonPtmin_) 
	 && (fabs(it->eta()) < 3.0) ) {
      if ( nMuon < 2 ) {
	Pxdimuon += it->p()*sin(it->theta())*cos(it->phi());
	Pydimuon += it->p()*sin(it->theta())*sin(it->phi());
      }
      nMuon++;
    }
  }
  
  if ( nMuon < NminMuon_ ) return false;

  double PtdiMuon = sqrt( Pxdimuon*Pxdimuon + Pydimuon*Pydimuon );
  if ( PtdiMuon < PtmindiMuon_ ) return false;
    
  nAccepted_++;

  return true;
}

/*------------------------------------------------------------------------*/

void HadSUSYdiMuonSkim::endJob()
{
  edm::LogVerbatim( "HadSUSYdiMuonSkim" ) 
    << "Events read " << nEvents_
    << " Events accepted " << nAccepted_
    << "\nEfficiency " << (double)(nAccepted_)/(double)(nEvents_) 
    << endl;
}
