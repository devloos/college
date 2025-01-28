#ifndef LAPTOP_H_
#define LAPTOP_H_
#include <iostream>

class Laptop {
 public:
  Laptop();
  Laptop(const Laptop &rhs);
  Laptop &operator=(const Laptop &rhs);
  Laptop(Laptop &&rhs);
  Laptop &operator=(Laptop &&rhs);

  void Print() const;
};

#endif  // LAPTOP_H_