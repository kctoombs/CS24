// evaluator.h
// Prototypes for two functions (1) converts infix expressions to postfix
// expressions, and (2) evaluates postfix expressions.
   
// Use as-is for CS 24 Project 3. DO NOT CHANGE THIS FILE.
   
#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "token.h"

#include <queue>
using std::queue;

queue<Token> infixToPostfix(queue<Token> infixExpression);
    // returns postfix translation of infix expression parameter

double evaluatePostfix(queue<Token> expression);
    // attempt to evaluate the postfix expression parameter
    // return result of the expression
    // throw string reason if expression is not valid

#endif
