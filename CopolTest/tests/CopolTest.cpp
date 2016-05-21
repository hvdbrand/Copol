/*
 * CopolTest.cpp
 *
 *  Created on: 21 mei 2016
 *      Author: HBrand
 */

#define First Boost Tests
#include <boost/test/included/unit_test.hpp>
using namespace boost::unit_test;
#include "../src/main.h"

void free_test_function()
/* Compare with void free_test_function() */
{
  BOOST_TEST( true /* test assertion */ );
}

void PolymerChain_CallGetLength_ReturnsOne()
{
	PolymerChain test(4);
	unsigned int len=test.get_length();
	BOOST_CHECK_EQUAL(1,len);
}

test_suite* init_unit_test_suite( int /*argc*/, char* /*argv*/[] )
{
   framework::master_test_suite().
    add( BOOST_TEST_CASE( &free_test_function ) );
   framework::master_test_suite().
       add( BOOST_TEST_CASE( &PolymerChain_CallGetLength_ReturnsOne ) );

  return 0;
}


