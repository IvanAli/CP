/*
 * 10341.cpp
 *
 *  Created on: Jul 23, 2015
 *      Author: Ivan
 */

// 10341 - Solve It

#define EPS 1e-10
#include <cstdio>
#include <algorithm>
#include <cmath>

int p, q, r, s, t, u;

double function(double x) {
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main() {

	double x;
	double low = 0;
	double high = 1;
	bool found;

	// p ∗ e^−x + q ∗ sin(x) + r ∗ cos(x) + s ∗ tan(x) + t ∗ x2 + u = 0
	while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {
		x = 0; low = 0; high = 1;
		found = false;
		// printf("%f\n", function(0.7071));
		double a = function(0); double b = function(1);
		if(a > 0 && b > 0) printf("No solution\n");
		else if(a < 0 && b < 0) printf("No solution\n");
		else if(a == 0) printf("0.0000\n");
		else if(b == 0) printf("1.0000\n");
		else {
			while(fabs(high - low) > EPS) {
				// printf("x: %f, h: %f, l: %f\n", x, high, low);


				x = (high + low) / 2.0;
				if(function(x) < EPS) {
					high = x;
				}
				else if(function(x) > -EPS){
					low = x;
				}

			}
			printf("%.4f\n", x);
		}


	}


	return 0;
}


