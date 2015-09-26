/*
ID: ivanali1
LANG: C++
TASK: milk2
*/

#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

typedef vector<int> vi;

int main() {
    int N, a, b;
    FILE* fin = fopen("milk2.in", "r");
    FILE* fout = fopen("milk2.out", "w+");
    int countone = 0;
    int countzero = 0;
    int maxcountone = 0;
    int maxcountzero = 0;
    int upperbound = 0;
    int lowerbound = 1000001;
    bitset<1000001> bs;
    bs.reset();
    fscanf(fin, "%d", &N);
    for(int i = 0; i < N; i++) {
        fscanf(fin, "%d %d", &a, &b);
        lowerbound = min(lowerbound, a);
        upperbound = max(upperbound, b);
        while(a < b) {
            bs[a++] = 1;
        }
    }
    for(int i = lowerbound; i < upperbound; i++) {
        if(bs[i]) {
            countone++;
            maxcountzero = max(maxcountzero, countzero);
            countzero = 0;
        }
        else {
            countzero++;
            maxcountone = max(maxcountone, countone);
            countone = 0;
        }
    }
    maxcountone = max(maxcountone, countone);
    maxcountzero = max(maxcountzero, countzero);
    fprintf(fout, "%d %d\n", maxcountone, maxcountzero);
    return 0;
}
