#include "../../include/header.h"

std::istream &operator>>(std::istream &is, MenuOption &choice) {
  int data;
  is >> data;
  choice = MenuOption(data);
  return is;
}

int validation(int choice, const MenuOption &menuOption, const int MIN, const int MAX,
               const std::string &option, const bool &initialized) {
  bool validated = false;
  do {
    try{
      if (menuOption == ChangeAge || menuOption == ChangeValue) {
        printSetMenu(option);
      }else if (menuOption == InitAnimals) {
        printMenu(initialized);
      }else if (menuOption == NEW) {
        std::cout << "NEW " << option << ": ";
      }
      if (menuOption != Menu) {
        std::cin >> choice;
        std::cin.ignore(1000, '\n');
      }
      if (std::cin.fail()) {
        throw true;
      }
      validated = true;
    } catch(bool invalid) {
      std::cout << "\n**** Please enter a NUMBER between " << MIN << " and ";
      std::cout << MAX << " ****\n";
      std::cin.clear();
      std::cin.ignore(1000, '\n');
    }
  }while (!validated);
  return choice;
}

float floatValidation(const MenuOption &menuOption, const int MIN, const int MAX,
               const std::string &option, const bool &initialized) {
  float choice;
  bool validated = false;
  do {
    try{
      if (menuOption == ChangeAge || menuOption == ChangeValue) {
        printSetMenu(option);
      }else if (menuOption == InitAnimals) {
        printMenu(initialized);
      }else {
        std::cout << "\nNEW " << option << ": ";
      }
      std::cin >> choice;
      std::cin.ignore(1000, '\n');
      if (std::cin.fail()) {
        throw true;
      }
      validated = true;
    } catch(bool invalid) {
      std::cout << "\n**** Please enter a NUMBER between " << MIN << " and ";
      std::cout << MAX << " ****\n";
      std::cin.clear();
      std::cin.ignore(1000, '\n');
    }
  }while (!validated);
  return choice;
}

void validateChar(char &init) {
  bool validated = false;
  do {
    try{
      std::cout << "Are you sure you want to reinitialize (Y/N)? ";
      std::cin.get(init);
      std::cin.ignore(1000, '\n');
      if (toupper(init) != 'Y' && toupper(init) != 'N') {
        throw true;
      }
      validated = true;
    } catch(bool invalid) {
      std::cout << "\n**** " << init << " is an invalid entry ****\n";
      std::cout << "**** Please input Y or N ****\n\n";
    }
  }while (!validated);

}