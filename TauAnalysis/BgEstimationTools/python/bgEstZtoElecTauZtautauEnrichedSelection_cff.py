import FWCore.ParameterSet.Config as cms
import copy

from TauAnalysis.CandidateTools.tools.objSelConfigurator import *
from TauAnalysis.RecoTools.tools.eventSelFlagProdConfigurator import *

#--------------------------------------------------------------------------------
# select signal enriched event sample
#--------------------------------------------------------------------------------



#--------------------------------------------------------------------------------  
# produce collection of pat::Electrons
#--------------------------------------------------------------------------------

from TauAnalysis.RecoTools.patLeptonSelection_cff import *

# require electron candidate to pass the eidRobustTight electron id. criteria
electronsBgEstZtautauEnrichedId = copy.deepcopy(selectedPatElectronsForElecTauId)

# require electron candidate to not be within eta-crack
# between Barrel and Encap ECAL calorimeter
electronsBgEstZtautauEnrichedAntiCrackCut = copy.deepcopy(selectedPatElectronsForElecTauAntiCrackCut)

# require electron candidate to be within geometric acceptance of electron trigger
electronsBgEstZtautauEnrichedEta = copy.deepcopy(selectedPatElectronsForElecTauEta)

# require electron candidate to have transverse momentum above threshold
electronsBgEstZtautauEnrichedPt = copy.deepcopy(selectedPatElectronsForElecTauPt)

# require electron candidate to be isolated w.r.t combined relative PF candidates
electronsBgEstZtautauEnrichedIso = copy.deepcopy(selectedPatElectronsForElecTauIso)

# require electron to not be from a photon conversion
electronsBgEstZtautauEnrichedConversionVeto = copy.deepcopy(selectedPatElectronsForElecTauConversionVeto)
electronsBgEstZtautauEnrichedConversionVeto.usePogMethod = cms.bool(True)
electronsBgEstZtautauEnrichedConversionVeto.doMissingHitsCut = cms.bool(True)
electronsBgEstZtautauEnrichedConversionVeto.doPixCut = cms.bool(False)

# require track of electron candidate to have small transverse impact parameter
# (in order to veto electrons resulting from b-quark decays)
electronsBgEstZtautauEnrichedTrkIP = copy.deepcopy(selectedPatElectronsForElecTauTrkIP)


electronSelConfiguratorBgEstZtautauEnriched = objSelConfigurator(
    [ electronsBgEstZtautauEnrichedId,
      electronsBgEstZtautauEnrichedAntiCrackCut,
      electronsBgEstZtautauEnrichedEta,
      electronsBgEstZtautauEnrichedPt,
      electronsBgEstZtautauEnrichedIso,
      electronsBgEstZtautauEnrichedConversionVeto,
      electronsBgEstZtautauEnrichedTrkIP
      ],
    src = "cleanPatElectrons",
    pyModuleName = __name__,
    doSelIndividual = True
)


selectElectronsBgEstZtautauEnriched = electronSelConfiguratorBgEstZtautauEnriched.configure(pyNameSpace = locals())

   
#--------------------------------------------------------------------------------  
# produce collection of pat::Taus
#--------------------------------------------------------------------------------

#selectTausBgEstZtautauEnriched = copy.deepcopy(selectPatTausForElecTau)

# require tau candidate not to overlap with selected electrons
# (in order to avoid double-counting one and the same physical particle
#  as electron and as tau candidate)
tausBgEstZtautauEnrichedAntiOverlapWithElectronsVeto = copy.deepcopy(selectedPatTausForElecTauAntiOverlapWithElectronsVeto)
tausBgEstZtautauEnrichedAntiOverlapWithElectronsVeto.srcNotToBeFiltered = cms.VInputTag("electronsBgEstZtautauEnrichedPtCumulative")

# require tau candidate to be within geometric acceptance of Pixel + SiTracker detectors
tausBgEstZtautauEnrichedEta = copy.deepcopy(selectedPatTausForElecTauEta)

# require tau candidate to have transverse energy above threshold
tausBgEstZtautauEnrichedPt = copy.deepcopy(selectedPatTausForElecTauPt)

# require tau candidate to have a leading track
# (track of Pt > 1. GeV within matching cone of size dR = 0.2 around jet-axis)
tausBgEstZtautauEnrichedLeadTrk = copy.deepcopy(selectedPatTausForElecTauLeadTrk)

# require leading track of tau candidate to have Pt > 5. GeV
tausBgEstZtautauEnrichedLeadTrkPt = copy.deepcopy(selectedPatTausForElecTauLeadTrkPt)

# require tau candidate to pass TaNC discriminator
tausBgEstZtautauEnrichedIso = copy.deepcopy(selectedPatTausForElecTauIso)

# require tau candidate to pass electron veto
tausBgEstZtautauEnrichedElectronVeto = copy.deepcopy(selectedPatTausForElecTauElectronVeto)

# require tau candidate to pass muon veto
tausBgEstZtautauEnrichedMuonVeto = copy.deepcopy(selectedPatTausForElecTauMuonVeto)

## tausBgEstZtautauEnrichedMuonVeto.cut = cms.string('tauID("againstMuonTight") > -1000')
## tausBgEstZtautauEnrichedElectronVeto.cut = cms.string('tauID("againstElectronLoose") > -1000')


tauSelConfiguratorBgEstZtautauEnriched = objSelConfigurator(
    [ tausBgEstZtautauEnrichedAntiOverlapWithElectronsVeto,
      tausBgEstZtautauEnrichedEta,
      tausBgEstZtautauEnrichedPt,
      tausBgEstZtautauEnrichedLeadTrkPt,
      tausBgEstZtautauEnrichedIso,
      tausBgEstZtautauEnrichedElectronVeto,
      tausBgEstZtautauEnrichedMuonVeto ],
    src = "cleanPatTaus",
    pyModuleName = __name__,
    doSelIndividual = True
)

selectTausBgEstZtautauEnriched = tauSelConfiguratorBgEstZtautauEnriched.configure(pyNameSpace = locals())


#--------------------------------------------------------------------------------  
# produce collection of electron + tau-jet combinations
#--------------------------------------------------------------------------------

### production

from TauAnalysis.CandidateTools.elecTauPairProduction_cff import *

elecTauPairsBgEstZtautauEnriched = copy.deepcopy(allElecTauPairs)
elecTauPairsBgEstZtautauEnriched.srcLeg1 = cms.InputTag('electronsBgEstZtautauEnrichedTrkIPcumulative')
elecTauPairsBgEstZtautauEnriched.srcLeg2 = cms.InputTag('tausBgEstZtautauEnrichedMuonVetoCumulative')

produceElecTauPairsBgEstZtautauEnriched = cms.Sequence(elecTauPairsBgEstZtautauEnriched)

### selection

from TauAnalysis.CandidateTools.elecTauPairSelection_cfi import *

elecTauPairsBgEstZtautauEnrichedAntiOverlapVeto = copy.deepcopy(selectedElecTauPairsAntiOverlapVeto)
elecTauPairsBgEstZtautauEnrichedAntiOverlapVeto.cut = cms.string("dR12 > 0.5")

### !!!!! turned off
elecTauPairsBgEstZtautauEnrichedMt1MET = copy.deepcopy(selectedElecTauPairsMt1MET)
elecTauPairsBgEstZtautauEnrichedMt1MET.cut = cms.string('mt1MET > -1000.')

elecTauPairsBgEstZtautauEnrichedPzetaDiff = copy.deepcopy(selectedElecTauPairsPzetaDiff)
elecTauPairsBgEstZtautauEnrichedZeroCharge = copy.deepcopy(selectedElecTauPairsZeroCharge)



elecTauPairSelConfiguratorBgEstZtautauEnriched = objSelConfigurator(
    [ elecTauPairsBgEstZtautauEnrichedAntiOverlapVeto,
      elecTauPairsBgEstZtautauEnrichedMt1MET,
      elecTauPairsBgEstZtautauEnrichedPzetaDiff,
      elecTauPairsBgEstZtautauEnrichedZeroCharge,
      ],
    src = "elecTauPairsBgEstZtautauEnriched",
    pyModuleName = __name__,
    doSelIndividual = True
)

selectElecTauPairsBgEstZtautauEnriched = elecTauPairSelConfiguratorBgEstZtautauEnriched.configure(pyNameSpace = locals())





####### anti Zee Cut #######

# Two methods of Z->ee rejection:

# 1)  Z->ee reconstruction veto
# 2)  Opposite-sign, isolated second lepton veto



