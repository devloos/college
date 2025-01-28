#include "../include/header.h"

void switchCase(const Menu &choice, Person* &head, int &size)
{
    switch (choice)
    {
        case PUSH:
            push(&head, size);
            break;
        case POP:
            pop(&head, size);
            break;
        case ISEMPTY:
            if (isEmpty(&head))
                std::cout << "\nYes, the stack is empty!\n";
            else
                std::cout << "\nThe stack is NOT empty!\n";
            break;
        case PEEK:
            peek(&head);
            break;
        case SIZE:
            if (size == 1)
                std::cout << "\nThere is one person on the stack!\n";
            else if (size > 1)
                std::cout << "\nThere are " << size << " people on the stack!\n";
            else
                std::cout << "\nNobody on the stack!\n";
            break;
        case EXIT:
            std::cout << "Thank you!\n";
            break;
        default:
            std::string strChoice = std::to_string(choice);
            std::cout << std::left;
            std::cout << "\n**** The number " << strChoice << " is an invalid number ";
            std::cout << std::right;
            std::cout << std::setw(10 - strChoice.size()) << "****\n";
            std::cout << "**** Please input a number between 0 and 5 ****\n";
            break;
    }
}