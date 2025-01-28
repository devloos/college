/*****************************************************************************
 * AUTHOR      : Carlos Aguilera
 * STUDENT ID  : 1152562
 * LAB #8      : Implementing a Stack
 * CLASS       : CS1B
 * SECTION     : M-W
 * DUE DATE    : 03.31.22
 ****************************************************************************/

/****************************************************************************
 * Title:
 * --------------------------------------------------------------------------
 * FUNCTION:
 * --------------------------------------------------------------------------
 * Data Table
 * ----------
 ***************************************************************************/

#include "../include/header.h"

int main()
{
    heading();
    int size = 0;
    Person* head = nullptr;
    Person* tail = nullptr;
    Menu choice = EXIT;

    do
    {
        displayMenu();
        choice = switchValidation();
        switchCase(choice, head, tail, size);
    } while (choice != EXIT);

    deallocate(head);
    return 0;    
}