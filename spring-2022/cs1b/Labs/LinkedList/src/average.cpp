#include "../include/header.h"
#include "../include/studentNode.h"

void average(StudentNode** head)
{
    StudentNode* node = nullptr;
    node = *head;
    int size = 0;
    float totalGPA = 0;

    while (node != nullptr)
    {
        totalGPA += node->gpa;
        node = node->nextNode;
        ++size;
    }
    std::cout << "Average GPA: " << totalGPA/size << "\n";
}