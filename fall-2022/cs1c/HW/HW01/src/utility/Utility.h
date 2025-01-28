#ifndef UTILITY_H_
#define UTILITY_H_
#include <limits.h>

#include <iostream>
#include <string>

namespace Log {
enum struct Status { ERROR = -1, WARNING = 0, SUCCESS = 1 };
}  // namespace Log

class Exception {
 public:
  /**
   * @brief Construct a new Exception object
   *
   * @param LogStatus
   * @param Msg
   */
  Exception(const Log::Status &LogStatus, const std::string &Msg);
  /**
   * @brief Destroy the Exception object
   *
   */
  ~Exception();
  /**
   * @brief Get the Log Status object
   *
   * @return Log::Status
   */
  Log::Status GetLogStatus() const;

  /**
   * @brief Get the Msg object
   *
   * @return std::string
   */
  std::string GetMsg() const;

 private:
  Log::Status LogStatus_;
  std::string Msg_;
};

namespace Utility {
/**
 * @brief Log with different statuses
 *
 * @param LogStatus
 * @param Msg
 */
void Log(const Log::Status &LogStatus, const std::string &Msg);

/**
 * @brief Clean buffer and if fail then throw exception
 *
 * @param is
 */
void Buffer(std::istream &is);

/**
 * @brief Takes user input and validates it (int)
 *
 * @param num User input
 * @param Prefix Text before user input
 */
void ValidateInt(short int &num, const char* Prefix);

/**
 * @brief Takes user input and validates it (char)
 *
 * @param c User input
 * @param Prefix Text before user input
 */
void ValidateChar(char &c, const char* Prefix);
}  // namespace Utility

#endif  // UTILITY_H_