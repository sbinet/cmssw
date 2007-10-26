///////////////////////////////////////////////////////////////////////////////
// File: ClusterProducerFP420.cc
// Date: 12.2006
// Description: ClusterProducerFP420 for FP420
// Modifications: 
///////////////////////////////////////////////////////////////////////////////
#include "RecoRomanPot/RecoFP420/interface/ClusterProducerFP420.h"
using namespace std;
//#define mycldebug0
//#define mycldebug1

// sense of zside here is X or Y type planes. Now we are working with X only, i.e. zside=2

bool ClusterProducerFP420::badChannel( int channel, 
				       const std::vector<short>& badChannels) const
{
  const std::vector<short>::size_type linearCutoff = 20;// number of possible bad channels
  // check: is it bad cnannel or not
#ifdef mycldebug0
  std::cout  
    << "badChannel:  badChannels.size()= " << badChannels.size() <<  " \t"
    << "badChannel:  hardcoded linearCutoff= " << linearCutoff  << " \t"
    << "badChannel:  channel= " << channel <<  " \t"
    << std::endl; 
#endif
  if (badChannels.size() < linearCutoff) {
    return (std::find( badChannels.begin(), badChannels.end(), channel) != badChannels.end());
  }
  else return std::binary_search( badChannels.begin(), badChannels.end(), channel);


}


//FIXME
//In the future, with blobs, perhaps we will come back at this version
// std::vector<ClusterFP420>
// ClusterProducerFP420::clusterizeDetUnit( DigiIterator begin, DigiIterator end,
//                                                 unsigned int detid,
//                                                 const std::vector<float>& noiseVec,
//                                                 const std::vector<short>& badChannels)
// {

