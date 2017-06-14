// dlist.cpp - implements class DList
// Kenneth Toombs, Marcellis Carr-Barfield.  11/6/2014.

#include <iostream>
#include "dlist.h"

void DList::clear() {
  DLNode* nodePtr = first;
  //if there are zero nodes, do nothing
  if(first != 0 && last != 0){
    //if there is only one node, delete it and set list pointers to null
    if(first->next == 0 && first->prev == 0){
      first = 0;
      last = 0;
      delete nodePtr;
    }
    //if there is more than one node, iterate through list and delete each node
    //until you reach the final node. Delete the final node, and set list pointers
    //to null
    else{
      first = 0;
      last = 0;
      nodePtr = nodePtr->next;
      while(nodePtr->next){
	delete nodePtr->prev;
	nodePtr = nodePtr->next;
      }
      delete nodePtr;
    }
  }
}

int DList::getSize() const {
  //declare variables
  int size = 0;
  DLNode* firstCpy = first;
  //if the list is not empty, iterate through list and count the total nodes
  if(isEmpty() == 0){
    size++;
    while(firstCpy->next){
      firstCpy = firstCpy->next;
      size++;
    }
  }
  //return the size of the list
  return size;
}

bool DList::isEmpty() const {
  //if the first and last pointers are null, return true
  if(first == 0 && last == 0)
    return 1;
  else
    return 0; 
}

string DList::get(int index) const {
  //declare variables
  DLNode* loop = first;
  //throw exception if index is not valid
  if (index < 0 || index > (getSize()-1)){
    throw BadIndex();
  }
  //if list is not empty, return the string at the index provided
  if (isEmpty() == 0){
    for(int i = 0; i < index; i++){
      loop = loop->next;
    }

  }
  return loop->info;
}

string DList::getFirst() const {
  //if the list is empty, throw exception
  if(isEmpty() == 1)
    throw EmptyList();

  //else return the first string in the list
  return first->info;
}

string DList::getLast() const {
    //if the list is empty, throw exception
  if(isEmpty() == 1)
    throw EmptyList();

  //else return the first string in the list
  return last->info;
}

DList DList::head(int length) const {
  DList sublist; 

  //declare variables
  DLNode* firstCpy = first;

  //if the list is empty, return sublist with an empty node
  if(isEmpty() == 1){
    sublist.addFirst("");
    return sublist;
  }

  //if the length is larger than the list, return a copy of the entire list
  if (length >= getSize()){
    while(firstCpy){
      sublist.addLast(firstCpy->info);
      firstCpy = firstCpy->next;
    }
  }
  //if the length is shorter than the list, return a copy of the first "length"
  // elements
  else{
    for(int i = 0; i < length; i++){
      sublist.addLast(firstCpy->info);
      firstCpy = firstCpy->next;
    }
  } 

  return sublist;
}

DList DList::tail(int length) const {
    DList sublist;
    //declare variables
  DLNode* lastCpy = last;

  //if the list is empty, return sublist with an empty node
  if(isEmpty() == 1){
    sublist.addLast("");
    return sublist;
  }

  //if the length is larger than the list, return a copy of the entire list
  if (length >= getSize()){
    while(lastCpy){
      sublist.addFirst(lastCpy->info);
      lastCpy = lastCpy->prev;
    }
  }
  //if the length is shorter than the list, return a copy of the first "length"
  // elements
  else{
    for(int i = 0; i < length; i++){
      sublist.addFirst(lastCpy->info);
      lastCpy = lastCpy->prev;
    }
  }
  return sublist;
}

void DList::insert(int index,  string obj) {
  //create node to be inserted
  DLNode* node1 = new DLNode(obj);
  //declare variables
  DLNode* loop = first;

  //if the index is zero insert new node at beginning
  if(index == 0)
    addFirst(obj);
  //if the index is equal to the total number of items in the list
  // insert the new node at the end of the list
  else if(index == getSize())
    addLast(obj);
  else if(index < 0 || index > getSize() - 1)
    throw BadIndex();
  else{
    //insert the new node at the given index  
    for(int i = 0; i < index; i++){
      loop = loop->next;
    }
    node1->next = loop;
    node1->prev = loop->prev;
    loop->prev->next = node1;
    loop->prev = node1;
  }
}

void DList::addFirst(string obj) {
  //if list is empty
  if (first == 0 && last == 0){
    first = new DLNode(obj);
    last = first;
  }
  else{
  DLNode* node1 = new DLNode(obj);
  //point the new first node at the new second node
  node1->next = first;
  //point the new second node at new first node
  first->prev = node1;
  //point first pointer at new first node
  first = node1;
    }
}

void DList::addLast(string obj){
   //if list is empty
  if (first == 0 && last == 0){
    first = new DLNode(obj);
    last = first;
  }
  else{
  DLNode* node1 = new DLNode(obj);
  //point the new last node at the new second to last node
  node1->prev = last;
  //point the new second node at new first node
  last->next = node1;
  //point first pointer at new first node
  last = node1;
  //set copy pointer to null and delete
  node1 = 0;
  delete node1;
    }
}

