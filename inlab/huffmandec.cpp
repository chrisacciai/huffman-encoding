/* Christopher Acciai
 * cga4yc
 * Lab 103
 * huffmandec.cpp
 */


// This program is the skeleton code for the lab 10 in-lab.  It uses
// C++ streams for the file input, and just prints out the data when
// read in from the file.

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "huffmanNode.h"

using namespace std;

void buildTree(huffmanNode* node ,string character, string prefix) {

  if (prefix.length() == 0) {
    
    node->letter = character[0];
    
  }
  else {

    if (prefix[0] == '0') {

      if (node->left == NULL) {

	node->left = new huffmanNode(0, '/');
	
        }

	node = node->left;

     }
      
     if (prefix[0] == '1') {

       if (node->right == NULL) {

	  node->right = new huffmanNode(0, '/');

	  }

	  node = node->right;

      }

      prefix = prefix.substr (1, prefix.length());
      buildTree(node, character, prefix);

   }
}

void traverse(huffmanNode* node, string& huffbits, string& decodedMessage) {

  if (node->left == NULL & node->right == NULL) {

    decodedMessage = decodedMessage + node->letter;
    
  }
  else {
    
    if (huffbits[0] == '0') {

      if (node->left == NULL) {
	cout << "error missing left" << endl;
      }
      else {
	node = node->left;
      }
    }
    if (huffbits[0] == '1') {
      if (node->right == NULL) {
	cout << "error missing right" << endl;
      }
      else {
	node = node->right;
      }
    }
    
    huffbits = huffbits.substr(1, huffbits.length());
    traverse(node, huffbits, decodedMessage);
  }
}

// main(): we want to use parameters
int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file; must be opened in binary
    // mode, as otherwise whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    
    // read in the first section of the file: the prefix codes
    huffmanNode* root = new huffmanNode(0, '/');
    
    while ( true ) {
        string character, prefix;
        // read in the first token on the line
        file >> character;
        // did we hit the separator?
        if ( (character[0] == '-') && (character.length() > 1) )
            break;
        // check for space
        if ( character == "space" )
            character = " ";
        // read in the prefix code
        file >> prefix;
        // do something with the prefix code
        cout << "character '" << character << "' has prefix code '"
             << prefix << "'" << endl;

	buildTree(root, character, prefix);
    }
    // read in the second section of the file: the encoded message
    stringstream sstm;
    while ( true ) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if ( bits[0] == '-' )
            break;
        // add it to the stringstream
        sstm << bits;
    }
    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    cout << "All the bits: " << allbits << endl;

    string decodedMessage = "";

    cout <<"----------------------------" << endl;

    while (allbits.length() > 0) {
      traverse(root, allbits, decodedMessage);
    }

    cout <<"Decoded Message: "<< decodedMessage << endl;

    
    // close the file before exiting  
    file.close();

    
    
}
