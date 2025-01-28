#ifndef MAIN_H_
#define MAIN_H_
#include "../include/Sheep.h"
#include "../include/Livestock.h"
using namespace std;

enum MenuType { kMain = 0, kEntry, kAnimal, kChoosingAnimal, kChoosingAge };
enum MenuOptions { 
  kExit = 0,
  kInitializeAnimals,
  kReInitializeSheep,
  kReInitializePig,
  kChangeAge,
  kDisplayAnimals,
};
enum AnimalMenu { kAnimalExit = 0, kSheep, kPig };

/*******************************************************************************
 * class heading
 ------------------------------------------------------------------------------- 
 * function: this method prints out class heading
 * returns - void
 ******************************************************************************/
void heading();

/*******************************************************************************
 * Initialize Sheeps
 ------------------------------------------------------------------------------- 
 * FUNCTION: This Function reads from a file (Sheep.txt) and plugs in values
 * into a vector that holds sheep, Livestock is responsible for having that
 * vector. Attributes are validated using a function named attributesValidated
 * and Logs any Errors with Initialization. With the conversion of a string
 * to an enum type, a map is used to have the string be the key and enum be the
 * pair and once validated we match one and one.
 * @param livestock - livestock to hold the Animals using vector
 * RETURNS - void
 ******************************************************************************/
void initSheeps(Livestock &livestock);

/*******************************************************************************
 * Initialize Pigs
 ------------------------------------------------------------------------------- 
 * FUNCTION: This Function reads from a file (Pig.txt) and plugs in values
 * into a vector that holds sheep, Livestock is responsible for having that
 * vector. Attributes are validated using a function named attributesValidated
 * and Logs any Errors with Initialization. With the conversion of a string
 * to an enum type, a map is used to have the string be the key and enum be the
 * pair and once validated we match one and one.
 * @param livestock - livestock to hold the Animals using vector
 * RETURNS - void
 ******************************************************************************/
void initPigs(Livestock &livestock);

/*******************************************************************************
 * Print Menu
 ------------------------------------------------------------------------------- 
 * FUNCTION:
 * @param menu - enum type to tell function what curr menu the program state is
 * RETURNS - void
 ******************************************************************************/
void menu(const MenuType &menu);

/*******************************************************************************
 * Switch Delegation
 ------------------------------------------------------------------------------- 
 * FUNCTION: Handles the delegation of methods and menu options, this is done
 * with a switch case
 * @param livestock - class that holds Animals
 * @param choice - enum of menu options for the program
 * @param menuType - curr menu
 * RETURNS - void
 ******************************************************************************/
void switchLoop(Livestock &livestock, MenuOptions &choice, MenuType &menuType);

#endif // MAIN_H_

#include "../include/main.h"
#include "handlers/mainSwitch.cpp"
/*******************************************************************************
 * AUTHOR      : Carlos Aguilera
 * STUDENT ID  : 1152562
 * LAB #14     : Inheritance, Overloading, Redefining
 * CLASS       : CS1B
 * SECTION     : M-W
 * DUE DATE    : 05.18.22
 ******************************************************************************/

/******************************************************************************
 * Animal Tracking 2.0
 * ----------------------------------------------------------------------------
 * PROGRAM: Animal Tracking 2.0 is a program that tracks Animals, two in
 * specific Sheep, and Pig. This is done with a class that stores them and
 * has methods to edit, view and manipulate list. Most input validation happens,
 * First menu that is prompted is Initialize or Exit, second is a varity of
 * options from re-initialize to display list. Age of an animal can only be
 * set from 0 - 10 anything else will result in an exception being thrown.
 * Something important to note is list gets generated and re-generated
 * using a two txt files Sheep.txt & Pig.txt both have respective attributes.
 * Any wrong or out of bounds input from file will result in a exception being
 * thrown and printed to console and current Animal being worked with does not
 * get intitialized.
 * ----------------------------------------------------------------------------
 ******************************************************************************/


int main() {
  heading();
  Livestock livestock;        // livestock - Lives through scope of program 
  MenuOptions choice = kExit; // choice - Menu Option
  MenuType menuType = kEntry; // menuType - Menu Type
  // PROCCESSING: Main loop of program
  do {
    switchLoop(livestock, choice, menuType);
  } while (choice != kExit);
  return 0;
}

#include "../../include/main.h"

/*******************************************************************************
 * Validation For Program
 ------------------------------------------------------------------------------- 
 * FUNCTION: Handles Validation for switch case, and change age methods, this
 * is done by do while try catch and throws string with corresponding exception
 * @param menuType - To print proper menu while repeating validation
 * @param MIN - Minimum bounds of input
 * @param MAX - Maximum bounds of input
 * RETURNS - unsigned int
 ******************************************************************************/
unsigned int caseValidation(const MenuType &menuType, const int &MIN, const int &MAX);

/*******************************************************************************
 * Change Animal Age
 ------------------------------------------------------------------------------- 
 * FUNCTION: Determines what Animal user wants to choose from, once decided
 * uses iteration to print all specified Animals, lastly user chooses what Animal
 * to change age
 * @param livestock
 * RETURNS - void
 ******************************************************************************/
