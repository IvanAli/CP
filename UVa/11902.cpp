/*
 * 11902.cpp
 *
 *  Created on: Jul 24, 2015
 *      Author: Ivan
 */

// 11902 - Dominator

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int T, N;
int id;
vi nodes;
vi tmpvec;
vector<vii> AdjList;

const int UNVISITED = -1;
const int VISITED = 1;

void dfs(int u, int skip) {
	if(u == skip && u) return;
	nodes[u] = VISITED;

	for(int j = 0; j < AdjList[u].size(); j++) {
		ii vertex = AdjList[u][j];
		if(nodes[vertex.first] == UNVISITED) {
			dfs(vertex.first, skip);
		}
	}
}

int main() {

	scanf("%d", &T);

	for(int t = 0; t < T; t++) {
		scanf("%d", &N);
		AdjList.clear(); nodes.clear();
		nodes.assign(N, -1);
		AdjList.assign(N, vii());

		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				scanf("%d", &id);
				if(id) AdjList[i].push_back(ii(j, id));
			}
		}
		// algorithm
		//dfs(0);
		printf("Case %d:\n", t + 1);
		printf("+");
		for(int i = 0; i < N * 2 - 1; i++) printf("-");
		printf("+\n");

		dfs(0, 0);
		tmpvec.assign(N, 0);
		for(int i = 0; i < N; i++) {
			tmpvec[i] = nodes[i];
		}
		for(int j = 0; j < nodes.size(); j++) {
			if(nodes[j] == VISITED) printf("|Y");
			else printf("|N");
		}
		printf("|\n+");
		for(int i = 0; i < N * 2 - 1; i++) printf("-");
		printf("+\n");

		for(int i = 1; i < N; i++) {
			nodes.clear();
			nodes.assign(N, -1);
			dfs(0, i);

			for(int j = 0; j < nodes.size(); j++) {
				if(nodes[j] != tmpvec[j]) printf("|Y");
				else printf("|N");
			}
			printf("|\n+");
			for(int i = 0; i < N * 2 - 1; i++) printf("-");
			printf("+\n");
		}

	}
	return 0;
}



