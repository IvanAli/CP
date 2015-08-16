/*
 * 12582.cpp
 *
 *  Created on: Jul 29, 2015
 *      Author: Ivan
 */

// 12582 - Wedding of Sultan

#include <cstdio>
#include <vector>
#include <cstring>
#define UNVISITED -1
#define VISITED 1
using namespace std;

typedef vector<int> vi;

vi degree;
vi dfs_num;
char seq[100000];
int len;
vector<vi> AdjList;

void dfs2(int u) {
	int deg = 1;
	dfs_num[seq[u] - 'A'] = VISITED;
	for(int i = u + 1; i < len; i++) {
		if(dfs_num[seq[i] - 'A'] == UNVISITED) {
			deg++;
			dfs2(i);
		}
		else if(seq[i] == seq[u]) {
			if(!u) deg--;
			degree[seq[u] - 'A'] = deg;
			break;
		}
	}
}
/*

void dfs(int u) {
	dfs_num[u] = VISITED;
	// print u
	for(int j = 0; j < AdjList[u].size(); j++) {
		int v = AdjList[u][j];
		if(dfs_num[v] == UNVISITED)
			dfs(v); degree[u]++;
	}
	// print u
}
*/

int main() {
	int T;

	scanf("%d", &T);

	for(int t = 0; t < T; t++) {
		scanf("%s", &seq);
		len = strlen(seq);
		AdjList.assign('Z' - 'A' + 1, vi());
		degree.assign('Z' - 'A' + 1, 0);
		dfs_num.assign('Z' - 'A' + 1, UNVISITED);

		dfs2(0);

		printf("Case %d\n", t + 1);
		for(int i = 0; i < degree.size(); i++) {
			if(degree[i]) printf("%c = %d\n", i + 'A', degree[i]);
		}

	}

	return 0;
}