void changeAnimalAge(Livestock &livestock);

/*******************************************************************************
 * Switch Delegation
 ------------------------------------------------------------------------------- 
 * FUNCTION: Handles the delegation of methods and menu options, this is done
 * with a switch case
 * @param livestock - class that holds Animals
 * @param choice - enum of menu options for the program
 * @param menuType - curr menu
 * RETURNS - void
 ******************************************************************************/
void switchLoop(Livestock &livestock, MenuOptions &choice, MenuType &menuType) {
  // PROCCESSING: Calls validation, for menu and casts into MenuOptions
  choice = MenuOptions(caseValidation(menuType, 0, ((menuType == kMain) ? 4 : 1)));
  // PROCCESSING: Delegation of program
  switch (choice) {
    case kExit: {
      break;
    }
    case kInitializeAnimals: {
      // PROCCESSING: Clears list before initializing
      livestock.clear();
      initPigs(livestock);
      initSheeps(livestock);
      menuType = kMain;
      break;
    }
    case kReInitializeSheep: {
      // PROCCESSING: Clears Sheep list before initializing
      livestock.clearSheep();
      initSheeps(livestock);
      break;
    }
    case kReInitializePig: {
      // PROCCESSING: Clears Pig list before initializing
      livestock.clearPig();
      initPigs(livestock);
      break;
    }
    case kChangeAge: {
      changeAnimalAge(livestock);
      break;
    }
    case kDisplayAnimals: {
      livestock.print();
      break;
    }
    default: {
      break;
    }
  }
}

/*******************************************************************************
 * Validation For Program
 ------------------------------------------------------------------------------- 
 * FUNCTION: Handles Validation for switch case, and change animal methods, this
 * is done by do while try catch and throws string with corresponding exception
 * @param menuType - To print proper menu while repeating validation
 * @param MIN - Minimum bounds of input
 * @param MAX - Maximum bounds of input
 * RETURNS - unsigned int
 ******************************************************************************/
unsigned int caseValidation(const MenuType &menuType, const int &MIN, const int &MAX) {
  bool validated = false; // bool for do while loop
  unsigned int choice;    // choice of user input
  do {
    try {
      // PROCCESSING: Calls menu with respective menuType past in
      menu(menuType);
      cin >> choice;
      // PROCCESSING: If cin failed clear buffer and throw exception
      if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        throw string("[Input stores integers]");
      }
      // PROCCESSING: Bounds check
      if (choice < MIN || choice > MAX)
        throw string("[Invalid MIN or MAX]");
      // PROCCESSING: if all went well validate
      validated = true;
    } catch(const string &e) {
      cout << "\nERROR: " << e << "\n";
    }
  } while (!validated);
  // PROCCESSING: This is to insure once they are in main menu we ++choice because
  // we are using the same Enum so numbers are one off
  if (menuType == kMain && choice != 0)
    ++choice;
  return choice;
}

/*******************************************************************************
 * Change Animal Age
 ------------------------------------------------------------------------------- 
 * FUNCTION: Determines what Animal user wants to choose from, once decided
 * uses iteration to print all specified Animals, lastly user chooses what Animal
 * to change age
 * @param livestock
 * RETURNS - void
 ******************************************************************************/
void changeAnimalAge(Livestock &livestock) {
  // PROCCESSING: Calls validation for choosing Sheep or Pig
  AnimalMenu choice = AnimalMenu(caseValidation(kAnimal, 0, 2));
  // PROCCESSING: Directs to user choice
  if (choice == kAnimalExit) {
    return;
  } else if (choice == kSheep) {
    cout << "\nSHEEP LIVESTOCK LIST:\n";
    // PROCCESSING: Prints all Sheep in livestock
    for (int i = 0; i < livestock.m_SheepLivestock.size(); ++i) {
      cout << i+1 << ". " << livestock.m_SheepLivestock[i].getName() << "\n";
    }
    // PROCCESSING: Validates index for m_SheepLivestock.size()
    unsigned int index = caseValidation(kChoosingAnimal, 1, livestock.m_SheepLivestock.size()) - 1;
    // PROCCESSING: Using validated index to access element and validate set age
    livestock.m_SheepLivestock[index].setAge(caseValidation(kChoosingAge, 0, 10));
  } else if (choice == kPig) {
    cout << "\nPIG LIVESTOCK LIST:\n";
    // PROCCESSING: Prints all Pig in livestock
    for (int i = 0; i < livestock.m_PigLivestock.size(); ++i) {
      cout << i+1 << ". " << livestock.m_PigLivestock[i].getName() << "\n";
    }
    // PROCCESSING: Validates index for m_PigLivestock.size()
    unsigned int index = caseValidation(kChoosingAnimal, 1, livestock.m_PigLivestock.size()) - 1;
    // PROCCESSING: Using validated index to access element and validate set age
    livestock.m_PigLivestock[index].setAge(caseValidation(kChoosingAge, 0, 10));
  }
}

#include "../../include/Livestock.h"
#include <fstream>
#include <map>