## # 1)
## from TauAnalysis.RecoTools.elecTauPairZeeHypothesis_cff import *
## ### production
## elecTauPairBgEstZtautauEnrichedZeeHypotheses = copy.deepcopy(elecTauPairZeeHypotheses)
## elecTauPairBgEstZtautauEnrichedZeeHypotheses.diCandidatePairSource = cms.InputTag('elecTauPairsBgEstZtautauEnrichedZeroChargeCumulative')
## ### selection
## selectedElecTauPairBgEstZtautauEnrichedZeeHypotheses = copy.deepcopy(selectedElecTauPairZeeHypotheses)
## selectedElecTauPairBgEstZtautauEnrichedZeeHypotheses.src = cms.InputTag('elecTauPairBgEstZtautauEnrichedZeeHypotheses')
## ### sequence
## produceElecTauPairZeeHypothesesBgEstZtautauEnriched = cms.Sequence(
##         elecTauPairBgEstZtautauEnrichedZeeHypotheses*
##         selectedElecTauPairBgEstZtautauEnrichedZeeHypotheses
## )


# 2)
from TauAnalysis.RecoTools.diElecPairZeeHypothesis_cff import *
### production
allDiElecPairBgEstZtautauEnrichedZeeHypothesesByLooseIsolation = allDiElecPairZeeHypothesesByLooseIsolation.clone(
	srcLeg1 = cms.InputTag("electronsBgEstZtautauEnrichedTrkIPcumulative")
)
### selection
selectedDiElecPairBgEstZtautauEnrichedZeeHypothesesByLooseIsolation = selectedDiElecPairZeeHypothesesByLooseIsolation.clone(
	src = cms.InputTag("allDiElecPairBgEstZtautauEnrichedZeeHypothesesByLooseIsolation")
)
### sequence
produceElecTauPairZeeHypothesesBgEstZtautauEnriched = cms.Sequence(
	selectedPatElectronsForZeeHypotheses * 
	allDiElecPairBgEstZtautauEnrichedZeeHypothesesByLooseIsolation *
	selectedDiElecPairBgEstZtautauEnrichedZeeHypothesesByLooseIsolation
)




from TauAnalysis.RecoTools.patJetSelectionForAHtoElecTau_cff import *

## eta < 4.5
jetsBgEstZtautauEnrichedEta = copy.deepcopy(selectedPatJetsForAHtoElecTauEta)
## Et > 20 GeV
jetsBgEstZtautauEnrichedEt = copy.deepcopy(selectedPatJetsForAHtoElecTauEt)
## Delta R > 0.5
jetsBgEstZtautauEnrichedAntiOverlapWithLeptonsVeto = copy.deepcopy(selectedPatJetsForAHtoElecTauAntiOverlapWithLeptonsVeto)
jetsBgEstZtautauEnrichedAntiOverlapWithLeptonsVeto.srcNotToBeFiltered = cms.VInputTag(
        "electronsBgEstZtautauEnrichedTrkIPcumulative",
        "tausBgEstZtautauEnrichedMuonVetoCumulative")

#####

## Et > 30 GeV
jetsBgEstZtautauEnrichedJetTag = copy.deepcopy(selectedPatJetsForAHtoElecTauJetTag)

## bDiscriminator("trackCountingHighEffBJetTags") > 3.3
jetsBgEstZtautauEnrichedJetBtag = copy.deepcopy(selectedPatJetsForAHtoElecTauBtag)


patJetSelConfiguratorBgEstZtautauEnrichedBtag = objSelConfigurator(
    [ jetsBgEstZtautauEnrichedEta,
      jetsBgEstZtautauEnrichedEt,
      jetsBgEstZtautauEnrichedAntiOverlapWithLeptonsVeto,
      jetsBgEstZtautauEnrichedJetBtag ],
    src = "patJets",
    pyModuleName = __name__,
    doSelIndividual = True
)

selectPatJetsBgEstZtautauEnrichedBtag = patJetSelConfiguratorBgEstZtautauEnrichedBtag.configure(pyNameSpace = locals())

patJetSelConfiguratorJetTag = objSelConfigurator(
    [ jetsBgEstZtautauEnrichedJetTag ],
    src = 'jetsBgEstZtautauEnrichedAntiOverlapWithLeptonsVetoCumulative',
    pyModuleName = __name__,
    doSelIndividual = True
)

selectPatJetsBgEstZtautauEnrichedJetTag = patJetSelConfiguratorJetTag.configure(pyNameSpace = locals())

selectPatJetsBgEstZtautauEnriched = cms.Sequence(selectPatJetsBgEstZtautauEnrichedBtag + selectPatJetsBgEstZtautauEnrichedJetTag)


#--------------------------------------------------------------------------------  
# produce boolean event selection flags
#--------------------------------------------------------------------------------

from TauAnalysis.Configuration.selectZtoElecTau_cff import *
from TauAnalysis.Configuration.selectAHtoElecTau_cff import *

# trigger selection
cfgTriggerBgEst = copy.deepcopy(cfgTrigger)

from TauAnalysis.BgEstimationTools.selectZtoElecTauEventVertex_cff import *


# electron cuts

cfgElectronIdCutBgEstZtautauEnriched = copy.deepcopy(cfgElectronIdCut)
cfgElectronIdCutBgEstZtautauEnriched.pluginName = cms.string('electronIdCutBgEstZtautauEnriched')
cfgElectronIdCutBgEstZtautauEnriched.src_cumulative = cms.InputTag('electronsBgEstZtautauEnrichedIdCumulative')
cfgElectronIdCutBgEstZtautauEnriched.src_individual = cms.InputTag('electronsBgEstZtautauEnrichedIdIndividual')

cfgElectronAntiCrackCutBgEstZtautauEnriched = copy.deepcopy(cfgElectronAntiCrackCut)
cfgElectronAntiCrackCutBgEstZtautauEnriched.pluginName = cms.string('electronAntiCrackCutBgEstZtautauEnriched')
cfgElectronAntiCrackCutBgEstZtautauEnriched.src_cumulative = cms.InputTag('electronsBgEstZtautauEnrichedAntiCrackCutCumulative')
cfgElectronAntiCrackCutBgEstZtautauEnriched.src_individual = cms.InputTag('electronsBgEstZtautauEnrichedAntiCrackCutIndividual')

cfgElectronEtaCutBgEstZtautauEnriched = copy.deepcopy(cfgElectronEtaCut)
cfgElectronEtaCutBgEstZtautauEnriched.pluginName = cms.string('electronEtaCutBgEstZtautauEnriched')
cfgElectronEtaCutBgEstZtautauEnriched.src_cumulative = cms.InputTag('electronsBgEstZtautauEnrichedEtaCumulative')
cfgElectronEtaCutBgEstZtautauEnriched.src_individual = cms.InputTag('electronsBgEstZtautauEnrichedEtaIndividual')

cfgElectronPtCutBgEstZtautauEnriched = copy.deepcopy(cfgElectronPtCut)
cfgElectronPtCutBgEstZtautauEnriched.pluginName = cms.string('electronPtCutBgEstZtautauEnriched')
cfgElectronPtCutBgEstZtautauEnriched.src_cumulative = cms.InputTag('electronsBgEstZtautauEnrichedPtCumulative')
cfgElectronPtCutBgEstZtautauEnriched.src_individual = cms.InputTag('electronsBgEstZtautauEnrichedPtIndividual')

cfgElectronIsoCutBgEstZtautauEnriched = copy.deepcopy(cfgElectronIsoCut)
cfgElectronIsoCutBgEstZtautauEnriched.pluginName = cms.string('electronIsoCutBgEstZtautauEnriched')
cfgElectronIsoCutBgEstZtautauEnriched.src_cumulative = cms.InputTag('electronsBgEstZtautauEnrichedIsoCumulative')
cfgElectronIsoCutBgEstZtautauEnriched.src_individual = cms.InputTag('electronsBgEstZtautauEnrichedIsoIndividual')

cfgElectronConversionVetoBgEstZtautauEnriched = copy.deepcopy(cfgElectronConversionVeto)
cfgElectronConversionVetoBgEstZtautauEnriched.pluginName = cms.string('electronConversionVetoBgEstZtautauEnriched')
cfgElectronConversionVetoBgEstZtautauEnriched.src_cumulative = cms.InputTag('electronsBgEstZtautauEnrichedConversionVetoCumulative')
cfgElectronConversionVetoBgEstZtautauEnriched.src_individual = cms.InputTag('electronsBgEstZtautauEnrichedConversionVetoIndividual')

