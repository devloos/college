#ifndef PERSON_TYPE_H_
#define PERSON_TYPE_H_
#include <string>
#include <iostream>

class PersonType {
 public:
  PersonType();
  PersonType(const string &name, const unsigned int &age,
             const int &weight, const float &height);
  ~PersonType();

  void setInitialValues(const string &name, const unsigned int &age,
                        const int &weight, const float &height);
  void setName(const string &name);
  void setAge(const unsigned int &age);
  void setWeight(const int &weight);
  void setHeight(const float &height);

  virtual void print() const;
  string getName() const;
  unsigned int getAge() const;
  int getWeight() const;
  float getHeight() const;

 private:
  string m_Name;
  unsigned int m_Age;
  int m_Weight;
  float m_Height;
};

#endif // PERSON_TYPE_H_

#ifndef STUDENT_TYPE_H_
#define STUDENT_TYPE_H_
#include "PersonType.h"

enum ClassYear {
  Undefined = 0,
  Freshman,
  Sophomore,
  Junior,
  Senior
};

class StudentType : public PersonType {
 public:
  StudentType();
  StudentType(const string &name, const unsigned int age, const int &weight,
              const float &height, const string &major, const float &gpa,
              const ClassYear &year);
  ~StudentType();

  void setMajor(const string &major);
  void setGpa(const float &gpa);
  void setClassYear(const ClassYear &year);

  virtual void print() const override;
  string getMajor() const;
  float getGpa() const;
  ClassYear getClassYear() const;

 private:
  string m_Major;
  float m_Gpa;
  ClassYear m_Year;
};

#endif // STUDENT_TYPE_H_

#include "../include/PersonType.h"
using namespace std;

PersonType::PersonType() : m_Name(""), m_Age(0), m_Weight(0), m_Height(0.00f) {}
PersonType::PersonType(const string &name, const unsigned int &age,
                       const int &weight, const float &height) 
    : m_Name(name), m_Age(age), m_Weight(weight), m_Height(height) {}
PersonType::~PersonType() {}

void PersonType::setInitialValues(const string &name, const unsigned int &age,
                                  const int &weight, const float &height) {
  this->m_Name = name;
  this->m_Age = age;
  this->m_Weight = weight;
  this->m_Height = height;
}

// Setters
void PersonType::setName(const string &name) { this->m_Name = name; }
void PersonType::setAge(const unsigned int &age) { this->m_Age = age; }
void PersonType::setWeight(const int &weight) { this->m_Weight = weight; }
void PersonType::setHeight(const float &height) { this->m_Height = height; }

// Print Class Function
void PersonType::print() const {
  cout << "Name: " << m_Name << '\n'
            << "Age: " << m_Age << '\n'
            << "Weight: " << m_Weight << '\n'
            << "Height: " << m_Height << '\n';
}
// Getters
string PersonType::getName() const { return m_Name; }
unsigned int PersonType::getAge() const { return m_Age; }
int PersonType::getWeight() const { return m_Weight; }
float PersonType::getHeight() const { return m_Height; }

#include "../include/StudentType.h"
using namespace std;

StudentType::StudentType() : PersonType("", 0, 0, 0.00f), m_Major(""),
                             m_Gpa(0.00f), m_Year(Undefined) {}
// Overloaded constructor that delegates to PersonType Constructor
StudentType::StudentType(
  const string &name, const unsigned int age, const int &weight,
  const float &height, const string &major, const float &gpa,
  const ClassYear &year)
    : PersonType(name, age, weight, height), m_Major(major), m_Gpa(gpa), m_Year(year) {}


StudentType::~StudentType() {}

// Setters
void StudentType::setMajor(const string &major) { this->m_Major = major; }
void StudentType::setGpa(const float &gpa) { this->m_Gpa = gpa; }
void StudentType::setClassYear(const ClassYear &year) { this->m_Year = year; }

void StudentType::print() const {
  PersonType::print();
  cout << "Major: " << m_Major << '\n'
            << "GPA: " << m_Gpa << '\n'
            << "Class Year: " << m_Year << '\n';
}

// Getters
string StudentType::getMajor() const { return m_Major; }
float StudentType::getGpa() const { return m_Gpa; }
ClassYear StudentType::getClassYear() const { return m_Year; }

#include "../include/PersonType.h"
#include "../include/StudentType.h"

void testPerson();
void testStudent();

int main() {
  testPerson();
  testStudent();
  return 0;
}

#include "../include/StudentType.h"
using namespace std;

void testPerson() {
  // PersonType Constructor Test
  cout << "Constructor:\n";
  PersonType generalPerson("General Person", 20, 90, 5.9f);
  generalPerson.print();

  // Set Initial Values test
  cout << "\nInitial Values:\n";
  generalPerson.setInitialValues("Changed Name", 18, 90, 5.6f);
  generalPerson.print();

  // Setters
  cout << "\nSetters:\n";
  generalPerson.setName("Set Name");
  generalPerson.setAge(40);
  generalPerson.setWeight(90);
  generalPerson.setHeight(5.3f);
  generalPerson.print();

  // Getters
  cout << "\nGetters:\n";
  cout << "Name: " << generalPerson.getName() << '\n';
  cout << "Age: " << generalPerson.getAge() << '\n';
  cout << "Weight: " << generalPerson.getWeight() << '\n';
  cout << "Height: " << generalPerson.getHeight() << '\n';
}

#include "../include/StudentType.h"
using namespace std;

void testStudent() {
  // StudentType Constructor Test
  cout << "Constructor:\n";
  StudentType* student = new StudentType("Student", 20, 90, 5.9f,
      "Computer Science", 3.8f, Freshman);
  student->print();

  // Setters
  cout << "\nSetters:\n";
  student->setName("Set Name");
  student->setAge(40);
  student->setWeight(90);
  student->setHeight(5.3f);
  student->setMajor("English");
  student->setGpa(3.7f);
  student->setClassYear(Sophomore);
  student->print();

  // Getters
  cout << "\nGetters:\n";
  cout << "Name: " << student->getName() << '\n';
  cout << "Age: " << student->getAge() << '\n';
  cout << "Weight: " << student->getWeight() << '\n';
  cout << "Height: " << student->getHeight() << '\n';
  cout << "Major: " << student->getMajor() << '\n';
  cout << "GPA: " << student->getGpa() << '\n';
  cout << "Class Year: " << student->getClassYear() << '\n';
}