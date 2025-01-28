/*****************************************************************************
 * AUTHOR      : Carlos Aguilera
 * STUDENT ID  : 1152562
 * LAB #       : 1
 * CLASS       : CS1B
 * SECTION     : M-W
 * DUE DATE    : 02.02.22
 ****************************************************************************/

#include "main.hpp"
/****************************************************************************
 * Title: Functions & Arrays
 * --------------------------------------------------------------------------
 * FUNCTION:
 *  handles output of searches
 * --------------------------------------------------------------------------
 * Data Table
 * ----------
 * char selection IN & CALC - char for switch case condition
 * std::string inputFileName IN & CALC - file name for input
 * std::string outputFileName IN & CALC - file name for output
 * std::string inputName IN & CALC - name input to search for from user
 * std::fstream inFile CALC - read from input file
 * std::fstream outFile CALC - output to file
 * size_t sizeofArray CALC - size of the array
 * Account arrayofAccounts[] CALC - array of Accounts
 ***************************************************************************/

int main()
{
	heading();

	std::string inputFileName {}, outputFileName {}, temp {};
	std::cout << "What input file would you like to use? ";
	std::cin >> inputFileName; //reads input for what file to read from
	std::cout << "What output file would you like to use? ";
	std::cin >> outputFileName; // reads input for what file to write to

	size_t sizeofArray {0};
	std::fstream inFile;
	inFile.open(inputFileName, std::ios::in); //file is in read only mode
	while(std::getline(inFile, temp))//stores line in temporary string
		++sizeofArray;// a loop that gets the number of lines in the file
	sizeofArray /= 2;// works for the type of formatting that the input file has if format changes then bugs could occur
	inFile.close();

	Account arrayofAccounts[sizeofArray];

	readFile(inputFileName, sizeofArray, arrayofAccounts);//reads file and sets values in the arrays

	char selection {};
	std::fstream outFile;
	outFile.open(outputFileName, std::ios::app);//appends to file and doesn't erase but adds instead
	do
	{
		std::cout << "\nMenu Options\n\n"
				<< "1 - Find the larger balance\n"
				<< "2 - Find the smaller balance\n"
				<< "3 - Obtain the sum of all balances\n"
				<< "4 - Obtain the average of all balances\n"
				<< "5 - Find Person\n"
				<< "0 - Exit\n"
		        << "Enter an option (0 to exit): ";
		std::cin >> selection;
		std::cout << "\n";

		switch (selection)
		{
			case '1': {
				std::cout << "Finding the Larger Balance...\n";
				std::string type {"Larger"};
				int index {balanceIndex(selection, sizeofArray, arrayofAccounts)};
				handleOutput(index, type, outFile, selection, sizeofArray, arrayofAccounts);
				break;
			}
			case '2': {
				std::cout << "Finding the Smaller Balance...\n";
				std::string type {"Smaller"};
				int index {balanceIndex(selection, sizeofArray, arrayofAccounts)};
				handleOutput(index, type, outFile, selection, sizeofArray, arrayofAccounts);
				break;
			}
			case '3': {
				std::cout << "Obtaining the sum of all Balances...\n";

				outFile << "Sum of Balance for all persons:\n";
				outFile << std::fixed << std::setprecision(2) << "$" << std::setw(10) << sumofBalances(sizeofArray, arrayofAccounts) << "\n\n";//returns sum of balances
				break;
			}
			case '4': {
				std::cout << "Obtaining the average of all Balances...\n";

				outFile << "Average Balance for all persons:\n";
				outFile << std::fixed << std::setprecision(2) << "$" << std::setw(10) << sumofBalances(sizeofArray, arrayofAccounts)/sizeofArray << "\n\n";//returns average of balances using the size of array or how many IDs we have
				break;
			}
			case '5': {
				std::string inputName {};
				int index {};
				std::cin.ignore(10, '\n');
				do
				{
					std::cout << "Who do you want to search for (enter done to exit): ";
					std::getline(std::cin, inputName);

					if(inputName == "done") { //expection handling for when user enters done
						handleSearchOutput(inputName, index, outFile, arrayofAccounts);
						continue;
					}
					else if((index = searchName(inputName, sizeofArray, arrayofAccounts)) != -1) {// function returns a -1 if not found and if found returns index that it was found in
						std::cout << "Found.\n";
						handleSearchOutput(inputName, index, outFile, arrayofAccounts);
					}else
						std::cout << inputName << " was not found.\n";//handling not found
				} while (inputName != "done");
				
				break;
			}
			case '0': {
				std::cout << "Thank you for using my program.\n";
				break;
			}
			default: {
				std::cout << "Invalid input!\n";
				break;
			}
		}
	} while (selection != '0');
	outFile.close();
	return 0;
}