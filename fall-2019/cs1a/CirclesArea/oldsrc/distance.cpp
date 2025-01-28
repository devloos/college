#include "hw06.h"

double distance(double point1x, double point1y, double point2x, double point2y) {
	return sqrt(pow((point2x - point1x), 2.0) + pow((point2y - point1y), 2.0));
}
