/*
 * Manipulation of arrays
 * Author: Carlos Aguilera
 * Class: Cs1b
 */
#include "hw04.h"

int main()
{
    int ar[] = {23,32,4,43,56,6,75,1,3,78,65,97,44,66,99,22};
    int size = 16;
    int n = 3;
    //int *p = nullptr;
    //p = &ar[3];
    //p++;  ******* tried pointers on the day of the lesson

    std::cout << "Original Array: {";
    for(int i = 0; i < size; ++i)
    {
        std::cout << ar[i] << ",";
    }
    std::cout << "}" << std::endl;

    size *= .20;
    size = size + n;
    slider(ar, size, n);
    size = 16;

    std::cout << "Altered Array: {";
    for(int i = 0; i < size; ++i)
    {
        std::cout << ar[i] << ",";
    }
    std::cout << "}" << std::endl;
}