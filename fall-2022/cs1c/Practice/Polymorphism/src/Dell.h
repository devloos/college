#ifndef DELL_H_
#define DELL_H_
#include <iostream>

#include "Laptop.h"

class Dell : public Laptop {
 public:
  Dell();
  Dell(const Dell &rhs);
  Dell &operator=(const Dell &rhs);
  Dell(Dell &&rhs);
  Dell &operator=(Dell &&rhs);

  void Print() const;
};

#endif  // DELL_H_