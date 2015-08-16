/*
 * 459.cpp
 *
 *  Created on: Jul 25, 2015
 *      Author: Ivan
 */

// 459 - Graph Connectivity

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vi> AdjList;
const int UNVISITED = -1;
const int VISITED = 1;

vi dfs_num;

void dfs(int u) {
	dfs_num[u] = VISITED;
	for(int i = 0; i < AdjList[u].size(); i++) {
		int neighbor = AdjList[u][i];
		if(dfs_num[neighbor] == UNVISITED) {
			dfs(neighbor);
		}
	}
}

int main() {
	int tc;
	int v;
	char ch;
	char str[2];

	scanf("%d", &tc);

	getc(stdin);
	getc(stdin);

	while(tc--) {

		int count = 0;

		scanf("%c", &ch);
		getc(stdin);
		// printf("scanned: %c\n", ch);
		AdjList.assign(ch - 'A' + 1, vi());
		dfs_num.assign(ch - 'A' + 1, UNVISITED);

		while(gets(str) && strlen(str)) {
			// scanf("%s", &str);
			// printf("scanned: %s\n", str);
			AdjList[str[0] - 'A'].push_back(str[1] - 'A');
			AdjList[str[1] - 'A'].push_back(str[0] - 'A');
		}
		for(int i = 0; i < dfs_num.size(); i++) {
			if(dfs_num[i] == UNVISITED) {
				dfs(i);
				count++;
				// printf("%c unvisited\n", 'A' + 	i);
			}
		}

		printf("%d\n", count);
		if(tc) printf("\n");


	}
	return 0;
}


