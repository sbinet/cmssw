import FWCore.ParameterSet.Config as cms

#
# 
# Configuration blocks for the TrajectoryFactories inheriting 
# from TrajectoryFactoryBase.
# Include this file and do e.g.
# PSet TrajectoryFactory = {
#   using ReferenceTrajectoryFactory
# }
# 
#
#
#
# Common to all TrajectoryFactories
#
#
TrajectoryFactoryBase = cms.PSet(
    PropagationDirection = cms.string('alongMomentum'), ## or "oppositeToMomentum" or "anyDirection"
    MaterialEffects = cms.string('Combined'), ## or "MultipleScattering" or "EnergyLoss" or "None"
    UseProjectedHits = cms.bool(True), ## if false, projected hits are skipped
    UseInvalidHits = cms.bool(False), ## if false, invalid hits are skipped
    UseHitWithoutDet = cms.bool(True) ## if false, RecHits that are not attached to GeomDets are skipped
)

#
#
# ReferenceTrajectoryFactory
#
#
ReferenceTrajectoryFactory = cms.PSet(
    TrajectoryFactoryBase,
    ParticleMass = cms.double(0.10565836),
    TrajectoryFactoryName = cms.string('ReferenceTrajectoryFactory')
)

#
#
# BzeroReferenceTrajectoryFactory
#
#
BzeroReferenceTrajectoryFactory = cms.PSet(
    TrajectoryFactoryBase,
    ParticleMass = cms.double(0.10565836),
    TrajectoryFactoryName = cms.string('BzeroReferenceTrajectoryFactory'),
    MomentumEstimate = cms.double(2.0)
)

#
#
# DualTrajectoryFactory
#
#
DualTrajectoryFactory = cms.PSet(
    TrajectoryFactoryBase,
    ParticleMass = cms.double(0.10565836),
    TrajectoryFactoryName = cms.string('DualTrajectoryFactory')
)

#
#
# DualBzeroTrajectoryFactory
#
#
DualBzeroTrajectoryFactory = cms.PSet(
    TrajectoryFactoryBase,
    ParticleMass = cms.double(0.10565836),
    TrajectoryFactoryName = cms.string('DualBzeroTrajectoryFactory'),
    MomentumEstimate = cms.double(2.0)
)

#
#
# TwoBodyDecayReferenceTrajectoryFactory
#
#
TwoBodyDecayTrajectoryFactory = cms.PSet(
    TrajectoryFactoryBase,
    NSigmaCut = cms.double(100.0),
    BeamSpot = cms.PSet(
        VarYY = cms.double(2.25e-06),
        VarXX = cms.double(2.25e-06),
        VarXY = cms.double(0.0),
        VarYZ = cms.double(0.0),
        MeanX = cms.double(0.0),
        MeanY = cms.double(0.0),
        MeanZ = cms.double(0.0),
        VarXZ = cms.double(0.0),
        VarZZ = cms.double(28.09)
    ),
    ParticleProperties = cms.PSet(
        PrimaryMass = cms.double(91.1876),
        PrimaryWidth = cms.double(2.4952),
        SecondaryMass = cms.double(0.105658)
    ),
    ConstructTsosWithErrors = cms.bool(False),
    UseRefittedState = cms.bool(True),
    EstimatorParameters = cms.PSet(
        MaxIterationDifference = cms.untracked.double(0.01),
        RobustificationConstant = cms.untracked.double(1.0),
        MaxIterations = cms.untracked.int32(100),
        UseInvariantMass = cms.untracked.bool(True)
    ),
    TrajectoryFactoryName = cms.string('TwoBodyDecayTrajectoryFactory')
)

#
#
# CombinedTrajectoryFactory using an instance of TwoBodyDecayTrajectoryFactory
# and ReferenceTrajectoryFactory
#
#
CombinedTrajectoryFactory = cms.PSet(
    TrajectoryFactoryBase,
    ParticleProperties = cms.PSet(
        PrimaryMass = cms.double(91.1876),
        PrimaryWidth = cms.double(2.4952),
        SecondaryMass = cms.double(0.105658)
    ),
    ConstructTsosWithErrors = cms.bool(False),
    BeamSpot = cms.PSet(
        VarYY = cms.double(1000.0),
        VarXX = cms.double(1000.0),
        VarXY = cms.double(0.0),
        VarYZ = cms.double(0.0),
        MeanX = cms.double(0.0),
        MeanY = cms.double(0.0),
        MeanZ = cms.double(0.0),
        VarXZ = cms.double(0.0),
        VarZZ = cms.double(1000.0)
    ),
    TrajectoryFactoryNames = cms.vstring('TwoBodyDecayTrajectoryFactory', 
        'ReferenceTrajectoryFactory'),
    UseRefittedState = cms.bool(True),
    ParticleMass = cms.double(0.10565836),
    EstimatorParameters = cms.PSet(
        MaxIterationDifference = cms.untracked.double(0.01),
        RobustificationConstant = cms.untracked.double(1.0),
        MaxIterations = cms.untracked.int32(100),
        UseInvariantMass = cms.untracked.bool(True)
    ),
    NSigmaCut = cms.double(100.0),
    TrajectoryFactoryName = cms.string('CombinedTrajectoryFactory')
)

