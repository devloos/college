#ifndef HEADER_H_
#define HEADER_H_
#include <iostream>
#include <iomanip>
using namespace std;

enum Menu {
  Exit = 0,
  AddSheep,
  FirstSheep,
  FindSheep,
  ListSize,
  OutputList,
  ClearList
};

/*******************************************************************************
 * menu
 ------------------------------------------------------------------------------- 
 * FUNCTION: Handles the output of menu
 * RETURNS - void
 ******************************************************************************/
void menu();

/*******************************************************************************
 * headerClass
 ------------------------------------------------------------------------------- 
 * FUNCTION: Handles the output of the header class
 * RETURNS - void
 ******************************************************************************/
void headerClass();

/*******************************************************************************
 * validateInt
 ------------------------------------------------------------------------------- 
 * FUNCTION: This handles validating an unsigned int using try catch and an
 * exception is thrown if the cin fails, on top of that we are validating the 
 * range using MIN and MAX that programmer passes in
 * @param choice - integer choice of user
 * @param isMenu - bool to let function know its a menu call
 * @param MIN - minimum of range
 * @param MAX - maximum of range
 * RETURNS - void
 ******************************************************************************/
void validateInt(unsigned int &choice, const bool &isMenu, const int MIN, const int MAX);
#endif // HEADER_H_

#ifndef SHEEP_H_
#define SHEEP_H_
#include <string>
using namespace std;

// Class prototype to let compiler know this class exist somewhere
class SheepLinkedList;

class Sheep {
 private:
  string m_Name;
  unsigned int m_Age;
  Sheep* next;
  friend SheepLinkedList;

  /*******************************************************************************
   * Insertion Operator
   ------------------------------------------------------------------------------- 
   * FUNCTION: Handles the output of the sheep list, does it in a manner that makes
   * sense to overload this operator
   * @param os - ostream var to return to cout
   * @param sheepList - reference to sheepList
   * RETURNS - ostream&
   ******************************************************************************/
  friend ostream &operator<<(ostream &os, const SheepLinkedList &sheepList);
 public:
  /*******************************************************************************
   * Empty Constructor
   ------------------------------------------------------------------------------- 
   * CONSTRUCTOR: Initializes all variables
   ******************************************************************************/
  Sheep();

  /*******************************************************************************
   * 2 Argument Constructor
   ------------------------------------------------------------------------------- 
   * FUNCTION: Handles the Initializing of name and age by parameter pass in
   * @param name - name of the sheep
   * @param age - age of the sheep
   ******************************************************************************/
  Sheep(const string &name, const unsigned int &age);

  /*******************************************************************************
   * Destructor
   ------------------------------------------------------------------------------- 
   * DESTRUCTOR: Used when an obj needs to get destroyed
   ******************************************************************************/
  ~Sheep();

  /*******************************************************************************
   * setInitialValues
   ------------------------------------------------------------------------------- 
   * FUNCTION: This function assignes initial values to member variables
   * @param name - name of the sheep
   * @param age - age of the sheep
   * RETURNS - void
   ******************************************************************************/
  void setInitialValues(const string name, const unsigned int &age);

  /*******************************************************************************
   * setName
   ------------------------------------------------------------------------------- 
   * FUNCTION: sets name of sheep
   * @param name - name of the sheep
   * RETURNS - void
   ******************************************************************************/
  void setName(const string &name);

  /*******************************************************************************
   * setAge
   ------------------------------------------------------------------------------- 
   * FUNCTION: sets age of sheep
   * @param age - age of sheep
   * RETURNS - void
   ******************************************************************************/
  void setAge(const unsigned int &age);

  /*******************************************************************************
   * getValues
   ------------------------------------------------------------------------------- 
   * FUNCTION: handles getting multiple values by passing values by reference
   * @param name - name of the sheep
   * @param age - age of the sheep
   * RETURNS - void
   ******************************************************************************/
  void getValues(string &name, unsigned int &age) const;

  /*******************************************************************************
   * getName
   ------------------------------------------------------------------------------- 
   * FUNCTION: returns name of sheep
   * RETURNS - string
   ******************************************************************************/
  string getName() const;

  /*******************************************************************************
   * getAge
   ------------------------------------------------------------------------------- 
   * FUNCTION: returns age of sheep
   * RETURNS - unsigned int
   ******************************************************************************/
  unsigned int getAge() const;
};
#endif // SHEEP_H_

#ifndef SHEEP_LINKED_LIST_H_
#define SHEEP_LINKED_LIST_H_
#include "SheepList.h"
using namespace std;

