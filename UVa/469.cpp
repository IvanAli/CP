/*
 * 469.cpp
 *
 *  Created on: Jul 26, 2015
 *      Author: Ivan
 */

// 469 - Wetlands of Florida

#include <cstdio>
#include <cstring>
#include <cctype>

char grid[100][100];
// S, SE, E, NE, N, NW, W, SW
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int maxrow, maxcol;

int floodfill(int r, int c, char c1, char c2) {


	if(r < 0 || r >= maxrow || c < 0 || c >= maxcol) return 0;

	if(grid[r][c] != c1) return 0;
	int ans = 1;
	grid[r][c] = c2;
	for(int d = 0; d < 8; d++) {
		ans += floodfill(r + dr[d], c + dc[d], c1, c2);
	}
	return ans;
}

int main() {
	int tc;
	int currRow;
	int c, r;
	char str[100];


	scanf("%d", &tc);
	getc(stdin);
	getc(stdin);

	while(tc--) {


		currRow = 0;
		while(gets(grid[currRow]) && strlen(grid[currRow])) {
			// printf("scanned: %s\n", grid[currRow]);
			if(!currRow) maxcol = strlen(grid[0]);
			if(isdigit(grid[currRow][0])) {
				sscanf(grid[currRow], "%d %d", &r, &c);
				// printf("r: %d, c: %d\n", r, c);
				maxrow = currRow;
				printf("%d\n", floodfill(r - 1, c - 1, 'W', '.'));
				floodfill(r - 1, c - 1, '.', 'W');
			}
			else {
				currRow++;
			}
		}
		if(tc) printf("\n");


	}


	return 0;
}


