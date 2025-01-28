#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

/*******************************************************************************
 * heading
 ------------------------------------------------------------------------------- 
 * FUNCTION: this function prints out heading
 * @param
 * RETURNS - void
 ******************************************************************************/
void heading();

/*******************************************************************************
 * gcd
 ------------------------------------------------------------------------------- 
 * FUNCTION: This is a recursive function that takes in two values and finds the
 * greatest common divisor for them
 * @param m value being divided
 * @param n value to divide by
 * RETURNS - int
 ******************************************************************************/
int gcd(int m, int n);

#endif // HEADER_H_