#include "HIPixelClusterVtxAnalyzer.h"

#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/Event.h"

#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"

#include "Geometry/TrackerGeometryBuilder/interface/TrackerGeometry.h"
#include "Geometry/TrackerGeometryBuilder/interface/PixelGeomDetUnit.h"
#include "Geometry/TrackerTopology/interface/RectangularPixelTopology.h"
#include "Geometry/Records/interface/TrackerDigiGeometryRecord.h"
#include "Geometry/CommonDetUnit/interface/GeomDet.h"

#include "DataFormats/TrackerRecHit2D/interface/SiPixelRecHitCollection.h"

#include "DataFormats/GeometryVector/interface/LocalPoint.h"
#include "DataFormats/GeometryVector/interface/GlobalPoint.h"

#include "DataFormats/SiPixelDetId/interface/PXBDetId.h"

#include "SimDataFormats/Vertex/interface/SimVertexContainer.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

/*****************************************************************************/
HIPixelClusterVtxAnalyzer::HIPixelClusterVtxAnalyzer(const edm::ParameterSet& ps)
  : srcPixels_(ps.getParameter<edm::InputTag>("pixelRecHits")),
    minZ_(ps.getParameter<double>("minZ")),
    maxZ_(ps.getParameter<double>("maxZ")),
    zStep_(ps.getParameter<double>("zStep")),
    maxHists_(ps.getParameter<int>("maxHists")),
    counter(0)

{
  // Constructor

}


/*****************************************************************************/
HIPixelClusterVtxAnalyzer::~HIPixelClusterVtxAnalyzer()
{ 
  // Destructor
}


/*****************************************************************************/
void HIPixelClusterVtxAnalyzer::analyze(const edm::Event& ev, const edm::EventSetup& es)
{

  if(counter > maxHists_) return;
  std::cout << "counter = " << counter << std::endl;
  counter++;

  int evtnum = ev.id().event();
  TH1D *hClusterVtx = fs->make<TH1D>(Form("hClusterVtx_%d",evtnum),"compatibility of pixel cluster length with vertex hypothesis; z [cm]",(int)((maxZ_-minZ_)/zStep_),minZ_,maxZ_);

  // new vertex collection
  std::auto_ptr<reco::VertexCollection> vertices(new reco::VertexCollection);

  // get pixel rechits
  edm::Handle<SiPixelRecHitCollection> hRecHits;
  try {
    ev.getByLabel(srcPixels_,hRecHits);
  } catch (...) {}

  // get tracker geometry
  if (hRecHits.isValid()) {
    edm::ESHandle<TrackerGeometry> trackerHandle;
    es.get<TrackerDigiGeometryRecord>().get(trackerHandle);
    const TrackerGeometry *tgeo = trackerHandle.product();
    const SiPixelRecHitCollection *hits = hRecHits.product();

    // loop over pixel rechits
    std::vector<VertexHit> vhits;
    for(SiPixelRecHitCollection::DataContainer::const_iterator hit = hits->data().begin(), 
          end = hits->data().end(); hit != end; ++hit) {
      if (!hit->isValid())
        continue;
      DetId id(hit->geographicalId());
      if(id.subdetId() != int(PixelSubdetector::PixelBarrel))
        continue;
      const PixelGeomDetUnit *pgdu = static_cast<const PixelGeomDetUnit*>(tgeo->idToDet(id));
      if (1) {
        const RectangularPixelTopology *pixTopo = 
          static_cast<const RectangularPixelTopology*>(&(pgdu->specificTopology()));
	std::vector<SiPixelCluster::Pixel> pixels(hit->cluster()->pixels());
        bool pixelOnEdge = false;
        for(std::vector<SiPixelCluster::Pixel>::const_iterator pixel = pixels.begin(); 
            pixel != pixels.end(); ++pixel) {
          int pixelX = pixel->x;
          int pixelY = pixel->y;
          if(pixTopo->isItEdgePixelInX(pixelX) || pixTopo->isItEdgePixelInY(pixelY)) {
            pixelOnEdge = true;
            break;
          }
        }
        if (pixelOnEdge)
          continue;
      }

      LocalPoint lpos = LocalPoint(hit->localPosition().x(),
				   hit->localPosition().y(),
				   hit->localPosition().z());
      GlobalPoint gpos = pgdu->toGlobal(lpos);
      VertexHit vh;
      vh.z = gpos.z(); 
      vh.r = gpos.perp(); 
      vh.w = hit->cluster()->sizeY();
      vhits.push_back(vh);
    }
    
    // estimate z-position from cluster lengths
    double zest = 0.0;
    int nhits = 0, nhits_max = 0;
    double chi = 0, chi_max = 1e+9;
    for(double z0 = minZ_; z0 <= maxZ_; z0 += zStep_) {
      nhits = getContainedHits(vhits, z0, chi);
      hClusterVtx->Fill(z0,nhits);
      if(nhits == 0) 
	continue;
      if(nhits > nhits_max) { 
	chi_max = 1e+9; 
	nhits_max = nhits; 
      }
      if(nhits >= nhits_max && chi < chi_max) {
	chi_max = chi; 
	zest = z0;   
      }
    } 

    LogTrace("MinBiasTracking")
      << "  [vertex position] estimated = " << zest 
      << " | pixel barrel hits = " << vhits.size();

  }

}

/*****************************************************************************/
int HIPixelClusterVtxAnalyzer::getContainedHits(const std::vector<VertexHit> &hits, double z0, double &chi)
{
  // Calculate number of hits contained in v-shaped window in cluster y-width vs. z-position.
  int n = 0;
  chi   = 0.;

  for(std::vector<VertexHit>::const_iterator hit = hits.begin(); hit!= hits.end(); hit++) {
    double p = 2 * fabs(hit->z - z0)/hit->r + 0.5; // FIXME
    if(TMath::Abs(p - hit->w) <= 1.) { 
      chi += fabs(p - hit->w);
      n++;
    }
  }
  return n;
}
