/*******************************************************************************
 * searchName
 ------------------------------------------------------------------------------- 
 * FUNCTION: searches linked list with key and returns
 * true if found else, this is done by iterating 
 * through linked list until null and comparing string
 * by string
 * @param head ptr to head of linked list
 * @param searchKey key for searching name inputed by
 * user
 * RETURNS - bool
 ******************************************************************************/
#include "../../include/header.h"

bool searchName(Node* &head, std::string searchKey) {
  Node* node = head;
  std::cout << "\nSearching for " << searchKey << "...\n\n";
  while (node != nullptr) {
    // PROCCESSING - iterate through linked list until found
    if (node->name == searchKey) {
      std::cout << std::left;
      std::cout << std::setw(10) << "Name:" << node->name << "\n";
      std::cout << std::setw(10) << "Gender:" << node->gender << "\n";
      std::cout << std::setw(10) << "Age:" << node->age << "\n\n";
      std::cout << std::right;
      return true;
    }
    node = node->next;
  }
  // if it was not found return false
  return false;
}