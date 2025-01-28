#include "../include/main.h"
/****************************************************************************
 * Title: handleOutput
 * --------------------------------------------------------------------------
 * FUNCTION:
 *  Handles the output of the array in a certain format
 * --------------------------------------------------------------------------
 * No Data Table
 * ----------
 ***************************************************************************/

void handleOutput(const size_t &AR_SIZE, int intArray[])
{
    std::cout << std::endl;
    for(size_t i {0}; i < AR_SIZE; i++)
        std::cout << "Index #" << i << ": " << intArray[i] << "\n";
}