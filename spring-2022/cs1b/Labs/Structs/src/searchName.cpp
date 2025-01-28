#include "main.hpp"
/****************************************************************************
 * Title: searchName 
 * --------------------------------------------------------------------------
 * FUNCTION:
 *  handles name search from user and if name was not found returns -1
 * --------------------------------------------------------------------------
 * No Data Table
 * ----------
 ***************************************************************************/

int searchName(std::string inputName, size_t sizeofArray, Account arrayofAccounts[])
{
    for(size_t i {0}; i < sizeofArray; i++)
    {
        if(inputName == arrayofAccounts[i].userName)//checking if the name user inputed exists
            return i;// returns index if true
    }
    return -1;//returns -1 if not found
}