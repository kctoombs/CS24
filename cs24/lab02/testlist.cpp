// testlist.cpp
// Tests intlist.cpp for CS 24 Lab02

#include "intlist.h"

#include <iostream>
using namespace std;

// creates two lists (one empty), and does simple tests of list methods
int main() {

    IntList list1, list2;

    // add data to list1 (first 10 powers of 2, for no particular reason)
    for (int i = 1; i <= 512; i *= 2)
        list1.append(i);

    // print and test methods for list1
    cout << "List: ";
    list1.print();
    cout << endl << "   count: " << list1.count() << endl;
    cout << "   sum: " << list1.sum() << endl;
    cout << "   contains 1? " << list1.contains(1) << endl;
    cout << "   contains 32? " << list1.contains(32) << endl;
    cout << "   contains 512? " << list1.contains(512) << endl;
    cout << "   contains 17? " << list1.contains(17) << endl;

    // test methods for empty list2 (just need one contains test though)
    cout << "Empty list: ";
    list2.print();
    cout << endl << "   count: " << list2.count() << endl;
    cout << "   sum: " << list2.sum() << endl;
    cout << "   contains 1? " << list2.contains(1) << endl;

    // add tests for optional methods that you attempt to implement

    return 0;
}
