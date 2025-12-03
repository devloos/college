
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Person {
public:
  std::string name;
  int age;

  // Allows for direct printing of Person objects
  friend std::ostream &operator<<(std::ostream &os, const Person &p) {
    os << p.name << ", " << p.age;
    return os;
  }
};

int main() {
  std::cout << "CECS 342 Assignment 6\n";
  std::cout << "Name: Carlos Aguilera\n";
  std::cout << "Algorithm: generic sort, Language: C++\n\n";

  std::vector<double> numbers = {645.41, 37.59, 76.41,  5.31,    -34.23, 1.11,
                                 1.10,   23.46, 635.47, -876.32, 467.83, 62.25};

  std::vector<Person> people = {
      {"Hal", 20},      {"Susann", 31},  {"Dwight", 19}, {"Kassandra", 21},
      {"Lawrence", 25}, {"Cindy", 22},   {"Cory", 27},   {"Mac", 19},
      {"Romana", 27},   {"Doretha", 32}, {"Danna", 20},  {"Zara", 23},
      {"Rosalyn", 26},  {"Risa", 24},    {"Benny", 28},  {"Juan", 33},
      {"Natalie", 25}};

  // Sort numbers in ascending order
  std::sort(numbers.begin(), numbers.end());
  std::cout << "Numbers sorted in ascending order:\n";

  for (const auto &n : numbers) {
    std::cout << n << std::endl;
  }

  std::cout << std::endl;

  // Sort people alphabetically by name
  std::sort(people.begin(), people.end(),
            [](const Person &a, const Person &b) { return a.name < b.name; });

  std::cout << "People sorted alphabetically by name:\n";

  for (const auto &p : people) {
    std::cout << p << std::endl;
  }

  std::cout << std::endl;

  // Sort people by age (descending), then by name
  std::sort(people.begin(), people.end(), [](const Person &a, const Person &b) {
    if (a.age != b.age) {
      return a.age > b.age;
    }

    return a.name < b.name;
  });

  std::cout << "People sorted by age (descending), then by name:\n";

  for (const auto &p : people) {
    std::cout << p << std::endl;
  }

  return 0;
}
