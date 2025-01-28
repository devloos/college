#include "../include/Sheep.h"

Sheep::Sheep() : m_Name(""), m_Age(0), next(nullptr) {}
Sheep::Sheep(const std::string &name, const unsigned int &age) 
    : m_Name(name), m_Age(age) {}
Sheep::~Sheep() {}

// Setters
void Sheep::setInitialValues(const std::string name, const unsigned int &age) {
  this->m_Name = name;
  this->m_Age = age;
}
void Sheep::setName(const std::string &name) { this->m_Name = name; }
void Sheep::setAge(const unsigned int &age) { this->m_Age = age; }

// Getters
void Sheep::getValues(std::string &name, unsigned int &age) const {
  name = this->m_Name;
  age = this->m_Age;
}
std::string Sheep::getName() const { return m_Name; }
unsigned int Sheep::getAge() const { return m_Age; }