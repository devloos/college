#ifndef MAIN_H_
#define MAIN_H_
#include "../include/Sheep.h"
#include "../include/Livestock.h"

enum MenuType { kMain = 0, kEntry, kAnimal, kChoosingAnimal, kChoosingAge };
enum MenuOptions { 
  kExit = 0,
  kInitializeAnimals,
  kReInitializeSheep,
  kReInitializePig,
  kChangeAge,
  kDisplayAnimals,
};
enum AnimalMenu { kAnimalExit = 0, kSheep, kPig };

void heading();
void initSheeps(Livestock &livestock);
void initPigs(Livestock &livestock);
void menu(const MenuType &menu);
void switchLoop(Livestock &livestock, MenuOptions &choice, MenuType &menuType);

#endif // MAIN_H_