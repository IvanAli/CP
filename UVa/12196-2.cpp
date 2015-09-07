/*
 * 12196-2.cpp
 *
 *  Created on: Aug 19, 2015
 *      Author: Ivan
 */
/*
 * 12196.cpp
 *
 *  Created on: Aug 19, 2015
 *      Author: Ivan
 */

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

#define INF 1e5

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vi> table;

int main() {
	int N, K, g, ans, prev, _max, _min;

	while(scanf("%d", &N) && N) {
		table.assign(N, vi(1001, 0));
		for(int i = 0; i < N; i++) {
			prev = 0;
			_max = 0;
			_min = INF;
			scanf("%d", &K);
			for(int k = 0; k < K; k++) {
				scanf("%d", &g);
				table[i][g] = table[i][prev] + 1;
				_max = max(g, _max);
				table[i][0] = _max;
				prev = g;
			}
			//printf("max at %d: %d with value %d\n", i, table[i][0], table[i][table[i][0]]);
		}
		puts("good");
		 // sort(table[i].begin(), table[i].end());
		ans = INF;
		printf("MAX FIRST: %d\n", table[0][0]);
		printf("MAX SEC %d\n", table[1][0]);
		for(int t = 1; t < 1001; t++) {
			int diff = 0;
			prev = 0;
			for(int n = 0; n < table.size(); n++) {
				_max = table[n][0];
				if(!table[n][t]) {
					diff = table[n][_max];
					continue;
				}
				printf("max at %d with value %d\n", _max, table[n][_max]);
				if(t > 1) diff += abs(table[n][_max] - 2 * table[n][prev]);
				else diff = table[n][_max];
				prev = t;
			}
			// printf("DIFF: %d\n", diff);
			ans = min(ans, diff);
		}

		printf("%d\n", ans);
	}
	return 0;
}







