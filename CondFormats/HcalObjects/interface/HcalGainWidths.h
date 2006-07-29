#ifndef HcalGainWidths_h
#define HcalGainWidths_h

/** 
\class HcalGainWidths
\author Fedor Ratnikov (UMd)
POOL container to store GainWidth values 4xCapId
$Author: ratnikov
$Date: 2006/04/13 22:40:41 $
$Revision: 1.6 $
*/

#include <vector>
#include <algorithm>

#include "CondFormats/HcalObjects/interface/HcalGainWidth.h"
#include "DataFormats/DetId/interface/DetId.h"

// 
class HcalGainWidths {
 public:
  HcalGainWidths();
  ~HcalGainWidths();
  /// get array of values for 4 capIds
  const HcalGainWidth* getValues (DetId fId) const;
  /// get value for given capId = 0..3
  float getValue (DetId fId, int fCapId) const;
  /// get list of all available channels
  std::vector<DetId> getAllChannels () const;
  /// check if data are sorted
  bool sorted () const {return mSorted;}
  /// fill values
  bool addValue (DetId fId, const float fValues [4]);
  /// fill values
  bool addValue (DetId fId, float fValue0, float fValue1, float fValue2, float fValue3);
  /// sort values by channelId  
  void sort ();
  // helper typedefs
  typedef HcalGainWidth Item;
  typedef std::vector <Item> Container;
 private:
  Container mItems;
  bool mSorted;
};

#endif
