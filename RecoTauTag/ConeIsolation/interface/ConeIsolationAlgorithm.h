#ifndef ConeIsolationAlgorithm_H
#define ConeIsolationAlgorithm_H
#include "DataFormats/BTauReco/interface/IsolatedTauTagInfo.h"
#include "DataFormats/BTauReco/interface/JetTag.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/JetReco/interface/Jet.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/BTauReco/interface/JetTracksAssociation.h"
//#include "MagneticField/Engine/interface/MagneticField.h"
#include "Geometry/Vector/interface/GlobalVector.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
//Math
#include "Math/GenVector/VectorUtil.h"
#include "Math/GenVector/PxPyPzE4D.h"





class  ConeIsolationAlgorithm  {

 public:
 
  ConeIsolationAlgorithm(const edm::ParameterSet  & parameters );
  ConeIsolationAlgorithm(); 

  // For out of framework usage we may need a different constructor
  // so we keep datamember as builtin types (instead of ParameterSet) 
  //ConeIsolationAlgorithm (int,float,....);
   
  ~ConeIsolationAlgorithm() {}

//  void setBeamSpot();
  void setPrimaryVertex(reco::Vertex * pv) {m_primaryVertex = pv;}
  
  std::pair<reco::JetTag,reco::IsolatedTauTagInfo> tag(const  reco::JetTracksAssociationRef & jetTracks, const reco::Vertex & pv); 
  

 private:
  reco::Vertex * m_primaryVertex;

  //algorithm parameters
  int  m_nthTrack;
  int  m_cutPixelHits;
  int  m_cutTotalHits;
  double  m_cutMaxTIP;
  double  m_cutMinPt;
  double  m_cutMaxDecayLen;
  double  m_cutMaxChiSquared;
  double matching_cone;
  double signal_cone;
  double isolation_cone;
  double pt_min_isolation;
  double pt_min_leadTrack;
  double dZ_vertex;
  int n_tracks_isolation_ring;
  bool useVertexConstrain_;
  bool useFixedSizeIsolationCone;
  double variableConeParameter;
};

#endif 

