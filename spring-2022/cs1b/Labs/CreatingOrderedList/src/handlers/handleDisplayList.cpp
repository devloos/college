/*******************************************************************************
 * handleDisplayList
 ------------------------------------------------------------------------------- 
 * FUNCTION: handles the displaying of all nodes in
 * the linked list by iterating through until node
 * is null
 * @param head ptr to head of linked list
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void handleDisplayList(Node* &head) {
  // counter for output
  int count = 1;
  Node* node = head;

  // if list is not empty then displayHeader
  if (!isListEmpty(node)) {displayHeader();}
  while (node != nullptr) {
    std::cout << std::right;
    std::cout << std::setw(4) << count;
    std::cout << std::left;
    std::cout << "    " << std::setw(30) << node->name << std::setw(7);
    std::cout << node->gender << std::setw(4) << node->age << "\n";
    ++count;
    node = node->next;
  }
  std::cout << "\n";
}