class SheepLinkedList : public SheepList {
 private:
  Sheep* head;
  Sheep* tail;

  /*******************************************************************************
   * Insertion Operator
   ------------------------------------------------------------------------------- 
   * FUNCTION: Handles the output of the sheep list, does it in a manner that makes
   * sense to overload this operator
   * @param os - ostream var to return to cout
   * @param sheepList - reference to sheepList
   * RETURNS - ostream&
   ******************************************************************************/
  friend ostream &operator<<(ostream &os,
                                  const SheepLinkedList &sheepList);

  /*******************************************************************************
   * listOneSheep
   ------------------------------------------------------------------------------- 
   * FUNCTION: Handles that output of one sheep takes in sheep as its parameter
   * @param node - node ptr to sheep
   * RETURNS - void
   ******************************************************************************/
  void listOneSheep(const Sheep* node) const;
 public:

  /*******************************************************************************
   * Constructor
   ------------------------------------------------------------------------------- 
   * CONSTRUCTOR: inits values
   ******************************************************************************/
  SheepLinkedList() : head(nullptr), tail(nullptr) {}

  /*******************************************************************************
   * Destructor
   ------------------------------------------------------------------------------- 
   * DESTRUCTOR:
   ******************************************************************************/
  ~SheepLinkedList();

  /*******************************************************************************
   * addSheep
   ------------------------------------------------------------------------------- 
   * FUNCTION: Handles the adding of new sheep to the list
   * @param name - name of sheep
   * @param age - age of sheep
   * RETURNS - void
   ******************************************************************************/
  void addSheep(const string &name, const unsigned int &age);

  /*******************************************************************************
   * clear
   ------------------------------------------------------------------------------- 
   * FUNCTION: Handles clearing the list
   * RETURNS - void
   ******************************************************************************/
  void clear();

  /*******************************************************************************
   * find
   ------------------------------------------------------------------------------- 
   * FUNCTION: find a sheep in the list if the list is not empty, by manners of
   * sheep name
   * @param name - name of sheep wanting to be found
   * RETURNS - bool
   ******************************************************************************/
  bool find(const string name) const;

  /*******************************************************************************
   * firstSheep
   ------------------------------------------------------------------------------- 
   * FUNCTION: Handles the output of the first sheep on the list if list is not
   * empty
   * RETURNS - void
   ******************************************************************************/
  void firstSheep() const;
};
#endif // SHEEP_LINKED_LIST_H_

#ifndef SHEEP_LIST_H_
#define SHEEP_LIST_H_
#include "header.h"
#include "Sheep.h"

const int ARRAY_SIZE = 50;

class SheepList {
 protected:
  int sheepCount;
 private:
  Sheep sheepArray[ARRAY_SIZE];

  /*******************************************************************************
   * Insertion Operator
   ------------------------------------------------------------------------------- 
   * FUNCTION: Handles the output of the sheep list, does it in a manner that makes
   * sense to overload this operator
   * @param os - ostream var to return to cout
   * @param sheepList - reference to sheepList
   * RETURNS - ostream&
   ******************************************************************************/
  friend ostream &operator<<(ostream &os, const SheepList &sheepList);

  /*******************************************************************************
   * listOneSheep
   ------------------------------------------------------------------------------- 
   * FUNCTION: Handles that output of one sheep takes in sheep as its parameter
   * @param node - node ptr to sheep
   * RETURNS - void
   ******************************************************************************/
  void listOneSheep(const int &index) const;
 public:

  /*******************************************************************************
   * Constructor
   ------------------------------------------------------------------------------- 
   * CONSTRUCTOR: inits values
   ******************************************************************************/
  SheepList() : sheepCount(0) {}

  /*******************************************************************************
   * Destructor
   ------------------------------------------------------------------------------- 
   * DESTRUCTOR:
   ******************************************************************************/
  ~SheepList() {}

  /*******************************************************************************
   * addSheep
   ------------------------------------------------------------------------------- 
   * FUNCTION: Handles the adding of new sheep to the list
   * @param name - name of sheep
   * @param age - age of sheep
   * RETURNS - void
   ******************************************************************************/
  void addSheep(const Sheep &newSheep);

  /*******************************************************************************
   * clear
   ------------------------------------------------------------------------------- 
   * FUNCTION: Handles clearing the list
   * RETURNS - void
   ******************************************************************************/
  void clear();

