#include "../include/DVDnode.h"
#include "../include/MovieList.h"
#include "../include/StackList.h"
#include <iostream>
#include<unistd.h>

/*******************************************************************************
 * AUTHOR      : Carlos Aguilera
 * STUDENT ID  : 1152562
 * LAB #       : 
 * CLASS       : CS1B
 * SECTION     : M-W
 * DUE DATE    : 
 ******************************************************************************/

/******************************************************************************
 * Title:
 * ----------------------------------------------------------------------------
 * PROGRAM:
 * 
 * ----------------------------------------------------------------------------
 ******************************************************************************/

/*******************************************************************************
 * 
 ------------------------------------------------------------------------------- 
 * FUNCTION:
 * @param
 * RETURNS - 
 ******************************************************************************/

void heading(std::ostream &os);

void delay(const std::string &inFileInput, const std::string &oFileInput) {
  for (int i = 3; i > 0; --i) {
    system("clear");
    heading(std::cout);
    std::cout << "INPUT FILE: " << inFileInput << '\n';
    std::cout << "OUTPUT FILE: " << oFileInput << '\n';
    std::cout << "READING: System Complete in -> " << i << '\n';
    usleep(1000000);
  }
}

int main() {
  heading(std::cout);
  MovieList list;
  std::string inFileInput;
  std::string oFileInput;

  std::cout << "INPUT FILE: ";
  std::getline(std::cin, inFileInput);
  std::cout << "OUTPUT FILE: ";
  std::getline(std::cin, oFileInput);
  if (inFileInput == "default.txt") {
    list.createList(inFileInput);
    list.outputList(oFileInput);
  } else {
    std::cout << "ERROR: [Input file not found]\n";
  }
  return 0;
}