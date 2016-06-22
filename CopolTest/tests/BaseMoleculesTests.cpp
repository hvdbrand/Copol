/*
 * BaseMoleculesTests.cpp
 *
 *  Created on: 21 jun. 2016
 *      Author: HBrand
 */

#include "gtest/gtest.h"
#include "gmock/gmock.h"
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
	ASSERT_EQ(basemol.name_in_db("foo",5),-1);
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

class FakePolymerChain : public PolymerChain {
	public:
		FakePolymerChain()
		{PolymerChain(0U);}

		MOCK_CONST_METHOD0(get_length,unsigned int());
		MOCK_CONST_METHOD1(get_unit,short(unsigned int));
};

TEST(BaseMoleculesTests,GetChainMass_FakePolymerChain_ReturnsFifteen)
{
	BaseMolecules basemol=EmptyBaseMolecules();
	basemol.add_molecule("Testmol",Monomers,15);
	FakePolymerChain *polychain=new FakePolymerChain();
	EXPECT_CALL(*polychain,get_length()).Times(1).WillOnce(testing::Return(1));
	EXPECT_CALL(*polychain,get_unit(0)).Times(1).WillOnce(testing::Return(0));
	ASSERT_EQ(basemol.get_chain_mass(polychain),15);
};

}

