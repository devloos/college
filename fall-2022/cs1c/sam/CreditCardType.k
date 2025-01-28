#include "CreditCardType.h"
#include <iostream>

using namespace std;

int CreditCardType::count = 0;

CreditCardType::CreditCardType() 
{
    count++;
    totalPurchases = 0;
    creditLimit = 0; // Initialize creditLimit within the constructor
}

CreditCardType::CreditCardType(const string cardNumber, const string nameOnCard, const string expiration) 
{
    this->cardNumber = cardNumber;
    this->nameOnCard = nameOnCard;
    this->expiration = expiration;
    balance = 0;
    totalPurchases = 0;
    count++;
    creditLimit = 0; // Initialize creditLimit within the constructor
}

void CreditCardType::setCardNumber( string cardNumber) 
{
    this->cardNumber = cardNumber;
    return;
}

void CreditCardType::setNameOnCard( string nameOnCard) 
{
    this->nameOnCard = nameOnCard;
    return;
}

void CreditCardType::setExpiration( string expiration) 
{
    this->expiration = expiration;
    return;
}

void CreditCardType::setCreditLimit(float creditLimit) 
{
    this->creditLimit = creditLimit;
    return;
}

string CreditCardType::getCardNumber() const 
{
    return cardNumber;
}

string CreditCardType::getNameOnCard() const 
{
    return nameOnCard;
}

string CreditCardType::getExpiration() const 
{
    return expiration;
}

float CreditCardType::getBalance() const 
{
    return balance;
}

float CreditCardType::getCreditLimit() const 
{
    return creditLimit;
}

void CreditCardType::print() const 
{
    cout << "Card Number: " << cardNumber << endl;
    cout << "Name on Card: " << nameOnCard << endl;
    cout << "Expiration: " << expiration << endl;
    cout << "Balance: $" << balance << endl;
    cout << "Total Purchases: $" << totalPurchases << endl;
}

bool CreditCardType::equals(const CreditCardType& other) const 
{
    return (cardNumber == other.cardNumber);
}

bool CreditCardType::purchase(float amount) 
{
    if (balance + amount <= creditLimit) {
        balance += amount;
        totalPurchases += amount;
        return true;
    }
    return false;
}

int CreditCardType::getCount() 
{
    return count;
}