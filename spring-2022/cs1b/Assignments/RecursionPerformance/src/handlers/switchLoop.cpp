#include "../../include/header.h"

std::istream &operator>>(std::istream &is, MenuOption &choice) {
  int temp;
  bool validated = false;
  do {
    try {
      printMenu();
      is >> temp;
      if (is.fail()) {
        is.clear();
        is.ignore(1000, '\n');
        throw true;
      }
      validated = true;
    }catch(bool invalid) {
      std::cout << "Please enter a NUMBER! TRY AGAIN\n";
    }
  }while (!validated);
  choice = MenuOption(temp);
  return is;
}

void switchLoop() {
  MenuOption choice = Exit;
  long long n = 0;
  long long result;
  do {
    // PROCESSING: prints menu and validates operator overloading
    std::cin >> choice;
    // PROCESSING: switch statement on choice
    switch (choice) {
      case Exit: {
        break;
      }
      case DisplayFactorial: {
        std::cout << "\nEnter number to get the Factorial of: ";
        validation(n);
        std::cout << "[ ";
        result = recursiveFactorial(n);
        std::cout << "]\n";
        std::cout << "Factorial of " << n << " is: " << result << "\n\n";
        break;
      }
      case DisplayFibonacci: {
        std::cout << "\nEnter number for series of Fibonacci: ";
        validation(n);
        std::cout << "[ ";
        result = recursiveFib(n);
        std::cout << "]\n";
        std::cout << "Fibonacci series of " << n << " is: " << result << "\n\n";
        break;
      }
      case FactorialPerformance: {
        std::cout << "\nEnter number for comparsion of Factorial: ";
        validation(n);
        factorialPerformance(n);
        break;
      }
      case FibonacciPerformance: {
        std::cout << "\nEnter number for comparison of Fibonacci: ";
        validation(n);
        fibonacciPerformance(n);
        break;
      }
      default: {
        std::cout << "Enter a number between 0 and 4!\n";
        break;
      }
    }
  }while (choice != Exit);
  
}