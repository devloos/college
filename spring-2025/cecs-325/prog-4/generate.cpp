// Name: Carlos Aguilera
// Class CECS 325-02
// Project Name Prog 3 – Generate
// Due Date 03/06/2025
//
// I certify that this program is my own original work. I did not copy any part
// of this program from any other source. I further certify that I typed each
// and every line of code in this program.
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>

int main(int argc, char *argv[]) {
  if (argc != 4) {
    std::cout << "Please ONLY pass 3 args: COUNT MIN MAX.\n";
    return 1;
  }

  std::srand(std::time(0));

  std::fstream outFile("numbers.dat", std::ios::out);

  if (!outFile.is_open()) {
    std::cout << "File did not open sucessfully.";
    return 1;
  }

  int count = std::stoi(argv[1]);
  int min = std::stoi(argv[2]);
  int max = std::stoi(argv[3]);

  for (int i = 0; i < count; ++i) {
    int num = (std::rand() % (max - min + 1)) + min;

    outFile << num << '\n';
  }

  outFile.close();

  return 0;
}