#include "../include/header.h"

void deallocate(Person* &head)
{
    Person* node = nullptr;

    while (head != nullptr)
    {
        node = head;
        head = node->nextNode;
        delete node;
    }
}