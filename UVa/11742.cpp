/*
 * 11742.cpp
 *
 *  Created on: Jul 6, 2015
 *      Author: Ivan
 */

#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;
int num_permutation;
int *A;

int findPosition(int x) {
	for(int i = 0; i < n; i++)
		if(A[i] == x) return i;

}

bool checkCondition(int *a, int *b, int *c) {
	for(int i = 0; i < m; i++) {
		int posa = findPosition(a[i]);
		int posb = findPosition(b[i]);
		if(c[i] > 0) {
			if(abs(posb - posa) > c[i]) return false;
		}
		else {
			if(abs(posb - posa) < -c[i]) return false;
		}
	}
	return true;
}

int main() {
	int *a, *b, *c;
	int counter;

	while(scanf("%d %d", &n, &m) && (n || m)) {
		// if(n == 0 && m == 0) break;
		A = new int[n];
		a = new int[m];
		b = new int[m];
		c = new int[m];
		counter = 0;
		for(int i = 0; i < n; i++) A[i] = i;
		for(int i = 0; i < m; i++) {
			scanf("%d %d %d", &a[i], &b[i], &c[i]);
		}
		do {
			if(checkCondition(a, b, c))
				counter++;
		}
		while(next_permutation(A, A + n));
		printf("%d\n", counter);

	}
	return 0;
}


