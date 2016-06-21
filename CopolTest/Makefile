INC = -I./src -I/usr/include -Igoogletest/include \
      -Igooglemock/include
LINK = -L/lib64 -lpthread 

CopolTest: BaseMoleculesTests.o PolymerChainTests.o CopolTest.o Molecule.o BaseMolecules.o googletest/make/gtest_main.a
	c++ ${LINK} --coverage $^ -o $@

CopolTest.o: tests/CopolTest.cpp
	c++ ${INC} --coverage -c $^ -o $@
	
PolymerChainTests.o: tests/PolymerChainTests.cpp
	c++ ${INC} --coverage -c $^ -o $@
	
BaseMoleculesTests.o: tests/BaseMoleculesTests.cpp
	c++ ${INC} --coverage -c $^ -o $@
        
Molecule.o: src/Molecule.cpp
	c++ ${INC} --coverage -c $^ -o $@

BaseMolecules.o: src/BaseMolecules.cpp
	c++ ${INC} --coverage -c $^ -o $@

googletest/make/gtest_main.a:
	make -C googletest/make gtest_main.a
	
googlemock/make/gmock_main.a:
	make -C googlemock/make gmock_main.a

