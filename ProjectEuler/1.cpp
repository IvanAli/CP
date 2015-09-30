#include <cstdio>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int a = 3, b = 5, c = lcm(a, b), n = 1000;
    int common = c;
    printf("lcm: %d\n", lcm(a, b));
    int sum = 0;
    while(a < n || b < n || c < n) {
        if(a < n) {
            sum += a;
            a += 3;
        }
        if(b < n) {
            sum += b;
            b += 5;
        }
        if(c < n) {
            sum -= c;
            printf("sub: %d\n", c);
            c += common;
        }

    }
    printf("%d\n", sum);
    return 0;
}