//                                                                              digiRangeIteratorBegin,digiRangeIteratorEnd
std::vector<ClusterFP420> ClusterProducerFP420::clusterizeDetUnit( HDigiFP420Iter begin, HDigiFP420Iter end,
								   unsigned int detid, const ElectrodNoiseVector& vnoise){
//                                                 const std::vector<short>& badChannels)

  //reminder:	  int zScale=2;  unsigned int detID = sScale*(sector - 1)+zScale*(zmodule - 1)+zside;
  // const int maxBadChannels_ = 1;
  HDigiFP420Iter ibeg, iend, ihigh, itest, i;  
  ibeg = iend = begin;
  std::vector<HDigiFP420> cluster_digis;  
  // reserve 15 possible channels for one cluster
  cluster_digis.reserve(15);
  // reserve one third of digiRange for number of clusters
  std::vector<ClusterFP420> rhits; rhits.reserve( (end - begin)/3 + 1);
  //  predicate(declare): take noise above seed_thr
  AboveSeed predicate(seedThresholdInNoiseSigma(),vnoise);
  //Check if channel is lower than vnoise.size()
  itest = end - 1;
  int vnoisesize = vnoise.size();
  //  if (vnoise.size()<=itest->channel()) // old
  if (vnoisesize<=itest->channel()) 
    {
      std::cout <<  "WARNING for detid " << detid << " there will be a request for noise for channel seed" << itest->channel() << " but this detid has vnoise.size= " <<  vnoise.size() << "\nskip"<< std::endl;
      return rhits;
    }
  //
  //                                   loop in elements above seed_thr
  //                                find seed with seed noise above seed_thr
  while ( ibeg != end && (ihigh = find_if( ibeg, end, predicate)) != end) {
    // The seed electrode is ihigh. Scan up and down from it, finding nearby(sosednie) electrodes above
    // threshold, allowing for some voids. The accepted cluster runs from electrode ibeg
    // to iend, and itest is the electrode under study, not yet accepted.
    
    // go to right side:
    iend = ihigh;
    itest = iend + 1;
    while ( itest != end && (itest->channel() - iend->channel() <= max_voids_ + 1 )) {
      float channelNoise = vnoise[itest->channel()].getNoise();
      bool IsBadChannel = vnoise[itest->channel()].getDisable();
      if (!IsBadChannel && itest->adc() >= static_cast<int>( channelThresholdInNoiseSigma() * channelNoise)) { 
	iend = itest;
      }
      ++itest;
    }
    //if the next digi after iend is an adjacent bad(!) digi then insert into candidate cluster
    itest=iend+1;
    if ( itest != end && (itest->channel() - iend->channel() == 1) && vnoise[itest->channel()].getDisable() ) {    
      std::cout << "Inserted bad electrode at the end edge iend->channel()= " << iend->channel() << " itest->channel() = " << itest->channel() << std::endl;
      iend++;
    }
    // go to left side:
    ibeg = ihigh;
    itest = ibeg - 1;
    while ( itest >= begin && (ibeg->channel() - itest->channel() <= max_voids_ + 1 )) {
      float channelNoise = vnoise[itest->channel()].getNoise();  
      bool IsBadChannel = vnoise[itest->channel()].getDisable();
      if (!IsBadChannel && itest->adc() >= static_cast<int>( channelThresholdInNoiseSigma() * channelNoise)) { 
        ibeg = itest;
      }
      --itest;
    }
    //if the next digi after ibeg is an adiacent bad digi then insert into candidate cluster
    itest=ibeg-1;
    if ( itest >= begin && (ibeg->channel() - itest->channel() == 1) && vnoise[itest->channel()].getDisable() ) {    
      std::cout << "Inserted bad electrode at the begin edge ibeg->channel()= " << ibeg->channel() << " itest->channel() = " << itest->channel() << std::endl;
      ibeg--;
    }
    //============================================================================================================
    int charge = 0;
    float sigmaNoise2=0;
    cluster_digis.clear();
    for (i=ibeg; i<=iend; ++i) {
      float channelNoise = vnoise[i->channel()].getNoise();  
      bool IsBadChannel = vnoise[i->channel()].getDisable();
      //just check for consecutive digis
      if (i!=ibeg && i->channel()-(i-1)->channel()!=1){
	//digits: *(i-1) and *i   are not consecutive(we asked !=1-> it means 2...),so  create an equivalent number of Digis with zero amp
	for (int j=(i-1)->channel()+1;j<i->channel();++j){
	  cluster_digis.push_back(HDigiFP420(j,0)); //if electrode bad or under threshold set HDigiFP420.adc_=0  
	}
      }
      //

// FIXME: should the digi be tested for badChannel before using the adc?

      if (!IsBadChannel && i->adc() >= static_cast<int>( channelThresholdInNoiseSigma()*channelNoise)) {
        charge += i->adc();
        sigmaNoise2 += channelNoise*channelNoise; // 
        cluster_digis.push_back(*i);// put into cluster_digis good i info
      } else {
	cluster_digis.push_back(HDigiFP420(i->channel(),0)); //if electrode bad or under threshold set HDigiFP420.adc_=0
      }
      //
    }//for i++
    float sigmaNoise = sqrt(sigmaNoise2);
    // define here cog,err,zside not used
    float cog;
    float err;
    unsigned int zside=2;// it can be even =1,although we are working with =2(Xtypes of planes)
    if (charge >= static_cast<int>( clusterThresholdInNoiseSigma()*sigmaNoise)) {
      rhits.push_back( ClusterFP420( detid, zside, ClusterFP420::HDigiFP420Range( cluster_digis.begin(),
									   cluster_digis.end()), 
				     cog, err));
#ifdef mycldebug0
      std::cout << "Looking at cog and err  : cog " << cog << " err " << err  << std::endl;
#endif
    }
    ibeg = iend+1;
  } // while ( ibeg
  return rhits;
}

