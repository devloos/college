#include "DetCost.h"

std::pair<double, double> DetermineCost(const Membership &NewMembership) {
  const double MONTHLY_BASE_PRICE = 100.0f;
  const double TRAINING_BASE_PRICE_PER_SESSION = 20.0f;
  const double FIFTEEN_PERCENT = .15f;
  const double TWENTY_PERCENT = .20f;
  const double THIRTY_PERCENT = .30f;
  double TodaysTotal = MONTHLY_BASE_PRICE * NewMembership.MonthsUpFront_;
  double MonthlyTotal = MONTHLY_BASE_PRICE;
  double Discount = 0.0f;

  // MONTHS UP FRONT
  if (NewMembership.MonthsUpFront_ >= 12) {
    Discount += TodaysTotal * FIFTEEN_PERCENT;
  }

  // TRAINING
  if (NewMembership.PersonalTrainingsUpFront_ >= 5) {
    // e.g. 20 * .20 = 4
    // e.g. 4 * 5 = 20
    Discount += (TRAINING_BASE_PRICE_PER_SESSION * TWENTY_PERCENT) *
                NewMembership.PersonalTrainingsUpFront_;
  }
  TodaysTotal +=
      NewMembership.PersonalTrainingsUpFront_ * TRAINING_BASE_PRICE_PER_SESSION;

  // SENIOR CITIZEN
  if (NewMembership.isSeniorCitizen_) {
    Discount += TodaysTotal * THIRTY_PERCENT;
    MonthlyTotal -= (MONTHLY_BASE_PRICE * THIRTY_PERCENT);
  }

  TodaysTotal -= Discount;

  return std::make_pair(TodaysTotal, MonthlyTotal);
}