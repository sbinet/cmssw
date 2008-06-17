import FWCore.ParameterSet.Config as cms

import copy
from HLTrigger.HLTfilters.hltHighLevel_cfi import *
lepSUSY_0Muon_1Elec_1Jets_MET_HLTPath = copy.deepcopy(hltHighLevel)
import copy
from HLTrigger.HLTfilters.hltHighLevel_cfi import *
lepSUSY_0Muon_1Elec_2Jets_MET_HLTPath = copy.deepcopy(hltHighLevel)
import copy
from HLTrigger.HLTfilters.hltHighLevel_cfi import *
lepSUSY_0Muon_2Elec_2Jets_MET_HLTPath = copy.deepcopy(hltHighLevel)
import copy
from HLTrigger.HLTfilters.hltHighLevel_cfi import *
lepSUSY_1Muon_0Elec_1Jets_MET_HLTPath = copy.deepcopy(hltHighLevel)
import copy
from HLTrigger.HLTfilters.hltHighLevel_cfi import *
lepSUSY_1Muon_0Elec_2Jets_MET_HLTPath = copy.deepcopy(hltHighLevel)
import copy
from HLTrigger.HLTfilters.hltHighLevel_cfi import *
lepSUSY_1Muon_1Elec_2Jets_MET_HLTPath = copy.deepcopy(hltHighLevel)
import copy
from HLTrigger.HLTfilters.hltHighLevel_cfi import *
lepSUSY_2Muon_0Elec_2Jets_MET_HLTPath = copy.deepcopy(hltHighLevel)
lepSUSY_0Muon_1Elec_1Jets_MET_HLTPath.HLTPaths = ['HLT_IsoEle15_L1I', 'HLT_IsoEle18_L1R', 'HLT_DoubleIsoEle10_L1I', 'HLT_DoubleIsoEle12_L1R', 'HLT1jet', 
    'HLT_DoubleJet150', 'HLT_IsoEle12_Jet40']
lepSUSY_0Muon_1Elec_2Jets_MET_HLTPath.HLTPaths = ['HLT1jet', 'HLT_DoubleJet150', 'HLT_TripleJet85', 'HLT1jetPE1', 'HLT1jetPE3', 
    'HLT1jetPE5', 'HLT_Jet180_MET60', 'HLT_DoubleJet125_MET60', 'HLT_MET35_HT350', 'HLT_IsoEle12_Jet40', 
    'HLT_IsoEle12_DoubleJet80', 'HLT_DoubleJet125_Aco', 'HLT_Jet100_MET60_Aco', 'HLT_Jet80_Jet20_MET60_NV', 'HLT_DoubleJet60_MET60_Aco', 
    'CandHLTSjet1MET1Aco', 'CandHLTSjet2MET1Aco', 'CandHLTS2jetAco']
lepSUSY_0Muon_2Elec_2Jets_MET_HLTPath.HLTPaths = ['HLT_IsoEle15_L1I', 'HLT_IsoEle18_L1R', 'HLT_DoubleIsoEle10_L1I', 'HLT_DoubleIsoEle12_L1R', 'HLT_IsoEle12_Jet40', 
    'HLT_IsoEle12_DoubleJet80', 'HLT_IsoEle12_TripleJet60', 'HLT_TripleJet85', 'HLT_QuadJet60']
lepSUSY_1Muon_0Elec_1Jets_MET_HLTPath.HLTPaths = ['HLT_IsoMu11', 'HLT_Mu15_L1Mu7', 'HLT_DoubleMu3', 'HLT_DoubleMu3_SameSign', 'HLT_IsoMu7_Jet40']
lepSUSY_1Muon_0Elec_2Jets_MET_HLTPath.HLTPaths = ['HLT1jet', 'HLT_DoubleJet150', 'HLT1jetPE1', 'HLT1jetPE3', 'HLT1jetPE5', 
    'HLT_Jet180_MET60', 'HLT_DoubleJet125_MET60', 'HLT_MET35_HT350', 'HLT_IsoMu7_Jet40', 'HLT_DoubleJet125_Aco', 
    'HLT_Jet100_MET60_Aco', 'HLT_Jet80_Jet20_MET60_NV', 'HLT_DoubleJet60_MET60_Aco', 'CandHLTSjet1MET1Aco', 'CandHLTSjet2MET1Aco', 
    'CandHLTS2jetAco']
lepSUSY_1Muon_1Elec_2Jets_MET_HLTPath.HLTPaths = ['HLT_IsoMu11', 'HLT_Mu15_L1Mu7', 'HLT_IsoEle15_L1I', 'HLT_IsoEle18_L1R', 'HLT_IsoEle8_IsoMu7', 
    'HLT_IsoEle10_Mu10_L1R', 'HLT_IsoEle12_Jet40', 'HLT_IsoEle12_DoubleJet80', 'HLT_IsoMu7_Jet40']
lepSUSY_2Muon_0Elec_2Jets_MET_HLTPath.HLTPaths = ['HLT_IsoMu11', 'HLT_Mu15_L1Mu7', 'HLT_DoubleMu3', 'HLT_DoubleMu3_SameSign', 'HLT_IsoMu7_Jet40']

