#include "../include/header.h"
/****************************************************************************
 * Title: validateInput
 * --------------------------------------------------------------------------
 * FUNCTION:
 *    This is an input validation function it handles all major validations
 * from the switch statement, year, and rating validation
 * --------------------------------------------------------------------------
 * Data Table
 * ----------
 * bool inputValidated = false; CALC - to determine if input was validated
 * int choice; IN & CALC - input choice and verify if its valid
 ***************************************************************************/

MenuOptions switchValidation() {
   int choice;
   bool inputValidated = false;
   //try catch wrapped in a do while until input is validated
   do {
      try {
         std::cout << "Enter an option (0 to exit): ";
         std::cin >> choice;
         if (std::cin.fail()) {//if cin fails throw expection
            std::cin.clear();//clears buffer for next cin 
            std::cin.ignore(10, '\n');
            throw(true);
         }
         inputValidated = true;
      }
      catch(bool invalid) {
         std::cout << "Please enter a number!\n";
      }
   } while (!inputValidated);
   
   return static_cast <MenuOptions> (choice);//returns int but static cast to enum MenuOptions
}

void yearValidation(int &keyInt) {
   bool inputValidated = false;
   do {
      try {
         std::cout << "\nWhich year are you looking for? ";
         std::cin >> keyInt;
         if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            throw(true);
         }else if (keyInt >= 1878 && keyInt <= 3000)//if key is valid and its betweens years then 
            inputValidated = true;
         else {
            std::cout << "The number " << keyInt << " is an invalid entry\n";
            std::cout << "**** Please input a number between 1878 and 3000 ****\n";
         }
      }
      catch(bool invalid) {
         std::cout << "**** Please input a NUMBER between 1878 and 3000 ****\n";
      }
   } while (!inputValidated);
}

void ratingValidation(int &keyInt) {
   bool inputValidated = false;
   do {
      try {
         std::cout << "\nWhich rating are you looking for? ";
         std::cin >> keyInt;
         if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            throw(true);
         }else if (keyInt >= 0 && keyInt <= 9)
            inputValidated = true;
         else {
            std::cout << "The number " << keyInt << " is an invalid entry\n";
            std::cout << "**** Please input a number between 0 and 9 ****\n";
         }
      }
      catch(bool invalid) {
         std::cout << "**** Please input a NUMBER between 0 and 9 ****\n";
      }
   } while (!inputValidated);
}