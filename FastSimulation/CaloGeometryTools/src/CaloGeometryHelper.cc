#include "FastSimulation/CaloGeometryTools/interface/CaloGeometryHelper.h"

// needed for the debugging
#include "Geometry/CaloGeometry/interface/CaloCellGeometry.h"
#include "Geometry/EcalBarrelAlgo/interface/EcalBarrelGeometry.h"
#include "Geometry/EcalEndcapAlgo/interface/EcalEndcapGeometry.h"
#include "Geometry/CaloTopology/interface/CaloTopology.h"
#include "Geometry/CaloTopology/interface/CaloSubdetectorTopology.h"

#include "DataFormats/EcalDetId/interface/EBDetId.h"
#include "DataFormats/EcalDetId/interface/EEDetId.h"
#include "DataFormats/HcalDetId/interface/HcalDetId.h"
#include "DataFormats/EcalDetId/interface/EcalSubdetector.h"

#include "FastSimulation/CaloGeometryTools/interface/DistanceToCell.h"
#include "FastSimulation/CaloGeometryTools/interface/Crystal.h"
#include "FastSimulation/ParticlePropagator/interface/MagneticFieldMap.h"
#include "FastSimulation/Calorimetry/interface/FamosDebug.h"

#include "FWCore/MessageLogger/interface/MessageLogger.h"

CaloGeometryHelper::CaloGeometryHelper():Calorimeter()
{
  neighbourmapcalculated_= false;
  psLayer1Z_ = 303;
  psLayer2Z_ = 307;
}

CaloGeometryHelper::CaloGeometryHelper(const edm::ParameterSet& fastCalo):Calorimeter(fastCalo)
{
  psLayer1Z_ = 303;
  psLayer2Z_ = 307;
}

void CaloGeometryHelper::initialize()
{
  buildNeighbourArray();
  bfield_ = MagneticFieldMap::instance()->inTesla(GlobalPoint(0.,0.,0.)).z();
}

CaloGeometryHelper::~CaloGeometryHelper()
{;
}

DetId CaloGeometryHelper::getClosestCell(const HepPoint3D& point, bool ecal, bool central) const
{
  DetId result;
  if(ecal)
    {
      if(central)
	{
	  //	  std::cout << "EcalBarrelGeometry_" << " " << EcalBarrelGeometry_ << std::endl;
	  result = EcalBarrelGeometry_->getClosestCell(GlobalPoint(point.x(),point.y(),point.z()));
#ifdef DEBUGGCC
	  if(result.null()) return result;
	  GlobalPoint ip=GlobalPoint(point.x(),point.y(),point.z());
	  GlobalPoint cc=EcalBarrelGeometry_->getGeometry(result)->getPosition();
	  float deltaeta2 = ip.eta()-cc.eta();
	  deltaeta2 *= deltaeta2;
	  float deltaphi2 = acos(cos(ip.phi()-cc.phi()));
	  deltaphi2 *= deltaphi2;
	  Histos::instance()->fill("h100",point.eta(),sqrt(deltaeta2+deltaphi2));
#endif
	}
      else
	{
	  result = EcalEndcapGeometry_->getClosestCell(GlobalPoint(point.x(),point.y(),point.z()));
#ifdef DEBUGGCC
	  if(result.null()) 
	    {
	      return result;
	    }
	  GlobalPoint ip=GlobalPoint(point.x(),point.y(),point.z());
	  GlobalPoint cc=EcalEndcapGeometry_->getGeometry(result)->getPosition();
	  Histos::instance()->fill("h110",point.eta(),(ip-cc).perp());
#endif
	}
    }
  else
    {
      result=HcalGeometry_->getClosestCell(GlobalPoint(point.x(),point.y(),point.z()));
#ifdef DEBUGGCC
      if(result.null()) 
	{
	  return result;
	}
      GlobalPoint ip=GlobalPoint(point.x(),point.y(),point.z());
      GlobalPoint cc=HcalGeometry_->getGeometry(result)->getPosition();
      float deltaeta2 = ip.eta()-cc.eta();
      deltaeta2 *= deltaeta2;
      float deltaphi2 = acos(cos(ip.phi()-cc.phi()));
      deltaphi2 *= deltaphi2;

      Histos::instance()->fill("h120",point.eta(),sqrt(deltaeta2+deltaphi2));
#endif
      
    }
  return result;
}

