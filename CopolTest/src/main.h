/*
 * main.h
 *
 *  Created on: 21 mei 2016
 *      Author: HBrand
 */

#ifndef MAIN_H_
#define MAIN_H_

// Preprocessor Macro's
// Macro for numerical to string conversion (double expansion required)
#define STR2(X) #X
#define STR(X) STR2(X)

// Include standard libraries
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <time.h>
using namespace std;

// Add header files for classes
#include "Molecule.h"
#include "constants.h"
using namespace constants;

// Defaults that are used internally in the classes
#define LASTSIM "last_sim.xml"
#define LASTREG "last_reg.xml"
#define DEFSIM "def_sim.xml"
#define DEFREG "def_reg.xml"
#define HUGE 1e99
#define MAX_RND_NUM 10000
#define MAX_LIST_CHAINS 10000000L
#define MAX_CHAIN_UNITS 1000
#define MAX_LIST_ITEMS 2000000000L
//Defaults that the user will encounter whilst entering data
#define MAX_REACT 2000000000L
#define MIN_RES 100L
#define MAX_RES 10000000L
#define MAX_SEED 4294967295UL
#define MIN_MASS 1e-6
#define MIN_CONC 1e-6
#define MIN_RATE_CONST 1e-18
#define MIN_TIME 1e-8
#define DFLT_INIT_MULT 2.0
#define DFLT_RES 1000

#endif /* MAIN_H_ */
