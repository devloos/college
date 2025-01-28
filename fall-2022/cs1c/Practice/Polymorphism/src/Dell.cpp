#include "Dell.h"

Dell::Dell() {}

Dell::Dell(const Dell &rhs) {}

Dell &Dell::operator=(const Dell &rhs) {}

Dell::Dell(Dell &&rhs) {}

Dell &Dell::operator=(Dell &&rhs) {}

void Dell::Print() const { std::cout << "Dell\n"; }