#include "../../include/header.h"

void factorialPerformance(long long n) {
  std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now(); 
  for (int i = 0; i < 500000000; i++)
    recursiveFactorialRaw(n);
  std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now(); 
  std::chrono::duration<double> recursiveTime =  end - start;

  start = std::chrono::high_resolution_clock::now(); 
  for (int i = 0; i < 500000000; i++)
    iterativeFactorialRaw(n);
  end = std::chrono::high_resolution_clock::now(); 
  std::chrono::duration<double> iterationTime = end - start;
 
  std::cout << "Factorial Recursive in seconds: " << recursiveTime.count() << "\n";
  std::cout << "Factorial Iterative in seconds: " << iterationTime.count() << "\n\n";
}