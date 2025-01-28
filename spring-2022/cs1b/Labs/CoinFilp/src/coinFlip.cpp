#include "stdlib.h"
#include "time.h"

bool coinFlip()
{
    srand(time(NULL));//sets seed to time function gets called
    return static_cast<bool>(rand() % 2);//returns 0 or 1 and gets casted to a bool
}