#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

struct Node {
 public:
  string name;
  char gender;
  int age;
  Node* next;
  Node* prev;
  // Constructors
  // Initializes next and prev to nullptr every time an object is made
  Node() : next(nullptr), prev(nullptr) {}
};

enum Menu {
  Exit = 0,
  CreateList,
  DisplayList,
  IsEmpty,
  SearchName,
  RemoveNode,
  ClearList
};

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
void createList(Node* &head, Node* &tail);

/*******************************************************************************
 * readInput
 ------------------------------------------------------------------------------- 
 * FUNCTION: reads input from file from single node 
 * being passed in
 * @param node ptr to node being passed in
 * @param inFile passed by ref to access reading file
 * RETURNS - void
 ******************************************************************************/
void readInput(Node* &node, fstream &inFile);

/*******************************************************************************
 * placeNodeFront
 ------------------------------------------------------------------------------- 
 * FUNCTION: this function places current node on the
 * front of the linked list 
 * @param head ptr to head of linked list
 * @param currNode ptr to current node of linked list
 * @param node ptr a node on the linked list
 * RETURNS - void
 ******************************************************************************/
void placeNodeFront(Node* &head, Node* &currNode, Node* &node);

/*******************************************************************************
 * placeNodeBack
 ------------------------------------------------------------------------------- 
 * FUNCTION: this function places current node on the
 * back of the linked list 
 * @param head ptr to head of linked list
 * @param currNode ptr to current node of linked list
 * @param node ptr a node on the linked list
 * RETURNS - void
 ******************************************************************************/
void placeNodeBack(Node* &tail, Node* &currNode, Node* &node);

/*******************************************************************************
 * insertNode
 ------------------------------------------------------------------------------- 
 * FUNCTION: places current node in between two nodes
 * @param currNode ptr to current node of linked list
 * @param node ptr a node on the linked list
 * RETURNS - void
 ******************************************************************************/
void insertNode(Node* &node, Node* &currNode);

/*******************************************************************************
 * handleNodePlacement
 ------------------------------------------------------------------------------- 
 * FUNCTION: handles where to place the node by 
 * going through the linked list from head every time
 * its called and using the string compare method
 * @param head ptr to head of linked list
 * @param tail ptr to tail of linked list
 * @param currNode ptr to current node of linked list
 * @param node ptr a node on the linked list
 * RETURNS - void
 ******************************************************************************/
void handleNodePlacement(Node* &head, Node* &tail, Node* &node, Node* &currNode);

/*******************************************************************************
 * displayHeader
 ------------------------------------------------------------------------------- 
 * FUNCTION: displays header for the displayList
 * function
 * RETURNS - void
 ******************************************************************************/
void displayHeader();

/*******************************************************************************
 * handleDisplayList
 ------------------------------------------------------------------------------- 
 * FUNCTION: handles the displaying of all nodes in
 * the linked list by iterating through until node
 * is null
 * @param head ptr to head of linked list
 * RETURNS - void
 ******************************************************************************/
void handleDisplayList(Node* &head);

/*******************************************************************************
 * displayMenu
 ------------------------------------------------------------------------------- 
 * FUNCTION: handles the menu display
 * RETURNS - void
 ******************************************************************************/
void displayMenu();

/*******************************************************************************
 * isListEmpty
 ------------------------------------------------------------------------------- 
 * FUNCTION: returns true if list is empty else false
 * this is done by checking if head is null
 * @param head ptr to head of linked list
 * RETURNS - bool
 ******************************************************************************/
bool isListEmpty(Node* &head);

/*******************************************************************************
 * searchName
 ------------------------------------------------------------------------------- 
 * FUNCTION: searches linked list with key and returns
 * true if found else, this is done by iterating 
 * through linked list until null and comparing string
 * by string
 * @param head ptr to head of linked list
 * @param searchKey key for searching name inputed by
 * user
 * RETURNS - bool
 ******************************************************************************/
bool searchName(Node* &head, string searchKey);

/*******************************************************************************
 * removeNode
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
void removeNode(Node* &head, Node* &tail, string searchKey);

/*******************************************************************************
 * clearList
 ------------------------------------------------------------------------------- 
 * FUNCTION: handles the clearing of linked list this
 * is also used for my deallocation at the end of prog
 * if list is not empty
 * @param head ptr to head of linked list
 * @param tail ptr to tail of linked list
 * RETURNS - void
 ******************************************************************************/
void clearList(Node* &head, Node* &tail);

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
void validateInput(Menu &choice);

/*******************************************************************************
 * handleSwitch
 ------------------------------------------------------------------------------- 
 * FUNCTION: handles all movement of choice that the user chooses this is done
 * by a switch case statement
 * @param head ptr to head of linked list
 * @param tail ptr to tail of linked list
 * RETURNS - void
 ******************************************************************************/
