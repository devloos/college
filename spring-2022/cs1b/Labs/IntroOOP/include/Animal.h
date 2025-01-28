#ifndef ANIMAL_H_
#define ANIMAL_H_
#include "header.h"
/*******************************************************************************
 * 
 ------------------------------------------------------------------------------- 
 * FUNCTION:
 * @param
 * RETURNS - 
 ******************************************************************************/

class Animal {
 public:
  Animal ();
  Animal(std::string name, std::string type, int age, float value);
  ~Animal ();
  void setInitialValues (std::string name, std::string type, int age, float value);
  void changeAge (int age);
  void changeValue (float value);
  void display () const;
  std::string getName () const;
  std::string getType () const;
  int getAge () const;
  float getValue () const;
 private:
  std::string m_Name;
  std::string m_Type;
  int m_Age;
  float m_Value;
};
#endif // ANIMAL_H_