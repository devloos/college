#include "../../include/Animal.h"

// Construtors
Animal::Animal() : Animal("", 0) {}
Animal::Animal(const std::string &name, const unsigned int &age) 
    : m_Name(name), m_Age(age) {}
// Getters
std::string Animal::getName() const { return m_Name; }
unsigned int Animal::getAge() const { return m_Age; }
// Setters
void Animal::setName(const std::string &name) { m_Name = name; }
void Animal::setAge(const unsigned int &age) { m_Age = age; }
// Methods
void Animal::print() const {
  std::cout << std::setw(12) << m_Name << std::setw(4) << m_Age;
}