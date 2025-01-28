#include "../../include/header.h"

int validateBounds(int choice, const MenuOption &menuOption, const int MIN, const int MAX,
               const std::string &option, const bool &initialized) {
  int validate;
  do {
    validate = validation(choice, menuOption, MIN, MAX, option, initialized);
    if (validate < MIN || validate > MAX) {
      std::cout << "\n**** The number " << validate << " is an invalid entry ****\n";
      std::cout << "**** Please input a number between " << MIN << " and " << MAX << " ****\n\n";
      if (menuOption == Menu)
        return 0;
    }
  } while (validate < MIN || validate > MAX);
  return validate;
}

float validateFloatBounds(const MenuOption &menuOption, const int MIN, const int MAX,
               const std::string &option, const bool &initialized) {
  float validate;
  do {
    validate = validation(0, menuOption, MIN, MAX, option, initialized);
    if (validate < MIN || validate > MAX) {
      std::cout << "\n**** The number " << validate << " is an invalid entry ****\n";
      std::cout << "**** Please input a number between " << MIN << " and " << MAX << " ****\n\n";
    }
  } while (validate < MIN || validate > MAX);
  return validate;
}