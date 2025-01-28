#ifndef HEADER_H_
#define HEADER_H_
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "Animal.h"

enum MenuOption {
  Exit = 0,
  InitAnimals,
  ChangeAge,
  ChangeValue,
  Display,
  NEW,
  Menu,
};

void switchLoop(std::vector<Animal> &animals);
float validateFloatBounds(const MenuOption &menuOption, const int MIN, const int MAX,
               const std::string &option, const bool &initialized);
int validation(int choice, const MenuOption &menuOption, const int MIN, const int MAX,
               const std::string &option, const bool &initialized);
int validateBounds(int choice, const MenuOption &menuOption, const int MIN, const int MAX,
               const std::string &option, const bool &initialized);
float floatValidation(const MenuOption &menuOption, const int MIN, const int MAX,
               const std::string &option, const bool &initialized);
void printSetMenu(const std::string &option);
void printMenu(const bool &initialized);
void heading();
void validateChar(char &init);
std::istream& operator>> (std::istream& is, MenuOption& choice);

#endif // HEADER_H_