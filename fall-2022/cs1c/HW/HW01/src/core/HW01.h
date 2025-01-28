#ifndef HW01_H_
#define HW01_H_
#include <utility>

#include "../components/DetCost.h"
#include "../membership/Membership.h"
#include "../views/Info.h"
#include "../views/Menu.h"

namespace Application {
const short int EXIT = 0;
const short int INFO = 1;
const short int RUN = 2;
/**
 * @brief Start of the entire app
 *
 */
void Start();
}  // namespace Application

#endif  // HW01_H_