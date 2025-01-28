#include "../include/header.h"
#include "../include/studentNode.h"

void search(StudentNode* &head, std::map<std::string, StudentNode> &studentData)
{
    std::string key;

    std::cout << "Enter name of student to search: ";
    std::getline(std::cin, key);


    if (studentData.find(key) != studentData.end()) //Using .find method in the map to find key 
    {
        StudentNode node = studentData[key];

        std::cout << std::left;
        std::cout << "\nFOUND\n--------";
        std::cout << std::setw(9) << "\nName:" << node.name << "\n";
        std::cout << std::setw(8) << "Age:" << node.age << "\n";
        std::cout << std::setw(8) << "Major:" << node.major << "\n";
        std::cout << std::setw(8) << "GPA:" << node.gpa << "\n\n";
        std::cout << std::right;
    }else
        std::cout << "Student was not found!\n";
}