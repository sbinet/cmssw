/*
 * \file EEOccupancyTask.cc
 *
 * $Date: 2008/01/22 22:10:42 $
 * $Revision: 1.24 $
 * \author G. Della Ricca
 * \author G. Franzoni
 *
*/

#include <iostream>
#include <fstream>
#include <vector>

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "DQMServices/Core/interface/DaqMonitorBEInterface.h"
#include "DQMServices/Daemon/interface/MonitorDaemon.h"

#include "DataFormats/EcalRawData/interface/EcalRawDataCollections.h"
#include "DataFormats/EcalDetId/interface/EEDetId.h"
#include "DataFormats/EcalDigi/interface/EEDataFrame.h"
#include "DataFormats/EcalDigi/interface/EcalDigiCollections.h"
#include "DataFormats/EcalRecHit/interface/EcalUncalibratedRecHit.h"
#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"

#include <DQM/EcalCommon/interface/Numbers.h>

#include <DQM/EcalEndcapMonitorTasks/interface/EEOccupancyTask.h>

using namespace cms;
using namespace edm;
using namespace std;

EEOccupancyTask::EEOccupancyTask(const ParameterSet& ps){

  init_ = false;

  // get hold of back-end interface
  dbe_ = Service<DaqMonitorBEInterface>().operator->();

  enableCleanup_ = ps.getUntrackedParameter<bool>("enableCleanup", false);

  EEDigiCollection_ = ps.getParameter<edm::InputTag>("EEDigiCollection");
  EcalPnDiodeDigiCollection_ = ps.getParameter<edm::InputTag>("EcalPnDiodeDigiCollection");
  EcalRecHitCollection_ = ps.getParameter<edm::InputTag>("EcalRecHitCollection");
  EcalTrigPrimDigiCollection_ = ps.getParameter<edm::InputTag>("EcalTrigPrimDigiCollection");

  for (int i = 0; i < 18; i++) {
    meOccupancy_[i]    = 0;
    meOccupancyMem_[i] = 0;
  }

  meEEDigiOccupancy_[0] = 0;
  meEEDigiOccupancyProjX_[0] = 0;
  meEEDigiOccupancyProjY_[0] = 0;
  meEEDigiOccupancy_[1] = 0;
  meEEDigiOccupancyProjX_[1] = 0;
  meEEDigiOccupancyProjY_[1] = 0;

  meEERecHitOccupancy_[0] = 0;
  meEERecHitOccupancyProjX_[0] = 0;
  meEERecHitOccupancyProjY_[0] = 0;
  meEERecHitOccupancy_[1] = 0;
  meEERecHitOccupancyProjX_[1] = 0;
  meEERecHitOccupancyProjY_[1] = 0;

  meEETrigPrimDigiOccupancy_[0] = 0;
  meEETrigPrimDigiOccupancyProjX_[0] = 0;
  meEETrigPrimDigiOccupancyProjY_[0] = 0;
  meEETrigPrimDigiOccupancy_[1] = 0;
  meEETrigPrimDigiOccupancyProjX_[1] = 0;
  meEETrigPrimDigiOccupancyProjY_[1] = 0;

}

EEOccupancyTask::~EEOccupancyTask(){

}

void EEOccupancyTask::beginJob(const EventSetup& c){

  ievt_ = 0;

  if ( dbe_ ) {
    dbe_->setCurrentFolder("EcalEndcap/EEOccupancyTask");
    dbe_->rmdir("EcalEndcap/EEOccupancyTask");
  }

  Numbers::initGeometry(c);

}

