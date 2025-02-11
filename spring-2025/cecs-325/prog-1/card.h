// Name: Carlos Aguilera
// Class CECS 325-02
// Project Name Prog 1 – Card War
// Due Date 02/11/2025
//
// I certify that this program is my own original work. I did not copy any part
// of this program from any other source. I further certify that I typed each
// and every line of code in this program.

#ifndef CARD_H
#define CARD_H

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