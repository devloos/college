#include "../include/header.h"

void switchCase(const Menu &choice, Person* &head, Person* &tail, int &size)
{
    switch (choice)
    {
        case PUSH:
            enqueue(&head, &tail, size);
            break;
        case POP:
            pop(&head, size);
            break;
        case ISEMPTY:
            if (isEmpty(&head))
                std::cout << "Yes, the queue is empty!\n";
            else
                std::cout << "The queue is NOT empty!\n";
            break;
        case PEEK:
            front(&head);
            break;
        case SIZE:
            if (size == 1)
                std::cout << "\nThere is one person on the queue!\n";
            else if (size > 1)
                std::cout << "\nThere are " << size << " people on the queue!\n";
            else
                std::cout << "\nNobody on the queue!\n";
            break;
        case CLEAR:
            clearQueue(head);
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