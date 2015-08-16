/*
 * 11228.cpp
 *
 *  Created on: Aug 10, 2015
 *      Author: Ivan
 */

// 11228 - Transportation System

#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<ii> vii;
typedef vector<dd> vdd;

vi taken;
vii coord;
vector< pair<int, ii> > EdgeList;
vector<vdd> AdjList;
priority_queue<dd> pq;

int T, n, r, x, y;

void process(int u) {
	taken[u] = 1;
	for(int j = 0; j < AdjList[u].size(); j++) {
		dd v = AdjList[u][j];
		pq.push(dd(-v.second, -v.first));
	}
}

double hyp(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
	int states;

	scanf("%d", &T);
	for(int t = 0; t < T; t++) {
		scanf("%d %d", &n, &r);
		taken.assign(n, 0);
		coord.clear();
		states = 1;
		for(int i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			coord.push_back(ii(x, y));
		}
		double c;
		AdjList.assign(n, vdd());
		for(int i = 0; i < n - 1; i++) {
			for(int j = i + 1; j < n; j++) {
				c = hyp(coord[i].first, coord[i].second, coord[j].first, coord[j].second);
				AdjList[i].push_back(dd(j, c));
				AdjList[j].push_back(dd(i, c));
			}
		}
		double mst_cost_road = 0.0;
		double mst_cost_railroad = 0.0;
		process(0);

		while(!pq.empty()) {
			dd front = pq.top(); pq.pop();
			int u = -front.second; double w = -front.first;
			if(!taken[u]) {
				if(w < r) mst_cost_road += w;
				else {
					mst_cost_railroad += w;
					states++;
				}
				process(u);
			}
		}
		printf("Case #%d: %d %.0f %.0f\n", t + 1, states, mst_cost_road, mst_cost_railroad);
	}
	return 0;
}


