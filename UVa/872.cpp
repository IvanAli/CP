/*
 * 872.cpp
 *
 *  Created on: Aug 1, 2015
 *      Author: Ivan
 */

// 872 - Ordering

#include <cstdio>
#include <vector>
#include <cstring>
#define UNVISITED -1
#define VISITED 1

using namespace std;

typedef vector<int> vi;

vector<vi> AdjList;
vi dfs_num;
vi toposort;
int vnum;
vi incoming_degree;

int backtrack(int c) {
	int ans = 0;
	if(c == vnum) {
		for(int i = 0; i < vnum; i++) {
			if(i) printf(" ");
			printf("%c", toposort[i] + 'A');
		}
		printf("\n");
		return 1;
	}
	for(int i = 0; i < AdjList.size(); i++) {
		if(incoming_degree[i] == 0 && dfs_num[i] == UNVISITED) {
			dfs_num[i] = VISITED;
			for(int j = 0; j < AdjList[i].size(); j++) {
				int v = AdjList[i][j];
				incoming_degree[v]--;
			}
			toposort[c] = i;
			ans += backtrack(c + 1);
			for(int j = 0; j < AdjList[i].size(); j++) {
				int v = AdjList[i][j];
				incoming_degree[v]++;
			}
			dfs_num[i] = UNVISITED;
		}
	}
	return ans;
}

int main() {
	int T;
	char str[100];
	char str2[100];

	scanf("%d", &T);
	getc(stdin);


	for(int t = 0; t < T; t++) {
		if(t) printf("\n");
		getc(stdin);
		gets(str);

		vnum = 0;
		AdjList.assign(26, vi());
		dfs_num.assign(26, -2);
		incoming_degree.assign(26, 0);

		int len = strlen(str);
		for(int i = 0; i < len; i += 2) {
				dfs_num[str[i] - 'A'] = UNVISITED;
				vnum++;
		}
		toposort.assign(vnum, -1);

		gets(str2);
		len = strlen(str2);

		for(int i = 0; i < len; i++) {
			if(str2[i] == '<') {
				AdjList[str2[i - 1] - 'A'].push_back(str2[i + 1] - 'A');
				incoming_degree[str2[i + 1] - 'A']++;
			}
		}

		// algorithm
		if(!backtrack(0)) printf("NO\n");
	}

	return 0;
}

