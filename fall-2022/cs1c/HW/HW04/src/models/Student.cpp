#include "Student.h"

void Student::setId(const int &id) {
  this->id_ = id;
}

int Student::getId() const {
  return this->id_;
}

std::string Student::getFullName() const {
  return this->firstName_ + " " + this->lastName_;
}

void Student::setLastName(const std::string &lastName) {
  this->lastName_ = lastName;
}

std::string Student::getLastName() const {
  return this->lastName_;
}

void Student::setFirstName(const std::string &firstName) {
  this->firstName_ = firstName;
}

std::string Student::getFirstName() const {
  return this->firstName_;
}

void Student::setEmail(const std::string &email) {
  this->email_ = email;
}

std::string Student::getEmail() const {
  return this->email_;
}

void Student::setPhone(const std::string &phone) {
  this->phone_ = phone;
}

std::string Student::getPhone() const {
  return this->phone_;
}

void Student::setAddress(const Address &address) {
  this->address_ = address;
}

Address Student::getAddress() const {
  return this->address_;
}

void Student::setMajor(const std::string &major) {
  this->major_ = major;
}

std::string Student::getMajor() const {
  return this->major_;
}

void Student::setRank(const std::string &rank) {
  this->rank_ = rank;
}

std::string Student::getRank() const {
  return this->rank_;
}

void Student::setGpa(const float &gpa) {
  this->gpa_ = gpa;
}

float Student::getGpa() const {
  return this->gpa_;
}

void Student::print() const {
  std::cout << "Name: " << this->getFullName() << "\n"
            << "Email: " << this->email_ << "\n"
            << "Phone: " << this->phone_ << "\n";
  this->address_.print();
  std::cout << "Major: " << this->major_ << "\n"
            << "Rank: " << this->rank_ << "\n"
            << "GPA: " << this->gpa_ << "\n";
}

bool Student::operator<(const Student &other) const {
  return this->lastName_ < other.lastName_;
}