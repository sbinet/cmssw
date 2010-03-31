#include "TauAnalysis/Core/plugins/CompositePtrCandidateT1T2MEtHistManager.h"

#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/ServiceRegistry/interface/Service.h"

#include "AnalysisDataFormats/TauAnalysis/interface/CompositePtrCandidateT1T2MEt.h"
#include "AnalysisDataFormats/TauAnalysis/interface/CompositePtrCandidateT1T2MEtFwd.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/Common/interface/AssociationVector.h"
#include "DataFormats/PatCandidates/interface/MET.h"

#include "TauAnalysis/Core/interface/histManagerAuxFunctions.h"

#include <TMath.h>

const double epsilon = 0.01;
const double speedOfLight = 3.e+10; // speed of light [cm/s]
const double tauLeptonMass = 1.78; // tau lepton mass [GeV]

template<typename T1, typename T2>
bool matchesGenCandidatePair(const CompositePtrCandidateT1T2MEt<T1,T2>& compositePtrCandidate)
{
  bool isGenMatched = false;
// not implemented yet...
  return isGenMatched;
}

//
//-----------------------------------------------------------------------------------------------------------------------
//

template<typename T1, typename T2>
CompositePtrCandidateT1T2MEtHistManager<T1,T2>::CompositePtrCandidateT1T2MEtHistManager(const edm::ParameterSet& cfg)
  : HistManagerBase(cfg)
{
  //std::cout << "<CompositePtrCandidateT1T2MEtHistManager::CompositePtrCandidateT1T2MEtHistManager>:" << std::endl;

  diTauCandidateSrc_ = cfg.getParameter<edm::InputTag>("diTauCandidateSource");
  //std::cout << " diTauCandidateSrc = " << diTauCandidateSrc_ << std::endl;

  vertexSrc_ = cfg.getParameter<edm::InputTag>("vertexSource");
  //std::cout << " vertexSrc = " << vertexSrc_ << std::endl;

  visMassHypothesisSrc_ = ( cfg.exists("visMassHypothesisSource") ) ?  
    cfg.getParameter<edm::InputTag>("visMassHypothesisSource") : edm::InputTag();
  //std::cout << " visMassHypothesisSrc = " << visMassHypothesisSrc_ << std::endl;

  diTauLeg1WeightExtractors_ = getTauJetWeightExtractors<T1>(cfg, "diTauLeg1WeightSource");
  diTauLeg2WeightExtractors_ = getTauJetWeightExtractors<T2>(cfg, "diTauLeg2WeightSource");
  
  requireGenMatch_ = cfg.getParameter<bool>("requireGenMatch");
  //std::cout << " requireGenMatch = " << requireGenMatch_ << std::endl;

  std::string normalization_string = cfg.getParameter<std::string>("normalization");
  normMethod_ = getNormMethod(normalization_string, "diTauCandidates");
}

template<typename T1, typename T2>
CompositePtrCandidateT1T2MEtHistManager<T1,T2>::~CompositePtrCandidateT1T2MEtHistManager()
{
  for ( typename std::vector<FakeRateJetWeightExtractor<T1>*>::iterator it = diTauLeg1WeightExtractors_.begin();
	it != diTauLeg1WeightExtractors_.end(); ++it ) {
    delete (*it);
  }

  for ( typename std::vector<FakeRateJetWeightExtractor<T2>*>::iterator it = diTauLeg2WeightExtractors_.begin();
	it != diTauLeg2WeightExtractors_.end(); ++it ) {
    delete (*it);
  }
}

