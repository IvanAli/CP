/*
 * 10765.cpp
 *
 *  Created on: Aug 7, 2015
 *      Author: Ivan
 */

// 10765 - Doves and bombs

#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define UNVISITED -1
#define VISITED 1

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vi> AdjList;
vi dfs_num;
vi dfs_low;
vi dfs_parent;
vector<bool> articulation_vertex;
vi pigeons;
int dfsCount;
int dfsRoot;
int rootChildren;
priority_queue<ii> pq;


class UnionFind {
public:
	vi p;
	vi rank;
	int cc;
	UnionFind(int N) {
		cc = 0;
		p.assign(N, -1);
		rank.assign(N, 0);
		for(int i = 0; i < N; i++) {
			p[i] = i;
		}
	}
	int findSet(int i) {
		return p[i] == i ? i : p[i] = findSet(p[i]);
	}
	void unify(int i, int j) {
		if(findSet(i) != findSet(j)) {
			int x = p[i];
			int y = p[j];
			if(rank[x] < rank[y]) {
				p[i] = findSet(j);
				rank[x]--; rank[y]++;
				cc++;
			}
			else {
				p[j] = findSet(i);
				rank[x]++; rank[y]--;
				cc++;
			}
			AdjList[i].push_back(j);
			AdjList[j].push_back(i);
		}
	}
};

void articulationPoint(int u) {
	dfs_num[u] = dfs_low[u] = dfsCount++;
	for(int j = 0; j < AdjList[u].size(); j++) {
		int v = AdjList[u][j];
		if(dfs_num[v] == UNVISITED) {
			dfs_parent[v] = u;
			if(dfsRoot == u) rootChildren++;

			articulationPoint(v);

			if(dfs_low[v] >= dfs_num[u]) {
				pigeons[u]++;
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if(dfs_parent[u] != v) { // there's a back edge
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

int main() {
	int n, m, x, y, cc;
	while(scanf("%d %d", &n, &m) && (n | m)) {
		AdjList.assign(n, vi());
		dfs_num.assign(n, UNVISITED);
		dfs_low.assign(n, UNVISITED);
		dfs_parent.assign(n, -1);
		pigeons.assign(n, 0);
		cc = 0;
		// UnionFind UF(n);

		while(scanf("%d %d", &x, &y) && (x != -1 || y != -1)) {
			// UF.unify(x, y);
			AdjList[x].push_back(y);
			AdjList[y].push_back(x);
		}
		// algorithm
		for(int i = 0; i < n; i++) {
			if(dfs_num[i] == UNVISITED) {
				dfsRoot = i;
				dfsCount = 0;
				rootChildren = 0;
				articulationPoint(i);
				cc++;
				pigeons[i] = rootChildren - 1;
			}
		}

		for(int i = 0; i < n; i++) {
			pq.push(ii(pigeons[i] + cc, -i));
		}
		for(int i = 0; i < m; i++) {
			printf("%d %d\n", -pq.top().second, pq.top().first);
			pq.pop();
		}
		printf("\n");


	}
	return 0;
}
