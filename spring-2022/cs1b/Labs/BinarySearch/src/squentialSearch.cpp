#include "../include/main.h"
/****************************************************************************
 * Title: squentialSearch
 * --------------------------------------------------------------------------
 * FUNCTION:
 *  I did not use a for loop in this function because using return would
 *  break logic in the for loop, so I used do while loop to triverse through
 *  the array until key was found
 * --------------------------------------------------------------------------
 * Data Table
 * ----------
 * bool found {false} CALC - if found false keep searching
 * int index CALC - counter for index
 * const int NOT_FOUND {-1} CALC - return value if not found
 ***************************************************************************/

int squentialSearch(const int &searchKey, const size_t &AR_SIZE,int intArray[])
{
    bool found {false};
    int index {0};
    const int NOT_FOUND {-1};
    do
    {
        if(searchKey == intArray[index]) {
            found = true;
            return index;
        }
        ++index;
    } while (!found && index < AR_SIZE);
    return NOT_FOUND;
}