/*
 * 318.cpp
 *
 *  Created on: Jul 29, 2015
 *      Author: Ivan
 */

// 318 - Domino Effect

#define UNVISITED -1
#define VISITED 1
#define INF 1 << 15
#include <cstdio>
#include <vector>
#include <set>
#include <queue>
using namespace std;


typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n, m;
vector<vii> AdjList;
vi dfs_num;
vi layer;
queue<int> q;
priority_queue<ii> pq;
priority_queue<int> kd;
set<int> kset;

int main() {
	int a, b, l;
	int k1, k2;
	double sec;
	while(scanf("%d %d", &n, &m) && (n | m)) {
		AdjList.assign(n, vii());
		dfs_num.assign(n, UNVISITED);
		layer.assign(n, INF);
		for(int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &l);
			AdjList[a - 1].push_back(ii(b - 1, l));
			AdjList[b - 1].push_back(ii(a - 1, l));
		}

		// algorithm
		// bfs
		int s = 0;
		pq.push(ii(0, s)); layer[s] = 0;

		while(!pq.empty()) {
			ii u = pq.top(); pq.pop();
			for(int j = 0; j < AdjList[u.second].size(); j++) {
				ii v = AdjList[u.second][j];
				if(layer[v.first] == INF) {
					layer[v.first] = layer[u.second] + v.second;
					pq.push(ii(u.first + v.second, v.first));
				}
				else {
					printf("At: %d\n", u.second + 1);
					kset.insert(u.second + 1);
					sec = (layer[v.first] + layer[u.second] + v.second) / 2.0;
					printf("Sec: %.1f\n", sec);
				}
			}
		}
		set<int>::iterator it = kset.begin();
		set<int>::iterator it2 = kset.end();
		--it2;
		if(kset.size() > 1) {
			printf("The last domino falls after %.1f seconds, between key dominoes %d and %d.\n", sec, *(it), *(it2));
		}
		else {
			printf("The last domino falls after %.1f seconds, at key domino %d.\n", sec, *(it));
		}

	}
	return 0;
}


