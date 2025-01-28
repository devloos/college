#include "../include/DVDnode.h"
#include "../include/MovieList.h"
#include "../include/StackList.h"
#include <iostream>
#include<unistd.h>
using namespace std;

/*******************************************************************************
 * AUTHOR      : Carlos Aguilera
 * STUDENT ID  : 1152562
 * LAB #5      : Movie List OOP
 * CLASS       : CS1B
 * SECTION     : M-W
 * DUE DATE    : 05.19.22
 ******************************************************************************/
/******************************************************************************
 * Movie List 2.0
 * ----------------------------------------------------------------------------
 * PROGRAM: This program is very simple, but integrates powerful OOP behind
 * the scenes. Takes to inputs inFileInput and oFileInput, uses inFile to 
 * read from user specified source if exsits and oFile to output. Program
 * reads data from inFile and formats it to be placed in oFile. Uses linked
 * list stack implementation.
 * ----------------------------------------------------------------------------
 ******************************************************************************/

/*******************************************************************************
 * Print Class Heading
 ------------------------------------------------------------------------------- 
 * FUNCTION: Prints out class heading
 * @param os - ostream for what output source is wanted
 * RETURNS - void
 ******************************************************************************/
void heading(ostream &os);

int main() {
  // PROCCESSING: passing console out
  heading(cout);
  MovieList   list;        
  string inFileInput; 
  string oFileInput;  

  cout << "INPUT FILE: ";
  getline(cin, inFileInput);
  cout << "OUTPUT FILE: ";
  getline(cin, oFileInput);
  if (inFileInput == "default.txt") {
    list.createList(inFileInput);
    list.outputList(oFileInput);
  } else {
    cout << "ERROR: [Input file not found]\n";
  }
  return 0;
}

#ifndef DVDNODE_H_
#define DVDNODE_H_
#include <string>
using namespace std;

struct DVDNode { 
  DVDNode() : next(nullptr) {}

  string title;           // store movie's title 
  string leadingActor;    // store leading actor/actress 
  string supportingActor; // store supporting actor/actress 
  string genre;           // store movie’s genre 
  string alternateGenre;  // store movie’s alternate genre 
  int         year;            // store movie’s release year 
  int         rating;          // store movie’s rating 
  string synopsis;        // store movie’s synopsis 
  DVDNode     *next;           // linked list next pointer 
}; 

#endif // DVDNODE_H_

#ifndef STACKLIST_H_
#define STACKLIST_H_
#include "DVDnode.h"
using namespace std;

class StackList {             
 public: 
/*******************************************************************************
 * StackList Constructor
 ------------------------------------------------------------------------------- 
 * CONSTRUCTOR: Constructs StackList
 ******************************************************************************/
  StackList () : head(nullptr), stackCount(0) {}

/*******************************************************************************
 * StackList Destructor
 ------------------------------------------------------------------------------- 
 * DESTRUCTOR: Destructs StackList
 ******************************************************************************/
  ~StackList () {}

/*******************************************************************************
 * Push New DVD on the heap
 ------------------------------------------------------------------------------- 
 * FUNCTION: Allocates heap memory and links it to exsiting or creates linked
 * list
 * @param newDVD - type DVDNode to push on the heap
 * RETURNS - void
 ******************************************************************************/
  void Push(const DVDNode &newDVD);  

/*******************************************************************************
 * Pop Front DVD
 ------------------------------------------------------------------------------- 
 * FUNCTION: Pops DVD off the front and deallocates memory before that it creates
 * a copy and returns it
 * RETURNS - DVDNode
 ******************************************************************************/
  DVDNode Pop();              

/*******************************************************************************
 * Check if Linked List is Empty
 ------------------------------------------------------------------------------- 
 * FUNCTION: checks if head is null and returns bool
 * RETURNS - bool
 ******************************************************************************/
  bool IsEmpty() const;       

/*******************************************************************************
 * Peek Front of list
 ------------------------------------------------------------------------------- 
 * FUNCTION: returns copy of *head
 * RETURNS - DVDNode
 ******************************************************************************/
  DVDNode Peek() const;       

/*******************************************************************************
 * Size of Linked List
 ------------------------------------------------------------------------------- 
 * FUNCTION: Returns stackCount
 * RETURNS - int
 ******************************************************************************/
  int Size() const;           
 protected: 
  DVDNode *head;              
  int stackCount;             
};

