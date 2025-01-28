#include "Utility.h"

Utility::Exception::Exception(const Exception::Level &level, const std::string &msg)
    : level_(level), msg_(msg) {}

void Utility::Exception::log() const {
  switch (this->level_) {
    case Exception::Level::ERROR: {
      std::cerr << msg_ << "\n";
      break;
    }
    case Exception::Level::WARNING: {
      std::cout << msg_ << "\n";
      break;
    }
    default: {
      break;
    }
  }
}

int Utility::validate(const std::string &prefix) {
  bool validated = false;
  int option = 0;
  do {
    try {
      std::cout << prefix;
      std::cin >> option;
      Utility::cleanBuffer(std::cin);
      if (std::cin.fail()) {
        throw Utility::Exception(
            Utility::Exception::Level::WARNING, "\nPlease input a NUMBER!\n");
      }
      validated = true;
    } catch (const Utility::Exception &e) {
      e.log();
    }
  } while (!validated);
  return option;
}

void Utility::cleanBuffer(std::istream &is) {
  is.clear();
  is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}