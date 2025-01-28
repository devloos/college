#include <iostream>

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
CreditCardType() 
{
    count++;
    totalPurchases = 0;
    creditLimit = 0; // Initialize creditLimit within the constructor
}

CreditCardType(const string cardNumber, const string nameOnCard, const string expiration) 
{
    this->cardNumber = cardNumber;
    this->nameOnCard = nameOnCard;
    this->expiration = expiration;
    balance = 0;
    totalPurchases = 0;
    count++;
    creditLimit = 0; // Initialize creditLimit within the constructor
}

void setCardNumber( string cardNumber) 
{
    this->cardNumber = cardNumber;
    return;
}

void setNameOnCard( string nameOnCard) 
{
    this->nameOnCard = nameOnCard;
    return;
}

void setExpiration( string expiration) 
{
    this->expiration = expiration;
    return;
}

void setCreditLimit(float creditLimit) 
{
    this->creditLimit = creditLimit;
    return;
}

string getCardNumber() const 
{
    return cardNumber;
}

string getNameOnCard() const 
{
    return nameOnCard;
}

string getExpiration() const 
{
    return expiration;
}

float getBalance() const 
{
    return balance;
}

float getCreditLimit() const 
{
    return creditLimit;
}

void print() const 
{
    cout << "Card Number: " << cardNumber << endl;
    cout << "Name on Card: " << nameOnCard << endl;
    cout << "Expiration: " << expiration << endl;
    cout << "Balance: $" << balance << endl;
    cout << "Total Purchases: $" << totalPurchases << endl;
}

bool equals(const CreditCardType& other) const 
{
    return (cardNumber == other.cardNumber);
}

bool purchase(float amount) 
{
    if (balance + amount <= creditLimit) {
        balance += amount;
        totalPurchases += amount;
        return true;
    }
    return false;
}

static int getCount() 
{
    return count;
}
};

int CreditCardType::count = 0;

void purchaseInfo(CreditCardType &card1, CreditCardType &card2, CreditCardType &card3)
{
    cout << "Number of Credit Cards: " << CreditCardType::getCount() << std::endl;

    // Make purchases with each card and print the balance after each purchase
    float purchaseAmount1 = 500.00;
    
    if (card1.purchase(purchaseAmount1)) 
    {
        cout << "Purchase successful. Card 1 Balance: $" << card1.getBalance() << endl;
    } 
    else 
    {
        cout << "Purchase declined. Card 1 Balance: $" << card1.getBalance() << endl;
    }

    float purchaseAmount2 = 5000.00;

    if (card2.purchase(purchaseAmount2)) 
    {
        cout << "Purchase successful. Card 2 Balance: $" << card2.getBalance() << endl;
    } 
    else 
    {
        cout << "Purchase declined. Card 2 Balance: $" << card2.getBalance() << endl;
    }

    float purchaseAmount3 = 20000.00;
    // float creditLimit(10000.00);

    if (card1.purchase(purchaseAmount3)) 
    {
        cout << "Purchase successful. Card 3 Balance: $" << card3.getBalance() << endl;
    } 
    else 
    {
        cout << "Purchase declined. Card 3 Balance: $" << card3.getBalance() << endl;
    }
}

int main() 
{
  CreditCardType card1("1234 5678 1234 5678", "Cristiano Messi", "12/24");
  CreditCardType card2("4321 8765 4321 8765", "Lionel Ronaldo", "11/23");
  CreditCardType card3("1234 8765 4321 8765", "LaBall James", "10/22");


  purchaseInfo(card1, card2, card3);
  card1.print();
  card2.print();
  card3.print();

  return 0;
}