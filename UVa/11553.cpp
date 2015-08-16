/*
 * 11553.cpp
 *
 *  Created on: Jul 8, 2015
 *      Author: Ivan
 */

// 11553 - Grid Game

#include <cstdio>
#include <cstdlib>

int t, n, **grid, *row, sum, max, min, sign;

bool isCross(int r, int c) {
	for(int prev = 0; prev < c; prev++) {
		if(row[prev] == r) return false;
	}
	return true;
}

void backtrack(int c) {
	sum = 0;
	if(c == n) {
		for(int i = 0; i < n; i++) {
			sum += grid[row[i]][i];
		}
		if(min > sum) min = sum;
	}
	for(int r = 0; r < n; r++) {
		if(isCross(r, c)) {
			row[c] = r;
			backtrack(c + 1);
		}
	}
}

int main() {

	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);

		grid = new int*[n];
		for(int i = 0; i < n; i++) grid[i] = new int[n];
		row = new int[n];

		sum = 0;
		max = 0;
		min = 1 << 15;

		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				scanf("%d", &grid[i][j]);

		// algo
		backtrack(0);
		printf("%d\n", min);
		// printf("%d\n", sign ? -max : max);

	}

	return 0;
}


