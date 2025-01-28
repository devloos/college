#include "../include/header.h"

void clearQueue(
    Person* &head) //ref to ptr stores head of stack
{
    Person* node = nullptr;

    if (head != nullptr) {
      std::cout << "\nCLEARING...\n";
    }else 
        std::cout << "The QUEUE is ALREADY clear!\n";

    //PROCCESSING - while head not nullptr
    while (head != nullptr)
    {
        //PROCCESSING - node = head & head = .nextNode then node deallocated
        node = head;
        std::cout << node->name << "\n";
        head = node->nextNode;
        delete node;
    }
    head = nullptr;
}