// Name: Carlos Aguilera
// Class CECS 325-02
// Project Name Prog 4 – Thread Sort
// Due Date 03/25/2025
//
// I certify that this program is my own original work. I did not copy any part
// of this program from any other source. I further certify that I typed each
// and every line of code in this program.
#include <fstream>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

long long totalSwaps = 0;
std::mutex myMutex;

void mergeInPlace(int arr1[], int arr2[], int size) {
  int i = 0, j = 0, k = 0;
  int n1 = size;
  int n2 = size;

  int* arr3 = new int[size * 2];

  while (i < n1 && j < n2) {
    if (arr1[i] < arr2[j])
      arr3[k++] = arr1[i++];
    else
      arr3[k++] = arr2[j++];
  }

  while (i < n1) {
    arr3[k++] = arr1[i++];
  }

  while (j < n2) {
    arr3[k++] = arr2[j++];
  }

  // overwrite everything including arr2
  memcpy(arr1, arr3, sizeof(int) * (size * 2));

  delete[] arr3;
}

void bubble(int arr[], int size, const std::string& process) {
  long long localSwaps = 0;
  for (int i = 0; i < size; ++i) {
    for (int j = i + 1; j < size; ++j) {
      if (arr[i] > arr[j]) {
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;

        ++localSwaps;
      }
    }
  }

  std::lock_guard<std::mutex> lock(myMutex);

  totalSwaps += localSwaps;
  std::cout << process << " swap count: " << totalSwaps << std::endl;
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

  // CustomVector sheesh (i still got it)
  int capacity = 10;
  int size = 0;
  int* arr = new int[capacity];

  std::string line;
  while (std::getline(inputFile, line)) {
    const int num = std::stoi(line);
    arr[size++] = num;

    if (size == capacity) {
      int* buffer = new int[capacity * 2];
      memcpy(buffer, arr, sizeof(int) * size);

      delete[] arr;
      capacity *= 2;
      arr = buffer;
    }
  }

  inputFile.close();

  int NUMBER_OF_THREADS = 16;

  std::vector<std::thread> threads;

  int PARTITION_SIZE = size / NUMBER_OF_THREADS;

  for (int i = 0; i < NUMBER_OF_THREADS; ++i) {
    int* partition = &arr[PARTITION_SIZE * i];
    threads.emplace_back(bubble, partition, PARTITION_SIZE,
                         "Process " + std::to_string(i));
  }

  for (auto& thread : threads) {
    thread.join();
  }

  threads.clear();

  while (NUMBER_OF_THREADS > 1) {
    PARTITION_SIZE = size / NUMBER_OF_THREADS;

    for (int i = 0; i < NUMBER_OF_THREADS; i += 2) {
      int* partition1 = &arr[PARTITION_SIZE * i];
      int* partition2 = &arr[PARTITION_SIZE * (i + 1)];

      threads.emplace_back(mergeInPlace, partition1, partition2,
                           PARTITION_SIZE);
    }

    for (auto& thread : threads) {
      thread.join();
    }

    threads.clear();

    NUMBER_OF_THREADS /= 2;
  }

  std::cout << "Total Swaps: " << totalSwaps << "\n";

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