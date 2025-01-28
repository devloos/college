#include "Utility.h"

namespace Utility {
Exception::Exception(const LogStatus &Status, const std::string &Msg)
    : Status_(Status), Msg_(Msg) {}
Exception::~Exception() {}

LogStatus Exception::GetLogStatus() const { return Status_; }
std::string Exception::GetMsg() const { return Msg_; }

void Log(const LogStatus &Status, const std::string &msg) {
  switch (Status) {
    case LogStatus::TERMINATE: {
      std::cerr << "STATUS TERMINATE: " << msg << '\n';
      throw std::exception();
    }
    case LogStatus::ERROR: {
      std::cerr << "STATUS ERROR: " << msg << '\n';
      break;
    }
    case LogStatus::WARNING: {
      std::cout << "STATUS WARNING: " << msg << '\n';
      break;
    }
    case LogStatus::SUCCESS: {
      std::cout << "STATUS SUCCESS: " << msg << '\n';
      break;
    }
  }
}

void Buffer(std::istream &is) {
  bool Failed = is.fail();
  is.clear();
  is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  if (Failed) throw Exception(LogStatus::ERROR, "INPUT STREAM HAS FAILED");
  return;
}

namespace Input {
void Validate(
    short int &num_, const char* Prefix, const int &MAX_INT, const int &MIN_INT) {
  bool Validated = false;
  do {
    try {
      std::cout << Prefix;
      std::cin >> num_;
      Buffer(std::cin);

      if (num_ > MAX_INT || num_ < MIN_INT) {
        throw Exception(LogStatus::WARNING, "BOUNDARY REQUIREMENT NOT MET!");
      }

      Validated = true;
    } catch (const Exception &ex) {
      Log(ex.GetLogStatus(), ex.GetMsg());
      std::cout << std::endl;
    }
  } while (!Validated);
}
}  // namespace Input
}  // namespace Utility