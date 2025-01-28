#include "../../include/Livestock.h"
#include <fstream>

bool attributesValidated(std::string &errorCode, const unsigned int &age,
                         const std::string &tailType);

void LogValidationError(const std::string &errorCode, const std::string &name,
                        const unsigned int &age, const std::string &tailType);

void initPigs(Livestock &livestock) {
  std::map<std::string, TailType> StringToTailType = {
    {"Straight", kStraight},
    {"Corkscrew", kCorkscrew},
    {"Curl Up", kCurlUp},
    {"Curl Right", kCurlRight},
    {"Curl Left", kCurlLeft}
  };
  std::string name;
  unsigned int age;
  std::string tailType;
  std::string errorCode;
  std::fstream fin("Pig.txt", std::ios::in);

  if (fin.is_open()) {
    while (!fin.eof()) {
      std::getline(fin, name);
      fin >> age;
      if (fin.fail()) {
        fin.clear();
        age = -1;
      }
      fin.ignore(1000, '\n');
      std::getline(fin, tailType);
      fin.ignore(1000, '\n');

      if (!attributesValidated(errorCode, age, tailType)) {
        LogValidationError(errorCode, name, age, tailType);
        continue;
      }
      livestock.m_PigLivestock.push_back(
        std::move(Pig(name, age, StringToTailType[tailType])));
    }
  } else {
    std::cerr << "ERROR: [Opening Pig.txt]\n";
  }
  fin.close();
}

bool attributesValidated(std::string &errorCode, const unsigned int &age,
                         const std::string &tailType) {
  if (age < 0 || age > 10) {
    errorCode = "[Invalid Age]";
    return false;
  }
  if (!(tailType == "Straight" || tailType == "Corkscrew" || tailType == "Curl Up" || 
        tailType == "Curl Right" || tailType == "Curl Left")) {
    errorCode = "[Invalid TailType]";
    return false;
  }
  return true;
}

void LogValidationError(const std::string &errorCode, const std::string &name,
                        const unsigned int &age, const std::string &tailType) {
  std::cout << std::left;
  std::cout << "\nERROR CODE: " << errorCode << "\n";
  std::cout << std::setw(10) << "Name:" << name << "\n";
  std::cout << std::setw(10) << "Age:" << age << "\n";
  std::cout << std::setw(10) << "TailType:" << tailType << "\n";
  std::cout << "[Initialization failed on this Pig]\n";
  std::cout << std::right;
}