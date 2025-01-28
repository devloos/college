#include "hw02.h"

void print(const std::array<int, HW_SIZE_OF_ARRAY> &PrimeNumbers, const long int &n) {
  if (isPrime(n)) {
    std::cout << "The number: " << n << " is a prime number!\n";
  } else {
    std::cout << "The number: " << n << " is not a prime number!\n";
    std::cout << "The first Prime Factor is: " << PrimeFactor(PrimeNumbers, n) << "!\n";
  }
}