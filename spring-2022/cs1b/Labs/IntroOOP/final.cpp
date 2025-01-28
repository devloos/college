****************************************************
*   PROGRAMMED BY : Carlos Aguilera
*   CLASS         : CS1B
*   SECTION       : MW: 7:30p - 9:50p
*   LAB #12       : Introduction OOP
****************************************************

1 - Initialize Animals
0 - Exit
Enter Selection: 2

**** The number 2 is an invalid entry ****
**** Please input a number between 0 and 1 ****


1 - Initialize Animals
0 - Exit
Enter Selection: a

**** Please enter a NUMBER between 0 and 1 ****

1 - Initialize Animals
0 - Exit
Enter Selection: 1

1 - Initialize Animals
2 - Change Age
3 - Change Value
4 - Display Animals
0 - Exit
Enter Selection: 5

**** The number 5 is an invalid entry ****
**** Please input a number between 0 and 4 ****


1 - Initialize Animals
2 - Change Age
3 - Change Value
4 - Display Animals
0 - Exit
Enter Selection: 4

ANIMAL     NAME           AGE    VALUE
---------- -------------- --- ------------
Sheep      Fluffy          1    $ 15000.00
Sheep      Maa             2    $ 16520.35
Pig        Babe            3    $ 10240.67

1 - Initialize Animals
2 - Change Age
3 - Change Value
4 - Display Animals
0 - Exit
Enter Selection: 2

Change Age:
1 - Fluffy
2 - Maa
3 - Babe
Select the animal you'd like to change: 4

**** The number 4 is an invalid entry ****
**** Please input a number between 1 and 3 ****


Change Age:
1 - Fluffy
2 - Maa
3 - Babe
Select the animal you'd like to change: a

**** Please enter a NUMBER between 1 and 3 ****

Change Age:
1 - Fluffy
2 - Maa
3 - Babe
Select the animal you'd like to change: 1
NEW AGE: 2

Changing Fluffy's age to 2 ...

1 - Initialize Animals
2 - Change Age
3 - Change Value
4 - Display Animals
0 - Exit
Enter Selection: 2

Change Age:
1 - Fluffy
2 - Maa
3 - Babe
Select the animal you'd like to change: 2
NEW AGE: 4

Changing Maa's age to 4 ...

1 - Initialize Animals
2 - Change Age
3 - Change Value
4 - Display Animals
0 - Exit
Enter Selection: 2

Change Age:
1 - Fluffy
2 - Maa
3 - Babe
Select the animal you'd like to change: 3
NEW AGE: 11

**** The number 11 is an invalid entry ****
**** Please input a number between 1 and 10 ****

NEW AGE: 3

Changing Babe's age to 3 ...

1 - Initialize Animals
2 - Change Age
3 - Change Value
4 - Display Animals
0 - Exit
Enter Selection: 4

ANIMAL     NAME           AGE    VALUE
---------- -------------- --- ------------
Sheep      Fluffy          2    $ 15000.00
Sheep      Maa             4    $ 16520.35
Pig        Babe            3    $ 10240.67

1 - Initialize Animals
2 - Change Age
3 - Change Value
4 - Display Animals
0 - Exit
Enter Selection: 3

Change Value:
1 - Fluffy
2 - Maa
3 - Babe
Select the animal you'd like to change: 4

**** The number 4 is an invalid entry ****
**** Please input a number between 1 and 3 ****


Change Value:
1 - Fluffy
2 - Maa
3 - Babe
Select the animal you'd like to change: 4

**** The number 4 is an invalid entry ****
**** Please input a number between 1 and 3 ****


Change Value:
1 - Fluffy
2 - Maa
3 - Babe
Select the animal you'd like to change: 1
NEW VALUE: 154154.51

Changing Fluffy's value to 154154.51 ...

1 - Initialize Animals
2 - Change Age
3 - Change Value
4 - Display Animals
0 - Exit
Enter Selection: 3

Change Value:
1 - Fluffy
2 - Maa
3 - Babe
Select the animal you'd like to change: 2
NEW VALUE: 651651.61

