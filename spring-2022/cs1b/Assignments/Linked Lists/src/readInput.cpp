#include "../include/header.h"
/****************************************************************************
 * Title: readInput
 * --------------------------------------------------------------------------
 * FUNCTION:
 *    This function reads from the input file specified, how it goes about it
 * is as so creates head ptr to DVD and creates node ptr to DVD but allocates
 * a new DVD on the heap. What happens is node = new DVD and head = NULL
 * and first iteration of the while loop the next node equals head which is 
 * NULL what that is doing is setting the node to be NULL and last in the 
 * linked list. head then has the address of orignal node and node = new DVD
 * --------------------------------------------------------------------------
 * Data Table
 * ----------
 * DVD* head = NULL IN & CALC - used in linked list
 * DVD* node = new DVD IN & CALC - used in linked list
 * std::fstream inFile IN - used to grab movie data
 * std::string temp IN - used to grab \n 
 * std::string inputFile IN & CALC - used to identify input file
 ***************************************************************************/


DVD *readInput() {
   DVD *head = NULL;
   DVD *node = new DVD;
   std::fstream inFile;
   std::string temp;
   std::string inputFile;
   do {
      std::cout << "Which input file would you like to use(type d for default file)? ";
      std::getline(std::cin, inputFile);
      if (inputFile != "d")
         inputFile = "../build/" + inputFile;//adding folder structure to file
      else
         inputFile = "../build/AS5-BigInFile.txt";//default

      inFile.open(inputFile, std::ios::in);

      if (inFile.is_open()) {
         while (!inFile.eof()) {//while not end of file
            std::getline(inFile, node -> title);
            std::getline(inFile, node -> leadActor);
            std::getline(inFile, node -> subActor);
            std::getline(inFile, node -> genre);
            std::getline(inFile, node -> altGenre);
            inFile >> node -> year >> node -> rating;
            inFile.ignore(10000, '\n');
            std::getline(inFile, node -> synopsis);
            std::getline(inFile, temp);
            
            node->nextNode = head;
            head = node;
            node = new DVD;
         }
         inFile.close();
      }else
         std::cout << "Enter Valid File name\n";// if no input file exist
   } while (head == NULL);//run while havent been initialized
   delete node;
   return head;
}