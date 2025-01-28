#ifndef ANIMAL_H_
#define ANIMAL_H_
#include <string>
#include <iomanip>
#include <iostream>
#include <vector>

class Animal {
 public:
  Animal();
  Animal(const std::string &name, const unsigned int &age);
  ~Animal() {}
  // Getters
  std::string getName() const;
  unsigned int getAge() const;
  // Setters
  void setName(const std::string &name);
  void setAge(const unsigned int &age);

  void print() const;
 private:
  std::string m_Name;
  unsigned int m_Age;
};

#endif // ANIMAL_H_