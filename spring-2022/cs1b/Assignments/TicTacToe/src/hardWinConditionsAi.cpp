/****************************************************************************
 * Title: hardWinConditionsAi
 * --------------------------------------------------------------------------
 * Function:
 *  This function with the addition of normalWinConditionsAi have every
 *  possible win condition hard coded to be able to make that move and win
 *  the game
 * --------------------------------------------------------------------------
 * No Data Table
 * ----------
 ***************************************************************************/

#include "main.h"

bool hardWinConditionsAi(char boardAr[][3], const char token)
{
    if(boardAr[0][0] == 'O' && boardAr[0][2] == 'O' && boardAr[0][1] != 'X') {
        thinking(boardAr);
        boardAr[0][1] = token;
        return true;
    }
    if(boardAr[1][0] == 'O' && boardAr[1][2] == 'O' && boardAr[1][1] != 'X') {
        thinking(boardAr);
        boardAr[1][1] = token;
        return true;
    }
    if(boardAr[2][0] == 'O' && boardAr[2][2] == 'O' && boardAr[2][1] != 'X') {
        thinking(boardAr);
        boardAr[2][1] = token;
        return true;
    }
    if(boardAr[0][0] == 'O' && boardAr[2][0] == 'O' && boardAr[1][0] != 'X') {
        thinking(boardAr);
        boardAr[1][0] = token;
        return true;
    }
    if(boardAr[0][1] == 'O' && boardAr[2][1] == 'O' && boardAr[1][1] != 'X') {
        thinking(boardAr);
        boardAr[1][1] = token;
        return true;
    }
    if(boardAr[0][2] == 'O' && boardAr[2][2] == 'O' && boardAr[1][2] != 'X') {
        thinking(boardAr);
        boardAr[1][2] = token;
        return true;
    }
    if(boardAr[0][0] == 'O' && boardAr[2][2] == 'O' && boardAr[1][1] != 'X') {
        thinking(boardAr);
        boardAr[1][1] = token;
        return true;
    }
    if(boardAr[0][2] == 'O' && boardAr[2][0] == 'O' && boardAr[1][1] != 'X') {
        thinking(boardAr);
        boardAr[1][1] = token;
        return true;
    }
    else
        return false;
}