/*
 * 1237.cpp
 *
 *  Created on: Jul 7, 2015
 *      Author: Ivan
 */
// 1237 - Expert Enough?

#define STRPAIR string, pair<int, int>
#include <cstdio>
#include <map>
#include <cstring>
#include <string>
#include <utility>
using namespace std;

int main() {
	int tc, D, L, H, Q, P, makerCounter;
	char M[200000];
	string ans;
	map<STRPAIR> m;
	scanf("%d", &tc);

	while(tc--) {
		scanf("%d", &D);
		getc(stdin);
		m.clear();
		ans = "";
		while(D--) {
			scanf("%s %d %d", &M, &L, &H);
			m[M].first = L;
			m[M].second = H;
		}

		scanf("%d", &Q);
		while(Q--) {
			makerCounter = 0;
			scanf("%d", &P);
			for(map<STRPAIR>::iterator it = m.begin();
					it != m.end(); it++) {
				if(P >= it->second.first && P <= it->second.second) {
					ans = it->first;
					makerCounter++;
				}
			}
			if(makerCounter == 1)
				printf("%s", ans.c_str());
			else
				printf("UNDETERMINED");
			printf("\n");
		}
		if(tc) printf("\n");
	}
	return 0;
}



