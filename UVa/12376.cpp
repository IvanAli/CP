/*
 * 12376.cpp
 *
 *  Created on: Jul 31, 2015
 *      Author: Ivan
 */

// 12376 - As Long as I Learn, I Live

#include <cstdio>
#include <vector>
using namespace std;

#define UNVISITED -1
#define VISITED 1

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vi units;
vector<vii> AdjList;
int total;
int last;

void dfs(int u) {
	int route = -1;
	int w = 0;
	for(int j = 0; j < AdjList[u].size(); j++) {
		ii v = AdjList[u][j];
		if(v.second > w) {
			route = v.first;
			w = v.second;
		}
	}
	if(route != -1) {
		total += w;
		dfs(route);
	}
	else {
		last = u;
	}
}

int main() {
	int T, n, m, u, v;
	scanf("%d", &T);

	for(int t = 0; t < T; t++) {
		scanf("%d %d", &n, &m);
		total = 0;
		units.assign(n, 0);
		AdjList.assign(n, vii());
		for(int i = 0; i < n; i++) scanf("%d", &units[i]);
		for(int i = 0; i < m; i++) {
			scanf("%d %d", &u, &v);
			AdjList[u].push_back(ii(v, units[v]));
		}

		// algorithm
		dfs(0);
		printf("Case %d: %d %d\n", t + 1, total, last);

	}
	return 0;
}

