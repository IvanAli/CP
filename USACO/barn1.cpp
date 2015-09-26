/*
ID: ivanali1
LANG: C++
TASK: barn1
*/

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Maxes {
    int maxdiff;
    int maxindex;
    bool operator< (const Maxes& other) const {
        return maxindex < other.maxindex;
    }
};

bool nextmax(const vector<Maxes>& maxes, int m, int index) {
    for(int i = 0; i < m; i++) {
        if(maxes[i].maxindex == index) return false;
    }
    return true;
}

int main() {
    FILE* fin = fopen("barn1.in", "r");
    FILE* fout = fopen("barn1.out", "w+");
    int M, S, C;
    vector<int> stalls;
    vector<Maxes> maxes;
    fscanf(fin, "%d %d %d", &M, &S, &C);
    stalls = vector<int>(C);
    maxes = vector<Maxes>(M);
    for(int i = 0; i < C; i++) fscanf(fin, "%d", &stalls[i]);

    // algorithm
    sort(stalls.begin(), stalls.end());
    int maxdiff = 0;
    int maxindex;
    for(int m = 0; m < M - 1; m++) {
        maxes[m].maxdiff = 0; maxes[m].maxindex = 0;
        for(int i = 0; i < stalls.size() - 1; i++) {
            int diff = stalls[i + 1] - stalls[i];
            if(diff > maxes[m].maxdiff && nextmax(maxes, m, i + 1)) {
                maxes[m].maxdiff = diff;
                maxes[m].maxindex = i + 1;
            }
        }
    }
    maxes[M - 1].maxindex = C;
    /*for(int i = 0; i < maxes.size(); i++) {
        printf("diff: %d index: %d\n", maxes[i].maxdiff, maxes[i].maxindex);
    }*/
    sort(maxes.begin(), maxes.end());
    int sum = 0;
    int currindex = 0;
    for(int i = 0; i < maxes.size(); i++) {
        sum += stalls[maxes[i].maxindex - 1] - stalls[currindex] + 1;
        currindex = maxes[i].maxindex;
    }
    // sum += stalls[C - 1] - stalls[currindex] + 1;
    fprintf(fout, "%d\n", M < C ? sum : C);
    return 0;
}
