#include "../include/SheepList.h"

void SheepList::addSheep(const Sheep &newSheep) {
  if (sheepCount <= ARRAY_SIZE) {
    sheepArray[sheepCount].setName(newSheep.getName());
    sheepArray[sheepCount].setAge(newSheep.getAge());
    std::cout << "\nThe sheep...\n";
    std::cout << "Sheep Name: " << newSheep.getName() << "\n";
    std::cout << "Sheep Age:  " << newSheep.getAge() << "\n";
    std::cout << "Has been added!\n";
    ++sheepCount;
  }else {
    std::cout << "List is full sorry!\n";
  }
}

void SheepList::clear() {
  if (sheepCount == 0) {
    std::cout << "\nThe list is empty!\n";
    return;
  }
  for (int i = 0; i < sheepCount; ++i) {
    sheepArray[i].setName("");
    sheepArray[i].setAge(0);
  }
  sheepCount = 0;
  std::cout << "The list has been cleared!\n";
}

int SheepList::size() const { return sheepCount; }

bool SheepList::find(const std::string name) const {
  bool found = false;
  int i = 0;
  while (!found && i < sheepCount) {
    if (sheepArray[i].getName() == name) {
      listOneSheep(i);
      std::cout << "Has been found\n";
      return true;
    }
    ++i;
  }
  return false;
}

void SheepList::listOneSheep(const int &index) const {
  std::cout << "\nNAME           AGE\n";
  std::cout << "-------------- ---\n";
  std::cout << std::left;
  std::cout << std::setw(16) << sheepArray[index].getName();
  std::cout << sheepArray[index].getAge() << '\n';
  std::cout << std::right;
}

void SheepList::firstSheep() const {
  if (sheepCount > 0) {
    listOneSheep(0);
    std::cout << "\nIs at the front of the list.\n";
  } else {
    std::cout << "\nNobody is in front - the list is empty!\n";
  }
}

std::ostream &operator<<(std::ostream &os, const SheepList &sheepList) {
  if (sheepList.sheepCount > 0) {
    os << "\nNAME           AGE\n";
    os << "-------------- ---\n";
    std::cout << std::left;
    for (int i = 0; i < sheepList.sheepCount; ++i) {
      std::cout << std::setw(16) << sheepList.sheepArray[i].getName();
      std::cout << sheepList.sheepArray[i].getAge();
      std::cout << ((i + 1 < sheepList.sheepCount) ? '\n' : ' ');
    }
    std::cout << std::right;
    std::cout << "\nThere are " << sheepList.sheepCount << " sheep in the list!\n";
  } else {
    std::cout << "\nThe list is empty!";
  }
  return os;
}