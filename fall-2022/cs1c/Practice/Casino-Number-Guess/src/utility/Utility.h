#ifndef UTILITY_H_
#define UTILITY_H_
#include <limits.h>

#include <exception>
#include <fstream>
#include <iostream>
#include <string>

enum struct LogStatus { TERMINATE = -1, ERROR = 0, SUCCESS = 1, WARNING = 2 };

namespace Utility {

class Exception {
 public:
  Exception(const LogStatus &Status, const std::string &Msg);
  ~Exception();

  LogStatus GetLogStatus() const;
  std::string GetMsg() const;

 private:
  LogStatus Status_;
  std::string Msg_;
};

void Log(const LogStatus &Status, const std::string &msg);
void Buffer(std::istream &is);

namespace Input {
void Validate(
    short int &num_, const char* Prefix, const int &MAX_INT, const int &MIN_INT);
}  // namespace Input
}  // namespace Utility

#endif  // UTILITY_H_