****************************************************
*   PROGRAMMED BY : Carlos Aguilera
*   CLASS         : CS1B
*   SECTION       : MW: 7:30p - 9:50p
*   LAB #4        : Recursion Performance
****************************************************

MENU OPTIONS

1 - Calculate and Display Factorial of a Number
2 - Calculate and Display Fibonacci Series of a Number
3 - Compare Performance for Factorial Implementations
4 - Compare Performance for Fibonacci Series Implementations
0 - EXIT
Enter an option (0 to exit): 1

Enter number to get the Factorial of: 5
[ 2 6 24 120 ]
Factorial of 5 is: 120

MENU OPTIONS

1 - Calculate and Display Factorial of a Number
2 - Calculate and Display Fibonacci Series of a Number
3 - Compare Performance for Factorial Implementations
4 - Compare Performance for Fibonacci Series Implementations
0 - EXIT
Enter an option (0 to exit): 2

Enter number for series of Fibonacci: 10
[ 1 2 1 3 1 2 5 1 2 1 3 8 1 2 1 3 1 2 5 13 1 2 1 3 1 2 5 1 2 1 3 8 21 1 2 1 3 1 2 5 1 2 1 3 8 1 2 1 3 1 2 5 13 34 1 2 1 3 1 2 5 1 2 1 3 8 1 2 1 3 1 2 5 13 1 2 1 3 1 2 5 1 2 1 3 8 21 55 ]
Fibonacci series of 10 is: 55

MENU OPTIONS

1 - Calculate and Display Factorial of a Number
2 - Calculate and Display Fibonacci Series of a Number
3 - Compare Performance for Factorial Implementations
4 - Compare Performance for Fibonacci Series Implementations
0 - EXIT
Enter an option (0 to exit): 3

Enter number for comparsion of Factorial: 5
Factorial Recursive in seconds: 5.19531
Factorial Iterative in seconds: 2.44554

MENU OPTIONS

1 - Calculate and Display Factorial of a Number
2 - Calculate and Display Fibonacci Series of a Number
3 - Compare Performance for Factorial Implementations
4 - Compare Performance for Fibonacci Series Implementations
0 - EXIT
Enter an option (0 to exit): 3

Enter number for comparsion of Factorial: 10
Factorial Recursive in seconds: 10.9075
Factorial Iterative in seconds: 4.30652

MENU OPTIONS

1 - Calculate and Display Factorial of a Number
2 - Calculate and Display Fibonacci Series of a Number
3 - Compare Performance for Factorial Implementations
4 - Compare Performance for Fibonacci Series Implementations
0 - EXIT
Enter an option (0 to exit): 4

Enter number for comparison of Fibonacci: 10
Fibonacci Recursive in seconds: 0.056394
Fibonacci Iterative in seconds: 0.00216117

MENU OPTIONS

1 - Calculate and Display Factorial of a Number
2 - Calculate and Display Fibonacci Series of a Number
3 - Compare Performance for Factorial Implementations
4 - Compare Performance for Fibonacci Series Implementations
0 - EXIT
Enter an option (0 to exit): 4

Enter number for comparison of Fibonacci: 30
Fibonacci Recursive in seconds: 521.906
Fibonacci Iterative in seconds: 0.0047385

MENU OPTIONS

1 - Calculate and Display Factorial of a Number
2 - Calculate and Display Fibonacci Series of a Number
3 - Compare Performance for Factorial Implementations
4 - Compare Performance for Fibonacci Series Implementations
0 - EXIT
Enter an option (0 to exit): 0

#ifndef HEADER_H_
#define HEADER_H_
#include <iostream>
#include <iomanip>
#include <cstdlib> 
#include <string> 
#include <chrono> 
#include <ctime> 
using namespace std;

enum MenuOption {
  Exit = 0,
  DisplayFactorial,
  DisplayFibonacci,
  FactorialPerformance,
  FibonacciPerformance
};

