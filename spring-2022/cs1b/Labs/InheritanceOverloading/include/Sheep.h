#ifndef SHEEP_H_
#define SHEEP_H_
#include "Animal.h"
#include <map>

enum WoolType { kLong = 0, kMedium, kFine, kCarpet };
enum WoolColor { kWhite = 0, kBlack };

class Sheep : public Animal {
 public:
  Sheep();
  Sheep(const std::string &name, const unsigned int &age,
        const WoolType &woolType, const WoolColor &woolColor);
  ~Sheep() {}
  // Getters
  WoolType getWoolType() const;
  WoolColor getWoolColor() const;
  // Setters
  void setWoolType(const WoolType &woolType);
  void setWoolColor(const WoolColor &woolColor);
  // Methods
  void print() const;
 private:
  WoolType m_WoolType;
  WoolColor m_WoolColor;
  std::map<WoolType, std::string> WoolKeyPair;
  std::map<WoolColor, std::string> WoolColorKeyPair;
};

#endif // SHEEP_H_