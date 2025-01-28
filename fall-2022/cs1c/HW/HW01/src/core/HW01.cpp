#include "HW01.h"

namespace Application {
void Start() {
  Membership NewMembership;
  short int Choice = EXIT;

  do {
    Menu::Primary(Choice);
    switch (Choice) {
      case EXIT: {
        return;
      }
      case INFO: {
        Print::Info();
        break;
      }
      case RUN: {
        Menu::Questionare(NewMembership);
        const std::pair<double, double> Totals = DetermineCost(NewMembership);

        Menu::Purchase(Totals);
        break;
      }
      default: {
        Utility::Log(Log::Status::WARNING, "INVALID INPUT RANGE");
        break;
      }
    }
  } while (Choice != EXIT);

  return;
}
}  // namespace Application