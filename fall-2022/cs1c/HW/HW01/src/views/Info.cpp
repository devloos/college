#include "Info.h"

namespace Print {
void Info() {
  std::cout << std::endl << std::endl;
  std::cout << "\033[" << 34 << "m";
  std::cout << std::setw(32) << "MEMBERSHIP INFO\n";
  std::cout << "\033[" << 39 << "m"
            << "------------------------------------------------\n"
            << "* MONTHLY BASE PRICE FOR MEMBERSHIP: $100\n\n"
            << "* PERSONAL TRAINING BASE PRICE PER SESSION: $20\n\n"
            << "* Senior Citizens get 30% OFF\n\n"
            << "* Pay 12 or more months upfront and get 15% OFF\n\n"
            << "* More than five personal trainings paid upfront\n"
            << "and get 20% OFF \"per session\"\n\n";

  std::cout << "ENTER ANY KEY TO GO BACK: ";
  std::cin.get();
  std::cin.clear();
}
}  // namespace Print