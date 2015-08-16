/*
 * 725.cpp
 *
 *  Created on: Jul 6, 2015
 *      Author: Ivan
 */
// 725 - Division
// based on the book version

#include <cstdio>

int main() {
	int N;
	bool found;
	bool first = true;
	while(scanf("%d", &N) && N) {
		// range is 01234 to 98765
		if(!first) printf("\n");
		first = false;
		found = false;
		for(int fghij = 1234; fghij <= 98765 / N; fghij++) {
			int abcde, used, tmp;
			abcde = fghij * N;
			used = fghij < 10000;
			tmp = abcde;
			while(tmp) {
				used |= 1 << (tmp % 10);
				tmp /= 10;
			}
			tmp = fghij;
			while(tmp) {
				used |= 1 << (tmp % 10);
				tmp /= 10;
			}
			if(used == (1 << 10) - 1) {
				printf("%0.5d / %0.5d = %d\n", abcde, fghij, N);
				found = true;
			}
		}
		if(!found) printf("There are no solutions for %d.\n", N);

	}
	return 0;
}


