/*
 * 11831.cpp
 *
 *  Created on: Jul 27, 2015
 *      Author: Ivan
 */

// 11831 - Sticker Collector Robot

#include <cstdio>
#include <vector>
#include <cstring>
#include <cctype>
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
using namespace std;

typedef vector<int> vi;

char directions[4] = {'N', 'L', 'S', 'O'};
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int main() {
	int N, M, S;
	int x, y;
	int dir;
	while(scanf("%d %d %d", &N, &M, &S) && (N | M | S)) {
		char grid[N][M];
		char str[S];
		int count = 0;

		for(int i = 0; i < N; i++) {
			scanf("%s", &grid[i]);
			for(int j = 0; j < M; j++) {
				if(isalpha(grid[i][j])) {
					x = i; y = j;
					if(grid[x][y] == directions[NORTH]) dir = NORTH;
					if(grid[x][y] == directions[EAST]) dir = EAST;
					if(grid[x][y] == directions[SOUTH]) dir = SOUTH;
					if(grid[x][y] == directions[WEST]) dir = WEST;
				}
			}
		}

		scanf("%s", &str);

		// algorithm
		for(int i = 0; i < S; i++) {
			if(str[i] == 'D') { // turn 90 degrees to the right
				dir = (dir + 1) % 4;
				grid[x][y] = directions[dir];
			}
			if(str[i] == 'E') {
				dir = (dir + 4 - 1) % 4;
				grid[x][y] = directions[dir];
			}
			if(str[i] == 'F') {
				if(x + dr[dir] >= 0 && x + dr[dir] < N && y + dc[dir] >= 0 && y + dc[dir] < M) {
					if(grid[x + dr[dir]][y + dc[dir]] != '#') {
						grid[x][y] = '.';
						x += dr[dir];
						y += dc[dir];
						if(grid[x][y] == '*') count++;
						grid[x][y] = directions[dir];
					}
				}
			}
		}
		printf("%d\n", count);
	}

	return 0;
}


