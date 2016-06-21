#include "BaseMolecules.h"
#include "../main.h"

BaseMolecules::~BaseMolecules()
{
    m_molecules.clear();
}

BaseMolecules::BaseMolecules(const BaseMolecules &old)
{
    unsigned num_mol=old.number_of_molecules();
    for(unsigned i=0;i<num_mol;i++)
        this->add_molecule(old.get_molecule(i));;
}

void BaseMolecules::add_molecule(Molecule const* p_new_mol)
{
    Molecule new_mol(p_new_mol);
    add_molecule(new_mol);
}

void BaseMolecules::add_molecule(Molecule new_mol)
{
    this->m_molecules.push_back(new_mol);
    this->m_types[new_mol.get_type()]++;
#ifdef DEBUG_SIM
    cout << "BaseMolecules: added " << MoleculeType_str[new_mol.get_type()] << " named:  " << new_mol.get_name() << endl;
#endif
}

void BaseMolecules::add_molecule(string name, MoleculeType type, double mass)
{
    Molecule temp(name,type,mass);
    this->add_molecule(temp);
}

void BaseMolecules::update_molecule(int db_entry, Molecule new_mol)
{
    if (db_entry>-1)
    {
        // Update the molecule 
        this->m_molecules[db_entry]=new_mol;
    #ifdef DEBUG_SIM
        cout << "BaseMolecules: updated " << MoleculeType_str[m_molecules[db_entry].get_type()] << " named:  " << this->m_molecules[db_entry].get_name() << endl;
    #endif
    }
    else
    {
        this->add_molecule(new_mol);
    }
}

void BaseMolecules::update_molecule(int db_entry,string name, MoleculeType type, double mass)
{
    Molecule temp(name,type,mass);
    this->update_molecule(db_entry,temp);
}

Molecule const* BaseMolecules::get_molecule(unsigned db_entry) const
{
     if (db_entry>=static_cast<unsigned int>(m_molecules.size()))
         return 0;;
     return &(m_molecules[db_entry]);
}

short BaseMolecules::get_type(unsigned db_entry) const
{
    if (db_entry>=static_cast<unsigned int>(m_molecules.size()))
         return 0;;
    return static_cast<short>(m_molecules[db_entry].get_type());
}
      

double BaseMolecules::get_mass(unsigned db_entry) const
{
    if (db_entry>=static_cast<unsigned int>(m_molecules.size()))
         return 0.0;;
    return m_molecules[db_entry].get_mass();
}

double BaseMolecules::get_chain_mass(PolymerChain* ip_polychain)
{
    double tot_mass=0;
    unsigned int num_mole=static_cast<unsigned int>(ip_polychain->get_length());
    for (unsigned int i = 0; i<num_mole; ++i)
        tot_mass += get_mass(ip_polychain->get_unit(i));;
    return tot_mass;
}


string BaseMolecules::get_name(unsigned db_entry) const
{
    string empty("");
    if (db_entry>=static_cast<unsigned int>(m_molecules.size()))
         return empty;;
    return m_molecules[db_entry].get_name();
}

unsigned BaseMolecules::number_of_molecules() const
{
    return this->m_molecules.size();
}
     
void BaseMolecules::remove_molecule(unsigned db_entry)
{   // Remove entry db_entry from the database
#ifdef DEBUG_SIM 
   cout << "BaseMolecules: removed " << MoleculeType_str[m_molecules[db_entry].get_type()] << " named:  " << this->m_molecules[db_entry].get_name() << endl;
#endif
   this->m_types[this->m_molecules[db_entry].get_type()]--;
   this->m_molecules.erase(m_molecules.begin()+db_entry);
}

int BaseMolecules::name_in_db(string new_name, int db_entry) const
{
    for (unsigned int i=0;i<m_molecules.size();i++)
    {
        if ((i!=db_entry) && (this->m_molecules[i].get_name().compare(new_name) == 0))
            return i;;    // Molecule name is already used
    }
    return -1;    
}

string BaseMolecules::polymer_string(PolymerChain* ip_polychain)
{
    // Assumes four monomers and one initiator type
    unsigned short mono1,mono2,mono3;
    unsigned int monomers_used=0;
    ostringstream strs;
    for (unsigned i=0;i<ip_polychain->get_length();i++)
    {
        if (get_type(ip_polychain->get_unit(i))==InitiatorRads)
        {
            strs << "I";
        }
        else if (get_type(ip_polychain->get_unit(i))==Monomers)
        {
             if (monomers_used>0)
             {
                 if (ip_polychain->get_unit(i)==mono1)
                 {
                     strs << "A";
                 }
                 else if (monomers_used>1)
                 {
                     if (ip_polychain->get_unit(i)==mono2)
                     {
                         strs << "B";
                     }
                     else if (monomers_used>2)
                     {
                         if (ip_polychain->get_unit(i)==mono3)
                         {
                             strs << "C";
                         }
                         else
                         {
                             strs << "D";    
                         }     
                     }
                     else
                     {
                         mono3=ip_polychain->get_unit(i);
                         monomers_used=3;
                         strs << "C";      
                     }  
                 }
                 else
                 {
                     mono2=ip_polychain->get_unit(i);
                     monomers_used=2;
                     strs << "B";     
                 }
             }
             else
             {
                 mono1=ip_polychain->get_unit(i);
                 monomers_used=1;
                 strs << "A";    
             }
        }
    }
    return strs.str();      
}