**** The number 651651.00 is an invalid entry ****
**** Please input a number between 0 and 400000 ****

NEW VALUE: 165165.61

Changing Maa's value to 165165.61 ...

1 - Initialize Animals
2 - Change Age
3 - Change Value
4 - Display Animals
0 - Exit
Enter Selection: 3

Change Value:
1 - Fluffy
2 - Maa
3 - Babe
Select the animal you'd like to change: 3
NEW VALUE: 123123.12

Changing Babe's value to 123123.12 ...

1 - Initialize Animals
2 - Change Age
3 - Change Value
4 - Display Animals
0 - Exit
Enter Selection: 4

ANIMAL     NAME           AGE    VALUE
---------- -------------- --- ------------
Sheep      Fluffy          2    $ 154154.00
Sheep      Maa             4    $ 165165.61
Pig        Babe            3    $ 123123.12

1 - Initialize Animals
2 - Change Age
3 - Change Value
4 - Display Animals
0 - Exit
Enter Selection: 1
Are you sure you want to reinitialize (Y/N)? x

**** x is an invalid entry ****
**** Please input Y or N ****

Are you sure you want to reinitialize (Y/N)? n
Animals have not been re-initialized!

1 - Initialize Animals
2 - Change Age
3 - Change Value
4 - Display Animals
0 - Exit
Enter Selection: 4

ANIMAL     NAME           AGE    VALUE
---------- -------------- --- ------------
Sheep      Fluffy          2   $ 154154.00
Sheep      Maa             4   $ 165165.61
Pig        Babe            3   $ 123123.12

1 - Initialize Animals
2 - Change Age
3 - Change Value
4 - Display Animals
0 - Exit
Enter Selection: 1
Are you sure you want to reinitialize (Y/N)? y
Initializing Fluffy, Maa, & Babe...

1 - Initialize Animals
2 - Change Age
3 - Change Value
4 - Display Animals
0 - Exit
Enter Selection: 4

ANIMAL     NAME           AGE    VALUE
---------- -------------- --- ------------
Sheep      Fluffy          1    $ 15000.00
Sheep      Maa             2    $ 16520.35
Pig        Babe            3    $ 10240.67

1 - Initialize Animals
2 - Change Age
3 - Change Value
4 - Display Animals
0 - Exit
Enter Selection: 0

#ifndef HEADER_H_
#define HEADER_H_
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "Animal.h"
using namespace std;

enum MenuOption {
  Exit = 0,
  InitAnimals,
  ChangeAge,
  ChangeValue,
  Display,
  NEW,
  Menu,
};

/*******************************************************************************
 * switchLoop
 ------------------------------------------------------------------------------- 
 * FUNCTION: Primarily the main loop of our program, this function is in charge
 * of delegating work to other functions and also providing execption handling
 * on a switch case level. This takes in a vector of Type Animal and uses
 * multiple functions for validation of what user inputed for MenuOption
 * @param animals this is a vector of Type Animal see class Animal for reference
 * RETURNS - void
 ******************************************************************************/
void switchLoop(vector<Animal> &animals);

/*******************************************************************************
 * validateFloatBounds
 ------------------------------------------------------------------------------- 
 * FUNCTION: this function handles validation of type float with specified
 * bounds MIN and MAX uses do while try catch and ||
 * @param menuOption holds menu choice of user
 * @param MIN holds minimum boundary
 * @param MAX holds maximum boundary
 * @param option holds string difference if there is any
 * @param initialized bool that holds if Animals have been initialized
 * RETURNS - float
 ******************************************************************************/
float validateFloatBounds(const MenuOption &menuOption, const int MIN, const int MAX,
               const string &option, const bool &initialized);

