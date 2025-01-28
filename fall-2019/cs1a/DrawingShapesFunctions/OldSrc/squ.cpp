#include "hw05.hpp"
void prsqu(int dimension,char character) {

		for (int i = 0; i <= dimension - 1; ++i) {
			for (int j = 0; j <= dimension - 1; ++j) {
		       		cout << character << " ";
			}	
			cout << endl;
		}
}

