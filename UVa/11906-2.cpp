/*
 * 11906-2.cpp
 *
 *  Created on: Jul 29, 2015
 *      Author: Ivan
 */

// 11906 2 - Knight in a War Grid

#include <cstdio>
#include <vector>
#include <algorithm>
#define UNVISITED -1
#define VISITED 1
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

int R, C, M, N, W;
vector<vi> Matrix;
vector<vi> dfs_xy;

int nr, nc;
int vr[4] = {1, 1, -1, -1};
int vc[4] = {1, -1, -1, 1};

void dfs(int r, int c) {
	dfs_xy[r][c] = VISITED;
	for(int j = 0; j < 4; j++) {
		nr = r + N * vr[j];
		nc = c + M * vc[j];
		if((nr < R && nr >= 0) && (nc < C && nc >= 0) && Matrix[nr][nc] != -1) {
			Matrix[r][c]++;
			if(dfs_xy[nr][nc] == UNVISITED)
				dfs(nr, nc);
		}
		if(M != N) {
			nr = r + M * vr[j];
			nc = c + N * vc[j];
			if((nr < R && nr >= 0) && (nc < C && nc >= 0) && Matrix[nr][nc] != -1) {
				Matrix[r][c]++;
				if(dfs_xy[nr][nc] == UNVISITED)
					dfs(nr, nc);
			}
		}
	}
}


int main() {
	int tc;
	int even, odd;
	int x, y;

	scanf("%d", &tc);
	for(int t = 0; t < tc; t++) {
		scanf("%d %d %d %d", &R, &C, &M, &N);
		scanf("%d", &W);

		Matrix.assign(R, vi(C, 0));
		dfs_xy.assign(R, vi(C, UNVISITED));

		for(int j = 0; j < W; j++) {
			scanf("%d %d", &x, &y);
			Matrix[x][y] = -1;
		}

		// algorithm
		even = 0; odd = 0;

		dfs(0, 0);

		int div = !(N && M) ? 2 : 1;
		for(int i = 0; i < R; i++) {
			for(int j = 0; j < C; j++) {
				if(dfs_xy[i][j] == VISITED) {
					if((Matrix[i][j] / div) % 2 == 0) even++;
					else odd++;
				}
			}
		}
		printf("Case %d: %d %d\n", t + 1, even, odd);
	}

	return 0;
}






