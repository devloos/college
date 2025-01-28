#include "hw07.h"

std::istream &operator>>(std::istream &is, Option &option) {
  int n = 0;
  is >> n;

  if (is.fail()) {
    std::cerr << "\nERROR: INVALID INPUT\n";
    std::exit(EXIT_FAILURE);
  }

  is.clear();
  is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  switch (static_cast<Option>(n)) {
    case Option::EXIT: {
      option = Option::EXIT;
      break;
    }
    case Option::RUN: {
      option = Option::RUN;
      break;
    }
    default: {
      std::cerr << "\nERROR: INVALID INPUT\n";
      std::exit(EXIT_FAILURE);
    }
  }
  return is;
}

void printMenu() {
  std::cout << std::setw(33) << "\nIS YOUR STRING A PALINDROME?\n";
  std::cout << std::setfill('-') << std::setw(36) << "\n";
  std::cout << std::setfill(' ');
  std::cout << "EXIT: 0\n";
  std::cout << "RUN: 1\n";
  std::cout << "Enter option: ";
}

/// @brief recursively check whether is palindrome
/// @param data
/// @return bool
bool isPalindrome(const std::string &data) {
  if (data.size() <= 1) {
    return true;
  }

  if (data[0] != data[data.size() - 1]) {
    return false;
  }

  return isPalindrome(data.substr(1, data.size() - 2));
}

void exec() {
  std::string data;

  std::cout << "\nEnter string: ";
  std::getline(std::cin, data);

  if (isPalindrome(data)) {
    printf("The string %s is a palindrome\n", data.c_str());
  } else {
    printf("The string %s is NOT a palindrome\n", data.c_str());
  }
}