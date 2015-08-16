/*
 * 10034.cpp
 *
 *  Created on: Aug 11, 2015
 *      Author: Ivan
 */

// 10034 - Freckles

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<vi> vii;

vector< pair<double, ii> > EdgeList;
vector< pair<double, double> > coordinates;

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

double hyp(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
	int T, n;
	double x, y;
	scanf("%d", &T);

	for(int t = 0; t < T; t++) {
		if(t) printf("\n");
		EdgeList.clear();
		coordinates.clear();
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%lf %lf", &x, &y);
			coordinates.push_back(dd(x, y));
		}
		double c;
		for(int i = 0; i < n - 1; i++) {
			for(int j = i + 1; j < n; j++) {
				c = hyp(coordinates[i].first, coordinates[i].second, coordinates[j].first, coordinates[j].second);
				EdgeList.push_back(make_pair(c, ii(i, j)));
			}
		}
		sort(EdgeList.begin(), EdgeList.end());
		UnionFind UF(n);
		double mst_cost = 0.0;
		for(int i = 0; i < EdgeList.size(); i++) {
			pair<double, ii> front = EdgeList[i];
			if(!UF.sameSet(front.second.first, front.second.second)) {
				mst_cost += front.first;
				UF.unionSet(front.second.first, front.second.second);
			}
		}
		printf("%.2f\n", mst_cost);
	}
	return 0;
}


