#ifndef DETCOST_H_
#define DETCOST_H_
#include <utility>

#include "../membership/Membership.h"

/**
 * @brief Logic for determining totals
 *
 * @param NewMembership
 * @return std::pair<double, double>
 */
std::pair<double, double> DetermineCost(const Membership &NewMembership);

#endif  // DETCOST_H_