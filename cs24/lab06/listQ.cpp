// listQ.cpp - implements queue as linked list
// Aaron Chang, Kenneth Toombs. 11/17/2014

#include "listQ.h"

Queue::Queue() : front(0), rear(0), size(0) { }  // IMPLEMENT CONSTRUCTOR

Queue::~Queue() {
  clear();
}

void Queue::enqueue(int n) {
  if(front == 0){
    front = new Node(n);
    rear = front;
  }
  else{
    rear->next = new Node(n);
    rear = rear->next;
  }
  size++;
}

int Queue::dequeue() {
   Node* n = front;
   int data;
    if (isEmpty())
        throw EmptyQueue();
    else if(getSize() == 1){
      data = n->data;
      delete n;
      front = 0;
      rear = 0;
    }
    else{
      front = front->next;
      data = n->data;
      delete n;
    }
    size--;
    return data;
}

void Queue::clear() {
  while(isEmpty() == 0){
    dequeue();
  }
}

bool Queue::isEmpty() const {
  if(front == 0)
    return true;
  return false;
}

bool Queue::isFull() const {
    return false; // done
}

int Queue::getSize() const {
  /* int size = 0;
  Node* n = front; 
  while(n){
    size++;
    n = n-> next;
  }
  return size;
  */
  return size;
}
