/*
 * FenceRepair.cpp
 *
 *  Created on: Aug 4, 2015
 *      Author: Ivan
 */

// Problem J - Fence Repair

#include <cstdio>
#include <vector>
using namespace std;
#define EPS 1e9

typedef pair<int, int> ii;
int n, *a, m, *b, planks;
vector<ii> p;

bool can(int h) {
	int j = 0; planks = 0;
	p.clear();
	for(int i = 0; i < n; i++) {
		int tmp = a[i];
		while(a[i] + b[j] < h) {
			j++;
			if(j == m) return false;
		}
		if(a[i] < h) {
			p.push_back(ii(i + 1, j + 1));
			j++;
			planks++;
			if(j == m) return false;
		}
	}
	return true;
}

int main() {

	FILE *fin = fopen("wall.in", "r");
	FILE *fout = fopen("wall.out", "w+");
	freopen("wall.out", "w+", stdout);

	fscanf(fin, "%d", &n);
	a = new int[n];

	for(int i = 0; i < n; i++) fscanf(fin, "%d", &a[i]);
	fscanf(fin, "%d", &m);

	b = new int[m];
	for(int i = 0; i < m; i++) fscanf(fin, "%d", &b[i]);

	int low, high, middle, ans;
	low = 0; high = EPS;
	for(int i = 0; i < 50; i++) {
		middle = (low + high) / 2.0;
		if(can(middle)) {
			ans = middle;
			low = middle;
		}
		else {
			high = middle;
		}
	}
	fprintf(fout, "%d %d\n", ans, planks);
	for(int i = 0; i < p.size(); i++) {
		fprintf(fout, "%d %d\n", p[i].first, p[i].second);
	}

	return 0;
}


