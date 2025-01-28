#include "main.h"
/****************************************************************************
 * Title: convertEnum
 * --------------------------------------------------------------------------
 * FUNCTION:
 *  This function takes inputDay and the string array as args
 *  then uses a switch statement to determine what day it is
 *  and returns index of the day in the 
 * --------------------------------------------------------------------------
 * Data Table
 * ----------
 * const int failState {-1} CALC - used to understand why return -1 works
 ***************************************************************************/

int convertEnum(const std::string &inputDay)
{
    Days today;
    const int failState {-1};

    switch(toupper(inputDay[0]))//using toupper method to caps first letter and use that for the expression of the switch statement
    {
        case 'S': {
            if(toupper(inputDay[1]) == 'U')
                today = SUNDAY;
            else
                today = SATURDAY;
            break;
        }
        case 'M':
            today = MONDAY;
            break;
        case 'T': {
            if(toupper(inputDay[1]) == 'U')
                today = TUESDAY;
            else
                today = THURSDAY;
            break;
        }
        case 'W':
            today = WEDNESDAY;
            break;
        case 'F':
            today = FRIDAY;
            break;
        default:
            return failState;//means fail state

    }
    return today;
}