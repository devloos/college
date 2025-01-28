#ifndef _HEADER_H_
#define _HEADER_H_
//PRE-PROCCESSOR DIRECTIVES
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Person {
    string name;       //var that stores person name
    char gender;       //var the stores person gender
    int age;           //var that stores person age
    Person* nextNode;  //ptr that points to Person struct && is used for points to the next node in the linked list
};

enum Menu{
    EXIT = 0,
    ENQUEUE,
    POP,
    ISEMPTY,
    front,
    SIZE,
    CLEAR
};

/*****************************************************
 * heading
 ----------------------------------------------------- 
 * Outputs the class heading
 * RETURNS - void
 ****************************************************/
void heading();



/*****************************************************
 * displayMenu
 ----------------------------------------------------- 
 * This function handles the display of the menu
 * RETURNS - void
 ****************************************************/
void displayMenu();



/*****************************************************
 * enqueue
 ----------------------------------------------------- 
 * enqueuees a new person on to the stack
 * this is accomplished by creating a new node
 * and assigning its .nextNode attribute to head 
 * and then assigning head to node
 * RETURNS - void
 ****************************************************/
void enqueue(Person** head, Person** tail, int &size);



/*****************************************************
 * pop
 ----------------------------------------------------- 
 * a ptr to a person struct is created and has the 
 * address of head then head is reassigned to 
 * the .nextNode attribute of node and then node is
 * deallocated
 * RETURNS - void
 ****************************************************/
void pop(Person** head, int &size);




/*****************************************************
 * isEmpty
 ----------------------------------------------------- 
 * if head equal nullptr then return true else false
 * RETURNS - bool
 ****************************************************/
bool isEmpty(Person** head);



/*****************************************************
 * switchValidation
 ----------------------------------------------------- 
 * prompt user to enter choice for swtich
 * and choice is validated by cin.fail() method
 * if it faild it will throw an execption and the
 * try catch will catch a bool and re prompt if failed.
 * It will loop until inputValid is true.
 * choice is an int so it gets static_casted into
 * a enum Menu
 * RETURNS - enum Menu
 ****************************************************/
Menu switchValidation();




/*****************************************************
 * FRONT
 ----------------------------------------------------- 
 * check if stack is empty then we output "nothing
 * to FRONT at" else we output person on top of stack
 * RETURNS - void
 ****************************************************/
void FRONT(Person** head);




/*****************************************************
 * switchCase
 ----------------------------------------------------- 
 * this function handles the option that is inputted
 * using enum and directs what functions to call 
 * RETURNS - void
 ****************************************************/
void switchCase(const Menu &choice, Person* &head, Person* &tail, int &size);




/*****************************************************
 * deallocate
 ----------------------------------------------------- 
 * if head is nullptr then nothing to deallocate 
 * else run while loop until head = nullptr 
 * create node = to head then assign head to .nextNode
 * then delete node 
 * RETURNS - void
 ****************************************************/
void deallocate(Person* &head);

#endif

/*****************************************************************************
 * AUTHOR      : Carlos Aguilera
 * STUDENT ID  : 1152562
 * LAB #8      : Implementing a Stack
 * CLASS       : CS1B
 * SECTION     : M-W
 * DUE DATE    : 04.04.22
 ****************************************************************************/

/****************************************************************************
 * Implementing a Queue
 * --------------------------------------------------------------------------
 * This program controls a flow of a linked list.
 * It performs as a Queue Linked list FIFO
 * The program prompts user with a menu choices are enqueue a person on the
 * stack, pop a person off the queue, FRONT at the top of the queue, is empty
 * to tell the user if the queue is empty, and size tell the user what size
 * is the stack.
 * --------------------------------------------------------------------------
 * Input:
 * <The user will input an Enum option when prompted>
 * <Input info when prompted command>
 * 
 * Output:
 * <Output the class heading>
 * <Output the menu options>
 * <Output prompt when enqueueing>
 * <Output info when popping>
 * <Output FRONTing info>
 * <Output whether queue is empty>
 * <Output size of queue>
 ***************************************************************************/

#include "../include/header.h"

int main()
{
    //PROCCESSING/OUTPUT - Output the class heading
    heading();
    //DATA TABLE
    int size = 0;             //var that stores the size of the stack
    Person* head = nullptr;   //var head that points to person struct
    Person* tail = nullptr;   //var head that points to person struct
    Menu choice = EXIT;       //Var that stores choice of user

    //PROCCESSING - runs to choice = EXIT
    do
    {
        //PROCCESSING/OUTPUT - Output menu
        displayMenu();
        //PROCCESSING - calls function that validates input of the choice
        choice = switchValidation();
        //PROCCESSING - handles switch case statement
        switchCase(choice, head, tail, size);
    } while (choice != EXIT);

    //PROCCESSING - deallocate memory that was allocated for the stack
    deallocate(head);
    return 0;    
}





