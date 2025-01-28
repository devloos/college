#ifndef PERSON_TYPE_H_
#define PERSON_TYPE_H_
#include <string>
#include <iostream>

class PersonType {
 public:
  PersonType();
  PersonType(const std::string &name, const unsigned int &age,
             const int &weight, const float &height);
  ~PersonType();

  void setInitialValues(const std::string &name, const unsigned int &age,
                        const int &weight, const float &height);
  void setName(const std::string &name);
  void setAge(const unsigned int &age);
  void setWeight(const int &weight);
  void setHeight(const float &height);

  virtual void print() const;
  std::string getName() const;
  unsigned int getAge() const;
  int getWeight() const;
  float getHeight() const;

 private:
  std::string m_Name;
  unsigned int m_Age;
  int m_Weight;
  float m_Height;
};

#endif // PERSON_TYPE_H_