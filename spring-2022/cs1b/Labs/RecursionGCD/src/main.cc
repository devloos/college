/*******************************************************************************
 * AUTHOR      : Carlos Aguilera
 * STUDENT ID  : 1152562
 * LAB #11     : Recursion GCD
 * CLASS       : CS1B
 * SECTION     : M-W
 * DUE DATE    : 04.25.22
 ******************************************************************************/

/******************************************************************************
 * GCD Recursion
 * ----------------------------------------------------------------------------
 * PROGRAM: This program is a GCD calculator using recursion its fairly simple
 * so ill let you go through the code
 * ----------------------------------------------------------------------------
 ******************************************************************************/

#include "../include/header.h"

int main() {
  std::fstream oFile;
  int m, n;
  oFile.open("OutputFile.txt", std::ios::out);

  heading();
  for (int i = 0; i < 4; i++) {
    std::cout << std::left;
    std::cout << std::setw(26) << "Enter the first integer:";
    std::cin >> m;
    std::cout << std::setw(26) << "Enter the second integer:";
    std::cin >> n;
    std::cout << "\n";
    std::cout << std::right;
    oFile << "The GCD for " << m << " & " << n << " = " << gcd(m, n) << "\n";
  }
  std::cout << "Thank you for using my GCD calculator!\n";
  oFile.close();
  return 0;
}