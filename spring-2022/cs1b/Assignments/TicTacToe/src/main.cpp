/*****************************************************************************
 * AUTHOR      : Carlos Aguilera
 * STUDENT ID  : 1152562
 * LAB #       : 2
 * CLASS       : CS1B
 * SECTION     : M-W
 * DUE DATE    : 03.04.22
 ****************************************************************************/

#include "main.h"

/****************************************************************************
 * Title: Multi-Dimensional Array-TicTacToe
 * --------------------------------------------------------------------------
 * This is a clone of Tic Tac Toe, in this program you will be able to set
 * your players name and choose between going against a Ai or 1v1 against
 * another human. You can change the difficulty of the Ai by entering a
 * string in the menu for that, also on another note if you don't supply
 * a name for your players default name will be put in place.
 * --------------------------------------------------------------------------
 * Data Table
 * ----------
 * std::string playerX IN & OUT - used to set name for player with token X
 * std::string playerO IN & OUT - used to set name for player with token O
 * char menuChoice IN - used to get choice of menu selection
 * int ignoreCounter CALC - used to ignore cin.ignore once in the program
 * char boardAr[3][3] IN & OUT & CALC - used to store values like token & space
 * char whoWon CALC - used to store token on who won either X or O
 * char token CALC - used to decide winner and used by boardAr for placement move
 * std::string difficultyInput IN & CALC - used for determining Ai difficulty
 * const int ONE_SECOND CALC - used for storing int of 1000000 ms
 ***************************************************************************/
int main() 
{
    std::string playerX {"PlayerX"};
    std::string playerO {"PlayerO"};
    char menuChoice {};
    int ignoreCounter {0};
    do
    {
        system("clear");//clear command in the terminal do to wipe every time while loop runs
        displayHeader();
        if(ignoreCounter < 1)
            displayInstructions();
        std::cout << "Main Menu\na. Exit\nb. Set Player Names\nc. Play in Two Player Mode\nd. Play in One Player Mode\nEnter Choice: ";
        if(ignoreCounter > 0 && menuChoice != 'b')//if statement to ignore first run of the while loop
            std::cin.ignore(10, '\n');
        std::cin.get(menuChoice);
        std::cin.ignore(10, '\n');

        switch(menuChoice)
        {
            case 'a': 
                std::cout << "Thank You!\n";
                usleep(ONE_SECOND);//Delay from reading next line of code one second
                system("clear");
                break;
            case 'b':
                setPlayerNames(playerX, playerO);
                break;
            case 'c':
            {
                char boardAr[3][3];
                initBoard(boardAr);//initialize board to ' '
                char whoWon {};
                char token {'X'};
                std::string difficultyInput {};

                do
                {
                    system("clear");
                    displayBoard(boardAr);
                    getAndCheckInp(difficultyInput, menuChoice, boardAr, token, playerX, playerO);
                    whoWon = winLogic(boardAr);//check win returns token 
                    switchToken(token);
                } while (whoWon != 't' && whoWon != 'X' && whoWon != 'O');
                displayWinner(boardAr, whoWon, playerX, playerO);//display winner
                break;
            }
            case 'd':
            {
                system("clear");
                char boardAr[3][3];
                initBoard(boardAr);
                char whoWon {};
                char token {'X'};
                std::string difficultyInput {"Easy"};

                std::cout << "Select what difficultly you want the AI to be!\n";
                std::cout << "Easy\nNormal\nHard\nEnter String: ";
                std::getline(std::cin, difficultyInput);

                do
                {
                    system("clear");
                    displayBoard(boardAr);
                    getAndCheckInp(difficultyInput, menuChoice, boardAr, token, playerX, playerO);
                    whoWon = winLogic(boardAr);
                    switchToken(token);
                } while (whoWon != 't' && whoWon != 'X' && whoWon != 'O');
                displayWinner(boardAr, whoWon, playerX, playerO);
                break;
            }
        }
        ++ignoreCounter;
    }while(menuChoice != 'a');
    return 0;
}