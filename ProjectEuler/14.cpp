// 14
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int collatz(ll n) {
    int len = 1;
    while(n > 1) {
        if(n % 2) {
            n *= 3;
            n++;
        }
        else {
            n /= 2;
        }
        len++;
    }
    return len;
}

int main() {
    int longest = 0;
    int starting = 0;
    for(int i = 0; i < 1000000; i++) {
        int chainLen = collatz(i);
        if(chainLen > longest) {
            longest = chainLen;
            starting = i;
        }
    }
    printf("starting number: %d chain length: %d\n", starting, longest);
    return 0;
}
