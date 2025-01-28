#include "hw10.h"

Ctors::Ctors() : id_(++idGen_s), tptr_(nullptr) {
  tptr_ = new std::string("<empty>");
  ++inst_s;

  std::cout << "default ctor: " << *this << "\n";
}

Ctors::Ctors(const std::string &value) : id_(++idGen_s) {
  tptr_ = new std::string(value);
  ++inst_s;

  std::cout << "ctor(" << value << "): " << *this << "\n";
}

Ctors::Ctors(std::string &&value) : id_(++idGen_s) {
  std::cout << "ctor(" << value << "): ";
  tptr_ = new std::string(std::move(value));
  ++inst_s;

  std::cout << *this << '\n';
}

Ctors::Ctors(const Ctors &other) {
  *this = other;
  ++inst_s;

  std::cout << "cctor(" << other << "): " << *this << "\n";
}

Ctors::Ctors(Ctors &&other) noexcept {
  std::cout << "mctor(" << other << "): ";
  *this = std::move(other);
  ++inst_s;

  std::cout << *this << "\n";
}

Ctors::~Ctors() noexcept {
  std::cout << "dtor: " << *this << "\n";
  delete tptr_;
  --inst_s;
}

Ctors &Ctors::operator=(const Ctors &other) {
  if (this == &other) {
    return *this;
  }

  std::cout << "cass(" << other << "): ";

  delete tptr_;
  tptr_ = nullptr;
  tptr_ = new std::string(*other.tptr_);
  id_ = other.id_;

  std::cout << *this << "\n";
  return *this;
}

Ctors &Ctors::operator=(Ctors &&other) noexcept {
  if (this == &other) {
    return *this;
  }

  std::cout << "mass(" << other << "): ";

  delete tptr_;
  tptr_ = nullptr;
  tptr_ = other.tptr_;
  id_ = other.id_;

  // super weird to do this but following instructions
  other.tptr_ = new std::string("<empty>");
  other.id_ *= -1;

  std::cout << *this << "\n";
  return *this;
}

std::ostream &operator<<(std::ostream &os, const Ctors &obj) {
  assert(obj.tptr_ != nullptr);
  os << '[' << obj.id_ << ']' << *obj.tptr_;
  return os;
};

Ctors operator+(const Ctors &arg1, const Ctors &arg2) {
  Ctors rvo(*arg1.tptr_ + *arg2.tptr_);

  std::cout << "operator+() returns: " << rvo << '\n';
  return rvo;
}

Ctors add(const Ctors &arg1, const Ctors &arg2) {
  Ctors rvo(*arg1.tptr_ + *arg2.tptr_);

  std::cout << "add() returns: " << rvo << '\n';
  return rvo;
}
