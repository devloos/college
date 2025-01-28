#ifndef HW06_H_
#define HW06_H_
#include <stdlib.h>

#include <iostream>
#include <numeric>
#include <string>

#include "../utility/utility.h"

struct Vector2 {
 public:
  int num_;
  int den_;

 public:
  Vector2();
  Vector2(const int &num, const int &den);
};

class Fraction {
 private:
  int num_;
  int den_;

 public:
  Fraction();
  Fraction(const int &num, const int den);
  ~Fraction() noexcept;

 private:
  friend std::istream &operator>>(std::istream &is, Fraction &frac);
  friend std::ostream &operator<<(std::ostream &os, const Fraction &frac);

  // Arithmetic Operations
  friend Fraction operator*(const Fraction &lhs, const Fraction &rhs);
  friend Fraction operator/(const Fraction &lhs, const Fraction &rhs);
  friend Fraction operator-(const Fraction &lhs, const Fraction &rhs);
  friend Fraction operator+(const Fraction &lhs, const Fraction &rhs);

  // Relational Operations
  friend bool operator<(const Fraction &lhs, const Fraction &rhs);
  friend bool operator<=(const Fraction &lhs, const Fraction &rhs);
  friend bool operator>(const Fraction &lhs, const Fraction &rhs);
  friend bool operator>=(const Fraction &lhs, const Fraction &rhs);
  friend bool operator==(const Fraction &lhs, const Fraction &rhs);
  friend bool operator!=(const Fraction &lhs, const Fraction &rhs);

 public:
  // Self Arithmetic Operations
  Fraction &operator*=(const Fraction &rhs);
  Fraction &operator/=(const Fraction &rhs);
  Fraction &operator-=(const Fraction &rhs);
  Fraction &operator+=(const Fraction &rhs);

 private:
  Vector2 parse(std::string &dirty);
  void setGCD();

 public:
  void setFrac(const int &num, const int &den);
  Fraction getFrac() const;
};

#endif  // HW06_H_
