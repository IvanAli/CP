/*
 * 10004.cpp
 *
 *  Created on: Jul 26, 2015
 *      Author: Ivan
 */

// 10004 - Bicoloring

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
#define INF 1 << 15

typedef vector<int> vi;

vector<vi> AdjList;
vi color;


int main() {
	int n, l;
	int u, v;

	while(scanf("%d", &n) && n) {
		AdjList.assign(n, vi());

		scanf("%d", &l);
		for(int i = 0; i < l; i++) {
			scanf("%d %d", &u, &v);
			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}

		// algorithm
		int s = 0;
		bool bipartite = true;
		queue<int> q;
		color.assign(n, INF);
		q.push(s); color[s] = 0;

		while(!q.empty() & bipartite) {
			u = q.front(); q.pop();
			for(int j = 0; j < AdjList[u].size(); j++) {
				v = AdjList[u][j];
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
		if(!bipartite) printf("NOT ");
		printf("BICOLORABLE.\n");

	}

	return 0;
}


