/*
 * CopolTest.cpp
 *
 *  Created on: 21 mei 2016
 *      Author: HBrand
 */

//#define BOOST_TEST_MODULE First Boost Tests
//#include <boost/test/included/unit_test.hpp>
//using namespace boost::unit_test;
#include "include/gtest/gtest.h"
#include "../src/main.h"

/* struct PolymerChain_Tests
{

};

BOOST_FIXTURE_TEST_SUITE(PolymerChain_TestSuite,PolymerChain_Tests);

PolymerChain Initialize_PolymerChain_Unit4()
{
	return PolymerChain(4);
}

BOOST_AUTO_TEST_CASE(CallGetLength_InitializedWithSingleUnit_ReturnsOne)
{
	PolymerChain test=Initialize_PolymerChain_Unit4();
	unsigned int len=test.get_length();
	unsigned int expected=1;
	BOOST_CHECK_EQUAL(expected,len);
}

BOOST_AUTO_TEST_CASE(GetNumberOfunitsDiffers_InitializedWithSingleUnit_ReturnsZero)
{
	PolymerChain test=Initialize_PolymerChain_Unit4();
	unsigned int units=test.get_units_of_type(3);
	unsigned int expected=0;
	BOOST_CHECK_EQUAL(expected,units);
}

BOOST_AUTO_TEST_CASE(GetNumberOfUnitsSame_InitializedWithSingleUnit_ReturnsOne)
{
	PolymerChain test=Initialize_PolymerChain_Unit4();
	unsigned int units=test.get_units_of_type(4);
	unsigned int expected=1;
	BOOST_CHECK_EQUAL(expected,units);
}

BOOST_AUTO_TEST_CASE(GetInitialUnit_InitializedWithSingleUnit_ReturnsInitUnit)
{
	unsigned short initunit=4;
	PolymerChain test=Initialize_PolymerChain_Unit4();
	unsigned int retunit=test.get_initial_unit();
	BOOST_CHECK_EQUAL(initunit,retunit);
}

BOOST_AUTO_TEST_CASE(GetUltimateUnit_InitializedWithSingleUnit_ReturnsInitUnit)
{
	unsigned short initunit=4;
	PolymerChain test=Initialize_PolymerChain_Unit4();
	unsigned int retunit=test.get_ultimate_unit();
	BOOST_CHECK_EQUAL(initunit,retunit);
}

BOOST_AUTO_TEST_CASE(GetPenUltimateUnit_InitializedWithSingleUnit_ReturnsMinusOne)
{
	PolymerChain test=Initialize_PolymerChain_Unit4();
	short retunit=test.get_penultimate_unit();
	short expected=-1;
	BOOST_CHECK_EQUAL(expected,retunit);
}

BOOST_AUTO_TEST_CASE(GetUltimateUnit_InitializedAndAddedUnit_ReturnsAddedUnit)
{
	PolymerChain test=Initialize_PolymerChain_Unit4();
	unsigned short added_unit=2;
	test.add_molecule_unit(added_unit);
	short retunit=test.get_ultimate_unit();
	BOOST_CHECK_EQUAL(added_unit,retunit);
}

BOOST_AUTO_TEST_CASE(GetPenultimateUnit_InitializedAndAddedUnit_ReturnsInitUnit)
{
	unsigned short initunit=4;
	PolymerChain test=Initialize_PolymerChain_Unit4();
	unsigned short added_unit=2;
	test.add_molecule_unit(added_unit);
	short retunit=test.get_penultimate_unit();
	BOOST_CHECK_EQUAL(initunit,retunit);
}

BOOST_AUTO_TEST_CASE(GetUnitThree_Initialized_ReturnsMinusOne)
{
	PolymerChain test=Initialize_PolymerChain_Unit4();
	short retunit=test.get_unit(3);
	short expected=-1;
	BOOST_CHECK_EQUAL(expected,retunit);
}

BOOST_AUTO_TEST_CASE(GetUnitZero_Initialized_ReturnsInitUnit)
{
	unsigned short initunit=4;
	PolymerChain test=Initialize_PolymerChain_Unit4();
	short retunit=test.get_unit(0);
	BOOST_CHECK_EQUAL(initunit,retunit);
}

BOOST_AUTO_TEST_CASE(GetUnitZero_InitializedAndCopyConstruct_ReturnsInitUnit)
{
	unsigned short initunit=4;
	PolymerChain test(Initialize_PolymerChain_Unit4());
	short retunit=test.get_unit(0);
	BOOST_CHECK_EQUAL(initunit,retunit);
}

BOOST_AUTO_TEST_CASE(ExactString_InitializedWithExactString_ReturnsSameString)
{
	string initstring="030512891601";
	PolymerChain test(initstring);
	string retstring=test.exact_string();
	BOOST_CHECK_EQUAL(initstring,retstring);
}


BOOST_AUTO_TEST_SUITE_END(); */

//test_suite* init_unit_test_suite( int /*argc*/, char* /*argv*/[] )
/*{
  return 0;
}*/

TEST(FactorialTest, HandlesZeroInput) {
  EXPECT_EQ(1, 1);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


