// -*- C++ -*-
//
// Package:    SiStripElectronAssociator
// Class:      SiStripElectronAssociator
// 
/**\class SiStripElectronAssociator SiStripElectronAssociator.cc RecoEgamma/SiStripElectronAssociator/src/SiStripElectronAssociator.cc

 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  Jim Pivarski
//         Created:  Tue Aug  1 15:24:02 EDT 2006
// $Id: SiStripElectronAssociator.cc,v 1.4 2007/08/28 01:42:29 ratnik Exp $
//
//


#include <map>
#include <sstream>

#include "SiStripElectronAssociator.h"

#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "DataFormats/EgammaCandidates/interface/SiStripElectronFwd.h"
#include "DataFormats/EgammaCandidates/interface/SiStripElectron.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/EgammaCandidates/interface/Electron.h"
#include "DataFormats/EgammaCandidates/interface/ElectronFwd.h"

#include "DataFormats/DetId/interface/DetId.h"
#include "FWCore/Utilities/interface/Exception.h"
#include "DataFormats/GeometryVector/interface/LocalPoint.h"
#include "DataFormats/TrackingRecHit/interface/TrackingRecHit.h"
#include "DataFormats/Math/interface/LorentzVector.h"
#include "DataFormats/Math/interface/Point3D.h"
#include "DataFormats/TrackerRecHit2D/interface/SiStripRecHit2DCollection.h"

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
SiStripElectronAssociator::SiStripElectronAssociator(const edm::ParameterSet& iConfig)
{
   //register your products
  electronsLabel_ = iConfig.getParameter<std::string>("electronsLabel");
  produces<reco::ElectronCollection>(electronsLabel_);

   //now do what ever other initialization is needed
   siStripElectronProducer_ = iConfig.getParameter<std::string>("siStripElectronProducer");
   siStripElectronCollection_ = iConfig.getParameter<std::string>("siStripElectronCollection");
   trackProducer_ = iConfig.getParameter<std::string>("trackProducer");
   trackCollection_ = iConfig.getParameter<std::string>("trackCollection");
}


SiStripElectronAssociator::~SiStripElectronAssociator()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called to produce the data  ------------
void
SiStripElectronAssociator::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{

  // position tolerance for equality of 2 hits set to 10 microns
  static const double positionTol = 1e-3 ; 

   edm::Handle<reco::SiStripElectronCollection> siStripElectrons;
   iEvent.getByLabel(siStripElectronProducer_, siStripElectronCollection_, siStripElectrons);

   edm::Handle<reco::TrackCollection> tracks;
   iEvent.getByLabel(trackProducer_, trackCollection_, tracks);

   std::map<const reco::SiStripElectron*, bool> alreadySeen;
   for (reco::SiStripElectronCollection::const_iterator strippyIter = siStripElectrons->begin();  strippyIter != siStripElectrons->end();  ++strippyIter) {
      alreadySeen[&(*strippyIter)] = false;
   }

   // Output the high-level Electrons
   std::auto_ptr<reco::ElectronCollection> output(new reco::ElectronCollection);

   LogDebug("") << " About to loop over tracks " << std::endl ;
   LogDebug("") << " Number of tracks in Associator " << tracks.product()->size() ;
   LogDebug("") << " Number of SiStripElectron Candidates " << siStripElectrons->size();

   // The reco::Track's hits are a (improper?) subset of the reco::SiStripElectron's
   // countSiElFit counts electron candidates that return w/ a good track fit
   int countSiElFit = 0 ;
   for (unsigned int i = 0;  i < tracks.product()->size();  i++) {
      const reco::Track* trackPtr = &(*reco::TrackRef(tracks, i));
      
      std::ostringstream debugstr;
   
      // If the reco::Track and the reco::SiStripElectron share even
      // one hit in common, they belong to each other.  (Disjoint sets
      // of hits are assigned to electrons.)  So let's look at one hit.

      // But first, make sure the track's hit list is not empty.
      if (trackPtr->recHitsBegin() == trackPtr->recHitsEnd()) { continue; }



      // Detector id is not enough to completely specify a hit
      uint32_t id = (*trackPtr->recHitsBegin())->geographicalId().rawId();
      LocalPoint pos = (*trackPtr->recHitsBegin())->localPosition();
      
      debugstr << " New Track Candidate " << i
	       << " DetId " << id
	       << " pos " << pos << "\n" ;

      // Find the electron with that hit!
      bool foundElectron = false;
      for (reco::SiStripElectronCollection::const_iterator strippyIter = siStripElectrons->begin();  strippyIter != siStripElectrons->end();  ++strippyIter) {
	 if (!alreadySeen[&(*strippyIter)]) {

	 

	    bool hitInCommon = false;

	    debugstr << " Looping over Mono hits " << "\n" ;

	    for (std::vector<SiStripRecHit2D>::const_iterator hitIter = strippyIter->rphiRecHits().begin();  hitIter != strippyIter->rphiRecHits().end();  ++hitIter) {

	      debugstr << " SiStripCand " 
		       << " DetId " << hitIter->geographicalId().rawId()
		       << " localPos " << hitIter->localPosition()
		       << " deltasPos " << (hitIter->localPosition() - pos).mag() ;

		if (hitIter->geographicalId().rawId() == id   &&
		    (hitIter->localPosition() - pos).mag() < positionTol ) {
		  hitInCommon = true;
		  debugstr << " hitInCommon True " << "\n" ;
		    break;
		} else {
		  debugstr << " hitInCommon False " << "\n" ;
		    }
	    } // end loop over rphi hits


	    if(!hitInCommon) {
	      debugstr << " Looping over Stereo hits " << "\n" ;

	      for (std::vector<SiStripRecHit2D>::const_iterator hitIter = strippyIter->stereoRecHits().begin();  hitIter != strippyIter->stereoRecHits().end();  ++hitIter) {
		
		debugstr << " SiStripCand " 
			 << " DetId " << hitIter->geographicalId().rawId()
			 << " localPos " << hitIter->localPosition()
			 << " deltasPos " << (hitIter->localPosition() - pos).mag() ;
 		
		if (hitIter->geographicalId().rawId() == id   &&
		    (hitIter->localPosition() - pos).mag() < positionTol) {
		  hitInCommon = true;
		  debugstr << " hitInCommon True " << "\n"  ;
		  break;
		} else {
		  debugstr << " hitInCommon False " << "\n" ;
		}
		
	      } // end loop over stereo hits
	    } // end of hitInCommon check for loop over stereo hits

	    if (hitInCommon) {
	      debugstr << " Hit in Common Found \n" ;
 	      ++countSiElFit ;
	       foundElectron = true;
	       alreadySeen[&(*strippyIter)] = true;

	       reco::Electron electron((trackPtr->charge() > 0 ? 1 : -1),
				       math::XYZTLorentzVector(trackPtr->px(),
							       trackPtr->py(),
							       trackPtr->pz(),
							       trackPtr->p()),
				       math::XYZPoint(trackPtr->vx(),
						      trackPtr->vy(),
						      trackPtr->vz()));
	       electron.setSuperCluster(strippyIter->superCluster());
	       electron.setTrack(reco::TrackRef(tracks, i));
	       
	       output->push_back(electron);
	       break ; // no need to check other SiStripElectrons if this one is good 

	    } else {

	      debugstr << "Hit in Common NOT found \n"  ;

	    }
	    // endif this electron belongs to this track


	 } // endif we haven't seen this electron before
	 debugstr << "Done with this electron " << "\n\n\n";
      } // end loop over electrons

      LogDebug("") << debugstr.str() << std::endl ;
      LogDebug("") << "Testing if foundElectron " << foundElectron << std::endl ;

      if (!foundElectron) {
	edm::LogError("SIStripElectron")
	  //	 throw cms::Exception("InconsistentData")
	   << " It is possible that the trackcollection used '"
	   << trackCollection_ << "' from producer '" << trackProducer_
	   << "' is not consistent with '"<< siStripElectronCollection_ 
	   << "' from the producer '"<< siStripElectronProducer_
	   << "' --- Please check your cfg file " << "\n"
	   << " OR Hit Position don't match " 
	  //	   << "\n" << std::endl
	  ;
      }

      LogDebug("") << "At end of track loop \n" << std::endl; 

   } // end loop over tracks


   LogDebug("") << " Number of SiStripElectrons returned with a good fit " 
                     << countSiElFit << "\n"<<  std::endl ;

   iEvent.put(output,electronsLabel_);
}
