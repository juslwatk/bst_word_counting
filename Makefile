CXX = g++
CXXFLAGS = -std=c++17

all: bst

bst: driver.o bst.o
	$(CXX) $(CXXFLAGS) -o bst driver.o bst.o

driver.o: driver.cpp bst.h node.h
	$(CXX) $(CXXFLAGS) -c driver.cpp

bst.o: bst.cpp bst.h node.h
	$(CXX) $(CXXFLAGS) -c bst.cpp

clean:
	rm -f *.o bst
