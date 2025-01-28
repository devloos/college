#include "Game.h"

namespace Game {
void Start() {
  system("clear");
  srand(time(nullptr));
  const short int WINNING_NUMBER = rand() % 100 + 1;
  short int NumInput;
  unsigned int NumberOfGuesses;
  bool GameOver = false;
  std::vector<short int> NumbersGuessed;

  while (!GameOver) {
    Draw(NumbersGuessed);
    Input(NumInput, NumbersGuessed);
    Logic(NumInput, WINNING_NUMBER, GameOver);
    ++NumberOfGuesses;
  }

  if (NumberOfGuesses == FIRST_TRY) {
    View::Winner();
  } else {
    View::Loser();
  }
}

void Draw(const std::vector<short int> &NumbersGuessed) {
  system("clear");
  std::cout << "NUMBERS GUESSED: [";
  for (const auto &num : NumbersGuessed) {
    std::cout << num << ", ";
  }
  std::cout << "]\n";
  std::cout << "------------------" << std::setfill('-')
            << std::setw(NumbersGuessed.size() * 4) << '\n';
}

void Input(short int &num, std::vector<short int> &NumbersGuessed) {
  Utility::Input::Validate(num, "YOUR GUESS: ", 100, 1);
  NumbersGuessed.push_back(num);
}

void Logic(const short int &NumInput, const short int &WINNING_NUMBER, bool &GameOver) {
  if (NumInput == WINNING_NUMBER) {
    GameOver = true;
    return;
  }

  const short int OUTPUT_STATEMENT_RNG = rand() % 3 + 1;

  if (NumInput > WINNING_NUMBER) {
    switch (OUTPUT_STATEMENT_RNG) {
      case 1: {
        std::cout << "The number: " << NumInput << " was a bit to high\n\n";
        break;
      }
      case 2: {
        std::cout << "You are a highroller guess lower!\n\n";
        break;
      }
      case 3: {
        std::cout << "You could have won if you guessed lower try again though!\n\n";
        break;
      }
      default: {
        break;
      }
    }
  }

  if (NumInput < WINNING_NUMBER) {
    switch (OUTPUT_STATEMENT_RNG) {
      case 1: {
        std::cout << "The number: " << NumInput << " was a bit to low\n\n";
        break;
      }
      case 2: {
        std::cout << "You are lowballing me guess HIGHER!\n\n";
        break;
      }
      case 3: {
        std::cout << "You could have won if you guessed higher try again though!\n\n";
        break;
      }
      default: {
        break;
      }
    }
  }
  usleep(THREE_SECONDS);
}

}  // namespace Game