#ifndef HEADER_H_
#define HEADER_H_
#include <iostream>
#include <iomanip>

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
 * 
 ------------------------------------------------------------------------------- 
 * FUNCTION:
 * @param
 * RETURNS - 
 ******************************************************************************/
void menu();
void headerClass();
void validateInt(unsigned int &choice, const bool &isMenu, const int MIN, const int MAX);
#endif // HEADER_H_