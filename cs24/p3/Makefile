# Makefile for CS 24 Project 3
#     Done: you do not need to change or submit it

# Usage:
#     Either "make" - compile/link evaluate.cpp
#     Or "make clean" - remove all .o and executable

evaluate: evaluate.o evaluator.o token.o
	g++ -Wall -o evaluate evaluate.o evaluator.o token.o -lm

evaluate.o: evaluate.cpp
	g++ -Wall -c evaluate.cpp

evaluator.o: evaluator.cpp
	g++ -Wall -c evaluator.cpp

token.o: token.cpp
	g++ -Wall -c token.cpp

clean:
	rm -f evaluate evaluate.o evaluator.o token.o
