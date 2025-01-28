#include "Utility.h"

namespace Utility {
void Log(const Log::Status &LogStatus, const std::string &Msg) {
  switch (LogStatus) {
    case Log::Status::ERROR: {
      std::cerr << "\nERROR: [" << Msg << "]\n\n";
      break;
    }
    case Log::Status::WARNING: {
      std::cout << "\nWARNING: [" << Msg << "]\n\n";
      break;
    }
    case Log::Status::SUCCESS: {
      std::cout << "\nSUCCESS: [" << Msg << "]\n\n";
      break;
    }
  }
}

void Buffer(std::istream &is) {
  const bool StreamFailed = is.fail();
  is.clear();
  is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  if (StreamFailed) throw Exception(Log::Status::ERROR, "STREAM FAILED");
  return;
}

void ValidateInt(short int &num, const char* Prefix) {
  bool Validated = false;
  do {
    try {
      std::cout << Prefix;
      std::cin >> num;
      Buffer(std::cin);
      Validated = true;
    } catch (const Exception &ex) {
      Log(ex.GetLogStatus(), ex.GetMsg());
    }
  } while (!Validated);
}

void ValidateChar(char &c, const char* Prefix) {
  bool Validated = false;
  do {
    try {
      std::cout << Prefix;
      std::cin.get(c);
      Buffer(std::cin);
      if (toupper(c) != 'Y' && toupper(c) != 'N') {
        throw Exception(Log::Status::WARNING, "INVALID REQUEST");
      }
      Validated = true;
    } catch (const Exception &ex) {
      Log(ex.GetLogStatus(), ex.GetMsg());
    }
  } while (!Validated);
}
}  // namespace Utility

Exception::Exception(const Log::Status &LogStatus, const std::string &Msg)
    : LogStatus_(LogStatus), Msg_(Msg) {}
Exception::~Exception() {}

Log::Status Exception::GetLogStatus() const { return this->LogStatus_; }
std::string Exception::GetMsg() const { return this->Msg_; }