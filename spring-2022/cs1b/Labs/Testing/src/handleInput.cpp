#include "../include/main.h"
/****************************************************************************
 * Title: handelInput
 * --------------------------------------------------------------------------
 * FUNCTION:
 *    this function handles input from the user and validates it if needed
 *    I use a try catch for the validation
 * --------------------------------------------------------------------------
 * Data Table
 * ----------
 * bool inputValidated CALC - bool to say if input is validated or not
 ***************************************************************************/


void handleInput(size_t &numOfSheeps, size_t &numOfChocolateBars) {
   bool inputValidated = false;
   std::cout << "\n";
   do {
      try {
         std::cout << "Enter number of Sheep: ";
         std::cin >> numOfSheeps;
         if (std::cin.fail()) {//if cin failed meaining if they put something invalid we clear cin and throw true and catch it 
            std::cin.clear();
            std::cin.ignore(10, '\n');
            throw(true);
         }
         std::cout << "Enter number of Chocolate Bars: ";
         std::cin >> numOfChocolateBars;
         if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10, '\n');
            throw(true);
         }
         inputValidated = true;
      }
      catch(bool invalid) {
         std::cout << "Input was invalid try again!!\n";
      }
   }while(!inputValidated);
}

