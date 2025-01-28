#include "hw07.h"

void prmenu(int a[3][3],int b[3][3],int add[3][3],int sub[3][3],int ab[3][3],int mul) {
	int choice;

	while (cin) {

		cout << "1. Addition" << endl;
		cout << "2. Subtraction" << endl;
		cout << "3. Multiplication" << endl;
		cout << "4. Determinant" << endl;
		cout << "5. Exit" << endl;

		cout << "Choice: ";
		cin >> choice;
		if (choice == 1) {
			pradd(a,b,add);
		}
		else if (choice == 2) {
			prsub(a,b,sub);
		}
		else if (choice == 3) {
			prmul(ab,a,b,mul);
		}
		else if (choice == 4) {
			prdet();
		}
		else if (choice == 5) {
			cout<< "End of Program!"<<endl;
			break;
		}
		else {
			cout << "Choice is not valid." << endl; //telling user choice does not exist
		}
	}
}
