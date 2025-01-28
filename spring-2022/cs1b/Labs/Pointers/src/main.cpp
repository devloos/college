#include "../include/header.h"
/*****************************************************************************
 * AUTHOR      : Carlos Aguilera
 * STUDENT ID  : 1152562
 * LAB #8      : Pointers
 * CLASS       : CS1B
 * SECTION     : M-W
 * DUE DATE    : 03.28.22
 ****************************************************************************/

/****************************************************************************
 * Title: Lab Pointers
 * --------------------------------------------------------------------------
 * FUNCTION:
 *    This program takes two numbers and outputs the sum of those numbers
 *    & outputs the product of the two, both numbers are being accessed by pointers
 * --------------------------------------------------------------------------
 * Data Table
 * ----------
 * int val1 {}; 
 * int *ptrVal = &val1; IN & CALC - get input and get product and sum
 * int *ptrNew = new int; IN & CALC - get input and get product and sum
 ***************************************************************************/

int main() {
   int val1 {};
   int *ptrVal = &val1;
   int *ptrNew = new int;
   heading();

   std::cout << std::left;
   do {
      std::cout << std::setw(45) << "\nInput the first value (enter -999 to exit)?";
      std::cin >> *ptrVal;
      std::cin.ignore(10,'\n');
      if (*ptrVal != -999) {
         std::cout << std::setw(43) << "Input second value?";
         std::cin >> *ptrNew;
         std::cin.ignore(10,'\n');
         std::cout << std::setw(17) << "\nThe sum is:" << *ptrVal + *ptrNew << "\n";
         std::cout << std::setw(16) << "The product is:" << *ptrVal * *ptrNew << "\n";
      }
   } while (*ptrVal != -999);
   std::cout << std::right;
   
   delete ptrNew;
}