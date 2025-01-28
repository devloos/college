#ifndef MENU_H_
#define MENU_H_
#include <iomanip>
#include <iostream>
#include <utility>

#include "../membership/Membership.h"
#include "../utility/Utility.h"

namespace Menu {
/**
 * @brief Display main menu and take user input
 *
 * @param Choice
 */
void Primary(short int &Choice);

/**
 * @brief All three questions required by Assignment
 *
 * @param NewMembership
 */
void Questionare(Membership &NewMembership);

/**
 * @brief Display final totals nothing done with input
 *
 * @param Totals
 */
void Purchase(const std::pair<double, double> &Totals);
}  // namespace Menu

#endif  // MENU_H_