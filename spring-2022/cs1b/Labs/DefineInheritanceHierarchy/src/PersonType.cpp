#include "../include/PersonType.h"

PersonType::PersonType() : m_Name(""), m_Age(0), m_Weight(0), m_Height(0.00f) {}
PersonType::PersonType(const std::string &name, const unsigned int &age,
                       const int &weight, const float &height) 
    : m_Name(name), m_Age(age), m_Weight(weight), m_Height(height) {}
PersonType::~PersonType() {}

void PersonType::setInitialValues(const std::string &name, const unsigned int &age,
                                  const int &weight, const float &height) {
  this->m_Name = name;
  this->m_Age = age;
  this->m_Weight = weight;
  this->m_Height = height;
}

// Setters
void PersonType::setName(const std::string &name) { this->m_Name = name; }
void PersonType::setAge(const unsigned int &age) { this->m_Age = age; }
void PersonType::setWeight(const int &weight) { this->m_Weight = weight; }
void PersonType::setHeight(const float &height) { this->m_Height = height; }

// Print Class Function
void PersonType::print() const {
  std::cout << "Name: " << m_Name << '\n'
            << "Age: " << m_Age << '\n'
            << "Weight: " << m_Weight << '\n'
            << "Height: " << m_Height << '\n';
}
// Getters
std::string PersonType::getName() const { return m_Name; }
unsigned int PersonType::getAge() const { return m_Age; }
int PersonType::getWeight() const { return m_Weight; }
float PersonType::getHeight() const { return m_Height; }