cfgElectronTrkIPcutBgEstZtautauEnriched = copy.deepcopy(cfgElectronTrkIPcut)
cfgElectronTrkIPcutBgEstZtautauEnriched.pluginName = cms.string('electronTrkIPcutBgEstZtautauEnriched')
cfgElectronTrkIPcutBgEstZtautauEnriched.src_cumulative = cms.InputTag('electronsBgEstZtautauEnrichedTrkIPcumulative')
cfgElectronTrkIPcutBgEstZtautauEnriched.src_individual = cms.InputTag('electronsBgEstZtautauEnrichedTrkIPcumulative')

# tau cuts

cfgTauAntiOverlapWithElectronsVetoBgEstZtautauEnriched = copy.deepcopy(cfgTauAntiOverlapWithElectronsVeto)
cfgTauAntiOverlapWithElectronsVetoBgEstZtautauEnriched.pluginName = cms.string('tauAntiOverlapWithElectronsVetoBgEstZtautauEnriched')
cfgTauAntiOverlapWithElectronsVetoBgEstZtautauEnriched.src_cumulative = cms.InputTag('tausBgEstZtautauEnrichedAntiOverlapWithElectronsVetoCumulative')
cfgTauAntiOverlapWithElectronsVetoBgEstZtautauEnriched.src_individual = cms.InputTag('tausBgEstZtautauEnrichedAntiOverlapWithElectronsVetoIndividual')

cfgTauEtaCutBgEstZtautauEnriched = copy.deepcopy(cfgTauEtaCut)
cfgTauEtaCutBgEstZtautauEnriched.pluginName = cms.string('tauEtaCutBgEstZtautauEnriched')
cfgTauEtaCutBgEstZtautauEnriched.src_cumulative = cms.InputTag('tausBgEstZtautauEnrichedEtaCumulative')
cfgTauEtaCutBgEstZtautauEnriched.src_individual = cms.InputTag('tausBgEstZtautauEnrichedEtaIndividual')

cfgTauPtCutBgEstZtautauEnriched = copy.deepcopy(cfgTauPtCut)
cfgTauPtCutBgEstZtautauEnriched.pluginName = cms.string('tauPtCutBgEstZtautauEnriched')
cfgTauPtCutBgEstZtautauEnriched.src_cumulative = cms.InputTag('tausBgEstZtautauEnrichedPtCumulative')
cfgTauPtCutBgEstZtautauEnriched.src_individual = cms.InputTag('tausBgEstZtautauEnrichedPtIndividual')

cfgTauLeadTrkPtCutBgEstZtautauEnriched = copy.deepcopy(cfgTauLeadTrkPtCut)
cfgTauLeadTrkPtCutBgEstZtautauEnriched.pluginName = cms.string('tauLeadTrkPtCutBgEstZtautauEnriched')
cfgTauLeadTrkPtCutBgEstZtautauEnriched.src_cumulative = cms.InputTag('tausBgEstZtautauEnrichedLeadTrkPtCumulative')
cfgTauLeadTrkPtCutBgEstZtautauEnriched.src_individual = cms.InputTag('tausBgEstZtautauEnrichedLeadTrkPtIndividual')

cfgTauIsoCutBgEstZtautauEnriched = copy.deepcopy(cfgTauIsoCut)
cfgTauIsoCutBgEstZtautauEnriched.pluginName = cms.string('tauIsoCutBgEstZtautauEnriched')
cfgTauIsoCutBgEstZtautauEnriched.src_cumulative = cms.InputTag('tausBgEstZtautauEnrichedIsoCumulative')
cfgTauIsoCutBgEstZtautauEnriched.src_individual = cms.InputTag('tausBgEstZtautauEnrichedIsoIndividual')

cfgTauElectronVetoBgEstZtautauEnriched = copy.deepcopy(cfgTauElectronVeto)
cfgTauElectronVetoBgEstZtautauEnriched.pluginName = cms.string('tauElectronVetoBgEstZtautauEnriched')
cfgTauElectronVetoBgEstZtautauEnriched.src_cumulative = cms.InputTag('tausBgEstZtautauEnrichedElectronVetoCumulative')
cfgTauElectronVetoBgEstZtautauEnriched.src_individual = cms.InputTag('tausBgEstZtautauEnrichedElectronVetoIndividual')

cfgTauMuonVetoBgEstZtautauEnriched = copy.deepcopy(cfgTauMuonVeto)
cfgTauMuonVetoBgEstZtautauEnriched.pluginName = cms.string('tauMuonVetoBgEstZtautauEnriched')
cfgTauMuonVetoBgEstZtautauEnriched.src_cumulative = cms.InputTag('tausBgEstZtautauEnrichedMuonVetoCumulative')
cfgTauMuonVetoBgEstZtautauEnriched.src_individual = cms.InputTag('tausBgEstZtautauEnrichedMuonVetoIndividual')

# di-tau candidate selection

cfgDiTauCandidateAntiOverlapVetoBgEstZtautauEnriched = copy.deepcopy(cfgDiTauCandidateForElecTauAntiOverlapVeto)
cfgDiTauCandidateAntiOverlapVetoBgEstZtautauEnriched.pluginName = cms.string('diTauCandidateAntiOverlapVetoBgEstZtautauEnriched')
cfgDiTauCandidateAntiOverlapVetoBgEstZtautauEnriched.src_cumulative = cms.InputTag('elecTauPairsBgEstZtautauEnrichedAntiOverlapVetoCumulative')
cfgDiTauCandidateAntiOverlapVetoBgEstZtautauEnriched.src_individual = cms.InputTag('elecTauPairsBgEstZtautauEnrichedAntiOverlapVetoIndividual')

cfgDiTauCandidateForElecTauMt1METCutBgEstZtautauEnriched = copy.deepcopy(cfgDiTauCandidateForElecTauMt1METCut)
cfgDiTauCandidateForElecTauMt1METCutBgEstZtautauEnriched.pluginName = cms.string('diTauCandidateMt1METCutBgEstZtautauEnriched')
cfgDiTauCandidateForElecTauMt1METCutBgEstZtautauEnriched.src_cumulative = cms.InputTag('elecTauPairsBgEstZtautauEnrichedMt1METcumulative')
cfgDiTauCandidateForElecTauMt1METCutBgEstZtautauEnriched.src_individual = cms.InputTag('elecTauPairsBgEstZtautauEnrichedMt1METindividual')

cfgDiTauCandidateForElecTauPzetaDiffCutBgEstZtautauEnriched = copy.deepcopy(cfgDiTauCandidateForElecTauPzetaDiffCut)
cfgDiTauCandidateForElecTauPzetaDiffCutBgEstZtautauEnriched.pluginName = cms.string('diTauCandidatePzetaDiffCutBgEstZtautauEnriched')
cfgDiTauCandidateForElecTauPzetaDiffCutBgEstZtautauEnriched.src_cumulative = cms.InputTag('elecTauPairsBgEstZtautauEnrichedPzetaDiffCumulative')
cfgDiTauCandidateForElecTauPzetaDiffCutBgEstZtautauEnriched.src_individual = cms.InputTag('elecTauPairsBgEstZtautauEnrichedPzetaDiffIndividual')

cfgDiTauCandidateForElecTauZeroChargeCutBgEstZtautauEnriched = copy.deepcopy(cfgDiTauCandidateForElecTauZeroChargeCut)
cfgDiTauCandidateForElecTauZeroChargeCutBgEstZtautauEnriched.pluginName = cms.string('diTauCandidateZeroChargeCutBgEstZtautauEnriched')
cfgDiTauCandidateForElecTauZeroChargeCutBgEstZtautauEnriched.src_cumulative = cms.InputTag('elecTauPairsBgEstZtautauEnrichedZeroChargeCumulative')
cfgDiTauCandidateForElecTauZeroChargeCutBgEstZtautauEnriched.src_individual = cms.InputTag('elecTauPairsBgEstZtautauEnrichedZeroChargeIndividual')


# anti-Zee selection

# 1)
## cfgElecTauPairZeeHypothesisVetoBgEstZtautauEnriched = copy.deepcopy(cfgElecTauPairZeeHypothesisVeto)
## cfgElecTauPairZeeHypothesisVetoBgEstZtautauEnriched.pluginName = cms.string('diTauCandidateZeeHypothesisVetoBgEstZtautauEnriched')
## cfgElecTauPairZeeHypothesisVetoBgEstZtautauEnriched.src = cms.InputTag('selectedElecTauPairBgEstZtautauEnrichedZeeHypotheses')

