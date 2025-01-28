/****************************************************************************
 * Title: normalWinConditionsAi
 * --------------------------------------------------------------------------
 * Function:
 *  this function checks to see if there is a possible win condition for Ai
 *  and if there is then acts on it, normal only does some win possible
 *  win conditions
 * --------------------------------------------------------------------------
 * No Data Table
 * ----------
 ***************************************************************************/
#include "main.h"

bool normalWinConditionsAi(char boardAr[][3], const char token)
{
    if(boardAr[0][0] == 'O' && boardAr[0][1] == 'O' && boardAr[0][2] != 'X') {
        thinking(boardAr);
        boardAr[0][2] = token;
        return true;
    }
    else if(boardAr[0][2] == 'O' && boardAr[0][1] == 'O' && boardAr[0][0] != 'X') {
        thinking(boardAr);
        boardAr[0][0] = token;
        return true;
    }
    else if(boardAr[1][0] == 'O' && boardAr[1][1] == 'O' && boardAr[1][2] != 'X') {
        thinking(boardAr);
        boardAr[1][2] = token;
        return true;
    }
    else if(boardAr[1][2] == 'O' && boardAr[1][1] == 'O' && boardAr[1][0] != 'X') {
        thinking(boardAr);
        boardAr[1][0] = token;
        return true;
    }
    else if(boardAr[2][0] == 'O' && boardAr[2][1] == 'O' && boardAr[2][2] != 'X') {
        thinking(boardAr);
        boardAr[2][2] = token;
        return true;
    }
    else if(boardAr[2][2] == 'O' && boardAr[2][1] == 'O' && boardAr[2][0] != 'X') {
        thinking(boardAr);
        boardAr[2][0] = token;
        return true;
    }
    else if(boardAr[0][0] == 'O' && boardAr[1][0] == 'O' && boardAr[2][0] != 'X') {
        thinking(boardAr);
        boardAr[2][0] = token;
        return true;
    }
    else if(boardAr[2][0] == 'O' && boardAr[1][0] == 'O' && boardAr[0][0] != 'X') {
        thinking(boardAr);
        boardAr[0][0] = token;
        return true;
    }
    else if(boardAr[0][1] == 'O' && boardAr[1][1] == 'O' && boardAr[2][1] != 'X') {
        thinking(boardAr);
        boardAr[2][1] = token;
        return true;
    }
    else if(boardAr[2][1] == 'O' && boardAr[1][1] == 'O' && boardAr[0][1] != 'X') {
        thinking(boardAr);
        boardAr[0][1] = token;
        return true;
    }
    else if(boardAr[0][2] == 'O' && boardAr[1][2] == 'O' && boardAr[2][2] != 'X') {
        thinking(boardAr);
        boardAr[2][2] = token;
        return true;
    }
    else if(boardAr[2][2] == 'O' && boardAr[1][2] == 'O' && boardAr[0][2] != 'X') {
        thinking(boardAr);
        boardAr[0][2] = token;
        return true;
    }
    else if(boardAr[0][0] == 'O' && boardAr[1][1] == 'O' && boardAr[2][2] != 'X') {
        thinking(boardAr);
        boardAr[2][2] = token;
        return true;
    }
    else if(boardAr[2][2] == 'O' && boardAr[1][1] == 'O' && boardAr[0][0] != 'X') {
        thinking(boardAr);
        boardAr[0][0] = token;
        return true;
    }
    else if(boardAr[0][2] == 'O' && boardAr[1][1] == 'O' && boardAr[2][0] != 'X') {
        thinking(boardAr);
        boardAr[2][0] = token;
        return true;
    }
    else if(boardAr[2][0] == 'O' && boardAr[1][1] == 'O' && boardAr[0][2] != 'X') {
        thinking(boardAr);
        boardAr[0][2] = token;
        return true;
    }
    else
        return false;
}