/*
 * 796.cpp
 *
 *  Created on: Aug 7, 2015
 *      Author: Ivan
 */

// 796 - Crtical Links

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

#define UNVISITED -1
#define VISITED

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vi> AdjList;
int AdjMatrix[1000][1000];
vi dfs_num;
vi dfs_low;
vi dfs_parent;
vector<bool> articulation_vertex;
int root;
int dfs_count;
int rootChildren;
priority_queue<ii, vector<ii>, greater<ii> > bridges;

void articulationPoints(int u) {
	dfs_num[u] = dfs_low[u] = dfs_count++;
	for(int j = 0; j < AdjList[u].size(); j++) {
		int v = AdjList[u][j];
		if(dfs_num[v] == UNVISITED) {
			dfs_parent[v] = u;
			if(root == u) rootChildren++;
			articulationPoints(v);

			if(dfs_low[v] >= dfs_num[u]) {
				articulation_vertex[u] = true;
			}
			if(dfs_low[v] > dfs_num[u]) {
				if(u < v) bridges.push(ii(u, v));
				else bridges.push(ii(v, u));
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if(dfs_parent[u] != v) { // this probably means that there's a back edge
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

int main() {
	int n, k, a, b, parindex, len;
	char s[10000];
	char s2[10000];

	while(scanf("%d", &n) != EOF) {
		getc(stdin);
		AdjList.assign(n, vi());
		dfs_num.assign(n, UNVISITED);
		dfs_low.assign(n, UNVISITED);
		dfs_parent.assign(n, -1);
		articulation_vertex.assign(n, false);

		dfs_count = 0;
		for(int i = 0; i < n; i++) {
			gets(s);
			len = strlen(s);


			sscanf(s, "%d (%d)", &a, &k);
			if(k == 0) continue;
			for(parindex = 0; s[parindex] != ')'; parindex++);

			// printf("a: %d, k: %d\n", a, k);
			strcpy(s2, s + parindex + 2);

			len = strlen(s2);

			char *pch;
			pch = strtok(s2, " ");

			while(pch != NULL) {
				sscanf(pch, "%d", &b);
				AdjList[a].push_back(b);
				//AdjList[b].push_back(a);
				// printf("%d AND %d\n", AdjList[a].back(), AdjList[b].back());
				pch = strtok(NULL, " ");
			}
		}

		// algorithm
		for(int i = 0; i < n; i++) {
			if(dfs_num[i] == UNVISITED) {
				root = i;
				rootChildren = 0;
				dfs_count = 0;
				articulationPoints(i);
				articulation_vertex[root] = rootChildren > 1;
			}
		}
		printf("%d critical links\n", bridges.size());
		while(!bridges.empty()) {
			printf("%d - %d\n", bridges.top().first, bridges.top().second);
			bridges.pop();
		}

		printf("\n");
	}

	return 0;
}


