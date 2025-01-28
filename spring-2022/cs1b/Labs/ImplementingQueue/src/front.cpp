#include "../include/header.h"

void front(Person** head)
{
    Person* node = *head;
    if (isEmpty(&node))
        std::cout << "\nNobody in FRONT, queue is empty!!\n";
    else
    {
        std::cout << std::left;
        std::cout << "\nThe first person in the queue is:\n";
        std::cout << std::setw(8) << "Name:" << node->name << "\n";
        std::cout << std::setw(8) << "Gender:" << node->gender << "\n";
        std::cout << std::setw(8) << "Age:" << node->age << "\n";
        std::cout << std::right;
    }
}