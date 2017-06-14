# Makefile for CS 24 Lab02

testlist: testlist.o intlist.o
	g++ -o testlist testlist.o intlist.o

testlist.o: testlist.cpp
	g++ -c testlist.cpp

intlist.o: intlist.cpp
	g++ -c intlist.cpp

clean:
	rm testlist.o intlist.o
