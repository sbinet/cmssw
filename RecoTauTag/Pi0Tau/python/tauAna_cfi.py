import FWCore.ParameterSet.Config as cms

tauAna = cms.EDFilter("TauAna",
    pFCandidateCollectionName = cms.string(''),
    histFileName = cms.string('hist.root'),
    pFCandidateProducerName = cms.string('particleFlow'),
    tauCollectionName = cms.string('caloRecoTauTagInfoProducer'),
    trackCollectionName = cms.string('generalTracks')
)