/*******************************************************************************
 * validation
 ------------------------------------------------------------------------------- 
 * FUNCTION: this validation function is the bread and butter of the program
 * it handles validation for most of the program with delgating print function to
 * throwing to catch error handling
 * @param choice is a deciding factor for helper in switchLoop default
 * @param menuOption holds menu choice of user
 * @param MIN holds minimum boundary
 * @param MAX holds maximum boundary
 * @param option holds string difference if there is any
 * @param initialized bool that holds if Animals have been initialized
 * RETURNS - int
 ******************************************************************************/
int validation(int choice, const MenuOption &menuOption, const int MIN, const int MAX,
               const string &option, const bool &initialized);

/*******************************************************************************
 * validateBounds
 ------------------------------------------------------------------------------- 
 * FUNCTION: This function uses the validation function but adds on top of it 
 * bounds checking
 * @param choice is a deciding factor for helper in switchLoop default
 * @param menuOption holds menu choice of user
 * @param MIN holds minimum boundary
 * @param MAX holds maximum boundary
 * @param option holds string difference if there is any
 * @param initialized bool that holds if Animals have been initialized
 * RETURNS - int
 ******************************************************************************/
int validateBounds(int choice, const MenuOption &menuOption, const int MIN, const int MAX,
               const string &option, const bool &initialized);

/*******************************************************************************
 * validateFloatBounds
 ------------------------------------------------------------------------------- 
 * FUNCTION: this function handles validation of type float with specified
 * bounds MIN and MAX
 * @param menuOption holds menu choice of user
 * @param MIN holds minimum boundary
 * @param MAX holds maximum boundary
 * @param option holds string difference if there is any
 * @param initialized bool that holds if Animals have been initialized
 * RETURNS - float
 ******************************************************************************/
float floatValidation(const MenuOption &menuOption, const int MIN, const int MAX,
               const string &option, const bool &initialized);

/*******************************************************************************
 * printSetMenu
 ------------------------------------------------------------------------------- 
 * FUNCTION: prints out menu for change cases
 * @param option
 * RETURNS - void
 ******************************************************************************/
void printSetMenu(const string &option);

/*******************************************************************************
 * printMenu
 ------------------------------------------------------------------------------- 
 * FUNCTION: prints main menu and sub menu
 * @param initialized
 * RETURNS - void
 ******************************************************************************/
void printMenu(const bool &initialized);

/*******************************************************************************
 * Class heading
 ------------------------------------------------------------------------------- 
 * FUNCTION: This is function that prints out class heading
 * @param PROGRAMMER[]
 * @param CLASS[]     
 * @param SECTION[]   
 * @param LAB_NUM     
 * @param LAB_NAME[]  
 * RETURNS - void
 ******************************************************************************/
void heading();

/*******************************************************************************
 * validateChar
 ------------------------------------------------------------------------------- 
 * FUNCTION: this is a validation for a type char, uses toupper and do while for
 * bounds validation
 * @param init
 * RETURNS - void
 ******************************************************************************/
void validateChar(char &init);

/*******************************************************************************
 * overloaded insertion operator
 ------------------------------------------------------------------------------- 
 * FUNCTION: This is really just a throw away function that was not used I just
 * wanted to get some advice on if this would be the best or proper way to 
 * return an istream variable with the casting and all that
 * @param is This is an istream variable that returns the buffer into the rhs
 * @param choice MenuOption variable that captures what menu choice user 
 * selected
 * RETURNS - istream
 ******************************************************************************/
istream &operator>> (istream &is, MenuOption& choice);

#endif // HEADER_H_

#ifndef ANIMAL_H_
#define ANIMAL_H_
#include "header.h"
/*******************************************************************************
 * Animal
 ------------------------------------------------------------------------------- 
 * CLASS: This class holds animals methods below
 * @param m_Name
 * @param m_Type
 * @param m_Age
 * @param m_Value
 ******************************************************************************/