template<typename T1, typename T2>
void CompositePtrCandidateT1T2MEtHistManager<T1,T2>::bookHistogramsImp()
{
  //std::cout << "<CompositePtrCandidateT1T2MEtHistManager::bookHistogramsImp>:" << std::endl;

  hGenDiTauCandidatePt_ = book1D("GenDiTauCandidatePt", "gen. Composite P_{T}", 75, 0., 150.);
  
  hGenLeg1PtVsLeg2Pt_ = book2D("GenLeg1PtVsLeg2Pt", "gen. leg_{1} P_{T} vs. leg_{2} P_{T}", 20, 0., 100., 20, 0., 100.);
  hGenLeg1EtaVsLeg2Eta_ = book2D("GenLeg1EtaVsLeg2Eta", "gen. leg_{1} #eta vs. leg_{2} #eta", 20, -2.5, 2.5, 20, -2.5, 2.5);
  hGenLeg1DecayTime_ = book1D("GenLeg1DecayTime", "gen. leg_{1} Decay eigentime", 100, 0., 1000.);
  hGenLeg2DecayTime_ = book1D("GenLeg2DecayTime", "gen. leg_{2} Decay eigentime", 100, 0., 1000.);

  hDiTauCandidatePt_ = book1D("DiTauCandidatePt", "Composite P_{T}", 75, 0., 150.);
  hDiTauCandidateEta_ = book1D("DiTauCandidateEta", "Composite #eta", 100, -5., +5.);
  hDiTauCandidatePhi_ = book1D("DiTauCandidatePhi", "Composite #phi", 36, -TMath::Pi(), +TMath::Pi());
  hDiTauCandidateCharge_ = book1D("DiTauCandidateCharge", "Composite Charge", 11, -5.5, +5.5);
  hDiTauCandidateMass_ = book1D("DiTauCandidateMass", "Composite Invariant Mass", 50, 0., 250.);

  hSVfitMass_ = book1D("SVfitMass", "SVfit Mass", 50, 0., 250.);
  hSVfitMassBestMatch_ = book1D("SVfitMassBestMatch", "SVfit Mass best matching gen. Mass", 50, 0., 250.);
  hSVfitMassVsLogLikelihood_ = book2D("SVfitMassVsLogLikelihood", "SVfit Mass vs. log-Likelihood", 20, -35., 25., 50, 0., 250.);
  hSVfitLogLikelihood_ = book1D("SVfitLogLikelihood", "SVfit log-Likelihood", 100, -50., 50.);
  hSVfitDecayTimeLeg1_ = book1D("SVfitDecayTimeLeg1", "SVfit leg_{1} Decay eigentime", 100, 0., 1000.);
  hSVfitDecayTimeLeg2_ = book1D("SVfitDecayTimeLeg2", "SVfit leg_{2} Decay eigentime", 100, 0., 1000.);
  hSVfitStatus_ = book1D("SVfitStatus", "SVfit Status", 10, -2.5, 7.5);
  
  hLeg1PtVsLeg2Pt_ = book2D("Leg1PtVsLeg2Pt", "leg_{1} P_{T} vs. leg_{2} P_{T}", 20, 0., 100., 20, 0., 100.);
  hLeg1EtaVsLeg2Eta_ = book2D("Leg1EtaVsLeg2Eta", "leg_{1} #eta vs. leg_{2} #eta", 20, -2.5, 2.5, 20, -2.5, 2.5);
  
  bookWeightHistograms(*dqmStore_, "DiTauCandidateWeight", "Composite Weight", 
		       hDiTauCandidateWeightPosLog_, hDiTauCandidateWeightNegLog_, hDiTauCandidateWeightZero_, 
		       hDiTauCandidateWeightLinear_);

  hDiTauCandidateImpParSig_ = book1D("DiTauCandidateImpParSig", "#sqrt{#frac{dxy_{1}}{#Delta dxy_{1}}^{2}+#frac{dxy_{2}}{#Delta dxy_{2}}^{2}}", 30, 0., 15.);
  
  hVisPt_ = book1D("VisPt", "Visible P_{T}", 50, 0., 100.);
  hVisPhi_ = book1D("VisPhi", "Visible #phi", 36, -TMath::Pi(), +TMath::Pi());
  hVisMass_ = book1D("VisMass", "Visible Mass", 40, 0., 200.);
  hVisMassZllCombinedHypothesis_ = ( visMassHypothesisSrc_.label() != "" ) ?
    book1D("VisMassZllCombinedHypothesis", "Visible Mass (combined Value of different Event Hypotheses)", 40, 0., 200.) : 0;
  
  hCollinearApproxEta_ = book1D("CollinearApproxEta", "Collinear Approximation #eta", 100, -5., +5.);
  hCollinearApproxMass_ = book1D("CollinearApproxMass", "Collinear Approximation Mass", 50, 0., 250.);
  hCollinearApproxX1_ = book1D("CollinearApproxX1", "Collinear Approximation X_{1}", 100, -2.5, +2.5);
  hCollinearApproxX2_ = book1D("CollinearApproxX2", "Collinear Approximation X_{2}", 100, -2.5, +2.5);

  hCDFmethodMass_ = book1D("CDFmethodMass", "CDF Method Mass", 50, 0., 250.);
  
  hMt12MET_ = book1D("Mt12MET", "Mass_{T 1,2,MET}", 50, 0., 250.);
  
  hMt1MET_ = book1D("Mt1MET", "Mass_{T 1,MET}", 40, 0., 200.);
  hMt2MET_ = book1D("Mt2MET", "Mass_{T 2,MET}", 40, 0., 200.);
  
  hDPhi12_ = book1D("DPhi12", "#Delta#phi_{1,2}", 36, -epsilon, TMath::Pi() + epsilon);
  hDR12_ = book1D("DR12", "#Delta R_{1,2}", 51, -0.1, 10.1);
  
  hVisEtaMin_ = book1D("VisEtaMin", "VisEtaMin", 60, -3., +3.);
  hVisEtaMax_ = book1D("VisEtaMax", "VisEtaMax", 60, -3., +3.);
  
  hDPhi1MET_ = book1D("DPhi1MET", "#Delta#phi_{1,MET}", 36, -epsilon, TMath::Pi() + epsilon);
  hDPhi2MET_ = book1D("DPhi2MET", "#Delta#phi_{2,MET}", 36, -epsilon, TMath::Pi() + epsilon);
  hDPhi1METvsDPhi2MET_ = book2D("DPhi1METvsDPhi2MET", "#Delta#phi_{1,MET} vs. #Delta#phi_{2,MET}", 18, -epsilon, TMath::Pi() + epsilon, 18, -epsilon, TMath::Pi() + epsilon); 

  hPzetaCorr_ = book2D("PzetaCorr", "P_{#zeta} vs. P_{#zeta}^{vis}", 10, 0., 50., 14, -20., 50.);
  hPzetaDiff_ = book1D("PzetaDiff", "P_{#zeta} - 1.5*P_{#zeta}^{vis}", 40, -100., +100.);
}

