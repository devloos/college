#ifndef UTILITY_H_
#define UTILITY_H_
#include <fstream>
#include <iostream>
#include <limits>
#include <string>

namespace Utility {
class Exception {
 public:
  enum struct Level {
    ERROR = 0,
    WARNING,
  };

 public:
  Exception(const Exception::Level &level, const std::string &msg);
  void log() const;

 private:
  std::string msg_;
  Exception::Level level_;
};

int validate(const std::string &prefix);
void cleanBuffer(std::istream &is);

}  // namespace Utility

#endif  // UTILITY_H_