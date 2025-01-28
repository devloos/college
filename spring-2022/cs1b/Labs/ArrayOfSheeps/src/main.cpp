#include "../include/header.h"
#include "../include/Sheep.h"
#include "../include/SheepList.h"
#include "../include/SheepLinkedList.h"

/*******************************************************************************
 * AUTHOR      : Carlos Aguilera
 * STUDENT ID  : 1152562
 * LAB #       : 
 * CLASS       : CS1B
 * SECTION     : M-W
 * DUE DATE    : 
 ******************************************************************************/

/******************************************************************************
 * Title:
 * ----------------------------------------------------------------------------
 * PROGRAM:
 * 
 * ----------------------------------------------------------------------------
 ******************************************************************************/

int main() {
  headerClass();
  SheepList sheepList;
  // SheepLinkedList sheepList;
  unsigned int n, age;
  Menu choice = Exit;
  std::string name;
  do {
    menu();
    validateInt(n, true, 0, 6);
    choice = Menu(n);
    switch (choice) {
      case Exit: {
        break;
      }
      case AddSheep: {
        std::cout << "\nSheep Name: ";
        std::cin.ignore(1000, '\n');
        std::getline(std::cin, name);
        std::cout << "Sheep Age: ";
        validateInt(age, false, 1, 9);
        Sheep newSheep(name, age);
        sheepList.addSheep(newSheep);
        // sheepList.addSheep(name, age);
        break;
      }
      case FirstSheep: {
        sheepList.firstSheep();
        break;
      }
      case FindSheep: {
        if (sheepList.size() > 0) {
          std::cout << "\nWho are you looking for? ";
          std::cin.ignore(1000, '\n');
          std::getline(std::cin, name);
          if (!sheepList.find(name))
            std::cout << "Sheep not found\n";
        } else {
          std::cout << "\nThere are no sheep to be found!\n";
        }
        break;
      }
      case ListSize: {
        std::cout << "\nThere are " << sheepList.size() << " sheep in the list!\n"; 
        break;
      }
      case OutputList: {
        std::cout << sheepList << "\n";
        break;
      }
      case ClearList: {
        sheepList.clear();
        break;
      }
      default: {
        break;
      }
    }
  } while (choice != Exit);
  return 0;
}