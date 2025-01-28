/*****************************************************************************
 * AUTHOR      : Carlos Aguilera
 * STUDENT ID  : 1152562
 * LAB #4      : Intro to Arrays
 * CLASS       : CS1B
 * SECTION     : M-W
 * DUE DATE    : 02.16.22 
 ****************************************************************************/

#include "../include/main.hpp"

/****************************************************************************
 * Title: Intro to Arrays
 * --------------------------------------------------------------------------
 * This program will take 10 name inputs from the keyboard and console out
 * how many instances there were of a certain name chosen by the user.
 * --------------------------------------------------------------------------
 * const int AR_SIZE {10}; CALC - How big the array needs to be
 * std::string names[AR_SIZE]; - holds array of names type is string
 * std::string inputName {}; IN & CALC - input of name to be found
 * int inputNameInstances {0}; CALC - calculates how many instances of a name was found
 ***************************************************************************/
const int AR_SIZE {10};
int main()
{
    printHeading();

    std::string names[AR_SIZE];
    for(size_t i {0}; i < AR_SIZE; i++) // This for loop is going to take all ten inputs and store a name in each element
    {
        std::cout << "Enter name #" << i+1 << ": ";
        std::cin >> names[i];
    }

    std::string inputName {};
    do
    {
        std::cout << "\nWho do you want to search for(enter done to exit)? ";
        std::cin >> inputName;

        if(inputName != "done")
        {
            int inputNameInstances {0};
            for(auto name : names)
                if(inputName == name)//if the input name equals current name in the array then we increment inputNameInstances
                    ++inputNameInstances;

            if(inputNameInstances > 1)//execption handling on different outputs
                std::cout << "There are " << inputNameInstances << " instances of the name " << inputName << ".\n";
            else if(inputNameInstances == 1)
                std::cout << "There is one instance of the name " << inputName << ".\n";
            else if(inputNameInstances == 0)
                std::cout << inputName << "'s name does not exist in the list.\n";
        }

    } while (inputName != "done");

    std::cout << "Thank you for using my program!\n";
    return 0;
}