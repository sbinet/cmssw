import FWCore.ParameterSet.Config as cms

process = cms.Process("PROD")
process.load('Configuration.Generator.PythiaUESettings_cfi')
process.load("HeavyFlavorAnalysis.Examples.Bp2JpsiKp_cff")

process.load("HeavyFlavorAnalysis.Examples.HFExample_cff")
process.load("FastSimulation/Configuration/FamosSequences_cff")
process.load("HeavyFlavorAnalysis.Examples.famos_cff")

#process.load("HeavyFlavorAnalysis.Examples.HFFamosReplacements_cff")
process.trkDump.muonsLabel = 'paramMuons:ParamGlobalMuons'
process.trkDump.tracksLabel = 'generalTracks'
process.trkDump.doTruthMatching = 2
process.signalDump.muonsLabel = 'paramMuons:ParamGlobalMuons'
process.signalDump.tracksLabel = 'generalTracks'
process.trkDump.verbose = 0
process.signalDump.verbose = 1
process.genParticles.src = 'evtgenproducer'
process.genParticles.abortOnUnknownPDGCode = False
process.trkDump.generatorEventLabel = 'evtgenproducer'
process.famosSimHits.SourceLabel = 'evtgenproducer'

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(10000)
)


process.RandomNumberGeneratorService = cms.Service("RandomNumberGeneratorService",
    moduleSeeds = cms.PSet(
        g4SimHits = cms.untracked.uint32(11),
        evtgenproducer = cms.untracked.uint32(1234566),
        mix = cms.untracked.uint32(12345),
        VtxSmeared = cms.untracked.uint32(98765432),
        caloRecHits = cms.untracked.uint32(654321),
        MuonSimHits = cms.untracked.uint32(97531),
        muonCSCDigis = cms.untracked.uint32(525432),
        muonDTDigis = cms.untracked.uint32(67673876),
        famosSimHits = cms.untracked.uint32(13579),
        paramMuons = cms.untracked.uint32(54525),
        famosPileUp = cms.untracked.uint32(918273),
        muonRPCDigis = cms.untracked.uint32(524964),
        siTrackerGaussianSmearingRecHits = cms.untracked.uint32(24680),
        simMuonCSCDigis = cms.untracked.uint32(12345),
        simMuonDTDigis = cms.untracked.uint32(12345),
        simMuonRPCDigis = cms.untracked.uint32(12345)
    ),
    sourceSeed = cms.untracked.uint32(15678956)
)