void handleSwitch(Node* &head, Node* &tail);

/*******************************************************************************
 * heading
 ------------------------------------------------------------------------------- 
 * FUNCTION: handles displaying class header
 * RETURNS - void
 ******************************************************************************/
void heading();
#endif // HEADER_H_

/*******************************************************************************
 * AUTHOR      : Carlos Aguilera
 * STUDENT ID  : 1152562
 * LAB #10     : Creating Ordered List
 * CLASS       : CS1B
 * SECTION     : M-W
 * DUE DATE    : 04.18.22
 ******************************************************************************/

/******************************************************************************
 * Creating an Ordered List
 * ----------------------------------------------------------------------------
 * PROGRAM: This program creates a doubly linked list on the heap and grabs
 * data from a input file. Holds two primary variables,
 * @param head ptr to head of the list
 * @param tail ptr to tail of the list
 * these to variables are used to access the linked list at all times through
 * the program. Some of the functionality you can do as a user is create list,
 * display list, check if list is empty, search a name in the list, remove
 * a node from the list, and clear list. Here is a demo of the create list 
 * function:
 *  LIST MENU
 *  1 - Create List
 *  2 - Display List
 *  3 - Is the list empty?
 *  4 - Search by name
 *  5 - Remove node
 *  6 - Clear List
 *  0 - to Exit
 *  Enter a command (0 to exit): 1

 *  Adding : Payne, Royal
 *  Adding : Ding, Bill
 *  Adding : Post, Mark
 *  Adding : Sassin, Anna
 *  Adding : Lear, Shanda
 *  Adding : Longbottom, Iva
 *  Adding : Dwyer, Barb
 *  Adding : Hogg, Ima
 *  Adding : Belcher, Ura
 *  Adding : Age, Sue
 * 
 * ----------------------------------------------------------------------------
 ******************************************************************************/

#include "../include/header.h"

int main() {
  Node* head = nullptr;
  Node* tail = nullptr;
  heading();
  handleSwitch(head, tail);
  clearList(head, tail);
  return 0;
}

#include "../../include/header.h"

