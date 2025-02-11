// Name: Carlos Aguilera
// Class CECS 325-02
// Project Name Prog 1 – Card War
// Due Date 02/11/2025
//
// I certify that this program is my own original work. I did not copy any part
// of this program from any other source. I further certify that I typed each
// and every line of code in this program.

#include "card.h"

#include <iostream>
#include <unordered_map>

#include "deck.h"

Card::Card() {
  this->suit = 'X';
  this->rank = 'X';
}

Card::Card(char suit, char rank) {
  this->suit = suit;
  this->rank = rank;
}

void Card::displayCard() const {
  if (this->rank == 'X') {
    std::cout << "10" << this->suit;
  } else {
    std::cout << this->rank << this->suit;
  }
}

int Card::compareCard(const Card &other) const {
  int thisRankNum = 0;
  int otherRankNum = 0;

  for (int i = 0; i < NUMBER_OF_RANKS; ++i) {
    if (this->rank == RANKS[i]) {
      thisRankNum = i;
    }

    if (other.rank == RANKS[i]) {
      otherRankNum = i;
    }
  }

  if (thisRankNum == otherRankNum) {
    return 0;
  }

  return thisRankNum > otherRankNum ? 1 : -1;
}