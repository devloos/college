#include "hw05.hpp"

void pruppyr(int dimension,char character) {
		for (int i = dimension; i >= 1; --i) {
			for (int k = 0; k < (dimension - i); ++k) {
				cout << " ";
			}
			for (int j = 0; j < i; ++j) {
				cout << character << " ";
			}
			cout << endl;
		}
}

