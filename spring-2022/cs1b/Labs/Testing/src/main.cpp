/*****************************************************************************
 * AUTHOR      : Carlos Aguilera
 * STUDENT ID  : 1152562
 * LAB #7      : Testing 
 * CLASS       : CS1B
 * SECTION     : M-W
 * DUE DATE    : 03.14.22
 ****************************************************************************/

/****************************************************************************
 * Title: Testing
 * --------------------------------------------------------------------------
 * FUNCTION:
 *    This program calculates the number of chocolate bars a sheep should get
 * --------------------------------------------------------------------------
 * Data Table
 * ----------
 * size_t numOfSheeps IN & CALC - used to take input of number of sheeps and
 * also a calc for how many chocolate bars a sheep should get
 * 
 * size_t numOfChocolateBars IN & CALC - used to take input of number of 
 * chocolate bars and also a calc for how many chocolate bars a sheep should get
 ***************************************************************************/

#include "../include/main.h"

int main() {
   heading();

   size_t numOfSheeps {};
   size_t numOfChocolateBars {};

   for (size_t i {0}; i < 3; i++) {
      handleInput(numOfSheeps, numOfChocolateBars);
      handleCalc(numOfSheeps, numOfChocolateBars);
   }
   return 0;
}