testarray: testQ.o arrayQ.o
	g++ -Wall -o testQ testQ.o arrayQ.o

testQ.o: testQ.cpp
	g++ -Wall -c testQ.cpp

arrayQ.o: arrayQ.cpp
	g++ -Wall -c arrayQ.cpp

testlist: testQ.o listQ.o
	g++ -Wall -o testQ testQ.o listQ.o

listQ.o: listQ.cpp
	g++ -Wall -c listQ.cpp