/*******************************************************************************
 * Attributes Validated
 ------------------------------------------------------------------------------- 
 * FUNCTION: Validates Age, Wool Type, and Wool Color
 * @param errorCode - Error code if function produced any
 * @param age - age that needs to be validated
 * @param woolType - Wool Type to validate
 * @param woolColor - Wool Color to validate
 * RETURNS - bool
 ******************************************************************************/
bool attributesValidated(string &errorCode, const unsigned int &age,
                         const string &woolType, const string &woolColor);

/*******************************************************************************
 * Log Validation Error
 ------------------------------------------------------------------------------- 
 * FUNCTION: Logs Validation Error that was returned from attributesValidated
 * @param errorCode - Error code if function produced any
 * @param name - name of this->Sheep
 * @param age - age of this->Sheep
 * @param woolType - Wool Type this->Sheep
 * @param woolColor - Wool Color this->Sheep
 * RETURNS - void
 ******************************************************************************/
void LogValidationError(const string &errorCode, const string &name,
                        const unsigned int &age, const string &woolType,
                        const string &woolColor);

/*******************************************************************************
 * Initialize Sheeps
 ------------------------------------------------------------------------------- 
 * FUNCTION: This Function reads from a file (Sheep.txt) and plugs in values
 * into a vector that holds sheep, Livestock is responsible for having that
 * vector. Attributes are validated using a function named attributesValidated
 * and Logs any Errors with Initialization. With the conversion of a string
 * to an enum type, a map is used to have the string be the key and enum be the
 * pair and once validated we match one and one.
 * @param livestock - livestock to hold the Animals using vector
 * RETURNS - void
 ******************************************************************************/
void initSheeps(Livestock &livestock) {
  // PROCCESSING: Initializing map string -> enum
  map<string, WoolType> StringToWoolType = {
    {"Long", kLong},
    {"Medium", kMedium},
    {"Fine", kFine},
    {"Carpet", kCarpet}
  };
  // PROCCESSING: Initializing map string -> enum
  map<string, WoolColor> StringToWoolColor= {
    {"White", kWhite},
    {"Black", kBlack}
  };
  string name;
  unsigned int age;
  string woolType;
  string woolColor;
  string errorCode;
  fstream fin("Sheep.txt", ios::in);
  // PROCCESSING: Check if file opened successfully
  if (fin.is_open()) {
    // PROCCESSING: While not end of file
    while (!fin.eof()) {
      getline(fin, name);
      fin >> age;
      // PROCCESSING: if cin fails age = -1;
      if (fin.fail()) {
        fin.clear();
        age = -1;
      }
      fin.ignore(1000, '\n');
      getline(fin, woolType);
      getline(fin, woolColor);
      fin.ignore(1000, '\n');
      // PROCCESING: if attributes were not validated log error
      if (!attributesValidated(errorCode, age, woolType, woolColor)) {
        LogValidationError(errorCode, name, age, woolType, woolColor);
        // PROCCESSING: used to not push back animal
        continue;
      }
      // PROCCESSING: Pushing back with swapped enum pairs
      livestock.m_SheepLivestock.push_back(
        move(Sheep(name, age, StringToWoolType[woolType],
        StringToWoolColor[woolColor])));
    }
  } else {
    cerr << "ERROR: [Opening Sheep.txt]\n";
  }
  fin.close();
}

/*******************************************************************************
 * Attributes Validated
 ------------------------------------------------------------------------------- 
 * FUNCTION: Validates Age, Wool Type, and Wool Color
 * @param errorCode - Error code if function produced any
 * @param age - age that needs to be validated
 * @param woolType - Wool Type to validate
 * @param woolColor - Wool Color to validate
 * RETURNS - bool
 ******************************************************************************/
bool attributesValidated(string &errorCode, const unsigned int &age,
                         const string &woolType, const string &woolColor) {
  if (age < 0 || age > 10) {
    errorCode = "[Invalid Age]";
    return false;
  }
  if (!(woolType == "Long" || woolType == "Medium" || woolType == "Fine" || 
        woolType == "Carpet")) {
    errorCode = "[Invalid WoolType]";
    return false;
  }
  if (!(woolColor == "Black" || woolColor == "White")) {
    errorCode = "[Invalid WoolColor]";
    return false;
  }
  return true;
}

/*******************************************************************************
 * Log Validation Error
 ------------------------------------------------------------------------------- 
 * FUNCTION: Logs Validation Error that was returned from attributesValidated
 * @param errorCode - Error code if function produced any
 * @param name - name of this->Sheep
 * @param age - age of this->Sheep
 * @param woolType - Wool Type this->Sheep
 * @param woolColor - Wool Color this->Sheep
 * RETURNS - void
 ******************************************************************************/
void LogValidationError(const string &errorCode, const string &name,
                        const unsigned int &age, const string &woolType,
                        const string &woolColor) {
  cout << left;
  cout << "\nERROR CODE: " << errorCode << "\n";
  cout << setw(11) << "Name:" << name << "\n";
  cout << setw(11) << "Age:" << age << "\n";
  cout << setw(11) << "WoolType:" << woolType << "\n";
  cout << setw(11) << "WoolColor:" << woolColor << "\n";
  cout << "[Initialization failed on this Sheep]\n";
  cout << right;
}

