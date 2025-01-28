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
    SIZE
};

void heading();
void displayMenu();
void push(Person** head, int &size);
void pop(Person** head, int &size);
bool isEmpty(Person** head);
Menu switchValidation();
void peek(Person** head);
void switchCase(const Menu &choice, Person* &head, int &size);
void deallocate(Person* &head);

#endif