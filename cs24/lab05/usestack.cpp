// usestack.cpp - for CS 24 Lab05 practice using stacks
// Aaron Chang, Kenneth Toombs.  11/10/14

#include "intstack.h"
#include <iostream>
using namespace std;

int main() {
    //evaluating " 6 3 + 9 * "
    Stack s;
    s.push(6);
    s.push(3);
    
    // * operation
    int right = s.top();
    s.pop();
    int left = s.top();
    s.pop();
    s.push(left + right);

    s.push(9);

    // + operation
    int rright = s.top();
    s.pop();
    int rleft = s.top();
    s.pop();
    s.push( rleft * rright);

    cout << s.top() << endl;


    return 0;
}
