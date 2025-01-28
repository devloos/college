#include "Laptop.h"

Laptop::Laptop() {}

Laptop::Laptop(const Laptop &rhs) {}

Laptop &Laptop::operator=(const Laptop &rhs) {}

Laptop::Laptop(Laptop &&rhs) {}

Laptop &Laptop::operator=(Laptop &&rhs) {}

void Laptop::Print() const { std::cout << "Laptop\n"; }