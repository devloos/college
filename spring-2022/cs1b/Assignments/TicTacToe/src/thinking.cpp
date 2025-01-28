/****************************************************************************
 * Title: Thinking
 * --------------------------------------------------------------------------
 * Function:
 *  this function outputs thinking
 * --------------------------------------------------------------------------
 * No Data Table
 * ----------
 ***************************************************************************/

#include "main.h"

void thinking(char boardAr[][3])
{
    for(size_t i {3}; i > 0; i--)
    {
        system("clear");
        displayBoard(boardAr);
        if(i == 3)
            std::cout << "Thinking.\n";
        else if(i == 2)
            std::cout << "Thinking..\n";
        else if(i == 1)
            std::cout << "Thinking...\n";
        usleep(150000);
    }
}