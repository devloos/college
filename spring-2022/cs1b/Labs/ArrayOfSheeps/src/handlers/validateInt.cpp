#include "../../include/header.h"

void validateInt(unsigned int &choice, const bool &isMenu, const int MIN,
                 const int MAX) {
  bool validated = false;
  do {
    try {
      std::cin >> choice;
      if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        throw true;
      }
      if (choice < MIN || choice > MAX) {
        if (!isMenu)
          throw true;
        std::string n = std::to_string(choice);
        std::cout << std::left;
        std::cout << "\n**** The number " << n << std::setw(27 - n.size());
        std::cout << " is an invalid entry" << "****\n";
        std::cout << "**** Please input a number between " << MIN << " and ";
        std::cout << MAX << " ****\n";
        std::cout << std::right;
      }
      validated = true;
    } catch (bool invalid) {
      std::cout << "\n**** Enter a NUMBER between " << MIN << " and " << MAX;
      std::cout << " ****\n";
      if (isMenu) {
        menu();
      } else {
        std::cout << "\nSheep Age: ";
      }
    }
  } while (!validated);
}