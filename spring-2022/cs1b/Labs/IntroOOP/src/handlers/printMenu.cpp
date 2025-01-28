#include "../../include/header.h"

void printMenu(const bool &initialized) {
  std::cout << "\n1 - Initialize Animals\n";
  if (initialized) {
    std::cout << "2 - Change Age\n";
    std::cout << "3 - Change Value\n";
    std::cout << "4 - Display Animals\n";
  }
  std::cout << "0 - Exit\n";
  std::cout << "Enter Selection: ";
  return;
}