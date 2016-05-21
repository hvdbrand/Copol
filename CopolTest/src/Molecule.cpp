/*
 * Molecule.cpp
 *
 *  Created on: 21 mei 2016
 *      Author: HBrand
 */

#include "Molecule.h"

#include "main.h"

const char *MoleculeType_str[]={ "Initiator","Initiator Radical","Monomer" };

PolymerChain::PolymerChain(unsigned short i_radical)
{
    this->add_molecule_unit(i_radical);
}

PolymerChain::PolymerChain(string i_string)
{
    unsigned short unit;
    for(unsigned i=0;i<i_string.length()-1;i=i+2)
    {
        istringstream unit_str(i_string.substr(i,2));
        unit_str >> unit;
        add_molecule_unit(unit);
    }
}

PolymerChain::PolymerChain(const PolymerChain& old)
{
    unsigned int num_mole=old.get_length();
    for (unsigned int i = 0; i<num_mole; ++i)
         m_monomer_units.push_back(old.get_unit(i));;
}

PolymerChain::~PolymerChain()
{
    m_monomer_units.clear();
}

unsigned int PolymerChain::get_units_of_type(unsigned short check_mole)
{
    unsigned int units=0;
    unsigned int num_mole=static_cast<unsigned int>(m_monomer_units.size());
    for (unsigned int i = 0; i<num_mole; ++i)
    {
        if (m_monomer_units[i] == check_mole)
            units++;
    }
    return units;
}

unsigned int PolymerChain::get_length() const
{
    return static_cast<unsigned int>(m_monomer_units.size());
}

void PolymerChain::add_molecule_unit(unsigned short mole_to_add)
{
    m_monomer_units.push_back(mole_to_add);
}

unsigned short PolymerChain::get_initial_unit()
{
    return m_monomer_units[0];
}

unsigned short PolymerChain::get_ultimate_unit()
{
    return m_monomer_units.back();
}

short PolymerChain::get_penultimate_unit()
{
    unsigned int mon_units=static_cast<unsigned int>(m_monomer_units.size());
    if(mon_units<2)
        return -1;;
    return m_monomer_units[mon_units-2];
}

short PolymerChain::get_unit(unsigned unit_num) const
{
    if (unit_num >= static_cast<unsigned int>(m_monomer_units.size()))
        return -1;;
    return m_monomer_units[unit_num];
}

string PolymerChain::exact_string()
{
    ostringstream strs;
    unsigned int num_mole=get_length();
    for (unsigned i=0;i<num_mole;i++)
    {
        strs << setfill('0') << setw(2) << m_monomer_units[i];
    }
    return strs.str();
}



