// #include "CondFormats/PhysicsToolsObjects/interface/Histogram2D.h"
#include "CondFormats/RecoMuonObjects/interface/MuScleFitDBobject.h"
#include "CondFormats/DataRecord/interface/MuScleFitDBobjectRcd.h"

#include "DBReader.h"

#include <iostream>
#include <stdio.h>
#include <sys/time.h>
#include <string>

using namespace std;
using namespace cms;

DBReader::DBReader( const edm::ParameterSet& iConfig ) : type_(iConfig.getUntrackedParameter<string>("Type"))
{
}

void DBReader::initialize( const edm::EventSetup& iSetup )
{
  edm::ESHandle<MuScleFitDBobject> dbObject;
  iSetup.get<MuScleFitDBobjectRcd>().get(dbObject);
  edm::LogInfo("DBReader") << "[DBReader::analyze] End Reading MuScleFitDBobjectRcd" << endl;

  cout << "identifiers size from dbObject = " << dbObject->identifiers.size() << endl;
  cout << "parameters size from dbObject = " << dbObject->parameters.size() << endl;;

  // This string is one of: scale, resolution, background.
  // Create the corrector and set the parameters
  if( type_ == "scale" ) corrector_.reset(new MomentumScaleCorrector( dbObject.product() ) );
  else if( type_ == "resolution" ) resolution_.reset(new ResolutionFunction( dbObject.product() ) );
  else if( type_ == "background" ) background_.reset(new BackgroundFunction( dbObject.product() ) );
  else {
    cout << "Error: unrecognized type. Use one of those: 'scale', 'resolution', 'background'" << endl;
    exit(1);
  }

  // cout << "pointer = " << corrector_.get() << endl;
}

//:  printdebug_(iConfig.getUntrackedParameter<uint32_t>("printDebug",1)){}

DBReader::~DBReader(){}

void DBReader::analyze( const edm::Event& e, const edm::EventSetup& iSetup)
{
  initialize(iSetup);
  if( type_ == "scale" ) printParameters(corrector_);
  else if( type_ == "resolution" ) printParameters(resolution_);
  else if( type_ == "background" ) printParameters(background_);
}

#include "FWCore/PluginManager/interface/ModuleDef.h"
#include "FWCore/Framework/interface/MakerMacros.h"
DEFINE_SEAL_MODULE();
DEFINE_ANOTHER_FWK_MODULE(DBReader);
