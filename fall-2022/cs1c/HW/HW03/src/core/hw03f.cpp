#include "hw03f.h"

// Constructor
StringType::StringType(size_t length) : buffer_(nullptr), length_(0) {
  if (length == 0) return;

  this->length_ = length;
  this->buffer_ = new char[length_];
}

StringType::StringType(const char* s) : buffer_(nullptr), length_(0) {
  if (s == nullptr) return;

  this->length_ = strlen(s) + 1;
  this->buffer_ = new char[length_];
  strncpy(this->buffer_, s, this->length_);
}

// Copy Constructor
StringType::StringType(const StringType &rhs) : buffer_(nullptr), length_(0) {
  *this = rhs;
}

// Move Constructor
StringType::StringType(StringType &&rhs) noexcept : buffer_(nullptr), length_(0) {
  *this = rhs;
}

// Copy Assignment
StringType &StringType::operator=(const StringType &rhs) {
  if (this == &rhs) return *this;

  this->~StringType();

  this->length_ = rhs.length_;
  if (this->isEmpty() || rhs.buffer_ == nullptr) return *this;

  this->buffer_ = new char[length_];
  strncpy(this->buffer_, rhs.buffer_, this->length_);

  return *this;
}

// Move Assignment
StringType &StringType::operator=(StringType &&rhs) {
  if (this == &rhs) return *this;

  this->buffer_ = rhs.buffer_;
  this->length_ = rhs.length_;

  rhs.buffer_ = nullptr;
  rhs.length_ = 0;
  return *this;
}

// Destructor
StringType::~StringType() {
  delete[] this->buffer_;
  this->buffer_ = nullptr;
}

std::ostream &operator<<(std::ostream &os, const StringType &rhs) {
  if (rhs.buffer_ == nullptr) return os;
  os << rhs.buffer_;
  return os;
}

std::istream &operator>>(std::istream &is, StringType &rhs) {
  char s[1024];
  is.getline(s, 1024, '\n');
  char* str = s;
  rhs = StringType(str);
  return is;
}

size_t StringType::length() const { return this->length_; }

char &StringType::operator[](const int &index) {
  if (!inBoundary(index)) throw -1;
  return *(buffer_ + (sizeof(char) * index));
}

bool StringType::operator==(const StringType &rhs) const {
  // return (strcmp(this->buffer_, rhs.buffer_) == 0);
  return strCompare(rhs);
}

bool StringType::inBoundary(const int &index) const {
  return (index < length_ && index >= 0);
}

size_t StringType::indexOf(const char &c) const {
  for (int i = 0; i < this->length_; i++) {
    if (this->buffer_[i] == c) {
      return i;
    }
  }
  return -1;
}

size_t StringType::indexOf(const StringType &rhs) const {
  char* c = strstr(this->buffer_, rhs.buffer_);
  if (c == nullptr) return -1;

  for (int i = 0; i < length_; i++)
    if (&buffer_[i] == c) return i;

  return -1;
}

bool StringType::isEmpty() const { return this->length_ == 0; }

bool StringType::strCompare(const StringType &rhs) const {
  if (this->length_ != rhs.length_) return false;

  for (int i = 0; i < this->length_; i++) {
    if (this->buffer_[i] != rhs.buffer_[i]) {
      return false;
    }
  }

  return true;
}

StringType StringType::operator+(const StringType &rhs) const {
  char newBuffer[this->length_ + rhs.length_];
  strncpy(newBuffer, this->buffer_, this->length_);

  strcat(newBuffer, rhs.buffer_);
  return newBuffer;
}

StringType &StringType::operator+=(const StringType &rhs) {
  char* newBuffer = new char[this->length_ + rhs.length_];
  strncpy(newBuffer, this->buffer_, this->length_);
  strcat(newBuffer, rhs.buffer_);

  this->~StringType();
  this->buffer_ = newBuffer;
  newBuffer = nullptr;
  return *this;
}

StringType StringType::reverse() const {
  if (this->length_ <= 1) return this->buffer_;
  const int LEN = strlen(this->buffer_) - 1;
  StringType str(this->length_);
  for (int i = LEN; i >= 0; i--) {
    str[LEN - i] = this->buffer_[i];
  }
  return str;
}