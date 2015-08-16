/*
 * 10567-2.cpp
 *
 *  Created on: Jul 19, 2015
 *      Author: Ivan
 */

// 10567-2 - Helping Fill Bates

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
	char s[1000000];
	char ss[100001];
	vector<vi> alphabet;
	vii query;
	int q;

	alphabet.resize(256);
	scanf("%s", &s);
	for(int i = 0; i < strlen(s); i++) {
		alphabet[s[i]].push_back(i);
	}

	scanf("%d", &q);
	for(int i = 0; i < q; i++) {
		scanf("%s", &ss);
		int index = -1, first;
		bool match = true;
		for(int j = 0; j < strlen(ss); j++) {
			if(query.empty()) query.push_back(ii(ss[j], 1));
			else if(query.back().first != ss[j]) query.push_back(ii(ss[j], 1));
			else query.back().second++;
			/*
			vector<int>::iterator it = upper_bound(alphabet[ss[j]].begin(), alphabet[ss[j]].end(), index);
			if(it == alphabet[ss[j]].end()) {
				match = false;
				break;
			}
			index = *it;
			if(!j) first = *it;
			*/
		}
		for(int j = 0; j < query.size(); j++) {
			if(alphabet[query[j].first].size() <= query[j].second) match = false;
		}
		if(match) {
			first = alphabet[query.front().first][0];
			index = alphabet[query.back().first][query.back().second - 1];
		}
		if(match) printf("Matched %d %d\n", first, index);
		else printf("Not matched\n");

	}

	return 0;
}


