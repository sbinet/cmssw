# The following comments couldn't be translated into the new config version:

# It might be necessary to have the xml file locally to activate the miscalibration
#include "FastSimulation/Configuration/data/MisCalibration.cff"

import FWCore.ParameterSet.Config as cms

process = cms.Process("PROD")
#The module which reade from a HepMC ASCII file
#   source = MCFileSource
#   {
#      # The HepMC test File
#      untracked vstring fileNames = {"SherpaWriteHepMC.dat"}
#   }
# Include the RandomNumberGeneratorService definition
process.load("FastSimulation.Configuration.RandomServiceInitialization_cff")

# 
# source = FlatRandomEGunSource 
# {	 
# untracked uint32 firstRun  = 1
# untracked      PSet  PGunParameters =
# {
# # you can request more than 1 particle
# #untracked vint32  PartID = { 211, 11, -13 }
# untracked vint32 PartID = {11} 
# untracked double MinEta = 0.0
# untracked double MaxEta = 0.5
# untracked double MinPhi = -3.14159265358979323846  # it must be in radians
# untracked double MaxPhi =  3.14159265358979323846
# untracked double MinE   = 200.
# untracked double MaxE   = 200.
# }      
# untracked int32 Verbosity = 0 # for printouts, set it to 1 (or greater)   
# }
# 
process.load("DQMServices.Core.DQM_cfg")

# Famos SimHits 
process.load("FastSimulation.Configuration.CommonInputsFake_cff")

process.load("FastSimulation.Configuration.FamosSequences_cff")

#    endpath outpath = { o1 }
# To get rid of the CaloNumbering messages 
# Keep the logging output to a nice level #
process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(100)
)
process.source = cms.Source("PythiaSource",
    PythiaParameters = cms.PSet(
        #
        # Default cards for minimum bias events (unfiltered)
        # Name of the set is "pythiaMinBias"
        #include "IOMC/GeneratorInterface/test/pythiaMinBias.cfg"
        #
        # User cards - name is "myParameters"
        # Pythia's random generator initialization 
        myParameters = cms.vstring('MSEL=0 ! Users defined processes', 
            'MSUB(102)=1 ! Define the process : gg -> H', 
            'PMAS(23,1)=91.188 ! Z mass', 
            'PMAS(24,1)=80.450 ! W mass', 
            'PMAS(25,1)=180.00 ! H mass', 
            'MDME(210,1)=0 ! Switch off Higgs decay channels', 
            'MDME(211,1)=0', 
            'MDME(212,1)=0', 
            'MDME(213,1)=0', 
            'MDME(214,1)=0', 
            'MDME(215,1)=0', 
            'MDME(216,1)=0', 
            'MDME(217,1)=0', 
            'MDME(218,1)=0', 
            'MDME(219,1)=0', 
            'MDME(220,1)=0', 
            'MDME(221,1)=0', 
            'MDME(222,1)=0', 
            'MDME(223,1)=0', 
            'MDME(224,1)=0', 
            'MDME(225,1)=1 ! H -> ZZ switched on', 
            'MDME(226,1)=0', 
            'MDME(174,1)=0 ! Switch off Z decay channels', 
            'MDME(175,1)=0', 
            'MDME(176,1)=0', 
            'MDME(177,1)=0', 
            'MDME(178,1)=0', 
            'MDME(179,1)=0', 
            'MDME(180,1)=0', 
            'MDME(181,1)=0', 
            'MDME(182,1)=1 ! Z -> e+e- switched on', 
            'MDME(183,1)=0', 
            'MDME(184,1)=1 ! Z -> mu+mu- switched on', 
            'MDME(185,1)=0', 
            'MDME(186,1)=0', 
            'MDME(187,1)=0', 
            'MSTJ(22)=2   ! Do not decay unstable particles', 
            'PARJ(71)=10. ! with c*tau > cTauMin (in mm) in PYTHIA'),
        # This is a vector of ParameterSet names to be read, in this order
        # The first two are in the include files below
        # The last one are simply my additional parameters
        parameterSets = cms.vstring('myParameters')
    )
)

process.o1 = cms.OutputModule("PoolOutputModule",
    fileName = cms.untracked.string('test-cfg.root')
)

process.digiCheck = cms.EDFilter("DigiCheck")

process.p1 = cms.Path(process.famosWithCaloHits*process.digiCheck)
process.load("Configuration.StandardSequences.MagneticField_40T_cff")
#process.load("Configuration.StandardSequences.MagneticField_38T_cff")
process.VolumeBasedMagneticFieldESProducer.useParametrizedTrackerField = True
process.famosSimHits.SimulateCalorimetry = True
process.famosSimHits.SimulateTracking = False
process.caloRecHits.RecHitsFactory.doDigis = True
process.MessageLogger.destinations = ['detailedInfo.txt']


