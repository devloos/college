/****************************************************************************
 * Title: Easy Ai Logic
 * --------------------------------------------------------------------------
 * Function:
 *  Declares and initializes row and col to a random number between 0 & 2
 *  & then checks to see if spot is available and will continue to loop
 *  until valid
 * --------------------------------------------------------------------------
 * Data Table
 * ----------
 * int row{rand() % 3} CALC - initializes row to a number between 0 & 2
 * int col{rand() % 3} CALC - initializes col to a number between 0 & 2
 ***************************************************************************/

#include "main.h"

bool easyAi(char boardAr[][3], const char token)
{
    while(true)
    {
        int row {rand() % 3};
        int col {rand() % 3};
        if(isspace(boardAr[row][col])) {
            thinking(boardAr);
            boardAr[row][col] = token;
            return true;
        }
    }
}