class Animal {
 public:
/*******************************************************************************
 * Animal Constructor
 ------------------------------------------------------------------------------- 
 * FUNCTION: This constructor is a no arguments cnstr and initializes member
 * variables using initializer list
 * RETURNS - this->object
 ******************************************************************************/
  Animal ();

/*******************************************************************************
 * Animal Constructor
 ------------------------------------------------------------------------------- 
 * FUNCTION: This constructor takes in 4 args name, type, age, and value then 
 * initializes member variables using initializer list
 * @param name this variable is taken when object gets instantiated
 * @param type this variable is taken when object gets instantiated
 * @param age this variable is taken when object gets instantiated
 * @param value this variable is taken when object gets instantiated
 * RETURNS - this->object
 ******************************************************************************/
  Animal(string name, string type, int age, float value);

/*******************************************************************************
 * Animal Destructor
 ------------------------------------------------------------------------------- 
 * FUNCTION: This deconstructs this->object
 ******************************************************************************/
  ~Animal ();

/*******************************************************************************
 * setInitialValues
 ------------------------------------------------------------------------------- 
 * FUNCTION: this method takes in name, type, age and value then assigns it to
 * all members in this->object
 * @param name passed in and used for assigning to member variables
 * @param type passed in and used for assigning to member variables
 * @param age passed in and used for assigning to member variables
 * @param value passed in and used for assigning to member variables
 * RETURNS - void
 ******************************************************************************/
  void setInitialValues (string name, string type, int age, float value);

/*******************************************************************************
 * changeAge
 ------------------------------------------------------------------------------- 
 * FUNCTION: takes in int age and assigns age to m_Age
 * @param age stores age passed in
 * RETURNS - void
 ******************************************************************************/
  void changeAge (int age);

/*******************************************************************************
 * changeValue
 ------------------------------------------------------------------------------- 
 * FUNCTION: takes in float value and assigns value to m_Value
 * @param value stores value passed in
 * RETURNS - void
 ******************************************************************************/
  void changeValue (float value);

/*******************************************************************************
 * display
 ------------------------------------------------------------------------------- 
 * FUNCTION: Displays all current objects member variables, also static int to 
 * hold when to output header
 * RETURNS - void
 ******************************************************************************/
  void display () const;

/*******************************************************************************
 * getName
 ------------------------------------------------------------------------------- 
 * FUNCTION: returns m_Name
 * RETURNS - string
 ******************************************************************************/
  string getName () const;

/*******************************************************************************
 * getType
 ------------------------------------------------------------------------------- 
 * FUNCTION: returns m_Type
 * RETURNS - string
 ******************************************************************************/
  string getType () const;

/*******************************************************************************
 * getAge
 ------------------------------------------------------------------------------- 
 * FUNCTION: returns m_Age
 * RETURNS - int
 ******************************************************************************/
  int getAge () const;

/*******************************************************************************
 * getValue
 ------------------------------------------------------------------------------- 
 * FUNCTION: returns m_Value
 * RETURNS - float
 ******************************************************************************/
  float getValue () const;
 private:
  string m_Name; // DATA TABLE: m_Name holds name of animal
  string m_Type; // DATA TABLE: m_Type holds type of animal
  int m_Age;     // DATA TABLE: m_Age holds age of animal
  float m_Value; // DATA TABLE: m_Value holds price of animal
};
#endif // ANIMAL_H_

#include "../include/header.h"
#include "../include/Animal.h"
/*******************************************************************************
 * AUTHOR      : Carlos Aguilera
 * STUDENT ID  : 1152562
 * LAB #12     : Introduction OOP
 * CLASS       : CS1B
 * SECTION     : M-W
 * DUE DATE    : 05.02.22
 ******************************************************************************/

/******************************************************************************
 * Title: Introduction OOP
 * ----------------------------------------------------------------------------
 * PROGRAM:
 * 
 * ----------------------------------------------------------------------------
 ******************************************************************************/

int main() {
  heading();
  // PROCESSING: VECTOR OF ANIMALS
  vector<Animal> animals;
  animals.push_back(Animal ("Fluffy", "Sheep", 1, 15000.00f));
  animals.push_back(Animal ("Maa", "Sheep", 2, 16520.35f));
  animals.push_back(Animal ("Babe", "Pig", 3, 10240.67f));
  // PROCESSING: Switch Loop
  switchLoop(animals);
  return 0;
}

