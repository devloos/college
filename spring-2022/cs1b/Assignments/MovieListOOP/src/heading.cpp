#include <iostream>
#include <iomanip>

void heading(std::ostream &os) {

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
	const int LAB_NUM       = 5;
	const char LAB_NAME[]   = "Movie List OOP";

	os << std::left;
	os << "****************************************************\n";
	os << "*   PROGRAMMED BY : " << PROGRAMMER << std::endl;
	os << "*   " << std::setw(14) <<"CLASS" << ": " << CLASS << std::endl;
	os << "*   " << std::setw(14) <<"SECTION" << ": " << SECTION << std::endl;
	os << "*   LAB #" << std::setw(9) << LAB_NUM << ": " << LAB_NAME << std::endl;
	os << "****************************************************\n\n";
	os << std::right;
}