/*
 * 10474.cpp
 *
 *  Created on: Jul 15, 2015
 *      Author: Ivan
 */

// 10474 - Where is the marble?

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int tc = 0;
	int N, Q, q;
	vector<int> m;


	while(scanf("%d %d", &N, &Q) && (N || Q)) {
		m.clear();
		for(int i = 0; i < N; i++) {
			scanf("%d", &q);
			m.push_back(q);
		}
		sort(m.begin(), m.end());
		for(int i = 0; i < Q; i++) {
			if(!i) printf("CASE# %d:\n", ++tc);
			scanf("%d", &q);
			vector<int>::iterator it = lower_bound(m.begin(), m.end(), q);
			if((*it) == q) {
				printf("%d found at %d\n", *it, it - m.begin() + 1);
			}
			else {
				printf("%d not found\n", q);
			}
		}


	}

	return 0;
}


