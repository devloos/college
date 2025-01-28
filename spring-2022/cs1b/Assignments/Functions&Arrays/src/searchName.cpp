#include "main.hpp"

int searchName(std::string inputName, size_t sizeofArray, std::string arrayofNames[])
{
    for(size_t i {0}; i < sizeofArray; i++)
    {
        if(inputName == arrayofNames[i])//checking if the name user inputed exists
            return i;// returns index if true
    }
    return -1;//returns -1 if not found
}