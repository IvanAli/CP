/*
 * 12190.cpp
 *
 *  Created on: Jul 23, 2015
 *      Author: Ivan
 */

// 12190 - Electric Bill

#include <cstdio>
#include <algorithm>
using namespace std;

#define EPS 1e9
using namespace std;

int getPrice(int watts) {
	if(watts <= 100) return 2 * watts;
	else if(watts <= 10000) return 2 * watts + (watts - 100);
	else if(watts <= 1000000) return 2 * watts + (watts - 100) + 2 * (watts - 10000);
	else return 2 * watts + (watts - 100) + 2 * (watts - 10000) + 2 * (watts - 1000000);
}

int getWatts(int price) {
	if(price <= 2 * 100) return price / 2;
	else if(price <= 2 * 100 + 3 * (10000 - 100)) return (price + 100) / 3;
	else if(price <= 2 * 100 + 3 * (10000 - 100) + 5 * (1000000 - 10000)) return (price + 20100) / 5;
	else return (price + 2020100) / 7;
}

int main() {
	int A, B;
	while(scanf("%d %d", &A, &B) && (A | B)) {
		int watts = getWatts(A);
		int low = 0; int high = watts; int mid = 0; int ans = 0; int diff;
		while(low < high) {
			mid = low + (high - low) / 2;
			diff = getPrice(watts - mid) - getPrice(mid);
			// printf("mid: %d\n", mid);
			if(diff > B) {
				low = mid + 1;
				/*printf("value obtained: %d\n", abs(getPrice(mid) - getPrice(watts - mid)));
				printf("low is now: %d\n", low);*/
			}
			else if(diff < B){
				high = mid;
				/*printf("value obtained 2: %d\n", abs(getPrice(mid) - getPrice(watts - mid)));
				printf("high is now: %d\n", high);*/
			}
			else {
				ans = mid; break;
			}
		}
		printf("%d\n", getPrice(ans));
	}
	return 0;
}
