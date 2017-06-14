// intlist.h
// Linked list header file for CS 24 Lab02

#ifndef INTLIST_H
#define INTLIST_H

class IntList {

public:

    // ctor, dtor and 3 methods already done in intlist.cpp:
    IntList();              // constructor
    ~IntList();             // destructor
    void append(int value); // append value at end of list
    void print() const;     // print values separate by ' '
    int count() const;      // return count of values

    // 2 METHODS YOU MUST IMPLEMENT IN intlist.cpp:
    int sum() const;                 // sum of all values
    bool contains(int value) const;  // true if value in list

    // suggested signatures of optional challenge methods
    // int max() const;              // maximum value
    // double average() const;       // average of all values
    // void insertFirst(int value);  // insert new first value

private:

    // DO NOT CHANGE DEFINITION OF struct Node:
    struct Node {
        int info;
        Node *next;
    };

    // just one instance variable (pointer to first node):
    Node *first;
};

#endif
