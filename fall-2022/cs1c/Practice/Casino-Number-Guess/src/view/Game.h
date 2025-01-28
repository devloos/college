#ifndef GAME_H_
#define GAME_H_
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include <iomanip>
#include <iostream>
#include <vector>

#include "../utility/Utility.h"
#include "View.h"

namespace Game {
const short int FIRST_TRY = 1;
const int THREE_SECONDS = 3000000;

/**
 * @brief
 *
 */
void Start();

/**
 * @brief
 *
 */
void Draw(const std::vector<short int> &NumbersGuessed);

/**
 * @brief
 *
 * @param num
 * @param NumbersGuessed
 */
void Input(short int &num, std::vector<short int> &NumbersGuessed);

/**
 * @brief
 *
 * @param NumInput
 * @param GameOver
 */
void Logic(const short int &NumInput, const short int &WINNING_NUMBER, bool &GameOver);
}  // namespace Game

#endif  // GAME_H_