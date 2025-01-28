#include "../../include/header.h"

void iterativeFactorial(long long &n) {
  long long nFactored = n;
  std::cout << "[";
  for (int i = 1; i < n; i++) {
    nFactored *= i;
    std::cout << nFactored << ((i + 1 < n) ? ", " : "");
  }
  std::cout << "]\n";
}

long long recursiveFactorial(long long n) {
  if (n == 1) {
    return n;
  }
  n *= recursiveFactorial(n - 1);
  std::cout << n << " ";
  return n;
}

void iterativeFactorialRaw(long long &n) {
  long long nFactorial = n;
  for (int i = 1; i < n; i++) {
    nFactorial *= i;
  }
}

long long recursiveFactorialRaw(long long n) {
  if (n == 1) {
    return n;
  }
  return n * recursiveFactorialRaw(n - 1);
}