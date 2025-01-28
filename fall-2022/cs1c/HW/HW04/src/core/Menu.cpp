#include "Menu.h"

namespace Menu {
int exec() {
  db db("../src/db/studentdb.txt");
  try {
    db.init();
  } catch (Utility::Exception &e) {
    e.log();
    return -1;
  }
  Menu::loop(db);
  return 0;
}

void loop(db &db) {
  int option = EXIT;
  do {
    Menu::print();
    option = Utility::validate("Option: ");

    switch (option) {
      case 1: {
        DirtyStudent dStudent = Menu::read();
        if (db.post(dStudent)) {
          std::cout << "Inserted student with id: " << dStudent.id_
                    << " into the database\n";
        } else {
          std::cout << "Inserting of student with id: " << dStudent.id_ << " FAILED\n";
        }
        break;
      }
      case 2: {
        Menu::deleteRecord(db);
        break;
      }
      case 3: {
        Menu::displayRecord(db);
        break;
      }
      case 4: {
        db.sort();
        std::cout << "\nDATABASE SORTED BY NAME\n\n";
        break;
      }
      case EXIT: {
        db.saveAll();
        std::cout << "\nDATABASE CLOSED!\n";
        break;
      }
      default: {
        std::cout << "\n" << option << " is not a valid option\n\n";
        break;
      }
    }
  } while (option != EXIT);
}

void deleteRecord(db &db) {
  bool validOption = false;
  char option;
  do {
    Menu::Delete();
    std::cin.get(option);
    Utility::cleanBuffer(std::cin);

    switch (option) {
      case 'a': {
        int studentId = 0;
        std::cout << "Enter student id: ";
        std::cin >> studentId;
        Utility::cleanBuffer(std::cin);
        if (db.deleteById(studentId)) {
          std::cout << "Student with id: " << studentId << " was deleted\n";
        } else {
          std::cout << "No student with id: " << studentId << " was found\n";
        }
        validOption = true;
        break;
      }
      case 'b': {
        std::string studentName;
        std::cout << "Enter student name: ";
        std::getline(std::cin, studentName);
        if (db.deleteByName(studentName)) {
          std::cout << "Student with name: " << studentName << " was deleted\n";
        } else {
          std::cout << "No student with name: " << studentName << " was found\n";
        }
        validOption = true;
        break;
      }
      default: {
        std::cout << "\n" << option << " is not a valid option\n\n";
        break;
      }
    }
  } while (!validOption);
}

void displayRecord(db &db) {
  bool validOption = false;
  char option;
  do {
    Menu::display();
    std::cin.get(option);
    Utility::cleanBuffer(std::cin);

    switch (option) {
      case 'a': {
        int studentId = 0;
        std::cout << "Enter student id: ";
        std::cin >> studentId;
        Utility::cleanBuffer(std::cin);
        std::optional<Student> student = db.getById(studentId);
        if (student) {
          std::cout << "\n";
          student->print();
        } else {
          std::cout << "No student with id: " << studentId << " was found\n";
        }
        validOption = true;
        break;
      }
      case 'b': {
        std::string studentName;
        std::cout << "Enter student name: ";
        std::getline(std::cin, studentName);
        std::optional<Student> student = db.getByName(studentName);
        if (student) {
          std::cout << "\n";
          student->print();
        } else {
          std::cout << "No student with name: " << studentName << " was found\n";
        }
        validOption = true;
        break;
      }
      case 'c': {
        db.print();
        validOption = true;
        break;
      }
      default: {
        std::cout << "\n" << option << " is not a valid option\n\n";
        break;
      }
    }
  } while (!validOption);
}

DirtyStudent read() {
  DirtyStudent dStudent;

  std::cout << "\nNew Student Information\n";
  std::cout << "  ID: ";
  std::cin >> dStudent.id_;
  Utility::cleanBuffer(std::cin);
  std::cout << "  Last Name: ";
  std::getline(std::cin, dStudent.lastName_);
  std::cout << "  First Name: ";
  std::getline(std::cin, dStudent.firstName_);
  std::cout << "  Email: ";
  std::getline(std::cin, dStudent.email_);
  std::cout << "  Phone: ";
  std::getline(std::cin, dStudent.phone_);

  std::cout << "  Street: ";
  std::getline(std::cin, dStudent.address_.street_);
  std::cout << "  City: ";
  std::getline(std::cin, dStudent.address_.city_);
  std::cout << "  State: ";
  std::getline(std::cin, dStudent.address_.state_);
  std::cout << "  Zip: ";
  std::cin >> dStudent.address_.zip_;
  Utility::cleanBuffer(std::cin);

  std::cout << "  School Major: ";
  std::getline(std::cin, dStudent.major_);
  std::cout << "  School Rank: ";
  std::getline(std::cin, dStudent.rank_);
  std::cout << "  School GPA: ";
  std::cin >> dStudent.gpa_;
  Utility::cleanBuffer(std::cin);

  return dStudent;
}

void print() {
  std::cout << "\nMenu - Select:\n";
  std::cout << "  1. Add a record\n"
            << "  2. Delete a record\n"
            << "  3. Display database contents on screen\n"
            << "  4. Sort database by names\n"
            << "  5. Save and Exit\n\n";
}

void Delete() {
  std::cout << "\nMenu - Select:\n";
  std::cout << "  (a) Select record to delete using student ID\n"
            << "  (b) Select record to delete using student's name\n\n";
  std::cout << "Option: ";
}

void display() {
  std::cout << "\nMenu - Select:\n";
  std::cout << "  (a) Select record to display using student ID\n"
            << "  (b) Select record to display using studentś name\n"
            << "  (c) Display all records\n\n";
  std::cout << "Option: ";
}
}  // namespace Menu
