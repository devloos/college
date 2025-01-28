/**
 * @author Carlos Aguilera
 * @brief Program to test my Fraction type
 * @version 0.1
 * @date 2022-10-28
 */
#include "hw06.h"

static Fraction f1(1, 2);
static Fraction f2(1, 4);

namespace UnitTest {
// Arithmetic Operations
void adding() {
  std::cout << f1 << " + " << f2 << " = " << f1 + f2 << "\n";
}

void subtracting() {
  std::cout << f1 << " - " << f2 << " = " << f1 - f2 << "\n";
}

void multiplying() {
  std::cout << f1 << " * " << f2 << " = " << f1 * f2 << "\n";
}

void dividing() {
  std::cout << f1 << " / " << f2 << " = " << f1 / f2 << "\n";
}

// Relational Operations
void lessThan() {
  std::cout << std::boolalpha;
  std::cout << f1 << " < " << f2 << " = " << (f1 < f2) << "\n";
  std::cout << f1 << " <= " << f2 << " = " << (f1 <= f2) << "\n";
  std::cout << std::noboolalpha;
}

void greaterThan() {
  std::cout << std::boolalpha;
  std::cout << f1 << " > " << f2 << " = " << (f1 > f2) << "\n";
  std::cout << f1 << " >= " << f2 << " = " << (f1 >= f2) << "\n";
  std::cout << std::noboolalpha;
}

void equals() {
  std::cout << std::boolalpha;
  std::cout << f1 << " == " << f2 << " = " << (f1 == f2) << "\n";
  std::cout << std::noboolalpha;
}

void notEq() {
  std::cout << std::boolalpha;
  std::cout << f1 << " != " << f2 << " = " << (f1 != f2) << "\n";
  std::cout << std::noboolalpha;
}

// Misc.
void input() {
  Fraction input;
  std::cout << "Enter fraction (e.g. 3/4): ";
  std::cin >> input;
  std::cout << "The fraction entered was " << input << "\n\n";

  std::cout << "Enter an invalid fraction (e.g. cat/dog): ";
  std::cin >> input;
}
}  // namespace UnitTest

int main() {
  // Arithmetic Operations
  std::cout << "-ARITHMETIC OPERATIONS-\n\n";
  UnitTest::adding();
  UnitTest::subtracting();
  UnitTest::multiplying();
  UnitTest::dividing();

  // Relational Operations
  std::cout << "\n-RELATIONAL OPERATIONS-\n\n";
  UnitTest::lessThan();
  UnitTest::greaterThan();
  UnitTest::equals();
  UnitTest::notEq();

  // Misc.
  std::cout << "\n-INPUT-\n\n";
  UnitTest::input();
  return 0;
}
