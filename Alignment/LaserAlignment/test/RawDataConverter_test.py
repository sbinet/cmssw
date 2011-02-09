import FWCore.ParameterSet.Config as cms

process = cms.Process( "RawDataConverter" )

## Choose the input files (and if needed the Event ranges)
process.source = cms.Source( "PoolSource",
  fileNames = cms.untracked.vstring(
       '/store/data/Run2010A/TestEnables/RAW/v1/000/140/124/56E00D1B-308F-DF11-BE54-001D09F24691.root'              
    ),
    eventsToProcess = cms.untracked.VEventRange(
    '140124:1141118271-140124:2134733046'
    )
)

# Choose how many events should be processed
process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32( -1 )
)

## message logger
process.MessageLogger = cms.Service(
    "MessageLogger",
    destinations = cms.untracked.vstring( 'cout', 'cerr' ),
    #destinations = cms.untracked.vstring( 'cerr' ),
    debugModules = cms.untracked.vstring( 'RawDataConverter' ),
    cerr = cms.untracked.PSet(
    threshold = cms.untracked.string( 'ERROR' )
    ),
    cout = cms.untracked.PSet(
    threshold = cms.untracked.string( 'INFO' )
    )
)


# Choose the correct global tag for the data
process.load( "Configuration.StandardSequences.FrontierConditions_GlobalTag_cff" )
process.GlobalTag.globaltag = cms.string('GR_R_37X_V6::All')


# Laser Alignment Event Filter
process.load('Alignment.LaserAlignment.LaserAlignmentEventFilter_cfi')


# strip digitizer
process.load( "EventFilter.SiStripRawToDigi.SiStripDigis_cfi" )
process.siStripDigis.ProductLabel = 'source'
process.siStripDigis.TriggerFedId = -1

# Raw Data Converter
process.load('Alignment.LaserAlignment.RawDataConverter_cfi')
process.RawDataConverter.OutputFileName = cms.untracked.string( 'RawDataConverter.root' ) #@@@ output file

# Run the Raw Data Converter
process.p = cms.Path(process.LaserAlignmentEventFilter + process.siStripDigis + process.RawDataConverter)
