#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <iterator>
#include <queue>
#include <fstream> 
#include <stack>

#define INF 1e8
#define EPS 1e-10
 
using namespace std;
 
int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};
 
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;


priority_queue<ii> pq;
stack<int> stk;

int main() {
	int N;
	// char str[105];
	int d;
	int hour;
	int mult;
	int h, m, s;
	int E, X, UNK;
	int max;
	int Ecount, Xcount;
	char l;
	while(scanf("%d%*c", &N) == 1 && N) {
		// getc(stdin);
		max = 0;
		E = X = UNK = 0;
		Ecount = Xcount = 0;
		for(int n = 0; n < N; n++) {
			mult = 10000;
			hour = 0;
			// gets(str);
			scanf("%d:%d:%d %c", &h, &m, &s, &l);
			// printf("%d %d %d %c\n", h, m, s, l);
			hour = h * 10000 + m * 100 + s;
			pq.push(ii(-hour, l));
			if(l == 'E') E++;
			if(l == 'X') X++;
			if(l == '?') UNK++;
			// printf("hour: %d\n", hour);
		}
		// algorithm
		// puts("asdasd");
		for(int i = 0; i <= UNK; i++) {
			if(E + i == X + UNK - i) {
				E = i;
				X = UNK - i;
				break;
			}
		}
		// printf("%d %d\n", E, X);
		printf("E: %d\n", E);
		while(!pq.empty()) {
			// puts("aaaaa");
			ii front = pq.top(); pq.pop();
			// printf("front: %d %c\n", -front.first, front.second);
			if(front.second == 'E') {
				Ecount++;
				stk.push(-front.first);
			}
			if(front.second == 'X') {
				Xcount++;
				if(!stk.empty()) stk.pop();
			}
			if(front.second == '?') {
				if(Ecount > E) {
					if(!stk.empty()) stk.pop();
					Xcount++;
					printf("pop\n");
				}
				else {
					stk.push(-front.second);
					Ecount++;
					printf("push\n");
				}
			}
			printf("stack size:%d\n", stk.size());
			if(stk.size() > max) max = stk.size();
		}
		printf("%d\n", max);
	}

	return 0;
}
