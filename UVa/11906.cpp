/*
 * 11906.cpp
 *
 *  Created on: Jul 28, 2015
 *      Author: Ivan
 */

// 11906 - Knight in a War Grid

#include <cstdio>
#include <vector>
#include <algorithm>
#define UNVISITED -1
#define VISITED 1
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

int R, C, M, N, W;
vector<vi> AdjList;
vector<ii> water;

int vr[4] = {1, 1, -1, -1};
int vc[4] = {1, -1, -1, 1};
vi dfs_num;

bool containsWater(int r, int c) {
	for(int k = 0; k < water.size(); k++) {
		if(r == water[k].first && c == water[k].second) return true;
	}
	return false;
}

void dfs(int u) {
	dfs_num[u] = VISITED;
	for(int j = 0; j < 4; j++) {
		int r = u / R + N * vr[j];
		int c = u % C + M * vc[j];
		if((r < R && r >= 0) && (c < C && c >= 0)) {
			if(!containsWater(r, c)) {
				int v = r + c + (C - 1) * r;
				AdjList[u].push_back(v);
				//printf("%d pushed to %d at %d\n", v, u, j);
				//printf("%d: %d at [%d, %d]\n", u, v, r, c);
				if(dfs_num[v] == UNVISITED) {

					dfs(v);
				}
			}


		}
		if(M == N) continue;
		r = u / R + M * vr[j];
		c = u % C + N * vc[j];
		if((r < R && r >= 0) && (c < C && c >= 0)) {
			if(!containsWater(r, c)) {
				int v = r + c + (C - 1) * r;
				AdjList[u].push_back(v);
				//printf("%d pushed to %d at %d\n", v, u, j);
				//printf("%d: %d at [%d, %d] here\n", u, v, r, c);
				if(dfs_num[v] == UNVISITED) {

					dfs(v);
				}
			}


		}
	}
}

int main() {
	int tc;
	int even, odd;
	int x, y;

	scanf("%d", &tc);
	for(int i = 0; i < tc; i++) {
		scanf("%d %d %d %d", &R, &C, &M, &N);
		scanf("%d", &W);
		water.clear();

		for(int j = 0; j < W; j++) {
			scanf("%d %d", &x, &y);
			water.push_back(ii(x, y));
		}
		even = 0; odd = 0;


		AdjList.assign(R * C, vi());
		dfs_num.assign(R * C, UNVISITED);
		dfs(0);

		int sz;
		for(int j = 0; j < AdjList.size(); j++) {
			if(dfs_num[j] == UNVISITED) continue;
			sz = AdjList[j].size();
			if(!N || !M) sz /= 2;
			if(sz % 2 == 0) even++;
			else odd++;
			//printf("%d size: %d\n", j, AdjList[j].size());
		}
		printf("Case %d: %d %d\n", i + 1, even, odd);
	}

	return 0;
}


