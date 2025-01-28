#include "../include/main.h"
/****************************************************************************
 * Title: handelOutput
 * --------------------------------------------------------------------------
 * FUNCTION:
 *    Handles output, also overloading this function
 * --------------------------------------------------------------------------
 * No Data Table
 * ----------
 ***************************************************************************/


void handleOutput(const size_t &remainder, size_t &i) {
   std::cout << "Number of remaining Chocolate Bars: " << remainder << "\n";
   std::cout << "Number of Chocolate Bars each sheep got: " << i << "\n";
   i = 1;
}
void handleOutput(const size_t &remainder) {
   std::cout << "Number of remaining Chocolate Bars: " << remainder << "\n";
   std::cout << "Number of Chocolate Bars each sheep got: 0 \n";
}