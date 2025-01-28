/*******************************************************************************
 * isListEmpty
 ------------------------------------------------------------------------------- 
 * FUNCTION: returns true if list is empty else false
 * this is done by checking if head is null
 * @param head ptr to head of linked list
 * RETURNS - bool
 ******************************************************************************/
#include "../../include/header.h"

bool isListEmpty(Node* &head) {
  return (head == nullptr);
}