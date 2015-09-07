/*
 * 1112.cpp
 *
 *  Created on: Aug 16, 2015
 *      Author: Ivan
 */

// 1122 - Mice and Maze

#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 1e9

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

priority_queue< ii, vector<ii>, greater<ii> > pq;
vector<vii> AdjList;
vi p;
vi dist;
int N, E, T, M;


void dijkstra(int s) {
	dist[s] = 0; p[s] = s;
	pq.push(ii(dist[s], s));

	while(!pq.empty()) {
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if(d > dist[u]) continue;
		for(int j = 0; j < AdjList[u].size(); j++) {
			ii v = AdjList[u][j];
			if(dist[v.first] > dist[u] + v.second) {
				dist[v.first] = dist[u] + v.second;
				p[v.first] = u;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}
}

int main() {
	int tc, a, b, w;

	scanf("%d", &tc);
	for(int t = 0; t < tc; t++) {
		if(t) printf("\n");
		scanf("%d", &N);
		AdjList.assign(N, vii());
		int miceout = 0;
		scanf("%d", &E); scanf("%d", &T); scanf("%d", &M);
		for(int i = 0; i < M; i++) {
			scanf("%d %d %d", &a, &b, &w);
			AdjList[a - 1].push_back(ii(b - 1, w));
		}
		// algorithm
		for(int i = 0; i < N; i++) { // mice in all cells
			p.assign(N, -1);
			dist.assign(N, INF);
			dijkstra(i);
			if(dist[E - 1] <= T) miceout++;
		}
		printf("%d\n", miceout);
	}

	return 0;
}


