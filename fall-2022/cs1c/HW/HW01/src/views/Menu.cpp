#include "Menu.h"

namespace Menu {
void Primary(short int &Choice) {
  std::cout << "\033[" << 34 << "m"
            << "\n\nCARLOS 24 HOUR FITNESS\n";
  std::cout << "\033[" << 39 << "m";
  std::cout << "----------------------\n";
  std::cout << std::setw(16) << "Info [1]\n"
            << std::setw(21) << "Decide Options [2]\n"
            << std::setw(17) << "Leave [0]\n\n";
  Utility::ValidateInt(Choice, "ENTER #: ");
}

void Questionare(Membership &NewMembership) {
  bool inRange = false;
  char isSeniorCitizen;
  short int UpFrontMonths;
  short int UpFrontTraining;

  // Question #1
  std::cout << "\n\n";
  std::cout << "\033[" << 34 << "m";
  std::cout << std::setw(23) << "QUESTIONARE\n";
  std::cout << "\033[" << 39 << "m"
            << "-----------------------------------\n";
  Utility::ValidateChar(isSeniorCitizen, "* Are you a Senior Citizen [Y/N]: ");
  if (toupper(isSeniorCitizen) == 'Y') {
    NewMembership.isSeniorCitizen_ = true;
  } else {
    NewMembership.isSeniorCitizen_ = false;
  }

  // Question #2
  do {
    std::cout << "\n\n";
    std::cout << "\033[" << 34 << "m";
    std::cout << std::setw(31) << "QUESTIONARE\n";
    std::cout << "\033[" << 39 << "m"
              << "----------------------------------------------------\n";
    Utility::ValidateInt(
        UpFrontMonths, "* How many months upfront will you pay [NUMBER]: ");
    if (UpFrontMonths < 1) {
      Utility::Log(Log::Status::WARNING, "INVALID RANGE");
      continue;
    }
    // Once in range
    NewMembership.MonthsUpFront_ = UpFrontMonths;
    inRange = true;
  } while (!inRange);

  // Question #3
  std::cout << "\n\n";
  std::cout << "\033[" << 34 << "m";
  std::cout << std::setw(41) << "QUESTIONARE\n";
  std::cout
      << "\033[" << 39 << "m"
      << "-----------------------------------------------------------------------\n";
  Utility::ValidateInt(
      UpFrontTraining,
      "* How many Personal Training Sessions upfront will you pay [NUMBER]: ");
  NewMembership.PersonalTrainingsUpFront_ = UpFrontTraining;

  return;
}

void Purchase(const std::pair<double, double> &Totals) {
  std::cout << "\n\n";
  std::cout << "\033[" << 34 << "m";
  std::cout << std::setw(17) << "PURCHASE\n";
  std::cout << "\033[" << 39 << "m"
            << "------------------------\n"
            << "* TOTAL TODAY: $" << Totals.first << "\n"
            << "* MONTHLY TOTAL: $" << Totals.second << "\n"
            << "* PURCHASE? [Y/N]: ";
  std::cin.get();
  std::cin.clear();
}
}  // namespace Menu