//
// Created by Carlos Aguilera on 3/22/20.
//
#include "hw06.h"

void menu()
{
    int choice;

    while(std::cin)
    {
        std::cout << "Select from the following options:" << std::endl;
        std::cout << "  1. Add a book" << std::endl;
        std::cout << "  2. Delete a book" << std::endl;
        std::cout << "  3. Display a book" << std::endl;
        std::cout << "  4. Display all books" << std::endl;
        std::cout << "  5. Save and exit" << std::endl;
        std::cout << std::endl;
        std::cout << "Enter your choice: ";

        std::cin >> choice;

        if(choice == 1)
        {
            addbook();
        }
        if(choice == 2)
        {
            delbook();
        }
        if(choice  == 3)
        {
            showbook();
        }
        if(choice == 4)
        {
            showbooks();
        }
        if(choice == 5)
        {
            break;
        }//else
            //std::cout << "Entered invalid character!\n";
    }
}