#ifndef ShiftTTrigDB_H
#define ShiftTTrigDB_H

/** \class ShiftTTrigDB
 *  Class which read a ttrig DB and modifies it introducing
 *  shifts with chamber granularity
 *
 *  $Date: 2007/11/09 16:02:14 $
 *  $Revision: 1.0 $
 *  \author S. Bolognesi - INFN Torino
 */

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include <FWCore/Framework/interface/ESHandle.h>

#include <string>

class DTTtrig;
class DTGeometry;

class ShiftTTrigDB : public edm::EDAnalyzer {
public:
  /// Constructor
  ShiftTTrigDB(const edm::ParameterSet& pset);

  /// Destructor
  virtual ~ShiftTTrigDB();

  // Operations

  virtual void beginJob(const edm::EventSetup& setup);

  virtual void analyze(const edm::Event& event, const edm::EventSetup& setup){}

  virtual void endJob();

protected:

private:
  const DTTtrig *tTrigMap;
  edm::ESHandle<DTGeometry> muonGeom;

  std::vector<std::vector<int> > chambers;
  std::vector<double> shifts;
  std::map<std::vector <int>, double> mapShiftsByChamber;
  bool debug;

};
#endif