# 2)
cfgElecTauPairZeeHypothesisVetoBgEstZtautauEnriched = copy.deepcopy(cfgDiElecPairZeeHypothesisVetoByLooseIsolation)
cfgElecTauPairZeeHypothesisVetoBgEstZtautauEnriched.pluginName = cms.string('diTauCandidateZeeHypothesisVetoBgEstZtautauEnriched')
cfgElecTauPairZeeHypothesisVetoBgEstZtautauEnriched.src = cms.InputTag('selectedDiElecPairBgEstZtautauEnrichedZeeHypothesesByLooseIsolation')



# jet veto/b-jet candidate selection
cfgJetEtCutBgEstZtautauEnriched = copy.deepcopy(cfgJetEtCut)
cfgJetEtCutBgEstZtautauEnriched.pluginName = cms.string('jetEtCutBgEstZtautauEnriched')
cfgJetEtCutBgEstZtautauEnriched.src_cumulative = cms.InputTag('jetsBgEstZtautauEnrichedJetTagCumulative')
cfgJetEtCutBgEstZtautauEnriched.src_individual = cms.InputTag('jetsBgEstZtautauEnrichedJetTagIndividual')

cfgBtagVetoBgEstZtautauEnriched = copy.deepcopy(cfgBtagVeto)
cfgBtagVetoBgEstZtautauEnriched.pluginName = cms.string('jetBtagVetoBgEstZtautauEnriched')
cfgBtagVetoBgEstZtautauEnriched.src_cumulative = cms.InputTag('jetsBgEstZtautauEnrichedJetBtagCumulative')
cfgBtagVetoBgEstZtautauEnriched.src_individual = cms.InputTag('jetsBgEstZtautauEnrichedJetBtagIndividual')

cfgBtagCutBgEstZtautauEnriched = copy.deepcopy(cfgBtagCut)
cfgBtagCutBgEstZtautauEnriched.pluginName = cms.string('jetBtagBgEstZtautauEnriched')
cfgBtagCutBgEstZtautauEnriched.src_cumulative = cms.InputTag('jetsBgEstZtautauEnrichedJetBtagCumulative')
cfgBtagCutBgEstZtautauEnriched.src_individual = cms.InputTag('jetsBgEstZtautauEnrichedJetBtagIndividual')





evtSelConfiguratorBgEstZtautauEnriched = eventSelFlagProdConfigurator(
    [ cfgGenPhaseSpaceCut,
      cfgTriggerBgEst,
      cfgPrimaryEventVertexQuality,
      cfgPrimaryEventVertexPosition,      
      cfgPrimaryEventVertexHighestPtTrackSum,
      cfgElectronIdCutBgEstZtautauEnriched,
      cfgElectronAntiCrackCutBgEstZtautauEnriched,
      cfgElectronEtaCutBgEstZtautauEnriched,
      cfgElectronPtCutBgEstZtautauEnriched,
      cfgElectronIsoCutBgEstZtautauEnriched,
      cfgElectronConversionVetoBgEstZtautauEnriched,
      cfgElectronTrkIPcutBgEstZtautauEnriched,
      cfgTauAntiOverlapWithElectronsVetoBgEstZtautauEnriched,
      cfgTauEtaCutBgEstZtautauEnriched,
      cfgTauPtCutBgEstZtautauEnriched,
      cfgTauLeadTrkPtCutBgEstZtautauEnriched,
      cfgTauIsoCutBgEstZtautauEnriched,
      cfgTauElectronVetoBgEstZtautauEnriched,
      cfgTauMuonVetoBgEstZtautauEnriched,
      cfgDiTauCandidateAntiOverlapVetoBgEstZtautauEnriched,
      cfgDiTauCandidateForElecTauMt1METCutBgEstZtautauEnriched,
      cfgDiTauCandidateForElecTauPzetaDiffCutBgEstZtautauEnriched,
      cfgDiTauCandidateForElecTauZeroChargeCutBgEstZtautauEnriched,
      cfgElecTauPairZeeHypothesisVetoBgEstZtautauEnriched,
      cfgJetEtCutBgEstZtautauEnriched,
      cfgBtagVetoBgEstZtautauEnriched,
      cfgBtagCutBgEstZtautauEnriched
      ],
    boolEventSelFlagProducer = "BoolEventSelFlagProducer",
    pyModuleName = __name__
)

selectEventsBgEstZtautauEnriched = evtSelConfiguratorBgEstZtautauEnriched.configure()

#--------------------------------------------------------------------------------  
# apply event selection criteria; fill histograms
#--------------------------------------------------------------------------------

from TauAnalysis.Configuration.analyzeZtoElecTau_cff import *

diTauCandidateHistManagerForElecTauBgEstZtautauEnriched = copy.deepcopy(diTauCandidateHistManagerForElecTau)
diTauCandidateHistManagerForElecTauBgEstZtautauEnriched.pluginName = cms.string('diTauCandidateHistManagerForElecTauBgEstZtautauEnriched')
diTauCandidateHistManagerForElecTauBgEstZtautauEnriched.diTauCandidateSource = cms.InputTag('elecTauPairsBgEstZtautauEnriched')
diTauCandidateHistManagerForElecTauBgEstZtautauEnriched.visMassHypothesisSource = cms.InputTag('')


# import config for svfit histogram manager
from TauAnalysis.Core.diTauCandidateNSVfitHistManager_cfi import *
diTauCandidateNSVfitHistManagerForElecTauBgEstZtautauEnriched = copy.deepcopy(diTauCandidateNSVfitHistManagerForElecTau)
diTauCandidateNSVfitHistManagerForElecTauBgEstZtautauEnriched.pluginName = cms.string('diTauCandidateNSVfitHistManagerForElecTauBgEstZtautauEnriched')
diTauCandidateNSVfitHistManagerForElecTauBgEstZtautauEnriched.diTauCandidateSource = cms.InputTag('elecTauPairsBgEstZtautauEnriched')

# import config for electron histogram manager
from TauAnalysis.Core.electronHistManager_cfi import *
electronHistManagerForElecTauBgEstZtautauEnriched = copy.deepcopy(electronHistManager)
electronHistManagerForElecTauBgEstZtautauEnriched.pluginName = cms.string('electronHistManagerForElecTauBgEstZtautauEnriched')
electronHistManagerForElecTauBgEstZtautauEnriched.jetSource = cms.InputTag('cleanPatJets')
electronHistManagerForElecTauBgEstZtautauEnriched.vertexSource = cms.InputTag('selectedPrimaryVertexHighestPtTrackSumForElecTau')

# import config for tau histogram manager
from TauAnalysis.Core.pftauHistManager_cfi import *
tauHistManagerForElecTauBgEstZtautauEnriched = copy.deepcopy(tauHistManager)
tauHistManagerForElecTauBgEstZtautauEnriched.pluginName = cms.string('tauHistManagerForElecTauBgEstZtautauEnriched')
tauHistManagerForElecTauBgEstZtautauEnriched.jetSource = cms.InputTag('cleanPatJets')
tauHistManagerForElecTauBgEstZtautauEnriched.vertexSource = cms.InputTag('selectedPrimaryVertexHighestPtTrackSumForElecTau')

from TauAnalysis.Core.vertexHistManager_cfi import *
vertexHistManagerForElecTauBgEstZtautauEnriched = copy.deepcopy(vertexHistManager)
vertexHistManagerForElecTauBgEstZtautauEnriched.pluginName = cms.string('vertexHistManagerForElecTauBgEstZtautauEnriched')
vertexHistManagerForElecTauBgEstZtautauEnriched.vertexSource = cms.InputTag('selectedPrimaryVertexHighestPtTrackSumForElecTau')

from TauAnalysis.Core.jetHistManager_cfi import *
jetHistManagerForElecTauBgEstZtautauEnriched = copy.deepcopy(jetHistManager)
jetHistManagerForElecTauBgEstZtautauEnriched.pluginName = cms.string('jetHistManagerForElecTauBgEstZtautauEnriched')
jetHistManagerForElecTauBgEstZtautauEnriched.jetSource = cms.InputTag('patJets')
 

