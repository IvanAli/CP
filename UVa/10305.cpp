/*
 * 10305.cpp
 *
 *  Created on: Aug 3, 2015
 *      Author: Ivan
 */

// 10305 - Ordering Tasks

#include <cstdio>
#include <vector>
#include <deque>
#define UNVISITED -1
#define VISITED 1
using namespace std;

typedef vector<int> vi;

deque<int> d;
vector<vi> AdjList;
vi dfs_num;

void toposort(int u) {
	dfs_num[u] = VISITED;
	for(int j = 0; j < AdjList[u].size(); j++) {
		int v = AdjList[u][j];
		if(dfs_num[v] == UNVISITED) toposort(v);
	}
	d.push_front(u);
}

int main() {
	int n, m;
	int u, v;
	while(scanf("%d %d", &n, &m) && (n | m)) {
		AdjList.assign(n, vi());
		dfs_num.assign(n, UNVISITED);
		d.clear();
		for(int i = 0; i < m; i++) {
			scanf("%d %d", &u, &v);
			AdjList[u - 1].push_back(v - 1);
		}

		// algorithm
		for(int i = 0; i < n; i++) {
			if(dfs_num[i] == UNVISITED) toposort(i);
		}
		for(int i = 0; i < n; i++) {
			if(i) printf(" ");
			printf("%d", d[i] + 1);
		}
		printf("\n");

	}

	return 0;
}


