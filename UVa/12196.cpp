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

int dp[1002];
vector<vi> AdjList;

int main() {
	int N, K, g;

	while(scanf("%d", &N) && N) {
		memset(dp, 0, 1001);
		vi vec;
		priority_queue<int, vi, greater<int> > pq;
		int prev = 0;
		int _max = 0;
		int _min = INF;
		AdjList.assign(N, vi());
		for(int i = 0; i < N; i++) {
			scanf("%d", &K);
			for(int k = 0; k < K; k++) {
				scanf("%d", &g);
				AdjList[i].push_back(g);
				pq.push(g);
				_max = max(g, _max);
			}
		}
		while(!pq.empty()) {
			int front = pq.top(); pq.pop();
			dp[front] = dp[prev] + 1;
			prev = front;
		}
		int t = 0;
/*
		printf("Max grade: %d\n", _max);
		printf("Value at max grade: %d\n", dp[_max]);
*/
		for(int i = 1; i < _max + 1; i++) {
			if(_min > abs(dp[_max] - dp[i - 1] - dp[i - 1])) t = i;
			_min = min(_min, abs(dp[_max] - dp[i - 1] - dp[i - 1]));
		}
		int diff = 0;
		for(int i = 0; i < AdjList.size(); i++) {
			vi::iterator it = lower_bound(AdjList[i].begin(), AdjList[i].end(), t);
			diff += abs((it - AdjList[i].begin()) - (AdjList[i].end() - it));
		}
		printf("t: %d\n", t);
		printf("%d\n", diff);
	}
	return 0;
}



