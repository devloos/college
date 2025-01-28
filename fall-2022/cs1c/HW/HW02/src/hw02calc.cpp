#include "hw02.h"

bool isPrime(const int &n) {
  int m = n / 2;
  for (int i = 2; i <= m; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
};

int PrimeFactor(const std::array<int, HW_SIZE_OF_ARRAY> &PrimeNumbers, const int &n) {
  for (const auto &el : PrimeNumbers) {
    if (n % el == 0) {
      return el;
    }
  }
  return n;
};