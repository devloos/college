#include "../../include/Livestock.h"
#include <fstream>
#include <map>

bool attributesValidated(std::string &errorCode, const unsigned int &age,
                         const std::string &woolType, const std::string &woolColor);

void LogValidationError(const std::string &errorCode, const std::string &name,
                        const unsigned int &age, const std::string &woolType,
                        const std::string &woolColor);

void initSheeps(Livestock &livestock) {
  std::map<std::string, WoolType> StringToWoolType = {
    {"Long", kLong},
    {"Medium", kMedium},
    {"Fine", kFine},
    {"Carpet", kCarpet}
  };
  std::map<std::string, WoolColor> StringToWoolColor= {
    {"White", kWhite},
    {"Black", kBlack}
  };
  std::string name;
  unsigned int age;
  std::string woolType;
  std::string woolColor;
  std::string errorCode;
  std::fstream fin("Sheep.txt", std::ios::in);

  if (fin.is_open()) {
    while (!fin.eof()) {
      std::getline(fin, name);
      fin >> age;
      if (fin.fail()) {
        fin.clear();
        age = -1;
      }
      fin.ignore(1000, '\n');
      std::getline(fin, woolType);
      std::getline(fin, woolColor);
      fin.ignore(1000, '\n');

      if (!attributesValidated(errorCode, age, woolType, woolColor)) {
        LogValidationError(errorCode, name, age, woolType, woolColor);
        continue;
      }
      livestock.m_SheepLivestock.push_back(
        std::move(Sheep(name, age, StringToWoolType[woolType],
        StringToWoolColor[woolColor])));
    }
  } else {
    std::cerr << "ERROR: [Opening Sheep.txt]\n";
  }
  fin.close();
}

bool attributesValidated(std::string &errorCode, const unsigned int &age,
                         const std::string &woolType, const std::string &woolColor) {
  if (age < 0 || age > 10) {
    errorCode = "[Invalid Age]";
    return false;
  }
  if (!(woolType == "Long" || woolType == "Medium" || woolType == "Fine" || 
        woolType == "Carpet")) {
    errorCode = "[Invalid WoolType]";
    return false;
  }
  if (!(woolColor == "Black" || woolColor == "White")) {
    errorCode = "[Invalid WoolColor]";
    return false;
  }
  return true;
}

void LogValidationError(const std::string &errorCode, const std::string &name,
                        const unsigned int &age, const std::string &woolType,
                        const std::string &woolColor) {
  std::cout << std::left;
  std::cout << "\nERROR CODE: " << errorCode << "\n";
  std::cout << std::setw(11) << "Name:" << name << "\n";
  std::cout << std::setw(11) << "Age:" << age << "\n";
  std::cout << std::setw(11) << "WoolType:" << woolType << "\n";
  std::cout << std::setw(11) << "WoolColor:" << woolColor << "\n";
  std::cout << "[Initialization failed on this Sheep]\n";
  std::cout << std::right;
}
