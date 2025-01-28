#include "hw02.h"

void input(long &n) {
  const long MAX_RANGE = 100000000;
  const long MIN_RANGE = 2;
  bool Validated = false;

  std::cout << "CALCULATE PRIME NUMBER\n";
  std::cout << "----------------------\n\n";
  do {
    try {
      std::cout << "Enter Number: ";
      std::cin >> n;
      if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::string("\nINPUT FAILED PLEASE ENTER LONG INT\n\n");
      }
      if (n < MIN_RANGE || n > MAX_RANGE)
        throw std::string("\nLONG INT NOT WITHIN BOUNDARY!\n\n");
      Validated = true;
    } catch (const std::string &err) {
      std::cerr << err;
    }
  } while (!Validated);
}