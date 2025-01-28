/*****************************************************************************
 * AUTHOR      : Carlos Aguilera
 * STUDENT ID  : 1152562
 * LAB #       : GCD
 * CLASS       : CS1B
 * SECTION     : M-W
 * DUE DATE    : 02.09.22 
 ****************************************************************************/

#include "main.hpp"

/****************************************************************************
 * Title: GCD
 * --------------------------------------------------------------------------
 * This program will output a GCD of 2 integers
 * --------------------------------------------------------------------------
 * std::fstream outfile OUT - file variable
 * int value1 CALC & IN - value from the user and comparison
 * int value2 CALC & IN - value from the user and comparison
 ***************************************************************************/

int main() 
{
    printHeader(std::cout);
    std::fstream outfile;
    outfile.open("output.txt", std::ios::out);
    printHeader(outfile);

    std::cout << printHeader(); //returns back a string and we print to the console
    outfile << printHeader(); //returns back a string and we write to file

    int value1 {};
    int value2 {};
    for(size_t i {0}; i < 4; i++)
    {
        readValues(value1, value2); //reads to values
        handleResults(outfile, value1, value2, GCD((value1 > value2) ? value1 : value2, (value1 < value2) ? value1 : value2)); //handles results and passes GCD 2 values in the order of largest and then smallest
    }
    outfile.close();
    std::cout << "Thank you for using my GCD calculator!\n";
    return 0;
}

void printHeader(std::ostream &output)
{
	 /***********************************************************************
	  * CONSTANTS
	  * ---------------------------------------------------------------------
	  * OUTPUT - USED FOR CLASS HEADING
	  * ---------------------------------------------------------------------
	  * PROGRAMMER : Programmer's Name
	  * CLASS      : Student's Course
	  * SECTION    : Class Days and Times
	  * LAB_NUM    : Lab Number (specific to this lab)
	  * LAB_NAME   : Title of the Lab
	  **********************************************************************/
	const char PROGRAMMER[] = "Carlos Aguilera";
	const char CLASS[]      = "CS1B";
	const char SECTION[]    = "MW: 7:30p - 9:50p";
	const int LAB_NUM       = 3;
	const char LAB_NAME[]   = "GCD";

	/************************************************************************
	 * OUTPUT - Class Heading
	 ***********************************************************************/
	output << std::left;
	output << "****************************************************\n";
	output << "*   PROGRAMMED BY : " << PROGRAMMER << std::endl;
	output << "*   " << std::setw(14) <<"CLASS" << ": " << CLASS << std::endl;
	output << "*   " << std::setw(14) <<"SECTION" << ": " << SECTION << std::endl;
	output << "*   LAB #" << std::setw(9) << LAB_NUM << ": " << LAB_NAME << std::endl;
	output << "****************************************************\n\n";
	output << std::right;
}

std::string printHeader()
{
	 /***********************************************************************
	  * CONSTANTS
	  * ---------------------------------------------------------------------
	  * OUTPUT - USED FOR CLASS HEADING
	  * ---------------------------------------------------------------------
	  * PROGRAMMER : Programmer's Name
	  * CLASS      : Student's Course
	  * SECTION    : Class Days and Times
	  * LAB_NUM    : Lab Number (specific to this lab)
	  * LAB_NAME   : Title of the Lab
	  **********************************************************************/
	const char PROGRAMMER[] = "Carlos Aguilera";
	const char CLASS[]      = "CS1B";
	const char SECTION[]    = "MW: 7:30p - 9:50p";
	const int LAB_NUM       = 3;
	const char LAB_NAME[]   = "GCD";

	/************************************************************************
	 * OUTPUT - Class Heading
	 ***********************************************************************/
    std::ostringstream output;
	output << std::left;
	output << "****************************************************\n";
	output << "*   PROGRAMMED BY : " << PROGRAMMER << std::endl;
	output << "*   " << std::setw(14) <<"CLASS" << ": " << CLASS << std::endl;
	output << "*   " << std::setw(14) <<"SECTION" << ": " << SECTION << std::endl;
	output << "*   LAB #" << std::setw(9) << LAB_NUM << ": " << LAB_NAME << std::endl;
	output << "****************************************************\n\n";
	output << std::right;

    return output.str();
}