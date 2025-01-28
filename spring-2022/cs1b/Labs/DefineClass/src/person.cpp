#include "../include/header.h"

// Constructor
PersonType::PersonType() : m_Name(""), m_Age(0), m_Weight(0), m_Height(0.0f) {}
// Destructor
PersonType::~PersonType() {}
// setInitialValue?
void PersonType::setInitialValue(const std::string &name, const int &age, 
                                 const int &weight, const double &height) {
  this->m_Name = name;
  this->m_Age = age;
  this->m_Weight = weight;
  this->m_Height = height;
}
// Print all member variables
void PersonType::print() const {
  std::cout << "Name: " << m_Name << "\n";
  std::cout << "Age: " << m_Age << "\n";
  std::cout << "Weight: " << m_Weight << "\n";
  std::cout << "Height: " << m_Height << "\n";
}
// Set m_Name
void PersonType::setName(std::string name) { this->m_Name = name; }
// Set m_Age
void PersonType::setAge(int age) { this->m_Age = age; }
// Set m_Weight
void PersonType::setWeight(int weight) { this->m_Weight = weight; }
// Set m_Height
void PersonType::setHeight(double height) { this->m_Height = height; }
// Get m_Name
std::string PersonType::getName() const { return m_Name; }
// Get m_Age
int PersonType::getAge() const { return m_Age; }
// Get m_Weight
int PersonType::getWeight() const { return m_Weight; }
// Get m_Height
double PersonType::getHeight() const { return m_Height; }