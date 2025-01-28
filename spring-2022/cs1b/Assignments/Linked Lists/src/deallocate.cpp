#include "../include/header.h"

void deallocate(DVD* head) {
   DVD* node = head;
   while(node != NULL) {
      head = node->nextNode;
      delete node;
      node = head;
   }
}