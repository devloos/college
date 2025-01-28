#include "main.hpp"

void triangle(int dimension, char charater)
{
    for(size_t i {0}; i < dimension; i++)
    {
        for(int j {dimension}; j > i; j--)
        {
            std::cout << " ";
        }
        for(size_t k {0}; k <= i; k++)
        {
            std::cout << charater << " ";
        }
        std::cout << "\n";
    }

}