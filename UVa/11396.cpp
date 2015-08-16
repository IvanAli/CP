/*
 * 11396.cpp
 *
 *  Created on: Aug 3, 2015
 *      Author: Ivan
 */

// 11396 - Claw Decomposition

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define INF 1 << 9

typedef vector<int> vi;

queue<int> q;
vector<vi> AdjList;
vi color;

int main() {
	int V;
	int a, b;
	bool bipartite;
	while(scanf("%d", &V) && V) {
		AdjList.assign(V, vi());
		color.assign(V, INF);
		while(scanf("%d %d", &a, &b) && (a | b)) {
			AdjList[a - 1].push_back(b - 1);
			AdjList[b - 1].push_back(a - 1);
		}
		// algorithm
		int s = 0;
		bipartite = true;
		for(int i = 0; i < V; i++) {
			if(color[i] == INF) {
				q.push(i); color[i] = 0;

				while(!q.empty()) {
					int u = q.front(); q.pop();
					for(int j = 0; j < AdjList[u].size(); j++) {
						int v = AdjList[u][j];
						if(color[v] == INF) {
							color[v] = 1 - color[u];
							q.push(v);
						}
						else if(color[v] == color[u]) {
							bipartite = false;
							break;
						}
					}
				}
			}
		}

		if(bipartite) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}


