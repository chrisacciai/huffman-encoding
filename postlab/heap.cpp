/* Christopher Acciai
 * cga4yc
 * Lab 103
 * heap.cpp
 */

#include "heap.h"
#include <iostream>

using namespace std;

// default constructor
heap::heap() : heap_size(0) {
  
  binHeap.push_back(0);
}

// the destructor doesn't need to do much
heap::~heap() {
}

void heap::insert(huffmanNode* node) {
    // a vector push_back will resize as necessary
    binHeap.push_back(node);
    // move it up into the right position
    percolateUp(++heap_size);
}

void heap::percolateUp(int hole) {
    // get the value just inserted
    int x = binHeap[hole]->frequency;
    huffmanNode* temp = binHeap[hole]; 
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (x < binHeap[hole/2]->frequency); hole /= 2 )
        binHeap[hole] = binHeap[hole/2]; // move the parent down
    // correct position found!  insert at that spot
    binHeap[hole] = temp;
}

huffmanNode* heap::deleteMin() {
    // make sure the heap is not empty
    if ( heap_size == 0 )
        throw "deleteMin() called on empty heap";
    // save the value to be returned
    huffmanNode* ret = binHeap[1];
    // move the last inserted position into the root
    binHeap[1] = binHeap[heap_size--];
    // make sure the vector knows that there is one less element
    binHeap.pop_back();
    // percolate the root down to the proper position
    percolateDown(1);
    // return the old root node
    return ret;
}

void heap::percolateDown(int hole) {
    // get the value to percolate down
    int x = binHeap[hole]->frequency;
    huffmanNode* temp = binHeap[hole];
    // while there is a left child...
    while ( hole*2 <= heap_size ) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ( (child+1 <= heap_size) && (binHeap[child+1]->frequency < binHeap[child]->frequency) )
            child++;
        // if the child is greater than the node...
        if ( x > binHeap[child]->frequency) {
            binHeap[hole] = binHeap[child]; // move child up
            hole = child;             // move hole down
        } else
            break;
    }
    // correct position found!  insert at that spot
    binHeap[hole] = temp;
}

huffmanNode* heap::findMin() {
    if ( heap_size == 0 )
        throw "findMin() called on empty heap";
    return binHeap[1];
}

unsigned int heap::size() {
    return heap_size;
}

void heap::makeEmpty() {
    heap_size = 0;
    binHeap.resize(1);
}

bool heap::isEmpty() {
    return heap_size == 0;
}

huffmanNode* heap::getRoot() {
    if ( heap_size == 0 )
        throw "findMin() called on empty heap";
    return binHeap[1];
}

void heap::print() {
    cout << "(" << binHeap[0]<< "," << binHeap[0] << ") ";
    for ( int i = 1; i <= heap_size; i++ ) {
        cout << binHeap[i] << binHeap[i] << " ";
        // next line from from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if ( isPow2 )
            cout << endl << "\t";
    }
    cout << endl;
}

