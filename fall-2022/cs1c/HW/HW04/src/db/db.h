#ifndef DB_H_
#define DB_H_
#include <fstream>
#include <iostream>
#include <optional>
#include <string>

#include "../models/Student.h"
#include "../stl/List.h"
#include "../utility/Utility.h"

struct DirtyAddress {
  std::string street_;
  std::string city_;
  std::string state_;
  int zip_ = 0;
};

struct DirtyStudent {
  int id_ = 0;
  std::string lastName_;
  std::string firstName_;
  std::string email_;
  std::string phone_;
  DirtyAddress address_;
  std::string major_;
  std::string rank_;
  float gpa_ = 0.0;
};

class db {
 private:
  std::string fileName_;
  std::fstream fin_;
  List<Student> students_;

 public:
  db(const std::string &fileName);
  ~db() noexcept;
  bool init();

  void print() const;
  std::optional<Student> getById(const int &id);
  std::optional<Student> getByName(const std::string &name);

  // sorting based on default <
  void sort();
  bool post(const DirtyStudent &dStudent);
  bool deleteById(const int &id);
  bool deleteByName(const std::string &name);

  /// @brief BE VERY CAREFUL WITH THIS AS IT WILL DELETE ENTIRE DB
  bool deleteAll();
  void saveAll();

 private:
  DirtyStudent readStudent(std::fstream &fin) const;
  Student cleanStudent(const DirtyStudent &dStudent) const;
  bool write();
};

#endif  // DB_H_
