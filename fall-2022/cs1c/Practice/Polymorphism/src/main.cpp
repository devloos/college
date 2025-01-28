#include <iostream>

#include "Dell.h"
#include "Laptop.h"
#include "Mac.h"

void Print(const Laptop &laptop);

int main() {
  Mac mac;
  Dell dell;
  Laptop lap;

  Print(lap);
  Print(mac);
  Print(dell);
  return 0;
}

void Print(const Laptop &laptop) { laptop.Print(); }
