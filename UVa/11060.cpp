/*
 * 11060.cpp
 *
 *  Created on: Jul 26, 2015
 *      Author: Ivan
 */

// 11060 - Beverages

#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vii;

map<string, int> m;
vector<vi> AdjList;
vi ts;
queue<int> q;
priority_queue<int> pq;
vi source;

int main() {
	int tc = 0;
	int N, M;
	char B1[52];
	char B2[52];
	vector<string> drinks;

	while(scanf("%d", &N) != EOF) {
		// if(tc) printf("\n");
		AdjList.assign(N, vi());
		source.assign(N, 0);
		drinks.resize(N);
		ts.clear();

		for(int i = 0; i < N; i++) {
			scanf("%s", &B1);
			m[B1] = i;
			drinks[i] = B1;
		}
		scanf("%d", &M);
		for(int i = 0; i < M; i++) {
			scanf("%s %s", &B1, &B2);
			AdjList[m[B1]].push_back(m[B2]);
		}

		// algorithm
		for(int i = 0; i < N; i++) {
			int len = AdjList[i].size();
			for(int j = 0; j < len; j++) {
				source[AdjList[i][j]]++;
			}
		}
		for(int i = 0; i < N; i++) {
			if(!source[i]) pq.push(-i);
		}
		while(!pq.empty()) {
			int u = -pq.top(); pq.pop();
			ts.push_back(u);
			for(int j = 0; j < AdjList[u].size(); j++) {
				source[AdjList[u][j]]--;
				if(!source[AdjList[u][j]]) pq.push(-AdjList[u][j]);
			}
		}
		printf("Case #%d: Dilbert should drink beverages in this order:", ++tc);
		for(int i = 0; i < ts.size(); i++) {
			printf(" %s", drinks[ts[i]].c_str());
		}
		printf(".\n\n");


	}

	return 0;
}


