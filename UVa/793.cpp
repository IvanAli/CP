/*
 * 793.cpp
 *
 *  Created on: Jul 4, 2015
 *      Author: Ivan
 */
// 793 - Network Connections
// using adjacency lists

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
	bool success;

	scanf("%d", &t);
	getc(stdin);

	while(t--) {
		getc(stdin);

		yes = no = 0;
		grid.clear();

		scanf("%d", &pc);
		printf("pc is %d\n", pc);
		grid.assign(pc + 1, vi());

		getc(stdin);
		while((ch = getc(stdin)) != '\n') {
			scanf("%d %d", &ci, &cj);
			success = false;
			if(ch == 'c') {
				printf("Connected\n");
				grid[ci].push_back(cj);
				grid[cj].push_back(ci);
			}
			else if(ch == 'q') {
				printf("Question\n");
				if(ci < cj) {
					for(int i = 0; i < grid[ci].size(); i++) {
						if(grid[ci][i] == cj) { success = true; break;}
					}
				}
				else {
					for(int i = 0; i < grid[cj].size(); i++) {
						if(grid[cj][i] == ci) { success = true; break;}
					}
				}
				printf("%s\n", success ? "Successful" : "Unsuccessful");
				if(success) yes++;
				else no++;
			}
			getc(stdin);
		}
		printf("%d,%d\n", yes, no);
	}


	return 0;
}


