/*
 * 11991-2.cpp
 *
 *  Created on: Jul 4, 2015
 *      Author: Ivan
 */

//11991 using an adj list

#include <cstdio>
#include <vector>
#include <map>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
	vector<vi> adjList;
	int n, m, k, v;
	int aux;

	while(scanf("%d %d", &n, &m) != EOF) {

		adjList.assign(1000000, vi());

		for(int i = 0; i < n; i++) {
			scanf("%d", &aux);
			adjList[aux].push_back(i + 1);
		}
		for(int i = 0; i < m; i++) {
			scanf("%d %d", &k, &v);
			printf("%d\n", k - 1 < adjList[v].size() ? adjList[v][k - 1] : 0);
		}

	}

	return 0;
}