#include "../../include/header.h"

/*******************************************************************************
 * Animal Constructor
 ------------------------------------------------------------------------------- 
 * FUNCTION: This constructor is a no arguments cnstr and initializes member
 * variables using initializer list
 * RETURNS - this->object
 ******************************************************************************/
Animal::Animal() : m_Type(""), m_Name(""), m_Age(0), m_Value(0) {}

/*******************************************************************************
 * Animal Constructor
 ------------------------------------------------------------------------------- 
 * FUNCTION: This constructor takes in 4 args name, type, age, and value then 
 * initializes member variables using initializer list
 * @param name this variable is taken when object gets instantiated
 * @param type this variable is taken when object gets instantiated
 * @param age this variable is taken when object gets instantiated
 * @param value this variable is taken when object gets instantiated
 * RETURNS - this->object
 ******************************************************************************/
Animal::Animal(string name, string type, int age, float value) 
    : m_Type(type), m_Name(name), m_Age(age), m_Value(value) {}

/*******************************************************************************
 * Animal Destructor
 ------------------------------------------------------------------------------- 
 * FUNCTION: This deconstructs this->object
 ******************************************************************************/
Animal::~Animal () {}

/*******************************************************************************
 * setInitialValues
 ------------------------------------------------------------------------------- 
 * FUNCTION: this method takes in name, type, age and value then assigns it to
 * all members in this->object
 * @param name passed in and used for assigning to member variables
 * @param type passed in and used for assigning to member variables
 * @param age passed in and used for assigning to member variables
 * @param value passed in and used for assigning to member variables
 * RETURNS - void
 ******************************************************************************/
void Animal::setInitialValues (string name, string type, int age,
                               float value) {
  this->m_Name= name;
  this->m_Type = type;
  this->m_Age= age;
  this->m_Value = value;
}

/*******************************************************************************
 * changeAge
 ------------------------------------------------------------------------------- 
 * FUNCTION: takes in int age and assigns age to m_Age
 * @param age stores age passed in
 * RETURNS - void
 ******************************************************************************/
void Animal::changeAge (int age) { this->m_Age = age; }

/*******************************************************************************
 * changeValue
 ------------------------------------------------------------------------------- 
 * FUNCTION: takes in float value and assigns value to m_Value
 * @param value stores value passed in
 * RETURNS - void
 ******************************************************************************/
void Animal::changeValue (float value) { this->m_Value = value; }

/*******************************************************************************
 * display
 ------------------------------------------------------------------------------- 
 * FUNCTION: Displays all current objects member variables, also static int to 
 * hold when to output header
 * RETURNS - void
 ******************************************************************************/
void Animal::display () const {
  static int i = 0;
  // PROCESSING: if first iteration then print header
  if (i == 0) {
    cout << left;
    cout << setw(12) << "\nANIMAL" << setw(15) << "NAME";
    cout << setw(7) << "AGE" << setw(6) << "VALUE\n";
    cout << "----------" << " --------------" << " ---" << " ------------\n";
    cout << right;
  }
  // PROCESSING: print this->objects attributes
  cout << left;
  cout << setw(11) << m_Type << setw(16) << m_Name;
  cout << right << setw(1) << m_Age << setprecision(2);
  cout << fixed << setw(6) << "$ " << setw(7) << m_Value << "\n";
  cout << right;
  // Header logic
  if (i < 2) {
    ++i;
  }else {
    i = 0;
  }
}

/*******************************************************************************
 * getName
 ------------------------------------------------------------------------------- 
 * FUNCTION: returns m_Name
 * RETURNS - string
 ******************************************************************************/
string Animal::getName () const { return this->m_Name; }

/*******************************************************************************
 * getType
 ------------------------------------------------------------------------------- 
 * FUNCTION: returns m_Type
 * RETURNS - string
 ******************************************************************************/
string Animal::getType () const { return this->m_Type; }

