#include "hw06.h"

Vector2::Vector2() : num_(0), den_(-1) {}
Vector2::Vector2(const int &num, const int &den) : num_(num), den_(den) {}

Fraction::Fraction() : num_(0), den_(-1) {}
Fraction::Fraction(const int &num, const int den) : num_(num), den_(den) {
  if (den_ == 0) {
    throw Exception("Can't divide by zero.", Exception::Level::ERROR);
  }

  setGCD();
}

Fraction::~Fraction() noexcept {}

Vector2 Fraction::parse(std::string &dirty) {
  size_t index = dirty.find('/');
  if (index == dirty.npos) {
    throw Exception("Invalid fraction format.", Exception::Level::ERROR);
  }

  int num = std::stoi(dirty.substr(0, index));
  int den = std::stoi(dirty.substr(index + 1));

  return Vector2(num, den);
}

void Fraction::setGCD() {
  int gcd = std::gcd(num_, den_);
  if (gcd != 0) {
    num_ /= gcd;
    den_ /= gcd;
  }
}

void Fraction::setFrac(const int &num, const int &den) {
  if (den == 0) {
    throw Exception("Can't divide by zero.", Exception::Level::ERROR);
  }

  num_ = num;
  den_ = den;
  setGCD();
}

Fraction Fraction::getFrac() const {
  return *this;
}

std::istream &operator>>(std::istream &is, Fraction &frac) {
  std::string input;
  try {
    is >> input;
    Vector2 clean = frac.parse(input);

    frac.setFrac(clean.num_, clean.den_);
  } catch (const Exception &e) {
    std::cout << e.what() << "\n";
    std::exit(EXIT_FAILURE);
  } catch (const std::invalid_argument &e) {
    std::cout << e.what() << "\n";
    std::exit(EXIT_FAILURE);
  } catch (const std::out_of_range &e) {
    std::cout << e.what() << "\n";
    std::exit(EXIT_FAILURE);
  }
  return is;
}

std::ostream &operator<<(std::ostream &os, const Fraction &frac) {
  os << frac.num_ << "/" << frac.den_;
  return os;
}

Fraction operator*(const Fraction &lhs, const Fraction &rhs) {
  return Fraction(lhs.num_ * rhs.num_, lhs.den_ * rhs.den_);
}

Fraction operator/(const Fraction &lhs, const Fraction &rhs) {
  return Fraction(lhs.num_ * rhs.den_, lhs.den_ * rhs.num_);
}

Fraction operator-(const Fraction &lhs, const Fraction &rhs) {
  Vector2 cp;
  cp.num_ = (lhs.num_ * rhs.den_) - (rhs.num_ * lhs.den_);
  cp.den_ = lhs.den_ * rhs.den_;

  return Fraction(cp.num_, cp.den_);
}

Fraction operator+(const Fraction &lhs, const Fraction &rhs) {
  Vector2 cp;
  cp.num_ = (lhs.num_ * rhs.den_) + (rhs.num_ * lhs.den_);
  cp.den_ = lhs.den_ * rhs.den_;

  return Fraction(cp.num_, cp.den_);
}

Fraction &Fraction::operator*=(const Fraction &rhs) {
  *this = *this * rhs;
  return *this;
}

Fraction &Fraction::operator/=(const Fraction &rhs) {
  *this = *this / rhs;
  return *this;
}

Fraction &Fraction::operator-=(const Fraction &rhs) {
  *this = *this - rhs;
  return *this;
}

Fraction &Fraction::operator+=(const Fraction &rhs) {
  *this = *this + rhs;
  return *this;
}

bool operator<(const Fraction &lhs, const Fraction &rhs) {
  return lhs.num_ * rhs.den_ < rhs.num_ * lhs.den_;
}

bool operator<=(const Fraction &lhs, const Fraction &rhs) {
  return lhs.num_ * rhs.den_ <= rhs.num_ * lhs.den_;
}
bool operator>(const Fraction &lhs, const Fraction &rhs) {
  return lhs.num_ * rhs.den_ > rhs.num_ * lhs.den_;
}

bool operator>=(const Fraction &lhs, const Fraction &rhs) {
  return lhs.num_ * rhs.den_ >= rhs.num_ * lhs.den_;
}

bool operator==(const Fraction &lhs, const Fraction &rhs) {
  return lhs.num_ * rhs.den_ == rhs.num_ * lhs.den_;
}

bool operator!=(const Fraction &lhs, const Fraction &rhs) {
  return lhs.num_ * rhs.den_ != rhs.num_ * lhs.den_;
}