#include "../../include/Livestock.h"
#include <fstream>

/*******************************************************************************
 * Attributes Validated
 ------------------------------------------------------------------------------- 
 * FUNCTION: Validates Age, Wool Type, and Wool Color
 * @param errorCode - Error code if function produced any
 * @param age - age that needs to be validated
 * @param tailType - Tail Type to validate
 * RETURNS - bool
 ******************************************************************************/
bool attributesValidated(string &errorCode, const unsigned int &age,
                         const string &tailType);

/*******************************************************************************
 * Log Validation Error
 ------------------------------------------------------------------------------- 
 * FUNCTION: Logs Validation Error that was returned from attributesValidated
 * @param errorCode - Error code if function produced any
 * @param name - name of this->Sheep
 * @param age - age of this->Sheep
 * @param tailType - Tail Type this->Sheep
 * RETURNS - void
 ******************************************************************************/
void LogValidationError(const string &errorCode, const string &name,
                        const unsigned int &age, const string &tailType);

/*******************************************************************************
 * Initialize Pigs
 ------------------------------------------------------------------------------- 
 * FUNCTION: This Function reads from a file (Pig.txt) and plugs in values
 * into a vector that holds sheep, Livestock is responsible for having that
 * vector. Attributes are validated using a function named attributesValidated
 * and Logs any Errors with Initialization. With the conversion of a string
 * to an enum type, a map is used to have the string be the key and enum be the
 * pair and once validated we match one and one.
 * @param livestock - livestock to hold the Animals using vector
 * RETURNS - void
 ******************************************************************************/
void initPigs(Livestock &livestock) {
  // PROCCESSING: Initializing map string -> enum
  map<string, TailType> StringToTailType = {
    {"Straight", kStraight},
    {"Corkscrew", kCorkscrew},
    {"Curl Up", kCurlUp},
    {"Curl Right", kCurlRight},
    {"Curl Left", kCurlLeft}
  };
  string name;
  unsigned int age;
  string tailType;
  string errorCode;
  fstream fin("Pig.txt", ios::in);
  // PROCCESSING: Check if file opened successfully
  if (fin.is_open()) {
    // PROCCESSING: While not end of file
    while (!fin.eof()) {
      getline(fin, name);
      fin >> age;
      // PROCCESSING: if cin fails age = -1;
      if (fin.fail()) {
        fin.clear();
        age = -1;
      }
      fin.ignore(1000, '\n');
      getline(fin, tailType);
      fin.ignore(1000, '\n');
      // PROCCESING: if attributes were not validated log error
      if (!attributesValidated(errorCode, age, tailType)) {
        LogValidationError(errorCode, name, age, tailType);
        // PROCCESSING: used to not push back animal
        continue;
      }
      // PROCCESSING: Pushing back with swapped enum pairs
      livestock.m_PigLivestock.push_back(
        move(Pig(name, age, StringToTailType[tailType])));
    }
  } else {
    cerr << "ERROR: [Opening Pig.txt]\n";
  }
  fin.close();
}

bool attributesValidated(string &errorCode, const unsigned int &age,
                         const string &tailType) {
  if (age < 0 || age > 10) {
    errorCode = "[Invalid Age]";
    return false;
  }
  if (!(tailType == "Straight" || tailType == "Corkscrew" || tailType == "Curl Up" || 
        tailType == "Curl Right" || tailType == "Curl Left")) {
    errorCode = "[Invalid TailType]";
    return false;
  }
  return true;
}

void LogValidationError(const string &errorCode, const string &name,
                        const unsigned int &age, const string &tailType) {
  cout << left;
  cout << "\nERROR CODE: " << errorCode << "\n";
  cout << setw(10) << "Name:" << name << "\n";
  cout << setw(10) << "Age:" << age << "\n";
  cout << setw(10) << "TailType:" << tailType << "\n";
  cout << "[Initialization failed on this Pig]\n";
  cout << right;
}

#include "../../include/main.h"

/*******************************************************************************
 * Print Menu
 ------------------------------------------------------------------------------- 
 * FUNCTION:
 * @param menu - enum type to tell function what curr menu the program state is
 * RETURNS - void
 ******************************************************************************/
void menu(const MenuType &menu) {
  if (menu == kEntry) {
    cout << "\nENTRY MENU:\n";
    cout << "1 - Initialize Animals\n";
    cout << "0 - Exit\n";
    cout << "Enter selection: ";
    return;
  }
  if (menu == kMain) {
    cout << "\nMAIN MENU:\n";
    cout << "1 - Re-Initialize Sheep\n";
    cout << "2 - Re-Initialize Pigs\n";
    cout << "3 - Change Age\n";
    cout << "4 - Display\n";
    cout << "0 - Exit\n";
    cout << "Enter selection: ";
    return;
  }
  if (menu == kAnimal) {
    cout << "\nANIMAL MENU:\n";
    cout << "1 - Sheep\n";
    cout << "2 - Pig\n";
    cout << "0 - Exit\n";
    cout << "Enter selection: ";
    return;
  }
  if (menu == kChoosingAnimal) {
    cout << "\nEnter selection: ";
    return;
  }
  if (menu == kChoosingAge) {
    cout << "\nEnter Age: ";
    return;
  }
}

