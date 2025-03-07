// Name: Carlos Aguilera
// Class CECS 325-02
// Project Name Prog 3 – Sort
// Due Date 03/06/2025
//
// I certify that this program is my own original work. I did not copy any part
// of this program from any other source. I further certify that I typed each
// and every line of code in this program.
#include <fstream>
#include <iostream>

void bubble(int arr[], int size) {
  for (int i = 0; i < size; ++i) {
    for (int j = i + 1; j < size; ++j) {
      if (arr[i] > arr[j]) {
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
      }
    }
  }
}

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cout << "Please ONLY pass 2 args: INPUT_FILE, OUTPUT_FILE\n";
    return 1;
  }

  std::fstream inputFile(argv[1], std::ios::in);

  if (!inputFile.is_open()) {
    std::cout << "Input file did not open sucessfully.";
    return 1;
  }

  int capacity = 10;
  int size = 0;
  int* arr = new int[capacity];

  std::string line;
  while (std::getline(inputFile, line)) {
    const int num = std::stoi(line);
    arr[size++] = num;

    if (size == capacity) {
      int* buffer = new int[capacity * 2];
      memcpy(buffer, arr, sizeof(int) * (size - 1));

      delete[] arr;
      capacity *= 2;
      arr = buffer;
    }
  }

  inputFile.close();

  bubble(arr, size);

  std::fstream outFile(argv[2], std::ios::out);

  if (!outFile.is_open()) {
    std::cout << "Output file did not open sucessfully.";
    return 1;
  }

  for (int i = 0; i < size; ++i) {
    outFile << arr[i] << '\n';
  }

  outFile.close();

  delete[] arr;

  return 0;
}