  /*******************************************************************************
   * size
   ------------------------------------------------------------------------------- 
   * FUNCTION: returns size of list
   * RETURNS - int
   ******************************************************************************/
  int size() const;

  /*******************************************************************************
   * find
   ------------------------------------------------------------------------------- 
   * FUNCTION: find a sheep in the list if the list is not empty, by manners of
   * sheep name
   * @param name - name of sheep wanting to be found
   * RETURNS - bool
   ******************************************************************************/
  bool find(const string name) const;

  /*******************************************************************************
   * firstSheep
   ------------------------------------------------------------------------------- 
   * FUNCTION: Handles the output of the first sheep on the list if list is not
   * empty
   * RETURNS - void
   ******************************************************************************/
  void firstSheep() const;
};
#endif // SHEEP_LIST_H_

#include "../include/header.h"
#include "../include/Sheep.h"
#include "../include/SheepList.h"
#include "../include/SheepLinkedList.h"

/*******************************************************************************
 * AUTHOR      : Carlos Aguilera
 * STUDENT ID  : 1152562
 * LAB #13     : Array & Linked List (OOP)
 * CLASS       : CS1B
 * SECTION     : M-W
 * DUE DATE    : 05.09.22
 ******************************************************************************/

/******************************************************************************
 * Title: Array & Linked List (OOP)
 * ----------------------------------------------------------------------------
 * PROGRAM: Welcome to my sheep list program this program uses two different
 * methods on holding sheeps Array, and Linked List. The example you find 
 * below is the array version but with two simple uncomments you can be up and 
 * running on the Linked List version. User has choices like add a sheep,
 * First sheep in the list, Find sheep, List size, output list, and clear list.
 * ----------------------------------------------------------------------------
 ******************************************************************************/

int main() {
  headerClass();
  // PROCCESSING - You can either use linked list or array
  SheepList sheepList;
  // SheepLinkedList sheepList;

  string name;
  unsigned int n, age;
  Menu choice = Exit;

  do {
    menu();
    // PROCCESSING - Validate unsigned int
    validateInt(n, true, 0, 6);
    // cast validated int into type Menu
    choice = Menu(n);
    switch (choice) {
      case Exit: {
        break;
      }
      case AddSheep: {
        cout << "\nSheep Name: ";
        cin.ignore(1000, '\n');
        getline(cin, name);
        cout << "Sheep Age: ";
        // PROCCESSING - Validate unsigned int
        validateInt(age, false, 1, 9);
        // PROCCESSING - Instantiating new sheep with name and age
        Sheep newSheep(name, age);
        // PROCCESSING - add sheep with new sheep as param
        sheepList.addSheep(newSheep);
        // sheepList.addSheep(name, age);
        break;
      }
      case FirstSheep: {
        sheepList.firstSheep();
        break;
      }
      case FindSheep: {
        if (sheepList.size() > 0) {
          cout << "\nWho are you looking for? ";
          cin.ignore(1000, '\n');
          getline(cin, name);
          // returns bool if !false then sheep not found
          if (!sheepList.find(name))
            cout << "Sheep not found\n";
        } else {
          cout << "\nThere are no sheep to be found!\n";
        }
        break;
      }
      case ListSize: {
        cout << "\nThere are " << sheepList.size() << " sheep in the list!\n"; 
        break;
      }
      case OutputList: {
        // Overloaded Insertion to output entire list
        cout << sheepList << "\n";
        break;
      }
      case ClearList: {
        sheepList.clear();
        break;
      }
      default: {
        break;
      }
    }
  } while (choice != Exit);
  return 0;
}

#include "../include/Sheep.h"

  /*******************************************************************************
   * Empty Constructor
   ------------------------------------------------------------------------------- 
   * CONSTRUCTOR: Initializes all variables
   ******************************************************************************/
Sheep::Sheep() : m_Name(""), m_Age(0), next(nullptr) {}

  /*******************************************************************************
   * 2 Argument Constructor
   ------------------------------------------------------------------------------- 
   * FUNCTION: Handles the Initializing of name and age by parameter pass in
   * @param name - name of the sheep
   * @param age - age of the sheep
   ******************************************************************************/
Sheep::Sheep(const string &name, const unsigned int &age) 
    : m_Name(name), m_Age(age) {}

  /*******************************************************************************
   * Destructor
   ------------------------------------------------------------------------------- 
   * DESTRUCTOR: Used when an obj needs to get destroyed
   ******************************************************************************/
