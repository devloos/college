#include "main.h"

void displayHeader()
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
	const int LAB_NUM       = 1;
	const char LAB_NAME[]   = "";

	// (variable declerations go here)


	/************************************************************************
	 * OUTPUT - Class Heading
	 ***********************************************************************/
	std::cout << std::left;
	std::cout << "****************************************************\n";
	std::cout << "*   PROGRAMMED BY : " << PROGRAMMER << std::endl;
	std::cout << "*   " << std::setw(14) <<"CLASS" << ": " << CLASS << std::endl;
	std::cout << "*   " << std::setw(14) <<"SECTION" << ": " << SECTION << std::endl;
	std::cout << "*   LAB #" << std::setw(9) << LAB_NUM << ": " << LAB_NAME << std::endl;
	std::cout << "****************************************************\n\n";
	std::cout << std::right;
}