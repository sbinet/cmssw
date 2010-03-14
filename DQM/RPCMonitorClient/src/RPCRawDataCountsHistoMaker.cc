#include "DQM/RPCMonitorClient/interface/RPCRawDataCountsHistoMaker.h"
#include "EventFilter/RPCRawToDigi/interface/RPCRawDataCounts.h"
#include "EventFilter/RPCRawToDigi/interface/DataRecord.h"
#include "EventFilter/RPCRawToDigi/interface/ReadoutError.h"

#include "TH1F.h"
#include "TH2F.h"

#include <vector>
#include <sstream>
using namespace rpcrawtodigi;
using namespace std;


TH1F * RPCRawDataCountsHistoMaker::emptyReadoutErrorHisto(int fedId) {
  ostringstream str;
  str <<"readoutErrors_"<<fedId;
  TH1F * result = new TH1F(str.str().c_str(),str.str().c_str(),9, 0.5,9.5);
  for (unsigned int i=1; i<=9; ++i) {
    ReadoutError::ReadoutErrorType code =  static_cast<ReadoutError::ReadoutErrorType>(i);
    result->GetXaxis()->SetBinLabel(i,ReadoutError::name(code).c_str());
  }
  return result;
}

TH1F * RPCRawDataCountsHistoMaker::emptyRecordTypeHisto(int fedId) {
  ostringstream str;
  str <<"recordType_"<<fedId;
  TH1F * result = new TH1F(str.str().c_str(),str.str().c_str(),9, 0.5,9.5);
  result->SetTitleOffset(1.4,"x");
  for (unsigned int i=1; i<=9; ++i) {
    DataRecord::DataRecordType code = static_cast<DataRecord::DataRecordType>(i);
    result->GetXaxis()->SetBinLabel(i,DataRecord::name(code).c_str());
  }
  return result;
}

TH2F * RPCRawDataCountsHistoMaker::emptyReadoutErrorMapHisto(int fedId, int type) {
  ostringstream str;
  ReadoutError::ReadoutErrorType code =  static_cast<ReadoutError::ReadoutErrorType>(type);
  str <<"errors_"<<ReadoutError::name(code)<<"_"<<fedId;
  TH2F * result = new TH2F(str.str().c_str(),str.str().c_str(), 36,-0.5,35.5, 18,-0.5,17.5);
  result->GetXaxis()->SetNdivisions(512);
  result->GetYaxis()->SetNdivisions(505);
  result->SetXTitle("rmb");
  result->SetYTitle("link");
  result->SetStats(0);
  return result;
}
