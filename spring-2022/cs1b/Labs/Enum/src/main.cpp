#include "main.h"
/****************************************************************************
 * Title: Extra Credit Enum
 * --------------------------------------------------------------------------
 * This progam takes a string from the user (what day of the week)
 * and converts it to a Days type and then converts that Days type back to 
 * a string and outputs whether invalid or valid
 * --------------------------------------------------------------------------
 * Data Table
 * ----------
 * std::string strDays[7] OUT & CALC - holds days of the week
 * bool invalid {false} CALC - repeats while loop until invalid equals true
 * std::string inputDay {}; IN - takes input from user of what day it is
 ***************************************************************************/


int main()
{
    displayHeader();
    std::string strDays[7] {"SUNDAY","MONDAY","TUESDAY","WEDNESDAY","THURSDAY","FRIDAY","SATURDAY"};
    bool invalid {false};
    std::string inputDay {};

    do
    {
        std::cout << "What day is today? ";
        std::cin >> inputDay;

        if(convertString(convertEnum(inputDay), strDays) != "INVALID") //if the calling functions return "INVALID" then else statements run
            std::cout << "Today is " << convertString(convertEnum(inputDay), strDays) << " !\n\n";
        else {
            std::cout << "***** Invalid day input *****\n\n";
            std::cout << "Today is " << convertString(convertEnum(inputDay), strDays) << " !\n";
            invalid = true;
        }

    } while (!invalid);//while invalid does not equal true
    
}