void EEOccupancyTask::setup(void){

  init_ = true;

  char histo[200];

  if ( dbe_ ) {
    dbe_->setCurrentFolder("EcalEndcap/EEOccupancyTask");

    for (int i = 0; i < 18; i++) {
      sprintf(histo, "EEOT digi occupancy %s", Numbers::sEE(i+1).c_str());
      meOccupancy_[i] = dbe_->book2D(histo, histo, 50, Numbers::ix0EE(i+1)+0., Numbers::ix0EE(i+1)+50., 50, Numbers::iy0EE(i+1)+0., Numbers::iy0EE(i+1)+50.);
      meOccupancy_[i]->setAxisTitle("jx", 1);
      meOccupancy_[i]->setAxisTitle("jy", 2);
      dbe_->tag(meOccupancy_[i], i+1);
    }
    for (int i = 0; i < 18; i++) {
      sprintf(histo, "EEOT MEM digi occupancy %s", Numbers::sEE(i+1).c_str());
      meOccupancyMem_[i] = dbe_->book2D(histo, histo, 10, 0., 10., 5, 0., 5.);
      meOccupancyMem_[i]->setAxisTitle("pseudo-strip", 1);
      meOccupancyMem_[i]->setAxisTitle("channel", 2);
      dbe_->tag(meOccupancyMem_[i], i+1);
    }

    sprintf(histo, "EEOT digi occupancy EE -");
    meEEDigiOccupancy_[0] = dbe_->book2D(histo, histo, 100, 0., 100., 100, 0., 100.);
    meEEDigiOccupancy_[0]->setAxisTitle("jx", 1);
    meEEDigiOccupancy_[0]->setAxisTitle("jy", 2);
    sprintf(histo, "EEOT digi occupancy EE - projection x");
    meEEDigiOccupancyProjX_[0] = dbe_->book1D(histo, histo, 100, 0., 100.);
    meEEDigiOccupancyProjX_[0]->setAxisTitle("jx", 1);
    meEEDigiOccupancyProjX_[0]->setAxisTitle("number of digis", 2);
    sprintf(histo, "EEOT digi occupancy EE - projection y");
    meEEDigiOccupancyProjY_[0] = dbe_->book1D(histo, histo, 100, 0., 100.);
    meEEDigiOccupancyProjY_[0]->setAxisTitle("jy", 1);
    meEEDigiOccupancyProjY_[0]->setAxisTitle("number of digis", 2);

    sprintf(histo, "EEOT digi occupancy EE +");
    meEEDigiOccupancy_[1] = dbe_->book2D(histo, histo, 100, 0., 100., 100, 0., 100.);
    meEEDigiOccupancy_[1]->setAxisTitle("jx", 1);
    meEEDigiOccupancy_[1]->setAxisTitle("jy", 2);
    sprintf(histo, "EEOT digi occupancy EE + projection x");
    meEEDigiOccupancyProjX_[1] = dbe_->book1D(histo, histo, 100, 0., 100.);
    meEEDigiOccupancyProjX_[1]->setAxisTitle("jx", 1);
    meEEDigiOccupancyProjX_[1]->setAxisTitle("number of digis", 2);
    sprintf(histo, "EEOT digi occupancy EE + projection y");
    meEEDigiOccupancyProjY_[1] = dbe_->book1D(histo, histo, 100, 0., 100.);
    meEEDigiOccupancyProjY_[1]->setAxisTitle("jy", 1);
    meEEDigiOccupancyProjY_[1]->setAxisTitle("number of digis", 2);

    sprintf(histo, "EEOT rec hit occupancy EE -");
    meEERecHitOccupancy_[0] = dbe_->book2D(histo, histo, 100, 0., 100., 100, 0., 100.);
    meEERecHitOccupancy_[0]->setAxisTitle("jx", 1);
    meEERecHitOccupancy_[0]->setAxisTitle("jy", 2);
    sprintf(histo, "EEOT rec hit occupancy EE - projection x");
    meEERecHitOccupancyProjX_[0] = dbe_->book1D(histo, histo, 100, 0., 100.);
    meEERecHitOccupancyProjX_[0]->setAxisTitle("jx", 1);
    meEERecHitOccupancyProjX_[0]->setAxisTitle("number of hits", 2);
    sprintf(histo, "EEOT rec hit occupancy EE - projection y");
    meEERecHitOccupancyProjY_[0] = dbe_->book1D(histo, histo, 100, 0., 100.);
    meEERecHitOccupancyProjY_[0]->setAxisTitle("jy", 1);
    meEERecHitOccupancyProjY_[0]->setAxisTitle("number of hits", 2);

    sprintf(histo, "EEOT rec hit occupancy EE +");
    meEERecHitOccupancy_[1] = dbe_->book2D(histo, histo, 100, 0., 100., 100, 0., 100.);
    meEERecHitOccupancy_[1]->setAxisTitle("jx", 1);
    meEERecHitOccupancy_[1]->setAxisTitle("jy", 2);
    sprintf(histo, "EEOT rec hit occupancy EE + projection x");
    meEERecHitOccupancyProjX_[1] = dbe_->book1D(histo, histo, 100, 0., 100.);
    meEERecHitOccupancyProjX_[1]->setAxisTitle("jx", 1);
    meEERecHitOccupancyProjX_[1]->setAxisTitle("number of hits", 2);
    sprintf(histo, "EEOT rec hit occupancy EE + projection y");
    meEERecHitOccupancyProjY_[1] = dbe_->book1D(histo, histo, 100, 0., 100.);
    meEERecHitOccupancyProjY_[1]->setAxisTitle("jy", 1);
    meEERecHitOccupancyProjY_[1]->setAxisTitle("number of hits", 2);

    sprintf(histo, "EEOT trigger primitives digi occupancy EE -");
    meEETrigPrimDigiOccupancy_[0] = dbe_->book2D(histo, histo, 100, 0., 100., 100, 0., 100.);
    meEETrigPrimDigiOccupancy_[0]->setAxisTitle("jx", 1);
    meEETrigPrimDigiOccupancy_[0]->setAxisTitle("jy", 2);
    sprintf(histo, "EEOT trigger primitives digi occupancy EE - projection x");
    meEETrigPrimDigiOccupancyProjX_[0] = dbe_->book1D(histo, histo, 100, 0., 100.);
    meEETrigPrimDigiOccupancyProjX_[0]->setAxisTitle("jx", 1);
    meEETrigPrimDigiOccupancyProjX_[0]->setAxisTitle("number of TP digis", 2);
    sprintf(histo, "EEOT trigger primitives digi occupancy EE - projection y");
    meEETrigPrimDigiOccupancyProjY_[0] = dbe_->book1D(histo, histo, 100, 0., 100.);
    meEETrigPrimDigiOccupancyProjY_[0]->setAxisTitle("jy", 1);
    meEETrigPrimDigiOccupancyProjY_[0]->setAxisTitle("number of TP digis", 2);

    sprintf(histo, "EEOT trigger primitives digi occupancy EE +");
    meEETrigPrimDigiOccupancy_[1] = dbe_->book2D(histo, histo, 100, 0., 100., 100, 0., 100.);
    meEETrigPrimDigiOccupancy_[1]->setAxisTitle("jx", 1);
    meEETrigPrimDigiOccupancy_[1]->setAxisTitle("jy", 2);
    sprintf(histo, "EEOT trigger primitives digi occupancy EE + projection x");
    meEETrigPrimDigiOccupancyProjX_[1] = dbe_->book1D(histo, histo, 100, 0., 100.);
    meEETrigPrimDigiOccupancyProjX_[1]->setAxisTitle("jx", 1);
    meEETrigPrimDigiOccupancyProjX_[1]->setAxisTitle("number of TP digis", 2);
    sprintf(histo, "EEOT trigger primitives digi occupancy EE + projection y");
    meEETrigPrimDigiOccupancyProjY_[1] = dbe_->book1D(histo, histo, 100, 0., 100.);
    meEETrigPrimDigiOccupancyProjY_[1]->setAxisTitle("jy", 1);
    meEETrigPrimDigiOccupancyProjY_[1]->setAxisTitle("number of TP digis", 2);

  }

}

