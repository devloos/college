#include "../include/StudentType.h"

void testPerson() {
  // PersonType Constructor Test
  std::cout << "Constructor:\n";
  PersonType generalPerson("General Person", 20, 90, 5.9f);
  generalPerson.print();

  // Set Initial Values test
  std::cout << "\nInitial Values:\n";
  generalPerson.setInitialValues("Changed Name", 18, 90, 5.6f);
  generalPerson.print();

  // Setters
  std::cout << "\nSetters:\n";
  generalPerson.setName("Set Name");
  generalPerson.setAge(40);
  generalPerson.setWeight(90);
  generalPerson.setHeight(5.3f);
  generalPerson.print();

  // Getters
  std::cout << "\nGetters:\n";
  std::cout << "Name: " << generalPerson.getName() << '\n';
  std::cout << "Age: " << generalPerson.getAge() << '\n';
  std::cout << "Weight: " << generalPerson.getWeight() << '\n';
  std::cout << "Height: " << generalPerson.getHeight() << '\n';
}