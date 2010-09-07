// -*- C++ -*-
//
// Package:     Muon
// Class  :     FWCSCWireDigiProxyBuilder
//
// Implementation:
//     <Notes on implementation>
//
// Original Author: mccauley
//         Created:  Sun Jan  6 23:57:00 EST 2008
// $Id: FWCSCWireDigiProxyBuilder.cc,v 1.16 2010/09/06 15:49:55 yana Exp $
//

#include "TEveStraightLineSet.h"
#include "TEveCompound.h"

#include "Fireworks/Core/interface/FWProxyBuilderBase.h"
#include "Fireworks/Core/interface/FWEventItem.h"
#include "Fireworks/Core/interface/FWGeometry.h"
#include "Fireworks/Core/interface/fwLog.h"

#include "DataFormats/CSCDigi/interface/CSCWireDigiCollection.h"

#include <cmath>

class FWCSCWireDigiProxyBuilder : public FWProxyBuilderBase
{
public:
  FWCSCWireDigiProxyBuilder() {}
  virtual ~FWCSCWireDigiProxyBuilder() {}

  REGISTER_PROXYBUILDER_METHODS();

private:
  virtual void build(const FWEventItem* iItem, TEveElementList* product, const FWViewContext*);
  FWCSCWireDigiProxyBuilder(const FWCSCWireDigiProxyBuilder&);    
  const FWCSCWireDigiProxyBuilder& operator=(const FWCSCWireDigiProxyBuilder&);

  // NOTE: these parameters are not available via a public interface
  // from the geometry or topology so must be hard-coded.
  double getYOfFirstWire(const int station, const int ring, const double length);
};
       
double
FWCSCWireDigiProxyBuilder::getYOfFirstWire(const int station, const int ring, const double length)                             
{
  double yAlignmentFrame = 3.49;
  double alignmentPinToFirstWire;

  if ( station == 1 ) 
  { 
    if ( ring == 1 || ring == 4 )
    {
      alignmentPinToFirstWire = 1.065;
      yAlignmentFrame = 0.0;
    }
        
    else // ME12, ME 13 
      alignmentPinToFirstWire = 2.85;
  }
  
  else if ( station == 4 && ring == 1 )
    alignmentPinToFirstWire = 3.04;
      
  else if ( station == 3 && ring == 1 )
    alignmentPinToFirstWire =  2.84;
      
  else  // ME21, ME22, ME32, ME42 
    alignmentPinToFirstWire = 2.87;
  
  return (yAlignmentFrame-length) + alignmentPinToFirstWire;
}

void
FWCSCWireDigiProxyBuilder::build(const FWEventItem* iItem, TEveElementList* product, const FWViewContext*)
{
  const CSCWireDigiCollection* digis = 0;
 
  iItem->get(digis);

  if ( ! digis ) 
  {
    fwLog( fwlog::kWarning ) << "Failed to get CSCWireDigis" << std::endl;
    return;
  }
  const FWGeometry *geom = iItem->getGeom();

  for ( CSCWireDigiCollection::DigiRangeIterator dri = digis->begin(), driEnd = digis->end(); 
        dri != driEnd; ++dri )
  {
    const CSCDetId& cscDetId = (*dri).first;
    unsigned int rawid = cscDetId.rawId();
    const CSCWireDigiCollection::Range& range = (*dri).second;
 
    if( ! geom->contains( rawid ))
    {
      fwLog( fwlog::kWarning ) << "Failed to get geometry of CSC chamber with detid: "
			       << rawid << std::endl;
      
      TEveCompound* compound = createCompound();
      setupAddElement( compound, product );

      continue;
    }

    const float* shape = geom->getShapePars( rawid );

    float length = shape[4];
    float topWidth = shape[2];
    float bottomWidth = shape[1];
    
    const float* parameters = iItem->getGeom()->getParameters( rawid );
    
    float wireSpacing  = parameters[6];
    float wireAngle    = parameters[7];
    float cosWireAngle = cos(wireAngle);

    double yOfFirstWire = getYOfFirstWire( cscDetId.station(), cscDetId.ring(), length ); 
             
    for ( CSCWireDigiCollection::const_iterator dit = range.first;
          dit != range.second; ++dit )        
    { 
      TEveStraightLineSet* wireDigiSet = new TEveStraightLineSet();
      wireDigiSet->SetLineWidth(3);
      setupAddElement(wireDigiSet, product);

      int wireGroup = (*dit).getWireGroup();

      float yOfWire = yOfFirstWire + ((wireGroup-1)*wireSpacing)/cosWireAngle;
      yOfWire += length;

      float wireLength = yOfWire*(topWidth-bottomWidth) / length;
      wireLength += bottomWidth*2.0;
     
      float localPointLeft[3] = 
      {
        -wireLength*0.5, yOfWire, 0.0
      };

      // NOTE: This is only an approximation for slanted wires.
      // Need to improve the determination of the x coordinate.
      float localPointRight[3] = 
      {
        wireLength*0.5, yOfWire + wireLength*tan(wireAngle), 0.0
      };

      float globalPointLeft[3];     
      float globalPointRight[3];

      geom->localToGlobal( rawid, localPointLeft, globalPointLeft, localPointRight, globalPointRight ); 
      
      wireDigiSet->AddLine( globalPointLeft[0],  globalPointLeft[1],  globalPointLeft[2],
                            globalPointRight[0], globalPointRight[1], globalPointRight[2] );
    }
  }
}

REGISTER_FWPROXYBUILDER(FWCSCWireDigiProxyBuilder, CSCWireDigiCollection, "CSCWireDigi", 
                        FWViewType::kAll3DBits | FWViewType::kAllRPZBits);