#endif // STACKLIST_H_

#include "../../include/StackList.h"
#include <iostream>

/*******************************************************************************
 * Push New DVD on the heap
 ------------------------------------------------------------------------------- 
 * FUNCTION: Allocates heap memory and links it to exsiting or creates linked
 * list
 * @param newDVD - type DVDNode to push on the heap
 * RETURNS - void
 ******************************************************************************/
void StackList::Push(const DVDNode &newDVD) {
  DVDNode* node = new DVDNode;
  // PROCCESSING: Linking new node
  if (node != nullptr) {
    *node = newDVD;
    node->next = head;
    head = node;
    ++stackCount;
    return;
  }
  cout << "\nERROR: [Allocation of Memory]\n";
}

/*******************************************************************************
 * Pop Front DVD
 ------------------------------------------------------------------------------- 
 * FUNCTION: Pops DVD off the front and deallocates memory before that it creates
 * a copy and returns it
 * RETURNS - DVDNode
 ******************************************************************************/
DVDNode StackList::Pop() {
  // PROCCESSING: If head null list is empty
  if (head == nullptr)
    return DVDNode();
  DVDNode temp = *head;
  DVDNode* node = head;
  head = node->next;
  delete node;
  --stackCount;
  return temp;
}

/*******************************************************************************
 * Check if Linked List is Empty
 ------------------------------------------------------------------------------- 
 * FUNCTION: checks if head is null and returns bool
 * RETURNS - bool
 ******************************************************************************/
bool StackList::IsEmpty() const { return (head == nullptr); }

/*******************************************************************************
 * Peek Front of list
 ------------------------------------------------------------------------------- 
 * FUNCTION: returns copy of *head
 * RETURNS - DVDNode
 ******************************************************************************/
DVDNode StackList::Peek() const { return *head; }

/*******************************************************************************
 * Size of Linked List
 ------------------------------------------------------------------------------- 
 * FUNCTION: Returns stackCount
 * RETURNS - int
 ******************************************************************************/
int StackList::Size() const { return stackCount; }

#ifndef MOVIELIST_H_
#define MOVIELIST_H_
#include "StackList.h"
#include <fstream>
using namespace std;

void heading();

class MovieList : public StackList {
 private:
/*******************************************************************************
 * Wrap Synopsis
 ------------------------------------------------------------------------------- 
 * FUNCTION: Formats synopsis to be wrapped every 75 character, this is done
 * by creating a r value string from a word in the synopsis and if current
 * line is going to be greater than 75 with word added then we \n and clear line
 * @param plot - raw synopsis
 * RETURNS - string
 ******************************************************************************/
  string wordWrap(string plot);
  
/*******************************************************************************
 * Read DVDNode Attributes from file
 ------------------------------------------------------------------------------- 
 * FUNCTION: Helper function for reading data from file
 * @param inFile - File stream used to read from
 * @param node - node that program stores read data in
 * RETURNS - void
 ******************************************************************************/
  void FileInput(fstream &inFile, DVDNode &node);
  
/*******************************************************************************
 * Format Data Recieved from File
 ------------------------------------------------------------------------------- 
 * FUNCTION: Formats data on how program needs to use it
 * @param node - type DVDNode that holds data to be formatted
 * RETURNS - void
 ******************************************************************************/
  void FileFormat(DVDNode &node);
 public:
/*******************************************************************************
 * MovieList Constructor
 ------------------------------------------------------------------------------- 
 * CONSTRUCTOR: Constructs MovieList
 ******************************************************************************/
  MovieList() : StackList() {}

/*******************************************************************************
 * MovieList Destructor
 ------------------------------------------------------------------------------- 
 * DESTRUCTOR: Handles the deallocation of linked list
 ******************************************************************************/
  ~MovieList();

/*******************************************************************************
 * Create Linked List
 ------------------------------------------------------------------------------- 
 * FUNCTION: Delegates and controls the creation of each node on the heap,
 * uses helper functions FileInput(), FileFormat(), Push()
 * @param inFileName - name of file user wants to use as input file
 * RETURNS - void
 ******************************************************************************/
  void createList(const string &inFileName);

/*******************************************************************************
 * Output List to File
 ------------------------------------------------------------------------------- 
 * FUNCTION: Output entire formatted linked list to a user specified output file
 * @param oFileName - output file that user specified
 * RETURNS - void
 ******************************************************************************/
  void outputList(const string &oFileName);
};

