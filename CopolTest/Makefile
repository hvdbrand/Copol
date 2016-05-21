INCLUDE = -I./src -I/usr/include

CopolTest: CopolTest.o Molecule.o
	ln $^ -o $@

CopolTest.o: tests/CopolTest.cpp
	gcc -c $^ -o $@
        
Molecule.o: src/Molecule.cpp
	gcc -c $^ -o $@



