#include "hw07.h"

void prsub(int a[3][3],int b[3][3],int sub[3][3]) {
	cout<<"Enter value for matrix A: "<<endl;

	for (int i=0;i<3;i++) {
        	for (int k=0;k<3;k++) {
                	cin>>a[i][k];
        	}
	}

	cout<<"Enter value for matrix B: "<<endl;

	for (int i=0;i<3;i++) {
        	for (int k=0;k<3;k++) {
                	cin>>b[i][k];
        	}
	}

	for (int i=0;i<3;i++) {
        	for (int k=0;k<3;k++) {
                	sub[i][k]=a[i][k]-b[i][k];
        	}
	}
	cout<<"Subtracting Matrices.....: "<<endl;

	for (int i=0;i<3;i++) {
        	for (int k=0;k<3;k++) {
                	cout<<sub[i][k];
        	}
		cout<<endl;
	}	
}
