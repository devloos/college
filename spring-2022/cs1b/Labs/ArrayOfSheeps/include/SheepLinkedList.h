#ifndef SHEEP_LINKED_LIST_H_
#define SHEEP_LINKED_LIST_H_
#include "SheepList.h"

class SheepLinkedList : public SheepList {
 private:
  Sheep* head;
  Sheep* tail;
  friend std::ostream &operator<<(std::ostream &os,
                                  const SheepLinkedList &sheepList);
  void listOneSheep(const Sheep* node) const;
 public:
  SheepLinkedList() : head(nullptr), tail(nullptr) {}
  ~SheepLinkedList();

  void addSheep(const std::string &name, const unsigned int &age);
  void clear();

  bool find(const std::string name) const;
  void firstSheep() const;
};
#endif // SHEEP_LINKED_LIST_H_