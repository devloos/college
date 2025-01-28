/****************************************************************************
 * Title: Set Player Names
 * --------------------------------------------------------------------------
 * Function:
 *  Takes input on what position on the board the current player wants to
 *  place current token, if the position on the board is already taken
 *  then it console outputs invalid position and repeats until a position 
 *  is valid.
 *  Also calls the checkAiInput function to validate the Ai's input
 * --------------------------------------------------------------------------
 * Data Table
 * ----------
 * std::string difficulty CALC - to determine what difficulty of Ai
 * const char onePlayerDeterminer CALC - this char is used to determine if 
 * the user chose one player mode
 ***************************************************************************/

#include "main.h"

void getAndCheckInp(const std::string difficulty, const char onePlayerDeterminer, char boardAr[][3], const char token, const std::string &playerX, const std::string &playerO)
{
    int row {};
    int col {};
    bool updatedBoard {false};

    do
    {
        if(token == 'X') {
            std::cout << playerX << "'s turn! What's your play? ";
            std::cin >> row >> col;
            --row;
            --col;
        }else if(onePlayerDeterminer != 'd' && token == 'O') {
            std::cout << playerO << "'s turn! What's your play? ";
            std::cin >> row >> col;
            --row;
            --col;
        }else {
            updatedBoard = checkAiInput(difficulty, boardAr, token);//returns true if Ai input was valid
        }
        
        if(onePlayerDeterminer != 'd' || token == 'X')//if one player mode is active than only on token X will this control flow statement run
        {
            if(row < 3 && row > -1 && col < 3 && col > -1)
            {
                if(isspace(boardAr[row][col])) {//if current element in the 2d array is taken by a space then its available
                    boardAr[row][col] = token;
                    updatedBoard = true;
                }else {//if its taken by token O or X than its taken
                    system("clear");
                    std::cout << "Spot is taken on the board! Retry.\n";
                    displayBoard(boardAr);
                }
            }else{
                system("clear");
                std::cout << "Invalid Row and Col\n";
                displayBoard(boardAr);
            }
        }
    }while(!updatedBoard);//once board is updated to true this expression will be not true
}