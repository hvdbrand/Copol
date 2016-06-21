/*
 * CopolTest.cpp
 *
 *  Created on: 21 mei 2016
 *      Author: HBrand
 */

#include "gtest/gtest.h"
#include "../src/main.h"

namespace  PolymerChain_Tests {

PolymerChain Initialize_PolymerChain_Unit4()
{
	return PolymerChain(4);
}

TEST(PolymerChain_Tests,CallGetLength_InitializedWithSingleUnit_ReturnsOne)
{
	PolymerChain test=Initialize_PolymerChain_Unit4();
	unsigned int len=test.get_length();
	unsigned int expected=1;
	ASSERT_EQ(expected,len);
}

TEST(PolymerChain_Tests,GetNumberOfunitsDiffers_InitializedWithSingleUnit_ReturnsZero)
{
	PolymerChain test=Initialize_PolymerChain_Unit4();
	unsigned int units=test.get_units_of_type(3);
	unsigned int expected=0;
	ASSERT_EQ(expected,units);
}

TEST(PolymerChain_Tests,GetNumberOfUnitsSame_InitializedWithSingleUnit_ReturnsOne)
{
	PolymerChain test=Initialize_PolymerChain_Unit4();
	unsigned int units=test.get_units_of_type(4);
	unsigned int expected=1;
	ASSERT_EQ(expected,units);
}

TEST(PolymerChain_Tests,GetInitialUnit_InitializedWithSingleUnit_ReturnsInitUnit)
{
	unsigned short initunit=4;
	PolymerChain test=Initialize_PolymerChain_Unit4();
	unsigned int retunit=test.get_initial_unit();
	ASSERT_EQ(initunit,retunit);
}

TEST(PolymerChain_Tests,GetUltimateUnit_InitializedWithSingleUnit_ReturnsInitUnit)
{
	unsigned short initunit=4;
	PolymerChain test=Initialize_PolymerChain_Unit4();
	unsigned int retunit=test.get_ultimate_unit();
	ASSERT_EQ(initunit,retunit);
}

TEST(PolymerChain_Tests,GetPenUltimateUnit_InitializedWithSingleUnit_ReturnsMinusOne)
{
	PolymerChain test=Initialize_PolymerChain_Unit4();
	short retunit=test.get_penultimate_unit();
	short expected=-1;
	ASSERT_EQ(expected,retunit);
}

TEST(PolymerChain_Tests,GetUltimateUnit_InitializedAndAddedUnit_ReturnsAddedUnit)
{
	PolymerChain test=Initialize_PolymerChain_Unit4();
	unsigned short added_unit=2;
	test.add_molecule_unit(added_unit);
	short retunit=test.get_ultimate_unit();
	ASSERT_EQ(added_unit,retunit);
}

TEST(PolymerChain_Tests,GetPenultimateUnit_InitializedAndAddedUnit_ReturnsInitUnit)
{
	unsigned short initunit=4;
	PolymerChain test=Initialize_PolymerChain_Unit4();
	unsigned short added_unit=2;
	test.add_molecule_unit(added_unit);
	short retunit=test.get_penultimate_unit();
	ASSERT_EQ(initunit,retunit);
}

TEST(PolymerChain_Tests,GetUnitThree_Initialized_ReturnsMinusOne)
{
	PolymerChain test=Initialize_PolymerChain_Unit4();
	short retunit=test.get_unit(3);
	short expected=-1;
	ASSERT_EQ(expected,retunit);
}

TEST(PolymerChain_Tests,GetUnitZero_Initialized_ReturnsInitUnit)
{
	unsigned short initunit=4;
	PolymerChain test=Initialize_PolymerChain_Unit4();
	short retunit=test.get_unit(0);
	ASSERT_EQ(initunit,retunit);
}

TEST(PolymerChain_Tests,GetUnitZero_InitializedAndCopyConstruct_ReturnsInitUnit)
{
	unsigned short initunit=4;
	const PolymerChain test1=Initialize_PolymerChain_Unit4();
	PolymerChain test(test1);
	short retunit=test.get_unit(0);
	ASSERT_EQ(initunit,retunit);
}

TEST(PolymerChain_Tests,ExactString_InitializedWithExactString_ReturnsSameString)
{
	string initstring="030512891601";
	PolymerChain test(initstring);
	string retstring=test.exact_string();
	ASSERT_EQ(initstring,retstring);
}


};

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


