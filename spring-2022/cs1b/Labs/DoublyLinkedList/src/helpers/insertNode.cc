/*******************************************************************************
 * insertMovieRec
 ------------------------------------------------------------------------------- 
 * FUNCTION: places current node in between two nodes
 * @param currMovieRec ptr to current node of linked list
 * @param node ptr a node on the linked list
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void insertMovieRec(MovieRec* &node, MovieRec* &currMovieRec) {
  node->prev->next = currMovieRec;
  currMovieRec->prev = node->prev;
  node->prev = currMovieRec;
  currMovieRec->next = node;
}