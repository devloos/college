#include "../include/StudentType.h"

void testStudent() {
  // StudentType Constructor Test
  std::cout << "Constructor:\n";
  StudentType* student = new StudentType("Student", 20, 90, 5.9f,
      "Computer Science", 3.8f, Freshman);
  student->print();

  // Setters
  std::cout << "\nSetters:\n";
  student->setName("Set Name");
  student->setAge(40);
  student->setWeight(90);
  student->setHeight(5.3f);
  student->setMajor("English");
  student->setGpa(3.7f);
  student->setClassYear(Sophomore);
  student->print();

  // Getters
  std::cout << "\nGetters:\n";
  std::cout << "Name: " << student->getName() << '\n';
  std::cout << "Age: " << student->getAge() << '\n';
  std::cout << "Weight: " << student->getWeight() << '\n';
  std::cout << "Height: " << student->getHeight() << '\n';
  std::cout << "Major: " << student->getMajor() << '\n';
  std::cout << "GPA: " << student->getGpa() << '\n';
  std::cout << "Class Year: " << student->getClassYear() << '\n';
}