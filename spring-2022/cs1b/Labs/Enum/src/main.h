#pragma once
#include <iostream>
#include <string>
#include <iomanip>

enum Days {SUNDAY,MONDAY,TUESDAY,WEDNESDAY,THURSDAY,FRIDAY,SATURDAY};

void displayHeader();
int convertEnum(const std::string &inputDay);//converts day string input to element associated with days type
std::string convertString(const int enumIndex, const std::string days[]);//takes placement conversion by convertEnum and uses it as index for what string to return