string DList::remove (int index) {
  //declare variables
  DLNode* node1 = first;
  string data;
 
  //if the list is empty throw exception
  if(isEmpty() == 1)
    throw EmptyList();

  //if the index is zero delete node at beginning
  if(index == 0){
    data = first->info;
    removeFirst();
    return data;
  }
  //if the index is equal to the total number of items in the list
  // delete node at the end of the list
  else if(index == getSize()-1){
    data = last->info;
    removeLast();
    return data;
  }
  else if(index < 0 || index > getSize() - 1)
    throw BadIndex();
  else{
    //delete the new node at the given index  
    for(int i = 0; i < index; i++){
      node1 = node1->next;
    }
    node1->next->prev = node1->prev;
    node1->prev->next = node1->next;
    node1->next = 0;
    node1->prev = 0;
    data = node1->info;
    delete node1;
  }
  return data;
}

string DList::removeFirst () {
  //declare variables
  DLNode* firstCpy = first;
  string data;
  
  //if the list is empty throw an exception
  if(isEmpty() == 1)
    throw EmptyList();

  //if there is one element in the list, remove the element and return its string
  if(getSize() == 1){
    first = 0;
    last = 0;
    data = firstCpy->info;
    delete firstCpy;
  }
  //else remove first node and make second node new first node.
  else{
    first = first->next;
    first->prev = 0;
    data = firstCpy->info;
    delete firstCpy;
  }
  return data;
}

string DList::removeLast() {
    //declare variables
  DLNode* lastCpy = last;
  string data;
  
  //if the list is empty throw an exception
  if(isEmpty() == 1)
    throw EmptyList();

  //if there is one element in the list, remove the element and return its string
  if(getSize() == 1){
    first = 0;
    last = 0;
    data = lastCpy->info;
    delete lastCpy;
  }
  //else remove first node and make second node new first node.
  else{
    last = last->prev;
    last->next = 0;
    data = lastCpy->info;
    delete lastCpy;
  }
  return data;
}

void DList::removeAllEqual(string obj) {
  DLNode* firstCpy = first;
  DLNode* lastCpy = last;
  DLNode* onlyElement = firstCpy;
  
  //if the string is the only string in list, clear the list
  int count = 0;
  while(onlyElement){
    if(onlyElement->info == obj){
      count++;
    } 
    onlyElement = onlyElement->next;
    if(count == getSize())
      clear();
  }
  //reset firstCpy
  firstCpy = first;

  
  //if the list is not empty, remove elements

  if(getSize() > 0){    
    //while the object is located in the first OR last node, remove the
    //node containing obj
    while(firstCpy->info == obj){
      first = firstCpy->next;
      first->prev = 0;
      delete firstCpy;
      firstCpy = first;
    }
    
    while(lastCpy->info == obj){
      last = lastCpy->prev;
      last->next = 0;
      delete lastCpy;
      lastCpy = last;
    }
    
    //iterate through the list and delete the nodes where obj appears (center
    // of the list is the only thing that needs to be checked)
    firstCpy = firstCpy->next;
    /*for(int i = 1; i < getSize() - 1; i++)*/
    while(contains(obj) == 1){
      if(firstCpy->info == obj){
	firstCpy->next->prev = firstCpy->prev;
	firstCpy->prev->next = firstCpy->next;
	firstCpy->next = 0;
	firstCpy->prev = 0;
	delete firstCpy;
	firstCpy = first->next;
      }
      else
	firstCpy = firstCpy->next;
    }
    
    firstCpy = first;
  }

}

      

void DList::reverse() {
  //declare variables
  DLNode* head = first;
  DLNode* tail = 0;

  //if the list has more than one element

  if(getSize() > 1){
    while(head){
      head->prev = head->next;
      head->next = tail;
      tail = head;
      head = head->prev;
    }
    head = first;
    tail = last;
    first = tail;
    last = head;
  }
  head = 0;
  tail = 0;
  delete head;
  delete tail;
}

bool DList::contains(string obj) const {
  //Create node pointer to traverse list
  DLNode* firstCpy = first;
  //traverse entire list. If info field is same as obj, return true
  //else return false
  for(int i = 0; i < getSize() -1; i++){
    if(firstCpy->info == obj)
      return true;
    firstCpy = firstCpy->next;
  }
    return false;
}


// DO NOT CHANGE ANYTHING BELOW THIS COMMENT.
// print and rprint are already done.

void DList::print() const {
    DLNode *n = first;
    while (n) {
        std::cout << n->info;
        if (n->next)
            std::cout << ", ";
        n = n->next;
    }
}

void DList::rprint() const {
    DLNode *n = last;
    while (n) {
        std::cout << n->info;
        if (n->prev)
            std::cout << ", ";
        n = n->prev;
    }
}