#include <iostream>
#include <iomanip>

/*******************************************************************************
 * Class Heading
 ------------------------------------------------------------------------------- 
 * FUNCTION: This method prints out class heading
 * RETURNS - void
 ******************************************************************************/

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
	const int LAB_NUM       = 14;
	const char LAB_NAME[]   = "Inheritance, Overloading, & Redefining";

	cout << left;
	cout << "***********************************************************\n";
	cout << "*   PROGRAMMED BY : " << PROGRAMMER << endl;
	cout << "*   " << setw(14) <<"CLASS" << ": " << CLASS << endl;
	cout << "*   " << setw(14) <<"SECTION" << ": " << SECTION << endl;
	cout << "*   LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME << endl;
	cout << "***********************************************************\n";
	cout << right;
}

#ifndef ANIMAL_H_
#define ANIMAL_H_
#include <string>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

class Animal {
 public:
/*******************************************************************************
 * Animal Constructor
 ------------------------------------------------------------------------------- 
 * CONSTRUCTOR: constructs Animal with no PARAM
 ******************************************************************************/
  Animal();

/*******************************************************************************
 * Animal Constructor
 ------------------------------------------------------------------------------- 
 * CONSTRUCTOR: constructs Animal with PARAMS
 * @param name - name of this->Animal
 * @param age - age of this->Animal
 ******************************************************************************/
  Animal(const string &name, const unsigned int &age);

/*******************************************************************************
 * Animal Destructor
 ------------------------------------------------------------------------------- 
 * DESTRUCTOR: Destructs this->Animal
 ******************************************************************************/
  ~Animal() {}

  // Getters
/*******************************************************************************
 * Get Name of calling Animal
 ------------------------------------------------------------------------------- 
 * FUNCTION: return name of this->Animal
 * RETURNS - string
 ******************************************************************************/
  string getName() const;

/*******************************************************************************
 * Get Age of calling Animal
 ------------------------------------------------------------------------------- 
 * FUNCTION: returns age of this->Animal
 * RETURNS - unsigned int
 ******************************************************************************/
  unsigned int getAge() const;

  // Setters
/*******************************************************************************
 * Set Name of calling Animal
 ------------------------------------------------------------------------------- 
 * FUNCTION:
 * @param name - name that will get assigned to member name
 * RETURNS - void
 ******************************************************************************/
  void setName(const string &name);

/*******************************************************************************
 * Set Age of calling Animal
 ------------------------------------------------------------------------------- 
 * FUNCTION:
 * @param age - age thats will get assigned to member age
 * RETURNS - void
 ******************************************************************************/
  void setAge(const unsigned int &age);

/*******************************************************************************
 * Print Animal Attributes
 ------------------------------------------------------------------------------- 
 * FUNCTION: This method prints out its own private attributes
 * RETURNS - void
 ******************************************************************************/
  void print() const;
 private:
  string m_Name;
  unsigned int m_Age;
};

#endif // ANIMAL_H_

#ifndef PIG_H_
#define PIG_H_
#include "Animal.h"
#include <map>

enum TailType { kStraight = 0, kCorkscrew, kCurlUp, kCurlRight, kCurlLeft };

class Pig : public Animal {
 public:
/*******************************************************************************
 * Pig Constructor
 ------------------------------------------------------------------------------- 
 * CONSTRUCTOR: constructs Pig
 ******************************************************************************/
  Pig();

/*******************************************************************************
 * Pig Constructor
 ------------------------------------------------------------------------------- 
 * CONSTRUCTOR: Constructs Pig with all needed parameters
 * @param name - name of this->Pig
 * @param age - age of this->Pig
 * @param tailType - tail type of this->Pig
 ******************************************************************************/
  Pig(const string &name, const unsigned int &age, const TailType &tailType);
  
/*******************************************************************************
 * Pig Destructor
 ------------------------------------------------------------------------------- 
 * DESTRUCTOR: Destructs Pig
 ******************************************************************************/
  ~Pig() {}

  // Setters
/*******************************************************************************
 * Set Tail Type
 ------------------------------------------------------------------------------- 
 * FUNCTION: Sets the tail type for this->Pig
 * @param tailType - Tail Type of this->Pig
 * RETURNS - void
 ******************************************************************************/
  void setTailType(const TailType &tailType);

  // Getters
/*******************************************************************************
 * Get Tail Type
 ------------------------------------------------------------------------------- 
 * FUNCTION: returns TailType of this->Pig
 * RETURNS - TailType
 ******************************************************************************/
  TailType getTailType() const;

  // Methods
/*******************************************************************************
 * Print Attributes
 ------------------------------------------------------------------------------- 
 * FUNCTION: Displays this->Pig attributes
 * RETURNS - void
 ******************************************************************************/
  void print() const;
 private:
  TailType m_TailType;
  map<TailType, string> TailKeyPair;
};

#endif // PIG_H_

#ifndef SHEEP_H_
#define SHEEP_H_
#include "Animal.h"
#include <map>

enum WoolType { kLong = 0, kMedium, kFine, kCarpet };
enum WoolColor { kWhite = 0, kBlack };

