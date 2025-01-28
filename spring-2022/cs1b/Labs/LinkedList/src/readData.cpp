#include "../include/header.h"
#include "../include/studentNode.h"

void readData(StudentNode** head, std::map<std::string, StudentNode> &studentData) 
{
    StudentNode* node = nullptr;
    node = new StudentNode;
    *head = node;
    std::string temp;

    std::ifstream inFile;
    inFile.open("inFile.txt");
    if (inFile.is_open()) 
    {
        while (!inFile.eof()) 
        {
            std::getline(inFile, node->name);
            inFile >> node->age;
            inFile.ignore(1000, '\n');
            std::getline(inFile, node->major);
            inFile >> node->gpa;
            inFile.ignore(1000, '\n');
            std::getline(inFile, temp);

            if (node->name[node->name.size() - 1] == ' ')
            {
                node->name = node->name.substr(0, node->name.size() - 1);
            }

            if (node->major[node->major.size() - 1] == ' ')
            {
                node->major = node->major.substr(0, node->major.size() - 1);
            }

            studentData[node->name] = *node;

            if (!inFile.eof()) 
            {
                node->nextNode = new StudentNode;
                node = node->nextNode;
            }else
                node->nextNode = nullptr;
        }
    }else {
        std::cout << "File did not open successfully!\n";
        delete node;
    }
    
    inFile.close();
}