/*
 * 1174.cpp
 *
 *  Created on: Aug 11, 2015
 *      Author: Ivan
 */

// 1174 - IP-TV

#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vii> AdjList;
vector< pair<int, ii> > EdgeList;
map<string, int> m;

class UnionFind {
public:
	int cc;
	vi rank, p;
	UnionFind(int N) {
		cc = N;
		p.assign(N, 0);
		for(int i = 0; i < N; i++) p[i] = i;
		rank.assign(N, 0);
	}
	int findSet(int i) {
		return p[i] == i ? i : p[i] = findSet(p[i]);
	}
	bool sameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j) {
		if(!sameSet(i, j)) {
			int x = p[i]; int y = p[j];
			if(rank[x] < rank[y]) {
				p[x] = y;
				rank[x]--;
				rank[y]++;
			}
			else {
				p[y] = x;
				rank[x]++;
				rank[y]--;
			}
			cc--;
		}
	}
};
int main() {
	int T, M, N, C, idx;
	char B[10];
	char E[10];
	char str[10000];

	scanf("%d", &T);

	for(int t = 0; t < T; t++) {
		if(t) printf("\n");
		scanf("%d", &M);
		scanf("%d", &N);
		m.clear();
		EdgeList.clear();
		idx = 0;
		getc(stdin);
		for(int n = 0; n < N; n++) {
			gets(str);
			sscanf(str, "%s %s %d", &B, &E, &C);
			if(m.find(B) == m.end()) {
				m[B] = idx++;
			}
			if(m.find(E) == m.end()) {
				m[E] = idx++;
			}
			EdgeList.push_back(make_pair(C, ii(m[B], m[E])));
		}
		sort(EdgeList.begin(), EdgeList.end());
		UnionFind UF(M);
		int mst_cost = 0;
		for(int i = 0; i < N && UF.cc > 1; i++) {
			pair<int, ii> front = EdgeList[i];
			if(!UF.sameSet(front.second.first, front.second.second)) {
				mst_cost += front.first;
				UF.unionSet(front.second.first, front.second.second);
			}
		}
		printf("%d\n", mst_cost);

	}
	return 0;
}


