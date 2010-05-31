#ifndef Fireworks_Core_FWDisplayProperties_h
#define Fireworks_Core_FWDisplayProperties_h
// -*- C++ -*-
//
// Package:     Core
// Class  :     FWDisplayProperties
//
/**\class FWDisplayProperties FWDisplayProperties.h Fireworks/Core/interface/FWDisplayProperties.h

   Description: <one line class summary>

   Usage:
    <usage>

 */
//
// Original Author:
//         Created:  Thu Jan  3 14:22:36 EST 2008
// $Id: FWDisplayProperties.h,v 1.7 2009/01/23 21:35:41 amraktad Exp $
//

// system include files
#include "Rtypes.h"

// user include files

// forward declarations

class FWDisplayProperties
{

public:
   static const FWDisplayProperties defaultProperties;
   /** Note that I removed the default values to make sure that properties do
       not get copied around via the not so uncommon paradigm:
       
       FWDisplayProperties new(old.color(), old.isVisible());
       
       or similar which has the drawback of not carring over transparency 
       information.
       
       In general it's a good idea to have a copy and modify approach when
       changing updating only one value.
     */
   FWDisplayProperties(const Color_t& iColor,
                       bool isVisible);
   //virtual ~FWDisplayProperties();

   // ---------- const member functions ---------------------
   const Color_t& color() const {
      return m_color;
   }

   bool isVisible() const {
      return m_isVisible;
   }

   bool operator==(const FWDisplayProperties& iRHS) const {
      return m_color == iRHS.m_color && m_isVisible == iRHS.m_isVisible;
   }
   bool operator!=(const FWDisplayProperties& iRHS) const {
      return not (*this == iRHS);
   }

   // ---------- static member functions --------------------

   // ---------- member functions ---------------------------
   void setIsVisible(bool iSet) {
      m_isVisible = iSet;
   }

   void setColor(Color_t iColor);
private:
   //FWDisplayProperties(const FWDisplayProperties&); // stop default

   //const FWDisplayProperties& operator=(const FWDisplayProperties&); // stop default

   // ---------- member data --------------------------------
   Color_t m_color;
   bool m_isVisible;
};


#endif
