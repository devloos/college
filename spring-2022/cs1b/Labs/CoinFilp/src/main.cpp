/*****************************************************************************
 * AUTHOR      : Carlos Aguilera
 * STUDENT ID  : 1152562
 * LAB #2      : Coin Flip
 * CLASS       : CS1B
 * SECTION     : M-W
 * DUE DATE    : 02.02.22
 ****************************************************************************/
#include "../include/main.hpp"
/****************************************************************************
 * Title: Coin Flip
 * --------------------------------------------------------------------------
 * This program will output the class heading
 * --------------------------------------------------------------------------
 * INPUT:
 *  char flipInitializer {}; //IN       -Input of the \n
 * OUTPUT:
 *  size_t flipCount {0}; //CALC & OUT  -Total flip count
 ***************************************************************************/
int main() 
{
    heading();

    std::cout << "Welcome to coin toss! Get 3 heads in a row to win!\n\n";
    userInformation();

    size_t currentHeadCount {0}; //CALC -Increase by one if heads is flipped, resets to 0 if tails is flipped
    size_t totalHeadCount {0}; //CALC   -Total head count for the run of the program
    size_t flipCount {0}; //CALC & OUT  -Total flip count
    char flipInitializer {}; //IN       -Input of the \n

    while (currentHeadCount != 3)//while currentHeadCount is not equal to 3 keep looping
    {
        std::cout << "Press <enter> to flip";
        std::cin.get(flipInitializer);

        if(flipInitializer == '\n')//if flipInitializer has \n stored the true
        {
            if(coinFlip()) {//if function coin flip returns true then run
                std::cout << "HEAD\n";
                ++currentHeadCount;
                ++totalHeadCount;
            }else {//else run
                std::cout << "TAIL\n";
                currentHeadCount = 0;//reset currentHeadCount to 0;
            }
            ++flipCount;
        }else {//else reset buffer and flip again
            std::cin.ignore(10,'\n');
        }
    }
    outputResults(flipCount, averageLogic(totalHeadCount, flipCount));
    return 0;
}