#endif // MOVIELIST_H_

#include "../../include/MovieList.h"
#include <fstream>
#include <iostream>
#include <iomanip>

void heading(ostream &os);

/*******************************************************************************
 * Read DVDNode Attributes from file
 ------------------------------------------------------------------------------- 
 * FUNCTION: Helper function for reading data from file
 * @param inFile - File stream used to read from
 * @param node - node that program stores read data in
 * RETURNS - void
 ******************************************************************************/
void MovieList::FileInput(fstream &inFile, DVDNode &node) {
  // PROCCESSING: Reading data
  getline(inFile, node.title);
  getline(inFile, node.leadingActor);
  getline(inFile, node.supportingActor);
  getline(inFile, node.genre);
  getline(inFile, node.alternateGenre);
  inFile >> node.year;
  inFile.ignore(1000, '\n');
  inFile >> node.rating;
  inFile.ignore(1000, '\n');
  getline(inFile, node.synopsis);
  inFile.ignore(1000, '\n');
}

/*******************************************************************************
 * Format Data Recieved from File
 ------------------------------------------------------------------------------- 
 * FUNCTION: Formats data on how program needs to use it
 * @param node - type DVDNode that holds data to be formatted
 * RETURNS - void
 ******************************************************************************/
void MovieList::FileFormat(DVDNode &node) {
  // PROCCESSING: Parsing data
  node.title = node.title.substr(0, node.title.size() - 1);
  node.leadingActor = 
      node.leadingActor.substr(0, node.leadingActor.size() - 1);

  node.supportingActor = 
      node.supportingActor.substr(0, node.supportingActor.size() - 1);

  node.genre = node.genre.substr(0, node.genre.size() - 1);
  node.alternateGenre =
      node.alternateGenre.substr(0, node.alternateGenre.size() - 1);

  node.synopsis = node.synopsis.substr(0, node.synopsis.size() - 1);
  node.synopsis += " ";
}

/*******************************************************************************
 * MovieList Destructor
 ------------------------------------------------------------------------------- 
 * DESTRUCTOR: Handles the deallocation of linked list
 ******************************************************************************/
MovieList::~MovieList() {
  // PROCCESSING: Reusing deallocation method
  for (int i = 0; i < stackCount; ++i)
    this->Pop();
}

/*******************************************************************************
 * Wrap Synopsis
 ------------------------------------------------------------------------------- 
 * FUNCTION: Formats synopsis to be wrapped every 75 character, this is done
 * by creating a r value string from a word in the synopsis and if current
 * line is going to be greater than 75 with word added then we \n and clear line
 * @param plot - raw synopsis
 * RETURNS - string
 ******************************************************************************/