template<typename T1, typename T2>
double CompositePtrCandidateT1T2MEtHistManager<T1,T2>::getDiTauCandidateWeight(const CompositePtrCandidateT1T2MEt<T1,T2>& diTauCandidate)
{
  double diTauLeg1Weight = getTauJetWeight<T1>(*diTauCandidate.leg1(), diTauLeg1WeightExtractors_);
  double diTauLeg2Weight = getTauJetWeight<T2>(*diTauCandidate.leg2(), diTauLeg2WeightExtractors_);
  return (diTauLeg1Weight*diTauLeg2Weight);
}

double compDecayEigenTime(const reco::Candidate::Point& primaryVertexPos, const reco::Candidate::Point& decayVertexPos, 
			  double tauLeptonEnergy)
{
  double decayDistance = TMath::Sqrt((decayVertexPos - primaryVertexPos).Mag2());
  double gamma = tauLeptonEnergy/tauLeptonMass;
  return decayDistance/(speedOfLight*gamma);
}

template<typename T1, typename T2>
void CompositePtrCandidateT1T2MEtHistManager<T1,T2>::fillHistogramsImp(const edm::Event& evt, const edm::EventSetup& es, double evtWeight)
{  
  //std::cout << "<CompositePtrCandidateT1T2MEtHistManager::fillHistogramsImp>:" << std::endl; 

  typedef std::vector<CompositePtrCandidateT1T2MEt<T1,T2> > CompositePtrCandidateCollection;
  edm::Handle<CompositePtrCandidateCollection> diTauCandidates;
  getCollection(evt, diTauCandidateSrc_, diTauCandidates);

  //std::cout << " diTauCandidates.size = " << diTauCandidates->size() << std::endl;

  edm::Handle<std::vector<reco::Vertex> > recoVertices;
  evt.getByLabel(vertexSrc_, recoVertices);

  double diTauCandidateWeightSum = 0.;
  for ( typename CompositePtrCandidateCollection::const_iterator diTauCandidate = diTauCandidates->begin(); 
	diTauCandidate != diTauCandidates->end(); ++diTauCandidate ) {
    if ( requireGenMatch_ && !matchesGenCandidatePair(*diTauCandidate) ) continue;

    diTauCandidateWeightSum += getDiTauCandidateWeight(*diTauCandidate);
  }

  for ( typename CompositePtrCandidateCollection::const_iterator diTauCandidate = diTauCandidates->begin(); 
	diTauCandidate != diTauCandidates->end(); ++diTauCandidate ) {

    //bool isGenMatched = matchesGenCandidatePair(*diTauCandidate);
    //std::cout << " Pt = " << diTauCandidate->pt() << ", phi = " << diTauCandidate->phi() << ", visMass = " << diTauCandidate->p4Vis().mass() << std::endl;
    //std::cout << " isGenMatched = " << isGenMatched << std::endl;

    if ( requireGenMatch_ && !matchesGenCandidatePair(*diTauCandidate) ) continue;

    double diTauCandidateWeight = getDiTauCandidateWeight(*diTauCandidate);
    double weight = getWeight(evtWeight, diTauCandidateWeight, diTauCandidateWeightSum);

    if ( diTauCandidate->p4Leg1gen().energy() > epsilon && 
	 diTauCandidate->p4Leg2gen().energy() > epsilon ) {
      hGenDiTauCandidatePt_->Fill(diTauCandidate->p4VisGen().pt(), weight);

      hGenLeg1PtVsLeg2Pt_->Fill(diTauCandidate->p4VisLeg1gen().pt(), diTauCandidate->p4VisLeg2gen().pt(), weight);
      hGenLeg1EtaVsLeg2Eta_->Fill(diTauCandidate->p4VisLeg1gen().eta(), diTauCandidate->p4VisLeg2gen().eta(), weight);

      hGenLeg1DecayTime_->Fill(compDecayEigenTime(diTauCandidate->decayVertexPosLeg1gen(), 
						  diTauCandidate->primaryVertexPosGen(), diTauCandidate->p4Leg1gen().energy()), weight);
      hGenLeg2DecayTime_->Fill(compDecayEigenTime(diTauCandidate->decayVertexPosLeg2gen(), 
						  diTauCandidate->primaryVertexPosGen(), diTauCandidate->p4Leg2gen().energy()), weight);
    }

    hDiTauCandidatePt_->Fill(diTauCandidate->pt(), weight);
    hDiTauCandidateEta_->Fill(diTauCandidate->eta(), weight);
    hDiTauCandidatePhi_->Fill(diTauCandidate->phi(), weight);
    hDiTauCandidateCharge_->Fill(diTauCandidate->charge(), weight);
    hDiTauCandidateMass_->Fill(diTauCandidate->mass(), weight);

    double genDiTauMass = diTauCandidate->p4gen().mass();
    double svFitMassBestMatch = 1.e+6;

    const std::vector<SVmassRecoSolution>& svFitSolutions = diTauCandidate->svFitSolutions();
    for ( std::vector<SVmassRecoSolution>::const_iterator svFitSolution = svFitSolutions.begin();
	  svFitSolution != svFitSolutions.end(); ++svFitSolution ) {
      if ( svFitSolution->isValidSolution() ) {
	hSVfitMass_->Fill(svFitSolution->p4().mass(), weight);
	hSVfitMassVsLogLikelihood_->Fill(svFitSolution->logLikelihood(), svFitSolution->p4().mass(), weight);
	hSVfitLogLikelihood_->Fill(svFitSolution->logLikelihood(), svFitSolution->p4().mass(), weight);
	double leg1TotEnergy = ( svFitSolution->x1() > 0 && svFitSolution->x1() <= 1 ) ?
	  svFitSolution->p4VisLeg1().energy()/svFitSolution->x1() : svFitSolution->p4VisLeg1().energy();
	hSVfitDecayTimeLeg1_->Fill(compDecayEigenTime(svFitSolution->decayVertexPosLeg1(), 
						      svFitSolution->primaryVertexPosSVrefitted(), leg1TotEnergy), weight);
	double leg2TotEnergy = ( svFitSolution->x2() > 0 && svFitSolution->x2() <= 1 ) ?
	  svFitSolution->p4VisLeg2().energy()/svFitSolution->x2() : svFitSolution->p4VisLeg2().energy();
	hSVfitDecayTimeLeg2_->Fill(compDecayEigenTime(svFitSolution->decayVertexPosLeg2(), 
						      svFitSolution->primaryVertexPosSVrefitted(), leg2TotEnergy), weight);
	hSVfitStatus_->Fill(svFitSolution->svFitStatus(), weight);

	if ( TMath::Abs(svFitSolution->p4().mass() - genDiTauMass) < TMath::Abs(svFitMassBestMatch - genDiTauMass) ) {
	  svFitMassBestMatch = svFitSolution->p4().mass();
	}
      }
    }

    if ( svFitMassBestMatch != 1.e+6 ) hSVfitMassBestMatch_->Fill(svFitMassBestMatch, weight);

    hLeg1PtVsLeg2Pt_->Fill(diTauCandidate->leg1()->pt(), diTauCandidate->leg2()->pt(), weight);
    hLeg1EtaVsLeg2Eta_->Fill(diTauCandidate->leg1()->eta(), diTauCandidate->leg2()->eta(), weight);

    fillWeightHistograms(hDiTauCandidateWeightPosLog_, hDiTauCandidateWeightNegLog_, hDiTauCandidateWeightZero_, 
			 hDiTauCandidateWeightLinear_, diTauCandidateWeight);

    const reco::Track* trackLeg1 = trackExtractorLeg1_(*diTauCandidate->leg1());
    const reco::Track* trackLeg2 = trackExtractorLeg2_(*diTauCandidate->leg2());
    if ( trackLeg1 && trackLeg2 &&
	 recoVertices->size() >= 1 ) {
      const reco::Vertex& thePrimaryEventVertex = (*recoVertices->begin());

      double trackLeg1IpSig = trackLeg1->dxy(thePrimaryEventVertex.position())/trackLeg1->dxyError();
      double trackLeg2IpSig = trackLeg2->dxy(thePrimaryEventVertex.position())/trackLeg2->dxyError();

      hDiTauCandidateImpParSig_->Fill(TMath::Sqrt(trackLeg1IpSig*trackLeg1IpSig + trackLeg2IpSig*trackLeg2IpSig), weight);
    }

    hVisPt_->Fill(diTauCandidate->p4Vis().pt(), weight);
    hVisPhi_->Fill(diTauCandidate->p4Vis().phi(), weight);
    hVisMass_->Fill(diTauCandidate->p4Vis().mass(), weight);
    if ( visMassHypothesisSrc_.label() != "" ) {
      typedef edm::RefProd<CompositePtrCandidateCollection> CompositePtrCandidateRefProd;
      typedef std::vector<float> vfloat;
      typedef edm::AssociationVector<CompositePtrCandidateRefProd, vfloat> ZtautauVisMassHypothesisCollection;
      edm::Handle<ZtautauVisMassHypothesisCollection> visMassHypotheses;
      evt.getByLabel(visMassHypothesisSrc_, visMassHypotheses);

      unsigned numDiTauCandidates = diTauCandidates->size();
      for ( unsigned idxDiTauCandidate = 0; idxDiTauCandidate < numDiTauCandidates; ++idxDiTauCandidate ) {
	edm::Ref<CompositePtrCandidateCollection> diTauCandidateRef(diTauCandidates, idxDiTauCandidate);

	if ( diTauCandidateRef.get() != &(*diTauCandidate) ) continue;

	if ( visMassHypotheses->keyProduct().id() == diTauCandidateRef.id() ) {
	  hVisMassZllCombinedHypothesis_->Fill((*visMassHypotheses)[diTauCandidateRef], weight);
	} else {
	  edm::LogWarning("CompositePtrCandidateT1T2MEtHistManager::fillHistogramsImp") 
	    << " Mismatch between Product ids. of ZtautauVisMassHypothesisCollection  = " << visMassHypotheses->keyProduct().id()
	    << " and CompositePtrCandidateCollection = " << diTauCandidateRef.id() << ", "
	    << " presumably CompositePtrCandidateCollection has been filtered without re-keying ZtautauVisMassHypothesisCollection !!";
	}
      }
    }

    if ( diTauCandidate->collinearApproxIsValid() ) {  
      hCollinearApproxEta_->Fill(diTauCandidate->p4CollinearApprox().eta(), weight);
      hCollinearApproxMass_->Fill(diTauCandidate->p4CollinearApprox().mass(), weight);
      hCollinearApproxX1_->Fill(diTauCandidate->x1CollinearApprox(), weight);
      hCollinearApproxX2_->Fill(diTauCandidate->x2CollinearApprox(), weight);
    }

    hCDFmethodMass_->Fill(diTauCandidate->p4CDFmethod().mass(), weight);

    hMt12MET_->Fill(diTauCandidate->mt12MET(), weight);

    hMt1MET_->Fill(diTauCandidate->mt1MET(), weight);
    hMt2MET_->Fill(diTauCandidate->mt2MET(), weight);

    hDPhi12_->Fill(diTauCandidate->dPhi12(), weight);
    hDR12_->Fill(diTauCandidate->dR12(), weight);

    hVisEtaMin_->Fill(diTauCandidate->visEtaMin(), weight);
    hVisEtaMax_->Fill(diTauCandidate->visEtaMax(), weight);

    hDPhi1MET_->Fill(diTauCandidate->dPhi1MET(), weight);
    hDPhi2MET_->Fill(diTauCandidate->dPhi2MET(), weight);
    hDPhi1METvsDPhi2MET_->Fill(diTauCandidate->dPhi1MET(), diTauCandidate->dPhi2MET(), weight);

    hPzetaCorr_->Fill(diTauCandidate->pZetaVis(), diTauCandidate->pZeta(), weight);
    hPzetaDiff_->Fill(diTauCandidate->pZeta() - 1.5*diTauCandidate->pZetaVis(), weight);
  }
}

