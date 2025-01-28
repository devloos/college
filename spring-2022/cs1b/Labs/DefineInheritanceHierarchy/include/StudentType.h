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
  StudentType(const std::string &name, const unsigned int age, const int &weight,
              const float &height, const std::string &major, const float &gpa,
              const ClassYear &year);
  ~StudentType();

  void setMajor(const std::string &major);
  void setGpa(const float &gpa);
  void setClassYear(const ClassYear &year);

  virtual void print() const override;
  std::string getMajor() const;
  float getGpa() const;
  ClassYear getClassYear() const;

 private:
  std::string m_Major;
  float m_Gpa;
  ClassYear m_Year;
};

#endif // STUDENT_TYPE_H_