/*******************************************************************************
 * printMenu
 ------------------------------------------------------------------------------- 
 * FUNCTION: This Function handles the printing of menu
 * RETURNS - void
 ******************************************************************************/
void printMenu();

/*******************************************************************************
 * printHeading
 ------------------------------------------------------------------------------- 
 * FUNCTION: handles printing class heading
 * RETURNS - void
 ******************************************************************************/
void printHeading();

/*******************************************************************************
 * iterativeFactorial
 ------------------------------------------------------------------------------- 
 * FUNCTION: finds factorial of num using an iterative approach this is done 
 * with a for loop the iterates up to n and then we use algorithim 
 * nFactorial *= i what this does is multiplies every number up to n to find
 * Factorial, this is the printable method
 * @param n long long that holds number to find factorial of 
 * @param nFactorial used so that n does not get altered stores final factorial
 * RETURNS - void
 ******************************************************************************/
void iterativeFactorial(long long &n);

/*******************************************************************************
 * recursiveFactorial
 ------------------------------------------------------------------------------- 
 * FUNCTION: takes in n finds Factorial by multipling curr n with a recursive
 * call n - 1, this is a print function
 * @param n long long used by recursive factorial algorithim
 * RETURNS - long long
 ******************************************************************************/
long long recursiveFactorial(long long n);

/*******************************************************************************
 * recursiveFib
 ------------------------------------------------------------------------------- 
 * FUNCTION: Base case is if series is <= 1 return series, else run a
 * recursive call on series - 1 then when it base case gets hit right side 
 * recursive call gets hit and unwinds until all are added and you get fib
 * printable function
 * @param series holds user inputed series num
 * RETURNS - long long
 ******************************************************************************/
long long recursiveFib(long long series);

/*******************************************************************************
 * iterativeFib
 ------------------------------------------------------------------------------- 
 * FUNCTION: using a 3 variable method for solving Fibonacci iteratively
 * this is done by storing curr, prev, and next and updating these variables
 * as you iterate through the for loop, printable function
 * @param series holds user inputed series num
 * RETURNS - void
 ******************************************************************************/
void iterativeFib(const int &series);

/*******************************************************************************
 * recursiveFib
 ------------------------------------------------------------------------------- 
 * FUNCTION: Base case is if series is <= 1 return series, else run a
 * recursive call on series - 1 then when it base case gets hit right side 
 * recursive call gets hit and unwinds until all are added and you get fib
 * non-printable function
 * @param series holds user inputed series num
 * RETURNS - long long
 ******************************************************************************/
long long recursiveFibRaw(long long series);

/*******************************************************************************
 * iterativeFib
 ------------------------------------------------------------------------------- 
 * FUNCTION: using a 3 variable method for solving Fibonacci iteratively
 * this is done by storing curr, prev, and next and updating these variables
 * as you iterate through the for loop, non-printable function
 * @param series holds user inputed series num
 * RETURNS - void
 ******************************************************************************/
void iterativeFibRaw(const int &series);

/******************************************************************************
 * iterativeFactorial
 ------------------------------------------------------------------------------- 
 * FUNCTION: finds factorial of num using an iterative approach this is done 
 * with a for loop the iterates up to n and then we use algorithim 
 * nFactorial *= i what this does is multiplies every number up to n to find
 * Factorial, this is the non-printable method
 * @param n long long that holds number to find factorial of 
 * @param nFactorial used so that n does not get altered stores final factorial
 * RETURNS - void
 ******************************************************************************/
void iterativeFactorialRaw(long long &n);

/*******************************************************************************
 * recursiveFactorial
 ------------------------------------------------------------------------------- 
 * FUNCTION: takes in n finds Factorial by multipling curr n with a recursive
 * call n - 1, this is a non-print function
 * @param n long long used by recursive factorial algorithim
 * RETURNS - long long
 ******************************************************************************/
long long recursiveFactorialRaw(long long n);

