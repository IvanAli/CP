/*
 * 11057.cpp
 *
 *  Created on: Jul 20, 2015
 *      Author: Ivan
 */

// 11057 - Exact Sum

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
	int N, M;
	vi price;
	vii books;
	int min;
	bool first = true;

	while(scanf("%d", &N) != EOF) {
		price.clear();
		books.clear();
		price.resize(N);
		for(int i = 0; i < N; i++) {
			scanf("%d", &price[i]);
		}
		scanf("%d", &M);

		// algorithm
		sort(price.begin(), price.end());

		//if(!first) printf("\n");
		//first = false;

		for(int i = 0; i < price.size(); i++) {
			vi::iterator it = lower_bound(price.begin(), price.end(), M - price[i]);
			if(it != price.end() && *it == M - price[i] && (it - price.begin()) != i) {
				books.push_back(ii(price[i], M - price[i]));
				//printf("Books: %d %d\n", books[i].first, books[i].second);
			}
		}

		min = 0;
		for(int i = 0; i < books.size(); i++) {
			// let's get the min difference
			if(books[i].second - books[i].first < books[min].second - books[min].first) {
				if(books[i].second >= books[i].first) min = i;
			}
		}

		printf("Peter should buy books whose prices are %d and %d.\n\n", books[min].first, books[min].second);

	}


	return 0;
}


