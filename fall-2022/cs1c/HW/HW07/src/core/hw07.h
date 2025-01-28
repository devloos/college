#pragma once

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <istream>
#include <limits>
#include <string>

enum struct Option { EXIT = 0, RUN = 1 };
std::istream &operator>>(std::istream &is, Option &option);

void printMenu();
bool isPalindrome(const std::string &data);
void exec();