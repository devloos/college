#include "../../include/StackList.h"
#include <iostream>

void StackList::Push(const DVDNode &newDVD) {
  DVDNode* node = new DVDNode;
  if (node != nullptr) {
    *node = newDVD;
    node->next = head;
    head = node;
    ++stackCount;
    return;
  }
  std::cout << "\nERROR: [Allocation of Memory]\n";
}

DVDNode StackList::Pop() {
  if (head == nullptr)
    return DVDNode();
  DVDNode temp = *head;
  DVDNode* node = head;
  head = node->next;
  delete node;
  --stackCount;
  return temp;
}

bool StackList::IsEmpty() const { return (head == nullptr); }
DVDNode StackList::Peek() const { return *head; }
int StackList::Size() const { return stackCount; }