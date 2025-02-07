#ifndef CARD_H
#define CARD_H
#include <unordered_map>

class Card {
 public:
  Card();

  Card(char suit, char rank);

  void displayCard() const;

  int compareCard(const Card &other) const;

 private:
  char suit;
  char rank;
};

#endif