Sheep::~Sheep() {}

  /*******************************************************************************
   * setInitialValues
   ------------------------------------------------------------------------------- 
   * FUNCTION: This function assignes initial values to member variables
   * @param name - name of the sheep
   * @param age - age of the sheep
   * RETURNS - void
   ******************************************************************************/
void Sheep::setInitialValues(const string name, const unsigned int &age) {
  this->m_Name = name;
  this->m_Age = age;
}

  /*******************************************************************************
   * setName
   ------------------------------------------------------------------------------- 
   * FUNCTION: sets name of sheep
   * @param name - name of the sheep
   * RETURNS - void
   ******************************************************************************/
void Sheep::setName(const string &name) { this->m_Name = name; }

  /*******************************************************************************
   * setAge
   ------------------------------------------------------------------------------- 
   * FUNCTION: sets age of sheep
   * @param age - age of sheep
   * RETURNS - void
   ******************************************************************************/
void Sheep::setAge(const unsigned int &age) { this->m_Age = age; }

  /*******************************************************************************
   * getValues
   ------------------------------------------------------------------------------- 
   * FUNCTION: handles getting multiple values by passing values by reference
   * @param name - name of the sheep
   * @param age - age of the sheep
   * RETURNS - void
   ******************************************************************************/
void Sheep::getValues(string &name, unsigned int &age) const {
  name = this->m_Name;
  age = this->m_Age;
}

  /*******************************************************************************
   * getName
   ------------------------------------------------------------------------------- 
   * FUNCTION: returns name of sheep
   * RETURNS - string
   ******************************************************************************/
string Sheep::getName() const { return m_Name; }

  /*******************************************************************************
   * getAge
   ------------------------------------------------------------------------------- 
   * FUNCTION: returns age of sheep
   * RETURNS - unsigned int
   ******************************************************************************/
unsigned int Sheep::getAge() const { return m_Age; }

#include "../include/SheepLinkedList.h"

SheepLinkedList::~SheepLinkedList() {
  Sheep* node = head;
  // PROCCESSING - The deletion of nodes if not nullptr
  if (node != nullptr) {
    while (node != nullptr) {
      head = node->next;
      delete node;
      node = head;
    }
  }
  sheepCount = 0;
}

void SheepLinkedList::addSheep(const string &name, const unsigned int &age) {
  // node = tail because we want to add to the back of the list
  Sheep* node = tail;
  if (node != nullptr) {
    // age is already validated
    node = new Sheep(name, age);
    tail->next = node;
    tail = node;
  } else {
    head = new Sheep(name, age);
    tail = head;
  }
  cout << "\nThe Sheep...\n";
  cout << "Sheep Name: " << tail->m_Name;
  cout << "\nSheep Age:  " << tail->m_Age;
  cout << "\nHas been Added!\n";
  // sheep count incerement 
  ++sheepCount;
}

  /*******************************************************************************
   * clear
   ------------------------------------------------------------------------------- 
   * FUNCTION: Handles clearing the list
   * RETURNS - void
   ******************************************************************************/
void SheepLinkedList::clear() {
  Sheep* node = head;
  // node already == nullptr then list is empty
  if (node == nullptr) {
    cout << "\nThe list is empty!\n";
    return;
  }
  while (node != nullptr) {
    head = node->next;
    delete node;
    node = head;
  }
  sheepCount = 0;
  tail = nullptr;
  head = nullptr;
  cout << "The list has been cleared!\n";
}

  /*******************************************************************************
   * listOneSheep
   ------------------------------------------------------------------------------- 
   * FUNCTION: Handles that output of one sheep takes in sheep as its parameter
   * @param node - node ptr to sheep
   * RETURNS - void
   ******************************************************************************/
void SheepLinkedList::listOneSheep(const Sheep* node) const {
  cout << "\nNAME           AGE\n";
  cout << "-------------- ---\n";
  cout << left;
  cout << setw(16) << node->m_Name;
  cout << node->m_Age << '\n';
  cout << right;
}

  /*******************************************************************************
   * find
   ------------------------------------------------------------------------------- 
   * FUNCTION: find a sheep in the list if the list is not empty, by manners of
   * sheep name
   * @param name - name of sheep wanting to be found
   * RETURNS - bool
   ******************************************************************************/
