#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

int toInt(char c) {
  return c - '0'; // kinda like casting v[i] to int
}

class BigInt {
private:
  std::vector<char> v;

public:
  BigInt() {}
  BigInt(int num) : BigInt(std::to_string(num)) {}
  BigInt(std::string str) {
    std::reverse(str.begin(), str.end());

    for (char c : str) {
      v.push_back(c);
    }
  }

  BigInt operator+(BigInt other) {
    int carry = 0;
    BigInt bigger;
    BigInt smaller;
    BigInt result;

    if (this->size() > other.size()) {
      bigger = *this;
      smaller = other;
    } else {
      bigger = other;
      smaller = *this;
    }

    for (int i = 0; i < bigger.size(); ++i) {
      int num1 = toInt(bigger.v[i]);
      int num2 = 0;

      if (i < smaller.size()) {
        num2 = toInt(smaller.v[i]);
      }

      int newNum = carry + num1 + num2; // number between 0 - 19

      if (newNum <= 9) {
        result.v.push_back(std::to_string(newNum)[0]);
        carry = 0;
      } else {
        result.v.push_back(std::to_string(newNum)[1]);
        carry = 1;
      }
    }

    if (carry == 1) {
      result.v.push_back(std::to_string(carry)[0]);
    }

    return result;
  }

  BigInt operator+(int num) {
    BigInt other(num);

    return *this + other;
  }

  BigInt operator-(BigInt other) {
    int carry = 0;
    BigInt bigger;
    BigInt smaller;
    BigInt result;

    if (this->size() > other.size()) {
      bigger = *this;
      smaller = other;
    } else {
      bigger = other;
      smaller = *this;
    }

    for (int i = 0; i < bigger.size(); ++i) {
      int num1 = toInt(bigger.v[i]);
      int num2 = 0;

      if (i < smaller.size()) {
        num2 = toInt(smaller.v[i]);
      }

      int newNum = (num1 - carry) - num2; // number between 0 - 19

      if (newNum >= 0) {
        result.v.push_back(std::to_string(newNum)[0]);
        carry = 0;
      } else {
        newNum = (num1 + 10) - num2; // should be between 0 - 9
        result.v.push_back(std::to_string(newNum)[0]);
        carry = 1;
      }
    }

    return result;
  }

  BigInt operator-(int num) {
    BigInt other(num);

    return *this - other;
  }

  BigInt operator*(BigInt other) {
    BigInt result;

    for (int i = 0; i < other.size(); ++i) {
      result = result + (*this);
    }

    return result;
  }

  BigInt operator/(BigInt other) { return BigInt("000000000000000000000"); }
  BigInt operator%(BigInt other) { return BigInt("000000000000000000000"); }

  BigInt operator++() {
    int carry = 1;

    for (int i = 0; i < v.size(); ++i) {
      int num = toInt(v[i]);

      if (num < 9) {
        v[i] = std::to_string(++num)[0];
        carry = 0;
        break;
      } else {
        v[i] = '0';
      }
    }

    if (carry == 1) {
      v.push_back(std::to_string(carry)[0]);
    }

    return *this;
  }

  BigInt operator++(int) {
    BigInt copy = *this; // vector implements copy
    ++(*this);
    return copy;
  }

  bool operator==(BigInt other) { return this->v == other.v; }

  BigInt operator[](int index) { return BigInt(std::to_string(v[index])); }

  int size() { return v.size(); }

  void print() {
    for (int i = v.size() - 1; i >= 0; --i) {
      std::cout << v[i];
    }
  }

  BigInt fibo() { return BigInt("000000000000000000000"); }
  BigInt fact() { return BigInt("000000000000000000000"); }

  friend BigInt operator+(int num, BigInt other) { return other + num; }

  friend std::ostream &operator<<(std::ostream &ostream, const BigInt &num) {
    for (int i = num.v.size() - 1; i >= 0; --i) {
      ostream << num.v[i];
    }

    return ostream;
  }
};

void testUnit() {
  int space = 10;
  std::cout << "\a\nTestUnit:\n" << std::flush;
  system("whoami");
  system("date");
  // initialize variables
  BigInt n1(25);
  BigInt s1("25");
  BigInt n2(1234);
  BigInt s2("1234");
  BigInt n3(n2);
  BigInt fibo(12345);
  BigInt fact(50);
  BigInt imax = INT_MAX;
  BigInt big("9223372036854775807");

  // display variables
  std::cout << "n1(int) :" << std::setw(space) << n1 << std::endl;
  std::cout << "s1(str) :" << std::setw(space) << s1 << std::endl;
  std::cout << "n2(int) :" << std::setw(space) << n2 << std::endl;
  std::cout << "s2(str) :" << std::setw(space) << s2 << std::endl;
  std::cout << "n3(n2) :" << std::setw(space) << n3 << std::endl;
  std::cout << "fibo(12345):" << std::setw(space) << fibo << std::endl;
  std::cout << "fact(50) :" << std::setw(space) << fact << std::endl;
  std::cout << "imax :" << std::setw(space) << imax << std::endl;
  std::cout << "big :" << std::setw(space) << big << std::endl;
  std::cout << "big.print(): ";
  big.print();
  std::cout << std::endl;

  // compute stuff
  std::cout << n2 << "/" << n1 << " = " << n2 / n1 << " rem " << n2 % n1
            << std::endl;
  std::cout << "fibo(" << fibo << ") = " << fibo.fibo() << std::endl;
  std::cout << "fact(" << fact << ") = " << fact.fact() << std::endl;
  std::cout << "10 + n1 = " << 10 + n1 << std::endl;
  std::cout << "n1 + 10 = " << n1 + 10 << std::endl;
  std::cout << "(n1 == s1)? --> " << ((n1 == s1) ? "true" : "false")
            << std::endl;
  std::cout << "n1++ = ? --> before:" << n1++ << " after:" << n1 << std::endl;
  std::cout << "++s1 = ? --> before:" << ++s1 << " after:" << s1 << std::endl;
  std::cout << "s2 * big = ? --> " << s2 * big << std::endl;
  std::cout << "big * s2 = ? --> " << big * s2 << std::endl;
}

int main() {
  testUnit();

  BigInt num1(328008);
  BigInt num2(328008);

  std::cout << num1 - num2 << '\n';

  return 0;
}
