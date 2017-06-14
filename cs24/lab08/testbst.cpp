// testbst.cpp
// Tests intbst.cpp for CS 24 Lab08

#include "intbst.h"

#include <iostream>
using namespace std;

// creates two trees (one empty), and does simple tests of tree methods
int main() {

    IntBST bst1, bst2;

    // insert data to bst1
    bst1.insert(64);
    bst1.insert(128);
    bst1.insert(8);
    bst1.insert(512);
    bst1.insert(256);
    bst1.insert(32);
    bst1.insert(16);
    bst1.insert(4);

    // print and test methods for bst1
    cout << "BST: " << endl << "  pre-order: ";
    bst1.print(IntBST::PRE);
    cout << endl << "  in-order: ";
    bst1.print(IntBST::IN);
    cout << endl << "  post-order: ";
    bst1.print(IntBST::POST);
    cout << endl;
    cout << "  sum: " << bst1.sum() << endl;
    cout << "  contains 16? " << bst1.contains(16) << endl;
    cout << "  contains 128? " << bst1.contains(128) << endl;
    cout << "  contains 17? " << bst1.contains(17) << endl;
    cout << "  contains 512? " << bst1.contains(512) << endl;

    // test methods for empty bst2 (just need one contains test though)
    cout << "Empty BST: " << endl << "  pre-order: ";
    bst2.print(IntBST::PRE);
    cout << endl << "  in-order: ";
    bst2.print(IntBST::IN);
    cout << endl << "  post-order: ";
    bst2.print(IntBST::POST);
    cout << endl;
    cout << "  sum: " << bst2.sum() << endl;
    cout << "  contains 16? " << bst2.contains(16) << endl;

    // add tests for optional methods that you attempt to implement

    return 0;
}
