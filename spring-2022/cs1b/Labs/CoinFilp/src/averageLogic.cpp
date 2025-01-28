#include "../include/main.hpp"

size_t averageLogic(const size_t &totalHeadCount, const size_t &totalFlipCount)
{
    /*
        size_t totalHeadCount; CALC -Gets divided by totalFlipCount
        size_t totalFlipCount; CALC -Divides totalHeadCount and the result gets multiplied
    */
    return double(totalHeadCount)/totalFlipCount * 100; // returns a type size_t variable
}