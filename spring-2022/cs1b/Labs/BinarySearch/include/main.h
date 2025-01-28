#pragma once
#include <iostream>
#include <iomanip>

void displayHeader();//display header
void initArray(const size_t AR_SIZE, int intArray[]);//initialize the array by user input
int squentialSearch(const int &searchKey, const size_t &AR_SIZE,int intArray[]);//search for key in array (linear)
void handleOutput(const size_t &AR_SIZE, int intArray[]);//display output
void insertionSort(const size_t &AR_SIZE, int intArray[]);//sort array using insertion
int binarySearch(const int &searchKey, const size_t AR_SIZE, int intArray[]);//search for key in array (logarithmic)