void heading() {

	/***********************************************************************
	 * CONSTANTS
	 * ---------------------------------------------------------------------
	 * OUTPUT - USED FOR CLASS HEADING
	 * ---------------------------------------------------------------------
	 * PROGRAMMER : Programmer's Name
	 * CLASS      : Student's Course
	 * SECTION    : Class Days and Times
	 * LAB_NUM    : Lab Number (specific to this lab)
	 * LAB_NAME   : Title of the Lab
	 **********************************************************************/
	const char PROGRAMMER[] = "Carlos Aguilera";
	const char CLASS[]      = "CS1B";
	const char SECTION[]    = "MW: 7:30p - 9:50p";
	const int LAB_NUM       = 10;
	const char LAB_NAME[]   = "Creating Ordered List";

	cout << left;
	cout << "****************************************************\n";
	cout << "*   PROGRAMMED BY : " << PROGRAMMER << endl;
	cout << "*   " << setw(14) <<"CLASS" << ": " << CLASS << endl;
	cout << "*   " << setw(14) <<"SECTION" << ": " << SECTION << endl;
	cout << "*   LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME << endl;
	cout << "****************************************************\n\n";
	cout << right;
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

void createList(Node* &head, Node* &tail) {
  // Creating input file
  fstream inFile;
  inFile.open("inFile.txt", ios::in);

  if (!inFile.eof()) {
    // New Node getting allocated in the heap
    Node* node = new Node;
    // node gets assigned to tail and tail gets assigned to head
    head = tail = node;
    // PROCCESSING - reading input from file to node
    readInput(node, inFile); 
    
    Node* currNode = nullptr;
    while (!inFile.eof()) {
      currNode = new Node;
      readInput(currNode, inFile);
      // PROCCESSING - current node placement being handled
      handleNodePlacement(head, tail, node, currNode);
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

void readInput(Node* &node, fstream &inFile) {
  // temp for '\n' 
  string temp;
  getline(inFile, node->name);
  // PROCCESSING - if the last character of the string == ' ' then substr
  if (node->name[node->name.size() - 1] == ' ') {
    node->name = node->name.substr(0, node->name.find_last_of(' '));
  }
  inFile.get(node->gender);
  inFile.ignore(1000, ' ');
  inFile >> node->age;
  inFile.ignore(1000, '\n');
  getline(inFile, temp);

  cout << "Adding : " << node->name << "\n";
}

/*******************************************************************************
 * placeNodeFront
 ------------------------------------------------------------------------------- 
 * FUNCTION: this function places current node on the
 * front of the linked list 
 * @param head ptr to head of linked list
 * @param currNode ptr to current node of linked list
 * @param node ptr a node on the linked list
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void placeNodeFront(Node* &head, Node* &currNode, Node* &node) {
  node->prev = currNode;
  currNode->next = node;
  head = currNode;
}

/*******************************************************************************
 * placeNodeBack
 ------------------------------------------------------------------------------- 
 * FUNCTION: this function places current node on the
 * back of the linked list 
 * @param head ptr to head of linked list
 * @param currNode ptr to current node of linked list
 * @param node ptr a node on the linked list
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void placeNodeBack(Node* &tail, Node* &currNode, Node* &node) {
  tail = currNode;
  node->next = tail;
  tail->prev = node;
}

/*******************************************************************************
 * insertNode
 ------------------------------------------------------------------------------- 
 * FUNCTION: places current node in between two nodes
 * @param currNode ptr to current node of linked list
 * @param node ptr a node on the linked list
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void insertNode(Node* &node, Node* &currNode) {
  node->prev->next = currNode;
  currNode->prev = node->prev;
  node->prev = currNode;
  currNode->next = node;
}

/*******************************************************************************
 * handleNodePlacement
 ------------------------------------------------------------------------------- 
 * FUNCTION: handles where to place the node by 
 * going through the linked list from head every time
 * its called and using the string compare method
 * @param head ptr to head of linked list
 * @param tail ptr to tail of linked list
 * @param currNode ptr to current node of linked list
 * @param node ptr a node on the linked list
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void handleNodePlacement(Node* &head, Node* &tail, Node* &node, Node* &currNode) {
  bool placed = false;
  // node = head so we don't mess with head when not wanting to 
  node = head;
  while (!placed) {
    // PROCCESSING - if obj.name first character is lower in the ascii table
    // then place in front node
    if (currNode->name.compare(node->name) < 0) {
      placed = true;
      // PROCCESSING - if front of node is null 
      if (node->prev == nullptr) {
        placeNodeFront(head, currNode, node);
      }else {
        insertNode(node, currNode);
      }
    }else if (node->next == nullptr) { // currNode is bigger than all names
      placeNodeBack(tail, currNode, node);
      placed = true;
    }else {
      node = node->next;// move through list
    }
  }
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
            << setw(9) << "GENDER" << setw(4) << "AGE\n"
            << "-------" << " -------------------------" << "  --------" 
            << " -----\n" << right;
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

void handleDisplayList(Node* &head) {
  // counter for output
  int count = 1;
  Node* node = head;

  // if list is not empty then displayHeader
  if (!isListEmpty(node)) {displayHeader();}
  while (node != nullptr) {
    cout << right;
    cout << setw(4) << count;
    cout << left;
    cout << "    " << setw(30) << node->name << setw(7);
    cout << node->gender << setw(4) << node->age << "\n";
    ++count;
    node = node->next;
  }
  cout << "\n";
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
  cout << "1 - Create List\n";
  cout << "2 - Display List\n";
  cout << "3 - Is the list empty?\n";
  cout << "4 - Search by name\n";
  cout << "5 - Remove node\n";
  cout << "6 - Clear List\n";
  cout << "0 - to Exit\n";
  cout << left;
}

/*******************************************************************************
 * isListEmpty
 ------------------------------------------------------------------------------- 
 * FUNCTION: returns true if list is empty else false
 * this is done by checking if head is null
 * @param head ptr to head of linked list
 * RETURNS - bool
 ******************************************************************************/
#include "../../include/header.h"

bool isListEmpty(Node* &head) {
  return (head == nullptr);
}

/*******************************************************************************
 * searchName
 ------------------------------------------------------------------------------- 
 * FUNCTION: searches linked list with key and returns
 * true if found else, this is done by iterating 
 * through linked list until null and comparing string
 * by string
 * @param head ptr to head of linked list
 * @param searchKey key for searching name inputed by
 * user
 * RETURNS - bool
 ******************************************************************************/
#include "../../include/header.h"

bool searchName(Node* &head, string searchKey) {
  Node* node = head;
  cout << "\nSearching for " << searchKey << "...\n\n";
  while (node != nullptr) {
    // PROCCESSING - iterate through linked list until found
    if (node->name == searchKey) {
      cout << left;
      cout << setw(10) << "Name:" << node->name << "\n";
      cout << setw(10) << "Gender:" << node->gender << "\n";
      cout << setw(10) << "Age:" << node->age << "\n\n";
      cout << right;
      return true;
    }
    node = node->next;
  }
  // if it was not found return false
  return false;
}

/*******************************************************************************
 * removeNode
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

void removeNode(Node* &head, Node* &tail, string searchKey) {
  Node* node = head;
  cout << "\nSearching for " << searchKey << "...\n\n";
  while (node != nullptr) {
    // PROCCESSING - iterate through linked list until found
    if (node->name == searchKey) {
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
      cout << "Removing " << node->name << "\n\n";
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
 * clearList
 ------------------------------------------------------------------------------- 
 * FUNCTION: handles the clearing of linked list this
 * is also used for my deallocation at the end of prog
 * if list is not empty
 * @param head ptr to head of linked list
 * @param tail ptr to tail of linked list
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void clearList(Node* &head, Node* &tail) {
  Node* node = head;
  // PROCCESSING - if list is already cleared
  if (isListEmpty(node)) {
    cout << "The list has been cleared!\n\n";
    return;
  }
  cout << "CLEARING LIST:\n";
  while (node != nullptr) {
    cout << "Removing " << node->name << "!\n";
    // Handling the removal of nodes and also making sure everything points to
    // null
    head->prev = nullptr;
    head = node->next;
    delete node;
    node = head;
  }
  tail = nullptr;
  cout << "\nThe list has been cleared!\n\n";
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

void validateInput(Menu &choice) {
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
      choice = static_cast<Menu>(n);
      valid = true;
    }catch (bool invalid) {
      cout << "**** Please input a NUMBER between 0 and 6 ****\n";
    }
  } while (!valid);
  return;
}

/*******************************************************************************
 * handleSwitch
 ------------------------------------------------------------------------------- 
 * FUNCTION: handles all movement of choice that the user chooses this is done
 * by a switch case statement
 * @param head ptr to head of linked list
 * @param tail ptr to tail of linked list
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void handleSwitch(Node* &head, Node* &tail) {
  Menu choice = Exit;
  do {
    // PROCCESSING - displayMenu and validateInput
    displayMenu();
    validateInput(choice);
    cout << "\n";
    switch (choice) {
      case Exit: {
        break;
      }
      case CreateList: {
        if (head == nullptr) {
          createList(head, tail);
        }else {
          cout << "List is already made\n\n";
        }
        break;
      }
      case DisplayList: {
        if (isListEmpty(head)) {
          cout << "Can't display an empty list\n\n";
        }else {
          handleDisplayList(head);
        }
        break;
      }
      case IsEmpty: {
        if (isListEmpty(head)) {
          cout << "Yes, the list is empty.\n\n";
        }else {
          cout << "No, The list is NOT empty.\n\n";
        }
        break;
      }
      case SearchName: {
        string searchKey;
        // if list is not empty else
        if (!isListEmpty(head)) {
          cout << "Who would you like to search for? ";
          cin.ignore(1000, '\n');
          getline(cin, searchKey);
          // PROCCESSING - returns true if name found
          if (!searchName(head, searchKey)) {
            cout << "I'm sorry, \"" << searchKey << "\" was NOT found!\n\n";
          }
        }else {
          cout << "Can't search an empty list\n\n";
        }
        break;
      }
      case RemoveNode: {
        string searchKey;
        if (!isListEmpty(head)) {
          cout << "Who would you like to remove for? ";
          cin.ignore(1000, '\n');
          getline(cin, searchKey);
          removeNode(head, tail, searchKey);
        }else {
          cout << "Can't remove from an empty list\n\n";
        }
        break;
      }
      case ClearList: {
        clearList(head, tail);
        break;
      }
      default: {
        // validation for out of bounds
        string number;
        number = to_string(choice);
        cout << left;
        cout << "**** The number ";
        cout << number << " is an invalid entry";
        cout << right;
        cout << setw(11 - number.size())
                  << "****\n";
        cout << "**** Please input a number between 0 and 6 ****\n\n";
        break;
      }
    }
  } while (choice != Exit);
  return;
}

/*******************************************************************************
 * heading
 ------------------------------------------------------------------------------- 
 * FUNCTION: handles displaying class header
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void heading() {

	/***********************************************************************
	 * CONSTANTS
	 * ---------------------------------------------------------------------
	 * OUTPUT - USED FOR CLASS HEADING
	 * ---------------------------------------------------------------------
	 * PROGRAMMER : Programmer's Name
	 * CLASS      : Student's Course
	 * SECTION    : Class Days and Times
	 * LAB_NUM    : Lab Number (specific to this lab)
	 * LAB_NAME   : Title of the Lab
	 **********************************************************************/
	const char PROGRAMMER[] = "Carlos Aguilera";
	const char CLASS[]      = "CS1B";
	const char SECTION[]    = "MW: 7:30p - 9:50p";
	const int LAB_NUM       = 10;
	const char LAB_NAME[]   = "Creating Ordered List";

	cout << left;
	cout << "****************************************************\n";
	cout << "*   PROGRAMMED BY : " << PROGRAMMER << endl;
	cout << "*   " << setw(14) <<"CLASS" << ": " << CLASS << endl;
	cout << "*   " << setw(14) <<"SECTION" << ": " << SECTION << endl;
	cout << "*   LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME << endl;
	cout << "****************************************************\n\n";
	cout << right;
}