#include "../../include/Sheep.h"

// Constructors
Sheep::Sheep() : Sheep("", 0, kLong, kWhite) {}
Sheep::Sheep(const std::string &name, const unsigned int &age,
             const WoolType &woolType, const WoolColor &woolColor)
    : Animal::Animal(name, age), m_WoolType(woolType), m_WoolColor(woolColor) {
  WoolKeyPair[kLong] = ("Long");
  WoolKeyPair[kMedium] = ("Medium");
  WoolKeyPair[kFine] = ("Fine");
  WoolKeyPair[kCarpet] = ("Carpet");
  WoolColorKeyPair[kWhite] = ("White");
  WoolColorKeyPair[kBlack] = ("Black");
}
// Getters
WoolType Sheep::getWoolType() const { return m_WoolType; }
WoolColor Sheep::getWoolColor() const { return m_WoolColor; }
// Setters
void Sheep::setWoolType(const WoolType &woolType) { m_WoolType = woolType; }
void Sheep::setWoolColor(const WoolColor &woolColor) { m_WoolColor = woolColor; }
// Methods
void Sheep::print() const {
  Animal::print();
  std::cout << std::setw(10) << WoolKeyPair.at(m_WoolType) << std::setw(5) << WoolColorKeyPair.at(m_WoolColor);
}