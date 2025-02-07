#include "card.h"

#include <iostream>

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
  static const std::unordered_map<char, int> RANK_MAPPINGS = {
      {'A', 1},
  };
  return -1;
}