/*******************************************************************************
 * getAge
 ------------------------------------------------------------------------------- 
 * FUNCTION: returns m_Age
 * RETURNS - int
 ******************************************************************************/
int Animal::getAge () const { return this->m_Age; }

/*******************************************************************************
 * getValue
 ------------------------------------------------------------------------------- 
 * FUNCTION: returns m_Value
 * RETURNS - float
 ******************************************************************************/
float Animal::getValue () const { return this->m_Value; }

#include "../../include/header.h"

/*******************************************************************************
 * overloaded insertion operator
 ------------------------------------------------------------------------------- 
 * FUNCTION: This is really just a throw away function that was not used I just
 * wanted to get some advice on if this would be the best or proper way to 
 * return an istream variable with the casting and all that
 * @param is This is an istream variable that returns the buffer into the rhs
 * @param choice MenuOption variable that captures what menu choice user 
 * selected
 * RETURNS - istream
 ******************************************************************************/
istream &operator>>(istream &is, MenuOption &choice) {
  int data;
  is >> data;
  // PROCESSING: cast data into type MenuOption and store result in choice
  choice = MenuOption(data);
  return is;
}

/*******************************************************************************
 * validation
 ------------------------------------------------------------------------------- 
 * FUNCTION: this validation function is the bread and butter of the program
 * it handles validation for most of the program with delgating print function to
 * throwing to catch error handling
 * @param choice is a deciding factor for helper in switchLoop default
 * @param menuOption holds menu choice of user
 * @param MIN holds minimum boundary
 * @param MAX holds maximum boundary
 * @param option holds string difference if there is any
 * @param initialized bool that holds if Animals have been initialized
 * RETURNS - int
 ******************************************************************************/

int validation(int choice, const MenuOption &menuOption, const int MIN, const int MAX,
               const string &option, const bool &initialized) {
  bool validated = false;
  // PROCESSING: validation
  do {
    try{
      // prints set menu if not InitAnimals
      if (menuOption == ChangeAge || menuOption == ChangeValue) {
        // PROCESSING: call printSetMenu
        printSetMenu(option);
      }else if (menuOption == InitAnimals) {
        printMenu(initialized);
      }else if (menuOption == NEW) {
        cout << "NEW " << option << ": ";
      }
      if (menuOption != Menu) {
        cin >> choice;
        cin.ignore(1000, '\n');
      }
      if (cin.fail()) {
        throw true;
      }
      validated = true;
    } catch(bool invalid) {
      // Catching exception clearing buffer and relooping
      cout << "\n**** Please enter a NUMBER between " << MIN << " and ";
      cout << MAX << " ****\n";
      cin.clear();
      cin.ignore(1000, '\n');
    }
  }while (!validated);
  return choice;
}

/*******************************************************************************
 * validateFloatBounds
 ------------------------------------------------------------------------------- 
 * FUNCTION: this function handles validation of type float with specified
 * bounds MIN and MAX
 * @param menuOption holds menu choice of user
 * @param MIN holds minimum boundary
 * @param MAX holds maximum boundary
 * @param option holds string difference if there is any
 * @param initialized bool that holds if Animals have been initialized
 * RETURNS - float
 ******************************************************************************/

float floatValidation(const MenuOption &menuOption, const int MIN, const int MAX,
               const string &option, const bool &initialized) {
  float choice;
  bool validated = false;
  // PROCESSING: validation
  do {
    try{
      if (menuOption == ChangeAge || menuOption == ChangeValue) {
        printSetMenu(option);
      }else if (menuOption == InitAnimals) {
        printMenu(initialized);
      }else {
        cout << "\nNEW " << option << ": ";
      }
      cin >> choice;
      cin.ignore(1000, '\n');
      if (cin.fail()) {
        throw true;
      }
      validated = true;
    } catch(bool invalid) {
      // Catching exception clearing buffer and relooping
      cout << "\n**** Please enter a NUMBER between " << MIN << " and ";
      cout << MAX << " ****\n";
      cin.clear();
      cin.ignore(1000, '\n');
    }
  }while (!validated);
  return choice;
}