/*******************************************************************************
 * factorialPerformance
 ------------------------------------------------------------------------------- 
 * FUNCTION: This function calls recursive and iterative factorial func and uses
 * chrono library to calculate time in seconds also displays microseconds.
 * Both recursive and iterative calls get 500,000,000 cycles to calculate
 * better time
 * @param n holds value that user wants to get factorial of
 * RETURNS - void
 ******************************************************************************/
void factorialPerformance(long long n);

/*******************************************************************************
 * fibonacciPerformance
 ------------------------------------------------------------------------------- 
 * FUNCTION: This function calls recursive and iterative fibonacci func and uses
 * chrono library to calculate time in seconds also displays microseconds.
 * Both recursive and iterative calls get 1,000,000 cycles to calculate
 * better time
 * @param n holds value that user wants to get fibonacci series of
 * RETURNS - void
 ******************************************************************************/
void fibonacciPerformance(long long n);

/*******************************************************************************
 * switchLoop
 ------------------------------------------------------------------------------- 
 * FUNCTION: this function handles delegation of menu option, also handles
 * validation of out of bounds menu inputs
 * RETURNS - void
 ******************************************************************************/
void switchLoop();

/*******************************************************************************
 * validation
 ------------------------------------------------------------------------------- 
 * FUNCTION: validation for long long this is done by do while try catch method
 * also validates if number is negative
 * @param n holds long long of user input
 * RETURNS - void
 ******************************************************************************/
void validation(long long &n);

#endif // HEADER_H_

#include "../include/header.h"
/*******************************************************************************
 * AUTHOR      : Carlos Aguilera
 * STUDENT ID  : 1152562
 * LAB #4      : Recursion Performance
 * CLASS       : CS1B
 * SECTION     : M-W
 * DUE DATE    : 05.03.22
 ******************************************************************************/

/******************************************************************************
 * Title: Recursion Performance
 * ----------------------------------------------------------------------------
 * PROGRAM: Calculates performance difference of Recursion and Iterative using
 * problems like Factorial, and Fibonacci. Displays time in seconds but includes
 * microseconds source code is fairly simple if needed to change time do so in
 * performance functions
 * ----------------------------------------------------------------------------
 ******************************************************************************/

int main() {
  printHeading();
  switchLoop();
  return 0;
}

#include "../../include/header.h"

/*******************************************************************************
 * >>
 ------------------------------------------------------------------------------- 
 * OPERATOR: validation for type MenuOption this is done by do while try catch
 * method also delegates printMenu
 * @param
 * RETURNS - istream
 ******************************************************************************/

istream &operator>>(istream &is, MenuOption &choice) {
  int temp;
  bool validated = false;
  do {
    try {
      printMenu();
      // PROCESSING: if failed then clear buffer and loop back
      is >> temp;
      if (is.fail()) {
        is.clear();
        is.ignore(1000, '\n');
        throw true;
      }
      validated = true;
    }catch(bool invalid) {
      cout << "Please enter a NUMBER! TRY AGAIN\n";
    }
  }while (!validated);
  // cast temp to MenuOption type and store result in choice
  choice = MenuOption(temp);
  return is;
}

/*******************************************************************************
 * switchLoop
 ------------------------------------------------------------------------------- 
 * FUNCTION: this function handles delegation of menu option, also handles
 * validation of out of bounds menu inputs
 * RETURNS - void
 ******************************************************************************/
