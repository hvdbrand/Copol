/*
 * CopolTest.cpp
 *
 *  Created on: 21 mei 2016
 *      Author: HBrand
 */

//#define BOOST_TEST_MODULE First Boost Tests
#include <boost/test/included/unit_test.hpp>
using namespace boost::unit_test;
#include "../src/main.h"

struct PolymerChain_Tests
{

};

BOOST_FIXTURE_TEST_SUITE(PolymerChain_TestSuite,PolymerChain_Tests)

void free_test_function()
/* Compare with void free_test_function() */
{
  BOOST_CHECK( true /* test assertion */ );
}

void PolymerChain_CallGetLength_ReturnsOne()
{
	PolymerChain test(4);
	unsigned int len=test.get_length();
	BOOST_CHECK_EQUAL(1,len);
}

void PolymerChain_GetNumberOfunits_ReturnsZero()
{
	PolymerChain test(4);
	unsigned int units=test.get_units_of_type(3);
	BOOST_CHECK_EQUAL(0,units);
}

void PolymerChain_GetNumberOfunits_ReturnsOne()
{
	PolymerChain test(4);
	unsigned int units=test.get_units_of_type(4);
	BOOST_CHECK_EQUAL(1,units);
}

test_suite* init_unit_test_suite( int /*argc*/, char* /*argv*/[] )
{
   framework::master_test_suite().
    add( BOOST_TEST_CASE( &free_test_function ) );
   framework::master_test_suite().
       add( BOOST_TEST_CASE( &PolymerChain_CallGetLength_ReturnsOne ) );
   framework::master_test_suite().
          add( BOOST_TEST_CASE( &PolymerChain_GetNumberOfunits_ReturnsZero ) );
   framework::master_test_suite().
      add( BOOST_TEST_CASE( &PolymerChain_GetNumberOfunits_ReturnsOne ) );
  return 0;
}

BOOST_AUTO_TEST_SUITE_END()

