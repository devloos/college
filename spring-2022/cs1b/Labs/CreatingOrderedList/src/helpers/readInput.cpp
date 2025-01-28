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

void readInput(Node* &node, std::fstream &inFile) {
  // temp for '\n' 
  std::string temp;
  std::getline(inFile, node->name);
  // PROCCESSING - if the last character of the string == ' ' then substr
  if (node->name[node->name.size() - 1] == ' ') {
    node->name = node->name.substr(0, node->name.find_last_of(' '));
  }
  inFile.get(node->gender);
  inFile.ignore(1000, ' ');
  inFile >> node->age;
  inFile.ignore(1000, '\n');
  std::getline(inFile, temp);

  std::cout << "Adding : " << node->name << "\n";
}