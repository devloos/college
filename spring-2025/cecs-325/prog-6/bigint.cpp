#include <iostream>
#include <string>
#include <vector>

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
    int size = this->size() > other.size() ? this->size() : other.size();
    BigInt result;

    for (int i = 0; i < size; ++i) {
      int num1 = 0;
      int num2 = 0;

      if (i < this->size()) {
        num1 = this->v[i] - '0';
      }

      if (i < other.size()) {
        num2 = other.v[i] - '0';
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

  BigInt operator-(BigInt other) {}
  BigInt operator-(int other) {}

  BigInt operator*(BigInt other) {
    BigInt result;

    for (int i = 0; i < other.size(); ++i) {
      result = result + (*this);
    }

    return result;
  }

  BigInt operator/(BigInt other) {}
  BigInt operator%(BigInt other) {}

  BigInt operator++() {
    int carry = 1;

    for (int i = 0; i < v.size(); ++i) {
      int num = v[i] - '0'; // kinda like casting v[i] to int

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

  BigInt operator[](int index) { return BigInt(std::to_string(v[index])); }

  int size() { return v.size(); }

  void print() {
    for (int i = v.size() - 1; i >= 0; --i) {
      std::cout << v[i];
    }

    std::cout << '\n';
  }

  BigInt fibo(BigInt num) {}
  BigInt fact(BigInt num) {}
  friend BigInt operator+(int, BigInt) {}

  friend std::ostream &operator<<(std::ostream &ostream, const BigInt &num) {
    for (int i = num.v.size() - 1; i >= 0; --i) {
      ostream << num.v[i];
    }

    ostream << '\n';

    return ostream;
  }
};

int main() {
  BigInt num1(90230);
  BigInt num2(43290293);

  BigInt num3 = num1 * num2;

  std::cout << num3;
  return 0;
}
