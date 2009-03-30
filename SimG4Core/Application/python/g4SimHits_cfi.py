import FWCore.ParameterSet.Config as cms

from SimG4Core.Application.hectorParameter_cfi import *

common_heavy_suppression = cms.PSet(
    NeutronThreshold = cms.double(30.0),
    ProtonThreshold = cms.double(30.0),
    IonThreshold = cms.double(30.0)
)

common_maximum_time = cms.PSet(
    MaxTrackTime  = cms.double(500.0),
    MaxTimeNames  = cms.vstring(),
    MaxTrackTimes = cms.vdouble()
)

g4SimHits = cms.EDProducer("OscarProducer",
    NonBeamEvent = cms.bool(False),
    G4EventManagerVerbosity = cms.untracked.int32(0),
    G4StackManagerVerbosity = cms.untracked.int32(0),
    G4TrackingManagerVerbosity = cms.untracked.int32(0),
    UseMagneticField = cms.bool(True),
    OverrideUserStackingAction = cms.bool(True),
    StoreRndmSeeds = cms.bool(False),
    RestoreRndmSeeds = cms.bool(False),
    PhysicsTablesDirectory = cms.string('PhysicsTables'),
    StorePhysicsTables = cms.bool(False),
    RestorePhysicsTables = cms.bool(False),
    CheckOverlap = cms.untracked.bool(False),
    G4Commands = cms.vstring(),
    Watchers = cms.VPSet(),
    MagneticField = cms.PSet(
        UseLocalMagFieldManager = cms.bool(False),
        Verbosity = cms.untracked.bool(False),
        ConfGlobalMFM = cms.PSet(
            Volume = cms.string('OCMS'),
            OCMS = cms.PSet(
                Stepper = cms.string('G4ClassicalRK4'),
                Type = cms.string('CMSIMField'),
                G4ClassicalRK4 = cms.PSet(
                    MaximumEpsilonStep = cms.untracked.double(0.01), ## in mm

                    DeltaOneStep = cms.double(0.001), ## in mm

                    MaximumLoopCounts = cms.untracked.double(1000.0),
                    DeltaChord = cms.double(0.001), ## in mm

                    MinStep = cms.double(0.1), ## in mm

                    DeltaIntersectionAndOneStep = cms.untracked.double(-1.0),
                    DeltaIntersection = cms.double(0.0001), ## in mm

                    MinimumEpsilonStep = cms.untracked.double(1e-05) ## in mm

                )
            )
        ),
        delta = cms.double(1.0)
    ),
    Physics = cms.PSet(
        # NOTE : if you want EM Physics only,
        #        please select "SimG4Core/Physics/DummyPhysics" for type
        #        and turn ON DummyEMPhysics
        #
        type = cms.string('SimG4Core/Physics/QGSP_BERT_EMV'),
        DummyEMPhysics = cms.bool(False),
        CutsPerRegion = cms.bool(True),
        DefaultCutValue = cms.double(1.0), ## cuts in cm
        G4BremsstrahlungThreshold = cms.double(0.5), ## cut in GeV
        Verbosity = cms.untracked.int32(0),
        # 1 will print cuts as they get set from DD
        # 2 will do as 1 + will dump Geant4 table of cuts
        EMPhysics   = cms.untracked.bool(True),
        HadPhysics  = cms.untracked.bool(True),
        FlagBERT    = cms.untracked.bool(False),
        FlagCHIPS   = cms.untracked.bool(False),
        FlagFTF     = cms.untracked.bool(False),
        FlagGlauber = cms.untracked.bool(False),
        FlagHP      = cms.untracked.bool(False),
        GFlash = cms.PSet(
            GflashHistogram = cms.bool(False),
            GflashEMShowerModel = cms.bool(False),
            GflashHadronPhysics = cms.string('QGSP_BERT_EMV'),
            GflashHadronShowerModel = cms.bool(False)
        )
    ),
    Generator = cms.PSet(
        HectorEtaCut,
        # string HepMCProductLabel = "VtxSmeared"
        HepMCProductLabel = cms.string('generator'),
        ApplyPCuts = cms.bool(True),
        MinPCut = cms.double(0.04), ## the pt-cut is in GeV (CMS conventions)
        MaxPCut = cms.double(99999.0), ## the ptmax=99.TeV in this case
        ApplyEtaCuts = cms.bool(True),
        MinEtaCut = cms.double(-5.5),
        MaxEtaCut = cms.double(5.5),
        ApplyPhiCuts = cms.bool(False),
        MinPhiCut = cms.double(-3.14159265359), ## in radians
        MaxPhiCut = cms.double(3.14159265359), ## according to CMS conventions
        RDecLenCut = cms.double(2.9), ## the minimum decay length in cm (!) for mother tracking
        Verbosity = cms.untracked.int32(0)
    ),
    RunAction = cms.PSet(
        StopFile = cms.string('StopRun')
    ),
    EventAction = cms.PSet(
        debug = cms.untracked.bool(False),
        StopFile = cms.string('StopRun'),
        CollapsePrimaryVertices = cms.bool(False)
    ),
    StackingAction = cms.PSet(
        common_heavy_suppression,
        common_maximum_time,
        TrackNeutrino = cms.bool(False),
        KillHeavy     = cms.bool(False),
        SaveFirstLevelSecondary = cms.untracked.bool(False),
        SavePrimaryDecayProductsAndConversionsInTracker = cms.untracked.bool(True),
        SavePrimaryDecayProductsAndConversionsInCalo = cms.untracked.bool(False),
        SavePrimaryDecayProductsAndConversionsInMuon = cms.untracked.bool(False)
    ),
    TrackingAction = cms.PSet(
        DetailedTiming = cms.untracked.bool(False)
    ),
    SteppingAction = cms.PSet(
        common_maximum_time,
        KillBeamPipe            = cms.bool(True),
        CriticalEnergyForVacuum = cms.double(2.0),
        CriticalDensity         = cms.double(1e-15),
        EkinNames               = cms.vstring(),
        EkinThresholds          = cms.vdouble(),
        EkinParticles           = cms.vstring(),
        Verbosity = cms.untracked.int32(0)
    ),
    TrackerSD = cms.PSet(
        ZeroEnergyLoss = cms.bool(False),
        PrintHits = cms.bool(False),
        ElectronicSigmaInNanoSeconds = cms.double(12.06),
        NeverAccumulate = cms.bool(False),
        EnergyThresholdForPersistencyInGeV = cms.double(0.2),
        EnergyThresholdForHistoryInGeV = cms.double(0.05)
    ),
    MuonSD = cms.PSet(
        EnergyThresholdForPersistency = cms.double(1.0),
        PrintHits = cms.bool(False),
        AllMuonsPersistent = cms.bool(True)
    ),
    CaloSD = cms.PSet(
        common_heavy_suppression,
        SuppressHeavy = cms.bool(False),
        UseMap    = cms.untracked.bool(False),
        EminTrack = cms.double(1.0),
        TmaxHit   = cms.double(1000.0),
	HCNames   = cms.vstring('EcalHitsEB','EcalHitsEE','EcalHitsES','HcalHits'),
        EminHits  = cms.vdouble(0.015,0.010,0.0,0.0),
        TmaxHits  = cms.vdouble(500.0,500.0,500.0,500.0),
        DetailedTiming = cms.untracked.bool(False),
        Verbosity = cms.untracked.int32(0),
        CheckHits = cms.untracked.int32(25),
        BeamPosition = cms.untracked.double(0.0),
        CorrectTOFBeam = cms.untracked.bool(False)
    ),
    ECalSD = cms.PSet(
        UseBirkLaw = cms.bool(True),
        BirkL3Parametrization = cms.bool(True),
        BirkSlope = cms.double(0.253694),
        BirkCut = cms.double(0.1),
        BirkC1 = cms.double(0.03333),
        BirkC3 = cms.double(1.0),
        BirkC2 = cms.double(0.0),
        SlopeLightYield = cms.double(0.02),
        TestBeam = cms.untracked.bool(False)
    ),
    HCalSD = cms.PSet(
        UseBirkLaw = cms.bool(True),
        BirkC3 = cms.double(1.75),
        BirkC2 = cms.double(0.142),
        BirkC1 = cms.double(0.0052),
        UseShowerLibrary = cms.bool(True),
        UseParametrize   = cms.bool(False),
        UsePMTHits       = cms.bool(False),
        TestNumberingScheme = cms.bool(False),
        EminHitHB = cms.double(0.0),
        EminHitHE = cms.double(0.0),
        EminHitHO = cms.double(0.0),
        EminHitHF = cms.double(0.0),
        BetaThreshold = cms.double(0.7),
        UseHF = cms.untracked.bool(True),
        ForTBH2 = cms.untracked.bool(False),
        UseLayerWt = cms.untracked.bool(False),
        WtFile = cms.untracked.string('None')
    ),
    CaloTrkProcessing = cms.PSet(
        TestBeam = cms.bool(False),
        EminTrack = cms.double(0.01)
    ),
    HFShower = cms.PSet(
        ProbMax         = cms.double(1.0),
        CFibre          = cms.double(0.5),
        PEPerGeV        = cms.double(0.25),
        TrackEM         = cms.bool(False),
        UseShowerLibrary= cms.bool(False),
        EminLibrary     = cms.double(5.0),
        RefIndex        = cms.double(1.459),
        Lambda1         = cms.double(280.0),
        Lambda2         = cms.double(700.0),
        Aperture        = cms.double(0.33),
        ApertureTrapped = cms.double(0.22),
        Gain            = cms.double(0.33),
        CheckSurvive    = cms.bool(False)
    ),
    HFShowerLibrary = cms.PSet(
        FileName        = cms.FileInPath('SimG4CMS/Calo/data/hfshowerlibrary_lhep_140_edm.root'),
        BackProbability = cms.double(0.2),
        TreeEMID        = cms.string('emParticles'),
        TreeHadID       = cms.string('hadParticles'),
        Verbosity       = cms.untracked.bool(False),
        BranchPost      = cms.untracked.string('_R.obj'),
        BranchEvt       = cms.untracked.string('HFShowerLibraryEventInfos_hfshowerlib_HFShowerLibraryEventInfo'),
        BranchPre       = cms.untracked.string('HFShowerPhotons_hfshowerlib_')
    ),
    HFShowerPMT = cms.PSet(
        PEPerGeVPMT     = cms.double(1.0),
        RefIndex        = cms.double(1.52),
        Lambda1         = cms.double(280.0),
        Lambda2         = cms.double(700.0),
        Aperture        = cms.double(0.66),
        ApertureTrapped = cms.double(0.22),
        Gain            = cms.double(0.33),
        CheckSurvive    = cms.bool(False)
    ),
    CastorSD = cms.PSet(
        useShowerLibrary               = cms.bool(False),
        minEnergyInGeVforUsingSLibrary = cms.double(1.0),
        Verbosity                      = cms.untracked.int32(0)
    ),
    CastorShowerLibrary =  = cms.PSet(
        FileName  = cms.FileInPath('SimG4CMS/Forward/test/data/CastorShowerLibrary_01-60GeV_5.7-6.1eta.root'),
        BranchEvt = cms.untracked.string('CastorShowerLibInfo'),
        BranchEM  = cms.untracked.string('emParticles'),
        BranchHAD = cms.untracked.string('hadParticles'),
        Verbosity = cms.untracked.bool(False)
    ),
    TotemSD = cms.PSet(
        Verbosity = cms.untracked.int32(0)
    ),
    ZdcSD = cms.PSet(
        Verbosity = cms.int32(0),
        UseShowerLibrary = cms.bool(True),
        UseShowerHits = cms.bool(False),
        FiberDirection = cms.double(45.0),
        ZdcHitEnergyCut = cms.double(1.0)
    ),
    ZdcShowerLibrary = cms.PSet(
        Verbosity = cms.untracked.int32(0)
    ),
    FP420SD = cms.PSet(
        Verbosity = cms.untracked.int32(2)
    ),
    BscSD = cms.PSet(
        Verbosity = cms.untracked.int32(0)
    ),
    HcalTB02SD = cms.PSet(
        UseBirkLaw = cms.untracked.bool(False),
        BirkC1 = cms.untracked.double(0.013),
        BirkC3 = cms.untracked.double(1.75),
        BirkC2 = cms.untracked.double(0.0568)
    ),
    EcalTBH4BeamSD = cms.PSet(
        UseBirkLaw = cms.bool(False),
        BirkC1 = cms.double(0.013),
        BirkC3 = cms.double(1.75),
        BirkC2 = cms.double(0.0568)
    ),
    HcalTB06BeamSD = cms.PSet(
        UseBirkLaw = cms.bool(False),
        BirkC1 = cms.double(0.013),
        BirkC3 = cms.double(1.75),
        BirkC2 = cms.double(0.0568)
    )
)



