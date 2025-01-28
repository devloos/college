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

void displayList(MovieRec* &head) {
  // counter for output
  int count = 1;
  MovieRec* node = head;

  displayHeader();
  // if list is not empty then displayHeader
  while (node != nullptr) {
    std::cout << std::right;
    std::cout << std::setw(4) << count;
    std::cout << std::left;
    std::cout << "    " << std::setw(28) << node->movieTitle << std::setw(9);
    std::cout << node->genre << std::setw(4) << node->releaseYear << "\n";
    ++count;
    node = node->next;
  }
  std::cout << "\n";
}