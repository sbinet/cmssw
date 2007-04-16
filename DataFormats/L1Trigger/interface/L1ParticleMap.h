#ifndef L1Trigger_L1ParticleMap_h
#define L1Trigger_L1ParticleMap_h
// -*- C++ -*-
//
// Package:     L1Trigger
// Class  :     L1ParticleMap
// 
/**\class L1ParticleMap \file L1ParticleMap.h DataFormats/L1Trigger/interface/L1ParticleMap.h \author Werner Sun

 Description: L1Extra class for map between triggers and L1Extra particles.
*/
//
// Original Author:  Werner Sun
//         Created:  Fri Jul 14 19:46:30 EDT 2006
// $Id: L1ParticleMap.h,v 1.13 2007/04/13 17:50:46 wsun Exp $
// $Log: L1ParticleMap.h,v $
// Revision 1.13  2007/04/13 17:50:46  wsun
// New trigger table for HLT exercise.
//
// Revision 1.12  2007/04/02 08:03:13  wsun
// Updated Doxygen documentation.
//
// Revision 1.11  2006/08/31 10:23:32  wsun
// Added MinBias trigger.
//
// Revision 1.10  2006/08/28 03:10:40  wsun
// Revamped L1ParticleMap to handle OR triggers.
//
// Revision 1.9  2006/08/23 23:09:04  wsun
// Separated iso/non-iso EM triggers and RefVectors.
//
// Revision 1.8  2006/08/10 18:47:41  wsun
// Removed L1PhysObjectBase; particle classes now derived from LeafCandidate.
//
// Revision 1.7  2006/08/06 15:32:26  wsun
// Added comment.
//
// Revision 1.6  2006/08/04 03:30:47  wsun
// Separated tau/jet bookkeeping, added static function objectTypeIsGlobal().
//
// Revision 1.5  2006/08/02 20:48:55  wsun
// Added more trigger lines, added mapping for global objects.
//
// Revision 1.4  2006/08/02 14:21:33  wsun
// Added trigger name dictionary, moved particle type enum to L1ParticleMap.
//
// Revision 1.3  2006/07/26 20:41:30  wsun
// Added implementation of L1ParticleMap.
//
// Revision 1.2  2006/07/26 00:05:39  wsun
// Structural mods for HLT use.
//
// Revision 1.1  2006/07/17 20:35:19  wsun
// First draft.
//
//

// system include files
#include <string>

// user include files
#include "DataFormats/L1Trigger/interface/L1EmParticle.h"
#include "DataFormats/L1Trigger/interface/L1JetParticle.h"
#include "DataFormats/L1Trigger/interface/L1MuonParticle.h"
#include "DataFormats/L1Trigger/interface/L1EtMissParticle.h"
#include "DataFormats/L1Trigger/interface/L1ParticleMapFwd.h"

// forward declarations

namespace l1extra {

   class L1ParticleMap
   {

      public:
         enum L1ObjectType
	 {
            kEM,   // = isolated or non-isolated
            kJet,  // = central, forward, or tau
            kMuon,
	    kEtMiss,
	    kEtTotal,
	    kEtHad,
            kNumOfL1ObjectTypes
	 } ;

	 // For now, use trigger menu from PTDR:
	 // http://monicava.web.cern.ch/monicava/hlt_rates.htm#l1bits

	 // RelaxedEM = isolated OR non-isolated
	 // Jet = central OR forward OR tau

	 enum L1TriggerType
	 {
	    kSingleMu3,
	    kSingleMu10,
	    kSingleMu14,
	    kSingleMu20,
	    kSingleMu25,
	    kSingleIsoEG5,
	    kSingleIsoEG10,
	    kSingleIsoEG15,
	    kSingleIsoEG20,
	    kSingleIsoEG25,
	    kSingleEG5,
	    kSingleEG10,
	    kSingleEG15,
	    kSingleEG20,
	    kSingleEG25,
	    kSingleJet20,
	    kSingleJet60,
	    kSingleJet100,
	    kSingleJet140,
	    kSingleJet180,
	    kSingleTauJet20,
	    kSingleTauJet60,
	    kSingleTauJet100,
	    kSingleTauJet140,
	    kSingleTauJet180,
	    kHTT100,
	    kHTT200,
	    kHTT300,
	    kHTT400,
	    kHTT500,
	    kETM20,
	    kETM40,
	    kETM60,
	    kETM80,
	    kETM100,
	    kDoubleMu7,
	    kDoubleIsoEG10,
	    kDoubleEG20,
	    kDoubleJet100,
	    kDoubleTauJet50,
	    kMu7_IsoEG15,
	    kMu7_EG15,
	    kMu7_Jet100,
	    kMu7_TauJet50,
	    kIsoEG10_EG10,
	    kIsoEG15_Jet100,
	    kIsoEG15_TauJet50,
	    kEG15_Jet100,
	    kEG15_TauJet50,
	    kJet100_TauJet50,
	    kMu7_HTT300,
	    kIsoEG15_HTT300,
	    kEG15_HTT300,
	    kJet100_HTT300,
	    kTauJet50_HTT300,
	    kMu7_ETM30,
	    kIsoEG15_ETM30,
	    kEG15_ETM30,
	    kJet100_ETM40,
	    kTauJet50_ETM40,
	    kHTT200_ETM40,
	    kTripleMu7,
	    kTripleIsoEG5,
	    kTripleEG10,
	    kTripleJet70,
	    kTripleTauJet50,
	    kDoubleMu7_IsoEG5,
	    kDoubleMu7_EG5,
	    kDoubleIsoEG5_Mu7,
	    kDoubleEG5_Mu7,
	    kDoubleMu7_HTT150,
	    kDoubleIsoEG5_HTT150,
	    kDoubleEG5_HTT150,
	    kDoubleJet50_HTT150,
	    kDoubleTauJet50_HTT150,
	    kDoubleMu7_ETM15,
	    kDoubleIsoEG5_ETM15,
	    kDoubleEG5_ETM15,
	    kDoubleJet50_ETM15,
	    kDoubleTauJet50_ETM15,
	    kQuadJet50,
	    kMinBias_HTT10,
	    kZeroBias,
	    kNumOfL1TriggerTypes
	 } ;

