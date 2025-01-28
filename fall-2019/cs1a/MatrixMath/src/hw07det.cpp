#include "hw07.h"

void prdet() {
	int A[3][3];
	int det;
	int a,b,c;

	cout<< "Enter value for matrix A: "<<endl;

        for (int i=0; i<3; i++) {
                for (int k=0; k<3; k++) {
                        cin>>A[i][k];
                }
        }

        cout<< "Entered Matrix: "<<endl;

        for (int i=0; i<3; i++) {
                for (int k=0; k<3; k++) {
                        cout<<A[i][k]<< " ";
                }
                cout<<endl;

                a=A[0][0]*(A[1][1]*A[2][2]-A[1][2]*A[2][1]);
                b=A[0][1]*(A[1][0]*A[2][2]-A[1][2]*A[2][0]);
                c=A[0][2]*(A[1][0]*A[2][1]-A[1][1]*A[2][0]);
                det=a-b+c;
        }
        cout<<"Determinant of Matrix 3X3: "<<det<<endl;
}

