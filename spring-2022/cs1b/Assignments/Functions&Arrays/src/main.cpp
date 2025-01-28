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
 * This program will output the class heading
 * --------------------------------------------------------------------------
 * INPUT:
 * inputFileName {file name for input}
 * outputFileName {file name for output}
 * selection {char for switch case condition}
 * inputName {name input to search for from user}
 * inFile {read from input file}
 * OUTPUT:
 * outFile {output to file}
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
	while(inFile)//stores line in temporary string
		++sizeofArray;// a loop that gets the number of lines in the file
	sizeofArray /= 2;// works for the type of formatting that the input file has if format changes then bugs could occur
	inFile.close();

	std::string arrayofNames[sizeofArray];
	int arrayofIDs[sizeofArray];
	double arrayofBalances[sizeofArray];

	readFile(inputFileName, sizeofArray, arrayofNames, arrayofIDs, arrayofBalances);//reads file and sets values in the arrays

	char selection {};
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
				
				std::fstream outFile;
				outFile.open(outputFileName, std::ios::app);//appends to file and doesn't erase but adds instead
				outFile << "Larger Balance:\n";
				outFile << "ID #     NAME                     BALANCE DUE\n";
				outFile << "----     --------------------     -----------\n";
				outFile << arrayofIDs[balanceIndex(selection, sizeofArray, arrayofBalances)] << "     ";//returns an index for the largest balance in the input file
				outFile << arrayofNames[balanceIndex(selection, sizeofArray, arrayofBalances)];
				outFile << std::setw(26 - arrayofNames[balanceIndex(selection, sizeofArray, arrayofBalances)].size());//returns the size of the largest balance name and subtracts a set width of 26 to get proper format
				outFile << "$" << std::setw(10) << arrayofBalances[balanceIndex(selection, sizeofArray, arrayofBalances)] << "\n\n";
				outFile.close();
				break;
			}
			case '2': {
				std::cout << "Finding the Smaller Balance...\n";

				std::fstream outFile;
				outFile.open(outputFileName, std::ios::app);
				outFile << "Smaller Balance:\n";
				outFile << "ID #     NAME                     BALANCE DUE\n";
				outFile << "----     --------------------     -----------\n";
				outFile << arrayofIDs[balanceIndex(selection, sizeofArray, arrayofBalances)] << "     ";
				outFile << arrayofNames[balanceIndex(selection, sizeofArray, arrayofBalances)]; 
				outFile << std::setw(26 - arrayofNames[balanceIndex(selection, sizeofArray, arrayofBalances)].size());
				outFile << "$" << std::setw(10) << arrayofBalances[balanceIndex(selection, sizeofArray, arrayofBalances)] << "\n\n";
				outFile.close();
				break;
			}
			case '3': {
				std::cout << "Obtaining the sum of all Balances...\n";

				std::fstream outFile;
				outFile.open(outputFileName, std::ios::app);
				outFile << "Sum of Balance for all persons:\n";
				outFile << std::fixed << std::setprecision(2) << "$" << std::setw(10) << sumofBalances(sizeofArray, arrayofBalances) << "\n\n";//returns sum of balances
				outFile.close();
				break;
			}
			case '4': {
				std::cout << "Obtaining the average of all Balances...\n";

				std::fstream outFile;
				outFile.open(outputFileName, std::ios::app);
				outFile << "Average Balance for all persons:\n";
				outFile << std::fixed << std::setprecision(2) << "$" << std::setw(10) << sumofBalances(sizeofArray, arrayofBalances)/sizeofArray << "\n\n";//returns average of balances using the size of array or how many IDs we have
				outFile.close();
				break;
			}
			case '5': {
				std::string inputName {};
				std::cout << "Who do you want to search for (enter done to exit): ";
				std::cin.ignore(10, '\n');
				std::getline(std::cin, inputName);

				if(inputName == "done")//expection handling for when user enters done
					continue;
				else if(searchName(inputName, sizeofArray, arrayofNames) != -1) {// function returns a -1 if not found and if found returns index that it was found in
					std::cout << "Found.\n";

					std::fstream outFile;
					outFile.open(outputFileName, std::ios::app);
					outFile << "Search Name:\n";
					outFile << "ID #     NAME                     BALANCE DUE\n";
					outFile << "----     --------------------     -----------\n";
					outFile << arrayofIDs[searchName(inputName, sizeofArray, arrayofNames)] << "     ";
					outFile << arrayofNames[searchName(inputName, sizeofArray, arrayofNames)];
					outFile << std::setw(26 - arrayofNames[searchName(inputName, sizeofArray, arrayofNames)].size());
					outFile << "$" << std::setw(10) << arrayofBalances[searchName(inputName, sizeofArray, arrayofNames)] << "\n\n";
					outFile.close();
				}else
					std::cout << inputName << " was not found.\n";//handling not found
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
	
}