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
  std::cout << "1 - Add Movie\n";
  std::cout << "2 - Remove Movie\n";
  std::cout << "3 - Display List\n";
  std::cout << "0 - to Exit\n";
  std::cout << std::left;
}