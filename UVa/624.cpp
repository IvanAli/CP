/*
 * 624.cpp
 *
 *  Created on: Jul 9, 2015
 *      Author: Ivan
 */

// 624 - CD

#include <cstdio>
#include <deque>
using namespace std;

int N, t;
int *d;
int *list;
int sumt;
bool done;
deque<int> order;

bool fits(int index, int c) {
	int sum = 0;
	for(int i = 0; i < c; i++) {
		if(list[i] == d[index]) return false;
		sum += list[i];
		if(sum + d[index] > N) return false;
	}
	if(sum + d[index] <= N) {
		//sumt = sum + d[index];
		return true;
	}
	return false;
}

void backtrack(int c) {
	int s = 0;
	if(done) return;

	if(c == t) {
		int sum = 0;
		// printf("here we are\n");
		for(int i = 0; i < t; i++) {
			sum += list[i];
		}
		if(sum > sumt) {
			sumt = sum;
			order.clear();
			for(int i = 0; i < t; i++) {
				if(list[i] != 0) order.push_back(list[i]);
			}
		}
	}
	for(int i = c; i < t; i++) {
		if(done) return;
		if(fits(i, c)) {
			list[c] = d[i];
			//printf("%d fits\n", d[i]);

		}
		backtrack(c + 1);
		//else printf("nope\n");
		list[c] = 0;
	}

}

int main() {


	while(scanf("%d", &N) != EOF) {
		scanf("%d", &t);
		d = new int[t];
		list = new int[t];
		sumt = 0;
		done = false;
		order.clear();
		for(int i = 0; i < t; i++) {
			scanf("%d", &d[i]);
		}
		printf("algo\n");
		// algorithm
		backtrack(0);
		for(deque<int>::iterator it = order.begin(); it != order.end(); it++) {
			printf("%d ", (*it));
		}
		printf("sum:%d", sumt);
	}
	return 0;
}


