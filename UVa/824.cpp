/*
 * 824.cpp
 *
 *  Created on: Jul 31, 2015
 *      Author: Ivan
 */

// 824 - Coast Tracker

#include <cstdio>

int x, y, d;
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int getx(int xi) {
	return xi - x + 1;
}

int gety(int yi) {
	return (yi - y - 1) * -1;
}

int main() {

	int xi, yi, si;
	int grid[9][9];
	while(scanf("%d %d %d", &x, &y, &d) && x != -1) {
		grid[1][1] = d;
		for(int i = 0; i < 8; i++) {
			scanf("%d %d %d", &xi, &yi, &si);
			// printf("x: %d, y: %d\n", getx(xi), gety(yi));
			grid[gety(yi)][getx(xi)] = si;
		}
		// graph print
		/*for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				printf("%d|", grid[i][j]);
			}
			printf("\n");
		}*/
		// algorithm
		int xnext = (d + 7) % 8;
		for(int i = 0; i < 8; i++) {
			if(grid[1 + dr[xnext]][1 + dc[xnext]] == 1) {
				printf("%d\n", xnext);
				break;
			}
			xnext = (xnext + 1) % 8;
		}

	}
}


