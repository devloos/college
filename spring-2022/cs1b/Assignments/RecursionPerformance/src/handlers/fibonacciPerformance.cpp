#include "../../include/header.h"

void fibonacciPerformance(long long n) {
  std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now(); 
  for (int i = 0; i < 1000000; i++)
    recursiveFibRaw(n);
  std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now(); 
  std::chrono::duration<double> recursiveTime =  end - start;

  start = std::chrono::high_resolution_clock::now(); 
  for (int i = 0; i < 1000000; i++)
    iterativeFibRaw(n);
  end = std::chrono::high_resolution_clock::now(); 
  std::chrono::duration<double> iterationTime = end - start;
 
  std::cout << "Fibonacci Recursive in seconds: " << recursiveTime.count() << "\n";
  std::cout << "Fibonacci Iterative in seconds: " << iterationTime.count() << "\n\n";
}