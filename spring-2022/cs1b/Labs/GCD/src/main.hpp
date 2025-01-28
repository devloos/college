#pragma once
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

void printHeader(std::ostream &output);//prints header using the ostream method to print to console and file
std::string printHeader();//prints header using ostringstream method to print to console and file
void readValues(int &value1, int &value2);//reads to values from user by reference
int GCD(int value1, int value2);//calculates GCD of 2 values in order of larger and smaller
void handleResults(std::ostream &output, const int &value1, const int &value2, const int &GCD);//handles the output of results to file