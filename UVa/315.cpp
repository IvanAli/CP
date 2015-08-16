/*
 * 315.cpp
 *
 *  Created on: Aug 3, 2015
 *      Author: Ivan
 */

// 315 - Network

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define UNVISITED -1
using namespace std;

typedef vector<int> vi;

vector<vi> AdjList;
vi dfs_num;
vi dfs_low;
vi dfs_parent;
vi artpoints;
int rootChildren;
int dfsRoot;
int dfsIteration;

void artPoint(int u) {

	dfs_num[u] = dfs_low[u] = dfsIteration++;
	for(int j = 0; j < AdjList[u].size(); j++) {
		int v = AdjList[u][j];
		if(dfs_num[v] == UNVISITED) {
			dfs_parent[v] = u;
			if(dfsRoot == u) rootChildren++;
			artPoint(v);

			if(dfs_low[v] >= dfs_num[u]) {
				artpoints[u] = 1;
			}

			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if(dfs_parent[u] != v) {
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

int main() {
	int N;
	int a, b;
	char str[10000];

	while(scanf("%d", &N) && N) {
		rootChildren = 0;
		dfsRoot = 0;
		dfsIteration = 0;
		AdjList.assign(N, vi());
		dfs_num.assign(N, UNVISITED);
		dfs_low.assign(N, 0);
		dfs_parent.assign(N, -1);
		artpoints.assign(N, 0);

		getc(stdin);
		while(gets(str)) {
			char *pch;
			pch = strtok(str, " ");
			sscanf(pch, "%d", &a);
			if(!a) break;
			while(pch != NULL) {
				pch = strtok(NULL, " ");
				if(pch == NULL) break;
				sscanf(pch, "%d", &b);

				AdjList[a - 1].push_back(b - 1);
				AdjList[b - 1].push_back(a - 1);
			}
		}
		for(int i = 0; i < N; i++) {
			if(dfs_num[i] == UNVISITED) {
				dfsRoot = i;
				dfsIteration = 0;
				rootChildren = 0;
				artPoint(i);
				artpoints[i] = rootChildren > 1;
			}
		}
		int count = 0;
		for(int i = 0; i < N; i++) {
			if(artpoints[i]) count++;
		}
		printf("%d\n", count);

	}
	return 0;
}
