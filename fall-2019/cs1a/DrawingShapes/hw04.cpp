/*
* Author: Carlos Aguilera
* Class: Cs1a, 2019, 80540
*/
#include <iostream>

using namespace std;

int main() {
	int choice;
	int dimension;
	char character;

	while (cin) {
		cout << "1. Sqaure " << endl;
		cout << "2. Right Triangle " << endl;
		cout << "3. Triangle " << endl;
		cout << "4. Upside Down Triangle " << endl;
		cout << "5. Exit Program " << endl;

		cout << " Choice: ";
		cin >> choice;
		cout << " Dimension: ";
		cin >> dimension;
		cout << " Character: ";
		cin >> character;

		if (choice == 1) {
			for (int i = 0; i <= dimension - 1; ++i) {
				for (int j = 0; j <= dimension - 1; ++j) {
					cout << character << " ";
				}
				cout << endl;

			}
		}
		if (choice == 2) {
			for (int i = 1; i <= dimension; ++i) {
				for (int j = 1; j <= i; ++j) {
					cout << character << " ";
				}
				cout << endl;
			}
		}
		if (choice == 3) {
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
		if (choice == 4) {
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
	}

		return 0;
	}
