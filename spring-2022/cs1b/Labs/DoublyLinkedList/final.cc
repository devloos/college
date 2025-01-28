#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

struct MovieRec {
  string movieTitle;
  string genre;
  int releaseYear;
  MovieRec* next;
  MovieRec* prev;
};
enum Choice {
  EXIT = 0,
  ADD,
  REMOVE,
  DISPLAY
};

void readInput(MovieRec* &node, fstream &inFile);
void nodePlacement(MovieRec* &head, MovieRec* &tail, MovieRec* node, MovieRec* &currMovieRec);
void placeMovieRecFront(MovieRec* &head, MovieRec* &currMovieRec, MovieRec* &node);
void createList(MovieRec* &head, MovieRec* &tail);
void insertMovieRec(MovieRec* &node, MovieRec* &currMovieRec);
void placeMovieRecBack(MovieRec* &tail, MovieRec* &currMovieRec, MovieRec* &node);
void displayHeader();
void displayMenu();
void displayList(MovieRec* &head);
void validateInput(Choice &choice);
void removeMovieRec(MovieRec* &head, MovieRec* &tail, string searchKey);

#endif // HEADER_H_

#include "../include/header.h"

int main() {
  MovieRec* head = nullptr;
  MovieRec* tail = nullptr;
  createList(head, tail);

  Choice choice = EXIT;
  do {
    displayMenu();
    validateInput(choice);
    switch (choice) {
      case EXIT: {
        break;
      }
      case ADD: {
        MovieRec* node = new MovieRec;

        cout << "Enter Movie details\n";
        cout << "Movie Title: ";
        cin.ignore(1000, '\n');
        getline(cin, node->movieTitle);
        cout << "Movie Genre: ";
        getline(cin, node->genre);
        cout << "Release Year: ";
        cin >> node->releaseYear;
        cin.ignore(1000, '\n');

        nodePlacement(head, tail, nullptr, node);
        node = nullptr;
        cout << "\n";
        break;
      }
      case REMOVE: {
        string key;
        cout << "Enter Movie to remove\n";
        cout << "Movie Title: ";
        cin.ignore(1000, '\n');
        getline(cin, key);
        removeMovieRec(head, tail, key);
        break;
      }
      case DISPLAY: {
        displayList(head);
        break;
      }
      default: {
        cout << "Enter number between 0 - 3\n";
        break;
      }
    }
  }while (choice != EXIT);
  return 0;
}

/*******************************************************************************
 * createList
 -------------------------------------------------------------------------------
 * FUNCTION: takes in head and tail and creates linked
 * list handles the calling of readInput and node
 * placement runs until end of file
 * @param head ptr to head of linked list 
 * @param tail ptr to tail of linked list 
 * RETURNS: void
 ******************************************************************************/
#include "../../include/header.h"

void createList(MovieRec* &head, MovieRec* &tail) {
  // Creating input file
  fstream inFile;
  inFile.open("inFile.txt", ios::in);

  if (!inFile.eof()) {
    // New MovieRec getting allocated in the heap
    MovieRec* node = new MovieRec;
    // node gets assigned to tail and tail gets assigned to head
    head = tail = node;
    // PROCCESSING - reading input from file to node
    readInput(node, inFile); 
    
    MovieRec* currMovieRec = nullptr;
    while (!inFile.eof()) {
      currMovieRec = new MovieRec;
      readInput(currMovieRec, inFile);
      // PROCCESSING - current node placement being handled
      nodePlacement(head, tail, node, currMovieRec);
    }
  }
  cout << "\n";
  inFile.close();
}

