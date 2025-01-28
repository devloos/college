/****************************************************************************
 * Title: Win Logic
 * --------------------------------------------------------------------------
 * Function:
 *  This function is very simple if you break it down all it does is checks
 *  to see if a win condition is met
 * --------------------------------------------------------------------------
 * Data Table
 * ----------
 * static int plays CALC - calculates the number of plays made
 ***************************************************************************/

#include "main.h"

char winLogic(char boardAr[][3])
{
    static int plays {0};
    if(plays > 3)
    {
        if(boardAr[0][0] != ' ' && boardAr[0][0] == boardAr[0][1] && boardAr[0][1] == boardAr[0][2]) {
            //same logic applies to if else ladder if position [0][0] does not equal to space, and a win condition of tic tac toe is met then reset plays and return current token
            plays = 0;
            return boardAr[0][0];
        }
        else if(boardAr[1][0] != ' ' && boardAr[1][0] == boardAr[1][1] && boardAr[1][1] == boardAr[1][2]) {
            plays = 0;
            return boardAr[1][0];
        }
        else if(boardAr[2][0] != ' ' && boardAr[2][0] == boardAr[2][1] && boardAr[2][1] == boardAr[2][2]) {
            plays = 0;
            return boardAr[2][0];
        }
        else if(boardAr[0][0] != ' ' && boardAr[0][0] == boardAr[1][0] && boardAr[1][0] == boardAr[2][0]) {
            plays = 0;
            return boardAr[0][0];
        }
        else if(boardAr[0][1] != ' ' && boardAr[0][1] == boardAr[1][1] && boardAr[1][1] == boardAr[2][1]) {
            plays = 0;
            return boardAr[0][1];
        }
        else if(boardAr[0][2] != ' ' && boardAr[0][2] == boardAr[1][2] && boardAr[1][2] == boardAr[2][2]) {
            plays = 0;
            return boardAr[0][2];
        }
        else if(boardAr[0][0] != ' ' && boardAr[0][0] == boardAr[1][1] && boardAr[1][1] == boardAr[2][2]) {
            plays = 0;
            return boardAr[0][0];
        }
        else if(boardAr[0][2] != ' ' && boardAr[0][2] == boardAr[1][1] && boardAr[1][1] == boardAr[2][0]) {
            plays = 0;
            return boardAr[0][2];
        }
        else if(plays > 7) {
            plays = 0;
            return 't';
        }
    }
    ++plays;
    return 'c';//return c or continue if nothing was met
}