// Name: Carlos Aguilera
// Class CECS 325-02
// Project Name Prog 5 – Gold Rabbits
// Due Date 04/21/2025
//
// I certify that this program is my own original work. I did not copy any part
// of this program from any other source. I further certify that I typed each
// and every line of code in this program.
#include <format>
#include <iostream>
#include <limits>
#include <map>
#include <string>

// #define integer short
#define integer int
// #define integer long long

const int PRINT_MAP = -1;

static std::map<integer, integer> map;

integer fibo(integer n) {
  if (n == 0 || n == 1) {
    return 1;
  }

  if (map.find(n) != map.end()) {
    return map[n];
  }

  integer a = fibo(n - 1);
  integer b = fibo(n - 2);

  integer result;

  if (__builtin_add_overflow(a, b, &result)) {
    std::string message = "overflow error at fib(" + std::to_string(n) + "): ";

    throw message + std::to_string(result);
  }

  map[n] = result;

  return map[n];
}

int main(int argc, char* argv[]) {
  for (int i = 1; i < argc; ++i) {
    try {
      int input = std::stoi(argv[i]);

      if (input == PRINT_MAP) {
        std::cout << "Fibo Map contents:\n";

        for (auto kv : map) {
          std::cout << kv.first << ":" << kv.second << "\n";
        }

        std::cout << "end of Fibo map\n\n";
      } else {
        std::string message = "fib(" + std::to_string(input) + "): ";
        std::cout << message << fibo(input) << "\n";
      }
    } catch (std::invalid_argument e) {
      std::cout << argv[i] << " is not an integer.\n";
    } catch (std::string e) {
      std::cout << e << "\n";
    }
  }

  return 0;
}