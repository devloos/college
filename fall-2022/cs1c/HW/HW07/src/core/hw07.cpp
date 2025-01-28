/**
 * @author Carlos Aguilera
 * @brief This program allows the user to enter a
 * string and check whether it is a palindrome
 * @date 2022-11-04
 */
#include "hw07.h"

int main() {
  Option option = Option::EXIT;
  do {
    printMenu();
    std::cin >> option;

    if (option == Option::RUN) {
      exec();
    }
  } while (option != Option::EXIT);
  return 0;
}
