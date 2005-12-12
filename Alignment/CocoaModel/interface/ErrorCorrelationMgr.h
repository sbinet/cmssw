//   COCOA class header file
//Id:  ErrorCorrelationMgr.h
//CAT: Model
//
//   Manages the error correlations
// 
//   History: v1.0  29/01/02   Pedro Arce

#ifndef ErrorCorrelationMgr_h
#define ErrorCorrelationMgr_h

#include "OpticalAlignment/CocoaUtilities/interface/CocoaGlobals.h" 
#include <vector>
#include <map>
typedef std::map<ALIstring, ALIdouble, std::less<ALIstring> > msd;

class ErrorCorrelation;

class ErrorCorrelationMgr {

 private:
  ErrorCorrelationMgr(){};

 public:
  static ErrorCorrelationMgr* getInstance();
  void readFromReportFile( const ALIstring& filename );
  ErrorCorrelation* getCorrelation( ALIint ii );

  ALIint getNumberOfCorrelations(){ 
    return theCorrs.size(); }

 private:
  static ErrorCorrelationMgr* theInstance;
  std::vector<ErrorCorrelation*> theCorrs;

};

#endif
