// $Id: testOneToOneAssociation.cc,v 1.2 2006/04/21 13:13:56 llista Exp $
#include <cppunit/extensions/HelperMacros.h>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "DataFormats/Common/interface/AssociationMap.h"

class testOneToOneAssociation : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(testOneToOneAssociation);
  CPPUNIT_TEST(checkAll);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp() {}
  void tearDown() {}
  void checkAll(); 
  void dummy();
};

CPPUNIT_TEST_SUITE_REGISTRATION(testOneToOneAssociation);

void testOneToOneAssociation::checkAll() {
  typedef std::vector<int> CKey;
  typedef std::vector<double> CVal;
  typedef edm::AssociationMap<CKey, CVal, edm::OneToOne, unsigned char> Assoc;
  Assoc v;
  CPPUNIT_ASSERT( v.empty() );
  CPPUNIT_ASSERT( v.size() == 0 );
}

// just check that some stuff compiles
void  testOneToOneAssociation::dummy() {
  typedef std::vector<int> CKey;
  typedef std::vector<double> CVal;
  typedef edm::AssociationMap<CKey, CVal, edm::OneToOne, unsigned char> Assoc;
  Assoc v;
  v.insert( edm::Ref<CKey>(), edm::Ref<CVal>() );
  Assoc::const_iterator b = v.begin(), e = v.end();
  Assoc::const_iterator f = v.find( edm::Ref<CKey>() );
  edm::Ref<Assoc> r;
}
