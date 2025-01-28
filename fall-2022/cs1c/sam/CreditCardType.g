#ifndef CREDITCARDTYPE_H
#define CREDITCARDTYPE_H

#include <string>

using namespace std;

class CreditCardType {

private:
  string cardNumber;
  string nameOnCard;
  string expiration;

  // Static vars
  static float balance;
  static float creditLimit;
  static int count;
  float totalPurchases;

public:
  // Constructors
  CreditCardType();
  CreditCardType(const string cardNumber, const string nameOnCard,
                 const string expiration);

  // Setters
  void setCardNumber(string cardNumber);
  void setNameOnCard(string nameOnCard);
  void setExpiration(string expiration);
  void setCreditLimit(float creditLimit);

  // Getters
  string getCardNumber() const;
  string getNameOnCard() const;
  string getExpiration() const;
  float getBalance() const;
  float getCreditLimit() const;

  // Public Functions
  void print() const;
  bool equals(const CreditCardType &other) const;
  bool purchase(float amount);

  // Static Functions
  static int getCount();
};

#endif
