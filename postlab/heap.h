/* Christopher Acciai
 * cga4yc
 * Lab 103
 * heap.h
 */

#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "huffmanNode.h"

using namespace std;

class heap {

 public:

    heap();
    
    ~heap();

    void insert(huffmanNode* node);
    
    huffmanNode* findMin();
    
    huffmanNode* deleteMin();
    
    unsigned int size();
    
    void makeEmpty();
    
    bool isEmpty();

    void print();

    vector< huffmanNode* > binHeap;

    huffmanNode* getRoot();
    
 private:
    
    unsigned int heap_size;

    void percolateUp(int hole);
    
    void percolateDown(int hole);
    
};

#endif
