#ifndef DECK_H
#define DECK_H
#include "card.h"

const int NUMBER_OF_CARDS = 52;
const int NUMBER_OF_SUITS = 4;
const int NUMBER_OF_RANKS = 13;

const char SUITS[] = {'C', 'S', 'D', 'H'};
const char RANKS[] = {'A', '2', '3', '4', '5', '6', '7',
                      '8', '9', 'X', 'J', 'Q', 'K'};

class Deck {
 public:
  Deck();

  Card deal();

  void displayDeck();

  void shuffle();

 private:
  Card deck[NUMBER_OF_CARDS];
  int dealtIdx;
};

#endif