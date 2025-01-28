#include "hw05.hpp"

void prrtri(int dimension,char character) {
	
		for (int i = 1; i <= dimension; ++i) {
			for (int k = 0; k < (dimension - i); ++k) {
				cout << " ";
			}
			for (int j = 0; j < i; ++j) {
				cout << character << " ";
			}
			cout << endl;
		}
}

