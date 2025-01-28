/*******************************************************************************
 * insertNode
 ------------------------------------------------------------------------------- 
 * FUNCTION: places current node in between two nodes
 * @param currNode ptr to current node of linked list
 * @param node ptr a node on the linked list
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void insertNode(Node* &node, Node* &currNode) {
  node->prev->next = currNode;
  currNode->prev = node->prev;
  node->prev = currNode;
  currNode->next = node;
}