// arrayQ.cpp - implements queue as array
// NAME(S), DATE

#include "arrayQ.h"

Queue::Queue() { }  // IMPLEMENT CONSTRUCTOR

void Queue::enqueue(int n) {
    if (isFull())
        throw FullQueue();

    // COMPLETE THIS IMPLEMENTATION
}

int Queue::dequeue() {
    if (isEmpty())
        throw EmptyQueue();

    // COMPLETE THIS IMPLEMENTATION
    return 0; // AND REPLACE THIS RETURN STATEMENT
}

void Queue::clear() {
    // IMPLEMENT
}

bool Queue::isEmpty() const {
    // IMPLEMENT
    return true; // AND REPLACE THIS RETURN STATEMENT
}

bool Queue::isFull() const {
    // IMPLEMENT
    return false; // AND REPLACE THIS RETURN STATEMENT
}

int Queue::getSize() const {
    // IMPLEMENT
    return 0; // AND REPLACE THIS RETURN STATEMENT
}
