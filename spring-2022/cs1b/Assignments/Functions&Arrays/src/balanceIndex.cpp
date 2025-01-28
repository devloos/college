#include "main.hpp"

int balanceIndex(char selection, size_t sizeofArray, double arrayofBalances[])
{
	if(selection == '1')//if user chose larger in the menu selection
	{
		int index {};
		double balance {arrayofBalances[0]};//did not want to use a nested for loop so initialized balance to index 0 of arrayofBalances
		for(size_t i {1}; i < sizeofArray; i++)
		{
			if(arrayofBalances[i] > balance)//if array of balances at index i is greater than balance(because we want the largest) then assign it to balance and assign i to index
			{
				balance = arrayofBalances[i];
				index = i;
			}
		}
		return index;
	}else {
		int index {};
		double balance {arrayofBalances[0]};
		for(size_t i {1}; i < sizeofArray; i++)
		{
			if(arrayofBalances[i] < balance)//same thing but for smallest value
			{
				balance = arrayofBalances[i];
				index = i;
			}
		}
		return index;
	}
}