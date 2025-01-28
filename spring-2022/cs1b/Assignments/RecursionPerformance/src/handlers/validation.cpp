#include "../../include/header.h"

void validation(long long &n) {
  bool validated = false;
  do {
    try {
      std::cin >> n;
      if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        throw true;
      }else if (n < 0) {
        std::cout << "Enter positive number!\n";
        std::cout << "Try Again: ";
        continue;
      }
      validated = true;
      return;
    }catch(bool invalid) {
      std::cout << "Please enter a NUMBER!\n";
      std::cout << "Try Again: ";
    }
  }while (!validated);
}