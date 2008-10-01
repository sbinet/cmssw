#ifndef L1TauEfficiencyAnalyzer_H
#define L1TauEfficiencyAnalyzer_H

/** \class L1TauEfficiencyAnalyzer
 *
 *
 *  This class is an EDFilter for selecting events
 *  passing chosen HLT bits
 *
 *  \author Sami Lehti  -  HIP Helsinki
 *
 */

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/L1Trigger/interface/L1JetParticle.h"
#include "DataFormats/L1Trigger/interface/L1JetParticleFwd.h"


#include "DataFormats/TauReco/interface/CaloTau.h"
#include "DataFormats/TauReco/interface/PFTau.h"

#include <TTree.h>
#include <TFile.h>

#include <string>

using namespace edm;
using namespace l1extra;
using namespace reco;
using namespace std;

class L1TauEfficiencyAnalyzer : public edm::EDAnalyzer {

    public:
        L1TauEfficiencyAnalyzer();
        explicit L1TauEfficiencyAnalyzer(const edm::ParameterSet&);
        void Setup(const edm::ParameterSet&,TTree *l1tree);
        ~L1TauEfficiencyAnalyzer();

        virtual void analyze(const edm::Event&, const edm::EventSetup&);
        virtual void beginJob(const edm::EventSetup&);
        virtual void endJob();

   private:
	bool L1TauFound(const math::XYZTLorentzVector&);

        // Input parameters
	InputTag L1extraTauJetSource;  
	double   jetMatchingCone;
        std::string rootFile_;   // Output file name

        Handle<L1JetParticleCollection> l1TauHandle;

        int nEvents,
            nSelectedEvents;

        // Output file, tree and related variables
        TFile *l1file;
        TTree *l1tree;

        float jetPt, jetEta, jetPhi;
        int hasL1Jet;
        float PFPt, PFEta, PFPhi;
};
#endif
