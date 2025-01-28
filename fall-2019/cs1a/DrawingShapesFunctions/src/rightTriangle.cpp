#include "main.hpp"

void rightTriangle(int dimension, char character)
{
    for(size_t i {0}; i < dimension; i++)
    {
        for(size_t j {0}; j <= i; j++)
            std::cout << character << " ";
        std::cout << "\n";
    }
}