bool SheepLinkedList::find(const string name) const {
  Sheep* node = head;
  bool found = false;
  if (node != nullptr) {
    // PROCCESSING - if found exit or if reached end of list
    while (!found && node != nullptr) {
      if (node->m_Name == name) {
        listOneSheep(node);
      cout << "\nHas been found!\n";
        return true;
      }
      node = node->next;
    }
  } else {
    cout << "\nThere are no sheep to be found!\n";
  }
  // if made this far than obj was not found
  return false;
}

  /*******************************************************************************
   * firstSheep
   ------------------------------------------------------------------------------- 
   * FUNCTION: Handles the output of the first sheep on the list if list is not
   * empty
   * RETURNS - void
   ******************************************************************************/
void SheepLinkedList::firstSheep() const {
  Sheep* node = head;
  if (node != nullptr) {
    // PROCCESSING - head would be first of list
    listOneSheep(node);
    cout << "\nIs in the front of the list\n";
  } else {
    cout << "\nNobody is in front - the list is empty!\n";
  }
}

/*******************************************************************************
 * Insertion Operator
 ------------------------------------------------------------------------------- 
 * FUNCTION: Handles the output of the sheep list, does it in a manner that makes
 * sense to overload this operator
 * @param os - ostream var to return to cout
 * @param sheepList - reference to sheepList
 * RETURNS - ostream&
 ******************************************************************************/
ostream &operator<<(ostream &os, const SheepLinkedList &sheepList) {
  // this method is a friend of SheepLinkedList so has access to head
  Sheep* node = sheepList.head;
  if (node != nullptr) {
    os << "\nNAME           AGE\n";
    os << "-------------- ---\n";
    cout << left;
    while (node != nullptr) {
      cout << setw(16) << node->getName();
      cout << node->getAge();
      // Ternary for if last node
      cout << ((node->next == nullptr) ? ' ' : '\n');
      node = node->next;
    }
    cout << right;
    cout << "\nThere are " << sheepList.sheepCount << " sheep in the list!\n";
  } else {
    cout << "\nThe list is empty!";
  }
  return os;
}

#include "../include/SheepList.h"

  /*******************************************************************************
   * addSheep
   ------------------------------------------------------------------------------- 
   * FUNCTION: Handles the adding of new sheep to the list
   * @param name - name of sheep
   * @param age - age of sheep
   * RETURNS - void
   ******************************************************************************/

void SheepList::addSheep(const Sheep &newSheep) {
  // if true we have space to add another sheep
  if (sheepCount <= ARRAY_SIZE) {
    // sheep array at index sheepCount because its one ahead, solely array starts 0
    sheepArray[sheepCount].setName(newSheep.getName());
    sheepArray[sheepCount].setAge(newSheep.getAge());

    cout << "\nThe sheep...\n";
    cout << "Sheep Name: " << newSheep.getName() << "\n";
    cout << "Sheep Age:  " << newSheep.getAge() << "\n";
    cout << "Has been added!\n";

    ++sheepCount;
  }else {
    cout << "List is full sorry!\n";
  }
}

void SheepList::clear() {
  if (sheepCount == 0) {
    cout << "\nThe list is empty!\n";
    return;
  }
  // PROCCESSING - Setting initial values and assigning 0 to sheepCount
  for (int i = 0; i < sheepCount; ++i) {
    sheepArray[i].setName("");
    sheepArray[i].setAge(0);
  }

  sheepCount = 0;
  cout << "The list has been cleared!\n";
}

  /*******************************************************************************
   * size
   ------------------------------------------------------------------------------- 
   * FUNCTION: returns size of list
   * RETURNS - int
   ******************************************************************************/
int SheepList::size() const { return sheepCount; }

bool SheepList::find(const string name) const {
  bool found = false;
  int i = 0;
  while (!found && i < sheepCount) {
    // PROCCESSING - using getter to compare key name with sheep
    if (sheepArray[i].getName() == name) {
      listOneSheep(i);
      cout << "Has been found\n";
      return true;
    }
    ++i;
  }
  // if reached this point obj was not found
  return false;
}

  /*******************************************************************************
   * listOneSheep
   ------------------------------------------------------------------------------- 
   * FUNCTION: Handles that output of one sheep takes in sheep as its parameter
   * @param index - index on what element to display
   * RETURNS - void
   ******************************************************************************/
void SheepList::listOneSheep(const int &index) const {
  cout << "\nNAME           AGE\n";
  cout << "-------------- ---\n";
  cout << left;
  cout << setw(16) << sheepArray[index].getName();
  cout << sheepArray[index].getAge() << '\n';
  cout << right;
}

  /*******************************************************************************
   * firstSheep
   ------------------------------------------------------------------------------- 
   * FUNCTION: Handles the output of the first sheep on the list if list is not
   * empty
   * RETURNS - void
   ******************************************************************************/
