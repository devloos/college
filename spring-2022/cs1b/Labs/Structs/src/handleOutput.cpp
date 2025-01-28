#include "main.hpp"
/****************************************************************************
 * Title: handleOutput
 * --------------------------------------------------------------------------
 * FUNCTION:
 *  handles output of balances 
 * --------------------------------------------------------------------------
 * No Data Table
 * ----------
 ***************************************************************************/

void handleOutput(int index, std::string type, std::fstream &outFile, const char selection, const size_t sizeofArray, Account arrayofAccounts[])
{
    outFile << type << " Balance:\n";
    outFile << "ID #     NAME                     BALANCE DUE\n";
    outFile << "----     --------------------     -----------\n";
    outFile << arrayofAccounts[index].userID << "     ";//returns an index for the largest balance in the input file
    outFile << arrayofAccounts[index].userName;
    outFile << std::setw(26 - arrayofAccounts[index].userName.size());//returns the size of the largest balance name and subtracts a set width of 26 to get proper format
    outFile << "$" << std::setw(10) << arrayofAccounts[index].userBalance << "\n\n";

}