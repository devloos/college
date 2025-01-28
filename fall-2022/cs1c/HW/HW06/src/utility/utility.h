#ifndef UTILITY_H_
#define UTILITY_H_
#include <iostream>
#include <string>

class Exception {
 public:
  enum Level { ERROR = 0, WARNING };

 private:
  std::string msg_;
  Exception::Level level_;

 public:
  Exception(const std::string &msg, const Exception::Level &level);

 public:
  std::string what() const;
};

#endif  // UTILITY_H_