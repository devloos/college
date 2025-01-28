#include "../include/main.hpp"

void outputResults(const size_t &totalFlipCount, size_t averageHeadFlip)
{
    /*
        const size_t &totalFlipCount; OUT -total flip count
        size_t averageHeadFlip; OUT -average head flip per total flips in percentage
    */

    std::cout << "It took you " << totalFlipCount << " tosses to get 3 heads in a row.\n";
    std::cout << "On average you flipped heads " << averageHeadFlip << "% "<< "of the time\n";
}