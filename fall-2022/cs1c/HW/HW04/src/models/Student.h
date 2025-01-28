#ifndef STUDENT_H_
#define STUDENT_H_
#include <iostream>
#include <string>

#include "Address.h"

class Student {
 private:
  int id_ = 0;
  std::string lastName_;
  std::string firstName_;
  std::string email_;
  std::string phone_;
  Address address_;
  std::string major_;
  std::string rank_;
  float gpa_ = 0.0;

 public:
  /**
   * @brief Set the Id object
   *
   * @param id
   */
  void setId(const int &id);

  /**
   * @brief Get the Id object
   *
   * @return int
   */
  int getId() const;

  /**
   * @brief Get the Full Name object
   *
   * @return std::string
   */
  std::string getFullName() const;

  /**
   * @brief Set the Last Name object
   *
   * @param lastName
   */
  void setLastName(const std::string &lastName);

  /**
   * @brief Get the Last Name object
   *
   * @return std::string
   */
  std::string getLastName() const;

  /**
   * @brief Set the First Name object
   *
   * @param firstName
   */
  void setFirstName(const std::string &firstName);

  /**
   * @brief Get the First Name object
   *
   * @return std::string
   */
  std::string getFirstName() const;

  /**
   * @brief Set the Email object
   *
   * @param email
   */
  void setEmail(const std::string &email);

  /**
   * @brief Get the Email object
   *
   * @return std::string
   */
  std::string getEmail() const;

  /**
   * @brief Set the Phone object
   *
   * @param phone
   */
  void setPhone(const std::string &phone);

  /**
   * @brief Get the Phone object
   *
   * @return std::string
   */
  std::string getPhone() const;

  /**
   * @brief Set the Address object
   *
   * @param address
   */
  void setAddress(const Address &address);

  /**
   * @brief Get the Address object
   *
   * @return Address
   */
  Address getAddress() const;

  /**
   * @brief Set the Major object
   *
   * @param major
   */
  void setMajor(const std::string &major);

  /**
   * @brief Get the Major object
   *
   * @return std::string
   */
  std::string getMajor() const;

  /**
   * @brief Set the Rank object
   *
   * @param rank
   */
  void setRank(const std::string &rank);

  /**
   * @brief Get the Rank object
   *
   * @return std::string
   */
  std::string getRank() const;

  /**
   * @brief Set the Gpa object
   *
   * @param gpa
   */
  void setGpa(const float &gpa);

  /**
   * @brief Get the Gpa object
   *
   * @return float
   */
  float getGpa() const;

 public:
  void print() const;
  bool operator<(const Student &other) const;
};

#endif  // STUDENT_H_