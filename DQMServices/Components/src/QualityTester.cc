/*
 * \file QualityTester.cc
 * 
 * $Date: 2007/07/08 21:03:55 $
 * $Revision: 1.4.2.1 $
 * \author M. Zanetti - CERN PH
 *
 */

#include "DQMServices/Components/interface/QualityTester.h"

// Framework
#include <FWCore/Framework/interface/Event.h>
#include <FWCore/Framework/interface/ESHandle.h>
#include <FWCore/Framework/interface/MakerMacros.h>
#include <FWCore/Framework/interface/EventSetup.h>
#include <FWCore/ParameterSet/interface/ParameterSet.h>
#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include <DQMServices/UI/interface/MonitorUIRoot.h>
#include "DQMServices/ClientConfig/interface/QTestHandle.h"


#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <math.h>

using namespace edm;
using namespace std;


QualityTester::QualityTester(const ParameterSet& ps){
  
  parameters = ps;

  nevents = 0;

  mui = new MonitorUIRoot();
  bei = mui->getBEInterface();

  qtHandler=new QTestHandle;

  // if you use this module, it's non-sense not to provide the QualityTests.xml
  if (parameters.getUntrackedParameter<bool>("getQualityTestsFromFile", true))
    qtHandler->configureTests(parameters.getUntrackedParameter<string>("qtList",
    "QualityTests.xml"),bei);
  
}


QualityTester::~QualityTester() { 
 
  delete mui;
  delete qtHandler;

}


void QualityTester::analyze(const Event& e, const EventSetup& c){

  nevents++;

  // run QT test every "QualityTestPrescaler" event
  if (parameters.getUntrackedParameter<bool>("getQualityTestsFromFile", true) &&
      nevents%parameters.getUntrackedParameter<int>("QualityTestPrescaler", 1000) == 0) {

    // always needed..
    mui->doMonitoring();

    // done here because new ME can appear while processing data
    qtHandler->attachTests(bei);

    edm::LogVerbatim ("QualityTester") <<"Running the Quality Test";    

    bei->runQTests();

  }

}