void EEOccupancyTask::cleanup(void){

  if ( ! enableCleanup_ ) return;

  if ( dbe_ ) {
    dbe_->setCurrentFolder("EcalEndcap/EEOccupancyTask");

    for (int i = 0; i < 18; i++) {
      if ( meOccupancy_[i] ) dbe_->removeElement( meOccupancy_[i]->getName() );
      meOccupancy_[i] = 0;
      if ( meOccupancyMem_[i] ) dbe_->removeElement( meOccupancyMem_[i]->getName() );
      meOccupancyMem_[i] = 0;
    }

    if ( meEEDigiOccupancy_[0] ) dbe_->removeElement( meEEDigiOccupancy_[0]->getName() );
    meEEDigiOccupancy_[0] = 0;
    if ( meEEDigiOccupancyProjX_[0] ) dbe_->removeElement( meEEDigiOccupancyProjX_[0]->getName() );
    meEEDigiOccupancyProjX_[0] = 0;
    if ( meEEDigiOccupancyProjY_[0] ) dbe_->removeElement( meEEDigiOccupancyProjY_[0]->getName() );
    meEEDigiOccupancyProjY_[0] = 0;

    if ( meEEDigiOccupancy_[1] ) dbe_->removeElement( meEEDigiOccupancy_[1]->getName() );
    meEEDigiOccupancy_[1] = 0;
    if ( meEEDigiOccupancyProjX_[1] ) dbe_->removeElement( meEEDigiOccupancyProjX_[1]->getName() );
    meEEDigiOccupancyProjX_[1] = 0;
    if ( meEEDigiOccupancyProjY_[1] ) dbe_->removeElement( meEEDigiOccupancyProjY_[1]->getName() );
    meEEDigiOccupancyProjY_[1] = 0;

    if ( meEERecHitOccupancy_[0] ) dbe_->removeElement( meEERecHitOccupancy_[0]->getName() );
    meEERecHitOccupancy_[0] = 0;
    if ( meEERecHitOccupancyProjX_[0] ) dbe_->removeElement( meEERecHitOccupancyProjX_[0]->getName() );
    meEERecHitOccupancyProjX_[0] = 0;
    if ( meEERecHitOccupancyProjY_[0] ) dbe_->removeElement( meEERecHitOccupancyProjY_[0]->getName() );
    meEERecHitOccupancyProjY_[0] = 0;

    if ( meEERecHitOccupancy_[1] ) dbe_->removeElement( meEERecHitOccupancy_[1]->getName() );
    meEERecHitOccupancy_[1] = 0;
    if ( meEERecHitOccupancyProjX_[1] ) dbe_->removeElement( meEERecHitOccupancyProjX_[1]->getName() );
    meEERecHitOccupancyProjX_[1] = 0;
    if ( meEERecHitOccupancyProjY_[1] ) dbe_->removeElement( meEERecHitOccupancyProjY_[1]->getName() );
    meEERecHitOccupancyProjY_[1] = 0;

    if ( meEETrigPrimDigiOccupancy_[0] ) dbe_->removeElement( meEETrigPrimDigiOccupancy_[0]->getName() );
    meEETrigPrimDigiOccupancy_[0] = 0;
    if ( meEETrigPrimDigiOccupancyProjX_[0] ) dbe_->removeElement( meEETrigPrimDigiOccupancyProjX_[0]->getName() );
    meEETrigPrimDigiOccupancyProjX_[0] = 0;
    if ( meEETrigPrimDigiOccupancyProjY_[0] ) dbe_->removeElement( meEETrigPrimDigiOccupancyProjY_[0]->getName() );
    meEETrigPrimDigiOccupancyProjY_[0] = 0;

    if ( meEETrigPrimDigiOccupancy_[1] ) dbe_->removeElement( meEETrigPrimDigiOccupancy_[1]->getName() );
    meEETrigPrimDigiOccupancy_[1] = 0;
    if ( meEETrigPrimDigiOccupancyProjX_[1] ) dbe_->removeElement( meEETrigPrimDigiOccupancyProjX_[1]->getName() );
    meEETrigPrimDigiOccupancyProjX_[1] = 0;
    if ( meEETrigPrimDigiOccupancyProjY_[1] ) dbe_->removeElement( meEETrigPrimDigiOccupancyProjY_[1]->getName() );
    meEETrigPrimDigiOccupancyProjY_[1] = 0;

  }

  init_ = false;

}

