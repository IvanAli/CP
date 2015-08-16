/*
 * 722.cpp
 *
 *  Created on: Jul 31, 2015
 *      Author: Ivan
 */

// 722 - Lakes

#include <cstdio>
#include <cstring>

int maxr, maxc;
int grid[100][100];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};
int cc;

void floodfill(int r, int c, int c1, int c2) {
	if(r < 0 || r >= maxr) return;
	if(c < 0 || c >= maxc) return;
	if(grid[r][c] != c1) return;
	grid[r][c] = c2;
	cc++;
	for(int j = 0; j < 4; j++) {
		if(grid[r + dr[j]][c + dc[j]] == c1) {
			floodfill(r + dr[j], c + dc[j], c1, c2);
		}
	}
}

int main() {
	int T, r, c;
	char pos[5];
	char s[100];
	int len;
	int currRow;

	scanf("%d", &T);
	getc(stdin); getc(stdin);
	for(int t = 0; t < T; t++) {
		if(t) printf("\n");
		currRow = 0;
		cc = 0;
		gets(s);
		sscanf(s, "%d %d", &r, &c);

		while(gets(s) && (len = strlen(s))) {
			maxc = len;
			for(int j = 0; j < len; j++) {
				grid[currRow][j] = s[j] - '0';
			}
			currRow++;
		}
		maxr = currRow;
		r--; c--;
		floodfill(r, c, 0, 2);
		printf("%d\n", cc);
		floodfill(r, c, 2, 0);
	}

	return 0;
}

