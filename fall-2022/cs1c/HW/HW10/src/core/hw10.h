#pragma once
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Ctors {
 public:
  Ctors();
  Ctors(const std::string &value);
  Ctors(std::string &&value);
  Ctors(const Ctors &other);
  Ctors(Ctors &&other) noexcept;
  ~Ctors() noexcept;

 public:
  Ctors &operator=(const Ctors &other);
  Ctors &operator=(Ctors &&other) noexcept;
  friend Ctors operator+(const Ctors &arg1, const Ctors &arg2);
  friend std::ostream &operator<<(std::ostream &os, const Ctors &obj);

  // Not sure if this is what you wanted
  // i am assuming so since i am passing
  // two params in
  friend Ctors add(const Ctors &arg1, const Ctors &arg2);

 private:
  int id_ = 0;
  static int idGen_s;
  std::string* tptr_ = nullptr;
  static int inst_s;  // keep track of instances
};

void printval(Ctors value);
void printref(const Ctors &ref);
void printmov(Ctors &&move);