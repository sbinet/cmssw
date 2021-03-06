#ifndef POPCON_RPC_DATA_SRC_H
#define POPCON_RPC_DATA_SRC_H

/*
 * \class RpcData
 *  Core of RPC PopCon Appication
 *
 *  \author D. Pagano - Dip. Fis. Nucl. e Teo. & INFN Pavia
 */

#include "CondCore/PopCon/interface/PopConSourceHandler.h"

#include "CondFormats/RPCObjects/interface/RPCObCond.h"
#include "CondFormats/DataRecord/interface/RPCObCondRcd.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "CondTools/RPC/interface/RPCFw.h"
#include<string>

namespace popcon{
  class RpcDataT : public popcon::PopConSourceHandler<RPCObTemp>{
  public:
    void getNewObjects();
    std::string id() const { return m_name;}
    ~RpcDataT(); 
    RpcDataT(const edm::ParameterSet& pset); 

    RPCObTemp* Tdata;

  private:
    std::string m_name;
    std::string host;
    std::string user;
    std::string passw;
    bool m_first;
    unsigned long long m_since;
    unsigned long long m_range;
  };
}
#endif

