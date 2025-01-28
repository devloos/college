/*******************************************************************************
 * displayMenu
 ------------------------------------------------------------------------------- 
 * FUNCTION: handles the menu display
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void displayMenu() {
  std::cout << std::right;
  std::cout << "LIST MENU:\n";
  std::cout << "1 - Create List\n";
  std::cout << "2 - Display List\n";
  std::cout << "3 - Is the list empty?\n";
  std::cout << "4 - Search by name\n";
  std::cout << "5 - Remove node\n";
  std::cout << "6 - Clear List\n";
  std::cout << "0 - to Exit\n";
  std::cout << std::left;
}