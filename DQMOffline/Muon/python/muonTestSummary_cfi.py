import FWCore.ParameterSet.Config as cms

muonTestSummary = cms.EDFilter("MuonTestSummary",
                             # tests parameters
                             etaExpected = cms.double(1.),
                             phiExpected = cms.double(1.),
                             chi2Fraction = cms.double(0.4),
                             chi2Spread = cms.double(0.2),
                             resEtaSpread_tkGlb = cms.double(0.001),
                             resEtaSpread_glbSta = cms.double(0.05),
                             resPhiSpread_tkGlb = cms.double(0.001),
                             resPhiSpread_glbSta = cms.double(0.05),
                             resOneOvPSpread_tkGlb = cms.double(0.001),
                             resOneOvPSpread_glbSta = cms.double(0.05),
                             resChargeLimit_tkGlb = cms.double(0.10),
                             resChargeLimit_glbSta = cms.double(0.14),
                             resChargeLimit_tkSta = cms.double(0.18),
                             numMatchedExpected_min = cms.double(3.0),
                             numMatchedExpected_max = cms.double(5.0),
                             matchesFractionDt_min = cms.double(0.75),
                             matchesFractionDt_max = cms.double(1.0),
                             matchesFractionCsc_min = cms.double(0.75),
                             matchesFractionCsc_max = cms.double(1.0),
                             resSegmTrack_rms_min = cms.double(0.9),
                             resSegmTrack_rms_max = cms.double(1.1),
                             resSegmTrack_mean_min = cms.double(-0.2),
                             resSegmTrack_mean_max = cms.double(0.2),
                             expPeakEcalS9_min= cms.double(0.1), 
                             expPeakEcalS9_max= cms.double(0.3), 
                             expPeakHadS9_min= cms.double(1.), 
                             expPeakHadS9_max= cms.double(3.), 
                             expMultiplicityGlb_min = cms.double(0.75),
                             expMultiplicityGlb_max = cms.double(0.95),
                             expMultiplicityTk_min = cms.double(0.08),
                             expMultiplicityTk_max = cms.double(0.16),
                             expMultiplicitySta_min = cms.double(0.01),
                             expMultiplicitySta_max = cms.double(0.02)
                             )
