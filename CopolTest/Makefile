INC = -I./src -I/usr/include

CopolTest: CopolTest.o Molecule.o
	ld $^ -o $@

CopolTest.o: tests/CopolTest.cpp
	c++ ${INC} -c $^ -o $@
        
Molecule.o: src/Molecule.cpp
	c++ ${INC} -c $^ -o $@



