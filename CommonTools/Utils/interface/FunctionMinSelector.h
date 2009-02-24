#ifndef CommonTools_Utils_FunctionMinSelector_h
#define CommonTools_Utils_FunctionMinSelector_h
/* \class FunctionMinSelector
 *
 * \author Luca Lista, INFN
 *
 * $Id: FunctionMinSelector.h,v 1.1 2007/08/03 09:38:38 llista Exp $
 */

template<typename F>
struct FunctionMinSelector {
  explicit FunctionMinSelector( double minCut ) :
    minCut_( minCut ) { }
  bool operator()( const typename F::type & t ) const {
    return f( t ) >= minCut_;
  }
private:
  F f;
  double minCut_;
};

#endif
