## import skeleton process
from PhysicsTools.PatAlgos.patTemplate_cfg import *

## add track candidates
from PhysicsTools.PatAlgos.tools.trackTools import *

makeTrackCandidates(process,
    label        = 'TrackCands',
    tracks       = cms.InputTag('generalTracks'),
    particleType = 'pi+',
    preselection = 'pt > 10',
    selection    = 'pt > 10',
    isolation    = {'tracker':0.3, 'ecalTowers':0.3, 'hcalTowers':0.3},
    isoDeposits  = [],
    mcAs         = 'muon'
)

## add generic tracks to the output file
process.out.outputCommands.append('keep *_selectedPatTrackCands_*_*')

## let it run
process.p = cms.Path(
    process.patDefaultSequence
)

## ------------------------------------------------------
#  In addition you usually want to change the following
#  parameters:
## ------------------------------------------------------
#
#   process.GlobalTag.globaltag =  ...    ##  (according to https://twiki.cern.ch/twiki/bin/view/CMS/SWGuideFrontierConditions)
#                                         ##
from PhysicsTools.PatAlgos.patInputFiles_cff import filesRelValProdTTbarAODSIM
process.source.fileNames = filesRelValProdTTbarAODSIM
#                                         ##
process.maxEvents.input = 10
#                                         ##
#   process.out.outputCommands = [ ... ]  ##  (e.g. taken from PhysicsTools/PatAlgos/python/patEventContent_cff.py)
#                                         ##
process.out.fileName = 'patTuple_addTracks.root'
#                                         ##
#   process.options.wantSummary = False   ##  (to suppress the long output at the end of the job)
