CXX = g++
CXXFLAGS = #-std=c++17 -O2

.PHONY: all clean

all: list_main Makefile

list_main: list_main.o list.hpp #list.o
	$(CXX) $(CXXFLAGS) -o $@ $<

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm *.o

