// Name: Carlos Aguilera
// Class CECS 325-02
// Project Name Prog 1 – Card War
// Due Date 02/11/2025
//
// I certify that this program is my own original work. I did not copy any part
// of this program from any other source. I further certify that I typed each
// and every line of code in this program.

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