void CaloGeometryHelper::getWindow(const DetId& pivot,int s1,int s2,std::vector<DetId>& vec) const
{
  // currently the getWindow method is the same for EcalBarrelTopology and EndcapTopology
  // (implemented in CaloSubDetectorTopology)
  // optimized versions are foreseen 

  vec=getEcalTopology(pivot.subdetId())->getWindow(pivot,s1,s2);
  DistanceToCell distance(getEcalGeometry(pivot.subdetId()),pivot);
  sort(vec.begin(),vec.end(),distance);
}

void CaloGeometryHelper::buildCrystal(const DetId & cell,Crystal& xtal) const
{
  xtal = Crystal(cell);
  const CaloCellGeometry * geom;
  if(xtal.getSubdetNumber()==EcalBarrel)
    {
      geom = EcalBarrelGeometry_->getGeometry(xtal.getDetId());
      xtal.setCorners(geom->getCorners(),geom->getPosition());
      return;
    }
 if(xtal.getSubdetNumber()==EcalEndcap)
    {
      geom = EcalEndcapGeometry_->getGeometry(xtal.getDetId());
      xtal.setCorners(geom->getCorners(),geom->getPosition());
      return;
    }     
}

// Build the array of (max)8 neighbors
void CaloGeometryHelper::buildNeighbourArray()
{

  static const CaloDirection orderedDir[8]={SOUTHWEST,SOUTH,SOUTHEAST,WEST,EAST,NORTHWEST,NORTH,
					    NORTHEAST};

  const unsigned nbarrel = 62000;
  // Barrel first. The hashed index runs from 0 to 61199
  barrelNeighbours_.resize(nbarrel);
  
  std::cout << " Building the array of neighbours (barrel) " ;

  std::vector<DetId> vec(EcalBarrelGeometry_->getValidDetIds(DetId::Ecal,EcalBarrel));
  unsigned size=vec.size();    
  for(unsigned ic=0; ic<size; ++ic) 
    {
      // We get the 9 cells in a square. 
      std::vector<DetId> neighbours(EcalBarrelTopology_->getWindow(vec[ic],3,3));
      //      std::cout << " Cell " << EBDetId(vec[ic]) << std::endl;
      unsigned nneighbours=neighbours.size();

      unsigned hashedindex=EBDetId(vec[ic]).hashedIndex();
      if(hashedindex>=nbarrel)
	{
	  LogDebug("CaloCaloGeometryTools")  << " Array overflow " << std::endl;
	}


      // If there are 9 cells, it is easy, and this order is know:
//      6  7  8
//      3  4  5 
//      0  1  2   (0 = SOUTHWEST)

      if(nneighbours==9)
	{
	  barrelNeighbours_[hashedindex].reserve(8);
	  for(unsigned in=0;in<nneighbours;++in)
	    {
	      // remove the centre
	      if(neighbours[in]!=vec[ic]) 
		{
		  barrelNeighbours_[hashedindex].push_back(neighbours[in]);
		  //	      std::cout << " Neighbour " << in << " " << EBDetId(neighbours[in]) << std::endl;
		}
	    }
	}
      else
	{
	  DetId central(vec[ic]);
	  barrelNeighbours_[hashedindex].resize(8,DetId(0));
	  for(unsigned idir=0;idir<8;++idir)
	    {
	      DetId testid=central;
	      bool status=move(testid,orderedDir[idir],false);
	      if(status) barrelNeighbours_[hashedindex][idir]=testid;
	    }

	}
    }

  // Moved to the endcap

  std::cout << " done " << size << std::endl;
  std::cout << " Building the array of neighbours (endcap) " ;

  vec.clear();
  vec=EcalEndcapGeometry_->getValidDetIds(DetId::Ecal,EcalEndcap);
  size=vec.size();    
  // There are some holes in the hashedIndex for the EE. Hence the array is bigger than the number
  // of crystals
  const unsigned nendcap=19960;

  endcapNeighbours_.resize(nendcap);
  for(unsigned ic=0; ic<size; ++ic) 
    {
      // We get the 9 cells in a square. 
      std::vector<DetId> neighbours(EcalEndcapTopology_->getWindow(vec[ic],3,3));
      unsigned nneighbours=neighbours.size();
      // remove the centre
      unsigned hashedindex=EEDetId(vec[ic]).hashedIndex();
      
      if(hashedindex>=nendcap)
	{
	  LogDebug("CaloCaloGeometryTools")  << " Array overflow " << std::endl;
	}

      if(nneighbours==9)
	{
	  endcapNeighbours_[hashedindex].reserve(8);
	  for(unsigned in=0;in<nneighbours;++in)
	    {	  
	      // remove the centre
	      if(neighbours[in]!=vec[ic]) 
		{
		  endcapNeighbours_[hashedindex].push_back(neighbours[in]);
		}
	    }
	}
      else
	{
	  DetId central(vec[ic]);
	  endcapNeighbours_[hashedindex].resize(8,DetId(0));
	  for(unsigned idir=0;idir<8;++idir)
	    {
	      DetId testid=central;
	      bool status=move(testid,orderedDir[idir],false);
	      if(status) endcapNeighbours_[hashedindex][idir]=testid;
	    }

	}
    }
  std::cout << " done " << size <<std::endl;
  neighbourmapcalculated_ = true;
}

