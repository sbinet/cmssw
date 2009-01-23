#include "FastSimulation/Tracking/interface/TrackerRecHit.h"
#include "FastSimulation/TrackerSetup/interface/TrackerInteractionGeometry.h"

TrackerRecHit::TrackerRecHit(const SiTrackerGSMatchedRecHit2D* theHit, 
			     const TrackerGeometry* theGeometry) :
  theSplitHit(0),
  theMatchedHit(theHit),
  theSubDetId(0),
  theLayerNumber(0),
  theRingNumber(0),
  theCylinderNumber(0),
  theLocalError(0.),
  theLargerError(0.)
     
{ 
  init(theGeometry);
}

TrackerRecHit::TrackerRecHit(const SiTrackerGSRecHit2D* theHit, 
			     const TrackerGeometry* theGeometry) :
  theSplitHit(theHit),
  theMatchedHit(0),
  theSubDetId(0),
  theLayerNumber(0),
  theRingNumber(0),
  theCylinderNumber(0),
  theLocalError(0.),
  theLargerError(0.)
     
{ 
  init(theGeometry);
}

void
TrackerRecHit::init(const TrackerGeometry* theGeometry) { 

  const DetId& theDetId = hit()->geographicalId();
  theGeomDet = theGeometry->idToDet(theDetId);
  theSubDetId = theDetId.subdetId(); 
  if ( theSubDetId == StripSubdetector::TIB) { 
    TIBDetId tibid(theDetId.rawId()); 
    theLayerNumber = tibid.layer();
    theCylinderNumber = TrackerInteractionGeometry::TIB+theLayerNumber;
    forward = false;
  } else if ( theSubDetId ==  StripSubdetector::TOB ) { 
    TOBDetId tobid(theDetId.rawId()); 
    theLayerNumber = tobid.layer();
    theCylinderNumber = TrackerInteractionGeometry::TOB+theLayerNumber;
    forward = false;
  } else if ( theSubDetId ==  StripSubdetector::TID) { 
    TIDDetId tidid(theDetId.rawId());
    theLayerNumber = tidid.wheel();
    theCylinderNumber = TrackerInteractionGeometry::TID+theLayerNumber;
    theRingNumber = tidid.ring();
    forward = true;
  } else if ( theSubDetId ==  StripSubdetector::TEC ) { 
    TECDetId tecid(theDetId.rawId()); 
    theLayerNumber = tecid.wheel(); 
    theCylinderNumber = TrackerInteractionGeometry::TEC+theLayerNumber;
    theRingNumber = tecid.ring();
    forward = true;
  } else if ( theSubDetId ==  PixelSubdetector::PixelBarrel ) { 
    PXBDetId pxbid(theDetId.rawId()); 
    theLayerNumber = pxbid.layer(); 
    theCylinderNumber = TrackerInteractionGeometry::PXB+theLayerNumber;
    forward = false;
  } else if ( theSubDetId ==  PixelSubdetector::PixelEndcap ) { 
    PXFDetId pxfid(theDetId.rawId()); 
    theLayerNumber = pxfid.disk();  
    theCylinderNumber = TrackerInteractionGeometry::PXD+theLayerNumber;
    forward = true;
  }
  
}

bool
TrackerRecHit::isOnRequestedDet(const std::vector<unsigned int>& whichDet) const { 
  
  bool isOnDet = false;
  
  for ( unsigned idet=0; idet<whichDet.size(); ++idet ) {
    
    switch ( whichDet[idet] ) { 
      
    case 1: 
      //Pixel Barrel
      isOnDet =  theSubDetId==1;
      break;
      
    case 2: 
      //Pixel Disks
      isOnDet = theSubDetId==2;
      break;
      
    case 3:
      //Inner Barrel
      isOnDet = theSubDetId==3 && theLayerNumber < 4;
      break;
      
    case 4:
      //Inner Disks
      isOnDet = theSubDetId==4 && theRingNumber < 3;
      break;
      
    case 5:
      //Outer Barrel
      isOnDet = false;
      break;
      
    case 6:
      //Tracker EndCap
      //      isOnDet = theSubDetId==6 && theLayerNumber < 4 && theRingNumber < 3;
      //in third step we use up to layer 3 and ring2 
      //     isOnDet = theSubDetId==6 && theLayerNumber < 4 && theRingNumber < 3;
      //for the pixelless now we use TEC layers 1-5 so I think this should be changed
      isOnDet = theSubDetId==6 && theLayerNumber < 6 && theRingNumber < 3;
      break;
      
    default:
      // Should not happen
      isOnDet = false;
      break;
      
    }
    
    if ( isOnDet ) break;
    
  }
  
  return isOnDet;
}

