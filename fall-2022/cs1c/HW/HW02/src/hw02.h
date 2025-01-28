#ifndef HW02_H_
#define HW02_H_
#include <limits.h>

#include <array>
#include <cmath>
#include <iostream>
#include <string>

const int HW_SIZE_OF_ARRAY = 1230;

/**
 * @brief check if int n is a prime
 *
 * @param n
 * @return true
 * @return false
 */
bool isPrime(const int &n);

/**
 * @brief return first prime factor within PrimeNumbers
 *
 * @param PrimeNumbers
 * @param n
 * @return int
 */
int PrimeFactor(const std::array<int, HW_SIZE_OF_ARRAY> &PrimeNumbers, const int &n);

/**
 * @brief
 *
 * @param n
 */
void input(long &n);

/**
 * @brief
 *
 * @param PrimeNumbers
 * @param n
 */
void print(const std::array<int, HW_SIZE_OF_ARRAY> &PrimeNumbers, const long int &n);

#endif  // HW02_H_
