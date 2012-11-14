#ifndef CALO_TOPOLOGY_HCAL_TOPOLOGY_MODE_H
# define CALO_TOPOLOGY_HCAL_TOPOLOGY_MODE_H

#include "FWCore/Utilities/interface/Exception.h"
#include <map>
#include <string>
#include <algorithm>

using namespace std;

template< typename T >
class StringToEnumParser
{
    map< string, T > enumMap;
public:
    
    StringToEnumParser( void );

    T parseString( const string &value )
	{ 
	    typename map<string, T>::const_iterator iValue = enumMap.find( value );
	    if( iValue  == enumMap.end())
                throw cms::Exception( "Configuration" )
		    << "the value " << value << " is not defined.";
	    
	    return iValue->second;
	}
};

namespace HcalTopologyMode {
    enum Mode {
	LHC=0, H2=1, SLHC=2, H2HE=3 };
}


#endif // CALO_TOPOLOGY_HCAL_TOPOLOGY_MODE_H
