/*******************************************************************************
 * handleNodePlacement
 ------------------------------------------------------------------------------- 
 * FUNCTION: handles where to place the node by 
 * going through the linked list from head every time
 * its called and using the string compare method
 * @param head ptr to head of linked list
 * @param tail ptr to tail of linked list
 * @param currNode ptr to current node of linked list
 * @param node ptr a node on the linked list
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void handleNodePlacement(Node* &head, Node* &tail, Node* &node, Node* &currNode) {
  bool placed = false;
  // node = head so we don't mess with head when not wanting to 
  node = head;
  while (!placed) {
    // PROCCESSING - if obj.name first character is lower in the ascii table
    // then place in front node
    if (currNode->name.compare(node->name) < 0) {
      placed = true;
      // PROCCESSING - if front of node is null 
      if (node->prev == nullptr) {
        placeNodeFront(head, currNode, node);
      }else {
        insertNode(node, currNode);
      }
    }else if (node->next == nullptr) { // currNode is bigger than all names
      placeNodeBack(tail, currNode, node);
      placed = true;
    }else {
      node = node->next;// move through list
    }
  }
}