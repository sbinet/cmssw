#ifndef DUPLICATIONCHECKER_H
#define DUPLICATIONCHECKER_H

/*class DuplicationChecker
 *  
 *  Class to monitor duplication of events
 *
 *  $Date: 2010/03/19 09:10:56 $
 *  $Revision: 1.2 $
 *
 */

// framework & common header files
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/Run.h"

#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"

//DQM services
#include "DQMServices/Core/interface/DQMStore.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "DQMServices/Core/interface/MonitorElement.h"

#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include <map>
#include <vector>

#include "SimDataFormats/GeneratorProducts/interface/HepMCProduct.h"
#include "SimDataFormats/GeneratorProducts/interface/LHEEventProduct.h"
#include "DataFormats/Provenance/interface/EventID.h"

class DuplicationChecker : public edm::EDAnalyzer
{
  
 public:

  typedef std::multimap<double,edm::EventID> associationMap;
  typedef std::vector<associationMap::iterator> itemList;

  explicit DuplicationChecker(const edm::ParameterSet&);
  virtual ~DuplicationChecker();
  void beginJob();
  void endJob();  
  void analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup);
  virtual void beginRun(const edm::Run&, const edm::EventSetup&){ return;}
  virtual void endRun(const edm::Run&, const edm::EventSetup&){ return;}
  void findValuesAssociatedWithKey(associationMap &mMap, double &key, itemList &theObjects);  
  
 private:
  
  edm::InputTag generatedCollection_;
  
  bool searchForLHE_;

  associationMap xBjorkenHistory;
	
  DQMStore *dbe;

  MonitorElement* xBjorkenME;

};

#endif
