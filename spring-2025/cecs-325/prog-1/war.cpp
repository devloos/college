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
  Player firstPlayer;
  Player secondPlayer;

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

    if (firstPlayer.currentCard.compareCard(secondPlayer.currentCard) ==
        WON_GAME) {
      // if first player won
      std::cout << secondPlayer.name << "=> Winner";
    } else if (firstPlayer.currentCard.compareCard(secondPlayer.currentCard) ==
               TIE_GAME) {
      // if tie game
      std::cout << "Tie game";
    } else {
      // if second player won
      std::cout << secondPlayer.name << "=> Winner";
    }

    std::cout << "\n\n";
  }

  std::cout << "------Final Stats-------\n";
  std::cout << firstPlayer.name << " vs. " << secondPlayer.name << '\n';
  // std::cout << Wins 14 10 Losses 10 14 Ties 2 2
}
