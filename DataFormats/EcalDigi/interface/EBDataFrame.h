#ifndef DIGIECAL_EBDATAFRAME_H
#define DIGIECAL_EBDATAFRAME_H

#include "DataFormats/EcalDetId/interface/EBDetId.h"
#include "DataFormats/EcalDigi/interface/EcalDataFrame.h"
#include <iosfwd>



/** \class EBDataFrame
      
$Id: EBDataFrame.h,v 1.4 2006/07/05 17:38:51 meridian Exp $
*/
class EBDataFrame : public EcalDataFrame 
{
 public:
  typedef EBDetId key_type; ///< For the sorted collection
  typedef EcalDataFrame Base;

  EBDataFrame() {}
  // EBDataFrame(DetId i) :  Base(i) {}
  EBDataFrame(DataFrame const & base) : Base(base) {}
  EBDataFrame(EcalDataFrame const & base) : Base(base) {}
    
  virtual ~EBDataFrame() {}

  key_type id() const { return Base::id(); }

};

std::ostream& operator<<(std::ostream&, const EBDataFrame&);


#endif
