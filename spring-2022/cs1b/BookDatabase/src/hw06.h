/*
 * Linked List Book Database
 * Carlos Aguilera
 * Dr. B Cs1b
 */

#ifndef HW06_HW06_H
#define HW06_HW06_H
#include <iostream>

typedef struct BookList BookList;
typedef struct BookEntry BookEntry;
typedef struct BookData BookData;

struct BookList
{
    int rc;
    BookEntry *head;
    BookEntry *tail;
};

struct BookEntry
{
    BookList *lst;
    BookEntry *nxt;
    BookEntry *prv;
    BookData *dat;
};

struct BookData
{
    std::string isdn;
    std::string author;
    std::string title;
};

void menu();
void addbook();
void delbook();
void showbook();
void showbooks();
#endif //HW06_HW06_H