const std::vector<DetId>& CaloGeometryHelper::getNeighbours(const DetId& detid) const
{
  return (detid.subdetId()==EcalBarrel)?barrelNeighbours_[EBDetId(detid).hashedIndex()]:
    endcapNeighbours_[EEDetId(detid).hashedIndex()];
}

bool CaloGeometryHelper::move(DetId& cell, const CaloDirection&dir,bool fast) const
{  
  DetId originalcell = cell; 
  if(dir==NONE || cell==DetId(0)) return false;

  // Conversion CaloDirection and index in the table
  // CaloDirection :NONE,SOUTH,SOUTHEAST,SOUTHWEST,EAST,WEST, NORTHEAST,NORTHWEST,NORTH
  // Table : SOUTHWEST,SOUTH,SOUTHEAST,WEST,EAST,NORTHWEST,NORTH, NORTHEAST
  static const int calodirections[9]={-1,1,2,0,4,3,7,5,6};
    
  if(fast&&neighbourmapcalculated_)
    {
      DetId result = (originalcell.subdetId()==EcalBarrel) ? 
	barrelNeighbours_[EBDetId(originalcell).hashedIndex()][calodirections[dir]]:
	endcapNeighbours_[EEDetId(originalcell).hashedIndex()][calodirections[dir]];
      bool status =  !result.null();
      cell = result;
      return status; 
    }
  
  if(dir==NORTH || dir ==SOUTH || dir==EAST || dir==WEST)
    {
      return simplemove(cell,dir);
    }
  else
    {
      if(dir == NORTHEAST || dir==NORTHWEST || dir==SOUTHEAST || dir==SOUTHWEST)
	return diagonalmove(cell,dir);
    }
  
  cell = DetId(0);
  return false;
}


bool CaloGeometryHelper::simplemove(DetId& cell, const CaloDirection& dir) const
{
  std::vector<DetId> neighbours;
  if(cell.subdetId()==EcalBarrel)
    neighbours = EcalBarrelTopology_->getNeighbours(cell,dir);
  else if(cell.subdetId()==EcalEndcap)
    neighbours= EcalEndcapTopology_->getNeighbours(cell,dir);
  
  if(neighbours.size()>0 && !neighbours[0].null())
    {
      cell = neighbours[0];
      return true;
    }
  else 
    {
      cell = DetId(0);
      return false;
    }
}

bool CaloGeometryHelper::diagonalmove(DetId& cell, const CaloDirection& dir) const
{
  bool result; 
  // One has to try both paths
  if(dir==NORTHEAST)
    {
      result = simplemove(cell,NORTH);
      if(result)
	return simplemove(cell,EAST);
      else
	{
	  result = simplemove(cell,EAST);
	  if(result)
	    return simplemove(cell,NORTH);
	  else
	    return false; 
	}
    }
  else if(dir==NORTHWEST)
    {
      result = simplemove(cell,NORTH);
      if(result)
	return simplemove(cell,WEST);
      else
	{
	  result = simplemove(cell,WEST);
	  if(result)
	    return simplemove(cell,NORTH);
	  else
	    return false; 
	}
    }
  else if(dir == SOUTHEAST)
    {
      result = simplemove(cell,SOUTH);
      if(result)
	return simplemove(cell,EAST);
      else
	{
	  result = simplemove(cell,EAST);
	  if(result)
	    return simplemove(cell,SOUTH);
	  else
	    return false; 
	}
    }
  else if(dir == SOUTHWEST)
    {
      result = simplemove(cell,SOUTH);
      if(result)
	return simplemove(cell,WEST);
      else
	{
	  result = simplemove(cell,SOUTH);
	  if(result)
	    return simplemove(cell,WEST);
	  else
	    return false; 
	}
    }
  cell = DetId(0);
  return false;
}
