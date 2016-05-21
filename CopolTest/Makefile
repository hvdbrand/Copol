INCLUDE = -I./src -I/usr/include

CopolTest: CopolTest.o Molecule.o
	ln $^ -o $@

CopolTest.o: tests/CopolTest.cpp
	c++ -c $^ -o $@
        
Molecule.o: src/Molecule.cpp
	c++ -c $^ -o $@