/*******************************************************************************
 * validateChar
 ------------------------------------------------------------------------------- 
 * FUNCTION: this is a validation for a type char, uses toupper and do while for
 * bounds validation
 * @param init
 * RETURNS - void
 ******************************************************************************/

void validateChar(char &init) {
  bool validated = false;
  do {
    try{
      cout << "Are you sure you want to reinitialize (Y/N)? ";
      cin.get(init);
      cin.ignore(1000, '\n');
      // PROCESSING: toupper just incase they did not capitalize
      if (toupper(init) != 'Y' && toupper(init) != 'N') {
        throw true;
      }
      validated = true;
    } catch(bool invalid) {
      cout << "\n**** " << init << " is an invalid entry ****\n";
      cout << "**** Please input Y or N ****\n\n";
    }
  }while (!validated);

}

#include "../../include/header.h"

/*******************************************************************************
 * validateBounds
 ------------------------------------------------------------------------------- 
 * FUNCTION: This function uses the validation function but adds on top of it 
 * bounds checking
 * @param choice is a deciding factor for helper in switchLoop default
 * @param menuOption holds menu choice of user
 * @param MIN holds minimum boundary
 * @param MAX holds maximum boundary
 * @param option holds string difference if there is any
 * @param initialized bool that holds if Animals have been initialized
 * RETURNS - int
 ******************************************************************************/

int validateBounds(int choice, const MenuOption &menuOption, const int MIN, const int MAX,
               const string &option, const bool &initialized) {
  int validate;
  do {
    // calling validation and storing result in validate
    validate = validation(choice, menuOption, MIN, MAX, option, initialized);
    // PROCESSING: bounds still needs to be validated
    if (validate < MIN || validate > MAX) {
      cout << "\n**** The number " << validate << " is an invalid entry ****\n";
      cout << "**** Please input a number between " << MIN << " and " << MAX << " ****\n\n";
      // if menuOption is menu then return back to switch statement
      if (menuOption == Menu)
        return 0;
    }
  } while (validate < MIN || validate > MAX);
  return validate;
}

/*******************************************************************************
 * validateFloatBounds
 ------------------------------------------------------------------------------- 
 * FUNCTION: this function handles validation of type float with specified
 * bounds MIN and MAX uses do while try catch and ||
 * @param menuOption holds menu choice of user
 * @param MIN holds minimum boundary
 * @param MAX holds maximum boundary
 * @param option holds string difference if there is any
 * @param initialized bool that holds if Animals have been initialized
 * RETURNS - float
 ******************************************************************************/

float validateFloatBounds(const MenuOption &menuOption, const int MIN, const int MAX,
               const string &option, const bool &initialized) {
  float validate;
  do {
    // calling validation and storing result in validate
    validate = validation(0, menuOption, MIN, MAX, option, initialized);
    // PROCESSING: bounds still needs to be validated
    if (validate < MIN || validate > MAX) {
      cout << "\n**** The number " << validate << " is an invalid entry ****\n";
      cout << "**** Please input a number between " << MIN << " and " << MAX << " ****\n\n";
    }
  } while (validate < MIN || validate > MAX);
  return validate;
}

#include "../../include/header.h"

/*******************************************************************************
 * switchLoop
 ------------------------------------------------------------------------------- 
 * FUNCTION: Primarily the main loop of our program, this function is in charge
 * of delegating work to other functions and also providing execption handling
 * on a switch case level. This takes in a vector of Type Animal and uses
 * multiple functions for validation of what user inputed for MenuOption
 * @param animals this is a vector of Type Animal see class Animal for reference
 * RETURNS - void
 ******************************************************************************/

