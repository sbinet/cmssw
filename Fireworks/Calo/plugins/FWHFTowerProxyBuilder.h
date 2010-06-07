#ifndef Fireworks_Calo_FWHFTowerProxyBuilder_h
#define Fireworks_Calo_FWHFTowerProxyBuilder_h
// -*- C++ -*-
//
// Package:     Calo
// Class  :     FWHFTowerProxyBuilder
// 
/**\class FWHFTowerProxyBuilder FWHFTowerProxyBuilder.h Fireworks/Calo/interface/FWHFTowerProxyBuilder.h

 Description: [one line class summary]

 Usage:
    <usage>

*/
//
// Original Author:  
//         Created:  Mon May 31 16:41:23 CEST 2010
// $Id: FWHFTowerProxyBuilder.h,v 1.3 2010/06/03 14:48:22 amraktad Exp $
//

// system include files
#include <map>

// user include files
#include "Fireworks/Calo/interface/FWCaloDataProxyBuilderBase.h"
#include "Fireworks/Calo/src/FWFromTEveCaloDataSelector.h"
#include "DataFormats/HcalRecHit/interface/HFRecHit.h"
#include "DataFormats/HcalRecHit/interface/HcalRecHitCollections.h"

class TEveCaloDataVec;
//
// base
//
class FWHFTowerProxyBuilderBase : public FWCaloDataProxyBuilderBase
{
public:
   FWHFTowerProxyBuilderBase(int depth);
   virtual ~FWHFTowerProxyBuilderBase();
  
   // ---------- const member functions ---------------------
  
   // ---------- static member functions --------------------
  
   // ---------- member functions ---------------------------
   virtual const std::string sliceName() const { return "HF slice";}

protected:
   virtual void setCaloData(const fireworks::Context&);
   virtual void fillCaloData();
   virtual bool assertCaloDataSlice();
  
private:
  
   FWHFTowerProxyBuilderBase(const FWHFTowerProxyBuilderBase&); // stop default
  
   const FWHFTowerProxyBuilderBase& operator=(const FWHFTowerProxyBuilderBase&); // stop default
  
   virtual void build(const FWEventItem* iItem,
                      TEveElementList* product, const FWViewContext*);
  
   int fillTowerForDetId(HcalDetId&, float);
   // ---------- member data --------------------------------
  

   static std::map<int, int>  m_detIdMap;

   const HFRecHitCollection* m_hits;
   int   m_depth;
   TEveCaloDataVec* m_vecData;  
};


//
// ShortFiber
//

class FWHFShortTowerProxyBuilder : public FWHFTowerProxyBuilderBase
{
public:
  FWHFShortTowerProxyBuilder() : FWHFTowerProxyBuilderBase(1) {
  }
  virtual ~FWHFShortTowerProxyBuilder() {
  }
  
  // ---------- const member functions ---------------------
  virtual const std::string sliceName() const {
    return "HFShort";
  }; 
  
  REGISTER_PROXYBUILDER_METHODS();
  
private:
  FWHFShortTowerProxyBuilder(const FWHFShortTowerProxyBuilder&); // stop default
  const FWHFShortTowerProxyBuilder& operator=(const FWHFShortTowerProxyBuilder&); // stop default
};


//
// LongFiber
//

class FWHFLongTowerProxyBuilder : public FWHFTowerProxyBuilderBase
{
public:
  FWHFLongTowerProxyBuilder() : FWHFTowerProxyBuilderBase(2) {
  }
  virtual ~FWHFLongTowerProxyBuilder(){
  }
  
  // ---------- const member functions ---------------------
  virtual const std::string sliceName() const {
    return "HFLong";
  }
  
  
  REGISTER_PROXYBUILDER_METHODS();
private:
  FWHFLongTowerProxyBuilder(const FWHFLongTowerProxyBuilder&); // stop default
  
  const FWHFLongTowerProxyBuilder& operator=(const FWHFLongTowerProxyBuilder&); // stop default
};

#endif
