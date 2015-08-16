/*
 * 1234.cpp
 *
 *  Created on: Aug 12, 2015
 *      Author: Ivan
 */

// 1234 - Racing

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vii> AdjList;
vi taken;
priority_queue<ii> pq;

void process(int u) {
	taken[u] = 1;
	for(int j = 0; j < AdjList[u].size(); j++) {
		ii v = AdjList[u][j];
		if(!taken[v.first]) {
			pq.push(ii(v.second, -v.first));
		}
	}
}

int main() {
	int T, n, m, u, v, w;

	scanf("%d", &T);
	for(int t = 0; t < T; t++) {
		scanf("%d %d", &n, &m);
		AdjList.assign(n, vii());
		taken.assign(n, 0);
		for(int i = 0; i < m; i++) {
			scanf("%d %d %d", &u, &v, &w);
			AdjList[u - 1].push_back(ii(v - 1, w));
			AdjList[v - 1].push_back(ii(u - 1, w));
		}
		// algorithm
		process(0);
		int maxst_cost = 0;
		while(!pq.empty()) {
			ii front = pq.top(); pq.pop();
			int u = -front.second; int w = front.first;
			if(!taken[u]) {
				process(u);
			}
			else {
				maxst_cost += w;
			}
		}
		printf("%d\n", maxst_cost);
	}
	return 0;
}