bool
TrackerRecHit::makesAPairWith(const TrackerRecHit& anotherHit) const { 

  bool isAProperPair = false;

  unsigned int anotherSubDetId = anotherHit.subDetId();
  unsigned int anotherLayerNumber = anotherHit.layerNumber();
  isAProperPair = 
    // First hit on PXB1
    ( ( theSubDetId == 1 && theLayerNumber == 1 ) && (
      ( anotherSubDetId == 1 && anotherLayerNumber == 2) || 
      ( anotherSubDetId == 1 && anotherLayerNumber == 3) || 
      ( anotherSubDetId == 2 && anotherLayerNumber == 1) || 
      ( anotherSubDetId == 2 && anotherLayerNumber == 2) ) ) || 
    // First hit on PXB2
    ( ( theSubDetId == 1 && theLayerNumber == 2 ) && (
      ( anotherSubDetId == 1 && anotherLayerNumber == 3) || 
      ( anotherSubDetId == 2 && anotherLayerNumber == 1) || 
      ( anotherSubDetId == 2 && anotherLayerNumber == 2) ) ) ||
    // First Hit on PXD1
    ( ( theSubDetId == 2 && theLayerNumber == 1 ) && 
      ( anotherSubDetId == 2 && anotherLayerNumber == 2 ) ) ||
    // First Hit on PXD2
    ( ( theSubDetId == 2 && theLayerNumber == 2 ) && ( 
      ( anotherSubDetId == 6 && anotherLayerNumber == 1 ) ||
      ( anotherSubDetId == 6 && anotherLayerNumber == 2 ) ) ) ||
    // First Hit on TEC1
    ( ( theSubDetId == 6 && theLayerNumber == 1 ) && 
      ( anotherSubDetId == 6 && anotherLayerNumber == 2 ) ) ||
    // First Hit on TEC2
    ( ( theSubDetId == 6 && theLayerNumber == 2 ) && 
      ( anotherSubDetId == 6 && anotherLayerNumber == 3 ) ) ||

  //Pixelless Pairs  
   // First Hit on TIB1
    ( ( theSubDetId == 4 && theLayerNumber == 1 ) && 
      ( anotherSubDetId == 4 && anotherLayerNumber == 2 ) ||
      ( anotherSubDetId == 3 && anotherLayerNumber == 1 ) ) ||
    // First Hit on TID1
    ( ( theSubDetId == 3 && theLayerNumber == 1 ) && 
      ( anotherSubDetId == 3 && anotherLayerNumber == 2 ) ) ||
    // First Hit on TID2
    ( ( theSubDetId == 3 && theLayerNumber == 2 ) && 
      ( anotherSubDetId == 3 && anotherLayerNumber == 3 ) ) ||
    // First Hit on TID3
    ( ( theSubDetId == 3 && theLayerNumber == 3 ) && 
      ( anotherSubDetId == 6 && anotherLayerNumber == 1 ) ) ||
    //    // First Hit on TEC1 (already there)
    //    ( ( theSubDetId == 6 && theLayerNumber == 1 ) && 
    //      ( anotherSubDetId == 6 && anotherLayerNumber == 2 ) ) ||
//     // First Hit on TEC2 (already there)
//     ( ( theSubDetId == 6 && theLayerNumber == 2 ) && 
//       ( anotherSubDetId == 6 && anotherLayerNumber == 3 ) ) ||
    // First Hit on TEC3
    ( ( theSubDetId == 6 && theLayerNumber == 3 ) && 
      ( anotherSubDetId == 6 && anotherLayerNumber == 4 ) || 
      ( anotherSubDetId == 6 && anotherLayerNumber == 5 ) ) ||
    // First Hit on TEC4
    ( ( theSubDetId == 6 && theLayerNumber == 4 ) && 
      ( anotherSubDetId == 6 && anotherLayerNumber == 5 ) );

  return isAProperPair;

} 

