#include "../include/header.h"

Menu switchValidation() 
{
   int choice;
   bool inputValidated = false;
   //try catch wrapped in a do while until input is validated
   do {
      try {
         std::cout << "Enter a Command? ";
         std::cin >> choice;
         if (std::cin.fail()) {//if cin fails throw expection
            std::cin.clear();//clears buffer for next cin 
            std::cin.ignore(10, '\n');
            throw(true);
         }
         inputValidated = true;
      }
      catch(bool invalid) {
         std::cout << "\n**** Please enter a NUMBER between 0 and 5 ****\n\n";
      }
   } while (!inputValidated);
   std::cin.ignore(100, '\n');
   
   return static_cast <Menu> (choice);//returns int but static cast to enum MenuOptions
}