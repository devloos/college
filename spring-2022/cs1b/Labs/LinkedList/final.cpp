#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <map>
#include <unordered_map>
#include "studentNode.h"

using namespace std;

void readData(StudentNode** head, map<string, StudentNode> &studentData);
void heading();
void dispList(StudentNode* &head);
void pop(StudentNode** head, map<string, StudentNode> &studentData);
void search(StudentNode* &head, map<string, StudentNode> &studentData);
void average(StudentNode** head);

#endif

#ifndef _STUDENTNODE_H_
#define _STUDENTNODE_H_
#include "header.h"

struct StudentNode {
	string name;
	int age;
	string major;
	float gpa;
	StudentNode* nextNode;
};

#endif

#include "../include/header.h"
#include "../include/studentNode.h"

int main() 
{
	heading();
	StudentNode* head = nullptr;
	/*
		Using map to get myself understanding hashing and Big O(1) with hashing
		so I used an ordered map just to keep the elements in the map the same as what 
		was read in the file, also made the name the id to hash
	*/
    map<string, StudentNode> studentData;
	readData(&head, studentData);//a ptr to ptr for accesses the ptr in main

	search(head, studentData);
	pop(&head, studentData);
	average(&head);
	dispList(head);

	return 0;
}

#include "../include/header.h"
#include "../include/studentNode.h"

void readData(StudentNode** head, map<string, StudentNode> &studentData) 
{
    StudentNode* node = nullptr;
    node = new StudentNode;
    *head = node;
    string temp;

    ifstream inFile;
    inFile.open("inFile.txt");
    if (inFile.is_open()) 
    {
        while (!inFile.eof()) 
        {
            getline(inFile, node->name);
            inFile >> node->age;
            inFile.ignore(1000, '\n');
            getline(inFile, node->major);
            inFile >> node->gpa;
            inFile.ignore(1000, '\n');
            getline(inFile, temp);

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
        cout << "File did not open successfully!\n";
        delete node;
    }
    
    inFile.close();
}

#include "../include/header.h"
#include "../include/studentNode.h"

void dispList(StudentNode* &head)
{
	StudentNode* node = head;
	while (node != nullptr)
	{
		cout << node->name << "\n";
		cout << "------------------\n";
		cout << node->age << "\n";
		cout << node->major << "\n";
		cout << node->gpa << "\n\n";
		node = node->nextNode;
	}

}

#include "../include/header.h"
#include "../include/studentNode.h"

void pop(StudentNode** head, map<string, StudentNode> &studentData)
{
    StudentNode* node = *head;
    if (node != nullptr)
    {
        cout << left;
        cout << "POPPING\n";
        cout << setw(8) << "Name:" << node->name << "\n";
        cout << setw(8) << "Age:" << node->age << "\n";
        cout << setw(8) << "Major:" << node->major << "\n";
        cout << setw(8) << "GPA:" << node->gpa << "\n\n";
        cout << right;

        studentData.erase(node->name);
        *head = node->nextNode;
        delete node;
    }else
        cout << "The stack is empty!\n\n";
    
}

#include "../include/header.h"
#include "../include/studentNode.h"

void search(StudentNode* &head, map<string, StudentNode> &studentData)
{
    string key;

    cout << "Enter name of student to search: ";
    getline(cin, key);


    if (studentData.find(key) != studentData.end()) //Using .find method in the map to find key 
    {
        StudentNode node = studentData[key];

        cout << left;
        cout << "\nFOUND\n--------";
        cout << setw(9) << "\nName:" << node.name << "\n";
        cout << setw(8) << "Age:" << node.age << "\n";
        cout << setw(8) << "Major:" << node.major << "\n";
        cout << setw(8) << "GPA:" << node.gpa << "\n\n";
        cout << right;
    }else
        cout << "Student was not found!\n";
}

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
    cout << "Average GPA: " << totalGPA/size << "\n";
}