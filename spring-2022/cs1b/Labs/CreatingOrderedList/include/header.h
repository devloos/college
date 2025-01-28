#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

class Node {
 public:
  std::string name;
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
void readInput(Node* &node, std::fstream &inFile);

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
bool searchName(Node* &head, std::string searchKey);

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
void removeNode(Node* &head, Node* &tail, std::string searchKey);

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