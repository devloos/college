#include "hw06.h"

using namespace std;

double centerx = 0;
double centery = 0;
double pointx = 0;
double pointy = 0;
double radiusvalue = 0;

int main() {

	cout << "Enter X and Y values for the center coordinate of a circle: ";

	cin >> centerx >> centery;

	cout << "Enter the X and Y coordinates for any point on the circle: ";

	cin >> pointx;
	cin >> pointy;

	radiusvalue = radius(centerx, centery, pointx, pointy);

	cout << "Radius: " << radiusvalue << endl;
	cout << "Diameter: " << radiusvalue * 2 << endl;
	cout << "Circumference: " << circumference(radiusvalue) << endl;
	cout << "Area: " << area(radiusvalue) << endl;

	return 0;
}


