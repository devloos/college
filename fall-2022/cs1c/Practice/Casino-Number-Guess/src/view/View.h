#ifndef VIEW_H_
#define VIEW_H_
#include <unistd.h>

#include <array>
#include <iostream>

#include "../color/Color.h"
#include "../utility/Utility.h"
#include "Game.h"

#define PLAY 1
#define QUIT 2

namespace View {
void Header();
void Menu();
void Winner();
void Loser();
}  // namespace View

#endif  // VIEW_H_