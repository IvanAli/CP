/*
 * functionerror.cpp
 *
 *  Created on: Aug 12, 2015
 *      Author: Ivan
 */

#include <cstdio>
#include <cmath>

double f(double x) {
	return pow(x, 3) - 6.1 * pow(x, 2) + 3.2 * x + 1.5;
}

double ftrunc(double x) {
	return trunc(pow(x, 3)) - trunc(6.1 * pow(x, 2)) + trunc(3.2 * x) + trunc(1.5);
}

double relativeTruncateError(double x) {
	return fabs((f(x) - ftrunc(x)) / f(x));
}

int main() {
	printf("%f\n", f(4.71));
	printf("%f\n", relativeTruncateError(4.71));
	return 0;
}

