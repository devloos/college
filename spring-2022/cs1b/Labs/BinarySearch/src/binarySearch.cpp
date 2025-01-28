#include "../include/main.h"
/****************************************************************************
 * Title: binarySearch
 * --------------------------------------------------------------------------
 * FUNCTION:
 *  this is my implementation of binary search, after my way I searched up
 *  binary search and saw the recursive version of it and a simpler version
 *  of iterative implementation.
 *  In short words you have a max, mid, and min 
 *  First the data set has to be in order
 *  Second check to see if key == max or min
 *  if not then we find out whether key is greater than mid or less than mid
 *  if not found return -1
 * --------------------------------------------------------------------------
 * Data Table
 * ----------
 * int max {AR_SIZE} CALC - used to find max size for the array
 * int min {0} CALC - used to find min size of array
 * int mid {AR_SIZE/2} CALC - used to find the mid of max and min
 * bool notFound {false} CALC - if not found then set to true else
 * int invalid {-1} CALC - return -1 if not found
 ***************************************************************************/

int binarySearch(const int &searchKey, const size_t AR_SIZE, int intArray[])
{
    int max {static_cast <int> (AR_SIZE)};
    int min {0};
    int mid {static_cast <int> (AR_SIZE)/2};
    bool notFound {false};
    int invalid {-1};

    if(searchKey == intArray[max])
        return max;
    else if(searchKey == intArray[min])
        return min;

    do
    {
        if(searchKey >= intArray[mid])
        {
            if(searchKey == intArray[mid])
                return mid;
            else {
                min = mid;
                mid = (max + min)/2;
            }
        }else if(searchKey <= intArray[mid]) {
            if(searchKey == intArray[mid])
                return mid;
            else {
                max = mid;
                mid = (max + min)/2;
            }
        }
        if((max - min) == 1)
            notFound = true;
    } while (!notFound);
    return invalid;
}