	 typedef std::vector< unsigned int > L1IndexCombo ;
	 typedef std::vector< L1IndexCombo > L1IndexComboVector ;
	 typedef std::vector< L1ObjectType > L1ObjectTypeVector ;

	 L1ParticleMap();
	 L1ParticleMap(
	    L1TriggerType triggerType,
	    bool triggerDecision,
	    const L1ObjectTypeVector& objectTypes,
	    const L1EmParticleVectorRef& emParticles =
	    L1EmParticleVectorRef(),
	    const L1JetParticleVectorRef& jetParticles =
	    L1JetParticleVectorRef(),
	    const L1MuonParticleVectorRef& muonParticles =
	       L1MuonParticleVectorRef(),
	    const L1EtMissParticleRefProd& etMissParticle =
	       L1EtMissParticleRefProd(),
	    const L1IndexComboVector& indexCombos =
	       L1IndexComboVector()
	    ) ;

	 virtual ~L1ParticleMap();

	 // ---------- const member functions ---------------------
	 L1TriggerType triggerType() const
	 { return triggerType_ ; }

	 const std::string& triggerName() const
	 { return triggerName( triggerType_ ) ; }

	 bool triggerDecision() const
	 { return triggerDecision_ ; }

	 // Indices of object types (see the above enum), that participated
	 // in this trigger.  The order of these type indices corresponds to
	 // the particles listed in each L1IndexCombo.
	 const L1ObjectTypeVector& objectTypes() const
	 { return objectTypes_ ; }

	 // Number of objects that participated in this trigger.
	 int numOfObjects() const
	 { return objectTypes_.size() ; }

	 const L1EmParticleVectorRef& emParticles() const
	 { return emParticles_ ; }

	 const L1JetParticleVectorRef& jetParticles() const
	 { return jetParticles_ ; }

	 const L1MuonParticleVectorRef& muonParticles() const
	 { return muonParticles_ ; }

	 const L1EtMissParticleRefProd& etMissParticle() const
	 { return etMissParticle_ ; }

	 // If there are zero or one non-global objects, then there is no need
	 // to store the object combinations.  In this case, the stored
	 // vector m_objectCombinations will be empty, and it will be
	 // filled upon request at analysis time.
	 const L1IndexComboVector& indexCombos() const ;

	 // These functions retrieve the object corresponding to a
	 // particular entry in a given combination.  The pointer is null
	 // if an error occurs (e.g. the particle requested does not match
	 // the type of the function).
	 const reco::LeafCandidate* candidateInCombo(
	    int aIndexInCombo, const L1IndexCombo& aCombo ) const ;

	 const L1EmParticle* emParticleInCombo(
	    int aIndexInCombo, const L1IndexCombo& aCombo ) const ;

	 const L1JetParticle* jetParticleInCombo(
	    int aIndexInCombo, const L1IndexCombo& aCombo ) const ;

	 const L1MuonParticle* muonParticleInCombo(
	    int aIndexInCombo, const L1IndexCombo& aCombo ) const ;

	 // This function just returns the single global object.
	 const L1EtMissParticle* etMissParticleInCombo(
	    int aIndexInCombo, const L1IndexCombo& aCombo ) const ;

	 // For a given particle combination, convert all the particles to
	 // reco::LeafCandidate pointers.
	 std::vector< const reco::LeafCandidate* > candidateCombo(
	    const L1IndexCombo& aCombo ) const ;

	 // ---------- static member functions --------------------
	 static const std::string& triggerName( L1TriggerType type ) ;
	 static L1TriggerType triggerType( const std::string& name ) ;
	 static bool objectTypeIsGlobal( L1ObjectType type ) ;

	 // ---------- member functions ---------------------------

      private:
	 // L1ParticleMap(const L1ParticleMap&); // stop default

	 // const L1ParticleMap& operator=(const L1ParticleMap&); // stop default

	 // ---------- member data --------------------------------

	 // Index into trigger menu.
	 L1TriggerType triggerType_ ;

	 bool triggerDecision_ ;

	 // Vector of length numOfObjects() that gives the
	 // type of each trigger object.
	 L1ObjectTypeVector objectTypes_ ;

	 // Lists of particles that fired this trigger, perhaps in combination
	 // with another particle.
	 L1EmParticleVectorRef emParticles_ ;
	 L1JetParticleVectorRef jetParticles_ ;
	 L1MuonParticleVectorRef muonParticles_ ;

	 // Global (event-wide) objects.  The Ref is null if the object
	 // was not used in this trigger.
	 L1EtMissParticleRefProd etMissParticle_ ;

	 // Object combinations that fired this trigger.  The inner
	 // vector< int > has length numOfObjects() and contains
	 // references to the elements in emParticles_, jetParticles_, and
	 // muonParticles_ for a successful combination.  A dummy index is
	 // entered for each global object in the trigger.  The object type
	 // of each entry is given by objectTypes_.
	 //
	 // This data member is mutable because if #particles = 1, then this
	 // vector is empty and is filled on request.
	 mutable L1IndexComboVector indexCombos_ ;

	 // Static array of trigger names.
	 static std::string triggerNames_[ kNumOfL1TriggerTypes ] ;
   };

}

#endif
