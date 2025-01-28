#include "../include/header.h"
#include "../include/studentNode.h"

void pop(StudentNode** head, std::map<std::string, StudentNode> &studentData)
{
    StudentNode* node = *head;
    if (node != nullptr)
    {
        std::cout << std::left;
        std::cout << "POPPING\n";
        std::cout << std::setw(8) << "Name:" << node->name << "\n";
        std::cout << std::setw(8) << "Age:" << node->age << "\n";
        std::cout << std::setw(8) << "Major:" << node->major << "\n";
        std::cout << std::setw(8) << "GPA:" << node->gpa << "\n\n";
        std::cout << std::right;

        studentData.erase(node->name);
        *head = node->nextNode;
        delete node;
    }else
        std::cout << "The stack is empty!\n\n";
    
}