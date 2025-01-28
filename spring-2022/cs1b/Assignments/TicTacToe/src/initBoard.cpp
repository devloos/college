/****************************************************************************
 * Title: Initialize Board
 * --------------------------------------------------------------------------
 * This function initializes board to spaces it has a nested for loop
 * & it assigns every position in the 2D array to a space
 * --------------------------------------------------------------------------
 * No Data Table
 * ----------
 ***************************************************************************/
#include "main.h"

void initBoard(char boardAr[][3])
{
    for(size_t row {0}; row < 3; row++)
        for(size_t col {0}; col < 3; col++)
            boardAr[row][col] = ' ';
}