string MovieList::wordWrap(string plot) {
  const int Max_Line_Length = 75;
  string line;
  string FormattedPlot;
  // PROCCESSING: iterate until plot is cleared
  do {
    // PROCCESSING: Creating temp string and finding size with respect on adding word
    if (string(line + plot.substr(0, plot.find(' '))).size() < Max_Line_Length) {
      // PROCCESSING: Find first space from one word to another
      line += plot.substr(0, plot.find(' ') + 1);
      plot = plot.substr(plot.find(' ') + 1);
    } else {
      FormattedPlot += line + '\n';
      line.clear();
    }
  } while (!(plot.empty()));

  FormattedPlot += line;
  return FormattedPlot;
}

/*******************************************************************************
 * Create Linked List
 ------------------------------------------------------------------------------- 
 * FUNCTION: Delegates and controls the creation of each node on the heap,
 * uses helper functions FileInput(), FileFormat(), Push()
 * @param inFileName - name of file user wants to use as input file
 * RETURNS - void
 ******************************************************************************/
void MovieList::createList(const string &inFileInput) {
  DVDNode node;
  fstream inFile(inFileInput, ios::in);
  if (inFile.is_open()) {
    while (!inFile.eof()) {
      // PROCCESSING: READING DATA FROM FILE
      this->FileInput(inFile, node);
      // PROCCESSING: FORMATTING STRING
      this->FileFormat(node);
      // PROCCESSING: Pushing node on the Linked List
      this->Push(node);
    }
  } else {
    cerr << "\nERROR: [File " << inFileInput << " failed to open]\n"; 
  }
  inFile.close();
}

/*******************************************************************************
 * Output List to File
 ------------------------------------------------------------------------------- 
 * FUNCTION: Output entire formatted linked list to a user specified output file
 * @param oFileName - output file that user specified
 * RETURNS - void
 ******************************************************************************/
void MovieList::outputList(const string &oFileInput) {
  DVDNode* node = head;
  fstream oFile(oFileInput, ios::out);
  // PROCCESSING: Printing class header into output file
  heading(oFile);
  if (oFile.is_open()) {
    // Using iteration since we have size of list
    for (int i = 0; i < stackCount; ++i) {
      oFile << left;
      oFile << "***************************************************************************\n";
      oFile << "MOVIE #: " << setw(9) << i+1 << "Title: " << node->title << "\n";
      oFile << "---------------------------------------------------------------------------\n";
      oFile << "Year: " << setw(12) << node->year << "Rating: " << node->rating << '\n';
      oFile << "---------------------------------------------------------------------------\n";
      oFile << "Leading Actor:    " << setw(22) << node->leadingActor << "Genre 1: " << node->genre << "\n";
      oFile << "Supporting Actor: " << setw(22) << node->supportingActor << "Genre 2: " << node->alternateGenre << "\n";
      oFile << "---------------------------------------------------------------------------\n";
      oFile << "PLOT:\n";
      oFile << this->wordWrap(node->synopsis) << '\n';
      oFile << "***************************************************************************\n";
      oFile << right;
      node = node->next;
    }
  } else {
    cerr << "\nERROR: [File " << oFileInput << " failed to open]\n"; 
  }
  oFile.close();
}

#include <iostream>
#include <iomanip>

/*******************************************************************************
 * Print Class Heading
 ------------------------------------------------------------------------------- 
 * FUNCTION: Prints out class heading
 * @param os - ostream for what output source is wanted
 * RETURNS - void
 ******************************************************************************/
void heading(ostream &os) {

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
	const int LAB_NUM       = 5;
	const char LAB_NAME[]   = "Movie List OOP";

	os << left;
	os << "****************************************************\n";
	os << "*   PROGRAMMED BY : " << PROGRAMMER << endl;
	os << "*   " << setw(14) <<"CLASS" << ": " << CLASS << endl;
	os << "*   " << setw(14) <<"SECTION" << ": " << SECTION << endl;
	os << "*   LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME << endl;
	os << "****************************************************\n\n";
	os << right;
}