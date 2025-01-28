#include "Address.h"

Address &Address::operator=(const Address &rhs) {
  if (this == &rhs) {
    return *this;
  }

  this->setStreet(rhs.street_);
  this->setCity(rhs.city_);
  this->setState(rhs.state_);
  this->setZip(rhs.zip_);

  return *this;
}

std::string Address::getFullAddress() const {
  return this->street_ + " " + this->city_ + " " + this->state_ + " " +
         std::to_string(this->zip_);
}

void Address::setStreet(const std::string &street) {
  this->street_ = street;
}

std::string Address::getStreet() const {
  return this->street_;
}

void Address::setCity(const std::string &city) {
  this->city_ = city;
}

std::string Address::getCity() const {
  return this->city_;
}

void Address::setState(const std::string &state) {
  this->state_ = state;
}

std::string Address::getState() const {
  return this->state_;
}

void Address::setZip(const int &zip) {
  this->zip_ = zip;
}

int Address::getZip() const {
  return this->zip_;
}

void Address::print() const {
  std::cout << "Address: " << this->getFullAddress() << "\n";
}