#include "../../include/header.h"

long long recursiveFib(long long series) {
  if (series <= 1) {
    return series;
  }
  long long n = recursiveFib(series - 1) + recursiveFib(series - 2);
  std::cout << n << " ";
  return n;
}

void iterativeFib(const int &series) {
  int curr = 0, prev = 1, next = 0;
  std::cout << "[";
  for (int i = 0; i <= series; i++) {
    std::cout << curr << ((i + 1 <= series) ? "," : "");
    next = curr + prev;
    curr = prev;
    prev = next;
  }
  std::cout << "]\n";
}

long long recursiveFibRaw(long long series) {
  if (series <= 1) {
    return series;
  }
  return recursiveFibRaw(series - 1) + recursiveFibRaw(series - 2);
}

void iterativeFibRaw(const int &series) {
  int curr = 0, prev = 1, next = 0;
  for (int i = 0; i <= series; i++) {
    next = curr + prev;
    curr = prev;
    prev = next;
  }
}