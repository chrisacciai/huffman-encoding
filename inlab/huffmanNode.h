/* Christopher Acciai
 * cga4yc
 * Lab 103
 * huffmanNode.h
 */

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

using namespace std;

class huffmanNode {

 public:

    huffmanNode(int freq, char let);
    
    ~huffmanNode();

    huffmanNode* right;

    huffmanNode* left;

    int frequency;

    char letter;

    bool isLeaf();
    
 private:
    
};

#endif
