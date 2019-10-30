/* Christopher Acciai
 * cga4yc
 * Lab 103
 * huffmanenc.cpp
 */

#include <iostream>
#include <stdlib.h>
#include "heap.h"
#include <ctype.h>
#include "huffmanNode.h"
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#include <stdio.h>

heap* buildTree(heap *minHeap) {

    while(minHeap->size() != 1) {

      huffmanNode* left = minHeap->deleteMin();
      huffmanNode* right = minHeap->deleteMin();

      huffmanNode* parent = new huffmanNode(left->frequency + right->frequency, '/');

      parent->left = left;
      parent->right = right;

      minHeap->insert(parent);
      
    }
    return minHeap;
}

void getCode(huffmanNode* node, string code, map<char, string> &huffCode) {

  if (node == NULL)
    return;

  if (!node->left && !node->right) {
    
    huffCode[node->letter] = code;
    
  }

  getCode(node->left, code + "0", huffCode);
  getCode(node->right, code + "1", huffCode);
    
}


int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }
    
    FILE *fp = fopen(argv[1], "r");

    if ( fp == NULL ) {
        cout << "File '" << argv[1] << "' does not exist!" << endl;
        exit(2);
    }

    //get the frequencies
    
    char g;

    vector<char> letters;

    vector<char> message;

    int freq[95] = {0};
    
    while ( (g = fgetc(fp)) != EOF ) {

        if (g >= ' ' && g <= '~') {
	  
	  freq[g - ' ']++;

	if (find(letters.begin(), letters.end(), g) == letters.end()) {

	  letters.push_back(g);
        }
      }
    }

    heap *minHeap = new heap();

    for (int i = 0; i < letters.size(); i++) {

      huffmanNode* temp = new huffmanNode(freq[letters.at(i) - ' '], letters.at(i));

      minHeap->insert(temp);

    }

    //build the prefix huffman tree

    heap* huffmanTree = buildTree(minHeap);

    //get codes of each char

    map<char, string> huffCode;

    getCode(huffmanTree->findMin(), "", huffCode);

    //print out each pair in map of char w/ respective code

    for (map<char, string>::iterator it = huffCode.begin(); it != huffCode.end(); ++it) {

      if (it->first == ' ') {
	cout << "space" << " " << it->second << endl;
      }
      else {
	cout << it->first << " " << it->second << endl;
      }
    }

     
    // a nice pretty separator
    cout << "----------------------------------------" << endl;

    string compBits;

    for (int i = 0; i < message.size(); i++) {

      map<char, string>::iterator it = huffCode.find(message.at(i));

      if (it->first) {
	cout << it->second << " ";
      }

      //get number of compressed bits

      compBits = compBits + it->second;
    }

    cout <<endl;
      

    cout << "----------------------------------------" << endl;

    cout << "There are a total of "<< message.size() <<" symbols that are encoded." << endl;
    cout << "There are "<< letters.size() <<" distinct symbols used." << endl;

    //calc number of bits

    int bits = message.size() * 8;
    
    cout << "There were "<< bits <<" bits in the original file." << endl;

    cout << "There were "<< compBits.length() <<" bits in the compressed file." << endl;

    float ratio =  bits/(float)compBits.length();
    
    cout << "This gives a compression ratio of "<< ratio <<"." << endl;

    float cost =  compBits.length()/(float)message.size();

    cout << "The cost of the Huffman tree is "<< cost <<" bits per character." << endl;

    
    // rewinds the file pointer, so that it starts reading the file
    // again from the begnning
    rewind(fp);
    // read the file again, and print to the screen
    while ( (g = fgetc(fp)) != EOF ) {
      //    cout << g;
    // close the file
    fclose(fp);
    }
}
