/*
 * 11413.cpp
 *
 *  Created on: Jul 24, 2015
 *      Author: Ivan
 */

// 11413 - Fill the Containers

#define EPS 1e6
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int *A;
long low, high, mid, ans;

bool canFill(int x) {
	int k = 0;
	int* con = new int[m];
	for(int i = 0; i < m; i++) con[i] = 0;

	for(int i = 0; i < n; i++) {
		if(k < m) {
			if(con[k] + A[i] > x) {
				k++;
				i--;
			}
			else {
				con[k] += A[i];
			}
		}
		else {
			return false;
		}

	}
	return true;


}

int main() {
	while(scanf("%d %d", &n, &m) != EOF) {
		A = new int[n];
		for(int i = 0; i < n; i++) {
			scanf("%d", &A[i]);
		}

		// algorithm
		low = 1; high = EPS;
		for(int i = 0; i < 25; i++) {
			mid = (low + high) / 2;
			if(canFill(mid)) {
				ans = mid;
				high = mid;
			}
			else {
				low = mid;
			}
		}
		printf("%d\n", ans);
	}
}