bool
TrackerRecHit::makesAPairWith3rd(const TrackerRecHit& anotherHit) const { 

  bool isAProperPair = false;

  unsigned int anotherSubDetId = anotherHit.subDetId();
  unsigned int anotherLayerNumber = anotherHit.layerNumber();
  isAProperPair = 
    // First hit on PXB1
    ( ( theSubDetId == 1 && theLayerNumber == 1 ) && (
      ( anotherSubDetId == 1 && anotherLayerNumber == 2) || 
      ( anotherSubDetId == 2 && anotherLayerNumber == 1) ) || 
      // First hit on PXB2
    ( ( theSubDetId == 1 && theLayerNumber == 2 ) && 
      ( anotherSubDetId == 1 && anotherLayerNumber == 3) ) || 
    // First Hit on PXD1
    ( ( theSubDetId == 2 && theLayerNumber == 1 ) && 
      ( anotherSubDetId == 2 && anotherLayerNumber == 2) ) ||
    // First Hit on PXD2
    ( ( theSubDetId == 2 && theLayerNumber == 2 ) &&  
      ( anotherSubDetId == 6 && anotherLayerNumber == 2 ) ) );

 return isAProperPair;

}
      
bool
TrackerRecHit::makesATripletWith(const TrackerRecHit& anotherHit,
				 const TrackerRecHit& yetAnotherHit ) const { 

  bool isAProperTriplet = false;

  unsigned int anotherSubDetId = anotherHit.subDetId();
  unsigned int anotherLayerNumber = anotherHit.layerNumber();
  unsigned int yetAnotherSubDetId = yetAnotherHit.subDetId();
  unsigned int yetAnotherLayerNumber = yetAnotherHit.layerNumber();
  isAProperTriplet = 
    // First hit on PXB1, second on PXB2
    ( ( theSubDetId == 1 && theLayerNumber == 1 ) && 
      ( anotherSubDetId == 1 && anotherLayerNumber == 2) && ( 
      ( yetAnotherSubDetId == 1 && yetAnotherLayerNumber == 3) || 
      ( yetAnotherSubDetId == 2 && yetAnotherLayerNumber == 1) || 
      ( yetAnotherSubDetId == 3 && yetAnotherLayerNumber == 1) ) ) || 
    // First hit on PXB1, second on PXB3 
    ( ( theSubDetId == 1 && theLayerNumber == 1 ) &&
      ( anotherSubDetId == 1 && anotherLayerNumber == 3) && 
      ( yetAnotherSubDetId == 3 && yetAnotherLayerNumber == 1) ) || 
    // First hit on PXB2, second on PXB3 
    ( ( theSubDetId == 1 && theLayerNumber == 2 ) &&
      ( anotherSubDetId == 1 && anotherLayerNumber == 3) && 
      ( yetAnotherSubDetId == 3 && yetAnotherLayerNumber == 1) ) || 
    // First Hit on PXB1, second on PXD1
    ( ( theSubDetId == 1 && theLayerNumber == 1 ) &&
      ( anotherSubDetId == 2 && anotherLayerNumber == 1) && ( 
      ( yetAnotherSubDetId == 2 && yetAnotherLayerNumber == 2) || 
      ( yetAnotherSubDetId == 4 && yetAnotherLayerNumber == 1) || 
      ( yetAnotherSubDetId == 4 && yetAnotherLayerNumber == 2) ) ) || 
    // First Hit on PXD1, second on PXD2
    ( ( theSubDetId == 2 && theLayerNumber == 1 ) && 
      ( anotherSubDetId == 2 && anotherLayerNumber == 2 ) && (
      ( yetAnotherSubDetId == 6 && yetAnotherLayerNumber == 1 ) ||
      ( yetAnotherSubDetId == 6 && yetAnotherLayerNumber == 2 ) ) ) ||
    // First hit on TIB1 (pixel less)
    ( ( theSubDetId == 3 && theLayerNumber == 1 ) && 
      ( anotherSubDetId == 3 && anotherLayerNumber == 2 ) && 
      ( yetAnotherSubDetId == 3 && yetAnotherLayerNumber == 3 ) );
  
  return isAProperTriplet;
  
}




