/*
 * 12442.cpp
 *
 *  Created on: Jul 29, 2015
 *      Author: Ivan
 */

// 12442 - Forwarding Emails

#define UNVISITED -1
#define VISITED 1
#include <cstdio>
#include <vector>
using namespace std;


typedef vector<int> vi;

vi AdjList;
vi dfs_num;
vi chain;

int dfs(int u) {
	dfs_num[u] = VISITED;
	int sum = 0;
	int v = AdjList[u];
	if(v != -1 && dfs_num[v] == UNVISITED) {
		sum += 1 + dfs(v);
	}
	dfs_num[u] = UNVISITED;
	return chain[u] = sum;
}

int main() {
	int T, N, u, v;
	int maximum, ans, len;

	scanf("%d", &T);
	for(int t = 0; t < T; t++) {
		scanf("%d", &N);
		AdjList.assign(N, -1);
		dfs_num.assign(N, UNVISITED);

		chain.assign(N, -1);

		for(int i = 0; i < N; i++) {
			scanf("%d %d", &u, &v);
			AdjList[u - 1] = v - 1;
		}

		// algorithm
		maximum = 0; ans = 0; len = 0;
		for(int i = 0; i < N; i++) {
			// dfs_num.assign(N, UNVISITED);
			if(chain[i] == -1) dfs(i);
			if(chain[i] > maximum) {
				maximum = chain[i];
				ans = i;
			}
		}
		printf("Case %d: %d\n", t + 1, ans + 1);
	}
	return 0;
}


