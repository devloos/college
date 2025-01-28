
#include "hw10.h"

int Ctors::inst_s = 0;
int Ctors::idGen_s = 0;

int main() {
  std::cout << "default constructor:" << '\n';
  Ctors ctor;
  std::cout << "ctor = " << ctor << '\n';

  std::cout << '\n' << "constructor with parameters:" << '\n';
  Ctors obj01("cs1c");
  Ctors obj02("student");
  std::cout << "obj01 = " << obj01 << '\n';
  std::cout << "obj02 = " << obj02 << '\n';

  std::cout << '\n' << "copy constructor:" << '\n';
  Ctors obj11(obj01);
  std::cout << "obj01 = " << obj01 << '\n';
  std::cout << "obj11 = " << obj11 << '\n';

  std::cout << '\n' << "move constructor:" << '\n';
  Ctors obj21(std::move(obj01));  // make obj01 an rvalue
  std::cout << "obj01 = " << obj01 << '\n';
  std::cout << "obj21 = " << obj21 << '\n';

  std::cout << '\n' << "copy assignment operator:" << '\n';
  Ctors obj12;
  obj12 = obj02;
  std::cout << "obj02 = " << obj02 << '\n';
  std::cout << "obj12 = " << obj12 << '\n';

  std::cout << '\n' << "move assignment operator 1:" << '\n';
  Ctors obj11obj12;
  obj11obj12 = obj11 + obj12;  // the expression is an rvalue
  std::cout << "obj11obj12 = " << obj11obj12 << '\n';
  std::cout << "     obj11 = " << obj11 << '\n';
  std::cout << "     obj12 = " << obj12 << '\n';

  std::cout << '\n' << "move assignment operator 2:" << '\n';
  Ctors obj11obj12r;
  obj11obj12r = add(obj11, obj12);  // the return value is an rvalue
  std::cout << "obj11obj12r = " << obj11obj12r << '\n';
  std::cout << "     obj11 = " << obj11 << '\n';
  std::cout << "     obj12 = " << obj12 << '\n';

  std::cout << '\n' << "move assignment operator 3:" << '\n';
  Ctors obj02m;
  obj02m = std::move(obj02);  // make obj02 an rvalue
  std::cout << "obj02 = " << obj02 << '\n';
  std::cout << "obj02m = " << obj02m << '\n';

  std::cout << '\n' << "moved return rvalue 1:" << '\n';
  Ctors hi("Hi");
  Ctors mom("Mom");
  Ctors himom(hi + mom);  // the return rvalue is moved
  std::cout << "himom = " << himom << '\n';

  std::cout << '\n' << "moved return rvalue 2:" << '\n';
  Ctors go("go");
  Ctors bobcats("bobcats");
  Ctors gobobcats(add(go, bobcats));  // the return rvalue is moved
  std::cout << "gobobcats = " << gobobcats << '\n';

  std::cout << '\n' << "append an lvalue to a vector container:" << '\n';
  std::vector<Ctors> v;
  v.reserve(2);
  v.push_back(gobobcats);
  std::cout << "v[0] = " << v[0] << '\n';

  std::cout << '\n' << "append an rvalue to a vector container:" << '\n';
  v.push_back(go + bobcats);
  std::cout << "v[1] = " << v[1] << '\n';
  std::cout << '\n' << "print by value 1:" << '\n';
  printval(obj11);
  std::cout << '\n' << "print by value 2:" << '\n';
  printval(obj11 + obj12);
  std::cout << '\n' << "print by reference:" << '\n';
  printref(obj11);
  std::cout << '\n' << "print by move 1:" << '\n';
  printmov(obj11 + obj12);
  std::cout << '\n' << "print by move 2:" << '\n';
  printmov(std::move(obj11));
  printref(obj11);

  std::cout << '\n' << "end of program" << '\n';
  return 0;
}

void printval(Ctors value) {
  std::cout << "function printval: " << value << '\n';
}

void printref(const Ctors &ref) {
  std::cout << "function printref: " << ref << '\n';
}

void printmov(Ctors &&move) {
  std::cout << "function printmov: " << move << '\n';
}