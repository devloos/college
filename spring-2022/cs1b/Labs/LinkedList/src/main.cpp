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
    std::map<std::string, StudentNode> studentData;
	readData(&head, studentData);//a ptr to ptr for accesses the ptr in main

	search(head, studentData);
	pop(&head, studentData);
	average(&head);
	dispList(head);

	return 0;
}