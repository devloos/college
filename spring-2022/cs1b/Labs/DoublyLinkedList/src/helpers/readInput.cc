/*******************************************************************************
 * readInput
 ------------------------------------------------------------------------------- 
 * FUNCTION: reads input from file from single node 
 * being passed in
 * @param node ptr to node being passed in
 * @param inFile passed by ref to access reading file
 * RETURNS - void
 ******************************************************************************/
#include "../../include/header.h"

void readInput(MovieRec* &node, std::fstream &inFile) {
  std::getline(inFile, node->movieTitle);
  // PROCCESSING - if the last character of the string == ' ' then substr
  if (node->movieTitle[node->movieTitle.size() - 1] == ' ') {
    node->movieTitle = node->movieTitle.substr(0, node->movieTitle.find_last_of(' '));
  }
  std::getline(inFile, node->genre);
  // PROCCESSING - if the last character of the string == ' ' then substr
  if (node->genre[node->genre.size() - 1] == ' ') {
    node->genre = node->genre.substr(0, node->genre.find_last_of(' '));
  }
  inFile >> node->releaseYear;
  inFile.ignore(1000, '\n');
}