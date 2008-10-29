/**\class CSCCorrelatedLCTDigi
 *
 * Digi for Correlated LCT trigger primitives.
 *
 * $Date: 2007/09/24 10:14:48 $
 * $Revision: 1.11 $
 *
 * \author L.Gray, UF
 */

#include "DataFormats/CSCDigi/interface/CSCCorrelatedLCTDigi.h"
#include <iostream>

/// Constructors
CSCCorrelatedLCTDigi::CSCCorrelatedLCTDigi(const int itrknmb, const int ivalid,
					   const int iquality,
					   const int ikeywire,
					   const int istrip,
					   const int ipattern, const int ibend,
					   const int ibx, const int& impclink, 
					   const uint16_t& ibx0,  const uint16_t& isyncErr, 
					   const uint16_t& icscID):
  trknmb(itrknmb),
  valid(ivalid),
  quality(iquality),
  keywire(ikeywire),
  strip(istrip),
  pattern(ipattern),
  bend(ibend),
  bx(ibx),
  mpclink(impclink),
  bx0(ibx0),
  syncErr(isyncErr),
  cscID(icscID)
{}

/// Default
CSCCorrelatedLCTDigi::CSCCorrelatedLCTDigi() {
  clear(); // set contents to zero
}

/// Clears this LCT.
void CSCCorrelatedLCTDigi::clear() {
  trknmb  = 0;
  valid   = 0;
  quality = 0;
  keywire = 0;
  strip   = 0;
  pattern = 0;
  bend    = 0;
  bx      = 0;
  mpclink = 0;
}

/// Comparison
bool CSCCorrelatedLCTDigi::operator==(const CSCCorrelatedLCTDigi &rhs) const {
  return ((trknmb == rhs.trknmb)   && (quality == rhs.quality) &&
	  (keywire == rhs.keywire) && (strip == rhs.strip)     &&
	  (pattern == rhs.pattern) && (bend == rhs.bend)       &&
	  (bx == rhs.bx)           && (valid == rhs.valid) && (mpclink == rhs.mpclink) );
}

/// Debug
void CSCCorrelatedLCTDigi::print() const {
  if (isValid()) {
    std::cout << "CSC LCT #"        << getTrknmb() 
	      << ": Valid = "       << isValid()
	      << " Quality = "      << getQuality()
	      << " Key Wire = "     << getKeyWG()
	      << " Strip = "        << getStrip()
	      << " CLCT Pattern = " << getCLCTPattern()
	      << " Strip Type = "   << ( (getStripType() == 0) ? 'D' : 'H' )
	      << " Bend = "         << ( (getBend() == 0) ? 'L' : 'R' )
	      << " BX = "           << getBX() 
	      << " MPC Link = "     << getMPCLink() << std::endl;
  }
  else {
    std::cout << "Not a valid correlated LCT." << std::endl;
  }
}

std::ostream & operator<<(std::ostream & o,
                                 const CSCCorrelatedLCTDigi& digi) {
  return o << "CSC LCT #"   << digi.getTrknmb()
           << ": Valid = "  << digi.isValid()
           << " Quality = " << digi.getQuality()
           << " MPC Link = " << digi.getMPCLink() << "\n"
           <<"  cathode info: Strip = "    << digi.getStrip()
           <<" ("           << ((digi.getStripType() == 0) ? 'D' : 'H') << ")"
           << " Bend = "    << ((digi.getBend() == 0) ? 'L' : 'R')
           << " Pattern = " << digi.getCLCTPattern() << "\n"
           <<"    anode info: Key wire = " << digi.getKeyWG()
           << " BX = "      << digi.getBX()
           << " bx0= "      << digi.getBX0()
           << " syncErr = " << digi.getSyncErr()
           << " cscID= "    << digi.getCSCID() << "\n";
}

