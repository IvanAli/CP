/*
ID: ivanali1
LANG: C++
TASK: milk
*/

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct Farmer {
    int P;
    int A;

    bool operator< (const Farmer& other) const {
        return other.P < P;
    }
} farmer;

/*struct cmp {
    bool operator() (const Farmer& a, const Farmer& b) {
        return a.P > b.P;
    }
};*/

int main() {
    FILE* fin = fopen("milk.in", "r");
    FILE* fout = fopen("milk.out", "w+");
    int N, M;
    int P, A;
    int total = 0;
    priority_queue<Farmer> pq;
    fscanf(fin, "%d %d", &N, &M);
    for(int i = 0; i < M; i++) {
        fscanf(fin, "%d %d", &P, &A);
        farmer.P = P; farmer.A = A;
        pq.push(farmer);
    }
    while(N) {
        Farmer f = pq.top(); pq.pop();
        if(f.A < N) {
            total += f.A * f.P;
            N -= f.A;
        }
        else {
            total += (f.P * N);
            N = 0;
        }
    }
    fprintf(fout, "%d\n", total);
    return 0;
}
