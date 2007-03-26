#include "RecoLocalTracker/SiStripRecHitConverter/test/ClusterFilter.h"
#include <iostream>
#include "DataFormats/SiStripCluster/interface/SiStripCluster.h"
#include "DataFormats/Common/interface/DetSetVector.h"
#include "FWCore/Framework/interface/Handle.h"
#include "FWCore/Framework/interface/Event.h"
 using namespace std;
 using namespace edm;
 
ClusterFilter::ClusterFilter( const ParameterSet & pset ) :
  nMax_( pset.getParameter<int>( "maxClusters" ) ),conf_(pset){
  }
 
 ClusterFilter::~ClusterFilter() {
 }
 
 
 bool ClusterFilter::filter( Event &e , EventSetup const& es) {
   std::string clusterProducer = conf_.getParameter<std::string>("ClusterProducer");
   edm::Handle<edm::DetSetVector<SiStripCluster> > clusters;
   e.getByLabel(clusterProducer, clusters);
   int size=clusters.product()->size();
   if(size>nMax_)return 0;
   else return 1;	
}

