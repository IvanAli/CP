/*
 * 11747.cpp
 *
 *  Created on: Aug 12, 2015
 *      Author: Ivan
 */

// 11747 - Heavy Cycle Edges

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vi taken;
priority_queue<ii> pq;
int heavyEdge;
vi ans;
vi p;
vector<vii> AdjList;
vector< pair<int, ii> > EdgeList;
bool forest;

class UnionFind {
public:
	int cc;
	vi rank, p;
	UnionFind(int N) {
		cc = N;
		rank.assign(N, 0);
		p.assign(N, 0);
		for(int i = 0; i < N; i++) p[i] = i;
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
void process(int u) {
	taken[u] = 1;
	for(int j = 0; j < AdjList[u].size(); j++) {
		ii v = AdjList[u][j];
		if(!taken[v.first]) {
			pq.push(ii(-v.second, -v.first));
			p[v.first] = u;
		}
		else {
			if(v.second > heavyEdge) heavyEdge = v.second;
			if(p[u] != v.first) {
				printf("Parent of %d is actually %d", u, v.first);
				printf("heavy edge: %d\n", heavyEdge);
				ans.push_back(heavyEdge);
				forest = false;
			}
		}
	}
}

int main() {
	int n, m, u, v, w;

	while(scanf("%d %d", &n, &m) && (n | m)) {
		AdjList.assign(n, vii());
		taken.assign(n, 0);
		p.assign(n, -1);
		heavyEdge = 0;
		forest = true;
		ans.clear();
		EdgeList.clear();
		/*for(int i = 0; i < m; i++) {
			scanf("%d %d %d", &u, &v, &w);
			AdjList[u].push_back(ii(v, w));
			AdjList[v].push_back(ii(u, w));
		}*/
		// algorithm
		/*process(0);
		while(!pq.empty()) {
			ii front = pq.top(); pq.pop();
			int u = -front.second; int w = -front.first;
			if(!taken[u]) {
				process(u);
			}
		}*/

		// using kruskal's
		for(int i = 0; i < m; i++) {
			scanf("%d %d %d", &u, &v, &w);
			EdgeList.push_back(make_pair(w, ii(u, v)));
		}
		sort(EdgeList.begin(), EdgeList.end());
		UnionFind UF(n);
		for(int i = 0; i < EdgeList.size(); i++) {
			pair<int, ii> front = EdgeList[i];
			if(front.first > heavyEdge) heavyEdge = front.first;
			if(!UF.sameSet(front.second.first, front.second.second)) {
				UF.unionSet(front.second.first, front.second.second);
			}
			else {
				ans.push_back(heavyEdge);
				heavyEdge = 0;
				forest = false;
			}
		}

		if(forest) printf("forest");
		else {
			for(int i = 0; i < ans.size(); i++) {
				if(i) printf(" ");
				printf("%d", ans[i]);
			}
		}

		printf("\n");
	}
	return 0;
}


