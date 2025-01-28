/*******************************************************************************
 * placeMovieRecBack
 ------------------------------------------------------------------------------- 
 * FUNCTION: this function places current node on the
 * back of the linked list 
 * @param head ptr to head of linked list
 * @param currMovieRec ptr to current node of linked list
 * @param node ptr a node on the linked list
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void placeMovieRecBack(MovieRec* &tail, MovieRec* &currMovieRec, MovieRec* &node) {
  tail = currMovieRec;
  node->next = tail;
  tail->prev = node;
}