int ClusterProducerFP420::difNarr(unsigned int zside, HDigiFP420Iter ichannel,
				  HDigiFP420Iter jchannel) {
  int d = 9999;
    if(zside == 2) {
      d = ichannel->stripV() - jchannel->stripV();
      d=abs(d);
    }
    else if(zside == 1) {
      d = ichannel->stripH() - jchannel->stripH();
      d=abs(d);
    }
    else{
      std::cout << "difNarr: wrong zside =  " << zside << std::endl;
    }
  return d;
}
int ClusterProducerFP420::difWide(unsigned int zside, HDigiFP420Iter ichannel,
				  HDigiFP420Iter jchannel) {
  int d = 9999;
    if(zside == 2) {
      d = ichannel->stripVW() - jchannel->stripVW();
      d=abs(d);
    }
    else if(zside == 1) {
      d = ichannel->stripHW() - jchannel->stripHW();
      d=abs(d);
    }
    else{
      std::cout << "difWide: wrong zside =  " << zside << std::endl;
    }
  return d;
}
//                                                                              digiRangeIteratorBegin,digiRangeIteratorEnd
std::vector<ClusterFP420> ClusterProducerFP420::clusterizeDetUnitPixels( HDigiFP420Iter begin, HDigiFP420Iter end,
									 unsigned int detid, const ElectrodNoiseVector& vnoise, unsigned int zside){
//                                                 const std::vector<short>& badChannels)

  //reminder:	  int zScale=2;  unsigned int detID = sScale*(sector - 1)+zScale*(zmodule - 1)+zside;

  // const int maxBadChannels_ = 1;
  
  HDigiFP420Iter ibeg, iend, ihigh, itest, i;  
  ibeg = iend = begin;
  std::vector<HDigiFP420> cluster_digis;  
  
  // reserve 15 possible channels for one cluster
  cluster_digis.reserve(15);
  
  // reserve one third of digiRange for number of clusters
  std::vector<ClusterFP420> rhits; rhits.reserve( (end - begin)/3 + 1);
  
  //  predicate(declare): take noise above seed_thr
  AboveSeed predicate(seedThresholdInNoiseSigma(),vnoise);
  
  //Check if channel is lower than vnoise.size()
  itest = end - 1;

  int vnoisesize = vnoise.size();
  //  if (vnoise.size()<=itest->channel()) // old
  if (vnoisesize<=itest->channel()) 
    {
//      std::cout <<  "WARNING for detid " << detid << " there will be a request for noise for channel seed" << itest->channel() << " but this detid has vnoise.size= " <<  vnoise.size() << "\nskip"<< std::endl;
      return rhits;
    }
  //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
  
  //  std::cout << "before while loop..." << std::endl;
  
  //                                   loop in elements above seed_thr
  //                                find seed with seed noise above seed_thr
  while ( ibeg != end && (ihigh = find_if( ibeg, end, predicate)) != end) {
    
    
    // The seed electrode is ihigh. Scan up and down from it, finding nearby(sosednie) electrodes above
    // threshold, allowing for some voids. The accepted cluster runs from electrode ibeg
    // to iend, and itest is the electrode under study, not yet accepted.
    
    // go to right side:
    iend = ihigh;
    itest = iend + 1;
    //    while ( itest != end && (itest->channel() - iend->channel() <= max_voids_ + 1 )) {
    while ( itest != end && (difNarr(zside,itest,iend)<= max_voids_ + 1 ) && (difWide(zside,itest,iend)<= 1 ) ) {
      float channelNoise = vnoise[itest->channel()].getNoise();
      bool IsBadChannel = vnoise[itest->channel()].getDisable();
      if (!IsBadChannel && itest->adc() >= static_cast<int>( channelThresholdInNoiseSigma() * channelNoise)) { 
	iend = itest;
      }
      ++itest;
    }
    //if the next digi after iend is an adjacent bad(!) digi then insert into candidate cluster
    itest=iend+1;
    if ( itest != end && (difNarr(zside,itest,iend) == 1) && vnoise[itest->channel()].getDisable() ) {    
      std::cout << "Inserted bad electrode at the end edge iend->channel()= " << iend->channel() << " itest->channel() = " << itest->channel() << std::endl;
      iend++;
    }
    
    // go to left side:
    ibeg = ihigh;
    itest = ibeg - 1;
    //  while ( itest >= begin && (ibeg->channel() - itest->channel() <= max_voids_ + 1 )) {
    while ( itest >= begin && (difNarr(zside,ibeg,itest) <= max_voids_ + 1 ) && (difWide(zside,ibeg,itest) <= 1 ) ) {
      float channelNoise = vnoise[itest->channel()].getNoise();  
      bool IsBadChannel = vnoise[itest->channel()].getDisable();
      if (!IsBadChannel && itest->adc() >= static_cast<int>( channelThresholdInNoiseSigma() * channelNoise)) { 
        ibeg = itest;
      }
      --itest;
    }
    //if the next digi after ibeg is an adjacent bad digi then insert into candidate cluster
    itest=ibeg-1;
    if ( itest >= begin && (difNarr(zside,ibeg,itest) == 1) && vnoise[itest->channel()].getDisable() ) {    
      std::cout << "Inserted bad electrode at the begin edge ibeg->channel()= " << ibeg->channel() << " itest->channel() = " << itest->channel() << std::endl;
      ibeg--;
    }
    //============================================================================================================
    
    
    
    
    
    //============================================================================================================
    int charge = 0;
    float sigmaNoise2=0;
    cluster_digis.clear();
    //    HDigiFP420Iter ilast=ibeg; // AZ
    for (i=ibeg; i<=iend; ++i) {
      float channelNoise = vnoise[i->channel()].getNoise();  
      bool IsBadChannel = vnoise[i->channel()].getDisable();
#ifdef mycldebug1
      std::cout << "Looking at cluster digis: detid " << detid << " digis " << i->channel()  
		<< " adc " << i->adc() << " channelNoise " << channelNoise << " IsBadChannel  " << IsBadChannel << std::endl;
#endif
      
      //just check for consecutive digis
      // if (i!=ibeg && i->channel()-(i-1)->channel()!=1){
      //if (i!=ibeg && difNarr(zside,i,i-1) !=1 && difWide(zside,i,i-1) !=1){
      if (i!=ibeg && (difNarr(zside,i,i-1) > 1 || difWide(zside,i,i-1) > 1)   ){
	//digits: *(i-1) and *i   are not consecutive(we asked !=1-> it means 2...),so  create an equivalent number of Digis with zero amp
	for (int j=(i-1)->channel()+1;j<i->channel();++j){
	  cluster_digis.push_back(HDigiFP420(j,0)); //if not consecutive digis set HDigiFP420.adc_=0  
	}
      }
      //
      if (!IsBadChannel && i->adc() >= static_cast<int>( channelThresholdInNoiseSigma()*channelNoise)) {
        charge += i->adc();
        sigmaNoise2 += channelNoise*channelNoise; // 
        cluster_digis.push_back(*i);// put into cluster_digis good i info
      } else {
	cluster_digis.push_back(HDigiFP420(i->channel(),0)); //if electrode bad or under threshold set HDigiFP420.adc_=0
      }
      //
    }//for i++
    
    
    
    
    float sigmaNoise = sqrt(sigmaNoise2);
    float cog;
    float err;
    if (charge >= static_cast<int>( clusterThresholdInNoiseSigma()*sigmaNoise)) {
      rhits.push_back( ClusterFP420( detid, zside, ClusterFP420::HDigiFP420Range( cluster_digis.begin(),
									   cluster_digis.end()), 
				     cog, err));
#ifdef mycldebug1
      std::cout << "Looking at cog and err  : cog " << cog << " err " << err  << std::endl;
#endif
    }
    
    
    ibeg = iend+1;
  } // while ( ibeg
  
  
  return rhits;
  
}



