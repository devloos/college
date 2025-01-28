/*******************************************************************************
 * validateInput
 ------------------------------------------------------------------------------- 
 * FUNCTION: handles the validation on input of Menu
 * choice this is accomplished by a try catch method
 * that uses a .fail as its way of knowing if cin
 * failed
 * @param choice enum of Menu used for switch case
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void validateInput(Choice &choice) {
  int n; // take in an int... instead of overloading the extraction operator
  bool valid = false;
  do {
    try {
      std::cout << "Enter a command (0 to exit): ";
      std::cin >> n;
      // PROCCESSING - if cin.fail then we throw an execption
      if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        throw true;
      }
      // static cast to an Menu to store in choice
      choice = static_cast<Choice>(n);
      valid = true;
    }catch (bool invalid) {
      std::cout << "**** Please input a NUMBER between 0 and 3 ****\n";
    }
  } while (!valid);
  return;
}