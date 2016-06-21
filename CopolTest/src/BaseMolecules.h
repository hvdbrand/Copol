#ifndef BASEMOLECULES_H
#define BASEMOLECULES_H

#include <vector>
#include <string>
using namespace std;

#include "main.h"

/**
 *  \brief Structure to manage a set of Molecule pointers.
 * 
 *  This class holds pointers to Molecules.
 *  BaseMolecules keeps track of the different types of Molecule pointers.
 *  A pointer to a Molecule can be requested, as well as a particular name is already used by a molecule.
 *  \see Molecule,AddMoleculeGuiWindow
 *  \ingroup SIMclasses
 */
class BaseMolecules
{
public:
    BaseMolecules()
    {for (unsigned i=0;i<NumberOfTypes;m_types[i++]=0);}
    ~BaseMolecules();
    BaseMolecules(const BaseMolecules &old);
    /** \brief Add a Molecule pointer.
     *  \param p_new_mol Molecule pointer to add.
     */
    void add_molecule(Molecule const* p_new_mol);
    /** \brief Add a Molecule.
     *  \param new_mol Molecule to add.
     */
    void add_molecule(Molecule new_mol);
    /** \brief Add a Molecule to a Molecule with the specified properties.
     *  \param name Name of the new Molecule.
     *  \param type Type of the new Molecule.
     *  \param mass Mass of the new Molecule.
     */
    void add_molecule(string name, MoleculeType type, double mass);
    /** \brief Update a Molecule (or add a new Molecule) based on a pointer.
     *  \param db_entry Number of Molecule pointer to replace. A new Molecule pointer is added if this value is -1.
     *  \param new_mol Molecule pointer used to replace the old value. If db_entry is -1, the Molecule pointer is added.
     */
    void update_molecule(int db_entry, Molecule new_mol);
    /** \brief Update a Molecule (or add a Molecule ) to a Molecule with the specified properties.
     *  \param db_entry Number of Molecule pointer to replace. A new Molecule pointer is added if this value is -1.
     *  \param name New name of the Molecule.
     *  \param type New type of the Molecule.
     *  \param mass New mass of the Molecule.
     */
    void update_molecule(int db_entry,string name, MoleculeType type, double mass);
    /** \brief Returns a Molecule pointer.
     *  \param db_entry Number of the Molecule in the BaseMolecules class for which to return.
     *  \return A pointer to the Molecule. A zero pointer is returned if db_entry exceeds the number of Molecule pointers.
     */
    Molecule const* get_molecule(unsigned db_entry) const;
    /** \brief Returns the type of a Molecule.
     *  \param db_entry Number of the Molecule in the BaseMolecules class for which to return.
     *  \return The type of the Molecule. -1 is returned if db_entry exceeds the number of Molecule pointers.
     */
    short get_type(unsigned db_entry) const;
    /** \brief Returns the mass of a Molecule.
     *  \param db_entry Number of the Molecule in the BaseMolecules class for which to return.
     *  \return The mass of the Molecule. Zero is returned if db_entry exceeds the number of Molecule pointers.
     */
    double get_mass(unsigned db_entry) const;
    /** \brief Calculate the mass of a PolymerChain. */
    double get_chain_mass(PolymerChain* ip_polychain);
    /** \brief Returns the name of a Molecule.
     *  \param db_entry Number of the Molecule in the BaseMolecules class for which to return.
     *  \return The name of the Molecule. An empty string is returned if db_entry exceeds the number of Molecule pointers.
     */
    string get_name(unsigned db_entry) const;
    /** \brief Returns the number of Molecule pointers in the BaseMolecules class. */
    unsigned number_of_molecules() const;
    /** \brief Remove Molecule pointer from the BaseMolecules class.
     *  \param db_entry Molecule pointer to delete.
     *  \warning This function doesn't check whether the db_entry doesn't exceed the amount of pointers in the BaseMolecules class.
     */
    void remove_molecule(unsigned db_entry);
    /** \brief Check whether a \ref Molecule::m_name is already in use by another Molecule in the BaseMolecules class.
     *  \param new_name Check if this name is already used by another Molecule pointer in the BaseMolecules class.
     *  \param db_entry Number that should be excluded from the comparison. -1 if all pointers should be checked.
     *  \result Returns the number of the Molecule pointer that has the \ref Molecule::m_name new_name or -1 if the \ref Molecule::m_name is not used.
     */
    int name_in_db(string new_name, int db_entry=-1) const;
    /** \brief Returns a string describing the polymer chain.
     *
     *  This functions converts the PolymerChain to a human readable string that indicates its structure.
     *  Molecules of the Initiator type are noted by an I. A Molecule of the type Monomer is assigned a letter A, B, C or D.
     *  Each of these letters corresponds to a type of Monomer. This allows one to see the structure of the PolymerChain.
     *  \return A string indicating the structure, for instance: IABBACBBAADI.
     *  \warning The letters do not necessarily correspond to the same type of monomer for different chains.
     *  In fact, the first monomer unit is always named A (although it could be monomer 1 for one chain and 
     *  monomer 2 for another chain). Therefore the string IABBAABAA could indicate either a polymer
     *  with 5 units of monomer 1 or 3 units of monomer 1.
     *  \param[in] ip_polychain Pointer to the PolymerChain to use for monomer interpretation.
     */
    string polymer_string(PolymerChain* ip_polychain);
    /** \brief Array that holds the number of Molecule pointers of a specific type. */
    int m_types[NumberOfTypes];

protected: 
    /** \brief Vector that holds the Molecules. */
    vector<Molecule> m_molecules;
};

#endif
