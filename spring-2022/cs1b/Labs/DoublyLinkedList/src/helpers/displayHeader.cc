/*******************************************************************************
 * displayHeader
 ------------------------------------------------------------------------------- 
 * FUNCTION: displays header for the displayList
 * function
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void displayHeader() {
  std::cout << std::left
            << "   " << std::setw(5) << "#" << std::setw(28) << "NAME"
            << std::setw(9) << "GENRE" << std::setw(4) << "YEAR\n"
            << "-------" << " -------------------------" << "  --------" 
            << " -----\n" << std::right;
}