// $Id: RBCChamberORLogic.cc,v 1.1 2009/01/30 15:42:47 aosorio Exp $
// Include files 


// local
#include "L1Trigger/RPCTechnicalTrigger/src/RBCChamberORLogic.h"

//-----------------------------------------------------------------------------
// Implementation file for class : RBCChamberORLogic
// 
// 2008-10-11 : Andres Osorio
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RBCChamberORLogic::RBCChamberORLogic(  ) {
  
  m_rbname.push_back(std::string("RB1InFw"));
  m_rbname.push_back(std::string("RB1OutFw"));
  m_rbname.push_back(std::string("RB22Fw"));
  m_rbname.push_back(std::string("RB23Fw"));
  m_rbname.push_back(std::string("RB23M"));
  m_rbname.push_back(std::string("RB3Fw"));
  m_rbname.push_back(std::string("RB4Fw"));
  m_rbname.push_back(std::string("RB1InBk"));
  m_rbname.push_back(std::string("RB1OutBk"));
  m_rbname.push_back(std::string("RB22Bk"));
  m_rbname.push_back(std::string("RB23Bk"));
  m_rbname.push_back(std::string("RB3Bk"));
  m_rbname.push_back(std::string("RB4Bk"));
  
  itr2names itr = m_rbname.begin();
  
  while ( itr != m_rbname.end() )
  {
    m_chamber.insert( make_pair( (*itr) , 0 ) );
    ++itr;
  }

  m_maxcb    = 13;
  m_maxlevel = 3; // 1 <= m <= 6
  
}
//=============================================================================
// Destructor
//=============================================================================
RBCChamberORLogic::~RBCChamberORLogic() {
  
  
  

} 

//=============================================================================

void RBCChamberORLogic::process( const RBCInput & _input, std::bitset<2> & _decision ) 
{
  
  std::cout << "RBCChamberORLogic> Working with chambers OR logic ..." << '\n';
  bool status(false);


  for (int k=0; k < 2; ++k ) 
  {
    
    if( _input.needmapping )
      this->createmap( _input.input_sec[k] );
    else
      this->copymap  ( _input.input_sec[k] );
    
    status = this->evaluateLayerOR( "RB1InFw"  , "RB1InBk" );
    m_layersignal[k].set( 0 , status);
    
    status = this->evaluateLayerOR( "RB1OutFw" , "RB1OutBk" );
    m_layersignal[k].set( 1 , status);
    
    status = this->evaluateLayerOR( "RB22Fw"   , "RB22Bk" );
    m_layersignal[k].set( 2 , status);
    
    status = this->evaluateLayerOR( "RB23Fw"   , "RB23Bk" );
    m_layersignal[k].set( 3 , status);
    
    status = this->evaluateLayerOR( "RB3Fw"    , "RB3Bk" );
    m_layersignal[k].set( 4 , status);
    
    status = this->evaluateLayerOR( "RB4Fw"    , "RB4Bk" );
    m_layersignal[k].set( 5 , status);
    
    reset();
    
    //... apply now majority level criteria:
    
    int _majority = int(m_layersignal[k].count());
    
    if ( _majority >= m_maxlevel) _decision[k] = true;
    else _decision[k] = false;
    
  }

  //...all done!
  
}

void RBCChamberORLogic::copymap( const std::bitset<15> & _input ) 
{
  
  m_chamber[m_rbname[0]]  = _input[0];
  m_chamber[m_rbname[1]]  = _input[1];
  m_chamber[m_rbname[2]]  = _input[2];
  m_chamber[m_rbname[3]]  = _input[3];
  m_chamber[m_rbname[4]]  = _input[4];
  m_chamber[m_rbname[5]]  = _input[5];
  m_chamber[m_rbname[6]]  = _input[6];
  m_chamber[m_rbname[7]]  = _input[7];
  m_chamber[m_rbname[8]]  = _input[8];
  m_chamber[m_rbname[9]]  = _input[9];
  m_chamber[m_rbname[10]] = _input[10];
  m_chamber[m_rbname[11]] = _input[11];
  m_chamber[m_rbname[12]] = _input[12];
  
}

void RBCChamberORLogic::createmap( const std::bitset<15> & _input ) 
{
  
  m_chamber[m_rbname[0]]  = _input[3];
  m_chamber[m_rbname[1]]  = _input[4];
  m_chamber[m_rbname[2]]  = _input[5];
  m_chamber[m_rbname[3]]  = _input[8];
  m_chamber[m_rbname[4]]  = _input[7];
  m_chamber[m_rbname[5]]  = _input[11];
  m_chamber[m_rbname[6]]  = _input[12] || _input[14];
  m_chamber[m_rbname[7]]  = _input[0];
  m_chamber[m_rbname[8]]  = _input[1];
  m_chamber[m_rbname[9]]  = _input[2];
  m_chamber[m_rbname[10]] = _input[6];
  m_chamber[m_rbname[11]] = _input[9];
  m_chamber[m_rbname[12]] = _input[10] || _input[13];
  
}

void RBCChamberORLogic::reset() 
{
  
  //... Reset map for next sector analysis
  m_chamber.clear();
  
  itr2names itr = m_rbname.begin();
  
  while ( itr != m_rbname.end() )
  {
    m_chamber.insert( make_pair( (*itr) , 0 ) );
    ++itr;
  }
  
}

bool RBCChamberORLogic::evaluateLayerOR(const char * _chA, const char *_chB )
{
  
  itr2chambers ptr1 = m_chamber.find( std::string(_chA) );
  itr2chambers ptr2 = m_chamber.find( std::string(_chB) );
  
  if ( ptr1 == m_chamber.end() || ptr2 == m_chamber.end() ) {
    //handle error...little the user can do
    std::cout << "RBCChamberORLogic> Cannot find a chamber name" << '\n';
    return 0;
  }
  
  return ( ptr1->second || ptr2->second );
  
}

