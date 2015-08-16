/*
 * 10895.cpp
 *
 *  Created on: Jul 4, 2015
 *      Author: Ivan
 */
//10895 - Matrix Transpose

#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
using std::vector;
using std::pair;
using std::queue;
using std::pair;
using std::make_pair;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
	vector<vii> adjList;
	vector<vii> trList;
	queue<int> pos;
	int m, n, r, v;

	while(scanf("%d %d", &m, &n) != EOF) {

		adjList.clear();
		trList.clear();
		adjList.assign(m, vii());
		trList.assign(n, vii());

		for(int i = 0; i < m; i++) {
			scanf("%d", &r);

			for(int j = 0; j < r; j++) {
				scanf("%d", &v);
				pos.push(v - 1);
			}
			for(int j = 0; j < r; j++) {
				scanf("%d", &v);
				adjList[i].push_back(ii(pos.front(), v));
				pos.pop();
			}
		}
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < adjList[i].size(); j++) {
				trList[adjList[i][j].first].push_back(ii(i, adjList[i][j].second));
			}
		}
		printf("%d %d\n", n, m);
		for(int i = 0; i < n; i++) {
			printf("%d", trList[i].size());
			for(int j = 0; j < trList[i].size(); j++) {
				printf(" %d", trList[i][j].first + 1);
			}
			printf("\n");
			for(int j = 0; j < trList[i].size(); j++) {
				printf("%d", trList[i][j].second);
				if(j < trList[i].size() - 1) printf("%c", ' ');
			}
			printf("\n");
		}

	}

	return 0;
}



