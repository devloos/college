/*******************************************************************************
 * handleSwitch
 ------------------------------------------------------------------------------- 
 * FUNCTION: handles all movement of choice that the user chooses this is done
 * by a switch case statement
 * @param head ptr to head of linked list
 * @param tail ptr to tail of linked list
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void handleSwitch(Node* &head, Node* &tail) {
  Menu choice = Exit;
  do {
    // PROCCESSING - displayMenu and validateInput
    displayMenu();
    validateInput(choice);
    std::cout << "\n";
    switch (choice) {
      case Exit: {
        break;
      }
      case CreateList: {
        if (head == nullptr) {
          createList(head, tail);
        }else {
          std::cout << "List is already made\n\n";
        }
        break;
      }
      case DisplayList: {
        if (isListEmpty(head)) {
          std::cout << "Can't display an empty list\n\n";
        }else {
          handleDisplayList(head);
        }
        break;
      }
      case IsEmpty: {
        if (isListEmpty(head)) {
          std::cout << "Yes, the list is empty.\n\n";
        }else {
          std::cout << "No, The list is NOT empty.\n\n";
        }
        break;
      }
      case SearchName: {
        std::string searchKey;
        // if list is not empty else
        if (!isListEmpty(head)) {
          std::cout << "Who would you like to search for? ";
          std::cin.ignore(1000, '\n');
          std::getline(std::cin, searchKey);
          // PROCCESSING - returns true if name found
          if (!searchName(head, searchKey)) {
            std::cout << "I'm sorry, \"" << searchKey << "\" was NOT found!\n\n";
          }
        }else {
          std::cout << "Can't search an empty list\n\n";
        }
        break;
      }
      case RemoveNode: {
        std::string searchKey;
        if (!isListEmpty(head)) {
          std::cout << "Who would you like to remove for? ";
          std::cin.ignore(1000, '\n');
          std::getline(std::cin, searchKey);
          removeNode(head, tail, searchKey);
        }else {
          std::cout << "Can't remove from an empty list\n\n";
        }
        break;
      }
      case ClearList: {
        clearList(head, tail);
        break;
      }
      default: {
        // validation for out of bounds
        std::string number;
        number = std::to_string(choice);
        std::cout << std::left;
        std::cout << "**** The number ";
        std::cout << number << " is an invalid entry";
        std::cout << std::right;
        std::cout << std::setw(11 - number.size())
                  << "****\n";
        std::cout << "**** Please input a number between 0 and 6 ****\n\n";
        break;
      }
    }
  } while (choice != Exit);
  return;
}