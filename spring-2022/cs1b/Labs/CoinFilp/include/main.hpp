#pragma once
#include <iostream>
#include <iomanip>

void heading(); //Displays heading to console
void userInformation(); //Handles user data ex. name, and sex
bool coinFlip(); //Returns true or false depending on whether it generates a 0 or 1
size_t averageLogic(const size_t &totalHeadCount, const size_t &totalFlipCount);//Returns average head flip per total flip count in percentage
void outputResults(const size_t &totalFlipCount, size_t averageHeadFlip); //Displays results of the program