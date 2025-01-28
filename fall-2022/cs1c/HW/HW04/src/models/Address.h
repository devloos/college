#ifndef ADDRESS_H_
#define ADDRESS_H_
#include <iostream>
#include <string>

class Address {
 private:
  std::string street_;
  std::string city_;
  std::string state_;
  int zip_ = 0;

 public:
  /**
   * @brief
   *
   * @param rhs
   * @return Address&
   */
  Address &operator=(const Address &rhs);

 public:
  /**
   * @brief Get the Full Address object
   *
   * @return std::string
   */
  std::string getFullAddress() const;

  /**
   * @brief Set the Street object
   *
   * @param street
   */
  void setStreet(const std::string &street);

  /**
   * @brief Get the Street object
   *
   * @return std::string
   */
  std::string getStreet() const;

  /**
   * @brief Set the City object
   *
   * @param city
   */
  void setCity(const std::string &city);

  /**
   * @brief Get the City object
   *
   * @return std::string
   */
  std::string getCity() const;

  /**
   * @brief Set the State object
   *
   * @param state
   */
  void setState(const std::string &state);

  /**
   * @brief Get the State object
   *
   * @return std::string
   */
  std::string getState() const;

  /**
   * @brief Set the Zip object
   *
   * @param zip
   */
  void setZip(const int &zip);

  /**
   * @brief Get the Zip object
   *
   * @return int
   */
  int getZip() const;

 public:
  void print() const;
};

#endif  // ADDRESSS_H_