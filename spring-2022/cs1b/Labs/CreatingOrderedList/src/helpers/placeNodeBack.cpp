/*******************************************************************************
 * placeNodeBack
 ------------------------------------------------------------------------------- 
 * FUNCTION: this function places current node on the
 * back of the linked list 
 * @param head ptr to head of linked list
 * @param currNode ptr to current node of linked list
 * @param node ptr a node on the linked list
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void placeNodeBack(Node* &tail, Node* &currNode, Node* &node) {
  tail = currNode;
  node->next = tail;
  tail->prev = node;
}