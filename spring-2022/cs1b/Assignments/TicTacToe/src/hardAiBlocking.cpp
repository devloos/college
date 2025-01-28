/****************************************************************************
 * Title: hardAiBlocking
 * --------------------------------------------------------------------------
 * Function:
 *  Blocks any possible win conditions that player X has
 * --------------------------------------------------------------------------
 * No Data Table
 * ----------
 ***************************************************************************/

#include "main.h"

bool hardAiBlocking(char boardAr[][3], const char token)
{
    if(boardAr[0][0] == 'X' && boardAr[0][2] == 'X' && boardAr[0][1] != 'O') {
        thinking(boardAr);
        boardAr[0][1] = token;
        return true;
    }
    if(boardAr[1][0] == 'X' && boardAr[1][2] == 'X' && boardAr[1][1] != 'O') {
        thinking(boardAr);
        boardAr[1][1] = token;
        return true;
    }
    if(boardAr[2][0] == 'X' && boardAr[2][2] == 'X' && boardAr[2][1] != 'O') {
        thinking(boardAr);
        boardAr[2][1] = token;
        return true;
    }
    if(boardAr[0][0] == 'X' && boardAr[2][0] == 'X' && boardAr[1][0] != 'O') {
        thinking(boardAr);
        boardAr[1][0] = token;
        return true;
    }
    if(boardAr[0][1] == 'X' && boardAr[2][1] == 'X' && boardAr[1][1] != 'O') {
        thinking(boardAr);
        boardAr[1][1] = token;
        return true;
    }
    if(boardAr[0][2] == 'X' && boardAr[2][2] == 'X' && boardAr[1][2] != 'O') {
        thinking(boardAr);
        boardAr[1][2] = token;
        return true;
    }
    if(boardAr[0][0] == 'X' && boardAr[2][2] == 'X' && boardAr[1][1] != 'O') {
        thinking(boardAr);
        boardAr[1][1] = token;
        return true;
    }
    if(boardAr[0][2] == 'X' && boardAr[2][0] == 'X' && boardAr[1][1] != 'O') {
        thinking(boardAr);
        boardAr[1][1] = token;
        return true;
    }
    else
        return false;
}