// Name: Carlos Aguilera
// Class CECS 325-02
// Project Name Prog 1 – Card War
// Due Date 02/11/2025
//
// I certify that this program is my own original work. I did not copy any part
// of this program from any other source. I further certify that I typed each
// and every line of code in this program.

#include <iomanip>
#include <iostream>
#include <string>

#include "deck.h"

const int WON_GAME = 1;
const int TIE_GAME = 0;

struct Player {
  std::string name;
  Card currentCard;
  int wins;
  int losses;
  int ties;
};

int main() {
  Player firstPlayer = {"Player 1", Card(), 0, 0, 0};
  Player secondPlayer = {"Player 1", Card(), 0, 0, 0};

  std::cout << "Enter the name of the first player: ";
  std::getline(std::cin, firstPlayer.name);

  std::cout << "Enter the name of the second player: ";
  std::getline(std::cin, secondPlayer.name);

  Deck deck;

  std::cout << '\n';

  std::cout << "Original Deck\n";
  deck.displayDeck();

  deck.shuffle();

  std::cout << '\n';

  std::cout << "Shuffled Deck\n";
  deck.displayDeck();

  std::cout << '\n';

  for (int i = 0; i < NUMBER_OF_CARDS / 2; ++i) {
    firstPlayer.currentCard = deck.deal();
    secondPlayer.currentCard = deck.deal();

    std::cout << "Game " << i + 1 << '\n';
    std::cout << "--------" << '\n';

    std::cout << firstPlayer.name << "=>";
    firstPlayer.currentCard.displayCard();
    std::cout << '\n';

    std::cout << secondPlayer.name << "=>";
    secondPlayer.currentCard.displayCard();
    std::cout << '\n';

    const int firstPlayerResult =
        firstPlayer.currentCard.compareCard(secondPlayer.currentCard);

    if (firstPlayerResult == WON_GAME) {
      std::cout << firstPlayer.name << "=> Winner";

      ++firstPlayer.wins;
      ++secondPlayer.losses;
    } else if (firstPlayerResult == TIE_GAME) {
      std::cout << "Tie game";

      ++firstPlayer.ties;
      ++secondPlayer.ties;
    } else {
      std::cout << secondPlayer.name << "=> Winner";

      ++firstPlayer.losses;
      ++secondPlayer.wins;
    }

    std::cout << "\n\n";
  }

  // is there a better way to manipulate text this is absolutely HORRIBLE
  std::cout << "------Final Stats-------\n";
  std::cout << std::setw(7 + firstPlayer.name.length()) << firstPlayer.name
            << " vs. " << secondPlayer.name << '\n';

  std::cout << std::left << std::setw(7) << "Wins " << firstPlayer.wins;

  std::cout << std::right << std::setw(5 + firstPlayer.name.length())
            << secondPlayer.wins << '\n';

  std::cout << std::left << std::setw(7) << "Losses " << firstPlayer.losses;

  std::cout << std::right << std::setw(5 + firstPlayer.name.length())
            << secondPlayer.losses << '\n';

  std::cout << std::left << std::setw(7) << "Ties " << firstPlayer.ties;

  std::cout << std::right << std::setw(5 + firstPlayer.name.length())
            << secondPlayer.ties << '\n';
}
