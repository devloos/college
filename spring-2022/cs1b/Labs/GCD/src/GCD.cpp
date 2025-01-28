#include "main.hpp"
/****************************************************************************
 * Title: GCD
 * --------------------------------------------------------------------------
 * This function will return a GCD of 2 integers
 * --------------------------------------------------------------------------
 * int largerValue CALC  - larger value taken from user
 * int smallerValue CALC - smaller value taken from user
 * int remainder CALC - remainder from mod of larger and smaller value
 ***************************************************************************/

int GCD(int largerValue, int smallerValue)
{
    int remainder {};
    do
    {
        remainder = largerValue % smallerValue; //mod to integers and store remainder in remainder
        if(remainder != 0) {//if remainder does not equal 0
            largerValue = smallerValue;
            smallerValue = remainder;
        }
    } while (remainder != 0);//once remainder equals 0 then we exit while loop

    return smallerValue;//return current small number
}