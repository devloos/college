#include "main.hpp"
/****************************************************************************
 * Title: readFile
 * --------------------------------------------------------------------------
 * FUNCTION:
 * 	Reads from file and stores data in an array of accounts 
 * --------------------------------------------------------------------------
 * Data Table
 * ----------
 * std::string fname, lname CALC - reads first name and last name 
 ***************************************************************************/

void readFile(std::string inputFileName, size_t sizeofArray, Account arrayofAccounts[])//reads file and sets values in the arrays
{
	std::string fname{}, lname{};
	std::fstream inFile;
	inFile.open(inputFileName, std::ios::in); // read mode
	for (size_t i{0}; i < sizeofArray; i++)
	{
		inFile >> fname >> lname;					   // wanted to use getline but then thought this could be less error prone
		arrayofAccounts[i].userName = fname + ' ' + lname;		   // concat fname and lname and assigning it to array names at index i
		inFile >> arrayofAccounts[i].userID >> arrayofAccounts[i].userBalance; // reading id and balance
	}
	inFile.close();
}