#ifndef CalibFormats_SiStripObjects_NumberOfDevices_H
#define CalibFormats_SiStripObjects_NumberOfDevices_H

#include <boost/cstdint.hpp>
#include <ostream>
#include <sstream>

/** 
    @class NumberOfDevices
    @author R.Bainbridge
    @brief Simple container class for counting devices.
*/
class NumberOfDevices {
  
 public:
  
  NumberOfDevices() { clear(); }
  
  void clear();
  void print( std::stringstream& ) const;
  
 public: // ----- Public member data -----
  
  uint32_t nFecCrates_, nFecSlots_, nFecRings_;      // FECs and rings
  uint32_t nCcuAddrs_, nCcuChans_, nApvs_, nDcuIds_; // CCUs and modules
  uint32_t nDetIds_, nApvPairs_;                     // Geometry
  uint32_t nFedIds_, nFedChans_;                     // FED
  uint32_t nDcus_, nMuxes_, nPlls_, nLlds_;          // Ancilliary devices

}; 

/** Debug info for FedChannelConnection class. */
std::ostream& operator<< ( std::ostream&, const NumberOfDevices& );

#endif // CalibTracker_SiStripObjects_NumberOfDevices_H
