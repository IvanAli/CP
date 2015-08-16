/*
 * 12032.cpp
 *
 *  Created on: Jul 24, 2015
 *      Author: Ivan
 */

// 12032 - The Monkey and the Oiled Bamboo

#define EPS 1e7
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int tc, n;
int *A;
int min;
long ans;
long low, high, mid;

bool possibleK(int k) {
	int diff = A[0];
	for(int i = 1; i <= n; i++) {
		if(k - diff < 0) {
			return false;
		}
		if(k - diff == 0) k--;
		if(i != n) diff = A[i] - A[i - 1];
	}
	return true;
}

int main() {


	scanf("%d", &tc);

	for(int t = 0; t < tc; t++) {
		// min = 0;

		scanf("%d", &n);
		A = new int[n];
		for(int i = 0; i < n; i++) scanf("%d", &A[i]);

		// algorithm
		low = 1; high = EPS; mid = (low + high) / 2;
		// while(abs(high - low) > 1 || (low + high == 3)) {
		for(int y = 0; y < 25; y++) {
			mid = (low + high) / 2;
			// printf("mid: %d, low: %d, high: %d\n", mid, low, high);
			if(possibleK(mid)) {
				ans = mid;
				high = mid;
			}
			else {
				low = mid;
			}
			// printf("loop: %d, mid: %d\n", y + 1, ans);
		}


		/*min = A[0];
		for(int i = 0; i < n - 1; i++) {
			if(A[i + 1] - A[i] > min) min = A[i + 1] - A[i];
			else if(A[i + 1] - A[i] == min) min = A[i + 1] - A[i] + 1;
		}*/
		printf("Case %d: %d\n", t + 1, ans);
	}

	return 0;
}


