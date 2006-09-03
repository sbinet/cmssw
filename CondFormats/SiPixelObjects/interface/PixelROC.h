#ifndef SiPixelObjects_PixelROC_H
#define SiPixelObjects_PixelROC_H

#include <boost/cstdint.hpp>
#include <string>

/** \class PixelROC
 * Represents ReadOut Chip of DetUnit. 
 * Converts pixel coordinates from Local (in ROC) to Global (in DetUnit).
 * The Local coordinates are double column (dcol) and pixel index in dcol.
 * The Global coordinates are row and column in DetUnit.
 */

namespace sipixelobjects {

class PixelROC {
public:

  /// dummy
  PixelROC(){}

  /// ctor with offsets in DU (units of ROC)
  PixelROC( 
      uint32_t du, int idDU, int idLk, 
      int rocInX, int rocInY); 

  /// x position of this ROC in DetUnit (in units of ROCs)
  int x() const { return theRocInX; }

  /// y position of this ROC in DetUnit (in units of ROCs)
  int y() const { return theRocInY; }

  /// id of this ROC in DetUnit (representing pixel module) according 
  /// to PixelDatabase. 
  int idInDetUnit() const { return theIdDU; }

  /// id of this ROC in parent Link.
  int idInLink() const { return theIdLk; }

  /// return the DetUnit to which this ROC belongs to.
  // uint32_t rawId() const { return theDetUnit; }

  bool inside(int dcol, int pxid) const;

  std::string print(int depth = 0) const;

  /// number of rows in ROC
  static int rows() { return theNRows; }
  /// number of columns in ROC 
  static int cols() { return theNCols; }

private:
  uint32_t theDetUnit;
  int theIdDU, theIdLk;
  int theRocInX, theRocInY; // offsets in DU (in units of ROC);
  static int theNRows, theNCols; 
};

}

#endif
