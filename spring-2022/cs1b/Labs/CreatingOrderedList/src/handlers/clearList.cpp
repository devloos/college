/*******************************************************************************
 * clearList
 ------------------------------------------------------------------------------- 
 * FUNCTION: handles the clearing of linked list this
 * is also used for my deallocation at the end of prog
 * if list is not empty
 * @param head ptr to head of linked list
 * @param tail ptr to tail of linked list
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void clearList(Node* &head, Node* &tail) {
  Node* node = head;
  // PROCCESSING - if list is already cleared
  if (isListEmpty(node)) {
    std::cout << "The list has been cleared!\n\n";
    return;
  }
  std::cout << "CLEARING LIST:\n";
  while (node != nullptr) {
    std::cout << "Removing " << node->name << "!\n";
    // Handling the removal of nodes and also making sure everything points to
    // null
    head->prev = nullptr;
    head = node->next;
    delete node;
    node = head;
  }
  tail = nullptr;
  std::cout << "\nThe list has been cleared!\n\n";
}