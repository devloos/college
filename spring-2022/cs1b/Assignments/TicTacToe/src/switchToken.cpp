/****************************************************************************
 * Title: Switch Token
 * --------------------------------------------------------------------------
 * Function:
 *  switch token from X to O and O to X
 * --------------------------------------------------------------------------
 * Data Table
 * ----------
 * char &token CALC - PBR and switch from current token
 ***************************************************************************/

#include "main.h"

void switchToken(char &token)
{
    if(token == 'X')
        token = 'O';
    else if(token == 'O')
        token = 'X';
}