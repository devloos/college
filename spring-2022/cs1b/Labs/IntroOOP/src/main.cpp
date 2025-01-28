#include "../include/header.h"
#include "../include/Animal.h"
/*******************************************************************************
 * AUTHOR      : Carlos Aguilera
 * STUDENT ID  : 1152562
 * LAB #12     : Introduction OOP
 * CLASS       : CS1B
 * SECTION     : M-W
 * DUE DATE    : 05.02.22
 ******************************************************************************/

/******************************************************************************
 * Title: Introduction OOP
 * ----------------------------------------------------------------------------
 * PROGRAM:
 * 
 * ----------------------------------------------------------------------------
 ******************************************************************************/

int main() {
  heading();
  // PROCESSING: VECTOR OF ANIMALS
  std::vector<Animal> animals;
  animals.push_back(Animal ("Fluffy", "Sheep", 1, 15000.00f));
  animals.push_back(Animal ("Maa", "Sheep", 2, 16520.35f));
  animals.push_back(Animal ("Babe", "Pig", 3, 10240.67f));
  // PROCESSING: Switch Loop
  switchLoop(animals);
  return 0;
}