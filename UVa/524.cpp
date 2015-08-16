/*
 * 524.cpp
 *
 *  Created on: Jul 10, 2015
 *      Author: Ivan
 */

// 524 - Prime Ring Problem

#include <cstdio>
#include <bitset>
#include <vector>
using std::bitset;
using std::vector;

int n;
int sieveSize;
int *ring;
bitset<45> bs;
// vector<int> primes;

/*
bool isPrime(int n) {
	for(int j = 2; j < n; j++) {
		if(n == 2) return true;
		if(n % j == 0) return false;
	}
	return true;
}
*/

void sieve(int upperbound) {
	sieveSize = upperbound + 1;
	bs.set();
	bs[0] = 0; bs[1] = 0;
	for(int i = 2; i <= sieveSize; i++) {
		if(bs[i])
			for(int j = i * i; j <= sieveSize; j += i) bs[j] = 0;

	}
}

bool isPrime(int n) {
	// if(bs[n]) printf("%d is prime\n", n);
	return bs[n];
}

bool adjacentPrimes(int c, int x) {
	int i = 0;
	for(; i < c; i++) {
		if(ring[i] == x) return false;
	}
	// check if they are prime numbers
	int n = i > 0 ? ring[i - 1] + x : x;
	if(x == 0 || x == 1) return true;
	return isPrime(n);
}

void backtrack(int c) {
	if(c == n) {
		if(isPrime(1 + ring[c - 1])) {
			printf("%d", 1);
			for(int i = 1; i < n; i++) printf(" %d", ring[i]);
			printf("\n");
		}
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(adjacentPrimes(c, i)) {
			ring[c] = i;
			backtrack(c + 1);
		}
	}
}

int main() {
	int t = 0;

	sieve(40);
	while(scanf("%d", &n) != EOF) {
		if(t) printf("\n");
		ring = new int[n];
		ring[0] = 1;
		printf("Case %d:\n", ++t);
		backtrack(1);

	}
	return 0;
}