process.evtgenproducer = cms.EDProducer("EvtGenProducer",
    use_default_decay = cms.untracked.bool(False),
    decay_table = cms.FileInPath('GeneratorInterface/EvtGenInterface//data/DECAY.DEC'),
    particle_property_file = cms.FileInPath('GeneratorInterface/EvtGenInterface/data/evt.pdl'),
    user_decay_file = cms.FileInPath('GeneratorInterface/EvtGenInterface/data/incl_BtoJpsi_mumu.dec'),
    list_forced_decays = cms.vstring(
        'MyB+', 
        'MyB-'), 
    processParameters = cms.vstring('MDCY(134,1) = 0', 
        'MDCY(137,1) = 0', 
        'MDCY(138,1) = 0', 
        'MDCY(135,1) = 0', 
        'MDCY(141,1) = 0', 
        'MDCY(140,1) = 0', 
        'MDCY(15,1) = 0', 
        'MDCY(123,1) = 0', 
        'MDCY(126,1) = 0', 
        'MDCY(129,1) = 0', 
        'MDCY(122,1) = 0', 
        'MDCY(125,1) = 0', 
        'MDCY(128,1) = 0', 
        'MDCY(262,1) = 0', 
        'MDCY(264,1) = 0', 
        'MDCY(263,1) = 0', 
        'MDCY(265,1) = 0', 
        'MDCY(286,1) = 0', 
        'MDCY(287,1) = 0', 
        'MDCY(124,1) = 0', 
        'MDCY(127,1) = 0', 
        'MDCY(266,1) = 0', 
        'MDCY(288,1) = 0', 
        'MDCY(267,1) = 0', 
        'MDCY(130,1) = 0', 
        'MDCY(112,1) = 0', 
        'MDCY(113,1) = 0', 
        'MDCY(114,1) = 0', 
        'MDCY(117,1) = 0', 
        'MDCY(258,1) = 0', 
        'MDCY(256,1) = 0', 
        'MDCY(257,1) = 0', 
        'MDCY(259,1) = 0', 
        'MDCY(284,1) = 0', 
        'MDCY(283,1) = 0', 
        'MDCY(118,1) = 0', 
        'MDCY(115,1) = 0', 
        'MDCY(102,1) = 0', 
        'MDCY(109,1) = 0', 
        'MDCY(103,1) = 0', 
        'MDCY(107,1) = 0', 
        'MDCY(110,1) = 0', 
        'MDCY(119,1) = 0', 
        'MDCY(120,1) = 0', 
        'MDCY(281,1) = 0', 
        'MDCY(280,1) = 0', 
        'MDCY(281,1) = 0', 
        'MDCY(108,1) = 0', 
        'MDCY(104,1) = 0', 
        'MDCY(253,1) = 0', 
        'MDCY(251,1) = 0', 
        'MDCY(250,1) = 0', 
        'MDCY(252,1) = 0', 
        'MDCY(254,1) = 0', 
        'MDCY(282,1) = 0', 
        'MDCY(285,1) = 0', 
        'MDCY(111,1) = 0', 
        'MDCY(121,1) = 0', 
        'MDCY(255,1) = 0', 
        'MDCY(261,1) = 0', 
        'MDCY(131,1) = 0', 
        'MDCY(132,1) = 0', 
        'MDCY(295,1) = 0', 
        'MDCY(268,1) = 0', 
        'MDCY(289,1) = 0', 
        'MDCY(133,1) = 0', 
        'MDCY(146,1) = 0', 
        'MDCY(147,1) = 0', 
        'MDCY(296,1) = 0', 
        'MDCY(278,1) = 0', 
        'MDCY(294,1) = 0', 
        'MDCY(148,1) = 0', 
        'MDCY(279,1) = 0', 
        'MDCY(181,1) = 0', 
        'MDCY(182,1) = 0', 
        'MDCY(84,1) = 0', 
        'MDCY(179,1) = 0', 
        'MDCY(185,1) = 0', 
        'MDCY(189,1) = 0', 
        'MDCY(187,1) = 0', 
        'MDCY(194,1) = 0', 
        'MDCY(192,1) = 0', 
        'MDCY(164,1) = 0', 
        'MDCY(169,1) = 0', 
        'MDCY(158,1) = 0', 
        'MDCY(159,1) = 0', 
        'MDCY(175,1) = 0', 
        'MDCY(155,1) = 0', 
        'MDCY(151,1) = 0', 
        'MDCY(162,1) = 0', 
        'MDCY(167,1) = 0', 
        'MDCY(163,1) = 0', 
        'MDCY(170,1) = 0', 
        'MDCY(168,1) = 0', 
        'MDCY(174,1) = 0', 
        'MDCY(172,1) = 0', 
        'MDCY(173,1) = 0', 
        'MDCY(176,1) = 0', 
        'MDCY(180,1) = 0', 
        'MDCY(186,1) = 0', 
        'MDCY(188,1) = 0', 
        'MDCY(193,1) = 0', 
        'MDCY(195,1) = 0', 
        'MDCY(196,1) = 0', 
        'MDCY(197,1) = 0', 
        'MDCY(43,1) = 0', 
        'MDCY(44,1) = 0', 
        'MDCY(269,1) = 0', 
        'MDCY(210,1) = 0', 
        'MDCY(211,1) = 0', 
        'MDCY(219,1) = 0', 
        'MDCY(227,1) = 0', 
        'MDCY(217,1) = 0', 
        'MDCY(208,1) = 0', 
        'MDCY(215,1) = 0', 
        'MDCY(143,1) = 0', 
        'MDCY(223,1) = 0', 
        'MDCY(225,1) = 0', 
        'MDCY(272,1) = 0', 
        'MDCY(291,1) = 0', 
        'MDCY(273,1) = 0', 
        'MDCY(139,1) = 0', 
        'MDCY(270,1) = 0', 
        'MDCY(290,1) = 0', 
        'MDCY(271,1) = 0', 
        'MDCY(136,1) = 0', 
        'MDCY(274,1) = 0', 
        'MDCY(292,1) = 0', 
        'MDCY(275,1) = 0', 
        'MDCY(142,1) = 0', 
        'MDCY(144,1) = 0', 
        'MDCY(145,1) = 0', 
        'MDCY(209,1) = 0', 
        'MDCY(218,1) = 0', 
        'MDCY(216,1) = 0', 
        'MDCY(224,1) = 0', 
        'MDCY(226,1) = 0', 
        'MDCY(228,1) = 0', 
        'MDCY(276,1) = 0', 
        'MDCY(277,1) = 0', 
        'MDCY(293,1) = 0', 
        'MDCY(105,1) = 0', 
        'MSEL=5         ! b-bbar')
)

process.bfilter = cms.EDFilter("PythiaFilter",
    ParticleID = cms.untracked.int32(521)
)

process.mumugenfilter = cms.EDFilter("MCParticlePairFilter",
    Status = cms.untracked.vint32(1, 1),
    MinPt = cms.untracked.vdouble(2.5, 2.5),
    MaxEta = cms.untracked.vdouble(2.5, 2.5),
    moduleLabel = cms.untracked.string('evtgenproducer'),
    MinEta = cms.untracked.vdouble(-2.5, -2.5),
    ParticleCharge = cms.untracked.int32(0),
    MaxInvMass = cms.untracked.double(3.15),
    MinInvMass = cms.untracked.double(3.05),
    ParticleID1 = cms.untracked.vint32(13),
    ParticleID2 = cms.untracked.vint32(13)
)

#process.FEVT = cms.OutputModule("PoolOutputModule",
#    dataset = cms.untracked.PSet(
#        dataTier = cms.untracked.string('GEN-SIM-DIGI-RECO')
#    ),
#    fileName = cms.untracked.string('bs2mumu.root')
#)

#process.outpath = cms.EndPath(process.FEVT)


process.p1 = cms.Path(process.bfilter*
                      process.evtgenproducer*
                      process.mumugenfilter*
#                      process.genFilter*
                      process.genParticles* # defined in PhysicsTools/HepMCCandAlgos/python/genParticles_cfi.py
                      process.genDump*
                      process.famosWithEverything*
                      process.trkDump*
                      process.signalDump*
#                      process.allTracks*
#                      process.goodTracks*
#                      process.triggerDump*  # this one is not working so far
                      #process.allMuons*
#===========JETS
#                      process.caloJetCollectionClone*
#                      process.caloJetSele*
#                      process.tagJetAlgo*
#                      process.tagJetPhys*
#                      process.genJetCollectionClone*
#                      process.genJetSele*
#                      process.gentagJetAlgo*
#                      process.gentagJetPhys*
#                      process.jetDump*
#============other stuff
#                     process.stuffDump* # dies sollte noch zum Laufen gebracht werden
                      process.tree)

process.tree.fileName = 'hfexample.root'





