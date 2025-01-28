#ifndef MENU_H_
#define MENU_H_
#include <iostream>
#include <limits>
#include <optional>
#include <string>

#include "../db/db.h"
#include "../models/Address.h"
#include "../models/Student.h"
#include "../utility/Utility.h"

#define EXIT 5

namespace Menu {
/**
 * @brief
 *
 * @return int
 */
int exec();

/**
 * @brief
 *
 * @param db
 */
void loop(db &db);

/**
 * @brief
 *
 * @param db
 */
void deleteRecord(db &db);

/**
 * @brief
 *
 * @param db
 */
void displayRecord(db &db);

/**
 * @brief
 *
 */
void print();

/**
 * @brief
 *
 */
void Delete();

/**
 * @brief
 *
 */
void display();

/**
 * @brief
 *
 * @return DirtyStudent
 */
DirtyStudent read();
}  // namespace Menu

#endif  // MENU_H_