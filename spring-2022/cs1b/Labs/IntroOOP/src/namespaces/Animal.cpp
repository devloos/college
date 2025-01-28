#include "../../include/header.h"

Animal::Animal() : m_Type(""), m_Name(""), m_Age(0), m_Value(0) {}
Animal::Animal(std::string name, std::string type, int age, float value) 
    : m_Type(type), m_Name(name), m_Age(age), m_Value(value) {}
Animal::~Animal () {}
void Animal::setInitialValues (std::string name, std::string type, int age,
                               float value) {
  this->m_Name= name;
  this->m_Type = type;
  this->m_Age= age;
  this->m_Value = value;
}
void Animal::changeAge (int age) { this->m_Age = age; }
void Animal::changeValue (float value) { this->m_Value = value; }
void Animal::display () const {
  static int i = 0;
  if (i == 0) {
    std::cout << std::left;
    std::cout << std::setw(12) << "\nANIMAL" << std::setw(15) << "NAME";
    std::cout << std::setw(7) << "AGE" << std::setw(6) << "VALUE\n";
    std::cout << "----------" << " --------------" << " ---" << " ------------\n";
    std::cout << std::right;
  }
  std::cout << std::left;
  std::cout << std::setw(11) << m_Type << std::setw(16) << m_Name;
  std::cout << std::right << std::setw(1) << m_Age << std::setprecision(2);
  std::cout << std::fixed << std::setw(6) << "$ " << std::setw(7) << m_Value << "\n";
  std::cout << std::right;
  if (i < 2) {
    ++i;
  }else {
    i = 0;
  }
}
std::string Animal::getName () const { return this->m_Name; }
std::string Animal::getType () const { return this->m_Type; }
int Animal::getAge () const { return this->m_Age; }
float Animal::getValue () const { return this->m_Value; }