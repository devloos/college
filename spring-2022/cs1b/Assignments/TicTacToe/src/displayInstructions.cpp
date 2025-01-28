/****************************************************************************
 * Title: displayInstructions
 * --------------------------------------------------------------------------
 * This function displays the instructions to the player or players 
 * returns nothing
 * --------------------------------------------------------------------------
 * No Data Table
 * ----------
 ***************************************************************************/

#include "main.h"

void displayInstructions()
{
    std::cout << "[Tic Tac Toe]\n";
    std::cout << "<Instructions>\n";
    std::cout << "<p>\nWhen selecting the option to set a name "
              << "playerX is the first to go & is given token 'X'.\n"
              << "If set names option is not selected then default names will take place.\n</p>\n";
    std::cout << "<p>\n"
<<"                                      How to Play EX. 1                                             \n"
<<"         1       2       3                                    " <<"         1       2       3      \n " 
<<"      [1][1] | [1][2] | [1][3]                                " <<"      [1][1] | [1][2] | [1][3]  \n " 
<<"             |        |                                       " <<"             |        |         \n " 
<<"1            |        |                                       " <<"1            |        |         \n " 
<<"             |        |                                       " <<"             |        |         \n " 
<<"     --------------------------                               " <<"     -------------------------- \n " 
<<"      [2][1] | [2][2] | [2][3]                                " <<"      [2][1] | [2][2] | [2][3]  \n " 
<<"             |        |                                       " <<"             |        |         \n " 
<<"2            |        |                       ->              " <<"2            |   X    |         \n " 
<<"             |        |                                       " <<"             |        |         \n " 
<<"     --------------------------                               " <<"     -------------------------- \n " 
<<"      [3][1] | [3][2] | [3][3]                                " <<"      [3][1] | [3][2] | [3][3]  \n " 
<<"             |        |                                       " <<"             |        |         \n " 
<<"3            |        |                                       " <<"3            |        |         \n " 
<<"             |        |                                       " <<"             |        |         \n " 
                                                                                                           
                                                                                                           
<<"\nPlayerX's turn! What's your play? 2 2                       " <<"PlayerO's turn! What's your play?_ _\n\n\n\n"

<<"                                     How not to Play EX. 2                                         \n "
<<"                                                             Spot is taken on the board! Retry     \n "
<<"         1       2       3                                    " <<"         1       2       3      \n "
<<"      [1][1] | [1][2] | [1][3]                                " <<"      [1][1] | [1][2] | [1][3]  \n " 
<<"             |        |                                       " <<"             |        |         \n " 
<<"1            |        |                                       " <<"1            |        |         \n " 
<<"             |        |                                       " <<"             |        |         \n " 
<<"     --------------------------                               " <<"     -------------------------- \n " 
<<"      [2][1] | [2][2] | [2][3]                                " <<"      [2][1] | [2][2] | [2][3]  \n " 
<<"             |        |                                       " <<"             |        |         \n " 
<<"2            |   X    |                       ->              " <<"2            |   X    |         \n " 
<<"             |        |                                       " <<"             |        |         \n " 
<<"     --------------------------                               " <<"     -------------------------- \n " 
<<"      [3][1] | [3][2] | [3][3]                                " <<"      [3][1] | [3][2] | [3][3]  \n " 
<<"             |        |                                       " <<"             |        |         \n " 
<<"3            |        |                                       " <<"3            |        |         \n " 
<<"             |        |                                       " <<"             |        |         \n " 
                                                                                                           
                                                                                                           
<<"\nPlayerO's turn! What's your play? 2 2                       " <<"PlayerO's turn! What's your play?_ _\n</p>\n";

     std::cout << "</Instructions>\n\n";
}