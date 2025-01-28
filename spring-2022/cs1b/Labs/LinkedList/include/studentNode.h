#ifndef _STUDENTNODE_H_
#define _STUDENTNODE_H_
#include "header.h"

struct StudentNode {
	std::string name;
	int age;
	std::string major;
	float gpa;
	StudentNode* nextNode;
};

#endif