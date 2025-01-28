#include "hw05.hpp"
#include <iostream>

void prmenu() {
	
	int choice;
	int dimension;
	char character;
	
	while (cin) {

		cout << "1. Sqaure " << endl;
		cout << "2. Right Triangle " << endl;
		cout << "3. Triangle " << endl;
		cout << "4. Upsidown Triangle " << endl;
		cout << "5. Exit " << endl;

		cout << " Choice: ";
		cin >> choice;
		if (choice < 5) {
			cout << " Dimension: ";
			cin >> dimension;
			cout << " character: ";
			cin >> character;
		}
		if (choice == 1) {
			prsqu(dimension,character);
		}
		else if (choice == 2) {
			prrtri(dimension,character);
		}
		else if (choice == 3) {
			prpyr(dimension,character);
		}
		else if (choice == 4) {
			pruppyr(dimension,character);
		}
		else if (choice == 5) {
			cout << "End of Program" << endl;
		        break;
		}
	}

}
