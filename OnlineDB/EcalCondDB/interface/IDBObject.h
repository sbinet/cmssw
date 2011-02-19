#ifndef IDBOBJECT_H
#define IDBOBJECT_H

#include <stdexcept>
#include "OnlineDB/Oracle/interface/Oracle.h"

// XXX remove later
#include <iostream>
using namespace std;

/**
 *  Abstract base class for objects storable in the database
 */
class IDBObject {
 public:
  // give the interface class permission to use the functions
  friend class EcalCondDBInterface;

  static int const ECALDB_NROWS=1000;
  
  virtual ~IDBObject() {}

  // Sets the connection
  inline void setConnection(oracle::occi::Environment* env, oracle::occi::Connection* conn) 
    {
      m_env = env;
      m_conn = conn;
    }

  


 protected:
  // Database connection to use
  oracle::occi::Environment* m_env;
  oracle::occi::Connection* m_conn;
  
  void checkConnection() const
    throw(std::runtime_error)
    {
      if (m_conn == NULL) {
	throw std::runtime_error("ERROR:  Connection was not set");
      }
    }
};

#endif
