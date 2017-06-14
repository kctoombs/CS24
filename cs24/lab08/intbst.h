// intbst.h
// Binary search tree header file for CS 24 Lab08

#ifndef INTBST_H
#define INTBST_H

class IntBST {

public:
    // enumeration for traversal order when printing
    enum Order { PRE, IN, POST };

    // ctor, dtor and insert method already done in intbst.cpp:
    IntBST();               // constructor
    ~IntBST();              // destructor
    bool insert(int value); // insert value in tree; return false if duplicate

    // 1 method partly done (for pre-order only) in intbst.cpp
    void print(Order o) const; // YOU MUST COMPLETE FOR IN- AND POST-ORDER

    // 2 METHODS YOU MUST IMPLEMENT COMPLETELY IN intbst.cpp:
    int sum() const;                 // sum of all values
    bool contains(int value) const;  // true if value is in tree

    // suggested signatures of optional challenge methods:
    // int count() const;       // count of values
    // void remove(int value);  // remove value from the tree

private:

    // DO NOT CHANGE DEFINITION OF struct Node:
    struct Node {
        int info;
        Node *left, *right;
        // constructor implemented inline:
        Node(int v=0) : info(v), left(0), right(0) { }
    };

    // just one instance variable (pointer to root node):
    Node *root;

    // recursive utility functions for public methods above
    void clear(Node *n); // for destructor
    bool insert(int value, Node *n); // note overloading names for simplicity
    void print(Order o, Node *n) const;
    int sum(Node *n) const;
    bool contains(int value, Node *n) const; // not used for iterative solution

    // suggested signatures of utility functions for optional challenges:
    // int count(Node *n) const;
    // void remove(int value, Node* &n); // uses removeThis below too
    // void removeThis(Node* &n); // in turn, uses maxValue below
    // int maxValue(Node *n) const;
};

#endif
