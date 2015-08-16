/*
 * 908.cpp
 *
 *  Created on: Aug 11, 2015
 *      Author: Ivan
 */

// 908 - Re-connecting Computer Sites

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vii> AdjList;
vector< pair<int, ii> > EdgeList;

class UnionFind {
public:
	vi p, rank;
	int cc;
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
		//printf("Parent of %d: %d parent of %d: %d\n", i, findSet(i), j, findSet(j));
		return findSet(i) == findSet(j);
	}
	void unify(int i, int j) {
		if(!sameSet(i, j)) {
			int x = p[i]; int y = p[j];
			if(rank[x] < rank[y]) {
				p[x] = y;
				rank[y]++;
				rank[x]--;
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
	int N, T, K, M, a, b, w;
	bool f = false;

	while(scanf("%d", &N) != EOF) {
		AdjList.assign(N, vii());
		EdgeList.clear();
		int mst_cost = 0;
		for(int i = 0; i < N - 1; i++) {
			scanf("%d %d %d", &a, &b, &w);
			mst_cost += w;
		}
		// algorithm
		if(f) printf("\n");
		else f = true;

		printf("%d\n", mst_cost);
		scanf("%d", &K);
		EdgeList.clear();
		for(int i = 0; i < K; i++) {
			scanf("%d %d %d", &a, &b, &w);
			EdgeList.push_back(make_pair(w, ii(a - 1, b - 1)));
		}
		scanf("%d", &M);
		for(int i = 0; i < M; i++) {
			scanf("%d %d %d", &a, &b, &w);
			EdgeList.push_back(make_pair(w, ii(a - 1, b - 1)));
		}
		sort(EdgeList.begin(), EdgeList.end());

		mst_cost = 0;
		UnionFind UF2(N);
		for(int i = 0; UF2.cc > 1 && i < M; i++) {
			pair<int, ii> front = EdgeList[i];
			if(!UF2.sameSet(front.second.first, front.second.second)) {
				mst_cost += front.first;
				UF2.unify(front.second.first, front.second.second);
			}
		}
		printf("%d\n", mst_cost);
	}
	return 0;
}


