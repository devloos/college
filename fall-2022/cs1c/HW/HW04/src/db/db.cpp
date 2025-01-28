#include "db.h"

db::db(const std::string &fileName) : fileName_(fileName) {}

bool db::init() {
  this->fin_.open(this->fileName_, std::ios::in);
  if (!this->fin_.is_open()) {
    throw Utility::Exception(
        Utility::Exception::Level::ERROR,
        "File: " + this->fileName_ + " could not be opened");
  }

  while (!this->fin_.eof()) {
    DirtyStudent dStudent = this->readStudent(this->fin_);
    students_.insert(this->cleanStudent(dStudent));
  }
  this->fin_.close();
  return true;
}

db::~db() noexcept {}

DirtyStudent db::readStudent(std::fstream &fin) const {
  DirtyStudent dStudent;

  fin >> dStudent.id_;
  Utility::cleanBuffer(fin);
  std::getline(fin, dStudent.lastName_);
  std::getline(fin, dStudent.firstName_);
  std::getline(fin, dStudent.email_);
  std::getline(fin, dStudent.phone_);

  std::getline(fin, dStudent.address_.street_);
  std::getline(fin, dStudent.address_.city_);
  std::getline(fin, dStudent.address_.state_);
  fin >> dStudent.address_.zip_;
  Utility::cleanBuffer(fin);

  std::getline(fin, dStudent.major_);
  std::getline(fin, dStudent.rank_);
  fin >> dStudent.gpa_;
  Utility::cleanBuffer(fin);
  // Used to ignore extra \n
  fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  return dStudent;
}

Student db::cleanStudent(const DirtyStudent &dStudent) const {
  Student student;
  Address address;

  student.setId(dStudent.id_);
  student.setLastName(dStudent.lastName_);
  student.setFirstName(dStudent.firstName_);
  student.setEmail(dStudent.email_);
  student.setPhone(dStudent.phone_);

  address.setStreet(dStudent.address_.street_);
  address.setCity(dStudent.address_.city_);
  address.setState(dStudent.address_.state_);
  address.setZip(dStudent.address_.zip_);

  student.setAddress(address);
  student.setMajor(dStudent.major_);
  student.setRank(dStudent.rank_);
  student.setGpa(dStudent.gpa_);

  return student;
}

void db::print() const {
  if (this->students_.isEmpty()) return;

  auto iter = this->students_.begin();
  while (iter != this->students_.end()) {
    iter->data.print();
    std::cout << "\n";
    // TODO: Overload ++ operator to work more like a real iterator
    iter = iter->next;
  }
}

std::optional<Student> db::getById(const int &id) {
  Student* data =
      this->students_.find([id](const Student &rhs) { return rhs.getId() == id; });
  if (data != nullptr) {
    return *data;
  }
  return {};
}

std::optional<Student> db::getByName(const std::string &name) {
  Student* data = this->students_.find(
      [name](const Student &rhs) { return rhs.getFullName() == name; });
  if (data != nullptr) {
    return *data;
  }
  return {};
}

void db::sort() {
  if (students_.isEmpty()) return;
  students_.sort();
  this->write();
}

bool db::post(const DirtyStudent &dStudent) {
  const Student data = this->cleanStudent(dStudent);
  students_.insert(data);
  this->fin_.open(this->fileName_, std::ios::app);
  if (!this->fin_.is_open()) return false;

  Address address = data.getAddress();

  this->fin_ << '\n';
  this->fin_ << data.getId() << '\n';
  this->fin_ << data.getLastName() << '\n';
  this->fin_ << data.getFirstName() << '\n';
  this->fin_ << data.getEmail() << '\n';
  this->fin_ << data.getPhone() << '\n';
  this->fin_ << address.getStreet() << '\n';
  this->fin_ << address.getCity() << '\n';
  this->fin_ << address.getState() << '\n';
  this->fin_ << address.getZip() << '\n';
  this->fin_ << data.getMajor() << '\n';
  this->fin_ << data.getRank() << '\n';
  this->fin_ << data.getGpa() << '\n';

  this->fin_.close();
  return true;
}

bool db::deleteById(const int &id) {
  bool removedFromMem =
      students_.remove([id](const Student &data) { return data.getId() == id; });
  if (removedFromMem) {
    if (this->write()) {
      return true;
    }
  }
  return false;
}

bool db::deleteByName(const std::string &name) {
  bool removedFromMem = students_.remove(
      [name](const Student &data) { return data.getFullName() == name; });
  if (removedFromMem) {
    if (this->write()) {
      return true;
    }
  }
  return false;
}

/// @brief BE VERY CAREFUL WITH THIS AS IT WILL DELETE ENTIRE DB
bool db::deleteAll() {
  this->fin_.open(this->fileName_, std::ios::out);
  if (!this->fin_.is_open()) return false;
  this->fin_.close();
  students_.clear();
  return true;
}

bool db::write() {
  this->fin_.open(this->fileName_, std::ios::out);
  if (!this->fin_.is_open()) return false;

  auto iter = students_.begin();
  while (iter != students_.end()) {
    Address address = iter->data.getAddress();
    this->fin_ << iter->data.getId() << '\n';
    this->fin_ << iter->data.getLastName() << '\n';
    this->fin_ << iter->data.getFirstName() << '\n';
    this->fin_ << iter->data.getEmail() << '\n';
    this->fin_ << iter->data.getPhone() << '\n';
    this->fin_ << address.getStreet() << '\n';
    this->fin_ << address.getCity() << '\n';
    this->fin_ << address.getState() << '\n';
    this->fin_ << address.getZip() << '\n';
    this->fin_ << iter->data.getMajor() << '\n';
    this->fin_ << iter->data.getRank() << '\n';
    this->fin_ << iter->data.getGpa()
               << ((iter->next != students_.end()) ? "\n\n" : "\n");
    iter = iter->next;
  }
  this->fin_.close();
  return true;
}

void db::saveAll() {
  if (students_.isEmpty()) return;
  this->write();
}
