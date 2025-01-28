#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
#include <string>
#include <iomanip>

struct Person {
    std::string name;
    char gender;
    int age;
    Person* nextNode;
};

enum Menu{
    EXIT = 0,
    PUSH,
    POP,
    ISEMPTY,
    PEEK,
    SIZE,
    CLEAR
};

void clearQueue(Person* &head);
void heading();
void displayMenu();
void enqueue(Person** head, Person** tail, int &size);
void pop(Person** head, int &size);
bool isEmpty(Person** head);
Menu switchValidation();
void front(Person** head);
void switchCase(const Menu &choice, Person* &head, Person* &tail, int &size);
void deallocate(Person* &head);

#endif