void switchLoop() {
  MenuOption choice = Exit; // IN & CALC: choice of menu
  long long n = 0;          // IN & CALC: n to hold user input of what number to get Factorial or Fibonacci
  long long result;         // IN & CALC: holds result of recursive calls
  do {
    // PROCESSING: prints menu and validates operator overloading
    cin >> choice;
    // PROCESSING: switch statement on choice
    switch (choice) {
      case Exit: {
        break;
      }
      case DisplayFactorial: {
        cout << "\nEnter number to get the Factorial of: ";
        // PROCESSING: validation of input
        validation(n);
        cout << "[ ";
        // stores result of recursiveFactorial
        result = recursiveFactorial(n);
        cout << "]\n";
        cout << "Factorial of " << n << " is: " << result << "\n\n";
        break;
      }
      case DisplayFibonacci: {
        cout << "\nEnter number for series of Fibonacci: ";
        // PROCESSING: validation of input
        validation(n);
        cout << "[ ";
        result = recursiveFib(n);
        cout << "]\n";
        cout << "Fibonacci series of " << n << " is: " << result << "\n\n";
        break;
      }
      case FactorialPerformance: {
        cout << "\nEnter number for comparsion of Factorial: ";
        // PROCESSING: validation of input
        validation(n);
        factorialPerformance(n);
        break;
      }
      case FibonacciPerformance: {
        cout << "\nEnter number for comparison of Fibonacci: ";
        // PROCESSING: validation of input
        validation(n);
        fibonacciPerformance(n);
        break;
      }
      default: {
        cout << "Enter a number between 0 and 4!\n";
        break;
      }
    }
  }while (choice != Exit);
  
}

#include "../../include/header.h"

/*******************************************************************************
 * validation
 ------------------------------------------------------------------------------- 
 * FUNCTION: validation for long long this is done by do while try catch method
 * also validates if number is negative
 * @param n holds long long of user input
 * RETURNS - void
 ******************************************************************************/

void validation(long long &n) {
  bool validated = false;
  do {
    try {
      cin >> n;
      // PROCESSING: if failed then clear buffer and loop back
      if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        // throwing exception to catch
        throw true;
      }else if (n < 0) {
        // if bounds is not met
        cout << "Enter positive number!\n";
        cout << "Try Again: ";
        continue;
      }
      validated = true;
      return;
    }catch(bool invalid) {
      cout << "Please enter a NUMBER!\n";
      cout << "Try Again: ";
    }
  }while (!validated);
}

#include "../../include/header.h"
/*******************************************************************************
 * iterativeFactorial
 ------------------------------------------------------------------------------- 
 * FUNCTION: finds factorial of num using an iterative approach this is done 
 * with a for loop the iterates up to n and then we use algorithim 
 * nFactorial *= i what this does is multiplies every number up to n to find
 * Factorial, this is the printable method
 * @param n long long that holds number to find factorial of 
 * @param nFactorial used so that n does not get altered stores final factorial
 * RETURNS - void
 ******************************************************************************/

void iterativeFactorial(long long &n) {
  long long nFactorial = n;
  cout << "[";
  // PROCESSING: For loop that uses algo *= count of i 
  for (int i = 1; i < n; i++) {
    nFactorial *= i;
    // Tenary operator to not output last comma
    cout << nFactorial << ((i + 1 < n) ? ", " : "");
  }
  cout << "]\n";
}

/*******************************************************************************
 * recursiveFactorial
 ------------------------------------------------------------------------------- 
 * FUNCTION: takes in n finds Factorial by multipling curr n with a recursive
 * call n - 1, this is a print function
 * @param n long long used by recursive factorial algorithim
 * RETURNS - long long
 ******************************************************************************/

long long recursiveFactorial(long long n) {
  // BASE CASE
  if (n == 1) {
    return n;
  }
  // PROCESSING: DONE this way to be printable return n after
  n *= recursiveFactorial(n - 1);
  cout << n << " ";
  return n;
}

/******************************************************************************
 * iterativeFactorial
 ------------------------------------------------------------------------------- 
 * FUNCTION: finds factorial of num using an iterative approach this is done 
 * with a for loop the iterates up to n and then we use algorithim 
 * nFactorial *= i what this does is multiplies every number up to n to find
 * Factorial, this is the printable method
 * @param n long long that holds number to find factorial of 
 * @param nFactorial used so that n does not get altered stores final factorial
 * RETURNS - void
 ******************************************************************************/

