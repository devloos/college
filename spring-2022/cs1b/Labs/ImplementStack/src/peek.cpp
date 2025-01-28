#include "../include/header.h"

void peek(Person** head)
{
    Person* node = *head;
    if (isEmpty(&node))
        std::cout << "\nThere is nobody to peek at!!\n";
    else
    {
        std::cout << std::left;
        std::cout << "\nPEEKING\n";
        std::cout << std::setw(8) << "Name:" << node->name << "\n";
        std::cout << std::setw(8) << "Gender:" << node->gender << "\n";
        std::cout << std::setw(8) << "Age:" << node->age << "\n";
        std::cout << std::right;
    }
}