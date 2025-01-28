/*******************************************************************************
 * nodePlacement
 ------------------------------------------------------------------------------- 
 * FUNCTION: handles where to place the node by 
 * going through the linked list from head every time
 * its called and using the string compare method
 * @param head ptr to head of linked list
 * @param tail ptr to tail of linked list
 * @param currMovieRec ptr to current node of linked list
 * @param node ptr a node on the linked list
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void nodePlacement(MovieRec* &head, MovieRec* &tail, MovieRec* node, MovieRec* &currMovieRec) {
  bool placed = false;
  // node = head so we don't mess with head when not wanting to 
  node = head;
  while (!placed) {
    // PROCCESSING - if obj.name first character is lower in the ascii table
    // then place in front node
    if (currMovieRec->movieTitle.compare(node->movieTitle) < 0) {
      placed = true;
      // PROCCESSING - if front of node is null 
      if (node->prev == nullptr) {
        placeMovieRecFront(head, currMovieRec, node);
      }else {
        insertMovieRec(node, currMovieRec);
      }
    }else if (node->next == nullptr) { // currMovieRec is bigger than all names
      placeMovieRecBack(tail, currMovieRec, node);
      placed = true;
    }else {
      node = node->next;// move through list
    }
  }
}