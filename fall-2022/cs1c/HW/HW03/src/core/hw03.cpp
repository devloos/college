#include "hw03.h"

/*
 * Author: Carlos Aguilera
 * Class: CS1C
 * Professor: Dr. B
 * Date: 09-13-22
 */

class Test {
 public:
  static void reverse(const StringType &obj) {
    std::cout << "Reverse: " << obj.reverse() << "\n";
  }

  static void copyConstructor(StringType obj) {
    std::cout << "Copy Constructor: " << obj << '\n';
  }

  static void moveConstructor(StringType obj) {
    std::cout << "Move Constructor: " << obj << '\n';
  }

  static void addOperator(const StringType &obj) {
    std::cout << "Adding Jr to end: " << obj + " Jr"
              << "\n";
  }

  static void comparison(const StringType &obj) {
    std::cout << std::boolalpha;
    std::cout << "Comparison with Dr. B [true or false]: ";
    std::cout << (obj == "Dr. b") << "\n";
    std::cout << std::noboolalpha;
  }

  static void indexOf(const StringType &obj) {
    std::cout << "Index of [s]: " << obj.indexOf('s') << "\n";
  }
};

int main() {
  StringType name("Carlos Aguilera");

  std::cout << "My String Program\n\n";
  std::cout << "Test String: " << name << "\n\n";

  try {
    Test::reverse(name);
    Test::copyConstructor(name);
    Test::moveConstructor(std::move("Carlos Aguilera"));
    Test::addOperator(name);
    Test::comparison(name);
    Test::indexOf(name);
  } catch (const int &errCode) {
    std::cerr << "Exception thrown code [" << errCode << "]\n";
  }

  return 0;
}
