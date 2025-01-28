/****************************************************************************
 * Title: Display Winner
 * --------------------------------------------------------------------------
 * Function:
 *  This function takes player that won or takes a condition if it was
 *  a tie game and outputs the results accoordingly
 * --------------------------------------------------------------------------
 * Data Table
 * ----------
 ***************************************************************************/

#include "main.h"

void displayWinner(const char boardAr[][3], const char &whoWon, const std::string &playerX, const std::string &playerO)
{
    if(whoWon == 'X')
    {
        for(size_t i {5}; i > 0; i--)
        {
            system("clear");
            displayBoard(boardAr);
            std::cout << "Congratulations " << playerX << " for winning!!!\n";
            std::cout << "In "<< i << " seconds you will be sent back to the main menu.\n";
            usleep(ONE_SECOND);
        }
    }else if(whoWon == 'O') 
    {
        for(size_t i {5}; i > 0; i--)
        {
            system("clear");
            displayBoard(boardAr);
            std::cout << "Congratulations " << playerO << " for winning!!!\n";
            std::cout << "In "<< i << " seconds you will be sent back to the main menu.\n";
            usleep(ONE_SECOND);
        }
    }else if(whoWon == 't')
    {
        for(size_t i {5}; i > 0; i--)
        {
            system("clear");
            displayBoard(boardAr);
            std::cout << "TIE Game " << playerX << " & " << playerO << " Goodluck next time!!!\n";
            std::cout << "In "<< i << " seconds you will be sent back to the main menu.\n";
            usleep(ONE_SECOND);
        }
    }
}