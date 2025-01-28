#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <map>
#include <unordered_map>
#include "studentNode.h"

void readData(StudentNode** head, std::map<std::string, StudentNode> &studentData);
void heading();
void dispList(StudentNode* &head);
void pop(StudentNode** head, std::map<std::string, StudentNode> &studentData);
void search(StudentNode* &head, std::map<std::string, StudentNode> &studentData);
void average(StudentNode** head);

#endif