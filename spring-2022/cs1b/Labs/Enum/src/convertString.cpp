#include "main.h"
/****************************************************************************
 * Title: convertString
 * --------------------------------------------------------------------------
 * FUNCTION:
 *  Takes enum index and uses it to indicate index on the string
 * --------------------------------------------------------------------------
 * No Data Table
 * ----------
 ***************************************************************************/

std::string convertString(const int enumIndex, const std::string days[])
{
    if(enumIndex != -1)
        return days[enumIndex];
    else
        return "INVALID";
}