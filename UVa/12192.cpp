/*
 * 12192.cpp
 *
 *  Created on: Jul 22, 2015
 *      Author: Ivan
 */

// 12192 - Grapevine

#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main() {
	int N, M, Q, L, U;
	vector<vi> A;

	while(scanf("%d %d", &N, &M) && (N || M)) {
		A.clear();
		A.assign(N, vi(M, 0));

		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				scanf("%d", &A[i][j]);
			}
		}
		scanf("%d", &Q);
		for(int i = 0; i < Q; i++) {
			vi::iterator it;
			int p = 0;
			int count = 0;
			scanf("%d %d", &L, &U);
			for(int j = 0; j < A.size(); j++) {
				p = 0;
				it = lower_bound(A[j].begin(), A[j].end(), L);

				int a = j; int b = (it - A[j].begin());

				for(int k = count; k < A.size(); k++) {
					if(a + k >= A.size() || b + k >= A[j].size() || A[a + k][b + k] > U) break;
					if(k + 1 > count) count = k + 1;
					/*if(A[a + count][b + count] <= U) {
						p++;
						a++; b++;
					}*/

				}
				if(count < p) count = p;
			}

			printf("%d\n", count);
		}
		printf("-\n");
		// algorithm

	}
	return 0;
}


