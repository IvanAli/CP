/*
 * 628.cpp
 *
 *  Created on: Jul 9, 2015
 *      Author: Ivan
 */

// 628 - Passwords

#include <cstdio>
#include <deque>
#include <vector>
#include <set>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

int n, m;
char s[100000];
string *input;
string *order;

void backtrack(int c) {
	if(c == strlen(s)) {
		for(int i = 0; i < c; i++) {
			printf("%s", order[i].c_str());
		}
		printf("\n");
		return;
	}
	if(s[c] == '#') { // it expects a word
		for(int i = 0; i < n; i++) {
			order[c] = input[i];
			backtrack(c + 1);
		}
	}
	else if(s[c] == '0') {
		for(char i = '0'; i <= '9'; i++) {
			order[c] = i;
			backtrack(c + 1);
		}
	}

}

int main() {


	while(scanf("%d", &n) != EOF) {
		input = new string[n];
		for(int i = 0; i < n; i++) {
			scanf("%s", &s);
			input[i] = s;
		}
		scanf("%d", &m);
		for(int i = 0; i < m; i++) {
			scanf("%s", &s);
			if(!i) printf("--\n");
			order = new string[strlen(s)];
			// algorithm
			backtrack(0);
		}

	}

	return 0;
}


