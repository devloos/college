#include "main.hpp"
/****************************************************************************
 * Title: handleSearchOutput
 * --------------------------------------------------------------------------
 * FUNCTION:
 *  handles output of searches
 * --------------------------------------------------------------------------
 * Data Table
 * ----------
 * static int displayCounter CALC - used to determine when to run header
 ***************************************************************************/

void handleSearchOutput(const std::string inputName, const int index, std::fstream &outFile, Account arrayofAccounts[])
{
    static int displayCounter {0};
    if (inputName != "done") {
        if(displayCounter < 1) {
            //start of header
            outFile << "Search Balance:\n";
            outFile << "ID #     NAME                     BALANCE DUE\n";
            outFile << "----     --------------------     -----------\n";
            ++displayCounter;
            //end of header
        }
        outFile << arrayofAccounts[index].userID << "     ";//returns an index for the largest balance in the input file
        outFile << arrayofAccounts[index].userName;
        outFile << std::setw(26 - arrayofAccounts[index].userName.size());//returns the size of the largest balance name and subtracts a set width of 26 to get proper format
        outFile << "$" << std::setw(10) << arrayofAccounts[index].userBalance << "\n";
    }else 
        displayCounter = 0;//reset display counter good for reusability
}