//
// Created by Carlos Aguilera on 3/2/20.
//

#include "hw04.h"

void slider(int ar[], int size, int n)
{
    for(int i = n; i >= 0; --i)
    {
        ar[size] = ar[i];
        size = size - 1;

    }
}