/*****************************************************
 * displayMenu
 ----------------------------------------------------- 
 * This function handles the display of the menu
 * RETURNS - void
 ****************************************************/

#include "../include/header.h"

void displayMenu()
{
    //PROCCESSING - Menu to user
    std::cout << "QUEUE MENU:\n"; 
    std::cout << "1 ENQUEUE (Add a person)\n";
    std::cout << "2 DEQUEUE (Remove a person)\n";
    std::cout << "3 ISEMPTY (Is the queue empty?)\n";   
    std::cout << "4 FRONT   (Who is in front?)\n";
    std::cout << "5 SIZE    (How many people are there?)\n";
    std::cout << "6 Clear the Queue\n";
    std::cout << "0 Exit\n";
}




/*****************************************************
 * switchValidation
 ----------------------------------------------------- 
 * prompt user to enter choice for swtich
 * and choice is validated by cin.fail() method
 * if it faild it will throw an execption and the
 * try catch will catch a bool and re prompt if failed.
 * It will loop until inputValid is true.
 * choice is an int so it gets static_casted into
 * a enum Menu
 * RETURNS - enum Menu
 ****************************************************/

#include "../include/header.h"

Menu switchValidation() 
{
   int choice;                   //int choice of user
   bool inputValidated = false;  //bool whether input is validated
   //PROCCESSING - try catch wrapped in a do while until input is validated
   do {
      try {
         cout << "Enter a Command? ";
         cin >> choice;
         //PROCCESSING - if cin.fail() returns true or false
         if (cin.fail()) 
         {
            //if cin fails throw expection
            cin.clear();//clears buffer for next cin 
            cin.ignore(10, '\n');
            throw(true);
         }
         inputValidated = true;
      }
      //PROCCESSING - catches execption if thrown
      catch(bool invalid) {
         cout << "\n**** Please enter a NUMBER between 0 and 5 ****\n\n";
      }
   } while (!inputValidated);
   cin.ignore(100, '\n');
   
   return static_cast <Menu> (choice);//returns int but static cast to enum MenuOptions
}




/*****************************************************
 * switchCase
 ----------------------------------------------------- 
 * this function handles the option that is inputted
 * using enum and directs what functions to call 
 * RETURNS - void
 ****************************************************/

#include "../include/header.h"

void switchCase(
    const Menu &choice, //var menu choice of user
    Person* &head,      //var head ptr reference that hold head of stack
    Person* &tail,
    int &size)          //var stores size of stack
{
    //PROCCESSING - choice of user
    switch (choice)
    {
        case ENQUEUE:
            //PROCCESSING/IO - calls enqueue function to add person to the stack
            enqueue(&head, &tail, size);
            break;
        case POP:
            //PROCCESSING/Output - calls pop function to remove top person from stack
            pop(&head, size);
            break;
        case ISEMPTY:
            //PROCCESSING - calls is empty function returns true if stack is empty else 
            if (isEmpty(&head))
                cout << "Yes, the queue is empty!\n";
            else
                cout << "The queue is NOT empty!\n";
            break;
        case front:
            //PROCCESSING/Output - person on top of the stack
            FRONT(&head);
            break;
        case SIZE:
            //OUTPUT - output the size of the stack
            if (size == 1)
                cout << "\nThere is one person on the queue!\n";
            else if (size > 1)
                cout << "\nThere are " << size << " people on the queue!\n";
            else
                cout << "\nNobody on the queue!\n";
            break;
        case EXIT:
            cout << "Thank you!\n";
            break;
        default:
            //PROCCESSING - converts choice to string and we use the string to get setw format right
            //OUTPUT - invalid choice 
            string strChoice = to_string(choice);
            cout << left;
            cout << "\n**** The number " << strChoice << " is an invalid number ";
            cout << right;
            //CALC - 10 - string size
            cout << setw(10 - strChoice.size()) << "****\n";
            cout << "**** Please input a number between 0 and 5 ****\n";
            break;
    }
}




/*****************************************************
 * enqueue
 ----------------------------------------------------- 
 * enqueuees a new person on to the stack
 * this is accomplished by creating a new node
 * and assigning its .nextNode attribute to head 
 * and then assigning head to node
 * RETURNS - void
 ****************************************************/

#include "../include/header.h"

void enqueue(
    Person** head, //ptr to a ptr that holds head of stack
    Person** tail,
    int &size)     //int stores size of stack
{
    Person* node = nullptr; //ptr that points to Person struct

    //PROCCESSING - new person and assigning attributes
    node = new Person;
    cout << left;
    cout << "\nWho would you like to add?\n\n";

    cout << setw(14) << "Enter Name:";
    getline(cin, node->name);

    cout << "Enter Gender: ";
    cin.get(node->gender);
    cin.ignore(100,'\n');

    cout << setw(14) << "Enter Age:";
    cin >> node->age;
    cin.ignore(100,'\n');
    cout << right;

    //PROCCESSING - if head = null then run head = tail and tail equals node
    if (*head != nullptr) {
        (*tail)->nextNode = node;
        *tail = node;
        (*tail)->nextNode = nullptr;
    }else {
        *tail = node;
        (*tail)->nextNode = nullptr;
        *head = *tail;
    }
    ++size;
}





