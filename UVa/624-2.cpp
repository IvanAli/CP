/*
 * 624-2.cpp
 *
 *  Created on: Jul 9, 2015
 *      Author: Ivan
 */

// 624 - 2 AGAIN

#include <cstdio>

int N, t, *d, max, maxset;

int sumset(int set) {
	int sum = 0;
	for(int i = 0; i < t; i++) {
		if(set & (1 << i)) {
			sum += d[i];
		}
	}
	return sum;
}

bool isLonger(int a, int b) {
	int asum = 0, bsum = 0;
	for(int i = 0; i < t; i++) {
		if(a & (1 << i)) asum++;
		if(b & (1 << i)) bsum++;
	}
	if(asum > bsum) return true;
	return false;
}

int main() {

	while(scanf("%d", &N) != EOF) {
		scanf("%d", &t);
		d = new int[t];
		max = 0;
		for(int i = 0; i < t; i++) {
			scanf("%d", &d[i]);
		}
		// algorithm
		for(int set = 0; set < (1 << t); set++) {
			if(sumset(set) <= N && sumset(set) >= max) {
				if(max == sumset(set)) {// check which one has the most tracks
					if(isLonger(maxset, set)) {
						continue;
					}
				}
				max = sumset(set);
				maxset = set;

			}
		}
		for(int i = 0; i < t; i++) {
			if(maxset & (1 << i)) printf("%d ", d[i]);
		}
		printf("sum:%d\n", max);
	}
	return 0;
}



