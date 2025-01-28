#include "main.hpp"
/****************************************************************************
 * Title: sumofBalances
 * --------------------------------------------------------------------------
 * FUNCTION:
 * 	sums all balances in the array and returns it
 * --------------------------------------------------------------------------
 * Data Table
 * ----------
 * double balanceSum CALC - calcs balances sum
 ***************************************************************************/

double sumofBalances(size_t sizeofArray, Account arrayofAccounts[])
{
	double balanceSum {};
	for(size_t i {0}; i < sizeofArray; i++)
		balanceSum += arrayofAccounts[i].userBalance;//takes in balance for each iteration of the for loop and plus equals it
	return balanceSum;//returns result
}