import FWCore.ParameterSet.Config as cms

#
# Geometry master configuration
#
# Ideal geometry, needed for simulation
from Geometry.CMSCommonData.cmsPilotIdealGeometryXML_cfi import *
from Geometry.TrackerNumberingBuilder.trackerNumberingGeometry_cfi import *
# Reconstruction geometry services
#  Tracking Geometry
from Geometry.CommonDetUnit.globalTrackingGeometry_cfi import *

#Tracker
from RecoTracker.GeometryESProducer.TrackerRecoGeometryESProducer_cfi import *

#Muon
from Geometry.MuonNumbering.muonNumberingInitialization_cfi import *
from RecoMuon.DetLayers.muonDetLayerGeometry_cfi import *

#L1
from L1TriggerConfig.L1GeometryProducers.l1CaloGeometry_cfi import *
from L1TriggerConfig.L1GeometryProducers.l1CaloGeomRecordSource_cff import *

#  Alignment
from Geometry.TrackerGeometryBuilder.idealForDigiTrackerGeometry_cff import *
from Geometry.CSCGeometryBuilder.idealForDigiCscGeometry_cff import *
from Geometry.DTGeometryBuilder.idealForDigiDtGeometry_cff import *

#  Calorimeters
from Geometry.CaloEventSetup.CaloTopology_cfi import *
from Geometry.CaloEventSetup.CaloGeometry_cff import *
from Geometry.CaloEventSetup.EcalTrigTowerConstituents_cfi import *
from Geometry.EcalMapping.EcalMapping_cfi import *
from Geometry.EcalMapping.EcalMappingRecord_cfi import *
from RecoEcal.EgammaClusterProducers.geometryForClustering_cff import *
CaloGeometryBuilder.SelectedCalos = ['HCAL', 'ZDC', 'EcalBarrel', 'EcalEndcap', 'TOWER']


