#include "View.h"

// std::ostream &operator<<(std::ostream &os, const Color::Code &code) {
//   return os << "\033[" << code << "m";
// }

namespace View {
void Header() {
  std::array<Color::Code, 8> codes = {
      Color::Code::FG_RED,    Color::Code::FG_MAGENTA, Color::Code::FG_GREEN,
      Color::Code::FG_YELLOW, Color::Code::FG_WHITE,   Color::Code::FG_CYAN,
      Color::Code::FG_BLUE,   Color::Code::FG_DEFAULT,
  };
  for (int i = 0; i < codes.size(); i++) {
    system("clear");
    std::cout << "\033[" << int(codes[i]) << "m"
              << " __       __         __     __        __  __  __ \n"
              << "/    /\\  (_  | |\\ | /  \\   / _  /  \\ |_  (_  (_  \n"
              << "\\__ /--\\ __) | | \\| \\__/   \\__) \\__/ |__ __) __) \n";
    usleep(300000);
  }
}

void Menu() {
  system("clear");
  short int Choice = QUIT;
  Utility::Input::Validate(Choice, "Main Menu\nPlay [1]\nQuit [2]\n\nENTER #: ", 2, 1);
  switch (Choice) {
    case QUIT: {
      return;
    }
    case PLAY: {
      Game::Start();
      return;
    }
  }
}

void Winner() { std::cout << "YOU WON\n"; }

void Loser() { std::cout << "YOU LOST\n"; }
}  // namespace View