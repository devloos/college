#include "main.hpp"
/****************************************************************************
 * Title: handleResults
 * --------------------------------------------------------------------------
 * This function will output the results of the program to a file
 * --------------------------------------------------------------------------
 * std::ostream &output OUT - output for file
 * const int &value1 OUT    - value 1 that user entered
 * const int &value2 OUT    - value 2 that user entered
 * const int &GCD OUT       - GCD of the 2 values
 ***************************************************************************/

void handleResults(std::ostream &output, const int &value1, const int &value2, const int &GCD)
{
    output << "The GCD for " << value1 << " & " << value2 << " = " << GCD << "\n\n";
}