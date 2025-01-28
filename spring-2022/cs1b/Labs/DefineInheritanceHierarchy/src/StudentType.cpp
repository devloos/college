#include "../include/StudentType.h"

StudentType::StudentType() : PersonType("", 0, 0, 0.00f), m_Major(""),
                             m_Gpa(0.00f), m_Year(Undefined) {}
// Overloaded constructor that delegates to PersonType Constructor
StudentType::StudentType(
  const std::string &name, const unsigned int age, const int &weight,
  const float &height, const std::string &major, const float &gpa,
  const ClassYear &year)
    : PersonType(name, age, weight, height), m_Major(major), m_Gpa(gpa), m_Year(year) {}


StudentType::~StudentType() {}

// Setters
void StudentType::setMajor(const std::string &major) { this->m_Major = major; }
void StudentType::setGpa(const float &gpa) { this->m_Gpa = gpa; }
void StudentType::setClassYear(const ClassYear &year) { this->m_Year = year; }

void StudentType::print() const {
  PersonType::print();
  std::cout << "Major: " << m_Major << '\n'
            << "GPA: " << m_Gpa << '\n'
            << "Class Year: " << m_Year << '\n';
}

// Getters
std::string StudentType::getMajor() const { return m_Major; }
float StudentType::getGpa() const { return m_Gpa; }
ClassYear StudentType::getClassYear() const { return m_Year; }