#include "../include/header.h"

int main() {
  PersonType person;
  person.print();
  person.setInitialValue("Carlos", 21, 155, 5.9);
  person.print();
  person.setName("Changed");
  person.setAge(19);
  person.setWeight(144);
  person.setHeight(5.8);
  std::cout << "Using get() Name: " << person.getName() << '\n';
  std::cout << "Using get() Age: " << person.getAge() << '\n';
  std::cout << "Using get() Weight: " << person.getWeight() << '\n';
  std::cout << "Using get() Height: " << person.getHeight() << '\n';
  return 0;
}