void iterativeFactorialRaw(long long &n) {
  long long nFactorial = n;
  // PROCESSING: For loop that uses algo *= count of i 
  for (int i = 1; i < n; i++) {
    nFactorial *= i;
  }
}

/*******************************************************************************
 * recursiveFactorial
 ------------------------------------------------------------------------------- 
 * FUNCTION: takes in n finds Factorial by multipling curr n with a recursive
 * call n - 1, this is a print function
 * @param n long long used by recursive factorial algorithim
 * RETURNS - long long
 ******************************************************************************/

long long recursiveFactorialRaw(long long n) {
  if (n == 1) {
    return n;
  }
  return n * recursiveFactorialRaw(n - 1);
}

#include "../../include/header.h"

/*******************************************************************************
 * recursiveFib
 ------------------------------------------------------------------------------- 
 * FUNCTION: Base case is if series is <= 1 return series, else run a
 * recursive call on series - 1 then when it base case gets hit right side 
 * recursive call gets hit and unwinds until all are added and you get fib
 * @param series
 * RETURNS - long long
 ******************************************************************************/

long long recursiveFib(long long series) {
  if (series <= 1) {
    return series;
  }
  // PROCESSING: Algo
  long long n = recursiveFib(series - 1) + recursiveFib(series - 2);
  cout << n << " ";
  return n;
}

/*******************************************************************************
 * iterativeFib
 ------------------------------------------------------------------------------- 
 * FUNCTION: using a 3 variable method for solving Fibonacci iteratively
 * this is done by storing curr, prev, and next and updating these variables
 * as you iterate through the for loop, printable function
 * @param series holds user inputed series num
 * RETURNS - void
 ******************************************************************************/

void iterativeFib(const int &series) {
  int curr = 0, prev = 1, next = 0;
  // print first brace
  cout << "[";
  for (int i = 0; i <= series; i++) {
    // tenary operator on last comma 
    cout << curr << ((i + 1 <= series) ? "," : "");
    // first case example
    // next = 0 + 1
    next = curr + prev;
    // curr = 1
    curr = prev;
    // prev = 1
    prev = next;
  }
  // print last brace
  cout << "]\n";
}

/*******************************************************************************
 * recursiveFib
 ------------------------------------------------------------------------------- 
 * FUNCTION: Base case is if series is <= 1 return series, else run a
 * recursive call on series - 1 then when it base case gets hit right side 
 * recursive call gets hit and unwinds until all are added and you get fib
 * non-printable function
 * @param series
 * RETURNS - long long
 ******************************************************************************/

long long recursiveFibRaw(long long series) {
  if (series <= 1) {
    return series;
  }
  return recursiveFibRaw(series - 1) + recursiveFibRaw(series - 2);
}

void iterativeFibRaw(const int &series) {
  int curr = 0, prev = 1, next = 0;
  for (int i = 0; i <= series; i++) {
    next = curr + prev;
    curr = prev;
    prev = next;
  }
}

#include "../../include/header.h"

/*******************************************************************************
 * factorialPerformance
 ------------------------------------------------------------------------------- 
 * FUNCTION: This function calls recursive and iterative factorial func and uses
 * chrono library to calculate time in seconds also displays microseconds.
 * Both recursive and iterative calls get 500,000,000 cycles to calculate
 * better time
 * @param n holds value that user wants to get factorial of
 * RETURNS - void
 ******************************************************************************/

