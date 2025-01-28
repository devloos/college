#include "../include/main.h"
/****************************************************************************
 * Title: handelCalc
 * --------------------------------------------------------------------------
 * FUNCTION:
 *    Handles the calculation of how many chocolate bars a sheep gets
 * --------------------------------------------------------------------------
 * No Data Table
 * ----------
 ***************************************************************************/


void handleCalc(const size_t numOfSheeps, const size_t numOfChocolateBars) {
   /*
      I used a for loop to test possible solutions on how many chocolate bars a sheep got
      if number of sheeps was greater than # of chocolate bars then the remainder
      was simply # of chocolate bars
   */
   for (size_t i {4}; i > 0; i--) {
      if (numOfSheeps == 0 || numOfSheeps > numOfChocolateBars) {
         handleOutput(numOfChocolateBars);
         i = 1;
      } else if (numOfChocolateBars >= (numOfSheeps * i)) {
         size_t remainder {numOfChocolateBars - (numOfSheeps * i)};
         handleOutput(remainder, i);
      }
   }
}