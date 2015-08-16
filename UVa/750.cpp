/*
 * 750.cpp
 *
 *  Created on: Jul 7, 2015
 *      Author: Ivan
 */
// 750 - 8 Queens Chess Problem

#include <cstdio>
#include <cstdlib>
#include <cstring>

int t, rowc, colc, rows[8], sol;

bool inPlace(int row, int col) {
	for(int i = 0; i < col; i++) {
		if(rows[i] == row) return false;
		if(abs(rows[i] - row) == abs(i - col)) return false;
	}
	return true;
}

void backtrack(int col) {
	if(col == 8) {
		if(rows[colc] == rowc) {
			printf("%2d      %d", ++sol, rows[0] + 1);
			for(int i = 1; i < 8; i++) printf(" %d", rows[i] + 1);
			printf("\n");
		}
	}

		for(int row = 0; row < 8; row++) {
			if(inPlace(row, col)) {
				rows[col] = row;
				backtrack(col + 1);
			}
		}

}

int main() {

	scanf("%d", &t);

	while(t--) {
		scanf("%d %d", &rowc, &colc);
		rowc--;
		colc--;
		memset(rows, 0, sizeof(rows));
		sol = 0;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		backtrack(0);

		if(t) printf("\n");

	}
	return 0;
}



