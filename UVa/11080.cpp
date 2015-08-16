/*
 * 11080.cpp
 *
 *  Created on: Aug 3, 2015
 *      Author: Ivan
 */

// 11080 - Place the Guards

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define UNGUARDED -1
#define GUARDED 1
#define c1 0
#define c2 1
#define nocolor -1
#define VISITED 1
#define UNVISITED -1
#define INF 1 << 9

typedef vector<int> vi;

vector<vi> AdjList;
queue<int> q;
vi guards;
vi color;
vi incoming_degree;
vi dfs_num;
bool bipartite;
/*

int dfs(int u, int c) {
	color[u] = c;
	int ans = 0;
	bool g = true;
	for(int j = 0; j < AdjList[u].size(); j++) {
		int v = AdjList[u][j];
		if(guards[v] == GUARDED) {
			g = false;
		}
		if(color[v] == nocolor) {
			ans += dfs(v, 1 - color[u]);
		}
		else if(color[v] == color[u]) {
			bipartite = false;
		}
	}
	if(g) {
		guards[u] = GUARDED;
		printf("yes %d\n", u);
		for(int j = 0; j < AdjList[u].size(); j++) {
			int v = AdjList[u][j];
			guards[v] = GUARDED;
		}
		return ans + 1;
	}
	else return 0;
	if(bipartite) return ans;
	return -1;
}
*/

int bfs(int s) {
	q.push(s); //color[s] = 0;
	bipartite = true; bool g;
	int count = 0;
	int mindeg = INF; int umin = s;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		dfs_num[u] = VISITED;
		if(AdjList[u].size() < mindeg) {
			mindeg = AdjList[u].size();
			umin = u;
		}
		for(int j = 0; j < AdjList[u].size(); j++) {
			int v = AdjList[u][j];
			if(dfs_num[v] == UNVISITED) {
				q.push(v);
			}
		}
	}
	q.push(umin); color[umin] = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		if(guards[u] == GUARDED) g = false;
		else g = true;
		for(int j = 0; j < AdjList[u].size(); j++) {
			int v = AdjList[u][j];
			if(guards[v] == GUARDED) {
				g = false;
			}
			if(color[v] == INF) {
				color[v] = 1 - color[u];
				q.push(v);
			}
			else if(color[v] == color[u]) {
				bipartite = false;
				break;
			}
		}
		if(g) {
			guards[u] = GUARDED;
			for(int j = 0; j < AdjList[u].size(); j++) {
				int v = AdjList[u][j];
				guards[v] = GUARDED;
			}
			count++;
		}
	}
	// printf("count is %d\n", count);
	if(bipartite) return count;
	else return -1;
}

int main() {
	int T, v, e, f, t;
	scanf("%d", &T);

	for(int tc = 0; tc < T; tc++) {
		scanf("%d %d", &v, &e);
		AdjList.assign(v, vi());
		guards.assign(v, UNGUARDED);
		color.assign(v, INF);
		incoming_degree.assign(v, 0);
		dfs_num.assign(v, UNVISITED);

		//printf("case %d %d\n", v, e);

		for(int i = 0; i < e; i++) {
			scanf("%d %d", &f, &t);
			AdjList[f].push_back(t);
			AdjList[t].push_back(f);
			incoming_degree[f]++; incoming_degree[t]++;
		}
		// if(mindeg == INF) mindeg = 0;
		// printf("min indeg: %d\n", mindeg);
		// algorithm using bfs
		int res = 0;
		int ans = 0;
		for(int i = 0; i < v; i++) {
			if(color[i] == INF) {
				/*incoming_degree.assign(v, 0);
				dfs_num.assign(v, UNVISITED);*/

				res = bfs(i);
				if(!bipartite) break;
				ans += res;
			}
		}
		printf("%d\n", bipartite ? ans : -1);

	}

	return 0;
}


