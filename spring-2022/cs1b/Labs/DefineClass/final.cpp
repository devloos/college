#ifndef HEADER_H_
#define HEADER_H_
#include <iostream>
#include <iomanip>
#include "person.h"
using namespace std;

#endif // HEADER_H_

#ifndef PERSON_H_
#define PERSON_H_
#include <string>

class PersonType {
 private:
  string m_Name;
  int m_Age;
  int m_Weight;
  double m_Height;
 public:
  PersonType();
  ~PersonType();
  void setInitialValue(const string &name, const int &age,
                       const int &weight, const double &height);
  void print() const;
  void setName(string name);
  void setAge(int age);
  void setWeight(int weight);
  void setHeight(double height);
  string getName() const;
  int getAge() const;
  int getWeight() const;
  double getHeight() const;
};

#endif // PERSON_H_

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
  cout << "Using get() Name: " << person.getName() << '\n';
  cout << "Using get() Age: " << person.getAge() << '\n';
  cout << "Using get() Weight: " << person.getWeight() << '\n';
  cout << "Using get() Height: " << person.getHeight() << '\n';
  return 0;
}

#include "../include/header.h"

// Constructor
PersonType::PersonType() : m_Name(""), m_Age(0), m_Weight(0), m_Height(0.0f) {}
// Destructor
PersonType::~PersonType() {}
// setInitialValue?
void PersonType::setInitialValue(const string &name, const int &age, 
                                 const int &weight, const double &height) {
  this->m_Name = name;
  this->m_Age = age;
  this->m_Weight = weight;
  this->m_Height = height;
}
// Print all member variables
void PersonType::print() const {
  cout << "Name: " << m_Name << "\n";
  cout << "Age: " << m_Age << "\n";
  cout << "Weight: " << m_Weight << "\n";
  cout << "Height: " << m_Height << "\n";
}
// Set m_Name
void PersonType::setName(string name) { this->m_Name = name; }
// Set m_Age
void PersonType::setAge(int age) { this->m_Age = age; }
// Set m_Weight
void PersonType::setWeight(int weight) { this->m_Weight = weight; }
// Set m_Height
void PersonType::setHeight(double height) { this->m_Height = height; }
// Get m_Name
string PersonType::getName() const { return m_Name; }
// Get m_Age
int PersonType::getAge() const { return m_Age; }
// Get m_Weight
int PersonType::getWeight() const { return m_Weight; }
// Get m_Height
double PersonType::getHeight() const {return m_Height; }