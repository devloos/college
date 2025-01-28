#pragma once
#include <iostream>
#include <iomanip>

void heading();//prints out heading
void handleInput(size_t &numOfSheeps, size_t &numOfChocolateBars);//handles input of sheeps and chocolate bars
void handleCalc(const size_t numOfSheeps, const size_t numOfChocolateBars);//handles the logic
void handleOutput(const size_t &remainder, size_t &i);//handles output
void handleOutput(const size_t &remainder);//overloaded function that handles output