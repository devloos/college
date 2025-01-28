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