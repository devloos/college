#include "main.hpp"

void readFile(std::string inputFileName, size_t sizeofArray, std::string arrayofNames[], int arrayofIDs[], double arrayofBalances[])
{
	std::string fname{}, lname{};
	std::fstream inFile;
	inFile.open(inputFileName, std::ios::in); // read mode
	for (size_t i{0}; i < sizeofArray; i++)
	{
		inFile >> fname >> lname;					   // wanted to use getline but then thought this could be less error prone
		arrayofNames[i] = fname + ' ' + lname;		   // concat fname and lname and assigning it to array names at index i
		inFile >> arrayofIDs[i] >> arrayofBalances[i]; // reading id and balance
	}
	inFile.close();
}