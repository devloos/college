#ifndef MAC_H_
#define MAC_H_
#include <iostream>

#include "Laptop.h"

class Mac : public Laptop {
 public:
  Mac();
  Mac(const Mac &rhs);
  Mac &operator=(const Mac &rhs);
  Mac(Mac &&rhs);
  Mac &operator=(Mac &&rhs);

  void Print() const;
};

#endif  // MAC_H_