/*****************************************************************************
 * AUTHOR      : Carlos Aguilera
 * STUDENT ID  : 1152562
 * LAB #3      : Searching Linked Lists
 * CLASS       : CS1B
 * SECTION     : M-W
 * DUE DATE    : 04.05.22
 ****************************************************************************/

#include "../include/header.h"

/****************************************************************************
 * Title: Searching Linked Lists
 * --------------------------------------------------------------------------
 * PROGRAM:
 *    This Program pulls data from an input file that is specified or it will
 * resort to a default, it is using linked lists to collect that data and
 * store it in the heap. The functionality of the program should be as follows
 * user starts application and selects file to read from then that file if 
 * valid gets collected as a linked list. Then you can obtain that data and 
 * search through it using sequential search.
 * --------------------------------------------------------------------------
 * Data Table
 * ----------
 * std::string outputFile IN - used to create or open output file
 * DVD* head IN, CALC & OUT - creates pointer that points to DVD struct
 * MenuOptions option IN & CALC - enum that holds what option they choose
 * std::fstream oFile OUT - used for outputting to a file
 ***************************************************************************/

int main() {
   heading();
   std::string outputFile;
   DVD *head = NULL;
   head = readInput();//reads input file
   subString(head);

   MenuOptions option;
   std::fstream oFile;
   std::cout << "Which output file would you like to use(type d for default file)? ";
   std::getline(std::cin, outputFile);
   if (outputFile == "d")
      outputFile = "output.txt";
   oFile.open(outputFile, std::ios::out);//opens file to write

   do {
      dispMenu();//displays menu
      option = switchValidation();//validates switch choice before choosing 
      switchOption(option, head, oFile);
   } while(option != Exit);

   oFile.close();
   deallocate(head);
   head = NULL;
   return 0;
}