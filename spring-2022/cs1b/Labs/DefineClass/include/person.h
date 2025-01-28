#ifndef PERSON_H_
#define PERSON_H_
#include <string>

class PersonType {
 private:
  std::string m_Name;
  int m_Age;
  int m_Weight;
  double m_Height;
 public:
  PersonType();
  ~PersonType();
  void setInitialValue(const std::string &name, const int &age,
                       const int &weight, const double &height);
  void print() const;
  void setName(std::string name);
  void setAge(int age);
  void setWeight(int weight);
  void setHeight(double height);
  std::string getName() const;
  int getAge() const;
  int getWeight() const;
  double getHeight() const;
};

#endif // PERSON_H_