void switchLoop(vector<Animal> &animals) {
  bool initialized = false;
  MenuOption choice = Exit;
  do {
    // PROCESSING: validating int and after casting it into type MenuOption
    // Also using tenary operator for bounds 
    choice = MenuOption(validation(0, InitAnimals, 0, ((initialized) ? 4 : 1),
                                   "", initialized));
    // only happens in first menu
    if (!initialized && choice > 1 || choice < 0) {
      validateBounds(choice, Menu, 0, 1, "", initialized);
      continue;
    }
    switch (choice) {
      case Exit: {
        break;
      }
      case InitAnimals: {
        if (initialized) {
          char init;
          validateChar(init);
          // reintialize is Y then run setInitialValue
          if (toupper(init) == 'Y') {
            animals[0].setInitialValues("Fluffy", "Sheep", 1, 15000.00f);
            animals[1].setInitialValues("Maa", "Sheep", 2, 16520.35f);
            animals[2].setInitialValues("Babe", "Pig", 3, 10240.67f);
            cout << "Initializing Fluffy, Maa, & Babe...\n";
          }else {
            cout << "Animals have not been re-initialized!\n";
          }
        }
        initialized = true;
        break;
      }
      case ChangeAge: {
        // PROCESSING: calling validateBounds and storing it in AnimalChoice
        int animalChoice = validateBounds(0, ChangeAge, 1, 3, "Change Age", true);
        // PROCESSING: calling validateBounds and storing it in ageChoice
        int ageChoice = validateBounds(0, NEW, 1, 10, "AGE", true);
        // PROCESSING: this way because of the way menu is set up - 1 because array starts at 0
        animals[animalChoice - 1].changeAge(ageChoice);
        cout << "\nChanging " << animals[animalChoice - 1].getName() << "'s age to " << ageChoice << " ...\n";
        break;
      }
      case ChangeValue: {
        // PROCESSING: calling validateBounds and storing it in AnimalChoice
        int animalChoice = validateBounds(0, ChangeAge, 1, 3, "Change Value", true);
        // PROCESSING: calling validateFloatBounds and storing it in valueChoice
        float valueChoice = validateFloatBounds(NEW, 0, 400000, "VALUE", true);
        // PROCESSING: this way because of the way menu is set up - 1 because array starts at 0
        animals[animalChoice - 1].changeValue(valueChoice);
        cout << "\nChanging " << animals[animalChoice - 1].getName() << "'s value to " << valueChoice << " ...\n";
        break;
      }
      case Display: {
        animals[0].display();
        animals[1].display();
        animals[2].display();
        break;
      }
      default: {
        validateBounds(choice, Menu, 0, 4, "", true);
        break;
      }
    }
  }while (choice != 0);
}

#include "../../include/header.h"

/*******************************************************************************
 * printSetMenu
 ------------------------------------------------------------------------------- 
 * FUNCTION: prints out menu for change cases
 * @param option
 * RETURNS - void
 ******************************************************************************/

void printSetMenu(const string &option) {
  cout << "\n" << option << ":\n";
  cout << "1 - Fluffy\n";
  cout << "2 - Maa\n";
  cout << "3 - Babe\n";
  cout << "Select the animal you'd like to change: ";
  return; 
}

#include "../../include/header.h"

/*******************************************************************************
 * printMenu
 ------------------------------------------------------------------------------- 
 * FUNCTION: prints main menu and sub menu
 * @param initialized
 * RETURNS - void
 ******************************************************************************/

void printMenu(const bool &initialized) {
  cout << "\n1 - Initialize Animals\n";
  if (initialized) {
    cout << "2 - Change Age\n";
    cout << "3 - Change Value\n";
    cout << "4 - Display Animals\n";
  }
  cout << "0 - Exit\n";
  cout << "Enter Selection: ";
  return;
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
	const int  LAB_NUM       = 12;
	const char LAB_NAME[]   = "Introduction OOP";

	cout << left;
	cout << "****************************************************\n";
	cout << "*   PROGRAMMED BY : " << PROGRAMMER << endl;
	cout << "*   " << setw(14) <<"CLASS" << ": " << CLASS << endl;
	cout << "*   " << setw(14) <<"SECTION" << ": " << SECTION << endl;
	cout << "*   LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME << endl;
	cout << "****************************************************\n";
	cout << right;
}