#include "FWCore/Framework/interface/MakerMacros.h"

#include "DataFormats/Candidate/interface/Candidate.h" 
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Tau.h"

typedef CompositePtrCandidateT1T2MEtHistManager<reco::Candidate, reco::Candidate> DiCandidatePairHistManager;
typedef CompositePtrCandidateT1T2MEtHistManager<pat::Electron, pat::Tau> PATElecTauPairHistManager;
typedef CompositePtrCandidateT1T2MEtHistManager<pat::Muon, pat::Tau> PATMuTauPairHistManager;
typedef CompositePtrCandidateT1T2MEtHistManager<pat::Tau, pat::Tau> PATDiTauPairHistManager;
typedef CompositePtrCandidateT1T2MEtHistManager<pat::Electron, pat::Muon> PATElecMuPairHistManager;

DEFINE_EDM_PLUGIN(AnalyzerPluginFactory, DiCandidatePairHistManager, "DiCandidatePairHistManager");
DEFINE_EDM_PLUGIN(HistManagerPluginFactory, DiCandidatePairHistManager, "DiCandidatePairHistManager");
DEFINE_EDM_PLUGIN(AnalyzerPluginFactory, PATElecTauPairHistManager, "PATElecTauPairHistManager");
DEFINE_EDM_PLUGIN(HistManagerPluginFactory, PATElecTauPairHistManager, "PATElecTauPairHistManager");
DEFINE_EDM_PLUGIN(AnalyzerPluginFactory, PATMuTauPairHistManager, "PATMuTauPairHistManager");
DEFINE_EDM_PLUGIN(HistManagerPluginFactory, PATMuTauPairHistManager, "PATMuTauPairHistManager");
DEFINE_EDM_PLUGIN(AnalyzerPluginFactory, PATDiTauPairHistManager, "PATDiTauPairHistManager");
DEFINE_EDM_PLUGIN(HistManagerPluginFactory, PATDiTauPairHistManager, "PATDiTauPairHistManager");
DEFINE_EDM_PLUGIN(AnalyzerPluginFactory, PATElecMuPairHistManager, "PATElecMuPairHistManager");
DEFINE_EDM_PLUGIN(HistManagerPluginFactory, PATElecMuPairHistManager, "PATElecMuPairHistManager");
  
#include "TauAnalysis/Core/interface/HistManagerAdapter.h"

typedef HistManagerAdapter<DiCandidatePairHistManager> DiCandidatePairAnalyzer;
typedef HistManagerAdapter<PATElecTauPairHistManager> PATElecTauPairAnalyzer;
typedef HistManagerAdapter<PATMuTauPairHistManager> PATMuTauPairAnalyzer;
typedef HistManagerAdapter<PATDiTauPairHistManager> PATDiTauPairAnalyzer;
typedef HistManagerAdapter<PATElecMuPairHistManager> PATElecMuPairAnalyzer;

DEFINE_ANOTHER_FWK_MODULE(DiCandidatePairAnalyzer);
DEFINE_ANOTHER_FWK_MODULE(PATElecTauPairAnalyzer);
DEFINE_ANOTHER_FWK_MODULE(PATMuTauPairAnalyzer);
DEFINE_ANOTHER_FWK_MODULE(PATDiTauPairAnalyzer);
DEFINE_ANOTHER_FWK_MODULE(PATElecMuPairAnalyzer);

