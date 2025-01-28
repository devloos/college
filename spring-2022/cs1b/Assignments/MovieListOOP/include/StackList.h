#ifndef STACKLIST_H_
#define STACKLIST_H_
#include "DVDnode.h"

class StackList {             
 public: 
  StackList () : head(nullptr), tail(nullptr), stackCount(0) {}
  ~StackList () {}

  void Push(const DVDNode &newDVD);  
  DVDNode Pop();              

  bool IsEmpty() const;       
  DVDNode Peek() const;       
  int Size() const;           
 protected: 
  DVDNode *head;              
  DVDNode *tail;
  int stackCount;             
};

#endif // STACKLIST_H_