/*
 * 10567.cpp
 *
 *  Created on: Jul 16, 2015
 *      Author: Ivan
 */

// 10567 - Fill Bates?

#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
	char s[1000000];
	char ss[101];
	vector<vi> alphabet(52);
	vector<int> indices;
	int count = 0;
	int Q;
	bool ans;

	scanf("%s", &s);
	for(int i = 0; i < strlen(s); i++) {
		if(s[i] < 'a') {
			alphabet[s[i] - 'A'].push_back(i);
		}
		else {
			alphabet[s[i] - 'a'].push_back(i);
		}
	}
	count = 0;
	scanf("%d", &Q);
	for(int i = 0; i < Q; i++) {
		indices.clear();
		scanf("%s", &ss);
		ans = true;
		char ch = ss[0];
		count = 0;
		for(int j = 0; j < strlen(ss); j++) {
			if(ss[j] != ch) {
				count = 0;
				ch = ss[j];
			}

			if(ss[j] < 'a') {
				if(count == alphabet[ss[j] - 'A'].size()) {
					ans = false;
					break;
				}
				indices.push_back(alphabet[ss[j] - 'A'][count]);
			}
			else {
				if(count == alphabet[ss[j] - 'a'].size()) {
					ans = false;
					break;
				}
				indices.push_back(alphabet[ss[j] - 'a'][count]);
			}
			count++;
		}
		// check the sorting
		int min = indices[0];
		for(int i = 0; i < indices.size(); i++) {
			if(min > indices[i]) {
				ans = false;
				break;
			}
		}
		if(ans) printf("Matched %d %d\n", indices.front(), indices.back());
		else printf("Not matched\n");
	}

	return 0;
}

