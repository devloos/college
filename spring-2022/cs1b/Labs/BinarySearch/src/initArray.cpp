#include "../include/main.h"
/****************************************************************************
 * Title: initArray
 * --------------------------------------------------------------------------
 * FUNCTION:
 *  Initializes array with user input
 * --------------------------------------------------------------------------
 * No Data Table
 * ----------
 ***************************************************************************/

void initArray(const size_t AR_SIZE, int intArray[])
{
    for(size_t i {0}; i < AR_SIZE; i++)
    {
        std::cout << "Index #" << i << ": ";
        std::cin >> intArray[i];
    }
}