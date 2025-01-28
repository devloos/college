#include "main.hpp"

double sumofBalances(size_t sizeofArray, double arrayofBalances[])
{
	double balanceSum {};
	for(size_t i {0}; i < sizeofArray; i++)
		balanceSum += arrayofBalances[i];//takes in balance for each iteration of the for loop and plus equals it
	return balanceSum;//returns result
}