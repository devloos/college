/*
* hw01.cpp: average of 5 numbers
*
* author: Carlos Aguilera
* class: Cs1a, Fall 2019, 80540
*
* modifications:
* 09/06/19 CA
*/
#include <iostream>

using namespace std;

int main() {
	double score1 = 32.6;
	double score2 = 55;
	double score3 = 67.3;
	double score4 = 43;
	double score5 = 87;

	double avg;

	avg = (score1 + score2 + score3 + score4 + score5)/5;

	cout << "The average is: " << avg << endl;

	return 0;
}
