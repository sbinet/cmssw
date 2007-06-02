#ifndef DATAFORMATS_DETID_H
#define DATAFORMATS_DETID_H

#include <boost/cstdint.hpp>
// #include <ostream>

/** \class DetId

Parent class for all detector ids in CMS.  The DetId is a 32-bit
unsigned integer.  The four most significant bits ([31:28]) identify
the large-scale detector (e.g. Tracker or Ecal) while the next three
bits ([27:25]) identify a part of the detector (such as HcalBarrel
(HB) for Hcal).

$Date: 2006/10/13 19:38:48 $
$Revision: 1.5 $
*/
class DetId {
public:
  static const int kDetOffset          = 28;
  static const int kSubdetOffset       = 25;


  enum Detector { Tracker=1,Muon=2,Ecal=3,Hcal=4,Calo=5 };
  /// Create an empty or null id (also for persistence)
  DetId()  : id_(0) { }
  /// Create an id from a raw number
  DetId(uint32_t id) : id_(id) { }
  /// Create an id, filling the detector and subdetector fields as specified
  DetId(Detector det, int subdet)  {
    id_=((det&0xF)<<28)|((subdet&0x7)<<25);
  }

  /// get the detector field from this detid
  Detector det() const { return Detector((id_>>kDetOffset)&0xF); }
  /// get the contents of the subdetector field (not cast into any detector's numbering enum)
  int subdetId() const { return ((id_>>kSubdetOffset)&0x7); }

  uint32_t operator()() const { return id_; }
  operator uint32_t() const { return id_; }

  /// get the raw id 
  uint32_t rawId() const { return id_; }
  /// is this a null id ?
  bool null() const { return id_==0; }
  
  /// equality
  bool operator==(DetId id) const { return id_==id.id_; }
  /// inequality
  bool operator!=(DetId id) const { return id_!=id.id_; }
  /// comparison
  bool operator<(DetId id) const { return id_<id.id_; }

protected:
  uint32_t id_;
};

/// equality
bool operator==(uint32_t i, DetId id) const { return i==id.id_; }
bool operator==(DetId id, uint32_t i) const { return i==id.id_; }
/// inequality
bool operator!=(uint32_t i, DetId id) const { return i!=id.id_; }
bool operator!=(DetId id, uint32_t i) const { return i!=id.id_; }
/// comparison
bool operator<(uint32_t i, DetId id) const { return i<id.id_; }
bool operator<(DetId id, uint32_t i) const { return id.id_<i; }


//std::ostream& operator<<(std::ostream& s, const DetId& id);

#endif
