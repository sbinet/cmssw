

#include <memory>
#include <vector>
#include <functional>

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "RecoPixelVertexing/PixelTriplets/interface/OrderedHitTriplets.h"
#include "RecoPixelVertexing/PixelTriplets/src/LayerTriplets.h"

#include "Geometry/Records/interface/TrackerDigiGeometryRecord.h"
#include "Geometry/TrackerGeometryBuilder/interface/TrackerGeometry.h"
#include "Geometry/CommonDetUnit/interface/GlobalTrackingGeometry.h"
#include "Geometry/Records/interface/GlobalTrackingGeometryRecord.h"

#include "Geometry/CommonDetUnit/interface/GeomDet.h"

#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/EventSetup.h"

#include "RecoTracker/TkSeedingLayers/interface/SeedingLayerSets.h"
#include "RecoTracker/TkSeedingLayers/interface/SeedingLayerSetsBuilder.h"
#include "RecoTracker/TkSeedingLayers/interface/SeedingHitSet.h"
#include "RecoTracker/TransientTrackingRecHit/interface/TSiPixelRecHit.h"
#include "RecoTracker/TkTrackingRegions/interface/TrackingRegion.h"
#include "RecoTracker/TkSeedGenerator/interface/SeedCreatorFactory.h"

#include "TrackingTools/TransientTrackingRecHit/interface/TransientTrackingRecHitBuilder.h"
#include "TrackingTools/Records/interface/TransientRecHitRecord.h"

#include "DataFormats/SiPixelDetId/interface/PXBDetId.h"
#include "DataFormats/SiPixelDetId/interface/PXFDetId.h"
#include "DataFormats/SiPixelDetId/interface/PixelBarrelName.h"
#include "DataFormats/SiPixelDetId/interface/PixelEndcapName.h"
#include "DataFormats/TrajectorySeed/interface/TrajectorySeedCollection.h"


///
/// helper class for extracting info
/// from layer bare names
///
class SeedMergerPixelLayer {

 public:
  enum Side{ Minus=1, Plus=2, Undefined, SideError }; // Changed to correspond with PXFDetId ...

  SeedMergerPixelLayer( const std::string& );
  unsigned getLayerNumber( void ) const { return layer_; }
  Side getSide( void ) const { return side_;}
  PixelSubdetector::SubDetector getSubdet( void ) const { return subdet_; }
  std::string getName( void ) const { return name_; }
  bool isContainsDetector( const DetId& ) const;

 private:
  bool isValidName( const std::string& );
  bool isValid_;
  std::string name_;
  PixelSubdetector::SubDetector subdet_;
  unsigned layer_;
  SeedMergerPixelLayer::Side side_;

};



///
/// merge triplets into quadruplets
///
class QuadrupletSeedMerger {

 public:

  QuadrupletSeedMerger( const edm::EventSetup& );
  ~QuadrupletSeedMerger();
  const std::vector<SeedingHitSet> mergeTriplets( const OrderedSeedingHits&, const edm::EventSetup& );
  const TrajectorySeedCollection mergeTriplets( const TrajectorySeedCollection&, const TrackingRegion&, const edm::EventSetup&, const edm::ParameterSet& );
  bool isEqual( const TrackingRecHit*, const TrackingRecHit* ) const;
  std::pair<double,double> calculatePhiEta( SeedingHitSet const& ) const;
  void printHit( const TrackingRecHit* ) const;
  void printHit( const  TransientTrackingRecHit::ConstRecHitPointer& ) const;
  void printNtuplet( const SeedingHitSet& ) const;
  void setLayerListName( std::string );
  void setMergeTriplets( bool );
  void setAddRemainingTriplets( bool );
  void setTTRHBuilderLabel( std::string );

 private:

  bool isValidQuadruplet( const SeedingHitSet&, const std::vector<SeedMergerPixelLayer>& ) const;

  bool isTripletsShareHitsOnLayers( const SeedingHitSet&, const SeedingHitSet&, 
    const std::pair<SeedMergerPixelLayer, SeedMergerPixelLayer>&,
    std::pair<TransientTrackingRecHit::ConstRecHitPointer,TransientTrackingRecHit::ConstRecHitPointer>& ) const;

  bool isMergeableHitsInTriplets( const SeedingHitSet&, const SeedingHitSet&, 
    const std::pair<SeedMergerPixelLayer, SeedMergerPixelLayer>&,
    std::pair<TransientTrackingRecHit::ConstRecHitPointer,TransientTrackingRecHit::ConstRecHitPointer>& ) const;

  bool isGreaterHit( const TransientTrackingRecHit::ConstRecHitPointer&,
		     const TransientTrackingRecHit::ConstRecHitPointer&  );

  ctfseeding::SeedingLayerSets theLayerSets_;
  edm::ESHandle<TrackerGeometry> theTrackerGeometry_;
  edm::ESHandle<TransientTrackingRecHitBuilder> theTTRHBuilder_;
  std::string layerListName_;
  bool isMergeTriplets_;
  bool isAddRemainingTriplets_;
  std::string theTTRHBuilderLabel_;

};