class Sheep : public Animal {
 public:
/*******************************************************************************
 * Sheep Constructor
 ------------------------------------------------------------------------------- 
 * CONSTRUCTOR: Constructs Sheep
 ******************************************************************************/
  Sheep();

/*******************************************************************************
 * Sheep Constructor
 ------------------------------------------------------------------------------- 
 * CONSTRUCTOR: Constructs Sheep with its attributes
 * @param name - name of this->Sheep
 * @param age - age of this->Sheep
 * @param woolType - Wool Type of this->Sheep
 * @param woolColor - Wool Color of this->Sheep
 ******************************************************************************/
  Sheep(const string &name, const unsigned int &age,
        const WoolType &woolType, const WoolColor &woolColor);

/*******************************************************************************
 * Sheep Destructor
 ------------------------------------------------------------------------------- 
 * DESTRUCTOR: Destructs Sheep
 ******************************************************************************/
  ~Sheep() {}

  // Getters
/*******************************************************************************
 * Get Wool Type
 ------------------------------------------------------------------------------- 
 * FUNCTION: returns m_WoolType of this->Sheep
 * RETURNS - WoolType
 ******************************************************************************/
  WoolType getWoolType() const;

/*******************************************************************************
 * Get Wool Color
 ------------------------------------------------------------------------------- 
 * FUNCTION: returns m_WoolColor of this->Sheep
 * RETURNS - WoolColor
 ******************************************************************************/
  WoolColor getWoolColor() const;

  // Setters
/*******************************************************************************
 * Set Wool Type
 ------------------------------------------------------------------------------- 
 * FUNCTION: Sets Wool Type of this->Sheep
 * @param woolType - Wool Type of this->Sheep
 * RETURNS - void
 ******************************************************************************/
  void setWoolType(const WoolType &woolType);

/*******************************************************************************
 * Set Wool Color
 ------------------------------------------------------------------------------- 
 * FUNCTION: Sets Wool Color of this->Sheep
 * @param woolColor - Wool Color of this->Sheep
 * RETURNS - void
 ******************************************************************************/
  void setWoolColor(const WoolColor &woolColor);
  
  // Methods
/*******************************************************************************
 * Print Attributes
 ------------------------------------------------------------------------------- 
 * FUNCTION: Prints Attributes of this->Sheep
 * RETURNS - void
 ******************************************************************************/
  void print() const;
 private:
  WoolType m_WoolType;
  WoolColor m_WoolColor;
  map<WoolType, string> WoolKeyPair;
  map<WoolColor, string> WoolColorKeyPair;
};

#endif // SHEEP_H_

#ifndef LIVESTOCK_H_
#define LIVESTOCK_H_
#include "Sheep.h"
#include "Pig.h"

class Livestock {
/*******************************************************************************
 * Friend Function Initialize Pigs
 ------------------------------------------------------------------------------- 
 * FUNCTION: This Function reads from a file (Pig.txt) and plugs in values
 * into a vector that holds sheep, Livestock is responsible for having that
 * vector. Attributes are validated using a function named attributesValidated
 * and Logs any Errors with Initialization. With the conversion of a string
 * to an enum type, a map is used to have the string be the key and enum be the
 * pair and once validated we match one and one.
 * @param livestock - livestock to hold the Animals using vector
 * RETURNS - void
 ******************************************************************************/
 friend void initPigs(Livestock &livestock);

/*******************************************************************************
 * Friend Function Initialize Sheeps
 ------------------------------------------------------------------------------- 
 * FUNCTION: This Function reads from a file (Sheep.txt) and plugs in values
 * into a vector that holds sheep, Livestock is responsible for having that
 * vector. Attributes are validated using a function named attributesValidated
 * and Logs any Errors with Initialization. With the conversion of a string
 * to an enum type, a map is used to have the string be the key and enum be the
 * pair and once validated we match one and one.
 * @param livestock - livestock to hold the Animals using vector
 * RETURNS - void
 ******************************************************************************/
 friend void initSheeps(Livestock &livestock);

/*******************************************************************************
 * Friend Function Change Animal Age
 ------------------------------------------------------------------------------- 
 * FUNCTION: Determines what Animal user wants to choose from, once decided
 * uses iteration to print all specified Animals, lastly user chooses what Animal
 * to change age
 * @param livestock
 * RETURNS - void
 ******************************************************************************/
 friend void changeAnimalAge(Livestock &livestock);

