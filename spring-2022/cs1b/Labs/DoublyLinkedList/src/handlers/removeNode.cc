/*******************************************************************************
 * removeMovieRec
 ------------------------------------------------------------------------------- 
 * FUNCTION: handles the removing of a node in any pos
 * this is done by checking whether node.prev or node.
 * next equals null we run a separate function to 
 * remove node 
 * @param head ptr to head of linked list
 * @param tail ptr to tail of linked list
 * @param searchKey key for searching name inputed by
 * user
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void removeMovieRec(MovieRec* &head, MovieRec* &tail, std::string searchKey) {
  MovieRec* node = head;
  std::cout << "\nSearching for " << searchKey << "...\n\n";
  while (node != nullptr) {
    // PROCCESSING - iterate through linked list until found
    if (node->movieTitle == searchKey) {
      // if node was found in head
      if (node->prev == nullptr) {
        head = node->next;
        node->next->prev = nullptr;
      }else if (node->next == nullptr) { // if node was found in tail
        tail = node->prev;
        node->prev->next = nullptr;
      }else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
      }
      std::cout << "Removing " << node->movieTitle << "\n\n";
      delete node;
      return;
    }
    node = node->next;
  }
  // if node was not found
  std::cout << "I'm sorry, \"" << searchKey << "\" was NOT found!\n\n";
  return;
}