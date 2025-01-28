/****************************************************************************
 * Title: Normal Ai 
 * --------------------------------------------------------------------------
 * Function:
 *  All this function does is reads the board to see if player X has a 
 *  possible win condition if so then Ai will block player from that win
 *  condition. Also does a check to see if its already blocked that move
 * --------------------------------------------------------------------------
 * No Data Table
 * ----------
 ***************************************************************************/

#include "main.h"

bool normalAiBlocking(char boardAr[][3], const char token)
{
    if(boardAr[0][0] == 'X' && boardAr[0][1] == 'X' && boardAr[0][2] != 'O') {
        //if boardAr at position [0][0] is equal to X and so is [0][1] then we check if Ai has already blocked [0][2] and if not than Ai blocks
        //same logic applies to the rest of the ladder
        thinking(boardAr);
        boardAr[0][2] = token;
        return true;
    }
    else if(boardAr[0][2] == 'X' && boardAr[0][1] == 'X' && boardAr[0][0] != 'O') {
        thinking(boardAr);
        boardAr[0][0] = token;
        return true;
    }
    else if(boardAr[1][0] == 'X' && boardAr[1][1] == 'X' && boardAr[1][2] != 'O') {
        thinking(boardAr);
        boardAr[1][2] = token;
        return true;
    }
    else if(boardAr[1][2] == 'X' && boardAr[1][1] == 'X' && boardAr[1][0] != 'O') {
        thinking(boardAr);
        boardAr[1][0] = token;
        return true;
    }
    else if(boardAr[2][0] == 'X' && boardAr[2][1] == 'X' && boardAr[2][2] != 'O') {
        thinking(boardAr);
        boardAr[2][2] = token;
        return true;
    }
    else if(boardAr[2][2] == 'X' && boardAr[2][1] == 'X' && boardAr[2][0] != 'O') {
        thinking(boardAr);
        boardAr[2][0] = token;
        return true;
    }
    else if(boardAr[0][0] == 'X' && boardAr[1][0] == 'X' && boardAr[2][0] != 'O') {
        thinking(boardAr);
        boardAr[2][0] = token;
        return true;
    }
    else if(boardAr[2][0] == 'X' && boardAr[1][0] == 'X' && boardAr[0][0] != 'O') {
        thinking(boardAr);
        boardAr[0][0] = token;
        return true;
    }
    else if(boardAr[0][1] == 'X' && boardAr[1][1] == 'X' && boardAr[2][1] != 'O') {
        thinking(boardAr);
        boardAr[2][1] = token;
        return true;
    }
    else if(boardAr[2][1] == 'X' && boardAr[1][1] == 'X' && boardAr[0][1] != 'O') {
        thinking(boardAr);
        boardAr[0][1] = token;
        return true;
    }
    else if(boardAr[0][2] == 'X' && boardAr[1][2] == 'X' && boardAr[2][2] != 'O') {
        thinking(boardAr);
        boardAr[2][2] = token;
        return true;
    }
    else if(boardAr[2][2] == 'X' && boardAr[1][2] == 'X' && boardAr[0][2] != 'O') {
        thinking(boardAr);
        boardAr[0][2] = token;
        return true;
    }
    else if(boardAr[0][0] == 'X' && boardAr[1][1] == 'X' && boardAr[2][2] != 'O') {
        thinking(boardAr);
        boardAr[2][2] = token;
        return true;
    }
    else if(boardAr[2][2] == 'X' && boardAr[1][1] == 'X' && boardAr[0][0] != 'O') {
        thinking(boardAr);
        boardAr[0][0] = token;
        return true;
    }
    else if(boardAr[0][2] == 'X' && boardAr[1][1] == 'X' && boardAr[2][0] != 'O') {
        thinking(boardAr);
        boardAr[2][0] = token;
        return true;
    }
    else if(boardAr[2][0] == 'X' && boardAr[1][1] == 'X' && boardAr[0][2] != 'O') {
        thinking(boardAr);
        boardAr[0][2] = token;
        return true;
    }
    else
        return false;
}