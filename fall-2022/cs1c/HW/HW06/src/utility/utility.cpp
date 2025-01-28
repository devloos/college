#include "utility.h"

Exception::Exception(const std::string &msg, const Exception::Level &level)
    : msg_(msg), level_(level) {}

std::string Exception::what() const {
  switch (level_) {
    case Exception::Level::ERROR: {
      return "ERROR: " + msg_;
    }
    case Exception::Level::WARNING: {
      return "WARNING: " + msg_;
    }
  }
}