 public:
/*******************************************************************************
 * Livestock Constructor
 ------------------------------------------------------------------------------- 
 * CONSTRUCTOR: Constructs Livestock
 ******************************************************************************/
  Livestock() {}

/*******************************************************************************
 * Livestock Destructor
 ------------------------------------------------------------------------------- 
 * DESTRUCTOR: Destructs Livestock
 ******************************************************************************/
  ~Livestock() {}

/*******************************************************************************
 * Clear All Livestock
 ------------------------------------------------------------------------------- 
 * FUNCTION: clears both Sheep and Pig vectors
 * RETURNS - void
 ******************************************************************************/
  void clear();

/*******************************************************************************
 * Clear Sheep Livestock
 ------------------------------------------------------------------------------- 
 * FUNCTION: Clears Sheep Vector
 * RETURNS - void
 ******************************************************************************/
  void clearSheep();

/*******************************************************************************
 * Clear Pig Livestock
 ------------------------------------------------------------------------------- 
 * FUNCTION: Clears Pig Vector
 * RETURNS - void
 ******************************************************************************/
  void clearPig();

/*******************************************************************************
 * Prints Entire Livestock
 ------------------------------------------------------------------------------- 
 * FUNCTION: Prints both headings and delegates printing of attributes to
 * respective Animals
 * RETURNS - void
 ******************************************************************************/
  void print() const;
 private:
  vector<Pig> m_PigLivestock;
  vector<Sheep> m_SheepLivestock;
};

#endif // LIVESTOCK_H_

#include "../../include/Animal.h"

// Construtors
/*******************************************************************************
 * Animal Constructor
 ------------------------------------------------------------------------------- 
 * CONSTRUCTOR: constructs Animal with no PARAM
 ******************************************************************************/
Animal::Animal() : Animal("", 0) {}

/*******************************************************************************
 * Animal Constructor
 ------------------------------------------------------------------------------- 
 * CONSTRUCTOR: constructs Animal with PARAMS
 * @param name - name of this->Animal
 * @param age - age of this->Animal
 ******************************************************************************/
Animal::Animal(const string &name, const unsigned int &age) 
    : m_Name(name), m_Age(age) {}

// Getters
/*******************************************************************************
 * Get Name of calling Animal
 ------------------------------------------------------------------------------- 
 * FUNCTION: return name of this->Animal
 * RETURNS - string
 ******************************************************************************/
string Animal::getName() const { return m_Name; }

/*******************************************************************************
 * Get Age of calling Animal
 ------------------------------------------------------------------------------- 
 * FUNCTION: returns age of this->Animal
 * RETURNS - unsigned int
 ******************************************************************************/
unsigned int Animal::getAge() const { return m_Age; }
// Setters
/*******************************************************************************
 * Set Name of calling Animal
 ------------------------------------------------------------------------------- 
 * FUNCTION:
 * @param name - name that will get assigned to member name
 * RETURNS - void
 ******************************************************************************/
void Animal::setName(const string &name) { m_Name = name; }

/*******************************************************************************
 * Set Age of calling Animal
 ------------------------------------------------------------------------------- 
 * FUNCTION:
 * @param age - age thats will get assigned to member age
 * RETURNS - void
 ******************************************************************************/
void Animal::setAge(const unsigned int &age) { m_Age = age; }
// Methods
/*******************************************************************************
 * Print Animal Attributes
 ------------------------------------------------------------------------------- 
 * FUNCTION: This method prints out its own private attributes
 * RETURNS - void
 ******************************************************************************/
void Animal::print() const {
  cout << setw(12) << m_Name << setw(4) << m_Age;
}

#include "../../include/Sheep.h"

// Constructors
/*******************************************************************************
 * Sheep Constructor
 ------------------------------------------------------------------------------- 
 * FUNCTION: Constructs Sheep
 ******************************************************************************/
Sheep::Sheep() : Sheep("", 0, kLong, kWhite) {}

/*******************************************************************************
 * Sheep Constructor
 ------------------------------------------------------------------------------- 
 * FUNCTION: Constructs Sheep with its attributes
 * @param name - name of this->Sheep
 * @param age - age of this->Sheep
 * @param woolType - Wool Type of this->Sheep
 * @param woolColor - Wool Color of this->Sheep
 ******************************************************************************/
Sheep::Sheep(const string &name, const unsigned int &age,
             const WoolType &woolType, const WoolColor &woolColor)
    : Animal::Animal(name, age), m_WoolType(woolType), m_WoolColor(woolColor) {
  // Initializes Map with key being Enum -> string
  WoolKeyPair[kLong] = ("Long");
  WoolKeyPair[kMedium] = ("Medium");
  WoolKeyPair[kFine] = ("Fine");
  WoolKeyPair[kCarpet] = ("Carpet");
  WoolColorKeyPair[kWhite] = ("White");
  WoolColorKeyPair[kBlack] = ("Black");
}
// Getters
/*******************************************************************************
 * Get Wool Type
 ------------------------------------------------------------------------------- 
 * FUNCTION: returns m_WoolType of this->Sheep
 * RETURNS - WoolType
 ******************************************************************************/
WoolType Sheep::getWoolType() const { return m_WoolType; }

/*******************************************************************************
 * Get Wool Color
 ------------------------------------------------------------------------------- 
 * FUNCTION: returns m_WoolColor of this->Sheep
 * RETURNS - WoolColor
 ******************************************************************************/
WoolColor Sheep::getWoolColor() const { return m_WoolColor; }
// Setters
/*******************************************************************************
 * Set Wool Type
 ------------------------------------------------------------------------------- 
 * FUNCTION: Sets Wool Type of this->Sheep
 * @param woolType - Wool Type of this->Sheep
 ******************************************************************************/
void Sheep::setWoolType(const WoolType &woolType) { m_WoolType = woolType; }