analyzeEventsBgEstZtautauEnriched = cms.EDAnalyzer("GenericAnalyzer",

    name = cms.string('BgEstTemplateAnalyzer_ZtautauEnriched'), 

    filters = cms.VPSet(
        evtSelGenPhaseSpace,
        evtSelTrigger,
        evtSelPrimaryEventVertexQuality,
        evtSelPrimaryEventVertexPosition,        
        evtSelPrimaryEventVertexHighestPtTrackSum,
        #start electron cuts
        
        cms.PSet(
            pluginName = cms.string('electronIdCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('electronIdCutBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('electronAntiCrackCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('electronAntiCrackCutBgEstZtautauEnriched','cumulative')
        ),        
        cms.PSet(
            pluginName = cms.string('electronEtaCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('electronEtaCutBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('electronPtCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('electronPtCutBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('electronIsoCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('electronIsoCutBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('electronConversionVetoBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('electronConversionVetoBgEstZtautauEnriched','cumulative')
        ),        
        cms.PSet(
            pluginName = cms.string('electronTrkIPcutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('electronTrkIPcutBgEstZtautauEnriched','cumulative')
        ),


        #start tau cuts
        
        cms.PSet(
            pluginName = cms.string('tauAntiOverlapWithElectronsVetoBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('tauAntiOverlapWithElectronsVetoBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('tauEtaCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('tauEtaCutBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('tauPtCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('tauPtCutBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('tauLeadTrkPtCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('tauLeadTrkPtCutBgEstZtautauEnriched','cumulative')
        ),  
        cms.PSet(
            pluginName = cms.string('tauIsoCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('tauIsoCutBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('tauElectronVetoBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('tauElectronVetoBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('tauMuonVetoBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('tauMuonVetoBgEstZtautauEnriched','cumulative')
        ),

        #start ditau cuts
        
        cms.PSet(
            pluginName = cms.string('diTauCandidateAntiOverlapVetoBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('diTauCandidateAntiOverlapVetoBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('diTauCandidateMt1METCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('diTauCandidateMt1METCutBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('diTauCandidatePzetaDiffCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('diTauCandidatePzetaDiffCutBgEstZtautauEnriched','cumulative')
        ),

        cms.PSet(
            pluginName = cms.string('diTauCandidateZeeHypothesisVetoBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('diTauCandidateZeeHypothesisVetoBgEstZtautauEnriched')
        ),
        cms.PSet(
            pluginName = cms.string('diTauCandidateZeroChargeCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('diTauCandidateZeroChargeCutBgEstZtautauEnriched','cumulative')
        ),
        
        
        
    ),
  
    analyzers = cms.VPSet(
         diTauCandidateHistManagerForElecTauBgEstZtautauEnriched,
         electronHistManagerForElecTauBgEstZtautauEnriched,
         tauHistManagerForElecTauBgEstZtautauEnriched,
         diTauCandidateNSVfitHistManagerForElecTauBgEstZtautauEnriched,
         vertexHistManagerForElecTauBgEstZtautauEnriched
    ),

    #eventDumps = cms.VPSet(elecTauEventDump),


    analysisSequence = cms.VPSet(
    
        # generator level phase-space selection
        # (NOTE: (1) to be used in case of Monte Carlo samples
        #            overlapping in simulated phase-space only !!
        #        (2) genPhaseSpaceCut needs to be **always** the first entry in the list of cuts
        #           - otherwise the script submitToBatch.csh for submission of cmsRun jobs
        #            to the CERN batch system will not work !!)

        cms.PSet(
            filter = cms.string('genPhaseSpaceCut'),
            title = cms.string('gen. Phase-Space')
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    ),
            replace = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched.electronSource = cleanPatElectrons',
                                  'tauHistManagerForElecTauBgEstZtautauEnriched.tauSource = cleanPatTaus'
                                  )
        ),    
        cms.PSet(
            filter = cms.string('evtSelTrigger'),
            title = cms.string('Trigger'),
        ),
        cms.PSet(
            filter = cms.string('evtSelPrimaryEventVertexQuality'),
            title = cms.string('Valid vertex with #dof >= 4')
        ),
        cms.PSet(
            filter = cms.string('evtSelPrimaryEventVertexPosition'),
            title = cms.string('Vertex abs(z) < 24 & Rho < 2')
        ),
        cms.PSet(
            filter = cms.string('evtSelPrimaryEventVertexHighestPtTrackSum'),
            title = cms.string('Highest Pt Vertex')
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    'vertexHistManagerForElecTauBgEstZtautauEnriched'
                                    ),
        ),         
        cms.PSet(
            filter = cms.string('electronIdCutBgEstZtautauEnriched'),
            title = cms.string('Electron ID'),
        ),
        cms.PSet(
            filter = cms.string('electronAntiCrackCutBgEstZtautauEnriched'),
            title = cms.string('Electron crack-Veto'),
        ),
        cms.PSet(
            filter = cms.string('electronEtaCutBgEstZtautauEnriched'),
            title = cms.string('-2.5 < eta(Electron) < +2.5'),
        ),
        cms.PSet(
            filter = cms.string('electronPtCutBgEstZtautauEnriched'),
            title = cms.string('Pt(Electron) > 20 GeV'),
        ),
        cms.PSet(
            filter = cms.string('tauAntiOverlapWithElectronsVetoBgEstZtautauEnriched'),
            title = cms.string('Tau not overlapping with Elec.'),
        ),
        cms.PSet(
            filter = cms.string('tauEtaCutBgEstZtautauEnriched'),
            title = cms.string('-2.3 < eta(Tau) < +2.3'),
        ),
        cms.PSet(
            filter = cms.string('tauPtCutBgEstZtautauEnriched'),
            title = cms.string('Pt(Tau) > 20 GeV'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    ),
            replace = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched.electronSource = electronsBgEstZtautauEnrichedPtCumulative',
                                  'tauHistManagerForElecTauBgEstZtautauEnriched.tauSource = tausBgEstZtautauEnrichedPtCumulative'
                                  )
        ),
        cms.PSet(
            filter = cms.string('electronIsoCutBgEstZtautauEnriched'),
            title = cms.string('Electron Isolation'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    ),
            replace = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched.electronSource = electronsBgEstZtautauEnrichedIsoCumulative')
        ),   
        cms.PSet(
            filter = cms.string('electronConversionVetoBgEstZtautauEnriched'),
            title = cms.string('Electron Track conversion veto'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    ),
            replace = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched.electronSource = electronsBgEstZtautauEnrichedConversionVetoCumulative')
        ), 
        cms.PSet(
            filter = cms.string('electronTrkIPcutBgEstZtautauEnriched'),
            title = cms.string('Electron Track IP'),
        ),
        cms.PSet(
            filter = cms.string('tauLeadTrkPtCutBgEstZtautauEnriched'),
            title = cms.string('Tau lead. Track Pt'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    ),
            replace = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched.electronSource = electronsBgEstZtautauEnrichedTrkIPcumulative',
                                  'tauHistManagerForElecTauBgEstZtautauEnriched.tauSource = tausBgEstZtautauEnrichedLeadTrkPtCumulative'
                                  )
        ),
        cms.PSet(
            filter = cms.string('tauIsoCutBgEstZtautauEnriched'),
            title = cms.string('Tau ID'),
#            title = cms.string('Tau TaNC by Loose Isolation'),            
#            title = cms.string('Tau TaNC by 0.5%'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    ),
            replace = cms.vstring('tauHistManagerForElecTauBgEstZtautauEnriched.tauSource = tausBgEstZtautauEnrichedIsoCumulative')
        ),  
                
        cms.PSet(
            filter = cms.string('tauElectronVetoBgEstZtautauEnriched'),
            title = cms.string('Tau e-Veto'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    ),
            replace = cms.vstring('tauHistManagerForElecTauBgEstZtautauEnriched.tauSource = tausBgEstZtautauEnrichedElectronVetoCumulative')
        ),   
        
        cms.PSet(
            filter = cms.string('tauMuonVetoBgEstZtautauEnriched'),
            title = cms.string('Tau mu-Veto'),
        ),
        cms.PSet(
            filter = cms.string('diTauCandidateAntiOverlapVetoBgEstZtautauEnriched'),
            title = cms.string('dR(Electron-Tau) > 0.5'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateNSVfitHistManagerForElecTauBgEstZtautauEnriched'
                                    
                                    ),
            replace = cms.vstring('tauHistManagerForElecTauBgEstZtautauEnriched.tauSource = tausBgEstZtautauEnrichedMuonVetoCumulative',
                                  'diTauCandidateHistManagerForElecTauBgEstZtautauEnriched.diTauCandidateSource = elecTauPairsBgEstZtautauEnrichedAntiOverlapVetoCumulative',
                                  'diTauCandidateNSVfitHistManagerForElecTauBgEstZtautauEnriched.diTauCandidateSource = elecTauPairsBgEstZtautauEnrichedAntiOverlapVetoCumulative'                                  
                                  )
        ), 
        cms.PSet(
            filter = cms.string('diTauCandidateMt1METCutBgEstZtautauEnriched'),
            title = cms.string('M_{T}(Electron-MET) < 40 GeV (off)'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateNSVfitHistManagerForElecTauBgEstZtautauEnriched'                                    
                                    
                                    ),
        ),   
        cms.PSet(
            filter = cms.string('diTauCandidatePzetaDiffCutBgEstZtautauEnriched'),
            title = cms.string('Pzeta-1.5*Pzeta(vis) > -20 GeV'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateNSVfitHistManagerForElecTauBgEstZtautauEnriched'                                    
                                    ),
        ), 
        cms.PSet(
            filter = cms.string('diTauCandidateZeeHypothesisVetoBgEstZtautauEnriched'),
            title = cms.string('no 2nd OS, loosely-isolated electron'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateNSVfitHistManagerForElecTauBgEstZtautauEnriched',
                                    'vertexHistManagerForElecTauBgEstZtautauEnriched'
                                    ),
            
        ),   
        cms.PSet(
            filter = cms.string('diTauCandidateZeroChargeCutBgEstZtautauEnriched'),
            title = cms.string('Charge(Electron+Tau) = 0'),
            saveRunLumiSectionEventNumbers = cms.vstring('passed_cumulative')
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateNSVfitHistManagerForElecTauBgEstZtautauEnriched',
                                    'vertexHistManagerForElecTauBgEstZtautauEnriched',
                                    ),
        ),        

    )

)







analyzeEventsBgEstZtautauEnrichedBtag = cms.EDAnalyzer("GenericAnalyzer",

    name = cms.string('BgEstTemplateAnalyzer_ZtautauEnrichedBtag'), 

    filters = cms.VPSet(
        evtSelGenPhaseSpace,
        evtSelTrigger,
        evtSelPrimaryEventVertexQuality,
        evtSelPrimaryEventVertexPosition,        
        evtSelPrimaryEventVertexHighestPtTrackSum,
        #start electron cuts
        
        cms.PSet(
            pluginName = cms.string('electronIdCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('electronIdCutBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('electronAntiCrackCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('electronAntiCrackCutBgEstZtautauEnriched','cumulative')
        ),        
        cms.PSet(
            pluginName = cms.string('electronEtaCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('electronEtaCutBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('electronPtCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('electronPtCutBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('electronIsoCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('electronIsoCutBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('electronConversionVetoBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('electronConversionVetoBgEstZtautauEnriched','cumulative')
        ),        
        cms.PSet(
            pluginName = cms.string('electronTrkIPcutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('electronTrkIPcutBgEstZtautauEnriched','cumulative')
        ),


        #start tau cuts
        
        cms.PSet(
            pluginName = cms.string('tauAntiOverlapWithElectronsVetoBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('tauAntiOverlapWithElectronsVetoBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('tauEtaCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('tauEtaCutBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('tauPtCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('tauPtCutBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('tauLeadTrkPtCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('tauLeadTrkPtCutBgEstZtautauEnriched','cumulative')
        ),  
        cms.PSet(
            pluginName = cms.string('tauIsoCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('tauIsoCutBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('tauElectronVetoBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('tauElectronVetoBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('tauMuonVetoBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('tauMuonVetoBgEstZtautauEnriched','cumulative')
        ),

        #start ditau cuts
        
        cms.PSet(
            pluginName = cms.string('diTauCandidateAntiOverlapVetoBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('diTauCandidateAntiOverlapVetoBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('diTauCandidateMt1METCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('diTauCandidateMt1METCutBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('diTauCandidatePzetaDiffCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('diTauCandidatePzetaDiffCutBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('diTauCandidateZeeHypothesisVetoBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('diTauCandidateZeeHypothesisVetoBgEstZtautauEnriched')
        ),
        cms.PSet(
            pluginName = cms.string('jetEtCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('jetEtCutBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('jetBtagBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('jetBtagBgEstZtautauEnriched','cumulative')
        ), 
        cms.PSet(
            pluginName = cms.string('diTauCandidateZeroChargeCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('diTauCandidateZeroChargeCutBgEstZtautauEnriched','cumulative')
        ),
        
        
    ),
  
    analyzers = cms.VPSet(
         diTauCandidateHistManagerForElecTauBgEstZtautauEnriched,
         electronHistManagerForElecTauBgEstZtautauEnriched,
         tauHistManagerForElecTauBgEstZtautauEnriched,
         diTauCandidateNSVfitHistManagerForElecTauBgEstZtautauEnriched,
         vertexHistManagerForElecTauBgEstZtautauEnriched,
         jetHistManagerForElecTauBgEstZtautauEnriched         
    ),

    #eventDumps = cms.VPSet(elecTauEventDump),


    analysisSequence = cms.VPSet(
    
        # generator level phase-space selection
        # (NOTE: (1) to be used in case of Monte Carlo samples
        #            overlapping in simulated phase-space only !!
        #        (2) genPhaseSpaceCut needs to be **always** the first entry in the list of cuts
        #           - otherwise the script submitToBatch.csh for submission of cmsRun jobs
        #            to the CERN batch system will not work !!)

        cms.PSet(
            filter = cms.string('genPhaseSpaceCut'),
            title = cms.string('gen. Phase-Space')
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    'jetHistManagerForElecTauBgEstZtautauEnriched'                                    
                                    ),
            replace = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched.electronSource = cleanPatElectrons',
                                  'tauHistManagerForElecTauBgEstZtautauEnriched.tauSource = cleanPatTaus',
                                  'jetHistManagerForElecTauBgEstZtautauEnriched.jetSource = patJets'
                                  )
        ),
        
        cms.PSet(
            filter = cms.string('evtSelTrigger'),
            title = cms.string('Trigger'),
        ),
        cms.PSet(
            filter = cms.string('evtSelPrimaryEventVertexQuality'),
            title = cms.string('Valid vertex with #dof >= 4')
        ),
        cms.PSet(
            filter = cms.string('evtSelPrimaryEventVertexPosition'),
            title = cms.string('Vertex abs(z) < 24 & Rho < 2')
        ),
        cms.PSet(
            filter = cms.string('evtSelPrimaryEventVertexHighestPtTrackSum'),
            title = cms.string('Highest Pt Vertex')
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    'vertexHistManagerForElecTauBgEstZtautauEnriched'
                                    ),
        ),         
        cms.PSet(
            filter = cms.string('electronIdCutBgEstZtautauEnriched'),
            title = cms.string('Electron ID'),
        ),
        cms.PSet(
            filter = cms.string('electronAntiCrackCutBgEstZtautauEnriched'),
            title = cms.string('Electron crack-Veto'),
        ),
        cms.PSet(
            filter = cms.string('electronEtaCutBgEstZtautauEnriched'),
            title = cms.string('-2.5 < eta(Electron) < +2.5'),
        ),
        cms.PSet(
            filter = cms.string('electronPtCutBgEstZtautauEnriched'),
            title = cms.string('Pt(Electron) > 20 GeV'),
        ),
        cms.PSet(
            filter = cms.string('tauAntiOverlapWithElectronsVetoBgEstZtautauEnriched'),
            title = cms.string('Tau not overlapping with Elec.'),
        ),
        cms.PSet(
            filter = cms.string('tauEtaCutBgEstZtautauEnriched'),
            title = cms.string('-2.3 < eta(Tau) < +2.3'),
        ),
        cms.PSet(
            filter = cms.string('tauPtCutBgEstZtautauEnriched'),
            title = cms.string('Pt(Tau) > 20 GeV'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    ),
            replace = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched.electronSource = electronsBgEstZtautauEnrichedPtCumulative',
                                  'tauHistManagerForElecTauBgEstZtautauEnriched.tauSource = tausBgEstZtautauEnrichedPtCumulative'
                                  )
        ),
        cms.PSet(
            filter = cms.string('electronIsoCutBgEstZtautauEnriched'),
            title = cms.string('Electron Isolation'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    ),
            replace = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched.electronSource = electronsBgEstZtautauEnrichedIsoCumulative')
        ),   
        cms.PSet(
            filter = cms.string('electronConversionVetoBgEstZtautauEnriched'),
            title = cms.string('Electron Track conversion veto'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    ),
            replace = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched.electronSource = electronsBgEstZtautauEnrichedConversionVetoCumulative')
        ), 
        cms.PSet(
            filter = cms.string('electronTrkIPcutBgEstZtautauEnriched'),
            title = cms.string('Electron Track IP'),
        ),
        cms.PSet(
            filter = cms.string('tauLeadTrkPtCutBgEstZtautauEnriched'),
            title = cms.string('Tau lead. Track Pt'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    ),
            replace = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched.electronSource = electronsBgEstZtautauEnrichedTrkIPcumulative',
                                  'tauHistManagerForElecTauBgEstZtautauEnriched.tauSource = tausBgEstZtautauEnrichedLeadTrkPtCumulative'
                                  )
        ),
        cms.PSet(
            filter = cms.string('tauIsoCutBgEstZtautauEnriched'),
            title = cms.string('Tau ID'),
#            title = cms.string('Tau TaNC by Loose Isolation'),            
#            title = cms.string('Tau TaNC by 0.5%'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    ),
            replace = cms.vstring('tauHistManagerForElecTauBgEstZtautauEnriched.tauSource = tausBgEstZtautauEnrichedIsoCumulative')
        ),  
                
        cms.PSet(
            filter = cms.string('tauElectronVetoBgEstZtautauEnriched'),
            title = cms.string('Tau e-Veto'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    ),
            replace = cms.vstring('tauHistManagerForElecTauBgEstZtautauEnriched.tauSource = tausBgEstZtautauEnrichedElectronVetoCumulative')
        ),   
        
        cms.PSet(
            filter = cms.string('tauMuonVetoBgEstZtautauEnriched'),
            title = cms.string('Tau mu-Veto'),
        ),
        cms.PSet(
            filter = cms.string('diTauCandidateAntiOverlapVetoBgEstZtautauEnriched'),
            title = cms.string('dR(Electron-Tau) > 0.5'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateNSVfitHistManagerForElecTauBgEstZtautauEnriched'
                                    
                                    ),
            replace = cms.vstring('tauHistManagerForElecTauBgEstZtautauEnriched.tauSource = tausBgEstZtautauEnrichedMuonVetoCumulative',
                                  'diTauCandidateHistManagerForElecTauBgEstZtautauEnriched.diTauCandidateSource = elecTauPairsBgEstZtautauEnrichedAntiOverlapVetoCumulative',
                                  'diTauCandidateNSVfitHistManagerForElecTauBgEstZtautauEnriched.diTauCandidateSource = elecTauPairsBgEstZtautauEnrichedAntiOverlapVetoCumulative'                                  
                                  )
        ), 
        cms.PSet(
            filter = cms.string('diTauCandidateMt1METCutBgEstZtautauEnriched'),
            title = cms.string('M_{T}(Electron-MET) < 40 GeV (off)'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateNSVfitHistManagerForElecTauBgEstZtautauEnriched'                                    
                                    
                                    ),
        ),   
        cms.PSet(
            filter = cms.string('diTauCandidatePzetaDiffCutBgEstZtautauEnriched'),
            title = cms.string('Pzeta-1.5*Pzeta(vis) > -20 GeV'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateNSVfitHistManagerForElecTauBgEstZtautauEnriched'                                    
                                    ),
        ), 
        cms.PSet(
            filter = cms.string('diTauCandidateZeeHypothesisVetoBgEstZtautauEnriched'),
            title = cms.string('no 2nd OS, loosely-isolated electron'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateNSVfitHistManagerForElecTauBgEstZtautauEnriched',
                                    'vertexHistManagerForElecTauBgEstZtautauEnriched',
                                    'jetHistManagerForElecTauBgEstZtautauEnriched'                                    
                                    ),
        ),
        cms.PSet(
            filter = cms.string('jetEtCutBgEstZtautauEnriched'),
            title = cms.string('N(jets with E_{T} > 30) < 2'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateNSVfitHistManagerForElecTauBgEstZtautauEnriched',
                                    'vertexHistManagerForElecTauBgEstZtautauEnriched',
                                    'jetHistManagerForElecTauBgEstZtautauEnriched'                                    
                                    ),
            replace = cms.vstring('jetHistManagerForElecTauBgEstZtautauEnriched.jetSource = jetsBgEstZtautauEnrichedJetTagCumulative')
        ),            
        cms.PSet(
            filter = cms.string('jetBtagBgEstZtautauEnriched'),
            title = cms.string('E_{T} > 20 GeV jet with b-Tag'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateNSVfitHistManagerForElecTauBgEstZtautauEnriched',
                                    'vertexHistManagerForElecTauBgEstZtautauEnriched',
                                    'jetHistManagerForElecTauBgEstZtautauEnriched'                                    
                                    ),
            replace = cms.vstring('jetHistManagerForElecTauBgEstZtautauEnriched.jetSource = jetsBgEstZtautauEnrichedJetBtagCumulative')
            
            
        ),   
        cms.PSet(
            filter = cms.string('diTauCandidateZeroChargeCutBgEstZtautauEnriched'),
            title = cms.string('Charge(Electron+Tau) = 0'),
            saveRunLumiSectionEventNumbers = cms.vstring('passed_cumulative')
        ),        
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateNSVfitHistManagerForElecTauBgEstZtautauEnriched',
                                    'vertexHistManagerForElecTauBgEstZtautauEnriched',
                                    'jetHistManagerForElecTauBgEstZtautauEnriched'                                    
                                    ),
        ),
    )

)




analyzeEventsBgEstZtautauEnrichedBtagVeto = cms.EDAnalyzer("GenericAnalyzer",

    name = cms.string('BgEstTemplateAnalyzer_ZtautauEnrichedBtagVeto'), 

    filters = cms.VPSet(
        evtSelGenPhaseSpace,
        evtSelTrigger,
        evtSelPrimaryEventVertexQuality,
        evtSelPrimaryEventVertexPosition,        
        evtSelPrimaryEventVertexHighestPtTrackSum,
        #start electron cuts
        
        cms.PSet(
            pluginName = cms.string('electronIdCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('electronIdCutBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('electronAntiCrackCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('electronAntiCrackCutBgEstZtautauEnriched','cumulative')
        ),        
        cms.PSet(
            pluginName = cms.string('electronEtaCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('electronEtaCutBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('electronPtCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('electronPtCutBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('electronIsoCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('electronIsoCutBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('electronConversionVetoBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('electronConversionVetoBgEstZtautauEnriched','cumulative')
        ),        
        cms.PSet(
            pluginName = cms.string('electronTrkIPcutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('electronTrkIPcutBgEstZtautauEnriched','cumulative')
        ),


        #start tau cuts
        
        cms.PSet(
            pluginName = cms.string('tauAntiOverlapWithElectronsVetoBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('tauAntiOverlapWithElectronsVetoBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('tauEtaCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('tauEtaCutBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('tauPtCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('tauPtCutBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('tauLeadTrkPtCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('tauLeadTrkPtCutBgEstZtautauEnriched','cumulative')
        ),  
        cms.PSet(
            pluginName = cms.string('tauIsoCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('tauIsoCutBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('tauElectronVetoBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('tauElectronVetoBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('tauMuonVetoBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('tauMuonVetoBgEstZtautauEnriched','cumulative')
        ),

        #start ditau cuts
        
        cms.PSet(
            pluginName = cms.string('diTauCandidateAntiOverlapVetoBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('diTauCandidateAntiOverlapVetoBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('diTauCandidateMt1METCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('diTauCandidateMt1METCutBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('diTauCandidatePzetaDiffCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('diTauCandidatePzetaDiffCutBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('diTauCandidateZeeHypothesisVetoBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('diTauCandidateZeeHypothesisVetoBgEstZtautauEnriched')
        ),
        cms.PSet(
            pluginName = cms.string('jetEtCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('jetEtCutBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('jetBtagVetoBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('jetBtagVetoBgEstZtautauEnriched','cumulative')
        ),
        cms.PSet(
            pluginName = cms.string('diTauCandidateZeroChargeCutBgEstZtautauEnriched'),
            pluginType = cms.string('BoolEventSelector'),
            src = cms.InputTag('diTauCandidateZeroChargeCutBgEstZtautauEnriched','cumulative')
        ),        
        
        
    ),
  
    analyzers = cms.VPSet(
         diTauCandidateHistManagerForElecTauBgEstZtautauEnriched,
         electronHistManagerForElecTauBgEstZtautauEnriched,
         tauHistManagerForElecTauBgEstZtautauEnriched,
         diTauCandidateNSVfitHistManagerForElecTauBgEstZtautauEnriched,
         vertexHistManagerForElecTauBgEstZtautauEnriched
    ),

    #eventDumps = cms.VPSet(elecTauEventDump),


    analysisSequence = cms.VPSet(
    
        # generator level phase-space selection
        # (NOTE: (1) to be used in case of Monte Carlo samples
        #            overlapping in simulated phase-space only !!
        #        (2) genPhaseSpaceCut needs to be **always** the first entry in the list of cuts
        #           - otherwise the script submitToBatch.csh for submission of cmsRun jobs
        #            to the CERN batch system will not work !!)

        cms.PSet(
            filter = cms.string('genPhaseSpaceCut'),
            title = cms.string('gen. Phase-Space')
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    ),
            replace = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched.electronSource = cleanPatElectrons',
                                  'tauHistManagerForElecTauBgEstZtautauEnriched.tauSource = cleanPatTaus'
                                  )
        ),    
        cms.PSet(
            filter = cms.string('evtSelTrigger'),
            title = cms.string('Trigger'),
        ),
        cms.PSet(
            filter = cms.string('evtSelPrimaryEventVertexQuality'),
            title = cms.string('Valid vertex with #dof >= 4')
        ),
        cms.PSet(
            filter = cms.string('evtSelPrimaryEventVertexPosition'),
            title = cms.string('Vertex abs(z) < 24 & Rho < 2')
        ),
        cms.PSet(
            filter = cms.string('evtSelPrimaryEventVertexHighestPtTrackSum'),
            title = cms.string('Highest Pt Vertex')
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    'vertexHistManagerForElecTauBgEstZtautauEnriched'
                                    ),
        ),         
        cms.PSet(
            filter = cms.string('electronIdCutBgEstZtautauEnriched'),
            title = cms.string('Electron ID'),
        ),
        cms.PSet(
            filter = cms.string('electronAntiCrackCutBgEstZtautauEnriched'),
            title = cms.string('Electron crack-Veto'),
        ),
        cms.PSet(
            filter = cms.string('electronEtaCutBgEstZtautauEnriched'),
            title = cms.string('-2.5 < eta(Electron) < +2.5'),
        ),
        cms.PSet(
            filter = cms.string('electronPtCutBgEstZtautauEnriched'),
            title = cms.string('Pt(Electron) > 20 GeV'),
        ),
        cms.PSet(
            filter = cms.string('tauAntiOverlapWithElectronsVetoBgEstZtautauEnriched'),
            title = cms.string('Tau not overlapping with Elec.'),
        ),
        cms.PSet(
            filter = cms.string('tauEtaCutBgEstZtautauEnriched'),
            title = cms.string('-2.3 < eta(Tau) < +2.3'),
        ),
        cms.PSet(
            filter = cms.string('tauPtCutBgEstZtautauEnriched'),
            title = cms.string('Pt(Tau) > 20 GeV'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    ),
            replace = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched.electronSource = electronsBgEstZtautauEnrichedPtCumulative',
                                  'tauHistManagerForElecTauBgEstZtautauEnriched.tauSource = tausBgEstZtautauEnrichedPtCumulative'
                                  )
        ),
        cms.PSet(
            filter = cms.string('electronIsoCutBgEstZtautauEnriched'),
            title = cms.string('Electron Isolation'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    ),
            replace = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched.electronSource = electronsBgEstZtautauEnrichedIsoCumulative')
        ),   
        cms.PSet(
            filter = cms.string('electronConversionVetoBgEstZtautauEnriched'),
            title = cms.string('Electron Track conversion veto'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    ),
            replace = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched.electronSource = electronsBgEstZtautauEnrichedConversionVetoCumulative')
        ), 
        cms.PSet(
            filter = cms.string('electronTrkIPcutBgEstZtautauEnriched'),
            title = cms.string('Electron Track IP'),
        ),
        cms.PSet(
            filter = cms.string('tauLeadTrkPtCutBgEstZtautauEnriched'),
            title = cms.string('Tau lead. Track Pt'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    ),
            replace = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched.electronSource = electronsBgEstZtautauEnrichedTrkIPcumulative',
                                  'tauHistManagerForElecTauBgEstZtautauEnriched.tauSource = tausBgEstZtautauEnrichedLeadTrkPtCumulative'
                                  )
        ),
        cms.PSet(
            filter = cms.string('tauIsoCutBgEstZtautauEnriched'),
            title = cms.string('Tau ID'),
#            title = cms.string('Tau TaNC by Loose Isolation'),            
#            title = cms.string('Tau TaNC by 0.5%'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    ),
            replace = cms.vstring('tauHistManagerForElecTauBgEstZtautauEnriched.tauSource = tausBgEstZtautauEnrichedIsoCumulative')
        ),  
                
        cms.PSet(
            filter = cms.string('tauElectronVetoBgEstZtautauEnriched'),
            title = cms.string('Tau e-Veto'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    ),
            replace = cms.vstring('tauHistManagerForElecTauBgEstZtautauEnriched.tauSource = tausBgEstZtautauEnrichedElectronVetoCumulative')
        ),   
        
        cms.PSet(
            filter = cms.string('tauMuonVetoBgEstZtautauEnriched'),
            title = cms.string('Tau mu-Veto'),
        ),
        cms.PSet(
            filter = cms.string('diTauCandidateAntiOverlapVetoBgEstZtautauEnriched'),
            title = cms.string('dR(Electron-Tau) > 0.5'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateNSVfitHistManagerForElecTauBgEstZtautauEnriched'
                                    
                                    ),
            replace = cms.vstring('tauHistManagerForElecTauBgEstZtautauEnriched.tauSource = tausBgEstZtautauEnrichedMuonVetoCumulative',
                                  'diTauCandidateHistManagerForElecTauBgEstZtautauEnriched.diTauCandidateSource = elecTauPairsBgEstZtautauEnrichedAntiOverlapVetoCumulative',
                                  'diTauCandidateNSVfitHistManagerForElecTauBgEstZtautauEnriched.diTauCandidateSource = elecTauPairsBgEstZtautauEnrichedAntiOverlapVetoCumulative'                                  
                                  )
        ), 
        cms.PSet(
            filter = cms.string('diTauCandidateMt1METCutBgEstZtautauEnriched'),
            title = cms.string('M_{T}(Electron-MET) < 40 GeV (off)'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateNSVfitHistManagerForElecTauBgEstZtautauEnriched'                                    
                                    
                                    ),
        ),   
        cms.PSet(
            filter = cms.string('diTauCandidatePzetaDiffCutBgEstZtautauEnriched'),
            title = cms.string('Pzeta-1.5*Pzeta(vis) > -20 GeV'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateNSVfitHistManagerForElecTauBgEstZtautauEnriched'                                    
                                    ),
        ),  
        cms.PSet(
            filter = cms.string('diTauCandidateZeeHypothesisVetoBgEstZtautauEnriched'),
            title = cms.string('no 2nd OS, loosely-isolated electron'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateNSVfitHistManagerForElecTauBgEstZtautauEnriched',
                                    'vertexHistManagerForElecTauBgEstZtautauEnriched'
                                    ),
        ),
        cms.PSet(
            filter = cms.string('jetEtCutBgEstZtautauEnriched'),
            title = cms.string('N(jets with E_{T} > 30) < 2'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateNSVfitHistManagerForElecTauBgEstZtautauEnriched',
                                    'vertexHistManagerForElecTauBgEstZtautauEnriched'
                                    ),
        ),            
        cms.PSet(
            filter = cms.string('jetBtagVetoBgEstZtautauEnriched'),
            title = cms.string('no E_{T} > 20 GeV jet with b-Tag'),
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateNSVfitHistManagerForElecTauBgEstZtautauEnriched',
                                    'vertexHistManagerForElecTauBgEstZtautauEnriched'
                                    ),
        ),
        cms.PSet(
            filter = cms.string('diTauCandidateZeroChargeCutBgEstZtautauEnriched'),
            title = cms.string('Charge(Electron+Tau) = 0'),
            saveRunLumiSectionEventNumbers = cms.vstring('passed_cumulative')        
        ),
        cms.PSet(
            analyzers = cms.vstring('electronHistManagerForElecTauBgEstZtautauEnriched',
                                    'tauHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateHistManagerForElecTauBgEstZtautauEnriched',
                                    'diTauCandidateNSVfitHistManagerForElecTauBgEstZtautauEnriched',
                                    'vertexHistManagerForElecTauBgEstZtautauEnriched',
                                    ),
        ),         

    )

)





#--------------------------------------------------------------------------------  
# define (final) analysis sequence
#--------------------------------------------------------------------------------

bgEstZtautauEnrichedAnalysisSequence = cms.Sequence(
    selectElectronsBgEstZtautauEnriched
    + selectTausBgEstZtautauEnriched
    + produceElecTauPairsBgEstZtautauEnriched
    + selectElecTauPairsBgEstZtautauEnriched
    + produceElecTauPairZeeHypothesesBgEstZtautauEnriched
    + selectPatJetsBgEstZtautauEnriched
    + selectEventsBgEstZtautauEnriched
    #+ analyzeEventsBgEstZtautauEnriched
    + analyzeEventsBgEstZtautauEnrichedBtag
    + analyzeEventsBgEstZtautauEnrichedBtagVeto   
    

)