void factorialPerformance(long long n) {
  // start time
  high_resolution_clock::time_point start = high_resolution_clock::now(); 
  for (int i = 0; i < 500000000; i++)
    recursiveFactorialRaw(n);
  // end time of for loop
  high_resolution_clock::time_point end = high_resolution_clock::now(); 
  // type Duration given as a template double and storing result of end - start into recursiveTime
  duration<double> recursiveTime =  end - start;

  start = high_resolution_clock::now(); 
  for (int i = 0; i < 500000000; i++)
    iterativeFactorialRaw(n);
  end = high_resolution_clock::now(); 
  // type Duration given as a template double and storing result of end - start into iterationTime
  duration<double> iterationTime = end - start;
 
  // using count method for proper display
  cout << "Factorial Recursive in seconds: " << recursiveTime.count() << "\n";
  cout << "Factorial Iterative in seconds: " << iterationTime.count() << "\n\n";
}

#include "../../include/header.h"

/*******************************************************************************
 * fibonacciPerformance
 ------------------------------------------------------------------------------- 
 * FUNCTION: This function calls recursive and iterative fibonacci func and uses
 * chrono library to calculate time in seconds also displays microseconds.
 * Both recursive and iterative calls get 1,000,000 cycles to calculate
 * better time
 * @param n holds value that user wants to get fibonacci series of
 * RETURNS - void
 ******************************************************************************/

void fibonacciPerformance(long long n) {
  high_resolution_clock::time_point start = high_resolution_clock::now(); 
  for (int i = 0; i < 1000000; i++)
    recursiveFibRaw(n);
  high_resolution_clock::time_point end = high_resolution_clock::now(); 
  // type Duration given as a template double and storing result of end - start into recursiveTime
  duration<double> recursiveTime =  end - start;

  start = high_resolution_clock::now(); 
  for (int i = 0; i < 1000000; i++)
    iterativeFibRaw(n);
  end = high_resolution_clock::now(); 
  // type Duration given as a template double and storing result of end - start into iterationTime
  duration<double> iterationTime = end - start;
 
  cout << "Fibonacci Recursive in seconds: " << recursiveTime.count() << "\n";
  cout << "Fibonacci Iterative in seconds: " << iterationTime.count() << "\n\n";
}

#include "../../include/header.h"

/*******************************************************************************
 * printMenu
 ------------------------------------------------------------------------------- 
 * FUNCTION: This Function handles the printing of menu
 * RETURNS - void
 ******************************************************************************/

void printMenu() {
  cout << "MENU OPTIONS\n\n";
  cout << "1 - Calculate and Display Factorial of a Number\n";
  cout << "2 - Calculate and Display Fibonacci Series of a Number\n";
  cout << "3 - Compare Performance for Factorial Implementations\n";
  cout << "4 - Compare Performance for Fibonacci Series Implementations\n";
  cout << "0 - EXIT\n";
  cout << "Enter an option (0 to exit): ";
  return;
}

#include "../../include/header.h"

/*******************************************************************************
 * printHeading
 ------------------------------------------------------------------------------- 
 * FUNCTION: handles printing class heading
 * RETURNS - void
 ******************************************************************************/

void printHeading() {
	/***********************************************************************
	 * CONSTANTS
	 * ---------------------------------------------------------------------
	 * OUTPUT - USED FOR CLASS HEADING
	 * ---------------------------------------------------------------------
	 * PROGRAMMER : Programmer's Name
	 * CLASS      : Student's Course
	 * SECTION    : Class Days and Times
	 * LAB_NUM    : Lab Number (specific to this lab)
	 * LAB_NAME   : Title of the Lab
	 **********************************************************************/
	const char PROGRAMMER[] = "Carlos Aguilera";
	const char CLASS[]      = "CS1B";
	const char SECTION[]    = "MW: 7:30p - 9:50p";
	const int  LAB_NUM      = 4;
	const char LAB_NAME[]   = "Recursion Performance";

	cout << left;
	cout << "****************************************************\n";
	cout << "*   PROGRAMMED BY : " << PROGRAMMER << endl;
	cout << "*   " << setw(14) <<"CLASS" << ": " << CLASS << endl;
	cout << "*   " << setw(14) <<"SECTION" << ": " << SECTION << endl;
	cout << "*   LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME << endl;
	cout << "****************************************************\n\n";
	cout << right;
}