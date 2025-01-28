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

void createList(MovieRec* &head, MovieRec* &tail) {
  // Creating input file
  std::fstream inFile;
  inFile.open("inFile.txt", std::ios::in);

  if (!inFile.eof()) {
    // New MovieRec getting allocated in the heap
    MovieRec* node = new MovieRec;
    // node gets assigned to tail and tail gets assigned to head
    head = tail = node;
    // PROCCESSING - reading input from file to node
    readInput(node, inFile); 
    
    MovieRec* currMovieRec = nullptr;
    while (!inFile.eof()) {
      currMovieRec = new MovieRec;
      readInput(currMovieRec, inFile);
      // PROCCESSING - current node placement being handled
      nodePlacement(head, tail, node, currMovieRec);
    }
  }
  std::cout << "\n";
  inFile.close();
}