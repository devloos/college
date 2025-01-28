/*******************************************************************************
 * createList
 -------------------------------------------------------------------------------
 * FUNCTION: takes in head and tail and creates linked
 * list handles the calling of readInput and node
 * placement runs until end of file
 * @param head ptr to head of linked list 
 * @param tail ptr to tail of linked list 
 * RETURNS: void
 ******************************************************************************/
#include "../../include/header.h"

void createList(Node* &head, Node* &tail) {
  // Creating input file
  std::fstream inFile;
  inFile.open("inFile.txt", std::ios::in);

  if (!inFile.eof()) {
    // New Node getting allocated in the heap
    Node* node = new Node;
    // node gets assigned to tail and tail gets assigned to head
    head = tail = node;
    // PROCCESSING - reading input from file to node
    readInput(node, inFile); 
    
    Node* currNode = nullptr;
    while (!inFile.eof()) {
      currNode = new Node;
      readInput(currNode, inFile);
      // PROCCESSING - current node placement being handled
      handleNodePlacement(head, tail, node, currNode);
    }
  }
  std::cout << "\n";
  inFile.close();
}