#include "main.hpp"
/****************************************************************************
 * Title: readValues
 * --------------------------------------------------------------------------
 * This function will read to values from the user as pass by reference
 * --------------------------------------------------------------------------
 * int &value1 IN - reference to value 1 in main
 * int &value2 IN - reference to value 2 in main
 ***************************************************************************/

void readValues(int &value1, int &value2)
{
    std::cout << std::left;
    std::cout << std::setw(26) << "Enter the first integer:";
    std::cin >> value1;
    std::cout << std::setw(26) << "Enter the second integer:";
    std::cin >> value2;
    std::cout << std::right;

    std::cout << "\n";
}