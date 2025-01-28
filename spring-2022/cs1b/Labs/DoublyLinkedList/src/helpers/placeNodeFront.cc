/*******************************************************************************
 * placeMovieRecFront
 ------------------------------------------------------------------------------- 
 * FUNCTION: this function places current node on the
 * front of the linked list 
 * @param head ptr to head of linked list
 * @param currMovieRec ptr to current node of linked list
 * @param node ptr a node on the linked list
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void placeMovieRecFront(MovieRec* &head, MovieRec* &currMovieRec, MovieRec* &node) {
  node->prev = currMovieRec;
  currMovieRec->next = node;
  head = currMovieRec;
}