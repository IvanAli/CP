/*
 * 11991.cpp
 *
 *  Created on: Jul 4, 2015
 *      Author: Ivan
 */
//11991 - Easy Problem from Rujia Liu?

#include <cstdio>

int main() {
	int n, m, k, v;
	int *arr;
	int occ, index;
	bool found;

	while(scanf("%d %d", &n, &m) != EOF) {
		arr = new int[n];

		for(int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		for(int i = 0; i < m; i++) {
			occ = 0;
			index = 1;
			found = false;

			scanf("%d %d", &k, &v);
			for(int j = 0; j < n; j++) {
				if(arr[j] == v) {
					occ++;
					if(occ == k) {
						found = true;
						index = j + 1;
						break;
					}
				}
			}
			printf("%d\n", found ? index : 0);
		}

	}

	return 0;
}



