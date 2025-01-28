#include "../../include/Livestock.h"

void Livestock::print() const {
  std::cout << std::left;
  std::cout << "\nTHE SHEEP:\n\n";
  std::cout << std::setw(11) << "NAME" << std::setw(5) << "AGE";
  std::cout << std::setw(10) << "WOOLTYPE" << std::setw(5) << "COLOR\n";
  std::cout << std::setw(11) << "---------" << std::setw(5) << "---";
  std::cout << std::setw(10) << "--------" << std::setw(5) << "-----\n";
  for (int i = 0; i < m_SheepLivestock.size(); ++i) {
    m_SheepLivestock[i].print();
    std::cout << "\n";
  }

  std::cout << "\nTHE PIG(S):\n\n";
  std::cout << std::setw(11) << "NAME" << std::setw(5) << "AGE";
  std::cout << std::setw(9) << "TAILTYPE\n";
  std::cout << std::setw(11) << "---------" << std::setw(5) << "---";
  std::cout << std::setw(9) << "----------\n"; 
  for (int i = 0; i < m_PigLivestock.size(); ++i) {
    m_PigLivestock.at(i).print();
    std::cout << "\n";
  }
  std::cout << std::right;
}

void Livestock::clear() { 
  m_SheepLivestock.clear();
  m_PigLivestock.clear();
}
void Livestock::clearSheep() { m_SheepLivestock.clear(); }
void Livestock::clearPig() { m_PigLivestock.clear(); }