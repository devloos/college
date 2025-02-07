#include "deck.h"

#include <cstdlib>
#include <iostream>

#include "card.h"

Deck::Deck() {
  this->dealtIdx = 0;

  for (int suitIdx = 0; suitIdx < NUMBER_OF_SUITS; ++suitIdx) {
    for (int rankIdx = 0; rankIdx < NUMBER_OF_RANKS; ++rankIdx) {
      // number of ranks determine offset, suitIdx determine how big
      // the offset will be
      const int index = suitIdx * NUMBER_OF_RANKS + rankIdx;
      this->deck[index] = Card(SUITS[suitIdx], RANKS[rankIdx]);
    }
  }
}

Card Deck::deal() { return this->deck[this->dealtIdx++]; }

void Deck::displayDeck() {
  for (int suitIdx = 0; suitIdx < NUMBER_OF_SUITS; ++suitIdx) {
    for (int rankIdx = 0; rankIdx < NUMBER_OF_RANKS; ++rankIdx) {
      // number of ranks determine offset, suitIdx determine how big
      // the offset will be
      const int index = suitIdx * NUMBER_OF_RANKS + rankIdx;
      this->deck[index].displayCard();

      if (rankIdx < 13) {
        std::cout << ',';
      }
    }
    std::cout << '\n';
  }
}

// O(n)
void Deck::shuffle() {
  std::srand(std::time(0));

  for (int i = 0; i < NUMBER_OF_CARDS; ++i) {
    // grab new index using i as an increment to skip previous cards
    int newIndex = rand() % (NUMBER_OF_CARDS - i + 1);

    // perform swap
    Card temp = this->deck[i];
    this->deck[i] = this->deck[newIndex];
    this->deck[newIndex] = temp;
  }
}