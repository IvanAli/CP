/*
 * 793.cpp
 *
 *  Created on: Jul 4, 2015
 *      Author: Ivan
 */
// 793 - Network Connections
// using the Union Find Data Structure

#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

class UnionFind {
private:
	vi p, rank, setSize;
	int numSets;
public:
	UnionFind(int N) {
		numSets = N;
		for(int i = 0; i < N; i++) p.push_back(i);
		rank.assign(N, 0);
		setSize.assign(N, 1);
	}
	int findSet(int i) {
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}
	bool sameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j) {
		if(!sameSet(i, j)) {
			numSets--;
			int x = findSet(i);
			int y = findSet(j);
			if(rank[x] > rank[y]) {
				p[y] = x;
				setSize[x] += setSize[y];
			}
			else {
				p[x] = y;
				setSize[y] += setSize[x];
				if(rank[x] == rank[y]) rank[y]++;
			}
		}
	}
};

int main() {
	int t, pc, ch, ci, cj;
	int yes, no;
	bool first = true;

	scanf("%d", &t);

	while(t--) {

		yes = no = 0;

		scanf("%d", &pc);

		UnionFind uf(pc);

		if(!first) printf("\n");

		first = false;

		getc(stdin);
		while((ch = getc(stdin)) != '\n') {
			scanf("%d %d", &ci, &cj);
			if(ch == 'c') {
				uf.unionSet(ci - 1, cj - 1);
			}
			else if(ch == 'q') {
				if(uf.sameSet(ci - 1, cj - 1)) yes++;
				else no++;
			}
			if(getc(stdin) == EOF) break;
		}
		printf("%d,%d\n", yes, no);
	}


	return 0;
}


