/*
 * ejerciciometnum.cpp
 *
 *  Created on: Aug 12, 2015
 *      Author: Ivan
 */

#include <cstdio>
#include <cmath>

double absoluteError(double a, double b) {
	return fabs(a - b);
}

double relativeError(double a, double b) {
	return absoluteError(a, b) / a;
}

int main() {
	printf("x:\n");
	printf("Error absoluto: %f\n", absoluteError(0.00347, 0.0035));
	printf("Error relativo: %f\n", relativeError(0.00347, 0.0035));
	printf("y:\n");
	printf("Error absoluto: %f\n", absoluteError(30.158, 30.16));
	printf("Error relativo: %f\n", relativeError(30.158, 30.16));
	return 0;
}


