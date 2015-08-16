/*
 * 318.cpp
 *
 *  Created on: Jul 30, 2015
 *      Author: Ivan
 */

// 318 2 - Domino Effect

#define UNVISITED -1
#define VISITED 1
#define INF 1 << 19
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n, m;
vector<vi> AdjList;
vi dist;
priority_queue<ii, vector<ii>, greater<ii> > pq;

int main() {
	int tc = 0;
	int a, b, l;
	int k1, k2;
	vector<ii>::iterator it;
	while(scanf("%d %d", &n, &m) && (n | m)) {
		// if(tc) printf("\n");
		AdjList.assign(n, vi(n, -1));
		dist.assign(n, INF);
		bool bflag;
		for(int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &l);
			if(a == b) continue;
			AdjList[a - 1][b - 1] = l;
			AdjList[b - 1][a - 1] = l;
		}
		// algorithm
		// Dijkstra's algorithm
		int s = 0;
		pq.push(ii(0, s)); dist[s] = 0;

		while(!pq.empty()) {
			ii front = pq.top(); pq.pop();
			int d = front.first; int u = front.second;
			if(d == -1) continue;
			if(d > dist[u]) continue;
			for(int j = 0; j < n; j++) {
				if(AdjList[u][j] == -1) continue;
				int v = j;
				int w = AdjList[u][j];
				if(dist[u] + w < dist[v] ) {
					dist[v] = dist[u] + w;
					pq.push(ii(dist[v], v));
				}
			}
		}

		int maxidx = 0; int maxidx2 = -1;
		double ans = 0;
		for(int i = 0; i < n; i++) {
			if(dist[i] > dist[maxidx] && dist[i] != INF) {
				ans = dist[i];
				maxidx = i;
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(AdjList[i][j] == -1) continue;
				k1 = dist[i];
				k2 = dist[j];
				int w = AdjList[i][j];
				float time = (k1 + k2 + w) / 2.0;
				if(k1 != INF && k2 != INF && time > ans) {
					if(i < j) {
						maxidx = i;
						maxidx2 = j;
					}
					else {
						maxidx2 = i;
						maxidx = j;
					}
					/*maxidx = i;
					maxidx2 = AdjList[i][j].first;
					if(maxidx > maxidx2) swap(maxidx, maxidx2);*/
					ans = time;
				}
			}
		}
		printf("System #%d\n", ++tc);
		if(maxidx2 == -1) {
			printf("The last domino falls after %.1lf seconds, at key domino %d.\n\n", ans, maxidx + 1);
		}
		else {
			printf("The last domino falls after %.1lf seconds, between key dominoes %d and %d.\n\n",
					ans,
					maxidx + 1,
					maxidx2 + 1
			);
		}
	}
	return 0;
}


