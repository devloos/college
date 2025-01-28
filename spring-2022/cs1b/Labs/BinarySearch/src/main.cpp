/*****************************************************************************
 * AUTHOR      : Carlos Aguilera
 * STUDENT ID  : 1152562
 * LAB #5      : Binary Search
 * CLASS       : CS1B
 * SECTION     : M-W
 * DUE DATE    : 02.28.22
 ****************************************************************************/

#include "../include/main.h"

/****************************************************************************
 * Title: Binary Search
 * --------------------------------------------------------------------------
 * This program will use sequential search and binary search to find a 
 * key that the user wants to find and output what index the key was found
 * in.
 * --------------------------------------------------------------------------
 * Data Table
 * ----------
 * const size_t AR_SIZE {8} CALC - used to calc how big the array is
 * int intArray [AR_SIZE] IN & OUT - array with values from user
 * int searchKey {} IN & OUT & CALC - search key to find in the array
 ***************************************************************************/
int main()
{
    displayHeader();
    const size_t AR_SIZE {8};
    int intArray[AR_SIZE];
    initArray(AR_SIZE, intArray);
    int searchKey {};

    for(size_t i {0}; i < 4; i++)
    {
        std::cout << "\nEnter an integer to search for: ";
        std::cin >> searchKey;

        int index {squentialSearch(searchKey, AR_SIZE, intArray)};
        if(index != -1)
            std::cout << "The integer " << searchKey << " was found in index #" << index << ".\n";
        else
            std::cout << searchKey << " was not found!\n";
    }

    std::cout << "\n\nPerforming insertion sort...\n";
    insertionSort(AR_SIZE, intArray);
    handleOutput(AR_SIZE, intArray);

    for(size_t i {0}; i < 4; i++)
    {
        std::cout << "\nEnter an integer to search for: ";
        std::cin >> searchKey;

        int index {binarySearch(searchKey, AR_SIZE, intArray)};
        if(index != -1)
            std::cout << "The integer " << searchKey << " was found in index #" << index << ".\n";
        else
            std::cout << searchKey << " was not found!\n";
    }
}
