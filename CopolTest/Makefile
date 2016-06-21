INC = -I./src -I/usr/include

CopolTest: CopolTest.o Molecule.o
	c++ --coverage $^ -o $@

CopolTest.o: tests/CopolTest.cpp
	c++ ${INC} --coverage -c $^ -o $@
        
Molecule.o: src/Molecule.cpp
	c++ ${INC} --coverage -c $^ -o $@

gtest_main.a:
    cd googletest/make
    make gtest_main.a
    cp gtest_main.a ../..

