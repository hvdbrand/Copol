INC = -I./src -I/usr/include

CopolTest: CopolTest.o Molecule.o
	c++ --coverage $^ -o $@

CopolTest.o: tests/CopolTest.cpp
	c++ ${INC} --coverage -c $^ -o $@
        
Molecule.o: src/Molecule.cpp
	c++ ${INC} --coverage -c $^ -o $@

gtest_main.a:
	make -C googletest/make gtest_main.a
	
gmock_main.a:
	make -C googlemock/make gmock_main.a

