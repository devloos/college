// Author: Carlos Aguilera
// CECS 325-02 Prog 0
// Due 01/27/2025
#include <iostream>

int fibo(int n) {
  if (n <= 1) {
    return 1;
  }

  return fibo(n - 1) + fibo(n - 2);
}

int main() {
  std::string name;
  int number = 0;

  std::cout << "What is your name? ";
  std::cin >> name;
  std::cout << "What is your favorite number? ";
  std::cin >> number;

  if (number % 2 == 0) {
    std::cout << "Your number is even.\n";
  } else {
    std::cout << "Your number is odd.\n";
  }

  std::cout << "Welcome to class " << name << "\n";
  for (int i = 0; i < 20; ++i) {
    std::cout << i << " : " << fibo(i) << "\n";
  }

  return 0;
}
