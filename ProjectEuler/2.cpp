// 2 - Even Fibonacci numbers

#include <cstdio>

int main() {
    long long fib = 0;
    int even = 0;
    long long fib1 = 1, fib2 = 1;
    long long sum = 0;
    for(fib = fib1 + fib2; fib < 4000000; fib2 = fib1, fib1 = fib, fib = fib1 + fib2) {
        if(fib % 2 == 0) sum += fib;
    }
    /*do {
        fib = fib1 + fib2;

        if(fib >= 4000000) break;
        printf("fib: %lld\n", fib);
        if(fib % 2 == 0) {
            even++;
            printf("yes\n");
        }
        fib2 = fib1;
        fib1 = fib;
    }
    while(fib < 4000000);*/
    printf("%d\n", sum);
    return 0;
}
