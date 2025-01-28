/*******************************************************************************
 * placeNodeFront
 ------------------------------------------------------------------------------- 
 * FUNCTION: this function places current node on the
 * front of the linked list 
 * @param head ptr to head of linked list
 * @param currNode ptr to current node of linked list
 * @param node ptr a node on the linked list
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void placeNodeFront(Node* &head, Node* &currNode, Node* &node) {
  node->prev = currNode;
  currNode->next = node;
  head = currNode;
}