/*******************************************************************************
 * readInput
 ------------------------------------------------------------------------------- 
 * FUNCTION: reads input from file from single node 
 * being passed in
 * @param node ptr to node being passed in
 * @param inFile passed by ref to access reading file
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void readInput(MovieRec* &node, fstream &inFile) {
  getline(inFile, node->movieTitle);
  // PROCCESSING - if the last character of the string == ' ' then substr
  if (node->movieTitle[node->movieTitle.size() - 1] == ' ') {
    node->movieTitle = node->movieTitle.substr(0, node->movieTitle.find_last_of(' '));
  }
  getline(inFile, node->genre);
  // PROCCESSING - if the last character of the string == ' ' then substr
  if (node->genre[node->genre.size() - 1] == ' ') {
    node->genre = node->genre.substr(0, node->genre.find_last_of(' '));
  }
  inFile >> node->releaseYear;
  inFile.ignore(1000, '\n');
}

/*******************************************************************************
 * placeMovieRecFront
 ------------------------------------------------------------------------------- 
 * FUNCTION: this function places current node on the
 * front of the linked list 
 * @param head ptr to head of linked list
 * @param currMovieRec ptr to current node of linked list
 * @param node ptr a node on the linked list
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void placeMovieRecFront(MovieRec* &head, MovieRec* &currMovieRec, MovieRec* &node) {
  node->prev = currMovieRec;
  currMovieRec->next = node;
  head = currMovieRec;
}

/*******************************************************************************
 * placeMovieRecBack
 ------------------------------------------------------------------------------- 
 * FUNCTION: this function places current node on the
 * back of the linked list 
 * @param head ptr to head of linked list
 * @param currMovieRec ptr to current node of linked list
 * @param node ptr a node on the linked list
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void placeMovieRecBack(MovieRec* &tail, MovieRec* &currMovieRec, MovieRec* &node) {
  tail = currMovieRec;
  node->next = tail;
  tail->prev = node;
}

/*******************************************************************************
 * insertMovieRec
 ------------------------------------------------------------------------------- 
 * FUNCTION: places current node in between two nodes
 * @param currMovieRec ptr to current node of linked list
 * @param node ptr a node on the linked list
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void insertMovieRec(MovieRec* &node, MovieRec* &currMovieRec) {
  node->prev->next = currMovieRec;
  currMovieRec->prev = node->prev;
  node->prev = currMovieRec;
  currMovieRec->next = node;
}

/*******************************************************************************
 * displayMenu
 ------------------------------------------------------------------------------- 
 * FUNCTION: handles the menu display
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void displayMenu() {
  cout << right;
  cout << "LIST MENU:\n";
  cout << "1 - Add Movie\n";
  cout << "2 - Remove Movie\n";
  cout << "3 - Display List\n";
  cout << "0 - to Exit\n";
  cout << left;
}

/*******************************************************************************
 * displayHeader
 ------------------------------------------------------------------------------- 
 * FUNCTION: displays header for the displayList
 * function
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void displayHeader() {
  cout << left
            << "   " << setw(5) << "#" << setw(28) << "NAME"
            << setw(9) << "GENRE" << setw(4) << "YEAR\n"
            << "-------" << " -------------------------" << "  --------" 
            << " -----\n" << right;
}

/*******************************************************************************
 * validateInput
 ------------------------------------------------------------------------------- 
 * FUNCTION: handles the validation on input of Menu
 * choice this is accomplished by a try catch method
 * that uses a .fail as its way of knowing if cin
 * failed
 * @param choice enum of Menu used for switch case
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void validateInput(Choice &choice) {
  int n; // take in an int... instead of overloading the extraction operator
  bool valid = false;
  do {
    try {
      cout << "Enter a command (0 to exit): ";
      cin >> n;
      // PROCCESSING - if cin.fail then we throw an execption
      if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        throw true;
      }
      // static cast to an Menu to store in choice
      choice = static_cast<Choice>(n);
      valid = true;
    }catch (bool invalid) {
      cout << "**** Please input a NUMBER between 0 and 3 ****\n";
    }
  } while (!valid);
  return;
}

/*******************************************************************************
 * removeMovieRec
 ------------------------------------------------------------------------------- 
 * FUNCTION: handles the removing of a node in any pos
 * this is done by checking whether node.prev or node.
 * next equals null we run a separate function to 
 * remove node 
 * @param head ptr to head of linked list
 * @param tail ptr to tail of linked list
 * @param searchKey key for searching name inputed by
 * user
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void removeMovieRec(MovieRec* &head, MovieRec* &tail, string searchKey) {
  MovieRec* node = head;
  cout << "\nSearching for " << searchKey << "...\n\n";
  while (node != nullptr) {
    // PROCCESSING - iterate through linked list until found
    if (node->movieTitle == searchKey) {
      // if node was found in head
      if (node->prev == nullptr) {
        head = node->next;
        node->next->prev = nullptr;
      }else if (node->next == nullptr) { // if node was found in tail
        tail = node->prev;
        node->prev->next = nullptr;
      }else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
      }
      cout << "Removing " << node->movieTitle << "\n\n";
      delete node;
      return;
    }
    node = node->next;
  }
  // if node was not found
  cout << "I'm sorry, \"" << searchKey << "\" was NOT found!\n\n";
  return;
}

/*******************************************************************************
 * nodePlacement
 ------------------------------------------------------------------------------- 
 * FUNCTION: handles where to place the node by 
 * going through the linked list from head every time
 * its called and using the string compare method
 * @param head ptr to head of linked list
 * @param tail ptr to tail of linked list
 * @param currMovieRec ptr to current node of linked list
 * @param node ptr a node on the linked list
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void nodePlacement(MovieRec* &head, MovieRec* &tail, MovieRec* node, MovieRec* &currMovieRec) {
  bool placed = false;
  // node = head so we don't mess with head when not wanting to 
  node = head;
  while (!placed) {
    // PROCCESSING - if obj.name first character is lower in the ascii table
    // then place in front node
    if (currMovieRec->movieTitle.compare(node->movieTitle) < 0) {
      placed = true;
      // PROCCESSING - if front of node is null 
      if (node->prev == nullptr) {
        placeMovieRecFront(head, currMovieRec, node);
      }else {
        insertMovieRec(node, currMovieRec);
      }
    }else if (node->next == nullptr) { // currMovieRec is bigger than all names
      placeMovieRecBack(tail, currMovieRec, node);
      placed = true;
    }else {
      node = node->next;// move through list
    }
  }
}

/*******************************************************************************
 * handleDisplayList
 ------------------------------------------------------------------------------- 
 * FUNCTION: handles the displaying of all nodes in
 * the linked list by iterating through until node
 * is null
 * @param head ptr to head of linked list
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void displayList(MovieRec* &head) {
  // counter for output
  int count = 1;
  MovieRec* node = head;

  displayHeader();
  // if list is not empty then displayHeader
  while (node != nullptr) {
    cout << right;
    cout << setw(4) << count;
    cout << left;
    cout << "    " << setw(28) << node->movieTitle << setw(9);
    cout << node->genre << setw(4) << node->releaseYear << "\n";
    ++count;
    node = node->next;
  }
  cout << "\n";
}