/****************************************************************************
 * Title: Check Ai Input
 * --------------------------------------------------------------------------
 * Function:
 *  This function takes difficulty and using that logic delegates proper
 *  functions to handle certain difficulty
 * --------------------------------------------------------------------------
 * Data Table
 * ----------
 * 
 ***************************************************************************/

#include "main.h"
#include <time.h>
#include <stdlib.h>

bool checkAiInput(const std::string difficulty, char boardAr[][3], const char token)
{
    srand(time(NULL));

    if(difficulty == "Easy") {
        return easyAi(boardAr, token);
    }
    else if(difficulty == "Normal") {
        if(normalWinConditionsAi(boardAr, token))
            return true;
        else if(normalAiBlocking(boardAr, token))
            return true;
        else
            return easyAi(boardAr, token);
    }
    else if(difficulty == "Hard") {
        if(hardWinConditionsAi(boardAr, token))
            return true;
        else if(normalWinConditionsAi(boardAr, token))
            return true;
        else if(hardAiBlocking(boardAr, token))
            return true;
        else if(normalAiBlocking(boardAr, token))
            return true;
        else
            return easyAi(boardAr, token);
    }
    return false;
}