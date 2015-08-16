/*
 * 793.cpp
 *
 *  Created on: Jul 4, 2015
 *      Author: Ivan
 */
// 793 - Network Connections
// using an array -- TLE

#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
	vector<vi> grid;
	int t, pc, ch, ci, cj;
	int yes, no;
	int *parent;
	bool first = true;

	scanf("%d", &t);
	getc(stdin);
	getc(stdin);

	while(t--) {

		yes = no = 0;

		scanf("%d", &pc);

		parent = new int[pc];

		if(!first) printf("\n");

		first = false;

		getc(stdin);
		while((ch = getc(stdin)) != '\n') {
			scanf("%d %d", &ci, &cj);
			if(ch == 'c') {
				if(ci < cj) {
					parent[ci - 1] = ci - 1;
					parent[cj - 1] = parent[ci - 1];
				}
				else {
					parent[cj - 1] = cj - 1;
					parent[ci - 1] = parent[cj - 1];
				}
			}
			else if(ch == 'q') {
				if(parent[ci - 1] == parent[cj - 1]) yes++;
				else no++;
			}
			if(getc(stdin) == EOF) break;
		}
		printf("%d,%d\n", yes, no);
	}


	return 0;
}


