/*
 * Molecule.h
 *
 *  Created on: 21 mei 2016
 *      Author: HBrand
 */

#ifndef MOLECULE_H_
#define MOLECULE_H_

#include <string>
#include <vector>
using namespace std;


/** \enum MoleculeType
 * Enumeration indication different Molecule types.
 */
enum MoleculeType
{
/** \var MoleculeType Initiators
 * Initiator type
 */
    Initiators,
/** \var MoleculeType InitiatorRads
 * Initiator radical type
 */
    InitiatorRads,
/** \var MoleculeType Monomers
 * Monomer type
 */
    Monomers,
/** \var MoleculeType NumberOfTypes
 * Total number of types
 */
    NumberOfTypes
};
extern const char *MoleculeType_str[NumberOfTypes];


/**
 * \brief Molecule properties
 *
 * This class holds the properties of a molecule.
 * Each molecule is given a name, mass and type.
 * The molecules are used as units of the polymers or in initiator reactions.
 * The molecules are created in the AddMoleculeGuiWindow class and saved in a
 * BaseMolecules class. A PolymerChain consists of multiple molecules units.
 * \see AddMoleculeGuiWindow, BaseMolecules, PolymerChain
 * \ingroup SIMclasses
 */
class Molecule
{
public:
    /** \brief Constructor based on the Molecule properties
     *  \param i_name Name of the new Molecule
     *  \param i_type Type of the new Molecule
     *  \param i_mass Mass of the new Molecule
     */
    Molecule(string i_name,MoleculeType i_type,double i_mass)
        :m_name(i_name),m_type(i_type),m_mass(i_mass)
        {}

    Molecule(Molecule const* p_mol)
        :m_name(p_mol->get_name()),m_type(p_mol->get_type()),m_mass(p_mol->get_mass())
        {}

    /** \brief Get the molecule name. */
    string get_name() const {return m_name;}
    /** \brief Get the molecule type. */
    MoleculeType get_type() const {return m_type;}
    /** \brief Get the molecule mass. */
    double get_mass() const {return m_mass;}

protected:
    /** \brief Name of the Molecule, which is usable as an identifier. */
    string m_name;
    /** \brief Molecule type to indicate in what reactions the molecule can be involved. */
    MoleculeType m_type;
    /** \brief Mass of the Molecule in arbitrary units, used for calculating the MMD. */
    double m_mass;
};

/**
 * \brief Chain of Molecule units that resembles the structure of a polymer.
 *
 * This class holds a list of pointers to molecules.
 * This resembles the linear structure of a polymer.
 * A chain is created with a single molcule.
 * Additional molecules can be added and th properties of the chain can be queried.
 * The molecules are used as units of the polymers or in initiator reactions.
 *
 * \see Molecule, BaseMolecules
 * \ingroup SIMclasses
*/
class PolymerChain
{
public:
    /** \brief Constructor which creates a one unit PolymerChain.
     *  \param i_radical Number of the first Molecule to add to the PolymerChain.
     */
    PolymerChain(unsigned short i_radical);
    /** \brief Constructor which creates PolymerChain using an exact string.
     *  \param i_string String containing the components of the polymer as created by
     *  \ref exact_string().
     */
    PolymerChain(string i_string);
    PolymerChain(const PolymerChain& old);
    /* The desctructor doesn't need to do anything, the pointers are to the basemolecule objects.
     * The vector should be cleared automatically. */
    virtual ~PolymerChain();
    /** \brief Return the number of Molecules of a specific type.
     *  \param check_mole Number of the molecule in BaseMolecules that might be in the PolymerChain.
     *  \return The number of units in the PolymerChain of Molecule check_mole.
     */
    unsigned int get_units_of_type(unsigned short check_mole);
    /** \brief Return the number of units in the PolymerChain. */
    unsigned int get_length() const;
    /** \brief Adds a Molecule to the back of the PolymerChain.
     *  \param mole_to_add Number of the Molecule that should be added.
     */
    void add_molecule_unit(unsigned short mole_to_add);
    /** \brief Returns a pointer to the Molecule that is the first unit.
     *  \return The number of the Molecule in BaseMolecules that serves as the first unit.
     */
    unsigned short get_initial_unit();
    /** \brief Returns the number of the Molecule that is the ultimate unit.
     *  \return The number of the Molecule in BaseMolecules that serves as the ultimate unit.
     */
    unsigned short get_ultimate_unit();
    /** \brief Returns the number of the Molecule that is the penultimate unit.
     *  \return The number of the Molecule in BaseMolecules that serves as the penultimate unit.
     *  If the chain doesn't have that enough molecules, -1 is returned.
     */
    short get_penultimate_unit();
    /** \brief Returns the number of the Molecule at a specific position the PolymerChain.
     *  \param unit_num Number of the Molecule pointer that is returned.
     *  \return The number of the Molecule in BaseMolecules at a specific position in the PolymerChain.
     *  If the chain doesn't have that enough molecules, -1 is returned.
     */
    short get_unit(unsigned unit_num) const;
    /** \brief Returns a string describing precisely the polymer chain.
     *
     *  This functions converts the PolymerChain to a string of numbers.
     *  The numbers refer to the molecules in BaseMolecules.
     *  Molecules of the Initiator type are noted by an I. A Molecule of the type Monomer is assigned a letter A, B, C or D.
     *  Each of these letters corresponds to a type of Monomer. This allows one to see the structure of the PolymerChain.
     *  \return A string indicating the structure, for instance: 010202030301.
     *  \warning The function assumes there are no more than 100 different molecules in BaseMolecules.
     */
    string exact_string();

protected:
    /** \brief A vector holding the numbers of the molecules in the PolymerChain. */
    vector<unsigned short> m_monomer_units;
};




#endif /* MOLECULE_H_ */
