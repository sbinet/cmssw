// File: FastsimHitNtuplizer.cc
// Description: see FastsimHitNtuplizer.h
// Authors: H. Cheung
//--------------------------------------------------------------


#include "SLHCUpgradeSimulations/Geometry/test/FastsimHitNtuplizer.h"

#include "FWCore/PluginManager/interface/ModuleDef.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

// DataFormats
#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/Common/interface/OwnVector.h"
#include "DataFormats/TrajectorySeed/interface/TrajectorySeedCollection.h"
#include "DataFormats/TrackCandidate/interface/TrackCandidateCollection.h"

#include "SimDataFormats/Track/interface/SimTrack.h"
#include "SimDataFormats/Track/interface/SimTrackContainer.h"
#include "SimDataFormats/Vertex/interface/SimVertex.h"
#include "SimDataFormats/Vertex/interface/SimVertexContainer.h"

#include "DataFormats/DetId/interface/DetId.h"
#include "DataFormats/SiPixelDetId/interface/PXBDetId.h" 
#include "DataFormats/SiPixelDetId/interface/PXFDetId.h" 
#include "DataFormats/SiPixelDetId/interface/PixelSubdetector.h"

#include "DataFormats/SiStripDetId/interface/TIBDetId.h"
#include "DataFormats/SiStripDetId/interface/TIDDetId.h"
#include "DataFormats/SiStripDetId/interface/TOBDetId.h"
#include "DataFormats/SiStripDetId/interface/TECDetId.h"
#include "DataFormats/SiStripDetId/interface/StripSubdetector.h"

// Geometry
#include "MagneticField/Engine/interface/MagneticField.h"
#include "Geometry/TrackerGeometryBuilder/interface/TrackerGeometry.h"
#include "Geometry/Records/interface/TrackerDigiGeometryRecord.h"

#include "Geometry/CommonDetUnit/interface/GeomDetUnit.h"

// For ROOT
#include <TROOT.h>
#include <TTree.h>
#include <TFile.h>
#include <TF1.h>
#include <TH2F.h>
#include <TH1F.h>

// STD
#include <memory>
#include <string>
#include <iostream>

using namespace std;
using namespace edm;

FastsimHitNtuplizer::FastsimHitNtuplizer(edm::ParameterSet const& conf) : 
  conf_(conf), 
  tfile_(0), 
  pixeltree_(0), 
  striptree_(0)
{
}


FastsimHitNtuplizer::~FastsimHitNtuplizer() { }  

void FastsimHitNtuplizer::endJob() 
{
  std::cout << " FastsimHitNtuplizer::endJob" << std::endl;
  tfile_->Write();
  tfile_->Close();
}



void FastsimHitNtuplizer::beginJob(const edm::EventSetup& es)
{
  std::cout << " FastsimHitNtuplizer::beginJob" << std::endl;
  std::string outputFile = conf_.getParameter<std::string>("OutputFile");
 
  tfile_ = new TFile ( outputFile.c_str() , "RECREATE" );
  pixeltree_ = new TTree("PixelNtuple","Pixel hit analyzer ntuple");
  striptree_ = new TTree("StripNtuple","Strip hit analyzer ntuple");

  int bufsize = 64000;

  //Common Branch
  pixeltree_->Branch("evt",    &evt_,      "run/I:evtnum/I", bufsize);
  pixeltree_->Branch("pixel_recHit", &recHit_, "x/F:y:xx:xy:yy:row:col:gx:gy:gz:subid/I", bufsize);
  
  // Strip Branches 
  striptree_->Branch("evt",    &evt_,      "run/I:evtnum/I", bufsize);
  striptree_->Branch("strip_recHit", &striprecHit_, "x/F:y:xx:xy:yy:row:col:gx:gy:gz:subid/I", bufsize);

  // fastsim setup
  edm::ESHandle<TrackerGeometry>        geometry;

  es.get<TrackerDigiGeometryRecord>().get(geometry);

  theGeometry = &(*geometry);
}

