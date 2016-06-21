/*
 * BaseMoleculesTests.cpp
 *
 *  Created on: 21 jun. 2016
 *      Author: HBrand
 */

#include "gtest/gtest.h"
#include "../src/main.h"

namespace BaseMoleculesTests {

BaseMolecules EmptyBaseMolecules() {
	return BaseMolecules();
}

TEST(BaseMoleculesTests,NumberOfMolecules_Initialized_ReturnsZero)
{
	BaseMolecules basemol=EmptyBaseMolecules();
	ASSERT_EQ(basemol.number_of_molecules(),0);
};

TEST(BaseMoleculesTests,NameInDb_Initialized_ReturnsMinusOne)
{
	BaseMolecules basemol=EmptyBaseMolecules();
	ASSERT_EQ(basemol.name_in_db("foo",5),0);
};

TEST(BaseMoleculesTests,GetName_Initialized_ReturnsEmptyString)
{
	BaseMolecules basemol=EmptyBaseMolecules();
	ASSERT_EQ(basemol.get_name(5),"");
};

TEST(BaseMoleculesTests,GetType_Initialized_ReturnsZero)
{
	BaseMolecules basemol=EmptyBaseMolecules();
	ASSERT_EQ(basemol.get_type(5),0);
};

TEST(BaseMoleculesTests,GetMass_Initialized_ReturnsZero)
{
	BaseMolecules basemol=EmptyBaseMolecules();
	ASSERT_EQ(basemol.get_mass(5),0);
};

}

