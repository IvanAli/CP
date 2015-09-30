// 53 - Combinatoric selections

#include <cstdio>
typedef long long ll;

ll factorial[101];

void dp() {
    factorial[0] = 1;
    factorial[1] = 1;
    for(int i = 2; i <= 100; i++) {
        factorial[i] = i * factorial[i - 1];
    }
}

int nCr(int n, int r) {
    return factorial[n] / (factorial[r] * factorial[n - r]);
}

int main() {
    int count = 0;
    dp();
    printf("dp done\n");
    /*for(int n = 23; n <= 100; n++) {
        for(int r = 0; r <= n; r++) {
            if(nCr(n, r) > 1000000) count++;
        }
    }
    printf("%d\n", count);*/
    printf("factorial of 14: %lld", factorial[23]);
    return 0;
}
