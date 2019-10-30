/* Christopher Acciai
 * cga4yc
 * Lab 103
 * huffmanNode.cpp
 */

#include <iostream>
#include "huffmanNode.h"
#include <stdlib.h>

using namespace std;

huffmanNode::huffmanNode(int freq, char let) {

  frequency = freq;

  letter = let;

  left = NULL;

  right = NULL;
  
}

huffmanNode::~huffmanNode() {
  
}

bool huffmanNode::isLeaf() {

  return (left != NULL && right != NULL);

}
  
