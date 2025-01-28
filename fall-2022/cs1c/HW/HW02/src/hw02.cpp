/*
 * AUTHOR: Carlos Aguilera
 * CLASS: CS1C
 * DATE: 09/06/22
 * ASIGNMENT: HW02 (PRIME NUMBERS)
 */

#include "hw02.h"

int main() {
  std::array<int, HW_SIZE_OF_ARRAY> PrimeNumbers;

  int CurrentSize = 0;
  for (int i = 2; CurrentSize < HW_SIZE_OF_ARRAY; i++) {
    if (isPrime(i)) {
      PrimeNumbers[CurrentSize] = i;
      ++CurrentSize;
    }
  }

  long n = 0;

  input(n);
  print(PrimeNumbers, n);
  return 0;
}