void EEOccupancyTask::endJob(void) {

  LogInfo("EEOccupancyTask") << "analyzed " << ievt_ << " events";

  if ( init_ ) this->cleanup();

}

void EEOccupancyTask::analyze(const Event& e, const EventSetup& c){

  if ( ! init_ ) this->setup();

  ievt_++;

  Handle<EEDigiCollection> digis;

  if ( e.getByLabel(EEDigiCollection_, digis) ) {

    int need = digis->size();
    LogDebug("EEOccupancyTask") << "event " << ievt_ << " digi collection size " << need;

    for ( EEDigiCollection::const_iterator digiItr = digis->begin(); digiItr != digis->end(); ++digiItr ) {

      EEDataFrame dataframe = (*digiItr);
      EEDetId id = dataframe.id();

      int ix = id.ix();
      int iy = id.iy();

      int ism = Numbers::iSM( id );

      if ( ism >= 1 && ism <= 9 ) ix = 101 - ix;

      float xix = ix - 0.5;
      float xiy = iy - 0.5;

      LogDebug("EEOccupancyTask") << " det id = " << id;
      LogDebug("EEOccupancyTask") << " sm, ix, iy " << ism << " " << ix << " " << iy;

      if ( xix <= 0. || xix >= 100. || xiy <= 0. || xiy >= 100. ) {
        LogWarning("EEOccupancyTask") << " det id = " << id;
        LogWarning("EEOccupancyTask") << " sm, ix, iw " << ism << " " << ix << " " << iy;
        LogWarning("EEOccupancyTask") << " xix, xiy " << xix << " " << xiy;
      }

      if ( meOccupancy_[ism-1] ) meOccupancy_[ism-1]->Fill( xix, xiy );

      int eex = id.ix();
      int eey = id.iy();

      if ( ism >= 1 && ism <= 9 ) eex = 101 - eex;

      if ( ism >=1 && ism <= 9 ) {
        if ( meEEDigiOccupancy_[0] ) meEEDigiOccupancy_[0]->Fill( eex, eey );
        if ( meEEDigiOccupancyProjX_[0] ) meEEDigiOccupancyProjX_[0]->Fill( eex );
        if ( meEEDigiOccupancyProjY_[0] ) meEEDigiOccupancyProjY_[0]->Fill( eey );
      } else {
        if ( meEEDigiOccupancy_[1] ) meEEDigiOccupancy_[1]->Fill( eex, eey );
        if ( meEEDigiOccupancyProjX_[1] ) meEEDigiOccupancyProjX_[1]->Fill( eex );
        if ( meEEDigiOccupancyProjY_[1] ) meEEDigiOccupancyProjY_[1]->Fill( eey );
      }

    }

  } else {

    LogWarning("EEOccupancyTask") << EEDigiCollection_ << " not available";

  }

  Handle<EcalPnDiodeDigiCollection> PNs;

  if ( e.getByLabel(EcalPnDiodeDigiCollection_, PNs) ) {

    // filling mem occupancy only for the 5 channels belonging
    // to a fully reconstructed PN's

    for ( EcalPnDiodeDigiCollection::const_iterator pnItr = PNs->begin(); pnItr != PNs->end(); ++pnItr ) {

      EcalPnDiodeDigi pn = (*pnItr);
      EcalPnDiodeDetId id = pn.id();

      if ( Numbers::subDet( id ) != EcalEndcap ) continue;

      int   ism   = Numbers::iSM( id );

      float PnId  = (*pnItr).id().iPnId();

      PnId        = PnId - 0.5;
      float st    = 0.0;

      for (int chInStrip = 1; chInStrip <= 5; chInStrip++){
        if ( meOccupancyMem_[ism-1] ) {
           st = chInStrip - 0.5;
           meOccupancyMem_[ism-1]->Fill(PnId, st);
        }
      }

    }

  } else {

    LogWarning("EEOccupancyTask") << EcalPnDiodeDigiCollection_ << " not available";

  }

  Handle<EcalRecHitCollection> rechits;

  if ( e.getByLabel(EcalRecHitCollection_, rechits) ) {

    int nebrh = rechits->size();
    LogDebug("EEOccupancyTask") << "event " << ievt_ << " rec hits collection size " << nebrh;

    for ( EcalRecHitCollection::const_iterator rechitItr = rechits->begin(); rechitItr != rechits->end(); ++rechitItr ) {

      EEDetId id = rechitItr->id();

      int eex = id.ix();
      int eey = id.iy();

      int ism = Numbers::iSM( id );

      if ( ism >= 1 && ism <= 9 ) eex = 101 - eex;

      if ( ism >= 1 && ism <= 9 ) {
        if ( meEERecHitOccupancy_[0] ) meEERecHitOccupancy_[0]->Fill( eex, eey );
        if ( meEERecHitOccupancyProjX_[0] ) meEERecHitOccupancyProjX_[0]->Fill( eex );
        if ( meEERecHitOccupancyProjY_[0] ) meEERecHitOccupancyProjY_[0]->Fill( eey );
      } else {
        if ( meEERecHitOccupancy_[1] ) meEERecHitOccupancy_[1]->Fill( eex, eey );
        if ( meEERecHitOccupancyProjX_[1] ) meEERecHitOccupancyProjX_[1]->Fill( eex );
        if ( meEERecHitOccupancyProjY_[1] ) meEERecHitOccupancyProjY_[1]->Fill( eey );
      }

    }

  } else {

    LogWarning("EEOccupancyTask") << EcalRecHitCollection_ << " not available";

  }

  Handle<EcalTrigPrimDigiCollection> trigPrimDigis;

  if ( e.getByLabel(EcalTrigPrimDigiCollection_, trigPrimDigis) ) {

    int nebtpg = trigPrimDigis->size();
    LogDebug("EEOccupancyTask") << "event " << ievt_ << " trigger primitives digis collection size " << nebtpg;

    for ( EcalTrigPrimDigiCollection::const_iterator tpdigiItr = trigPrimDigis->begin(); tpdigiItr != trigPrimDigis->end(); ++tpdigiItr ) {

      EcalTriggerPrimitiveDigi data = (*tpdigiItr);
      EcalTrigTowerDetId idt = data.id();

      if ( Numbers::subDet( idt ) != EcalEndcap ) continue;
      
      int ismt = Numbers::iSM( idt );
      
      vector<DetId> crystals = Numbers::crystals( idt );
      
      for ( unsigned int i=0; i<crystals.size(); i++ ) {
        
      EEDetId id = crystals[i];
        
      int eex = id.ix();
      int eey = id.iy();
        
      if ( ismt >= 1 && ismt <= 9 ) eex = 101 - eex;

      if ( ismt >= 1 && ismt <= 9 ) {
        if ( meEETrigPrimDigiOccupancy_[0] ) meEETrigPrimDigiOccupancy_[0]->Fill( eex, eey );
        if ( meEETrigPrimDigiOccupancyProjX_[0] ) meEETrigPrimDigiOccupancyProjX_[0]->Fill( eex );
        if ( meEETrigPrimDigiOccupancyProjY_[0] ) meEETrigPrimDigiOccupancyProjY_[0]->Fill( eey );
      } else {
        if ( meEETrigPrimDigiOccupancy_[1] ) meEETrigPrimDigiOccupancy_[1]->Fill( eex, eey );
        if ( meEETrigPrimDigiOccupancyProjX_[1] ) meEETrigPrimDigiOccupancyProjX_[1]->Fill( eex );
        if ( meEETrigPrimDigiOccupancyProjY_[1] ) meEETrigPrimDigiOccupancyProjY_[1]->Fill( eey );
      }

      }

    }

  } else {

    LogWarning("EEOccupancyTask") << EcalTrigPrimDigiCollection_ << " not available";

  }

}

