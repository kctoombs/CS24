// evaluate.cpp
// Use AS-IS for CS 24 Project 3 - you will not turn in this file

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "evaluator.h"

int main() {
    string line, t;
    double result;

    // utility functions defined below
    bool blankOrComment(string &);
    void printQueue(queue<Token>);

    while ( getline(cin, line) ) {
 
        if (blankOrComment(line))  // skip blank lines and comments
            continue;

        try {
            // parse line, and create and enqueue all Tokens
            istringstream parser(line);
            queue<Token> infix;
            while (parser >> t) {
                Token token(t);
                infix.push(token);
            }
           
            // convert to postfix and print translation
            queue<Token> postfix = infixToPostfix(infix);
            cout << "postfix: ";
            printQueue(postfix);
            cout << " ";

            // evaluate and print results
            result = evaluatePostfix(postfix);
            cout <<  "equals " << result << endl;
        }
        catch(string e) {
            cout << "Exception: " << e << endl;
        }
    }
    return 0;
}

bool blankOrComment(string &s) {
    for (size_t i = 0; i < s.size(); i++) {
        char c = s.at(i);
        if (c == '#')
            return true;
        if (!isspace(c))
            return false;
    }
    return true;
}

void printQueue(queue<Token> q) {
    queue<Token> temp(q); // make a copy
    while (!temp.empty()) {
        cout << temp.front();
        temp.pop();
        if (!temp.empty())
            cout << " ";
    }
}