void SheepList::firstSheep() const {
  if (sheepCount > 0) {
    listOneSheep(0);
    cout << "\nIs at the front of the list.\n";
  } else {
    cout << "\nNobody is in front - the list is empty!\n";
  }
}

/*******************************************************************************
 * Insertion Operator
 ------------------------------------------------------------------------------- 
 * FUNCTION: Handles the output of the sheep list, does it in a manner that makes
 * sense to overload this operator
 * @param os - ostream var to return to cout
 * @param sheepList - reference to sheepList
 * RETURNS - ostream&
 ******************************************************************************/
ostream &operator<<(ostream &os, const SheepList &sheepList) {
  if (sheepList.sheepCount > 0) {
    os << "\nNAME           AGE\n";
    os << "-------------- ---\n";
    cout << left;
    // PROCCESSING - sheepCount as the condition so we don't loop over non used
    // sheep
    for (int i = 0; i < sheepList.sheepCount; ++i) {
      cout << setw(16) << sheepList.sheepArray[i].getName();
      cout << sheepList.sheepArray[i].getAge();
      cout << ((i + 1 < sheepList.sheepCount) ? '\n' : ' ');
    }
    cout << right;
    cout << "\nThere are " << sheepList.sheepCount << " sheep in the list!\n";
  } else {
    cout << "\nThe list is empty!";
  }
  return os;
}

#include "../../include/header.h"

/*******************************************************************************
 * validateInt
 ------------------------------------------------------------------------------- 
 * FUNCTION: This handles validating an unsigned int using try catch and an
 * exception is thrown if the cin fails, on top of that we are validating the 
 * range using MIN and MAX that programmer passes in
 * @param choice - integer choice of user
 * @param isMenu - bool to let function know its a menu call
 * @param MIN - minimum of range
 * @param MAX - maximum of range
 * RETURNS - void
 ******************************************************************************/

void validateInt(unsigned int &choice, const bool &isMenu, const int MIN,
                 const int MAX) {
  bool validated = false;
  do {
    try {
      cin >> choice;
      // if fail throw exception
      if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        throw true;
      }
      // RANGE CHECK
      if (choice < MIN || choice > MAX) {
        // if not menu call then throw an exception instead of going back to menu
        if (!isMenu)
          throw true;
        // stringify choice
        string n = to_string(choice);
        cout << left;
        cout << "\n**** The number " << n << setw(27 - n.size());
        cout << " is an invalid entry" << "****\n";
        cout << "**** Please input a number between " << MIN << " and ";
        cout << MAX << " ****\n";
        cout << right;
      }
      validated = true;
    } catch (bool invalid) {
      // catch exception
      cout << "\n**** Enter a NUMBER between " << MIN << " and " << MAX;
      cout << " ****\n";
      // if isMenu then display menu again
      if (isMenu) {
        menu();
      } else {
        cout << "\nSheep Age: ";
      }
    }
  } while (!validated);
}

#include "../../include/header.h"

/*******************************************************************************
 * menu
 ------------------------------------------------------------------------------- 
 * FUNCTION: Handles the output of menu
 * RETURNS - void
 ******************************************************************************/

void menu() {
  cout << "\nSHEEP LIST MANAGER\n";
  cout << "1 - Add Sheep\n";
  cout << "2 - Output 1st Sheep\n";
  cout << "3 - Find Sheep\n";
  cout << "4 - List Size\n";
  cout << "5 - Output List\n";
  cout << "6 - Clear List\n";
  cout << "0 - Exit\n";
  cout << "Enter a command: ";
}

#include "../../include/header.h"

/*******************************************************************************
 * headerClass
 ------------------------------------------------------------------------------- 
 * FUNCTION: Handles the output of the header class
 * RETURNS - void
 ******************************************************************************/

void headerClass() {

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
	const int LAB_NUM       = 13;
	const char LAB_NAME[]   = "Array & Linked List (OOP)";

	cout << left;
	cout << "****************************************************\n";
	cout << "*   PROGRAMMED BY : " << PROGRAMMER << endl;
	cout << "*   " << setw(14) <<"CLASS" << ": " << CLASS << endl;
	cout << "*   " << setw(14) <<"SECTION" << ": " << SECTION << endl;
	cout << "*   LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME << endl;
	cout << "****************************************************\n\n";
	cout << right;
  cout << "*************************************\n";
  cout << "* WELCOME TO THE SHEEP LIST MANAGER *\n";
  cout << "*************************************\n";
}