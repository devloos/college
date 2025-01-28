#include "hw05.hpp"

void prpyr(int dimension,char character) {

		for (int i = 1; i <= dimension; ++i) {
			for (int j = 1; j <= i; ++j) {
				cout << character << " ";
			}
			cout << endl;
		}
}

