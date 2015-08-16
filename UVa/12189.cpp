/*
 * 12189.cpp
 *
 *  Created on: Aug 16, 2015
 *      Author: Ivan
 */

// 12189 - Dinner Hall

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> vi;

struct Card {
	int t;
	char e;
	Card(int time, char event): t(time), e(event) {}
	int E() { return e == 'E' ? 1 : 0; }
	int X() { return e == 'X' ? 1 : 0; }
	int UNK() { return e == '?' ? 1 : 0; }
};

bool compare(const Card& c1, const Card& c2) {
	return c1.t < c2.t;
}

int main() {
	int N, HH, MM, SS, E, X, UNK, maxE, max, entryNumber;
	char t;
	vector<Card> cards;

	while(scanf("%d", &N) && N) {
		E = X = UNK = 0;
		cards.clear();
		for(int i = 0; i < N; i++) {
			scanf("%d:%d:%d %c", &HH, &MM, &SS, &t);
			Card c = Card(HH * 10000 + MM * 100 + SS, t);
			E += c.E();
			X += c.X();
			UNK += c.UNK();
			cards.push_back(c);
		}
		// algorithm
		sort(cards.begin(), cards.end(), compare);
		maxE = (X + UNK - E) / 2;
		entryNumber = 0; max = 0;
		for(int i = 0; i < cards.size(); i++) {
			Card c = cards[i];
			if(c.E()) {
				entryNumber++;
			}
			if(c.X()) {
				entryNumber--;
			}
			if(c.UNK()) {
				if(maxE) {
					entryNumber++;
					maxE--;
				}
				else entryNumber--;
			}
			if(entryNumber > max) max = entryNumber;
		}
		printf("%d\n", max);
	}
	return 0;
}


