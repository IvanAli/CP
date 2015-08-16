/*
 * 11953.cpp
 *
 *  Created on: Aug 1, 2015
 *      Author: Ivan
 */

// 11953 - Battleships

#include <cstdio>

char grid[100][100];
int maxrow, maxcol;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};

int floodfill(int r, int c, char c1, char c2, char c3) {
	if(r < 0 || r >= maxrow) return 0;
	if(c < 0 || c >= maxcol) return 0;
	// if(!flag) if(grid[r][c] != c1) return 0;
	if(grid[r][c] != c1 && grid[r][c] != c2) return 0;
	int ans = 1;
	grid[r][c] = c3;
	for(int d = 0; d < 4; d++) {
		ans += floodfill(r + dr[d], c + dc[d], c1, c2, c3);
	}
	return ans;
}

int main() {
	int T, N;
	int ncc;
	char str[100];
	scanf("%d", &T);

	for(int t = 0; t < T; t++) {
		scanf("%d", &N);
		maxcol = N; maxrow = N;
		ncc = 0;
		for(int i = 0; i < N; i++) {
			scanf("%s", &str);
			for(int j = 0; j < N; j++) {
				grid[i][j] = str[j];
			}
		}


		// algorithm
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if(grid[i][j] == 'x') {
					floodfill(i, j, 'x', '@', 'y');
					ncc++;
				}
			}
		}
		printf("Case %d: %d\n", t + 1, ncc);
	}

	return 0;
}


