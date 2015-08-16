/*
 * 10576.cpp
 *
 *  Created on: Jul 10, 2015
 *      Author: Ivan
 */

// 10576 - YZK Accounting Bug

#include <cstdio>
int s, d, total;

int numBitsOn(int set) {
	int num = 0;
	for(int i = 0; i < 12; i++) {
		if(set & (1 << i)) {
			num++;
		}
	}
	return num;
}

bool fiveMonthDeficit(int set, int shift) {
	// ((1 << 5) - 1) << shift
	int surplus = 0, deficit = 0;
	for(int i = shift; i < 5 + shift; i++) {
		if(set & (1 << i)) surplus += s;
		else deficit += d;
	}
	if(deficit > surplus) return true;
	return false;
}

bool year(int set) {
	for(int i = 0; i < 8; i++) {
		if(!fiveMonthDeficit(set, i)) return false;
	}
	return true;
}

int main() {

	while(scanf("%d %d", &s, &d) != EOF) {
		total = 0;
		for(int set = 0; set < (1 << 12); set++) {
			if(year(set)) {
				if(numBitsOn(set) * s - ((12 - numBitsOn(set)) * d) > total)
					total = numBitsOn(set) * s - ((12 - numBitsOn(set)) * d);
			}
		}
		if(total > 0) printf("%d\n", total);
		else printf("Deficit\n");
	}

	return 0;
}


