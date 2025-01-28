#include "main.hpp"

void upsideDownTriangle(int dimension, char charater)
{
    for(size_t i {0}; i < dimension; i++)
    {
        for(size_t j {0}; j <= i; j++)
            std::cout << " ";
        for(int k {dimension}; k > i; k--)
            std::cout << charater << " ";
        std::cout << "\n";
    }
}