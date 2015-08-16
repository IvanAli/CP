/*
 * 12455.cpp
 *
 *  Created on: Jul 6, 2015
 *      Author: Ivan
 */
// 12455 - Bars

#include <cstdio>
#include <bitset>
using namespace std;

int fac(int x) {
	if(x == 0 || x == 1) return 1;
	return x * fac(x - 1);
}

int main() {
	int t, n, p;
	bool found;
	int *A;
	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);
		scanf("%d", &p);
		A = new int[p];
		found = false;
		for(int i = 0; i < p; i++) scanf("%d", &A[i]);

		for(int i = 0; i < (1 << p); i++) {
			if(found) break;
			int sum = 0;
			for(int j = 0; j < p; j++) {
				if(i & (1 << j)) {
					sum += A[j];
				}
			}
			if(sum == n) found = true;
		}
		printf("%s\n", found ? "YES" : "NO");
	}

	return 0;
}