// Functions that gets called by framework every event
void FastsimHitNtuplizer::analyze(const edm::Event& e, const edm::EventSetup& es)
{
  edm::Handle<SiTrackerGSRecHit2DCollection> theGSRecHits;
  std::string hitProducer = conf_.getParameter<std::string>("HitProducer");
  e.getByLabel(hitProducer, theGSRecHits);
  
  //std::cout << " Step A: Full GS RecHits found " << theGSRecHits->size() << std::endl;
  if(theGSRecHits->size() == 0) return;

//For each SiTrackerGSRecHit2D*
  SiTrackerGSRecHit2DCollection::const_iterator theRecHitRangeIteratorBegin = theGSRecHits->begin();
  SiTrackerGSRecHit2DCollection::const_iterator theRecHitRangeIteratorEnd   = theGSRecHits->end();
  SiTrackerGSRecHit2DCollection::const_iterator iterRecHit;

  std::string detname ;

  for ( iterRecHit = theRecHitRangeIteratorBegin; 
        iterRecHit != theRecHitRangeIteratorEnd; ++iterRecHit) {

       const DetId& detId =  iterRecHit->geographicalId();
       const GeomDet* geomDet( theGeometry->idToDet(detId) );

       unsigned int subdetId = detId.subdetId();
       int layerNumber=0;
       int ringNumber = 0;
       int stereo = 0;
       if ( subdetId == StripSubdetector::TIB) {
          detname = "TIB";
	  TIBDetId tibid(detId.rawId());
	  layerNumber = tibid.layer();
	  stereo = tibid.stereo();
       } else if ( subdetId ==  StripSubdetector::TOB ) {
          detname = "TOB";
	  TOBDetId tobid(detId.rawId());
	  layerNumber = tobid.layer();
	  stereo = tobid.stereo();
       } else if ( subdetId ==  StripSubdetector::TID) {
          detname = "TID";
	  TIDDetId tidid(detId.rawId());
	  layerNumber = tidid.wheel();
	  ringNumber = tidid.ring();
	  stereo = tidid.stereo();
       } else if ( subdetId ==  StripSubdetector::TEC ) {
          detname = "TEC";
	  TECDetId tecid(detId.rawId());
	  layerNumber = tecid.wheel();
	  ringNumber = tecid.ring();
	  stereo = tecid.stereo();
       } else if ( subdetId ==  PixelSubdetector::PixelBarrel ) {
          detname = "PXB";
	  PXBDetId pxbid(detId.rawId());
	  layerNumber = pxbid.layer();
	  stereo = 1;
       } else if ( subdetId ==  PixelSubdetector::PixelEndcap ) {
          detname = "PXF";
	  PXFDetId pxfid(detId.rawId());
	  layerNumber = pxfid.disk();
	  stereo = 1;
       }
/*
       std::cout << "Found RecHit in " << detname << " from detid " << detId.rawId()
		<< " subdet = " << subdetId
		<< " layer = " << layerNumber
		<< " ring = " << ringNumber
		<< " Stereo = " << stereo
		<< std::endl;
       std::cout << "Rechit global x/y/z/r : "
                 << geomDet->surface().toGlobal(iterRecHit->localPosition()).x() << " " 
                 << geomDet->surface().toGlobal(iterRecHit->localPosition()).y() << " " 
                 << geomDet->surface().toGlobal(iterRecHit->localPosition()).z() << " " 
                 << geomDet->surface().toGlobal(iterRecHit->localPosition()).perp() << std::endl;
*/
    unsigned int subid = detId.subdetId();
    if ( (subid==1)||(subid==2) ) {
      // 1 = PXB, 2 = PXF
      fillPRecHit(subid, iterRecHit, geomDet);
      fillEvt(e);
      pixeltree_->Fill();
      init();
    } else { //end of Pixel and start of Strip
      //TIB=3,TID=4,TOB=5,TEC=6
      fillEvt(e);
      fillSRecHit(subid, iterRecHit, geomDet);
      striptree_->Fill();
      init();
    }
  } // end of rechit loop
 
} // end analyze function

void FastsimHitNtuplizer::fillSRecHit(const int subid, 
                                   SiTrackerGSRecHit2DCollection::const_iterator pixeliter,
                                   const GeomDet* theGeom)
{
  LocalPoint lp = pixeliter->localPosition();
  LocalError le = pixeliter->localPositionError();

  striprecHit_.x = lp.x();
  striprecHit_.y = lp.y();
  striprecHit_.xx = le.xx();
  striprecHit_.xy = le.xy();
  striprecHit_.yy = le.yy();
  //MeasurementPoint mp = topol->measurementPosition(LocalPoint(striprecHit_.x, striprecHit_.y));
  //striprecHit_.row = mp.x();
  //striprecHit_.col = mp.y();
  GlobalPoint GP = theGeom->surface().toGlobal(pixeliter->localPosition());
  striprecHit_.gx = GP.x();
  striprecHit_.gy = GP.y();
  striprecHit_.gz = GP.z();
  striprecHit_.subid = subid;
}
void FastsimHitNtuplizer::fillPRecHit(const int subid, 
                                   SiTrackerGSRecHit2DCollection::const_iterator pixeliter,
                                   const GeomDet* PixGeom)
{
  LocalPoint lp = pixeliter->localPosition();
  LocalError le = pixeliter->localPositionError();

  recHit_.x = lp.x();
  recHit_.y = lp.y();
  recHit_.xx = le.xx();
  recHit_.xy = le.xy();
  recHit_.yy = le.yy();
  //MeasurementPoint mp = topol->measurementPosition(LocalPoint(recHit_.x, recHit_.y));
  //recHit_.row = mp.x();
  //recHit_.col = mp.y();
  GlobalPoint GP = PixGeom->surface().toGlobal(pixeliter->localPosition());
  recHit_.gx = GP.x();
  recHit_.gy = GP.y();
  recHit_.gz = GP.z();
  recHit_.subid = subid;
/*
       std::cout << "Found RecHit in " << subid
                 << " global x/y/z : "
                 << PixGeom->surface().toGlobal(pixeliter->localPosition()).x() << " " 
                 << PixGeom->surface().toGlobal(pixeliter->localPosition()).y() << " " 
                 << PixGeom->surface().toGlobal(pixeliter->localPosition()).z() << std::endl;
*/
}

void
FastsimHitNtuplizer::fillEvt(const edm::Event& E)
{
   evt_.run = E.id().run();
   evt_.evtnum = E.id().event();
}

void FastsimHitNtuplizer::init()
{
  evt_.init();
  recHit_.init();
  striprecHit_.init();
}

void FastsimHitNtuplizer::evt::init()
{
  int dummy_int = 9999;
  run = dummy_int;
  evtnum = dummy_int;
}

void FastsimHitNtuplizer::RecHit::init()
{
  float dummy_float = 9999.0;

  x = dummy_float;
  y = dummy_float;
  xx = dummy_float;
  xy = dummy_float; 
  yy = dummy_float;
  row = dummy_float;
  col = dummy_float;
  gx = dummy_float;
  gy = dummy_float;
  gz = dummy_float;
}

//define this as a plug-in
DEFINE_ANOTHER_FWK_MODULE(FastsimHitNtuplizer);

