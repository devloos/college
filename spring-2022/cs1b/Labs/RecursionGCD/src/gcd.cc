#include "../include/header.h"

/*******************************************************************************
 * gcd
 ------------------------------------------------------------------------------- 
 * FUNCTION: This is a recursive function that takes in two values and finds the
 * greatest common divisor for them
 * @param m value being divided
 * @param n value to divide by
 * RETURNS - int
 ******************************************************************************/

int gcd(int m, int n) {
  // case if invalid n value
  if (n == 0) {
    return 0;
  }
  // base case if m % n == 0
  if (m % n == 0) {
    return n;
  }else { // else call func
    return gcd(m, m % n);
  }
}