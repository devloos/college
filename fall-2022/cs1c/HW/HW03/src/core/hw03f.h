#ifndef HW03f_H_
#define HW03f_H_
#include <cstring>
#include <iostream>
#include <limits>
#include <stdio.h>
#include <string.h>

class StringType {
 public:
  StringType(size_t length);
  /**
   * @brief Construct a new String Type object
   *
   * @param s
   */
  StringType(const char* s);

  /**
   * @brief Copy Construct a new String Type object
   *
   * @param rhs
   */
  StringType(const StringType &rhs);

  /**
   * @brief Move Construct a new String Type object
   *
   * @param rhs
   */
  StringType(StringType &&rhs) noexcept;

  /**
   * @brief Copy Assignment
   *
   * @param rhs
   * @return StringType&
   */
  StringType &operator=(const StringType &rhs);

  /**
   * @brief Move Assignment
   *
   * @param rhs
   * @return StringType&
   */
  StringType &operator=(StringType &&rhs);

  /**
   * @brief Destroy the String Type object
   *
   */
  ~StringType();

  /**
   * @brief
   *
   * @param os
   * @param rhs
   * @return std::ostream&
   */
  friend std::ostream &operator<<(std::ostream &os, const StringType &rhs);

  /**
   * @brief
   *
   * @param is
   * @param rhs
   * @return std::istream&
   */
  friend std::istream &operator>>(std::istream &is, StringType &rhs);

  /**
   * @brief
   *
   * @return size_t
   */
  size_t length() const;

  /**
   * @brief
   *
   * @param index
   * @return char&
   */
  char &operator[](const int &index);

  /**
   * @brief
   *
   * @param rhs
   * @return true
   * @return false
   */
  bool operator==(const StringType &rhs) const;

  /**
   * @brief
   *
   * @param rhs
   * @return StringType
   */
  StringType operator+(const StringType &rhs) const;

  /**
   * @brief
   *
   * @param rhs
   * @return StringType&
   */
  StringType &operator+=(const StringType &rhs);

  /**
   * @brief
   *
   * @param c
   * @return size_t
   */
  size_t indexOf(const char &c) const;

  /**
   * @brief
   *
   * @param rhs
   * @return size_t
   */
  size_t indexOf(const StringType &rhs) const;

  /**
   * @brief
   *
   * @return true
   * @return false
   */
  bool isEmpty() const;

  /**
   * @brief
   *
   * @return StringType
   */
  StringType reverse() const;

  // INTERNAL LIB FUNCTIONS
 private:
  /**
   * @brief
   *
   * @param index
   * @return true
   * @return false
   */
  bool inBoundary(const int &index) const;

  /**
   * @brief
   *
   * @param rhs
   * @return true
   * @return false
   */
  bool strCompare(const StringType &rhs) const;

 private:
  char* buffer_ = nullptr;
  size_t length_ = 0;
};

#endif  // HW03f_H_