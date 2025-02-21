// Name: Carlos Aguilera
// Class CECS 325-02
// Project Name Prog 1 – Card War
// Due Date 02/11/2025
//
// I certify that this program is my own original work. I did not copy any part
// of this program from any other source. I further certify that I typed each
// and every line of code in this program.

#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

const int WON_GAME = 1;
const int TIE_GAME = 0;

const int NUMBER_OF_CARDS = 52;
const int NUMBER_OF_SUITS = 4;
const int NUMBER_OF_RANKS = 13;

const char SUITS[] = {'C', 'S', 'D', 'H'};
const char RANKS[] = {'A', '2', '3', '4', '5', '6', '7',
                      '8', '9', 'X', 'J', 'Q', 'K'};

class Card {
 public:
  Card() {
    this->suit = 'X';
    this->rank = 'X';
  }

  Card(char suit, char rank) {
    this->suit = suit;
    this->rank = rank;
  }

  void displayCard() const {
    if (this->rank == 'X') {
      std::cout << "10" << this->suit;
    } else {
      std::cout << this->rank << this->suit;
    }
  }

  int compareCard(const Card &other) const {
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
    for (int suitIdx = 0; suitIdx < NUMBER_OF_SUITS; ++suitIdx) {
      for (int rankIdx = 0; rankIdx < NUMBER_OF_RANKS; ++rankIdx) {
        this->deck.push_back(Card(SUITS[suitIdx], RANKS[rankIdx]));
      }
    }
  }

  Card deal() {
    Card temp = this->deck.back();
    this->deck.pop_back();
    return temp;
  }

  void displayDeck() {
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

  void shuffle() {
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