/*******************************************************************************
 * Set Wool Color
 ------------------------------------------------------------------------------- 
 * FUNCTION: Sets Wool Color of this->Sheep
 * @param woolColor - Wool Color of this->Sheep
 * RETURNS - void
 ******************************************************************************/
void Sheep::setWoolColor(const WoolColor &woolColor) { m_WoolColor = woolColor; }
// Methods
/*******************************************************************************
 * Print Attributes
 ------------------------------------------------------------------------------- 
 * FUNCTION: Prints Attributes of this->Sheep
 * RETURNS - void
 ******************************************************************************/
void Sheep::print() const {
  Animal::print();
  // Using Map index with type enum to shoot respective string out
  cout << setw(10) << WoolKeyPair.at(m_WoolType) << setw(5) << WoolColorKeyPair.at(m_WoolColor);
}

#include "../../include/Pig.h"

// Constructors
/*******************************************************************************
 * Pig Constructor
 ------------------------------------------------------------------------------- 
 * CONSTRUCTOR: constructs Pig
 ******************************************************************************/
Pig::Pig() : Pig("", 0, kStraight) {}

/*******************************************************************************
 * Pig Constructor
 ------------------------------------------------------------------------------- 
 * CONSTRUCTOR: Constructs Pig with all needed parameters
 * @param name - name of this->Pig
 * @param age - age of this->Pig
 * @param tailType - tail type of this->Pig
 ******************************************************************************/
Pig::Pig(const string &name, const unsigned int &age, const TailType &tailType)
    : Animal(name, age), m_TailType(tailType) {
  // Initializes Map with enum -> string
  TailKeyPair[kStraight] = ("Straight");
  TailKeyPair[kCorkscrew] = ("Corkscrew");
  TailKeyPair[kCurlUp] = ("Curl Up");
  TailKeyPair[kCurlRight] = ("Curl Right");
  TailKeyPair[kCurlLeft] = ("Curl Left");
}
// Setters
/*******************************************************************************
 * Set Tail Type
 ------------------------------------------------------------------------------- 
 * FUNCTION: Sets the tail type for this->Pig
 * @param tailType - Tail Type of this->Pig
 * RETURNS - void
 ******************************************************************************/
void Pig::setTailType(const TailType &tailType) { m_TailType = tailType; }
// Getters
/*******************************************************************************
 * Get Tail Type
 ------------------------------------------------------------------------------- 
 * FUNCTION: returns TailType of this->Pig
 * RETURNS - TailType
 ******************************************************************************/
TailType Pig::getTailType() const { return m_TailType; }

/*******************************************************************************
 * Print Attributes
 ------------------------------------------------------------------------------- 
 * FUNCTION: Displays this->Pig attributes
 * RETURNS - void
 ******************************************************************************/
void Pig::print() const {
  Animal::print();
  // Uses Map index with enum to access pair
  cout << setw(10) << TailKeyPair.at(m_TailType);
}

#include "../../include/Livestock.h"

/*******************************************************************************
 * Prints Entire Livestock
 ------------------------------------------------------------------------------- 
 * FUNCTION: Prints both headings and delegates printing of attributes to
 * respective Animals
 * RETURNS - void
 ******************************************************************************/

void Livestock::print() const {
  cout << left;
  cout << "\nTHE SHEEP:\n\n";
  cout << setw(11) << "NAME" << setw(5) << "AGE";
  cout << setw(10) << "WOOLTYPE" << setw(5) << "COLOR\n";
  cout << setw(11) << "---------" << setw(5) << "---";
  cout << setw(10) << "--------" << setw(5) << "-----\n";
  // PROCCESSING: Prints individual Sheep Attributes already formated
  for (int i = 0; i < m_SheepLivestock.size(); ++i) {
    m_SheepLivestock[i].print();
    cout << "\n";
  }

  cout << "\nTHE PIG(S):\n\n";
  cout << setw(11) << "NAME" << setw(5) << "AGE";
  cout << setw(9) << "TAILTYPE\n";
  cout << setw(11) << "---------" << setw(5) << "---";
  cout << setw(9) << "----------\n"; 
  // PROCCESSING: Prints individual Pig Attributes already formated
  for (int i = 0; i < m_PigLivestock.size(); ++i) {
    m_PigLivestock.at(i).print();
    cout << "\n";
  }
  cout << right;
}

/*******************************************************************************
 * Clear All Livestock
 ------------------------------------------------------------------------------- 
 * FUNCTION: clears both Sheep and Pig vectors
 * RETURNS - void
 ******************************************************************************/
void Livestock::clear() { 
  m_SheepLivestock.clear();
  m_PigLivestock.clear();
}

/*******************************************************************************
 * Clear Sheep Livestock
 ------------------------------------------------------------------------------- 
 * FUNCTION: Clears Sheep Vector
 * RETURNS - void
 ******************************************************************************/
void Livestock::clearSheep() { m_SheepLivestock.clear(); }

/*******************************************************************************
 * Clear Pig Livestock
 ------------------------------------------------------------------------------- 
 * FUNCTION: Clears Pig Vector
 * RETURNS - void
 ******************************************************************************/
void Livestock::clearPig() { m_PigLivestock.clear(); }
