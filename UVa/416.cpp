/*
 * 416.cpp
 *
 *  Created on: Jul 10, 2015
 *      Author: Ivan
 */

// 416 - LED Test

#include <cstdio>
#include <bitset>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

vector<string> vec;
vector<int> result;
bool match;
int N;
char s[7];

int segment[] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 111};

int bcdToDecimal(string bcd) {
	int decimal = 0;
	for(int i = 0; i < 7; i++) {
		if(bcd[i] == '1') decimal |= (1 << i);
	}
	return decimal;
}

int numBitsOn(int n) {
	int num = 0;
	for(int i = 0; i < 7; i++) {
		if(n & (1 << i)) num++;
	}
	return num;
}

bool matches(int a, int b) {
	int c = a | b;
	int bitsa = numBitsOn(a);
	int bitsc = numBitsOn(c);
	// int bitsb = numBitsOn(b);
	if(bitsc == bitsa) { // number found
		return true;
	}
	return false;
}

void backtrack(int index, int number, int burned) {
	if(index == N) {
		      int count = result[0];
		//printf("numbers are:");
		/*for(int i = 0; i < result.size(); i++) {
			printf(" %d", result[i]);
		}*/

		for(int i = 1; i < result.size(); i++) {
			if(result[i] != --count) {
				match = false;
				//printf("Mismatch at %d\n", count);
				return;
			}
		}
		match = true;
		return;
	}
	for(int i = 0; i < 10; i++) {
		if(match) return;
		if(matches(segment[i], bcdToDecimal(vec[index]))) {
			//      printf("match done for %d at %d\n", i, index);
			// check what bits are burned

			int toburn = segment[i] ^ bcdToDecimal(vec[index]);
			/*if(index == 1 && i == 3) {
				printf("burned mask: %d, toburn: %d\n", burned, toburn);
			}*/
			//printf("burned: %d, toburn: %d\n", burned, toburn);
			//if((burned & toburn) == burned) {
			if((burned & (toburn | (segment[i] ^ ((1 << 7) - 1)))) == burned) {
				//printf("yes\n");
				if(i == number || number == -1) {
					result[index] = i;
					backtrack(index + 1, i - 1, (burned | toburn));
				}

			}
		}
	}
}


int main() {
	bool first = true;
	while(scanf("%d", &N) && N) {
		vec.clear();
		result.clear();
		match = false;
		for(int i = 0; i < N; i++) {
			scanf("%s", s);
			for(int i = 0; i < 7; i++) {
				if(s[i] == 'Y') s[i] = '1';
				else s[i] = '0';
			}
			vec.push_back(s);
		}
		result.assign(N, 0);
		backtrack(0, -1, 0);
		//if(!first) printf("\n");
		//first = false;
		if(match) printf("MATCH\n");
		else printf("MISMATCH\n");
	}
	return 0;
}



