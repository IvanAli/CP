/*
 * 1047.cpp
 *
 *  Created on: Jul 7, 2015
 *      Author: Ivan
 */

// 1047 - Zones

#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int tc, n, b, m, t, tn, sub, best, order;
int *tower, *recommended;
bool first;
vector<vi> area;

void setRecommended(int set) {
	int pos = 0;
	for(int i = 0; i < n; i++) {
		if(set & (1 << i)) {
			recommended[pos] = i + 1;
			pos++;
		}
	}
}
void printOrder(int set) {
	for(int i = 0; i < n; i++) {
		if(set & (1 << i)) printf(" %d", i + 1);
	}
}

bool smallestBit(int set) {
	for(int i = 0; i < n; i++) {
		if(set & (1 << i) && !(order & (1 << i))) return true;
		else if(!(set & (1 << i)) && (order & (1 << i))) return false;
		//if(!((set & (1 << i)) && (order & (1 << i)))) return false;
		//if(set << i & (-set << i) >= order << i & (-order << i)) return false;
	}
	return false;
}

int sumTowers(int set) {
	int sum = 0;
	for(int i = 0; i < n; i++) {
		if(set & (1 << i)) sum += tower[i];
	}
	return sum;
}

int bitsOn(int set) {
	int num = 0;
	for(int i = 0; i < n; i++) {
		if(set & (1 << i)) num++;
	}
	return num;
}

bool numberMatch(int set, int condition) {
	if(set & 1 << (condition - 1)) return true;
	return false;
}

int conditionMatch(int set, int index) {
	int matched = 0;
	for(int i = 0; i < area[index].size() - 1; i++) {
		if(numberMatch(set, area[index][i])) {
			matched++;
		}
	}
	return matched;
}

int getSharedCustomers(int i, int matched) {
	if(matched == 0) return 0;
	return area[i].back() * (matched - 1);
}

int main() {

	first = true;
	tc = 0;
	while(scanf("%d %d", &n, &b) && (n || b)) {
		// input
		tower = new int[n];
		recommended = new int[b];
		best = 0;
		order = n;
		area.clear();

		for(int i = 0; i < n; i++) scanf("%d", &tower[i]);
		scanf("%d", &m);

		area.assign(m, vi());
		for(int i = 0; i < m; i++) {
			scanf("%d", &t);
			t++;
			while(t--) {
				scanf("%d", &tn);
				area[i].push_back(tn);
			}
		}

		// algorithm
		for(int set = (1 << b) - 1; set < (1 << n); set++) {
			sub = 0;
			// let's see if there are b bits on
			if(bitsOn(set) == b) { // if the set is of size b, it's valid
				// let's check each condition
				//printf("%d is valid\n", set);
				for(int i = 0; i < area.size(); i++) {
						//if(set == 19 || set == 21) printf("to sub: %d\n", getSharedCustomers(i, conditionMatch(set, i)));
						//printf("Condition %d matched for %d\n", i + 1, set);
						sub += getSharedCustomers(i, conditionMatch(set, i));
						//printf("substract %d\n", sub);
				}
				//printf("Sum of towers in the set: %d\n", sumTowers(set));
				if(best <= sumTowers(set) - sub) {
					if(best != sumTowers(set) - sub) {
						order = set;
					}
					else {
						if(smallestBit(set)) order = set;
					}

					best = sumTowers(set) - sub;
					// printf("best:%d,", best);
					// printOrder(set);
				}
			}
		}
		/*
		if(!first) printf("\n");
		first = false;
		*/
		printf("Case Number  %d\n", ++tc);
		printf("Number of Customers: %d\n", best);
		printf("Locations recommended:");
		printOrder(order);
		//for(int i = 0; i < b; i++) printf(" %d", recommended[i]);
		printf("\n\n");
	}
	return 0;
}


