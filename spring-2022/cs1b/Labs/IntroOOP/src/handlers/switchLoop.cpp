#include "../../include/header.h"

void switchLoop(std::vector<Animal> &animals) {
  bool initialized = false;
  MenuOption choice = Exit;
  do {
    choice = MenuOption(validation(0, InitAnimals, 0, ((initialized) ? 4 : 1),
                                   "", initialized));
    if (!initialized && choice > 1 || choice < 0) {
      validateBounds(choice, Menu, 0, 1, "", initialized);
      continue;
    }
    switch (choice) {
      case Exit: {
        break;
      }
      case InitAnimals: {
        if (initialized) {
          char init;
          validateChar(init);
          if (toupper(init) == 'Y') {
            animals[0].setInitialValues("Fluffy", "Sheep", 1, 15000.00f);
            animals[1].setInitialValues("Maa", "Sheep", 2, 16520.35f);
            animals[2].setInitialValues("Babe", "Pig", 3, 10240.67f);
            std::cout << "Initializing Fluffy, Maa, & Babe...\n";
          }else {
            std::cout << "Animals have not been re-initialized!\n";
          }
        }
        initialized = true;
        break;
      }
      case ChangeAge: {
        int animalChoice = validateBounds(0, ChangeAge, 1, 3, "Change Age", true);
        int ageChoice = validateBounds(0, NEW, 1, 10, "AGE", true);
        animals[animalChoice - 1].changeAge(ageChoice);
        std::cout << "\nChanging " << animals[animalChoice - 1].getName() << "'s age to " << ageChoice << " ...\n";
        break;
      }
      case ChangeValue: {
        int animalChoice = validateBounds(0, ChangeAge, 1, 3, "Change Value", true);
        float valueChoice = validateFloatBounds(NEW, 0, 400000, "VALUE", true);
        animals[animalChoice - 1].changeValue(valueChoice);
        std::cout << "\nChanging " << animals[animalChoice - 1].getName() << "'s value to " << valueChoice << " ...\n";
        break;
      }
      case Display: {
        animals[0].display();
        animals[1].display();
        animals[2].display();
        break;
      }
      default: {
        validateBounds(choice, Menu, 0, 4, "", true);
        break;
      }
    }
  }while (choice != 0);
}