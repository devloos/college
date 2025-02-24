// Name: Carlos Aguilera
// Class CECS 325-02
// Project Name Prog 2 – More Card War
// Due Date 02/23/2025
//
// I certify that this program is my own original work. I did not copy any part
// of this program from any other source. I further certify that I typed each
// and every line of code in this program.

#include <algorithm>
#include <array>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

const int WON_GAME = 1;
const int TIE_GAME = 0;

const std::array<char, 4> SUITS = {'C', 'S', 'D', 'H'};
const std::array<char, 13> RANKS = {'A', '2', '3', '4', '5', '6', '7',
                                    '8', '9', 'X', 'J', 'Q', 'K'};

class Card {
 public:
  Card(char suit, char rank) {
    this->suit = suit;
    this->rank = rank;
  }

  void displayCard() const { std::cout << rank << suit; }

  int compareCard(const Card& other) const {
    int thisRankNum = 0;
    int otherRankNum = 0;

    for (int i = 0; i < RANKS.size(); ++i) {
      if (rank == RANKS[i]) {
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

 private:
  char suit;
  char rank;
};

struct Player {
  std::string name;
  Card currentCard;
  int wins;
  int losses;
  int ties;
};

class Deck {
 public:
  Deck() {
    for (char suit : SUITS) {
      for (char rank : RANKS) {
        deck.push_back(Card(suit, rank));
      }
    }
  }

  Card deal() {
    if (deck.size() == 0) {
      throw "Error - Deck is empty";
    }

    Card temp = deck.back();
    deck.pop_back();
    return temp;
  }

  void displayDeck() {
    for (int i = 0; i < deck.size(); ++i) {
      deck[i].displayCard();

      if ((i + 1) % 13 == 0) {
        std::cout << '\n';
      } else {
        std::cout << ',';
      }
    }
  }

  void shuffle() {
    std::srand(std::time(0));

    for (int i = 0; i < deck.size(); ++i) {
      // grab new index using i as an increment to skip previous cards
      int newIndex = rand() % (deck.size() - i + 1);

      // perform swap
      Card temp = deck[i];
      deck[i] = deck[newIndex];
      deck[newIndex] = temp;
    }
  }

 private:
  std::vector<Card> deck;
};

int main() {
  Player firstPlayer = {"Player 1", Card(), 0, 0, 0};
  Player secondPlayer = {"Player 1", Card(), 0, 0, 0};

  std::cout << "Enter the name of the first player: ";
  std::getline(std::cin, firstPlayer.name);

  std::cout << "Enter the name of the second player: ";
  std::getline(std::cin, secondPlayer.name);

  int numberOfGames = 0;

  std::cout << "How many games will they play? ";
  std::cin >> numberOfGames;

  Deck deck;

  std::cout << '\n';

  std::cout << "Original Deck\n";
  deck.displayDeck();

  deck.shuffle();

  std::cout << '\n';

  std::cout << "Shuffled Deck\n";
  deck.displayDeck();

  std::cout << '\n';

  try {
    for (int i = 0; i < numberOfGames; ++i) {
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
  } catch (const char* message) {
    std::cout << message << "\n\n";
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
