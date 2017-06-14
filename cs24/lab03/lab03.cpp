// lab03.cpp - program file for CS 24 Lab03
// a node structure, specialized list move and copy functions,
// and a main function to test the functions
// Kenneth Toombs, Aaron Chang. 10/27/14

#include <iostream>
using namespace std;

// basically the same node structure used in Hw3
struct Node {
   int data;
   Node* next;

   // constructor implemented here ("implicit inline")
   Node (int item, Node* n = 0) : data(item), next(n) { }
};

// Here is a function we implement together (lab part 3)
Node *moveCat(Node* &first, Node* &second);

// HERE IS A FUNCTION YOU MUST TRY BY YOURSELVES (lab part 4)
Node *copyCat(Node *first, Node *second);

// Here are suggested optional functions for you to implement
Node *moveMerge(Node* &first, Node* &second);
Node *copyMerge(Node *first, Node *second);

// some utility functions used by main, implemented at the bottom
void setup(Node* &aList, Node* &bList, Node* &bigList);
Node *newList(int array[], int n);
void destroyList(Node* &list);
void printList(Node *list);
void printAll(Node* aList, Node* bList, Node* bigList);

// only edit main if you do some of the optional parts below
int main() {
    Node *aList=0, *bList=0, *bigList=0;

    // test moveCat function
    setup(aList, bList, bigList);
    bigList = moveCat(aList, bList);
    cout << "After moveCat(aList, bList):" << endl;
    printAll(aList, bList, bigList);

    // test copyCat function
    setup(aList, bList, bigList);
    bigList = copyCat(aList, bList);
    cout << "After copyCat(aList, bList):" << endl;
    printAll(aList, bList, bigList);

/* OPTIONAL TESTS:
    // test moveMerge function
    setup(aList, bList, bigList);
    bigList = moveMerge(aList, bList);
    cout << "After moveMerge(aList, bList):" << endl;
    printAll(aList, bList, bigList);

    // test moveMerge function with shorter list first this time
    setup(aList, bList, bigList);
    bigList = moveMerge(bList, aList);
    cout << "After moveMerge(bList, aList):" << endl;
    printAll(aList, bList, bigList);

    // test copyMerge function
    setup(aList, bList, bigList);
    bigList = copyMerge(aList, bList);
    cout << "After copyMerge(aList, bList):" << endl;
    printAll(aList, bList, bigList);

    // test copyMerge function with shorter list first this time
    setup(aList, bList, bigList);
    bigList = copyMerge(bList, aList);
    cout << "After copyMerge(bList, aList):" << endl;
    printAll(aList, bList, bigList);
END OPTIONAL TESTS */
    return 0;
}

// concatenates second list to end of first list to create a new
// list - moves the nodes, and leaves parameter lists empty
Node *moveCat(Node* &first, Node* &second) {
  Node* result = first;
  if(first != 0){
    Node* n = first;
    while(n->next != 0)
      n = n->next;
    n->next = second;
  }
  else
    result = second;
  first = second = 0;
  return result;
}

// concatenates second list to end of first list to create a new
// list - copies the nodes, and does not change parameter lists
// pre-condition: first is not empty and second is not empty
Node *copyCat(Node* first, Node* second) {
  Node* n = first, *m = second;
  Node* result = new Node(first->data);
  Node* a = result;
  while(n->next != 0){
    n = n->next;
    a->next = new Node(n->data);
    a = a->next;
  }
  while(m->next != 0){
    a->next = new Node(m->data);
    a = a->next;
    m = m->next;
  }
  return result;
}

// merges (by simple interleaving) first and second lists to create
// a new list - moves the nodes, and leaves parameter lists empty
Node *moveMerge(Node* &first, Node* &second) {
    return 0; // OPTIONAL: IMPLEMENT AND REPLACE THIS NULL RETURN
}

// merges (by simple interleaving) first and second lists to create
// a new list -  - copies the nodes, and does not change parameter lists
Node *copyMerge(Node* first, Node* second) {
    return 0; // OPTIONAL: IMPLEMENT AND REPLACE THIS NULL RETURN
}

// DO NOT CHANGE ANYTHING BELOW THIS COMMENT (JUST UTILITY FUNCTIONS)

// utility builds a list from first n elements of an array
Node *newList(int array[], int n) {
    Node *list = 0;
    for (int i = n-1; i >= 0; i--) // reverse order to insert first
        list = new Node(array[i], list);
    return list;
}

// utility destroys a list (returns nodes to the free store)
void destroyList(Node* &list) {
    Node *n = list;
    while (n != 0) {
        Node *garbage = n;
        n = n->next;
        delete garbage;
    }
    list = 0;
}

// utility prints a single list and a newline
void printList(Node *list) {
    cout << "[";
    while (list != 0) {
        cout << list->data;
        if (list->next != 0)
            cout << ",";
        list = list->next;
    }
    cout << "]" << endl;
}

// utility prints all three lists (with known labels)
void printAll(Node* aList, Node* bList, Node* bigList) {
    cout << "aList: ";
    printList(aList);
    cout << "bList: ";
    printList(bList);
    cout << "bigList: ";
    printList(bigList);
}

// utility sets up for a new problem, and prints initial state
void setup(Node* &aList, Node* &bList, Node* &bigList) {
    // starter data stored in arrays
    int a[] = {17, 12, 18, 15, 14, 16, 11, 13, 19};
    int b[] = {4, 7, 9, 1, 3, 2, 5};
    int aLen = 9, bLen = 7;

    // first clean up any old nodes (nothing happens if null)
    destroyList(aList);
    destroyList(bList);
    destroyList(bigList);

    // create two starter lists and print all lists
    aList = newList(a, aLen);
    bList = newList(b, bLen);
    cout << "------------------------------------------------" << endl;
    cout << "STARTING NEW TEST" << endl;
    cout << "------------------------------------------------" << endl;
    printAll(aList, bList, bigList);
}
