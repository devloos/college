/****************************************************************************
 * Title: Set Player Names
 * --------------------------------------------------------------------------
 * Function: takes input from the user and assigns that into playerX and
 * playerO 
 * --------------------------------------------------------------------------
 * Data Table
 * ----------
 * std::string &playerX IN - pass by reference value that takes in player with
 * token X name
 * std::string &playerO IN - pass by reference value that takes in player with
 * token O name
 ***************************************************************************/

#include "main.h"

void setPlayerNames(std::string &playerX, std::string &playerO)
{
    std::cout << "Enter name for player with token X: ";
    std::getline(std::cin, playerX);
    std::cout << "Enter name for player with token O: ";
    std::getline(std::cin, playerO);
}