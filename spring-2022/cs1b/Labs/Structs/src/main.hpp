#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

struct Account {
    std::string userName;
    int userID;
    double userBalance;
};

void heading();
void readFile(std::string inputFileName, size_t sizeofArray, Account arrayofAccounts[]);//reads file and sets values in the arrays
int balanceIndex(char selection, size_t sizeofArray, Account arrayofAccounts[]);//returns index of largest or smallest balance depending on choice
double sumofBalances(size_t sizeofArray, Account arrayofAccounts[]);//sums all balances in array
int searchName(std::string inputName, size_t sizeofArray, Account arrayofAccounts[]);//searches name specified from user
void handleOutput(int index, std::string type, std::fstream &outFile, const char selection, const size_t sizeofArray, Account arrayofAccounts[]);//handles balance output
void handleSearchOutput(const std::string inputName, const int index, std::fstream &outFile, Account arrayofAccounts[]);//handles search output