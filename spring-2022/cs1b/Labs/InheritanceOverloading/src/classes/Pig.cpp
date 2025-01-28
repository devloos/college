#include "../../include/Pig.h"

// Constructors
Pig::Pig() : Pig("", 0, kStraight) {}
Pig::Pig(const std::string &name, const unsigned int &age, const TailType &tailType)
    : Animal(name, age), m_TailType(tailType) {
  TailKeyPair[kStraight] = ("Straight");
  TailKeyPair[kCorkscrew] = ("Corkscrew");
  TailKeyPair[kCurlUp] = ("Curl Up");
  TailKeyPair[kCurlRight] = ("Curl Right");
  TailKeyPair[kCurlLeft] = ("Curl Left");
}
// Setters
void Pig::setTailType(const TailType &tailType) { m_TailType = tailType; }
// Getters
TailType Pig::getTailType() const { return m_TailType; }

void Pig::print() const {
  Animal::print();
  std::cout << std::setw(10) << TailKeyPair.at(m_TailType);
}