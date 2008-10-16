#ifndef RecoMuon_MuonSeedCleaner_H
#define RecoMuon_MuonSeedCleaner_H

/** \class MuonSeedCleaner
 *
 * Algorith to clean duplicate seeds and select a right one 
 *
 * author: Shih-Chuan Kao - UCR
 *
 */

#include <FWCore/ParameterSet/interface/ParameterSet.h>
#include <RecoMuon/MeasurementDet/interface/MuonDetLayerMeasurements.h>
#include <DataFormats/TrajectorySeed/interface/TrajectorySeedCollection.h>

//muon service
#include <RecoMuon/TrackingTools/interface/MuonServiceProxy.h>

#include<vector>

class DetLayer; 
class MuonDetLayerGeometry;
class MagneticField;

typedef std::vector<TrajectorySeed> SeedContainer;

class MuonSeedCleaner
{

 public:

  typedef MuonTransientTrackingRecHit::MuonRecHitContainer SegmentContainer;
  typedef std::deque<bool> BoolContainer;

  /// Constructor
  explicit MuonSeedCleaner(const edm::ParameterSet&);
  
  /// Destructor
  ~MuonSeedCleaner();
  
  // Operations

  /// Cache pointer to geometry
  //void setGeometry( const MuonDetLayerGeometry* lgeom ) {muonLayers = lgeom;}

  /// Cache pointer to Magnetic field
  //void setBField( const MagneticField* theField ) {BField = theField;}

  /// cleaning the seeds 
  std::vector<TrajectorySeed> seedCleaner(const edm::EventSetup& eventSetup, std::vector<TrajectorySeed>& seeds );   

  int NRecHitsFromSegment( const TrackingRecHit& rhit );
  int NRecHitsFromSegment( MuonTransientTrackingRecHit *rhit );
  //int NRecHitsFromSegment( const MuonTransientTrackingRecHit& rhit );

  std::vector<int> badSeedLayer;


 private:


  /// group the seeds 
  std::vector<SeedContainer> GroupSeeds( std::vector<TrajectorySeed>& seeds );

  /// select seed by balance length and chi2
  TrajectorySeed Chi2LengthSelection(std::vector<TrajectorySeed>& seeds );
  /// select the highest momentum pt seed
  TrajectorySeed LeanHighMomentum( std::vector<TrajectorySeed>& seeds ); 
  /// select the seed with bigger projection cone to next layer
  TrajectorySeed BiggerCone( std::vector<TrajectorySeed>& seeds ) ;
  /// select the seed with more rechits
  TrajectorySeed MoreRecHits( std::vector<TrajectorySeed>& seeds );

  /// filter out the bad pt seeds, if all are bad pt seeds then keep all    
  bool MomentumFilter(std::vector<TrajectorySeed>& seeds );
  /// pick the seeds w/ 1st layer information and w/ more than 1 segments 
  SeedContainer SeedCandidates( std::vector<TrajectorySeed>& seeds, bool good );
  /// check overlapping segment for seeds
  unsigned int OverlapSegments( TrajectorySeed seed1, TrajectorySeed seed2 );

  /// retrieve number of rechits& normalized chi2 of associated segments of a seed
  double NChi2OfSegment( const TrackingRecHit& rhit );

  double SeedChi2( TrajectorySeed seed );
  int    SeedLength( TrajectorySeed seed ); 

  /// retrieve seed global position
  GlobalPoint SeedPosition( TrajectorySeed seed );
  /// retrieve seed global momentum 
  GlobalVector SeedMomentum( TrajectorySeed seed );

  // obsoleted functions
  /// pick the seed by better parameter error
  /// collect long seeds
  SeedContainer LengthFilter(std::vector<TrajectorySeed>& seeds );


  // This Producer private debug flag
  bool debug;

  // Number of Segments from a shower
  int NShowerSeg;
  SegmentContainer ShoweringSegments;   
  std::vector<int> ShoweringLayers; 

  // Cache geometry for current event
  //const MuonDetLayerGeometry* muonLayers;

  // Cache Magnetic Field for current event
  const MagneticField* BField;
 
  // muon service
  MuonServiceProxy* theService;

  // Minimum separation when we can distinguish between 2 muon seeds
  // (to suppress combinatorics)

};
#endif

