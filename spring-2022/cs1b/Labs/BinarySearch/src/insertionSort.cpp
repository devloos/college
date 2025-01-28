#include "../include/main.h"
/****************************************************************************
 * Title: insertionSort
 * --------------------------------------------------------------------------
 * FUNCTION:
 *  insertion sort how this sort works is it goes through the array comparing
 *  last key to the elements and pushing the elements forward if needed
 * --------------------------------------------------------------------------
 * Data Table
 * ----------
 * int key {intArray[i]} CALC - holds value that for loop is on
 ***************************************************************************/

void insertionSort(const size_t &AR_SIZE, int intArray[])
{
    // 4 18 1 3
    // 1 3 4 18 

    for(int i {1}; i < AR_SIZE; i++)//i is 3
    {
        int key {intArray[i]};//key is 3
        int j {i - 1};//j is 0

        while(j >= 0 && intArray[j] > key)// key stays the same through while loop, you could also use a decrementing for loop here but it would be inefficient
        {
            intArray[j + 1] = intArray[j];
            --j;
        }
        intArray[j + 1] = key;
    }
}