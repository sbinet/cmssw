#include "L1TriggerConfig/CSCTFConfigProducers/interface/CSCTFObjectKeysOnlineProd.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

void
CSCTFObjectKeysOnlineProd::fillObjectKeys( ReturnType pL1TriggerKey )
{
     std::string csctfKey = pL1TriggerKey->subsystemKey( L1TriggerKey::kCSCTF ) ;

     // Execute SQL queries to get data from OMDS (using key) and make C++ object.

     if( !csctfKey.empty() )
     {
	  l1t::OMDSReader::QueryResults objectKeyResults =
	       m_omdsReader.basicQuery(
		    "SP1_KEY",
		    "CMS_CSC_TF",
		    "CSCTF_CONF",
		    "CSCTF_CONF.CSCTF_KEY",
		    m_omdsReader.singleAttribute( csctfKey  ) );

	  if( objectKeyResults.queryFailed() || objectKeyResults.numberRows() != 1 ) // check if query was successful
	  {
	       edm::LogError( "L1-O2O" ) << "Problem with CSCTF  key." ;
	       return ;
	  }

	  long long int objectKey ;
	  objectKeyResults.fillVariable( objectKey ) ;
	  std::stringstream ss;
	  ss<<objectKey;
	  std::string strKey=ss.str();


	  pL1TriggerKey->add( "L1MuCSCTFConfigurationRcd", "L1MuCSCTFConfiguration", strKey ) ;
     }
}

