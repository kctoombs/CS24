# Makefile for CS 24 Lab08

testbst: testbst.o intbst.o
	g++ -o testbst testbst.o intbst.o

testbst.o: testbst.cpp
	g++ -c testbst.cpp

intbst.o: intbst.cpp
	g++ -c intbst.cpp

clean:
	rm -f testbst.o intbst.o testbst
