INCLUDE = -I./src -I/usr/include

CopolTest: CopolTest.o Molecule.o
        ln $^ -o $@

CopolTest.o: tests/Copoltest.cpp
        gcc -c $^ -o $@
        
Molecule.h: tests/Molecule.cpp
        gcc -c $^ -o $@