/*****************************************************
 * pop
 ----------------------------------------------------- 
 * a ptr to a person struct is created and has the 
 * address of head then head is reassigned to 
 * the .nextNode attribute of node and then node is
 * deallocated
 * RETURNS - void
 ****************************************************/

void pop(
    Person** head, //ptr to a ptr that stores head of stack
    int &size)     //int stores size of stack
{
    Person* node = nullptr; //ptr that points to Person struct
    node = *head;

    //PROCCESSING - if head not nullptr print node else 
    if (*head != nullptr)
    {
        cout << left;
        cout << "\nDEQUEUEING\n";
        cout << setw(8) << "Name:" << node->name << "\n";
        cout << setw(8) << "Gender:" << node->gender << "\n";
        cout << setw(8) << "Age:" << node->age << "\n";
        cout << right;

        //PROCCESSING - head = node.nextNode then delete node
        *head = node->nextNode;
        delete node;
        --size;
    }else
        cout << "Can't dequeue from an empty stack!\n";
}




/*****************************************************
 * isEmpty
 ----------------------------------------------------- 
 * if head equal nullptr then return true else false
 * RETURNS - bool
 ****************************************************/

#include "../include/header.h"

bool isEmpty(
    Person** head) //ptr to a ptr holds head of stack
{
    //PROCCESSING - returns true if head = nullptr else
    return (*head == nullptr);
}



/*****************************************************
 * FRONT
 ----------------------------------------------------- 
 * check if stack is empty then we output "nothing
 * to FRONT at" else we output person on top of stack
 * RETURNS - void
 ****************************************************/

#include "../include/header.h"

void FRONT(
    Person** head) //ptr to a ptr stores head of stack
{
    Person* node = *head;
    
    //PROCCESSING - if node is empty then print nobody to FRONT else ouputs person on top of stack
    if (isEmpty(&node))
        cout << "\nNobody in FRONT, the queue is empty!!\n";
    else
    {
        cout << left;
        cout << "\nThe first person on the queue is:\n";
        cout << setw(8) << "Name:" << node->name << "\n";
        cout << setw(8) << "Gender:" << node->gender << "\n";
        cout << setw(8) << "Age:" << node->age << "\n";
        cout << right;
    }
}


/*****************************************************
 * clearQueue
 ----------------------------------------------------- 
 * if head is nullptr then nothing to deallocate 
 * else run while loop until head = nullptr 
 * create node = to head then assign head to .nextNode
 * then delete node 
 * RETURNS - void
 ****************************************************/

#include "../include/header.h"

void clearQueue(
    Person* &head) //ref to ptr stores head of stack
{
    Person* node = nullptr;

    if (head != nullptr) {
      std::cout << "\nCLEARING...\n";
    }else 
        std::cout << "The QUEUE is ALREADY clear!\n";
    //PROCCESSING - while head not nullptr
    while (head != nullptr)
    {
        //PROCCESSING - node = head & head = .nextNode then node deallocated
        node = head;
        std::cout << node->name << "\n";
        head = node->nextNode;
        delete node;
        if (head == nullptr)
            std::cout << "The queue has been CLEARED!\n";
    }
    head = nullptr;
}



/*****************************************************
 * deallocate
 ----------------------------------------------------- 
 * if head is nullptr then nothing to deallocate 
 * else run while loop until head = nullptr 
 * create node = to head then assign head to .nextNode
 * then delete node 
 * RETURNS - void
 ****************************************************/

#include "../include/header.h"

void deallocate(
    Person* &head) //ref to ptr stores head of stack
{
    Person* node = nullptr;

    //PROCCESSING - while head not nullptr
    while (head != nullptr)
    {
        //PROCCESSING - node = head & head = .nextNode then node deallocated
        node = head;
        head = node->nextNode;
        delete node;
    }
    head = nullptr;
}




/*****************************************************
 * heading
 ----------------------------------------------------- 
 * Outputs the class heading
 * RETURNS - void
 ****************************************************/

#include "../include/header.h"

void heading() 
{
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
	const int LAB_NUM       = 9;
	const char LAB_NAME[]   = "Lab Implementing a Queue";

	cout << left;
	cout << "****************************************************\n";
	cout << "*   PROGRAMMED BY : " << PROGRAMMER << endl;
	cout << "*   " << setw(14) <<"CLASS" << ": " << CLASS << endl;
	cout << "*   " << setw(14) <<"SECTION" << ": " << SECTION << endl;
	cout << "*   LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME << endl;
	cout << "****************************************************\n\n";
	cout << right;
}